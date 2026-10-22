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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

__int64 FUN_140869440();                                                       // current server time
MS2Ptr<Unk_MailTpl> FUN_140851e50(int id);                                     // mail template by id
CStringW FUN_14083d340(CStringW);
CStringW FUN_14083bdc0(const CMsTime& t, bool n, CStringW strSep, CStringW strSep2);
bool FUN_14025cd60(const CStringW&, const CStringW&);
class Unk_MailTextFilter { public: void FUN_1416fb300(CStringW& str); void FUN_1416fb340(CStringW& str); };
Unk_MailTextFilter* FUN_1403b4750();

class Unk_ReplMap { char m_pad[0x18]; };
class Unk_ReplList { char m_pad[0x20]; };
void FUN_140660c40(Unk_ReplList*);
void FUN_140660c80(Unk_ReplMap*);
// Placeholder substitution builder: feed (key, value) pairs, then read the result.
class Unk_StrRepl {
public:
    Unk_StrRepl(int mode);                                                     // 0x14065cfa0
    // @0x140692c60 MS2-FUNCTIONAL: inline dtor body order differs
    ~Unk_StrRepl() { FUN_140660c40(&m_list); FUN_140660c80(&m_map); }          // 0x140692c60
    void FUN_14065d590(const CStringW& key, const CStringW& value);
    CStringW FUN_14065d9d0();
private:
    void* m_unk_00;
    Unk_ReplMap m_map;
    Unk_ReplList m_list;
};
MS2_CHECK_SIZE(Unk_StrRepl, 0x40);

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
        FUN_14068fac0();
    }
    else
    {
        m_item = item->FUN_140524250();
        m_item->FUN_140526b70(index);
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
        spItem->FUN_140526a70(nUid);
        spItem->FUN_140526b70(nRarity);
        spItem->FUN_140526c70(nEnchant);
        spItem->FUN_140524eb0(packet);
        m_item = spItem;
    }
}

CMailAttachItem::~CMailAttachItem()
{
    FUN_14068fac0();
}

void CMailAttachItem::FUN_14068fac0()
{
    m_item = 0;
    m_nTime = 0;
    m_n20 = 0;
    m_n28 = 0;
}

int CMailAttachItem::FUN_14068fb10()
{
    if (m_item == 0)
        return -1;
    return m_item->FUN_140526b50();
}

// ---- CMailAdItem ----------------------------------------------------------------------------------------------------

void CMailAdItem::FUN_14068fb60(CInputStream* stream)
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

// @0x140692c20
// MS2-FUNCTIONAL: exe dtor stores no vptr
CMailAdItem::~CMailAdItem() {}

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
    if (m_item.get() && m_item->FUN_140526bd0() == slot)
        return m_item->FUN_140527640();
    if (m_attach.get() ? true : false)
    {
        if ((m_attach->m_item.get() ? true : false) && m_attach->m_item->FUN_140526bd0() == slot)
            return m_attach->m_item->FUN_140527640();
    }
    return 0;
}

// ---- Unk_MailTimeRange / benefit list -------------------------------------------------------------------------------

Unk_MailTimeRange::Unk_MailTimeRange()
{
    m_nBegin = 0;
    m_nClaim = 0;
}

bool Unk_MailTimeRange::FUN_1406936a0() const
{
    return m_nBegin > 0 && m_nClaim != 0;
}

bool Unk_MailTimeRange::FUN_1406936e0() const
{
    return m_nBegin > 0 && m_nClaim == 0;
}

bool Unk_MailTimeRange::FUN_140693b00(__int64 claim)
{
    if (m_nClaim != 0)
        return false;
    m_nClaim = claim;
    return true;
}

void Unk_MailTimeRange::FUN_140693300(CInputStream* stream)
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

void CMailInfo::FUN_140690330(__int64 id) { m_nId = id; }
__int64 CMailInfo::FUN_140690350() { return m_nId; }
int CMailInfo::FUN_140690370() { return m_nKind; }

void CMailInfo::FUN_140690390(__int64 value, CStringW text)
{
    m_n28 = value;
    m_str30 = text;
}

__int64 CMailInfo::FUN_1406903f0() { return m_n28; }
CStringW CMailInfo::FUN_140690410() const { return m_str30; }
void CMailInfo::FUN_140690460(__int64 value) { m_n38 = value; }
__int64 CMailInfo::FUN_140690480() { return m_n38; }
void CMailInfo::FUN_1406904a0(CStringW text) { m_str40 = text; }
CStringW CMailInfo::FUN_1406904f0() const { return m_str40; }

void CMailInfo::FUN_140690540(CStringW a, CStringW b)
{
    m_str48 = a;
    m_str50 = b;
}

CStringW CMailInfo::FUN_1406905b0() const { return m_str48; }
CStringW CMailInfo::FUN_140690600() const { return m_str50; }

void CMailInfo::FUN_140690650(int slot, Unk_MailAttachPtr attach)
{
    if (slot < 0 || slot >= 5)
        return;
    m_attach[slot] = attach;
}

void CMailInfo::FUN_1406906c0(int slot, __int64 time)
{
    if (slot < 0 || slot >= 5)
        return;
    Unk_MailAttachPtr spAttach(m_attach[slot]);
    if (spAttach == 0)
        return;
    if (spAttach->m_nTime != 0)
        return;
    spAttach->m_nTime = time;
    FUN_1406911e0(1);
}

Unk_MailAttachPtr CMailInfo::FUN_140690790(int slot) const
{
    if (slot < 0 || slot >= 5)
        return Unk_MailAttachPtr(0);
    Unk_MailAttachPtr spAttach(m_attach[slot]);
    return spAttach;
}

int CMailInfo::FUN_140690840() const
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

__int64 CMailInfo::FUN_140690920(int slot) const
{
    Unk_MailAttachPtr spAttach = FUN_140690790(slot);
    if (spAttach == 0)
        return 0;
    return spAttach->m_nTime;
}

int CMailInfo::FUN_1406909b0() const
{
    if (m_rangeB0.FUN_1406936a0())
        return 1;
    if (m_rangeC0.FUN_1406936a0())
        return 1;
    if (m_rangeD0.FUN_1406936a0())
        return 1;
    int nBenefits = m_benefits.FUN_14026a4b0();
    for (int i = 0; i < nBenefits; i++)
    {
        if (m_benefits.m_array[i].FUN_14026a170())
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
    if (m_rangeB0.FUN_1406936e0())
        return 1;
    if (m_rangeC0.FUN_1406936e0())
        return 1;
    if (m_rangeD0.FUN_1406936e0())
        return 1;
    if (m_benefits.FUN_14026a510())
        return 1;
    for (unsigned i = 0; i < m_attach.GetCount(); i++)
    {
        Unk_MailAttachPtr spAttach(m_attach[i]);
        if (spAttach == 0)
            continue;
        if (spAttach->m_nTime == 0)
            return 1;
    }
    if (m_nKind == 200 && m_n128 > FUN_140869440() && m_n130 == 0)
        return 1;
    return 0;
}

void CMailInfo::FUN_140690d20(__int64 a, __int64 b)
{
    m_rangeB0.m_nBegin = a;
    m_rangeB0.m_nClaim = b;
}

void CMailInfo::FUN_140690d60(__int64 time)
{
    if (m_rangeB0.FUN_140693b00(time) == 1)
        FUN_1406911e0(1);
}

__int64 CMailInfo::FUN_140690db0() const { return m_rangeB0.m_nBegin; }
__int64 CMailInfo::FUN_140690dd0() const { return m_rangeB0.m_nClaim; }

void CMailInfo::FUN_140690df0(__int64 time)
{
    if (m_rangeC0.FUN_140693b00(time) == 1)
        FUN_1406911e0(1);
}

__int64 CMailInfo::FUN_140690e40() const { return m_rangeC0.m_nBegin; }
__int64 CMailInfo::FUN_140690e60() const { return m_rangeC0.m_nClaim; }

void CMailInfo::FUN_140690e80(__int64 time)
{
    if (m_rangeD0.FUN_140693b00(time) == 1)
        FUN_1406911e0(1);
}

__int64 CMailInfo::FUN_140690ed0() const { return m_rangeD0.m_nBegin; }
__int64 CMailInfo::FUN_140690ef0() const { return m_rangeD0.m_nClaim; }

void CMailInfo::FUN_140690f10(__int64)
{
    int nBenefits = m_benefits.FUN_14026a4b0();
    for (int i = 0; i < nBenefits; i++)
    {
        if (m_benefits.m_array[i].FUN_14026a220())
            FUN_1406911e0(1);
    }
}

bool CMailInfo::FUN_140690fa0(int type, int sub, Unk_MailBenefit* out) const
{
    int nBenefits = m_benefits.FUN_14026a4b0();
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
void CMailInfo::FUN_140691090()
{
    if (FUN_140691130())
        return;
    FUN_1406911e0(1);
    m_n100 = FUN_140692760();
}

void CMailInfo::FUN_1406910e0(__int64 value) { m_n100 = value; }
__int64 CMailInfo::FUN_140691110() const { return m_n100; }

// @0x140691130
int CMailInfo::FUN_140691130()
{
    if (m_n100 == 0)
        return 0;
    return 1;
}

__int64 CMailInfo::FUN_140691160() const { return m_n108; }

int CMailInfo::FUN_140691180() const
{
    __int64 now = FUN_140692760();
    if (now >= m_n108)
        return 1;
    return 0;
}

__int64 CMailInfo::FUN_1406911c0() const { return m_n118; }
void CMailInfo::FUN_1406911e0(int state) { m_nState = state; }
int CMailInfo::FUN_140691200() const { return m_nState; }

int CMailInfo::FUN_140691220()
{
    Unk_MailAttachPtr spAttach(0);
    for (int i = 0; i < 5; i++)
    {
        spAttach = FUN_140690790(i);
        if (spAttach.get() && spAttach->m_nTime == 0)
            return 1;
    }
    if (m_rangeB0.FUN_1406936e0())
        return 1;
    if (m_rangeC0.FUN_1406936e0())
        return 1;
    if (m_rangeD0.FUN_1406936e0())
        return 1;
    if (m_benefits.FUN_14026a510())
        return 1;
    return 0;
}

// @0x1406922d0
CStringW CMailInfo::FUN_1406922d0() const
{
    CMsTime tm(m_n118);
    return FUN_14083bdc0(tm, 1, CStringW(L"/"), CStringW(L":"));
}

void CMailInfo::FUN_1406923a0(int slot, MS2Ptr<CMailAdItem> ad)
{
    if (slot < 0 || slot >= 5)
        return;
    m_ads[slot] = ad;
}

void CMailInfo::FUN_140692420(__int64 time)
{
    m_n130 = time ? 1 : 0;
    FUN_1406911e0(1);
}

MS2Ptr<CMailAdItem> CMailInfo::FUN_140692480(int slot) const
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
    __int64 now = FUN_140869440();
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
    __int64 now = FUN_140869440();
    return now;
}

// @0x1406913e0
// MS2-FUNCTIONAL: 3.8 KB packet reader; local layout differs
void CMailInfo::FUN_1406913e0(CInPacket& packet)
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
            spAd->FUN_14068fb60(&packet);
            FUN_1406923a0(i, spAd);
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
            FUN_140690650(spAttach->FUN_14068fb10(), spAttach);
        }
    }
    m_rangeB0.FUN_140693300(&packet);
    m_rangeC0.FUN_140693300(&packet);
    m_rangeD0.FUN_140693300(&packet);
    m_benefits.FUN_14026a3d0(&packet);
    m_n100 = packet.ReadInt64();
    m_n108 = packet.ReadInt64();
    m_n118 = packet.ReadInt64();
    m_str68 = packet.ReadUnicodeString();
    if (FUN_140692690(m_nKind))
    {
        MS2Ptr<Unk_MailTpl> spTpl(0);
        if (FUN_14025cd60(m_str50.SpanIncluding(L"0123456789"), m_str50))
        {
            int nTplId = _wtoi(m_str50);
            spTpl = FUN_140851e50(nTplId);
            if (spTpl.get())
            {
                if (m_str30.IsEmpty())
                {
                    m_str30 = spTpl->m_str38;
                    m_str48 = spTpl->m_str40;
                    m_str50 = spTpl->m_str48;
                }
                FUN_1403b4750()->FUN_1416fb340(m_str30);
                FUN_1403b4750()->FUN_1416fb340(m_str48);
                FUN_1403b4750()->FUN_1416fb340(m_str50);
            }
        }
        else
        {
            FUN_1403b4750()->FUN_1416fb300(m_str50);
        }
    }
    if (!FUN_1406926e0(m_nKind))
    {
        m_str30 = FUN_14083d340(m_str30);
        m_str48 = FUN_14083d340(m_str48);
        m_str50 = FUN_14083d340(m_str50);
        Unk_StrRepl repl0(0);
        repl0.FUN_14065d590(m_str30, CStringW(L""));
        Unk_StrRepl repl1(1);
        repl1.FUN_14065d590(m_str48, m_str58);
        Unk_StrRepl repl2(2);
        repl2.FUN_14065d590(m_str50, m_str60);
        m_str30 = repl0.FUN_14065d9d0();
        m_str48 = repl1.FUN_14065d9d0();
        m_str50 = repl2.FUN_14065d9d0();
    }
    if (FUN_140692720(m_nKind))
        FUN_1403b4750()->FUN_1416fb300(m_str50);
}
