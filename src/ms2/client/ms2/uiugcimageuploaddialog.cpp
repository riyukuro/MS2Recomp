// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCImageUploadDialog: see uiugcimageuploaddialog.h.
// MS2-UNIT: ?\uiugcimageuploaddialog.cpp
// MS2-RANGE: 0x14011eac0-0x14011eb80 .text$di
// MS2-RANGE: 0x141b39900-0x141b3b830 .text$mn
// MS2-RANGE: 0x142cc3090-0x142cc30b7 .text$yd
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcimageuploaddialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiugcimageuploaddialog.h"
#include "uiitemblueprintcreatedialog.h"
#include "uimessagebox.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ugcmanager.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject {};

// The status-listener registry (singleton 0x140aa6d40).
class Unk_UiStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);       // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);       // unregister
};
Unk_UiStatusMgr* FUN_140aa6d40();

// The UGC listener registry (singleton 0x140bc09f0).
class Unk_UgcEvents
{
public:
    void FUN_141b38be0(UIUGCEventListener* p);                  // register
    void FUN_141b38c70(UIUGCEventListener* p);                  // unregister
};
Unk_UgcEvents* FUN_140bc09f0();

// The movie root of the dialog: Invoke of a method with an int and an AS array (inline COMDAT 0x141b36aa0).
class Unk_UgcScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_141b36aa0(const char* szMethod, int n, ASArray& arr);
};

// A row of the file list: its members as text.
class Unk_UgcImageData : public AScript
{
public:
    CStringW FUN_1422bb2b0(const char* szName);                 // a member as text
};

CUgcManager* FUN_14052d220();
UIItemBlueprintCreateDialog* FUN_1418a6920();                   // the create dialog of a blueprint item, if open
bool FUN_140a467d0(const MS2Ptr<AScript>* pScript);             // the movie root is not loaded
void FUN_14151f200();
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);     // str == sz
bool FUN_140d74e80(CStringW& tag);                              // a "terms" message box tag answered with yes
void FUN_140d74640(void* p, int nBit, int nIdA, int nIdB);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
CStringW FUN_140719a00(__int64 nMoney);                         // a money amount as text
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);        // set an Int value
extern __int64 DAT_143ab2898;                                   // the money

// @0x141b3b610
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Unk_UgcOpenType a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14011eac0 (dynamic initializer of s_shopSort)

// @0x141b39900
UIUGCImageUploadDialog::UIUGCImageUploadDialog()
{
    FUN_141924170(1);
    m_188 = Unk_UgcOpenType_None;
}

// @0x141b399c0
UIUGCImageUploadDialog::~UIUGCImageUploadDialog()
{
}

// @0x141b39a50
CString UIUGCImageUploadDialog::GetTypeName()
{
    return CString("UGCImageUploadDialog");
}

// @0x141b39aa0
int UIUGCImageUploadDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_140bc09f0()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    return 1;
}

// @0x141b39b40
void UIUGCImageUploadDialog::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    UIDialog::vfunc_67();
    FUN_14052d220()->FUN_141880ec0(vfunc_48());
    m_188 = Unk_UgcOpenType_None;
}

// @0x141b39c10
void UIUGCImageUploadDialog::vfunc_72()
{
    if (m_18c != 0)
    {
        FUN_141b3b1d0();
        m_18c = 0;
    }
}

// @0x141b39c50
void UIUGCImageUploadDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x141b39c70
void UIUGCImageUploadDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
    {
        vfunc_67();
        return;
    }
    if (spUpload->GetDialog() == vfunc_48())
    {
        Unk_UgcOpenType nKind = (Unk_UgcOpenType)spUpload->m_nKind;
        if (FUN_141b3a780((const int*)&nKind) == 0)
        {
            vfunc_67();
            return;
        }
        m_188 = nKind;
        m_30->Invoke("changeOpenType", m_188);
        FUN_141b3ab90();
        FUN_141b3b2c0();
    }
    else
        vfunc_67();
}

// @0x141b39e30
int UIUGCImageUploadDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            if (FUN_1403b3c40(strTag, L"noexist") == 0)
            {
                if (FUN_140d74e80(strTag) != 0)
                    FUN_14052d220()->FUN_141882020();
            }
            else
            {
                FUN_141b3a600();
                MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
                if (spUpload.get() != 0)
                {
                    if (spUpload->m_spViewer.get() != 0)
                        spUpload->m_spViewer->vfunc_4();
                }
            }
            FUN_14151f200();
            return 1;
        }
        FUN_14151f200();
    }
    return 0;
}

// @0x141b3a020
int UIUGCImageUploadDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnOpenFolder", szMethod) == 0)
    {
        OnOpenFolder();
        return 1;
    }
    if (_stricmp("OnPreview", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b3acb0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnUpload", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b3adc0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnNewTemplate", szMethod) == 0)
    {
        OnNewTemplate();
        return 1;
    }
    if (_stricmp("OnAddImage", szMethod) == 0)
    {
        OnAddImage();
        return 1;
    }
    if (_stricmp("onScrollPosition", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            if (nIndex == -1)
                return 0;
            FUN_141b3b0e0(nIndex);
        }
        return 1;
    }
    if (_stricmp("OnItemDoubleClick", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            if (nIndex == -1)
            {
                FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
                return 1;
            }
            FUN_14052d220()->FUN_141882a70(nIndex, 1);
        }
        return 1;
    }
    return 0;
}

// @0x141b3a3d0
void UIUGCImageUploadDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CString strType = pArgs->FUN_1422b8d30();
    Scaleform::GFx::Value arg = pArgs->FUN_1422b9260();
    if (FUN_1409b0390(&arg) == 0 && FUN_1409b0350(&arg) == 0)
    {
        AScript root((const Scaleform::GFx::Value&)arg, 2);
        if (FUN_140184310(strType, "image"))
        {
            AScript data(root.FUN_1422baa20("data"), 2);
            if (data.FUN_1422ba9a0() == 0)
            {
                ASTooltip tip(1, 2);
                CStringW strText = ((Unk_UgcImageData*)&data)->FUN_1422bb2b0("tooltip");
                if (tip.FUN_1409e26b0(strText) != 0)
                {
                    tip.FUN_1409c6dc0(2);
                    tip.FUN_1409c6e60(-4);
                    tip.FUN_1409c6e90(1);
                    *pRetVal = tip.FUN_1422bb870();
                }
            }
        }
    }
}

// @0x141b3a5e0
int UIUGCImageUploadDialog::vfunc_82()
{
    return FUN_140c39820();
}

// @0x141b3a600
void UIUGCImageUploadDialog::FUN_141b3a600()
{
    FUN_141b3ab90();
    FUN_141b3b4e0(-1);
}

// @0x141b3a630
void UIUGCImageUploadDialog::vfunc_ugc_4(int nDialog)
{
    if (vfunc_48() == nDialog)
        m_18c = 1;
}

// @0x141b3a690
void UIUGCImageUploadDialog::FUN_141b3a690(int nResult)
{
    if (nResult == 0)
    {
        if (m_188 == 5)
            FUN_141275260(0x467, 1, 1);
        else if (m_188 == 3)
            FUN_141275260(0x469, 1, 1);
    }
    else
    {
        CStringW strText = FUN_14052d220()->FUN_14187f210(nResult);
        if (!strText.IsEmpty())
            FUN_1412751f0(strText, 1, 1);
    }
    vfunc_67();
}

// @0x141b3a780
bool UIUGCImageUploadDialog::FUN_141b3a780(const int* pnKind)
{
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return false;
    bool bOk;
    if (spUpload->m_nKind == *pnKind)
    {
        bOk = false;
        switch (*pnKind)
        {
        case 3:
            bOk = dynamic_cast<CUgcViewerBanner*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        case 5:
            bOk = dynamic_cast<CUgcViewerProfile*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        case 6:
            bOk = dynamic_cast<CUgcViewerGuildMark*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        case 8:
            bOk = dynamic_cast<CUgcViewerGuildPoster*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        case 9:
        case 0xd1:
            bOk = dynamic_cast<CUgcViewerBlueprintImage*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        case 10:
            bOk = dynamic_cast<CUgcViewerWeddingProfile*>((IUgcViewer*)spUpload->m_spViewer) != 0;
            break;
        }
    }
    else
        bOk = false;
    return bOk;
}

// @0x141b3ab90
void UIUGCImageUploadDialog::FUN_141b3ab90()
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    FUN_14052d220()->FUN_141889ce0(m_188);
    ASArray arr(2);
    FUN_14052d220()->FUN_141889e20(0x10, 0, &arr);
    int nCount = FUN_14052d220()->FUN_14188a480();
    ((Unk_UgcScript*)m_30.operator->())->FUN_141b36aa0("buildUGCFiles", nCount, arr);
}

// @0x141b3ac80
void UIUGCImageUploadDialog::OnOpenFolder()
{
    FUN_14052d220()->FUN_1418829b0(m_188);
}

// @0x141b3acb0
int UIUGCImageUploadDialog::FUN_141b3acb0(int nIndex)
{
    if (nIndex == -1)
    {
        FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_14052d220()->FUN_141881a40(nIndex) == 0)
    {
        FUN_140d73bc0(0x2e2, 0, static_cast<IMessageListener*>(this), CStringW(L"noexist"));
        return 0;
    }
    if (FUN_14052d220()->FUN_141881800(m_188, nIndex) == 0)
    {
        FUN_141275260(0x2e1, 1, 1);
        return 0;
    }
    return 1;
}

// @0x141b3adc0
int UIUGCImageUploadDialog::FUN_141b3adc0(int nIndex)
{
    if (nIndex == -1)
    {
        FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
        return 0;
    }
    if (m_188 == 3 && FUN_141b3b390() > DAT_143ab2898)
    {
        FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_14052d220()->FUN_141881890(nIndex) == 0)
    {
        FUN_140d73bc0(0x2e2, 0, static_cast<IMessageListener*>(this), CStringW(L"noexist"));
        return 0;
    }
    if (m_188 == 9 || m_188 == 0xd1)
    {
        UIItemBlueprintCreateDialog* pDialog = FUN_1418a6920();
        if (pDialog != 0)
            pDialog->FUN_140c38400();
        vfunc_67();
        return 1;
    }
    int nBit = 3;
    int nIdA = 0x9d5;
    if (m_188 == 6)
    {
        nBit = 4;
        nIdA = 0x9d6;
    }
    else if (m_188 == 8)
    {
        nBit = 9;
        nIdA = 0x9d7;
    }
    FUN_140d74640(static_cast<IMessageListener*>(this), nBit, nIdA, 0x9cf);
    return 1;
}

// @0x141b3b020
int UIUGCImageUploadDialog::OnNewTemplate()
{
    if (FUN_14052d220()->FUN_141880fc0() == 0)
        return 0;
    FUN_141b3ab90();
    return 1;
}

// @0x141b3b060
int UIUGCImageUploadDialog::OnAddImage()
{
    int nResult = FUN_14052d220()->FUN_1418810c0(CStringW(L"./"), L"Image Files (*.dds, *.png, *.jpg)");
    if (nResult == 0)
        return 0;
    FUN_141b3a600();
    return 1;
}

// @0x141b3b0e0
int UIUGCImageUploadDialog::FUN_141b3b0e0(int nIndex)
{
    if (nIndex == -1)
        return 0;
    if (FUN_140a467d0(&m_30) != 0)
        return 0;
    ASArray arr(2);
    FUN_14052d220()->FUN_141889e20(0x10, nIndex << 2, &arr);
    ((Unk_UgcScript*)m_30.operator->())->FUN_141b36aa0("buildScrollPosition", nIndex << 2, arr);
    return 1;
}

// @0x141b3b1d0
void UIUGCImageUploadDialog::FUN_141b3b1d0()
{
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return;
    if (spUpload->m_spFile == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("updateThumbnailImage");
}

// @0x141b3b2c0
void UIUGCImageUploadDialog::FUN_141b3b2c0()
{
    if (m_188 != 3)
        return;
    __int64 nPrice = FUN_141b3b390();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("changePrice", FUN_140719a00(nPrice));
}

// @0x141b3b390
__int64 UIUGCImageUploadDialog::FUN_141b3b390()
{
    if (m_188 != 3)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return 0;
    IUgcViewer* pViewer = spUpload->m_spViewer.get();
    if (pViewer == 0)
        return 0;
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(static_cast<CUgcViewerBanner*>(pViewer)->m_post.m_nBannerId);
    if (banner == 0)
        return 0;
    return banner->GetCurrentHourly();
}

// @0x141b3b4e0
void UIUGCImageUploadDialog::FUN_141b3b4e0(int nIndex)
{
    if (nIndex == -1)
    {
        if (m_30.get() != 0)
            m_30->Invoke("selectThumbnail", -1);
    }
    else
    {
        MS2Ptr<CUploadFile> spFile = FUN_14052d220()->FUN_14188a4b0(nIndex);
        if (spFile == 0)
            return;
        if (m_30.get() != 0)
            m_30->Invoke("selectThumbnail", nIndex);
        FUN_141b3acb0(nIndex);
    }
}
