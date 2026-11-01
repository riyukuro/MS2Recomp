// cloadingdialog.h - CLoadingDialog (RTTI .?AVCLoadingDialog@@, 0xf0 bytes): the startup splash window CGameApp::
// InitInstance (?\ms2.cpp) opens. Recovered from unit_140d4a310 (?\loadingdialog.cpp). Header name assumed; member
// names are invented from use. Not an original header.
// Open() starts a thread that builds the layered window from ./data/resource/image/loadingwindow/loading.bmp (+ an
// optional loading_mask.bmp alpha mask), pumps messages until Close() sets the event / closing flag.
#pragma once

#include <afx.h>
#include <atlimage.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CLoadingDialog : public CPtred
{
public:
    CLoadingDialog();                                       // 0x140d4a310
    virtual ~CLoadingDialog();                              // 0x140d4a3f0
    bool Open(const char* pszName, HINSTANCE hInst);   // Open(): names the window class, starts the thread
    void Close();                                           // 0x140d4a600: closing flag, set the event, join the thread
    void ThreadMain();                                      // 0x140d4ae50
private:
    void SetClosing() { m_bClosing = true; }                // 0x140d4a5e0
    HWND CreateWnd(DWORD dwExStyle, LPCSTR pszClass, LPCSTR pszTitle, DWORD dwStyle, int x, int y, int cx, int cy,
                   HWND hParent, HMENU hMenu, HINSTANCE hInst);     // 0x140d4a660
    bool RegisterWndClass(LPCSTR pszClass, HINSTANCE hInst);        // 0x140d4a770
    void FillWndClass(WNDCLASSEXA* pwc);                            // 0x140d4a800
    LRESULT OnMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // 0x140d4a8d0
    void OnEraseBkgnd(HWND hWnd);                                   // 0x140d4a9c0
    void OnPaint(HWND hWnd);                                        // 0x140d4aa10
    void Paint(HDC hdc);                                            // 0x140d4aa90
    void CenterRect(RECT* prc, int cx, int cy);                     // 0x140d4aae0
    bool LoadImages();                                              // 0x140d4ac70
    bool LoadImage(const CString& strPath, CImage* pImage);        // 0x140d4b2f0
    void DrawImage(HDC hdc, CImage* pImage);                        // 0x140d4b5a0
    bool ApplyMask(CImage* pMask, CImage* pSrc, CImage* pDest);    // 0x140d4b5f0
    static unsigned __stdcall ThreadProc(void* p);                  // 0x140d4b8c0
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);    // 0x140d4b8f0

    MS2_LAYOUT_FRIEND;
    HWND m_hWnd;                    // +0x18
    HINSTANCE m_hInst;              // +0x20
    bool m_bDestroyed;              // +0x28
    CString m_strClass;             // +0x30
    bool m_bLoading;                // +0x38
    bool m_bClosing;                // +0x39
    bool m_bInteractive;            // +0x3a
    HANDLE m_hThread;               // +0x40
    HANDLE m_hEvent;                // +0x48
    CImage m_imgBack;               // +0x50
    CImage m_imgMask;               // +0xa0
};
MS2_CHECK_SIZE(CLoadingDialog, 0xf0);
