// CGuildManager (RTTI .?AVCGuildManager@@): the client's guild state and the guild packet handlers.
// Bases: TSingleton<CGuildManager> +0 (vftable 0x142f0a5d8, s_instance 0x143aaee00), CGuildInfo +8 (vftable
// 0x142f0a5e8, no overrides). sizeof 0x480 (operator new in the singleton setup). Names other than the RTTI class
// names are inferred; methods without a proven name keep FUN_<va>.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <deque>
#include <map>
#include <set>
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/ascript.h"
class CInPacket;
class NotifyObject;
class CMsgBoxData;
class PCBase;
struct ItemEntity;
// The guild a notice points at (the second base at +8 carries the id and the name).
class Unk_GuildTargetInfo {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual __int64 vfunc_4();                                  // the guild id
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual CStringW vfunc_8();                                 // the guild name
};
class Unk_GuildTargetBase { public: virtual void vfunc_0(); };
class Unk_GuildTarget : public Unk_GuildTargetBase, public Unk_GuildTargetInfo {};

class CGuildManager : public TSingleton<CGuildManager>, public CGuildInfo {
public:
    CGuildManager();
    virtual ~CGuildManager();
    void FUN_1413b5e80();
    void FUN_1413b5f90();
    void FUN_1413b6110();
    int FUN_1413b6160();
    CStringW FUN_14197df60() { return m_targetGuildName; }   // inline COMDAT (uiguilddialog.cpp: the championship page)
    int FUN_1413b61a0();
    MS2Ptr<CGuildMember> FUN_1413b6200(__int64 characterId);
    void FUN_1413b6370(CInPacket& packet);
    bool FUN_1413b6d10(CStringW name);
    bool FUN_1413b7020();
    bool FUN_1413b71c0(CStringW name);
    void FUN_1413b74f0(int accept);
    void FUN_1413b75a0();
    void FUN_1413b76c0(CStringW name);
    void FUN_1413b78c0(CStringW name, int grade);
    void FUN_1413b7ad0(CStringW name);
    bool FUN_1413b7c70(int kind, CStringW text);
    bool FUN_1413b80d0(const CStringW& text);
    bool FUN_1413b8230();
    bool FUN_1413b8460();
    bool FUN_1413b8540(int amount);
    void FUN_1413b8a80(CString text);
    void FUN_1413b8c40(int index, CGuildGrade grade);
    void FUN_1413b8e60(int focus, int value);
    void FUN_1413b8fe0(int skillId);
    void FUN_1413b96e0(int skillId);
    void FUN_1413b9ac0(int skillId);
    void FUN_1413ba080(int eventId);
    void FUN_1413ba310(int eventId);
    void FUN_1413ba4b0();
    void FUN_1413ba820(int level, int theme);
    void FUN_1413babf0(int theme);
    void FUN_1413baef0(int posterId, unsigned char show);
    void FUN_1413bb000(Unk_GuildNpcKind kind);
    bool FUN_1413bb490(ItemEntity& item, const CStringW& receiver);
    void FUN_1413bbb80();
    bool FUN_1413bbc10(const CStringW& title, const CStringW& body);
    void FUN_1413bbe80();
    void FUN_1413bbf70(ATL::CAtlArray<MS2Ptr<CGuildPVPHistoryData>>& out);
    void FUN_1413bbfe0(ATL::CAtlArray<MS2Ptr<CGuildPVPSeasonHistoryData>>& out);
    void FUN_1413bc050();
    void FUN_1413bc190();
    void FUN_1413bc1f0(__int64 guildId, CStringW guildName);
    void FUN_1413bc250(Unk_GuildTarget* target);
    int FUN_1413bc390();
    void FUN_1413bc4a0(__int64 guildId);
    void FUN_1413bc540(__int64 guildId);
    void FUN_1413bc5b0(__int64 characterId, int accept);
    void FUN_1413bc630();
    void FUN_1413bc6a0();
    void FUN_1413bc710(bool anyFocus);
    bool FUN_1413bc860(CStringW name);
    int FUN_1413bca70(std::map<__int64, PCBase*>& out);
    int FUN_1413bcbc0(std::map<__int64, PCBase*>& out);
    void FUN_1413bcd10();
    void FUN_1413bce40(int skillId, unsigned short skillLevel);
    int FUN_1413bd050(int skillId, int skillLevel);
    int FUN_1413bd1a0(int skillId, int skillLevel);
    void FUN_1413bd2e0();
    void FUN_1413bd3f0();
    void FUN_1413bd4c0();
    int FUN_1413bd560();
    void FUN_1413bd5c0(NotifyObject* notify);
    void FUN_1413bd640(bool show);
    void FUN_1413c66f0(int kind, int code, int arg);
    CStringW FUN_1413c7c20();
    bool FUN_1413c7cb0(int result, const CMsgBoxData& box);
    void FUN_1413c7900(CInPacket& packet);
    void FUN_1413c7aa0(CInPacket& packet);                                 // reload the grade list
    void FUN_1413c7d40(ATL::CAtlArray<MS2Ptr<CSearchGuildJoin>>& out) const;
    MS2Ptr<CSearchGuildJoin> FUN_1413c7dc0(const CStringW& guildName) const;
    void FUN_1413c7ed0();
    void FUN_1413c7f00(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForChar>>& out) const;
    void FUN_1413c7f80(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForGuild>>& out) const;
    MS2Ptr<CGuildJoinRequestForChar> FUN_1413c8000(__int64 guildId) const;
    // @0x14197e010
    int FUN_14197e010() { return m_468; }                                  // the search propensity (inline; uiguilddialog.cpp)
    // @0x14197e040
    void FUN_14197e040(int nValue) { m_468 = nValue; }
    // @0x14197dfb0
    __int64 FUN_14197dfb0() { return m_targetGuildId; }                 // the pending join / visit guild (inline; uiguilddialog.cpp)

    // packet handlers dispatched by FUN_1413b6370 (exe order)
    void FUN_1413bd680(CInPacket& packet);
    void FUN_1413bd8a0(CInPacket& packet);
    void FUN_1413bda00(CInPacket& packet);
    void FUN_1413bdaf0(CInPacket& packet);
    void FUN_1413bdbb0(CInPacket& packet);
    void FUN_1413be020(CInPacket& packet);
    void FUN_1413be150(CInPacket& packet);
    void FUN_1413be350(CInPacket& packet);
    void FUN_1413be400(CInPacket& packet);
    void FUN_1413be460(CInPacket& packet);
    void FUN_1413be670(CInPacket& packet);
    void FUN_1413be7e0(CInPacket& packet);
    void FUN_1413be870(CInPacket& packet);
    void FUN_1413beb10(CInPacket& packet);
    void FUN_1413bebc0(CInPacket& packet);
    void FUN_1413bece0(CInPacket& packet);
    void FUN_1413bee70(CInPacket& packet);
    void FUN_1413beed0(CInPacket& packet);
    void FUN_1413beff0(CInPacket& packet);
    void FUN_1413bf050(CInPacket& packet);
    void FUN_1413bf130(CInPacket& packet);
    void FUN_1413bf2a0(CInPacket& packet);
    void FUN_1413bf340(CInPacket& packet);
    void FUN_1413bf540(CInPacket& packet);
    void FUN_1413bf690(CInPacket& packet);
    void FUN_1413bf9a0(CInPacket& packet);
    void FUN_1413bfaf0(CInPacket& packet);
    void FUN_1413bfe50(CInPacket& packet);
    void FUN_1413c0030(CInPacket& packet);
    void FUN_1413c0250(CInPacket& packet);
    void FUN_1413c0430(CInPacket& packet);
    void FUN_1413c0630(CInPacket& packet);
    void FUN_1413c0880(CInPacket& packet);
    void FUN_1413c0be0(CInPacket& packet);
    void FUN_1413c0d30(CInPacket& packet);
    void FUN_1413c0e70(CInPacket& packet);
    void FUN_1413c0fe0(CInPacket& packet);
    void FUN_1413c13d0(CInPacket& packet);
    void FUN_1413c15b0(CInPacket& packet);
    void FUN_1413c1720(CInPacket& packet);
    void FUN_1413c1840(CInPacket& packet);
    void FUN_1413c1960(CInPacket& packet);
    void FUN_1413c1c50(CInPacket& packet);
    void FUN_1413c1d30(CInPacket& packet);
    void FUN_1413c1f00(CInPacket& packet);
    void FUN_1413c2030(CInPacket& packet);
    void FUN_1413c23d0(CInPacket& packet);
    void FUN_1413c2590(CInPacket& packet);
    void FUN_1413c2860(CInPacket& packet);
    void FUN_1413c28e0(CInPacket& packet);
    void FUN_1413c2c60(CInPacket& packet);
    void FUN_1413c2e50(CInPacket& packet);
    void FUN_1413c2fc0(CInPacket& packet);
    void FUN_1413c3080(CInPacket& packet);
    void FUN_1413c3110(CInPacket& packet);
    void FUN_1413c3170(CInPacket& packet);
    void FUN_1413c3460(CInPacket& packet);
    void FUN_1413c3780(CInPacket& packet);
    void FUN_1413c39e0(CInPacket& packet);
    void FUN_1413c3c40(CInPacket& packet);
    void FUN_1413c3e50(CInPacket& packet);
    void FUN_1413c3ef0(CInPacket& packet);
    void FUN_1413c41b0(CInPacket& packet);
    void FUN_1413c4300(CInPacket& packet);
    void FUN_1413c4420(CInPacket& packet);
    void FUN_1413c4580(CInPacket& packet);
    void FUN_1413c45e0(CInPacket& packet);
    void FUN_1413c4870(CInPacket& packet);
    void FUN_1413c48b0(CInPacket& packet);
    void FUN_1413c4aa0(CInPacket& packet);
    void FUN_1413c4b60(CInPacket& packet);
    void FUN_1413c4bd0(CInPacket& packet);
    void FUN_1413c4c40(CInPacket& packet);
    void FUN_1413c4dd0(CInPacket& packet);
    void FUN_1413c4e20(CInPacket& packet);
    void FUN_1413c4ed0(CInPacket& packet);
    void FUN_1413c5000(CInPacket& packet);
    void FUN_1413c51c0(CInPacket& packet);
    void FUN_1413c5360(CInPacket& packet);
    void FUN_1413c5440(CInPacket& packet);
    void FUN_1413c5520(CInPacket& packet);
    void FUN_1413c5690(CInPacket& packet);
    void FUN_1413c5840(CInPacket& packet);
    void FUN_1413c59e0(CInPacket& packet);
    void FUN_1413c5c00(CInPacket& packet);
    void FUN_1413c5dc0(CInPacket& packet);
    void FUN_1413c5f90(CInPacket& packet);
    void FUN_1413c6180(CInPacket& packet);
    void FUN_1413c6460(CInPacket& packet);
    void FUN_1413c6580(CInPacket& packet);
    void FUN_1413c7700(CInPacket& packet);
    void FUN_1413c7810(CInPacket& packet);

    MS2Ptr<CGuildInviteInfo> m_invite;                                  // +0x378
    std::deque<MS2Ptr<CGuildPVPHistoryData>> m_pvpHistory;             // +0x388 (newest last, at most 10)
    __int64 m_lastPvpHistoryId;                                         // +0x3b0
    std::deque<MS2Ptr<CGuildPVPSeasonHistoryData>> m_pvpSeasonHistory; // +0x3b8
    bool m_3e0;
    bool m_noticeAttendance;                                            // +0x3e1 (cleared after the first notice)
    __int64 m_nextRefreshTime;                                          // +0x3e8
    __int64 m_targetGuildId;                                            // +0x3f0 (the guild of a pending join / guild-house visit)
    CStringW m_targetGuildName;
    bool m_400;
    ATL::CAtlArray<MS2Ptr<CSearchGuildJoin>> m_searchResults;             // +0x408
    ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForChar>> m_joinRequestsForChar; // +0x428
    ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForGuild>> m_joinRequestsForGuild; // +0x448
    int m_468;
    std::set<std::pair<int, unsigned short>> m_470;                    // +0x470 (skill id, level) uses awaiting the server ack
};
MS2_CHECK_OFFSET(CGuildManager, m_invite, 0x378);
MS2_CHECK_OFFSET(CGuildManager, m_pvpHistory, 0x388);
MS2_CHECK_OFFSET(CGuildManager, m_pvpSeasonHistory, 0x3b8);
MS2_CHECK_OFFSET(CGuildManager, m_targetGuildName, 0x3f8);
MS2_CHECK_OFFSET(CGuildManager, m_searchResults, 0x408);
MS2_CHECK_OFFSET(CGuildManager, m_468, 0x468);
MS2_CHECK_SIZE(CGuildManager, 0x480);
