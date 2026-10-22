// gameoptionpersonalinfoagreement.h - CGameOptionPersonalInfoAgreement (RTTI .?AVCGameOptionPersonalInfoAgreement@@): the
// "send log / personal info agreement" game option row. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// the unit is `?\gameoptionpersonalinfoagreement.cpp`. Member names are invented.
#pragma once
#include "ms2/client/ms2/baseoption.h"

// Unit-local view of the agreement state at +0x30; the first byte is the agree flag. Real size and type unknown.
struct Unk_PiAgreeState
{
    bool m_bAgree;
    char m_pad[7];
};

class CGameOptionPersonalInfoAgreement : public CBaseOption
{
public:
    CGameOptionPersonalInfoAgreement(int nId, int nType);        // 0x140a45d40
    virtual ~CGameOptionPersonalInfoAgreement();                 // 0x140a45da0

    virtual CString GetTypeName();                                   // 0x140a46340
    virtual void vfunc_3(int n);                                 // 0x140a45dd0
    virtual void vfunc_4(int n);                                 // 0x140a45e20
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x140a45e50
    virtual void vfunc_6();                                      // 0x140a45ed0
    virtual void vfunc_7();                                      // 0x140a46040
    virtual void vfunc_10();                                     // 0x140a461f0
    virtual void vfunc_12();                                     // 0x140a462f0
    virtual int vfunc_14();                                      // 0x140a46390

    Unk_PiAgreeState m_state;                                    // +0x30
};
MS2_CHECK_SIZE(CGameOptionPersonalInfoAgreement, 0x38);
