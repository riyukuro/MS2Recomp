// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TriggerDebugDialog: see triggerdebugdialog.h.
// MS2-UNIT: ?\triggerdebugdialog.cpp
// MS2-RANGE: 0x140b9b470-0x140b9c680 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\triggerdebugdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "triggerdebugdialog.h"

#include "ms2/client/ms2/uidialogcenterdialog.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/unnamed/unit_1406125d0.h"
#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

__int64 FUN_140869440();                                // server time
CStringW FUN_1408767c0(void* pszUtf8);                  // utf8 -> wide
CString FUN_1401d4330(const wchar_t* psz, int nFlag);   // wide -> narrow
CFileSystem* GetFileSystem();                           // the file system singleton
int FUN_140518af0(const CRect* pRect);                  // 0x140518af0 CRect::Height
int FUN_140519850(const CRect* pRect);                  // 0x140519850 CRect::Width
CRect* FUN_140517a60(CRect* pRect);                     // 0x140517a60 CRect::CRect()
LPRECT FUN_14098a2a0(CRect* pRect);                     // 0x14098a2a0 CRect::operator LPRECT
void FUN_140988d60(CStringW& strSrc, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep);   // 0x140988d60 (aidebugdialog)

// MS2-FUNCTIONAL: OnTimer (+ inlined GetCheck/Resize call sites) differ in callee order; permuter lane
IMPLEMENT_DYNAMIC(TriggerDebugDialog, CDialog)

// @0x140b9b490
TriggerDebugDialog::TriggerDebugDialog(CWnd* pParent)
    : CDialog(0xa7, pParent)
    , m_bInit(false)
    , m_nTimerId(0x66)
{
}

// @0x140b9b5c0
TriggerDebugDialog::~TriggerDebugDialog()
{
}

// @0x140b9b6b0
BOOL TriggerDebugDialog::OnInitDialog()
{
    if (!CDialog::OnInitDialog())
        return 0;
    if (!LoadXml())
        return 0;
    m_listTrace.InsertColumn(0, "Time", 0, -1, -1);
    m_listTrace.InsertColumn(1, "Log", 0, -1, -1);
    Resize();
    m_btnFollow.SetCheck(1);
    m_btnScroll.SetCheck(1);
    SetTimer(m_nTimerId, 100, 0);
    m_bInit = true;
    return 1;
}

// @0x140b9b7c0
BOOL TriggerDebugDialog::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN)
    {
        if (pMsg->wParam == VK_RETURN)
            return 0;
        if (pMsg->wParam == VK_ESCAPE)
            return 1;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

// @0x140b9b820
void TriggerDebugDialog::SetFile(CString strFile)
{
    m_strFile = strFile;
}

// @0x140b9b870
void TriggerDebugDialog::AddLine(int nLine)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    __int64 nTime = FUN_140869440();
    m_vecLines.push_back(std::make_pair(nLine, nTime));
}

// @0x140b9b8f0
void TriggerDebugDialog::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == m_nTimerId)
    {
        if (m_vecLines.empty())
            return;
        std::vector<std::pair<int, __int64> > vecLines;
        {
            Unk_LockGuard guard(m_lock);
            if (guard)
            {
            }
            else
            {
                vecLines = m_vecLines;
                m_vecLines.clear();
            }
        }
        for (size_t i = 0; i < vecLines.size() && m_btnFollow.GetCheck() == 1; i++)
        {
            std::pair<int, __int64>* pEntry = &vecLines[i];
            int nLine = pEntry->first;
            CTime time(pEntry->second);
            int nSecond = time.GetSecond();
            int nMinute = time.GetMinute();
            int nHour = time.GetHour();
            CStringW strTime = StringFormat(L"{0:02}:{1:02}:{2:02}", nHour, nMinute, nSecond);
            CStringW strLog;
            int nItem = m_listTrace.GetItemCount();
            if (nLine < 1)
            {
                strLog = L"Undefined Line";
            }
            else
            {
                long nStart = m_editXml.LineIndex(nLine - 1);
                long nEnd = m_editXml.LineIndex(nLine);
                m_editXml.SetSel(nStart, nEnd);
                char szLine[0x400] = { 0 };
                m_editXml.GetLine(nLine - 1, szLine, 0x400);
                CStringW strText(szLine);
                strText.Trim();
                strLog = strText;
            }
            m_listTrace.InsertItem(nItem, FUN_1401d4330(strTime, 0));
            m_listTrace.SetItemText(nItem, 1, FUN_1401d4330(strLog, 0));
            if (m_btnScroll.GetCheck() == 1)
                m_listTrace.EnsureVisible(nItem, 1);
        }
        Resize();
    }
    CDialog::OnTimer(nIDEvent);
}

// @0x140b9bd60
void TriggerDebugDialog::OnMoving(UINT fwSide, LPRECT pRect)
{
    CDialog::OnMoving(fwSide, pRect);
    if (m_bInit)
        Resize();
}

// @0x140b9bdb0
void TriggerDebugDialog::OnSize(UINT nType, int cx, int cy)
{
    CDialog::OnSize(nType, cx, cy);
    if (m_bInit)
        Resize();
}

// @0x140b9be10
void TriggerDebugDialog::OnDestroy()
{
    KillTimer(m_nTimerId);
}

// @0x140b9be40
void TriggerDebugDialog::OnClose()
{
    CDialog::OnClose();
    UIDialogCenterDialog* pCenter = Unk_LockDialog<UIDialogCenterDialog>(0x4ea9);
    if (pCenter)
        pCenter->SendSetDebugModeMode9(m_strFile);
}

// @0x140b9beb0
void TriggerDebugDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4f4, m_editXml);
    DDX_Control(pDX, 0x4f5, m_listTrace);
    DDX_Control(pDX, 0x4b6, m_btnFollow);
    DDX_Control(pDX, 0x4f6, m_btnScroll);
    DDX_Control(pDX, 0x4f7, m_btnClear);
}

// @0x140b9bf70
void TriggerDebugDialog::Resize()
{
    CRect rcClient;
    GetClientRect(rcClient);
    int nWidth = rcClient.Width() - 0x1e;
    int nXmlHeight = (int)((float)(rcClient.Height() - 0x46) * 0.7f);
    m_editXml.SetWindowPos(0, 0x14, 0x32, nWidth, nXmlHeight, SWP_NOZORDER | SWP_SHOWWINDOW);
    m_listTrace.SetWindowPos(0, 0x14, nXmlHeight + 0x3c, nWidth, (int)((float)(rcClient.Height() - 0x46) * 0.3f), SWP_NOZORDER | SWP_SHOWWINDOW);
    int nColumn;
    if ((int)((float)nWidth * 0.1f) < 100)
        nColumn = (int)((float)nWidth * 0.1f);
    else
        nColumn = 100;
    m_listTrace.SetColumnWidth(0, nColumn);
    m_listTrace.SetColumnWidth(1, (nWidth - nColumn) - 5);
}

// @0x140b9c190
int TriggerDebugDialog::LoadXml()
{
    SetWindowText(m_strFile);
    CFileSystem::BufferPtr spBuffer = GetFileSystem()->FUN_140397bc0(m_strFile, 0, 0);
    if (spBuffer.IsNull())
        return 0;
    CStringW strXml = FUN_1408767c0(spBuffer->GetBuffer());
    ATL::CAtlArray<CStringW> arrLines;
    FUN_140988d60(strXml, arrLines, L"\n");
    CStringW strText;
    for (size_t i = 0; i < arrLines.GetCount(); i++)
        strText += StringFormat(L"{0:03} : \t{1}\n", i + 1, arrLines[i]);
    m_editXml.SetWindowText(FUN_1401d4330(strText, 0));
    return 1;
}

// @0x140b9c410
void TriggerDebugDialog::OnClear()
{
    m_listTrace.DeleteAllItems();
}

BEGIN_MESSAGE_MAP(TriggerDebugDialog, CDialog)
    ON_WM_TIMER()
    ON_WM_MOVING()
    ON_WM_SIZE()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
    ON_CONTROL(BN_CLICKED, 0x4f7, &TriggerDebugDialog::OnClear)
END_MESSAGE_MAP()

// IMPLEMENT_DYNAMIC's _GetBaseClass sits just before this TU's range start in the exe.
// MS2-RANGE: 0x140b9b440-0x140b9b470 .text$mn
