// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's cashchargedialog.cpp: the cash charge web dialog,
// plus the header-inline code it instantiates (CExplorer1 wrapper, the UICashShopDialog handle, CDialogEx's dtor).
// MS2-UNIT: ?\cashchargedialog.cpp
// MS2-RANGE: 0x140b04a50-0x140b055c0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?GetRuntimeClass@CCashChargeDialog@@UEBAPEAUCRuntimeClass@@XZ 0x140b04a50
// MS2-PIN: ?GetMessageMap@CCashChargeDialog@@MEBAPEBUAFX_MSGMAP@@XZ 0x140b04e40
// MS2-PIN: ?GetEventSinkMap@CCashChargeDialog@@MEBAPEBUAFX_EVENTSINKMAP@@XZ 0x140b04e70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cashchargedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afxdialogex.h>
#include <exdisp.h>
#include "cashchargedialog.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cashshopref.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"

class UICashShopDialog : public UIObject
{
};

class Unk_CashShopUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
void FUN_141035920(UICashShopDialog* pDialog, int nArg);
void* FUN_140aadf80();                                              // the screen
void FUN_140ad4c30(void* pScreen, RECT* pRect);                     // the screen rect
void FUN_14098a440(CDialogEx* pDlg, CDataExchange* pDX);
void FUN_14098a5d0(CWnd* pWnd);
void FUN_14015b020(void* pCounted);                                 // adds a reference
void FUN_140159ba0(void* pCounted);

IMPLEMENT_DYNAMIC(CCashChargeDialog, CDialogEx)

// The UCRT's header-inline memcpy_s / memmove_s of this TU (0x<memcpy_s> / 0x<memmove_s>), kept alive through ATL::Checked.
// @0x140b0e380
#pragma function(memset, memcpy)
static __inline errno_t ms2_cud_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnCudMemcpyS)(void*, size_t, const void*, size_t) = &ms2_cud_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();

// @0x140b04a70
CCashChargeDialog::CCashChargeDialog(CWnd* pParent)
    : CDialogEx(0x94, pParent)
{
}

// @0x140b04af0
CCashChargeDialog::~CCashChargeDialog()
{
}

// @0x140b04b50
BOOL CCashChargeDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    if (m_strUrl.IsEmpty())
        m_strUrl = "about:blank";
    m_explorer.Navigate(m_strUrl, 0, 0, 0, 0);
    return 1;
}

// @0x140b04bf0
BOOL CCashChargeDialog::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->wParam == 0xd || pMsg->wParam == 0x1b)
        return 1;
    return CDialog::PreTranslateMessage(pMsg);
}

// @0x140b04c40
void CCashChargeDialog::Navigate(CString strUrl)
{
    if (strUrl.IsEmpty())
        return;
    m_strUrl = strUrl;
    m_explorer.Navigate(m_strUrl, 0, 0, 0, 0);
}

// @0x140b04cf0
void CCashChargeDialog::CenterOnScreen()
{
    RECT rcScreen;
    RECT rcWindow;
    FUN_140ad4c30(FUN_140aadf80(), &rcScreen);
    GetWindowRect(&rcWindow);
    int x = ((rcScreen.right - rcScreen.left) - (rcWindow.right - rcWindow.left)) / 2 + rcScreen.left;
    int y = ((rcScreen.bottom - rcScreen.top) - (rcWindow.bottom - rcWindow.top)) / 2 + rcScreen.top;
    int nWidth = rcWindow.right - rcWindow.left;
    int nHeight = rcWindow.bottom - rcWindow.top;
    MoveWindow(x, y, nWidth, nHeight, 1);
}

// @0x140b04de0
void CCashChargeDialog::DoDataExchange(CDataExchange* pDX)
{
    FUN_14098a440(this, pDX);
    DDX_Control(pDX, 0x4d4, m_explorer);
}

BEGIN_MESSAGE_MAP(CCashChargeDialog, CDialogEx)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

// @0x140b04ed0
void CCashChargeDialog::OnClose()
{
    {
        Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
        if (ref.FUN_140b051c0() != 0)
            FUN_141035920(ref.FUN_140b051d0(), 0);
    }
    FUN_14098a5d0(this);
}

BEGIN_EVENTSINK_MAP(CCashChargeDialog, CDialogEx)
    ON_EVENT(CCashChargeDialog, 0x4d4, 0xfc, CCashChargeDialog::OnNavigateComplete2, VTS_DISPATCH VTS_PVARIANT)
    ON_EVENT(CCashChargeDialog, 0x4d4, 0x103, CCashChargeDialog::OnDocumentComplete, VTS_DISPATCH VTS_PVARIANT)
    ON_EVENT(CCashChargeDialog, 0x4d4, 0x107, CCashChargeDialog::OnWindowClosing, VTS_BOOL VTS_PBOOL)
END_EVENTSINK_MAP()

// @0x140b04e90
void CCashChargeDialog::OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* pURL)
{
}

// @0x140b04eb0
void CCashChargeDialog::OnDocumentComplete(LPDISPATCH pDisp, VARIANT* pURL)
{
}

// @0x140b04f40
void CCashChargeDialog::OnWindowClosing(BOOL bIsChildWindow, BOOL* pbCancel)
{
    ::SendMessageA(m_hWnd, WM_CLOSE, 0, 0);
}

// @0x140b04f80
UICashShopDialog* FUN_140b04f80(int nId)
{
    if (reinterpret_cast<Unk_CashShopUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = reinterpret_cast<Unk_CashShopUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UICashShopDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140b05020
Unk_CashShopRef::Unk_CashShopRef(UICashShopDialog* pDialog)
{
    m_pDialog = pDialog;
    FUN_140b054b0();
}

// @0x140b05080
Unk_CashShopRef::~Unk_CashShopRef()
{
    FUN_140b05530();
}

// @0x140b051c0
UICashShopDialog* Unk_CashShopRef::FUN_140b051c0() const
{
    return m_pDialog;
}

// @0x140b051d0
UICashShopDialog* Unk_CashShopRef::FUN_140b051d0() const
{
    return m_pDialog;
}

// @0x140b054b0
void Unk_CashShopRef::FUN_140b054b0()
{
    if (m_pDialog != 0)
        FUN_140b05500(0);
}

// @0x140b054e0
void Unk_CashShopRef::FUN_140b054e0(UICashShopDialog* pDialog)
{
    FUN_14015b020(pDialog);
}

// @0x140b05500
void Unk_CashShopRef::FUN_140b05500(void*)
{
    FUN_140b054e0(m_pDialog);
}

// @0x140b05530
void Unk_CashShopRef::FUN_140b05530()
{
    if (m_pDialog != 0)
    {
        FUN_140b05570(0);
        m_pDialog = 0;
    }
}

// @0x140b05570
void Unk_CashShopRef::FUN_140b05570(void*)
{
    if (CPtred::ReleasePtred((class CPtred*)(m_pDialog)) == 0)
    {
        FUN_140b054e0(m_pDialog);
        FUN_140159ba0(m_pDialog);
    }
}
