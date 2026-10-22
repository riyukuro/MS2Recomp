// npsman.h - CNPSMan (RTTI .?AVCNPSMan@@, 0x38 bytes, base TSingleton<class CNPSMan> at +0): the Nexon NPS survey
// helper. Holds the player-id handle (+0x8), a mode int (+0x10), two wide strings, the survey-url string (+0x28) and
// two state flags; on destruction it opens the exit-survey window of nps64.dll (OpenSurveyWindowA). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\npsman.cpp` (0x140db8d80-0x140db9610 .text$mn).
// Header name assumed; member and method names invented.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"     // TSingleton

class CNPSMan;

// This instantiation stores the complete object pointer (exe DAT_143abf520).
template <> class TSingleton<CNPSMan>
{
public:
    TSingleton();                                       // 0x140db91a0
    virtual ~TSingleton();                              // 0x140db91d0 (??_G 0x140db91f0)
    static CNPSMan* s_instance;                         // 0x143abf520
    static CNPSMan* GetInstance() { return s_instance; }
};

class CNPSMan : public TSingleton<CNPSMan>
{
public:
    CNPSMan();                                          // 0x140db8d80
    virtual ~CNPSMan();                                 // 0x140db8e30 (??_G 0x140db9230)

    void FUN_140db8eb0();                               // arms the survey (+0x30) and caches the survey url (+0x28)
    void FUN_140db8f30();                               // opens the survey window once (+0x31)
    void SetMode(int nMode);
    void SetPlayer(__int64 hPlayer);
    void FUN_140db9040(CStringW& strText);              // -> +0x18
    void FUN_140db9070(CStringA& strText);              // -> +0x20 (widened)
    void FUN_140db90e0(CStringW& strText);              // -> +0x20
    void FUN_140db9170();                               // adds the "platform" survey parameter
    bool FUN_140db9110();                               // has a player handle
    bool IsArmed();                               // armed
    bool IsShown();                               // survey already shown

    __int64 m_hPlayer;                                  // +0x08
    int m_nMode;                                        // +0x10
    CStringW m_str18;                                   // +0x18
    CStringW m_str20;                                   // +0x20
    CStringA m_strSurveyUrl;                            // +0x28
    bool m_bArmed;                                      // +0x30
    bool m_bShown;                                      // +0x31
};
MS2_CHECK_SIZE(CNPSMan, 0x38);
MS2_CHECK_OFFSET(CNPSMan, m_hPlayer, 0x08);
MS2_CHECK_OFFSET(CNPSMan, m_str18, 0x18);
MS2_CHECK_OFFSET(CNPSMan, m_strSurveyUrl, 0x28);
MS2_CHECK_OFFSET(CNPSMan, m_bShown, 0x31);
