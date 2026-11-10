// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITencentCashChargeDialog: the Tencent cash charge web page
// dialog, a UIWebBrowserBase (uiupperhuddialog.h) that renders the page into an image of its swf.
// MS2-UNIT: ?\uitencentcashchargedialog.cpp
// MS2-RANGE: 0x140e99b90-0x140e9a970 .text$mn
// MS2-PIN: ??_EUITencentCashChargeDialog@@WBHI@EAAPEAXI@Z 0x140e9a7ec
// MS2-PIN: ??_GUITencentCashChargeDialog@@UEAAPEAXI@Z 0x140e9a800
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitencentcashchargedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiupperhuddialog.h"
#include "uitencentaas2dialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/gfxui/asurlrequest.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get

// ---- exe callees ----
class Unk_AasImage : public AScript                                         // the image holder the page is drawn into (0x90 bytes)
{
public:
    char m_pad_ascript[0x90 - sizeof(AScript)];
};
typedef Unk_AasImage Unk_CashImage;
typedef Unk_AasImagePtr Unk_CashImagePtr;                                   // its smart pointer (uitencentaas2dialog.h)
class Unk_CashConstInt { public: int m_n; char m_pad_04[0x54]; };                                // one value of the client constants
class Unk_StringOptionEntry { public: char m_pad_00[0x60]; };   // C3: layout view of Common::Constants::Value<CString> (its Get() is 0x140298f80)
class Unk_CashConsts
{
public:
    char m_pad_0000[0xdb60];
    Unk_StringOptionEntry m_strUrl;                                              // +0xdb60
    Unk_CashConstInt m_nWidth;                                              // +0xdbc0
    Unk_CashConstInt m_nHeight;                                             // +0xdc18
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

class CWebBrowserService;

class ASDialog : public ASDisplayObject
{
public:
};

void FUN_141901470(int n, int nTypeId);
bool FUN_141900a90(class UIDialog*);   // C3: was FUN_141900a90
//Unk_CashImage* FUN_140d03240(Unk_CashImagePtr* p);                          // operator->   // C3 (ICF i29): MS2Ptr<ASLoader>::operator->
#include "ms2/ms2format.h"
#include "ms2/commonfiles/os.h"

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
    // 0x140e48e10 finds the child and stores it = UISwfEntity::GetChildInto<ASUIComponent> (uiswfentity.h)

    int m_nDialogWidth;                                             // +0x198
    int m_nDialogHeight;                                            // +0x19c
    MS2Ptr<ASUIComponent> m_spTarget;                               // +0x1a0 "m_renderTarget"
    Unk_CashImagePtr m_spImage;                                     // +0x1b0 the page image
};
MS2_CHECK_SIZE(UITencentCashChargeDialog, 0x1c0);
MS2_CHECK_OFFSET(UITencentCashChargeDialog, m_spTarget, 0x1a0);

// @0x140e99b90
UITencentCashChargeDialog::UITencentCashChargeDialog()
    : UIWebBrowserBase(3)
{
    m_84 = 1;
    m_e0 = 0;
    m_spTarget = 0;
    *((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage)) = 0;
}

// @0x140e99c70
UITencentCashChargeDialog::~UITencentCashChargeDialog()
{
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
        pDialog->SetBoolMember("visible", nVisible == 1);
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

// @0x140e99ec0
void UITencentCashChargeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        m_nDialogWidth = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nWidth)->Get() + 0x1c;
        m_nDialogHeight = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nHeight)->Get() + 0x44;
        m_30->Invoke("setDialogSize", m_nDialogWidth, m_nDialogHeight);
    }
    vfunc_43();
    GetChildInto<ASUIComponent>("m_renderTarget", m_spTarget);
    int nId = vfunc_88();
    TSingleton<CWebBrowserService>::GetInstance()->OpenBrowser(m_nBrowserId, *reinterpret_cast<Common::Constants::Value<CString>*>(&((class Unk_CashConsts*)GetClientConstants())->m_strUrl)->Get(), "", nId);
    vfunc_87(&m_size);
    TSingleton<CWebBrowserService>::GetInstance()->ResizeBrowser(m_nBrowserId, m_size.cx, m_size.cy);
    vfunc_85();
}

// @0x140e9a110
void UITencentCashChargeDialog::vfunc_26()
{
    UIWebBrowserBase::vfunc_26();
    m_spTarget = 0;
    *((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage)) = 0;
}

// @0x140e9a160
void UITencentCashChargeDialog::vfunc_85()
{
    ((void*)&((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage))->AssignRaw(new ASLoader(2)));
    ((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage))->operator->()->Load(MS2Ptr<ASURLRequest>(new ASURLRequest(StringFormat<CString, int, int>(L"img://{0}:webBrowser/{1}/{2}", GetManagerKey(), *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nWidth)->Get(), *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nHeight)->Get()), 2)));
    if (m_spTarget.get() != 0)
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->AddChild((&**((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage)))->FUN_1422bb890());
    }
}

// @0x140e9a410
void UITencentCashChargeDialog::vfunc_86()
{
    if ((m_spTarget.get() ? true : false) && (((class Unk_AasImage*)((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage))->get()) ? true : false))
    {
        static_cast<ASDisplayObjectContainer*>(m_spTarget.operator->())->RemoveChild((&**((MS2Ptr<ASLoader>*)(class Unk_AasImagePtr*)(&m_spImage)))->FUN_1422bb890());
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
    pPos->x -= pDialog->GetX();
    pPos->y -= pDialog->GetY();
    if (m_spTarget == 0)
        return false;
    pPos->x -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(m_spTarget.operator->()))->GetX();
    pPos->y -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(m_spTarget.operator->()))->GetY();
    if (!(pPos->x >= 0 && pPos->y >= 0 && !(pPos->x > *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nWidth)->Get()) && pPos->y <= *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nHeight)->Get()))
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
    if (!FUN_141900a90((class UIDialog*)(this)))
        return 0;
    return UIDialog::vfunc_65();
}

// @0x140e9a7a0
void UITencentCashChargeDialog::vfunc_87(SIZE* pSize)
{
    pSize->cx = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nWidth)->Get();
    pSize->cy = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_CashConsts*)GetClientConstants())->m_nHeight)->Get();
}

// @0x140e9a840
int UITencentCashChargeDialog::vfunc_48()
{
    return 0x4f31;
}

// @0x140e9a850
MS2_EMIT_CRT_MEMMOVE_S();
