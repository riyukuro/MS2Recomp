// mentoringmanager.h - CMentoringManager (RTTI .?AVCMentoringManager@@, 0x78 bytes, TSingleton<CMentoringManager>), the
// client side of the mentoring system: it keeps the invitation lists (the mentors who asked, the accepted mentees) and
// handles the server's mentoring packet (protocol byte first, 15 cases). Not an original header; the member names are
// invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/mentor.h"
#include "ms2/placeholder/cinpacket.h"

class CMentoringManager : public TSingleton<CMentoringManager>
{
public:
    typedef Unk_MentorPtr<CMentor> MentorPtr;
    typedef ATL::CAtlArray<MentorPtr> MentorArray;

    CMentoringManager();                                    // 0x140b71440
    virtual ~CMentoringManager();                           // 0x140b714b0

    void FUN_140b71500();                                   // reset the state and both lists
    unsigned FUN_140b71580();                               // the local player's mentoring state (0 without a player)
    int FUN_140b715c0();                                    // m_n18 while the m_n20 date is still in the future
    bool FUN_140b71610();                                   // m_n20 has passed
    int FUN_140b71650();                                    // m_nC while m_n10 has not passed
    MentorPtr FUN_140b71680(int nIndex);                    // the nIndex-th accepted mentee
    size_t FUN_140b71720();                                 // number of accepted mentees
    size_t FUN_140b71750();                                 // number of waiting mentors
    CStringW FUN_140b71780();                               // the character name with the id m_n28
    CStringW FUN_140b718b0();                               // the character name with the id m_n30
    void OnPacket(CInPacket& packet);                       // 0x140b719e0 dispatch on the protocol byte

private:
    MS2_LAYOUT_FRIEND;
    void OnResult(CInPacket& packet);                       // 1: set the mentoring state of a player
    void OnMentorList(CInPacket& packet);                   // 2: the waiting mentors
    void OnMenteeList(CInPacket& packet);                   // 3: the accepted mentees
    void OnMenteeRegistered(CInPacket& packet);             // 4
    void OnInviteMentee(CInPacket& packet);                 // 5
    void OnMentorApproved(CInPacket& packet);               // 6
    void OnMentorDeclined(CInPacket& packet);               // 7
    void OnMentorRegistered(CInPacket& packet);             // 8
    void OnShowDialog(CInPacket& packet);                   // 9
    void OnSetDate(CInPacket& packet);                      // 10
    void OnSetCounts(CInPacket& packet);                    // 11
    void OnSetIds(CInPacket& packet);                       // 12
    void OnMentorRequest(CInPacket& packet);                // 14
    void OnPairMode(CInPacket& packet);                     // 15
    void OnError(CInPacket& packet);                        // 16

    int m_n8;                                               // +0x08 set by case 11
    int m_nC;                                               // +0x0c set by case 11
    __int64 m_n10;                                          // +0x10 set by case 11 (a date)
    int m_n18;                                              // +0x18 set by case 10
    __int64 m_n20;                                          // +0x20 set by case 10 (a date)
    __int64 m_n28;                                          // +0x28 set by case 12 (a character id)
    __int64 m_n30;                                          // +0x30 set by case 12 (a character id)
    MentorArray m_mentors;                                  // +0x38 the waiting mentors
    MentorArray m_mentees;                                  // +0x58 the accepted mentees
};
MS2_CHECK_SIZE(CMentoringManager, 0x78);
MS2_CHECK_OFFSET(CMentoringManager, m_n10, 0x10);
MS2_CHECK_OFFSET(CMentoringManager, m_n20, 0x20);
MS2_CHECK_OFFSET(CMentoringManager, m_mentors, 0x38);
MS2_CHECK_OFFSET(CMentoringManager, m_mentees, 0x58);
