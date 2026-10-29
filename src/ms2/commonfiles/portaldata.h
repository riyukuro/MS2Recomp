// CPortalData / CPortalHistoryData (RTTI names). Field names inferred.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// 12-byte float triple; ctor is the shared out-of-line FUN_14027db40 (commonfiles\commonstruct.cpp, not yet recovered).
struct Unk_PDVec3 {
    Unk_PDVec3(float x, float y, float z);   // 0x14027db40
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_PDVec3, 0xc);

// Placeholder: real class unrecovered (0x40 bytes); ctor 0x140266860, dtor 0x14027e920.
class QuestMask {
public:
    QuestMask();
    ~QuestMask();
    __int64 m_pad[8];
};
MS2_CHECK_SIZE(QuestMask, 0x40);

class CPortalData : public CPtred {
public:
    CPortalData();
    // virtual ~CPortalData();   // 0x14072ffe0 (??_G 0x1407300a0) implicit: the exe dtor stores no vptr
    int FUN_14072ff60();
    Unk_PDVec3 m_18, m_24;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c;
    __int64 m_50;
    Unk_PDVec3 m_58, m_64;
    float m_70; int m_74;
    CString m_78;
    int m_80, m_84, m_88, m_8c;
    __int64 m_90;
    int m_98, m_9c, m_a0, m_a4, m_a8, m_ac, m_b0, m_b4;
    CStringW m_b8, m_c0;
    unsigned char m_c8; unsigned char m_c9; short m_ca; int m_cc;
    CStringW m_d0, m_d8;
    QuestMask m_e0;
};
MS2_CHECK_SIZE(CPortalData, 0x120);

class CPortalHistoryData : public CPtred {
public:
    CPortalHistoryData();
    // virtual ~CPortalHistoryData();   // 0x140730070 (??_G 0x1407300e0) implicit: the exe dtor stores no vptr
    CPortalData m_data;     // +0x18
    __int64 m_138;
};
MS2_CHECK_SIZE(CPortalHistoryData, 0x140);
