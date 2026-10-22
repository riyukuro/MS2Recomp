// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The UGC proxy records (users, uploads, items, banners, guild
// marks / posters, blueprint images, market listings, bookmarks) and the MS2Ptr / container glue over them.
// MS2-UNIT: commonfiles\ugcdef.cpp
// MS2-RANGE: 0x14088e340-0x14089e270 .text$mn
// MS2-RANGE: 0x1400bd940-0x1400bdb40 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CNode@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@_JH@Z 0x140899450 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEAA@_JH@Z 0x140899540 ; unique
// MS2-PIN: ??1?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x140899770 ; unique
// MS2-PIN: ?Find@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@_J@Z 0x14089ace0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_JH@Z 0x14089b7d0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14089bb90 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14089bec0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14089bfa0 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_JH@Z 0x14089c2e0 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14089c870 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEAAPEAVCNode@12@_JH@Z 0x14089cc90 ; unique
// MS2-PIN: ?RemoveAll@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14089d2b0 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14089d410 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14089d5e0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@_JH@Z 0x14089d870 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14089db40 ; unique
// MS2-PIN: ?Successor@?$CRBTree@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14089dc20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1IUgcProxy@@UEAA@XZ 0x1408999a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcdef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcdef.h"
#include "stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "constraints.h"
#include "ms2/placeholder/exception.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "commonstruct.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cugcgetcosttable.h"

// The UGC info behind CItem::FUN_1405278d0 as this unit reads it (name at +0x40, rarity at +0x48).
struct Unk_UgcItemInfoView
{
    char m_pad_00[0x40];
    CStringW m_strName;
    int m_nRarity;
};

// The time helpers of unit_14088dbf0: the time (a packed date / hour) of a reservation, and the broken-down current time.
struct Unk_DateParts
{
    void* m_00;
    int m_date;
    int m_hour;
    void* m_time;
    int m_year;
    int m_month;
    int m_day;
    int m_dow;
    int m_hour2;
    int m_minute;
};
MS2_CHECK_SIZE(Unk_DateParts, 0x30);
unsigned __int64 FUN_14088dbf0(int nDate, int nHour);
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* out, __int64 t, int nHourOffset);
__int64 FUN_140869440();
unsigned char FUN_140898b80(CInPacket& packet, Unk_1402c45d0 checker);     // a byte that Unk_1402c45d0 accepts, else throws

// The UGC managers behind the item.cpp singleton FUN_14052d220 (only the "is the server a test server" query is used).
class Unk_SSGUgcMgr { public: int FUN_14187f3b0(); };
Unk_SSGUgcMgr* FUN_14052d220();
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);     // "{0}" formatter
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& arg0, const CStringW& arg1);
CString FUN_1410280d0(int nKind, CString strName);                         // the local file of a ugc content kind

// The music book table of item.cpp (the title of a music book lives at +0x28).
class Unk_MusicBookInfo : public CPtred { public: char m_pad18[0x10]; CString m_str28; };
class Unk_MusicBookTable { public: MS2Ptr<Unk_MusicBookInfo> FUN_14072cc10(unsigned); };
Unk_MusicBookTable* FUN_14052d1d0();

// The product id of the merat market (a premium product number and a UGC listing id); the key of the bookmark map.
struct Unk_MeratOid
{
    bool operator<(const Unk_MeratOid& o) const;
    bool operator==(const Unk_MeratOid& o) const;
    int m_nPremiumId;                                       // +0x00
    unsigned __int64 m_nUgcId;                              // +0x08
};
MS2_CHECK_SIZE(Unk_MeratOid, 0x10);

// @0x140899d90
bool Unk_MeratOid::operator<(const Unk_MeratOid& o) const
{
    if (m_nPremiumId != o.m_nPremiumId)
        return m_nPremiumId < o.m_nPremiumId;
    else
        return m_nUgcId < o.m_nUgcId;
}

// @0x140899ce0
bool Unk_MeratOid::operator==(const Unk_MeratOid& o) const
{
    if (m_nPremiumId == o.m_nPremiumId && m_nUgcId == o.m_nUgcId)
        return true;
    return false;
}

// The merat market product record as this unit sees it: the product id at +0x18, the UGC listing id at +0x288.
class Unk_MeratEquipEntry : public CPtred
{
public:
    Unk_MeratOid m_oid;                                     // +0x18
    char m_pad_28[0x288 - 0x28];
    __int64 m_nId;                                          // +0x288
};
class Unk_CharBookMarkOwner : public CPtred
{
};

// A node of the merat market basket tree: a comma separated list of items with a count, and the child nodes.
class Unk_BasketNode : public CPtred
{
public:
    char m_pad_18[0x30 - 0x18];
    CStringA m_strItems;                                    // +0x30
    int m_pad_38;
    int m_nCount;                                           // +0x3c
    ATL::CAtlList<MS2Ptr<Unk_BasketNode> > m_children;      // +0x40
};
// The receiver of the basket items.
class Unk_BasketSink
{
public:
    void FUN_1406ad840(const char* pszItem, int nCount);
};
void FUN_14028c700(const CStringA& strText, ATL::CAtlArray<CStringA>& arrOut, const char* pszSep);

// The names of the market order kinds (CUgcMarketSchCond::m_n20 indexes them).
static CStringA s_orderNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// Header statics of the unit: the property names of the UGC market search and a map (none is used by this unit's code).
static CStringA s_strSkill = "skill";
static CStringA s_strStun = "stun";
static ATL::CAtlMap<unsigned int, CStringA> s_mapNames;
static CStringA s_strJobCode = "jobCode";
static CStringA s_strSortValue = "sortValue";
static CStringA s_strTabIndex = "tabIndex";

// The scoped lock of a CLockCriticalSection (ctor 0x140203610, dtor 0x1401b5120).
struct Unk_PetLock { Unk_PetLock(CLockCriticalSection& cs, int n); ~Unk_PetLock(); void* p; };
MS2_CHECK_SIZE(Unk_PetLock, 8);

// Market lookups of the item and merat market units.
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1406a5390(int nItemId);
bool FUN_1406a5800();
bool FUN_140164830(const CStringW& a, const CStringW& b);

// The music record of a CItem as CUgcItemMusicNote::FUN_140893bb0 reads it.
struct Unk_MusicSrcView
{
    char m_pad_00[0x18];
    int m_n18;
    int m_n1c;
    CStringW m_str20;
    CStringW m_str28;
    CStringA m_str30;
    char m_pad_38[0x18];
    int m_n50;
    __int64 m_n58;
    __int64 m_n60;
    CStringW m_str68;
};

// @0x140899640
IUgcProxy::IUgcProxy()
{
}

// @0x14089abe0
void IUgcProxy::Write(COutputStream& stream) const
{
}

// @0x14089abd0
void IUgcProxy::Read(CInPacket& packet)
{
}

// @0x14088e340
CUgcUserProxy::CUgcUserProxy()
{
    Clear();
}

// @0x14088e3b0
CUgcUserProxy::~CUgcUserProxy()
{
}

// @0x14088e410
void CUgcUserProxy::Clear()
{
    m_nType = 0;
    m_accountId = 0;
    m_characterId = 0;
    m_strObjectName = "";
    m_strName = L"";
}

// @0x14088e480
int CUgcUserProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcUserProxy* pSrc = static_cast<const CUgcUserProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nType = pSrc->m_nType;
    m_accountId = pSrc->m_accountId;
    m_characterId = pSrc->m_characterId;
    m_strObjectName = pSrc->m_strObjectName;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x14088e540
void CUgcUserProxy::Write(COutputStream& stream) const
{
    stream.WriteInt32(m_nType);
    stream.WriteInt64(m_accountId);
    stream.WriteInt64(m_characterId);
    stream.WriteUnicodeStringA(m_strObjectName);
    stream.WriteUnicodeString(m_strName);
}

// @0x14088e5f0
void CUgcUserProxy::Read(CInPacket& packet)
{
    Clear();
    m_nType = packet.ReadInt32();
    m_accountId = packet.ReadInt64();
    m_characterId = packet.ReadInt64();
    m_strObjectName = packet.ReadUnicodeStringA();
    m_strName = packet.ReadUnicodeString();
}

// @0x14088e790
CUgcUploadProxy::CUgcUploadProxy()
{
    Clear();
}

// @0x14088e800
CUgcUploadProxy::~CUgcUploadProxy()
{
}

// @0x14088e860
void CUgcUploadProxy::Clear()
{
    m_uid = 0;
    m_strName = "";
    m_nType = 0;
    m_nState = 0xff;
    m_strPath = "";
}

// @0x14088e8d0
int CUgcUploadProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcUploadProxy* pSrc = static_cast<const CUgcUploadProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_uid = pSrc->m_uid;
    m_strName = pSrc->m_strName;
    m_nType = pSrc->m_nType;
    m_nState = pSrc->m_nState;
    m_strPath = pSrc->m_strPath;
    return 1;
}

// @0x14088e990
void CUgcUploadProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_uid);
    stream.WriteUnicodeStringA(m_strName);
    stream.WriteUInt8(m_nType);
    stream.WriteUInt8(m_nState);
    stream.WriteUnicodeStringA(m_strPath);
}

// @0x14088ea40
void CUgcUploadProxy::Read(CInPacket& packet)
{
    Clear();
    m_uid = packet.ReadInt64();
    m_strName = packet.ReadUnicodeStringA();
    m_nType = packet.ReadUInt8();
    m_nState = packet.ReadUInt8();
    m_strPath = packet.ReadUnicodeStringA();
}

// @0x14088ebf0
CUgcItemProxy::CUgcItemProxy()
{
    Clear();
}

// @0x14088ec50
CUgcItemProxy::CUgcItemProxy(CItem* pItem)
{
    FUN_14088f100(pItem);
}

// @0x14088ecc0
CUgcItemProxy::~CUgcItemProxy()
{
}

// @0x14088ed00
void CUgcItemProxy::Clear()
{
    m_itemUid = 0;
    m_nItemId = 0;
    m_nCount = 0;
    m_strName = "";
    m_nRarity = 0;
    m_uid = 0;
    m_nFlags = 0;
}

// @0x14088ed80
int CUgcItemProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcItemProxy* pSrc = static_cast<const CUgcItemProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_itemUid = pSrc->m_itemUid;
    m_nItemId = pSrc->m_nItemId;
    m_nCount = pSrc->m_nCount;
    m_strName = pSrc->m_strName;
    m_nRarity = pSrc->m_nRarity;
    return 1;
}

// @0x14088ee30
void CUgcItemProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_itemUid);
    stream.WriteInt32(m_nItemId);
    stream.WriteInt32(m_nCount);
    stream.WriteUnicodeString(m_strName);
    stream.WriteUInt8(m_nRarity);
    stream.WriteInt64(m_uid);
    stream.WriteBool(m_nFlags == 1);
}

// @0x14088ef20
void CUgcItemProxy::Read(CInPacket& packet)
{
    Clear();
    m_itemUid = packet.ReadInt64();
    m_nItemId = packet.ReadInt32();
    m_nCount = packet.ReadInt32();
    m_strName = packet.ReadUnicodeString();
    m_nRarity = packet.ReadUInt8();
    m_uid = packet.ReadInt64();
    m_nFlags = packet.ReadBool();
}

// @0x14088f100
void CUgcItemProxy::FUN_14088f100(CItem* pItem)
{
    if (pItem != 0 && pItem->FUN_140525f10() != 0 && pItem->FUN_140525f60() != 0)
    {
        m_itemUid = pItem->FUN_140526a50();
        m_nItemId = pItem->FUN_1405276c0();
        m_nCount = 1;
        m_strName = reinterpret_cast<Unk_UgcItemInfoView*>(pItem->FUN_1405278d0())->m_strName;
        m_nRarity = reinterpret_cast<Unk_UgcItemInfoView*>(pItem->FUN_1405278d0())->m_nRarity;
        return;
    }
    Clear();
}

// @0x14088f1c0
CUgcItemPC::CUgcItemPC()
{
    Clear();
}

// @0x14088f210
CUgcItemPC::CUgcItemPC(CItem* pItem, int nObjectId)
    : CUgcItemProxy(pItem)
{
    m_nObjectId = nObjectId;
    int nSlot;
    if (pItem)
        nSlot = pItem->FUN_14052a020();
    else
        nSlot = 0;
    m_nSlot = nSlot;
}

// @0x14088f2a0
CUgcItemPC::~CUgcItemPC()
{
}

// @0x14088f2d0
int CUgcItemPC::FUN_14088f2d0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    m_nObjectId = 0;
    m_nSlot = 0;
    return 1;
}

// @0x14088f330
void CUgcItemPC::Clear()
{
    CUgcItemProxy::Clear();
    m_nObjectId = 0;
    m_nSlot = 0;
}

// @0x14088f370
int CUgcItemPC::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemPC* pSrc = static_cast<const CUgcItemPC*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nObjectId = pSrc->m_nObjectId;
    m_nSlot = pSrc->m_nSlot;
    return 1;
}

// @0x14088f3f0
UgcItemIcon::CallBackData::CallBackData()
{
    FUN_14088f4b0();
}

// @0x14088f450
UgcItemIcon::CallBackData::~CallBackData()
{
    m_spCond = 0;
}

// @0x14088f4b0
void UgcItemIcon::CallBackData::FUN_14088f4b0()
{
    m_nKind = -1;
    m_spCond = 0;
    m_30 = 0;
    m_38 = 0;
}

// @0x14088f500
void UgcItemIcon::CallBackData::FUN_14088f500(int nKind, const CMeratMarketSchCond* pCond, __int64 n30, int n38)
{
    m_nKind = nKind;
    m_spCond = 0;
    if (pCond != 0)
    {
        m_spCond.AssignRaw(new CMeratMarketSchCond);
        m_spCond->FUN_1406a3720(pCond);
    }
    m_30 = n30;
    m_38 = n38;
}

// @0x14088f5e0
void UgcItemIcon::CallBackData::FUN_14088f5e0(const CallBackData* pOther)
{
    m_nKind = pOther->m_nKind;
    m_spCond = 0;
    if (pOther->m_spCond.get() != 0)
    {
        m_spCond.AssignRaw(new CMeratMarketSchCond);
        m_spCond->FUN_1406a3720(pOther->m_spCond.get());
    }
    m_30 = pOther->m_30;
    m_38 = pOther->m_38;
}

// @0x14088f6f0
CUgcItemIconPC::CUgcItemIconPC()
{
    Clear();
}

// @0x14088f750
CUgcItemIconPC::CUgcItemIconPC(CItem* pItem, int n50)
    : CUgcItemProxy(pItem)
{
    int nObjectId = pItem ? pItem->FUN_14052a020() : 0;
    int nKind;
    if (nObjectId == 0)
        nKind = 2;
    else
        nKind = 1;
    m_nKind = nKind;
    m_nObjectId = nObjectId;
    m_n50 = n50;
    m_callBack.FUN_14088f4b0();
}

// @0x14088f830
CUgcItemIconPC::CUgcItemIconPC(const UgcItemIcon::CallBackData& callBack)
    : CUgcItemProxy((CItem*)0)
{
    FUN_14088f960(callBack);
}

// @0x14088f8a0
CUgcItemIconPC::~CUgcItemIconPC()
{
}

// @0x14088f8e0
int CUgcItemIconPC::FUN_14088f8e0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    m_nKind = 0;
    m_nObjectId = 0;
    m_n50 = 0;
    m_callBack.FUN_14088f4b0();
    return 1;
}

// @0x14088f960
void CUgcItemIconPC::FUN_14088f960(const UgcItemIcon::CallBackData& callBack)
{
    m_nObjectId = 0;
    m_n50 = 0;
    m_nKind = 3;
    m_callBack.FUN_14088f5e0(&callBack);
}

// @0x14088f9c0
void CUgcItemIconPC::Clear()
{
    CUgcItemProxy::Clear();
    m_nKind = 0;
    m_nObjectId = 0;
    m_n50 = 0;
    m_callBack.FUN_14088f4b0();
}

// @0x14088fa20
int CUgcItemIconPC::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemIconPC* pSrc = static_cast<const CUgcItemIconPC*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nKind = pSrc->m_nKind;
    m_nObjectId = pSrc->m_nObjectId;
    m_n50 = pSrc->m_n50;
    m_callBack.FUN_14088f5e0(&pSrc->m_callBack);
    return 1;
}

// @0x14088fad0
CUgcItemCube::CUgcItemCube()
{
    Clear();
}

// @0x14088fb30
CUgcItemCube::CUgcItemCube(CItem* pItem, egf::EntityID id)
    : CUgcItemProxy(pItem)
{
    m_entityId = id;
}

// @0x14088fbb0
CUgcItemCube::~CUgcItemCube()
{
}

// @0x14088fbe0
int CUgcItemCube::FUN_14088fbe0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    efd::UInt64 zero = 0;
    m_entityId = zero;
    return 1;
}

// @0x14088fc40
void CUgcItemCube::Clear()
{
    CUgcItemProxy::Clear();
    efd::UInt64 zero = 0;
    m_entityId = zero;
}

// @0x14088fc80
int CUgcItemCube::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemCube* pSrc = static_cast<const CUgcItemCube*>(pOther);
    if (pSrc == 0)
        return 0;
    m_entityId = pSrc->m_entityId;
    return 1;
}

// @0x14088fd00
CUgcItemRidee::CUgcItemRidee()
{
    Clear();
}

// @0x14088fd60
CUgcItemRidee::CUgcItemRidee(CItem* pItem, egf::EntityID id)
    : CUgcItemProxy(pItem)
{
    m_entityId = id;
}

// @0x14088fde0
CUgcItemRidee::~CUgcItemRidee()
{
}

// @0x14088fe10
int CUgcItemRidee::FUN_14088fe10(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    efd::UInt64 zero = 0;
    m_entityId = zero;
    return 1;
}

// @0x14088fe70
void CUgcItemRidee::Clear()
{
    CUgcItemProxy::Clear();
    efd::UInt64 zero = 0;
    m_entityId = zero;
}

// @0x14088feb0
int CUgcItemRidee::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemRidee* pSrc = static_cast<const CUgcItemRidee*>(pOther);
    if (pSrc == 0)
        return 0;
    m_entityId = pSrc->m_entityId;
    return 1;
}

// @0x14088ff30
CUgcBannerProxy::CUgcBannerProxy()
{
    Clear();
}

// @0x14088ff80
CUgcBannerProxy::~CUgcBannerProxy()
{
}

// @0x14088ffb0
void CUgcBannerProxy::Clear()
{
    m_nBannerId = 0;
}

// @0x14088ffd0
int CUgcBannerProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcBannerProxy* pSrc = static_cast<const CUgcBannerProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nBannerId = pSrc->m_nBannerId;
    return 1;
}

// @0x140890030
void CUgcBannerProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64((unsigned int)m_nBannerId);
}

// @0x140890070
void CUgcBannerProxy::Read(CInPacket& packet)
{
    Clear();
    m_nBannerId = packet.ReadInt64();
}

// @0x1408900d0
CUgcBannerReserve::CUgcBannerReserve()
{
    m_nBannerUid = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_nDate = 0;
    m_nHour = 0;
    m_n30 = 0;
}

// @0x140890150
CUgcBannerReserve::~CUgcBannerReserve()
{
}

// @0x140890180
int CUgcBannerReserve::FUN_140890180() const
{
    unsigned __int64 nReserved = FUN_14088dbf0(m_nDate, m_nHour);
    Unk_DateParts now;
    FUN_14088dfa0(&now, FUN_140869440(), 0);
    if (nReserved < (unsigned __int64)now.m_00)
        return 1;
    return 0;
}

// @0x1408901e0
void CUgcBannerReserve::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_nBannerUid);
    stream.WriteInt32(m_n20);
    stream.WriteInt64((unsigned int)m_n24);
    stream.WriteInt32(m_nDate);
    stream.WriteInt32(m_nHour);
    stream.WriteInt64(m_n30);
}

// @0x1408902a0
void CUgcBannerReserve::Read(CInPacket& packet)
{
    m_nBannerUid = packet.ReadInt64();
    m_n20 = packet.ReadInt32();
    m_n24 = packet.ReadInt64();
    m_nDate = packet.ReadInt32();
    m_nHour = packet.ReadInt32();
    m_n30 = packet.ReadInt64();
}

// @0x1408903c0
unsigned __int64 CUgcBannerReserve::GetKey() const
{
    unsigned __int64 nKey = FUN_14088dbf0(m_nDate, m_nHour);
    return nKey;
}

// @0x140890400
CUgcPreReserve::CUgcPreReserve() : m_reserves(10)
{
    m_nCount = 0;
}

// @0x140890460
CUgcPreReserve::~CUgcPreReserve()
{
    m_reserves.RemoveAll();
}

// @0x1408904b0
void CUgcPreReserve::Write(COutputStream& stream) const
{
    stream.WriteInt64((unsigned int)m_nCount);
    unsigned int nCount = (unsigned int)m_reserves.GetCount();
    stream.WriteInt32(nCount);
    for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
    {
        CUgcBannerReservePtr spReserve = m_reserves.GetValueAt(pos);
        if (spReserve.get() != 0)
            spReserve->Write(stream);
    }
}

// @0x1408905b0
void CUgcPreReserve::Read(CInPacket& packet)
{
    m_nCount = packet.ReadInt64();
    unsigned int nCount = packet.ReadInt32();
    for (unsigned int i = 0; i < nCount; ++i)
    {
        CUgcBannerReservePtr spReserve(new CUgcBannerReserve);
        spReserve->Read(packet);
        m_reserves.SetAt(spReserve->GetKey(), spReserve);
    }
}

// @0x140890700
CUgcBannerPost::CUgcBannerPost() : m_reserves(10)
{
    Clear();
}

// @0x140890760
CUgcBannerPost::~CUgcBannerPost()
{
}

// @0x1408907a0
void CUgcBannerPost::Clear()
{
    CUgcBannerProxy::Clear();
    m_reserves.RemoveAll();
}

// @0x1408907d0
int CUgcBannerPost::CopyFrom(const IUgcProxy* pOther)
{
    m_reserves.RemoveAll();
    if (CUgcBannerProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcBannerPost* pSrc = static_cast<const CUgcBannerPost*>(pOther);
    if (pSrc == 0)
        return 0;
    for (POSITION pos = pSrc->m_reserves.GetHeadPosition(); pos != NULL; pSrc->m_reserves.GetNext(pos))
    {
        unsigned __int64 nKey = pSrc->m_reserves.GetKeyAt(pos);
        CUgcBannerReservePtr spReserve = pSrc->m_reserves.GetValueAt(pos);
        m_reserves.SetAt(nKey, spReserve);
    }
    return 1;
}

// @0x1408908e0
void CUgcBannerPost::Write(COutputStream& stream) const
{
    CUgcBannerProxy::Write(stream);
    stream.WriteUInt8((unsigned char)m_reserves.GetCount());
    for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
    {
        CUgcBannerReservePtr pUgcBannerReserve = m_reserves.GetValueAt(pos);
        MS2_ASSERT_AT(0x47b, pUgcBannerReserve);
        pUgcBannerReserve->Write(stream);
    }
}

// @0x1408909f0
void CUgcBannerPost::Read(CInPacket& packet)
{
    Clear();
    CUgcBannerProxy::Read(packet);
    int nCount = packet.ReadUInt8();
    for (int i = 0; i < nCount; ++i)
    {
        CUgcBannerReservePtr spReserve(new CUgcBannerReserve);
        if (spReserve.get() != 0)
        {
            spReserve->Read(packet);
            unsigned __int64 nKey = spReserve->GetKey();
            m_reserves.SetAt(nKey, spReserve);
        }
    }
}

// @0x140890b50
CUgcBannerReservePtr CUgcBannerPost::FUN_140890b50(unsigned __int64 nKey)
{
    CUgcBannerReservePtr spReserve(0);
    m_reserves.Lookup(nKey, spReserve);
    return spReserve;
}

// @0x140890bd0
__int64 CUgcBannerPost::FUN_140890bd0()
{
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_nBannerId);
    if (banner == 0)
        return 0;
    __int64 nTotal = 0;
    if (banner->m_nAd == 0)
    {
        nTotal = banner->GetCurrentHourly();
    }
    else
    {
        for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
        {
            CUgcBannerReservePtr spReserve = m_reserves.GetValueAt(pos);
            if (spReserve.get() != 0)
            {
                CUgcBannerReserve* pReserve = spReserve.operator->();
                __int64 nHourly = banner->GetHourly(pReserve->m_nHour);
                nTotal += nHourly;
            }
        }
    }
    return nTotal;
}

// @0x140890d50
CUgcRegistBanner::CUgcRegistBanner()
{
    Clear();
}

// @0x140890df0
CUgcRegistBanner::~CUgcRegistBanner()
{
    Clear();
}

// @0x140890e80
void CUgcRegistBanner::Clear()
{
    m_nType = 0;
    static_cast<IUgcProxy&>(m_user).Clear();
    static_cast<IUgcProxy&>(m_upload).Clear();
    static_cast<IUgcProxy&>(m_post).Clear();
    m_strUrl = "";
}

// @0x140890f30
void CUgcRegistBanner::Write(COutputStream& stream) const
{
    stream.WriteUInt8((unsigned char)m_nType);
    static_cast<const IUgcProxy&>(m_user).Write(stream);
    static_cast<const IUgcProxy&>(m_upload).Write(stream);
    static_cast<const IUgcProxy&>(m_post).Write(stream);
    CStringA strUrl(m_strUrl);
    stream.WriteUnicodeStringA(strUrl);
}

// @0x140891020
void CUgcRegistBanner::Read(CInPacket& packet)
{
    Unk_1402c45d0 checker;
    m_nType = FUN_140898b80(packet, checker);
    static_cast<IUgcProxy&>(m_user).Read(packet);
    static_cast<IUgcProxy&>(m_upload).Read(packet);
    static_cast<IUgcProxy&>(m_post).Read(packet);
    m_strUrl = packet.ReadUnicodeStringA();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
    {
        static_cast<IUgcProxy&>(m_upload).Clear();
        static_cast<IUgcProxy&>(m_post).Clear();
        m_strUrl = "";
    }
}

// @0x1408911f0
int CUgcRegistBanner::FUN_1408911f0(unsigned __int64 nTime)
{
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_post.m_nBannerId);
    if (banner.get() != 0 && banner->m_nAd == 0)
        return 0;
    int nResult = 1;
    for (POSITION pos = m_post.m_reserves.GetHeadPosition(); pos != NULL; m_post.m_reserves.GetNext(pos))
    {
        unsigned __int64 nKey = m_post.m_reserves.GetKeyAt(pos);
        if (nKey >= nTime)
        {
            nResult = 0;
            break;
        }
    }
    return nResult;
}

// The banner serial / upload serial pair of a banner upload (no RTTI; two byte-identical copies, 0x140891300 / 0x140891490).
struct Unk_BannerSN
{
    Unk_BannerSN();
    void Write(COutputStream& stream) const;
    void Read(CInPacket& packet);
    CStringA ToString() const;
    unsigned int m_nBannerSN;
    unsigned __int64 m_nUploadSN;
};
MS2_CHECK_SIZE(Unk_BannerSN, 0x10);

// @0x140891300
Unk_BannerSN::Unk_BannerSN()
    : m_nBannerSN(0), m_nUploadSN(0)
{
}

// @0x140891330
void Unk_BannerSN::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_nBannerSN);
    stream.WriteInt64(m_nUploadSN);
}

// @0x140891390
void Unk_BannerSN::Read(CInPacket& packet)
{
    m_nBannerSN = packet.ReadInt64();
    m_nUploadSN = packet.ReadInt64();
}

// @0x140891400
CStringA Unk_BannerSN::ToString() const
{
    CStringA str;
    str.Format("m_bannerSN:%I64d, m_uploadSN:%I64d", m_nBannerSN, m_nUploadSN);
    return str;
}

// The second copy of the banner serial pair (byte-identical code, a different class).
struct Unk_BannerSN2
{
    Unk_BannerSN2();
    void Write(COutputStream& stream) const;
    void Read(CInPacket& packet);
    CStringA ToString() const;
    unsigned int m_nBannerSN;
    unsigned __int64 m_nUploadSN;
};
MS2_CHECK_SIZE(Unk_BannerSN2, 0x10);

// @0x140891490
Unk_BannerSN2::Unk_BannerSN2()
    : m_nBannerSN(0), m_nUploadSN(0)
{
}

// @0x1408914c0
void Unk_BannerSN2::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_nBannerSN);
    stream.WriteInt64(m_nUploadSN);
}

// @0x140891520
void Unk_BannerSN2::Read(CInPacket& packet)
{
    m_nBannerSN = packet.ReadInt64();
    m_nUploadSN = packet.ReadInt64();
}

// @0x140891590
CStringA Unk_BannerSN2::ToString() const
{
    CStringA str;
    str.Format("m_bannerSN:%I64d, m_uploadSN:%I64d", m_nBannerSN, m_nUploadSN);
    return str;
}

// The upload serials of a character (no RTTI).
struct Unk_CharUploadSNs
{
    Unk_CharUploadSNs();
    void Write(COutputStream& stream) const;
    void Read(CInPacket& packet);
    CStringW ToString() const;
    ATL::CAtlArray<__int64> m_serials;
    CStringW m_strCharName;
};

// @0x140891620
Unk_CharUploadSNs::Unk_CharUploadSNs()
{
    m_serials.RemoveAll();
}

// @0x140891670
void Unk_CharUploadSNs::Write(COutputStream& stream) const
{
    stream.WriteUnicodeString(m_strCharName);
    int nCount = (int)m_serials.GetCount();
    stream.WriteInt32(nCount);
    for (int i = 0; i < nCount; ++i)
        stream.WriteInt64(m_serials[i]);
}

// @0x140891730
void Unk_CharUploadSNs::Read(CInPacket& packet)
{
    m_strCharName = packet.ReadUnicodeString();
    int nCount = packet.ReadInt32();
    for (int i = 0; i < nCount; ++i)
        m_serials.Add(packet.ReadInt64());
}

// @0x140891820
CStringW Unk_CharUploadSNs::ToString() const
{
    CStringW strSerials;
    for (size_t i = 0; i < m_serials.GetCount(); ++i)
        strSerials += FUN_1406c6bd0(L"{0} ", m_serials[i]);
    CStringW strResult;
    strResult = FUN_140656190(L"m_charName={0}, m_uploadSN={1}", m_strCharName, strSerials);
    return strResult;
}

// @0x140891980
CUgcGuildMarkProxy::CUgcGuildMarkProxy()
{
    Clear();
}

// @0x1408919e0
CUgcGuildMarkProxy::~CUgcGuildMarkProxy()
{
    Clear();
}

// @0x140891a40
void CUgcGuildMarkProxy::Clear()
{
    m_nGuildId = 0;
    m_strName.Empty();
}

// @0x140891a80
int CUgcGuildMarkProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcGuildMarkProxy* pSrc = static_cast<const CUgcGuildMarkProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nGuildId = pSrc->m_nGuildId;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x140891b00
void CUgcGuildMarkProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_nGuildId);
}

// @0x140891b40
void CUgcGuildMarkProxy::Read(CInPacket& packet)
{
    m_nGuildId = packet.ReadInt64();
}

// @0x140891b90
CUgcGuildPosterProxy::CUgcGuildPosterProxy()
{
    Clear();
}

// @0x140891bf0
CUgcGuildPosterProxy::~CUgcGuildPosterProxy()
{
    Clear();
}

// @0x140891c50
void CUgcGuildPosterProxy::Clear()
{
    m_nGuildId = 0;
    m_nIndex = 0;
    m_strName.Empty();
}

// @0x140891c90
int CUgcGuildPosterProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcGuildPosterProxy* pSrc = static_cast<const CUgcGuildPosterProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nGuildId = pSrc->m_nGuildId;
    m_nIndex = pSrc->m_nIndex;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x140891d20
void CUgcGuildPosterProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_nGuildId);
    stream.WriteInt32(m_nIndex);
}

// @0x140891d70
void CUgcGuildPosterProxy::Read(CInPacket& packet)
{
    m_nGuildId = packet.ReadInt64();
    m_nIndex = packet.ReadInt32();
}

// @0x140891de0
CUgcBannerEmptyProxy::CUgcBannerEmptyProxy()
{
}

// @0x140891e20
CUgcBannerEmptyProxy::~CUgcBannerEmptyProxy()
{
}

// @0x140891e50
void CUgcBannerEmptyProxy::Clear()
{
}

// @0x140891e60
int CUgcBannerEmptyProxy::CopyFrom(const IUgcProxy* pOther)
{
    return 1;
}

// @0x140891e80
void CUgcBannerEmptyProxy::Write(COutputStream& stream) const
{
}

// @0x140891ea0
void CUgcBannerEmptyProxy::Read(CInPacket& packet)
{
}

// @0x140891ec0
CUgcBannerRollingImageProxy::CUgcBannerRollingImageProxy()
{
}

// @0x140891f10
CUgcBannerRollingImageProxy::~CUgcBannerRollingImageProxy()
{
}

// @0x140891f50
void CUgcBannerRollingImageProxy::Clear()
{
    m_images.clear();
}

// @0x140891f80
int CUgcBannerRollingImageProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcBannerRollingImageProxy* pSrc = static_cast<const CUgcBannerRollingImageProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_images = pSrc->m_images;
    return 1;
}

// @0x140891ff0
void CUgcBannerRollingImageProxy::Write(COutputStream& stream) const
{
    stream.WriteInt16((short)m_images.size());
    for (size_t i = 0; i < m_images.size(); ++i)
        stream.WriteInt64(m_images[i]);
}

// @0x1408920a0
void CUgcBannerRollingImageProxy::Read(CInPacket& packet)
{
    unsigned int nCount = (unsigned short)packet.ReadInt16();
    m_images.clear();
    m_images.reserve(nCount);
    for (size_t i = 0; i < nCount; ++i)
    {
        unsigned int nImage = packet.ReadInt64();
        m_images.push_back(nImage);
    }
}

// @0x140892170
CUgcShopBannerProxy::CUgcShopBannerProxy()
{
    Clear();
}

// @0x1408921e0
CUgcShopBannerProxy::~CUgcShopBannerProxy()
{
    Clear();
}

// @0x140892250
void CUgcShopBannerProxy::Clear()
{
    m_strKey.Empty();
}

// @0x140892280
int CUgcShopBannerProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcShopBannerProxy* pSrc = static_cast<const CUgcShopBannerProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_strKey = pSrc->m_strKey;
    m_strEntity = pSrc->m_strEntity;
    return 1;
}

// @0x140892310
void CUgcShopBannerProxy::Write(COutputStream& stream) const
{
    stream.WriteUnicodeStringA(m_strKey);
}

// @0x140892350
void CUgcShopBannerProxy::Read(CInPacket& packet)
{
    m_strKey = packet.ReadUnicodeStringA();
}

// @0x1408923d0
CBlueprintItemData::CBlueprintItemData()
{
    Clear();
}

// @0x140892430
CBlueprintItemData::~CBlueprintItemData()
{
}

// @0x140892470
void CBlueprintItemData::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_n28 = 0;
    m_n30 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_n48 = 0;
    m_strName = L"";
}

// @0x140892510
void CBlueprintItemData::CopyFrom(const CBlueprintItemData& other)
{
    m_n18 = other.m_n18;
    m_n20 = other.m_n20;
    m_n24 = other.m_n24;
    m_n28 = other.m_n28;
    m_n30 = other.m_n30;
    m_n38 = other.m_n38;
    m_n40 = other.m_n40;
    m_n48 = other.m_n48;
    m_strName = other.m_strName;
}

// @0x1408925d0
void CBlueprintItemData::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteInt32(m_n20);
    stream.WriteInt32(m_n24);
    stream.WriteInt32(m_n28);
    stream.WriteInt64(m_n30);
    stream.WriteInt32(m_n38);
    stream.WriteInt64(m_n40);
    stream.WriteInt64(m_n48);
    stream.WriteUnicodeString(m_strName);
}

// @0x1408926e0
void CBlueprintItemData::Read(CInputStream& stream)
{
    m_n18 = stream.ReadInt64();
    m_n20 = stream.ReadInt32();
    m_n24 = stream.ReadInt32();
    m_n28 = stream.ReadInt32();
    m_n30 = stream.ReadInt64();
    m_n38 = stream.ReadInt32();
    m_n40 = stream.ReadInt64();
    m_n48 = stream.ReadInt64();
    m_strName = stream.ReadUnicodeString();
}

// @0x140892810
CUgcBlueprintImageProxy::CUgcBlueprintImageProxy()
{
    Clear();
}

// @0x140892870
CUgcBlueprintImageProxy::~CUgcBlueprintImageProxy()
{
    Clear();
}

// @0x1408928d0
void CUgcBlueprintImageProxy::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n28 = 0;
    m_strName = L"";
}

// @0x140892930
int CUgcBlueprintImageProxy::CopyFrom(const IUgcProxy* pOther)
{
    if (pOther == 0)
        return 0;
    const CUgcBlueprintImageProxy* pSrc = static_cast<const CUgcBlueprintImageProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_n18 = pSrc->m_n18;
    m_n20 = pSrc->m_n20;
    m_n28 = pSrc->m_n28;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x1408929c0
void CUgcBlueprintImageProxy::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteInt64(m_n20);
    stream.WriteInt32(m_n28);
    stream.WriteUnicodeString(m_strName);
}

// @0x140892a50
void CUgcBlueprintImageProxy::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    m_n20 = packet.ReadInt64();
    m_n28 = packet.ReadInt32();
    m_strName = packet.ReadUnicodeString();
}

// @0x140892b50
CUgcItemLook::CUgcItemLook()
{
    Clear();
}

// @0x140892bf0
CUgcItemLook::~CUgcItemLook()
{
}

// @0x140892c70
void CUgcItemLook::Clear()
{
    m_n18 = 0;
    m_str20 = "";
    m_str28 = L"";
    m_n30 = 0;
    m_n34 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_str48 = L"";
    m_n50 = 0;
    m_strUrl = "";
    m_n60 = 0;
}

// @0x140892d40
void CUgcItemLook::SetDefault()
{
    m_n18 = 1;
    m_n30 = 0;
    m_str28 = "";
    m_strUrl = "";
}

// @0x140892da0
void CUgcItemLook::CopyFrom(const CUgcItemLook* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_str20 = pOther->m_str20;
    m_str28 = pOther->m_str28;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
    m_n38 = pOther->m_n38;
    m_n40 = pOther->m_n40;
    m_str48 = pOther->m_str48;
    m_n50 = pOther->m_n50;
    m_strUrl = pOther->m_strUrl;
    m_n60 = pOther->m_n60;
}

// @0x140892ec0
CStringA CUgcItemLook::GetLocalPath() const
{
    CStringA strResult("");
    if (m_n30 != 0)
    {
        if (m_strUrl.Find("item/", 0) >= 0)
            strResult = FUN_1410280d0(0xc9, m_strUrl);
        else if (m_strUrl.Find("blueprint/", 0) >= 0)
            strResult = FUN_1410280d0(0xd1, m_strUrl);
    }
    return strResult;
}

// @0x140893070
void CUgcItemLook::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteUnicodeStringA(m_str20);
    stream.WriteUnicodeString(m_str28);
    stream.WriteUInt8((unsigned char)m_n30);
    stream.WriteInt32(m_n34);
    stream.WriteInt64(m_n38);
    stream.WriteInt64(m_n40);
    stream.WriteUnicodeString(m_str48);
    stream.WriteInt64(m_n50);
    if (m_n60 == 1)
    {
        {
            CStringA strEmpty("");
            stream.WriteUnicodeStringA(strEmpty);
        }
        stream.WriteUInt8((unsigned char)m_n60);
    }
    else
    {
        CStringA strUrl(m_strUrl);
        unsigned char nFlag = (unsigned char)m_n60;
        stream.WriteUnicodeStringA(strUrl);
        stream.WriteUInt8(nFlag);
    }
}

// @0x140893250
void CUgcItemLook::Read(CInputStream& stream)
{
    Clear();
    m_n18 = stream.ReadInt64();
    m_str20 = stream.ReadUnicodeStringA();
    m_str28 = stream.ReadUnicodeString();
    m_n30 = stream.ReadUInt8();
    m_n34 = stream.ReadInt32();
    m_n38 = stream.ReadInt64();
    m_n40 = stream.ReadInt64();
    m_str48 = stream.ReadUnicodeString();
    m_n50 = stream.ReadInt64();
    m_strUrl = stream.ReadUnicodeStringA();
    m_n60 = stream.ReadUInt8();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
        m_strUrl = "";
}

// @0x1408934f0
int CUgcItemLook::FUN_1408934f0() const
{
    if (m_n18 == 1 || m_n60 == 1)
        return 1;
    return 0;
}

// @0x140893520
int CUgcItemLook::FUN_140893520() const
{
    if (m_n60 == 2)
        return 1;
    return 0;
}

// @0x140893540
bool CUgcItemLook::FUN_140893540() const
{
    if (FUN_1408934f0() != 0)
        return false;
    if ((unsigned __int64)m_n18 <= 1)
        return false;
    if (m_n30 == 0)
        return false;
    return true;
}

// @0x140893590
CUgcUpload::CUgcUpload()
{
    Clear();
}

// @0x140893600
CUgcUpload::~CUgcUpload()
{
    Clear();
}

// @0x140893670
void CUgcUpload::Clear()
{
    m_nKind = 0;
    m_n1c = 2;
    static_cast<IUgcProxy&>(m_user).Clear();
    static_cast<IUgcProxy&>(m_upload).Clear();
}

// @0x1408936e0
int CUgcUpload::CopyFrom(const CUgcUpload* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    m_nKind = pOther->m_nKind;
    static_cast<IUgcProxy&>(m_user).CopyFrom(&pOther->m_user);
    static_cast<IUgcProxy&>(m_upload).CopyFrom(&pOther->m_upload);
    return 1;
}

// @0x140893780
void CUgcUpload::Write(COutputStream& stream) const
{
    stream.WriteUInt8((unsigned char)m_nKind);
    stream.WriteInt16((short)m_n1c);
    static_cast<const IUgcProxy&>(m_user).Write(stream);
    static_cast<const IUgcProxy&>(m_upload).Write(stream);
}

// @0x140893820
void CUgcUpload::Read(CInPacket& packet)
{
    Unk_1402c45d0 checker;
    m_nKind = FUN_140898b80(packet, checker);
    m_n1c = (unsigned short)packet.ReadInt16();
    static_cast<IUgcProxy&>(m_user).Read(packet);
    static_cast<IUgcProxy&>(m_upload).Read(packet);
}

// @0x1408938d0
CUgcItemMusicNote::CUgcItemMusicNote()
{
    Clear();
}

// @0x140893970
CUgcItemMusicNote::~CUgcItemMusicNote()
{
}

// @0x1408939f0
void CUgcItemMusicNote::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_str28.Empty();
    m_str30.Empty();
    m_str38.Empty();
    m_info.m_n00 = 0;
    m_info.m_n08 = 0;
    m_info.m_n10 = 0;
    m_info.m_str18.Empty();
}

// @0x140893aa0
void CUgcItemMusicNote::CopyFrom(const CUgcItemMusicNote* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n20 = pOther->m_n20;
    m_n24 = pOther->m_n24;
    m_str28 = pOther->m_str28;
    m_str30 = pOther->m_str30;
    m_str38 = pOther->m_str38;
    m_info.m_n00 = pOther->m_info.m_n00;
    m_info.m_n08 = pOther->m_info.m_n08;
    m_info.m_n10 = pOther->m_info.m_n10;
    m_info.m_str18 = pOther->m_info.m_str18;
}

// MS2-FUNCTIONAL: early-return layout differs
// @0x140893bb0
void CUgcItemMusicNote::FUN_140893bb0(const void* pSource, __int64 nId)
{
    Clear();
    const Unk_MusicSrcView* pSrc = (const Unk_MusicSrcView*)pSource;
    if (pSrc == 0)
        return;
    m_n18 = nId;
    m_n20 = pSrc->m_n18;
    m_n24 = pSrc->m_n1c;
    m_str28 = pSrc->m_str20;
    m_str30 = pSrc->m_str28;
    m_str38 = pSrc->m_str30;
    m_info.m_n00 = pSrc->m_n50;
    m_info.m_n08 = pSrc->m_n58;
    m_info.m_n10 = pSrc->m_n60;
    m_info.m_str18 = pSrc->m_str68;
}

// @0x140893cc0
void CUgcItemMusicNote::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteInt32(m_n20);
    stream.WriteInt32(m_n24);
    stream.WriteUnicodeString(m_str28);
    stream.WriteUnicodeString(m_str30);
    stream.WriteString(m_str38);
    stream.WriteInt32(m_info.m_n00);
    stream.WriteInt64(m_info.m_n08);
    stream.WriteInt64(m_info.m_n10);
    stream.WriteUnicodeString(m_info.m_str18);
}

// @0x140893e10
void CUgcItemMusicNote::Read(CInputStream& stream)
{
    Clear();
    m_n18 = stream.ReadInt64();
    m_n20 = stream.ReadInt32();
    m_n24 = stream.ReadInt32();
    m_str28 = stream.ReadUnicodeString();
    m_str30 = stream.ReadUnicodeString();
    m_str38 = stream.ReadString();
    m_info.m_n00 = stream.ReadInt32();
    m_info.m_n08 = stream.ReadInt64();
    m_info.m_n10 = stream.ReadInt64();
    m_info.m_str18 = stream.ReadUnicodeString();
}

// @0x140894060
CStringA CUgcItemMusicNote::FUN_140894060() const
{
    MS2Ptr<Unk_MusicBookInfo> spInfo = FUN_14052d1d0()->FUN_14072cc10(m_n24);
    if ((Unk_MusicBookInfo*)spInfo != 0)
    {
        return CStringA(spInfo->m_str28);
    }
    return CStringA("");
}

// @0x140894120
CUgcMarketSchCond::CUgcMarketSchCond()
{
    Clear();
}

// @0x140894180
CUgcMarketSchCond::CUgcMarketSchCond(CInPacket& packet)
{
    Read(packet);
}

// @0x1408941f0
CUgcMarketSchCond::~CUgcMarketSchCond()
{
    Clear();
}

// @0x140894250
void CUgcMarketSchCond::Clear()
{
    m_n18 = 0;
    m_n1c = 2;
    m_n20 = 0;
    m_str28 = "";
    m_n30 = 0;
    m_n34 = 0;
}

// @0x1408942c0
void CUgcMarketSchCond::CopyFrom(const CUgcMarketSchCond* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n1c = pOther->m_n1c;
    m_n20 = pOther->m_n20;
    m_str28 = pOther->m_str28;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
}

// @0x140894360
void CUgcMarketSchCond::Write(COutputStream& stream) const
{
    stream.WriteInt32(m_n18);
    stream.WriteUInt8((unsigned char)m_n1c);
    stream.WriteUInt8((unsigned char)m_n20);
    stream.WriteUnicodeString(m_str28);
    stream.WriteInt32(m_n30);
    stream.WriteUInt8((unsigned char)m_n34);
}

// @0x140894420
void CUgcMarketSchCond::Read(CInPacket& packet)
{
    Clear();
    m_n18 = packet.ReadInt32();
    m_n1c = packet.ReadUInt8();
    m_n20 = packet.ReadUInt8();
    m_str28 = packet.ReadUnicodeString();
    m_n30 = packet.ReadInt32();
    m_n34 = packet.ReadUInt8();
}

// @0x1408945c0
void CUgcMarketSchCond::WriteShort(COutputStream& stream) const
{
    stream.WriteInt32(m_n18);
    stream.WriteUInt8((unsigned char)m_n1c);
    stream.WriteUInt8((unsigned char)m_n20);
    stream.WriteUnicodeString(m_str28);
    stream.WriteInt32(m_n30);
}

// @0x140894670
void CUgcMarketSchCond::ReadShort(CInputStream& stream)
{
    Clear();
    m_n18 = stream.ReadInt32();
    m_n1c = stream.ReadUInt8();
    m_n20 = stream.ReadUInt8();
    m_str28 = stream.ReadUnicodeString();
    m_n30 = stream.ReadInt32();
}

// @0x140894750
int CUgcMarketSchCond::FUN_140894750() const
{
    if (m_n30 == 0)
        return -1;
    int nIndex = m_n30 - 1;
    int nPage = nIndex / 10;
    return nPage;
}

// @0x1408947a0
int CUgcMarketSchCond::FUN_1408947a0() const
{
    int nPage = FUN_140894750();
    if (nPage == -1)
        return 0;
    int nPerPage = 0x78;
    int nStart = nPage * nPerPage + 1;
    return nStart;
}

// @0x1408947f0
int CUgcMarketSchCond::FUN_1408947f0() const
{
    int nPage = FUN_140894750();
    if (nPage == -1)
        return 0;
    int nPerPage = 0x78;
    int nEnd = (nPage + 1) * nPerPage;
    return nEnd;
}

// @0x140894840
int CUgcMarketSchCond::FUN_140894840() const
{
    if (m_n30 == 0)
        return -1;
    int nIndex = m_n30 - 1;
    int nBlock = nIndex / 0x32;
    int nPerBlock = 600;
    int nEnd = (nBlock + 1) * nPerBlock;
    return nEnd;
}

// @0x1408948a0
CStringA CUgcMarketSchCond::FUN_1408948a0() const
{
    if (m_n20 < 0 || m_n20 >= 6)
        return CStringA("");
    CStringA strName(s_orderNames[m_n20]);
    return strName;
}

// @0x140894960
int CUgcMarketSchCond::FUN_140894960() const
{
    int nValue = 0;
    nValue = m_n18;
    return nValue;
}

// @0x140894990
int CUgcMarketSchCond::FUN_140894990() const
{
    int nResult = 0;
    switch (m_n18)
    {
    case 100:
        nResult = 199;
        break;
    case 200:
        nResult = 299;
        break;
    case 300:
        nResult = 399;
        break;
    case 400:
        nResult = 499;
        break;
    default:
        nResult = m_n18;
        break;
    }
    return nResult;
}

// @0x140894a10
int CUgcMarketSchCond::FUN_140894a10(const CUgcMarketSchCond* pOther) const
{
    if (pOther == 0)
        return 0;
    if (pOther->m_n18 != m_n18)
        return 0;
    if (pOther->m_n1c != m_n1c)
        return 0;
    if (pOther->m_n20 != m_n20)
        return 0;
    if (FUN_140164830(pOther->m_str28, m_str28))
        return 0;
    if (pOther->FUN_140894840() > pOther->FUN_140894840())
        return 0;
    return 1;
}

// @0x140894ad0
CUgcMarketProduct::CUgcMarketProduct()
{
    Clear();
}

// @0x140894bc0
CUgcMarketProduct::~CUgcMarketProduct()
{
    Clear();
}

// @0x140894cb0
void CUgcMarketProduct::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n28 = 0;
    m_n2c = 0;
    m_n30 = 0;
    m_n34 = 3;
    m_n38 = 0;
    m_n50 = 0;
    m_n3c = 0;
    m_n40 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n58 = 0;
    m_n60 = 0;
    m_n68 = 0;
    m_n70 = 0;
    m_n80 = 0;
    m_n88 = 0;
    m_n78 = 0;
    static_cast<IUgcProxy&>(m_user).Clear();
    m_str200 = "";
    m_str208 = "";
    m_str210 = "";
    m_look.Clear();
    m_music.Clear();
    m_blueprint.Clear();
    m_n1f0 = 0;
    m_n1f4 = 0;
    m_n1f8 = 1;
}

// @0x140894ea0
void CUgcMarketProduct::CopyFrom(const CUgcMarketProduct* pOther)
{
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n20 = pOther->m_n20;
    m_n28 = pOther->m_n28;
    m_n2c = pOther->m_n2c;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
    m_n38 = pOther->m_n38;
    m_n50 = pOther->m_n50;
    m_n3c = pOther->m_n3c;
    m_n40 = pOther->m_n40;
    m_n44 = pOther->m_n44;
    m_n48 = pOther->m_n48;
    m_n58 = pOther->m_n58;
    m_n60 = pOther->m_n60;
    m_n68 = pOther->m_n68;
    m_n70 = pOther->m_n70;
    m_n80 = pOther->m_n80;
    m_n88 = pOther->m_n88;
    m_n78 = pOther->m_n78;
    static_cast<IUgcProxy&>(m_user).CopyFrom(&pOther->m_user);
    SetStr200(CStringW(pOther->m_str200));
    SetStr208(CStringW(pOther->m_str208));
    SetStr210(CStringW(pOther->m_str210));
    m_look.CopyFrom(&pOther->m_look);
    m_music.CopyFrom(&pOther->m_music);
    m_blueprint.CopyFrom(pOther->m_blueprint);
    m_n1f4 = pOther->m_n1f4;
    m_n1f8 = pOther->m_n1f8;
}

// @0x140895230
void CUgcMarketProduct::Write(COutputStream& stream) const
{
    stream.WriteInt32(m_n18);
    stream.WriteInt64(m_n20);
    stream.WriteUInt8((unsigned char)m_n28);
    stream.WriteInt32(m_n2c);
    stream.WriteInt32(m_n30);
    stream.WriteUInt8((unsigned char)m_n34);
    stream.WriteInt32(m_n38);
    stream.WriteInt64(m_n50);
    stream.WriteInt32(m_n3c);
    stream.WriteInt32(m_n40);
    stream.WriteInt32(m_n44);
    stream.WriteInt32(m_n48);
    stream.WriteInt64(m_n58);
    stream.WriteInt64(m_n60);
    stream.WriteInt64(m_n68);
    stream.WriteInt32(m_n70);
    stream.WriteInt64(m_n80);
    stream.WriteInt64(m_n88);
    stream.WriteInt64(m_n78);
    m_user.Write(stream);
    stream.WriteUnicodeString(const_cast<CUgcMarketProduct*>(this)->GetStr200());
    stream.WriteUnicodeString(const_cast<CUgcMarketProduct*>(this)->GetStr208());
    stream.WriteUnicodeString(const_cast<CUgcMarketProduct*>(this)->GetStr210());
    m_look.Write(stream);
    m_music.Write(stream);
    m_blueprint.Write(stream);
    stream.WriteUInt8((unsigned char)m_n1f4);
}

// @0x140895670
void CUgcMarketProduct::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt32();
    m_n20 = packet.ReadInt64();
    m_n28 = packet.ReadUInt8();
    m_n2c = packet.ReadInt32();
    m_n30 = packet.ReadInt32();
    m_n34 = packet.ReadUInt8();
    m_n38 = packet.ReadInt32();
    m_n50 = packet.ReadInt64();
    m_n3c = packet.ReadInt32();
    m_n40 = packet.ReadInt32();
    m_n44 = packet.ReadInt32();
    m_n48 = packet.ReadInt32();
    m_n58 = packet.ReadInt64();
    m_n60 = packet.ReadInt64();
    m_n68 = packet.ReadInt64();
    m_n70 = packet.ReadInt32();
    m_n80 = packet.ReadInt64();
    m_n88 = packet.ReadInt64();
    m_n78 = packet.ReadInt64();
    m_user.Read(packet);
    CStringW strValue;
    strValue = packet.ReadUnicodeString();
    SetStr200(CStringW(strValue));
    strValue = packet.ReadUnicodeString();
    SetStr208(CStringW(strValue));
    strValue = packet.ReadUnicodeString();
    SetStr210(CStringW(strValue));
    m_look.Read(packet);
    m_music.Read(packet);
    m_blueprint.Read(packet);
    m_n1f4 = packet.ReadUInt8();
    m_n1f8 = FUN_1406a5390(m_n2c);
}

// @0x140895dd0
CStringW CUgcMarketProduct::GetStr200()
{
    Unk_PetLock lock(m_lock, 1);
    return CStringW(m_str200);
}

// @0x140895e50
void CUgcMarketProduct::SetStr200(CStringW str)
{
    Unk_PetLock lock(m_lock, 1);
    m_str200 = str;
}

// @0x140895ed0
CStringW CUgcMarketProduct::GetStr200Head()
{
    CStringW str = GetStr200();
    int nPos = str.ReverseFind(L',');
    if (nPos != -1)
    {
        int nLen = str.GetLength();
        int nCount;
        if (nLen - nPos < 0)
            nCount = 0;
        else
            nCount = nLen - nPos;
        str.Delete(nPos, nCount);
    }
    return CStringW(str);
}

// @0x140895fa0
CStringW CUgcMarketProduct::GetStr208()
{
    Unk_PetLock lock(m_lock, 1);
    return CStringW(m_str208);
}

// @0x140896020
void CUgcMarketProduct::SetStr208(CStringW str)
{
    Unk_PetLock lock(m_lock, 1);
    m_str208 = str;
}

// @0x1408960a0
CStringW CUgcMarketProduct::GetStr210()
{
    Unk_PetLock lock(m_lock, 1);
    return CStringW(m_str210);
}

// @0x140896120
void CUgcMarketProduct::SetStr210(CStringW str)
{
    Unk_PetLock lock(m_lock, 1);
    m_str210 = str;
}

// @0x1408961a0
int CUgcMarketProduct::FUN_1408961a0() const
{
    if (m_n88 > 0 && m_n88 > FUN_140869440())
        return 1;
    return 0;
}

// @0x1408961e0
int CUgcMarketProduct::FUN_1408961e0() const
{
    __int64 nNow = FUN_140869440();
    if (nNow < m_n58 || nNow > m_n68)
        return 0;
    return 1;
}

// @0x140896230
bool CUgcMarketProduct::FUN_140896230(Unk_CommonOwner& owner)
{
    if (owner.id == 0)
        return false;
    if (FUN_140896310() != 0)
    {
        if (owner.Matches(m_music.m_info.m_n00, m_music.m_info.m_n08))
            return true;
    }
    else if (FUN_140896350() != 0)
    {
        if (owner.Matches(m_blueprint.m_n38, m_blueprint.m_n40))
            return true;
    }
    else
    {
        if (owner.Matches(m_look.m_n34, m_look.m_n38))
            return true;
    }
    return false;
}

// @0x140896310
int CUgcMarketProduct::FUN_140896310() const
{
    int nLast = 499;
    if (m_n30 >= 400 && m_n30 <= nLast)
        return 1;
    return 0;
}

// @0x140896350
int CUgcMarketProduct::FUN_140896350() const
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_n2c);
    if ((bool)spData.get() && spData->FUN_14053d900())
        return 1;
    return 0;
}

// @0x1408963f0
bool CUgcMarketProduct::FUN_1408963f0(Unk_CommonOwner& owner)
{
    return !FUN_140896230(owner) && FUN_1406a5800();
}

// @0x140896450
CUgcMarketSeller::CUgcMarketSeller()
{
    Clear();
}

// @0x1408964c0
CUgcMarketSeller::~CUgcMarketSeller()
{
    Clear();
}

// @0x140896530
void CUgcMarketSeller::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_strName = "";
    m_n30 = 0;
    static_cast<IUgcProxy&>(m_user).Clear();
    m_n78 = 0;
    m_n80 = 0;
    m_n88 = 0;
    m_n90 = 0;
}

// @0x1408965f0
void CUgcMarketSeller::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteInt64(m_n20);
    stream.WriteUnicodeString(m_strName);
    stream.WriteInt32(m_n30);
    m_user.Write(stream);
    stream.WriteInt32(m_n78);
    stream.WriteInt64(m_n80);
    stream.WriteInt64(m_n88);
    stream.WriteInt64(m_n90);
}

// @0x140896710
void CUgcMarketSeller::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    m_n20 = packet.ReadInt64();
    m_strName = packet.ReadUnicodeString();
    m_n30 = packet.ReadInt32();
    m_user.Read(packet);
    m_n78 = packet.ReadInt32();
    m_n80 = packet.ReadInt64();
    m_n88 = packet.ReadInt64();
    m_n90 = packet.ReadInt64();
}

// @0x140896940
CUgcBookMark::CUgcBookMark()
{
    m_n18 = 0;
    m_n20 = 0;
    m_strName.Empty();
    m_strUrl = "";
}

// @0x1408969f0
CUgcBookMark::~CUgcBookMark()
{
}

// @0x140896a50
void CUgcBookMark::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteInt64(m_n20);
    stream.WriteUnicodeString(m_strName);
    stream.WriteUnicodeStringA(m_strUrl);
}

// @0x140896af0
void CUgcBookMark::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    m_n20 = packet.ReadInt64();
    m_strName = packet.ReadUnicodeString();
    m_strUrl = packet.ReadUnicodeStringA();
}

// @0x140897010
RideeItemInfo::RideeItemInfo()
{
    Clear();
}

// @0x140897070
RideeItemInfo::RideeItemInfo(const RideeItemInfo* pOther)
{
    Clear();
    CopyFrom(pOther);
}

// @0x1408970e0
RideeItemInfo::RideeItemInfo(int nId, __int64 nUid, const CUgcItemLook* pLook)
{
    Clear();
    m_nId = nId;
    m_nUid = nUid;
    m_look.CopyFrom(pLook);
}

// @0x140897180
RideeItemInfo::RideeItemInfo(CInPacket& packet)
{
    Read(packet);
}

// @0x1408971f0
RideeItemInfo::~RideeItemInfo()
{
    Clear();
}

// @0x140897250
void RideeItemInfo::CopyFrom(const RideeItemInfo* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_nId = pOther->m_nId;
    m_nUid = pOther->m_nUid;
    m_look.CopyFrom(&pOther->m_look);
}

// @0x1408972c0
void RideeItemInfo::Clear()
{
    m_nId = 0;
    m_nUid = 0;
    m_look.Clear();
}

// @0x140897300
int RideeItemInfo::IsValid() const
{
    if (m_nId != 0 && m_look.m_n18 != 0)
        return 1;
    return 0;
}

// @0x140897330
int RideeItemInfo::Equals(const RideeItemInfo* pOther) const
{
    if (pOther == 0)
        return 0;
    if (IsValid() == 0)
    {
        if (pOther->IsValid() == 1)
            return 0;
        if (pOther->m_nId == m_nId)
            return 1;
        return 0;
    }
    else
    {
        if (pOther->IsValid() == 0)
            return 0;
        if (m_nId != pOther->m_nId)
            return 0;
        if (m_look.m_n18 != pOther->m_look.m_n18)
            return 0;
        return 1;
    }
}

// @0x1408973e0
void RideeItemInfo::Write(COutputStream& stream) const
{
    stream.WriteInt32(m_nId);
    stream.WriteInt64(m_nUid);
    m_look.Write(stream);
}

// @0x140897440
void RideeItemInfo::Read(CInPacket& packet)
{
    Clear();
    m_nId = packet.ReadInt32();
    m_nUid = packet.ReadInt64();
    m_look.Read(packet);
}


// A string with a one byte flag (no RTTI).
struct Unk_StrFlag
{
    void Write(COutputStream& stream) const;
    void Read(CInputStream& stream);
    CStringW m_str;                                         // +0x00
    int m_nFlag;                                            // +0x08
};

// @0x1408974e0
void Unk_StrFlag::Write(COutputStream& stream) const
{
    stream.WriteUnicodeString(m_str);
    stream.WriteUInt8((unsigned char)m_nFlag);
}

// @0x140897540
void Unk_StrFlag::Read(CInputStream& stream)
{
    m_str = stream.ReadUnicodeString();
    m_nFlag = stream.ReadUInt8();
}

void FUN_140274fc0(CStringW& str, ATL::CAtlArray<unsigned>& out, const wchar_t* pszSep);

// @0x1408975c0
CUgcBannerRollingImage::CUgcBannerRollingImage()
{
    Clear();
}

// @0x140897680
CUgcBannerRollingImage::~CUgcBannerRollingImage()
{
    Clear();
}

// @0x140897740
int CUgcBannerRollingImage::FUN_140897740()
{
    m_strIds.Trim();
    ATL::CAtlArray<unsigned> ids;
    FUN_140274fc0(m_strIds, ids, L",");
    int nCount = (int)ids.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        unsigned nId = ids[i];
        m_idSet.insert(nId);
        Unk_BannerPtr banner = CFieldBannerData::GetBanner(nId);
        if (banner.get() != 0)
            m_fieldSet.insert(banner->m_nField);
        else
            MS2_ASSERT_AT(0xdc5, FALSE);
    }
    return 1;
}

// @0x1408978a0
void CUgcBannerRollingImage::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n30 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_str48.Empty();
    m_str58.Empty();
    m_str50.Empty();
    m_fieldSet.clear();
}

// @0x140897940
void CUgcBannerRollingImage::Write(COutputStream& stream) const
{
    stream.WriteInt64(m_n18);
    stream.WriteUnicodeString(m_strIds);
    stream.WriteUInt8((unsigned char)m_n20);
    stream.WriteInt32(m_n30);
    stream.WriteInt64(m_n38);
    stream.WriteInt64(m_n40);
    stream.WriteUnicodeStringA(m_str48);
    stream.WriteUnicodeString(m_str50);
    stream.WriteUnicodeString(m_str58);
}

// @0x140897a70
void CUgcBannerRollingImage::Read(CInPacket& packet)
{
    Clear();
    m_n18 = packet.ReadInt64();
    m_strIds = packet.ReadUnicodeString();
    m_n20 = packet.ReadUInt8();
    m_n30 = packet.ReadInt32();
    m_n38 = packet.ReadInt64();
    m_n40 = packet.ReadInt64();
    m_str48 = packet.ReadUnicodeStringA();
    m_str50 = packet.ReadUnicodeString();
    m_str58 = packet.ReadUnicodeString();
}

// @0x140897d70
int CUgcBannerRollingImage::FUN_140897d70(__int64 nTime) const
{
    if (m_n38 == 0 || m_n40 == 0)
        return 0;
    if (nTime < m_n38 || nTime > m_n40)
        return 0;
    return 1;
}

// @0x140897dd0
int CUgcBannerRollingImage::FUN_140897dd0(unsigned nId) const
{
    if (m_idSet.find(nId) != m_idSet.end())
        return 1;
    return 0;
}

// @0x140897e40
int CUgcBannerRollingImage::FUN_140897e40(unsigned nField) const
{
    if (m_fieldSet.empty())
        return 1;
    if (m_fieldSet.find(nField) != m_fieldSet.end())
        return 1;
    return 0;
}

// @0x140897ed0
TUgcGetCostInfo::TUgcGetCostInfo()
{
    m_nBase = 0;
    m_nCost = 0;
    m_nLeft = 0;
}

// @0x140897f30
void TUgcGetCostInfo::FUN_140897f30(__int64 nBase, int nPercent)
{
    m_nBase = nBase;
    m_nCost = (nBase * nPercent) / 100;
    m_nLeft = 100 - nPercent;
}

// The exe instantiates this 3-argument form against its own copy of the formatter (the one the socket code uses).
CStringA FUN_1402bf9a0(const char* format, const fmt::ArgList& args);
// @0x140898c00
template<> CString StringFormat<__int64, __int64, int>(const char* format, const __int64& first, const __int64& second,
                                                      const int& third)
{
    const fmt::internal::ArgArray<3>::Type array = {fmt::internal::MakeValue<fmt::BasicFormatter<char>>(first),
                                                  fmt::internal::MakeValue<fmt::BasicFormatter<char>>(second),
                                                  fmt::internal::MakeValue<fmt::BasicFormatter<char>>(third)};
    return FUN_1402bf9a0(format, fmt::ArgList(fmt::internal::make_type(first, second, third), array));
}

// @0x140897f90
CString TUgcGetCostInfo::FUN_140897f90() const
{
    return StringFormat("[{0}->{1}({2}%%)]", m_nBase, m_nCost, m_nLeft);
}

// @0x140898780
UGCMapDesignInfo::UGCMapDesignInfo()
{
    m_nId = 0;
    m_strName.Empty();
    m_nTime = 0;
}

// @0x1408987f0
UGCMapBlueprintInfo::UGCMapBlueprintInfo()
{
    m_nId = 0;
    m_strName.Empty();
    m_nTime = 0;
}

// @0x140898b80
unsigned char FUN_140898b80(CInPacket& packet, Unk_1402c45d0 checker)
{
    unsigned char nValue = packet.ReadUInt8();
    if (!checker.Check(nValue))
        throw Exception(13);
    return nValue;
}

// @0x140898000
CUgcGetCostTable::CUgcGetCostTable()
    : m_table(10)
{
}

// @0x140898070
CUgcGetCostTable::~CUgcGetCostTable()
{
    m_table.RemoveAll();
}

// @0x1408980d0
void CUgcGetCostTable::SetTable(const CostMap& src)
{
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        m_table.RemoveAll();
        for (POSITION pos = src.GetHeadPosition(); pos != NULL; src.GetNext(pos))
        {
            const int* pnPercent = &src.GetValueAt(pos);
            m_table.SetAt(src.GetKeyAt(pos), *pnPercent);
        }
    }
}

// MS2-FUNCTIONAL: map accessor call order / this materialisation
// @0x1408981a0
void CUgcGetCostTable::GetTable(CostMap& dst)
{
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        dst.RemoveAll();
        for (POSITION pos = m_table.GetHeadPosition(); pos != NULL; m_table.GetNext(pos))
        {
            const int* pnPercent = &m_table.GetValueAt(pos);
            dst.SetAt(m_table.GetKeyAt(pos), *pnPercent);
        }
    }
}

// MS2-FUNCTIONAL: stack frame 0x10 larger than the exe
// @0x140898280
void CUgcGetCostTable::Write(COutputStream& stream)
{
    CostMap table(10);
    GetTable(table);
    stream.WriteInt32((int)table.GetCount());
    for (POSITION pos = table.GetHeadPosition(); pos != NULL; table.GetNext(pos))
    {
        __int64 nKey = table.GetKeyAt(pos);
        int nPercent = table.GetValueAt(pos);
        stream.WriteInt64(nKey);
        stream.WriteInt32(nPercent);
    }
}

// @0x140898390
void CUgcGetCostTable::Read(CInPacket& packet)
{
    CostMap table(10);
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nKey = packet.ReadInt64();
        int nPercent = packet.ReadInt32();
        table.SetAt(nKey, nPercent);
    }
    SetTable(table);
}

// MS2-FUNCTIONAL: stack frame and loop shape differ from the exe
// Blueprint fee currency selector (unit-local view of the fee object; its owner unit is uiitemblueprintcreatedialog.cpp)
enum Unk_BpCurrency { Unk_BpCurrency_Default = 1 };
class Unk_140166410_Opt { public: bool FUN_14036d710(int); };
Unk_140166410_Opt* FUN_140166410();
class Unk_BpFee
{
public:
    Unk_BpCurrency FUN_14089e200();     // 0x14089e200

    char m_pad[0x24];
    int m_currency;                     // +0x24
};

// @0x14089e200
Unk_BpCurrency Unk_BpFee::FUN_14089e200()
{
    if (FUN_140166410()->FUN_14036d710(0x62))
    {
        if (m_currency == 3)
            return (Unk_BpCurrency)10;
    }
    else
    {
        if (m_currency == 10 || m_currency == 9)
            return (Unk_BpCurrency)3;
    }
    return (Unk_BpCurrency)m_currency;
}

// @0x1408984b0
bool CUgcGetCostTable::FUN_1408984b0(__int64 nStart, __int64 nLength, CostList& out)
{
    CostMap table(10);
    GetTable(table);
    POSITION posLast = NULL;
    __int64 nEnd = nStart + nLength;
    POSITION pos = table.GetHeadPosition();
    while (pos != NULL)
    {
        __int64 nKey = table.GetKeyAt(pos);
        if (nEnd < nKey)
        {
            posLast = pos;
            break;
        }
        posLast = pos;
        table.GetNext(pos);
    }
    if (posLast != NULL)
    {
        POSITION posCur = posLast;
        __int64 nLeft = nLength;
        while (posCur != NULL)
        {
            __int64 nKey = table.GetKeyAt(posCur);
            if (nKey <= nEnd)
            {
                __int64 nSpan = nEnd - nKey;
                if (nLeft < nSpan)
                    nSpan = nLeft;
                __int64 nPart = nSpan;
                int nPercent = table.GetValueAt(posCur);
                MS2Ptr<TUgcGetCostInfo> spInfo(new TUgcGetCostInfo);
                if (spInfo.get() != 0)
                {
                    spInfo->FUN_140897f30(nPart, nPercent);
                    out.Add(spInfo);
                }
                nEnd -= nPart;
                nLeft -= nPart;
                if (nLeft < 1)
                    return true;
            }
            table.GetPrev(posCur);
        }
    }
    return true;
}

// @0x1408999c0
TUgcGetCostInfo::~TUgcGetCostInfo()
{
}

// @0x1408999e0
UGCMapBlueprintInfo::~UGCMapBlueprintInfo()
{
}

// @0x140899a10
UGCMapDesignInfo::~UGCMapDesignInfo()
{
}

// @0x140896c50
CUgcCharBookMark::CUgcCharBookMark(MS2Ptr<Unk_CharBookMarkOwner> spOwner)
    : m_map(10)
{
    m_spOwner = spOwner;
    FUN_140896d90();
}

// @0x140896d00
CUgcCharBookMark::~CUgcCharBookMark()
{
    m_spOwner = 0;
    FUN_140896d90();
}

// @0x140896d90
void CUgcCharBookMark::FUN_140896d90()
{
    m_map.RemoveAll();
    m_list.RemoveAll();
}

// @0x140896dd0
void CUgcCharBookMark::FUN_140896dd0(MS2Ptr<Unk_MeratEquipEntry> spEntry)
{
    if (spEntry.get() != 0)
    {
        m_list.Add(spEntry);
        m_map.SetAt(spEntry->m_oid, spEntry);
    }
}

// @0x140896e50
void CUgcCharBookMark::FUN_140896e50(ATL::CAtlArray<MS2Ptr<Unk_MeratEquipEntry> >& out)
{
    out.Copy(m_list);
}

// @0x140896e80
MS2Ptr<Unk_MeratEquipEntry> CUgcCharBookMark::FUN_140896e80(const Unk_MeratOid& oid)
{
    MS2Ptr<Unk_MeratEquipEntry> spEntry(0);
    m_map.Lookup(oid, spEntry);
    return spEntry;
}

// @0x140896f00
MS2Ptr<Unk_MeratEquipEntry> CUgcCharBookMark::FUN_140896f00(__int64 nId)
{
    size_t nCount = m_list.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<Unk_MeratEquipEntry> spEntry = m_list[i];
        if (spEntry.get() != 0 && spEntry->m_nId == nId)
            return spEntry;
    }
    return MS2Ptr<Unk_MeratEquipEntry>(0);
}

// A zeroed 64-bit value and an int (no RTTI; the constructor only calls the initializer).
struct Unk_QuadInt
{
    Unk_QuadInt();
    void FUN_140898890();
    __int64 m_n00;
    int m_n08;
};

// @0x140898860
Unk_QuadInt::Unk_QuadInt()
{
    FUN_140898890();
}

// @0x140898890
void Unk_QuadInt::FUN_140898890()
{
    m_n00 = 0;
    m_n08 = 0;
}

// @0x1408988c0
void FUN_1408988c0(MS2Ptr<Unk_BasketNode> spNode, Unk_BasketSink& sink)
{
    if (spNode == 0)
        return;
    ATL::CAtlArray<CStringA> items;
    FUN_14028c700(spNode->m_strItems, items, ",");
    size_t nItems = items.GetCount();
    for (size_t i = 0; i < nItems; i++)
    {
        sink.FUN_1406ad840(items[i], spNode->m_nCount);
    }
}

// @0x1408989c0
void FUN_1408989c0(ATL::CAtlList<MS2Ptr<Unk_BasketNode> >& nodes, Unk_BasketSink& sink)
{
    for (POSITION pos = nodes.GetHeadPosition(); pos != NULL; nodes.GetNext(pos))
    {
        MS2Ptr<Unk_BasketNode> spNode = nodes.GetAt(pos);
        if (spNode == 0)
            continue;
        if (spNode->m_children.IsEmpty())
        {
            FUN_1408988c0(MS2Ptr<Unk_BasketNode>(spNode), sink);
        }
        else
        {
            ATL::CAtlList<MS2Ptr<Unk_BasketNode> >& children = spNode->m_children;
            for (POSITION posChild = children.GetHeadPosition(); posChild != NULL; children.GetNext(posChild))
            {
                MS2Ptr<Unk_BasketNode> spChild = children.GetAt(posChild);
                if (spChild == 0)
                    continue;
                FUN_1408988c0(MS2Ptr<Unk_BasketNode>(spChild), sink);
            }
        }
    }
}

// @0x14089b9d0 (glue: CAtlMap<CStringA,int>::IsEmpty)
template bool ATL::CAtlMap<CStringA, int, ATL::CStringElementTraits<CStringA>, ATL::CElementTraits<int> >::IsEmpty() const;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c760-0x142c9c850 .text$yd
