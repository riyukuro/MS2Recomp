// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's memorydepletiondlg.cpp: the two modal
// CDialogEx dialogs the client shows when it runs out of memory (resource 3000) and for a generic error notification
// (resource 0xbb9). Each is one text bound with DDX_Text; the memory dialog's link control (0x40a) opens the Nexon
// help page in the browser, and its "help" command remembers that the page was opened. See memorydepletiondlg.h.
// MS2-UNIT: ?\memorydepletiondlg.cpp
// MS2-RANGE: 0x140d53490-0x140d53ad0 .text$mn
// MS2-PIN: ?GetRuntimeClass@CMemoryDepletionDlg@@UEBAPEAUCRuntimeClass@@XZ 0x140d53490
// MS2-PIN: ?GetMessageMap@CMemoryDepletionDlg@@MEBAPEBUAFX_MSGMAP@@XZ 0x140d53600
// MS2-PIN: ?GetRuntimeClass@CErrorNotificationDlg@@UEBAPEAUCRuntimeClass@@XZ 0x140d53780
// MS2-PIN: ?GetMessageMap@CErrorNotificationDlg@@MEBAPEBUAFX_MSGMAP@@XZ 0x140d538b0
// MS2-PIN: ?_GetBaseClass@CErrorNotificationDlg@@KAPEAUCRuntimeClass@@XZ 0x140d53750
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\memorydepletiondlg.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <shellapi.h>

#include "memorydepletiondlg.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------


IMPLEMENT_DYNAMIC(CMemoryDepletionDlg, CDialogEx)

// @0x140d534b0
CMemoryDepletionDlg::CMemoryDepletionDlg(CWnd* pParent) : CDialogEx(3000, pParent)
{
    m_bHelpOpened = 0;
}

// @0x140d53520
CMemoryDepletionDlg::~CMemoryDepletionDlg()
{
}

// @0x140d53570
// The method only destroys its by-value argument (the client's out-of-memory path in util.cpp calls it with the
// localized caption before DoModal, alongside the class's real text setter 0x141b72590).
void CMemoryDepletionDlg::FUN_140d53570(CString strText)
{
    (void)strText;
}

// @0x140d535a0
void CMemoryDepletionDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, 0x40b, m_strText);
}

BEGIN_MESSAGE_MAP(CMemoryDepletionDlg, CDialogEx)
    ON_COMMAND(8, &CMemoryDepletionDlg::OnBnClickedOk)
    ON_NOTIFY(NM_CLICK, 0x40a, &CMemoryDepletionDlg::OnClickLink)
    ON_COMMAND(10, &CMemoryDepletionDlg::OnBnClickedHelp)
END_MESSAGE_MAP()

// @0x140d53620
void CMemoryDepletionDlg::OnBnClickedOk()
{
    if (m_bHelpOpened == 0)
        ::ShellExecuteW(0, L"open", L"http://cs.nexon.com/helpBoard/popuphelpview/1410", 0, 0, 1);
    CDialog::OnOK();
}

// @0x140d53680
void CMemoryDepletionDlg::OnClickLink(NMHDR* pNMHDR, LRESULT* pResult)
{
    m_bHelpOpened = 1;
    NMLINK* pLink = (NMLINK*)pNMHDR;
    ::ShellExecuteW(0, L"open", pLink->item.szUrl, 0, 0, 1);
    *pResult = 0;
}

// @0x140d53700
void CMemoryDepletionDlg::OnBnClickedHelp()
{
    m_bHelpOpened = 1;
    ::ShellExecuteW(0, L"open", L"http://cs.nexon.com/helpBoard/popuphelpview/1410", 0, 0, 1);
}

IMPLEMENT_DYNAMIC(CErrorNotificationDlg, CDialogEx)

// @0x140d537a0
CErrorNotificationDlg::CErrorNotificationDlg(CWnd* pParent) : CDialogEx(0xbb9, pParent)
{
}

// @0x140d53800
CErrorNotificationDlg::~CErrorNotificationDlg()
{
}

// @0x140d53850
void CErrorNotificationDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, 0x40c, m_strText);
}

BEGIN_MESSAGE_MAP(CErrorNotificationDlg, CDialogEx)
    ON_COMMAND(11, &CErrorNotificationDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// @0x140d538d0
void CErrorNotificationDlg::OnBnClickedOk()
{
    CDialog::OnOK();
}

// ---- the unreferenced CRT copy of this TU ---------------------------------------------------------------------------

MS2_EMIT_CRT_MEMMOVE_S();
