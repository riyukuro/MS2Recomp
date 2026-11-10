// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingBillboardDialog: see uiweddingbillboarddialog.h.
// MS2-UNIT: ?\uiweddingbillboarddialog.cpp
// MS2-RANGE: 0x140fc2c50-0x140fc6fa0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140fc5d40 ; unique
// MS2-PIN: ?vfunc_48@UIWeddingBillboardDialog@@UEAAHXZ 0x140fc6440 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140fc6b90 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140fc6c80 ; unique
// MS2-PIN: ??$Call@VUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140fc6cb0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIWeddingBillboardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140fc6cf0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddingbillboarddialog.cpp"    // assumed

// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uiweddingbillboarddialog.h"

#include <algorithm>
#include <stdlib.h>
#include "worldservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/weddingpackage.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/packethandlermanager.h"  // C3: PacketHandlerManager::RegisterHandler/UnregisterHandler
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/commonfiles/os.h"

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog

// ---- unit-local views of exe objects ----

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast target).
class ASDialog : public ASDisplayObject
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
};

// The page buttons of the movie.
#include "ms2/placeholder/asbutton.h"   // C3: the button view is ASButton (was the stand-in Unk_140acd6e0)

// The packet dispatcher (register / unregister a handler by opcode).
class Unk_WbPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);   // register
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);   // unregister
};
class Unk_140bccd50* GetPacketHandlerManager();   // C3: was FUN_140bccd50

class WeddingManager;
class WeddingManager   // C3: member view for the former free stand-ins
{
public:
    void SendInvitation(unsigned __int64);
};
unsigned __int64 ParseUInt64W(const CStringW& text);                // text -> number
bool IsNightTime(__int64 nTime);                              // the time is at night
CStringW FormatYearMonthDayHour(const CMsTime& kTime);                   // the date text
CStringW FUN_141b71910(__int64 nValue);                         // the number as text
void FUN_140710590(COutPacket& packet);                         // send the packet

// ---- WeddingHallTicket's copies (weddinghallticket.h: first instantiated here) ----

// @0x140fc6060
WeddingHallTicket::WeddingHallTicket(const WeddingHallTicket& other)
    : CPtred(other)
    , m_nWeddingHallSN(other.m_nWeddingHallSN)
    , m_nPackageId(other.m_nPackageId)
    , m_nHallId(other.m_nHallId)
    , m_bPublic(other.m_bPublic)
    , m_nBookingAccSN(other.m_nBookingAccSN)
    , m_nBookingCharSN(other.m_nBookingCharSN)
    , m_nTime(other.m_nTime)
    , m_strGroom(other.m_strGroom)
    , m_strBride(other.m_strBride)
    , m_fee(other.m_fee)
    , m_nReservationCouponId(other.m_nReservationCouponId)
{
}

// @0x140fc6240
WeddingHallTicket& WeddingHallTicket::operator=(const WeddingHallTicket& other)
{
    CPtred::operator=(other);
    m_nWeddingHallSN = other.m_nWeddingHallSN;
    m_nPackageId = other.m_nPackageId;
    m_nHallId = other.m_nHallId;
    m_bPublic = other.m_bPublic;
    m_nBookingAccSN = other.m_nBookingAccSN;
    m_nBookingCharSN = other.m_nBookingCharSN;
    m_nTime = other.m_nTime;
    m_strGroom = other.m_strGroom;
    m_strBride = other.m_strBride;
    m_fee.FUN_14026e780(other.m_fee);
    m_nReservationCouponId = other.m_nReservationCouponId;
    return *this;
}

// @0x140fc2c50
UIWeddingBillboardDialog::UIWeddingBillboardDialog()
    : m_nPage(0)
{
    m_2c = 0x19;
    FUN_1422dc3b0(1);
    SetTweenEnabled(1);
}

// @0x140fc2cf0
UIWeddingBillboardDialog::~UIWeddingBillboardDialog()
{
}

// @0x140fc2d40
CString UIWeddingBillboardDialog::GetTypeName()
{
    return "WeddingBillboardDialog";
}

// @0x140fc2d90
int UIWeddingBillboardDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140fc2dc0
void UIWeddingBillboardDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    ((class PacketHandlerManager*)GetPacketHandlerManager())->UnregisterHandler(0x12a, Delegate<void(CInPacket&)>(this, &UIWeddingBillboardDialog::FUN_140fc3300));
}

// @0x140fc2e70
void UIWeddingBillboardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ((class PacketHandlerManager*)GetPacketHandlerManager())->RegisterHandler(0x12a, Delegate<void(CInPacket&)>(this, &UIWeddingBillboardDialog::FUN_140fc3300));
    COutPacket packet(static_cast<int>(SendOp::WeddingBillboard), 0);
    packet.Encode1(4);
    packet.Encode4(0);
    FUN_140710590(packet);
}

// @0x140fc2f70
int UIWeddingBillboardDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onAttend") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            unsigned __int64 nSN = ParseUInt64W(data.FUN_1422b8f40());
            TSingleton<WeddingManager>::GetInstance()->SendInvitation(nSN);
        }
    }
    else if (_stricmp(szMethod, "onPrev") == 0)
    {
        m_nPage = m_nPage - 1;
        if (m_nPage < 0)
            m_nPage = 0;
        if (m_nPage > (int)(m_tickets.size() / 12))
            m_nPage = (int)(m_tickets.size() / 12);
        FUN_140fc3680();
    }
    else if (_stricmp(szMethod, "onNext") == 0)
    {
        m_nPage = m_nPage + 1;
        if (m_nPage < 0)
            m_nPage = 0;
        if (m_nPage > (int)(m_tickets.size() / 12))
            m_nPage = (int)(m_tickets.size() / 12);
        FUN_140fc3680();
    }
    else if (_stricmp(szMethod, "onRefresh") == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::WeddingBillboard), 0);
        packet.Encode1(4);
        packet.Encode4(0);
        FUN_140710590(packet);
    }
    return 0;
}

// @0x140fc3280
void UIWeddingBillboardDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(0, 0, -50);
}

// @0x140fc3300
void UIWeddingBillboardDialog::FUN_140fc3300(CInPacket& packet)
{
    unsigned char nType = packet.ReadUInt8();
    if (nType == 4)
    {
        m_tickets.clear();
        int nCount = packet.ReadInt32();
        for (int i = 0; i < nCount; ++i)
        {
            unsigned __int64 nSN = packet.ReadInt64();
            WeddingHallTicket ticket;
            ticket.Read(packet);
            m_tickets.push_back(std::make_pair(nSN, ticket));
        }
        std::sort(m_tickets.begin(), m_tickets.end(), FUN_140fc3500);
        FUN_140fc3680();
    }
}

// @0x140fc3500
bool FUN_140fc3500(const UIWeddingBillboardDialog::Entry& a, const UIWeddingBillboardDialog::Entry& b)
{
    if (a.second.m_nTime == b.second.m_nTime)
    {
        MS2Ptr<WeddingPackage> spPackageA = WeddingTable::GetInstance()->FindPackage(a.second.m_nPackageId);
        MS2Ptr<WeddingPackage> spPackageB = WeddingTable::GetInstance()->FindPackage(b.second.m_nPackageId);
        MS2Ptr<WeddingHallData> spHallA = spPackageA->FindHall(a.second.m_nHallId);
        MS2Ptr<WeddingHallData> spHallB = spPackageB->FindHall(b.second.m_nHallId);
        return spHallA->m_nMerat > spHallB->m_nMerat;
    }
    return a.second.m_nTime < b.second.m_nTime;
}

// @0x140fc3680
void UIWeddingBillboardDialog::FUN_140fc3680()
{
    int nEnd;
    int nFirst = m_nPage * 12;
    nEnd = nFirst + 12;
    if (nEnd < 0)
        nEnd = 0;
    if (nEnd > (int)m_tickets.size())
        nEnd = (int)m_tickets.size();
    if (MS2Ptr<ASButton> spNext = GetChild<ASButton>("m_nextPage"))
        spNext->SetEnabled(nEnd == (int)m_tickets.size());
    if (MS2Ptr<ASButton> spPrev = GetChild<ASButton>("m_prevPage"))
        spPrev->SetEnabled(nFirst == 0);
    if (MS2Ptr<ASTextField> spPage = GetChild<ASTextField>("m_page"))
        spPage->SetTextW(StringFormat<int>(L"{0}", m_nPage));
    bool bEmpty = true;
    PC* pPlayer = static_cast<PC*>(WorldService::GetInstance()->GetLocalPlayer());
    if (pPlayer == 0)
        return;
    CStringW strMyName = pPlayer->vfunc_77();
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_list"))
    {
        spList->FUN_1422dd1d0();
        for (int i = nFirst; i < nEnd; ++i)
        {
            unsigned __int64 nSN = m_tickets[i].first;
            const WeddingHallTicket& ticket = m_tickets[i].second;
            if (ticket.m_bPublic == 0 && ticket.m_strBride != strMyName &&
                ticket.m_strGroom != strMyName)
                continue;
            unsigned int nHallText = WeddingTable::GetInstance()->GetHallFieldId(ticket.m_nPackageId, ticket.m_nHallId,
                                                                                IsNightTime(ticket.m_nTime));
            ASObj row(2);
            row.SetWStringMember("weddingSN", FUN_141b71910(nSN));
            row.SetWStringMember("date", FormatYearMonthDayHour(CMsTime(ticket.m_nTime)));
            row.SetWStringMember("groomName", ticket.m_strGroom);
            row.SetWStringMember("brideName", ticket.m_strBride);
            row.SetWStringMember("weddingHall", TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, nHallText));
            spList->AddItem(row);
            bEmpty = false;
        }
        spList->vfunc_24(true);
    }
    if (MS2Ptr<ASTextField> spNotice = GetChild<ASTextField>("m_notice"))
        spNotice->vfunc_4(bEmpty);
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140FC2D90, UIWeddingBillboardDialog, vfunc_65, 37, 0x94509E1F);
MS2_REPLACE_METHOD(0x140FC2DC0, UIWeddingBillboardDialog, vfunc_67, 165, 0xB9AC4531);
MS2_REPLACE_METHOD(0x140FC2E70, UIWeddingBillboardDialog, OnLoadComplete, 235, 0x05FAADEC);
MS2_REPLACE_METHOD(0x140FC2F70, UIWeddingBillboardDialog, vfunc_28, 763, 0xF893F9AF);
MS2_REPLACE_METHOD(0x140FC3300, UIWeddingBillboardDialog, FUN_140fc3300, 500, 0x5C1CF974);
MS2_REPLACE_METHOD(0x140FC3680, UIWeddingBillboardDialog, FUN_140fc3680, 1912, 0xFBD15B3E);
