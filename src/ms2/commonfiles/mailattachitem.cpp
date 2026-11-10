// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The user mail objects: CMailInfo (one mail with its
// strings, five attachment slots, five ads, three time ranges and a benefit list), CMailAttachItem, CMailAdItem and
// CMailSendKeep, plus the smart-pointer / ATL array glue over them. See placeholder/cmailtypes.h.
// MS2-UNIT: commonfiles\mailattachitem.cpp
// MS2-RANGE: 0x14068f630-0x140693e60 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mailattachitem.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcoll.h>

#include "ms2/placeholder/cmailtypes.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/systemmailcontent.h"   // C3: CSystemMailContent::GetMail
#include "ms2/commonfiles/commonpricerecord.h"   // C3: Unk_CommonPriceRecord(List)
#include "ms2/commonfiles/mailtextutil.h"   // C3: MailText (its implicit dtor is this unit's 0x140692c60)

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

__int64 GetServerTime();                                                       // current server time
CStringW GetLocalizedText(CStringW);
CStringW FUN_14083bdc0(const CMsTime& t, bool n, CStringW strSep, CStringW strSep2);


// ---- Unk_MailAttachPtr (same bodies as the generic MS2Ptr<T>) -------------------------------------------------------

Unk_MailAttachPtr::Unk_MailAttachPtr() { p = 0; }
Unk_MailAttachPtr::Unk_MailAttachPtr(int) { p = 0; }
Unk_MailAttachPtr::Unk_MailAttachPtr(CMailAttachItem* value) { p = value; AddRef(); }
Unk_MailAttachPtr::Unk_MailAttachPtr(const Unk_MailAttachPtr& o) { p = o.p; AddRef(); }
Unk_MailAttachPtr::Unk_MailAttachPtr(Unk_MailAttachPtr&& o) { p = o.p; o.p = 0; }
Unk_MailAttachPtr::~Unk_MailAttachPtr() { Release(); }
Unk_MailAttachPtr& Unk_MailAttachPtr::operator=(const Unk_MailAttachPtr& o)
{
    o.AddRef();
    Release();
    p = o.p;
    return *this;
}
Unk_MailAttachPtr& Unk_MailAttachPtr::operator=(int) { Release(); return *this; }
bool Unk_MailAttachPtr::operator==(CMailAttachItem* value) const { return p == value; }
CMailAttachItem* Unk_MailAttachPtr::get() const { return p; }
CMailAttachItem* Unk_MailAttachPtr::operator->() const { return p; }
void Unk_MailAttachPtr::AddRef() const { if (p) AddRefImpl(0); }
void Unk_MailAttachPtr::AddRefImpl(void*) const { Reference(p); }
void Unk_MailAttachPtr::Reference(CMailAttachItem* value) { CPtred::AddRefPtred(value); }
void Unk_MailAttachPtr::Release()
{
    if (p)
    {
        ReleaseImpl(0);
        p = 0;
    }
}
void Unk_MailAttachPtr::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(p) == 0)
    {
        Reference(p);
        CPtred::DeletePtred(p);
    }
}

// ---- CMailAttachItem ------------------------------------------------------------------------------------------------

CMailAttachItem::CMailAttachItem(int index, MS2Ptr<CItem> item)
{
    if (item == 0)
    {
        Reset();
    }
    else
    {
        m_item = item->Clone();
        m_item->SetSlot(index);
        m_nTime = 0;
        m_n20 = 0;
        m_n28 = 0;
    }
}

CMailAttachItem::CMailAttachItem(CInPacket& packet)
{
    int nItemId = packet.ReadInt32();
    __int64 nUid = packet.ReadInt64();
    unsigned char nRarity = packet.ReadUInt8();
    int nAmount = packet.ReadInt32();
    int nEnchant = packet.ReadInt32();
    m_nTime = packet.ReadInt64();
    m_n20 = packet.ReadInt32();
    m_n28 = packet.ReadInt64();
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_140523c40(nItemId, nAmount, 0))
    {
        spItem->SetItemUid(nUid);
        spItem->SetSlot(nRarity);
        spItem->SetCountClamped(nEnchant);
        spItem->ReadFromStream(packet);
        m_item = spItem;
    }
}

CMailAttachItem::~CMailAttachItem()
{
    Reset();
}

void CMailAttachItem::Reset()
{
    m_item = 0;
    m_nTime = 0;
    m_n20 = 0;
    m_n28 = 0;
}

int CMailAttachItem::GetItemId()
{
    if (m_item == 0)
        return -1;
    return m_item->GetSlot();
}

// ---- CMailAdItem ----------------------------------------------------------------------------------------------------

void CMailAdItem::Read(CInputStream* stream)
{
    m_n18 = stream->ReadInt32();
    m_n1c = stream->ReadInt32();
    m_n20 = stream->ReadInt32();
    m_n24 = stream->ReadInt32();
    m_n28 = stream->ReadInt64();
    m_n30 = stream->ReadInt64();
    m_n38 = stream->ReadInt64();
}

CMailAdItem::CMailAdItem()
{
    m_n18 = 0;
    m_n1c = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_n28 = 0;
    m_n30 = 0;
    m_n38 = 0;
}

// ~CMailAdItem (0x140692c20) is implicit.

// ---- CMailSendKeep --------------------------------------------------------------------------------------------------

CMailSendKeep::CMailSendKeep(MS2Ptr<CItem> item)
{
    m_kind = 1;
    m_attach = 0;
    m_item = item;
}

CMailSendKeep::CMailSendKeep(Unk_MailAttachPtr attach)
{
    m_kind = 0;
    m_attach = attach;
    m_item = 0;
}

CMailSendKeep::~CMailSendKeep()
{
    m_attach = 0;
    m_item = 0;
}

__int64 CMailSendKeep::FUN_14068fe20(int slot)
{
    if (m_item.get() && m_item->GetRarity() == slot)
        return m_item->GetTotalSellPrice();
    if (m_attach.get() ? true : false)
    {
        if ((m_attach->m_item.get() ? true : false) && m_attach->m_item->GetRarity() == slot)
            return m_attach->m_item->GetTotalSellPrice();
    }
    return 0;
}

// ---- Unk_MailTimeRange / benefit list -------------------------------------------------------------------------------

Unk_MailTimeRange::Unk_MailTimeRange()
{
    m_nBegin = 0;
    m_nClaim = 0;
}

bool Unk_MailTimeRange::IsClaimed() const
{
    return m_nBegin > 0 && m_nClaim != 0;
}

bool Unk_MailTimeRange::IsUnclaimed() const
{
    return m_nBegin > 0 && m_nClaim == 0;
}

bool Unk_MailTimeRange::TryClaim(__int64 claim)
{
    if (m_nClaim != 0)
        return false;
    m_nClaim = claim;
    return true;
}

void Unk_MailTimeRange::Read(CInputStream* stream)
{
    m_nBegin = stream->ReadInt64();
    m_nClaim = stream->ReadInt64();
}

Unk_MailBenefitList::Unk_MailBenefitList() {}
Unk_MailBenefitList::~Unk_MailBenefitList() {}

// ---- CMailInfo ------------------------------------------------------------------------------------------------------

CMailInfo::CMailInfo(int kind)
    : m_nKind(kind)
{
    m_nId = 0;
    m_n28 = 0;
    m_n38 = 0;
    m_n24 = 0;
    m_attach.SetCount(5);
    for (int i = 0; i < 5; i++)
        m_attach[i] = 0;
    m_ads.SetCount(5);
    for (int i = 0; i < 5; i++)
        m_ads[i] = 0;
    m_n100 = 0;
    m_n108 = 0;
    m_n110 = 0;
    m_n118 = 0;
    m_nState = 0;
    m_n128 = 0;
    m_n130 = 1;
}

CMailInfo::~CMailInfo()
{
    m_attach.RemoveAll();
    m_ads.RemoveAll();
}

void CMailInfo::SetId(__int64 id) { m_nId = id; }
__int64 CMailInfo::GetId() { return m_nId; }
int CMailInfo::GetKind() { return m_nKind; }

void CMailInfo::SetSender(__int64 value, CStringW text)
{
    m_n28 = value;
    m_str30 = text;
}

__int64 CMailInfo::FUN_1406903f0() { return m_n28; }
CStringW CMailInfo::GetSenderName() const { return m_str30; }
void CMailInfo::FUN_140690460(__int64 value) { m_n38 = value; }
__int64 CMailInfo::FUN_140690480() { return m_n38; }
void CMailInfo::FUN_1406904a0(CStringW text) { m_str40 = text; }
CStringW CMailInfo::FUN_1406904f0() const { return m_str40; }

void CMailInfo::SetTitleAndContent(CStringW a, CStringW b)
{
    m_str48 = a;
    m_str50 = b;
}

CStringW CMailInfo::GetTitle() const { return m_str48; }
CStringW CMailInfo::GetContent() const { return m_str50; }

void CMailInfo::SetAttachment(int slot, Unk_MailAttachPtr attach)
{
    if (slot < 0 || slot >= 5)
        return;
    m_attach[slot] = attach;
}

void CMailInfo::SetAttachmentReceiveTime(int slot, __int64 time)
{
    if (slot < 0 || slot >= 5)
        return;
    Unk_MailAttachPtr spAttach(m_attach[slot]);
    if (spAttach == 0)
        return;
    if (spAttach->m_nTime != 0)
        return;
    spAttach->m_nTime = time;
    SetState(1);
}

Unk_MailAttachPtr CMailInfo::GetAttachment(int slot) const
{
    if (slot < 0 || slot >= 5)
        return Unk_MailAttachPtr(0);
    Unk_MailAttachPtr spAttach(m_attach[slot]);
    return spAttach;
}

int CMailInfo::GetUnreceivedAttachmentCount() const
{
    int nCount = 0;
    for (unsigned i = 0; i < m_attach.GetCount(); i++)
    {
        Unk_MailAttachPtr spAttach(m_attach[i]);
        if (spAttach == 0)
            continue;
        if (spAttach->m_nTime > 0)
            continue;
        nCount++;
    }
    return nCount;
}

__int64 CMailInfo::GetAttachmentReceiveTime(int slot) const
{
    Unk_MailAttachPtr spAttach = GetAttachment(slot);
    if (spAttach == 0)
        return 0;
    return spAttach->m_nTime;
}

int CMailInfo::FUN_1406909b0() const
{
    if (m_rangeB0.IsClaimed())
        return 1;
    if (m_rangeC0.IsClaimed())
        return 1;
    if (m_rangeD0.IsClaimed())
        return 1;
    int nBenefits = ((Unk_CommonPriceRecordList&)m_benefits).GetCount();
    for (int i = 0; i < nBenefits; i++)
    {
        if (((Unk_CommonPriceRecord&)m_benefits.m_array[i]).IsUsed())
            return 1;
    }
    for (unsigned i = 0; i < m_attach.GetCount(); i++)
    {
        Unk_MailAttachPtr spAttach(m_attach[i]);
        if (spAttach == 0)
            continue;
        if (spAttach->m_nTime > 0)
            return 1;
    }
    if (m_nKind == 200 && m_n130 == 1)
        return 1;
    return 0;
}

int CMailInfo::FUN_140690b80() const
{
    if (m_rangeB0.IsUnclaimed())
        return 1;
    if (m_rangeC0.IsUnclaimed())
        return 1;
    if (m_rangeD0.IsUnclaimed())
        return 1;
    if (((Unk_CommonPriceRecordList&)m_benefits).HasAvailable())
        return 1;
    for (unsigned i = 0; i < m_attach.GetCount(); i++)
    {
        Unk_MailAttachPtr spAttach(m_attach[i]);
        if (spAttach == 0)
            continue;
        if (spAttach->m_nTime == 0)
            return 1;
    }
    if (m_nKind == 200 && m_n128 > GetServerTime() && m_n130 == 0)
        return 1;
    return 0;
}

void CMailInfo::FUN_140690d20(__int64 a, __int64 b)
{
    m_rangeB0.m_nBegin = a;
    m_rangeB0.m_nClaim = b;
}

void CMailInfo::ClaimRangeB0(__int64 time)
{
    if (m_rangeB0.TryClaim(time) == 1)
        SetState(1);
}

__int64 CMailInfo::GetRangeB0Begin() const { return m_rangeB0.m_nBegin; }
__int64 CMailInfo::GetRangeB0Claim() const { return m_rangeB0.m_nClaim; }

void CMailInfo::ClaimRangeC0(__int64 time)
{
    if (m_rangeC0.TryClaim(time) == 1)
        SetState(1);
}

__int64 CMailInfo::GetRangeC0Begin() const { return m_rangeC0.m_nBegin; }
__int64 CMailInfo::FUN_140690e60() const { return m_rangeC0.m_nClaim; }

void CMailInfo::FUN_140690e80(__int64 time)
{
    if (m_rangeD0.TryClaim(time) == 1)
        SetState(1);
}

__int64 CMailInfo::FUN_140690ed0() const { return m_rangeD0.m_nBegin; }
__int64 CMailInfo::FUN_140690ef0() const { return m_rangeD0.m_nClaim; }

void CMailInfo::MarkBenefitsUsed(__int64)
{
    int nBenefits = ((Unk_CommonPriceRecordList&)m_benefits).GetCount();
    for (int i = 0; i < nBenefits; i++)
    {
        if (((Unk_CommonPriceRecord&)m_benefits.m_array[i]).MarkUsed())
            SetState(1);
    }
}

bool CMailInfo::FindBenefit(int type, int sub, Unk_MailBenefit* out) const
{
    int nBenefits = ((Unk_CommonPriceRecordList&)m_benefits).GetCount();
    for (int i = 0; i < nBenefits; i++)
    {
        Unk_MailBenefit& benefit = m_benefits.m_array[i];
        if (benefit.m_nType == type && benefit.m_nSub == sub)
        {
            *out = benefit;
            return true;
        }
    }
    return false;
}

// @0x140691090
void CMailInfo::MarkRead()
{
    if (IsRead())
        return;
    SetState(1);
    m_n100 = FUN_140692760();
}

void CMailInfo::SetReadTime(__int64 value) { m_n100 = value; }
__int64 CMailInfo::GetReadTime() const { return m_n100; }

// @0x140691130
int CMailInfo::IsRead()
{
    if (m_n100 == 0)
        return 0;
    return 1;
}

__int64 CMailInfo::GetExpireTime() const { return m_n108; }

int CMailInfo::IsExpired() const
{
    __int64 now = FUN_140692760();
    if (now >= m_n108)
        return 1;
    return 0;
}

__int64 CMailInfo::FUN_1406911c0() const { return m_n118; }
void CMailInfo::SetState(int state) { m_nState = state; }
int CMailInfo::GetState() const { return m_nState; }

int CMailInfo::HasAttachment()
{
    Unk_MailAttachPtr spAttach(0);
    for (int i = 0; i < 5; i++)
    {
        spAttach = GetAttachment(i);
        if (spAttach.get() && spAttach->m_nTime == 0)
            return 1;
    }
    if (m_rangeB0.IsUnclaimed())
        return 1;
    if (m_rangeC0.IsUnclaimed())
        return 1;
    if (m_rangeD0.IsUnclaimed())
        return 1;
    if (((Unk_CommonPriceRecordList&)m_benefits).HasAvailable())
        return 1;
    return 0;
}

// @0x1406922d0
CStringW CMailInfo::GetDateString() const
{
    CMsTime tm(m_n118);
    return FUN_14083bdc0(tm, 1, CStringW(L"/"), CStringW(L":"));
}

void CMailInfo::SetAd(int slot, MS2Ptr<CMailAdItem> ad)
{
    if (slot < 0 || slot >= 5)
        return;
    m_ads[slot] = ad;
}

void CMailInfo::FUN_140692420(__int64 time)
{
    m_n130 = time ? 1 : 0;
    SetState(1);
}

MS2Ptr<CMailAdItem> CMailInfo::GetAd(int slot) const
{
    if (slot < 0 || slot >= 5)
        return MS2Ptr<CMailAdItem>(0);
    return m_ads[slot];
}

__int64 CMailInfo::FUN_140692510() const
{
    __int64 total = 0;
    for (int i = 0; i < 5; i++)
    {
        const MS2Ptr<CMailAdItem>& spAd = m_ads[i];
        if (spAd == 0)
            break;
        total += spAd->m_n30;
    }
    return total;
}

__int64 CMailInfo::FUN_1406925a0() const
{
    __int64 total = 0;
    for (int i = 0; i < 5; i++)
    {
        const MS2Ptr<CMailAdItem>& spAd = m_ads[i];
        if (spAd == 0)
            break;
        total += spAd->m_n38;
    }
    return total;
}

int CMailInfo::FUN_140692630() const
{
    if (m_n128 == 0)
        return 0;
    __int64 now = GetServerTime();
    return now > m_n128;
}

bool CMailInfo::FUN_140692690(int kind) const
{
    switch (kind)
    {
    case 3: case 0x65: case 0x6b: case 0x6d: case 0x6f:
        return true;
    }
    return false;
}

bool CMailInfo::FUN_1406926e0(int kind) const
{
    switch (kind)
    {
    case 1: case 2:
        return true;
    }
    return false;
}

bool CMailInfo::FUN_140692720(int kind) const
{
    switch (kind)
    {
    case 3: case 0x64: case 0x67:
        return true;
    }
    return false;
}

__int64 CMailInfo::FUN_140692760() const
{
    __int64 now = GetServerTime();
    return now;
}

// @0x1406913e0
void CMailInfo::Read(CInPacket& packet)
{
    m_nKind = packet.ReadUInt8();
    m_nId = packet.ReadInt64();
    m_n28 = packet.ReadInt64();
    m_str30 = packet.ReadUnicodeString();
    m_str48 = packet.ReadUnicodeString();
    m_str50 = packet.ReadUnicodeString();
    m_str58 = packet.ReadUnicodeString();
    m_str60 = packet.ReadUnicodeString();
    if (m_nKind == 200)
    {
        int nAds = packet.ReadUInt8();
        for (int i = 0; i < nAds; i++)
        {
            MS2Ptr<CMailAdItem> spAd(new CMailAdItem);
            spAd->Read(&static_cast<CInputStream&>(packet));
            SetAd(i, spAd);
        }
        m_str120 = packet.ReadUnicodeString();
        m_n128 = packet.ReadInt64();
        m_n130 = packet.ReadUInt8();
    }
    else
    {
        int nAttach = packet.ReadUInt8();
        for (int i = 0; i < nAttach; i++)
        {
            Unk_MailAttachPtr spAttach(new CMailAttachItem(packet));
            SetAttachment(spAttach->GetItemId(), spAttach);
        }
    }
    m_rangeB0.Read(&static_cast<CInputStream&>(packet));
    m_rangeC0.Read(&static_cast<CInputStream&>(packet));
    m_rangeD0.Read(&static_cast<CInputStream&>(packet));
    ((Unk_CommonPriceRecordList&)m_benefits).Read(&static_cast<CInputStream&>(packet));
    m_n100 = packet.ReadInt64();
    m_n108 = packet.ReadInt64();
    m_n118 = packet.ReadInt64();
    m_str68 = packet.ReadUnicodeString();
    if (FUN_140692690(m_nKind))
    {
        MS2Ptr<CSystemMailContent> spTpl(0);
        if (m_str50.SpanIncluding(L"0123456789") == m_str50)
        {
            int nTplId = _wtoi(m_str50);
            spTpl = CSystemMailContent::GetMail(nTplId);
        }
        if (spTpl.get())
        {
            if (m_str30.IsEmpty())
                m_str30 = spTpl->m_strSender;
            m_str48 = spTpl->m_strSubject;
            m_str50 = spTpl->m_strContent;
            TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->ReplaceValueWords(m_str30);
            TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->ReplaceValueWords(m_str48);
            TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->ReplaceValueWords(m_str50);
        }
        else
        {
            TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->ReplaceObjectAndValueWords(m_str50);
        }
    }
    if (!FUN_1406926e0(m_nKind))
    {
        m_str30 = GetLocalizedText(m_str30);
        m_str48 = GetLocalizedText(m_str48);
        m_str50 = GetLocalizedText(m_str50);
        MailText repl0(0);
        repl0.Load(m_str30, L"");
        MailText repl1(1);
        repl1.Load(m_str48, m_str58);
        MailText repl2(2);
        repl2.Load(m_str50, m_str60);
        m_str30 = repl0.ResolveTitle();
        m_str48 = repl1.ResolveTitle();
        m_str50 = repl2.ResolveTitle();
    }
    if (FUN_140692720(m_nKind))
        TSingleton<CReservedWordTable>::GetInstance()/*C3:TSingleton<CReservedWordTable>::GetInstance*/->ReplaceObjectAndValueWords(m_str50);
}
