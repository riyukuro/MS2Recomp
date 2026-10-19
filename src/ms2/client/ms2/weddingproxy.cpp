// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WeddingProxy: the own character's wedding record (partners,
// messages, meso log), WeddingHallTicket and WeddingGuest with their packet serialisers, the wedding rule checks that
// return a result code (0: allowed) and the std::list<meso log row> glue.
// MS2-UNIT: ?\weddingproxy.cpp
// MS2-RANGE: 0x1408fe100-0x1409030d0 .text$mn
// MS2-PIN: ??1?$MS2Ptr@VWeddingHallData@@@@QEAA@XZ 0x140901e30 ; merge-bind
// MS2-PIN: ??1?$MS2Ptr@VWeddingPackage@@@@QEAA@XZ 0x140901e60 ; merge-bind
// MS2-PIN: ?Reference@?$MS2Ptr@VWeddingPackage@@@@CAXPEAVWeddingPackage@@@Z 0x140902420 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VWeddingHallData@@@@AEAAXXZ 0x140902920 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VWeddingPackage@@@@AEAAXXZ 0x140902960 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VWeddingPackage@@@@AEAAXPEAX@Z 0x1409029f0 ; merge-bind
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\weddingproxy.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/weddingguest.h"
#include "ms2/placeholder/weddinghallticket.h"
#include "ms2/placeholder/weddingpackage.h"
#include "ms2/placeholder/weddingproxy.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CFeatureManager* FUN_140166410();

// ---- Unk_WeddingPartner ----------------------------------------------------------------------------------------
// @0x1408fe100
Unk_WeddingPartner::Unk_WeddingPartner()
{
    Reset();
}
// @0x1408fe150
Unk_WeddingPartner::~Unk_WeddingPartner()
{
}
// @0x1408fe190
void Unk_WeddingPartner::Reset()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nCharacterId = 0;
    m_nAccountId = 0;
    m_strName.Empty();
    m_bOnline = false;
}
// @0x1408fe200
void Unk_WeddingPartner::Assign(Unk_WeddingPartner& other)
{
    __int64 nCharacterId = other.m_nCharacterId;
    __int64 nAccountId = other.m_nAccountId;
    CStringW strName = other.GetName();
    bool bOnline = other.IsOnline();
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nCharacterId = nCharacterId;
    m_nAccountId = nAccountId;
    m_strName = strName;
    m_bOnline = bOnline;
}
// @0x1408fe2d0
void Unk_WeddingPartner::Write(COutputStream& out)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    out.vfunc_o10_4(m_nCharacterId);
    out.vfunc_o10_4(m_nAccountId);
    out.vfunc_o10_8(m_strName);
    out.vfunc_o10_0(m_bOnline);
}
// @0x1408fe390
void Unk_WeddingPartner::Read(CInPacket& in)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nCharacterId = in.vfunc_o8_4();
    m_nAccountId = in.vfunc_o8_4();
    m_strName = in.vfunc_o8_8();
    m_bOnline = in.vfunc_o8_0();
}
// @0x1408fe4e0
void Unk_WeddingPartner::SetName(const CStringW& strName)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_strName = strName;
}
// @0x1408fe540
CStringW Unk_WeddingPartner::GetName()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_strName;
}
// @0x1408fe5c0
void Unk_WeddingPartner::SetOnline(bool bOnline)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_bOnline = bOnline;
}
// @0x1408fe610
bool Unk_WeddingPartner::IsOnline()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    bool bOnline = m_bOnline;
    return bOnline;
}

// ---- Unk_WeddingLog / Unk_WeddingLogList ---------------------------------------------------------------------------
// @0x1408fe660
Unk_WeddingLog::Unk_WeddingLog()
    : m_nType(0), m_nTime(0), m_nAmount(0)
{
}
// @0x1408fe6a0
Unk_WeddingLogList::Unk_WeddingLogList()
{
}
// @0x1408fe6d0
Unk_WeddingLogList::~Unk_WeddingLogList()
{
}
// @0x1408fe700
void Unk_WeddingLogList::Clear()
{
    m_list.clear();
}
// @0x1408fe730
void Unk_WeddingLogList::Assign(Unk_WeddingLogList& other)
{
    m_list.clear();
    m_list = other.m_list;
}
// @0x1408fe770
void Unk_WeddingLogList::Write(COutputStream& out)
{
    out.vfunc_o10_3((int)m_list.size());
    for (std::list<Unk_WeddingLog>::iterator it = m_list.begin(); it != m_list.end(); ++it) {
        out.vfunc_o10_2((short)it->m_nType);
        out.vfunc_o10_4(it->m_nAmount);
        out.vfunc_o10_4(it->m_nTime);
    }
}
// @0x1408fe860
void Unk_WeddingLogList::Read(CInPacket& in)
{
    m_list.clear();
    unsigned int nCount = in.vfunc_o8_3();
    for (unsigned int i = 0; i < nCount; i = i + 1) {
        Unk_WeddingLog log;
        log.m_nType = (unsigned short)in.vfunc_o8_2();
        log.m_nAmount = in.vfunc_o8_4();
        log.m_nTime = in.vfunc_o8_4();
        m_list.push_back(log);
    }
}
// @0x1408fe970
void Unk_WeddingLogList::Add(unsigned int nType, __int64 nAmount, __int64 nTime)
{
    Unk_WeddingLog log;
    log.m_nType = nType;
    log.m_nTime = nTime;
    log.m_nAmount = nAmount;
    m_list.push_back(log);
    if (m_list.size() > 0x19)
        m_list.erase(m_list.begin());
}

// ---- WeddingProxy --------------------------------------------------------------------------------------------------
// @0x1408fea10
WeddingProxy::WeddingProxy()
{
    Init();
}
// @0x1408feb00
WeddingProxy::~WeddingProxy()
{
}
// @0x1408febd0
void WeddingProxy::Init()
{
    m_n18 = 0;
    m_nState = 0;
    m_n28 = 0;
    m_n30 = 0;
    m_nMeso = 0;
    m_groom.Reset();
    m_bride.Reset();
    m_log.Clear();
}
// @0x1408fec60
void WeddingProxy::Assign(WeddingProxy& other)
{
    m_n18 = other.m_n18;
    m_nState = other.m_nState;
    m_n28 = other.m_n28;
    m_n30 = other.m_n30;
    m_groom.Assign(other.m_groom);
    m_bride.Assign(other.m_bride);
    SetMessageW(other.m_strMessageW0, true);
    SetMessageW(other.m_strMessageW1, true);
    __int64 nMeso = other.GetMeso();
    SetMeso(nMeso);
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_log.Assign(other.m_log);
}
// @0x1408feda0
void WeddingProxy::Write(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    out.vfunc_o10_1((unsigned char)m_nState);
    out.vfunc_o10_4(m_n28);
    out.vfunc_o10_4(m_n30);
    m_groom.Write(out);
    m_bride.Write(out);
    __int64 nMeso = GetMeso();
    out.vfunc_o10_4(nMeso);
    out.vfunc_o10_8(GetMessageW(true));
    out.vfunc_o10_8(GetMessageW(false));
    out.vfunc_o10_6(GetMessageA(true));
    out.vfunc_o10_6(GetMessageA(false));
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_log.Write(out);
}
// @0x1408ff040
void WeddingProxy::Read(CInPacket& in)
{
    m_n18 = in.vfunc_o8_4();
    m_nState = in.vfunc_o8_1();
    m_n28 = in.vfunc_o8_4();
    m_n30 = in.vfunc_o8_4();
    m_groom.Read(in);
    m_bride.Read(in);
    SetMeso(in.vfunc_o8_4());
    SetMessageW(in.vfunc_o8_8(), true);
    SetMessageW(in.vfunc_o8_8(), false);
    SetMessageA(in.vfunc_o8_6(), true);
    SetMessageA(in.vfunc_o8_6(), false);
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_log.Read(in);
}
// @0x1408ff3b0
Unk_WeddingPartner* WeddingProxy::GetPartner(__int64 nCharacterId)
{
    Unk_WeddingPartner* pPartner;
    if (m_groom.m_nCharacterId == nCharacterId)
        pPartner = &m_bride;
    else
        pPartner = &m_groom;
    return pPartner;
}
// @0x1408ff410
Unk_WeddingPartner* WeddingProxy::GetSelf(__int64 nCharacterId)
{
    Unk_WeddingPartner* pPartner;
    if (m_groom.m_nCharacterId == nCharacterId)
        pPartner = &m_groom;
    else
        pPartner = &m_bride;
    return pPartner;
}
// @0x1408ff470
bool WeddingProxy::IsBride(__int64 nCharacterId)
{
    return IsGroom(nCharacterId) == false;
}
// @0x1408ff4c0
bool WeddingProxy::IsGroom(__int64 nCharacterId)
{
    return m_groom.m_nCharacterId == nCharacterId;
}
// @0x1408ff500
__int64 WeddingProxy::GetMeso()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    __int64 nMeso = m_nMeso;
    return nMeso;
}
// @0x1408ff560
void WeddingProxy::SetMeso(__int64 nMeso)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nMeso = nMeso;
}
// @0x1408ff5c0
void WeddingProxy::AddMeso(unsigned int nType, __int64 nAmount)
{
    if (nAmount < 0) {
        __int64 nExp = GetExp();
        if (nExp < -nAmount)
            nAmount = -nExp;
    }
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nMeso = m_nMeso + nAmount;
    __int64 nTime = GetServerTime();
    m_log.Add(nType, nAmount, nTime);
}
// @0x1408ff6a0
void WeddingProxy::ClearMeso()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nMeso = 0;
    m_log.Clear();
}
// @0x1408ff710
void WeddingProxy::SetMessageW(const CStringW& str, bool bFirst)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (bFirst == false)
        m_strMessageW0 = str;
    else
        m_strMessageW1 = str;
}
// @0x1408ff7a0
void WeddingProxy::SetMessageA(const CString& str, bool bFirst)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (bFirst == false)
        m_strMessageA0 = str;
    else
        m_strMessageA1 = str;
}
// @0x1408ff830
CStringW WeddingProxy::GetMessageW(bool bFirst)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    CStringW* pStr;
    if (bFirst == false)
        pStr = &m_strMessageW0;
    else
        pStr = &m_strMessageW1;
    return *pStr;
}
// @0x1408ff8e0
CString WeddingProxy::GetMessageA(bool bFirst)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    CString* pStr;
    if (bFirst == false)
        pStr = &m_strMessageA0;
    else
        pStr = &m_strMessageA1;
    return *pStr;
}

// ---- WeddingHallTicket ---------------------------------------------------------------------------------------------
// @0x1408ff990
WeddingHallTicket::WeddingHallTicket()
{
    Reset();
}
// @0x1408ffa10
WeddingHallTicket::~WeddingHallTicket()
{
}
// @0x1408ffa80
void WeddingHallTicket::Reset()
{
    m_nWeddingHallSN = 0;
    m_nPackageId = 0;
    m_nHallId = 0;
    m_nTime = 0;
    m_bPublic = false;
    m_nBookingAccSN = 0;
    m_nBookingCharSN = 0;
    m_strGroom.Empty();
    m_strBride.Empty();
    m_fee.FUN_14026e7b0();
    m_nReservationCouponId = 0;
}
// @0x1408ffb30
void WeddingHallTicket::Assign(const WeddingHallTicket& other)
{
    m_nWeddingHallSN = other.m_nWeddingHallSN;
    m_nPackageId = other.m_nPackageId;
    m_nHallId = other.m_nHallId;
    m_nTime = other.m_nTime;
    m_bPublic = other.m_bPublic;
    m_nBookingAccSN = other.m_nBookingAccSN;
    m_nBookingCharSN = other.m_nBookingCharSN;
    m_strGroom = other.m_strGroom;
    m_strBride = other.m_strBride;
    m_fee.FUN_14026e860(other.m_fee);
    m_nReservationCouponId = other.m_nReservationCouponId;
}
// @0x1408ffc30
void WeddingHallTicket::Write(COutputStream& out)
{
    out.vfunc_o10_4(m_nWeddingHallSN);
    out.vfunc_o10_3(m_nPackageId);
    out.vfunc_o10_3(m_nHallId);
    out.vfunc_o10_4(m_nTime);
    out.vfunc_o10_0(m_bPublic);
    out.vfunc_o10_4(m_nBookingAccSN);
    out.vfunc_o10_4(m_nBookingCharSN);
    out.vfunc_o10_8(m_strGroom);
    out.vfunc_o10_8(m_strBride);
    m_fee.FUN_14026e8c0(out);
    out.vfunc_o10_3(m_nReservationCouponId);
}
// @0x1408ffd80
void WeddingHallTicket::Read(CInPacket& in)
{
    m_nWeddingHallSN = in.vfunc_o8_4();
    m_nPackageId = in.vfunc_o8_3();
    m_nHallId = in.vfunc_o8_3();
    m_nTime = in.vfunc_o8_4();
    m_bPublic = in.vfunc_o8_0();
    m_nBookingAccSN = in.vfunc_o8_4();
    m_nBookingCharSN = in.vfunc_o8_4();
    m_strGroom = in.vfunc_o8_8();
    m_strBride = in.vfunc_o8_8();
    m_fee.FUN_14026e940(in);
    m_nReservationCouponId = in.vfunc_o8_3();
}
// @0x140900050
CStringW WeddingHallTicket::ToString()
{
    CStringW str = StringFormat(L"m_weddingHallSN={0}, m_weddingHallID={1}, m_weddingDate={2}, m_isPublic={3}, m_bookingAccSN={4} m_bookingCharSN={5}, m_groomName={6}, m_brideName={7}, m_reservationCouponID={8}", m_nWeddingHallSN, m_nHallId, m_nTime, m_bPublic, m_nBookingAccSN, m_nBookingCharSN, m_strGroom, m_strBride, m_nReservationCouponId);
    return str;
}

// ---- a record of two partners, a guest list and a hall fee (0x138 bytes; ctor 0x140900160, dtor 0x140900250) ----------
struct Unk_WeddingRecord
{
    Unk_WeddingRecord();
    ~Unk_WeddingRecord();
    __int64 m_n00;
    __int64 m_n08;
    unsigned int m_n10;
    Unk_WeddingPartner m_a;                                 // +0x18
    Unk_WeddingPartner m_b;                                 // +0x68
    unsigned int m_nb8;
    unsigned int m_nbc;
    __int64 m_nc0;
    Unk_GuildArray m_arr;                                   // +0xc8
    __int64 m_ne8;
    __int64 m_nf0;
    WeddingHallReservationFee m_fee;                        // +0xf8
};
MS2_CHECK_SIZE(Unk_WeddingRecord, 0x138);
// @0x140900160
Unk_WeddingRecord::Unk_WeddingRecord()
    : m_n00(0), m_n08(0), m_n10(0), m_nb8(0), m_nbc(0), m_nc0(0), m_ne8(0), m_nf0(0)
{
}
// @0x140900250
Unk_WeddingRecord::~Unk_WeddingRecord()
{
}

// ---- WeddingGuest --------------------------------------------------------------------------------------------------
// @0x1409002b0
WeddingGuest::WeddingGuest()
    : m_nKind(0), m_n28(0)
{
}
// @0x140900310
WeddingGuest::~WeddingGuest()
{
}
// @0x140900350
void WeddingGuest::Assign(const WeddingGuest& other)
{
    m_nKind = other.m_nKind;
    m_strName = other.m_strName;
    m_n20 = other.m_n20;
    m_n28 = other.m_n28;
}
// @0x1409003c0
void WeddingGuest::Write(COutputStream& out)
{
    out.vfunc_o10_2((short)m_nKind);
    out.vfunc_o10_4(m_n20);
    out.vfunc_o10_4(m_n28);
    out.vfunc_o10_8(m_strName);
}
// @0x140900450
void WeddingGuest::Read(CInPacket& in)
{
    unsigned short nKind = in.vfunc_o8_2();
    m_nKind = nKind;
    m_n20 = in.vfunc_o8_4();
    m_n28 = in.vfunc_o8_4();
    m_strName = in.vfunc_o8_8();
}

// ---- wedding rules -------------------------------------------------------------------------------------------------
// @0x140900550
bool FUN_140900550()
{
    CFeatureManager* pFeatures = FUN_140166410();
    return pFeatures->FUN_14036d570(0x104) != false;
}
// @0x140900580
int FUN_140900580(bool bFlag)
{
    int nResult;
    CFeatureManager* pFeatures = FUN_140166410();
    if (pFeatures->FUN_14036d570(0x106) == false || bFlag != false)
        nResult = 1;
    else
        nResult = 0;
    return nResult;
}
// @0x1409005c0
int FUN_1409005c0(bool bA, bool bB)
{
    int nResult;
    CFeatureManager* pFeatures = FUN_140166410();
    if (pFeatures->FUN_14036d570(0x105) == false || bA != bB)
        nResult = 1;
    else
        nResult = 0;
    return nResult;
}
// @0x140900610
int WeddingProxy::CheckPropose()
{
    int nResult;
    int nState = m_nState;
    if (nState == 1) {
        nResult = 0x17;
    } else if (nState == 2) {
        nResult = 0x18;
    } else {
        if (2 < nState) {
            if (nState < 5)
                return 0x19;
            if (nState == 5 && IsProposeCooldownOver() == false)
                return 0x1a;
        }
        nResult = 0;
    }
    return nResult;
}
// @0x140900690
int WeddingProxy::CheckProposeEnd()
{
    int nResult;
    int nState = m_nState;
    if (nState == 1) {
        nResult = 0x1b;
    } else if (nState == 2) {
        nResult = 0x1c;
    } else {
        if (2 < nState) {
            if (nState < 5)
                return 0x1d;
            if (nState == 5 && IsProposeCooldownOver() == false)
                return 0x1e;
        }
        nResult = 0;
    }
    return nResult;
}
// @0x140900710
int WeddingProxy::CheckBase()
{
    int nResult;
    if (FUN_140900550() == false) {
        nResult = 0x12;
    } else if (m_nState == 1) {
        __int64 nLimit = GetPromiseLimit();
        __int64 nNow = GetServerTime();
        if (nNow < nLimit)
            nResult = 0;
        else
            nResult = 0x29;
    } else {
        nResult = 0x23;
    }
    return nResult;
}
// @0x140900780
int WeddingProxy::CheckVisit(WeddingHallTicket& ticket, __int64 nLimit)
{
    int nResult = CheckBase();
    if (nResult == 0) {
        if (ticket.m_nTime == 0 || ticket.m_nTime <= GetServerTime()) {
            CMsTime kTime(GetServerTime());
            AddHours(kTime, *TSingleton<Client::Constants>::GetInstance()->WeddingHallModifyLimitHour.Get());
            if (nLimit < kTime.Get())
                nResult = 0x36;
            else
                nResult = 0;
        } else {
            nResult = 0x2b;
        }
    }
    return nResult;
}
// @0x140900830
int WeddingProxy::CheckReservation(WeddingHallTicket& ticket, __int64 nCharacterId)
{
    int nResult = CheckBase();
    if (nResult == 0) {
        if ((__int64)ticket.m_nBookingCharSN == nCharacterId) {
            CMsTime kTime(ticket.m_nTime);
            AddHours(kTime, -(int)*TSingleton<Client::Constants>::GetInstance()->WeddingHallModifyLimitHour.Get());
            __int64 nNow = GetServerTime();
            if (nNow < kTime.Get())
                nResult = 0;
            else
                nResult = 0x2a;
        } else {
            nResult = 0x3e;
        }
    }
    return nResult;
}
// @0x1409008e0
int WeddingProxy::CheckReservationCancel(WeddingHallTicket& ticket, __int64 nCharacterId)
{
    int nResult = CheckBase();
    if (nResult == 0) {
        if ((__int64)ticket.m_nBookingCharSN == nCharacterId) {
            CMsTime kTime(ticket.m_nTime);
            AddHours(kTime, -(int)*TSingleton<Client::Constants>::GetInstance()->WeddingHallModifyLimitHour.Get());
            __int64 nNow = GetServerTime();
            if (nNow < kTime.Get())
                nResult = 0;
            else
                nResult = 0x2a;
        } else {
            nResult = 0x3e;
        }
    }
    return nResult;
}
// @0x140900990
int WeddingProxy::CheckReservationChange(WeddingHallTicket& current, WeddingHallTicket& wanted, __int64 nCharacterId)
{
    int nResult;
    int nCurrentGrade = TSingleton<WeddingTable>::GetInstance()->FUN_140909130(current.m_nPackageId, current.m_nHallId);
    int nWantedGrade = TSingleton<WeddingTable>::GetInstance()->FUN_140909130(wanted.m_nPackageId, wanted.m_nHallId);
    if (nWantedGrade < nCurrentGrade) {
        nResult = 0x24;
    } else if (current.m_nPackageId == wanted.m_nPackageId && current.m_nHallId == wanted.m_nHallId && current.m_nTime == wanted.m_nTime && current.m_bPublic == wanted.m_bPublic) {
        nResult = 0x2c;
    } else {
        nResult = CheckReservationCancel(current, nCharacterId);
    }
    return nResult;
}
// @0x140900a80
int WeddingProxy::CheckDivorce()
{
    int nResult;
    if (m_nState == 2) {
        if (IsOlderThanDays(m_n30, *TSingleton<Client::Constants>::GetInstance()->WeddingDivorceRequireMarriageDay.Get()) == 0)
            nResult = 0x2e;
        else
            nResult = 0;
    } else {
        nResult = 0x2d;
    }
    return nResult;
}
// @0x140900ae0
int WeddingProxy::CheckLeave(__int64 nCharacterId)
{
    int nResult;
    if (IsPartner(nCharacterId) == true) {
        nResult = 0x31;
    } else if (m_nState < 3 || 4 < m_nState) {
        nResult = 0x2d;
    } else {
        nResult = 0;
    }
    return nResult;
}
// @0x140900b40
int WeddingProxy::CheckEnter(__int64 nCharacterId)
{
    int nResult;
    if (IsPartner(nCharacterId) == false) {
        nResult = 0x37;
    } else {
        __int64 nDivorceTime = GetDivorceTime();
        __int64 nNow = GetServerTime();
        if (nDivorceTime < nNow)
            nResult = 0x37;
        else
            nResult = 0;
    }
    return nResult;
}
// @0x140900ba0
int WeddingProxy::CheckState2()
{
    int nResult;
    if (m_nState == 2)
        nResult = 0;
    else
        nResult = 0x32;
    return nResult;
}
// @0x140900bd0
bool WeddingProxy::IsPartner(__int64 nCharacterId)
{
    bool bResult;
    int nState = m_nState;
    if (nState == 3)
        bResult = IsGroom(nCharacterId);
    else if (nState == 4)
        bResult = IsBride(nCharacterId);
    else
        bResult = false;
    return bResult;
}
// @0x140900c30
__int64 WeddingProxy::GetPromiseLimit()
{
    CMsTime kTime(m_n28);
    AddDays(kTime, *TSingleton<Client::Constants>::GetInstance()->WeddingPromiseLimitDay.Get());
    return kTime.Get();
}
// @0x140900c80
__int64 WeddingProxy::GetDivorceTime()
{
    __int64 nResult;
    if (m_nState == 3 || m_nState == 4) {
        CMsTime kTime(m_n28);
        AddDays(kTime, *TSingleton<Client::Constants>::GetInstance()->WeddingCoolingOffDay.Get());
        nResult = kTime.Get();
    } else {
        nResult = 0;
    }
    return nResult;
}
// @0x140900cf0
__int64 WeddingProxy::GetCoolingOffTime()
{
    __int64 nResult;
    if (m_nState == 2) {
        CMsTime kTime(m_n28);
        AddDays(kTime, 0x1e);
        nResult = kTime.Get();
    } else {
        nResult = 0;
    }
    return nResult;
}
// @0x140900d40
unsigned int FUN_140900d40()
{
    return *TSingleton<Client::Constants>::GetInstance()->WeddingProposeItemID.Get();
}
// @0x140900d70
unsigned int FUN_140900d70()
{
    return *TSingleton<Client::Constants>::GetInstance()->WeddingDivorceMeso.Get();
}
// @0x140900da0
unsigned int FUN_140900da0()
{
    return *TSingleton<Client::Constants>::GetInstance()->WeddingInvitationMeso.Get();
}
// @0x140900dd0
unsigned int FUN_140900dd0()
{
    return *TSingleton<Client::Constants>::GetInstance()->WeddingDivorceFieldID.Get();
}
// @0x140900e00
bool WeddingProxy::IsProposeCooldownOver()
{
    bool bResult;
    if (m_nState == 5) {
        if (IsOlderThanDays(m_n28, *TSingleton<Client::Constants>::GetInstance()->WeddingProposeCooltime.Get()) == 0)
            bResult = false;
        else
            bResult = true;
    } else {
        bResult = false;
    }
    return bResult;
}
// @0x140900e50
__int64 WeddingProxy::GetExp()
{
    __int64 nExp;
    if (m_nState < 2 || 4 < m_nState) {
        nExp = 0;
    } else {
        __int64 nPerDay = TSingleton<WeddingTable>::GetInstance()->FUN_140908e60(1, 0);
        int nDays = GetDayNumberDifference(m_n30, GetServerTime());
        nExp = GetMeso();
        nExp = nPerDay * nDays + nExp;
        if (nExp < 0)
            nExp = 0;
    }
    return nExp;
}
// @0x140900f00
unsigned int FUN_140900f00()
{
    return *TSingleton<Client::Constants>::GetInstance()->WeddingInvitationMaxCount.Get();
}
// @0x140900f30
bool FUN_140900f30(__int64 nTime)
{
    CMsTime kTime(nTime);
    int nHour = kTime.GetHour();
    bool bNight;
    if (nHour < 6 || 0x11 < nHour)
        bNight = true;
    else
        bNight = false;
    return bNight;
}
// @0x140900f90
bool FUN_140900f90(int nPackageId, WeddingHallTicket* pTicket)
{
    MS2Ptr<WeddingPackage> spPackage = TSingleton<WeddingTable>::GetInstance()->FUN_140908b80(nPackageId);
    if (spPackage == 0) {
        return false;
    }
    int nGrade = TSingleton<WeddingTable>::GetInstance()->FUN_140909130(pTicket->m_nPackageId, pTicket->m_nHallId);
    std::map<int, MS2Ptr<WeddingHallData> >& halls = spPackage->m_halls;
    std::map<int, MS2Ptr<WeddingHallData> >::iterator it = halls.begin();
    std::map<int, MS2Ptr<WeddingHallData> >::iterator itEnd = halls.end();
    while (it != itEnd) {
        MS2Ptr<WeddingHallData> spHall = it->second;
        if (nGrade <= spHall->m_nGrade)
            return true;
        ++it;
    }
    return false;
}
