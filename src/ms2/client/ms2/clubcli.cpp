// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClubCli packet handlers and requests, and the club
// registry CClubClientManager (see clubcli.h).
// MS2-UNIT: client\ms2\clubcli.cpp
// MS2-RANGE: 0x1400c7620-0x1400c7840 .text$di
// MS2-RANGE: 0x142ca0960-0x142ca0a50 .text$yd
// MS2-RANGE: 0x140b12780-0x140b1d2b0 .text$mn
// MS2-PIN: ??__Fs_unk1402a9d70_0@@YAXXZ 0x142ca09a0
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142ca0a30
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCClubMember@@@@V?$CElementTraits@V?$MS2Ptr@VCClubMember@@@@@ATL@@@ATL@@QEBA_KXZ 0x140b1a490
// MS2-PIN: ??8?$MS2Ptr@VUnk_ClubBuffData@@@@QEBA_NPEAVUnk_ClubBuffData@@@Z 0x140b19db0
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
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uiclubdialog.h"
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

// ---- unit-local placeholders ----

// The message box record (0x2a0 bytes; the MS2Ptr<CMsgBoxData> members are the exe copies bound through symbols.tsv).
struct Unk_MsgParam
{
    __int64 m_nValue;
};
// A CAtlArray-like vector of parameters (data, count, ...).
struct Unk_MsgParamArray
{
    Unk_MsgParam* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
};
size_t FUN_14015a000(const Unk_MsgParamArray& arr);                   // count
Unk_MsgParam& FUN_140164970(Unk_MsgParamArray& arr, size_t nIndex);   // element (throws E_INVALIDARG past the end)
__int64 FUN_140718370(Unk_MsgParam& param);                           // value

class CMsgBoxData : public CPtred
{
public:
    CMsgBoxData(int nType);
    void SetMsg(const CStringW& strText);
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    bool FUN_140b19130(unsigned nIndex, __int64& nValue) const;    // the nIndex-th stored value (this unit)

    char m_pad_18[0x228 - 0x18];
    Unk_MsgParamArray m_values;                                    // +0x228
    char m_pad_248[0x2a0 - 0x248];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
extern template class MS2Ptr<CMsgBoxData>;
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;

void FUN_141a01ca0(CMsgBoxData* pBox, int a, int b, const CStringW& str);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);
void FUN_1405340b0(CMsgBoxData* pBox, __int64 n);
void FUN_14151f150(Unk_MsgBoxPtr box);
void FUN_140d73c60(Unk_MsgBoxPtr box);
Unk_MsgBoxPtr FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);

// UI manager and the club window lookup.
class Unk_ClubUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);
};
Unk_ClubUIManager* FUN_1403ed2b0();

// The world (FUN_1403ed2d0): my player and the player lookup by name.
class Unk_ClubWorldObj;
class Unk_ClubWorld
{
public:
    PCBase* FUN_141bd0cc0();
    Unk_ClubWorldObj* FUN_141bd1420(CStringW strName);
};
Unk_ClubWorld* FUN_1403ed2d0();

// Club buff table (global accessor 0x140b1a4e0): the buff record for a buff id and level.
class Unk_ClubBuffData : public CPtred
{
};
class Unk_ClubBuffTable
{
public:
    MS2Ptr<Unk_ClubBuffData> FUN_140211760(int nBuffId, int nLevel);
};

extern Unk_ClubBuffTable* DAT_143aac6f8;
Unk_ClubBuffTable* FUN_140b1a4e0();

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
Unk_ClubConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_ClubLimit* pLimit);

// Name filter chain of the create-club request.
class Unk_ClubNameFilter : public CPtred
{
public:
    int FUN_140226400(CStringW& strName, CStringW& strError);
};
class Unk_ClubFilterManager
{
public:
    MS2Ptr<Unk_ClubNameFilter> FUN_140229a50();
};
Unk_ClubFilterManager* FUN_14025e7d0();

// Feature flags (FUN_140166410 / FUN_14036d570) and the party manager (FUN_1409670d0).
class Unk_ClubFeatures
{
public:
    bool FUN_14036d570(int nFeature);
};
Unk_ClubFeatures* FUN_140166410();
CPartyManager* FUN_1409670d0();

// String helpers (string table lookups with arguments) and the chat/notice output.
CStringW GetStringCommon(int nId);
CStringW FUN_14052bd00(int nId, const CStringW& a);
CStringW FUN_140632a60(int nId, const CStringW& a, const CStringW& b);
CStringW FUN_1409eadb0(int nId, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_1409eec40(int nId);
CStringW FUN_1408116a0(int nId, const int& n);
void FUN_1412751b0(const CStringW& str, int nChannel);
void FUN_1412751f0(const CStringW& str, int a, int b);
void FUN_141275260(int nId, int a, int b);
bool FUN_14025cd60(const CStringW& a, const CStringW& b);
bool FUN_141b70f50(const CStringW& a, const CStringW& b);
int FUN_141276c80(const CStringW& strName, int nKind, CStringW& strError);
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
MS2Ptr<CClubMember> CClubCli::FUN_140b12850(__int64 nCharacterId)
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

// MS2-FUNCTIONAL: stack slot order of the locals and temporaries differs
// @0x140b12ad0
void CClubCli::FUN_140b12ad0(CInPacket& packet)
{
    int nResult = packet.vfunc_o8_3();
    CStringW strName = packet.vfunc_o8_8();
    if (nResult != 0)
    {
        FUN_140b18470(FUN_14020f1a0(), CStringW(strName), nResult);
    }
    else
    {
        FUN_14020f4e0(2);
        ATL::CAtlArray<MS2Ptr<CClubMember> > members;
        FUN_1402109d0(members);
        for (unsigned __int64 i = 0; i < members.GetCount(); i = i + 1)
        {
            MS2Ptr<CClubMember> spMember = members[i];
            if (!(spMember == 0))
                spMember->m_cc = 0;
        }
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
        FUN_1412751b0(FUN_14052bd00(0x344, FUN_14020f1a0()), 0xf);
    }
}

// MS2-FUNCTIONAL: stack slot order of the locals and temporaries differs
// @0x140b12d70
void CClubCli::FUN_140b12d70(CInPacket& packet)
{
    CStringW strActor = packet.vfunc_o8_8();
    CClubMember member;
    member.FUN_14020ea50(&packet);
    MS2Ptr<CClubMember> spMember = FUN_140210560(member.m_info.FUN_14020e5d0());
    if (!spMember)
    {
        spMember.AssignRaw(new CClubMember);
        spMember->FUN_14020e950(&member);
        vfunc_4(MS2Ptr<CClubMember>(spMember));
    }
    else
    {
        spMember->FUN_14020e950(&member);
    }
    if (spMember->m_c8 == 2)
    {
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
        FUN_1412751b0(FUN_1409eadb0(0x352, strActor, member.m_info.FUN_14020e5d0(), FUN_14020f1a0()), 0xf);
    }
}

// @0x140b13060
void CClubCli::FUN_140b13060(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
        FUN_1412751b0(FUN_140632a60(0x351, strName, FUN_14020f1a0()), 0xf);
    }
}

// @0x140b13200
void CClubCli::FUN_140b13200(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
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
        pDialog->FUN_140e0bc30();
    FUN_1412751b0(FUN_140632a60(0x353, FUN_14020f1a0(), strName), 0xf);
}

// @0x140b133c0
void CClubCli::FUN_140b133c0(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    __int64 nTime = packet.vfunc_o8_4();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
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
        pDialog->FUN_140e0bc30();
    FUN_1412751b0(FUN_140632a60(0x354, FUN_14020f1a0(), strName), 0xf);
}

// MS2-FUNCTIONAL: stack slot order of the locals and temporaries differs
// @0x140b135d0
void CClubCli::FUN_140b135d0(CInPacket& packet)
{
    CStringW strFirst = packet.vfunc_o8_8();
    CStringW strSecond = packet.vfunc_o8_8();
    unsigned nFlag = packet.vfunc_o8_1();
    MS2Ptr<CClubMember> spFirst = FUN_140210560(CStringW(strFirst));
    if (spFirst == 0)
        return;
    MS2Ptr<CClubMember> spSecond = FUN_140210560(CStringW(strSecond));
    if (!(spSecond == 0))
    {
        FUN_14020f720(spSecond->m_info.m_accountId, spSecond->m_info.m_characterId, spSecond->m_info.FUN_14020e5d0());
        m_leader = spSecond;
        bool bMe = FUN_141b70f50(strFirst, FUN_140b18ef0());
        if (!bMe)
        {
            FUN_1412751b0(FUN_140632a60(0x355, FUN_14020f1a0(), strSecond), 0xf);
        }
        else
        {
            UIClubDialog* pDialog = FUN_140b19090(0x4f25);
            if (pDialog != 0)
                pDialog->FUN_140e0bc30();
            if (nFlag == 0)
                FUN_1412751b0(FUN_14052bd00(0x356, FUN_14020f1a0()), 0xf);
        }
    }
}

// @0x140b13a20
void CClubCli::FUN_140b13a20(CInPacket& packet)
{
    int nBuffId = packet.vfunc_o8_3();
    int nBuffLevel = packet.vfunc_o8_3();
    FUN_14020f5b0(nBuffId, nBuffLevel);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
    FUN_1412751b0(FUN_14052bd00(0x357, FUN_14020f1a0()), 0xf);
}

// @0x140b13b50
void CClubCli::FUN_140b13b50(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
    if (spMember == 0)
        return;
    spMember->m_info.FUN_14020d5c0(packet);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b13c60
void CClubCli::FUN_140b13c60(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    CClubMemberProxy proxy;
    proxy.FUN_14020d640(&packet);
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
    if (spMember == 0)
        return;
    spMember->m_info.FUN_14020e130(proxy);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b13dc0
void CClubCli::FUN_140b13dc0(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
        FUN_1412751b0(FUN_14052bd00(0x351, strName), 0xf);
    }
}

// @0x140b13f20
void CClubCli::FUN_140b13f20(CInPacket& packet)
{
    CStringW strNewName = packet.vfunc_o8_8();
    CStringW strOldName = FUN_14020f1a0();
    __int64 nTime = packet.vfunc_o8_4();
    FUN_14020f230(strNewName);
    FUN_14020f3f0(nTime);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
    FUN_1412751b0(FUN_140632a60(0x358, strOldName, strNewName), 0xf);
}

// @0x140b14050
void CClubCli::FUN_140b14050(CInPacket& packet)
{
    CStringW strOldName = packet.vfunc_o8_8();
    CStringW strNewName = packet.vfunc_o8_8();
    FUN_1402107a0(strOldName, strNewName);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b14110
void CClubCli::FUN_140b14110(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubMember> spMember = FUN_140210560(CStringW(strName));
    if (spMember)
    {
        vfunc_5(CStringW(strName));
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
    }
}

// @0x140b14220
bool CClubCli::FUN_140b14220()
{
    return true;
}

// MS2-FUNCTIONAL: compare/branch layout of the limit checks differs
// @0x140b14230
bool CClubCli::FUN_140b14230(CStringW strName)
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return false;
    if (FUN_140211080(CStringW(strMe)) == 0)
        return false;
    CStringW strError;
    int nResult = FUN_141276c80(strName, 1, strError);
    if (nResult == 0)
    {
        int nCount = FUN_140210df0();
        if (nCount < (int)FUN_14020f380())
        {
            COutPacket pkt(0x95, 0);
            pkt.vfunc_o10_1(6);
            pkt.vfunc_o10_4(FUN_14020f0c0());
            pkt.vfunc_o10_8(strName);
            FUN_140710590(pkt);
            return true;
        }
        return false;
    }
    int nMessage;
    if (nResult == 10)
        nMessage = 0x349;
    else
        nMessage = 0x34a;
    FUN_141275260(nMessage, 1, 1);
    return false;
}

// @0x140b14480
void CClubCli::SendClubMode10()
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(10);
    pkt.vfunc_o10_4(FUN_14020f0c0());
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
    if (FUN_140211080(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x37b), 1, 1);
        return;
    }
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(0xc);
    pkt.vfunc_o10_4(FUN_14020f0c0());
    pkt.vfunc_o10_8(strName);
    FUN_140710590(pkt);
}

// MS2-FUNCTIONAL: compare/branch layout of the buff checks differs
// @0x140b146e0
void CClubCli::FUN_140b146e0(int nBuffId, int nBuffLevel)
{
    CStringW strMe = FUN_140b18ef0();
    if (strMe.IsEmpty())
        return;
    if (FUN_140211080(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x37b), 1, 1);
        return;
    }
    if (FUN_14020f640() == nBuffId && FUN_14020f6b0() == (unsigned)nBuffLevel)
        return;
    int bClear = 0;
    if (nBuffId == 0 && nBuffLevel == 0)
        bClear = 1;
    MS2Ptr<Unk_ClubBuffData> spBuff = FUN_140b1a4e0()->FUN_140211760(nBuffId, nBuffLevel);
    if (!(spBuff == 0) || bClear != 0)
    {
        COutPacket pkt(0x95, 0);
        pkt.vfunc_o10_1(0xd);
        pkt.vfunc_o10_4(FUN_14020f0c0());
        pkt.vfunc_o10_3(nBuffId);
        pkt.vfunc_o10_3(nBuffLevel);
        FUN_140710590(pkt);
    }
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
    if (FUN_140211080(CStringW(strMe)) == 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x37b), 1, 1);
        return;
    }
    if (m_name.CompareNoCase(strNewName) == 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x385), 1, 1);
        return;
    }
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(0xe);
    pkt.vfunc_o10_4(FUN_14020f0c0());
    pkt.vfunc_o10_8(strNewName);
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
void CClubClientManager::FUN_140b14c50()
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
int CClubClientManager::FUN_140b14cd0()
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
MS2Ptr<CClubCli> CClubClientManager::FUN_140b14d80(__int64 nClubId)
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
            if (spClub->FUN_14020f540() == 2)
                spResult->SetAt(nKey, spClub);
        }
    }
    return spResult;
}

// MS2-FUNCTIONAL: an extra local is allocated; frame is 0x10 bytes larger
// @0x140b14fc0
__int64 CClubClientManager::FUN_140b14fc0(CStringW strName)
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
            if (spClub.get() != 0 && spClub->FUN_14020f540() == 2 && FUN_14025cd60(spClub->FUN_14020f1a0(), strName))
            {
                nClubId = spClub->FUN_14020f0c0();
                break;
            }
        }
    }
    return nClubId;
}

// @0x140b15150
CStringW CClubClientManager::FUN_140b15150(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return CStringW(L"");
    return spClub->FUN_14020f1a0();
}

// @0x140b15210
int CClubClientManager::FUN_140b15210(__int64 nClubId)
{
    if (FUN_140b14d80(nClubId) == 0)
        return 0;
    return 1;
}

// @0x140b15290
int CClubClientManager::FUN_140b15290(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
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
                if (spClub->FUN_14020f540() == 2)
                    return 1;
            }
        }
    }
    return 0;
}

// @0x140b15440
void CClubClientManager::FUN_140b15440(MS2Ptr<CClubCli> spClub)
{
    if (spClub == 0)
        return;
    if (FUN_140b14cd0() == 1)
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
void CClubClientManager::FUN_140b15530(__int64 nClubId)
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
void CClubClientManager::FUN_140b155a0(MS2Ptr<Club::PacketInvite> spInvite)
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
void CClubClientManager::FUN_140b15640(__int64 nInviteId)
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
MS2Ptr<Club::PacketInvite> CClubClientManager::FUN_140b156b0(__int64 nInviteId)
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
MS2Ptr<CClubMember> CClubClientManager::FUN_140b15770(__int64 nClubId, __int64 nCharacterId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return MS2Ptr<CClubMember>(0);
    return spClub->FUN_140b12850(nCharacterId);
}

// @0x140b15830
int CClubClientManager::FUN_140b15830(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return 0;
    return spClub->FUN_140b129c0();
}

// @0x140b158c0
void CClubClientManager::OnClub(CInPacket& packet)
{
    if (!FUN_140166410()->FUN_14036d570(0x56))
        return;
    int nSubOpcode = packet.vfunc_o8_1();
    switch (nSubOpcode)
    {
    case 0:
        FUN_140b16520(packet);
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
        FUN_140b17d80(packet);
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
        FUN_140b18000(packet);
        break;
    case 0x1b:
        FUN_140b180a0(packet);
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

// MS2-FUNCTIONAL: branch layout of the create-club checks differs
// @0x140b15c10
bool CClubClientManager::FUN_140b15c10(CStringW strName)
{
    if (FUN_140b14cd0() == 1)
    {
        FUN_1412751f0(FUN_1408116a0(0x381, 3), 1, 1);
        return false;
    }
    int nMinLength = *FUN_1402056b0(&FUN_1401d3200()->m_nameMin);
    int nMaxLength = *FUN_1402056b0(&FUN_1401d3200()->m_nameMax);
    if (strName.GetLength() < nMinLength || nMaxLength < strName.GetLength())
        return false;
    if (strName.Find(L" ", 0) != -1)
    {
        FUN_141275260(0x386, 1, 1);
        return false;
    }
    if (!FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_141275260(0x36c, 1, 1);
        return false;
    }
    if (!FUN_1409670d0()->FUN_14162ab60())
    {
        FUN_141275260(0x36c, 1, 1);
        return false;
    }
    Unk_ClubNameFilter* pFilter = FUN_14025e7d0()->FUN_140229a50().get();
    if (pFilter != 0)
    {
        CStringW strError;
        if (pFilter->FUN_140226400(strName, strError) != 0)
        {
            FUN_1412751f0(strError, 1, 1);
            return false;
        }
    }
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(1);
    pkt.vfunc_o10_8(strName);
    FUN_140710590(pkt);
    return true;
}

// @0x140b15f40
void CClubClientManager::SendClubMode3(__int64 nClubId, int nCode)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    if (spClub->FUN_14020f540() != 1)
        return;
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(3);
    pkt.vfunc_o10_4(nClubId);
    pkt.vfunc_o10_3(nCode);
    FUN_140710590(pkt);
}

// @0x140b16030
bool CClubClientManager::FUN_140b16030(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return false;
    return spClub->FUN_140b14220();
}

// @0x140b160c0
bool CClubClientManager::FUN_140b160c0(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return false;
    return spClub->FUN_140b14230(CStringW(strName));
}

// @0x140b161a0
void CClubClientManager::SendClubMode8(__int64 nInviteId, int bAccept)
{
    MS2Ptr<Club::PacketInvite> spInvite = FUN_140b156b0(nInviteId);
    if (spInvite == 0)
        return;
    COutPacket pkt(0x95, 0);
    pkt.vfunc_o10_1(8);
    spInvite->FUN_14020c670(pkt);
    pkt.vfunc_o10_1(bAccept);
    FUN_140710590(pkt);
}

// @0x140b16270
void CClubClientManager::FUN_140b16270(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode10();
}

// @0x140b162f0
void CClubClientManager::FUN_140b162f0(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode12(CStringW(strName));
}

// @0x140b163c0
void CClubClientManager::FUN_140b163c0(__int64 nClubId, int nBuffId, int nLevel)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b146e0(nBuffId, nLevel);
}

// @0x140b16450
void CClubClientManager::FUN_140b16450(__int64 nClubId, CStringW strName)
{
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->SendClubMode14(CStringW(strName));
}

// @0x140b16520
void CClubClientManager::FUN_140b16520(CInPacket& packet)
{
    if (FUN_140b14cd0() == 1)
    {
        MS2_ASSERT_AT(0x317, 0);
        return;
    }
    MS2Ptr<CClubCli> spClub(new CClubCli);
    spClub->FUN_14020fd80(packet);
    FUN_140b15440(MS2Ptr<CClubCli>(spClub));
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b16650
void CClubClientManager::FUN_140b16650(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    CStringW strName = packet.vfunc_o8_8();
}

// MS2-FUNCTIONAL: temporary layout of the message box setup differs
// @0x140b166d0
void CClubClientManager::FUN_140b166d0(CInPacket& packet)
{
    MS2Ptr<CClubCli> spClub(new CClubCli);
    spClub->FUN_14020fd80(packet);
    FUN_140b15440(MS2Ptr<CClubCli>(spClub));
    if (!FUN_14025cd60(spClub->FUN_14020f8c0(), FUN_140b18ef0()))
    {
        Unk_MsgBoxPtr box = FUN_140b191a0(
            FUN_140632a60(0x345, spClub->FUN_14020f8c0(), spClub->FUN_14020f1a0()), 1,
            Delegate<bool(int, const CMsgBoxData&)>(this, &CClubClientManager::FUN_140b18390), spClub->FUN_14020f0c0());
        FUN_141a01ca0(box.operator->(), 0x14, 1, GetStringCommon(0x2b8));
        FUN_141a024a0(box.operator->(), false);
        FUN_140d73c60(box);
    }
    else
    {
        SendClubMode3(spClub->FUN_14020f0c0(), 0);
    }
}

// @0x140b16a70
void CClubClientManager::FUN_140b16a70(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    int nResult = packet.vfunc_o8_1();
    if (nResult != 0)
    {
        FUN_140b18700(4, nResult);
        return;
    }
    FUN_140b15530(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b16b20
void CClubClientManager::FUN_140b16b20(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    int nReason = packet.vfunc_o8_3();
    FUN_140b15530(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b16bc0
void CClubClientManager::FUN_140b16bc0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    FUN_1412751b0(FUN_140632a60(0x347, strName, spClub->FUN_14020f1a0()), 0x14);
}

// MS2-FUNCTIONAL: temporary layout of the invitation box setup differs
// @0x140b16d20
void CClubClientManager::FUN_140b16d20(CInPacket& packet)
{
    if (FUN_140b14cd0() == 1)
    {
        MS2_ASSERT_AT(0x389, 0);
        return;
    }
    MS2Ptr<Club::PacketInvite> spInvite(new Club::PacketInvite);
    spInvite->FUN_14020c720(packet);
    if (FUN_140b156b0(spInvite->m_inviteId).get() == 0)
    {
        FUN_140b155a0(MS2Ptr<Club::PacketInvite>(spInvite));
        CStringW strText = FUN_140632a60(0x348, spInvite->m_28, spInvite->m_20);
        Unk_MsgBoxPtr box = FUN_140d73d20(1, CStringW(strText), 0, CStringW(L""));
        if (box.get() != 0)
        {
            FUN_141a01ca0(box.operator->(), 0x14, 1, GetStringCommon(0x2b8));
            FUN_141a024a0(box.operator->(), false);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CClubClientManager::FUN_140b18400));
            FUN_1405340b0(box.operator->(), spInvite->m_inviteId);
            FUN_140d73c60(box);
        }
    }
    else
    {
        MS2_ASSERT_AT(0x392, 0);
    }
}

// @0x140b17150
void CClubClientManager::FUN_140b17150(CInPacket& packet)
{
    Club::PacketInvite invite;
    invite.FUN_14020c720(packet);
    int nResult = packet.vfunc_o8_3();
    FUN_140b15640(invite.m_inviteId);
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
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    CStringW strName = packet.vfunc_o8_8();
    int nType = packet.vfunc_o8_1();
    int nCode = packet.vfunc_o8_1();
    if (nType == 1)
    {
        UIClubDialog* pDialog = FUN_140b19090(0x4f25);
        if (pDialog != 0)
            pDialog->FUN_140e0bc30();
    }
    else
    {
        FUN_140b18580(spClub->FUN_14020f1a0(), CStringW(strName), nCode);
    }
}

// @0x140b173f0
void CClubClientManager::FUN_140b173f0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    FUN_140b15530(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
    FUN_1412751b0(FUN_14052bd00(0x350, spClub->FUN_14020f1a0()), 0xf);
}

// @0x140b17530
void CClubClientManager::FUN_140b17530(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    CStringW strName = packet.vfunc_o8_8();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
}

// @0x140b17600
void CClubClientManager::FUN_140b17600(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    int nBuffId = packet.vfunc_o8_3();
    int nBuffLevel = packet.vfunc_o8_3();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
}

// @0x140b176e0
void CClubClientManager::FUN_140b176e0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b12ad0(packet);
}

// @0x140b17780
void CClubClientManager::FUN_140b17780(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    CStringW strName = packet.vfunc_o8_8();
    int nCode = packet.vfunc_o8_3();
    if (nCode == 0xcf)
    {
        if (FUN_141b70f50(strName, FUN_140b18ef0()) == 1)
            FUN_1412751b0(FUN_14052bd00(0x346, spClub->FUN_14020f1a0()), 0xf);
        else
            FUN_1412751b0(FUN_14052bd00(0x346, spClub->FUN_14020f1a0()), 0xf);
    }
    FUN_140b15530(nClubId);
    UIClubDialog* pDialog = FUN_140b19090(0x4f25);
    if (pDialog != 0)
        pDialog->FUN_140e0bc30();
}

// @0x140b17a60
void CClubClientManager::FUN_140b17a60(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b12d70(packet);
}

// @0x140b17b00
void CClubClientManager::FUN_140b17b00(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13060(packet);
}

// @0x140b17ba0
void CClubClientManager::FUN_140b17ba0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13200(packet);
}

// @0x140b17c40
void CClubClientManager::FUN_140b17c40(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b133c0(packet);
}

// @0x140b17ce0
void CClubClientManager::FUN_140b17ce0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b135d0(packet);
}

// @0x140b17d80
void CClubClientManager::FUN_140b17d80(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13a20(packet);
}

// @0x140b17e20
void CClubClientManager::FUN_140b17e20(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13b50(packet);
}

// @0x140b17ec0
void CClubClientManager::FUN_140b17ec0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13c60(packet);
}

// @0x140b17f60
void CClubClientManager::FUN_140b17f60(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13dc0(packet);
}

// @0x140b18000
void CClubClientManager::FUN_140b18000(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b13f20(packet);
}

// @0x140b180a0
void CClubClientManager::FUN_140b180a0(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b14050(packet);
}

// @0x140b18140
void CClubClientManager::FUN_140b18140(CInPacket& packet)
{
    __int64 nClubId = packet.vfunc_o8_4();
    MS2Ptr<CClubCli> spClub = FUN_140b14d80(nClubId);
    if (spClub == 0)
        return;
    spClub->FUN_140b14110(packet);
}

// @0x140b181e0
void CClubClientManager::FUN_140b181e0(CInPacket& packet)
{
    int nKind = packet.vfunc_o8_1();
    int nCode = packet.vfunc_o8_3();
    FUN_140b18700(nKind, nCode);
}

// MS2-FUNCTIONAL: unused result slot of the first packet read is not reproduced
// @0x140b18260
void CClubClientManager::FUN_140b18260(CInPacket& packet)
{
    packet.vfunc_o8_4();
    CStringW strFirst = packet.vfunc_o8_8();
    CStringW strSecond = packet.vfunc_o8_8();
    Unk_ClubWorldObj* pObj = FUN_1403ed2d0()->FUN_141bd1420(CStringW(strFirst));
    if (pObj == 0)
    {
    }
    else
    {
    }
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
        strMessage = FUN_140632a60(0x36a, strName, strClub);
        break;
    default:
        strMessage = FUN_14052bd00(0x369, strClub);
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
        strMessage = FUN_140632a60(0x34f, strName, strClub);
        break;
    case 3:
        strMessage = FUN_140632a60(0x34e, strName, strClub);
        break;
    default:
        strMessage = FUN_140632a60(0x34d, strName, strClub);
        break;
    }
    FUN_1412751b0(strMessage, 0xf);
}

// MS2-FUNCTIONAL: switch value copy of the exe is not reproduced
// @0x140b18700
void FUN_140b18700(int nKind, int nCode)
{
    CStringW strMessage;
    switch (nCode - 1)
    {
    case 0:
        strMessage = GetStringCommon(0x368);
        break;
    default:
        strMessage = GetStringCommon(0x37e);
        break;
    case 10:
    case 0xb:
        strMessage = GetStringCommon(0x372);
        break;
    case 0xc:
        strMessage = GetStringCommon(0x375);
        break;
    case 0xd:
        strMessage = GetStringCommon(0x36b);
        break;
    case 0xe:
        strMessage = GetStringCommon(0x37d);
        break;
    case 0x32:
        strMessage = GetStringCommon(0x37b);
        break;
    case 0x33:
        strMessage = GetStringCommon(0x378);
        break;
    case 0x34:
        strMessage = GetStringCommon(0x379);
        break;
    case 0x35:
        strMessage = GetStringCommon(0x36f);
        break;
    case 0x36:
        strMessage = GetStringCommon(0x37c);
        break;
    case 0x38:
        strMessage = GetStringCommon(0x377);
        break;
    case 0x39:
        strMessage = GetStringCommon(0x382);
        break;
    case 0x3a:
        strMessage = GetStringCommon(0x387);
        break;
    case 0x3b:
        strMessage = GetStringCommon(0x373);
        break;
    case 0x3c:
        strMessage = GetStringCommon(0x374);
        break;
    case 0x3d:
        strMessage = GetStringCommon(0x376);
        break;
    case 0x3e:
        strMessage = GetStringCommon(0x36d);
        break;
    case 0x42:
        strMessage = GetStringCommon(899);
        break;
    case 0x47:
        strMessage = GetStringCommon(900);
        break;
    case 0x48:
        strMessage = GetStringCommon(0x385);
        break;
    case 0x49:
        strMessage = GetStringCommon(0x386);
    }
    FUN_1412751f0(strMessage, 1, 1);
}

// @0x140b18ef0
CStringW FUN_140b18ef0()
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return CStringW(L"");
    return pPlayer->vfunc_77();
}

// @0x140b1a4e0
Unk_ClubBuffTable* FUN_140b1a4e0()
{
    return DAT_143aac6f8;
}

// @0x140b19090
UIClubDialog* FUN_140b19090(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIClubDialog*>(spUI.operator->());
    }
    return 0;
}

// @0x140b19130
bool CMsgBoxData::FUN_140b19130(unsigned nIndex, __int64& nValue) const
{
    if (!(nIndex < FUN_14015a000(m_values)))
        return false;
    nValue = FUN_140718370(FUN_140164970(const_cast<Unk_MsgParamArray&>(m_values), nIndex));
    return true;
}

// @0x140b191a0
Unk_MsgBoxPtr FUN_140b191a0(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb, __int64 nUid)
{
    Unk_MsgBoxPtr box(new CMsgBoxData(nType));
    box->SetMsg(strText);
    box->FUN_141a027c0(cb);
    FUN_1405340b0(box.operator->(), nUid);
    FUN_14151f150(box);
    return box;
}
