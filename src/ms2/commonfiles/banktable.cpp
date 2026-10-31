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

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
CString FUN_14015f710(Unk_140165cf0*, const char*, CString strDefault);   // string attribute with default
int FUN_14021bdc0(CString& str);                                         // enum value of a slot name
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints

// The item record the table classifies (the same record FUN_14053f870 returns elsewhere).
class Unk_BankItemSlot;
class Unk_BankItem : public CPtred
{
public:
    int FUN_14053c5c0();                // item type
    int FUN_14053c5e0();                // item sub type
};
MS2Ptr<Unk_BankItem> FUN_14053f870(int nItemId);
Unk_BankItemSlot* FUN_14053eba0(Unk_BankItem*);
int FUN_14054b400(Unk_BankItemSlot*);   // slot of an item (0 when the item has none)

CLockCriticalSection* Unk_LockIdentity(CLockCriticalSection*); // identity (base-object constructor)
// Scoped lock helper shared with homeblockmanager / ugcmappackageinfo: locks on construction when asked, unlocks on exit.
class Unk_1401b4ec0
{
public:
    Unk_1401b4ec0(CLockCriticalSection& lock, int bLock)
    {
        m_p = Unk_LockIdentity(&lock);
        if (bLock)
            lock.vfunc_1();
    }
    ~Unk_1401b4ec0()
    {
        if (m_p)
            m_p->vfunc_2();
    }
private:
    CLockCriticalSection* m_p;
};
MS2_CHECK_SIZE(Unk_1401b4ec0, 8);

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
    FUN_140177de0(strList, ids, ",");
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
    MS2Ptr<Unk_BankItem> item = FUN_14053f870(nItemId);
    if (item == 0)
        return -1;
    int nSlot = FUN_14054b400(FUN_14053eba0(item.get()));
    int nType = item->FUN_14053c5c0();
    int nSubType = item->FUN_14053c5e0();
    int nFound = -1;
    Unk_1401b4ec0 guard(m_lock, 1);
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
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        DefinePtr def(new CBankItemDefine);
        FUN_1408731e0(pNode, "id", def->m_nId);
        ReadSlotAttr(pNode, "slot", &def->m_nSlot);
        FUN_1408731e0(pNode, "type", def->m_nType);
        FUN_1408731e0(pNode, "subType", def->m_nSubType);
        Unk_1401b4ec0 guard(m_lock, 1);
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
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    CString strStore;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("bankType"); pNode != 0; pNode = pNode->FUN_140168650("bankType"))
    {
        DataPtr data(new CBankData);
        FUN_140873220(pNode, "id", reinterpret_cast<unsigned&>(data->m_nId));
        FUN_1408731e0(pNode, "useCash", data->m_nUseCash);
        FUN_1408731e0(pNode, "slotCount", data->m_nSlotCount);
        strStore = FUN_14015f710(pNode, "storeItemType", CString(""));
        data->SetSlots(CString(strStore));
        Unk_1401b4ec0 guard(m_lock, 1);
        m_banks.SetAt(data->m_nId, data);
    }
    return 1;
}

MS2_REPLACE_METHOD(0x1401B47A0, CBankTable, LoadBankType, 996, 0x0C2D6239);

// @0x1401b4b90
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
int ReadSlotAttr(Unk_140165cf0* pElem, const char* pszName, int* pnOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString str;
    int nRead = FUN_1408733e0(pElem, pszName, str);
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
