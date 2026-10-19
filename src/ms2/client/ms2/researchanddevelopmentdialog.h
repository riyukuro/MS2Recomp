// researchanddevelopmentdialog.h - CResearchAndDevelopmentDialog (RTTI .?AVCResearchAndDevelopmentDialog@@, 0x280 bytes):
// the MFC debug tool (resource 0xa1) for the net stream sound ("192K" radio url + volume slider) and the screen recorder
// (RecodeMgr: start with a name, stop). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\recodemgr.cpp` (0x140c9ba20-0x140c9cc60, dir client\ms2). Header name assumed; member and handler names invented
// from use.
#pragma once
#include <afxdialogex.h>
#include <afxcmn.h>

#include "ms2/ms2layout.h"

class CResearchAndDevelopmentDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CResearchAndDevelopmentDialog)
public:
    CResearchAndDevelopmentDialog(CWnd* pParent);                   // 0x140c9c260 (resource 0xa1)
    virtual ~CResearchAndDevelopmentDialog();                       // 0x140c9c350 (deleting dtor 0x140c9ca10)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66, 0x140c9c5a0
    virtual BOOL OnInitDialog();                                    // slot 96, 0x140c9c400

    void FUN_140c9c4e0(CString strText);                            // set the status text (+0x268), callee destroys it
    void FUN_140c9c540(CString strText);                            // set the recording status text (+0x278)

    afx_msg void OnBnClickedCancel();                               // 0x140c9c6b0: IDCANCEL
    afx_msg void OnBnClickedOk();                                   // 0x140c9c6d0: IDOK
    afx_msg void OnBnClickedPlay();                                 // 0x140c9c6f0: 0x4e5 play the net stream at the slider volume
    afx_msg void OnBnClickedStop();                                 // 0x140c9c7d0: 0x4e6 drop the net stream
    afx_msg void OnNMCustomdrawVolume(NMHDR* pNMHDR, LRESULT* pResult);   // 0x140c9c800: 0x4e7 slider moved
    afx_msg void OnBnClickedRecord();                               // 0x140c9c8b0: 0x4ec start the recording
    afx_msg void OnBnClickedStopRecord();                           // 0x140c9c950: 0x4ed stop the recording
    afx_msg void OnNMClickHelp(NMHDR* pNMHDR, LRESULT* pResult);    // 0x140c9c980: 0x4ef open the codec help page
    DECLARE_MESSAGE_MAP()

public:
    CString m_strUrl;                                               // +0x170 DDX_Text 0x4e4
    CSliderCtrl m_sldVolume;                                        // +0x178 DDX_Control 0x4e7
    CString m_strVolume;                                            // +0x260 DDX_Text 0x4e8
    CString m_strStatus;                                            // +0x268 DDX_Text 0x4e9
    CString m_strRecordName;                                        // +0x270 DDX_Text 0x4ea
    CString m_strRecordStatus;                                      // +0x278 DDX_Text 0x4ee
};
MS2_CHECK_SIZE(CResearchAndDevelopmentDialog, 0x280);
