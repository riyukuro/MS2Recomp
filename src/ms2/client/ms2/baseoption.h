// baseoption.h - CBaseOption (RTTI .?AVCBaseOption@@): base of the game-option rows (CGameOptionAccount,
// CGameOptionPersonalInfoAgreement, ...) shown by UIGameOptionDialog. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\baseoption.cpp` (0x140a02ac0-0x140a03090). Header name assumed; member names are invented.
// An option is "applied" (m_nActive) once the dialog has loaded it; changes made before that are only flagged pending.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include <afx.h>

class UIGameOptionDialog;

class CBaseOption : public CPtred
{
public:
    CBaseOption(int nId, int nType);                                // 0x140a02ac0
    virtual ~CBaseOption();                                         // 0x140a02b40 (deleting dtor 0x140a02f00)

    virtual CString GetTypeName();                                      // display name (empty here)
    virtual void vfunc_2();                                         // mark active, flush a pending change through vfunc_6
    virtual void vfunc_3(int n);                                    // value changed: pend it or apply it
    virtual void vfunc_4(int n);                                    // n == 0 deactivates, otherwise vfunc_7
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // UI callback by name (0 = not handled)
    virtual void vfunc_6();                                         // apply
    virtual void vfunc_7();                                         // refresh
    virtual int vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();                                        // refresh if active
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14();

    UIGameOptionDialog* GetOptionDialog();                          // 0x140a02d70 (this unused)
    void FUN_140a02d90(int n);                                      // forwards n to the dialog if it is open
    bool IsEnabled() const;                                     // m_bEnabled
    void SetEnabled(bool b);
    int GetType() const;                                      // m_nType
    int GetActive() const;                                      // m_nActive
    int FUN_140a02e50() const;                                      // m_nId

public:
    int m_nPending;                                                 // +0x18 a change arrived before the option was active
    int m_nActive;                                                  // +0x1c
    int m_nId;                                                      // +0x20
    int m_nType;                                                    // +0x24
    bool m_bEnabled;                                                // +0x28
    bool m_pad_29; short m_pad_2a; int m_pad_2c;
};
MS2_CHECK_SIZE(CBaseOption, 0x30);

UIGameOptionDialog* FUN_140a02e60(int nDialogId);                   // the open UIGameOptionDialog, or 0
