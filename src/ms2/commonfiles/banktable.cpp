// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBankTable: Table/itemDefine.xml and Table/bankType.xml.
// MS2-UNIT: commonfiles\banktable.cpp
// MS2-RANGE: 0x1401b3c70-0x1401b6d10 .text$mn
// MS2-RANGE: 0x1400b4220-0x1400b42e0 .text$di
// MS2-RANGE: 0x142c9a080-0x142c9a0b0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CPair@?$CRBTree@IV?$MS2Ptr@VCBankData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBankData@@@@@3@@ATL@@IEAA@IAEBV?$MS2Ptr@VCBankData@@@@@Z 0x1401b4f90 ; unique
// MS2-PIN: ??_ECBankTable@@W7EAAPEAXI@Z 0x1401b52b0 ; unique
// MS2-PIN: ??_G?$CValidData@VCBankTable@@@@UEAAPEAXI@Z 0x1401b52c0 ; prop
// MS2-PIN: ??_G?$TSingleton@VCBankTable@@@@UEAAPEAXI@Z 0x1401b5300 ; prop
// MS2-PIN: ??_GCBankData@@UEAAPEAXI@Z 0x1401b5340 ; unique
// MS2-PIN: ??_GCBankItemDefine@@UEAAPEAXI@Z 0x1401b5380 ; unique
// MS2-PIN: ??_GCBankTable@@UEAAPEAXI@Z 0x1401b53c0 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@I@ATL@@SAHAEBI0@Z 0x1401b5620 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CBankTable@@6B?$TSingleton@VCBankTable@@@@@ 0x142cecdc0
// MS2-PIN: ??_7CBankTable@@6B?$CValidData@VCBankTable@@@@@ 0x142cecdd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\banktable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "banktable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{ public:  
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int FUN_14021bdc0(CString& str);                                         // enum value of a slot name
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177de0 (CAtlArray<int>)

// The item record the table classifies (the same record FUN_14053f870 returns elsewhere).
class Unk_BankItemSlot;
class CItemData : public CPtred   // C3: member view for the former free stand-ins
{
public:
    int GetType();                      // item type
    int GetSubtype();                   // item sub type
    class ItemModelData* GetModelOrEmpty();
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class ItemModelData   // C3: member view for the former free stand-ins
{
public:
    int FUN_14054b400() const;
};

CLockCriticalSection* Unk_LockIdentity(CLockCriticalSection*); // identity (base-object constructor)
// The scoped lock (clockcriticalsection.h; was the local Unk_1401b4ec0 class): locks on construction when asked,
// unlocks on exit. This unit is the exe's copy of the by-reference ctor 0x1401b4ec0 and the dtor 0x1401b5120.
#include "ms2/placeholder/clockcriticalsection.h"
Unk_CriticalSectionLock::Unk_CriticalSectionLock(CLockCriticalSection& lock, int bLock)
{
    m_p = Unk_LockIdentity(&lock);
    if (bLock)
        lock.vfunc_1();
}
Unk_CriticalSectionLock::~Unk_CriticalSectionLock()
{
    if (m_p)
        m_p->vfunc_2();
}
//
//
//
//
//

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CBankTable::s_bInit;
#endif

// Sort names of the bank list (header static of this unit).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// @0x1401b3c70
CBankItemDefine::CBankItemDefine()
{
    m_nId = 0;
    m_nSlot = 0;
    m_nType = 0;
    m_nSubType = 0;
}

// @0x1401b3ce0
CBankItemDefine::~CBankItemDefine()
{
}

// @0x1401b3d10
CBankData::CBankData()
{
    m_nId = 0;
    m_nSlotCount = 0;
    m_nUseCash = 0;
    int nMax = CBankTable::GetInstance()->GetMaxId() + 1;
    m_slots.SetCount(nMax, -1);
    for (int i = 0; i < nMax; i++)
        m_slots[i] = 0;
}

// @0x1401b3df0
CBankData::~CBankData()
{
}

// @0x1401b3e30
void CBankData::SetSlots(CStringA strList)
{
    ATL::CAtlArray<int> ids;
    XmlSplit(strList, ids, ",");
    int nMax = CBankTable::GetInstance()->GetMaxId();
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        int nId = ids[i];
        if (nId < 1 || nId > nMax)
        {
            MS2_ASSERT_AT(0x38, 0);
            continue;
        }
        m_slots[nId] = 1;
    }
}

// @0x1401b3f40
int CBankData::IsStorable(int nItemId)
{
    int nMax = CBankTable::GetInstance()->GetMaxId();
    int nBank = CBankTable::GetInstance()->FindBankId(nItemId);
    if (nBank < 1 || nBank > nMax)
        return 0;
    return m_slots[nBank];
}

// @0x1401b3fb0
CBankTable::CBankTable() : m_banks(10), m_defines(10)
{
    m_nMaxId = 0;
}

// @0x1401b4060
CBankTable::~CBankTable()
{
    m_banks.RemoveAll();
    m_defines.RemoveAll();
}

// @0x1401b4110
int CBankTable::Load()
{
    if (!LoadItemDefine())
        return 0;
    if (!LoadBankType())
        return 0;
    SetInit(true);
    return 1;
}

// @0x1401b4160
CBankTable::DataPtr CBankTable::GetBankData(unsigned nId)
{
    DataPtr data(0);
    {
        Unk_LockGuard guard(m_lock);
        if (guard)
        {
        }
        else
            m_banks.Lookup(nId, data);
    }
    return data;
}

// @0x1401b4220
int CBankTable::GetMaxId()
{
    return m_nMaxId;
}

// @0x1401b4240
int CBankTable::FindBankId(int nItemId)
{
    CheckInit();
    MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
    if (item == 0)
        return -1;
    int nSlot = item->GetModelOrEmpty()->FUN_14054b400();
    int nType = item->GetType();
    int nSubType = item->GetSubtype();
    int nFound = -1;
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (POSITION pos = m_defines.GetHeadPosition(); pos; m_defines.GetNext(pos))
    {
        BOOL bMatch = FALSE;
        DefinePtr def = m_defines.GetAt(pos);
        if (def == 0)
            continue;
        if (nSlot != 0)
        {
            if (def->m_nSlot == nSlot)
                bMatch = TRUE;
        }
        else if (nType == def->m_nType && nSubType == def->m_nSubType)
        {
            bMatch = TRUE;
        }
        if (bMatch)
        {
            nFound = def->m_nId;
            break;
        }
    }
    return nFound;
}

// @0x1401b4460
int CBankTable::LoadItemDefine()
{
    CString strPath = FUN_14071a5b0("Table", "itemDefine.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("key")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("key")))
    {
        DefinePtr def(new CBankItemDefine);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", def->m_nId);
        ReadSlotAttr(pNode, "slot", &def->m_nSlot);
        XmlGetAttr((class TiXmlElement*)(pNode), "type", def->m_nType);
        XmlGetAttr((class TiXmlElement*)(pNode), "subType", def->m_nSubType);
        Unk_CriticalSectionLock guard(m_lock, 1);
        m_defines.AddTail(def);
        if (def->m_nId > m_nMaxId)
            m_nMaxId = def->m_nId;
    }
    return 1;
}

MS2_REPLACE_METHOD(0x1401B4460, CBankTable, LoadItemDefine, 820, 0xC3037A24);

// @0x1401b47a0
int CBankTable::LoadBankType()
{
    CString strPath = FUN_14071a5b0("Table", "bankType.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    CString strStore;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("bankType")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("bankType")))
    {
        DataPtr data(new CBankData);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<unsigned&>(data->m_nId));
        XmlGetAttr((class TiXmlElement*)(pNode), "useCash", data->m_nUseCash);
        XmlGetAttr((class TiXmlElement*)(pNode), "slotCount", data->m_nSlotCount);
        strStore = Unk_ReadString((class Unk_XmlNode*)(pNode), "storeItemType", CString(""));
        data->SetSlots(CString(strStore));
        Unk_CriticalSectionLock guard(m_lock, 1);
        m_banks.SetAt(data->m_nId, data);
    }
    return 1;
}

MS2_REPLACE_METHOD(0x1401B47A0, CBankTable, LoadBankType, 996, 0x0C2D6239);

// @0x1401b4b90
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
int ReadSlotAttr(TiXmlElement* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRead != 0)
        return nRead;
    *pnOut = FUN_14021bdc0(str);
    return nRead;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\banktable.cpp"

// @0x1401b5570
void CBankTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CBankTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1401b6910
void CBankTable::SetInit(bool b)
{
    s_bInit = b;
}
