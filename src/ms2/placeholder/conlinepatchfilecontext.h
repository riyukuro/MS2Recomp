// conlinepatchfilecontext.h - PLACEHOLDER for COnlinePatchFileContext (RTTI .?AVCOnlinePatchFileContext@@, 0x40 bytes).
// NOT an original header. One file of the online patch list: CPtred base, the relative path, the download buffer, its
// size and the received byte count. Layout from ctor 0x140a86e50 / dtor 0x140a87080 (?\onlinepatchmanagercli.cpp).
#pragma once

#include <afx.h>
#include "ms2/placeholder/cptred.h"

class COnlinePatchFileContext : public CPtred
{
public:
    COnlinePatchFileContext();          // 0x140a86e50
    virtual ~COnlinePatchFileContext(); // 0x140a87080

    CString m_strPath;                  // +0x18
    char* m_pData;                      // +0x20 operator new[](m_nSize)
    unsigned __int64 m_nSize;           // +0x28
    unsigned __int64 m_nReceived;       // +0x30
    CString m_strDigest;                // +0x38
};
MS2_CHECK_SIZE(COnlinePatchFileContext, 0x40);
MS2_CHECK_OFFSET(COnlinePatchFileContext, m_strPath, 0x18);
MS2_CHECK_OFFSET(COnlinePatchFileContext, m_pData, 0x20);
MS2_CHECK_OFFSET(COnlinePatchFileContext, m_strDigest, 0x38);
