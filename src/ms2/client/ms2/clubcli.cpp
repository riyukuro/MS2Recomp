// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClubCli packet handlers and requests, and the club
// registry CClubClientManager (see clubcli.h).
// MS2-UNIT: client\ms2\clubcli.cpp
// MS2-RANGE: 0x1400c7620-0x1400c7840 .text$di
// MS2-RANGE: 0x142ca0960-0x142ca0a50 .text$yd
// MS2-RANGE: 0x140b12780-0x140b1d2b0 .text$mn
// MS2-PIN: ??__Fs_unk1402a9d70_0@@YAXXZ 0x142ca09a0
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142ca0a30
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@QEBA_KXZ 0x140b1a490
// MS2-PIN: ??0?$MS2Ptr@VCClubCli@@@@QEAA@PEAVCClubCli@@@Z 0x140b196f0
// MS2-PIN: ?AddRef@?$MS2Ptr@VCClubCli@@@@AEBAXXZ 0x140b1cda0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCClubCli@@@@AEBAXPEAX@Z 0x140b1cea0
// MS2-PIN: ?Release@?$MS2Ptr@VCClubCli@@@@AEAAXXZ 0x140b1cfa0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCClubClientManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140b1d180
// MS2-PIN: ??_7?$TPtredDummy@V?$CRBMap@_KV?$MS2Ptr@VCClubCli@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCClubCli@@@@@3@@ATL@@@@6B@ 0x142ddad60
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEBQEAVCClubClientManager@@@std@@YAAEBQEAVCClubClientManager@@AEBQEAV1@@Z 0x140b193a0 ; unique
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@QEAA@XZ 0x140b19400 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCClubMember@@@@QEAAAEAV1@PEAVCClubMember@@@Z 0x140b19cc0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VPacketInvite@Club@@@@QEBAPEAVPacketInvite@Club@@XZ 0x140b19e00 ; unique
// MS2-PIN: ??C?$MS2Ptr@VPacketInvite@Club@@@@QEBAPEAVPacketInvite@Club@@XZ 0x140b19e70 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCClubMember@@@@_K@Z 0x140b1a450 ; unique
// MS2-PIN: ?GetCount@?$CRBTree@_KV?$MS2Ptr@VCClubCli@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCClubCli@@@@@3@@ATL@@QEBA_KXZ 0x140b1a4a0 ; unique
// MS2-PIN: ?GetCount@?$CRBTree@_KV?$MS2Ptr@VPacketInvite@Club@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VPacketInvite@Club@@@@@3@@ATL@@QEBA_KXZ 0x140b1a4b0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCClubCli@@@@CAXPEAVCClubCli@@@Z 0x140b1ce40 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCClubCli@@@@AEAAXPEAX@Z 0x140b1d090 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCClubClientManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140b1d1e0 ; unique
// MS2-PIN: ??$Call@VCClubClientManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCClubClientManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCClubClientManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140b1d220 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\clubcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "clubcli.h"

#include "ms2/client/ms2/partymanager.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uiclubdialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"  // C3: CMsgBoxData
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"


// CClubCli has its CPtred base at +0xd8, so the exe's MS2Ptr<CClubCli> members convert through it with the null checks.
template<> void MS2Ptr<CClubCli>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>(static_cast<CClubCli*>(0)));
}
template<> MS2Ptr<CClubCli>::MS2Ptr(CClubCli* p)
{
    m_p = static_cast<CClubCli*>(static_cast<CPtred*>(p));
    AddRef();
}
template<> void MS2Ptr<CClubCli>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>(static_cast<CClubCli*>(0)));
        m_p = 0;
    }
}

// ---- statics (.text$di) ----
// The first three come from a header that precedes the item-sort header (header_statics_a.h) in this unit.
static CString s_strSkill0 = "skill";
static CString s_strStun0 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_0(17, 0.75f, 0.25f, 2.25f, 10);
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/ms2format.h"   // C3: fmt for BlockFormat<int>

// ---- unit-local placeholders ----

unsigned __int64 FUN_140718370(const CStringW& str);                 // value
extern template class MS2Ptr<CMsgBoxData>;
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;

void FUN_14151f150(Unk_MsgBoxPtr box);
void FUN_140d73c60(Unk_MsgBoxPtr box);
Unk_MsgBoxPtr FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);

// UI manager and the club window lookup.
class Unk_ClubUIManager
{
public:
};

class Unk_ClubWorldObj;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    class Unk_WsC_GameObj* FUN_141bd1420(CStringW strName);   // a player by name
    static class WorldService* GetInstance();
};

// The club buff table (CClubDataTable, commonfiles\clubcommon.h), through its global accessor 0x140b1a4e0.
CClubDataTable* FUN_140b1a4e0();

// The club name limits, kept in the game constants.
struct Unk_ClubLimit
{
    void* m_pad;
};
class Unk_ClubConsts
{
public:
    char m_pad_0[0x9e10];
    Unk_ClubLimit m_nameMin;                                       // +0x9e10
    char m_pad_9e18[0x9e68 - 0x9e18];
    Unk_ClubLimit m_nameMax;                                       // +0x9e68
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// Feature flags (FUN_140166410 / FUN_14036d570) and the party manager (TSingleton<CPartyManager>::GetInstance).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

// String helpers (string table lookups with arguments) and the chat/notice output.
CStringW GetStringCommon(int nId);
#include "ms2/placeholder/formatstringid.h"
CStringW BlockFormat(int nId);
#include "ms2/placeholder/blockformat.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
void FUN_1412751b0(const CStringW& str, int nChannel);
void FUN_1412751f0(const CStringW& str, int a, int b);
void FUN_141275260(int nId, int a, int b);
bool FUN_141b70f50(const CStringW& a, const CStringW& b);
int FUN_141276c80(const CStringW& strName, bool bCheckSelf, CStringW& strError);
void FUN_140710590(COutPacket& packet);

CStringW FUN_140b18ef0();
UIClubDialog* FUN_140b19090(int nUiId);
Unk_MsgBoxPtr FUN_140b191a0(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, __int64 nUid);
void FUN_140b18470(CStringW strClub, CStringW strName, int nResult);
void FUN_140b18580(CStringW strClub, CStringW strName, int nCode);
void FUN_140b18700(int nKind, int nCode);

// @0x1400c7620 .. 0x1400c77f0: the statics above.

// @0x140b12780
CClubCli::CClubCli()
{
}

// @0x140b127f0
CClubCli::~CClubCli()
{
}

// @0x140b12850
MS2Ptr<CClubMember> CClubCli::FindMemberById(__int64 nCharacterId)
{
    MS2Ptr<CClubMember> spResult(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos != 0; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> spMember = m_members.GetValueAt(pos);
            if (spMember && spMember->m_info.m_characterId == nCharacterId)
            {
                spResult = spMember;
                break;
            }
        }
    }
    return spResult;
}

// @0x140b129c0
int CClubCli::FUN_140b129c0()
{
    int nCount = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_members.GetHeadPosition(); pos != 0; m_members.GetNext(pos))
        {
            MS2Ptr<CClubMember> spMember = m_members.GetValueAt(pos);
            if (spMember && spMember->m_f0 == 0)
                nCount = nCount + 1;
        }
    }
    return nCount;
}

// @0x140b12ad0
void CClubCli::FUN_140b12ad0(CInPacket& packet)
{
    int nResult = packet.ReadInt32();
    CStringW strName = packet.ReadUnicodeString();
    if (nResult != 0)
    {
        FUN_140b18470(FUN_14020f1a0(), CStringW(strName), nResult);
        return;
    }
    SetState(2);
    ATL::CAtlArray<MS2Ptr<CClubMember> > members;
    GetAllMembers(members);
    for (unsigned __int64 i = 0; i < members.GetCount(); i = i + 1)
    {
        MS2Ptr<CClubMember> spMember = members[i];
        if (spMember == 0)
            continue;
        spMember->m_cc = 0;
    }
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW>(0x344, FUN_14020f1a0()), 0xf);
}

// @0x140b12d70
void CClubCli::FUN_140b12d70(CInPacket& packet)
{
    CStringW strActor = packet.ReadUnicodeString();
    CClubMember member;
    member.ReadPacket(&packet);
    MS2Ptr<CClubMember> spMember = FindMemberByName(member.m_info.GetName());
    if (spMember.get() != 0)
    {
        spMember->FUN_14020e950(&member);
    }
    else
    {
        spMember.AssignRaw(new CClubMember);
        spMember->FUN_14020e950(&member);
        vfunc_4(MS2Ptr<CClubMember>(spMember));
    }
    if (spMember->m_c8 == 2)
    {
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
        FUN_1412751b0(BlockFormat<CStringW, CStringW, CStringW>(0x352, strActor, member.m_info.GetName(), FUN_14020f1a0()), 0xf);
    }
}

// @0x140b13060
void CClubCli::FUN_140b13060(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
        FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x351, strName, FUN_14020f1a0()), 0xf);
    }
}

// @0x140b13200
void CClubCli::FUN_140b13200(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        spMember->m_f0 = 0;
    }
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x353, FUN_14020f1a0(), strName), 0xf);
}

// @0x140b133c0
void CClubCli::FUN_140b133c0(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    __int64 nTime = packet.ReadInt64();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        spMember->m_f0 = 1;
        spMember->m_d8 = nTime;
    }
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x354, FUN_14020f1a0(), strName), 0xf);
}

// @0x140b135d0
void CClubCli::FUN_140b135d0(CInPacket& packet)
{
    CStringW strFirst = packet.ReadUnicodeString();
    CStringW strSecond = packet.ReadUnicodeString();
    unsigned nFlag = packet.ReadUInt8();
    MS2Ptr<CClubMember> spFirst = FindMemberByName(CStringW(strFirst));
    if (spFirst == 0)
        return;
    MS2Ptr<CClubMember> spSecond = FindMemberByName(CStringW(strSecond));
    if (spSecond == 0)
        return;
    SetLeaderInfo(spSecond->m_info.m_accountId, spSecond->m_info.m_characterId, spSecond->m_info.GetName(), 1);
    m_leader = spSecond;
    bool bMe = FUN_141b70f50(strFirst, FUN_140b18ef0());
    if (bMe)
    {
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
        if (nFlag == 0)
            FUN_1412751b0(FormatStringId<CStringW>(0x356, FUN_14020f1a0()), 0xf);
    }
    else
    {
        FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x355, FUN_14020f1a0(), strSecond), 0xf);
    }
}

// @0x140b13a20
void CClubCli::OnPacketClubBuff(CInPacket& packet)
{
    int nBuffId = packet.ReadInt32();
    int nBuffLevel = packet.ReadInt32();
    SetBuff(nBuffId, nBuffLevel);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW>(0x357, FUN_14020f1a0()), 0xf);
}

// @0x140b13b50
void CClubCli::FUN_140b13b50(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember == 0)
        return;
    spMember->m_info.ReadMapId(packet);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b13c60
void CClubCli::FUN_140b13c60(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    CClubMemberProxy proxy;
    proxy.FUN_14020d640(&packet);
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember == 0)
        return;
    spMember->m_info.FUN_14020e130(proxy);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b13dc0
void CClubCli::FUN_140b13dc0(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
        FUN_1412751b0(FormatStringId<CStringW>(0x351, strName), 0xf);
    }
}

// @0x140b13f20
void CClubCli::OnPacketClubRename(CInPacket& packet)
{
    CStringW strNewName = packet.ReadUnicodeString();
    CStringW strOldName = FUN_14020f1a0();
    __int64 nTime = packet.ReadInt64();
    FUN_14020f230(strNewName);
    SetNameChangeAvailableTime(nTime);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x358, strOldName, strNewName), 0xf);
}

// @0x140b14050
void CClubCli::OnPacketMemberRename(CInPacket& packet)
{
    CStringW strOldName = packet.ReadUnicodeString();
    CStringW strNewName = packet.ReadUnicodeString();
    RenameMember(strOldName, strNewName);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b14110
void CClubCli::FUN_140b14110(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubMember> spMember = FindMemberByName(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
    }
}

// @0x140b14220
bool CClubCli::FUN_140b14220()
{
    return true;
}

// @0x140b14230
bool CClubCli::FUN_140b14230(CStringW strName)
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return false;
    if (IsLeaderName(CStringW(strMe)) == 0)
        return false;
    CStringW strError;
    int nResult = FUN_141276c80(strName, true, strError);
    if (nResult != 0)
    {
        int nMessage = (nResult == 10) ? 0x349 : 0x34a;
        FUN_141275260(nMessage, 1, 1);
        return false;
    }
    if (GetMemberCount() >= (int)GetMaxMemberCount())
        return false;
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(6);
    pkt.WriteInt64(FUN_14020f0c0());
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}

// @0x140b14480
void CClubCli::SendClubMode10()
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(10);
    pkt.WriteInt64(FUN_14020f0c0());
    FUN_140710590(pkt);
}

// @0x140b14530
void CClubCli::SendClubMode12(CStringW strName)
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    if (strMe.CompareNoCase(strName) == 0)
        return;
    if (IsLeaderName(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(BlockFormat(0x37b), 1, 1);
        return;
    }
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(0xc);
    pkt.WriteInt64(FUN_14020f0c0());
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
}

// @0x140b146e0
void CClubCli::FUN_140b146e0(int nBuffId, int nBuffLevel)
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    if (IsLeaderName(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(BlockFormat(0x37b), 1, 1);
        return;
    }
    if (GetBuffId() == nBuffId && GetBuffLevel() == (unsigned)nBuffLevel)
        return;
    int bClear = 0;
    if (nBuffId == 0 && nBuffLevel == 0)
        bClear = 1;
    CClubDataTable::BuffPtr spBuff = FUN_140b1a4e0()->FUN_140211760(nBuffId, nBuffLevel);
    if (spBuff == 0 && bClear == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(0xd);
    pkt.WriteInt64(FUN_14020f0c0());
    pkt.WriteInt32(nBuffId);
    pkt.WriteInt32(nBuffLevel);
    FUN_140710590(pkt);
}

// @0x140b14900
void CClubCli::SendClubMode14(CStringW strNewName)
{
    if (strNewName.IsEmpty())
        return;
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    if (strNewName.Find(L" ", 0) != -1)
    {
        FUN_141275260(0x386, 1, 1);
        return;
    }
    if (IsLeaderName(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(BlockFormat(0x37b), 1, 1);
        return;
    }
    if (m_name.CompareNoCase(strNewName) == 0)
    {
        FUN_1412751f0(BlockFormat(0x385), 1, 1);
        return;
    }
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(0xe);
    pkt.WriteInt64(FUN_14020f0c0());
    pkt.WriteUnicodeString(strNewName);
    FUN_140710590(pkt);
}

// @0x140b14b70
CClubClientManager::CClubClientManager()
    : m_invites(10), m_clubs(10)
{
}

// @0x140b14bf0
CClubClientManager::~CClubClientManager()
{
}

// @0x140b14c50
void CClubClientManager::ClearClubsAndInvites()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_clubs.RemoveAll();
        m_invites.RemoveAll();
    }
}

// @0x140b14cd0
int CClubClientManager::IsClubLimitReached()
{
    int nResult = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        int nClubs = (int)m_clubs.GetCount();
        int nInvites = (int)m_invites.GetCount();
        int nTotal = nClubs + nInvites;
        if (nTotal >= 3)
            nResult = 1;
    }
    return nResult;
}

// @0x140b14d80
MS2Ptr<CClubCli> CClubClientManager::GetClub(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_clubs.Lookup(nClubId, spClub);
    }
    return spClub;
}

// @0x140b14e40
Unk_SocketPtr<Unk_ClubCliMap> CClubClientManager::FUN_140b14e40()
{
    Unk_SocketPtr<Unk_ClubCliMap> spResult(Unk_SocketNew(0));
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_clubs.GetHeadPosition(); pos != 0; m_clubs.GetNext(pos))
        {
            unsigned __int64 nKey = m_clubs.GetKeyAt(pos);
            MS2Ptr<CClubCli> spClub = m_clubs.GetValueAt(pos);
            if (spClub->GetState() == 2)
                spResult->SetAt(nKey, spClub);
        }
    }
    return spResult;
}

// @0x140b14fc0
__int64 CClubClientManager::GetClubIdByName(CStringW strName)
{
    __int64 nClubId = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_clubs.GetHeadPosition(); pos != 0; m_clubs.GetNext(pos))
        {
            MS2Ptr<CClubCli> spClub = m_clubs.GetValueAt(pos);
            if (spClub.get() != 0 && spClub->GetState() == 2)
            {
                if (spClub->FUN_14020f1a0() == strName)
                {
                    nClubId = spClub->FUN_14020f0c0();
                    break;
                }
            }
        }
    }
    return nClubId;
}

// @0x140b15150
CStringW CClubClientManager::GetClubName(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return CStringW(L"");
    return spClub->FUN_14020f1a0();
}

// @0x140b15210
int CClubClientManager::HasClub(__int64 nClubId)
{
    if (GetClub(nClubId) == 0)
        return 0;
    return 1;
}

// @0x140b15290
int CClubClientManager::FUN_140b15290(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return 0;
    return 1;
}

// @0x140b15310
int CClubClientManager::FUN_140b15310()
{
    if (m_clubs.IsEmpty())
        return 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_clubs.GetHeadPosition(); pos != 0; m_clubs.GetNext(pos))
        {
            MS2Ptr<CClubCli> spClub = m_clubs.GetValueAt(pos);
            if (spClub)
            {
                if (spClub->GetState() == 2)
                    return 1;
            }
        }
    }
    return 0;
}

// @0x140b15440
void CClubClientManager::AddClub(MS2Ptr<CClubCli> spClub)
{
    if (spClub == 0)
        return;
    if (IsClubLimitReached() == 1)
    {
        MS2_ASSERT_AT(0x25a, 0);
        return;
    }
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_clubs.SetAt(spClub->FUN_14020f0c0(), spClub);
    }
}

// @0x140b15530
void CClubClientManager::RemoveClub(__int64 nClubId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_clubs.RemoveKey(nClubId);
    }
}

// @0x140b155a0
void CClubClientManager::AddInvite(MS2Ptr<Club::PacketInvite> spInvite)
{
    if (spInvite == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_invites.SetAt(spInvite->m_inviteId, spInvite);
    }
}

// @0x140b15640
void CClubClientManager::RemoveInvite(__int64 nInviteId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_invites.RemoveKey(nInviteId);
    }
}

// @0x140b156b0
MS2Ptr<Club::PacketInvite> CClubClientManager::FindInvite(__int64 nInviteId)
{
    MS2Ptr<Club::PacketInvite> spInvite(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_invites.Lookup(nInviteId, spInvite);
    }
    return spInvite;
}

// @0x140b15770
MS2Ptr<CClubMember> CClubClientManager::FindMember(__int64 nClubId, __int64 nCharacterId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return MS2Ptr<CClubMember>(0);
    return spClub->FindMemberById(nCharacterId);
}

// @0x140b15830
int CClubClientManager::FUN_140b15830(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return 0;
    return spClub->FUN_140b129c0();
}

// @0x140b158c0
void CClubClientManager::OnClub(CInPacket& packet)
{
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x56))
        return;
    int nSubOpcode = packet.ReadUInt8();
    switch (nSubOpcode)
    {
    case 0:
        OnClubAdded(packet);
        break;
    case 1:
        FUN_140b16650(packet);
        break;
    case 2:
        FUN_140b166d0(packet);
        break;
    case 4:
        FUN_140b16a70(packet);
        break;
    case 5:
        FUN_140b16b20(packet);
        break;
    case 6:
        FUN_140b16bc0(packet);
        break;
    case 7:
        FUN_140b16d20(packet);
        break;
    case 8:
        FUN_140b17150(packet);
        break;
    case 9:
        FUN_140b17210(packet);
        break;
    case 10:
        FUN_140b173f0(packet);
        break;
    case 0xc:
        FUN_140b17530(packet);
        break;
    case 0xd:
        FUN_140b17600(packet);
        break;
    case 0xf:
        FUN_140b176e0(packet);
        break;
    case 0x10:
        FUN_140b17780(packet);
        break;
    case 0x11:
        FUN_140b17a60(packet);
        break;
    case 0x12:
        FUN_140b17b00(packet);
        break;
    case 0x13:
        FUN_140b17ba0(packet);
        break;
    case 0x14:
        FUN_140b17c40(packet);
        break;
    case 0x15:
        FUN_140b17ce0(packet);
        break;
    case 0x16:
        OnPacketClubBuff(packet);
        break;
    case 0x17:
        FUN_140b17e20(packet);
        break;
    case 0x18:
        FUN_140b17ec0(packet);
        break;
    case 0x19:
        FUN_140b17f60(packet);
        break;
    case 0x1a:
        OnPacketClubRename(packet);
        break;
    case 0x1b:
        OnPacketMemberRename(packet);
        break;
    case 0x1c:
        FUN_140b18140(packet);
        break;
    case 0x1d:
        FUN_140b181e0(packet);
        break;
    case 0x1e:
        FUN_140b18260(packet);
        break;
    default:
        MS2_ASSERT_AT(0x30e, FALSE);
        break;
    }
}

// @0x140b15c10
bool CClubClientManager::FUN_140b15c10(CStringW strName)
{
    if (IsClubLimitReached() == 1)
    {
        FUN_1412751f0(BlockFormat<int>(0x381, 3), 1, 1);
        return false;
    }
    int nMinLength = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_ClubConsts*)FUN_1401d3200())->m_nameMin)->Get();
    int nMaxLength = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_ClubConsts*)FUN_1401d3200())->m_nameMax)->Get();
    if (strName.GetLength() < nMinLength || strName.GetLength() > nMaxLength)
        return false;
    if (strName.Find(L" ", 0) != -1)
    {
        FUN_141275260(0x386, 1, 1);
        return false;
    }
    if (!TSingleton<CPartyManager>::GetInstance()->IsInParty())
    {
        FUN_141275260(0x36c, 1, 1);
        return false;
    }
    if (!TSingleton<CPartyManager>::GetInstance()->IsLocalPlayerLeader())
    {
        FUN_141275260(0x36c, 1, 1);
        return false;
    }
    if (CBanTextChecker* pFilter = CommonString::GetInstance()->GetChecker())
    {
        CStringW strError;
        if (pFilter->FUN_140226400(strName, strError) != 0)
        {
            FUN_1412751f0(strError, 1, 1);
            return false;
        }
    }
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(1);
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}

// @0x140b15f40
void CClubClientManager::SendClubMode3(__int64 nClubId, int nCode)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    if (spClub->GetState() != 1)
        return;
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(3);
    pkt.WriteInt64(nClubId);
    pkt.WriteInt32(nCode);
    FUN_140710590(pkt);
}

// @0x140b16030
bool CClubClientManager::FUN_140b16030(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return false;
    return spClub->FUN_140b14220();
}

// @0x140b160c0
bool CClubClientManager::FUN_140b160c0(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return false;
    return spClub->FUN_140b14230(CStringW(strName));
}

// @0x140b161a0
void CClubClientManager::SendClubMode8(__int64 nInviteId, int bAccept)
{
    MS2Ptr<Club::PacketInvite> spInvite = FindInvite(nInviteId);
    if (spInvite == 0)
        return;
    COutPacket pkt(static_cast<int>(SendOp::Club), 0);
    pkt.WriteUInt8(8);
    spInvite->FUN_14020c670(pkt);
    pkt.WriteUInt8(bAccept);
    FUN_140710590(pkt);
}

// @0x140b16270
void CClubClientManager::WithdrawFromClub(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode10();
}

// @0x140b162f0
void CClubClientManager::ChangeClubLeader(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode12(CStringW(strName));
}

// @0x140b163c0
void CClubClientManager::FUN_140b163c0(__int64 nClubId, int nBuffId, int nLevel)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b146e0(nBuffId, nLevel);
}

// @0x140b16450
void CClubClientManager::RenameClub(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode14(CStringW(strName));
}

// @0x140b16520
void CClubClientManager::OnClubAdded(CInPacket& packet)
{
    if (IsClubLimitReached() == 1)
    {
        MS2_ASSERT_AT(0x317, 0);
        return;
    }
    MS2Ptr<CClubCli> spClub(new CClubCli);
    spClub->FUN_14020fd80(packet);
    AddClub(MS2Ptr<CClubCli>(spClub));
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b16650
void CClubClientManager::FUN_140b16650(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    CStringW strName = packet.ReadUnicodeString();
}

// @0x140b166d0
void CClubClientManager::FUN_140b166d0(CInPacket& packet)
{
    MS2Ptr<CClubCli> spClub(new CClubCli);
    spClub->FUN_14020fd80(packet);
    AddClub(MS2Ptr<CClubCli>(spClub));
    if (spClub->GetLeaderName() == FUN_140b18ef0())
    {
        SendClubMode3(spClub->FUN_14020f0c0(), 0);
    }
    else
    {
        Unk_MsgBoxPtr box = FUN_140b191a0(
            FormatStringId<CStringW, CStringW>(0x345, spClub->GetLeaderName(), spClub->FUN_14020f1a0()), 1,
            Delegate<bool(int, const CMsgBoxData&)>(this, &CClubClientManager::FUN_140b18390), spClub->FUN_14020f0c0());
        box->SetTimer(0x14, 1, GetStringCommon(0x2b8));
        box.operator->()->FUN_141a024a0(false);
        FUN_140d73c60(box);
    }
}

// @0x140b16a70
void CClubClientManager::FUN_140b16a70(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    int nResult = packet.ReadUInt8();
    if (nResult != 0)
    {
        FUN_140b18700(4, nResult);
        return;
    }
    RemoveClub(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b16b20
void CClubClientManager::FUN_140b16b20(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    int nReason = packet.ReadInt32();
    RemoveClub(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b16bc0
void CClubClientManager::FUN_140b16bc0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    FUN_1412751b0(FormatStringId<CStringW, CStringW>(0x347, strName, spClub->FUN_14020f1a0()), 0x14);
}

// @0x140b16d20
void CClubClientManager::FUN_140b16d20(CInPacket& packet)
{
    if (IsClubLimitReached() == 1)
    {
        MS2_ASSERT_AT(0x389, 0);
        return;
    }
    MS2Ptr<Club::PacketInvite> spInvite(new Club::PacketInvite);
    spInvite->FUN_14020c720(packet);
    if (FindInvite(spInvite->m_inviteId).get() != 0)
    {
        MS2_ASSERT_AT(0x392, 0);
        return;
    }
    AddInvite(MS2Ptr<Club::PacketInvite>(spInvite));
    CStringW strText = FormatStringId<CStringW, CStringW>(0x348, spInvite->m_28, spInvite->m_20);
    Unk_MsgBoxPtr box = FUN_140d73d20(1, CStringW(strText), 0, CStringW(L""));
    if (box.get() != 0)
    {
        box->SetTimer(0x14, 1, GetStringCommon(0x2b8));
        box.operator->()->FUN_141a024a0(false);
        box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CClubClientManager::FUN_140b18400));
        box->Append<__int64>(spInvite->m_inviteId);
        FUN_140d73c60(box);
    }
}

// @0x140b17150
void CClubClientManager::FUN_140b17150(CInPacket& packet)
{
    Club::PacketInvite invite;
    invite.FUN_14020c720(packet);
    int nResult = packet.ReadInt32();
    RemoveInvite(invite.m_inviteId);
    if (nResult == 0)
    {
    }
    else
    {
        if (nResult == 0x46)
            return;
        FUN_140b18700(8, nResult);
    }
}

// @0x140b17210
void CClubClientManager::FUN_140b17210(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    CStringW strName = packet.ReadUnicodeString();
    int nType = packet.ReadUInt8();
    int nCode = packet.ReadUInt8();
    if (nType == 1)
    {
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->RefreshData();
    }
    else
    {
        FUN_140b18580(spClub->FUN_14020f1a0(), CStringW(strName), nCode);
    }
}

// @0x140b173f0
void CClubClientManager::FUN_140b173f0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    RemoveClub(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
    FUN_1412751b0(FormatStringId<CStringW>(0x350, spClub->FUN_14020f1a0()), 0xf);
}

// @0x140b17530
void CClubClientManager::FUN_140b17530(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    CStringW strName = packet.ReadUnicodeString();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
}

// @0x140b17600
void CClubClientManager::FUN_140b17600(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    int nBuffId = packet.ReadInt32();
    int nBuffLevel = packet.ReadInt32();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
}

// @0x140b176e0
void CClubClientManager::FUN_140b176e0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b12ad0(packet);
}

// @0x140b17780
void CClubClientManager::FUN_140b17780(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    CStringW strName = packet.ReadUnicodeString();
    int nCode = packet.ReadInt32();
    if (nCode == 0xcf)
    {
        if (FUN_141b70f50(strName, FUN_140b18ef0()) == 1)
            FUN_1412751b0(FormatStringId<CStringW>(0x346, spClub->FUN_14020f1a0()), 0xf);
        else
            FUN_1412751b0(FormatStringId<CStringW>(0x346, spClub->FUN_14020f1a0()), 0xf);
    }
    RemoveClub(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->RefreshData();
}

// @0x140b17a60
void CClubClientManager::FUN_140b17a60(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b12d70(packet);
}

// @0x140b17b00
void CClubClientManager::FUN_140b17b00(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13060(packet);
}

// @0x140b17ba0
void CClubClientManager::FUN_140b17ba0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13200(packet);
}

// @0x140b17c40
void CClubClientManager::FUN_140b17c40(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b133c0(packet);
}

// @0x140b17ce0
void CClubClientManager::FUN_140b17ce0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b135d0(packet);
}

// @0x140b17d80
void CClubClientManager::OnPacketClubBuff(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->OnPacketClubBuff(packet);
}

// @0x140b17e20
void CClubClientManager::FUN_140b17e20(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13b50(packet);
}

// @0x140b17ec0
void CClubClientManager::FUN_140b17ec0(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13c60(packet);
}

// @0x140b17f60
void CClubClientManager::FUN_140b17f60(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13dc0(packet);
}

// @0x140b18000
void CClubClientManager::OnPacketClubRename(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->OnPacketClubRename(packet);
}

// @0x140b180a0
void CClubClientManager::OnPacketMemberRename(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->OnPacketMemberRename(packet);
}

// @0x140b18140
void CClubClientManager::FUN_140b18140(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    MS2Ptr<CClubCli> spClub = GetClub(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b14110(packet);
}

// @0x140b181e0
void CClubClientManager::FUN_140b181e0(CInPacket& packet)
{
    int nKind = packet.ReadUInt8();
    int nCode = packet.ReadInt32();
    FUN_140b18700(nKind, nCode);
}

// @0x140b18260
void CClubClientManager::FUN_140b18260(CInPacket& packet)
{
    __int64 nClubId = packet.ReadInt64();
    CStringW strFirst = packet.ReadUnicodeString();
    CStringW strSecond = packet.ReadUnicodeString();
    Unk_ClubWorldObj* pObj = ((Unk_ClubWorldObj*)WorldService::GetInstance()->FUN_141bd1420(strFirst));
    if (pObj == 0)
        return;
}

// @0x140b18390
bool CClubClientManager::FUN_140b18390(int nResult, const CMsgBoxData& data)
{
    int nCode = 0;
    if (nResult != 0)
        nCode = 0x4c;
    __int64 nClubId = 0;
    data.FUN_140b19130(0, nClubId);
    SendClubMode3(nClubId, nCode);
    return true;
}

// @0x140b18400
bool CClubClientManager::FUN_140b18400(int nResult, const CMsgBoxData& data)
{
    int nAccept = 1;
    if (nResult != 0)
        nAccept = 0;
    __int64 nInviteId = 0;
    data.FUN_140b19130(0, nInviteId);
    SendClubMode8(nInviteId, nAccept);
    return true;
}

// @0x140b18470
void FUN_140b18470(CStringW strClub, CStringW strName, int nResult)
{
    CStringW strMessage;
    switch (nResult)
    {
    case 0x4c:
        strMessage = FormatStringId<CStringW, CStringW>(0x36a, strName, strClub);
        break;
    default:
        strMessage = FormatStringId<CStringW>(0x369, strClub);
        break;
    }
    FUN_1412751b0(strMessage, 0xf);
}

// @0x140b18580
void FUN_140b18580(CStringW strClub, CStringW strName, int nCode)
{
    CStringW strMessage;
    switch (nCode)
    {
    case 2:
        strMessage = FormatStringId<CStringW, CStringW>(0x34f, strName, strClub);
        break;
    case 3:
        strMessage = FormatStringId<CStringW, CStringW>(0x34e, strName, strClub);
        break;
    default:
        strMessage = FormatStringId<CStringW, CStringW>(0x34d, strName, strClub);
        break;
    }
    FUN_1412751b0(strMessage, 0xf);
}

// @0x140b18700
void FUN_140b18700(int nKind, int nCode)
{
    CStringW strMessage;
    switch (nCode)
    {
    case 1:
        strMessage = GetStringCommon(0x368);
        break;
    case 11:
    case 12:
        strMessage = GetStringCommon(0x372);
        break;
    case 13:
        strMessage = GetStringCommon(0x375);
        break;
    case 14:
        strMessage = GetStringCommon(0x36b);
        break;
    case 15:
        strMessage = GetStringCommon(0x37d);
        break;
    case 51:
        strMessage = GetStringCommon(0x37b);
        break;
    case 52:
        strMessage = GetStringCommon(0x378);
        break;
    case 53:
        strMessage = GetStringCommon(0x379);
        break;
    case 54:
        strMessage = GetStringCommon(0x36f);
        break;
    case 55:
        strMessage = GetStringCommon(0x37c);
        break;
    case 57:
        strMessage = GetStringCommon(0x377);
        break;
    case 58:
        strMessage = GetStringCommon(0x382);
        break;
    case 60:
        strMessage = GetStringCommon(0x373);
        break;
    case 61:
        strMessage = GetStringCommon(0x374);
        break;
    case 62:
        strMessage = GetStringCommon(0x376);
        break;
    case 63:
        strMessage = GetStringCommon(0x36d);
        break;
    case 72:
        strMessage = GetStringCommon(900);
        break;
    case 67:
        strMessage = GetStringCommon(899);
        break;
    case 73:
        strMessage = GetStringCommon(0x385);
        break;
    case 74:
        strMessage = GetStringCommon(0x386);
        break;
    case 59:
        strMessage = GetStringCommon(0x387);
        break;
    default:
        strMessage = GetStringCommon(0x37e);
    }
    FUN_1412751f0(strMessage, 1, 1);
}

// @0x140b18ef0
CStringW FUN_140b18ef0()
{
    PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return CStringW(L"");
    return pPlayer->vfunc_77();
}

// @0x140b1a4e0
CClubDataTable* FUN_140b1a4e0()
{
    return TSingleton<CClubDataTable>::s_instance;
}

// @0x140b19090
UIClubDialog* FUN_140b19090(int nUiId)
{
    if (reinterpret_cast<Unk_ClubUIManager*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spUI = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIClubDialog*>(spUI.operator->());
    }
    return 0;
}

// @0x140b19130
bool CMsgBoxData::FUN_140b19130(unsigned nIndex, __int64& nValue) const
{
    if (!(nIndex < m_args.GetCount()))
        return false;
    nValue = FUN_140718370(m_args[nIndex]);
    return true;
}

// @0x140b191a0
Unk_MsgBoxPtr FUN_140b191a0(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, __int64 nUid)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->SetMsg(strText);
    box->SetCallback(cb);
    box->Append<__int64>(nUid);
    FUN_14151f150(box);
    return box;
}
