// cmeratmarketschcond.h - PLACEHOLDER for CMeratMarketSchCond (RTTI name; methods recovered in
// ?\meratmarketbasketinfo.cpp). A CPtred-derived market search condition (0x50 bytes, vftable with the dtor only). Only what
// commonfiles\ugcdef.cpp touches is declared (the UGC item icon callback owns one through MS2Ptr). NOT an original
// header; member names are invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CInPacket;
class CInputStream;
class COutputStream;

class CMeratMarketSchCond : public CPtred
{
public:
    CMeratMarketSchCond();                                      // 0x1406a34b0
    CMeratMarketSchCond(CInPacket& packet);                     // 0x1406a3510
    virtual ~CMeratMarketSchCond();                             // 0x1406a3580

    void Clear();                                               // 0x1406a35e0
    void Set(const CStringW& str);                              // 0x1406a36a0 a text search
    void CopyFrom(const CMeratMarketSchCond* pOther);      // reset, then copy `pOther` (when not NULL)
    void Write(COutputStream* pStream);                         // 0x1406a3760
    void Read(CInPacket& packet);                               // 0x1406a3880
    void WriteBrief(COutputStream* pStream);                    // 0x1406a3b00
    void ReadBrief(CInputStream* pStream);                      // 0x1406a3c10
    bool FUN_1406a3d50();                                       // m_18 in 40000..50000
    bool FUN_1406a3d80();                                       // m_18 in 100..10000
    int GetPageGroup();                                         // 0x1406a3db0 (page - 1) / 5, -1 without a page
    int GetPageGroupFirst();                                    // 0x1406a3e00
    int GetPageGroupLast();                                     // 0x1406a3e50
    int FUN_1406a3ea0();                                        // the item count up to the page's 15-page block
    int GetPageSize();                                          // 0x1406a3f10
    int GetMaxPageSize();                                       // 0x1406a3f30 (18)
    CStringA GetSortName();                                     // 0x1406a3f50
    int GetType();                                              // 0x1406a4010
    int FUN_1406a4030();                                        // m_18 rounded up to the end of its hundred
    int IsSameQuery(const CMeratMarketSchCond* pOther);         // 0x1406a4080 same search, page block and m_34
    int IsSameSearch(const CMeratMarketSchCond* pOther);        // 0x1406a4100
    bool IsValidPageSize();                                     // 0x1406a41e0

    int m_18;                                                   // +0x18
    int m_1c;                                                   // +0x1c
    int m_20;                                                   // +0x20
    int m_24;                                                   // +0x24
    CStringW m_str;                                             // +0x28
    int m_30;                                                   // +0x30
    int m_34;                                                   // +0x34
    int m_38;                                                   // +0x38
    int m_3c;                                                   // +0x3c
    int m_40;                                                   // +0x40
    int m_44;                                                   // +0x44
    int m_48;                                                   // +0x48
                                                                // +0x4c tail padding (operator= 0x1406a8e50 does not copy it)
};
MS2_CHECK_SIZE(CMeratMarketSchCond, 0x50);
