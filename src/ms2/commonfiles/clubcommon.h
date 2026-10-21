// clubcommon.h - CClub / CClubMember / CClubMemberProxy / CClubCli (RTTI names). Header name assumed (owning unit
// commonfiles\clubcommon.cpp, 0x14020c3a0..). Layouts proved from the constructors, destructors, reset functions and
// stream readers/writers cited per member. Unit workers: add FUN_ member declarations here as you recover them.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"              // MS2Ptr<T> (16 bytes, object pointer at +8)
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/clubuserclub.h"          // Club::NameInfo, Club::UserClub
#include "ms2/commonfiles/guilddef_1.h"          // Unk_GuildTriple (trophy triple)
#include "ms2/commonfiles/os.h"                   // TSingleton

class CInPacket;
class COutPacket;
class Unk_140165cf0;
class Unk_UserProxy;
namespace Club { class SaveMember; }

// Player snapshot shared by club members. 0xa8 bytes. ctor 0x14020d270, dtor 0x14020d310, reset 0x14020d380,
// writer 0x14020d9a0 (field order: account, character, name, gender, jobCode, job, level, mapId, channel, picture,
// +0x40, +0x44, +0x48, +0x50, trophy). Name get/set 0x14020e5d0/0x14020e650 and picture get/set
// 0x14020e6c0/0x14020e740 hold m_lock.
class CClubMemberProxy : public CPtred
{
public:
    CClubMemberProxy();
    virtual ~CClubMemberProxy();                    // ??_G 0x1402127a0, vftable 0x142cf3958
    CStringW FUN_14020e5d0();                       // name (under m_lock)
    void FUN_14020e650(CStringW strName);           // set the name (under m_lock)
    CString FUN_14020e6c0();                        // picture (under m_lock)
    void FUN_14020e740(CString strPicture);         // set the picture (under m_lock)
    void FUN_14020d380();                           // reset all fields
    void FUN_14020d4a0(CStringW strName, int nJobCode, int nJob, short nLevel, CString strPicture);   // reset, then set these
    void FUN_14020d580(COutputStream& out);         // write the map id
    void FUN_14020d690(COutputStream& out);         // write name, job code, job, level, picture
    void FUN_14020d610(COutputStream& out);         // write the whole snapshot (thunk of FUN_14020d9a0)
    void FUN_14020d9a0(COutputStream& out);         // write the whole snapshot
    void FUN_14020db80(CInputStream* in);           // read the whole snapshot
    void FUN_14020de80(COutputStream& out);         // write the short form
    void FUN_14020df70(CInputStream* in);           // read the short form
    void FUN_14020e350(Unk_UserProxy* p);           // fill from a user proxy (0x1408f19e0 / 0x1408f1a60 accessors)
    void FUN_14020d770(CInPacket& packet);          // read the short form from a packet
    void FUN_14020d5c0(CInPacket& packet);          // read from a packet (clubcli.cpp)
    void FUN_14020d640(CInPacket* packet);          // read (null-checked packet pointer)
    void FUN_14020e130(const CClubMemberProxy& o);  // copy assignment
    __int64 m_accountId;                            // +0x18
    __int64 m_characterId;                          // +0x20
    unsigned char m_gender;                         // +0x28 reset 3
    int m_jobCode;                                  // +0x2c
    int m_job;                                      // +0x30
    short m_level;                                  // +0x34
    int m_mapId;                                    // +0x38
    int m_channel;                                  // +0x3c (written as a short)
    int m_40;                                       // +0x40
    int m_44;                                       // +0x44
    int m_48;                                       // +0x48
    __int64 m_50;                                   // +0x50
    Unk_GuildTriple m_trophy;                       // +0x58 12-byte triple (ctor 0x140267ba0, writer 0x140267f50;
                                                    //       same type as userproxy.h Unk_UserProxyColor)
    CLockCriticalSection m_lock;                    // +0x68
    CStringW m_name;                                // +0x98
    CString m_picture;                              // +0xa0
};
MS2_CHECK_SIZE(CClubMemberProxy, 0xa8);
MS2_CHECK_OFFSET(CClubMemberProxy, m_gender, 0x28);
MS2_CHECK_OFFSET(CClubMemberProxy, m_level, 0x34);
MS2_CHECK_OFFSET(CClubMemberProxy, m_50, 0x50);
MS2_CHECK_OFFSET(CClubMemberProxy, m_trophy, 0x58);
MS2_CHECK_OFFSET(CClubMemberProxy, m_lock, 0x68);
MS2_CHECK_OFFSET(CClubMemberProxy, m_name, 0x98);
MS2_CHECK_OFFSET(CClubMemberProxy, m_picture, 0xa0);

// 0xf8 bytes (operator new(0xf8) in 0x1402102xx and clubcli). ctor 0x14020e7b0, dtor 0x14020e820,
// reset 0x14020e890.
class CClubMember : public CPtred
{
public:
    CClubMember();
    virtual ~CClubMember();                         // ??_G 0x140212760, vftable 0x142cf3968
    void FUN_14020ea50(CInPacket* packet);          // read from a packet
    void FUN_14020e950(CClubMember* o);             // copy (null-checked)
    void FUN_14020e890();                           // reset all fields
    void FUN_14020ea20(COutputStream& out);         // write (thunk of FUN_14020eaa0)
    void FUN_14020eaa0(COutputStream& out);         // write
    void FUN_14020eba0(CInputStream* in);           // read
    int FUN_14020eca0(Club::SaveMember* pSave);    // fill the save record when the dirty flag is set, then clear it
    void FUN_14020edb0(int nDirty);                 // set m_f4
    int FUN_14020edd0();                            // m_f4
    Unk_GuildTriple* FUN_14020edf0();               // &m_info.m_trophy
    void FUN_14020ee10();                           // m_info.m_trophy.FUN_140267c10()
    __int64 m_18;                                   // +0x18
    CClubMemberProxy m_info;                        // +0x20 (character id at +0x40 is compared with the club leader)
    int m_c8;                                       // +0xc8
    int m_cc;                                       // +0xcc
    __int64 m_d0;                                   // +0xd0
    __int64 m_d8;                                   // +0xd8
    int m_e0;                                       // +0xe0
    CStringW m_e8;                                  // +0xe8
    int m_f0;                                       // +0xf0 reset 1
    int m_f4;                                       // +0xf4
};
MS2_CHECK_SIZE(CClubMember, 0xf8);
MS2_CHECK_OFFSET(CClubMember, m_info, 0x20);
MS2_CHECK_OFFSET(CClubMember, m_c8, 0xc8);
MS2_CHECK_OFFSET(CClubMember, m_e8, 0xe8);
MS2_CHECK_OFFSET(CClubMember, m_f4, 0xf4);

// 0xd8 bytes, no CPtred base and no virtual destructor (CClubCli adds CPtred at +0xd8). ctor 0x14020ee40,
// dtor 0x14020ef00, vftable 0x142cf3978 (6 slots, inherited unchanged by CClubCli 0x142ddacd0).
// Reader 0x14020fd80 field order: id, name, leader account, leader character, leader name, creation time, state
// (byte), +0x50, +0x54, +0x90; setters 0x14020f130/f230/f4e0/f5b0/f720/f310/f3f0. Accessors hold m_lock.
class CClub
{
public:
    CClub();
    ~CClub();
    virtual void vfunc_0();                         // 0 0x14020efb0 reset all fields (also called by ctor/dtor)
    virtual void vfunc_1(int n);                    // 1 0x140216b50 (empty)
    virtual void vfunc_2(int n);                    // 2 0x140216e40 (empty)
    virtual int vfunc_3();                          // 3 0x1402133d0 return 0
    virtual int vfunc_4(MS2Ptr<CClubMember> spMember);  // 4 0x140210340 add member (by value; max 10, sets m_leader)
    virtual void vfunc_5(CStringW strName);         // 5 0x1402104e0 remove member by name (by value)
    // Accessors recovered by client\ms2\uiclubdialog.cpp (non-virtual; they take m_lock).
    CStringW FUN_14020f1a0();                       // m_name
    // clubcli.cpp users
    __int64 FUN_14020f0c0();                        // club id
    void FUN_14020f130(__int64 n);                  // set the club id
    unsigned FUN_14020f380();                       // max members (m_48)
    unsigned FUN_14020f540();                       // state (m_state)
    void FUN_14020f4e0(int nState);                 // set the state
    void FUN_14020f5b0(int nBuffId, int nBuffLevel);   // set m_50/m_54 then vfunc_2(1)
    void FUN_14020f230(const CStringW& strName);           // set the club name
    void FUN_14020f3f0(__int64 n);                  // set m_90
    void FUN_14020f720(__int64 nAccountId, __int64 nCharacterId, CStringW strName);   // set the leader, then vfunc_2(1)
    void FUN_1402107a0(const CStringW& strOldName, const CStringW& strNewName);   // rename a member
    CStringW FUN_14020f8c0();                       // leader name
    void FUN_14020fd80(CInPacket& packet);          // read the club
    __int64 FUN_14020f460();                        // name change available time
    int FUN_14020f640();                            // buff id
    unsigned FUN_14020f6b0();                       // buff level
    int FUN_140210df0();                            // member count
    int FUN_140211080(CStringW strName);            // 1 when the name is the leader's
    MS2Ptr<CClubMember> FUN_140210560(CStringW strName);   // find a member by name
    MS2Ptr<CClubMember> FUN_140210f70();            // leader
    __int64 FUN_14020f2a0();                        // creation time
    void FUN_14020f310(__int64 n);                  // set the creation time
    __int64 FUN_14020f7e0();                        // leader account id
    __int64 FUN_14020f850();                        // leader character id
    __int64 FUN_14020f950();                        // m_78
    void FUN_14020f9c0(__int64 n);                  // set m_78
    __int64 FUN_14020fa30();                        // m_80
    void FUN_14020fab0(__int64 n);                  // set m_80
    void FUN_14020fb20(COutputStream& out);         // write the club (header, then the members)
    void FUN_1402100e0(COutputStream& out);         // write the members
    void FUN_1402101e0(CInPacket& packet);          // read the members
    MS2Ptr<CClubMember> FUN_140210630(__int64 nId); // member by m_18
    void FUN_1402108e0(ATL::CAtlArray<__int64>& ids);   // character ids of the members whose m_c8 is 2
    void FUN_140210ad0(ATL::CAtlArray<MS2Ptr<CClubMember>>& members);   // members with the dirty flag set
    void FUN_140210be0(ATL::CAtlArray<MS2Ptr<CClubMember>>& members);   // members whose m_c8 is 2
    unsigned FUN_140210cf0();                       // number of members whose m_c8 is 2
    int FUN_140210e70();                            // number of those whose m_f0 is 0
    void FUN_140211000(MS2Ptr<CClubMember> spLeader);   // set the leader
    void FUN_1402109d0(ATL::CAtlArray<MS2Ptr<CClubMember>>& members);   // all members

    typedef ATL::CRBMap<CStringW, MS2Ptr<CClubMember>, ATL::CStringElementTraitsI<CStringW>> MemberMap;

    CLockCriticalSection m_lock;                    // +0x08
    __int64 m_clubId;                               // +0x38
    CStringW m_name;                                // +0x40
    int m_48;                                       // +0x48 reset 10
    int m_state;                                    // +0x4c (read as a byte)
    int m_50;                                       // +0x50
    int m_54;                                       // +0x54
    __int64 m_creationTime;                         // +0x58
    __int64 m_leaderAccountId;                      // +0x60
    __int64 m_leaderCharacterId;                    // +0x68
    CStringW m_leaderName;                          // +0x70
    __int64 m_78;                                   // +0x78
    __int64 m_80;                                   // +0x80
    CStringW m_88;                                  // +0x88
    __int64 m_90;                                   // +0x90
    MS2Ptr<CClubMember> m_leader;                   // +0x98 null ctor 0x140211ee0, reset(0) 0x140212520, dtor 0x140212330
    // +0xa8 members keyed by name, case-insensitive (Find 0x140212f90 -> _wcsicmp). CRBMap(10) ctor 0x140211bb0,
    // dtor 0x140212200, RemoveAll 0x140216500, SetAt 0x140216bd0, RemoveKey 0x140216660, Lookup 0x140214520.
    MemberMap m_members;
};
MS2_CHECK_SIZE(CClub, 0xd8);
MS2_CHECK_OFFSET(CClub, m_lock, 0x08);
MS2_CHECK_OFFSET(CClub, m_clubId, 0x38);
MS2_CHECK_OFFSET(CClub, m_state, 0x4c);
MS2_CHECK_OFFSET(CClub, m_creationTime, 0x58);
MS2_CHECK_OFFSET(CClub, m_leaderName, 0x70);
MS2_CHECK_OFFSET(CClub, m_90, 0x90);
MS2_CHECK_OFFSET(CClub, m_leader, 0x98);
MS2_CHECK_OFFSET(CClub, m_members, 0xa8);

namespace Club {
// Club invitation record: 0x38 bytes. ctor 0x14020c3a0, dtor 0x14020c420. The reader takes the input stream, the
// writer the output stream (both inline-called with a packet).
class PacketInvite : public CPtred
{
public:
    PacketInvite();
    virtual ~PacketInvite();
    void FUN_14020c720(CInputStream& in);           // read: id, then the three strings
    void FUN_14020c670(COutputStream& out);         // write: id, then the three strings
    void FUN_14020c490();                           // reset
    void FUN_14020c4f0(const PacketInvite* o);      // copy (null resets)
    void FUN_14020c580(CClub* pClub, CStringW strA, CStringW strB);   // fill from a club and two names
    __int64 m_inviteId;                             // +0x18 (the key of the manager's invite map)
    CStringW m_20;                                  // +0x20
    CStringW m_28;                                  // +0x28
    CStringW m_30;                                  // +0x30
};
// Persisted member record. 0x48 bytes. ctor 0x14020d180, dtor 0x14020d230.
class SaveMember : public CPtred
{
public:
    SaveMember();
    virtual ~SaveMember();
    __int64 m_id;                                   // +0x18
    unsigned char m_gender;                         // +0x20
    int m_jobCode;                                  // +0x24
    int m_job;                                      // +0x28
    int m_level;                                    // +0x2c
    int m_mapId;                                    // +0x30
    CStringW m_picture;                             // +0x38
    __int64 m_d8;                                   // +0x40
};
}
MS2_CHECK_SIZE(Club::PacketInvite, 0x38);
MS2_CHECK_SIZE(Club::SaveMember, 0x48);

// Client club: 0xf0 bytes (operator new(0xf0) in clubcli.cpp), no own members. ctor 0x140b12780, dtor 0x140b127f0,
// vftables 0x142ddacd0 (CClub part) and 0x142ddad08 (CPtred part at +0xd8; slot 0 thunk 0x140b19e80).
// The FUN_ members are the packet handlers and requests of client\ms2\clubcli.cpp.
class CClubCli : public CClub, public CPtred
{
public:
    CClubCli();
    virtual ~CClubCli();
    MS2Ptr<CClubMember> FUN_140b12850(__int64 nCharacterId);    // member by character id
    int FUN_140b129c0();                                        // number of members whose m_f0 is 0
    void FUN_140b12ad0(CInPacket& packet);                      // opcode 0xf
    void FUN_140b12d70(CInPacket& packet);                      // opcode 0x11
    void FUN_140b13060(CInPacket& packet);                      // opcode 0x12
    void FUN_140b13200(CInPacket& packet);                      // opcode 0x13
    void FUN_140b133c0(CInPacket& packet);                      // opcode 0x14
    void FUN_140b135d0(CInPacket& packet);                      // opcode 0x15
    void FUN_140b13a20(CInPacket& packet);                      // opcode 0x16
    void FUN_140b13b50(CInPacket& packet);                      // opcode 0x17
    void FUN_140b13c60(CInPacket& packet);                      // opcode 0x18
    void FUN_140b13dc0(CInPacket& packet);                      // opcode 0x19
    void FUN_140b13f20(CInPacket& packet);                      // opcode 0x1a
    void FUN_140b14050(CInPacket& packet);                      // opcode 0x1b
    void FUN_140b14110(CInPacket& packet);                      // opcode 0x1c
    bool FUN_140b14220();                                       // always true
    bool FUN_140b14230(CStringW strName);                       // request: add a member by name
    void FUN_140b14480();                                       // request: withdraw
    void FUN_140b14530(CStringW strName);                       // request: change the leader
    void FUN_140b146e0(int nBuffId, int nBuffLevel);            // request: set the buff
    void FUN_140b14900(CStringW strName);                       // request: rename the club
};
MS2_CHECK_SIZE(CClubCli, 0xf0);

// RTTI CClubDataTable (TSingleton, global instance 0x143aac6f8): Table/clubBuff.xml.
class CClubDataTable : public TSingleton<CClubDataTable>
{
public:
    // Club buff table row (clubBuff.xml), 0x30 bytes. ctor 0x140211200, read 0x140211280.
    class ClubBuffData : public CPtred
    {
    public:
        ClubBuffData();
        virtual ~ClubBuffData();
        void FUN_140211280(Unk_140165cf0* pElem);     // id, additionalEffectId, additionalEffectLevel
        int m_id;                                       // +0x18 "id"
        int m_1c;                                       // +0x1c
        int m_20;                                       // +0x20
        int m_24;                                       // +0x24
        int m_effectId;                                 // +0x28 "additionalEffectId"
        int m_effectLevel;                              // +0x2c "additionalEffectLevel"
    };
    typedef MS2Ptr<ClubBuffData> BuffPtr;
    // CRBMap<unsigned> whose ordering is the exe's signed int compare (0x140212de0)
    struct Unk_BuffKeyTraits : public ATL::CElementTraits<unsigned>
    {
        static int CompareElementsOrdered(const unsigned& a, const unsigned& b) { if ((int)a < (int)b) return -1; else if ((int)a == (int)b) return 0; else return 1; }
    };
    typedef ATL::CRBMap<unsigned, BuffPtr, Unk_BuffKeyTraits> BuffMap;
    CClubDataTable();                               // 0x1402112f0
    virtual ~CClubDataTable();                      // 0x140211360
    int FUN_1402113c0();                            // load (thunk of FUN_1402113f0)
    int FUN_1402113f0();                            // load Table/clubBuff.xml
    BuffPtr FUN_1402116a0(unsigned nId);            // buff by id
    BuffPtr FUN_140211760(int nEffectId, int nEffectLevel);   // buff by effect id and level
    void FUN_1402118e0(ATL::CAtlArray<unsigned>& ids);        // all buff ids
    void FUN_140211990(ATL::CAtlArray<BuffPtr>& buffs);       // all buffs
    BuffPtr FUN_140211a40();                        // first buff
    CLockCriticalSection m_lock;                    // +0x08
    BuffMap m_buffs;                                // +0x38
};
MS2_CHECK_SIZE(CClubDataTable::ClubBuffData, 0x30);
MS2_CHECK_SIZE(CClubDataTable, 0x68);
