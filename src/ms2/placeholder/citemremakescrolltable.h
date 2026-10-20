// citemremakescrolltable.h - PLACEHOLDER for CItemRemakeScrollTable (RTTI .?AVCItemRemakeScrollTable@@, 0xb0 bytes). NOT an original header.
// Bases: TSingleton<CItemRemakeScrollTable> at +0x0, CCacheData at +0x8, CValidData<CItemRemakeScrollTable> at +0x30; the
// lock +0x38 and the id -> row map +0x68 (same shape as CItemSocketScrollTable). A TSingleton that CGameApp::InitInstance
// (?\ms2.cpp) creates and loads. Bodies in ?\itemremakescrolldata.cpp.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/citemremakescrolldata.h"

class CItemRemakeScrollTable : public TSingleton<CItemRemakeScrollTable>,
                               public CCacheData,
                               public CValidData<CItemRemakeScrollTable>
{
public:
    CItemRemakeScrollTable();                               // 0x140615570
    virtual ~CItemRemakeScrollTable();                      // 0x140615640

    int Load();                                             // 0x140615700 parses Table/itemRemakeScroll.xml (always 1)
    int Reload();                                           // 0x140615b70 clears the map and loads again
    CItemRemakeScrollDataPtr GetData(int nId);              // 0x140615bf0 the row of a scroll id (null when missing)

    static void CheckInit();                                // 0x14061b280
    static void SetInit(bool b);                            // 0x14061c620

    static bool s_bInit;                                    // DAT_143aaff18

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                    // +0x38
    ATL::CAtlMap<int, CItemRemakeScrollDataPtr> m_map;              // +0x68 id -> row
};
MS2_CHECK_SIZE(CItemRemakeScrollTable, 0xb0);
MS2_CHECK_OFFSET(CItemRemakeScrollTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CItemRemakeScrollTable, m_map, 0x68);
