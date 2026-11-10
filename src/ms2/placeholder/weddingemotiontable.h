// weddingemotiontable.h - PLACEHOLDER for WeddingEmotionTable (RTTI .?AVWeddingEmotionTable@@, 0x20 bytes) and its row
// class WeddingEmotionData (0x30 bytes). NOT an original header. Both live in ?\weddingemotiondata.cpp
// (0x1409030d0-0x1409063b0), which reads Table/weddingEmotion.xml.
// Bases: TSingleton<WeddingEmotionTable> at +0x0, CValidData<WeddingEmotionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"

// One <weddingEmotion> row: the animation names of the couple emotion, split from the "anim" attribute at ','.
class WeddingEmotionData : public CPtred
{
public:
    WeddingEmotionData();                                   // 0x1409030d0
    virtual ~WeddingEmotionData();                          // 0x140903120

    std::vector<CString> m_anim;                            // +0x18
};
MS2_CHECK_SIZE(WeddingEmotionData, 0x30);
MS2_CHECK_OFFSET(WeddingEmotionData, m_anim, 0x18);

class WeddingEmotionTable : public TSingleton<WeddingEmotionTable>, public CValidData<WeddingEmotionTable>
{
public:
    WeddingEmotionTable();                                  // 0x140903170
    virtual ~WeddingEmotionTable();                         // 0x1409031e0

    MS2Ptr<WeddingEmotionData> FindByCode(unsigned nCode);   // row by code (null when missing)
    int Load();                                             // 0x140903250 (ms2.cpp calls it as FUN_140903250)

    // @0x140904dc0
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                                    // DAT_143a....

    std::map<unsigned, MS2Ptr<WeddingEmotionData> > m_map;  // +0x10 by code
};
MS2_CHECK_SIZE(WeddingEmotionTable, 0x20);
MS2_CHECK_OFFSET(WeddingEmotionTable, m_map, 0x10);
