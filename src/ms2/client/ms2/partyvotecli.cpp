// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Party vote objects: the kick vote (PartyVoteKickUserCli)
// and the ready check (PartyVoteReadyCli) over the base PartyVoteCli (ms2/placeholder/partyvotecli.h), plus the
// factory that CPartyManager uses to create them.
// MS2-UNIT: ?\partyvotecli.cpp
// MS2-RANGE: 0x1400c4b60-0x1400c4c50 .text$di
// MS2-RANGE: 0x140a89190-0x140a8af50 .text$mn
// MS2-RANGE: 0x142c9f930-0x142c9f980 .text$yd
// MS2-PIN: ?get@?$MS2Ptr@VPartyVoteCli@@@@QEBAPEAVPartyVoteCli@@XZ 0x140a8ab20
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140a8ab50
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140a8ae20
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VPartyVoteCli@@@@AEBAXPEAX@Z 0x140a8acd0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140a8ae80 ; unique
// MS2-PIN: ??$Call@VPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVPartyVoteReadyCli@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140a8aec0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1PartyVoteCli@@UEAA@XZ 0x140a8aa00
// MS2-PIN: ??1PartyVoteKickUserCli@@UEAA@XZ 0x140a8aa50
// MS2-PIN: ??1PartyVoteReadyCli@@UEAA@XZ 0x140a8aa80
// MS2-PIN: ??_GPartyVoteCli@@UEAAPEAXI@Z 0x140a8ab90
// MS2-PIN: ??_GPartyVoteKickUserCli@@UEAAPEAXI@Z 0x140a8abd0
// MS2-PIN: ??_GPartyVoteReadyCli@@UEAAPEAXI@Z 0x140a8ac10
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\partyvotecli.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "partyvotecli.h"

#include "ms2/client/ms2/partymanager.h"
#include "ms2/fmt/format.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/partyuidialogs.h"
#include "ms2/placeholder/uiobject.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/os.h"

// ---- statics (.text$di) ----
// The first initializer is the sort-type name table of header_statics_a.h without the skill/stun strings that follow it
// there; the second is the ready-check popup tag.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strReadyPopup("System_PartyReady_Popup_01");

// ---- unit-local placeholders ----

extern template class MS2Ptr<CMsgBoxData>;
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;
extern template class MS2Ptr<UIObject>;

void FUN_140d73c60(Unk_MsgBoxPtr box);
Unk_MsgBoxPtr CreateMessageBoxWithCallback(CStringW strText, int nType, Unk_MsgBoxCallback cb);

// The game constants: the ready-check length in seconds.
class Unk_PartyConsts
{
public:
    char m_pad_0[0xe608];
    int m_nReadySeconds;                                           // +0xe608
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)

extern __int64 DAT_143ab2828;                                      // my character id
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
__int64 GetServerTime();                                           // server time
CStringW FormatMinutesSeconds(const ATL::CTimeSpan& span);                // "mm:ss" text
CStringW GetStringCommon(int nId);
CStringW FUN_140298ea0(CStringW strKey);
void FUN_1412751b0(const CStringW& str, int nChannel);
void ShowSystemNotice(const CStringW& str, int a, int b);
int FUN_141276180(const CString& a, const CString& b);
void FUN_140710590(COutPacket& packet);

#include "ms2/placeholder/wcformat.h"  // FUN_14028dfa0 and its wrappers

CInputStream& FUN_140a8a230(CInputStream& in, std::set<unsigned __int64>& ids);
void* FindPartyDialog(int nUiId);
void* FUN_140a8a720();

// The dialog ids: GetPartyDialogId is the party dialog id.
// @0x140a8ac50
inline int GetPartyDialogId() { return 0x4e45; }

// ---- PartyVoteCli ----

// @0x140a89190
PartyVoteCli::PartyVoteCli() : id(0), kind(0), owner(0), expires(0) {}

// @0x140a89240
MS2Ptr<PartyVoteCli> CreateVote(int kind)
{
    MS2Ptr<PartyVoteCli> vote;
    switch (kind)
    {
    case 1:
        vote.AssignRaw(new PartyVoteKickUserCli);
        break;
    case 2:
        vote.AssignRaw(new PartyVoteReadyCli);
        break;
    }
    if (vote.get() != 0)
        vote->kind = kind;
    return vote;
}

// @0x140a89380
void PartyVoteCli::vfunc_1(CInPacket& packet)
{
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read6(reinterpret_cast<unsigned&>(id));
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read8(reinterpret_cast<unsigned __int64&>(expires));
    FUN_140a8a230(packet, participants);
    FUN_140a8a230(packet, yes);
    FUN_140a8a230(packet, no);
}

// @0x140a89420
void PartyVoteCli::vfunc_2() {}

// @0x140a89430
void PartyVoteCli::vfunc_3() {}

// @0x140a89440
CStringW PartyVoteCli::vfunc_4() { return CStringW(L""); }

// @0x140a89490
unsigned char PartyVoteCli::vfunc_5() { return 0; }

// @0x140a894a0
void PartyVoteCli::vfunc_6(unsigned __int64) {}

// @0x140a894c0
int PartyVoteCli::GetKind() const { return kind; }

// @0x140a894e0
void PartyVoteCli::AddVote(unsigned __int64 member, bool accepted)
{
    if (accepted)
        yes.insert(member);
    else
        no.insert(member);
    vfunc_7(member, accepted);
}

// @0x140a89560
size_t PartyVoteCli::GetYesCount() { return yes.size(); }

// @0x140a89590
size_t PartyVoteCli::GetNoCount() { return no.size(); }

// @0x140a895c0
bool PartyVoteCli::HasVoted()
{
    // the sets are unsigned; the exe passes &DAT_143ab2828 straight to find (no converted temporary)
    if (yes.find(reinterpret_cast<const unsigned __int64&>(DAT_143ab2828)) != yes.end())
        return true;
    if (no.find(reinterpret_cast<const unsigned __int64&>(DAT_143ab2828)) != no.end())
        return true;
    return false;
}

// @0x140a89680
void PartyVoteCli::SendParty(bool vote)
{
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.WriteUInt8(0x30);
    packet.WriteInt32(id);
    packet.WriteBool(vote);
    FUN_140710590(packet);
}

// @0x140a89700
void PartyVoteCli::vfunc_7(__int64, bool) {}

// @0x140a89720
CStringW PartyVoteCli::GetRemainingTimeText() const
{
    CMsTime end(expires);
    CMsTime now(GetServerTime());
    if (end < now)
        end = now;
    ATL::CTimeSpan span = end - now;
    return FormatMinutesSeconds(span);
}

// ---- PartyVoteKickUserCli ----

// @0x140a897c0
PartyVoteKickUserCli::PartyVoteKickUserCli() : target(0), reason(0) {}

// @0x140a89820
void PartyVoteKickUserCli::vfunc_1(CInPacket& packet)
{
    PartyVoteCli::vfunc_1(packet);
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read7(owner);
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read7(target);
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read11(name);
    reinterpret_cast<Unk_OSInput&>(static_cast<CInputStream&>(packet)).Read1(reason);
}

// @0x140a898b0
void PartyVoteKickUserCli::vfunc_2()
{
    CStringW strName;
    MS2Ptr<CPartyMember> member = TSingleton<CPartyManager>::GetInstance()->FindMemberByCharId(owner);
    if (member.get() != 0)
        strName = member->GetName();
    FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_party_vote_kick_user_notify"), strName), 2);
    void* pDialog = FindPartyDialog(0x4e45);
    if (pDialog != 0)
    {
        reinterpret_cast<UIPartyDialog*>(pDialog)->FUN_141a759b0();
        reinterpret_cast<UIPartyDialog*>(pDialog)->ArrangeBottomButton();
    }
}

// @0x140a89a00
CStringW PartyVoteKickUserCli::vfunc_4()
{
    return FUN_14028dfa0(L"s_party_vote_title_kick_user", name, reason, GetRemainingTimeText());
}

// @0x140a89ae0
unsigned char PartyVoteKickUserCli::vfunc_5() { return 1; }

// ---- PartyVoteReadyCli ----

// @0x140a89af0
PartyVoteReadyCli::PartyVoteReadyCli() {}

// @0x140a89b30
void PartyVoteReadyCli::vfunc_2()
{
    std::set<unsigned __int64>& all = participants;
    for (std::set<unsigned __int64>::const_iterator itEnd = all.end(), it = all.begin(); it != itEnd; ++it)
    {
        unsigned __int64 member = *it;
        if (yes.find(member) != yes.end())
            TSingleton<CPartyManager>::GetInstance()->SetMemberReadyState(member, 2);
        else if (no.find(member) != no.end())
            TSingleton<CPartyManager>::GetInstance()->SetMemberReadyState(member, 3);
        else
            TSingleton<CPartyManager>::GetInstance()->SetMemberReadyState(member, 1);
    }

    void* pDialog = FUN_140a8a720();
    if (pDialog != 0)
        reinterpret_cast<UIPartyDialog*>(pDialog)->SetDeadline(0);
    FUN_1412751b0(FUN_140298ea0(CStringW(L"s_party_vote_ready_message")), 2);
    {
        CString strEmpty("");
        FUN_141276180(s_strReadyPopup, strEmpty);
    }
    if (!HasVoted())
    {
        Unk_MsgBoxPtr box = CreateMessageBoxWithCallback(FUN_140298ea0(CStringW(L"s_party_vote_ready_message")), 1,
                                          Unk_MsgBoxCallback(this, &PartyVoteReadyCli::OnMessageBoxResult));
        ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->SetTimer(0x14, 1, GetStringCommon(0x2b8));
        ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->FUN_141a02460(1);
        ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->SetModaless(1);
        ((class CMsgBoxData*)(class CMsgBoxData*)(box.operator->()))->FUN_141a024a0(0);
        FUN_140d73c60(box);
    }
}

// @0x140a89f70
void PartyVoteReadyCli::vfunc_3()
{
    ShowSystemNotice(FUN_140298ea0(CStringW(L"s_party_vote_ready_message_end")), 1, 1);
    TSingleton<CPartyManager>::GetInstance()->FUN_14162c3a0();
    void* pDialog = FUN_140a8a720();
    if (pDialog != 0)
        reinterpret_cast<UIPartyDialog*>(pDialog)->SetDeadline((int)GetTickCountMs2() + ((class Unk_PartyConsts*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_nReadySeconds * 1000);
}

// @0x140a8a040
void PartyVoteReadyCli::vfunc_6(unsigned __int64 member)
{
    PartyVoteCli::vfunc_6(member);
    participants.erase(member);
    yes.erase(member);
    no.erase(member);
}

// @0x140a8a0b0
bool PartyVoteReadyCli::OnMessageBoxResult(int result, const CMsgBoxData& box)
{
    if (result == 0)
        SendParty(true);
    else if (box.GetTimer().m_nButton == 0)
        SendParty(false);
    return true;
}

// @0x140a8a100
void PartyVoteReadyCli::vfunc_7(__int64 member, bool accepted)
{
    if (accepted)
        TSingleton<CPartyManager>::GetInstance()->SetMemberReadyState(member, 2);
    else
        TSingleton<CPartyManager>::GetInstance()->SetMemberReadyState(member, 3);
}

// ---- helpers ----

// Reads a count followed by that many ids into the set.
// @0x140a8a230
CInputStream& FUN_140a8a230(CInputStream& in, std::set<unsigned __int64>& ids)
{
    unsigned count = in.ReadInt32();
    for (unsigned i = 0; i < count; ++i)
    {
        unsigned __int64 member;
        reinterpret_cast<Unk_OSInput&>(in).Read7(reinterpret_cast<__int64&>(member));
        ids.insert(member);
    }
    return in;
}

// @0x140a8a680
void* FindPartyDialog(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spUI = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIPartyDialog*>(spUI.operator->());
    }
    return 0;
}

// @0x140a8a720
void* FUN_140a8a720()
{
    CUIService* pManager = TSingleton<CUIService>::GetInstance();
    if (pManager == 0)
        return 0;
    MS2Ptr<UIObject> spUI = pManager->FindObject((eUIClassID)GetPartyDialogId());
    if (spUI.IsNull())
        return 0;
    return dynamic_cast<UIPartyDialog*>(spUI.operator->());
}

MS2_REPLACE_METHOD(0x140A89380, PartyVoteCli, vfunc_1, 149, 0xE53851CF);
MS2_REPLACE_METHOD(0x140A894C0, PartyVoteCli, GetKind, 14, 0x8AEE455B);
MS2_REPLACE_METHOD(0x140A894E0, PartyVoteCli, AddVote, 116, 0x3FCDCE36);
MS2_REPLACE_METHOD(0x140A89560, PartyVoteCli, GetYesCount, 31, 0x46B95FC3);
MS2_REPLACE_METHOD(0x140A89590, PartyVoteCli, GetNoCount, 31, 0xD8882F4A);
MS2_REPLACE_METHOD(0x140A895C0, PartyVoteCli, HasVoted, 176, 0xCA3DA8AC);
MS2_REPLACE_METHOD(0x140A89680, PartyVoteCli, SendParty, 112, 0xAA2B2CE1);
MS2_REPLACE_METHOD(0x140A89720, PartyVoteCli, GetRemainingTimeText, 152, 0x6206D5F9);
MS2_REPLACE_METHOD(0x140A89820, PartyVoteKickUserCli, vfunc_1, 138, 0xFF14D4C5);
MS2_REPLACE_METHOD(0x140A898B0, PartyVoteKickUserCli, vfunc_2, 320, 0x37927C83);
MS2_REPLACE_METHOD(0x140A89F70, PartyVoteReadyCli, vfunc_3, 194, 0x7D9A2807);
MS2_REPLACE_METHOD(0x140A8A040, PartyVoteReadyCli, vfunc_6, 100, 0x7070D226);
MS2_REPLACE_METHOD(0x140A8A0B0, PartyVoteReadyCli, OnMessageBoxResult, 74, 0x70360213);
MS2_REPLACE_METHOD(0x140A8A100, PartyVoteReadyCli, vfunc_7, 83, 0x567FCC8A);
MS2_REPLACE(0x140A8A230, FUN_140a8a230, 111, 0xE8E39513);
MS2_REPLACE(0x140A8A680, FindPartyDialog, 147, 0xC0BB06FA);
MS2_REPLACE(0x140A8A720, FUN_140a8a720, 172, 0x154A3F4C);
