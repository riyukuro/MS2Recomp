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

// ---- statics (.text$di) ----
// The first initializer is the sort-type name table of header_statics_a.h without the skill/stun strings that follow it
// there; the second is the ready-check popup tag.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strReadyPopup("System_PartyReady_Popup_01");

// ---- unit-local placeholders ----

// The message box record; only the callback registration and the result accessor are used here (see clubcli.cpp).
struct Unk_PartyMsgResult
{
    char m_pad_00[0x18];
    int m_nButton;                                                 // +0x18
};
class CMsgBoxData : public CPtred
{
public:
    const Unk_PartyMsgResult& FUN_141a04a80() const;               // the pressed-button record (+0xa0)

    char m_pad_18[0x2a0 - 0x18];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
extern template class MS2Ptr<CMsgBoxData>;
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;
extern template class MS2Ptr<UIObject>;

void FUN_141a01ca0(CMsgBoxData* pBox, int a, int b, const CStringW& str);
void FUN_141a02460(CMsgBoxData* pBox, int n);
void FUN_141a02480(CMsgBoxData* pBox, int n);
void FUN_141a024a0(CMsgBoxData* pBox, int n);
void FUN_140d73c60(Unk_MsgBoxPtr box);
Unk_MsgBoxPtr FUN_140d74500(CStringW strText, int nType, Unk_MsgBoxCallback cb);

// UI manager and the lookup of a dialog by its id (the party dialog is 0x4e45).
class Unk_PartyUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);
};
Unk_PartyUIManager* FUN_1403ed2b0();

// The game constants: the ready-check length in seconds.
class Unk_PartyConsts
{
public:
    char m_pad_0[0xe608];
    int m_nReadySeconds;                                           // +0xe608
};
Unk_PartyConsts* FUN_1401d3200();

extern __int64 DAT_143ab2828;                                      // my character id
unsigned FUN_140869420();                                          // tick count
__int64 FUN_140869440();                                           // server time
CStringW FUN_140b8fbc0(const ATL::CTimeSpan& span);                // "mm:ss" text
CPartyManager* FUN_1409670d0();
CStringW FUN_14028de60(int nId);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void FUN_1412751b0(const CStringW& str, int nChannel);
void FUN_1412751f0(const CStringW& str, int a, int b);
void FUN_141276180(const CString& a, const CString& b);
void FUN_140710590(COutPacket& packet);
void FUN_141a759b0(void* pDialog);
void FUN_141a75a20(void* pDialog);
void FUN_141a75a00(void* pDialog, int nValue);
CInputStream& FUN_14070f340(CInputStream& in, unsigned char& v);
CInputStream& FUN_14070f480(CInputStream& in, int& v);
CInputStream& FUN_14070f4c0(CInputStream& in, __int64& v);
CInputStream& FUN_14070f500(CInputStream& in, __int64& v);
CInputStream& FUN_14070f5f0(CInputStream& in, CStringW& v);

// The localized-string formatter: FUN_14028dfa0(key, args) is the non-variadic back end (invented name; see
// uiworldchampionrewarddialog.cpp). This formatter does not share fmt's BasicFormatter<wchar_t> instantiations, so the
// unit-local formatter class Unk_WcFormatter (same Char) gives its MakeValue / ArgType copies their own names.
CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(wc_make_type(arg)) {}
};
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
WC_WRAP(3)

CInputStream& FUN_140a8a230(CInputStream& in, std::set<unsigned __int64>& ids);
void* FUN_140a8a680(int nUiId);
void* FUN_140a8a720();

// The dialog ids: FUN_140a8ac50 is the party dialog id.
// @0x140a8ac50
inline int FUN_140a8ac50() { return 0x4e45; }

// ---- PartyVoteCli ----

// @0x140a89190
PartyVoteCli::PartyVoteCli() : id(0), kind(0), owner(0), expires(0) {}

// @0x140a89240
// MS2-FUNCTIONAL: MSVC emits a switch for the kind if/else-if chain; no spelling found that keeps the compare chain
MS2Ptr<PartyVoteCli> FUN_140a89240(int kind)
{
    MS2Ptr<PartyVoteCli> vote;
    if (kind == 1)
        vote.AssignRaw(new PartyVoteKickUserCli);
    else if (kind == 2)
        vote.AssignRaw(new PartyVoteReadyCli);
    if (vote.get() != 0)
        vote->kind = kind;
    return vote;
}

// @0x140a89380
void PartyVoteCli::vfunc_1(CInPacket& packet)
{
    FUN_14070f480(packet, id);
    FUN_14070f500(packet, expires);
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
int PartyVoteCli::FUN_140a894c0() const { return kind; }

// @0x140a894e0
void PartyVoteCli::FUN_140a894e0(unsigned __int64 member, bool accepted)
{
    if (accepted)
        yes.insert(member);
    else
        no.insert(member);
    vfunc_7(member, accepted);
}

// @0x140a89560
size_t PartyVoteCli::FUN_140a89560() { return yes.size(); }

// @0x140a89590
size_t PartyVoteCli::FUN_140a89590() { return no.size(); }

// @0x140a895c0
bool PartyVoteCli::FUN_140a895c0()
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
    COutPacket packet(0x2c, 0);
    packet.vfunc_o10_1(0x30);
    packet.vfunc_o10_3(id);
    packet.vfunc_o10_0(vote);
    FUN_140710590(packet);
}

// @0x140a89700
void PartyVoteCli::vfunc_7(__int64, bool) {}

// @0x140a89720
CStringW PartyVoteCli::FUN_140a89720() const
{
    CMsTime end(expires);
    CMsTime now(FUN_140869440());
    if (end < now)
        end = now;
    ATL::CTimeSpan span = end - now;
    return FUN_140b8fbc0(span);
}

// ---- PartyVoteKickUserCli ----

// @0x140a897c0
PartyVoteKickUserCli::PartyVoteKickUserCli() : target(0), reason(0) {}

// @0x140a89820
void PartyVoteKickUserCli::vfunc_1(CInPacket& packet)
{
    PartyVoteCli::vfunc_1(packet);
    FUN_14070f4c0(packet, owner);
    FUN_14070f4c0(packet, target);
    FUN_14070f5f0(packet, name);
    FUN_14070f340(packet, reason);
}

// @0x140a898b0
void PartyVoteKickUserCli::vfunc_2()
{
    CStringW strName;
    MS2Ptr<CPartyMember> member = FUN_1409670d0()->FUN_14162afc0(owner);
    if (member.get() != 0)
        strName = member->FUN_141637bd0();
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_party_vote_kick_user_notify"), strName), 2);
    void* pDialog = FUN_140a8a680(0x4e45);
    if (pDialog != 0)
    {
        FUN_141a759b0(pDialog);
        FUN_141a75a20(pDialog);
    }
}

// @0x140a89a00
// MS2-FUNCTIONAL: formatter by-value temp layout differs (extra 16-byte local), behaviour identical
CStringW PartyVoteKickUserCli::vfunc_4()
{
    CStringW strRemain = FUN_140a89720();
    return FUN_14028dfa0(L"s_party_vote_title_kick_user", name, reason, strRemain);
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
            FUN_1409670d0()->FUN_14162c580(member, 2);
        else if (no.find(member) != no.end())
            FUN_1409670d0()->FUN_14162c580(member, 3);
        else
            FUN_1409670d0()->FUN_14162c580(member, 1);
    }

    void* pDialog = FUN_140a8a720();
    if (pDialog != 0)
        FUN_141a75a00(pDialog, 0);
    FUN_1412751b0(FUN_140298ea0(CStringW(L"s_party_vote_ready_message")), 2);
    {
        CString strEmpty("");
        FUN_141276180(s_strReadyPopup, strEmpty);
    }
    if (!FUN_140a895c0())
    {
        Unk_MsgBoxPtr box = FUN_140d74500(FUN_140298ea0(CStringW(L"s_party_vote_ready_message")), 1,
                                          Unk_MsgBoxCallback(this, &PartyVoteReadyCli::FUN_140a8a0b0));
        FUN_141a01ca0(box.operator->(), 0x14, 1, FUN_14028de60(0x2b8));
        FUN_141a02460(box.operator->(), 1);
        FUN_141a02480(box.operator->(), 1);
        FUN_141a024a0(box.operator->(), 0);
        FUN_140d73c60(box);
    }
}

// @0x140a89f70
void PartyVoteReadyCli::vfunc_3()
{
    FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_vote_ready_message_end")), 1, 1);
    FUN_1409670d0()->FUN_14162c3a0();
    void* pDialog = FUN_140a8a720();
    if (pDialog != 0)
        FUN_141a75a00(pDialog, (int)FUN_140869420() + FUN_1401d3200()->m_nReadySeconds * 1000);
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
bool PartyVoteReadyCli::FUN_140a8a0b0(int result, const CMsgBoxData& box)
{
    if (result == 0)
        SendParty(true);
    else if (box.FUN_141a04a80().m_nButton == 0)
        SendParty(false);
    return true;
}

// @0x140a8a100
void PartyVoteReadyCli::vfunc_7(__int64 member, bool accepted)
{
    if (accepted)
        FUN_1409670d0()->FUN_14162c580(member, 2);
    else
        FUN_1409670d0()->FUN_14162c580(member, 3);
}

// ---- helpers ----

// Reads a count followed by that many ids into the set.
// @0x140a8a230
CInputStream& FUN_140a8a230(CInputStream& in, std::set<unsigned __int64>& ids)
{
    unsigned count = in.vfunc_o8_3();
    for (unsigned i = 0; i < count; ++i)
    {
        unsigned __int64 member;
        FUN_14070f4c0(in, reinterpret_cast<__int64&>(member));
        ids.insert(member);
    }
    return in;
}

// @0x140a8a680
void* FUN_140a8a680(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIPartyDialog*>(spUI.operator->());
    }
    return 0;
}

// @0x140a8a720
void* FUN_140a8a720()
{
    Unk_PartyUIManager* pManager = FUN_1403ed2b0();
    if (pManager == 0)
        return 0;
    MS2Ptr<UIObject> spUI = pManager->FUN_141adcea0(FUN_140a8ac50());
    if (spUI.IsNull())
        return 0;
    return dynamic_cast<UIPartyDialog*>(spUI.operator->());
}

MS2_REPLACE_METHOD(0x140A89380, PartyVoteCli, vfunc_1, 149, 0xE53851CF);
MS2_REPLACE_METHOD(0x140A894C0, PartyVoteCli, FUN_140a894c0, 14, 0x8AEE455B);
MS2_REPLACE_METHOD(0x140A894E0, PartyVoteCli, FUN_140a894e0, 116, 0x3FCDCE36);
MS2_REPLACE_METHOD(0x140A89560, PartyVoteCli, FUN_140a89560, 31, 0x46B95FC3);
MS2_REPLACE_METHOD(0x140A89590, PartyVoteCli, FUN_140a89590, 31, 0xD8882F4A);
MS2_REPLACE_METHOD(0x140A895C0, PartyVoteCli, FUN_140a895c0, 176, 0xCA3DA8AC);
MS2_REPLACE_METHOD(0x140A89680, PartyVoteCli, SendParty, 112, 0xAA2B2CE1);
MS2_REPLACE_METHOD(0x140A89720, PartyVoteCli, FUN_140a89720, 152, 0x6206D5F9);
MS2_REPLACE_METHOD(0x140A89820, PartyVoteKickUserCli, vfunc_1, 138, 0xFF14D4C5);
MS2_REPLACE_METHOD(0x140A898B0, PartyVoteKickUserCli, vfunc_2, 320, 0x37927C83);
MS2_REPLACE_METHOD(0x140A89F70, PartyVoteReadyCli, vfunc_3, 194, 0x7D9A2807);
MS2_REPLACE_METHOD(0x140A8A040, PartyVoteReadyCli, vfunc_6, 100, 0x7070D226);
MS2_REPLACE_METHOD(0x140A8A0B0, PartyVoteReadyCli, FUN_140a8a0b0, 74, 0x70360213);
MS2_REPLACE_METHOD(0x140A8A100, PartyVoteReadyCli, vfunc_7, 83, 0x567FCC8A);
MS2_REPLACE(0x140A8A230, FUN_140a8a230, 111, 0xE8E39513);
MS2_REPLACE(0x140A8A680, FUN_140a8a680, 147, 0xC0BB06FA);
MS2_REPLACE(0x140A8A720, FUN_140a8a720, 172, 0x154A3F4C);
