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

// ---- out-of-unit callees ----
__int64 FUN_140869440();                                // the server time
Unk_CMesoMarketConfig* FUN_1401d3200();                 // the config singleton
__int64* FUN_1402c05b0(void* pConstBlock);              // the <constants> record
unsigned* FUN_1402056b0(void* pField);                  // a config field
CStringW GetStringCommonByKey(const CStringW& strKey);         // string table text of a key
CStringW GetStringCommon(int nId);                        // string table text by id
CStringW FUN_140298ea0(CStringW strKey);                // localized string
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14062b4f0(CStringW strKey, const int* pnArg);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& strA, const CStringW& strB);
CStringW FUN_1412757d0(__int64 n);                      // number text
CStringW FUN_1409404f0(__int64 n);                      // number text, grouped
CStringW FUN_140719a80(__int64 n);                      // number text
CStringW FUN_1418fe870(int nCurrency, int* pnVSpace, unsigned nItemId);   // the "<img>" source of a token kind
CStringW FUN_140275590(const wchar_t* pszFormat, const CStringW& strA, const int& nB);
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);
void FUN_140710590(COutPacket&);                        // send
void* FUN_140166410();
bool FUN_14036d570(void* pOwner, int nId);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
class Unk_MesoUiMgr { public: void FUN_141add1f0(); void FUN_141add390(); };
Unk_MesoUiMgr* FUN_1403ed2b0();

// The penalty (block) record a result code asks for.
struct Unk_MesoBlockRef;
void FUN_1401cb250(Unk_MesoBlockRef*);
struct Unk_MesoBlockRef
{
    void* m_00;
    void* m_08;
    ~Unk_MesoBlockRef() { FUN_1401cb250(this); }
};
MS2_CHECK_SIZE(Unk_MesoBlockRef, 0x10);
class Unk_MesoBlockMgr;
Unk_MesoBlockMgr* FUN_140a6a830();
void FUN_140a2f620(Unk_MesoBlockMgr* pMgr, Unk_MesoBlockRef* pOut, int nKind);
void* FUN_1401cb3d0(Unk_MesoBlockRef* pRef);
void FUN_140a2ff20(Unk_MesoBlockRef* pRef, int nKind, __int64 n);

extern __int64 DAT_143ab2898;                           // the highest meso a listing may ask

// fmt call glue of the invalid-price message (a float and two int64 arguments; hand written as in
// uiitemrepackingscrolldialog.cpp)
typedef __int64 i64;
struct Unk_MesoFmtArg { const void* m_value; void* m_fn; };
struct Unk_MesoFmtPack { i64 m_n; const Unk_MesoFmtArg* m_args; };
Unk_MesoFmtArg* FUN_14027c920(Unk_MesoFmtArg* pOut, float fValue);
Unk_MesoFmtArg* FUN_14027c940(Unk_MesoFmtArg* pOut, i64 nValue);
i64* FUN_140274c80(i64* pOut, float* pValue);
i64* FUN_140274e10(i64* pOut, i64* pValue);
i64* FUN_140163e80(i64* pSlot);
i64 FUN_14016d660(i64 a0, i64 a1, i64 a2, i64 a3, i64 a4, i64 a5, i64 a6, i64 a7, i64 a8, i64 a9, i64 a10, i64 a11,
                  i64 a12, i64 a13, i64 a14);
Unk_MesoFmtPack* FUN_140163e50(Unk_MesoFmtPack* pOut, i64 nTypes, Unk_MesoFmtArg* pArgs);
CStringW FUN_14028dfa0(CStringW strKey, const Unk_MesoFmtPack& args);

// A notice box with the text of a key.
#define MESO_NOTICE(key) \
    do { MS2Ptr<CMsgBoxData> box_ = FUN_140d74390(FUN_140298ea0(CStringW(key)), 0, FUN_140b240b0()); } while (0)

CStringW FUN_140d6e230(int nCurrency);
i64 FUN_140d706c0(i64* pValue, i64 nMin, i64 nMax);
CStringW FUN_140d70320(CStringW strKey, float* pRate, i64* pLow, i64* pHigh);
CInputStream& FUN_14070f4c0(CInputStream& in, unsigned __int64* pValue);
CInputStream& FUN_140d70110(CInputStream& in, MS2Ptr<CMesoMarketProductCli>& sp);
CInputStream& FUN_140d701a0(CInputStream& in, CMesoMarketMan::ProductMap& map);
void FUN_140d70240(CInputStream& in, CMesoMarketMan::ProductArray& arr);

// @0x140d6d8c0
CMesoMarketProductCli::CMesoMarketProductCli()
{
}

// @0x140d70a70
CMesoMarketProductCli::~CMesoMarketProductCli()
{
}

// @0x140d6d900
bool CMesoMarketProductCli::FUN_140d6d900()
{
    CMsTime now(FUN_140869440());
    return now >= m_40;
}

// @0x140d6d940
void CMesoMarketProductCli::FUN_140d6d940(ASObj& row)
{
    FUN_140d6db30(row);
    if (!FUN_140d6d900())
    {
        CStringW strTime;
        CStringW strKey(L"s_mesoMarket_endSellTime");
        FUN_141b70f90(CMsTime(m_40), GetStringCommonByKey(strKey), strTime);
        row.FUN_1407cbb20("subText", CStringW(strTime));
        row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_cancel_sale");
    }
    else
    {
        row.FUN_1409c0e60("subText", L"$s_mesoMarket_own_product_expired");
        row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_cancel_sell_expired");
    }
}

// @0x140d6dab0
void CMesoMarketProductCli::FUN_140d6dab0(ASObj& row)
{
    FUN_140d6db30(row);
    row.FUN_1409c0e60("subText", L"");
    row.FUN_1409c0e60("buttonText", L"$s_mesoMarket_buy_product");
    if (m_b50)
        row.FUN_1409c0e60("subText", L"$s_mesoMarket_own_product");
}

// @0x140d6db30
void CMesoMarketProductCli::FUN_140d6db30(ASObj& row)
{
    __int64 nBase = *FUN_1402c05b0((char*)FUN_1401d3200() + 0x6018);
    __int64 nUnit = m_n28;
    if (nBase < m_n20)
    {
        __int64 nCount = m_n20 / nBase;
        nUnit = nUnit / nCount;
    }
    CStringW strBase = FUN_1412757d0(nBase);
    row.FUN_1407cbb20("marketSN", FUN_140719a80(m_n18));
    row.FUN_1407cbb20("sellMeso", FUN_1409404f0(m_n20));
    row.FUN_1407cbb20("buyMerat", FUN_1408f71a0(CStringW(L"s_mesoMarket_listItem_buyMerat"), FUN_1409404f0(m_n28),
                                                FUN_140d6e230(*FUN_1402056b0((char*)FUN_1401d3200() + 0x6140))));
    if (!FUN_14036d570(FUN_140166410(), 0xf4))
    {
        row.FUN_1407cbb20("sellMesoText", FUN_1405c2690(CStringW(L"s_mesoMarket_listItem_sellMesoText"), FUN_1412757d0(m_n20)));
        row.FUN_1407cbb20("buyMeratPerUnit", FUN_1408f71a0(CStringW(L"s_mesoMarket_listItem_unitPrice"), strBase, FUN_1409404f0(nUnit)));
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
    return FUN_140275590(L"<img src='{0}' vspace='{1}'/>", strSrc, nVSpace);
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
        FUN_140d6eb90(packet);
        break;
    case 1:
        FUN_140d6ebe0(packet);
        break;
    case 2:
        FUN_140d6ec20(packet);
        break;
    case 4:
        FUN_140d6eca0(packet);
        break;
    case 5:
        FUN_140d6ecf0(packet);
        break;
    case 6:
        FUN_140d6ee00(packet);
        break;
    case 7:
        FUN_140d6eec0(packet);
        break;
    case 8:
        FUN_140d6efb0(packet);
    }
}

// @0x140d6e5b0
void CMesoMarketMan::FUN_140d6e5b0(ASArray& rows)
{
    for (POSITION pos = m_mapOwn.GetHeadPosition(); pos != 0; m_mapOwn.GetNext(pos))
    {
        MS2Ptr<CMesoMarketProductCli> sp = m_mapOwn.GetValueAt(pos);
        ASObj row(2);
        sp->FUN_140d6d940(row);
        rows.FUN_1422bc050(row.FUN_1422bb890());
    }
}

// @0x140d6e6d0
void CMesoMarketMan::FUN_140d6e6d0(ASArray& rows)
{
    for (size_t i = 0; i < m_arrMarket.GetCount(); ++i)
    {
        MS2Ptr<CMesoMarketProductCli> sp = m_arrMarket[i];
        ASObj row(2);
        sp->FUN_140d6dab0(row);
        rows.FUN_1422bc050(row.FUN_1422bb890());
    }
}

// @0x140d6e7e0
MS2Ptr<CMesoMarketProductCli> CMesoMarketMan::FUN_140d6e7e0(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (m_mapOwn.Lookup(qwId, sp))
        return sp;
    return MS2Ptr<CMesoMarketProductCli>(0);
}

// @0x140d6e890
MS2Ptr<CMesoMarketProductCli> CMesoMarketMan::FUN_140d6e890(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (m_mapMarket.Lookup(qwId, sp))
        return sp;
    return MS2Ptr<CMesoMarketProductCli>(0);
}

// @0x140d6e940
Unk_MesoLimits& CMesoMarketMan::FUN_140d6e940()
{
    return m_limits;
}

// @0x140d6e960
bool CMesoMarketMan::FUN_140d6e960(__int64 nMeso, __int64 nPrice)
{
    if (nMeso > DAT_143ab2898)
    {
        FUN_140d6f130(5);
        return false;
    }
    if (m_mapOwn.GetCount() >= (unsigned)m_limits.m_n18)
    {
        FUN_140d6f130(8);
        return false;
    }
    if (m_nOwn >= m_limits.m_n1C)
    {
        FUN_140d6f130(0xd);
        return false;
    }
    __int64 nLow = FUN_140d6ff60();
    __int64 nHigh = FUN_140d6ffe0();
    if (nPrice > nHigh || nPrice < nLow)
    {
        FUN_140d6f130(0x10);
        return false;
    }
    return true;
}

// @0x140d6ea50
bool CMesoMarketMan::FUN_140d6ea50(unsigned __int64 qwId)
{
    MS2Ptr<CMesoMarketProductCli> sp;
    if (!m_mapMarket.Lookup(qwId, sp))
    {
        FUN_140d6f130(9);
        return false;
    }
    if (sp->m_b50)
    {
        FUN_140d6f130(0xb);
        return false;
    }
    if (m_nBuy >= m_limits.m_n20)
    {
        FUN_140d6f130(0xe);
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
void CMesoMarketMan::FUN_140d6eb90(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    FUN_140d6f130(nCode);
}

// @0x140d6ebe0
void CMesoMarketMan::FUN_140d6ebe0(CInPacket& packet)
{
    m_limits.Read(packet);
}

// @0x140d6ec20
void CMesoMarketMan::FUN_140d6ec20(CInPacket& packet)
{
    m_nOwn = packet.ReadInt32();
    m_nBuy = packet.ReadInt32();
}

// @0x140d6eca0
void CMesoMarketMan::FUN_140d6eca0(CInPacket& packet)
{
    m_mapOwn.RemoveAll();
    FUN_140d701a0(packet, m_mapOwn);
}

// @0x140d6ecf0
void CMesoMarketMan::FUN_140d6ecf0(CInPacket& packet)
{
    MS2Ptr<CMesoMarketProductCli> sp(new CMesoMarketProductCli);
    sp->Read(packet);
    FUN_140d6f0b0(sp);
    m_nOwn = packet.ReadInt32();
}

// @0x140d6ee00
void CMesoMarketMan::FUN_140d6ee00(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    __int64 qwId = packet.ReadInt64();
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_mapOwn.RemoveKey(qwId);
    FUN_140d6f130(nCode);
}

// @0x140d6eec0
void CMesoMarketMan::FUN_140d6eec0(CInPacket& packet)
{
    m_arrMarket.RemoveAll();
    m_mapMarket.RemoveAll();
    FUN_140d70240(packet, m_arrMarket);
    for (unsigned i = 0; i < m_arrMarket.GetCount(); ++i)
        m_mapMarket.SetAt(m_arrMarket[i]->GetValue18(), m_arrMarket[i]);
}

// @0x140d6efb0
void CMesoMarketMan::FUN_140d6efb0(CInPacket& packet)
{
    int nCode = packet.ReadInt32();
    __int64 qwId = packet.ReadInt64();
    m_nBuy = packet.ReadInt32();
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (nCode == 0 || nCode == 0x11)
        FUN_140d70060(qwId);
    FUN_140d6f130(nCode);
}

// @0x140d6f0b0
void CMesoMarketMan::FUN_140d6f0b0(MS2Ptr<CMesoMarketProductCli> sp)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_mapOwn.SetAt(sp->m_n18, sp);
}

// @0x140d6f130
// MS2-FUNCTIONAL: the exe keeps every message's temporaries in their own stack slots
void CMesoMarketMan::FUN_140d6f130(int nCode)
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
        FUN_1403ed2b0()->FUN_141add1f0();
        break;
    case 7:
        FUN_1403ed2b0()->FUN_141add390();
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
        i64 nHigh = FUN_140d6ffe0();
        i64 nLow = FUN_140d6ff60();
        float fRate = m_limits.m_fRateB * 100.0f;
        MS2Ptr<CMsgBoxData> box = FUN_140d74390(FUN_140d70320(CStringW(L"s_mesoMarket_error_invalidBuyMerat"), &fRate, &nLow, &nHigh),
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
        Unk_MesoBlockRef block;
        FUN_140a2f620(FUN_140a6a830(), &block, nKind);
        if (FUN_1401cb3d0(&block) != 0)
            FUN_140a2ff20(&block, nKind, 0);
        break;
    }
    case 0x14:
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d74390(GetStringCommon(0xd56), 0, FUN_140b240b0());
        break;
    }
    default:
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d74390(FUN_14062b4f0(CStringW(L"s_mesoMarket_error_unknown"), &nCode), 0, FUN_140b240b0());
    }
    }
}

// @0x140d6ff60
__int64 CMesoMarketMan::FUN_140d6ff60()
{
    double dFactor = 1.0001 - m_limits.m_fRateB;
    __int64 nValue = (__int64)((double)m_limits.m_nBase * dFactor);
    return FUN_140d706c0(&nValue, m_limits.m_nMin, m_limits.m_nMax);
}

// @0x140d6ffe0
__int64 CMesoMarketMan::FUN_140d6ffe0()
{
    double dFactor = 1.0001 + m_limits.m_fRateB;
    __int64 nValue = (__int64)((double)m_limits.m_nBase * dFactor);
    return FUN_140d706c0(&nValue, m_limits.m_nMin, m_limits.m_nMax);
}

// @0x140d70060
void CMesoMarketMan::FUN_140d70060(__int64 qwId)
{
    m_mapMarket.RemoveKey(qwId);
    for (size_t i = 0; i < m_arrMarket.GetCount(); ++i)
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
        MS2Ptr<CMesoMarketProductCli> sp(0);
        unsigned __int64 qwKey;
        FUN_140d70110(FUN_14070f4c0(in, &qwKey), sp);
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
// MS2-FUNCTIONAL: argument packing temporaries are laid out differently
CStringW FUN_140d70320(CStringW strKey, float* pRate, i64* pLow, i64* pHigh)
{
    Unk_MesoFmtArg aArgs[3];
    Unk_MesoFmtArg t0, t1, t2;
    aArgs[0] = *FUN_14027c920(&t0, *pRate);
    aArgs[1] = *FUN_14027c940(&t1, *pLow);
    aArgs[2] = *FUN_14027c940(&t2, *pHigh);
    i64 s[12];
    i64* p[12];
    for (int i = 0; i < 12; i++)
        p[i] = FUN_140163e80(&s[i]);
    i64 tc, tb, ta;
    i64* pTypeC = FUN_140274e10(&tc, pHigh);
    i64* pTypeB = FUN_140274e10(&tb, pLow);
    i64* pTypeA = FUN_140274c80(&ta, pRate);
    i64 nTypes = FUN_14016d660(*pTypeA, *pTypeB, *pTypeC, *p[11], *p[10], *p[9], *p[8], *p[7], *p[6], *p[5], *p[4], *p[3],
                               *p[2], *p[1], *p[0]);
    Unk_MesoFmtPack pack;
    FUN_140163e50(&pack, nTypes, aArgs);
    return FUN_14028dfa0(strKey, pack);
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
