// weddingproxy.h - PLACEHOLDER for WeddingProxy (RTTI .?AVWeddingProxy@@, 0x140 bytes), the own character's wedding
// record: the couple's two partner records, the wedding messages and the meso log. NOT an original header. Embedded in
// WeddingManager at +0x8 (WeddingManager::FUN_140d295d0). Layout from the v2525 reference decomp (work/ext/v2525,
// include/ms2/client/WeddingProxy.h: ctor 0x1408fea10, dtor 0x1408feb00) and the ctor/dtor/serialisers of weddingproxy.cpp;
// member names are invented.
#pragma once

#include <afx.h>
#include <list>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"

class COutputStream;
class CInPacket;
class WeddingHallTicket;

// One partner of the couple (0x50 bytes, ctor 0x1408fe100): a lock around the character id, name and online flag.
struct Unk_WeddingPartner
{
    Unk_WeddingPartner();                                   // 0x1408fe100
    ~Unk_WeddingPartner();                                  // 0x1408fe150
    void Reset();                                           // 0x1408fe190
    void Assign(Unk_WeddingPartner& other);                 // 0x1408fe200
    void Write(COutputStream& out);                         // 0x1408fe2d0
    void Read(CInPacket& in);                               // 0x1408fe390
    void SetName(const CStringW& strName);                  // 0x1408fe4e0
    CStringW GetName();                                     // 0x1408fe540
    void SetOnline(bool bOnline);                           // 0x1408fe5c0
    bool IsOnline();                                        // 0x1408fe610

    CLockCriticalSection m_lock;                            // +0x0
    __int64 m_nCharacterId;                                 // +0x30
    __int64 m_nAccountId;                                   // +0x38
    CStringW m_strName;                                     // +0x40 the character name
    bool m_bOnline;                                         // +0x48
};
MS2_CHECK_OFFSET(Unk_WeddingPartner, m_strName, 0x40);
MS2_CHECK_SIZE(Unk_WeddingPartner, 0x50);

// A meso log row (0x18 bytes, ctor 0x1408fe660).
struct Unk_WeddingLog
{
    Unk_WeddingLog();                                       // 0x1408fe660
    unsigned int m_nType;                                   // +0x0
    __int64 m_nTime;                                        // +0x8
    __int64 m_nAmount;                                      // +0x10
};
MS2_CHECK_SIZE(Unk_WeddingLog, 0x18);

// The meso log (0x10 bytes): the last 25 rows, serialised as a count and the rows.
struct Unk_WeddingLogList
{
    Unk_WeddingLogList();                                   // 0x1408fe6a0
    ~Unk_WeddingLogList();                                  // 0x1408fe6d0
    void Clear();                                           // 0x1408fe700
    void Assign(Unk_WeddingLogList& other);                 // 0x1408fe730
    void Write(COutputStream& out);                         // 0x1408fe770
    void Read(CInPacket& in);                               // 0x1408fe860
    void Add(unsigned int nType, __int64 nAmount, __int64 nTime);   // 0x1408fe970
    std::list<Unk_WeddingLog> m_list;
};
MS2_CHECK_SIZE(Unk_WeddingLogList, 0x10);

class WeddingProxy : public CPtred
{
public:
    WeddingProxy();                                         // 0x1408fea10
    virtual ~WeddingProxy();                                // 0x1408feb00 (??_G 0x140902380)

    void Init();                                            // 0x1408febd0
    void Assign(WeddingProxy& other);                       // 0x1408fec60
    void Write(COutputStream& out);                         // 0x1408feda0
    void Read(CInPacket& in);                               // 0x1408ff040
    Unk_WeddingPartner* GetSelf(__int64 nCharacterId);      // 0x1408ff3b0 the other partner of the couple (exe symbol name)
    Unk_WeddingPartner* GetPartner(__int64 nCharacterId);   // 0x1408ff410
    bool IsBride(__int64 nCharacterId);                     // 0x1408ff470
    bool IsGroom(__int64 nCharacterId);                     // 0x1408ff4c0
    __int64 GetMeso();                                      // 0x1408ff500
    void SetMeso(__int64 nMeso);                            // 0x1408ff560
    void AddMeso(unsigned int nType, __int64 nAmount);      // 0x1408ff5c0
    void ClearMeso();                                       // 0x1408ff6a0
    void SetMessageW(const CStringW& str, bool bFirst);     // 0x1408ff710
    void SetMessageA(const CString& str, bool bFirst);      // 0x1408ff7a0
    CStringW GetMessageW(bool bFirst);                      // 0x1408ff830
    CString GetMessageA(bool bFirst);                       // 0x1408ff8e0
    int CheckPropose();                                     // 0x140900610
    int CheckProposeEnd();                                  // 0x140900690
    int CheckBase();                                        // 0x140900710
    int CheckVisit(WeddingHallTicket& ticket, __int64 nLimit);                  // 0x140900780
    int CheckReservation(WeddingHallTicket& ticket, __int64 nCharacterId);      // 0x140900830
    int CheckReservationCancel(WeddingHallTicket& ticket, __int64 nCharacterId);    // 0x1409008e0
    int CheckReservationChange(WeddingHallTicket& current, WeddingHallTicket& wanted, __int64 nCharacterId);    // 0x140900990
    int CheckDivorce();                                     // 0x140900a80
    int CheckLeave(__int64 nCharacterId);                   // 0x140900ae0
    int CheckEnter(__int64 nCharacterId);                   // 0x140900b40
    int CheckState2(__int64 nCharacterId);                  // 0x140900ba0
    bool IsPartner(__int64 nCharacterId);                   // 0x140900bd0
    __int64 GetPromiseLimit();                              // 0x140900c30
    __int64 GetDivorceTime();                               // 0x140900c80
    __int64 GetCoolingOffTime();                            // 0x140900cf0
    bool IsProposeCooldownOver();                           // 0x140900e00
    __int64 GetExp();                                       // 0x140900e50

    __int64 m_n18;                                          // +0x18
    int m_nState;                                           // +0x20 the wedding progress state
    __int64 m_n28;                                          // +0x28 the state's time
    __int64 m_n30;                                          // +0x30 the marriage time
    Unk_WeddingPartner m_groom;                             // +0x38
    Unk_WeddingPartner m_bride;                             // +0x88
    CLockCriticalSection m_lock;                            // +0xd8
    CStringW m_strMessageW1;                                // +0x108
    CStringW m_strMessageW0;                                // +0x110
    CString m_strMessageA1;                                 // +0x118
    CString m_strMessageA0;                                 // +0x120
    __int64 m_nMeso;                                        // +0x128
    Unk_WeddingLogList m_log;                               // +0x130
};
MS2_CHECK_OFFSET(WeddingProxy, m_groom, 0x38);
MS2_CHECK_OFFSET(WeddingProxy, m_bride, 0x88);
MS2_CHECK_OFFSET(WeddingProxy, m_lock, 0xd8);
MS2_CHECK_OFFSET(WeddingProxy, m_log, 0x130);
MS2_CHECK_SIZE(WeddingProxy, 0x140);
