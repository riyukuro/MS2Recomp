// tcreatecharinfo.h - PLACEHOLDER for TCreateCharInfo (RTTI .?AUTCreateCharInfo@@, bases CPtred; ctors 0x14107ac30 /
// 0x14107acb0, dtor 0x14107ad50, deleting dtor 0x14107cba0) and the 12-byte equip record it embeds twice. NOT an
// original header; only the fields scenestatemulti.cpp touches are named. The unit that owns the code is
// ?\tcreatecharinfo.cpp (0x14107ac30-0x14107ce50, unrecovered). Size 0x60: byte at +0x58 is the last member used.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class MyPC;
class PC;

// 12-byte appearance record (two per character: the two equip colour slots); default ctor 0x1409f72f0.
struct Unk_CharEquip
{
    Unk_CharEquip();                                        // 0x1409f72f0
    int m_a, m_b, m_c;
};
MS2_CHECK_SIZE(Unk_CharEquip, 0xc);

class TCreateCharInfo : public CPtred
{
public:
    TCreateCharInfo();                                      // 0x14107ac30
    TCreateCharInfo(int nType, int nGender);                // 0x14107acb0
    virtual ~TCreateCharInfo();                             // 0x14107ad50

    void FUN_14107ae00();                                   // fill with a random gender and the default appearance
    int FUN_14107b440(PC* pPC);                           // apply to a pc
    int FUN_14107c3a0(PC* pPC);                           // apply to a pc and its default items
    void FUN_14107ad90();                                   // reset to the defaults
    void FUN_14107afa0();                                   // both equip records = the default appearance

    int m_nType;                                            // +0x18 (3 = lobby preview)
    unsigned long long m_n20;                               // +0x20
    int m_nGender;                                          // +0x28
    int m_nJobCode;                                         // +0x2c
    int m_n30;                                              // +0x30
    int m_n34;                                              // +0x34
    CStringW m_str38;                                       // +0x38
    Unk_CharEquip m_equip[2];                               // +0x40
    bool m_b58;                                             // +0x58
};
MS2_CHECK_SIZE(TCreateCharInfo, 0x60);
MS2_CHECK_OFFSET(TCreateCharInfo, m_equip, 0x40);
MS2_CHECK_OFFSET(TCreateCharInfo, m_b58, 0x58);
