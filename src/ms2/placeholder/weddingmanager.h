// weddingmanager.h - PLACEHOLDER for WeddingManager (RTTI .?AVWeddingManager@@, 0x228 bytes). NOT an original header.
// Bases: TSingleton<WeddingManager> at +0x0. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the client
// wedding flow: packet 0xba handlers (mode byte), the request senders and the message box callbacks. Owning unit
// ?\weddingmanager.cpp (0x141b835d0-0x141b90cd0). Layout and method names follow the v2525 reference decomp
// (work/ext/v2525, include/ms2/client/WeddingManager.h); member names are invented.
#pragma once

#include <afx.h>
#include <map>
#include <set>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/weddingproxy.h"
#include "ms2/placeholder/weddinghallticket.h"

class CInPacket;
class CMsgBoxData;
class PCBase;
class AScript;
template <class T> class MS2Ptr;
class Unk_WeddingMail;

class WeddingManager : public TSingleton<WeddingManager>
{
public:
    WeddingManager();                                       // 0x141b835d0
    virtual ~WeddingManager();                              // 0x141b836b0
    WeddingProxy* FUN_140d295d0();                          // the own wedding record (+0x8)

    void OnPacket(CInPacket& packet);                       // 0x141b83750
    void OnProxy(CInPacket& packet);                        // 0x141b83a20 (mode 0x00)
    void OnTicketList(CInPacket& packet);                   // 0x141b83a50 (mode 0x01)
    void OnResult(CInPacket& packet);                       // 0x141b83b80 (mode 0x02)
    void OnPropose(CInPacket& packet);                      // 0x141b83f90 (mode 0x03)
    void OnProposeAccepted(CInPacket& packet);              // 0x141b842b0 (mode 0x06)
    void OnReservationRequest(CInPacket& packet);           // 0x141b843a0 (mode 0x0d)
    void OnReserveOk(CInPacket& packet);                    // 0x141b846f0 (mode 0x0f)
    void OnInvitationTicket(CInPacket& packet);             // 0x141b84920 (mode 0x18)
    void OnInvitationRemove(CInPacket& packet);             // 0x141b84ac0 (mode 0x19)
    void OnInvitationClear(CInPacket& packet);              // 0x141b84b50 (mode 0x17)
    void OnHallList(CInPacket& packet);                     // 0x141b84b80 (mode 0x1b)
    void OnInvitationOk(CInPacket& packet);                 // 0x141b84bc0 (mode 0x1d)
    void OnReservationCancelRequest(CInPacket& packet);     // 0x141b84c60 (mode 0x10)
    void OnReservationChangeRequest(CInPacket& packet);     // 0x141b84da0 (mode 0x11)
    void OnReserveCancelOk(CInPacket& packet);              // 0x141b85060 (mode 0x13)
    void OnMode14(CInPacket& packet);                       // 0x141b850f0 (mode 0x14)
    void OnMode16(CInPacket& packet);                       // 0x141b854c0 (mode 0x16)
    void OnDivorceRequest(CInPacket& packet);               // 0x141b85710 (mode 0x08)
    void OnMode23(CInPacket& packet);                       // 0x141b85850 (mode 0x23)
    void OnMode27(CInPacket& packet);                       // 0x141b85890 (mode 0x27)
    void OnMode1e(CInPacket& packet);                       // 0x141b85920 (mode 0x1e)
    void OnMode1f(CInPacket& packet);                       // 0x141b85a20 (mode 0x1f)
    void ShowStep();                                        // 0x141b85aa0
    void ShowLastStep();                                    // 0x141b85db0
    void ShowStepResult(int result);                        // 0x141b85fe0
    void PlayEmotion(int type);                             // 0x141b869f0
    void FacePartner(PCBase* user);                         // 0x141b8a4c0
    void OnMode27Accept(CInPacket& packet);                 // 0x141b86bd0
    void ShowProposeAnswer(const CStringW& name);           // 0x141b86e20
    const WeddingHallTicket& GetTicket();                   // 0x141b87160
    void SendReservationCancel();                           // 0x141b86520
    void SendInvitation(unsigned __int64 id);               // 0x141b86750
    void SendPropose(const CStringW& name);                 // 0x141b862d0
    void SendReservation(int packageId, int hallId, __int64 time, unsigned char night, bool agree);   // 0x141b86420
    void SendReservationChange(int packageId, int hallId, __int64 time, unsigned char night);         // 0x141b865c0
    int CheckPropose(unsigned __int64 id);                  // 0x141b87220
    bool CanVisit(int packageId, int hallId, __int64 id);   // 0x141b89a10
    bool IsPartnerOnline();                                 // 0x141b8a580
    bool IsInProgress();                                    // 0x141b89990
    bool CanStartWedding(__int64 partnerId);                // 0x141b867e0
    void ReadTicketMail(MS2Ptr<Unk_WeddingMail> mail, AScript* script);   // 0x141b873c0
    void ShowError(int code);                               // 0x141b87760
    void RefreshTicketsIfDirty();                           // 0x141b89030
    void CollectTickets(std::map<unsigned __int64, WeddingHallTicket>& out);   // 0x141b896f0
    void RefreshTickets();                                  // 0x141b89070
    int CanInvite(unsigned __int64 first, unsigned __int64 second, int count);   // 0x141b89860
    int GetInvitedCount();                                  // 0x141b89920
    void ApplyHallTicket();                                 // 0x141b89950
    void ApplyPartner();                                    // 0x141b899d0
    bool OnProposeAnswer(int result, const CMsgBoxData& box);           // 0x141b89bd0
    bool OnReservationAnswer(int result, const CMsgBoxData& box);       // 0x141b89d00
    bool OnReservationCancelAnswer(int result, const CMsgBoxData& box); // 0x141b89d90
    bool OnDivorceAnswer(int result, const CMsgBoxData& box);           // 0x141b89f40
    bool OnStepNext(int result, const CMsgBoxData& box);                // 0x141b8a2f0
    bool OnProposeSentAnswer(int result, const CMsgBoxData& box);       // 0x141b89ac0
    bool OnNoRefundAnswer(int result, const CMsgBoxData& box);          // 0x141b89e20
    bool OnReservationChangeAnswer(int result, const CMsgBoxData& box); // 0x141b89eb0
    bool OnNicknameAnswer(int result, const CMsgBoxData& box);          // 0x141b89fd0
    bool OnLastStepAnswer(int result, const CMsgBoxData& box);          // 0x141b8a360
    bool OnActingAnswer(int result, const CMsgBoxData& box);            // 0x141b8a3e0
    CStringW GetPartnerName();                              // 0x141b8a670

    WeddingProxy m_proxy;                                   // +0x8
    WeddingHallTicket m_ticket;                             // +0x148
    std::set<std::pair<unsigned __int64, unsigned __int64> > m_invited;   // +0x1e8
    int m_nStep;                                            // +0x1f8 0
    int m_nStepMax;                                         // +0x1fc 3
    CStringW m_strTarget;                                   // +0x200 the proposed-to / proposing name
    CStringW m_strPartner;                                  // +0x208
    bool m_bTicketsDirty;                                   // +0x210
    std::map<unsigned __int64, WeddingHallTicket> m_tickets;   // +0x218
};
MS2_CHECK_OFFSET(WeddingManager, m_proxy, 0x8);
MS2_CHECK_OFFSET(WeddingManager, m_ticket, 0x148);
MS2_CHECK_OFFSET(WeddingManager, m_invited, 0x1e8);
MS2_CHECK_OFFSET(WeddingManager, m_strTarget, 0x200);
MS2_CHECK_OFFSET(WeddingManager, m_tickets, 0x218);
MS2_CHECK_SIZE(WeddingManager, 0x228);
