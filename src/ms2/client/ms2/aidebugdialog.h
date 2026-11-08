// aidebugdialog.h - AiDebugDialog (RTTI .?AVAiDebugDialog@@): the AI behaviour-tree debug tool dialog (resource 0xa5).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\aidebugdialog.cpp` (0x140987b20-0x14098a990).
// Header name assumed; member and handler names are invented from use.
//
// 0x398 bytes = CDialog (0x130) + CPtred (0x18, secondary base at +0x130) + a rich edit showing the AI xml (+0x148) +
// a list control with the live trace (+0x230) + the file name and entity id the trace belongs to + a locked queue of
// (line, time) pairs the game thread fills (AddLine) and the 100 ms timer drains into the list.
#pragma once
#include <afxcmn.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"

class AiDebugDialog : public CDialog, public CPtred
{
    DECLARE_DYNAMIC(AiDebugDialog)
public:
    AiDebugDialog(CWnd* pParent);                                   // 0x140987b40
    virtual ~AiDebugDialog();                                       // 0x140987ca0 (deleting dtor 0x14098a2c0)

    virtual BOOL OnInitDialog();                                    // slot 96
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69
    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66

    void SetTarget(CString strFile, int nId);                       // 0x140987ee0
    void AddLine(int nId, int nLine);                               // 0x140987f40
    void RequestTrace();                                            // 0x140987fe0 (packet 0x50)
    void Resize();                                                  // 0x140988690
    int LoadXml();                                                  // 0x1409888f0
    void AddStartMarker();                                          // 0x140988b70

    afx_msg void OnTimer(UINT_PTR nIDEvent);                        // 0x140988060
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);               // 0x140988520
    afx_msg void OnSize(UINT nType, int cx, int cy);                // 0x140988570
    afx_msg void OnDestroy();                                       // 0x1409885d0
    afx_msg void OnClose();                                         // 0x140988600
    DECLARE_MESSAGE_MAP()

public:
    CRichEditCtrl m_editXml;                                        // +0x148 DDX 0x4f3
    CListCtrl m_listTrace;                                          // +0x230 DDX 0x4d3
    CString m_strFile;                                              // +0x318 file under ./Data/Xml/AI/
    int m_nId;                                                      // +0x320
    std::vector<std::pair<int, __int64> > m_vecLines;               // +0x328 (line, time) queue
    int m_nStartCount;                                              // +0x340
    CLockCriticalSection m_lock;                                    // +0x348
    bool m_bInit;                                                   // +0x378
    int m_nMarginLeft;                                              // +0x37c 20
    int m_nMarginRight;                                             // +0x380 10
    int m_nMarginTop;                                               // +0x384 50
    int m_nMarginBottom;                                            // +0x388 10
    int m_nGap;                                                     // +0x38c 10
    UINT_PTR m_nTimerId;                                            // +0x390 0x65
};
MS2_CHECK_SIZE(AiDebugDialog, 0x398);
