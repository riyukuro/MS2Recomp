// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The maid record CMaid and the maid tables CMaidExpTable
// (Table/MaidExp.xml), CMaidInfoTable (Table/MaidProperty.xml), CMaidDescTable (MaidPropertyString.xml) and
// CMaidManufactureMsgTable (MaidManufactureMessage.xml), see maid.h. File name assumed; the unit range holds two
// original TUs (CMaid up to its COMDAT tail at 0x14067e980, then the tables).
// MS2-UNIT: ?\maid.cpp
// MS2-RANGE: 0x1400bb240-0x1400bb3c0 .text$di
// MS2-RANGE: 0x14067c610-0x1406846a0 .text$mn
// MS2-RANGE: 0x142c9b5b0-0x142c9b610 .text$yd
// MS2-PIN: ??_7CMaidExpTable@@6B?$TSingleton@VCMaidExpTable@@@@@ 0x142d75260
// MS2-PIN: ??_7CMaidExpTable@@6B?$CValidData@VCMaidExpTable@@@@@ 0x142d75270
// MS2-PIN: ??_7CMaidInfoTable@@6B?$TSingleton@VCMaidInfoTable@@@@@ 0x142d752a0
// MS2-PIN: ??_7CMaidInfoTable@@6B?$CValidData@VCMaidInfoTable@@@@@ 0x142d752b0
// MS2-PIN: ??_7CMaidDescTable@@6B?$TSingleton@VCMaidDescTable@@@@@ 0x142d752e0
// MS2-PIN: ??_7CMaidDescTable@@6B?$CValidData@VCMaidDescTable@@@@@ 0x142d752f0
// MS2-PIN: ??_7CMaidManufactureMsgTable@@6B?$TSingleton@VCMaidManufactureMsgTable@@@@@ 0x142d75320
// MS2-PIN: ??_7CMaidManufactureMsgTable@@6B?$CValidData@VCMaidManufactureMsgTable@@@@@ 0x142d75330
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\maid.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#define MS2_TPTRVALUE_MOVE
#include "maid.h"
#include <algorithm>
#include <typeinfo>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/pricetable.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14071ae20(const CString& strFile);                          // the locale's string table path of <file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
__int64 GetServerTime();                                                // the server time
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                           // the item data of an id

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flags (symbols-manual.tsv); local copies stay false
bool CMaidExpTable::s_bInit;
bool CMaidInfoTable::s_bInit;
bool CMaidDescTable::s_bInit;
bool CMaidManufactureMsgTable::s_bInit;
#endif

// The market sort-key names of an included header, once per original TU (names invented).
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- MaidProfile ------------------------------------------------------------------------------------------------------

// @0x14067c610
void MaidProfile::Write(COutputStream* pStream)
{
    pStream->WriteUnicodeString(title);
    pStream->WriteUnicodeString(name);
    pStream->WriteUnicodeString(birthDay);
    pStream->WriteUnicodeString(constellation);
    pStream->WriteUnicodeString(height);
    pStream->WriteUnicodeString(weight);
    pStream->WriteUnicodeString(specialty);
    pStream->WriteUnicodeString(specialDetail);
    pStream->WriteUnicodeString(like);
    pStream->WriteUnicodeString(hate);
    pStream->WriteUnicodeString(hobby);
    pStream->WriteUnicodeString(ownerName);
    pStream->WriteUnicodeString(belongTo);
}
MS2_REPLACE_METHOD(0x14067C610, MaidProfile, Write, 638, 0xEC3841F5);

// @0x14067c8a0
void MaidProfile::Read(CInPacket* pPacket)
{
    title = pPacket->ReadUnicodeString();
    name = pPacket->ReadUnicodeString();
    birthDay = pPacket->ReadUnicodeString();
    constellation = pPacket->ReadUnicodeString();
    height = pPacket->ReadUnicodeString();
    weight = pPacket->ReadUnicodeString();
    specialty = pPacket->ReadUnicodeString();
    specialDetail = pPacket->ReadUnicodeString();
    like = pPacket->ReadUnicodeString();
    hate = pPacket->ReadUnicodeString();
    hobby = pPacket->ReadUnicodeString();
    ownerName = pPacket->ReadUnicodeString();
    belongTo = pPacket->ReadUnicodeString();
}
MS2_REPLACE_METHOD(0x14067C8A0, MaidProfile, Read, 1547, 0x80377201);

// @0x14067cec0
CStringW MaidProfile::Encode()
{
    CStringW strResult = StringFormat(L"{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12}", title, name,
        birthDay, constellation, height, weight, specialty, specialDetail, like, hate, hobby, ownerName, belongTo);
    return strResult;
}
MS2_REPLACE_METHOD(0x14067CEC0, MaidProfile, Encode, 359, 0x38524D44);

// ---- CMaid ------------------------------------------------------------------------------------------------------------

// @0x14067d030
CMaid::CMaid()
    : m_n18(0), m_nId(0), m_nItemId(0), m_nMaidId(0), m_t38(0), m_t40(0), m_nMode(0), m_n4c(0), m_nMood(0),
      m_nOrder(0), m_t58(0), m_nExp(0), m_nExpireTime(0)
{
}

// @0x14067d130
CMaid::CMaid(__int64 n18, unsigned __int64 nId, __int64 n28, int nItemId, __int64 nExpireTime)
    : m_n18(n18), m_nId(nId), m_n28(n28), m_nItemId(nItemId), m_nMode(0), m_nMood(0), m_nExp(0),
      m_nExpireTime(nExpireTime)
{
    m_t58 = m_t38 = m_t40 = GetServerTime();
    m_n4c = 1;
    m_nOrder = 1;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.get())
        m_nMaidId = spItem->FUN_14053dd30();
}

// @0x14067d2a0
CMaid::~CMaid()
{
}

// @0x14067d300
void CMaid::Update(MS2Ptr<CMaid> spMaid)
{
    m_n4c = spMaid->m_n4c;
    m_nMood = spMaid->m_nMood;
    m_nOrder = spMaid->m_nOrder;
    m_t58 = spMaid->m_t58;
    m_nExp = spMaid->m_nExp;
    m_nExpireTime = spMaid->m_nExpireTime;
    m_t38 = spMaid->m_t38;
    m_t40 = spMaid->m_t40;
    m_profile = spMaid->m_profile;
}
MS2_REPLACE_METHOD(0x14067D300, CMaid, Update, 257, 0xB89A19D2);

// @0x14067d410
void CMaid::SetProgress(int n4c, int nMood, int nLevel, __int64 t58, int nExp, __int64 nExpireTime, CStringA strList)
{
    m_n4c = n4c;
    m_nMood = nMood;
    m_nOrder = nLevel;
    m_t58 = t58;
    m_nExp = nExp;
    m_nExpireTime = nExpireTime;
    XmlSplit(strList, m_list, ",");
}
MS2_REPLACE_METHOD(0x14067D410, CMaid, SetProgress, 157, 0x7FC100C7);

// @0x14067d4c0
void CMaid::SetTimes(__int64 t38, __int64 t40)
{
    m_t38 = t38;
    m_t40 = t40;
}
MS2_REPLACE_METHOD(0x14067D4C0, CMaid, SetTimes, 44, 0x44861EA9);

// @0x14067d500
void CMaid::SetProfile(const MaidProfile& profile)
{
    m_profile = profile;
}
MS2_REPLACE_METHOD(0x14067D500, CMaid, SetProfile, 43, 0x8952A75E);

// @0x14067d540
void CMaid::Write(COutputStream* pStream)
{
    pStream->WriteInt64(m_n18);
    pStream->WriteInt64(m_nId);
    pStream->WriteInt64(m_t38);
    pStream->WriteInt64(m_t40);
    pStream->WriteInt64(m_n28);
    pStream->WriteInt32(m_nItemId);
    pStream->WriteInt32(m_nMaidId);
    pStream->WriteUInt8((unsigned char)m_n4c);
    pStream->WriteInt32(m_nMood);
    pStream->WriteInt32(m_nOrder);
    pStream->WriteInt32(m_nExp);
    pStream->WriteInt64(m_nExpireTime);
    pStream->WriteInt32((int)m_list.GetCount());
    for (size_t i = 0; i < m_list.GetCount(); i++)
        pStream->WriteInt32(m_list[i]);
    m_profile.Write(pStream);
}
MS2_REPLACE_METHOD(0x14067D540, CMaid, Write, 486, 0x80E1C333);

// @0x14067d730
void CMaid::ReadFromPacket(CInPacket* pPacket)
{
    m_n18 = pPacket->ReadInt64();
    m_nId = pPacket->ReadInt64();
    m_t38 = pPacket->ReadInt64();
    m_t40 = pPacket->ReadInt64();
    m_n28 = pPacket->ReadInt64();
    m_nItemId = pPacket->ReadInt32();
    m_nMaidId = pPacket->ReadInt32();
    m_n4c = pPacket->ReadUInt8();
    m_nMood = pPacket->ReadInt32();
    m_nOrder = pPacket->ReadInt32();
    m_nExp = pPacket->ReadInt32();
    m_nExpireTime = pPacket->ReadInt64();
    m_list.RemoveAll();
    size_t nCount = (unsigned)pPacket->ReadInt32();
    for (size_t i = 0; i < nCount; i++)
        m_list.Add((int)pPacket->ReadInt64());
    m_profile.Read(pPacket);
}
MS2_REPLACE_METHOD(0x14067D730, CMaid, ReadFromPacket, 867, 0x307ABCDA);

// @0x14067daa0
int CMaid::GetRemainDays()
{
    CMsTime expire(m_nExpireTime);
    CMsTime now(GetServerTime());
    if (expire > now)
    {
        ATL::CTimeSpan span = expire - now;
        return (int)span.GetDays();
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14067DAA0, CMaid, GetRemainDays, 113, 0x2771DFCF);

// @0x14067db20
int CMaid::GetOverDays()
{
    CMsTime expire(m_nExpireTime);
    CMsTime now(GetServerTime());
    if (now > expire)
    {
        ATL::CTimeSpan span = now - expire;
        int nDays = (int)span.GetDays();
        return (std::max)(1, nDays);
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14067DB20, CMaid, GetOverDays, 142, 0xEE875E39);

// @0x14067dbc0
int CMaid::IsExpired()
{
    return m_nExpireTime < GetServerTime();
}
MS2_REPLACE_METHOD(0x14067DBC0, CMaid, IsExpired, 55, 0x88BFE212);

// @0x14067dc00
int CMaid::IsTime38Over(int nSeconds)
{
    __int64 now = GetServerTime();
    return (__int64)nSeconds + m_t38 < now;
}
MS2_REPLACE_METHOD(0x14067DC00, CMaid, IsTime38Over, 71, 0xEB8B66A2);

// @0x14067dc50
int CMaid::IsTime40Over(int nSeconds)
{
    __int64 now = GetServerTime();
    return (__int64)nSeconds + m_t40 < now;
}
MS2_REPLACE_METHOD(0x14067DC50, CMaid, IsTime40Over, 71, 0xB40A8361);

// @0x14067dca0
int CMaid::IsAffinityLevelAtMax()
{
    int nMaxLevel = CMaidExpTable::GetInstance()->GetMaxLevel();
    int nLimit = (std::min)(*GetClientConstants()->MaidAffinityMax.Get(), nMaxLevel);
    if (nLimit <= m_nOrder)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14067DCA0, CMaid, IsAffinityLevelAtMax, 92, 0x3EEABB11);

// @0x14067dd10
int CMaid::GetMoodGrade()
{
    if (m_nMood <= 30)
        return 0;
    else if (m_nMood <= 70)
        return 1;
    return 2;
}
MS2_REPLACE_METHOD(0x14067DD10, CMaid, GetMoodGrade, 44, 0xC737B0FC);

// @0x14067dd50
void CMaid::ResetLevel()
{
    m_nExp = 0;
    m_nOrder = 1;
}
MS2_REPLACE_METHOD(0x14067DD50, CMaid, ResetLevel, 30, 0x15ACA648);

// @0x14067dd80
void CMaid::AddLevel(int nDelta, int bIgnoreLimit)
{
    m_nOrder += nDelta;
    int nMaxLevel = CMaidExpTable::GetInstance()->GetMaxLevel();
    int nLimit = (std::min)(*GetClientConstants()->MaidAffinityMax.Get(), nMaxLevel);
    if (bIgnoreLimit != 0)
        nLimit = CMaidExpTable::GetInstance()->GetMaxLevel();
    if (nLimit <= m_nOrder)
        m_nExp = 0;
    m_nOrder = (std::max)(0, (std::min)(nLimit, m_nOrder));
}
MS2_REPLACE_METHOD(0x14067DD80, CMaid, AddLevel, 201, 0x15FEF669);

// @0x14067de50
int CMaid::AddMood(int nDelta)
{
    int nOld = m_nMood;
    m_nMood += nDelta;
    m_nMood = (std::max)(0, (std::min)(100, m_nMood));
    return m_nMood != nOld;
}
MS2_REPLACE_METHOD(0x14067DE50, CMaid, AddMood, 147, 0x4A09A432);

// @0x14067def0
void CMaid::SetMode(int nMode)
{
    m_nMode = nMode;
}
MS2_REPLACE_METHOD(0x14067DEF0, CMaid, SetMode, 22, 0x6608447B);

// ---- CMaidExpTable ----------------------------------------------------------------------------------------------------

// @0x14067e9d0
CMaidExpTable::CMaidExpTable()
{
}

// @0x14067ea50
CMaidExpTable::~CMaidExpTable()
{
}

// @0x14067eab0
int CMaidExpTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MaidExp.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    int nMaxLevel = 0;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("Exp")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("Exp")))
    {
        int nLevel = 0;
        int nExp = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "Level", reinterpret_cast<int&>(nLevel));
        XmlGetAttr((class TiXmlElement*)(pNode), "Exp", reinterpret_cast<int&>(nExp));
        m_exps.SetAt(nLevel, nExp);
        if (nMaxLevel <= nLevel)
            nMaxLevel = nLevel;
    }
    if (nMaxLevel != (int)m_exps.GetCount())
        return 0;
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x14067EAB0, CMaidExpTable, Load, 631, 0x0DC79A75);

// @0x14067ed30
int CMaidExpTable::GetExp(int nLevel)
{
    CheckInit();
    int nExp = 0;
    if (m_exps.Lookup(nLevel, nExp))
        return nExp;
    return 0;
}
MS2_REPLACE_METHOD(0x14067ED30, CMaidExpTable, GetExp, 72, 0x323CC01F);

// @0x14067ed80
int CMaidExpTable::GetMaxLevel()
{
    CheckInit();
    return (int)m_exps.GetCount();
}
MS2_REPLACE_METHOD(0x14067ED80, CMaidExpTable, GetMaxLevel, 36, 0xEA694AEF);

// ---- CMaidInfoTable ---------------------------------------------------------------------------------------------------

// @0x14067edb0
CMaidInfoTable::CMaidInfoTable()
{
}

// @0x14067ee30
CMaidInfoTable::~CMaidInfoTable()
{
}

// @0x14067ee90
int CMaidInfoTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MaidProperty.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("Property")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("Property")))
    {
        TPtrValue<MaidInfo> spInfo(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "MaidID", reinterpret_cast<int&>(spInfo->maidId));
        XmlGetAttr((class TiXmlElement*)(pNode), "RecipeGroupID", reinterpret_cast<int&>(spInfo->recipeGroupId));
        XmlGetAttr((class TiXmlElement*)(pNode), "NPCID", spInfo->npcId);
        CPriceTable::GetInstance()->GetSalary(spInfo->maidId, &spInfo->salaryType, &spInfo->salary);
        m_infos.SetAt(spInfo->maidId, spInfo);
    }
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x14067EE90, CMaidInfoTable, Load, 737, 0xD52AA6DC);

// @0x14067f180
TPtrValue<MaidInfo> CMaidInfoTable::Find(int nMaidId)
{
    CheckInit();
    TPtrValue<MaidInfo> spInfo;
    if (m_infos.Lookup(nMaidId, spInfo))
        return spInfo;
    return TPtrValue<MaidInfo>(0);
}
MS2_REPLACE_METHOD(0x14067F180, CMaidInfoTable, Find, 171, 0x326F473A);

// ---- CMaidDescTable ---------------------------------------------------------------------------------------------------

// @0x14067f240
CMaidDescTable::CMaidDescTable()
{
}

// @0x14067f2c0
CMaidDescTable::~CMaidDescTable()
{
}

// @0x14067f320
int CMaidDescTable::Load()
{
    CString strPath = FUN_14071ae20("MaidPropertyString.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("Desc")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("Desc")))
    {
        TPtrValue<MaidDesc> spDesc(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "MaidID", reinterpret_cast<int&>(spDesc->maidId));
        XmlGetAttr((class TiXmlElement*)(pNode), "Specialty", spDesc->specialty);
        XmlGetAttr((class TiXmlElement*)(pNode), "Title", spDesc->title);
        XmlGetAttr((class TiXmlElement*)(pNode), "Name", spDesc->name);
        XmlGetAttr((class TiXmlElement*)(pNode), "BirthDay", spDesc->birthDay);
        XmlGetAttr((class TiXmlElement*)(pNode), "Constellation", spDesc->constellation);
        XmlGetAttr((class TiXmlElement*)(pNode), "Height", spDesc->height);
        XmlGetAttr((class TiXmlElement*)(pNode), "Weight", spDesc->weight);
        XmlGetAttr((class TiXmlElement*)(pNode), "SpecialDetail", spDesc->specialDetail);
        XmlGetAttr((class TiXmlElement*)(pNode), "Like", spDesc->like);
        XmlGetAttr((class TiXmlElement*)(pNode), "Hate", spDesc->hate);
        XmlGetAttr((class TiXmlElement*)(pNode), "Hobby", spDesc->hobby);
        XmlGetAttr((class TiXmlElement*)(pNode), "OwnerName", spDesc->ownerName);
        XmlGetAttr((class TiXmlElement*)(pNode), "BelongTo", spDesc->belongTo);
        XmlGetAttr((class TiXmlElement*)(pNode), "SpecialTitle", spDesc->specialTitle);
        XmlGetAttr((class TiXmlElement*)(pNode), "Background", spDesc->background);
        spDesc->background.Replace(L"\\n", L"\n");
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spDesc->background);
        m_descs.SetAt(spDesc->maidId, spDesc);
    }
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x14067F320, CMaidDescTable, Load, 1113, 0xE14ACD22);

// @0x14067f780
TPtrValue<MaidDesc> CMaidDescTable::Find(int nMaidId)
{
    CheckInit();
    TPtrValue<MaidDesc> spDesc;
    if (m_descs.Lookup(nMaidId, spDesc))
        return spDesc;
    return TPtrValue<MaidDesc>(0);
}
MS2_REPLACE_METHOD(0x14067F780, CMaidDescTable, Find, 171, 0xCC4CC0DA);

// ---- CMaidManufactureMsgTable -----------------------------------------------------------------------------------------

// @0x14067f840
CMaidManufactureMsgTable::CMaidManufactureMsgTable()
{
}

// @0x14067f8c0
CMaidManufactureMsgTable::~CMaidManufactureMsgTable()
{
}

// @0x14067f920
int CMaidManufactureMsgTable::Load()
{
    CString strPath = FUN_14071ae20("MaidManufactureMessage.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("Message")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("Message")))
    {
        TPtrValue<MaidManufactureMsg> spMsg(Unk_GrNewTag(0));
        XmlGetAttr((class TiXmlElement*)(pNode), "MaidID", reinterpret_cast<int&>(spMsg->maidId));
        XmlGetAttr((class TiXmlElement*)(pNode), "SelectItem", spMsg->selectItem);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->selectItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "CraftRequest", spMsg->craftRequest);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->craftRequest);
        XmlGetAttr((class TiXmlElement*)(pNode), "CraftCancel", spMsg->craftCancel);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->craftCancel);
        XmlGetAttr((class TiXmlElement*)(pNode), "RecieveItem", spMsg->receiveItem);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->receiveItem);
        XmlGetAttr((class TiXmlElement*)(pNode), "RecieveJackpot", spMsg->receiveJackpot);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->receiveJackpot);
        XmlGetAttr((class TiXmlElement*)(pNode), "NotEnoughIgd", spMsg->notEnoughIgd);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->notEnoughIgd);
        XmlGetAttr((class TiXmlElement*)(pNode), "Expired", spMsg->expired);
        CReservedWordTable::GetInstance()->ReplaceObjectWords(spMsg->expired);
        m_msgs.SetAt(spMsg->maidId, spMsg);
    }
    SetInit(true);
    return 1;
}
MS2_REPLACE_METHOD(0x14067F920, CMaidManufactureMsgTable, Load, 1080, 0xF8450182);

// @0x14067fd60
TPtrValue<MaidManufactureMsg> CMaidManufactureMsgTable::Find(int nMaidId)
{
    CheckInit();
    TPtrValue<MaidManufactureMsg> spMsg;
    if (m_msgs.Lookup(nMaidId, spMsg))
        return spMsg;
    return TPtrValue<MaidManufactureMsg>(0);
}
MS2_REPLACE_METHOD(0x14067FD60, CMaidManufactureMsgTable, Find, 171, 0x91047537);

// ---- init flags -------------------------------------------------------------------------------------------------------

// @0x1406815b0
void CMaidDescTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidDescTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140681660
void CMaidExpTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidExpTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140681710
void CMaidInfoTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidInfoTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406817c0
void CMaidManufactureMsgTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CMaidManufactureMsgTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406840f0
void CMaidDescTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x140684100
void CMaidExpTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x140684110
void CMaidInfoTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x140684120
void CMaidManufactureMsgTable::SetInit(bool b)
{
    s_bInit = b;
}

// The tree nodes' nil-node zero fill is an inline REP STOSB in the exe's NewNode copies.
#pragma intrinsic(memset)

MS2_EMIT_CRT_MEMMOVE_S();
