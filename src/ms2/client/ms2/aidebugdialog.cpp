// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AiDebugDialog: see aidebugdialog.h.
// MS2-UNIT: ?\aidebugdialog.cpp
// MS2-RANGE: 0x140987b20-0x14098a990 .text$mn
// MS2-PIN: ??$?0AEAHAEA_J$0A@@?$pair@H_J@std@@QEAA@AEAHAEA_J@Z 0x140988c90 ; hand: make_pair 0x140989fa0 calls it
// MS2-PIN: ??$?0HAEA_J$0A@@?$pair@H_J@std@@QEAA@$$QEAHAEA_J@Z 0x140988ce0 ; hand: make_pair 0x140989ff0 calls it
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@H_J@std@@@?$vector@U?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@AEAAX$$QEAU?$pair@H_J@1@@Z 0x1409898e0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@H_J@std@@@?$vector@U?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@QEAAPEAU?$pair@H_J@1@QEAU21@$$QEAU21@@Z 0x1409899a0 ; unique
// MS2-PIN: ??$emplace_back@U?$pair@H_J@std@@@?$vector@U?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@QEAAX$$QEAU?$pair@H_J@1@@Z 0x140989f20 ; unique
// MS2-PIN: ??$make_pair@AEAHAEA_J@std@@YA?AU?$pair@H_J@0@AEAHAEA_J@Z 0x140989fa0 ; prop
// MS2-PIN: ??$make_pair@HAEA_J@std@@YA?AU?$pair@H_J@0@$$QEAHAEA_J@Z 0x140989ff0 ; unique
// MS2-PIN: ??_GCListCtrl@@UEAAPEAXI@Z 0x14098a320 ; order
// MS2-PIN: ??_GCRichEditCtrl@@UEAAPEAXI@Z 0x14098a380 ; order
// MS2-PIN: ?push_back@?$vector@U?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@QEAAX$$QEAU?$pair@H_J@2@@Z 0x14098a960 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\aidebugdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "aidebugdialog.h"

#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

__int64 FUN_140869440();                                // server time
CStringW FUN_1408767c0(void* pszUtf8);                  // utf8 -> wide
CString FUN_1401d4330(const wchar_t* psz, int nFlag);   // wide -> narrow
CStringW FUN_14025a640(const CStringW& str);            // copy
size_t FUN_14041ad70(ATL::CAtlArray<CStringW>* pArray, const CStringW& str);   // CAtlArray<CStringW>::Add (the exe copy of gameeventcontext)
CFileSystem* GetFileSystem();                           // the file system singleton
int FUN_140518af0(const CRect* pRect);                  // 0x140518af0 CRect::Height
int FUN_140519850(const CRect* pRect);                  // 0x140519850 CRect::Width
CRect* FUN_140517a60(CRect* pRect);                     // 0x140517a60 CRect::CRect()
LPRECT FUN_14098a2a0(CRect* pRect);                     // 0x14098a2a0 CRect::operator LPRECT

void FUN_140988d60(CStringW& strSrc, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep);   // 0x140988d60

IMPLEMENT_DYNAMIC(AiDebugDialog, CDialog)

// @0x140987b40
AiDebugDialog::AiDebugDialog(CWnd* pParent)
    : CDialog(0xa5, pParent)
    , m_nId(0)
    , m_nStartCount(0)
    , m_bInit(false)
    , m_nMarginLeft(0x14)
    , m_nMarginRight(10)
    , m_nMarginTop(0x32)
    , m_nMarginBottom(10)
    , m_nGap(10)
    , m_nTimerId(0x65)
{
}

// @0x140987ca0
AiDebugDialog::~AiDebugDialog()
{
}

// @0x140987d60
BOOL AiDebugDialog::OnInitDialog()
{
    if (!CDialog::OnInitDialog())
        return 0;
    if (!LoadXml())
        return 0;
    m_listTrace.RemoveAllGroups();
    m_listTrace.InsertColumn(0, "Time", 0, -1, -1);
    m_listTrace.InsertColumn(1, "Log", 0, -1, -1);
    m_listTrace.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    Resize();
    SetTimer(m_nTimerId, 100, 0);
    m_bInit = true;
    m_nStartCount = 0;
    return 1;
}

// @0x140987e80
BOOL AiDebugDialog::PreTranslateMessage(MSG* pMsg)
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

// @0x140987ee0
void AiDebugDialog::SetTarget(CString strFile, int nId)
{
    m_strFile = strFile;
    m_nId = nId;
}

// @0x140987f40
void AiDebugDialog::AddLine(int nId, int nLine)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_nId != nId)
        return;
    __int64 nTime = FUN_140869440();
    m_vecLines.push_back(std::make_pair(nLine, nTime));
}

// @0x140987fe0
void AiDebugDialog::RequestTrace()
{
    COutPacket packet(static_cast<int>(SendOp::SetDebugMode), 0);
    packet.WriteUInt8(4);
    packet.WriteInt32(m_nId);
    packet.WriteUInt8(7);
    packet.WriteInt64(0);
    FUN_140710590(packet);
}

// @0x140988060
void AiDebugDialog::OnTimer(UINT_PTR nIDEvent)
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
        for (size_t i = 0; i < vecLines.size(); i++)
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
            if (nLine < 0)
            {
                strLog = L"Undefined Line";
            }
            else if (nLine == 0)
            {
                strLog = StringFormat(L"-------------------------- Start Count : {0:03} --------------------------", m_nStartCount);
                m_nStartCount = m_nStartCount + 1;
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
            m_listTrace.EnsureVisible(nItem, 1);
        }
        Resize();
    }
    CDialog::OnTimer(nIDEvent);
}

// @0x140988520
void AiDebugDialog::OnMoving(UINT fwSide, LPRECT pRect)
{
    CDialog::OnMoving(fwSide, pRect);
    if (m_bInit)
        Resize();
}

// @0x140988570
void AiDebugDialog::OnSize(UINT nType, int cx, int cy)
{
    CDialog::OnSize(nType, cx, cy);
    if (m_bInit)
        Resize();
}

// @0x1409885d0
void AiDebugDialog::OnDestroy()
{
    KillTimer(m_nTimerId);
}

// @0x140988600
void AiDebugDialog::OnClose()
{
    CDialog::OnClose();
}

// @0x140988620
void AiDebugDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4f3, m_editXml);
    DDX_Control(pDX, 0x4d3, m_listTrace);
}

BEGIN_MESSAGE_MAP(AiDebugDialog, CDialog)
    ON_WM_MOVING()
    ON_WM_SIZE()
    ON_WM_TIMER()
    ON_WM_CLOSE()
    ON_WM_DESTROY()
END_MESSAGE_MAP()

// MS2-FUNCTIONAL: local int slot order differs (same code, permuted stack slots)
// @0x140988690
void AiDebugDialog::Resize()
{
    CRect rcClient;
    GetClientRect(rcClient);
    int nLogWidth, nListTop, nListHeight, nTimeWidth, nColumn, nLeft, nTop, nXmlHeight, nWidth;
    nLeft = m_nMarginLeft;
    nTop = m_nMarginTop;
    nWidth = (rcClient.Width() - m_nMarginLeft) - m_nMarginRight;
    nXmlHeight = (int)((float)(((rcClient.Height() - m_nMarginTop) - m_nGap) - m_nMarginBottom) * 0.7f);
    nListHeight = (int)((float)(((rcClient.Height() - m_nMarginTop) - m_nGap) - m_nMarginBottom) * 0.3f);
    nListTop = (nTop + nXmlHeight) + m_nGap;
    m_editXml.SetWindowPos(0, nLeft, nTop, nWidth, nXmlHeight, SWP_NOZORDER | SWP_SHOWWINDOW);
    m_listTrace.SetWindowPos(0, nLeft, nListTop, nWidth, nListHeight, SWP_NOZORDER | SWP_SHOWWINDOW);
    if ((int)((float)nWidth * 0.1f) < 100)
        nColumn = (int)((float)nWidth * 0.1f);
    else
        nColumn = 100;
    nTimeWidth = nColumn;
    nLogWidth = (nWidth - nColumn) - 5;
    m_listTrace.SetColumnWidth(0, nTimeWidth);
    m_listTrace.SetColumnWidth(1, nLogWidth);
}

// MS2-FUNCTIONAL: frame is 8 bytes larger than the exe (one extra temp slot; unwind-help slot 0xc8 vs 0xc0)
// @0x1409888f0
int AiDebugDialog::LoadXml()
{
    CString strPath = Unk_SocketFormat("{0}/{1}", "./Data/Xml/AI/", m_strFile);
    SetWindowText(strPath);
    CFileSystem::BufferPtr spBuffer = GetFileSystem()->FUN_140397bc0(strPath, 0, 0);
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

// @0x140988b70
void AiDebugDialog::AddStartMarker()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    __int64 nTime = FUN_140869440();
    m_vecLines.push_back(std::make_pair(0, nTime));
}

// @0x140988d60
void FUN_140988d60(CStringW& strSrc, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep)
{
    int iStart = 0;
    CStringW strToken = strSrc.Tokenize(pszSep, iStart);
    while (!strToken.IsEmpty())
    {
        FUN_14041ad70(&arrOut, FUN_14025a640(strToken));
        strToken = strSrc.Tokenize(pszSep, iStart);
    }
}
