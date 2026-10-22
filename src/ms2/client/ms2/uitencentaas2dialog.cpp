// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITencentAas2Dialog: see uitencentaas2dialog.h. w276.
// MS2-UNIT: ?\uitencentaas2dialog.cpp
// MS2-RANGE: 0x140e988a0-0x140e99b90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?vfunc_48@UITencentAas2Dialog@@UEAAHXZ 0x140e99ae0
// MS2-PIN: ??_EUITencentAas2Dialog@@WBHI@EAAPEAXI@Z 0x140e99a90
// MS2-PIN: ??_GUITencentAas2Dialog@@UEAAPEAXI@Z 0x140e99aa0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitencentaas2dialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uitencentaas2dialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
class Unk_AasImage : public AScript {};                                     // the image holder the page is drawn into (0x90 bytes)
struct Unk_AasSourcePtr                                                     // the image source handle (16 bytes, pointer at +8)
{
    void* m_0;
    void* m_p;
};
class Unk_AasConstInt { public: int m_n; char m_pad_04[0x54]; };            // one value of the client constants
class Unk_AasConsts
{
public:
    char m_pad_0000[0xdbc0];
    Unk_AasConstInt m_nWidth;                                               // +0xdbc0
    Unk_AasConstInt m_nHeight;                                              // +0xdc18
};
Unk_AasConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_AasConstInt* p);

class Unk_AasBrowserMgr
{
public:
    void FUN_141b781e0(int nId, const char* pszFrom, const char* pszTo, int n);
    void FUN_141b788b0(int nId, int nWidth, int nHeight);
};
Unk_AasBrowserMgr* FUN_140cc18a0();

class ASDialog : public ASDisplayObject
{
public:
    float FUN_1422c10a0();                                                  // x
    float FUN_1422c1110();                                                  // y
    void FUN_1407cbbe0(const char* szName, bool b);                         // set a bool member
};

void FUN_141901470(int n, int nTypeId);
bool FUN_141900a90(UIObject* pObject);
CString FUN_14016a600(const wchar_t* psz, int n);                           // wide -> narrow string
void FUN_140d03450(Unk_AasImagePtr* p);                                     // p = NULL (releases)
void FUN_140d03320(Unk_AasImage* p);                                        // add a reference
Unk_AasImage* FUN_140d03240(Unk_AasImagePtr* p);                            // operator->
Unk_AasSourcePtr FUN_140d03040(void* pRaw);                                 // wraps a raw object
Unk_AasImage* FUN_1422e5300(void* pMem, int nMovieId);                      // image holder ctor
void* FUN_1422e5a70(void* pMem, CStringW strUrl, int nMovieId);             // image source ctor
void FUN_1422e5530(Unk_AasImage* pImage, const Unk_AasSourcePtr& spSource);
void FUN_1416a0e70();
CNetworkService* FUN_140714f90();

// ---- Unk_AasImagePtr (inline COMDATs of this unit) ----

// @0x140e999b0
Unk_AasImagePtr::Unk_AasImagePtr()
{
    m_p = 0;
}

// @0x140e99980
Unk_AasImagePtr::Unk_AasImagePtr(Unk_AasImage* p)
{
    m_p = p;
    AddRef();
}

// @0x140e999d0
Unk_AasImagePtr& Unk_AasImagePtr::operator=(int nNull)
{
    FUN_140d03450(this);
    return *this;
}

// @0x140e99a00
Unk_AasImagePtr& Unk_AasImagePtr::AssignRaw(Unk_AasImage* p)
{
    Unk_AasImagePtr tmp(p);
    Unk_AasImage* pOld = m_p;
    m_p = tmp.m_p;
    tmp.m_p = pOld;
    return *this;
}

// @0x140e99a70
Unk_AasImage* Unk_AasImagePtr::get() const
{
    return m_p;
}

// @0x140e99a80
Unk_AasImage* Unk_AasImagePtr::operator->() const
{
    return m_p;
}

// @0x140e99b30
void Unk_AasImagePtr::AddRef() const
{
    if (m_p != 0)
        AddRefImpl(0);
}

// @0x140e99b60
void Unk_AasImagePtr::AddRefImpl(void*) const
{
    FUN_140d03320(m_p);
}

// ---- UITencentAas2Dialog ----

// @0x140e988a0
UITencentAas2Dialog::UITencentAas2Dialog()
    : UIWebBrowserBase(6), m_nExitOnClose(1)
{
    m_e0 = 0;
    m_spTarget = 0;
    m_spImage = 0;
    m_strPage = "";
    m_nExitOnClose = 0;
}

// @0x140e989c0
UITencentAas2Dialog::~UITencentAas2Dialog()
{
}

// @0x140e98a50
void UITencentAas2Dialog::FUN_140e98a50(CStringW strUrl, int nExitOnClose)
{
    m_strPage = FUN_14016a600(strUrl, 0);
    m_nExitOnClose = nExitOnClose;
}
MS2_REPLACE_METHOD(0x140E98A50, UITencentAas2Dialog, FUN_140e98a50, 138, 0xE5652FDE);

// @0x140e98ae0
void UITencentAas2Dialog::vfunc_47(int n)
{
    FUN_141901470(n, vfunc_48());
}
MS2_REPLACE_METHOD(0x140E98AE0, UITencentAas2Dialog, vfunc_47, 48, 0xF0165C7B);

// @0x140e98b20
CString UITencentAas2Dialog::GetTypeName()
{
    return CString("TencentAas2Dialog");
}
MS2_REPLACE_METHOD(0x140E98B20, UITencentAas2Dialog, GetTypeName, 61, 0x15733BAA);

// @0x140e98b70
void UITencentAas2Dialog::vfunc_8(int nVisible)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        vfunc_47(nVisible == 0);
        pDialog->vfunc_3(nVisible);
        pDialog->FUN_1407cbbe0("visible", nVisible == 1);
    }
}
MS2_REPLACE_METHOD(0x140E98B70, UITencentAas2Dialog, vfunc_8, 190, 0x8228A48D);

// @0x140e98c40
void UITencentAas2Dialog::vfunc_67()
{
    vfunc_47(1);
    UIWebBrowserBase::vfunc_67();
    if (m_nExitOnClose == 1)
    {
        FUN_140714f90()->FUN_1415388a0();
        FUN_1416a0e70();
        PostQuitMessage(0);
    }
}
MS2_REPLACE_METHOD(0x140E98C40, UITencentAas2Dialog, vfunc_67, 88, 0xABF83C9A);

// @0x140e98ca0
void UITencentAas2Dialog::vfunc_68()
{
    vfunc_8(0);
    UIDialog::vfunc_68();
}
MS2_REPLACE_METHOD(0x140E98CA0, UITencentAas2Dialog, vfunc_68, 42, 0x942CEDD9);

// @0x140e98cd0
// MS2-FUNCTIONAL: one byte shorter in the exe (temporaries of the Value return)
void UITencentAas2Dialog::OnLoadComplete()
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
    const char* pszUrl = m_strPage;
    FUN_140cc18a0()->FUN_141b781e0(m_nBrowserId, pszUrl, "", nId);
    vfunc_87(&m_size);
    FUN_140cc18a0()->FUN_141b788b0(m_nBrowserId, m_size.cx, m_size.cy);
    vfunc_85();
}
MS2_REPLACE_METHOD(0x140E98CD0, UITencentAas2Dialog, OnLoadComplete, 575, 0x1D3A196F);

// @0x140e98f20
void UITencentAas2Dialog::vfunc_26()
{
    UIWebBrowserBase::vfunc_26();
    m_spTarget = 0;
    m_spImage = 0;
}
MS2_REPLACE_METHOD(0x140E98F20, UITencentAas2Dialog, vfunc_26, 66, 0x3FE26FC5);

// @0x140e98f70
// MS2-FUNCTIONAL: operator new / ternary temporaries and the conditional-destruct flag differ
void UITencentAas2Dialog::vfunc_85()
{
    void* pMem = operator new(0x90);
    Unk_AasImage* pImage = 0;
    if (pMem != 0)
        pImage = FUN_1422e5300(pMem, 2);
    m_spImage.AssignRaw(pImage);
    void* pMem2 = operator new(0x40);
    void* pSource = 0;
    if (pMem2 != 0)
    {
        CString strKey = FUN_1422db6e0();
        pSource = FUN_1422e5a70(pMem2, StringFormat(L"img://{0}:webBrowser/{1}/{2}", strKey, *FUN_1402056b0(&FUN_1401d3200()->m_nWidth), *FUN_1402056b0(&FUN_1401d3200()->m_nHeight)), 2);
    }
    FUN_1422e5530(FUN_140d03240(&m_spImage), FUN_140d03040(pSource));
    if (m_spTarget.get() != 0)
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->FUN_1422c6900(m_spImage->FUN_1422bb890());
    }
}
MS2_REPLACE_METHOD(0x140E98F70, UITencentAas2Dialog, vfunc_85, 681, 0x07764DF1);

// @0x140e99220
void UITencentAas2Dialog::vfunc_86()
{
    if ((m_spTarget.get() ? true : false) && (m_spImage.get() ? true : false))
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->FUN_1422c6b70(m_spImage->FUN_1422bb890());
    }
}
MS2_REPLACE_METHOD(0x140E99220, UITencentAas2Dialog, vfunc_86, 248, 0xED12BCA0);

// @0x140e99320
void UITencentAas2Dialog::vfunc_16()
{
    UIWebBrowserBase::vfunc_16();
    vfunc_86();
}
MS2_REPLACE_METHOD(0x140E99320, UITencentAas2Dialog, vfunc_16, 43, 0xF4EC688D);

// @0x140e99360
bool UITencentAas2Dialog::vfunc_90(POINT* pPos)
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
MS2_REPLACE_METHOD(0x140E99360, UITencentAas2Dialog, vfunc_90, 397, 0xDFE00266);

// @0x140e99500
void UITencentAas2Dialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(0, 0, 0);
}
MS2_REPLACE_METHOD(0x140E99500, UITencentAas2Dialog, vfunc_43, 100, 0xA8EB34E7);

// @0x140e99570
int UITencentAas2Dialog::vfunc_65()
{
    if (!FUN_141900a90(this))
        return 0;
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x140E99570, UITencentAas2Dialog, vfunc_65, 45, 0xDB9A9168);

// @0x140e995b0
void UITencentAas2Dialog::vfunc_87(SIZE* pSize)
{
    pSize->cx = *FUN_1402056b0(&FUN_1401d3200()->m_nWidth);
    pSize->cy = *FUN_1402056b0(&FUN_1401d3200()->m_nHeight);
}
MS2_REPLACE_METHOD(0x140E995B0, UITencentAas2Dialog, vfunc_87, 76, 0xE5340123);
