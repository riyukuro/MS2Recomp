// sounddlg.h - CSoundDlg (RTTI .?AVCSoundDlg@@): the debug tool dialog (resource 0x92) with eight volume sliders for the
// Client::Constants VolumeXxx values. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\sounddlg.cpp` (0x141774240-0x141775810). Header name assumed; member names are invented from use.
#pragma once
#include <afxcmn.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/toolbasedialog.h"

class CSoundDlg : public CToolBaseDialog, public TSingleton<CSoundDlg>
{
    DECLARE_DYNAMIC(CSoundDlg)
public:
    CSoundDlg(CWnd* pParent = NULL);                                // 0x141774260
    virtual ~CSoundDlg();                                           // 0x141774460 (deleting dtor 0x141775540)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69
    virtual BOOL OnInitDialog();                                    // slot 96

    afx_msg void OnBnClickedOk();                                   // IDOK: nothing
    afx_msg void OnBnClickedCancel();                               // IDCANCEL
    afx_msg void OnClose();                                         // WM_CLOSE
    DECLARE_MESSAGE_MAP()

public:
    CSliderCtrl m_sldMyPcToNpc;                                     // +0x140 DDX 0x4d1, VolumeMyPcToNpc
    CSliderCtrl m_sldMyPcToObject;                                  // +0x228 DDX 0x4d9, VolumeMyPcToObject
    CSliderCtrl m_sldMyPcToBreakableObject;                         // +0x310 DDX 0x4da
    CSliderCtrl m_sldNpcToMyPc;                                     // +0x3f8 DDX 0x4df
    CSliderCtrl m_sldOtherPc;                                       // +0x4e0 DDX 0x4db
    CSliderCtrl m_sldPcToNpc;                                       // +0x5c8 DDX 0x4dc
    CSliderCtrl m_sldPcToBreakableObject;                           // +0x6b0 DDX 0x4dd
    CSliderCtrl m_sldNpcToPc;                                       // +0x798 DDX 0x4de
    CString m_strMyPcToNpc;                                         // +0x880 DDX 0x4d2
    CString m_strMyPcToObject;                                      // +0x888 DDX 0x4d3
    CString m_strMyPcToBreakableObject;                             // +0x890 DDX 0x4d4
    CString m_strNpcToMyPc;                                         // +0x898 DDX 0x4d5
    CString m_strOtherPc;                                           // +0x8a0 DDX 0x4d6
    CString m_strPcToNpc;                                           // +0x8a8 DDX 0x4d7
    CString m_strPcToBreakableObject;                               // +0x8b0 DDX 0x4d8
    CString m_strNpcToPc;                                           // +0x8b8 DDX 0x4e0
};
MS2_CHECK_SIZE(CSoundDlg, 0x8c0);
