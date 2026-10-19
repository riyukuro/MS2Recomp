// pvpmanager.h - CPVPManager (RTTI .?AVCPVPManager@@, 0x108 bytes, TSingleton<CPVPManager>), the PvP manager singleton.
// Not an original header: the member and helper-class names are invented (Unk_*); layout proven from the ctor
// 0x141280b40 and the component ctors 0x141281090 / 0x141281490.
//
// Members: a timer block at +0x8 (a notice timer plus a pointer vector), a block of two entry tables at +0x68
// and the rank-duel component at +0xc8. The three of them forward the server's PvP packets (OnMessage).
#pragma once

#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cpvprankduelcomponent.h"

// The notice timer (0x48 bytes). Its worker functions live in the neighbouring unit (unit_141017950).
class Unk_PvpTimer
{
public:
    Unk_PvpTimer(int nId, float fA, float fB, float fC, int nE)         // 0x141281090
    {
        m_0 = 0;
        m_8 = 0;
        m_nId = nId;
        m_fA = fA;
        m_fB = fB;
        m_fC = fC;
        m_20 = 0xffffffff;
        m_28 = 0;
        m_30 = 0;
        m_nE = nE;
        m_38 = 0;
        m_40 = 0;
        FUN_1412818f0(fA, fB, fC, false);
    }
    ~Unk_PvpTimer() noexcept(false) { try { FUN_14101ac20(); } catch (...) {} }         // 0x1412814e0

    void FUN_1412818f0(float fA, float fB, float fC, bool bApply);      // 0x1412818f0
    void FUN_14101af70();
    unsigned FUN_14101a900(unsigned __int64 nValue);
    void FUN_14101a9f0(unsigned nIndex);
    void FUN_14101ac20();
    void FUN_141017e80();                                               // clear
    void FUN_141017950(int nMessage, CInPacket& packet);                // OnMessage

    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_0;
    unsigned __int64 m_8;
    int m_nId;                                                          // +0x10
    float m_fA;                                                         // +0x14
    float m_fB;                                                         // +0x18
    float m_fC;                                                         // +0x1c
    unsigned __int64 m_20;
    unsigned __int64 m_28;
    int m_30;
    int m_nE;                                                           // +0x34
    void* m_38;
    void* m_40;
};
MS2_CHECK_SIZE(Unk_PvpTimer, 0x48);

struct Unk_PvpTimerItem;
struct Unk_PvpEntryItem;
struct Unk_PvpEntryTarget;

// Timer block (0x60): the timer, then a vector of owned pointers.
class Unk_PvpTimerBlock
{
public:
    Unk_PvpTimerBlock() : m_timer(0x11, 0.75f, 0.25f, 2.25f, 10) {}     // 0x1412813f0
    ~Unk_PvpTimerBlock() noexcept;                                      // 0x141281610

    MS2_LAYOUT_FRIEND;
    Unk_PvpTimer m_timer;                                               // +0x00
    std::vector<Unk_PvpTimerItem*> m_items;                             // +0x48
};
MS2_CHECK_SIZE(Unk_PvpTimerBlock, 0x60);

// One entry table (0x30): two ints, a vector of owned pointers and a map to flagged records.
class Unk_PvpEntryTable
{
public:
    Unk_PvpEntryTable() { FUN_14101ef40(); }                            // 0x141281490
    ~Unk_PvpEntryTable() {}                                             // 0x141281670

    void FUN_14101ef40();                                               // clear
    void FUN_14101b7f0() { FUN_14101ef40(); }

    MS2_LAYOUT_FRIEND;
    int m_0;
    int m_4;
    std::vector<Unk_PvpEntryItem*> m_items;                             // +0x08
    std::map<__int64, Unk_PvpEntryTarget*> m_targets;                   // +0x20
};
MS2_CHECK_SIZE(Unk_PvpEntryTable, 0x30);

class Unk_PvpEntryBlock
{
public:
    Unk_PvpEntryBlock() {}                                              // 0x141281450
    ~Unk_PvpEntryBlock() {}                                             // 0x141281640

    void FUN_14101b7f0();                                               // clear both tables
    void FUN_14101c0b0(void* pArgument);                                // forward
    void FUN_14101b830(int nMessage, CInPacket& packet);                // OnMessage

    MS2_LAYOUT_FRIEND;
    Unk_PvpEntryTable m_a;
    Unk_PvpEntryTable m_b;
};
MS2_CHECK_SIZE(Unk_PvpEntryBlock, 0x60);

class CPVPManager : public TSingleton<CPVPManager>
{
public:
    CPVPManager();                                                      // 0x141280b40
    virtual ~CPVPManager();                                             // 0x141280be0

    void Clear();                                                       // 0x141280c60
    void ForwardToEntries(void* pArgument);                             // 0x141280ca0
    void OnMessage(int nMessage, CInPacket& packet);                    // 0x141280cd0
    void SendCancelRequest();                                           // 0x141280d40
    int State() const { return m_nState; }                              // 0x1412818a0
    int Selection() const { return m_nSelection; }                      // 0x1412818d0
    CPvpRankDuelComponent* GetRankDuel() { return &m_rankDuel; }        // 0x140f97f00 (inline COMDAT, first emitted in uirankpvpdialog.cpp; name invented)

private:
    MS2_LAYOUT_FRIEND;
    Unk_PvpTimerBlock m_timers;                                         // +0x008
    Unk_PvpEntryBlock m_entries;                                        // +0x068
    CPvpRankDuelComponent m_rankDuel;                                   // +0x0c8
    int m_nState;                                                       // +0x100
    int m_nSelection;                                                   // +0x104
};
MS2_CHECK_SIZE(CPVPManager, 0x108);
MS2_CHECK_OFFSET(CPVPManager, m_timers, 0x8);
MS2_CHECK_OFFSET(CPVPManager, m_entries, 0x68);
MS2_CHECK_OFFSET(CPVPManager, m_rankDuel, 0xc8);
MS2_CHECK_OFFSET(CPVPManager, m_nState, 0x100);
