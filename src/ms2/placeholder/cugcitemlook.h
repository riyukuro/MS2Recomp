#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class COutputStream;
class CInputStream;

// Heap layouts: CUgcItemLook ctor 140892b50 and deleting dtor.
// The look of an uploaded item (a design / blueprint file) with its url.
class CUgcItemLook : public CPtred
{
public:
    CUgcItemLook();                                         // 0x140892b50
    virtual ~CUgcItemLook();                                // 0x140892bf0

    void Clear();                                           // 0x140892c70
    void SetDefault();                                      // 0x140892d40
    void CopyFrom(const CUgcItemLook* pOther);              // 0x140892da0
    CStringA GetLocalPath() const;                          // 0x140892ec0
    void Write(COutputStream& stream) const;                // 0x140893070
    void Read(CInputStream& stream);                        // 0x140893250
    int FUN_1408934f0() const;                              // m_n18 == 1 || m_n60 == 1
    int FUN_140893520() const;                              // m_n60 == 2
    bool FUN_140893540() const;

    __int64 m_n18;                                          // +0x18
    CStringA m_str20;                                       // +0x20
    CStringW m_str28;                                       // +0x28
    int m_n30;                                              // +0x30
    int m_n34;                                              // +0x34
    __int64 m_n38;                                          // +0x38
    __int64 m_n40;                                          // +0x40
    CStringW m_str48;                                       // +0x48
    __int64 m_n50;                                          // +0x50
    CStringA m_strUrl;                                      // +0x58
    int m_n60;                                              // +0x60
};
MS2_CHECK_SIZE(CUgcItemLook, 0x68);
