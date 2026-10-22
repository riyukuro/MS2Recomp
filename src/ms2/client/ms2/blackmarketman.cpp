// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBlackMarketMan: the black market (player auction house)
// manager: the own product list and the search result list, the handlers of the packet 0x5f replies and the senders
// of its requests. See placeholder/cblackmarketman.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\blackmarketman.cpp
// MS2-RANGE: 0x1400c2f90-0x1400c2fc0 .text$di
// MS2-RANGE: 0x140a20460-0x140a24e90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\blackmarketman.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cblackmarketman.h"
#include "ms2/client/ms2/uiblackmarketdialog.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include <sstream>

static CString s_strBlackMarketSell = "BlackMarket_Sell";

// ---- out-of-unit callees ----
// UI service: handle to a registered UI object.
class Unk_BmUIService { public: int FUN_141adc890(int nClass); void FUN_141adc530(int nClass); MS2Ptr<UIObject> FUN_141adcea0(int nClass); };
Unk_BmUIService* FUN_1403ed2b0();

// The table of text strings and the message helpers.
class Unk_BmStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_BmStrings* FUN_1401a9d70();
CStringW GetStringCommonByKey(const CStringW& strKey);         // string table text of a key
CStringW GetStringCommon(int nId);                        // string table text by id
CStringW FUN_1409eec40(int nId);
CStringW FUN_1408116a0(int nId, const int& nValue);     // text of an id with one number
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);
void FUN_140d73aa0(CStringW strText, int nType, void* pListener, CStringW strExtra);
void FUN_141275260(int, int, int);
void FUN_141275460(int, int, int, const fmt::ArgList& args);
void FUN_1412751f0(const CStringW& strText, int, int);
void FUN_1412751b0(const CStringW& strText, int);
void FUN_141276180(const CString&, const CString&);
void FUN_140710590(COutPacket& packet);                 // send the packet

// The client constants block: a table of readable values; the exe reads one at +0x6aa8.
class Unk_BmConstInt { public: const int& FUN_1402056b0(); };
class Unk_BmConstants
{
public:
    char m_pad[0x6aa8];
    Unk_BmConstInt m_nRegisterFee;                      // +0x6aa8
};
Unk_BmConstants* FUN_1401d3200();

// Black market dialog entry points taking a product (the dialog header types them with the page's own entry class).
void FUN_1418d0e40(UIBlackMarketDialog* pDlg, MS2Ptr<CBlackMarketProduct> spProduct);
void FUN_1418d0f00(UIBlackMarketDialog* pDlg, MS2Ptr<CBlackMarketProduct> spProduct, int n);
void FUN_1418d1080(UIBlackMarketDialog* pDlg, MS2Ptr<CBlackMarketProduct> spProduct, int n);

// The common string of a table id, formatted ("{0} {1}").
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
template CStringW FUN_14028dee0<int, CStringW>(int, const int&, const CStringW&);
template CStringW FUN_14028dee0<CStringW, unsigned short>(int, const CStringW&, const unsigned short&);

// fmt message wrapper (same shape as cashinventorybag.cpp's Unk_CashMessage).
enum Unk_BmResult : int {};
template<class A> inline void Unk_BmMessage(int id, int a, int b, const A& x) {
    const fmt::internal::ArgArray<1>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(x),values));
}
// @0x140a22fb0
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_BmResult& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_BmResult>::value)
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

// @0x140a22f10
static UIBlackMarketDialog* FUN_140a22f10(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIBlackMarketDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x140a20460
CBlackMarketMan::CBlackMarketMan()
    : m_listSearch(10), m_mapSearch(0x11, 0.75f, 0.25f, 2.25f, 10), m_mapOwn(0x11, 0.75f, 0.25f, 2.25f, 10), m_nF8(0), m_nReload(0)
{
}

// @0x140a20590
CBlackMarketMan::~CBlackMarketMan()
{
    m_mapSearch.RemoveAll();
    m_listSearch.RemoveAll();
    m_mapOwn.RemoveAll();
}

// @0x140a20650
void CBlackMarketMan::OnBlackMarket(CInPacket& packet)
{
    char cSub = packet.vfunc_o8_1();
    if (cSub == 6)
    {
        unsigned char bFlag = packet.vfunc_o8_1();
        __int64 qwA = packet.vfunc_o8_4();
        __int64 qwB = packet.vfunc_o8_4();
        m_nF8 = bFlag;
        m_tmA = CMsTime(qwA);
        m_tmB = CMsTime(qwB);
    }
    else if (cSub == 1)
        FUN_140a211a0(packet);
    else if (cSub == 2)
        FUN_140a21340(packet);
    else if (cSub == 3)
        FUN_140a21460(packet);
    else if (cSub == 4)
        FUN_140a216b0(packet);
    else if (cSub == 5)
        FUN_140a21930(packet);
    else if (cSub == 7)
    {
        FUN_141276180(s_strBlackMarketSell, CString(""));
        FUN_1412751b0(GetStringCommon(0x925), 0x12);
        SendBlackMarketMode1();
    }
    else if (cSub == 9)
    {
        if (FUN_1403ed2b0()->FUN_141adc890(0x4e97) == 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4e97);
    }
    else if (cSub == 8)
        FUN_140a21be0(packet);
    else if (cSub == 0)
        FUN_140a21ca0(packet);
}

// @0x140a20940
void CBlackMarketMan::SendBlackMarketMode1()
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(1);
    FUN_140710590(packet);
}

// @0x140a209a0
void CBlackMarketMan::SendBlackMarketMode6()
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(6);
    FUN_140710590(packet);
}

// @0x140a20a00
void CBlackMarketMan::SendBlackMarketMode2(unsigned __int64 qwA, unsigned __int64 qwB, int nCount)
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(2);
    packet.vfunc_o10_4(qwA);
    packet.vfunc_o10_4(qwB);
    packet.vfunc_o10_3(nCount);
    FUN_140710590(packet);
}

// @0x140a20aa0
void CBlackMarketMan::SendBlackMarketMode3(unsigned __int64 qwId)
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_4(qwId);
    FUN_140710590(packet);
}

// @0x140a20b10
void CBlackMarketMan::SendBlackMarketMode4(MS2Ptr<CBlackMarketSchCond> spCond)
{
    if (spCond == 0)
        return;
    if (spCond->Compact() == 0)
        return;
    if (spCond->m_dw48 == 1)
        m_nReload = 1;
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(4);
    spCond->Write(&packet);
    FUN_140710590(packet);
}

// @0x140a20bf0
void CBlackMarketMan::SendBlackMarketMode5(unsigned __int64 qwId, int nCount)
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_4(qwId);
    packet.vfunc_o10_3(nCount);
    FUN_140710590(packet);
}

// @0x140a20c70
void CBlackMarketMan::SendBlackMarketMode8(int nA, int nB)
{
    COutPacket packet(0x5f, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_3(nA);
    packet.vfunc_o10_3(nB);
    FUN_140710590(packet);
}

// @0x140a20cf0
int CBlackMarketMan::FUN_140a20cf0(MS2Ptr<CBlackMarketProduct> sp)
{
    if (sp == 0)
        return 0;
    int bNew = 1;
    MS2Ptr<CBlackMarketProduct> spOld = FUN_140a20e70(sp->m_qw18);
    if (spOld.get() != 0)
        bNew = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
        m_mapOwn.SetAt(sp->m_qw18, sp);
    return bNew;
}

// @0x140a20e00
void CBlackMarketMan::FUN_140a20e00(unsigned __int64 qwId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
        m_mapOwn.RemoveKey(qwId);
}

// @0x140a20e70
MS2Ptr<CBlackMarketProduct> CBlackMarketMan::FUN_140a20e70(unsigned __int64 qwId)
{
    MS2Ptr<CBlackMarketProduct> sp(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
        m_mapOwn.Lookup(qwId, sp);
    return sp;
}

// @0x140a20f30
void CBlackMarketMan::FUN_140a20f30(MS2Ptr<CBlackMarketProduct> sp)
{
    if (sp == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapSearch.SetAt(sp->m_qw18, sp);
        m_listSearch.AddTail(sp);
    }
}

// @0x140a20ff0
MS2Ptr<CBlackMarketProduct> CBlackMarketMan::FUN_140a20ff0(unsigned __int64 qwId)
{
    MS2Ptr<CBlackMarketProduct> sp(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
        m_mapSearch.Lookup(qwId, sp);
    return sp;
}

// @0x140a210b0
size_t CBlackMarketMan::FUN_140a210b0()
{
    return m_mapOwn.GetCount();
}

// @0x140a210e0
void CBlackMarketMan::FUN_140a210e0(ProductList& out)
{
    out.RemoveAll();
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_mapOwn.GetStartPosition(); pos != 0; m_mapOwn.GetNext(pos))
            out.AddTail(m_mapOwn.GetValueAt(pos));
    }
}

// @0x140a211a0
void CBlackMarketMan::FUN_140a211a0(CInPacket& packet)
{
    m_mapOwn.RemoveAll();
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<CBlackMarketProduct> sp(new CBlackMarketProduct);
        sp->Read(&packet);
        int nRemain = sp->GetRemain();
        sp->m_item->FUN_140526c70(nRemain);
        FUN_140a20cf0(sp);
    }
    UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
    if (pDlg != 0)
        pDlg->FUN_1418d0de0(&m_mapOwn);
}

// @0x140a21340
void CBlackMarketMan::FUN_140a21340(CInPacket& packet)
{
    MS2Ptr<CBlackMarketProduct> sp(new CBlackMarketProduct);
    sp->Read(&packet);
    if (FUN_140a20cf0(sp))
    {
        UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
        if (pDlg != 0)
            FUN_1418d0e40(pDlg, sp);
    }
}

// @0x140a21460
void CBlackMarketMan::FUN_140a21460(CInPacket& packet)
{
    unsigned __int64 qwId = packet.vfunc_o8_4();
    unsigned char bFlag = packet.vfunc_o8_1();
    ProductMap::CPair* pPair = m_mapOwn.Lookup(qwId);
    if (pPair != 0)
    {
        MS2Ptr<CBlackMarketProduct> sp = pPair == 0 ? MS2Ptr<CBlackMarketProduct>(0) : pPair->m_value;
        if (sp.get() != 0)
        {
            UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
            if (pDlg != 0)
                FUN_1418d0f00(pDlg, sp, bFlag);
            FUN_140a20e00(qwId);
        }
    }
}

// @0x140a216b0
void CBlackMarketMan::FUN_140a216b0(CInPacket& packet)
{
    if (m_nReload != 0)
    {
        m_mapSearch.RemoveAll();
        m_listSearch.RemoveAll();
    }
    m_nReload = 0;
    int nCount = packet.vfunc_o8_3();
    int nOld = m_listSearch.GetCount();
    POSITION posTail = m_listSearch.GetTailPosition();
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<CBlackMarketProduct> sp(new CBlackMarketProduct);
        sp->Read(&packet);
        int nRemain = sp->GetRemain();
        sp->m_item->FUN_140526c70(nRemain);
        if (sp->m_item->FUN_140527840() != 0)
            FUN_140a20f30(sp);
    }
    UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
    if (pDlg != 0)
    {
        m_listSearch.GetCount();
        size_t nNew = m_listSearch.GetCount();
        pDlg->FUN_1418d1330(nOld, (int)(nNew - 1), posTail);
    }
}

// @0x140a21930
void CBlackMarketMan::FUN_140a21930(CInPacket& packet)
{
    unsigned __int64 qwId = packet.vfunc_o8_4();
    int nBought = packet.vfunc_o8_3();
    MS2Ptr<CBlackMarketProduct> sp = FUN_140a20ff0(qwId);
    if (sp == 0)
        return;
    sp->m_nBought += nBought;
    int nRemain = sp->GetRemain();
    sp->m_item->FUN_140526c70(nRemain);
    if (sp->GetRemain() == 0)
        sp->m_nStateA = 1;
    if (FUN_140a20e70(qwId).get() != 0)
        sp->m_nStateA = 1;
    UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
    if (pDlg != 0)
    {
        int nOld = m_listSearch.GetCount();
        POSITION posTail = m_listSearch.GetTailPosition();
        m_listSearch.GetCount();
        size_t nNew = m_listSearch.GetCount();
        pDlg->FUN_1418d1330(nOld, (int)(nNew - 1), posTail);
        FUN_1418d1080(pDlg, sp, nBought);
    }
}

// @0x140a21be0
void CBlackMarketMan::FUN_140a21be0(CInPacket& packet)
{
    int nA = packet.vfunc_o8_3();
    int nB = packet.vfunc_o8_3();
    __int64 qw = packet.vfunc_o8_4();
    UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
    if (pDlg != 0)
        pDlg->FUN_1418d13a0(nA, nB, (void*)qw);
}

// @0x140a21ca0
void CBlackMarketMan::FUN_140a21ca0(CInPacket& packet)
{
    unsigned char bType = packet.vfunc_o8_1();
    Unk_BmResult nResult = (Unk_BmResult)packet.vfunc_o8_3();
    __int64 qw = packet.vfunc_o8_4();
    int nA = packet.vfunc_o8_3();
    unsigned short nB = (unsigned short)packet.vfunc_o8_3();
    switch (nResult)
    {
    case 5:
        FUN_140d73bc0(0x934, 0, 0, CStringW(L""));
        break;
    default:
        Unk_BmMessage(0x92b, 1, 1, nResult);
        break;
    case 11:
    case 12:
        if (bType == 2)
            FUN_140d73bc0(0x935, 0, 0, CStringW(L""));
        else
            Unk_BmMessage(0x92b, 1, 1, nResult);
        break;
    case 13:
        FUN_141275260(0x88, 1, 1);
        break;
    case 14:
        FUN_140d73bc0(0x935, 0, 0, CStringW(L""));
        break;
    case 21:
    {
        int nId = 0x1c;
        FUN_140d73aa0(FUN_1408116a0(0x933, nId), 0, 0, CStringW(L""));
        break;
    }
    case 22:
        FUN_141275260(0x34, 1, 1);
        break;
    case 23:
        if (bType == 3)
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_err_reserved_other")), 1, 1);
        else
            FUN_141275260(0x87, 1, 1);
        break;
    case 24:
        break;
    case 25:
        FUN_140d73bc0(0x932, 0, 0, CStringW(L""));
        break;
    case 26:
        FUN_140d73bc0(0x931, 0, 0, CStringW(L""));
        break;
    case 27:
        FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_blackmarket_error_buy_expired")), 1, 1);
        break;
    case 29:
        FUN_141275260(0x92d, 1, 1);
        break;
    case 30:
        FUN_140d73bc0(0x936, 0, 0, CStringW(L""));
        break;
    case 31:
        if (bType == 2)
            FUN_140d73bc0(0x92f, 0, 0, CStringW(L""));
        else
            Unk_BmMessage(0x92b, 1, 1, nResult);
        break;
    case 32:
        FUN_140d73bc0(0x92c, 0, 0, CStringW(L""));
        break;
    case 34:
    case 35:
        break;
    case 36:
        FUN_140d73bc0(0x8b7, 0, 0, CStringW(L""));
        break;
    case 37:
        FUN_140d73aa0(FUN_14028dee0(0x688, FUN_1401d3200()->m_nRegisterFee.FUN_1402056b0(), FUN_1409eec40(0x5a5)), 0, 0,
                      CStringW(L""));
        break;
    case 38:
        FUN_140d73bc0(0xc07, 0, 0, CStringW(L""));
        break;
    case 39:
        FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_blackmarket_error_not_useable")), 1, 1);
        break;
    case 40:
        break;
    case 41:
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_blackmarket_error_purchase_count")), 0, 0, CStringW(L""));
        break;
    case 42:
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_blackmarket_error_cannot_buy_ownProduct")), 0, 0, CStringW(L""));
        break;
    case 43:
        FUN_140d73aa0(FUN_14028dee0(0x93d, FUN_1401a9d70()->FUN_141811980(1, nA), nB), 0, 0, CStringW(L""));
        break;
    case 44:
        FUN_140d73aa0(FUN_14028dee0(0x93e, FUN_1401a9d70()->FUN_141811980(1, nA), nB), 0, 0, CStringW(L""));
        break;
    }
    UIBlackMarketDialog* pDlg = FUN_140a22f10(0x4e97);
    if (pDlg != 0)
        pDlg->FUN_1418d0b60(bType, nResult, (void*)qw);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9eee0-0x142c9ef00 .text$yd
