// pvpinfo.h - CPvPInfo (RTTI .?AVCPvPInfo@@, CPtred, 0x3c bytes): the pvp state a player carries (kind of pvp mode, the
// reward counters of the current match). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// ?\pvpinfo.cpp (0x140743430-0x140744670, directory commonfiles from the neighbouring objs). Member names are invented
// from their use. vftable: slot 0 only (the deleting destructor 0x1407441b0).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/stream.h"

class CPvPInfo : public CPtred
{
public:
    CPvPInfo();                                                         // 0x140743430
    virtual ~CPvPInfo();                                                //  0 0x1407434d0 (??_G 0x1407441b0)

    bool FUN_140743550();                                               // m_nPoint > 0
    bool FUN_140743590();                                               // mode 1
    bool FUN_1407435d0();                                               // mode 2
    bool FUN_140743610();                                               // mode 3
    bool FUN_140743650();                                               // mode 4
    bool FUN_140743690();                                               // mode 10
    bool FUN_1407436d0();                                               // mode 5 (one punch)
    int GetPoint();                                                // m_nPoint
    void FUN_140743730();                                               // reset
    void FUN_1407437b0(int nDelta);                                     // m_nKill += nDelta (never below 0)
    void FUN_140743810(__int64 nDelta);                                   // m_nUnk34 += nDelta
    void FUN_140743840(int nDelta);                                     // m_nWin += nDelta (never below 0); starts the match clock
    void FUN_1407438b0(int nDelta);                                     // m_nLose += nDelta (never below 0)
    void FUN_140743910();                                               // m_nTeam = random 0/1
    int FUN_140743940();                                                // reward item id of the mode
    void FUN_1407439a0(COutputStream* pOut);                            // encode point / team / mode
    void FUN_140743a10(CInPacket& packet);                              // decode point / team / mode
    void FUN_140743ab0(COutputStream* pOut);                            // encode win / lose / kill
    void FUN_140743b20(CInPacket& packet);                              // decode win / lose / kill

    int m_nPoint;                                                       // +0x18
    int m_nTeam;                                                        // +0x1c
    int m_nUnk20;                                                       // +0x20 (-1)
    int m_nKill;                                                        // +0x24
    int m_nWin;                                                         // +0x28
    int m_nLose;                                                        // +0x2c
    int m_nMode;                                                        // +0x30
    int m_nUnk34;                                                       // +0x34
    int m_nStartTime;                                                   // +0x38 match clock (0 = not started)
};
MS2_CHECK_SIZE(CPvPInfo, 0x40);
MS2_CHECK_OFFSET(CPvPInfo, m_nPoint, 0x18);
MS2_CHECK_OFFSET(CPvPInfo, m_nKill, 0x24);
MS2_CHECK_OFFSET(CPvPInfo, m_nMode, 0x30);
MS2_CHECK_OFFSET(CPvPInfo, m_nStartTime, 0x38);

// The two record blocks of the pvp observer popup (ui id 0x4e96; the block is read from a packet, see
// client\ms2\triggerservice.cpp which holds the same layouts). The 32-bit wire values are zero-extended into the
// 64-bit slots.
struct Unk_TrigPvpA
{
    __int64 m_0;
    unsigned __int64 m_8, m_10;
    int m_18, m_1c;
    __int64 m_20;
    unsigned __int64 m_28, m_30;
    int m_38, m_3c;
};
MS2_CHECK_SIZE(Unk_TrigPvpA, 0x40);
struct Unk_TrigPvpB
{
    __int64 m_0;
    unsigned __int64 m_8, m_10;
    int m_18, m_1c;
    __int64 m_20;
    unsigned __int64 m_28, m_30;
    int m_38, m_3c, m_40, m_44;
};
MS2_CHECK_SIZE(Unk_TrigPvpB, 0x48);
void FUN_140743bc0(Unk_TrigPvpA* pBlock, COutputStream* pOut);         // encode
void FUN_140743ca0(Unk_TrigPvpA* pBlock, CInPacket* pPacket);          // decode
void FUN_140743e20(Unk_TrigPvpB* pBlock, COutputStream* pOut);
void FUN_140743f50(Unk_TrigPvpB* pBlock, CInPacket* pPacket);
