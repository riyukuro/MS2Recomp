// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WeddingManager: the client wedding flow (packet 0xba
// handlers, request senders, message box callbacks). Field/helper names are inferred; the v2525 reference decomp
// (work/ext/v2525, ms2/tu/141b834b0.cpp) gave the structure.
// MS2-UNIT: ?\weddingmanager.cpp
// MS2-RANGE: 0x141b835d0-0x141b90cd0 .text$mn
// MS2-RANGE: 0x14011fc20-0x14011fe40 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x14011fce0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x14011fd10 ; probe
// MS2-PIN: ??__Es_systemFieldWar@@YAXXZ 0x14011fdb0 ; probe
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141b8e3d0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141b90410 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141b90940 ; unique
// MS2-PIN: ??$Call@VWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141b90980 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVWeddingManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141b909b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_unk1401cd100@@YAXXZ 0x14011fd40
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\weddingmanager.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <utility>

#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/weddingpackage.h"
#include "ms2/placeholder/stateweddingemotion.h"
#include "ms2/placeholder/sidepopuptalkparam.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiweddinghalllistdialog.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/memorydepletiondlg.h"
#include "ms2/client/ms2/groundeffectdata.h"
#include "ms2/commonfiles/commonstruct_wc.h"
#include "ms2/ms2format.h"

#include "ms2/ms2recover.h"
#pragma intrinsic(abs)
#include "hook/ms2hook.h"

// ---- unit statics (.text$di): the per-TU handle, the shared header statics (header_statics_a.h) and the field war string ----
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };   // ctor 0x1401cd100
static Unk_1401cd100 s_unk1401cd100(NULL);
static CStringA s_systemFieldWar("System_FieldWar");
static CErrorNotificationDlg s_errorNotificationDlg(NULL);
static CMemoryDepletionDlg s_memoryDepletionDlg(NULL);

enum Unk_WmResultCode : int {};            // takes the formatter's custom-argument path (MakeValue<enum>)
// fmt's ostream formatting of a custom argument with the MS2 enum shortcut in front (same shape as itembreakmanager.cpp
// 0x140534820): the stream branch is dead code for enums.
// @0x141b8e030
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_WmResultCode& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_WmResultCode>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
class Unk_WsB_Notice : public CPtred { public: char m_pad[1]; };   // unit-local; only held through MS2Ptr

class Unk_WeddingMail : public CPtred
{
public:
    CStringW FUN_141b8ecc0() const { return m_strPath; }       // inline (COMDAT emitted in this range)
    unsigned char m_pad_18[0x50];
    CStringW m_strPath;                                         // +0x68 the mail's xml body path
};
MS2_CHECK_OFFSET(Unk_WeddingMail, m_strPath, 0x68);
class Unk_WmFiles { public: int FUN_140397ab0(TiXmlDocument* pDoc, const CStringW& strPath); };
Unk_WmFiles* FUN_140166420();
void* FUN_140165cf0(void*, const char*);
void* FUN_140166410();                                          // the feature manager
bool FUN_14036d570(void* pFeatures, int nId);                   // feature enabled
class Unk_WmDialog94 { public: void FUN_140fcd5b0(CInPacket& packet); };
Unk_WmDialog94* FUN_140fe6700(int nId);
class Unk_WmDialog8c { public: void FUN_140fc7f30(); };
Unk_WmDialog8c* FUN_1418764c0(int nId);
class Unk_WmDialog57 { public: void FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam); };
Unk_WmDialog57* FUN_1413868b0(int nId);
void FUN_140d73ff0(CStringW text);                              // screen notice
void FUN_14151f200();                                           // close the open modal box
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);   // confirm box
bool FUN_14092f660();                                           // in the wedding hall
bool FUN_140900550();                                           // may send a wedding request
__int64 FUN_140869440();                                        // server time
int FUN_140900f00();                                            // max invitations
WeddingTable* FUN_1409023c0();
void FUN_140908f90(WeddingTable* pTable, __int64 nHallId);
int FUN_140900d40();                                            // the propose item id
CStringW FUN_141b71910(unsigned __int64 n);                     // u64 -> text
unsigned __int64 FUN_140718370(const CStringW& str);            // text -> u64
CStringW FUN_140298ea0(CStringW key);                           // system string
bool FUN_140900f30(__int64 nTime);                              // is night time
CStringW FUN_140b8e850(const CMsTime& time);                    // formatted date
CStringW FUN_1409404f0(__int64 n);                              // formatted number
unsigned __int64 FUN_141656a80(void* pUser);                    // character id of a user object
int FUN_141658e60(void* pUser);                                 // gender
int FUN_1406c75c0(void* pUser);                                 // level
bool FUN_1409005c0(unsigned char nGenderA, unsigned char nGenderB);
int FUN_140a5f180(char* pInventory, int nItemId, int nA);       // count of an item
int FUN_1401cc5f0(CPtred* pBuddy);                              // buddy accepted
class Unk_WmBuddyMgr { public: MS2Ptr<CPtred> FUN_140ae4880(unsigned __int64 nId); };
Unk_WmBuddyMgr* FUN_14097a780();
WeddingManager* FUN_1409eed90();
void FUN_140873420(void* pNode, const char* pName, CStringW* pOut);
void FUN_1408732e0(void* pNode, const char* pName, __int64* pOut);
void FUN_1408731e0(void* pNode, const char* pName, int* pOut);
void FUN_1408730a0(void* pNode, const char* pName, bool* pOut);
void FUN_14166d2d0(PCBase* pUser, const efd::Point3& pos, int n);   // face towards a position
int FUN_14166ce30(void* pUser);                                 // busy
int FUN_141659690(void* pUser);                                 // in a dungeon
int FUN_141527160(void* pUser, int nBuffId);                    // has a buff
class Unk_WmField { public: int FUN_1410d2f10(); bool FUN_1410c35c0(); };
class Unk_WmFieldHolder { public: void* FUN_1401cd040(); };
extern Unk_WmFieldHolder DAT_143b059e8;
class Unk_WmFieldRef
{
public:
    Unk_WmFieldRef(void* p);                                    // 0x1401cd0b0
    ~Unk_WmFieldRef();                                          // 0x1401cd150
    Unk_WmField* FUN_140885310() const;                         // get
    Unk_WmField* FUN_1401cd1a0() const;                         // operator->
    void* m_00;
    void* m_08;
};
extern unsigned __int64 DAT_143ab2828;                          // the local character id
extern char DAT_143ab2a90;                                      // the player inventory
class Unk_LockUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_LockUIManager* FUN_1403ed2b0();
void FUN_141adc5d0(Unk_LockUIManager* pUI, int nId);            // close a dialog
bool FUN_141924630(UIWeddingHallListDialog* pDialog);           // dialog is open
CStringW FUN_14028de60(int nStringId);                          // string table text by id
CStringW FUN_14052bd00(int nStringId, CStringW arg);            // formatted string by id
void FUN_1412751b0(const CStringW& text, int nKind);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
CStringW FUN_14028b8e0(const CStringW& str);
template <class T> T* Unk_WmDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}
WorldService* FUN_1403ed2d0();

// ---- the message strings and the empty ticket ----
static const WeddingHallTicket& Unk_EmptyTicket()
{
    static WeddingHallTicket s_empty;
    return s_empty;
}

// @0x141b835d0
WeddingManager::WeddingManager()
    : m_nStep(0), m_nStepMax(3), m_bTicketsDirty(false)
{
}

// @0x141b836b0
WeddingManager::~WeddingManager()
{
}

// @0x141b83750
void WeddingManager::OnPacket(CInPacket& packet)
{
    if (!FUN_14036d570(FUN_140166410(), 0x104))
        return;
    unsigned char mode = packet.vfunc_o8_1();
    switch (mode) {
    case 0x00: OnProxy(packet); break;
    case 0x01: OnTicketList(packet); break;
    case 0x02: OnResult(packet); break;
    case 0x03: OnPropose(packet); break;
    case 0x06: OnProposeAccepted(packet); break;
    case 0x08: OnDivorceRequest(packet); break;
    case 0x0d: OnReservationRequest(packet); break;
    case 0x0f: OnReserveOk(packet); break;
    case 0x10: OnReservationCancelRequest(packet); break;
    case 0x11: OnReservationChangeRequest(packet); break;
    case 0x13: OnReserveCancelOk(packet); break;
    case 0x14: OnMode14(packet); break;
    case 0x16: OnMode16(packet); break;
    case 0x17: OnInvitationClear(packet); break;
    case 0x18: OnInvitationTicket(packet); break;
    case 0x19: OnInvitationRemove(packet); break;
    case 0x1b: OnHallList(packet); break;
    case 0x1d: OnInvitationOk(packet); break;
    case 0x1e: OnMode1e(packet); break;
    case 0x1f: OnMode1f(packet); break;
    case 0x23: OnMode23(packet); break;
    case 0x27: OnMode27(packet); break;
    }
}

// @0x141b83a20
void WeddingManager::OnProxy(CInPacket& packet)
{
    m_proxy.Read(packet);
}

// @0x141b83a50
void WeddingManager::OnTicketList(CInPacket& packet)
{
    m_ticket.Read(packet);
    m_invited.clear();
    int count = packet.vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        unsigned __int64 first = packet.vfunc_o8_4();
        unsigned __int64 second = packet.vfunc_o8_4();
        m_invited.insert(std::make_pair(first, second));
    }
}

// @0x141b842b0
void WeddingManager::OnProposeAccepted(CInPacket& packet)
{
    FUN_14151f200();
    m_proxy.Read(packet);
    PlayEmotion(3);
    FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_wedding_propose_ok"), GetPartnerName()), 0x14);
}

// @0x141b84920
void WeddingManager::OnInvitationTicket(CInPacket& packet)
{
    if (FUN_1403ed2d0()->FUN_141bd3060() != 62000000 && FUN_14092f660())
        return;
    WeddingHallTicket ticket;
    unsigned __int64 id = packet.vfunc_o8_4();
    ticket.Read(packet);
    if (m_tickets.find(id) != m_tickets.end())
        m_tickets.erase(id);
    m_tickets.insert(std::make_pair(id, ticket));
    m_bTicketsDirty = true;
}

// @0x141b84ac0
void WeddingManager::OnInvitationRemove(CInPacket& packet)
{
    unsigned __int64 id = packet.vfunc_o8_4();
    m_tickets.erase(id);
    UIWeddingHallListDialog* dialog = Unk_WmDialog<UIWeddingHallListDialog>(0x4f96);
    if (dialog && FUN_141924630(dialog))
        dialog->FUN_140fd90f0(true);
}

// @0x141b84b50
void WeddingManager::OnInvitationClear(CInPacket& packet)
{
    m_tickets.clear();
}

// @0x141b84b80
void WeddingManager::OnHallList(CInPacket& packet)
{
    Unk_WmDialog94* dialog = FUN_140fe6700(0x4f94);
    if (dialog)
        dialog->FUN_140fcd5b0(packet);
}

// @0x141b84bc0
void WeddingManager::OnInvitationOk(CInPacket& packet)
{
    FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_wedding_invitation_ok")), 8, 1);
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4f8e);
}

// @0x141b84c60
void WeddingManager::OnReservationCancelRequest(CInPacket& packet)
{
    CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_hall_reservation_cancel_request"), GetPartnerName());
    FUN_140d74390(message, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnReservationCancelAnswer));
}

// @0x141b85060
void WeddingManager::OnReserveCancelOk(CInPacket& packet)
{
    m_ticket.Reset();
    FUN_1412751b0(FUN_14028b8e0(CStringW(L"s_wedding_hall_reserve_cancel_ok")), 0x14);
}

// @0x141b85710
void WeddingManager::OnDivorceRequest(CInPacket& packet)
{
    CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_divorce_mutual_msgbox"), GetPartnerName());
    FUN_140d74390(message, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnDivorceAnswer));
}

// @0x141b85850
void WeddingManager::OnMode23(CInPacket& packet)
{
    Unk_WmDialog8c* dialog = FUN_1418764c0(0x4f8c);
    dialog->FUN_140fc7f30();
}

// @0x141b85890
void WeddingManager::OnMode27(CInPacket& packet)
{
    int result = packet.vfunc_o8_1();
    bool accepted = result == 2;
    if (accepted)
        OnMode27Accept(packet);
    else
        PlayEmotion(result);
}

// @0x141b85920
void WeddingManager::OnMode1e(CInPacket& packet)
{
    int result = packet.vfunc_o8_1();
    switch (result) {
    case 1:
    case 2:
        ShowStepResult(result);
        break;
    case 3:
        m_nStep = 0;
        m_strPartner = packet.vfunc_o8_8();
        ShowStep();
        break;
    }
}

// @0x141b85a20
void WeddingManager::OnMode1f(CInPacket& packet)
{
    int result = packet.vfunc_o8_1();
    // 0x141b85a68: an unreachable jmp precedes the first case body (a statement before the first case label).
    switch (result) {
        break;
    case 3:
        m_nStep = m_nStepMax + 1;
        break;
    }
    FUN_14151f200();
}

// @0x141b86520
void WeddingManager::SendReservationCancel()
{
    int error = m_proxy.CheckReservation(m_ticket, DAT_143ab2828);
    if (error != 0) {
        ShowError(error);
    } else {
        COutPacket packet(0xba, 0);
        packet.Encode1(0x10);
        FUN_140710590(packet);
    }
}

// @0x141b86750
void WeddingManager::SendInvitation(unsigned __int64 id)
{
    if (!FUN_140900550()) {
        ShowError(0x12);
    } else {
        COutPacket packet(0xba, 0);
        packet.Encode1(0x1a);
        packet.Encode8(id);
        FUN_140710590(packet);
    }
}

// @0x141b87160
const WeddingHallTicket& WeddingManager::GetTicket()
{
    if (m_ticket.m_nTime != 0 && m_ticket.m_nTime < FUN_140869440())
        return Unk_EmptyTicket();
    return m_ticket;
}

// @0x141b89030
void WeddingManager::RefreshTicketsIfDirty()
{
    if (m_bTicketsDirty) {
        m_bTicketsDirty = false;
        RefreshTickets();
    }
}

// @0x141b89860
int WeddingManager::CanInvite(unsigned __int64 first, unsigned __int64 second, int count)
{
    int total = count + (int)m_invited.size();
    if (total > FUN_140900f00())
        return 0x33;
    if (m_invited.find(std::make_pair(first, second)) != m_invited.end())
        return 0x28;
    return 0;
}

// @0x141b89920
int WeddingManager::GetInvitedCount()
{
    return (int)m_invited.size();
}

// @0x141b89950
void WeddingManager::ApplyHallTicket()
{
    __int64 hallId = m_proxy.m_n18;
    FUN_140908f90(FUN_1409023c0(), hallId);
}

// @0x141b899d0
void WeddingManager::ApplyPartner()
{
    Unk_WeddingPartner* member = m_proxy.GetSelf(DAT_143ab2828);
    member->IsOnline();
}

// @0x141b89d00
bool WeddingManager::OnReservationAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(0xe);
    int answer;
    if (result == 0)
        answer = 7;
    else
        answer = 8;
    packet.Encode2(answer);
    FUN_140710590(packet);
    return true;
}

// @0x141b89d90
bool WeddingManager::OnReservationCancelAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(0x12);
    int answer;
    if (result == 0)
        answer = 9;
    else
        answer = 10;
    packet.Encode2(answer);
    FUN_140710590(packet);
    return true;
}

// @0x141b89f40
bool WeddingManager::OnDivorceAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(9);
    int answer;
    if (result == 0)
        answer = 0xd;
    else
        answer = 0xe;
    packet.Encode2(answer);
    FUN_140710590(packet);
    return true;
}

// @0x141b8a2f0
bool WeddingManager::OnStepNext(int result, const CMsgBoxData& box)
{
    m_nStep++;
    if (m_nStep == m_nStepMax)
        ShowLastStep();
    else
        ShowStep();
    return true;
}

// @0x141b8a670
CStringW WeddingManager::GetPartnerName()
{
    return m_proxy.GetSelf(DAT_143ab2828)->m_strName;
}

#define WM_CHAT(key) FUN_1412751f0(FUN_14028b8e0(L##key), 1, 1)
#define WM_CHAT_NAME(key) FUN_1412751f0(FUN_14028dfa0(CStringW(L##key), m_strTarget), 1, 1)

// @0x141b87760
void WeddingManager::ShowError(int code)
{
    switch (code) {
    case 0x13: WM_CHAT("s_wedding_result_err_wedding_block_age_to"); break;
    case 0x14: WM_CHAT("s_wedding_result_err_wedding_block_age_from"); break;
    case 0x15: WM_CHAT("s_wedding_result_err_wedding_block_gender"); break;
    case 0x16: WM_CHAT_NAME("s_wedding_result_err_not_buddy"); break;
    case 0x17: WM_CHAT_NAME("s_wedding_result_err_propose_state_to"); break;
    case 0x18: WM_CHAT_NAME("s_wedding_result_err_marriage_state_to"); break;
    case 0x19: WM_CHAT("s_wedding_result_err_coolingoff_state_to"); break;
    case 0x1a: WM_CHAT("s_wedding_result_err_prpose_cooltime_state_to"); break;
    case 0x1b: WM_CHAT("s_wedding_result_err_propose_state_from"); break;
    case 0x1c: WM_CHAT("s_wedding_result_err_mareriage_state_from"); break;
    case 0x1d: WM_CHAT("s_wedding_result_err_coolingoff_state_from"); break;
    case 0x1e: WM_CHAT("s_wedding_result_err_propose_cooltime_state_from"); break;
    case 0x1f:
        FUN_1412751f0(FUN_14028dfa0(CStringW(L"s_wedding_result_err_not_find_propose_item"),
            CStringTable::GetInstance()->FUN_141811980(1, FUN_140900d40())), 1, 1);
        break;
    case 0x20: WM_CHAT("s_wedding_result_err_propose_distance"); break;
    case 0x22: WM_CHAT("s_wedding_result_err_same_field"); break;
    case 0x21: WM_CHAT("s_wedding_result_err_already_propose_request"); break;
    case 0x23: WM_CHAT("s_wedding_result_err_only_promise_user"); break;
    case 0x24: WM_CHAT("s_wedding_result_err_invalid_wedding_hall"); break;
    case 0x25: WM_CHAT("s_wedding_result_err_lack_merat"); break;
    case 0x26: WM_CHAT("s_wedding_result_err_maintenance_time"); break;
    case 0x38: WM_CHAT("s_wedding_visit_failed_common"); break;
    case 0x39: WM_CHAT("s_wedding_visit_failed_disablemap"); break;
    case 0x3a: WM_CHAT("s_wedding_visit_failed_dead"); break;
    case 0x3b: WM_CHAT("s_wedding_visit_failed_same_place"); break;
    case 0x3c: WM_CHAT("s_wedding_visit_failed_solo_instance"); break;
    case 0x3d: WM_CHAT("s_wedding_visit_failed_invalid_time"); break;
    case 0x27: WM_CHAT("s_wedding_result_not_find_weddinghall"); break;
    case 0x28: WM_CHAT("s_wedding_result_already_send_invitation"); break;
    case 0x29: WM_CHAT("s_wedding_result_late_promise_time"); break;
    case 0x2a: WM_CHAT("s_wedding_result_late_wedding_reserve_modify"); break;
    case 0x2b: WM_CHAT("s_wedding_result_already_reservation"); break;
    case 0x2c: WM_CHAT("s_wedding_result_already_same_reservation"); break;
    case 0x2d: WM_CHAT("s_wedding_result_invaild_state_divorce"); break;
    case 0x2e: WM_CHAT("s_wedding_result_lack_marriage_date"); break;
    case 0x2f: WM_CHAT("s_wedding_result_lack_meso_divorce"); break;
    case 0x30: WM_CHAT("s_wedding_result_late_divorce_agree"); break;
    case 0x31: WM_CHAT("s_wedding_result_invalid_divorce_agree_user"); break;
    case 0x32: WM_CHAT("s_wedding_result_only_marriage_user"); break;
    case 0x33: WM_CHAT("s_wedding_result_wedding_invitation_count"); break;
    case 0x34: WM_CHAT("s_wedding_result_lack_meso_invitation"); break;
    case 0x35: WM_CHAT("s_wedding_result_early_remind_wedding"); break;
    case 0x36: WM_CHAT("s_wedding_result_early_wedding_reserve"); break;
    case 0x37: WM_CHAT("s_wedding_result_divorcecancel"); break;
    case 0x3e: WM_CHAT("s_wedding_result_only_booking_character"); break;
    case 0x3f: WM_CHAT("s_wedding_result_already_weddinghall_reserve"); break;
    case 0x40: WM_CHAT("s_wedding_result_lack_coupon"); break;
    default:
        FUN_1412751f0(FUN_14028dfa0(CStringW(L"s_wedding_result_err_system"), reinterpret_cast<const Unk_WmResultCode&>(code)), 1, 1);
    }
}

// @0x141b83b80
void WeddingManager::OnResult(CInPacket& packet)
{
    int result = packet.vfunc_o8_1();
    if (result >= 0x12) {
        ShowError(result);
        return;
    }
    switch (result) {
    case 3: ShowProposeAnswer(m_strTarget); break;
    case 2: WM_CHAT_NAME("s_wedding_result_decline_propose"); break;
    case 4: WM_CHAT("s_wedding_result_cancel_propose_to"); break;
    case 5: WM_CHAT_NAME("s_wedding_result_cancel_propose_from"); break;
    case 6: WM_CHAT("s_wedding_result_cancel_propose_expire"); break;
    case 0xf: FUN_140d73ff0(CStringW(L"s_wedding_result_send_wedding_hall_reservation")); break;
    case 0x10: FUN_140d73ff0(CStringW(L"s_wedding_result_send_wedding_hall_reservation_change")); break;
    case 0x11: FUN_140d73ff0(CStringW(L"s_wedding_result_send_wedding_hall_reservation_cancel")); break;
    }
    switch (result) {
    case 1:
    case 2:
    case 5:
    case 6:
        PlayEmotion(3);
        FUN_14151f200();
        break;
    }
}

// @0x141b83f90
void WeddingManager::OnPropose(CInPacket& packet)
{
    unsigned __int64 id = packet.vfunc_o8_4();
    CStringW name = packet.vfunc_o8_8();
    m_strTarget = name;
    CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_msg_box_propose_from"), name);
    MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, message, 0, CStringW(L""));
    if (box.get()) {
        box->FUN_141a01ca0(0x14, 1, FUN_14028de60(0x2b8));
        box->FUN_141a024a0(0);
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnProposeAnswer));
        box->FUN_140b76940(FUN_141b71910(id));
        FUN_140d73c60(box);
    }
}

// @0x141b84da0
void WeddingManager::OnReservationChangeRequest(CInPacket& packet)
{
    CStringW message;
    int reason = packet.vfunc_o8_2();
    switch (reason) {
    case 10:
        message = FUN_14028dfa0(CStringW(L"s_wedding_hall_reservation_cancel_no_refund_decline"), GetPartnerName());
        break;
    case 0x22:
        message = FUN_14028dfa0(CStringW(L"s_wedding_hall_reservation_cancel_no_refund_not_find_partner"), GetPartnerName());
        break;
    default:
        return;
    }
    FUN_14151f200();
    FUN_140d74390(message, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnNoRefundAnswer));
}

// @0x141b85aa0
void WeddingManager::ShowStep()
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (user) {
        CStringW name = GetPartnerName();
        if (name.IsEmpty())
            name = m_strPartner;
        CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_enter_nickname"), name);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0xe, message, 0, CStringW(L""));
        if (box.get()) {
            {
                CStringW blank(L"");
                box->FUN_141a01d30(2, blank, 0, 0, 0);
            }
            box->FUN_141a024e0(FUN_140298ea0(CStringW(L"s_wedding_enter_nickname_confirm_checkbox")), 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnNicknameAnswer));
            FUN_140d73c60(box);
        }
    }
}

// @0x141b85db0
void WeddingManager::ShowLastStep()
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (user) {
        CStringW name = GetPartnerName();
        if (name.IsEmpty())
            name = m_strPartner;
        CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_enter_nickname_confirm_final"), name);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0, message, 0, CStringW(L""));
        if (box.get()) {
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnLastStepAnswer));
            FUN_140d73c60(box);
        }
    }
}

// @0x141b85fe0
void WeddingManager::ShowStepResult(int result)
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (user) {
        CStringW message;
        switch (result) {
        case 1:
            message = FUN_140298ea0(CStringW(L"s_wedding_mutual_agree_start_acting"));
            break;
        case 2:
            message = FUN_140298ea0(CStringW(L"s_wedding_mutual_agree_end_acting"));
            break;
        default:
            return;
        }
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, message, 0, CStringW(L""));
        if (box.get()) {
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnActingAnswer));
            box->FUN_140534050(result);
            FUN_140d73c60(box);
        }
    }
}

// @0x141b86e20
void WeddingManager::ShowProposeAnswer(const CStringW& name)
{
    void* user = FUN_1403ed2d0()->FUN_141bd1420(name);
    if (!user)
        return;
    {
        PlayEmotion(1);
        CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_msg_box_propose_to"), m_strTarget);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0, message, 0, CStringW(L""));
        if (box.get()) {
            box->FUN_141a01ca0(0x14, 1, FUN_14028de60(0x2b8));
            box->FUN_141a01800(4);
            box->FUN_141a024a0(0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnProposeSentAnswer));
            box->FUN_140b76940(FUN_141b71910(FUN_141656a80(user)));
            FUN_140d73c60(box);
        }
    }
}

// @0x141b89ac0
bool WeddingManager::OnProposeSentAnswer(int result, const CMsgBoxData& box)
{
    PlayEmotion(3);
    if (box.FUN_141a04a80().m_nButton != 0)
        return true;
    unsigned __int64 id = FUN_140718370(box.FUN_141a02fd0(0, CStringW()));
    COutPacket packet(0xba, 0);
    packet.Encode1(5);
    packet.Encode8(id);
    FUN_140710590(packet);
    return true;
}

// @0x141b89bd0
bool WeddingManager::OnProposeAnswer(int result, const CMsgBoxData& box)
{
    unsigned __int64 id = FUN_140718370(box.FUN_141a02fd0(0, CStringW()));
    int answer = result == 0 ? 1 : 2;
    if (box.FUN_141a04a80().m_nButton != 0)
        answer = 6;
    COutPacket packet(0xba, 0);
    packet.Encode1(4);
    packet.Encode2(answer);
    packet.Encode8(id);
    FUN_140710590(packet);
    return true;
}

// @0x141b89e20
bool WeddingManager::OnNoRefundAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(0x11);
    int answer;
    if (result == 0)
        answer = 9;
    else
        answer = 10;
    packet.Encode2(answer);
    FUN_140710590(packet);
    return true;
}

// @0x141b89eb0
bool WeddingManager::OnReservationChangeAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(0x15);
    int answer;
    if (result == 0)
        answer = 0xb;
    else
        answer = 0xc;
    packet.Encode2(answer);
    FUN_140710590(packet);
    return true;
}

// @0x141b89fd0
bool WeddingManager::OnNicknameAnswer(int result, const CMsgBoxData& box)
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return true;
    CStringW name = GetPartnerName();
    if (name.IsEmpty())
        name = m_strPartner;
    CStringW text = box.FUN_141a02d50();
    text.Trim(L',');
    if (text.Compare(name) == 0) {
        COutPacket packet(0xba, 0);
        packet.Encode1(0x1e);
        packet.Encode1(3);
        packet.vfunc_o10_0(true);
        FUN_140710590(packet);
        return true;
    }
    CStringW message = FUN_140298ea0(CStringW(L"s_wedding_enter_nickname_error"));
    {
        MS2Ptr<CMsgBoxData> retry = FUN_140d73d20(0, message, 0, CStringW(L""));
        if (retry.get()) {
            retry->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnStepNext));
            FUN_140d73c60(retry);
        }
    }
    return true;
}

// @0x141b8a360
bool WeddingManager::OnLastStepAnswer(int result, const CMsgBoxData& box)
{
    COutPacket packet(0xba, 0);
    packet.Encode1(0x1e);
    packet.Encode1(3);
    packet.vfunc_o10_0(true);
    FUN_140710590(packet);
    return true;
}

// @0x141b8a3e0
bool WeddingManager::OnActingAnswer(int result, const CMsgBoxData& box)
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return false;
    COutPacket packet(0xba, 0);
    int type = box.FUN_141a02e50(0, 0);
    bool accept = result == 0 ? true : false;
    packet.Encode1(0x1e);
    packet.Encode1(type);
    packet.vfunc_o10_0(accept);
    FUN_140710590(packet);
    return true;
}

// The +0x18.. members of SidePopupTalkParam this unit writes (the shared placeholder only spells out part of it).
struct Unk_WmSidePopupView : public CPtred
{
    int m_nKind;                                            // +0x18
    char m_pad_1c[0x50 - 0x1c];
    int m_nDuration;                                        // +0x50
    int m_pad_54;
    CStringA m_str58;                                       // +0x58
    CStringA m_strSender;                                   // +0x60
    char m_pad_68[0x10];
    CStringA m_str78;                                       // +0x78
    CStringW m_str80;                                       // +0x80
    ATL::CAtlMap<CStringA, CStringW, ATL::CStringElementTraits<CStringA> > m_vars;   // +0x88
};
MS2_CHECK_OFFSET(Unk_WmSidePopupView, m_vars, 0x88);

static int Unk_FieldId(MS2Ptr<WeddingHallData>& hall, bool bNight)
{
    return bNight ? hall->m_nNightFieldId : hall->m_nFieldId;
}

// @0x141b843a0
void WeddingManager::OnReservationRequest(CInPacket& packet)
{
    WeddingHallTicket ticket;
    ticket.Read(packet);
    MS2Ptr<WeddingPackage> package = FUN_1409023c0()->FUN_140908b80(ticket.m_nPackageId);
    if (package.get() == 0)
        return;
    MS2Ptr<WeddingHallData> hall = package->FUN_140907110(ticket.m_nHallId);
    if (hall.get() == 0)
        return;
    CStringW hallName = CStringTable::GetInstance()->FUN_141811980(3, Unk_FieldId(hall, FUN_140900f30(ticket.m_nTime)));
    CStringW date = FUN_140b8e850(CMsTime(ticket.m_nTime));
    CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_reservation_request_messagebox"),
        m_proxy.m_groom.m_strName, m_proxy.m_bride.m_strName, hallName, date, hall->m_nMerat);
    FUN_140d74390(message, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnReservationAnswer));
}

// @0x141b846f0
void WeddingManager::OnReserveOk(CInPacket& packet)
{
    m_ticket.Read(packet);
    MS2Ptr<WeddingPackage> package = FUN_1409023c0()->FUN_140908b80(m_ticket.m_nPackageId);
    if (package.get() == 0)
        return;
    MS2Ptr<WeddingHallData> hall = package->FUN_140907110(m_ticket.m_nHallId);
    if (hall.get() == 0)
        return;
    CStringW hallName = CStringTable::GetInstance()->FUN_141811980(3, Unk_FieldId(hall, FUN_140900f30(m_ticket.m_nTime)));
    CStringW date = FUN_140b8e850(CMsTime(m_ticket.m_nTime));
    FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_wedding_hall_reserve_ok"), hallName, date, hall->m_nMerat), 0x14);
}

// @0x141b850f0
void WeddingManager::OnMode14(CInPacket& packet)
{
    WeddingHallTicket ticket;
    ticket.Read(packet);
    __int64 cost = packet.vfunc_o8_4();
    MS2Ptr<WeddingPackage> package = FUN_1409023c0()->FUN_140908b80(ticket.m_nPackageId);
    if (package.get() == 0)
        return;
    MS2Ptr<WeddingHallData> hall = package->FUN_140907110(ticket.m_nHallId);
    if (hall.get() == 0)
        return;
    CStringW hallName = CStringTable::GetInstance()->FUN_141811980(3, Unk_FieldId(hall, FUN_140900f30(ticket.m_nTime)));
    CStringW date = FUN_140b8e850(CMsTime(ticket.m_nTime));
    CStringW price = FUN_14052bd00(0x987, FUN_1409404f0(cost));
    CStringW message = FUN_14028dfa0(CStringW(L"s_wedding_reservation_change_request_messagebox"),
        m_proxy.m_groom.m_strName, m_proxy.m_bride.m_strName, hallName, date, price);
    FUN_140d74390(message, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &WeddingManager::OnReservationChangeAnswer));
}

// @0x141b854c0
void WeddingManager::OnMode16(CInPacket& packet)
{
    m_ticket.Read(packet);
    __int64 cost = packet.vfunc_o8_4();
    MS2Ptr<WeddingPackage> package = FUN_1409023c0()->FUN_140908b80(m_ticket.m_nPackageId);
    if (package.get() == 0)
        return;
    MS2Ptr<WeddingHallData> hall = package->FUN_140907110(m_ticket.m_nHallId);
    if (hall.get() == 0)
        return;
    CStringW hallName = CStringTable::GetInstance()->FUN_141811980(3, Unk_FieldId(hall, m_ticket.m_nTime != 0));
    CStringW date = FUN_140b8e850(CMsTime(m_ticket.m_nTime));
    FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_wedding_hall_reserve_change_ok"), hallName, date, cost), 0x14);
}

// @0x141b896f0
void WeddingManager::CollectTickets(std::map<unsigned __int64, WeddingHallTicket>& out)
{
    std::map<unsigned __int64, WeddingHallTicket>::iterator it = m_tickets.begin();
    std::map<unsigned __int64, WeddingHallTicket>::iterator end = m_tickets.end();
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return;
    __int64 now = FUN_140869440();
    for (; it != end; ++it) {
        if (FUN_1406c75c0(user) < 50) {
            int diff = (int)(now - it->second.m_nTime);
            if (abs(diff) > 1800)
                continue;
        }
        WeddingHallTicket ticket;
        ticket.Assign(it->second);
        out[it->first] = ticket;
    }
}

// @0x141b89070
void WeddingManager::RefreshTickets()
{
    std::map<unsigned __int64, WeddingHallTicket> tickets;
    CollectTickets(tickets);
    if (tickets.size() == 0)
        return;
    MS2Ptr<SidePopupTalkParam> param(new SidePopupTalkParam);
    Unk_WmSidePopupView* view = reinterpret_cast<Unk_WmSidePopupView*>(param.get());
    view->m_nKind = 5;
    view->m_nDuration = 30000;
    view->m_strSender = s_systemFieldWar;
    if (tickets.size() == 1) {
        unsigned __int64 id = tickets.begin()->first;
        WeddingHallTicket& ticket = tickets.begin()->second;
        MS2Ptr<WeddingPackage> package = FUN_1409023c0()->FUN_140908b80(ticket.m_nPackageId);
        if (package.get() == 0)
            return;
        MS2Ptr<WeddingHallData> hall = package->FUN_140907110(ticket.m_nHallId);
        if (hall.get() == 0)
            return;
        CStringW date = FUN_140b8e850(CMsTime(ticket.m_nTime));
        CMsTime start(ticket.m_nTime);
        start += ATL::CTimeSpan(0, 0, 15, 0);
        int fieldId = Unk_FieldId(hall, FUN_140900f30(ticket.m_nTime));
        view->m_str78 = StringFormat("{0}", start.GetTime());
        view->m_str80 = FUN_141b71910(id);
        view->m_vars.SetAt("groom", ticket.m_strGroom);
        view->m_vars.SetAt("bride", ticket.m_strBride);
        view->m_vars.SetAt("hall", CStringTable::GetInstance()->FUN_141811980(3, fieldId));
        view->m_vars.SetAt("date", date);
        view->m_vars.SetAt("npc", hall->m_strIllust);
        int type = 1;
        view->m_vars.SetAt("weddingType", StringFormat(L"{0}", type));
    } else {
        view->m_vars.SetAt("npc", L"Chloris");
        int type = 2;
        view->m_vars.SetAt("weddingType", StringFormat(L"{0}", type));
    }
    Unk_WmDialog57* dialog = FUN_1413868b0(0x4f57);
    if (dialog)
        dialog->FUN_140e879a0(param);
}

// @0x141b862d0
void WeddingManager::SendPropose(const CStringW& name)
{
    if (!FUN_140900550()) {
        ShowError(0x12);
    } else {
        m_strTarget = name;
        void* target = FUN_1403ed2d0()->FUN_141bd1420(name);
        if (!target) {
            ShowError(0x22);
        } else {
            int error = CheckPropose(FUN_141656a80(target));
            if (error != 0) {
                ShowError(error);
            } else {
                COutPacket packet(0xba, 0);
                packet.Encode1(3);
                packet.vfunc_o10_8(name);
                FUN_140710590(packet);
            }
        }
    }
}

// @0x141b86420
void WeddingManager::SendReservation(int packageId, int hallId, __int64 time, unsigned char night, bool agree)
{
    WeddingHallTicket ticket;
    ticket.m_nPackageId = packageId;
    ticket.m_nHallId = hallId;
    ticket.m_nTime = time;
    ticket.m_bPublic = night != 0;
    COutPacket packet(0xba, 0);
    packet.Encode1(0xd);
    ticket.Write(packet);
    packet.vfunc_o10_0(agree);
    FUN_140710590(packet);
}

// @0x141b865c0
void WeddingManager::SendReservationChange(int packageId, int hallId, __int64 time, unsigned char night)
{
    if (!FUN_140900550()) {
        ShowError(0x12);
    } else if (!IsPartnerOnline()) {
        ShowError(0x22);
    } else {
        WeddingHallTicket ticket;
        ticket.m_nPackageId = packageId;
        ticket.m_nHallId = hallId;
        ticket.m_nTime = time;
        ticket.m_bPublic = night != 0;
        int error = m_proxy.CheckReservationChange(m_ticket, ticket, DAT_143ab2828);
        if (error != 0) {
            ShowError(error);
            return;
        }
        COutPacket packet(0xba, 0);
        packet.Encode1(0x14);
        ticket.Write(packet);
        FUN_140710590(packet);
    }
}

// @0x141b87220
int WeddingManager::CheckPropose(unsigned __int64 id)
{
    if (!FUN_140900550())
        return 0x12;
    void* target = FUN_1403ed2d0()->FUN_141bd1530(id);
    if (!target)
        return 0x22;
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return 0x12;
    if (!FUN_1409005c0(FUN_141658e60(user), FUN_141658e60(target)))
        return 0x15;
    if (FUN_140a5f180(&DAT_143ab2a90, FUN_140900d40(), 0) == 0)
        return 0x1f;
    MS2Ptr<CPtred> buddy = FUN_14097a780()->FUN_140ae4880(id);
    if (buddy.get() == 0)
        return 0x16;
    if (FUN_1401cc5f0(buddy.get()) == 0)
        return 0x16;
    int error = m_proxy.CheckPropose();
    if (error != 0)
        return error;
    return 0;
}

// @0x141b89a10
bool WeddingManager::CanVisit(int packageId, int hallId, __int64 id)
{
    if (!FUN_140900550()) {
        ShowError(0x12);
        return false;
    }
    if (!IsPartnerOnline()) {
        ShowError(0x22);
        return false;
    }
    int error = m_proxy.CheckVisit(const_cast<WeddingHallTicket&>(FUN_1409eed90()->GetTicket()), id);
    if (error != 0) {
        ShowError(error);
        return false;
    }
    return true;
}

// @0x141b8a580
bool WeddingManager::IsPartnerOnline()
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return false;
    unsigned __int64 partnerId = m_proxy.GetSelf(FUN_141656a80(user))->m_nCharacterId;
    if (FUN_1403ed2d0()->FUN_141bd1530(partnerId))
        return true;
    if (FUN_1403ed2d0()->FUN_141bc9c60((void*)partnerId).get() != 0)
        return true;
    return false;
}

// @0x141b873c0
void WeddingManager::ReadTicketMail(MS2Ptr<Unk_WeddingMail> mail, AScript* script)
{
    TiXmlDocument doc;
    WeddingHallTicket ticket;
    int loaded = FUN_140166420()->FUN_140397ab0(&doc, mail->FUN_141b8ecc0());
    if (loaded) {
        void* root = FUN_140165cf0(&doc, "ms2");
        if (root) {
            void* node = FUN_140165cf0(root, "wedding");
            if (node) {
                bool cancelMail = false;
                FUN_140873420(node, "groom", &ticket.m_strGroom);
                FUN_140873420(node, "bride", &ticket.m_strBride);
                FUN_1408732e0(node, "date", &ticket.m_nTime);
                FUN_1408731e0(node, "package", &ticket.m_nPackageId);
                FUN_1408731e0(node, "hall", &ticket.m_nHallId);
                FUN_1408730a0(node, "cancelMail", &cancelMail);
                CStringW hallName = CStringTable::GetInstance()->FUN_141811980(3,
                    FUN_1409023c0()->FUN_140908d50(ticket.m_nPackageId, ticket.m_nHallId, FUN_140900f30(ticket.m_nTime)));
                CStringW date = FUN_140b8e850(CMsTime(ticket.m_nTime));
                ASObj* obj = static_cast<ASObj*>(script);
                obj->FUN_1407cbb20("groom", ticket.m_strGroom);
                obj->FUN_1407cbb20("bride", ticket.m_strBride);
                obj->FUN_1407cbb20("date", date);
                obj->FUN_1407cbb20("hall", hallName);
                obj->FUN_1407cbbe0("cancelMail", cancelMail);
            }
        }
    }
}

// @0x141b869f0
void WeddingManager::PlayEmotion(int type)
{
    PCBase* user = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (user) {
        MS2Ptr<StateWeddingEmotionData> data(new StateWeddingEmotionData);
        switch (type) {
            break;
        case 1: {
            int kind = user->FUN_14166c930();
            if ((kind == 1 || kind == 2 || kind == 0x47) == false)
                return;
            FacePartner(user);
            data->m_strAnim = "Emotion_HandKiss_A";
            data->m_n30 = 20000;
            data->m_b2c = true;
            user->vfunc_59(0x47, data.get(), 0, 0);
            break;
        }
        case 3: {
            int kind = user->FUN_14166c930();
            if (kind != 0x47)
                return;
            user->vfunc_59(1, 0, 0, 0);
            break;
        }
        }
    }
}

// @0x141b86bd0
void WeddingManager::OnMode27Accept(CInPacket& packet)
{
    PCBase* user = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (user) {
        MS2Ptr<StateWeddingEmotionData> data(new StateWeddingEmotionData);
        data->m_b18 = true;
        data->m_n28 = packet.vfunc_o8_3();
        data->m_b2d = packet.vfunc_o8_0();
        data->m_b2c = packet.vfunc_o8_0();
        if (data->m_b2c)
            data->m_n30 = packet.vfunc_o8_3();
        int kind = user->FUN_14166c930();
        if ((kind == 1 || kind == 2 || kind == 0x47) == false)
            return;
        user->vfunc_59(0x47, data.get(), 0, 1);
    }
}

// @0x141b89990
bool WeddingManager::IsInProgress()
{
    switch (m_proxy.m_nState) {
    case 2:
    case 3:
    case 4:
        return true;
    }
    return false;
}

// @0x141b8a4c0
void WeddingManager::FacePartner(PCBase* user)
{
    PCBase* partner = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd1420(m_strTarget));
    if (!partner)
        return;
    // the NiPoint3 result is sliced into its efd::Point3 base (12-byte rep movsb at 0x141b8a558)
    efd::Point3 position = partner->vfunc_18();
    FUN_14166d2d0(user, position, 1);
}

// @0x141b867e0
bool WeddingManager::CanStartWedding(__int64 partnerId)
{
    void* user = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!user)
        return false;
    if (FUN_140d295d0()->m_n18 == partnerId) {
        FUN_141275260(0xc00, 1, 0);
        return false;
    }
    if (FUN_14166ce30(user)) {
        FUN_141275260(0xbfd, 1, 0);
        return false;
    }
    int allowed = 0;
    Unk_WmFieldRef field(DAT_143b059e8.FUN_1401cd040());
    if ((field.FUN_140885310() ? true : false) && field.FUN_1401cd1a0()->FUN_1410d2f10() && !field.FUN_1401cd1a0()->FUN_1410c35c0()) {
        allowed = 1;
    } else {
        allowed = FUN_1403ed2d0()->FUN_141bd30a0()->m_5c;
    }
    if (allowed == 0) {
        FUN_141275260(0xc01, 1, 0);
        return false;
    }
    if (FUN_141659690(user)) {
        FUN_141275260(0xbfc, 1, 0);
        return false;
    }
    if (FUN_141527160(user, 0x27) == 0) {
        FUN_141275260(0xbfc, 1, 0);
        return false;
    }
    return true;
}

// ---- Unk_IndexPool (CGroundEffectData's weighted pool; the exe emits it in this unit's range) ----

// @0x141b90b70
Unk_IndexPool::Unk_IndexPool()
{
}

// @0x141b90ba0
Unk_IndexPool::~Unk_IndexPool()
{
}

// @0x141b90bd0
void Unk_IndexPool::AddIndex(int nIndex, int nCount)
{
    for (int i = 0; i < nCount; i++)
        m_indices.push_back(nIndex);
}

// @0x141b90c20
void Unk_IndexPool::Shuffle()
{
    std::random_shuffle(m_indices.begin(), m_indices.end());
}

// @0x141b90c70
int Unk_IndexPool::Pick()
{
    unsigned int nRand = rand();
    size_t nCount = m_indices.size() - 1;
    unsigned int nPick = nRand % nCount;
    return m_indices[nPick];
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc3790-0x142cc38a0 .text$yd
