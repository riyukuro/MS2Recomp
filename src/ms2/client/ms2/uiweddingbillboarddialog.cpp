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

#include "ms2/placeholder/ms2stdafx.h"

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

// ---- unit-local views of exe objects ----

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast target).
class ASDialog : public ASDisplayObject
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
};

// The page buttons of the movie.
class Unk_140acd6e0 : public ASDisplayObject { public: void FUN_1422c1fe0(unsigned int bEnabled); };

// The list control of the movie (the AS list with clear / append).
class Unk_WbList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
};

// The packet dispatcher (register / unregister a handler by opcode).
class Unk_WbPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);   // register
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);   // unregister
};
Unk_WbPackets* FUN_140bccd50();

void* FUN_1409eed90();                                          // the singleton of the own character
void FUN_141b86750(void* pCharacter, unsigned __int64 nWeddingHallSN);    // attend that wedding
unsigned __int64 FUN_140718370(const CStringW& text);                // text -> number
bool FUN_140164830(const CStringW& a, const CStringW& b);       // names are equal
bool FUN_140900f30(__int64 nTime);                              // the time is at night
CStringW FUN_140b8e850(const CMsTime& kTime);                   // the date text
CStringW FUN_141b71910(__int64 nValue);                         // the number as text
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);    // formats one number
CStringTable* FUN_1401a9d70();
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
    FUN_141924170(1);
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
    FUN_140bccd50()->FUN_140da51e0(0x12a, Delegate<void(CInPacket&)>(this, &UIWeddingBillboardDialog::FUN_140fc3300));
}

// @0x140fc2e70
void UIWeddingBillboardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140bccd50()->FUN_140da5180(0x12a, Delegate<void(CInPacket&)>(this, &UIWeddingBillboardDialog::FUN_140fc3300));
    COutPacket packet(0xbb, 0);
    packet.Encode1(4);
    packet.Encode4(0);
    FUN_140710590(packet);
}

// @0x140fc2f70
// MS2-FUNCTIONAL: same dispatch behavior; compare/frame layout differs from the exe
int UIWeddingBillboardDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onAttend") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nSN = FUN_140718370(data.FUN_1422b8f40());
            FUN_141b86750(FUN_1409eed90(), nSN);
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
        COutPacket packet(0xbb, 0);
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
    unsigned char nType = packet.vfunc_o8_1();
    if (nType == 4)
    {
        m_tickets.clear();
        int nCount = packet.vfunc_o8_3();
        for (int i = 0; i < nCount; ++i)
        {
            unsigned __int64 nSN = packet.vfunc_o8_4();
            WeddingHallTicket ticket;
            ticket.Read(packet);
            m_tickets.push_back(std::make_pair(nSN, ticket));
        }
        std::sort(m_tickets.begin(), m_tickets.end(), FUN_140fc3500);
        FUN_140fc3680();
    }
}

// @0x140fc3500
// MS2-FUNCTIONAL: same ordering logic; temp destruction/bool slot layout differs from the exe
bool FUN_140fc3500(const UIWeddingBillboardDialog::Entry& a, const UIWeddingBillboardDialog::Entry& b)
{
    if (a.second.m_nTime == b.second.m_nTime)
    {
        MS2Ptr<WeddingPackage> spPackageA = WeddingTable::GetInstance()->FUN_140908b80(a.second.m_nPackageId);
        MS2Ptr<WeddingPackage> spPackageB = WeddingTable::GetInstance()->FUN_140908b80(b.second.m_nPackageId);
        MS2Ptr<WeddingHallData> spHallA = spPackageA->FUN_140907110(a.second.m_nHallId);
        MS2Ptr<WeddingHallData> spHallB = spPackageB->FUN_140907110(b.second.m_nHallId);
        bool bGreater = spHallA->m_nMerat > spHallB->m_nMerat;
        return bGreater;
    }
    return a.second.m_nTime < b.second.m_nTime;
}

// @0x140fc3680
// MS2-FUNCTIONAL: same page refresh behavior; stack slot layout differs from the exe
void UIWeddingBillboardDialog::FUN_140fc3680()
{
    int nEnd;
    int nFirst = m_nPage * 12;
    nEnd = nFirst + 12;
    if (nEnd < 0)
        nEnd = 0;
    if ((int)m_tickets.size() < nEnd)
        nEnd = (int)m_tickets.size();
    if (MS2Ptr<Unk_140acd6e0> spNext = FUN_140bb4b10("m_nextPage"))
        spNext->FUN_1422c1fe0(nEnd == (int)m_tickets.size());
    if (MS2Ptr<Unk_140acd6e0> spPrev = FUN_140bb4b10("m_prevPage"))
        spPrev->FUN_1422c1fe0(nFirst == 0);
    if (MS2Ptr<ASTextField> spPage = FUN_140bb4cf0("m_page"))
        spPage->FUN_1422c4cd0(FUN_1401ceea0(L"{0}", m_nPage));
    bool bEmpty = true;
    PC* pPlayer = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        CStringW strMyName = pPlayer->vfunc_77();
        if (MS2Ptr<Unk_WbList> spList = FUN_140c02900("m_list"))
        {
            spList->FUN_1422dd1d0();
            for (; nFirst < nEnd; ++nFirst)
            {
                unsigned __int64 nSN = m_tickets[nFirst].first;
                const Entry& entry = m_tickets[nFirst];
                if (entry.second.m_bPublic != 0 || !FUN_140164830(entry.second.m_strBride, strMyName) ||
                    !FUN_140164830(entry.second.m_strGroom, strMyName))
                {
                    bool bNight = FUN_140900f30(entry.second.m_nTime);
                    unsigned int nHallText = WeddingTable::GetInstance()->FUN_140908d50(entry.second.m_nPackageId,
                                                                                         entry.second.m_nHallId, bNight);
                    ASObj row(2);
                    row.FUN_1407cbb20("weddingSN", FUN_141b71910(nSN));
                    row.FUN_1407cbb20("date", FUN_140b8e850(CMsTime(entry.second.m_nTime)));
                    row.FUN_1407cbb20("groomName", entry.second.m_strGroom);
                    row.FUN_1407cbb20("brideName", entry.second.m_strBride);
                    row.FUN_1407cbb20("weddingHall", FUN_1401a9d70()->FUN_141811980(3, nHallText));
                    spList->FUN_1422dd230(row);
                    bEmpty = false;
                }
            }
            spList->vfunc_24(true);
        }
        if (MS2Ptr<ASTextField> spNotice = FUN_140bb4cf0("m_notice"))
            spNotice->vfunc_4(bEmpty);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140FC2D90, UIWeddingBillboardDialog, vfunc_65, 37, 0x94509E1F);
MS2_REPLACE_METHOD(0x140FC2DC0, UIWeddingBillboardDialog, vfunc_67, 165, 0xB9AC4531);
MS2_REPLACE_METHOD(0x140FC2E70, UIWeddingBillboardDialog, OnLoadComplete, 235, 0x05FAADEC);
MS2_REPLACE_METHOD(0x140FC2F70, UIWeddingBillboardDialog, vfunc_28, 763, 0xF893F9AF);
MS2_REPLACE_METHOD(0x140FC3300, UIWeddingBillboardDialog, FUN_140fc3300, 500, 0x5C1CF974);
MS2_REPLACE_METHOD(0x140FC3680, UIWeddingBillboardDialog, FUN_140fc3680, 1912, 0xFBD15B3E);
