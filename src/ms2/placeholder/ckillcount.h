// ckillcount.h - PLACEHOLDER for CKillCount (RTTI .?AVCKillCount@@, 0x10 bytes): the kill-combo counter the HUD kill
// count (UIKillCount) owns. NOT an original header. Owning unit ?\killcount.cpp (0x14064c590-0x14064ca50, unrecovered);
// every out-of-line member is a symbols-manual row or an auto-bound FUN_<va>. vftable 0x142d6e0f0 (slot 0 = ??_G
// 0x14064c8f0), ctor 0x14064c590 (m_08 = m_0c = 0), dtor 0x14064c5d0.
// Recovered by w236 with ?\uikillcount.cpp. m_08 is the combo count, m_0c the tick of the last kill.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"

class CKillCount
{
public:
    CKillCount();                                                   // 0x14064c590
    virtual ~CKillCount();                                          //  0 0x14064c5d0 (??_G 0x14064c8f0)
    int RegisterKill(unsigned short a1, unsigned short a2);        // register a kill (levels of the killer and the victim): 1 = show it
    double GetBonusExpRate();                                         // lua calcKillCountBonusExpRate(count)
    unsigned int GetGrade();                                   // lua value for the count
    CStringW GetKillCountMessage();                                       // the lua text key for the count
    void Reset();                                           // 0x14064c7d0 reset the combo
    int GetCount();                                            // the combo count
    int GetLastKillTick();                                            // 0x14064c820 the tick of the last kill
    int IsComboAlive(int nTick);                                   // nonzero while the combo is still alive at nTick
    unsigned int CalcKillCount(unsigned short a1, unsigned short a2, int nDelta);   // 0x14064c8a0 lua calcKillCount

private:
    MS2_LAYOUT_FRIEND;
    int m_08;                                                       // +0x08 combo count
    int m_0c;                                                       // +0x0c tick of the last kill
};
MS2_CHECK_SIZE(CKillCount, 0x10);
MS2_CHECK_OFFSET(CKillCount, m_08, 0x8);
MS2_CHECK_OFFSET(CKillCount, m_0c, 0xc);
