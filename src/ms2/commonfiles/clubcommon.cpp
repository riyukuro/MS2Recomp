// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Club records: PacketInvite, NameInfo/UserClub, SaveMember,
// CClubMemberProxy, CClubMember, CClub and the club buff table CClubDataTable.
// MS2-UNIT: commonfiles\clubcommon.cpp
// MS2-RANGE: 0x14020c3a0-0x140217910 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VClubBuffData@CClubDataTable@@@@QEAA@PEAVClubBuffData@CClubDataTable@@@Z 0x140211df0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VClubBuffData@CClubDataTable@@@@QEBA_NPEAVClubBuffData@CClubDataTable@@@Z 0x140212590 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCClubMember@@@@QEBA_NPEAVCClubMember@@@Z 0x1402125d0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCClubMember@@@@@Z 0x140212a90 ; unique
// MS2-PIN: ?Add@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@QEAA_K_J@Z 0x140212bf0 ; unique
// MS2-PIN: ?Find@?$CRBTree@IV?$MS2Ptr@VClubBuffData@CClubDataTable@@@@UUnk_BuffKeyTraits@CClubDataTable@@V?$CElementTraits@V?$MS2Ptr@VClubBuffData@CClubDataTable@@@@@ATL@@@ATL@@IEBAPEAVCNode@12@I@Z 0x140212ea0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1402138c0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@_JV?$CElementTraits@_J@ATL@@@ATL@@AEAA_N_K@Z 0x140213c00 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@IV?$MS2Ptr@VClubBuffData@CClubDataTable@@@@UUnk_BuffKeyTraits@CClubDataTable@@V?$CElementTraits@V?$MS2Ptr@VClubBuffData@CClubDataTable@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@IAEBV?$MS2Ptr@VClubBuffData@CClubDataTable@@@@@Z 0x140213da0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCClubMember@@@@@ATL@@SAXPEAV?$MS2Ptr@VCClubMember@@@@0_K@Z 0x1402163a0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@_J@ATL@@SAXPEA_J0_K@Z 0x140216420 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?CompareElementsOrdered@Unk_BuffKeyTraits@CClubDataTable@@SAHAEBI0@Z 0x140212de0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\clubcommon.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "clubcommon.h"

#include "ms2/commonfiles/userproxy.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#define CLUB_JOIN_MAX 3

// Unrecovered xml helpers (the same ones the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);

// ---- Club::PacketInvite ----

// @0x14020c3a0
Club::PacketInvite::PacketInvite()
{
    FUN_14020c490();
}

// @0x14020c420
Club::PacketInvite::~PacketInvite()
{
}

// @0x14020c490
void Club::PacketInvite::FUN_14020c490()
{
    m_inviteId = 0;
    m_20.Empty();
    m_28.Empty();
    m_30.Empty();
}

// @0x14020c4f0
void Club::PacketInvite::FUN_14020c4f0(const PacketInvite* o)
{
    if (o == 0)
    {
        FUN_14020c490();
    }
    else
    {
        m_inviteId = o->m_inviteId;
        m_20 = o->m_20;
        m_28 = o->m_28;
        m_30 = o->m_30;
    }
}

// @0x14020c580
void Club::PacketInvite::FUN_14020c580(CClub* pClub, CStringW strA, CStringW strB)
{
    if (pClub == 0)
        return;
    m_inviteId = pClub->FUN_14020f0c0();
    m_20 = pClub->FUN_14020f1a0();
    m_28 = strA;
    m_30 = strB;
}

// @0x14020c670
void Club::PacketInvite::FUN_14020c670(COutputStream& out)
{
    out.WriteInt64(m_inviteId);
    out.WriteUnicodeString(m_20);
    out.WriteUnicodeString(m_28);
    out.WriteUnicodeString(m_30);
}

// @0x14020c720
void Club::PacketInvite::FUN_14020c720(CInputStream& in)
{
    m_inviteId = in.ReadInt64();
    m_20 = in.ReadUnicodeString();
    m_28 = in.ReadUnicodeString();
    m_30 = in.ReadUnicodeString();
}

// ---- Club::NameInfo / Club::UserClub ----

// @0x14020c860
Club::NameInfo::NameInfo()
{
    FUN_14020c900();
}

// @0x14020c900
void Club::NameInfo::FUN_14020c900()
{
    m_18 = 0;
    m_20.Empty();
}

// @0x14020c8c0
Club::NameInfo::~NameInfo()
{
}

// @0x14020c940
Club::UserClub::UserClub()
    : m_18(10)
{
    FUN_14020c9e0();
}

// @0x14020c9a0
Club::UserClub::~UserClub()
{
}

// @0x14020c9e0
void Club::UserClub::FUN_14020c9e0()
{
    m_18.RemoveAll();
}

// @0x14020ca10
MS2Ptr<Club::NameInfo> Club::UserClub::FUN_14020ca10(__int64 nId)
{
    MS2Ptr<NameInfo> sp(0);
    m_18.Lookup(nId, sp);
    return sp;
}

// @0x14020ca90
size_t Club::UserClub::FUN_14020ca90()
{
    return m_18.GetCount();
}

// @0x14020cac0
int Club::UserClub::FUN_14020cac0()
{
    if (m_18.GetCount() >= CLUB_JOIN_MAX)
        return 1;
    return 0;
}

// @0x14020cb00
int Club::UserClub::FUN_14020cb00(__int64 nId, CStringW strName)
{
    MS2Ptr<NameInfo> sp(new NameInfo);
    sp->m_18 = nId;
    sp->m_20 = strName;
    return FUN_14020cc00(sp);
}

// @0x14020cc00
int Club::UserClub::FUN_14020cc00(MS2Ptr<NameInfo> sp)
{
    if (sp == 0)
        return 0;
    if (FUN_14020cac0() == 1)
        return 0;
    m_18.SetAt(sp->m_18, sp);
    return 1;
}

// @0x14020ccb0
void Club::UserClub::FUN_14020ccb0(__int64 nId)
{
    m_18.RemoveKey(nId);
}

// @0x14020cce0
void Club::UserClub::FUN_14020cce0(ATL::CAtlArray<MS2Ptr<NameInfo> >& out)
{
    out.RemoveAll();
    for (POSITION pos = m_18.GetHeadPosition(); pos; m_18.GetNext(pos))
    {
        MS2Ptr<NameInfo> sp = m_18.GetValueAt(pos);
        if (sp.get() != 0)
            out.Add(sp);
    }
}

// @0x14020cda0
void Club::UserClub::FUN_14020cda0(const ATL::CAtlArray<MS2Ptr<NameInfo> >& in)
{
    FUN_14020c9e0();
    for (size_t i = 0; i < in.GetCount(); i++)
    {
        MS2Ptr<NameInfo> sp = in.GetAt(i);
        if (sp.get() != 0)
            m_18.SetAt(sp->m_18, sp);
    }
}

// @0x14020ce50
void Club::UserClub::FUN_14020ce50(COutputStream& out)
{
    int count = (int)m_18.GetCount();
    MS2_ASSERT_AT(0xb9, count <= CLUB_JOIN_MAX);
    out.WriteUInt8((unsigned char)count);
    for (POSITION pos = m_18.GetHeadPosition(); pos; m_18.GetNext(pos))
    {
        MS2Ptr<NameInfo> sp = m_18.GetValueAt(pos);
        if (sp == 0)
        {
            out.WriteUInt8(0);
        }
        else
        {
            out.WriteUInt8(1);
            out.WriteInt64(sp->m_18);
            out.WriteUnicodeString(sp->m_20);
        }
    }
}

// @0x14020cfc0
void Club::UserClub::FUN_14020cfc0(CInputStream& in)
{
    unsigned char count = in.ReadUInt8();
    MS2_ASSERT_AT(0xd0, count <= CLUB_JOIN_MAX);
    for (int i = 0; i < (int)count; i++)
    {
        if (in.ReadUInt8() == 1)
        {
            MS2Ptr<NameInfo> sp(new NameInfo);
            sp->m_18 = in.ReadInt64();
            sp->m_20 = in.ReadUnicodeString();
            m_18.SetAt(sp->m_18, sp);
        }
    }
}

// ---- Club::SaveMember ----

// @0x14020d180
Club::SaveMember::SaveMember()
{
    m_id = 0;
    m_gender = 0;
    m_jobCode = 0;
    m_job = 0;
    m_level = 0;
    m_mapId = 0;
    m_picture.Empty();
    m_d8 = 0;
}

// @0x14020d230
Club::SaveMember::~SaveMember()
{
}

// ---- CClubMemberProxy ----

// @0x14020d270
CClubMemberProxy::CClubMemberProxy()
{
    FUN_14020d380();
}

// @0x14020d310
CClubMemberProxy::~CClubMemberProxy()
{
}

// @0x14020d380
void CClubMemberProxy::FUN_14020d380()
{
    m_accountId = 0;
    m_characterId = 0;
    m_gender = 3;
    m_jobCode = 0;
    m_job = 0;
    m_level = 0;
    m_mapId = 0;
    m_channel = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_50 = 0;
    m_trophy.FUN_140267bd0();
    FUN_14020e650(CStringW(L""));
    FUN_14020e740(CString(""));
}

// @0x14020d4a0
void CClubMemberProxy::FUN_14020d4a0(CStringW strName, int nJobCode, int nJob, short nLevel, CString strPicture)
{
    FUN_14020d380();
    m_jobCode = nJobCode;
    m_job = nJob;
    m_level = nLevel;
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020d580
void CClubMemberProxy::FUN_14020d580(COutputStream& out)
{
    out.WriteInt32(m_mapId);
}

// @0x14020d5c0
void CClubMemberProxy::FUN_14020d5c0(CInPacket& packet)
{
    m_mapId = packet.ReadInt32();
}

// @0x14020d610
void CClubMemberProxy::FUN_14020d610(COutputStream& out)
{
    FUN_14020d9a0(out);
}

// @0x14020d640
void CClubMemberProxy::FUN_14020d640(CInPacket* packet)
{
    FUN_14020db80(packet);
}

// @0x14020d690
void CClubMemberProxy::FUN_14020d690(COutputStream& out)
{
    out.WriteUnicodeString(FUN_14020e5d0());
    out.WriteInt32(m_jobCode);
    out.WriteInt32(m_job);
    out.WriteInt16(m_level);
    out.WriteUnicodeStringA(m_picture);
}

// @0x14020d770
void CClubMemberProxy::FUN_14020d770(CInPacket& packet)
{
    CStringW strName;
    CStringA strPicture;
    strName = packet.ReadUnicodeString();
    m_jobCode = packet.ReadInt32();
    m_job = packet.ReadInt32();
    m_level = packet.ReadInt16();
    strPicture = packet.ReadUnicodeStringA();
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020d9a0
void CClubMemberProxy::FUN_14020d9a0(COutputStream& out)
{
    out.WriteInt64(m_accountId);
    out.WriteInt64(m_characterId);
    out.WriteUnicodeString(FUN_14020e5d0());
    out.WriteUInt8(m_gender);
    out.WriteInt32(m_jobCode);
    out.WriteInt32(m_job);
    out.WriteInt16(m_level);
    out.WriteInt32(m_mapId);
    out.WriteInt16((short)m_channel);
    out.WriteUnicodeStringA(FUN_14020e6c0());
    out.WriteInt32(m_40);
    out.WriteInt32(m_44);
    out.WriteInt32(m_48);
    out.WriteInt64(m_50);
    m_trophy.FUN_140267f50(out);
}

// @0x14020db80
void CClubMemberProxy::FUN_14020db80(CInputStream* in)
{
    CStringW strName;
    CStringA strPicture;
    m_accountId = in->ReadInt64();
    m_characterId = in->ReadInt64();
    strName = in->ReadUnicodeString();
    m_gender = in->ReadUInt8();
    m_jobCode = in->ReadInt32();
    m_job = in->ReadInt32();
    m_level = in->ReadInt16();
    m_mapId = in->ReadInt32();
    m_channel = (unsigned short)in->ReadInt16();
    strPicture = in->ReadUnicodeStringA();
    m_40 = in->ReadInt32();
    m_44 = in->ReadInt32();
    m_48 = in->ReadInt32();
    m_50 = in->ReadInt64();
    m_trophy.FUN_140267fb0(*in);
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020de80
void CClubMemberProxy::FUN_14020de80(COutputStream& out)
{
    out.WriteUnicodeString(FUN_14020e5d0());
    out.WriteInt32(m_jobCode);
    out.WriteInt32(m_job);
    out.WriteInt16(m_level);
    out.WriteUnicodeStringA(FUN_14020e6c0());
}

// @0x14020df70
void CClubMemberProxy::FUN_14020df70(CInputStream* in)
{
    CStringW strName;
    CStringA strPicture;
    strName = in->ReadUnicodeString();
    m_jobCode = in->ReadInt32();
    m_job = in->ReadInt32();
    m_level = in->ReadInt16();
    strPicture = in->ReadUnicodeStringA();
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020e130
void CClubMemberProxy::FUN_14020e130(const CClubMemberProxy& o)
{
    CStringW strName;
    CStringA strPicture;
    m_accountId = o.m_accountId;
    m_characterId = o.m_characterId;
    strName = o.m_name;
    m_gender = o.m_gender;
    m_jobCode = o.m_jobCode;
    m_job = o.m_job;
    m_level = o.m_level;
    m_mapId = o.m_mapId;
    m_channel = o.m_channel;
    strPicture = o.m_picture;
    m_40 = o.m_40;
    m_44 = o.m_44;
    m_48 = o.m_48;
    m_50 = o.m_50;
    m_trophy.FUN_140267ea0(o.m_trophy);
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020e350
void CClubMemberProxy::FUN_14020e350(Unk_UserProxy* p)
{
    CStringW strName;
    CStringA strPicture;
    m_accountId = p->m_0;
    m_characterId = p->m_8;
    strName = p->FUN_1408f19e0();
    m_gender = p->m_14;
    m_jobCode = p->m_3c;
    m_job = p->m_40;
    m_level = p->m_34;
    m_mapId = p->m_2c;
    m_channel = p->m_38;
    strPicture = p->FUN_1408f1a60();
    m_40 = p->m_98;
    m_44 = p->m_9c;
    m_48 = p->m_a0;
    m_50 = p->m_a8;
    m_trophy.FUN_140267ea0(*reinterpret_cast<const Unk_GuildTriple*>(&p->m_d4));
    FUN_14020e650(strName);
    FUN_14020e740(strPicture);
}

// @0x14020e5d0
CStringW CClubMemberProxy::FUN_14020e5d0()
{
    Unk_UserProxyWriteLock g(m_lock, 1);
    return m_name;
}

// @0x14020e650
void CClubMemberProxy::FUN_14020e650(CStringW strName)
{
    Unk_UserProxyWriteLock g(m_lock, 1);
    m_name = strName;
}

// @0x14020e6c0
CString CClubMemberProxy::FUN_14020e6c0()
{
    Unk_UserProxyWriteLock g(m_lock, 1);
    return m_picture;
}

// @0x14020e740
void CClubMemberProxy::FUN_14020e740(CString strPicture)
{
    Unk_UserProxyWriteLock g(m_lock, 1);
    m_picture = strPicture;
}

// ---- CClubMember ----

// @0x14020e7b0
CClubMember::CClubMember()
{
    FUN_14020e890();
}

// @0x14020e820
CClubMember::~CClubMember()
{
    FUN_14020e890();
}

// @0x14020e890
void CClubMember::FUN_14020e890()
{
    m_18 = 0;
    m_info.FUN_14020d380();
    m_c8 = 0;
    m_cc = 0;
    m_d0 = 0;
    m_d8 = 0;
    m_e0 = 0;
    m_e8.Empty();
    m_f0 = 1;
    m_f4 = 0;
}

// @0x14020e950
void CClubMember::FUN_14020e950(CClubMember* o)
{
    if (o == 0)
        return;
    m_18 = o->m_18;
    m_info.FUN_14020e130(o->m_info);
    m_c8 = o->m_c8;
    m_cc = o->m_cc;
    m_d0 = o->m_d0;
    m_d8 = o->m_d8;
    m_f0 = o->m_f0;
}

// @0x14020ea20
void CClubMember::FUN_14020ea20(COutputStream& out)
{
    FUN_14020eaa0(out);
}

// @0x14020ea50
void CClubMember::FUN_14020ea50(CInPacket* packet)
{
    FUN_14020eba0(packet);
}

// @0x14020eaa0
void CClubMember::FUN_14020eaa0(COutputStream& out)
{
    out.WriteUInt8((unsigned char)m_c8);
    if (m_c8 == 2)
    {
        out.WriteInt64(m_18);
        m_info.FUN_14020d9a0(out);
        out.WriteInt64(m_d0);
        out.WriteInt64(m_d8);
        out.WriteUInt8((unsigned char)m_f0);
    }
    else
    {
        out.WriteInt64(m_18);
        m_info.FUN_14020de80(out);
    }
}

// @0x14020eba0
void CClubMember::FUN_14020eba0(CInputStream* in)
{
    m_c8 = in->ReadUInt8();
    if (m_c8 == 2)
    {
        m_18 = in->ReadInt64();
        m_info.FUN_14020db80(in);
        m_d0 = in->ReadInt64();
        m_d8 = in->ReadInt64();
        m_f0 = in->ReadUInt8();
    }
    else
    {
        m_18 = in->ReadInt64();
        m_info.FUN_14020df70(in);
    }
}

// @0x14020eca0
int CClubMember::FUN_14020eca0(Club::SaveMember* pSave)
{
    if (FUN_14020edd0() == 0)
        return 0;
    pSave->m_id = m_18;
    pSave->m_gender = m_info.m_gender;
    pSave->m_jobCode = m_info.m_jobCode;
    pSave->m_job = m_info.m_job;
    pSave->m_level = (unsigned short)m_info.m_level;
    pSave->m_mapId = m_info.m_mapId;
    pSave->m_picture = (const char*)m_info.FUN_14020e6c0();
    pSave->m_d8 = m_d8;
    FUN_14020edb0(0);
    return 1;
}

// @0x14020edb0
void CClubMember::FUN_14020edb0(int nDirty)
{
    m_f4 = nDirty;
}

// @0x14020edd0
int CClubMember::FUN_14020edd0()
{
    return m_f4;
}

// @0x14020edf0
Unk_GuildTriple* CClubMember::FUN_14020edf0()
{
    return &m_info.m_trophy;
}

// @0x14020ee10
void CClubMember::FUN_14020ee10()
{
    m_info.m_trophy.FUN_140267c10();
}

// ---- CClub ----

// @0x14020ee40
CClub::CClub()
    : m_members(10)
{
    vfunc_0();
}

// @0x14020ef00
CClub::~CClub()
{
    vfunc_0();
}

// @0x14020efb0
void CClub::vfunc_0()
{
    m_clubId = 0;
    m_creationTime = 0;
    m_leaderAccountId = 0;
    m_leaderCharacterId = 0;
    m_leaderName = L"";
    m_78 = 0;
    m_80 = 0;
    m_88 = L"";
    m_50 = 0;
    m_54 = 0;
    m_leader = 0;
    m_members.RemoveAll();
    m_90 = 0;
    m_48 = 10;
    m_state = 0;
}

// @0x14020f0c0
__int64 CClub::FUN_14020f0c0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_clubId;
    }
    __nop();
}

// @0x14020f130
void CClub::FUN_14020f130(__int64 n)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_clubId = n;
    }
}

// @0x14020f1a0
CStringW CClub::FUN_14020f1a0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_name;
    }
    __nop();
}

// @0x14020f230
void CClub::FUN_14020f230(const CStringW& strName)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_name = strName;
    }
}

// @0x14020f2a0
__int64 CClub::FUN_14020f2a0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_creationTime;
    }
    __nop();
}

// @0x14020f310
void CClub::FUN_14020f310(__int64 n)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_creationTime = n;
    }
}

// @0x14020f380
unsigned CClub::FUN_14020f380()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_48;
    }
    __nop();
}

// @0x14020f3f0
void CClub::FUN_14020f3f0(__int64 n)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_90 = n;
    }
}

// @0x14020f460
__int64 CClub::FUN_14020f460()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_90;
    }
    __nop();
}

// @0x14020f4e0
void CClub::FUN_14020f4e0(int nState)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_state = nState;
    }
}

// @0x14020f540
unsigned CClub::FUN_14020f540()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_state;
    }
    __nop();
}

// @0x14020f5b0
void CClub::FUN_14020f5b0(int nBuffId, int nBuffLevel)
{
    {
        if (Unk_LockGuard guard = m_lock)
        {
            __assume(0);
        }
        else
        {
            m_50 = nBuffId;
            m_54 = nBuffLevel;
        }
    }
    vfunc_2(1);
}

// @0x14020f640
int CClub::FUN_14020f640()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_50;
    }
    __nop();
}

// @0x14020f6b0
unsigned CClub::FUN_14020f6b0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_54;
    }
    __nop();
}

// @0x14020f720
void CClub::FUN_14020f720(__int64 nAccountId, __int64 nCharacterId, CStringW strName)
{
    {
        if (Unk_LockGuard guard = m_lock)
        {
            __assume(0);
        }
        else
        {
            m_leaderAccountId = nAccountId;
            m_leaderCharacterId = nCharacterId;
            m_leaderName = strName;
        }
    }
    vfunc_2(1);
}

// @0x14020f7e0
__int64 CClub::FUN_14020f7e0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_leaderAccountId;
    }
    __nop();
}

// @0x14020f850
__int64 CClub::FUN_14020f850()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_leaderCharacterId;
    }
    __nop();
}

// @0x14020f8c0
CStringW CClub::FUN_14020f8c0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_leaderName;
    }
    __nop();
}

// @0x14020f950
__int64 CClub::FUN_14020f950()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_78;
    }
    __nop();
}

// @0x14020f9c0
void CClub::FUN_14020f9c0(__int64 n)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_78 = n;
    }
}

// @0x14020fa30
__int64 CClub::FUN_14020fa30()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_80;
    }
    __nop();
}

// @0x14020fab0
void CClub::FUN_14020fab0(__int64 n)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_80 = n;
    }
}

// @0x14020fb20
void CClub::FUN_14020fb20(COutputStream& out)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        out.WriteInt64(FUN_14020f0c0());
        out.WriteUnicodeString(FUN_14020f1a0());
        out.WriteInt64(FUN_14020f7e0());
        out.WriteInt64(FUN_14020f850());
        out.WriteUnicodeString(FUN_14020f8c0());
        out.WriteInt64(m_creationTime);
        out.WriteUInt8((unsigned char)m_state);
        out.WriteInt32(FUN_14020f640());
        out.WriteInt32(FUN_14020f6b0());
        out.WriteInt64(m_90);
        FUN_1402100e0(out);
    }
}

// @0x14020fd80
void CClub::FUN_14020fd80(CInPacket& packet)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
            __int64 nId = packet.ReadInt64();
        CStringW strName = packet.ReadUnicodeString();
        __int64 nLeaderAccount = packet.ReadInt64();
        __int64 nLeaderCharacter = packet.ReadInt64();
        CStringW strLeader = packet.ReadUnicodeString();
        __int64 nCreated = packet.ReadInt64();
        unsigned char nState = packet.ReadUInt8();
        int nBuffId = packet.ReadInt32();
        int nBuffLevel = packet.ReadInt32();
        __int64 n90 = packet.ReadInt64();
        FUN_14020f4e0(nState);
        FUN_14020f130(nId);
        FUN_14020f230(strName);
        FUN_14020f720(nLeaderAccount, nLeaderCharacter, strLeader);
        FUN_14020f310(nCreated);
        FUN_14020f5b0(nBuffId, nBuffLevel);
        FUN_14020f3f0(n90);
        FUN_1402101e0(packet);
    }
}

// @0x1402100e0
void CClub::FUN_1402100e0(COutputStream& out)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        out.WriteUInt8((unsigned char)FUN_140210df0());
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            sp->FUN_14020ea20(out);
        }
    }
}

// @0x1402101e0
void CClub::FUN_1402101e0(CInPacket& packet)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        unsigned char count = packet.ReadUInt8();
        for (int i = 0; i < (int)count; i++)
        {
            MS2Ptr<CClubMember> sp(new CClubMember);
            sp->FUN_14020ea50(&packet);
            vfunc_4(sp);
        }
    }
}

// @0x140210340
int CClub::vfunc_4(MS2Ptr<CClubMember> spMember)
{
    if (spMember == 0)
        return 0;
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (m_members.GetCount() < 10)
        {
            m_members.SetAt(spMember->m_info.FUN_14020e5d0(), spMember);
            if (m_leader == 0)
            {
                if (spMember->m_info.m_characterId == m_leaderCharacterId)
                    m_leader = spMember;
            }
            return 1;
        }
        return 0;
    }
    __nop();
}

// @0x1402104e0
void CClub::vfunc_5(CStringW strName)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_members.RemoveKey(strName);
    }
}

// @0x140210560
MS2Ptr<CClubMember> CClub::FUN_140210560(CStringW strName)
{
    MS2Ptr<CClubMember> sp(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_members.Lookup(strName, sp);
    }
    return sp;
}

// @0x140210630
MS2Ptr<CClubMember> CClub::FUN_140210630(__int64 nId)
{
    MS2Ptr<CClubMember> spFound(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp.get() != 0 && sp->m_18 == nId)
            {
                spFound = sp;
                break;
            }
        }
    }
    return spFound;
}

// @0x1402107a0
void CClub::FUN_1402107a0(const CStringW& strOldName, const CStringW& strNewName)
{
    MS2Ptr<CClubMember> sp(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (m_members.Lookup(strOldName, sp) == true)
        {
            m_members.RemoveKey(strOldName);
            sp->m_info.FUN_14020e650(strNewName);
            m_members.SetAt(strNewName, sp);
        }
    }
}

// @0x1402108e0
void CClub::FUN_1402108e0(ATL::CAtlArray<__int64>& ids)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp->m_c8 == 2)
                ids.Add(sp->m_info.m_characterId);
        }
    }
}

// @0x1402109d0
void CClub::FUN_1402109d0(ATL::CAtlArray<MS2Ptr<CClubMember> >& members)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp == 0)
                continue;
            members.Add(sp);
        }
    }
}

// @0x140210ad0
void CClub::FUN_140210ad0(ATL::CAtlArray<MS2Ptr<CClubMember> >& members)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp == 0)
            {
            }
            else
            {
                if (sp->FUN_14020edd0() == 1)
                    members.Add(sp);
            }
        }
    }
}

// @0x140210be0
void CClub::FUN_140210be0(ATL::CAtlArray<MS2Ptr<CClubMember> >& members)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp == 0)
            {
            }
            else
            {
                if (sp->m_c8 == 2)
                    members.Add(sp);
            }
        }
    }
}

// @0x140210cf0
unsigned CClub::FUN_140210cf0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        unsigned n = 0;
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp->m_c8 == 2)
                n++;
        }
        return n;
    }
    __nop();
}

// @0x140210df0
int CClub::FUN_140210df0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return (int)m_members.GetCount();
    }
    __nop();
}

// @0x140210e70
int CClub::FUN_140210e70()
{
    int n = 0;
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> sp = m_members.GetValueAt(pos);
            if (sp->m_c8 == 2 && sp->m_f0 == 0)
                n++;
        }
    }
    return n;
}

// @0x140210f70
MS2Ptr<CClubMember> CClub::FUN_140210f70()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        return m_leader;
    }
    __nop();
}

// @0x140211000
void CClub::FUN_140211000(MS2Ptr<CClubMember> spLeader)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_leader = spLeader;
    }
}

// @0x140211080
int CClub::FUN_140211080(CStringW strName)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        MS2Ptr<CClubMember> sp = FUN_140210560(strName);
        if (sp == 0)
            return 0;
        if (sp->m_info.m_characterId == m_leaderCharacterId)
            return 1;
        else
            return 0;
    }
}

// @0x1402133d0
int CClub::vfunc_3()
{
    return 0;
}

// @0x140216b50
void CClub::vfunc_1(int n)
{
}

// @0x140216e40
void CClub::vfunc_2(int n)
{
}

// ---- CClubDataTable ----

// @0x140211200
CClubDataTable::ClubBuffData::ClubBuffData()
{
    m_id = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_effectId = 0;
    m_effectLevel = 0;
}

// @0x140212480
CClubDataTable::ClubBuffData::~ClubBuffData()
{
}

// @0x140211280
void CClubDataTable::ClubBuffData::FUN_140211280(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "id", m_id);
    FUN_1408731e0(pElem, "additionalEffectId", m_effectId);
    FUN_1408731e0(pElem, "additionalEffectLevel", m_effectLevel);
}

// @0x1402112f0
CClubDataTable::CClubDataTable()
    : m_buffs(10)
{
}

// @0x140211360
CClubDataTable::~CClubDataTable()
{
    m_buffs.RemoveAll();
}

// @0x1402113c0
int CClubDataTable::FUN_1402113c0()
{
    if (!LoadClubBuff())
        return 0;
    return 1;
}

// @0x1402113f0
int CClubDataTable::LoadClubBuff()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("clubBuff.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("clubBuff"); pNode != 0; pNode = pNode->FUN_140168650("clubBuff"))
    {
        BuffPtr sp(new ClubBuffData);
        sp->FUN_140211280(pNode);
        if (Unk_LockGuard guard = m_lock)
        {
            __assume(0);
        }
        else
        {
            m_buffs.SetAt(sp->m_id, sp);
        }
    }
    return 1;
}

// @0x1402116a0
CClubDataTable::BuffPtr CClubDataTable::FUN_1402116a0(unsigned nId)
{
    BuffPtr sp(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        m_buffs.Lookup(nId, sp);
    }
    return sp;
}

// @0x140211760
CClubDataTable::BuffPtr CClubDataTable::FUN_140211760(int nEffectId, int nEffectLevel)
{
    BuffPtr spFound(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_buffs.GetHeadPosition(); pos; m_buffs.GetNext(pos))
        {
            BuffPtr sp = m_buffs.GetValueAt(pos);
            if (sp == 0)
            {
            }
            else
            {
                if (sp->m_effectId == nEffectId && sp->m_effectLevel == nEffectLevel)
                {
                    spFound = sp;
                    break;
                }
            }
        }
    }
    return spFound;
}

// @0x1402118e0
void CClubDataTable::FUN_1402118e0(ATL::CAtlArray<unsigned>& ids)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_buffs.GetHeadPosition(); pos; m_buffs.GetNext(pos))
            ids.Add(m_buffs.GetKeyAt(pos));
    }
}

// @0x140211990
void CClubDataTable::FUN_140211990(ATL::CAtlArray<BuffPtr>& buffs)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        for (POSITION pos = m_buffs.GetHeadPosition(); pos; m_buffs.GetNext(pos))
            buffs.Add(m_buffs.GetValueAt(pos));
    }
}

// @0x140211a40
CClubDataTable::BuffPtr CClubDataTable::FUN_140211a40()
{
    BuffPtr spFirst(0);
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        spFirst = m_buffs.GetValueAt(m_buffs.GetHeadPosition());
    }
    return spFirst;
}

// ---- instantiation glue of the club buff table (MS2Ptr<ClubBuffData> / CRBTree helpers), as plain functions ----

extern void* FUN_140217140(void* pTree, void* pNode);
extern void FUN_140159b70(int hr);
extern void FUN_1402176a0(void** pThis);
extern void* FUN_1401ba820(void* p);

// the MS2Ptr<ClubBuffData> fields the raw-view helpers touch
struct Unk_BuffPtrView { void* m_0; void* m_p; };

// @0x140211b20
CClubDataTable::ClubBuffData* Unk_NewClubBuffData(void* pTag)
{
    return new CClubDataTable::ClubBuffData;
}

// @0x140217680
void* Unk_BuffPtrAlloc(void* pTag)
{
    return FUN_1401ba820(Unk_NewClubBuffData(0));
}

// @0x140217650
void Unk_BuffPtrResetNew(void** pThis)
{
    FUN_1402176a0(pThis);
    ((Unk_BuffPtrView*)pThis)->m_p = Unk_BuffPtrAlloc(0);
}

// @0x140211da0
void* Unk_BuffPtrNew(void** pThis, void* pTag)
{
    ((Unk_BuffPtrView*)pThis)->m_p = 0;
    Unk_BuffPtrResetNew(pThis);
    return pThis;
}

// @0x140212650
void* Unk_BuffPtrGet(void** pThis)
{
    return ((Unk_BuffPtrView*)pThis)->m_p;
}

// @0x140212670
void* Unk_BuffPtrArrow(void** pThis)
{
    return ((Unk_BuffPtrView*)pThis)->m_p;
}

// @0x140212e20
int Unk_CompareUInt64(const unsigned __int64* a, const unsigned __int64* b)
{
    if (*a < *b)
        return -1;
    else
    {
        if (*a == *b)
            return 0;
        else
        {
            return 1;
        }
    }
}

// @0x140213520
void* Unk_TreePostInc(void* pTree, void** pPos)
{
    void* pOld = *pPos;
    *pPos = FUN_140217140(pTree, pOld);
    return pOld;
}

// @0x140213660
void* Unk_TreeNodePair(void* pTree, char* pNode)
{
    do {
        int bOk = (pNode != 0);
        do {} while (0);
        if (!bOk)
            FUN_140159b70(0x80004005);
    } while (0);
    return pNode + 8;
}

// @0x140217850
int Unk_ClubBuffCategory(int n)
{
    switch (n)
    {
    case 1:
        return 1;
    case 2:
        return 8;
    case 3:
        return 11;
    case 4:
        return 5;
    }
    return 0;
}

// @0x1402178b0
int Unk_ClubBuffTypeOf(int n)
{
    switch (n)
    {
    case 1:
    case 2:
        return 1;
    case 8:
        return 2;
    case 11:
        return 3;
    case 5:
        return 4;
    }
    return 0;
}

MS2_REPLACE_METHOD(0x14020c490, Club::PacketInvite, FUN_14020c490, 81, 0x10A01E02);
MS2_REPLACE_METHOD(0x14020c4f0, Club::PacketInvite, FUN_14020c4f0, 138, 0x4B5FF1D7);
MS2_REPLACE_METHOD(0x14020c580, Club::PacketInvite, FUN_14020c580, 228, 0x12D37926);
MS2_REPLACE_METHOD(0x14020c670, Club::PacketInvite, FUN_14020c670, 158, 0xDADA8B15);
MS2_REPLACE_METHOD(0x14020c720, Club::PacketInvite, FUN_14020c720, 302, 0xECCB73E2);
MS2_REPLACE_METHOD(0x14020c900, Club::NameInfo, FUN_14020c900, 45, 0x9850DA30);
MS2_REPLACE_METHOD(0x14020c9e0, Club::UserClub, FUN_14020c9e0, 31, 0xB025AAE5);
MS2_REPLACE_METHOD(0x14020ca10, Club::UserClub, FUN_14020ca10, 122, 0x068E1990);
MS2_REPLACE_METHOD(0x14020ca90, Club::UserClub, FUN_14020ca90, 31, 0xB4F52623);
MS2_REPLACE_METHOD(0x14020cac0, Club::UserClub, FUN_14020cac0, 46, 0xA7DDF840);
MS2_REPLACE_METHOD(0x14020cb00, Club::UserClub, FUN_14020cb00, 248, 0x258ABBFD);
MS2_REPLACE_METHOD(0x14020cc00, Club::UserClub, FUN_14020cc00, 165, 0x6154BD0B);
MS2_REPLACE_METHOD(0x14020ccb0, Club::UserClub, FUN_14020ccb0, 41, 0x0FBDAE35);
MS2_REPLACE_METHOD(0x14020cce0, Club::UserClub, FUN_14020cce0, 171, 0x1D2D6638);
MS2_REPLACE_METHOD(0x14020cda0, Club::UserClub, FUN_14020cda0, 169, 0xD83E39ED);
MS2_REPLACE_METHOD(0x14020ce50, Club::UserClub, FUN_14020ce50, 355, 0x5318A284);
MS2_REPLACE_METHOD(0x14020cfc0, Club::UserClub, FUN_14020cfc0, 427, 0xB8263F99);
MS2_REPLACE_METHOD(0x14020d380, CClubMemberProxy, FUN_14020d380, 270, 0x7284E1A2);
MS2_REPLACE_METHOD(0x14020d4a0, CClubMemberProxy, FUN_14020d4a0, 217, 0xEE53AE2B);
MS2_REPLACE_METHOD(0x14020d580, CClubMemberProxy, FUN_14020d580, 43, 0x5228BC05);
MS2_REPLACE_METHOD(0x14020d5c0, CClubMemberProxy, FUN_14020d5c0, 61, 0x4CD742F6);
MS2_REPLACE_METHOD(0x14020d610, CClubMemberProxy, FUN_14020d610, 34, 0xEDF9DFF8);
MS2_REPLACE_METHOD(0x14020d640, CClubMemberProxy, FUN_14020d640, 67, 0x531AF82C);
MS2_REPLACE_METHOD(0x14020d690, CClubMemberProxy, FUN_14020d690, 204, 0x4CEE299F);
MS2_REPLACE_METHOD(0x14020d770, CClubMemberProxy, FUN_14020d770, 549, 0xFB59E4E7);
MS2_REPLACE_METHOD(0x14020d9a0, CClubMemberProxy, FUN_14020d9a0, 470, 0x35F96B66);
MS2_REPLACE_METHOD(0x14020db80, CClubMemberProxy, FUN_14020db80, 760, 0x9BEF4172);
MS2_REPLACE_METHOD(0x14020de80, CClubMemberProxy, FUN_14020de80, 227, 0x5FE41701);
MS2_REPLACE_METHOD(0x14020df70, CClubMemberProxy, FUN_14020df70, 429, 0xF2A1C911);
MS2_REPLACE_METHOD(0x14020e130, CClubMemberProxy, FUN_14020e130, 535, 0x8241E2B1);
MS2_REPLACE_METHOD(0x14020e350, CClubMemberProxy, FUN_14020e350, 629, 0x59329419);
MS2_REPLACE_METHOD(0x14020e5d0, CClubMemberProxy, FUN_14020e5d0, 116, 0xF3D7B713);
MS2_REPLACE_METHOD(0x14020e650, CClubMemberProxy, FUN_14020e650, 105, 0x9E780C65);
MS2_REPLACE_METHOD(0x14020e6c0, CClubMemberProxy, FUN_14020e6c0, 116, 0x033B5C7C);
MS2_REPLACE_METHOD(0x14020e740, CClubMemberProxy, FUN_14020e740, 105, 0xBD91D60C);
MS2_REPLACE_METHOD(0x14020e890, CClubMember, FUN_14020e890, 171, 0xB4B40855);
MS2_REPLACE_METHOD(0x14020e950, CClubMember, FUN_14020e950, 190, 0xDDB0C5F0);
MS2_REPLACE_METHOD(0x14020ea20, CClubMember, FUN_14020ea20, 34, 0x04FC75E7);
MS2_REPLACE_METHOD(0x14020ea50, CClubMember, FUN_14020ea50, 67, 0xD06EF7E8);
MS2_REPLACE_METHOD(0x14020eaa0, CClubMember, FUN_14020eaa0, 245, 0xADC73256);
MS2_REPLACE_METHOD(0x14020eba0, CClubMember, FUN_14020eba0, 249, 0x5D098D43);
MS2_REPLACE_METHOD(0x14020eca0, CClubMember, FUN_14020eca0, 265, 0xA7ED6637);
MS2_REPLACE_METHOD(0x14020edb0, CClubMember, FUN_14020edb0, 25, 0xC37424D3);
MS2_REPLACE_METHOD(0x14020edd0, CClubMember, FUN_14020edd0, 17, 0xE3FAF62F);
MS2_REPLACE_METHOD(0x14020edf0, CClubMember, FUN_14020edf0, 15, 0x680A76B1);
MS2_REPLACE_METHOD(0x14020ee10, CClubMember, FUN_14020ee10, 31, 0x09CC4898);
MS2_REPLACE_METHOD(0x14020f0c0, CClub, FUN_14020f0c0, 104, 0xDA5FFFAA);
MS2_REPLACE_METHOD(0x14020f130, CClub, FUN_14020f130, 91, 0xC1D5427A);
MS2_REPLACE_METHOD(0x14020f1a0, CClub, FUN_14020f1a0, 137, 0x7E65C264);
MS2_REPLACE_METHOD(0x14020f230, CClub, FUN_14020f230, 101, 0x8FDA9E25);
MS2_REPLACE_METHOD(0x14020f2a0, CClub, FUN_14020f2a0, 104, 0x4EE10C12);
MS2_REPLACE_METHOD(0x14020f310, CClub, FUN_14020f310, 91, 0x921AF091);
MS2_REPLACE_METHOD(0x14020f380, CClub, FUN_14020f380, 101, 0x9DF0D68C);
MS2_REPLACE_METHOD(0x14020f3f0, CClub, FUN_14020f3f0, 94, 0x9A43EB30);
MS2_REPLACE_METHOD(0x14020f460, CClub, FUN_14020f460, 107, 0xAD41B767);
MS2_REPLACE_METHOD(0x14020f4e0, CClub, FUN_14020f4e0, 88, 0xE462DA0C);
MS2_REPLACE_METHOD(0x14020f540, CClub, FUN_14020f540, 101, 0x8753A277);
MS2_REPLACE_METHOD(0x14020f5b0, CClub, FUN_14020f5b0, 126, 0xA8B2CCB9);
MS2_REPLACE_METHOD(0x14020f640, CClub, FUN_14020f640, 101, 0xA3401D91);
MS2_REPLACE_METHOD(0x14020f6b0, CClub, FUN_14020f6b0, 101, 0xB74E3800);
MS2_REPLACE_METHOD(0x14020f720, CClub, FUN_14020f720, 172, 0xC453DD28);
MS2_REPLACE_METHOD(0x14020f7e0, CClub, FUN_14020f7e0, 104, 0x6AA63B60);
MS2_REPLACE_METHOD(0x14020f850, CClub, FUN_14020f850, 104, 0x92D7418F);
MS2_REPLACE_METHOD(0x14020f8c0, CClub, FUN_14020f8c0, 137, 0xE324CAAA);
MS2_REPLACE_METHOD(0x14020f950, CClub, FUN_14020f950, 104, 0x5D02D2F3);
MS2_REPLACE_METHOD(0x14020f9c0, CClub, FUN_14020f9c0, 91, 0x1E9456D4);
MS2_REPLACE_METHOD(0x14020fa30, CClub, FUN_14020fa30, 107, 0x8E973528);
MS2_REPLACE_METHOD(0x14020fab0, CClub, FUN_14020fab0, 94, 0xFAB60467);
MS2_REPLACE_METHOD(0x14020fb20, CClub, FUN_14020fb20, 601, 0x8013A294);
MS2_REPLACE_METHOD(0x14020fd80, CClub, FUN_14020fd80, 843, 0x27E47F04);
MS2_REPLACE_METHOD(0x1402100e0, CClub, FUN_1402100e0, 247, 0xA33DCD1F);
MS2_REPLACE_METHOD(0x1402101e0, CClub, FUN_1402101e0, 344, 0xDDF15478);
MS2_REPLACE_METHOD(0x140210560, CClub, FUN_140210560, 193, 0x4494E456);
MS2_REPLACE_METHOD(0x140210630, CClub, FUN_140210630, 350, 0x56CA7577);
MS2_REPLACE_METHOD(0x1402107a0, CClub, FUN_1402107a0, 299, 0x2D1F9475);
MS2_REPLACE_METHOD(0x1402108e0, CClub, FUN_1402108e0, 232, 0x9C367E6C);
MS2_REPLACE_METHOD(0x1402109d0, CClub, FUN_1402109d0, 238, 0x294EFCCD);
MS2_REPLACE_METHOD(0x140210ad0, CClub, FUN_140210ad0, 261, 0xF499838B);
MS2_REPLACE_METHOD(0x140210be0, CClub, FUN_140210be0, 257, 0x4FE9F893);
MS2_REPLACE_METHOD(0x140210cf0, CClub, FUN_140210cf0, 245, 0xC66CEF69);
MS2_REPLACE_METHOD(0x140210df0, CClub, FUN_140210df0, 112, 0x7B6C7A99);
MS2_REPLACE_METHOD(0x140210e70, CClub, FUN_140210e70, 246, 0x5286CF04);
MS2_REPLACE_METHOD(0x140210f70, CClub, FUN_140210f70, 138, 0x038BCF06);
MS2_REPLACE_METHOD(0x140211000, CClub, FUN_140211000, 113, 0x3186B5D2);
MS2_REPLACE_METHOD(0x140211080, CClub, FUN_140211080, 356, 0x330D17F1);
MS2_REPLACE_METHOD(0x140211280, CClubDataTable::ClubBuffData, FUN_140211280, 106, 0x47549914);
MS2_REPLACE_METHOD(0x1402113c0, CClubDataTable, FUN_1402113c0, 37, 0x66A38C51);
MS2_REPLACE_METHOD(0x1402113f0, CClubDataTable, LoadClubBuff, 672, 0x5962A366);
MS2_REPLACE_METHOD(0x1402116a0, CClubDataTable, FUN_1402116a0, 171, 0x34AEE797);
MS2_REPLACE_METHOD(0x140211760, CClubDataTable, FUN_140211760, 364, 0x07E0BEF5);
MS2_REPLACE_METHOD(0x1402118e0, CClubDataTable, FUN_1402118e0, 167, 0x5FA7F1F0);
MS2_REPLACE_METHOD(0x140211990, CClubDataTable, FUN_140211990, 168, 0xEA02FE78);
MS2_REPLACE_METHOD(0x140211a40, CClubDataTable, FUN_140211a40, 210, 0xDE7E0A43);
