// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\portaldata.cpp
// MS2-RANGE: 0x14072fd10-0x140730120 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\portaldata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "portaldata.h"
#include "hook/ms2hook.h"

// @0x14072fd10
CPortalData::CPortalData()
    : m_18(0, 0, 0), m_24(0, 0, 0), m_30(0), m_34(0), m_38(0), m_3c(0), m_40(1), m_44(1), m_48(0), m_50(0),
      m_58(0, 0, 0), m_64(200.0f, 200.0f, 250.0f), m_70(0), m_80(0), m_84(0), m_88(0), m_90(0),
      m_98(0), m_9c(0), m_a0(0), m_a4(0), m_a8(0), m_ac(0), m_b0(0), m_c8(0)
{
}

// @0x14072ff60
int CPortalData::FUN_14072ff60() { return m_88; }
MS2_REPLACE_METHOD(0x14072FF60, CPortalData, FUN_14072ff60, 17, 0x3F39D72B);

// @0x14072ff80
CPortalHistoryData::CPortalHistoryData() { m_138 = 0; }

