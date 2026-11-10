// usertrigger.h - CUserTrigger (RTTI .?AVCUserTrigger@@, vftable 0x142da64d0, only the deleting dtor in slot 0): a small
// CPtred-derived record of a user-placed trigger: three 64-bit values, two ints and a name string. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\usertrigger.cpp` (0x1408f4e20-0x1408f50a0 .text$mn). Header
// name assumed; member names invented from their use (only the setter touches them in this unit).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CUserTrigger : public CPtred
{
public:
    CUserTrigger();                                                             // 0x1408f4e20
    virtual ~CUserTrigger();                                                    // 0x1408f4e70 (??_G 0x1408f4f40)
    void SetData(__int64 n18, __int64 n20, __int64 n28, int n30, int n34, CString strName);   // 0x1408f4eb0 fill every member (the callee destroys strName)

    __int64 m_n18;                                                              // +0x18
    __int64 m_n20;                                                              // +0x20
    __int64 m_n28;                                                              // +0x28
    int m_n30;                                                                  // +0x30
    int m_n34;                                                                  // +0x34
    CString m_strName;                                                          // +0x38
};
MS2_CHECK_SIZE(CUserTrigger, 0x40);
