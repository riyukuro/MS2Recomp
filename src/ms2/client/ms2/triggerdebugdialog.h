// triggerdebugdialog.h - TriggerDebugDialog (RTTI .?AVTriggerDebugDialog@@): the trigger-script debug tool dialog (resource 0xa7).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\triggerdebugdialog.cpp` (0x140b9b470-0x140b9c680).
// Header name assumed; member and handler names are invented from use. Sibling of AiDebugDialog: the same xml view +
// trace list, but with three check/push buttons and a (line, time) queue without the entity id.
//
// 0x630 bytes = CDialog (0x130) + CPtred (0x18, secondary base at +0x130) + a rich edit showing the trigger xml (+0x148) +
// a list control with the live trace (+0x230) + three buttons (+0x318/+0x400/+0x4e8) + the xml path + a locked queue of
// (line, time) pairs the game thread fills (AddLine) and the 100 ms timer drains into the list.
#pragma once
#include <afxcmn.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"

class TriggerDebugDialog : public CDialog, public CPtred
{
    DECLARE_DYNAMIC(TriggerDebugDialog)
public:
    TriggerDebugDialog(CWnd* pParent);                              // 0x140b9b490
    virtual ~TriggerDebugDialog();                                  // 0x140b9b5c0 (deleting dtor 0x140b9c580)

    virtual BOOL OnInitDialog();                                    // slot 96
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69
    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66

    void SetFile(CString strFile);                                  // 0x140b9b820
    void AddLine(int nLine);                                        // 0x140b9b870
    void Resize();                                                  // 0x140b9bf70
    int LoadXml();                                                  // 0x140b9c190

    afx_msg void OnTimer(UINT_PTR nIDEvent);                        // 0x140b9b8f0
    afx_msg void OnMoving(UINT fwSide, LPRECT pRect);               // 0x140b9bd60
    afx_msg void OnSize(UINT nType, int cx, int cy);                // 0x140b9bdb0
    afx_msg void OnDestroy();                                       // 0x140b9be10
    afx_msg void OnClose();                                         // 0x140b9be40
    afx_msg void OnClear();                                         // 0x140b9c410
    DECLARE_MESSAGE_MAP()

public:
    CRichEditCtrl m_editXml;                                        // +0x148 DDX 0x4f4
    CListCtrl m_listTrace;                                          // +0x230 DDX 0x4f5
    CButton m_btnFollow;                                            // +0x318 DDX 0x4b6: checked = drain the queue into the list
    CButton m_btnScroll;                                            // +0x400 DDX 0x4f6: checked = scroll to each new row
    CButton m_btnClear;                                             // +0x4e8 DDX 0x4f7
    CString m_strFile;                                              // +0x5d0 xml path
    std::vector<std::pair<int, __int64> > m_vecLines;               // +0x5d8 (line, time) queue
    CLockCriticalSection m_lock;                                    // +0x5f0
    bool m_bInit;                                                   // +0x620
    UINT_PTR m_nTimerId;                                            // +0x628 0x66
};
MS2_CHECK_SIZE(TriggerDebugDialog, 0x630);
