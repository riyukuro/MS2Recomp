// titletable.h - CTitleTable (RTTI .?AVCTitleTable@@, 0x98 bytes) and its row CTitle (0x30), recovered from
// commonfiles\titletable.cpp (0x14087a3e0-0x14087d0c0, the last object of commonfiles\tinyxmlhelper.cpp). Header name
// assumed; member and method names invented.
// Reads Table/titleTag.xml: <ms2><key id tag account/></ms2>.
// Bases: TSingleton<CTitleTable> at +0x0 (s_instance DAT_143ab1fc8). CGameApp::InitInstance (?\ms2.cpp) creates it.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// One <key> row.
class CTitle : public CPtred
{
public:
    // @0x14087ae70
    CTitle() : m_nId(0), m_nAccount(0) {}
    virtual ~CTitle() = default;                                // 0x14087b000

    unsigned m_nId;                                             // +0x18 "id"
    CStringA m_strTag;                                          // +0x20 "tag"
    int m_nAccount;                                             // +0x28 "account"
};
MS2_CHECK_SIZE(CTitle, 0x30);

class CTitleTable : public TSingleton<CTitleTable>
{
public:
    CTitleTable();                                              // 0x14087a3e0
    virtual ~CTitleTable();                                     // 0x14087a490

    int Load();                                                 // 0x14087a4e0 (ms2.cpp calls it as FUN_14087a4e0)
    int HasTitle(unsigned nId);                                  // 0x14087a820
    int GetAccount(unsigned nId);                               // 0x14087a8a0
    unsigned FindTitleId(CStringA strTag);                      // 0x14087a930
    unsigned FindVipTitle(int nVipLevel);                       // 0x14087a9c0 tencentVip1..4

    ATL::CAtlMap<unsigned, MS2Ptr<CTitle>> m_titles;            // +0x08 by id
    ATL::CAtlMap<CStringA, unsigned, ATL::CStringElementTraits<CStringA>> m_tags;   // +0x50 id by tag
};
MS2_CHECK_SIZE(CTitleTable, 0x98);
MS2_CHECK_OFFSET(CTitleTable, m_titles, 0x8);
MS2_CHECK_OFFSET(CTitleTable, m_tags, 0x50);
