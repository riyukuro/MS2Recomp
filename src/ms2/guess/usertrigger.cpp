// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserTrigger (ctor, dtor, the all-member setter) and the
// unreferenced CRT memmove_s copy the object ends with. See usertrigger.h.
// MS2-UNIT: ?\usertrigger.cpp
// MS2-RANGE: 0x1408f4e20-0x1408f50a0 .text$mn
// MS2-PIN: ??_GCUserTrigger@@UEAAPEAXI@Z 0x1408f4f40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\usertrigger.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "usertrigger.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1408f4e20
CUserTrigger::CUserTrigger()
{
}

// @0x1408f4e70
CUserTrigger::~CUserTrigger()
{
}

// @0x1408f4eb0
void CUserTrigger::SetData(__int64 n18, __int64 n20, __int64 n28, int n30, int n34, CString strName)
{
    m_n18 = n18;
    m_n20 = n20;
    m_n28 = n28;
    m_n30 = n30;
    m_n34 = n34;
    m_strName = strName;
}
MS2_REPLACE_METHOD(0x1408F4EB0, CUserTrigger, SetData, 139, 0xBA7F14C0);

// @0x1408f4f80
MS2_EMIT_CRT_MEMMOVE_S();
