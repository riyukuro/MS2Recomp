// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITencentCashChargeDialog: the Tencent cash charge web page
// dialog, a UIWebBrowserBase (uiupperhuddialog.h) that renders the page into an image of its swf.
// MS2-UNIT: ?\uitencentcashchargedialog.cpp
// MS2-RANGE: 0x140e99b90-0x140e9a970 .text$mn
// MS2-PIN: ??_EUITencentCashChargeDialog@@WBHI@EAAPEAXI@Z 0x140e9a7ec
// MS2-PIN: ??_GUITencentCashChargeDialog@@UEAAPEAXI@Z 0x140e9a800
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitencentcashchargedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiupperhuddialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
class Unk_CashImage : public AScript {};                                    // the image holder the page is drawn into (0x90 bytes)
struct Unk_CashImagePtr                                                     // its smart pointer (16 bytes, pointer at +8)
{
    void* m_0;
    Unk_CashImage* m_p;
};
class Unk_CashConstInt { public: int m_n; char m_pad_04[0x54]; };                                // one value of the client constants
class Unk_CashConstStr { public: CString& FUN_140298f80(); char m_pad_00[0x60]; };
class Unk_CashConsts
{
public:
    char m_pad_0000[0xdb60];
    Unk_CashConstStr m_strUrl;                                              // +0xdb60
    Unk_CashConstInt m_nWidth;                                              // +0xdbc0
    Unk_CashConstInt m_nHeight;                                             // +0xdc18
};
Unk_CashConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_CashConstInt* p);

class Unk_CashBrowserMgr
{
public:
    void FUN_141b781e0(int nId, const char* pszFrom, const char* pszTo, int n);
    void FUN_141b788b0(int nId, int nWidth, int nHeight);
};
Unk_CashBrowserMgr* FUN_140cc18a0();

class ASDialog : public ASDisplayObject
{
public:
    float FUN_1422c10a0();                                                  // x
    float FUN_1422c1110();                                                  // y
    void FUN_1407cbbe0(const char* szName, bool b);                         // set a bool member
};

void FUN_141901470(int n, int nTypeId);
bool FUN_141900a90(UIObject* pObject);
void FUN_140e999b0(Unk_CashImagePtr* p);                                    // null ctor
void FUN_140d030a0(Unk_CashImagePtr* p);                                    // dtor
void* FUN_140e999d0(Unk_CashImagePtr* p, int nNull);                        // p = NULL
void* FUN_140e99a00(Unk_CashImagePtr* p, Unk_CashImage* pImage);            // p = pImage
Unk_CashImage* FUN_140e99a70(Unk_CashImagePtr* p);                          // get
Unk_CashImage* FUN_140e99a80(Unk_CashImagePtr* p);                          // operator->
Unk_CashImage* FUN_140d03240(Unk_CashImagePtr* p);                          // operator->
Unk_CashImagePtr FUN_140d03040(void* pRaw);                                 // wraps a raw object
Unk_CashImage* FUN_1422e5300(void* pMem, int nMovieId);                     // image holder ctor
void* FUN_1422e5a70(void* pMem, CStringW strUrl, int nMovieId);             // image source ctor
void FUN_1422e5530(Unk_CashImage* pImage, const Unk_CashImagePtr& spSource);
CStringW FUN_140e99600(const wchar_t* szFormat, const CString& strKey, const int& nWidth, const int& nHeight);   // StringFormat

class UITencentCashChargeDialog : public UIWebBrowserBase
{
public:
    UITencentCashChargeDialog();                                    // 0x140e99b90
    virtual ~UITencentCashChargeDialog();                           // 0x140e99c70 (deleting dtor 0x140e9a800)

    virtual CString GetTypeName();                                      //  1 0x140e99d30
    virtual void vfunc_8(int nVisible);                             //  8 0x140e99d80
    virtual void vfunc_16();                                        // 16 0x140e9a510
    virtual void OnLoadComplete();                                  // 22 0x140e99ec0
    virtual void vfunc_26();                                        // 26 0x140e9a110
    virtual void vfunc_43();                                        // 43 0x140e9a6f0
    virtual void vfunc_47(int n);                                   // 47 0x140e99cf0
    virtual int vfunc_48();                                         // 48 0x140e9a840
    virtual int vfunc_65();                                         // 65 0x140e9a760
    virtual void vfunc_67();                                        // 67 0x140e99e50
    virtual void vfunc_68();                                        // 68 0x140e99e90
    virtual void vfunc_85();                                        // 85 0x140e9a160
    virtual void vfunc_86();                                        // 86 0x140e9a410
    virtual void vfunc_87(SIZE* pSize);                             // 87 0x140e9a7a0
    virtual bool vfunc_90(POINT* pPos);                             // 90 0x140e9a550

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASUIComponent> FUN_140e48e10(const CString& strName, MS2Ptr<ASUIComponent>* pOut);   // finds the child and stores it in *pOut

    int m_nDialogWidth;                                             // +0x198
    int m_nDialogHeight;                                            // +0x19c
    MS2Ptr<ASUIComponent> m_spTarget;                               // +0x1a0 "m_renderTarget"
    Unk_CashImagePtr m_spImage;                                     // +0x1b0 the page image
};
MS2_CHECK_SIZE(UITencentCashChargeDialog, 0x1c0);
MS2_CHECK_OFFSET(UITencentCashChargeDialog, m_spTarget, 0x1a0);

// MS2-FUNCTIONAL: ctor EH state count differs
// @0x140e99b90
UITencentCashChargeDialog::UITencentCashChargeDialog()
    : UIWebBrowserBase(3)
{
    FUN_140e999b0(&m_spImage);
    m_84 = 1;
    m_e0 = 0;
    m_spTarget = 0;
    FUN_140e999d0(&m_spImage, 0);
}

// MS2-FUNCTIONAL: the exe dtor has no EH data
// @0x140e99c70
UITencentCashChargeDialog::~UITencentCashChargeDialog()
{
    FUN_140d030a0(&m_spImage);
}

// @0x140e99cf0
void UITencentCashChargeDialog::vfunc_47(int n)
{
    FUN_141901470(n, vfunc_48());
}

// @0x140e99d30
CString UITencentCashChargeDialog::GetTypeName()
{
    return CString("TencentCashChargeDialog");
}

// @0x140e99d80
void UITencentCashChargeDialog::vfunc_8(int nVisible)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        vfunc_47(nVisible == 0);
        pDialog->vfunc_3(nVisible);
        pDialog->FUN_1407cbbe0("visible", nVisible == 1);
    }
}

// @0x140e99e50
void UITencentCashChargeDialog::vfunc_67()
{
    vfunc_47(1);
    UIWebBrowserBase::vfunc_67();
}

// @0x140e99e90
void UITencentCashChargeDialog::vfunc_68()
{
    vfunc_8(0);
    UIDialog::vfunc_68();
}

// MS2-FUNCTIONAL: temporaries of the Value/CString returns differ
// @0x140e99ec0
void UITencentCashChargeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        m_nDialogWidth = *FUN_1402056b0(&FUN_1401d3200()->m_nWidth) + 0x1c;
        m_nDialogHeight = *FUN_1402056b0(&FUN_1401d3200()->m_nHeight) + 0x44;
        m_30->Invoke("setDialogSize", m_nDialogWidth, m_nDialogHeight);
    }
    vfunc_43();
    CString strName("m_renderTarget");
    FUN_140e48e10(strName, &m_spTarget);
    int nId = vfunc_88();
    const char* pszUrl = FUN_1401d3200()->m_strUrl.FUN_140298f80();
    FUN_140cc18a0()->FUN_141b781e0(m_nBrowserId, pszUrl, "", nId);
    vfunc_87(&m_size);
    FUN_140cc18a0()->FUN_141b788b0(m_nBrowserId, m_size.cx, m_size.cy);
    vfunc_85();
}

// @0x140e9a110
void UITencentCashChargeDialog::vfunc_26()
{
    UIWebBrowserBase::vfunc_26();
    m_spTarget = 0;
    FUN_140e999d0(&m_spImage, 0);
}

// MS2-FUNCTIONAL: operator new / ternary temporaries differ
// @0x140e9a160
void UITencentCashChargeDialog::vfunc_85()
{
    void* pMem = operator new(0x90);
    Unk_CashImage* pImage = 0;
    if (pMem != 0)
        pImage = FUN_1422e5300(pMem, 2);
    FUN_140e99a00(&m_spImage, pImage);
    void* pMem2 = operator new(0x40);
    void* pSource = 0;
    if (pMem2 != 0)
    {
        CString strKey = FUN_1422db6e0();
        pSource = FUN_1422e5a70(pMem2, FUN_140e99600(L"img://{0}:webBrowser/{1}/{2}", strKey, FUN_1401d3200()->m_nWidth.m_n, FUN_1401d3200()->m_nHeight.m_n), 2);
    }
    FUN_1422e5530(FUN_140d03240(&m_spImage), FUN_140d03040(pSource));
    if (m_spTarget.get() != 0)
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->FUN_1422c6900(FUN_140e99a80(&m_spImage)->FUN_1422bb890());
    }
}

// @0x140e9a410
void UITencentCashChargeDialog::vfunc_86()
{
    if ((m_spTarget.get() ? true : false) && (FUN_140e99a70(&m_spImage) ? true : false))
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->FUN_1422c6b70(FUN_140e99a80(&m_spImage)->FUN_1422bb890());
    }
}

// @0x140e9a510
void UITencentCashChargeDialog::vfunc_16()
{
    UIWebBrowserBase::vfunc_16();
    vfunc_86();
}

// @0x140e9a550
bool UITencentCashChargeDialog::vfunc_90(POINT* pPos)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return false;
    pPos->x -= pDialog->FUN_1422c10a0();
    pPos->y -= pDialog->FUN_1422c1110();
    if (m_spTarget == 0)
        return false;
    pPos->x -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(m_spTarget.operator->()))->FUN_1422c10a0();
    pPos->y -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(m_spTarget.operator->()))->FUN_1422c1110();
    if (!(pPos->x >= 0 && pPos->y >= 0 && !(pPos->x > *FUN_1402056b0(&FUN_1401d3200()->m_nWidth)) && pPos->y <= *FUN_1402056b0(&FUN_1401d3200()->m_nHeight)))
    {
        return false;
    }
    return true;
}

// @0x140e9a6f0
void UITencentCashChargeDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(0, 0, 0);
}

// @0x140e9a760
int UITencentCashChargeDialog::vfunc_65()
{
    if (!FUN_141900a90(this))
        return 0;
    return UIDialog::vfunc_65();
}

// @0x140e9a7a0
void UITencentCashChargeDialog::vfunc_87(SIZE* pSize)
{
    pSize->cx = *FUN_1402056b0(&FUN_1401d3200()->m_nWidth);
    pSize->cy = *FUN_1402056b0(&FUN_1401d3200()->m_nHeight);
}

// @0x140e9a840
int UITencentCashChargeDialog::vfunc_48()
{
    return 0x4f31;
}

// @0x140e9a850
MS2_EMIT_CRT_MEMMOVE_S();
