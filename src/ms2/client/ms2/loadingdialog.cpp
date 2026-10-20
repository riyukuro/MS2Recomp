// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CLoadingDialog: the startup splash window (layered
// window drawn from loading.bmp, optionally alpha-masked by loading_mask.bmp), plus the ATL::CImage / Gdiplus inlines.
// MS2-UNIT: ?\loadingdialog.cpp
// MS2-RANGE: 0x140d4a310-0x140d4dce0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CComPtr@UIStream@@@ATL@@QEAA@XZ 0x140d4ba00 ; unique
// MS2-PIN: ??0?$CComPtrBase@UIStream@@@ATL@@IEAA@XZ 0x140d4ba20 ; unique
// MS2-PIN: ??1?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEAA@XZ 0x140d4bf10 ; unique
// MS2-PIN: ?SetStatus@Graphics@Gdiplus@@IEBA?AW4Status@2@W432@@Z 0x140d4d8c0 ; unique
// MS2-PIN: ?SetStatus@Image@Gdiplus@@IEBA?AW4Status@2@W432@@Z 0x140d4d8f0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES

#include "ms2/placeholder/cloadingdialog.h"

#include <afxwin.h>
#include <process.h>
#include <shlwapi.h>
#include <atlcomcli.h>

#include "ms2/placeholder/ms2memfile.h"
#include "ms2/placeholder/ms2ptr_impl.h"

CString FUN_140188f50(const char* psz, int n);
extern unsigned __int64 DAT_143a4a5e8;

// @0x140d4a310
CLoadingDialog::CLoadingDialog()
    : m_hWnd(0), m_bDestroyed(false), m_bLoading(false), m_bClosing(false), m_bInteractive(false), m_hThread(0),
      m_hEvent(0)
{
    m_strClass = "";
}

// @0x140d4a3f0
CLoadingDialog::~CLoadingDialog()
{
    Close();
    if (!m_imgBack.IsNull() == false)
        m_imgBack.Destroy();
    if (!m_imgMask.IsNull() == false)
        m_imgMask.Destroy();
    m_bDestroyed = true;
    UnregisterClassA(m_strClass, m_hInst);
    if (m_hEvent != 0)
        CloseHandle(m_hEvent);
    if (m_hThread != 0)
        CloseHandle(m_hThread);
}

// @0x140d4a530
bool CLoadingDialog::FUN_140d4a530(const char* pszName, HINSTANCE hInst)
{
    m_hInst = hInst;
    m_strClass = FUN_140188f50(pszName, 0);
    m_hThread = (HANDLE)_beginthreadex(0, 0, ThreadProc, this, 0, 0);
    return true;
}

// @0x140d4a600
void CLoadingDialog::Close()
{
    SetClosing();
    if (m_hEvent != 0)
        SetEvent(m_hEvent);
    if (m_hThread != 0)
        WaitForSingleObject(m_hThread, 0xffffffff);
}

struct Unk_CreateParams
{
    char pad[0x30];
    CLoadingDialog* pThis;
};

// @0x140d4a660
HWND CLoadingDialog::CreateWnd(DWORD dwExStyle, LPCSTR pszClass, LPCSTR pszTitle, DWORD dwStyle, int x, int y, int cx,
                               int cy, HWND hParent, HMENU hMenu, HINSTANCE hInst)
{
    if (!RegisterWndClass(pszClass, hInst))
        return 0;
    Unk_CreateParams params = {};
    params.pThis = this;
    return CreateWindowExA(dwExStyle, pszClass, pszTitle, dwStyle, x, y, cx, cy, hParent, hMenu, hInst, &params);
}

// @0x140d4a770
bool CLoadingDialog::RegisterWndClass(LPCSTR pszClass, HINSTANCE hInst)
{
    WNDCLASSEXA wc;
    if (!GetClassInfoExA(hInst, pszClass, &wc))
    {
        FillWndClass(&wc);
        wc.hInstance = hInst;
        wc.lpszClassName = pszClass;
        if (!RegisterClassExA(&wc))
            return false;
    }
    return true;
}

// @0x140d4a800
void CLoadingDialog::FillWndClass(WNDCLASSEXA* pwc)
{
    memset(pwc, 0, sizeof(*pwc));
    pwc->cbSize = sizeof(WNDCLASSEXA);
    pwc->style = CS_HREDRAW | CS_VREDRAW;
    pwc->lpfnWndProc = (WNDPROC)WndProc;
    pwc->cbClsExtra = 0;
    pwc->cbWndExtra = 0;
    pwc->hInstance = 0;
    pwc->hIcon = 0;
    pwc->hCursor = LoadCursorA(0, IDC_ARROW);
    pwc->hbrBackground = 0;
    pwc->lpszMenuName = 0;
    pwc->lpszClassName = 0;
    pwc->hIconSm = 0;
}

// @0x140d4a8d0
LRESULT CLoadingDialog::OnMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (m_bLoading)
        return 0;
    if (m_bClosing)
        return 0;
    if (uMsg == WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    else
    {
        if (uMsg == WM_PAINT)
        {
            OnEraseBkgnd(hWnd);
            return 0;
        }
        if (uMsg == WM_ERASEBKGND)
        {
            OnPaint(hWnd);
            return 0;
        }
        if (uMsg == WM_LBUTTONDOWN)
        {
            if (m_bInteractive)
                DefWindowProcA(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, lParam);
            return 0;
        }
    }
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// @0x140d4a9c0
void CLoadingDialog::OnEraseBkgnd(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);
    if (hdc != 0)
        SetBkMode(hdc, TRANSPARENT);
}

// @0x140d4aa10
void CLoadingDialog::OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);
    Paint(ps.hdc);
    EndPaint(hWnd, &ps);
}

// @0x140d4aa90
void CLoadingDialog::Paint(HDC hdc)
{
    if (!m_imgBack.IsNull())
        DrawImage(hdc, &m_imgBack);
}

// @0x140d4aae0
void CLoadingDialog::CenterRect(RECT* prc, int cx, int cy)
{
    int nScreenX = GetSystemMetrics(SM_CXSCREEN);
    int nScreenY = GetSystemMetrics(SM_CYSCREEN);
    int nW = cx;
    if (nScreenX < cx)
        nW = nScreenX;
    int nH = cy;
    if (nScreenY < cy)
        nH = nScreenY;
    int nLeft = prc->left;
    int nRight = prc->right;
    int nTop = prc->top;
    int nBottom = prc->bottom;
    float fX = (float)(nScreenX - (nRight - nLeft)) * 0.5f;
    prc->left = (int)(0.0f <= fX ? fX : 0.0f);
    prc->right = prc->left + nW;
    float fY = (float)(nScreenY - (nBottom - nTop)) * 0.5f;
    prc->top = (int)(0.0f <= fY ? fY : 0.0f);
    prc->bottom = prc->top + nH;
}

// @0x140d4ac70
bool CLoadingDialog::LoadImages()
{
    CString strBack("./data/resource/image/loadingwindow/loading.bmp");
    CImage img;
    if (strBack.IsEmpty() || !LoadImage(strBack, &img))
        return false;
    if (img.GetBPP() == 24)
    {
        CString strMask("./data/resource/image/loadingwindow/loading_mask.bmp");
        if (!strMask.IsEmpty() && LoadImage(strMask, &m_imgMask) && ApplyMask(&m_imgMask, &img, &m_imgBack))
            return true;
    }
    HBITMAP hBitmap = img.Detach();
    m_imgBack.Attach(hBitmap);
    return true;
}

// @0x140d4ae50
void CLoadingDialog::ThreadMain()
{
    m_bLoading = true;
    bool bLoaded = LoadImages();
    m_bLoading = false;
    if (!bLoaded || m_imgBack.IsNull())
        return;
    int nWidth = m_imgBack.GetWidth();
    int nHeight = m_imgBack.GetHeight();
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = nWidth;
    rc.bottom = nHeight;
    CenterRect(&rc, nWidth, nHeight);
    AdjustWindowRect(&rc, WS_POPUP, FALSE);
    const char* pszClass = m_strClass;
    DWORD dwExStyle = 8;
    if (!m_bInteractive)
        dwExStyle = 0x28;
    if (m_imgBack.GetBPP() >= 32)
        dwExStyle |= WS_EX_LAYERED;
    m_hWnd = CreateWnd(dwExStyle, pszClass, pszClass, WS_POPUP, 0, 0, 0, 0, 0, 0, m_hInst);
    if (m_hWnd == 0)
        return;
    SetWindowPos(m_hWnd, 0, rc.left, rc.top, nWidth, nHeight, SWP_NOZORDER | SWP_NOACTIVATE);
    if (!m_bInteractive)
        EnableWindow(m_hWnd, FALSE);
    if ((dwExStyle & WS_EX_LAYERED) != 0 && !m_imgBack.IsNull())
    {
        POINT ptSrc = {0, 0};
        SIZE sz = {nWidth, nHeight};
        HDC hdcSrc = m_imgBack.GetDC();
        BLENDFUNCTION bf;
        bf.BlendOp = 0;
        bf.BlendFlags = 0;
        bf.SourceConstantAlpha = 0xff;
        bf.AlphaFormat = 1;
        UpdateLayeredWindow(m_hWnd, 0, 0, &sz, hdcSrc, &ptSrc, 0xffffff, &bf, ULW_ALPHA);
        m_imgBack.ReleaseDC();
    }
    ShowWindow(m_hWnd, SW_SHOW);
    UpdateWindow(m_hWnd);
    MSG msg;
    msg.message = 0;
    if (m_hEvent == 0)
        m_hEvent = CreateEventA(0, FALSE, FALSE, 0);
    do
    {
        while (true)
        {
            if (msg.message == WM_QUIT)
                return;
            if (m_bClosing)
                return;
            int bMsg = PeekMessageW(&msg, 0, 0, 0, PM_REMOVE) != 0;
            if (bMsg == 0)
                break;
            if (AfxPreTranslateMessage(&msg) == 0)
            {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        }
    } while (WaitForSingleObject(m_hEvent, 0) != 0);
}

// @0x140d4b2f0
bool CLoadingDialog::LoadImage(const CString& strPath, CImage* pImage)
{
    MS2MemFile file((const char*)strPath);
    if (!file)
        return false;
    unsigned int nSize = file.GetFileSize();
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, nSize);
    void* pData = GlobalLock(hMem);
    file.FUN_141627270(pData, nSize);
    file.GetFileSize();
    GlobalUnlock(hMem);
    CComPtr<IStream> spStream;
    spStream.Attach(SHCreateMemStream((const BYTE*)pData, nSize));
    pImage->Load(spStream);
    if (pImage->GetBPP() >= 32)
    {
        int nWidth = pImage->GetWidth();
        int nHeight = pImage->GetHeight();
        for (int y = 0; y < nHeight; y++)
        {
            for (int x = 0; x < nWidth; x++)
            {
                BYTE* p = (BYTE*)pImage->GetPixelAddress(x, y);
                BYTE a = p[3];
                if (a != 0xff)
                {
                    p[0] = (BYTE)((p[0] * a + 0x80) >> 8);
                    p[1] = (BYTE)((p[1] * a + 0x80) >> 8);
                    p[2] = (BYTE)((p[2] * a + 0x80) >> 8);
                }
            }
        }
    }
    return true;
}

// @0x140d4b5a0
void CLoadingDialog::DrawImage(HDC hdc, CImage* pImage)
{
    if (!pImage->IsNull())
        pImage->Draw(hdc, 0, 0);
}

// @0x140d4b5f0
bool CLoadingDialog::ApplyMask(CImage* pMask, CImage* pSrc, CImage* pDest)
{
    if (pMask->GetBPP() < 8)
        return false;
    if (pMask->GetWidth() != pSrc->GetWidth() && pMask->GetHeight() != pSrc->GetHeight())
        return false;
    if (!pDest->Create(pSrc->GetWidth(), pSrc->GetHeight(), 32, 0))
        return false;
    int nWidth = pSrc->GetWidth();
    int nHeight = pSrc->GetHeight();
    for (int y = 0; y < nHeight; y++)
    {
        for (int x = 0; x < nWidth; x++)
        {
            BYTE* pD = (BYTE*)pDest->GetPixelAddress(x, y);
            BYTE* pS = (BYTE*)pSrc->GetPixelAddress(x, y);
            char* pM = (char*)pMask->GetPixelAddress(x, y);
            BYTE a = (BYTE)(-*pM - 1);
            if (a == 0)
            {
                pD[0] = 0;
                pD[1] = 0;
                pD[2] = 0;
            }
            else
            {
                pD[0] = (BYTE)((pS[0] * a + 0x80) >> 8);
                pD[1] = (BYTE)((pS[1] * a + 0x80) >> 8);
                pD[2] = (BYTE)((pS[2] * a + 0x80) >> 8);
            }
            pD[3] = a;
        }
    }
    return true;
}

// @0x140d4b8c0
unsigned __stdcall CLoadingDialog::ThreadProc(void* p)
{
    ((CLoadingDialog*)p)->ThreadMain();
    return 0;
}

// @0x140d4b8f0
LRESULT CALLBACK CLoadingDialog::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LONG_PTR p;
    if (uMsg == WM_NCCREATE)
    {
        p = (LONG_PTR)((Unk_CreateParams*)((CREATESTRUCTA*)lParam)->lpCreateParams)->pThis;
        SetWindowLongPtrA(hWnd, GWLP_USERDATA, p);
    }
    else
    {
        p = GetWindowLongPtrA(hWnd, GWLP_USERDATA);
    }
    CLoadingDialog* pThis = (CLoadingDialog*)p;
    if (pThis == 0 || pThis->m_bDestroyed)
        return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    return pThis->OnMessage(hWnd, uMsg, wParam, lParam);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5020-0x142ca5060 .text$yd
