// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client NPC shop products: see npcshopproductbase.h. w290.
// MS2-UNIT: ?\npcshopproductbase.cpp
// MS2-RANGE: 0x1400d4e20-0x1400d4fa0 .text$di
// MS2-RANGE: 0x140db5c50-0x140db8d80 .text$mn
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npcshopproductbase.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "npcshopproductbase.h"
#include "inventory.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cnpcshopbuyperiod.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <algorithm>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_ItemEquipData : public CItemData { };                 // CItem::FUN_140527840's record (item.cpp)

CStringW GetStringCommonByKey(const CStringW& strKey);                 // localized text
CStringW FUN_1405c2690(CStringW strFmt, const CStringW& strArg);
CStringW FUN_1408f71a0(CStringW strFmt, const CStringW& strA, const CStringW& strB);
CStringW FUN_1409eaa20(CStringW strFmt, const CStringW& strA, const CStringW& strB, const CStringW& strC);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // formats one text argument into the message
CStringW FUN_14083bdc0(const CMsTime& t, bool bSeconds, CStringW strSep, CStringW strSep2);   // date and time text
CStringW FUN_14083bab0(CMsTime t, CStringW strSep);             // date text
CStringW FUN_140b8f230(int nDay);                               // the name of a week day
CStringW FUN_14086cc00(const wchar_t* pszFormat, const int& a, const int& b, const int& c, const int& d);
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);   // split into strings
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);   // message box
__int64 FUN_140869440();                                        // the server time
bool FUN_1406a5930();                                           // the star point event runs
int FUN_14053feb0(int nItemId);                                 // the fixed rank of an item (0: none)
__int64 FUN_141349ef0(int nKind, int nA, unsigned nB);          // the amount of a currency
bool FUN_14134a030(int nKind, int nA, int nAmount);             // the currency can pay nAmount
void FUN_14134a120(int nKind, int nA, int nAmount);             // tell the player the currency is missing
extern Unk_Inventory DAT_143ab2a90;                             // the player inventory

// The merat product record: two ints written by CNpcShopMeratItemCli::vfunc_2.
struct Unk_ProdPremium
{
    char m_pad_00[0x1c8];
    int m_1c8;                                                  // +0x1c8
    int m_1cc;                                                  // +0x1cc
};
MS2_CHECK_OFFSET(Unk_ProdPremium, m_1cc, 0x1cc);

// Two copies of the sort-type name table (as header_statics_a.h's s_strSortTypeNames; raw CString[7] arrays: their atexit
// thunks 0x142ca5690/0x142ca56c0 run the eh vector destructor iterator directly), constructed by the .text$di initializers.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143ac3df0
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143ac3e98

// The exe's swap-assign of an Unk_ShopLifeRef from a raw pointer (a COMDAT of the exe, 0x140db8b90).
Unk_ShopLifeRef& FUN_140db8b90(Unk_ShopLifeRef& ref, NpcShopItemLife* p);

// ---- CNpcShopProductBase --------------------------------------------------------------------------------------------

// @0x140db5c50
CNpcShopProductBase::CNpcShopProductBase() : m_18(0), m_1c(0)
{
}

// @0x140db5cd0
// MS2-FUNCTIONAL: EH funclet / vptr store shape differs; source form unknown
CNpcShopProductBase::~CNpcShopProductBase()
{
}

// @0x140db5d20
// MS2-FUNCTIONAL: extra call-result temporaries; source form unknown
CStringW CNpcShopProductBase::FUN_140db5d20()
{
    if (FUN_140db5e90().get() == 0)
        return CStringW(L"");
    MS2Ptr<CItem> spItem = FUN_140db5e90();
    return spItem->FUN_140527b10();
}

// @0x140db5e20
int CNpcShopProductBase::FUN_140db5e20()
{
    if (m_40.get() != 0)
        return m_40->FUN_1405276c0();
    return 0;
}

// @0x140db5e70
int CNpcShopProductBase::FUN_140db5e70()
{
    return m_18;
}

// @0x140db5e90
MS2Ptr<CItem> CNpcShopProductBase::FUN_140db5e90()
{
    return m_40;
}

// @0x140db5ee0
int CNpcShopProductBase::FUN_140db5ee0()
{
    return m_1c;
}

// @0x140db5f00
ATL::CAtlArray<CString>* CNpcShopProductBase::FUN_140db5f00()
{
    return &m_20;
}

// @0x140db5f20
int CNpcShopProductBase::vfunc_1()
{
    return 1;
}

// @0x140db5f40
int CNpcShopProductBase::vfunc_2()
{
    return 0;
}

// ---- CNpcShopProductCli ---------------------------------------------------------------------------------------------

// @0x140db5f50
CNpcShopProductCli::CNpcShopProductCli()
    : m_50(0), m_54(0), m_58(0), m_5c(0), m_60(0), m_64(0), m_68(0), m_6c(0), m_70(0), m_74(0), m_78(0), m_7c(0), m_80(0), m_84(0),
      m_88(0), m_8c(0), m_90(0), m_a0(0), m_a8(0), m_b8(1), m_bc(0), m_c0(0), m_c4(0)
{
    m_1c = 0;
}

// @0x140db6120
CNpcShopProductCli::~CNpcShopProductCli()
{
}

// @0x140db61a0
// MS2-FUNCTIONAL: first-pass source; frame layout and temp order not byte-compared
void CNpcShopProductCli::FUN_140db61a0(CInPacket& in, int nMode)
{
    if (nMode == 1)
    {
        m_18 = in.ReadInt32();
        int nItemId = in.ReadInt32();
        m_88 = in.ReadUInt8();
        m_8c = in.ReadInt32();
        m_90 = in.ReadInt32();
        m_a0 = (unsigned)in.ReadInt32();
        m_a8 = (unsigned)in.ReadInt32();
        unsigned char nRarity = in.ReadUInt8();
        int nCount = in.ReadInt32();
        m_5c = in.ReadInt32();
        int nBought = in.ReadInt32();
        m_60 = in.ReadInt32();
        m_b0 = in.ReadString();
        m_64 = in.ReadInt32();
        m_68 = in.ReadInt32();
        m_6c = in.ReadUInt8();
        m_70 = (unsigned short)in.ReadInt16();
        m_74 = in.ReadUInt8();
        m_78 = (unsigned short)in.ReadInt16();
        m_84 = in.ReadBool();
        m_b8 = (unsigned short)in.ReadInt16();
        m_bc = in.ReadUInt8();
        m_c0 = in.ReadUInt8();
        m_98 = in.ReadString();
        m_7c = (unsigned short)in.ReadInt16();
        m_80 = in.ReadInt32();
        m_c4 = in.ReadBool();
        if (in.ReadBool())
        {
            m_c8 = new CNpcShopBuyPeriod();
            m_c8->FUN_1406dcb40(in);
            m_c8->FUN_1406dc810();
        }
        if (in.ReadBool())
        {
            FUN_140db8b90(m_d8, new NpcShopItemLife());
            m_d8.operator->()->FUN_14026ef20(in);
        }
        FUN_14015f050(m_b0, m_20, ",");
        FUN_140db6e30(nBought);
        m_40.AssignRaw(new CItem());
        m_40->FUN_140523c40(nItemId, nRarity, nCount);
        m_40->FUN_140524eb0(in);
        m_40->FUN_14052b340(m_b8);
        m_40->FUN_14052b870(reinterpret_cast<const Unk_ItemSlot188&>(m_d8));
    }
    else if (nMode == 7)
    {
        m_18 = in.ReadInt32();
        int nItemId = in.ReadInt32();
        unsigned char nRarity = in.ReadUInt8();
        __int64 nPrice = in.ReadInt64();
        m_40.AssignRaw(new CItem());
        if (m_40->FUN_140523c40(nItemId, nRarity, 0))
            m_40->FUN_140524eb0(in);
        m_54 = m_40->FUN_140526c50();
        m_a0 = nPrice;
    }
}

// @0x140db6db0
void CNpcShopProductCli::FUN_140db6db0(int nIndex)
{
    if (m_40.get() != 0)
        m_40->FUN_140526b70(nIndex);
}

// @0x140db6e00
void CNpcShopProductCli::FUN_140db6e00(int nBuyCount)
{
    m_58 = nBuyCount;
    FUN_140db81c0();
}

// @0x140db6e30
void CNpcShopProductCli::FUN_140db6e30(unsigned nBuyCount)
{
    if (m_b8 > 1)
        m_58 = nBuyCount / m_b8;
    else
        m_58 = nBuyCount;
    FUN_140db81c0();
}

// @0x140db6e90
int CNpcShopProductCli::FUN_140db6e90()
{
    return m_54;
}

// @0x140db6eb0
int CNpcShopProductCli::FUN_140db6eb0()
{
    if (m_b8 > 1)
        return m_54 * m_b8;
    return m_54;
}

// @0x140db6ef0
int CNpcShopProductCli::FUN_140db6ef0()
{
    return m_5c;
}

// @0x140db6f10
int CNpcShopProductCli::FUN_140db6f10()
{
    if (m_b8 > 1)
        return m_5c * m_b8;
    return m_5c;
}

// @0x140db6f50
int CNpcShopProductCli::FUN_140db6f50()
{
    return m_58;
}

// @0x140db6f70
int CNpcShopProductCli::FUN_140db6f70()
{
    if (m_b8 > 1)
        return m_58 * m_b8;
    return m_58;
}

// @0x140db6fb0
int CNpcShopProductCli::FUN_140db6fb0()
{
    return m_60;
}

// @0x140db6fd0
int CNpcShopProductCli::FUN_140db6fd0()
{
    return m_84;
}

// @0x140db6ff0
CString CNpcShopProductCli::FUN_140db6ff0()
{
    return m_b0;
}

// @0x140db7040
ATL::CAtlArray<CString>* CNpcShopProductBase::FUN_140db7040()
{
    return &m_20;
}

// @0x140db7060
int CNpcShopProductCli::FUN_140db7060()
{
    int nResult;
    if (m_5c > 0 && m_54 <= 0)
        nResult = 1;
    else
        nResult = 0;
    return nResult;
}

// @0x140db70a0
// MS2-FUNCTIONAL: first-pass source; frame layout and temp order not byte-compared
bool CNpcShopProductCli::FUN_140db70a0(CStringW& strError)
{
    if (m_c8.get() != 0)
    {
        CMsTime tmNow(FUN_140869440());
        if (!m_c8->FUN_1406ddc90(tmNow))
        {
            CMsTime& tmStart = m_c8->m_tmStart;
            CMsTime& tmEnd = m_c8->m_tmEnd;
            if (!m_c8->FUN_1406dda70())
            {
                if (!(tmStart > CMsTime(0)))
                {
                    if (!(tmEnd > CMsTime(0)))
                        return false;
                }
                if (!(tmStart > tmNow))
                {
                    strError = GetStringCommonByKey(L"s_err_invalid_item_cannot_buy_by_period");
                }
                else if (!(tmEnd == CMsTime(0)))
                {
                    CStringW strEndText = FUN_14083bdc0(tmEnd, true, CStringW(L"/"), CStringW(L":"));
                    CStringW strStartText = FUN_14083bdc0(tmStart, true, CStringW(L"/"), CStringW(L":"));
                    strError = FUN_1408f71a0(CStringW(L"s_err_cannot_buy_period"), strStartText, strEndText);
                }
                else
                {
                    CStringW strStartText = FUN_14083bdc0(tmStart, true, CStringW(L"/"), CStringW(L":"));
                    strError = FUN_1405c2690(CStringW(L"s_err_cannot_buy_period_from_start"), strStartText);
                }
                return false;
            }
            CStringW strDate;
            bool bHasDate = true;
            if (!(tmStart > CMsTime(0)))
            {
                if (!(tmEnd > CMsTime(0)))
                    bHasDate = false;
            }
            if (bHasDate)
            {
                if (tmStart > CMsTime(0) && tmEnd > CMsTime(0))
                {
                    strDate = FUN_1408f71a0(CStringW(L"s_err_cannot_buy_period_fmt_date"), FUN_14083bab0(tmStart, CStringW(L"/")), FUN_14083bab0(tmEnd, CStringW(L"/")));
                }
                else if (!(tmStart > CMsTime(0)))
                {
                    strDate = FUN_1405c2690(CStringW(L"s_err_cannot_buy_period_fmt_date_to_end"), FUN_14083bab0(tmEnd, CStringW(L"/")));
                }
                else
                {
                    strDate = FUN_1405c2690(CStringW(L"s_err_cannot_buy_period_fmt_date_from_start"), FUN_14083bab0(tmStart, CStringW(L"/")));
                }
            }
            CStringW strDays;
            for (std::set<int>::iterator it = m_c8->m_setDays.begin(); it != m_c8->m_setDays.end(); ++it)
            {
                int nDay = *it;
                if (strDays.IsEmpty())
                    strDays.Append(FUN_140b8f230(nDay));
                else
                    strDays.Append(FUN_1401e8510(L", {0}", FUN_140b8f230(nDay)));
            }
            if (m_c8->m_aPartTimes.IsEmpty())
            {
                if (strDate.IsEmpty())
                    strError = FUN_1405c2690(CStringW(L"s_err_cannot_buy_period_day"), strDays);
                else
                    strError = FUN_1408f71a0(CStringW(L"s_err_cannot_buy_period_day_and_date"), strDays, strDate);
            }
            else
            {
                CStringW strParts;
                size_t nCount = m_c8->m_aPartTimes.GetCount();
                CStringW strFormat = GetStringCommonByKey(L"s_err_cannot_buy_period_fmt_part_time");
                for (size_t i = 0; i < nCount; i++)
                {
                    Unk_DayTimeRange& pair = m_c8->m_aPartTimes[i];
                    int nToA = pair.m_end.GetMinute();
                    int nToB = pair.m_end.GetHour();
                    int nFromA = pair.m_start.GetMinute();
                    int nFromB = pair.m_start.GetHour();
                    CStringW strOne = FUN_14086cc00(strFormat, nFromB, nFromA, nToB, nToA);
                    if (strParts.IsEmpty())
                        strParts.Append(strOne);
                    else
                        strParts.Append(FUN_1401e8510(L", {0}", strOne));
                }
                if (strDate.IsEmpty())
                    strError = FUN_1408f71a0(CStringW(L"s_err_cannot_buy_period_day_and_parttime"), strDays, strParts);
                else
                    strError = FUN_1409eaa20(CStringW(L"s_err_cannot_buy_period_day_and_parttime_and_date"), strDays, strParts, strDate);
            }
            return false;
        }
    }
    if (m_d8.m_p != 0)
    {
        CMsTime tmNow(FUN_140869440());
        if (!m_d8.operator->()->FUN_14026f080(tmNow))
        {
            strError = GetStringCommonByKey(L"s_blackmarket_error_buy_expired");
            return false;
        }
    }
    return true;
}

// @0x140db8180
__int64 CNpcShopProductCli::FUN_140db8180()
{
    return m_a0;
}

// @0x140db81a0
__int64 CNpcShopProductCli::FUN_140db81a0()
{
    return m_a8;
}

// @0x140db81c0
void CNpcShopProductCli::FUN_140db81c0()
{
    int nRemain = m_5c - m_58;
    int nZero = 0;
    m_54 = (std::max)(nZero, nRemain);
}

// @0x140db8210
// MS2-FUNCTIONAL: first-pass source; frame layout and temp order not byte-compared
unsigned CNpcShopProductCli::FUN_140db8210()
{
    MS2Ptr<CItem> spItem = FUN_140db5e90();
    if (spItem.get() == 0)
        return 0;
    CItem* pItem = spItem.operator->();
    if (pItem->FUN_140525f10() != 0)
    {
        if (pItem->FUN_1405281e0() == 1)
            return DAT_143ab2a90.FUN_140a615d0(0);
    }
    if (!static_cast<Unk_ItemEquipData*>(pItem->FUN_140527840())->FUN_14053c7c0())
        return 1;
    int nLimit = FUN_140db6ef0();
    int nLeft = FUN_140db6eb0();
    int nStack = pItem->FUN_1405281e0();
    int nOne = 1;
    int nResult = (std::max)(nStack, nOne);
    if (0 < nLimit)
        nResult = (std::min)(nLeft, nResult);
    unsigned nBuy = nResult;
    if (1 < m_b8)
        nBuy = nBuy / m_b8;
    return nBuy;
}

// @0x140db8400
// MS2-FUNCTIONAL: first-pass source; frame layout and temp order not byte-compared
int CNpcShopProductCli::FUN_140db8400()
{
    __int64 nPrice = FUN_140db8180();
    if (nPrice == 0)
        return 1;
    if (m_88 == 1)
    {
        int nRank = FUN_14053feb0(m_8c);
        int nHave = DAT_143ab2a90.FUN_140a5f180(m_8c, nRank);
        if (m_90 != 0)
            nHave = DAT_143ab2a90.FUN_140a5f7b0(m_90, 0);
        if (nHave / nPrice < (__int64)FUN_140db8210())
            return (int)(nHave / nPrice);
        return FUN_140db8210();
    }
    __int64 nHave = FUN_141349ef0(m_88, 0, (unsigned)nPrice);
    if (nHave / nPrice < (__int64)FUN_140db8210())
        return (int)(nHave / nPrice);
    return FUN_140db8210();
}

// @0x140db8580
// MS2-FUNCTIONAL: return value path/temp differs; source form unknown
int CNpcShopProductCli::FUN_140db8580(int nCount)
{
    __int64 nTotal = FUN_140db8180() * nCount;
    if (FUN_14134a030(m_88, m_8c, (int)nTotal) == 0)
    {
        FUN_14134a120(m_88, m_8c, (int)nTotal);
        return 0;
    }
    return 1;
}

// @0x140db8600
bool CNpcShopProductCli::FUN_140db8600()
{
    if (m_88 == 0xd && !FUN_1406a5930())
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_shop_no_star_point_event"), 0, 0, CStringW(L""));
        return false;
    }
    return true;
}

// @0x140db86d0
// MS2-FUNCTIONAL: return-copy / Format argument spill differ
CString CNpcShopProductCli::FUN_140db86d0()
{
    CString str;
    const char* pszCategory = m_b0;
    unsigned nItemId = m_40->FUN_1405276c0();
    str.Format("OnShop [ITEM_LIST] : nSerialID = %d, itemID = %u, price = %I64u, randomSeed = %u, nSellCount = %d, nBuyCount = %d, category=%s",
        (unsigned __int64)(unsigned)m_18, (unsigned __int64)nItemId, m_a0, m_50, m_5c, m_58, pszCategory);
    return str;
}

// ---- CNpcShopProductNewCli ------------------------------------------------------------------------------------------

// @0x140db87e0
CNpcShopProductNewCli::CNpcShopProductNewCli()
{
    m_1c = 2;
}

// @0x140db8b60
// MS2-FUNCTIONAL: the exe dtor stores no vptr (implicit); source form not found
CNpcShopProductNewCli::~CNpcShopProductNewCli() = default;

// @0x140db8840
void CNpcShopProductNewCli::FUN_140db8840(CInPacket& in)
{
    m_item.FUN_1406de840(in);
    FUN_14015f050(*reinterpret_cast<CString*>(&m_item.m_strName), m_20, ",");
    m_40.AssignRaw(new CItem());
    m_40->FUN_140523c40(m_item.m_nItemId, m_item.m_nRarity, 0);
}

// ---- CNpcShopMeratItemCli -------------------------------------------------------------------------------------------

// @0x140db8920
CNpcShopMeratItemCli::CNpcShopMeratItemCli() : m_30(0)
{
    m_40 = 1;
}

// @0x140db8980
CNpcShopMeratItemCli::~CNpcShopMeratItemCli()
{
    m_30 = 0;
}

// @0x140db8a00
void CNpcShopMeratItemCli::vfunc_2(CInPacket* pIn)
{
    CNpcShopMeratItemBase::vfunc_2(pIn);
    int nA = pIn->ReadInt32();
    int nB = pIn->ReadInt32();
    if (m_spProduct.get() != 0)
    {
        reinterpret_cast<Unk_ProdPremium*>(m_spProduct.operator->())->m_1c8 = nA;
        reinterpret_cast<Unk_ProdPremium*>(m_spProduct.operator->())->m_1cc = nB;
    }
}

// @0x140db8ac0
void CNpcShopMeratItemCli::FUN_140db8ac0(MS2Ptr<CItem> spItem)
{
    m_30 = spItem;
}

// @0x140db8b10
MS2Ptr<CItem> CNpcShopMeratItemCli::FUN_140db8b10()
{
    return m_30;
}

// @0x140db8b90
Unk_ShopLifeRef& FUN_140db8b90(Unk_ShopLifeRef& ref, NpcShopItemLife* p)
{
    Unk_ShopLifeRef tmp(p);
    NpcShopItemLife* pOld = ref.m_p;
    ref.m_p = tmp.m_p;
    tmp.m_p = pOld;
    return ref;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca5690-0x142ca56f0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140db5e20, CNpcShopProductBase, FUN_140db5e20, 65, 0xDB438C71);
MS2_REPLACE_METHOD(0x140db5e70, CNpcShopProductBase, FUN_140db5e70, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140db5ee0, CNpcShopProductBase, FUN_140db5ee0, 14, 0x8AEE455B);
MS2_REPLACE_METHOD(0x140db5f00, CNpcShopProductBase, FUN_140db5f00, 15, 0x5731F599);
MS2_REPLACE_METHOD(0x140db5f20, CNpcShopProductBase, vfunc_1, 11, 0x30025ED0);
MS2_REPLACE_METHOD(0x140db5f40, CNpcShopProductBase, vfunc_2, 8, 0x7F371472);
MS2_REPLACE_METHOD(0x140db6db0, CNpcShopProductCli, FUN_140db6db0, 69, 0x70CF012D);
MS2_REPLACE_METHOD(0x140db6e00, CNpcShopProductCli, FUN_140db6e00, 40, 0x1FEE011C);
MS2_REPLACE_METHOD(0x140db6e30, CNpcShopProductCli, FUN_140db6e30, 81, 0xFD40C69C);
MS2_REPLACE_METHOD(0x140db6e90, CNpcShopProductCli, FUN_140db6e90, 14, 0x5A3CA153);
MS2_REPLACE_METHOD(0x140db6eb0, CNpcShopProductCli, FUN_140db6eb0, 50, 0x18637C2F);
MS2_REPLACE_METHOD(0x140db6ef0, CNpcShopProductCli, FUN_140db6ef0, 14, 0x8A52079B);
MS2_REPLACE_METHOD(0x140db6f10, CNpcShopProductCli, FUN_140db6f10, 50, 0x49488A7F);
MS2_REPLACE_METHOD(0x140db6f50, CNpcShopProductCli, FUN_140db6f50, 14, 0x7245C177);
MS2_REPLACE_METHOD(0x140db6f70, CNpcShopProductCli, FUN_140db6f70, 50, 0x2A2F2617);
MS2_REPLACE_METHOD(0x140db6fb0, CNpcShopProductCli, FUN_140db6fb0, 14, 0xA1BBC3FF);
MS2_REPLACE_METHOD(0x140db6fd0, CNpcShopProductCli, FUN_140db6fd0, 17, 0xA49D819F);
MS2_REPLACE_METHOD(0x140db7040, CNpcShopProductBase, FUN_140db7040, 15, 0x5731F599);
MS2_REPLACE_METHOD(0x140db7060, CNpcShopProductCli, FUN_140db7060, 55, 0xA98A5A5B);
MS2_REPLACE_METHOD(0x140db70a0, CNpcShopProductCli, FUN_140db70a0, 4312, 0x60A5BCEC);
MS2_REPLACE_METHOD(0x140db8180, CNpcShopProductCli, FUN_140db8180, 18, 0x590460F1);
MS2_REPLACE_METHOD(0x140db81a0, CNpcShopProductCli, FUN_140db81a0, 18, 0x23C88FD9);
MS2_REPLACE_METHOD(0x140db81c0, CNpcShopProductCli, FUN_140db81c0, 69, 0xCD1EF701);
MS2_REPLACE_METHOD(0x140db8210, CNpcShopProductCli, FUN_140db8210, 484, 0x72A073E5);
MS2_REPLACE_METHOD(0x140db8400, CNpcShopProductCli, FUN_140db8400, 371, 0x3F8AEA03);
MS2_REPLACE_METHOD(0x140db8580, CNpcShopProductCli, FUN_140db8580, 122, 0x6C68DD87);
MS2_REPLACE_METHOD(0x140db8600, CNpcShopProductCli, FUN_140db8600, 190, 0x38C72280);
MS2_REPLACE_METHOD(0x140db8a00, CNpcShopMeratItemCli, vfunc_2, 186, 0xBEA2FAF8);
MS2_REPLACE(0x140db8b90, FUN_140db8b90, 97, 0x7C708882);

