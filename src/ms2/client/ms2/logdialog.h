// logdialog.h - CLogDialog (RTTI name, 0x4e0 bytes, CObject::operator new in ClientLogManager::ToggleDialog) and
// LogDialogCtx (RTTI name, 0x48 bytes): the in-game log viewer tool dialog (dialog template 0x8c) and one captured
// CLogString line. Bases CToolBaseDialog (+0x0) and CPtred (+0x138). Layout after the ctor/dtor and the v2525 snapshot
// (include/ms2/client/CLogDialog.h); member and method names are invented from use. Header name assumed.
#pragma once
#include <afxwin.h>
#include <afxcmn.h>
#include <map>
#include <list>
#include <deque>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/client/ms2/toolbasedialog.h"
#include "ms2/client/ms2/colorlistctrl.h"

// One log line as the dialog shows it (built by ClientLogManager::OnLogString from a CLogStringCtx).
class LogDialogCtx : public CPtred
{
public:
    LogDialogCtx() {}                       // 0x141456c10
    int m_nLevel;                           // +0x18 CLogStringCtx::m_level (1 error, 2 warning, 11 info, 12 debug)
    int m_nCategory;                        // +0x1c CLogStringCtx::m_category
    CStringA m_strNum;                      // +0x20 column 0: the running line number
    CStringA m_strLevel;                    // +0x28 column 1
    CStringA m_strCategory;                 // +0x30 column 2
    CStringA m_strText;                     // +0x38 column 3 (searched by the filter)
    CStringW m_strTextW;                    // +0x40 the original text
};
MS2_CHECK_SIZE(LogDialogCtx, 0x48);

typedef MS2Ptr<LogDialogCtx> LogDialogCtxPtr;

class CLogDialog : public CToolBaseDialog, public CPtred
{
    DECLARE_DYNAMIC(CLogDialog)
public:
    CLogDialog(CWnd* pParent = NULL);                                   // 0x14144fee0
    virtual ~CLogDialog();                                              // 0x141450130

    void SetLogContexts(std::list<LogDialogCtxPtr>& logs);             // 0x141450220 the history, when opened
    void AddLogContext(LogDialogCtxPtr spCtx);                          // 0x1414502b0 a new line

protected:
    virtual void DoDataExchange(CDataExchange* pDX);                    // slot 66, 0x1414503c0
    virtual BOOL OnInitDialog();                                        // slot 96, 0x141450440
    virtual BOOL PreTranslateMessage(MSG* pMsg);                        // slot 69, 0x1414507c0

    afx_msg void OnSize(UINT nType, int cx, int cy);                    // 0x1414508a0
    afx_msg void OnLvnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult); // 0x1414508f0 (empty)
    afx_msg void OnCbnSelchangeCategory();                              // 0x141450910
    afx_msg void OnBnClickedClear();                                    // 0x1414509a0
    afx_msg void OnBnClickedClearFilter();                              // 0x1414509f0
    afx_msg void OnEnChangeFilter();                                    // 0x141450a40
    afx_msg void OnBnClickedError();                                    // 0x141450a80 level 1
    afx_msg void OnBnClickedWarning();                                  // 0x141450af0 level 2
    afx_msg void OnBnClickedInfo();                                     // 0x141450b60 level 11
    afx_msg void OnBnClickedDebug();                                    // 0x141450bd0 level 12
    afx_msg void OnLvnGetdispinfoList(NMHDR* pNMHDR, LRESULT* pResult); // 0x141451290
    DECLARE_MESSAGE_MAP()

    void Resize(int cx, int cy);                                        // 0x141450c40
    void ExecuteCommand();                                              // 0x141450cf0 the command edit (Enter)
    bool IsFiltered(LogDialogCtxPtr spCtx);                             // 0x141450e20
    void Rebuild();                                                     // 0x141450f50 refilter every line
    void SetRowCount(int nCount);                                       // 0x1414510f0
    void CopySelection();                                               // 0x141451150 Ctrl+C

public:
    MS2_LAYOUT_FRIEND;
    int m_nCategory;                                                    // +0x150 the category filter (0 all)
    CColorListCtrl m_list;                                              // +0x158 control 0x4b5 (virtual list)
    CComboBox m_comboCategory;                                          // +0x2a0 control 0x4b6
    CEdit m_editCommand;                                                // +0x388 control 0x4e1
    std::map<int, bool> m_levels;                                       // +0x470 the shown levels (checks 0x4b8..0x4bb)
    std::vector<int> m_categories;                                      // +0x480 the combo entries
    CStringA m_strFilter;                                               // +0x498 the text filter (edit 0x4e2)
    std::deque<LogDialogCtxPtr> m_all;                                  // +0x4a0 every line (at most 1001)
    std::vector<LogDialogCtxPtr> m_shown;                               // +0x4c8 the rows after filtering
};
MS2_CHECK_SIZE(CLogDialog, 0x4e0);
MS2_CHECK_OFFSET(CLogDialog, m_nCategory, 0x150);
MS2_CHECK_OFFSET(CLogDialog, m_list, 0x158);
MS2_CHECK_OFFSET(CLogDialog, m_comboCategory, 0x2a0);
MS2_CHECK_OFFSET(CLogDialog, m_editCommand, 0x388);
MS2_CHECK_OFFSET(CLogDialog, m_levels, 0x470);
MS2_CHECK_OFFSET(CLogDialog, m_strFilter, 0x498);
MS2_CHECK_OFFSET(CLogDialog, m_all, 0x4a0);
MS2_CHECK_OFFSET(CLogDialog, m_shown, 0x4c8);
