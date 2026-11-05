// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMesoMarketMan: the meso market (merat for meso listings):
// the market page and the own listing, the limits, the handlers of the packet 0x81 replies and the rows the market UI
// shows for a listing (CMesoMarketProductCli). See placeholder/cmesomarketman.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\mesomarketproductcli.cpp
// MS2-RANGE: 0x140d6d8c0-0x140d72a60 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mesomarketproductcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cmesomarketman.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/client/ms2/blockmanager.h"  // C3: CBlockManager::FindBlockedAction, BlockPtr
#include "ms2/commonfiles/os.h"   // C3: Unk_OSInput::Read7
#include "ms2/placeholder/clockcriticalsection.h"   // Unk_CriticalSectionLock (was a local lock view)

// ---- out-of-unit callees ----
__int64 GetServerTime();                                // the server time
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
CStringW GetStringCommonByKey(const CStringW& strKey);         // string table text of a key
CStringW GetStringCommon(int nId);                        // string table text by id
CStringW FUN_140298ea0(CStringW strKey);                // localized string
CStringW FUN_1412757d0(__int64 n);                      // number text
CStringW FUN_1409404f0(__int64 n);                      // number text, grouped
CStringW FUN_140719a80(unsigned __int64 n);                      // number text
CStringW FUN_1418fe870(int nCurrency, int* pnVSpace, unsigned nItemId);   // the "<img>" source of a token kind
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_140710590(COutPacket&);                        // send
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
class CUIService;

// The penalty (block) record a result code asks for.
class Unk_InventoryStateManager* FUN_140a6a830();   // C3: was FUN_140a6a830
void FUN_140a2ff20(const BlockPtr& spBlock, int nKind, unsigned __int64 n);   // the blocked-action notice

extern __int64 DAT_143ab2898;                           // the highest meso a listing may ask

typedef __int64 i64;

// A notice box with the text of a key.
#define MESO_NOTICE(key) \
    { FUN_140d74390(FUN_140298ea0(CStringW(key)), 0, FUN_140b240b0()); }

CStringW FUN_140d6e230(int nCurrency);
i64 FUN_140d706c0(i64* pValue, i64 nMin, i64 nMax);
CStringW FUN_140d70320(CStringW strKey, const float& fRate, const i64& nLow, const i64& nHigh);
CInputStream& FUN_140d70110(CInputStream& in, MS2Ptr<CMesoMarketProductCli>& sp);
CInputStream& FUN_140d701a0(CInputStream& in, CMesoMarketMan::ProductMap& map);
void FUN_140d70240(CInputStream& in, CMesoMarketMan::ProductArray& arr);

// @0x140d6d8c0
CMesoMarketProductCli::CMesoMarketProductCli()
{
}

// @0x140d6d900
bool CMesoMarketProductCli::IsExpired()
{
    CMsTime now(GetServerTime());
    return now >= m_40;
}

// @0x140d6d940
void CMesoMarketProductCli::FillOwnRow(ASObj& row)
{
    FillCommonRow(row);
    if (IsExpired())
    {
        row.FUN_1409c0e60("subText", L"$s_mesoMarket_own_product_expired");
        row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_cancel_sell_expired");
    }
    else
    {
        CStringW strTime;
        {
            CStringW strKey(L"s_mesoMarket_endSellTime");
            FUN_141b70f90(CMsTime(m_40), GetStringCommonByKey(strKey), strTime);
        }
        row.FUN_1407cbb20("subText", CStringW(strTime));
        row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_cancel_sale");
    }
}

// @0x140d6dab0
void CMesoMarketProductCli::FillMarketRow(ASObj& row)
{
    FillCommonRow(row);
    row.FUN_1409c0e60("subText", L"");
    row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_buy_product");
    if (m_b50)
        row.FUN_1409c0e60("subText", L"$s_mesoMarket_own_product");
}

// @0x140d6db30
void CMesoMarketProductCli::FillCommonRow(ASObj& row)
{
    __int64 nBase = *reinterpret_cast<Common::Constants::Value<__int64>*>((char*)((class Unk_CMesoMarketConfig*)FUN_1401d3200()) + 0x6018)->Get();
    __int64 nUnit = m_n28;
    if (m_n20 > nBase)
        nUnit = nUnit / (m_n20 / nBase);
    CStringW strBase = FUN_1412757d0(nBase);
    row.FUN_1407cbb20("marketSN", FUN_140719a80(m_n18));
    row.FUN_1407cbb20("sellMeso", FUN_1409404f0(m_n20));
    row.FUN_1407cbb20("buyMerat", FUN_14028dfa0<CStringW, CStringW>(CStringW(L"s_mesoMarket_listItem_buyMerat"), FUN_1409404f0(m_n28),
                                                FUN_140d6e230(*reinterpret_cast<unsigned*>(reinterpret_cast<Common::Constants::Value<int>*>((char*)((class Unk_CMesoMarketConfig*)FUN_1401d3200()) + 0x6140)->Get()))));
    if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0xf4))
    {
        row.FUN_1407cbb20("sellMesoText", FUN_14028dfa0<CStringW>(CStringW(L"s_mesoMarket_listItem_sellMesoText"), FUN_1412757d0(m_n20)));
        row.FUN_1407cbb20("buyMeratPerUnit", FUN_14028dfa0<CStringW, CStringW>(CStringW(L"s_mesoMarket_listItem_unitPrice"), strBase, FUN_1409404f0(nUnit)));
    }
}

// @0x140d6df30
Unk_MesoLimits::Unk_MesoLimits()
{
    m_bLoaded = 0;
    m_fRateA = 0;
    m_fRateB = 0;
    m_nBase = 0;
    m_n18 = 0;
    m_n1C = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_nMin = 0;
    m_nMax = 0;
}

// @0x140d6dfc0
void Unk_MesoLimits::Read(CInPacket& packet)
{
    m_fRateA = packet.ReadFloat();
    m_fRateB = packet.ReadFloat();
    m_nBase = packet.ReadInt64();
    m_n18 = packet.ReadInt32();
    m_n1C = packet.ReadInt32();
    m_n20 = packet.ReadInt32();
    m_n24 = packet.ReadInt32();
    m_n28 = packet.ReadInt32();
    m_nMin = packet.ReadInt32();
    m_nMax = packet.ReadInt32();
    m_bLoaded = 1;
}

// @0x140d6e1f0
float Unk_MesoLimits::FUN_140d6e1f0()
{
    return m_fRateA * 100.0f;
}

// @0x140d6e210
float Unk_MesoLimits::FUN_140d6e210()
{
    return m_fRateB * 100.0f;
}

// @0x140d6e230
CStringW FUN_140d6e230(int nCurrency)
{
    int nVSpace = 0;
    CStringW strSrc = FUN_1418fe870(nCurrency, &nVSpace, 0);
    return StringFormat<CStringW, int>(L"<img src='{0}' vspace='{1}'/>", strSrc, nVSpace);
}

// @0x140d6e2b0
CMesoMarketMan::CMesoMarketMan()
    : m_nOwn(0), m_nBuy(0)
{
}

// @0x140d6e380
CMesoMarketMan::~CMesoMarketMan()
{
}

// @0x140d6e400
void CMesoMarketMan::SendMesoMarket()
{
    m_arrMarket.RemoveAll();
    m_mapMarket.RemoveAll();
    m_mapOwn.RemoveAll();
    COutPacket packet(static_cast<int>(SendOp::MesoMarket), 0);
    packet.WriteUInt8(3);
    FUN_140710590(packet);
}

// @0x140d6e490
void CMesoMarketMan::OnMesoMarket(CInPacket& packet)
{
    int nSub = packet.ReadUInt8();
    switch (nSub)
    {
    case 0:
        OnMesoMarketResult(packet);
        break;
    case 1:
        OnMesoMarketLimits(packet);
        break;
    case 2:
        OnMesoMarketCounts(packet);
        break;
    case 4:
        OnMesoMarketOwnList(packet);
        break;
    case 5:
        OnMesoMarketRegistered(packet);
        break;
    case 6:
        OnMesoMarketOwnRemoved(packet);
        break;
    case 7:
        OnMesoMarketMarketList(packet);
        break;
    case 8:
        OnBuyResult(packet);
    }
}

// @0x140d6e5b0
void CMesoMarketMan::FillOwnRows(ASArray& rows)
{
    for (POSITION pos = m_mapOwn.GetHeadPosition(); pos != 0; m_mapOwn.GetNext(pos))
    {
        MS2Ptr<CMesoMarketProductCli> sp = m_mapOwn.GetValueAt(pos);
        ASObj row(2);
        sp->FillOwnRow(row);
        rows.PushValue(row.FUN_1422bb890());
    }
}

// @0x140d6e6d0
void CMesoMarketMan::FillMarketRows(ASArray& rows)
{
    for (unsigned i = 0; i < m_arrMarket.GetCount(); i++)
    {
        MS2Ptr<CMesoMarketProductCli> sp = m_arrMarket[i];
        ASObj row(2);
        sp->FillMarketRow(row);
        rows.PushValue(row.FUN_1422bb890());
    }
}

// @0x140d6e7e0
MS2Ptr<CMesoMarketProductCli> CMesoMarketMan::FindOwnProduct(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (m_mapOwn.Lookup(qwId, sp))
        return sp;
    return MS2Ptr<CMesoMarketProductCli>(0);
}

// @0x140d6e890
MS2Ptr<CMesoMarketProductCli> CMesoMarketMan::FindMarketProduct(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (m_mapMarket.Lookup(qwId, sp))
        return sp;
    return MS2Ptr<CMesoMarketProductCli>(0);
}

// @0x140d6e940
Unk_MesoLimits& CMesoMarketMan::GetLimits()
{
    return m_limits;
}

// @0x140d6e960
bool CMesoMarketMan::CanRegister(__int64 nMeso, __int64 nPrice)
{
    if (nMeso > DAT_143ab2898)
    {
        ShowResultMessage(5);
        return false;
    }
    if (m_mapOwn.GetCount() >= (unsigned)m_limits.m_n18)
    {
        ShowResultMessage(8);
        return false;
    }
    if (m_nOwn >= m_limits.m_n1C)
    {
        ShowResultMessage(0xd);
        return false;
    }
    __int64 nLow = GetMinPrice();
    __int64 nHigh = GetMaxPrice();
    if (nPrice < nLow || nPrice > nHigh)
    {
        ShowResultMessage(0x10);
        return false;
    }
    return true;
}

// @0x140d6ea50
bool CMesoMarketMan::CanBuy(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (!m_mapMarket.Lookup(qwId, sp))
    {
        ShowResultMessage(9);
        return false;
    }
    if (sp->m_b50)
    {
        ShowResultMessage(0xb);
        return false;
    }
    if (m_nBuy >= m_limits.m_n20)
    {
        ShowResultMessage(0xe);
        return false;
    }
    return true;
}

// @0x140d6eb50
int CMesoMarketMan::GetOwn()
{
    return m_nOwn;
}

// @0x140d6eb70
int CMesoMarketMan::GetBuy()
{
    return m_nBuy;
}

// @0x140d6eb90
void CMesoMarketMan::OnMesoMarketResult(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    ShowResultMessage(nCode);
}

// @0x140d6ebe0
void CMesoMarketMan::OnMesoMarketLimits(CInPacket& packet)
{
    m_limits.Read(packet);
}

// @0x140d6ec20
void CMesoMarketMan::OnMesoMarketCounts(CInPacket& packet)
{
    m_nOwn = packet.ReadInt32();
    m_nBuy = packet.ReadInt32();
}

// @0x140d6eca0
void CMesoMarketMan::OnMesoMarketOwnList(CInPacket& packet)
{
    m_mapOwn.RemoveAll();
    FUN_140d701a0(packet, m_mapOwn);
}

// @0x140d6ecf0
void CMesoMarketMan::OnMesoMarketRegistered(CInPacket& packet)
{
    MS2Ptr<CMesoMarketProductCli> sp(new CMesoMarketProductCli);
    sp->Read(packet);
    AddOwnProduct(sp);
    m_nOwn = packet.ReadInt32();
}

// @0x140d6ee00
void CMesoMarketMan::OnMesoMarketOwnRemoved(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    __int64 qwId = packet.ReadInt64();
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_mapOwn.RemoveKey(qwId);
    ShowResultMessage(nCode);
}

// @0x140d6eec0
void CMesoMarketMan::OnMesoMarketMarketList(CInPacket& packet)
{
    m_arrMarket.RemoveAll();
    m_mapMarket.RemoveAll();
    FUN_140d70240(packet, m_arrMarket);
    for (unsigned i = 0; i < m_arrMarket.GetCount(); ++i)
        m_mapMarket.SetAt(m_arrMarket[i]->GetValue18(), m_arrMarket[i]);
}

// @0x140d6efb0
void CMesoMarketMan::OnBuyResult(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    __int64 qwId = packet.ReadInt64();
    m_nBuy = packet.ReadInt32();
    Unk_CriticalSectionLock lock(m_lock, 1);
    switch (nCode)
    {
    case 0:
    case 0x11:
        RemoveMarketProduct(qwId);
    }
    ShowResultMessage(nCode);
}

// @0x140d6f0b0
void CMesoMarketMan::AddOwnProduct(MS2Ptr<CMesoMarketProductCli> sp)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_mapOwn.SetAt(sp->m_n18, sp);
}

// @0x140d6f130
void CMesoMarketMan::ShowResultMessage(int nCode)
{
    if (nCode == 0)
        return;
    switch (nCode)
    {
    case 2:
        MESO_NOTICE(L"s_mesoMarket_error_errorDB");
        break;
    case 3:
        MESO_NOTICE(L"s_mesoMarket_error_shutDown");
        break;
    case 4:
        MESO_NOTICE(L"s_mesoMarket_error_alreadyDbWork");
        break;
    case 5:
        MESO_NOTICE(L"s_mesoMarket_error_hasNotMeso");
        break;
    case 6:
        TSingleton<CUIService>::GetInstance()->FUN_141add1f0();
        break;
    case 7:
        TSingleton<CUIService>::GetInstance()->ShowLackMesoMarketTokenAsk();
        break;
    case 8:
        MESO_NOTICE(L"s_mesoMarket_error_maxCountOwnProduct");
        break;
    case 9:
        MESO_NOTICE(L"s_mesoMarket_error_notFoundProduct");
        break;
    case 10:
        MESO_NOTICE(L"s_mesoMarket_error_invalidSearchParam");
        break;
    case 0xb:
        MESO_NOTICE(L"s_mesoMarket_error_cannotBuyOwnProduct");
        break;
    case 0xc:
        MESO_NOTICE(L"s_mesoMarket_error_cannotBuyExpireDate");
        break;
    case 0xd:
        MESO_NOTICE(L"s_mesoMarket_error_maxCountRegister");
        break;
    case 0xe:
        MESO_NOTICE(L"s_mesoMarket_error_maxCountBuy");
        break;
    case 0xf:
        MESO_NOTICE(L"s_mesoMarket_error_invalidSaleMoney");
        break;
    case 0x10:
    {
        FUN_140d74390(FUN_140d70320(CStringW(L"s_mesoMarket_error_invalidBuyMerat"), m_limits.m_fRateB * 100.0f,
                                    GetMinPrice(), GetMaxPrice()),
                      0, FUN_140b240b0());
        break;
    }
    case 0x11:
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_mesoMarket_error_alreadySoldProduct")), 1, 1);
        break;
    case 0x12:
    case 0x13:
    {
        int nKind = (nCode == 0x13) ? 0x27 : 0x28;
        BlockPtr block = ((CBlockManager*)FUN_140a6a830())->FindBlockedAction(nKind);
        if (block.get() != 0)
            FUN_140a2ff20(block, nKind, 0);
    }
        break;
        break;      // the exe has a second jmp to the switch end here
    case 0x14:
    {
        FUN_140d74390(GetStringCommon(0xd56), 0, FUN_140b240b0());
        break;
    }
    default:
    {
        FUN_140d74390(FUN_14028dfa0<int>(CStringW(L"s_mesoMarket_error_unknown"), +nCode), 0, FUN_140b240b0());
    }
    }
}

// @0x140d6ff60
__int64 CMesoMarketMan::GetMinPrice()
{
    double dFactor = 1.0001 - m_limits.m_fRateB;
    __int64 nValue = (__int64)((double)m_limits.m_nBase * dFactor);
    return FUN_140d706c0(&nValue, m_limits.m_nMin, m_limits.m_nMax);
}

// @0x140d6ffe0
__int64 CMesoMarketMan::GetMaxPrice()
{
    double dFactor = 1.0001 + m_limits.m_fRateB;
    __int64 nValue = (__int64)((double)m_limits.m_nBase * dFactor);
    return FUN_140d706c0(&nValue, m_limits.m_nMin, m_limits.m_nMax);
}

// @0x140d70060
void CMesoMarketMan::RemoveMarketProduct(__int64 qwId)
{
    m_mapMarket.RemoveKey(qwId);
    for (unsigned i = 0; i < m_arrMarket.GetCount(); i++)
    {
        if (m_arrMarket[i]->GetValue18() == qwId)
        {
            m_arrMarket.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x140d70110
CInputStream& FUN_140d70110(CInputStream& in, MS2Ptr<CMesoMarketProductCli>& sp)
{
    sp.AssignRaw(new CMesoMarketProductCli);
    in >> *sp;
    return in;
}

// @0x140d701a0
CInputStream& FUN_140d701a0(CInputStream& in, CMesoMarketMan::ProductMap& map)
{
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; ++i)
    {
        MS2Ptr<CMesoMarketProductCli> sp;
        unsigned __int64 qwKey;
        FUN_140d70110(reinterpret_cast<CInputStream&>(reinterpret_cast<Unk_OSInput&>(in).Read7(reinterpret_cast<__int64&>(qwKey))), sp);
        map.SetAt(qwKey, sp);
    }
    return in;
}

// @0x140d70240
void FUN_140d70240(CInputStream& in, CMesoMarketMan::ProductArray& arr)
{
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; ++i)
    {
        MS2Ptr<CMesoMarketProductCli> sp(new CMesoMarketProductCli);
        sp->Read(in);
        arr.Add(sp);
    }
}

// @0x140d70320
CStringW FUN_140d70320(CStringW strKey, const float& fRate, const i64& nLow, const i64& nHigh)
{
    const fmt::internal::ArgArray<3>::Type aArgs = {fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(fRate),
                                                    fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(nLow),
                                                    fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(nHigh)};
    return FUN_14028dfa0(strKey, fmt::ArgList(fmt::internal::wc_make_type(fRate, nLow, nHigh), aArgs));
}

// @0x140d706c0
i64 FUN_140d706c0(i64* pValue, i64 nMin, i64 nMax)
{
    if (*pValue < nMin)
        return nMin;
    if (*pValue > nMax)
        return nMax;
    return *pValue;
}
