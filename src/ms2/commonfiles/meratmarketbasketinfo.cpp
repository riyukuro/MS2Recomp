// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat (premium cash) market: basket entries, the
// premium product records and table (Table/Server/shop_merat.xml), market products and packets.
// MS2-UNIT: ?\meratmarketbasketinfo.cpp
// MS2-RANGE: 0x14069c3e0-0x1406ae9c0 .text$mn
// MS2-PIN: ??_7CMeratMarketPremium@@6B?$TSingleton@VCMeratMarketPremium@@@@@ 0x142d782c8
// MS2-PIN: ?Copy@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAXAEBV12@@Z 0x1406a98d0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCMeratMarketPremiumProduct@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMeratMarketPremiumProduct@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1406aa630
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@UPreminmMarketSaleEventContext@@@@AEAAXPEAX@Z 0x1406ae740
// MS2-PIN: ??8?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEBA_NPEAUPreminmMarketSaleEventContext@@@Z 0x1406a8f50
// MS2-RANGE: 0x1400bb3f0-0x1400bb6a0 .text$di
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@V?$CElementTraits@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@ATL@@@ATL@@QEAA@XZ 0x1406a86a0 ; merge-bind
// MS2-PIN: ??1?$MS2Ptr@VCUGCDesignData@@@@QEAA@XZ 0x1406a8930 ; merge-bind
// MS2-PIN: ?Reference@?$MS2Ptr@VCUGCDesignData@@@@CAXPEAVCUGCDesignData@@@Z 0x1406ae3e0 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VCUGCDesignData@@@@AEAAXXZ 0x1406ae6c0 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUGCDesignData@@@@AEAAXPEAX@Z 0x1406ae920 ; merge-bind
// cf9: preserve per-TU premium-event pointer copies.
// MS2-PIN: ??1?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAA@XZ 0x1406a8810
// MS2-PIN: ??4?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAAAEAV0@AEBV0@@Z 0x1406a8bc0
// MS2-PIN: ??C?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEBAPEAUPreminmMarketSaleEventContext@@XZ 0x1406a9100
// MS2-PIN: ??_G?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAAPEAXI@Z 0x1406a9190
// MS2-PIN: ?AddRef@?$MS2Ptr@UPreminmMarketSaleEventContext@@@@AEBAXXZ 0x1406ae220
// MS2-PIN: ?Release@?$MS2Ptr@UPreminmMarketSaleEventContext@@@@AEAAXXZ 0x1406ae540
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\meratmarketbasketinfo.cpp"   // no asserts of its own
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include <string>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmlprinter.h"
#include "ms2/placeholder/cfeaturemanager.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/ugcdesigntable.h"
#include <atlfile.h>
#include <algorithm>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_141425950(int nItemId);                                        // item name
CStringTable* GetStringTable();                                              // the string table singleton
CStringW FUN_141277a90(CUgcItemLook* pLook, const CStringW& strFallback);   // the UGC item name
CStringA FUN_140540050(const char* pszFormat, const CStringA& strArg);       // StringFormat with one string
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
int FUN_14028e280(CMsTime& out, const CStringA& strFormat, const CStringA& str); // parses a date string
struct Unk_MeratDefaultIcon { char m_pad[0xc0]; CStringA m_strIcon; };
Unk_MeratDefaultIcon* FUN_1401d31f0();
CShopEventManager* FUN_1403ed2a0();                                         // TSingleton<CShopEventManager>::GetInstance
void FUN_1407ce380(CShopEventManager* pManager, CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> >& arr,
                   const int& nCurrency);                                   // the sale events of a currency
bool FUN_1407cde30(PreminmMarketSaleEventContext* pContext, unsigned nId, int nCurrency);  // the event covers the id
int FUN_1407ce100(PreminmMarketSaleEventContext* pContext, int nPrice);    // the discounted price
bool FUN_1406a5840();
__int64 FUN_1406a61c0(__int64 nPrice, unsigned nRate);
__int64 FUN_1406a6150(__int64 nPrice, unsigned nRate);
CStringA FUN_14071a5b0(const CStringA& strDir, const CStringA& strFile);    // Table/<dir>/<file>
bool FUN_1406a4fe0(int nId);
bool FUN_1406a5010(int nId);
int FUN_140718170(const CString& strValue);                                 // a number or an enum name
HRESULT FUN_140299dc0(ATL::CAtlFile* pFile, const void* pData, DWORD nSize, DWORD* pWritten);  // writes the data
CFeatureManager* FUN_140166410();                                           // the CFeatureManager singleton
CGameEventValueManager* FUN_140302b00();                                    // TSingleton<CGameEventValueManager>::GetInstance
int FUN_140427050(Unk_GameEventLockedValue<0x38>* pValue);                 // the star shop npc
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
unsigned FUN_1402227e0(int nJob, int n);                                    // job -> job flag
bool FUN_140633d50(MS2Ptr<CItem> spItem);                                   // the item can be traded
// CItemDataTable::GetMusicScore / CUGCDesignTable::GetData are not in the link set; reached by VA.
class Unk_MeratItemTable { public: MS2Ptr<ItemMusicScore> FUN_1405565f0(unsigned nId); };
class Unk_MeratDesignTable { public: CUGCDesignDataPtr FUN_14089e9f0(unsigned nItemId); };
Unk_MeratItemTable* FUN_140281980();
__int64 FUN_1406a6d50(Common::Constants::Value<int>& value);

// The UGC sell fees per server (FUN_1401c0db0()).
class Unk_MeratPriceTable
{
public:
    __int64 FUN_140674bb0(int nItemId, const CString& strServer);
    void FUN_140674d70(const CString& strServer, __int64* pMin, __int64* pMax);
};
Unk_MeratPriceTable* FUN_1401c0db0();

// The blocked-action flags of the client config (FUN_14025e7b0()).
class Unk_MeratFlagSet { public: int FUN_1402c4c90(int nFlag); };
struct Unk_MeratConfig
{
    void* m_p00;
    Unk_MeratFlagSet m_flags;                                               // +0x08
};
Unk_MeratConfig* FUN_14025e7b0();

// The owner a UGC market listing is checked against.
struct Unk_MeratItemOwner
{
    __int64 m_nId;                                                          // +0x00
    int m_nType;                                                            // +0x08
};
bool FUN_14026d4d0(const Unk_MeratItemOwner* pOwner, int nType, __int64 nId);   // the owner matches

// CItemUgc (item.h, which clashes with ugcdef.h): the UGC info of an inventory item.
class Unk_MeratItemUgc : public CPtred
{
public:
    int FUN_1406321a0();
    int FUN_1406321d0();

    CUgcItemLook m_look;                                                    // +0x18
    CBlueprintItemData m_blueprint;                                         // +0x80
};
MS2_CHECK_OFFSET(Unk_MeratItemUgc, m_blueprint, 0x80);

// CItemCustomMusicScore (item.h): the custom music score of an inventory item.
class Unk_MeratMusicScore : public CPtred
{
public:
    int m_n18;                                                              // +0x18
    int m_n1c;                                                              // +0x1c a music book id
    CStringW m_str20;                                                       // +0x20
    CStringW m_str28;                                                       // +0x28
    CString m_str30;                                                        // +0x30
    int m_n38;                                                              // +0x38
    __int64 m_n40;                                                          // +0x40
    __int64 m_n48;                                                          // +0x48
    int m_nNoteType;                                                        // +0x50
    __int64 m_nNoteId;                                                      // +0x58
};
MS2_CHECK_OFFSET(Unk_MeratMusicScore, m_nNoteId, 0x58);

// The job limit of a market entry (only the job flags are read).
struct Unk_MeratJobLimit
{
    char m_pad[0x98];
    unsigned m_nJobFlags;                                                   // +0x98
};
MS2_CHECK_OFFSET(Unk_MeratJobLimit, m_nJobFlags, 0x98);

// The merat market home layouts (Table/Server/*HomeLayout.xml) and their product ids.
class Unk_MeratHomeLayout
{
public:
    void Load();

    TiXmlDocument m_meratDoc;                                               // +0x00
    CAtlList<int> m_meratItems;                                             // +0x70
    TiXmlDocument m_premiumDoc;                                             // +0xa0
    CAtlList<int> m_premiumItems;                                           // +0x110
    TiXmlDocument m_designersDoc;                                           // +0x140
};
MS2_CHECK_OFFSET(Unk_MeratHomeLayout, m_premiumDoc, 0xa0);
MS2_CHECK_OFFSET(Unk_MeratHomeLayout, m_designersDoc, 0x140);

typedef CRBMap<Unk_MeratProductKey, MS2Ptr<CMeratMarketProduct> > Unk_MeratProductMap;

// The common log (FUN_140166440()).
class Unk_MeratLog : public CLogString
{
public:
    template <class T> void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* format, const T& value)
    {
        fmt::internal::Value values[] = { fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value) };
        FUN_1406535b0(a, b, flags, format, fmt::ArgList(fmt::internal::make_type(value), values));
    }
};
Unk_MeratLog* FUN_140166440();

// ---- statics (.text$di in this order) -----------------------------------------------------------------------------

CLockCriticalSection CMeratMarketPremium::s_lock;
CStringA g_premiumSortNames[8] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };
CStringA g_ugcSortNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
CStringA g_strDesignersHomeLayout("designersHomeLayout.xml");
CStringA g_strMeratHomeLayout("meratHomeLayout.xml");
CStringA g_strPremiumHomeLayout("premiumHomeLayout.xml");
std::string g_strLocaleDir("kr/");
std::string g_strLocaleDir2("kr/");

// ---- CMeratMarketBasketInfo ------------------------------------------------------------------------------------------

// @0x14069c3e0
int FUN_14069c3e0(int nType)
{
    switch (nType)
    {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 9;
    case 3:
        return 0x11;
    default:
        return 1;
    }
}
MS2_REPLACE(0x14069C3E0, FUN_14069c3e0, 79, 0x5DB2E5B1);

// @0x14069c440
CMeratMarketBasketInfo::CMeratMarketBasketInfo()
{
    m_nKind = 2;
    m_key.Reset();
    m_n30 = 0;
    m_n38 = 0;
    m_n3c = 0;
    m_n40 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n50 = 0;
    m_n58 = 0;
}

// @0x14069c510
CMeratMarketBasketInfo::~CMeratMarketBasketInfo()
{
}

// @0x14069c540
void CMeratMarketBasketInfo::Write(COutputStream* pStream)
{
    pStream->vfunc_o10_1((unsigned char)m_nKind);
    m_key.Write(*pStream);
    pStream->vfunc_o10_4(m_n30);
    pStream->vfunc_o10_1((unsigned char)m_n38);
    pStream->vfunc_o10_3(m_n3c);
    pStream->vfunc_o10_3(m_n40);
    pStream->vfunc_o10_1((unsigned char)m_n44);
    pStream->vfunc_o10_3(m_n48);
    pStream->vfunc_o10_4(m_n50);
    pStream->vfunc_o10_4(m_n58);
}
MS2_REPLACE_METHOD(0x14069C540, CMeratMarketBasketInfo, Write, 263, 0x23EDB9E2);

// @0x14069c650
void CMeratMarketBasketInfo::Read(CInPacket& packet)
{
    m_nKind = packet.vfunc_o8_1();
    m_key.Read(packet);
    m_n30 = packet.vfunc_o8_4();
    m_n38 = packet.vfunc_o8_1();
    m_n3c = packet.vfunc_o8_3();
    m_n40 = packet.vfunc_o8_3();
    m_n44 = packet.vfunc_o8_1();
    m_n48 = packet.vfunc_o8_3();
    m_n50 = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x14069C650, CMeratMarketBasketInfo, Read, 518, 0x5F2177E5);

// ---- CDBPremiumProduct -----------------------------------------------------------------------------------------------

// @0x14069c860
CDBPremiumProduct::CDBPremiumProduct()
{
    Reset();
}

// @0x14069c9c0
CDBPremiumProduct::~CDBPremiumProduct()
{
}

// @0x14069ca70
void CDBPremiumProduct::Reset()
{
    m_nId = 0;
    m_n1c = 8;
    m_strName.Empty();
    m_nType = 0;
    m_n2c = 0;
    m_nChartOrder = 0;
    m_nCouponFlags = 0;
    m_bVisible = 0;
    m_nSaleTag = 0;
    m_nCurrency = 0;
    m_nPrice = 0;
    m_nSalePrice = 0;
    m_n58 = 0;
    m_startDate = 0;
    m_endDate = 0;
    m_n80 = 0;
    m_n84 = 0;
    m_nBuyLimit = 0;
    m_nBuyLimitMax = 0;
    m_n90 = 0;
    m_n94 = 0;
    m_n96 = 0;
    m_n98 = 0xfff;
    m_nItemId = 0;
    m_nGrade = 0;
    m_nb0 = 0;
    m_nb4 = 0;
    m_nb8 = 0;
    m_nCategoryId = 0;
    m_nLimitCount = 0;
    m_nc4 = 0;
    m_arrc8.RemoveAll();
    m_n9c = 0;
    m_strCategory.Empty();
    m_bf0 = false;
    m_n120 = 0;
    m_n124 = 0;
    m_n128 = 0;
    m_nf4 = 0;
    m_n104 = 0;
    m_b108 = false;
    m_nf8 = 0;
    m_nfc = 0;
    m_n100 = 0;
    m_n10c = 0;
    m_bPoint = false;
    m_nPoint = 0;
    m_eventStart = 0;
    m_eventEnd = 0;
    m_strEventCategory.Empty();
    m_n158 = 0;
    m_b168 = false;
    m_n16c = 0;
    m_n170 = 0;
    m_n174 = 0;
    m_time178 = 0;
    m_time188 = 0;
    m_time198 = 0;
    m_n1a8 = 0;
    m_n1ac = 0;
    m_n1b0 = 0;
    m_n1b4 = 0;
    m_randomSaleDay = 0;
}

// @0x14069ce50
// MS2-FUNCTIONAL: the exe is 83 bytes longer; its field copy order and temporaries are not recovered
void CDBPremiumProduct::CopyFrom(const CDBPremiumProduct* pOther)
{
    if (!pOther)
        return;
    m_nId = pOther->m_nId;
    m_n1c = pOther->m_n1c;
    m_strName = pOther->m_strName;
    m_nType = pOther->m_nType;
    m_n2c = pOther->m_n2c;
    m_nChartOrder = pOther->m_nChartOrder;
    m_nCouponFlags = pOther->m_nCouponFlags;
    m_bVisible = pOther->m_bVisible;
    m_nSaleTag = pOther->m_nSaleTag;
    m_nCurrency = pOther->m_nCurrency;
    m_nPrice = pOther->m_nPrice;
    m_nSalePrice = pOther->m_nSalePrice;
    m_n58 = pOther->m_n58;
    m_startDate = pOther->m_startDate;
    m_endDate = pOther->m_endDate;
    m_n80 = pOther->m_n80;
    m_n84 = pOther->m_n84;
    m_nBuyLimit = pOther->m_nBuyLimit;
    m_nBuyLimitMax = pOther->m_nBuyLimitMax;
    m_n90 = pOther->m_n90;
    m_n94 = pOther->m_n94;
    m_n96 = pOther->m_n96;
    m_n98 = pOther->m_n98;
    m_nItemId = pOther->m_nItemId;
    m_nGrade = pOther->m_nGrade;
    m_nb0 = pOther->m_nb0;
    m_nb4 = pOther->m_nb4;
    m_nb8 = pOther->m_nb8;
    m_nCategoryId = pOther->m_nCategoryId;
    m_nLimitCount = pOther->m_nLimitCount;
    m_nc4 = pOther->m_nc4;
    m_arrc8.Copy(pOther->m_arrc8);
    m_n9c = pOther->m_n9c;
    m_strCategory = pOther->m_strCategory;
    m_bf0 = pOther->m_bf0;
    m_n120 = pOther->m_n120;
    m_n124 = pOther->m_n124;
    m_n128 = pOther->m_n128;
    m_nf4 = pOther->m_nf4;
    m_n104 = pOther->m_n104;
    m_b108 = pOther->m_b108;
    m_nf8 = pOther->m_nf8;
    m_nfc = pOther->m_nfc;
    m_n100 = pOther->m_n100;
    m_n10c = pOther->m_n10c;
    m_bPoint = pOther->m_bPoint;
    m_nPoint = pOther->m_nPoint;
    m_eventStart = pOther->m_eventStart;
    m_eventEnd = pOther->m_eventEnd;
    m_strEventCategory = pOther->m_strEventCategory;
    m_n158 = pOther->m_n158;
    m_b168 = pOther->m_b168;
    m_n16c = pOther->m_n16c;
    m_n170 = pOther->m_n170;
    m_n174 = pOther->m_n174;
    m_time178 = pOther->m_time178;
    m_time188 = pOther->m_time188;
    m_time198 = pOther->m_time198;
    m_n1a8 = pOther->m_n1a8;
    m_n1ac = pOther->m_n1ac;
    m_n1b0 = pOther->m_n1b0;
    m_n1b4 = pOther->m_n1b4;
    m_randomSaleDay = pOther->m_randomSaleDay;
}

// @0x14069d460
void CDBPremiumProduct::Write(COutputStream& stream)
{
    stream.vfunc_o10_3(m_nId);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_8(m_strName);
    stream.vfunc_o10_1((unsigned char)m_nType);
    stream.vfunc_o10_3(m_n2c);
    stream.vfunc_o10_3(m_nChartOrder);
    stream.vfunc_o10_3(m_nCouponFlags);
    stream.vfunc_o10_1((unsigned char)m_bVisible);
    stream.vfunc_o10_1((unsigned char)m_nSaleTag);
    stream.vfunc_o10_1((unsigned char)m_nCurrency);
    stream.vfunc_o10_4(m_nPrice);
    stream.vfunc_o10_4(m_nSalePrice);
    stream.vfunc_o10_1((unsigned char)m_n58);
    stream.vfunc_o10_4(m_startDate.Get());
    stream.vfunc_o10_4(m_endDate.Get());
    stream.vfunc_o10_3(m_n80);
    stream.vfunc_o10_3(m_n84);
    stream.vfunc_o10_1((unsigned char)m_nBuyLimit);
    stream.vfunc_o10_3(m_nBuyLimitMax);
    stream.vfunc_o10_1((unsigned char)m_n90);
    stream.vfunc_o10_2(m_n94);
    stream.vfunc_o10_2(m_n96);
    stream.vfunc_o10_3(m_n98);
    stream.vfunc_o10_3(m_nItemId);
    stream.vfunc_o10_1((unsigned char)m_nGrade);
    stream.vfunc_o10_3(m_nb0);
    stream.vfunc_o10_3(m_nb4);
    stream.vfunc_o10_3(m_nb8);
    stream.vfunc_o10_3(m_nCategoryId);
    stream.vfunc_o10_3(m_nLimitCount);
    stream.vfunc_o10_1((unsigned char)m_nc4);
    stream.vfunc_o10_3(m_n9c);
    stream.vfunc_o10_7(m_strCategory);
    stream.vfunc_o10_7(m_strIcon);
    stream.vfunc_o10_0(m_bf0);
    stream.vfunc_o10_1((unsigned char)m_nf4);
    stream.vfunc_o10_3(m_n104);
    stream.vfunc_o10_0(m_b108);
    stream.vfunc_o10_3(m_nf8);
    stream.vfunc_o10_3(m_nfc);
    stream.vfunc_o10_3(m_n100);
    stream.vfunc_o10_1((unsigned char)m_n10c);
    stream.vfunc_o10_0(m_bPoint);
    stream.vfunc_o10_3((int)m_nPoint);
    if (!m_eventStart.IsNull())
    {
        stream.vfunc_o10_0(true);
        stream.vfunc_o10_7(m_strEventCategory);
        stream.vfunc_o10_4(m_eventStart.Get());
        stream.vfunc_o10_4(m_eventEnd.Get());
    }
    else
    {
        stream.vfunc_o10_0(false);
    }
    stream.vfunc_o10_1((unsigned char)m_n158);
    stream.vfunc_o10_6(m_str160);
    stream.vfunc_o10_0(m_b168);
    if (m_nType == 6)
    {
        stream.vfunc_o10_1((unsigned char)m_n16c);
        stream.vfunc_o10_1((unsigned char)m_n170);
        stream.vfunc_o10_3(m_n174);
        stream.vfunc_o10_4(m_time178.Get());
        stream.vfunc_o10_4(m_time188.Get());
        stream.vfunc_o10_4(m_time198.Get());
        stream.vfunc_o10_3(m_n1a8);
    }
    if (m_nType == 7 || m_nType == 8)
    {
        stream.vfunc_o10_3(m_n1ac);
        stream.vfunc_o10_3(m_n1b0);
        stream.vfunc_o10_3(m_n1b4);
        stream.vfunc_o10_4(m_randomSaleDay.Get());
    }
}

// @0x14069de70
// MS2-FUNCTIONAL: the exe frame is 0x10 larger; the CString read temporaries are laid out differently
void CDBPremiumProduct::Read(CInPacket& packet)
{
    m_nId = packet.vfunc_o8_3();
    m_n1c = packet.vfunc_o8_1();
    m_strName = packet.vfunc_o8_8();
    m_nType = packet.vfunc_o8_1();
    m_n2c = packet.vfunc_o8_3();
    m_nChartOrder = packet.vfunc_o8_3();
    m_nCouponFlags = packet.vfunc_o8_3();
    m_bVisible = packet.vfunc_o8_1();
    m_nSaleTag = packet.vfunc_o8_1();
    m_nCurrency = packet.vfunc_o8_1();
    m_nPrice = packet.vfunc_o8_4();
    m_nSalePrice = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_1();
    m_startDate = packet.vfunc_o8_4();
    m_endDate = packet.vfunc_o8_4();
    m_n80 = packet.vfunc_o8_3();
    m_n84 = packet.vfunc_o8_3();
    m_nBuyLimit = packet.vfunc_o8_1();
    m_nBuyLimitMax = packet.vfunc_o8_3();
    m_n90 = packet.vfunc_o8_1();
    m_n94 = packet.vfunc_o8_2();
    m_n96 = packet.vfunc_o8_2();
    m_n98 = packet.vfunc_o8_3();
    m_nItemId = packet.vfunc_o8_3();
    m_nGrade = packet.vfunc_o8_1();
    m_nb0 = packet.vfunc_o8_3();
    m_nb4 = packet.vfunc_o8_3();
    m_nb8 = packet.vfunc_o8_3();
    m_nCategoryId = packet.vfunc_o8_3();
    m_nLimitCount = packet.vfunc_o8_3();
    m_nc4 = packet.vfunc_o8_1();
    m_n9c = packet.vfunc_o8_3();
    m_strCategory = packet.vfunc_o8_7();
    m_strIcon = packet.vfunc_o8_7();
    m_bf0 = packet.vfunc_o8_0();
    m_nf4 = packet.vfunc_o8_1();
    m_n104 = packet.vfunc_o8_3();
    m_b108 = packet.vfunc_o8_0();
    m_nf8 = packet.vfunc_o8_3();
    m_nfc = packet.vfunc_o8_3();
    m_n100 = packet.vfunc_o8_3();
    m_n10c = packet.vfunc_o8_1();
    m_bPoint = packet.vfunc_o8_0();
    m_nPoint = (unsigned)packet.vfunc_o8_3();
    if (packet.vfunc_o8_0())
    {
        m_strEventCategory = packet.vfunc_o8_7();
        m_eventStart = packet.vfunc_o8_4();
        m_eventEnd = packet.vfunc_o8_4();
    }
    m_n158 = packet.vfunc_o8_1();
    m_str160 = packet.vfunc_o8_6();
    m_b168 = packet.vfunc_o8_0();
    if (m_nType == 6)
    {
        m_n16c = packet.vfunc_o8_1();
        m_n170 = packet.vfunc_o8_1();
        m_n174 = packet.vfunc_o8_3();
        m_time178 = packet.vfunc_o8_4();
        m_time188 = packet.vfunc_o8_4();
        m_time198 = packet.vfunc_o8_4();
        m_n1a8 = packet.vfunc_o8_3();
    }
    if (m_nType == 7 || m_nType == 8)
    {
        m_n1ac = packet.vfunc_o8_3();
        m_n1b0 = packet.vfunc_o8_3();
        m_n1b4 = packet.vfunc_o8_3();
        m_randomSaleDay = packet.vfunc_o8_4();
    }
}

// @0x14069eeb0
void CDBPremiumProduct::WriteBrief(COutputStream& stream)
{
    stream.vfunc_o10_3(m_nId);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_8(m_strName);
    stream.vfunc_o10_1((unsigned char)m_nType);
    stream.vfunc_o10_3(m_n2c);
    stream.vfunc_o10_3(m_nCouponFlags);
    stream.vfunc_o10_1((unsigned char)m_bVisible);
    stream.vfunc_o10_1((unsigned char)m_nSaleTag);
    stream.vfunc_o10_1((unsigned char)m_nCurrency);
    stream.vfunc_o10_4(m_nPrice);
    stream.vfunc_o10_4(m_nSalePrice);
    stream.vfunc_o10_1((unsigned char)m_n58);
    stream.vfunc_o10_3(m_n80);
    stream.vfunc_o10_3(m_n84);
    stream.vfunc_o10_1((unsigned char)m_nBuyLimit);
    stream.vfunc_o10_3(m_nBuyLimitMax);
    stream.vfunc_o10_1((unsigned char)m_n90);
    stream.vfunc_o10_2(m_n94);
    stream.vfunc_o10_2(m_n96);
    stream.vfunc_o10_3(m_n98);
    stream.vfunc_o10_3(m_nItemId);
    stream.vfunc_o10_1((unsigned char)m_nGrade);
    stream.vfunc_o10_3(m_nb0);
    stream.vfunc_o10_3(m_nb4);
    stream.vfunc_o10_3(m_nb8);
    stream.vfunc_o10_3(m_nCategoryId);
    stream.vfunc_o10_3(m_nf8);
    stream.vfunc_o10_3(m_nfc);
    stream.vfunc_o10_1((unsigned char)m_n10c);
    stream.vfunc_o10_0(m_bPoint);
    stream.vfunc_o10_3((int)m_nPoint);
}

// @0x14069f210
void CDBPremiumProduct::ReadBrief(CInPacket& packet)
{
    m_nId = packet.vfunc_o8_3();
    m_n1c = packet.vfunc_o8_1();
    m_strName = packet.vfunc_o8_8();
    m_nType = packet.vfunc_o8_1();
    m_n2c = packet.vfunc_o8_3();
    m_nCouponFlags = packet.vfunc_o8_3();
    m_bVisible = packet.vfunc_o8_1();
    m_nSaleTag = packet.vfunc_o8_1();
    m_nCurrency = packet.vfunc_o8_1();
    m_nPrice = packet.vfunc_o8_4();
    m_nSalePrice = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_1();
    m_n80 = packet.vfunc_o8_3();
    m_n84 = packet.vfunc_o8_3();
    m_nBuyLimit = packet.vfunc_o8_1();
    m_nBuyLimitMax = packet.vfunc_o8_3();
    m_n90 = packet.vfunc_o8_1();
    m_n94 = packet.vfunc_o8_2();
    m_n96 = packet.vfunc_o8_2();
    m_n98 = packet.vfunc_o8_3();
    m_nItemId = packet.vfunc_o8_3();
    m_nGrade = packet.vfunc_o8_1();
    m_nb0 = packet.vfunc_o8_3();
    m_nb4 = packet.vfunc_o8_3();
    m_nb8 = packet.vfunc_o8_3();
    m_nCategoryId = packet.vfunc_o8_3();
    m_nf8 = packet.vfunc_o8_3();
    m_nfc = packet.vfunc_o8_3();
    m_n10c = packet.vfunc_o8_1();
    m_bPoint = packet.vfunc_o8_0();
    m_nPoint = (unsigned)packet.vfunc_o8_3();
}

// @0x14069f980
// MS2-FUNCTIONAL: the sale-event loop codegen differs (exe 30 bytes shorter)
__int64 CDBPremiumProduct::GetSalePrice(const CDBPremiumProduct* pParent)
{
    if (m_nType == 3 || m_nType == 6 || m_nType == 7)
        return m_nSalePrice;
    else if (m_nType == 8)
        return FUN_1406a61c0(m_nSalePrice, m_n1b0);

    int nCurrency = GetCurrencyItemId();
    if (nCurrency == 0)
        return m_nSalePrice;

    unsigned nCouponFlags = m_nCouponFlags;
    if (pParent && m_nType == 2)
        nCouponFlags = pParent->m_nCouponFlags;
    MS2Ptr<PreminmMarketSaleEventContext> spBest(0);
    if (nCouponFlags & 1)
    {
        CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> > arrAll;
        const int nAllCurrency = 100002;
        FUN_1407ce380(FUN_1403ed2a0(), arrAll, nAllCurrency);
        if (!arrAll.IsEmpty())
        {
            int nCount = (int)arrAll.GetCount();
            for (int i = 0; i < nCount; i++)
            {
                MS2Ptr<PreminmMarketSaleEventContext>& spContext = arrAll[i];
                if (spContext == 0)
                    continue;
                if (!(spBest == 0) && spContext->m_18 <= spBest->m_18)
                    continue;
                spBest = spContext;
            }
        }
    }
    CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> > arr;
    FUN_1407ce380(FUN_1403ed2a0(), arr, nCurrency);
    if (!arr.IsEmpty())
    {
        std::vector<unsigned> ids;
        ids.reserve(5);
        ids.push_back(0);
        if (0 < m_nCategoryId)
        {
            const unsigned nCategoryId = m_nCategoryId;
            ids.push_back(nCategoryId);
        }
        if (0 < (int)nCouponFlags)
            FUN_14069ffc0(ids, nCouponFlags);
        int nCount = (int)arr.GetCount();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<PreminmMarketSaleEventContext>& spContext = arr[i];
            if (spContext == 0)
                continue;
            for (size_t j = 0; j < ids.size(); j++)
            {
                unsigned nId = ids[j];
                if (!FUN_1407cde30(spContext.operator->(), nId, nCurrency))
                    continue;
                if (!(spBest == 0) && spContext->m_18 <= spBest->m_18)
                    continue;
                spBest = spContext;
            }
        }
    }
    if (spBest.get() == NULL)
        return m_nSalePrice;
    return FUN_1407ce100(spBest.operator->(), (int)m_nSalePrice);
}
MS2_REPLACE_METHOD(0x14069F980, CDBPremiumProduct, GetSalePrice, 1149, 0xF2A3A3EA);

// @0x14069fe10
// MS2-FUNCTIONAL: the exe homes r8, an unused parameter that is not recovered
__int64 CDBPremiumProduct::GetPoint()
{
    return m_bPoint ? m_nPoint : 0;
}
MS2_REPLACE_METHOD(0x14069FE10, CDBPremiumProduct, GetPoint, 38, 0xDC68781C);

// @0x14069fe40
// MS2-FUNCTIONAL: branch layout differs (exe 10 bytes shorter)
int CDBPremiumProduct::FUN_14069fe40()
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_nItemId);
    if (spItem.get())
    {
        if (spItem->property.slotMax > 1 && m_nb4 == 0)
            return 1;
        return 2;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14069FE40, CDBPremiumProduct, FUN_14069fe40, 153, 0xD3C9C9A1);

// @0x14069fee0
int CDBPremiumProduct::FUN_14069fee0()
{
    return m_n10c;
}
MS2_REPLACE_METHOD(0x14069FEE0, CDBPremiumProduct, FUN_14069fee0, 17, 0xFFA719EE);

// @0x14069ff00
bool CDBPremiumProduct::FUN_14069ff00()
{
    if (!m_bPoint)
        return false;
    return m_nPoint > 0;
}
MS2_REPLACE_METHOD(0x14069FF00, CDBPremiumProduct, FUN_14069ff00, 69, 0xB9AF4874);

// @0x14069ff50
bool CDBPremiumProduct::FUN_14069ff50()
{
    if (m_n90 == 0 || m_n90 == 99)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14069FF50, CDBPremiumProduct, FUN_14069ff50, 40, 0xB45F7A29);

// @0x14069ff80
int CDBPremiumProduct::GetCurrencyItemId()
{
    if (m_nCurrency == 1)
        return 100000;
    else if (m_nCurrency == 2)
        return 100001;
    return 0;
}
MS2_REPLACE_METHOD(0x14069FF80, CDBPremiumProduct, GetCurrencyItemId, 44, 0xE8D982E0);

// @0x14069ffc0
bool CDBPremiumProduct::FUN_14069ffc0(std::vector<unsigned>& ids, const unsigned& nFlags)
{
    if (nFlags == 0 || nFlags == 1)
        return false;
    if ((nFlags & 2) || (nFlags & 8))
        ids.push_back(10);
    if ((nFlags & 4) || (nFlags & 0x10))
        ids.push_back(11);
    return !ids.empty();
}
MS2_REPLACE_METHOD(0x14069FFC0, CDBPremiumProduct, FUN_14069ffc0, 193, 0x0D2AE106);

// @0x1406a0090
bool CDBPremiumProduct::FUN_1406a0090()
{
    if (m_n1ac == 0)
        return true;
    if (IsNotRecentDayChange(m_randomSaleDay.Get()))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0090, CDBPremiumProduct, FUN_1406a0090, 69, 0x0A3F66AA);

// @0x1406a00e0
CStringW CDBPremiumProduct::GetName()
{
    if (m_nType == 3)
        return m_strName;
    return FUN_141425950(m_nItemId);
}
MS2_REPLACE_METHOD(0x1406A00E0, CDBPremiumProduct, GetName, 116, 0x15484927);

// @0x1406a0160
// MS2-FUNCTIONAL: the order of the path temporaries differs
CStringA CDBPremiumProduct::GetIconPath()
{
    if (m_nType == 3)
    {
        if (m_strIcon.IsEmpty())
            return FUN_1401d31f0()->m_strIcon;
        return FUN_140540050("./Data/Resource/Image/Item/icon/{0}", m_strIcon);
    }
    return CStringA("");
}
MS2_REPLACE_METHOD(0x1406A0160, CDBPremiumProduct, GetIconPath, 191, 0x7FE7101A);

// @0x1406a0230
int CDBPremiumProduct::FUN_1406a0230()
{
    int nCurrency = m_nCurrency;
    if (nCurrency == 3)
        nCurrency = 1;
    return FUN_14069c3e0(nCurrency);
}
MS2_REPLACE_METHOD(0x1406A0230, CDBPremiumProduct, FUN_1406a0230, 50, 0xEF9BAC3A);

// @0x1406a0270
__int64 CDBPremiumProduct::FUN_1406a0270()
{
    if (m_nType != 7)
        return 0;
    __int64 nPrice = FUN_1406a6150(m_nSalePrice, m_n1b0);
    return nPrice;
}
MS2_REPLACE_METHOD(0x1406A0270, CDBPremiumProduct, FUN_1406a0270, 64, 0xC6CAFFCB);

// @0x1406a02c0
// MS2-FUNCTIONAL: the day-text building temporaries differ (exe 55 bytes longer)
CStringW CDBPremiumProduct::GetSellDayText()
{
    if (m_nType == 7 || m_nType == 8)
    {
        CMsTime zero(0);
        if (!(m_randomSaleDay == zero))
        {
            const CStringW& strFormat = GetStringCommonByKey(CStringW(L"s_meratmarket_tooltip_sell_day"));
            int nDay = m_randomSaleDay.GetDay();
            int nMonth = m_randomSaleDay.GetMonth();
            int nYear = m_randomSaleDay.GetYear();
            return StringFormat((const wchar_t*)strFormat, nYear, nMonth, nDay);
        }
    }
    return CStringW(L"");
}
MS2_REPLACE_METHOD(0x1406A02C0, CDBPremiumProduct, GetSellDayText, 446, 0xFE195BD6);

// ---- CMeratMarketPremiumProduct --------------------------------------------------------------------------------------

// @0x1406a0490
CMeratMarketPremiumProduct::CMeratMarketPremiumProduct()
    : m_mapSub(10), m_mapLimit(10)
{
    Reset();
}

// @0x1406a0510
CMeratMarketPremiumProduct::~CMeratMarketPremiumProduct()
{
}

// @0x1406a0570
void CMeratMarketPremiumProduct::Reset()
{
    CDBPremiumProduct::Reset();
    SetCounts(0, 0, 0);
    m_mapSub.RemoveAll();
    m_mapLimit.RemoveAll();
}
MS2_REPLACE_METHOD(0x1406A0570, CMeratMarketPremiumProduct, Reset, 80, 0x94908197);

// @0x1406a05d0
BOOL CMeratMarketPremiumProduct::Copy(MS2Ptr<CDBPremiumProduct> spProduct)
{
    if (spProduct == 0)
        return FALSE;
    if (spProduct->m_nType != 1 && spProduct->m_nType != 3 && spProduct->m_nType != 6 && spProduct->m_nType != 7 &&
        spProduct->m_nType != 8)
        return FALSE;
    CDBPremiumProduct::CopyFrom(spProduct.get());
    SetCounts(0, 0, 0);
    m_mapSub.RemoveAll();
    m_mapLimit.RemoveAll();
    return TRUE;
}

// @0x1406a06f0
// MS2-FUNCTIONAL: the copy order differs (exe 22 bytes shorter)
BOOL CMeratMarketPremiumProduct::Copy(MS2Ptr<CMeratMarketPremiumProduct> spProduct, int nBuyCount, int nLimitCount,
                                      int nHomeCount)
{
    if (spProduct == 0)
        return FALSE;
    if (spProduct->m_nType != 1 && spProduct->m_nType != 3 && spProduct->m_nType != 6 && spProduct->m_nType != 7 &&
        spProduct->m_nType != 8)
        return FALSE;
    CDBPremiumProduct::CopyFrom(spProduct.get());
    SetCounts(nBuyCount, nLimitCount, nHomeCount);
    m_mapSub.RemoveAll();
    POSITION pos = spProduct->m_mapSub.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct>& spSub = spProduct->m_mapSub.GetValueAt(pos);
        const int& nKey = spProduct->m_mapSub.GetKeyAt(pos);
        m_mapSub.SetAt(nKey, spSub);
        spProduct->m_mapSub.GetNext(pos);
    }
    m_mapLimit.RemoveAll();
    pos = spProduct->m_mapLimit.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct>& spSub = spProduct->m_mapLimit.GetValueAt(pos);
        const int& nKey = spProduct->m_mapLimit.GetKeyAt(pos);
        m_mapLimit.SetAt(nKey, spSub);
        spProduct->m_mapLimit.GetNext(pos);
    }
    return TRUE;
}

// @0x1406a0970
void CMeratMarketPremiumProduct::SetCounts(int nBuyCount, int nLimitCount, int nHomeCount)
{
    m_nBuyCount = nBuyCount;
    m_nSoldCount = nLimitCount;
    m_nHomeSoldCount = nHomeCount;
}
MS2_REPLACE_METHOD(0x1406A0970, CMeratMarketPremiumProduct, SetCounts, 65, 0xD1469120);

// @0x1406a09c0
BOOL CMeratMarketPremiumProduct::HasLimit()
{
    switch (m_nType)
    {
    case 1:
    case 7:
    case 8:
        return m_nBuyLimit != 0;
    case 3:
    case 6:
        return m_nLimitCount != 0 || m_nBuyLimit != 0;
    }
    return FALSE;
}
MS2_REPLACE_METHOD(0x1406A09C0, CMeratMarketPremiumProduct, HasLimit, 149, 0xB461C77D);

// @0x1406a0a60
bool CMeratMarketPremiumProduct::IsBuyLimitReached()
{
    if (!HasLimit())
        return false;
    if (m_nBuyLimit)
        return m_nBuyCount >= m_nBuyLimitMax;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0A60, CMeratMarketPremiumProduct, IsBuyLimitReached, 97, 0x258A820F);

// @0x1406a0ad0
bool CMeratMarketPremiumProduct::IsLimitSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType != 3)
        return false;
    if (m_nLimitCount == 0)
        return false;
    return m_nSoldCount >= m_nLimitCount;
}
MS2_REPLACE_METHOD(0x1406A0AD0, CMeratMarketPremiumProduct, IsLimitSoldOut, 112, 0x7FDBB94B);

// @0x1406a0b50
bool CMeratMarketPremiumProduct::IsHomeSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType != 6)
        return false;
    if (m_nLimitCount == 0)
        return false;
    return m_nHomeSoldCount >= m_nLimitCount;
}
MS2_REPLACE_METHOD(0x1406A0B50, CMeratMarketPremiumProduct, IsHomeSoldOut, 112, 0x271C8904);

// @0x1406a0bd0
int CMeratMarketPremiumProduct::GetRemainCount()
{
    int nRemain = 0;
    if (m_nType == 3)
    {
        if (0 < m_nLimitCount)
            nRemain = m_nLimitCount - m_nSoldCount < 0 ? 0 : m_nLimitCount - m_nSoldCount;
    }
    else if (m_nType == 6 && 0 < m_nLimitCount)
    {
        nRemain = m_nLimitCount - m_nHomeSoldCount < 0 ? 0 : m_nLimitCount - m_nHomeSoldCount;
    }
    return nRemain;
}
MS2_REPLACE_METHOD(0x1406A0BD0, CMeratMarketPremiumProduct, GetRemainCount, 222, 0x373A971F);

// @0x1406a0cc0
bool CMeratMarketPremiumProduct::IsSoldOut()
{
    return IsBuyLimitReached() || IsLimitSoldOut() || IsHomeSoldOut();
}
MS2_REPLACE_METHOD(0x1406A0CC0, CMeratMarketPremiumProduct, IsSoldOut, 88, 0x5CDCCBAD);

// @0x1406a0d20
bool CMeratMarketPremiumProduct::IsNotSelling(__int64 nOffset)
{
    if (!IsSelling(nOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0D20, CMeratMarketPremiumProduct, IsNotSelling, 47, 0xC65BF660);

// @0x1406a0d60
bool CMeratMarketPremiumProduct::IsNotEventPeriod(__int64 nOffset)
{
    if (!IsEventPeriod(nOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0D60, CMeratMarketPremiumProduct, IsNotEventPeriod, 47, 0x3B0DCD4B);

// @0x1406a0da0
bool CMeratMarketPremiumProduct::IsSelling(__int64 nOffset)
{
    CMsTime zeroStart(0);
    if (m_startDate == zeroStart)
    {
        CMsTime zeroEnd(0);
        if (m_endDate == zeroEnd)
            return true;
    }
    CMsTime now(GetServerTime());
    CMsTime start(m_startDate.Get() - nOffset);
    return now >= start && now <= m_endDate;
}
MS2_REPLACE_METHOD(0x1406A0DA0, CMeratMarketPremiumProduct, IsSelling, 250, 0xACFDCFAD);

// @0x1406a0ea0
bool CMeratMarketPremiumProduct::IsEventPeriod(__int64 nOffset)
{
    CMsTime zeroStart(0);
    if (m_eventStart == zeroStart)
    {
        CMsTime zeroEnd(0);
        if (m_eventEnd == zeroEnd)
            return false;
    }
    CMsTime now(GetServerTime());
    CMsTime start(m_eventStart.Get() - nOffset);
    bool bInPeriod = now >= start && now <= m_eventEnd;
    if (!bInPeriod)
        return false;
    if (IsSelling(nOffset))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406A0EA0, CMeratMarketPremiumProduct, IsEventPeriod, 309, 0xFD9AF27F);

// @0x1406a0fe0
bool CMeratMarketPremiumProduct::FUN_1406a0fe0()
{
    return m_n9c == 0;
}
MS2_REPLACE_METHOD(0x1406A0FE0, CMeratMarketPremiumProduct, FUN_1406a0fe0, 48, 0xABBF3BA7);

// @0x1406a1020
void CMeratMarketPremiumProduct::Write(COutputStream& stream)
{
    CDBPremiumProduct::Write(stream);
    stream.vfunc_o10_3(m_nBuyCount);
    if (m_nType == 1)
    {
        WriteSubProducts(stream);
    }
    else if (m_nType == 3)
    {
        stream.vfunc_o10_3(m_nSoldCount);
        WriteLimitProducts(stream);
    }
    else if (m_nType == 6)
    {
        stream.vfunc_o10_3(m_nHomeSoldCount);
    }
}
MS2_REPLACE_METHOD(0x1406A1020, CMeratMarketPremiumProduct, Write, 182, 0x55B666E1);

// @0x1406a10e0
void CMeratMarketPremiumProduct::Read(CInPacket& packet)
{
    CDBPremiumProduct::Read(packet);
    m_nBuyCount = packet.vfunc_o8_3();
    if (m_nType == 1)
    {
        ReadSubProducts(packet);
    }
    else if (m_nType == 3)
    {
        m_nSoldCount = packet.vfunc_o8_3();
        ReadLimitProducts(packet);
    }
    else if (m_nType == 6)
    {
        m_nHomeSoldCount = packet.vfunc_o8_3();
    }
}
MS2_REPLACE_METHOD(0x1406A10E0, CMeratMarketPremiumProduct, Read, 239, 0xF64B2730);

// @0x1406a11e0
void CMeratMarketPremiumProduct::WriteBrief(COutputStream& stream)
{
    CDBPremiumProduct::WriteBrief(stream);
    if (m_nType == 1)
        WriteSubProducts(stream);
    else if (m_nType == 3)
        WriteLimitProducts(stream);
}
MS2_REPLACE_METHOD(0x1406A11E0, CMeratMarketPremiumProduct, WriteBrief, 88, 0x7630A694);

// @0x1406a1240
void CMeratMarketPremiumProduct::ReadBrief(CInPacket& packet)
{
    CDBPremiumProduct::ReadBrief(packet);
    if (m_nType == 1)
        ReadSubProducts(packet);
    else if (m_nType == 3)
        ReadLimitProducts(packet);
}
MS2_REPLACE_METHOD(0x1406A1240, CMeratMarketPremiumProduct, ReadBrief, 88, 0x2F2F442F);

// @0x1406a12a0
// MS2-FUNCTIONAL: the attribute read temporaries differ (exe 13 bytes shorter)
BOOL CMeratMarketPremiumProduct::LoadXml(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "sn", m_nId);
    FUN_140873220(pElem, "id", m_nItemId);
    FUN_1408731e0(pElem, "grade", m_nGrade);
    FUN_1408731e0(pElem, "saleTag", m_nSaleTag);
    CStringA strStart;
    FUN_1408733e0(pElem, "startDate", strStart);
    if (strStart.Trim().IsEmpty())
    {
        m_startDate = CMsTime(2010, 1, 1, 0, 0, 0);
    }
    else
    {
        CMsTime t;
        CStringA strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(t, strFormat, strStart))
            m_startDate = t;
    }
    CStringA strEnd;
    FUN_1408733e0(pElem, "endDate", strEnd);
    if (strEnd.Trim().IsEmpty())
    {
        m_endDate = CMsTime(2100, 1, 1, 0, 0, 0);
    }
    else
    {
        CMsTime t;
        CStringA strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(t, strFormat, strEnd))
            m_endDate = t;
    }
    FUN_1408731e0(pElem, "chartOrder", m_nChartOrder);
    bool bVisible = false;
    FUN_1408730a0(pElem, "visible", bVisible);
    m_bVisible = bVisible;
    int nBuyLimit = 0;
    FUN_1408731e0(pElem, "buyLimit", nBuyLimit);
    if (nBuyLimit < 0 || 2 < nBuyLimit)
        return FALSE;
    m_nBuyLimit = nBuyLimit;
    FUN_1408731e0(pElem, "buyLimitMax", m_nBuyLimitMax);
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406A12A0, CMeratMarketPremiumProduct, LoadXml, 892, 0x6BF24D93);

// @0x1406a1630
int CMeratMarketPremiumProduct::GetGrade()
{
    return m_nGrade;
}
MS2_REPLACE_METHOD(0x1406A1630, CMeratMarketPremiumProduct, GetGrade, 17, 0x84EDFDD7);

// @0x1406a1650
int CMeratMarketPremiumProduct::GetCurrency()
{
    return m_nCurrency;
}
MS2_REPLACE_METHOD(0x1406A1650, CMeratMarketPremiumProduct, GetCurrency, 14, 0x620CA41F);

// @0x1406a1670
int CMeratMarketPremiumProduct::GetDisplayId()
{
    int nId = 0;
    switch (m_nType)
    {
    case 1:
    case 3:
        nId = m_nId;
        break;
    case 2:
    case 4:
        nId = m_n2c;
        break;
    }
    return nId;
}
MS2_REPLACE_METHOD(0x1406A1670, CMeratMarketPremiumProduct, GetDisplayId, 89, 0xCDF1CA84);

// @0x1406a16d0
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetSubProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapSub.Lookup(nId, spProduct);
    return spProduct;
}
MS2_REPLACE_METHOD(0x1406A16D0, CMeratMarketPremiumProduct, GetSubProduct, 123, 0xF92751D5);

// @0x1406a1760
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetLimitProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapLimit.Lookup(nId, spProduct);
    return spProduct;
}
MS2_REPLACE_METHOD(0x1406A1760, CMeratMarketPremiumProduct, GetLimitProduct, 123, 0xEF481C73);

// @0x1406a17f0
int CMeratMarketPremiumProduct::GetB0(int nSubId)
{
    if (nSubId == 0)
        return m_nb0;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb0;
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A17F0, CMeratMarketPremiumProduct, GetB0, 136, 0x2060EF93);

// @0x1406a1880
int CMeratMarketPremiumProduct::GetB4(int nSubId)
{
    if (nSubId == 0)
        return m_nb4;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb4;
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1880, CMeratMarketPremiumProduct, GetB4, 136, 0x6B08FAA6);

// @0x1406a1910
int CMeratMarketPremiumProduct::GetB8(int nSubId)
{
    if (nSubId == 0)
        return m_nb8;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb8;
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1910, CMeratMarketPremiumProduct, GetB8, 136, 0x0DB071D5);

// @0x1406a19a0
CMsTime CMeratMarketPremiumProduct::GetStartDate(int nSubId)
{
    if (nSubId == 0)
        return CMsTime(m_startDate.Get());
    CMsTime t(0);
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            t = spSub->m_startDate.Get();
    }
    return t;
}
MS2_REPLACE_METHOD(0x1406A19A0, CMeratMarketPremiumProduct, GetStartDate, 202, 0x4A66A353);

// @0x1406a1a70
CMsTime CMeratMarketPremiumProduct::GetEndDate(int nSubId)
{
    if (nSubId == 0)
        return m_endDate;
    CMsTime t(0);
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            t = spSub->m_endDate;
    }
    return t;
}
MS2_REPLACE_METHOD(0x1406A1A70, CMeratMarketPremiumProduct, GetEndDate, 186, 0xDAA7A8CB);

// @0x1406a1b30
__int64 CMeratMarketPremiumProduct::GetSalePriceOf(int nSubId)
{
    if (nSubId == 0)
        return GetSalePrice(this);
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->GetSalePrice(this);
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1B30, CMeratMarketPremiumProduct, GetSalePriceOf, 169, 0xE287036E);

// @0x1406a1be0
__int64 CMeratMarketPremiumProduct::GetPriceOf(int nSubId)
{
    if (nSubId == 0)
        return m_nPrice;
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nPrice;
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1BE0, CMeratMarketPremiumProduct, GetPriceOf, 135, 0xEF940809);

// @0x1406a1c70
bool CMeratMarketPremiumProduct::FUN_1406a1c70(int nSubId)
{
    if (!FUN_1406a5840())
        return false;
    if (nSubId == 0)
    {
        if (m_n58 == 0)
            return false;
        if (m_nBuyLimit != 0)
            return false;
        if (m_nType != 1)
            return false;
        return true;
    }
    bool b = false;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            b = spSub->m_n58 == 1;
    }
    return b;
}
MS2_REPLACE_METHOD(0x1406A1C70, CMeratMarketPremiumProduct, FUN_1406a1c70, 221, 0x1442EE2B);

// @0x1406a1d60
BOOL CMeratMarketPremiumProduct::HasSubProducts()
{
    if (m_mapSub.IsEmpty())
        return FALSE;
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406A1D60, CMeratMarketPremiumProduct, HasSubProducts, 49, 0x7E7D6807);

// @0x1406a1da0
__int64 CMeratMarketPremiumProduct::GetPointOf(int nSubId)
{
    if (nSubId == 0)
        return GetPoint();
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->GetPoint();
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1DA0, CMeratMarketPremiumProduct, GetPointOf, 159, 0x7BB0F0B3);

// @0x1406a1e50
// MS2-FUNCTIONAL: a stack slot differs
CStringA CMeratMarketPremiumProduct::GetCategory()
{
    if (!IsEventPeriod(0))
        return m_strCategory;
    return m_strEventCategory;
}
MS2_REPLACE_METHOD(0x1406A1E50, CMeratMarketPremiumProduct, GetCategory, 130, 0x2EE05A1E);

// @0x1406a1ee0
int CMeratMarketPremiumProduct::FUN_1406a1ee0()
{
    return m_n158;
}
MS2_REPLACE_METHOD(0x1406A1EE0, CMeratMarketPremiumProduct, FUN_1406a1ee0, 17, 0xF95067D2);

// @0x1406a1f00
CStringA CMeratMarketPremiumProduct::FUN_1406a1f00()
{
    return m_str160;
}
MS2_REPLACE_METHOD(0x1406A1F00, CMeratMarketPremiumProduct, FUN_1406a1f00, 68, 0x4B23F95C);

// @0x1406a1f50
bool CMeratMarketPremiumProduct::FUN_1406a1f50()
{
    return m_b168;
}
MS2_REPLACE_METHOD(0x1406A1F50, CMeratMarketPremiumProduct, FUN_1406a1f50, 18, 0x7970D0EC);

// @0x1406a1f70
void CMeratMarketPremiumProduct::WriteSubProducts(COutputStream& stream)
{
    int nCount = (int)m_mapSub.GetCount();
    stream.vfunc_o10_1((unsigned char)nCount);
    for (POSITION pos = m_mapSub.GetHeadPosition(); pos; m_mapSub.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = m_mapSub.GetValueAt(pos);
        if (spSub == 0)
        {
            stream.vfunc_o10_1(0);
        }
        else
        {
            stream.vfunc_o10_1(1);
            spSub->Write(stream);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A1F70, CMeratMarketPremiumProduct, WriteSubProducts, 281, 0xF5F0BA0A);

// @0x1406a2090
void CMeratMarketPremiumProduct::ReadSubProducts(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nExists = packet.vfunc_o8_1();
        if (nExists == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapSub.SetAt(spSub->m_nId, spSub);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A2090, CMeratMarketPremiumProduct, ReadSubProducts, 341, 0x414652F1);

// @0x1406a21f0
void CMeratMarketPremiumProduct::WriteLimitProducts(COutputStream& stream)
{
    int nCount = (int)m_mapLimit.GetCount();
    stream.vfunc_o10_1((unsigned char)nCount);
    for (POSITION pos = m_mapLimit.GetHeadPosition(); pos; m_mapLimit.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = m_mapLimit.GetValueAt(pos);
        if (spSub == 0)
        {
            stream.vfunc_o10_1(0);
        }
        else
        {
            stream.vfunc_o10_1(1);
            spSub->Write(stream);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A21F0, CMeratMarketPremiumProduct, WriteLimitProducts, 281, 0x6CBC751C);

// @0x1406a2310
void CMeratMarketPremiumProduct::ReadLimitProducts(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nExists = packet.vfunc_o8_1();
        if (nExists == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapLimit.SetAt(spSub->m_nId, spSub);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A2310, CMeratMarketPremiumProduct, ReadLimitProducts, 341, 0x96DD3F11);

// @0x1406a2470
// MS2-FUNCTIONAL: the StringFormat argument temporaries differ
CStringA FUN_1406a2470(__int64 nTime)
{
    CMsTime t(nTime);
    int nSecond = t.GetSecond();
    int nMinute = t.GetMinute();
    int nHour = t.GetHour();
    int nDay = t.GetDay();
    int nMonth = t.GetMonth();
    int nYear = t.GetYear();
    return StringFormat("{0:04d}-{1:02d}-{2:02d} {3:02d}:{4:02d}:{5:02d}", nYear, nMonth, nDay, nHour, nMinute, nSecond);
}
MS2_REPLACE(0x1406A2470, FUN_1406a2470, 261, 0x9D2D65E2);

// ---- CMeratMarketPremium -------------------------------------------------------------------------------------------

// @0x1406a2580
CMeratMarketPremium::CMeratMarketPremium()
{
}

// @0x1406a26b0
CMeratMarketPremium::~CMeratMarketPremium()
{
}

// @0x1406a2750
void CMeratMarketPremium::Clear()
{
    m_products.RemoveAll();
    m_productMap.RemoveAll();
    m_categoryMap.RemoveAll();
    m_ugcMap.RemoveAll();
}
MS2_REPLACE_METHOD(0x1406A2750, CMeratMarketPremium, Clear, 86, 0x79A303C8);

// @0x1406a27b0
int CMeratMarketPremium::Init()
{
    m_nShopType = 100000;
    Clear();
    LoadCategories();
    CStringA strServerPath = FUN_14071a5b0("Table/Server", "shop_merat.xml");
    FUN_1401d1160(strServerPath);
    CStringA strPath = FUN_14071a5b0("Table", "shop_merat.xml");
    return 1;
}
MS2_REPLACE_METHOD(0x1406A27B0, CMeratMarketPremium, Init, 325, 0x52A35A3A);

// @0x1406a2900
int CMeratMarketPremium::LoadXml(const CStringA& strPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("item"); pElem; pElem = pElem->FUN_140168650("item"))
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(new CMeratMarketPremiumProduct);
        if (spProduct.get())
        {
            spProduct->LoadXml(pElem);
            CStringA strCategory;
            FUN_1408733e0(pElem, "category", strCategory);
            unsigned nItemId = spProduct->m_nItemId;
            {
                MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
                if (spItem.get())
                {
                    if (strCategory.IsEmpty())
                        strCategory = spItem->property.category;
                }
                else
                {
                    FUN_140166440()->Log(0, 0, 0x2d, L"CMeratMarket::Read - error item id ({0})", nItemId);
                    continue;
                }
            }
            spProduct->m_nCategoryId = GetCategoryId(strCategory);
            m_products.Add(spProduct);
            m_productMap.SetAt(spProduct->m_nId, spProduct);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1406A2900, CMeratMarketPremium, LoadXml, 841, 0x490FF2B8);

// @0x1406a2c50
int CMeratMarketPremium::LoadUgcXml(const CStringA& strPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("item"); pElem; pElem = pElem->FUN_140168650("item"))
    {
        MS2Ptr<CUgcPremiumProduct> spProduct(new CUgcPremiumProduct);
        if (spProduct.get())
        {
            FUN_140873220(pElem, "id", spProduct->m_nId);
            FUN_1408731e0(pElem, "sn", spProduct->m_nSn);
            FUN_140873220(pElem, "price", spProduct->m_nPrice);
            unsigned nId = spProduct->m_nId;
            if (spProduct->m_nPrice > 0)
                m_ugcMap.SetAt(nId, spProduct);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1406A2C50, CMeratMarketPremium, LoadUgcXml, 568, 0x285D3BB5);

// @0x1406a2e90
int CMeratMarketPremium::LoadCategories()
{
    if (CShopCategoryTable::GetInstance() == NULL)
        CShopCategoryTable::CreateInstance();
    int nShopType = m_nShopType;
    CShopCategoryTable::TabListPtr spTabs = CShopCategoryTable::GetInstance()->GetTabs(nShopType);
    if (static_cast<bool>(spTabs.get()) && !spTabs->IsEmpty())
    {
        for (POSITION pos = spTabs->GetHeadPosition(); pos; spTabs->GetNext(pos))
        {
            MS2Ptr<CShopCategoryTable::TabInfo> spTab(spTabs->GetAt(pos));
            if (spTab.get())
            {
                if (!spTab->m_subTabs.IsEmpty())
                {
                    CShopCategoryTable::TabList* pSubTabs = &spTab->m_subTabs;
                    for (POSITION subPos = pSubTabs->GetHeadPosition(); subPos; pSubTabs->GetNext(subPos))
                    {
                        MS2Ptr<CShopCategoryTable::TabInfo> spSubTab(pSubTabs->GetAt(subPos));
                        if (spSubTab.get())
                            AddCategory(spSubTab);
                    }
                }
                else
                {
                    AddCategory(spTab);
                }
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1406A2E90, CMeratMarketPremium, LoadCategories, 607, 0x13C3A945);

// @0x1406a3100
void CMeratMarketPremium::AddCategory(MS2Ptr<CShopCategoryTable::TabInfo> tab)
{
    CAtlArray<CStringA> names;
    FUN_14015f050(tab->m_strCategory, names, ",");
    for (unsigned i = 0; i < names.GetCount(); i++)
    {
        CStringA strName(names[i]);
        if (m_categoryMap.Lookup(strName) == NULL)
            m_categoryMap.SetAt(strName, tab->m_nId);
    }
}

// @0x1406a3240
int CMeratMarketPremium::GetCategoryId(CStringA strCategory)
{
    if (strCategory.IsEmpty())
        return 0;
    int nId = 0;
    m_categoryMap.Lookup(strCategory, nId);
    return nId;
}
MS2_REPLACE_METHOD(0x1406A3240, CMeratMarketPremium, GetCategoryId, 138, 0x17D7B8FE);

// @0x1406a32d0
MS2Ptr<CMeratMarketPremiumProduct> CMeratMarketPremium::FindProduct(int nId)
{
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
        m_productMap.Lookup(nId, spProduct);
        return spProduct;
    }
}
MS2_REPLACE_METHOD(0x1406A32D0, CMeratMarketPremium, FindProduct, 179, 0x8C57130B);

// @0x1406a3390
MS2Ptr<CUgcPremiumProduct> CMeratMarketPremium::FindUgcProduct(unsigned nId)
{
    if (Unk_LockGuard guard = s_lock) { __assume(0); } else
    {
        MS2Ptr<CUgcPremiumProduct> spProduct(0);
        m_ugcMap.Lookup(nId, spProduct);
        return spProduct;
    }
}
MS2_REPLACE_METHOD(0x1406A3390, CMeratMarketPremium, FindUgcProduct, 181, 0xDFF4960D);

// @0x1406a3450
int CMeratMarketPremium::GetShopType()
{
    return m_nShopType;
}
MS2_REPLACE_METHOD(0x1406A3450, CMeratMarketPremium, GetShopType, 14, 0x828204CF);

// @0x1406a3470
CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >* CMeratMarketPremium::GetProductMap()
{
    return &m_productMap;
}
MS2_REPLACE_METHOD(0x1406A3470, CMeratMarketPremium, GetProductMap, 15, 0x27BBF311);

// @0x1406a3490
CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> >* CMeratMarketPremium::GetProducts()
{
    return &m_products;
}
MS2_REPLACE_METHOD(0x1406A3490, CMeratMarketPremium, GetProducts, 15, 0x676E38F1);

// ---- CMeratMarketSchCond -------------------------------------------------------------------------------------------

// @0x1406a34b0
CMeratMarketSchCond::CMeratMarketSchCond()
{
    Clear();
}

// @0x1406a3510
CMeratMarketSchCond::CMeratMarketSchCond(CInPacket& packet)
{
    Read(packet);
}

// @0x1406a3580
CMeratMarketSchCond::~CMeratMarketSchCond()
{
    Clear();
}

// @0x1406a35e0
void CMeratMarketSchCond::Clear()
{
    m_18 = 0;
    m_1c = 3;
    m_20 = 0;
    m_24 = 0;
    m_str = "";
    m_30 = 1;
    m_34 = 1;
    m_3c = 0;
    m_38 = 0;
    m_40 = 0x12;
    m_44 = 0;
    m_48 = 0;
}
MS2_REPLACE_METHOD(0x1406A35E0, CMeratMarketSchCond, Clear, 171, 0xC93C3525);

// @0x1406a36a0
void CMeratMarketSchCond::Set(const CStringW& str)
{
    Clear();
    m_str = str;
    m_18 = 1;
    m_1c = 3;
    m_20 = 0xfff;
    m_30 = 1;
    m_34 = 1;
}
MS2_REPLACE_METHOD(0x1406A36A0, CMeratMarketSchCond, Set, 112, 0xF19ECEA1);

// @0x1406a3720
void CMeratMarketSchCond::FUN_1406a3720(const CMeratMarketSchCond* pOther)
{
    Clear();
    if (!pOther)
        return;
    *this = *pOther;
}
MS2_REPLACE_METHOD(0x1406A3720, CMeratMarketSchCond, FUN_1406a3720, 54, 0x2C2EE794);

// @0x1406a3760
void CMeratMarketSchCond::Write(COutputStream* pStream)
{
    pStream->vfunc_o10_3(m_18);
    pStream->vfunc_o10_1((unsigned char)m_1c);
    pStream->vfunc_o10_3(m_20);
    pStream->vfunc_o10_1((unsigned char)m_24);
    pStream->vfunc_o10_8(m_str);
    pStream->vfunc_o10_3(m_30);
    pStream->vfunc_o10_3(m_34);
    pStream->vfunc_o10_1((unsigned char)m_38);
    pStream->vfunc_o10_1((unsigned char)m_3c);
    pStream->vfunc_o10_1((unsigned char)m_40);
}
MS2_REPLACE_METHOD(0x1406A3760, CMeratMarketSchCond, Write, 278, 0xE90DE073);

// @0x1406a3880
void CMeratMarketSchCond::Read(CInPacket& packet)
{
    Clear();
    m_18 = packet.vfunc_o8_3();
    m_1c = packet.vfunc_o8_1();
    m_20 = packet.vfunc_o8_3();
    m_24 = packet.vfunc_o8_1();
    m_str = packet.vfunc_o8_8();
    m_30 = packet.vfunc_o8_3();
    m_34 = packet.vfunc_o8_3();
    m_38 = packet.vfunc_o8_1();
    m_3c = packet.vfunc_o8_1();
    m_40 = packet.vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1406A3880, CMeratMarketSchCond, Read, 628, 0x5DFF5C54);

// @0x1406a3b00
void CMeratMarketSchCond::WriteBrief(COutputStream* pStream)
{
    pStream->vfunc_o10_3(m_18);
    pStream->vfunc_o10_1((unsigned char)m_1c);
    pStream->vfunc_o10_3(m_20);
    pStream->vfunc_o10_1((unsigned char)m_24);
    pStream->vfunc_o10_8(m_str);
    pStream->vfunc_o10_3(m_30);
    pStream->vfunc_o10_3(m_34);
    pStream->vfunc_o10_1((unsigned char)m_38);
    pStream->vfunc_o10_1((unsigned char)m_40);
}
MS2_REPLACE_METHOD(0x1406A3B00, CMeratMarketSchCond, WriteBrief, 253, 0xB09B7120);

// @0x1406a3c10
void CMeratMarketSchCond::ReadBrief(CInputStream* pStream)
{
    Clear();
    m_18 = pStream->vfunc_o8_3();
    m_1c = pStream->vfunc_o8_1();
    m_20 = pStream->vfunc_o8_3();
    m_24 = pStream->vfunc_o8_1();
    m_str = pStream->vfunc_o8_8();
    m_30 = pStream->vfunc_o8_3();
    m_34 = pStream->vfunc_o8_3();
    m_38 = pStream->vfunc_o8_1();
    m_40 = pStream->vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1406A3C10, CMeratMarketSchCond, ReadBrief, 313, 0x30427471);

// @0x1406a3d50
bool CMeratMarketSchCond::FUN_1406a3d50()
{
    return FUN_1406a5010(m_18);
}
MS2_REPLACE_METHOD(0x1406A3D50, CMeratMarketSchCond, FUN_1406a3d50, 27, 0x55302461);

// @0x1406a3d80
bool CMeratMarketSchCond::FUN_1406a3d80()
{
    return FUN_1406a4fe0(m_18);
}
MS2_REPLACE_METHOD(0x1406A3D80, CMeratMarketSchCond, FUN_1406a3d80, 27, 0x13D3DEC1);

// @0x1406a3db0
int CMeratMarketSchCond::GetPageGroup()
{
    if (m_30 == 0)
        return -1;
    int nIndex = m_30 - 1;
    int nGroup = nIndex / 5;
    return nGroup;
}
MS2_REPLACE_METHOD(0x1406A3DB0, CMeratMarketSchCond, GetPageGroup, 64, 0x4B7A4534);

// @0x1406a3e00
int CMeratMarketSchCond::GetPageGroupFirst()
{
    int nGroup = GetPageGroup();
    if (nGroup == -1)
        return 0;
    int nGroupSize = m_40 * 5;
    int nFirst = nGroup * nGroupSize + 1;
    return nFirst;
}
MS2_REPLACE_METHOD(0x1406A3E00, CMeratMarketSchCond, GetPageGroupFirst, 71, 0x18CC09A0);

// @0x1406a3e50
int CMeratMarketSchCond::GetPageGroupLast()
{
    int nGroup = GetPageGroup();
    if (nGroup == -1)
        return 0;
    int nGroupSize = m_40 * 5;
    int nLast = (nGroup + 1) * nGroupSize;
    return nLast;
}
MS2_REPLACE_METHOD(0x1406A3E50, CMeratMarketSchCond, GetPageGroupLast, 71, 0x9CBF5E2A);

// @0x1406a3ea0
int CMeratMarketSchCond::FUN_1406a3ea0()
{
    if (m_30 == 0)
        return -1;
    int nIndex = m_30 - 1;
    int nBlock = nIndex / 15;
    int nBlockSize = m_40 * 15;
    int nCount = (nBlock + 1) * nBlockSize;
    return nCount;
}
MS2_REPLACE_METHOD(0x1406A3EA0, CMeratMarketSchCond, FUN_1406a3ea0, 92, 0x6BC4FC5B);

// @0x1406a3f10
int CMeratMarketSchCond::GetPageSize()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x1406A3F10, CMeratMarketSchCond, GetPageSize, 14, 0x620CA41F);

// @0x1406a3f30
int CMeratMarketSchCond::GetMaxPageSize()
{
    return 0x12;
}
MS2_REPLACE_METHOD(0x1406A3F30, CMeratMarketSchCond, GetMaxPageSize, 11, 0xCC810D29);

// @0x1406a3f50
CStringA CMeratMarketSchCond::GetSortName()
{
    if (m_24 < 0 || m_24 >= 7)
        return "";
    CStringA strName = g_premiumSortNames[m_24];
    return strName;
}
MS2_REPLACE_METHOD(0x1406A3F50, CMeratMarketSchCond, GetSortName, 172, 0x3F6D17D6);

// @0x1406a4010
int CMeratMarketSchCond::GetType()
{
    return m_18;
}
MS2_REPLACE_METHOD(0x1406A4010, CMeratMarketSchCond, GetType, 14, 0x72E52537);

// @0x1406a4030
int CMeratMarketSchCond::FUN_1406a4030()
{
    int nId = 0;
    if (m_18 % 100 == 0)
        nId = m_18 + 99;
    else
        nId = m_18;
    return nId;
}
MS2_REPLACE_METHOD(0x1406A4030, CMeratMarketSchCond, FUN_1406a4030, 73, 0xD1C235E0);

// @0x1406a4080
int CMeratMarketSchCond::IsSameQuery(const CMeratMarketSchCond* pOther)
{
    if (pOther == NULL)
        return 0;
    if (!IsSameSearch(pOther))
        return 0;
    if (const_cast<CMeratMarketSchCond*>(pOther)->FUN_1406a3ea0() > FUN_1406a3ea0())
        return 0;
    if (pOther->m_34 != m_34)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406A4080, CMeratMarketSchCond, IsSameQuery, 117, 0x57F536DB);

// @0x1406a4100
int CMeratMarketSchCond::IsSameSearch(const CMeratMarketSchCond* pOther)
{
    if (pOther == NULL)
        return 0;
    if (pOther->m_18 != m_18)
        return 0;
    if (pOther->m_1c != m_1c)
        return 0;
    if (pOther->m_20 != m_20)
        return 0;
    if (pOther->m_24 != m_24)
        return 0;
    if (pOther->m_str != m_str)
        return 0;
    if (pOther->m_38 != m_38)
        return 0;
    if (pOther->m_40 != m_40)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406A4100, CMeratMarketSchCond, IsSameSearch, 214, 0x95CB4598);

// @0x1406a41e0
bool CMeratMarketSchCond::IsValidPageSize()
{
    if (m_40 < 1 || m_40 > GetMaxPageSize())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406A41E0, CMeratMarketSchCond, IsValidPageSize, 51, 0x107DCEFD);

// ---- CMeratMarketProduct -------------------------------------------------------------------------------------------

// @0x1406a4220
CMeratMarketProduct::CMeratMarketProduct(CInPacket& packet)
{
    Read(packet);
}

// @0x1406a42b0
CMeratMarketProduct::~CMeratMarketProduct()
{
}

// @0x1406a4310
void CMeratMarketProduct::UpdateKey()
{
    if (m_nKind == 0)
        m_key.Set(m_premium.m_nId, 0);
    else
        m_key.Set(0, m_ugc.m_n20);
}
MS2_REPLACE_METHOD(0x1406A4310, CMeratMarketProduct, UpdateKey, 86, 0x7C13D87C);

// @0x1406a4370
BOOL CMeratMarketProduct::HasLimit()
{
    if (m_nKind == 1)
        return FALSE;
    return m_premium.HasLimit();
}
MS2_REPLACE_METHOD(0x1406A4370, CMeratMarketProduct, HasLimit, 46, 0x100EE29E);

// @0x1406a43b0
void CMeratMarketProduct::Write(COutputStream& stream)
{
    stream.vfunc_o10_1((unsigned char)m_nKind);
    m_key.Write(stream);
    if (m_nKind == 0)
        (&m_premium)->Write(stream);
    else
        m_ugc.Write(stream);
}
MS2_REPLACE_METHOD(0x1406A43B0, CMeratMarketProduct, Write, 142, 0x240DFE2C);

// @0x1406a4450
void CMeratMarketProduct::Read(CInPacket& packet)
{
    m_nKind = packet.vfunc_o8_1();
    m_key.Read(packet);
    if (m_nKind == 0)
        (&m_premium)->Read(packet);
    else
        m_ugc.Read(packet);
}
MS2_REPLACE_METHOD(0x1406A4450, CMeratMarketProduct, Read, 162, 0x42CA035C);

// @0x1406a4500
__int64 CMeratMarketProduct::GetSalePrice()
{
    __int64 nPrice = 0;
    if (m_nKind == 0)
        nPrice = m_premium.GetSalePriceOf(0);
    else
        nPrice = m_ugc.m_n50;
    return nPrice;
}
MS2_REPLACE_METHOD(0x1406A4500, CMeratMarketProduct, GetSalePrice, 82, 0x959BDF18);

// @0x1406a4560
__int64 CMeratMarketProduct::GetStartTime()
{
    __int64 nTime = 0;
    if (m_nKind == 0)
        nTime = m_premium.m_startDate.Get();
    else
        nTime = m_ugc.m_n78;
    return nTime;
}
MS2_REPLACE_METHOD(0x1406A4560, CMeratMarketProduct, GetStartTime, 82, 0x3BF4BDA9);

// @0x1406a45c0
int CMeratMarketProduct::GetChartOrder()
{
    int nOrder = 0;
    if (m_nKind == 0)
        nOrder = m_premium.m_nChartOrder;
    return nOrder;
}
MS2_REPLACE_METHOD(0x1406A45C0, CMeratMarketProduct, GetChartOrder, 46, 0x745B9C6E);

// @0x1406a4600
int CMeratMarketProduct::GetCategoryId()
{
    if (IsUgc())
        return m_ugc.m_n30;
    return m_premium.m_nCategoryId;
}
MS2_REPLACE_METHOD(0x1406A4600, CMeratMarketProduct, GetCategoryId, 52, 0x3015BABE);

// @0x1406a4640
int CMeratMarketProduct::GetItemId()
{
    int nItemId = 0;
    if (IsPremium())
        nItemId = m_premium.m_nItemId;
    else if (IsUgc())
        nItemId = m_ugc.m_n2c;
    return nItemId;
}
MS2_REPLACE_METHOD(0x1406A4640, CMeratMarketProduct, GetItemId, 86, 0xDE5C2764);

// @0x1406a46a0
int CMeratMarketProduct::GetCurrency()
{
    if (IsPremium())
        return m_premium.GetCurrency();
    return 1;
}
MS2_REPLACE_METHOD(0x1406A46A0, CMeratMarketProduct, GetCurrency, 52, 0x087080CA);

// @0x1406a46e0
int CMeratMarketProduct::GetType()
{
    if (IsPremium())
        return m_premium.m_nType;
    return 0;
}
MS2_REPLACE_METHOD(0x1406A46E0, CMeratMarketProduct, GetType, 40, 0x08C2D062);

// @0x1406a4710
__int64 CMeratMarketProduct::GetPoint()
{
    __int64 nPoint = 0;
    if (m_nKind == 0)
        nPoint = (&m_premium)->GetPoint();
    return nPoint;
}
MS2_REPLACE_METHOD(0x1406A4710, CMeratMarketProduct, GetPoint, 78, 0x1E5FACA7);

// @0x1406a4770
CStringW CMeratMarketProduct::GetName()
{
    if (IsPremium())
        return m_premium.GetName();
    int nItemId = GetItemId();
    CStringW strName = GetStringTable()->FUN_141811980(1, nItemId);
    if (IsUgc())
    {
        if (m_ugc.FUN_140896310())
            return m_ugc.m_music.m_str30;
        return FUN_141277a90(&m_ugc.m_look, strName);
    }
    return FUN_141425950(nItemId);
}
MS2_REPLACE_METHOD(0x1406A4770, CMeratMarketProduct, GetName, 331, 0x34470B07);

// @0x1406a48d0
int CMeratMarketProduct::GetPayCurrency()
{
    int nCurrency = GetCurrency();
    if (nCurrency == 3)
        return 1;
    return nCurrency;
}
MS2_REPLACE_METHOD(0x1406A48D0, CMeratMarketProduct, GetPayCurrency, 46, 0x4A4B9288);

// @0x1406a4910
__int64 CMeratMarketProduct::GetUgcId()
{
    if (m_nKind != 1)
        return 0;
    return m_ugc.m_n20;
}
MS2_REPLACE_METHOD(0x1406A4910, CMeratMarketProduct, GetUgcId, 33, 0x73020D06);

// ---- free helpers --------------------------------------------------------------------------------------------------

// @0x1406a4940
CStringA FUN_1406a4940()
{
    return g_strMeratHomeLayout;
}
MS2_REPLACE(0x1406A4940, FUN_1406a4940, 56, 0x743527AB);

// @0x1406a4980
CStringA FUN_1406a4980()
{
    return g_strPremiumHomeLayout;
}
MS2_REPLACE(0x1406A4980, FUN_1406a4980, 56, 0x5A1CB0F3);

// @0x1406a49c0
CStringA FUN_1406a49c0()
{
    return g_strDesignersHomeLayout;
}
MS2_REPLACE(0x1406A49C0, FUN_1406a49c0, 56, 0x9979CA64);

// @0x1406a4a00
CStringA FUN_1406a4a00()
{
    return FUN_14071a5b0("Table/Server", g_strMeratHomeLayout);
}
MS2_REPLACE(0x1406A4A00, FUN_1406a4a00, 99, 0xC1F7BB05);

// @0x1406a4a70
CStringA FUN_1406a4a70()
{
    return FUN_14071a5b0("Table/Server", g_strPremiumHomeLayout);
}
MS2_REPLACE(0x1406A4A70, FUN_1406a4a70, 99, 0xFD277E46);

// @0x1406a4ae0
CStringA FUN_1406a4ae0()
{
    return FUN_14071a5b0("Table/Server", g_strDesignersHomeLayout);
}
MS2_REPLACE(0x1406A4AE0, FUN_1406a4ae0, 99, 0x1C0A91EE);

// The product ids of a home layout file: <ms2><item sn="..."/>...</ms2>.
// @0x1406a4b50
int FUN_1406a4b50(TiXmlDocument* pDoc, CAtlList<int>* pList)
{
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(pDoc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != NULL; pItem = pItem->FUN_140168650("item"))
    {
        CStringA strSn;
        FUN_1408733e0(pItem, "sn", strSn);
        pList->AddTail(FUN_140718170(strSn));
    }
    return 1;
}
MS2_REPLACE(0x1406A4B50, FUN_1406a4b50, 194, 0xA9FC5A5F);

// Writes a layout document as the upsert of a dbo.tb_game_variable row.
// MS2-FUNCTIONAL: the CString / printer temporaries are laid out differently (1 byte longer)
// @0x1406a4c20
int FUN_1406a4c20(TiXmlDocument* pDoc, const CStringA& strName, const CStringA& strDesc, ATL::CAtlFile* pFile)
{
    CStringA strFormat("IF EXISTS (SELECT * FROM dbo.tb_game_variable WHERE s_name = '{0}')\nBEGIN\nUPDATE dbo.tb_game_variable\nSET s_group = {1}, s_name = '{2}', s_value = '{3}', s_desc = '{4}', s_use = {5}\nWHERE s_name = '{6}'\nEND\nELSE\nBEGIN\nINSERT INTO dbo.tb_game_variable(s_group, s_name, s_value, s_desc, s_use) VALUES({7}, '{8}', '{9}', '{10}', {11});\nEND\n\n\n");
    TiXmlPrinter printer;
    pDoc->Accept(&printer);
    int nGroup = 1;
    CStringA strValue(printer.CStr());
    int nUse = 1;
    CStringA strQuery = StringFormat((const char*)strFormat, strName, nGroup, strName, strValue, strDesc, nUse,
                                     strName, nGroup, strName, strValue, strDesc, nUse);
    FUN_140299dc0(pFile, (const char*)strQuery, strQuery.GetLength(), 0);
    return 1;
}
MS2_REPLACE(0x1406A4C20, FUN_1406a4c20, 455, 0x916239EE);

// MS2-FUNCTIONAL: the document pointer temporaries are not recovered
// @0x1406a4df0
void Unk_MeratHomeLayout::Load()
{
    CStringA strPath = FUN_1406a4a00();
    GetFileSystem()->FUN_1403974b0(&m_meratDoc, strPath, 0, true, false);
    FUN_1406a4b50(&m_meratDoc, &m_meratItems);
    strPath = FUN_1406a4a70();
    GetFileSystem()->FUN_1403974b0(&m_premiumDoc, strPath, 0, true, false);
    FUN_1406a4b50(&m_premiumDoc, &m_premiumItems);
    strPath = FUN_1406a4ae0();
    GetFileSystem()->FUN_1403974b0(&m_designersDoc, strPath, 0, true, false);
}
MS2_REPLACE_METHOD(0x1406A4DF0, Unk_MeratHomeLayout, Load, 447, 0xAA9F2445);

// The list loader of a layout without a product list (the parameters are unused).
// @0x1406a4fc0
int FUN_1406a4fc0(TiXmlDocument* pDoc, CAtlList<int>* pList)
{
    return 0;
}
MS2_REPLACE(0x1406A4FC0, FUN_1406a4fc0, 13, 0x370AB719);

// @0x1406a4fe0
bool FUN_1406a4fe0(int nId)
{
    if (nId >= 100 && nId <= 10000)
        return true;
    return false;
}
MS2_REPLACE(0x1406A4FE0, FUN_1406a4fe0, 28, 0xD244AD6D);

// @0x1406a5010
bool FUN_1406a5010(int nId)
{
    if (nId >= 40000 && nId <= 50000)
        return true;
    return false;
}
MS2_REPLACE(0x1406A5010, FUN_1406a5010, 31, 0x1922E959);

// @0x1406a5040
bool FUN_1406a5040(int nId)
{
    if (nId >= 10 && nId <= 12)
        return true;
    return false;
}
MS2_REPLACE(0x1406A5040, FUN_1406a5040, 25, 0x91706C4D);

// @0x1406a5060
bool FUN_1406a5060(int nId)
{
    if (FUN_1406a5040(nId) || FUN_1406a4fe0(nId) || FUN_1406a5010(nId))
        return true;
    return false;
}
MS2_REPLACE(0x1406A5060, FUN_1406a5060, 67, 0x0E89B702);

// The UGC products of a product list that are on sale (the 4xx kinds are not counted).
// @0x1406a50b0
int FUN_1406a50b0(Unk_MeratProductMap& map)
{
    if (map.IsEmpty())
        return 0;
    int nCount = 0;
    for (POSITION pos = map.GetHeadPosition(); pos != NULL; map.GetNext(pos))
    {
        MS2Ptr<CMeratMarketProduct> spProduct = map.GetValueAt(pos);
        if (spProduct == NULL || !spProduct->IsUgc())
            continue;
        if (spProduct->m_ugc.FUN_140896310())
            continue;
        if (FUN_140166410()->FUN_14036e510())
        {
            if (spProduct->m_ugc.m_n28 == 2 || spProduct->m_ugc.m_n28 == 1)
                ++nCount;
        }
        else
        {
            if (spProduct->m_ugc.m_n28 == 2)
                ++nCount;
        }
    }
    return nCount;
}
MS2_REPLACE(0x1406A50B0, FUN_1406a50b0, 342, 0xAA1BDA17);

// @0x1406a5210
__int64 FUN_1406a5210()
{
    return *FUN_1401d3200()->UGCShopAdFeeMerat.Get();
}
MS2_REPLACE(0x1406A5210, FUN_1406a5210, 31, 0x68635521);

// The UGC sell fee of an item on this server.
// MS2-FUNCTIONAL: the CString temporary / result locals are laid out differently
// @0x1406a5240
__int64 FUN_1406a5240(int nItemId)
{
    CString strServer = FUN_140166410()->FUN_14036d8e0();
    __int64 nFee = FUN_1401c0db0()->FUN_140674bb0(nItemId, strServer);
    return nFee;
}
MS2_REPLACE(0x1406A5240, FUN_1406a5240, 104, 0x2A6490A4);

// @0x1406a52b0
__int64 FUN_1406a52b0(int nItemId, bool bAd)
{
    __int64 nFee = FUN_1406a5240(nItemId);
    if (bAd)
        nFee += FUN_1406a5210();
    return nFee;
}
MS2_REPLACE(0x1406A52B0, FUN_1406a52b0, 66, 0x92C790EB);

// The UGC sell minimum price of a design.
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (the price local is not recovered)
// @0x1406a5300
__int64 FUN_1406a5300(unsigned nItemId)
{
    __int64 nPrice = FUN_1406a6d50(FUN_1401d3200()->UGCShopSellMinPrice);
    CUGCDesignDataPtr spData = reinterpret_cast<Unk_MeratDesignTable*>(CUGCDesignTable::GetInstance())->FUN_14089e9f0(nItemId);
    if (spData.get() != 0)
    {
        if (spData->m_nMarketMinPrice > 0)
            nPrice = spData->m_nMarketMinPrice;
    }
    return nPrice;
}
MS2_REPLACE(0x1406A5300, FUN_1406a5300, 136, 0x694D4729);

// The UGC grade of an item.
// MS2-FUNCTIONAL: the return-path branch layout differs (exe 2 bytes longer)
// @0x1406a5390
int FUN_1406a5390(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.get() != 0)
    {
        if (spItem->FUN_14053cd10())
            return 2;
        CUGCDesignDataPtr spData = reinterpret_cast<Unk_MeratDesignTable*>(CUGCDesignTable::GetInstance())->FUN_14089e9f0(nItemId);
        if (spData.get() != 0)
            return spData->m_nItemGrade;
    }
    return 1;
}
MS2_REPLACE(0x1406A5390, FUN_1406a5390, 220, 0x81D4D25E);

// The UGC sell price range of an item.
// MS2-FUNCTIONAL: the price clamp temporaries and branch layout differ
// @0x1406a5480
void FUN_1406a5480(MS2Ptr<CItemData> spItem, __int64* pMin, __int64* pMax)
{
    if (spItem == NULL)
        return;
    int nId = spItem->FUN_14053c510();
    __int64 nMin = FUN_1406a6d50(FUN_1401d3200()->UGCShopSellMinPrice);
    __int64 nMax = FUN_1406a6d50(FUN_1401d3200()->UGCShopSellMaxPrice);
    if (spItem->FUN_14053d6f0() || spItem->FUN_14053d900())
    {
        CUGCDesignDataPtr spData = reinterpret_cast<Unk_MeratDesignTable*>(CUGCDesignTable::GetInstance())->FUN_14089e9f0(nId);
        if (spData.get() != 0)
        {
            if (spData->m_nMarketMinPrice > 0)
                nMin = spData->m_nMarketMinPrice;
            if (spData->m_nMarketMaxPrice > 0)
                nMax = spData->m_nMarketMaxPrice;
        }
    }
    else if (spItem->FUN_14053cd10())
    {
        const CString& strServer = FUN_140166410()->FUN_14036d8e0();
        __int64 nServerMin = 0;
        __int64 nServerMax = 0;
        FUN_1401c0db0()->FUN_140674d70(strServer, &nServerMin, &nServerMax);
        if (nServerMin > 0)
            nMin = nServerMin;
        if (nServerMax > 0)
            nMax = nServerMax;
    }
    *pMin = nMin < 0 ? 0 : nMin;
    *pMax = nMax < *pMin ? *pMin : nMax;
}
MS2_REPLACE(0x1406A5480, FUN_1406a5480, 604, 0x8AF4D4F1);

// @0x1406a56f0
bool FUN_1406a56f0()
{
    return FUN_140166410()->FUN_14036d570(0x49);
}
MS2_REPLACE(0x1406A56F0, FUN_1406a56f0, 27, 0xD7E69A76);

// @0x1406a5720
bool FUN_1406a5720()
{
    return FUN_140166410()->FUN_14036d650();
}
MS2_REPLACE(0x1406A5720, FUN_1406a5720, 22, 0xCF0C1D8A);

// @0x1406a5740
bool FUN_1406a5740()
{
    return FUN_140166410()->FUN_14036d690(0x44);
}
MS2_REPLACE(0x1406A5740, FUN_1406a5740, 27, 0xEECC0297);

// @0x1406a5770
bool FUN_1406a5770()
{
    return FUN_140166410()->FUN_14036d570(0x45);
}
MS2_REPLACE(0x1406A5770, FUN_1406a5770, 27, 0x1C72616A);

// @0x1406a57a0
bool FUN_1406a57a0()
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x34) == 1)
        return true;
    return false;
}
MS2_REPLACE(0x1406A57A0, FUN_1406a57a0, 42, 0x6D0F554E);

// @0x1406a57d0
bool FUN_1406a57d0()
{
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x35) == 1)
        return true;
    return false;
}
MS2_REPLACE(0x1406A57D0, FUN_1406a57d0, 42, 0x06BD45DC);

// @0x1406a5800
bool FUN_1406a5800()
{
    if (FUN_1406a57d0() == true || !FUN_1406a5770())
        return false;
    return FUN_140166410()->FUN_14036d570(0x46);
}
MS2_REPLACE(0x1406A5800, FUN_1406a5800, 56, 0xE77E0C92);

// @0x1406a5840
bool FUN_1406a5840()
{
    if (FUN_1406a57a0() == true || !FUN_1406a5770())
        return false;
    return FUN_140166410()->FUN_14036d570(0x47);
}
MS2_REPLACE(0x1406A5840, FUN_1406a5840, 56, 0x6AF70C30);

// @0x1406a5880
bool FUN_1406a5880()
{
    return FUN_140166410()->FUN_14036d570(0x48);
}
MS2_REPLACE(0x1406A5880, FUN_1406a5880, 27, 0x125998D9);

// @0x1406a58b0
bool FUN_1406a58b0()
{
    if (!FUN_1406a5880())
        return false;
    return FUN_140166410()->FUN_14036d570(0xec);
}
MS2_REPLACE(0x1406A58B0, FUN_1406a58b0, 43, 0x19A075F1);

// @0x1406a58f0
bool FUN_1406a58f0()
{
    if (!FUN_1406a5880())
        return false;
    return FUN_140166410()->FUN_14036d570(0xa9);
}
MS2_REPLACE(0x1406A58F0, FUN_1406a58f0, 43, 0x5B820E5A);

// The star shop event has an npc.
// @0x1406a5930
bool FUN_1406a5930()
{
    int nNpcId = FUN_140427050(FUN_140302b00()->GetStarShop());
    if (nNpcId == 0 || FUN_1406cd330(nNpcId) == NULL)
        return false;
    return true;
}
MS2_REPLACE(0x1406A5930, FUN_1406a5930, 185, 0x1098843A);

// @0x1406a59f0
int FUN_1406a59f0(Unk_MeratJobLimit* pLimit, int nJob)
{
    if (pLimit == NULL)
        return 0x6a;
    unsigned nJobFlag = FUN_1402227e0(nJob, 0);
    if ((pLimit->m_nJobFlags & nJobFlag) == 0)
        return 0xb5;
    return 0;
}
MS2_REPLACE(0x1406A59F0, FUN_1406a59f0, 78, 0x21B65BE1);

// The inventory item can be listed on the UGC market by this owner.
// MS2-FUNCTIONAL: the early-return / destructor layout of the 0x5da-byte filter differs
// @0x1406a5a50
bool FUN_1406a5a50(MS2Ptr<CItem> spItem, const Unk_MeratItemOwner* pOwner)
{
    if (spItem == NULL)
        return false;
    if (spItem->FUN_140527840() == NULL)
        return false;
    if (spItem->FUN_140526010())
    {
        if (!FUN_140166410()->FUN_14036d570(0xec))
            return false;
        Unk_MeratItemUgc* pUgc = reinterpret_cast<Unk_MeratItemUgc*>(spItem->FUN_1405278d0());
        if (pUgc == NULL)
            return false;
        if (pUgc->m_blueprint.m_n18 == 0)
            return false;
        if (pUgc->FUN_1406321a0() || pUgc->FUN_1406321d0())
            return false;
        if (!FUN_140633d50(spItem))
            return false;
        if (pUgc->m_blueprint.m_n40 == pOwner->m_nId && pUgc->m_blueprint.m_n38 == pOwner->m_nType)
            return true;
        return false;
    }
    if (spItem->FUN_140525f60() == 0)
    {
        if (FUN_140166410()->FUN_14036d570(0xa9) && spItem->FUN_140525790())
        {
            Unk_MeratMusicScore* pScore = reinterpret_cast<Unk_MeratMusicScore*>(spItem->FUN_140527990());
            if (pScore != NULL)
            {
                if (pScore->m_n38 != 0)
                    return false;
                if (!FUN_14026d4d0(pOwner, pScore->m_nNoteType, pScore->m_nNoteId))
                    return false;
                MS2Ptr<ItemMusicScore> spScore =
                    FUN_140281980()->FUN_1405565f0(reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053c510());
                if (spScore == NULL)
                    return false;
                if (spScore->FUN_14054ad00() != spItem->FUN_140527340())
                    return false;
                if (spItem->FUN_140526bd0() != 2)
                    return false;
                if (!FUN_140633d50(spItem))
                    return false;
                return true;
            }
        }
        return false;
    }
    Unk_MeratItemUgc* pUgc = reinterpret_cast<Unk_MeratItemUgc*>(spItem->FUN_1405278d0());
    if (pUgc == NULL)
        return false;
    if (pUgc->FUN_1406321a0() || pUgc->FUN_1406321d0())
        return false;
    if (!spItem->FUN_140526060(const_cast<Unk_MeratItemOwner*>(pOwner)))
        return false;
    if (!FUN_140633d50(spItem))
        return false;
    return true;
}
MS2_REPLACE(0x1406A5A50, FUN_1406a5a50, 1498, 0x440A186E);

// The item can be sold on the UGC market.
// @0x1406a6030
bool FUN_1406a6030(MS2Ptr<CItemData> spItem)
{
    if (spItem == NULL)
        return false;
    if (spItem->FUN_14053d6f0())
        return true;
    if (spItem->FUN_14053d900())
        return FUN_140166410()->FUN_14036d570(0xec);
    if (spItem->FUN_14053cd10())
        return FUN_140166410()->FUN_14036d570(0xa9);
    return false;
}
MS2_REPLACE(0x1406A6030, FUN_1406a6030, 265, 0x74B7DAFD);

// @0x1406a6140
int FUN_1406a6140()
{
    return 7;
}
MS2_REPLACE(0x1406A6140, FUN_1406a6140, 6, 0xDBB5A9B9);

// The rate percent of a price.
// @0x1406a6150
__int64 FUN_1406a6150(__int64 nPrice, unsigned nRate)
{
    if (nPrice <= 0 || nRate == 0)
        return 0;
    unsigned nPercent = std::min<unsigned>(nRate, 100);
    __int64 nResult = nPrice * nPercent / 100;
    return nResult;
}
MS2_REPLACE(0x1406A6150, FUN_1406a6150, 102, 0xEA22620A);

// A price less the rate percent.
// @0x1406a61c0
__int64 FUN_1406a61c0(__int64 nPrice, unsigned nRate)
{
    if (nPrice == 0 || nRate == 0)
        return 0;
    unsigned nPercent = 100 - std::min<unsigned>(nRate, 100);
    return nPrice * nPercent / 100;
}
MS2_REPLACE(0x1406A61C0, FUN_1406a61c0, 99, 0x5705D44E);

// ---- CMeratMarketPacket::BuyPacket ---------------------------------------------------------------------------------

// @0x1406a6230
CMeratMarketPacket::BuyPacket::BuyPacket()
{
    Reset();
}

// @0x1406a62b0
void CMeratMarketPacket::BuyPacket::Reset()
{
    m_nKind = 0;
    m_key.Reset();
    m_n30 = 0;
    m_n34 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n4c = 0;
    m_str50.Empty();
    m_str58.Empty();
    m_n60 = 0;
    m_b68 = false;
    m_n6c = 0x11;
    m_n70 = 0;
    m_n74 = 0;
    m_n78 = 0;
    m_n80 = 0;
    m_n88 = 0;
}
MS2_REPLACE_METHOD(0x1406A62B0, CMeratMarketPacket::BuyPacket, Reset, 265, 0x9545D22B);

// @0x1406a63c0
void CMeratMarketPacket::BuyPacket::CopyFrom(const BuyPacket& other)
{
    *this = other;
}
MS2_REPLACE_METHOD(0x1406A63C0, CMeratMarketPacket::BuyPacket, CopyFrom, 34, 0x5B7DFB1F);

// @0x1406a63f0
void CMeratMarketPacket::BuyPacket::Write(COutputStream& stream)
{
    stream.vfunc_o10_1((unsigned char)m_nKind);
    m_key.Write(stream);
    stream.vfunc_o10_3(m_n34);
    stream.vfunc_o10_3(m_n30);
    stream.vfunc_o10_4(m_n38);
    stream.vfunc_o10_3(m_n40);
    stream.vfunc_o10_3(m_n44);
    stream.vfunc_o10_3(m_n48);
    stream.vfunc_o10_1((unsigned char)m_n4c);
    stream.vfunc_o10_8(m_str50);
    stream.vfunc_o10_8(m_str58);
    stream.vfunc_o10_4(m_n60);
    stream.vfunc_o10_0(m_b68);
    stream.vfunc_o10_1((unsigned char)m_n6c);
    stream.vfunc_o10_3(m_n70);
    stream.vfunc_o10_3(m_n74);
    stream.vfunc_o10_3(m_n78);
    stream.vfunc_o10_3(m_n88);
}
MS2_REPLACE_METHOD(0x1406A63F0, CMeratMarketPacket::BuyPacket, Write, 485, 0xEEF87292);

// @0x1406a65e0
void CMeratMarketPacket::BuyPacket::Read(CInPacket& packet)
{
    m_nKind = packet.vfunc_o8_1();
    m_key.Read(packet);
    m_n34 = packet.vfunc_o8_3();
    m_n30 = packet.vfunc_o8_3();
    m_n38 = packet.vfunc_o8_4();
    m_n40 = packet.vfunc_o8_3();
    m_n44 = packet.vfunc_o8_3();
    m_n48 = packet.vfunc_o8_3();
    m_n4c = packet.vfunc_o8_1();
    m_str50 = packet.vfunc_o8_8();
    m_str58 = packet.vfunc_o8_8();
    m_n60 = packet.vfunc_o8_4();
    m_b68 = packet.vfunc_o8_0();
    m_n6c = packet.vfunc_o8_1();
    m_n70 = packet.vfunc_o8_3();
    m_n74 = packet.vfunc_o8_3();
    m_n78 = packet.vfunc_o8_3();
    m_n88 = packet.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1406A65E0, CMeratMarketPacket::BuyPacket, Read, 1105, 0xAA1E76E3);

// ---- CMeratMarketPacket::ErrorPacket -------------------------------------------------------------------------------

// @0x1406a6a40
CMeratMarketPacket::ErrorPacket::ErrorPacket() : m_nKind(0), m_key(0, 0), m_n30(0), m_nValue(0)
{
}

// @0x1406a6ac0
CMeratMarketPacket::ErrorPacket::ErrorPacket(int nKind, int nError, const Unk_MeratProductKey& key, __int64 nValue)
    : m_nKind(nKind), m_nError(nError), m_key(key.m_nPremiumId, key.m_nUgcId), m_n30(0), m_nValue(nValue)
{
}

// @0x1406a6b60
void CMeratMarketPacket::ErrorPacket::Write(COutputStream& stream)
{
    stream.vfunc_o10_1((unsigned char)m_nKind);
    stream.vfunc_o10_3(m_nError);
    m_key.Write(stream);
    stream.vfunc_o10_4(m_nValue);
    stream.vfunc_o10_1((unsigned char)m_n30);
}
MS2_REPLACE_METHOD(0x1406A6B60, CMeratMarketPacket::ErrorPacket, Write, 140, 0xBC3B2559);

// @0x1406a6c00
void CMeratMarketPacket::ErrorPacket::Read(CInPacket& packet)
{
    m_nKind = packet.vfunc_o8_1();
    m_nError = packet.vfunc_o8_3();
    m_key.Read(packet);
    m_nValue = packet.vfunc_o8_4();
    m_n30 = packet.vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1406A6C00, CMeratMarketPacket::ErrorPacket, Read, 216, 0xA5721865);

// ---- CMeratMarketRandomSaleData ------------------------------------------------------------------------------------

// @0x1406a6ce0
CMeratMarketRandomSaleData::CMeratMarketRandomSaleData()
{
    m_n18 = 0;
    m_n1c = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_n28 = 1;
}

// @0x1406a6d50
__int64 FUN_1406a6d50(Common::Constants::Value<int>& value)
{
    return *value.Get();
}
MS2_REPLACE(0x1406A6D50, FUN_1406a6d50, 27, 0x4C6042D7);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b630-0x142c9b750 .text$yd
