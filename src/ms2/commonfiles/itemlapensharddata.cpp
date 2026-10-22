// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemLapenshardTable: Table/itemLapenshardUpgrade.xml
// (lapenshard rows: group, level, upgrade target, ingredients, equip parts), its queries, the six equip slots and the
// packet bodies of the lapenshard messages that share the TU; the range ends with the CAtlMap / MS2Ptr glue of the
// containers.
// MS2-UNIT: ?\itemlapensharddata.cpp
// MS2-RANGE: 0x1405b4080-0x1405bd5b0 .text$mn
// MS2-RANGE: 0x1400ba350-0x1400ba410 .text$di
// MS2-RANGE: 0x142c9b160-0x142c9b190 .text$yd
// MS2-PIN: ??_7CItemLapenshardTable@@6B?$TSingleton@VCItemLapenshardTable@@@@@ 0x142d644c8
// MS2-PIN: ??_7CItemLapenshardTable@@6B?$CValidData@VCItemLapenshardTable@@@@@ 0x142d644e8
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Allocate@?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@PEAX@Z 0x1405b63a0 ; unique
// MS2-PIN: ??0?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@QEAA@H@Z 0x1405b68c0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x1405b6bf0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$MS2Ptr@VCItemLapenshardData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItemLapenshardData@@@@@3@@ATL@@IEAA@H@Z 0x1405b6c30 ; unique
// MS2-PIN: ??8?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@QEBA_NPEAV?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@Z 0x1405b7010 ; unique
// MS2-PIN: ?Value@?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@CAPEAV?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@PEAV?$TPtredDummy@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@@Z 0x1405b7090 ; unique
// MS2-PIN: ??4?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x1405b7400 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4Kind@CItemLapenshardTable@@@ATL@@SAHAEBW4Kind@CItemLapenshardTable@@0@Z 0x1405b75e0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCItemLapenshardData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItemLapenshardData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1405b8670 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@W4Slot@CItemLapenshardTable@@W4Kind@2@V?$CElementTraits@W4Slot@CItemLapenshardTable@@@ATL@@V?$CElementTraits@W4Kind@CItemLapenshardTable@@@5@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1405bbf70 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1405bc150 ; prop
// MS2-PIN: ?Make@?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@AEAAXXZ 0x1405bd310 ; unique
// MS2-PIN: ?Create@?$TPtrValue@V?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@@@CAPEAV?$CAtlMap@GIV?$CElementTraits@G@ATL@@V?$CElementTraits@I@2@@ATL@@PEAX@Z 0x1405bd340 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemlapensharddata.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)   // the TU-local memcpy_s calls memcpy/memset out of line
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "itemlapensharddata.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Sort names of the item lists (header statics of this unit).
#ifndef MS2_HOOK_DLL
static const CString s_lapenSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408731a0(Unk_140165cf0* pElem, const char* pszName, unsigned short& nOut);
int FUN_1408732e0(Unk_140165cf0* pElem, const char* pszName, __int64& nOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA& strOut);
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);
extern MS2Ptr<CItemData> FUN_14053f870(int);
CString FUN_140719210(long n);                                           // number text
CString FUN_1401d2b10(const CString& a, const CString& b);               // a + b
void FUN_140275080(CString&, Unk_StrVec*, const char*);                  // split at a separator
void FUN_140177f30(CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);   // split into numbers
unsigned FUN_140482050(unsigned nAmount, unsigned nScale);               // scaled money amount
// The three-argument log call (the instantiation of itemgemstonedata.cpp's Unk_GemLog, same exe function)
void FUN_1405b1bd0(void* log, int level, int category, const wchar_t* format, const unsigned& a, const unsigned& b, const CStringA& c);

// The ingredient's tag setter (an inline member of CIngredientInfo in the exe).
// The ingredient vector's iterator (the exe's std::vector<Unk_IngRef>::iterator): the const base steps by one element.
struct Unk_LapenIngIterBase
{
    Unk_IngRef* m_p;
    // @0x1405b70f0
    Unk_IngRef** operator++() { ++m_p; return &m_p; }
};
struct Unk_LapenIngIter : Unk_LapenIngIterBase
{
    Unk_LapenIngIter(Unk_IngRef* p) { m_p = p; }
    // @0x1405b7110
    Unk_LapenIngIter& operator++() { Unk_LapenIngIterBase::operator++(); return *this; }
};

// @0x1405b3610
inline void Unk_LapenIngredientTag(CIngredientInfo* pInfo, int nTag)
{
    pInfo->m_b = nTag;
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CItemLapenshardTable::s_bInit;
#endif

// @0x1405b4080
CItemLapenshardData::CItemLapenshardData() : m_nGroup(0), m_nLevel(0), m_nNext(0), m_nMask(0), m_nMinCount(0), m_nMeso(0)
{
    m_spIngredients = new CIngredientContainer;
}

// @0x1405b4170
CItemLapenshardData::~CItemLapenshardData()
{
}

// @0x1405b41b0
// MS2-FUNCTIONAL: the exe walks the ingredient vector through unrecovered iterator helpers
MS2SvrPtr<CIngredientContainer> CItemLapenshardData::GetIngredients(int nScale)
{
    if (nScale == 0)
    {
        const MS2SvrPtr<CIngredientContainer>& spOwn = m_spIngredients;
        return spOwn;
    }
    MS2SvrPtr<CIngredientContainer> spResult(new CIngredientContainer);
    Unk_IngRef* pBegin = static_cast<Unk_IngRef*>(m_spIngredients->m_items.m_begin);
    Unk_IngRef* pEnd = static_cast<Unk_IngRef*>(m_spIngredients->m_items.m_end);
    for (Unk_LapenIngIter it(pBegin); it.m_p != pEnd; ++it)
    {
        int nItem = (*it.m_p)->m_a;
        int nAmount = (*it.m_p)->m_c;
        int nTag = (*it.m_p)->m_b;
        bool bMoney = nTag == 0x5d || nTag == 0x5e || nTag == 0x5f;
        if (bMoney)
        {
            int nScaled = FUN_140482050(nAmount, nScale);
            if (nScaled == 0)
                nScaled = 1;
            nAmount = nScaled;
        }
        Unk_IngRef info(new CIngredientInfo(nItem, nAmount, 0));
        Unk_LapenIngredientTag(info.operator->(), nTag);
        spResult->FUN_14026bca0(info);
    }
    return spResult;
}

// @0x1405b44b0
CItemLapenshardTable::CItemLapenshardTable() : m_rows(17, 0.75f, 0.25f, 2.25f, 10), m_slotKinds(17, 0.75f, 0.25f, 2.25f, 10),
                                               m_kindSlots(10), m_firstItems(17, 0.75f, 0.25f, 2.25f, 10),
                                               m_groups(17, 0.75f, 0.25f, 2.25f, 10)
{
    InitEquipParts();
}

// @0x1405b4660
CItemLapenshardTable::~CItemLapenshardTable()
{
}

// @0x1405b4740
void CItemLapenshardTable::InitEquipParts()
{
    AddEquipPart(Red, Red1);
    AddEquipPart(Red, Red2);
    AddEquipPart(Blue, Blue1);
    AddEquipPart(Blue, Blue2);
    AddEquipPart(Green, Green1);
    AddEquipPart(Green, Green2);
}

// @0x1405b47e0
void CItemLapenshardTable::AddEquipPart(Kind part, Slot index)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_slotKinds.SetAt(index, part);
        m_kindSlots.Insert(part, index);
    }
}

// @0x1405b4880
// MS2-FUNCTIONAL: the exe passes the path pointer through rcx -> r8 (+3 bytes, as banktable/pricetable loaders); the rest of the frame matches
int CItemLapenshardTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemLapenshardUpgrade.xml");
    FUN_1401d1160(strPath);
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    const CString& strKey = "key";
    const CString& strItemId = "ItemId";
    const CString& strGroup = "LapenGroupID";
    const CString& strLevel = "LapenLevel";
    const CString& strNext = "NextItemID";
    const CString& strMinCount = "GroupLapenshardMinCount";
    const CString& strIngredient = "IngredientItemID";
    const CString& strCount = "IngredientCount";
    const CString& strPart = "EquipPart";
    const CString& strMeso = "meso";
    const int nIngredients = 4;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0(strKey); pNode != 0; pNode = pNode->FUN_140168650(strKey))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nItemId;
        FUN_140873220(pNode, strItemId, nItemId);
        if (nItemId == 0)
            continue;
        DataPtr data(new CItemLapenshardData);
        if (data == 0)
            continue;
        FUN_140873220(pNode, strGroup, (unsigned&)data->m_nGroup);
        FUN_1408731a0(pNode, strLevel, data->m_nLevel);
        FUN_140873220(pNode, strNext, (unsigned&)data->m_nNext);
        FUN_140873220(pNode, strMinCount, (unsigned&)data->m_nMinCount);
        FUN_1408732e0(pNode, strMeso, data->m_nMeso);
        if (!FUN_1406af060(FUN_1406aeee0()))
        {
            int nTransfer = 0;
            {
                MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
                if (item.get() != 0)
                    nTransfer = item->limit.transferType;
            }
            MS2Ptr<CItemData> next = FUN_14053f870(data->m_nNext);
            if (next.get() != 0 && nTransfer != next->limit.transferType)
            {
                unsigned nNextId = next->FUN_14053c510();
                FUN_1405b1bd0(FUN_140166440(), 2, 0x13,
                              L"라펜샤드 거래타입(귀속,거래불가 등)이 같지않습니다(itemID: {0}, nextItemID: {1}). itemProperty transferType을 확인해 주세요. [{2}]",
                              nItemId, nNextId, strPath);
            }
        }
        CIngredientContainer* pIngredients = data->m_spIngredients;
        pIngredients->FUN_14026bfa0(4);
        for (unsigned i = 0; i < 4; i++)
        {
            CString strNumber = FUN_140719210(i + 1);
            CString strIngredientAttr = FUN_1401d2b10(strIngredient, strNumber);
            CString strCountAttr = FUN_1401d2b10(strCount, strNumber);
            CStringA strValue;
            unsigned nAmount = 0;
            if (FUN_1408733e0(pNode, strIngredientAttr, strValue) == 0)
            {
                if (FUN_140873220(pNode, strCountAttr, nAmount) == 0)
                {
                    int nId = 0;
                    int nTag = 0;
                    Unk_StrVec tokens;
                    FUN_140275080(strValue, &tokens, ":");
                    if (tokens.FUN_14028b4c0() != 0)
                        nId = FUN_1407181d0(tokens.FUN_14027f1c0(0));
                    if (tokens.FUN_14028b4c0() > 1)
                        nTag = FUN_140557640(FUN_140281980(), tokens.FUN_14027f1c0(1));
                    Unk_IngRef info(new CIngredientInfo(nId, nAmount, 0));
                    Unk_LapenIngredientTag(info.operator->(), nTag);
                    pIngredients->FUN_14026bca0(info);
                }
            }
        }
        CStringA strParts;
        FUN_1408733e0(pNode, strPart, strParts);
        strParts.Trim();
        if (strParts.IsEmpty())
        {
            data->m_nMask = 7;
        }
        else
        {
            ATL::CAtlArray<unsigned> list;
            FUN_140177f30(strParts, list, ",");
            if (!list.IsEmpty())
            {
                size_t nCount = list.GetCount();
                unsigned nMask = 0;
                for (size_t j = 0; j < nCount; j++)
                {
                    int nPart = list[j] - 1;
                    if (nPart < 0)
                    {
                        nMask = 7;
                        break;
                    }
                    int nBit = 1;
                    nMask |= nBit << nPart;
                }
                data->m_nMask = nMask;
            }
        }
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            m_rows.SetAt(nItemId, data);
            if (data->m_nLevel == 1)
                m_firstItems.SetAt(data->m_nGroup, nItemId);
            TPtrValue<LevelMap> levels(0);
            if (!m_groups.Lookup(data->m_nGroup, levels))
            {
                levels = Unk_GrNewTag(0);
                m_groups.SetAt(data->m_nGroup, levels);
            }
            levels->SetAt(data->m_nLevel, nItemId);
        }
    }
    SetInit(true);
    return 1;
}

// @0x1405b5610
int CItemLapenshardTable::Reload()
{
    int nResult = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_rows.RemoveAll();
        m_firstItems.RemoveAll();
        nResult = Load();
    }
    return nResult;
}

// @0x1405b56a0
CItemLapenshardTable::DataPtr CItemLapenshardTable::Get(int nItemId)
{
    CheckInit();
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)))
        Reload();
    DataPtr data(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_rows.Lookup(nItemId, data);
    }
    return data;
}

// @0x1405b5780
unsigned short CItemLapenshardTable::GetLevel(int nItemId)
{
    DataPtr data = Get(nItemId);
    if (data == 0)
        return 0;
    return data->m_nLevel;
}

// @0x1405b5810
CItemLapenshardTable::Kind CItemLapenshardTable::GetEquipPart(Slot index)
{
    Kind kind = static_cast<Kind>(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_slotKinds.Lookup(index, kind);
    }
    return kind;
}

// @0x1405b5890
unsigned CItemLapenshardTable::GetEquipMask(int nItemId)
{
    DataPtr data = Get(nItemId);
    if (data == 0)
        return 0;
    return data->m_nMask;
}

// @0x1405b5910
void CItemLapenshardTable::GetEquipParts(Kind part, ATL::CAtlArray<Slot>& slots)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        POSITION pos = m_kindSlots.FindFirstWithKey(part);
        while (pos != 0)
        {
            slots.Add(m_kindSlots.GetValueAt(pos));
            m_kindSlots.GetNextWithKey(pos, part);
        }
    }
}

// @0x1405b59d0
int CItemLapenshardTable::GetGroup(int nItemId)
{
    DataPtr data = Get(nItemId);
    if (data == 0)
        return 0;
    return data->m_nGroup;
}

// @0x1405b5a50
int CItemLapenshardTable::HasUpgrade(int nItemId)
{
    DataPtr data = Get(nItemId);
    if (data == 0)
        return 0;
    return data->m_nNext != 0;
}

// @0x1405b5af0
unsigned CItemLapenshardTable::GetFirstItem(int nGroup)
{
    CheckInit();
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)))
        Reload();
    unsigned nItem = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_firstItems.Lookup(nGroup, nItem);
    }
    return nItem;
}

// @0x1405b5ba0
unsigned CItemLapenshardTable::GetItem(int nGroup, unsigned short nLevel)
{
    CheckInit();
    if (FUN_1401d1320(&static_cast<CCacheData&>(*this)))
        Reload();
    unsigned nItem = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        TPtrValue<LevelMap> levels(0);
        m_groups.Lookup(nGroup, levels);
        if (levels == 0)
            return 0;
        levels->Lookup(nLevel, nItem);
    }
    return nItem;
}

// @0x1405b5cc0
void Unk_LapenEquip::Write(COutputStream* s) const
{
    s->WriteInt32(m_nSlot);
    s->WriteInt64(m_nUid);
}

// @0x1405b5d10
void Unk_LapenEquip::Read(CInPacket& p)
{
    m_nSlot = p.ReadInt32();
    m_nUid = p.ReadInt64();
}

// @0x1405b5d80
void Unk_LapenEquipped::Write(COutputStream* s) const
{
    s->WriteInt32(m_nSlot);
    s->WriteInt32(m_nItem);
}

// @0x1405b5dd0
void Unk_LapenEquipped::Read(CInPacket& p)
{
    m_nSlot = p.ReadInt32();
    m_nItem = p.ReadInt32();
}

// @0x1405b5e40
void Unk_LapenUnequip::Write(COutputStream* s) const
{
    s->WriteInt32(m_nSlot);
}

// @0x1405b5e70
void Unk_LapenUnequip::Read(CInPacket& p)
{
    m_nSlot = p.ReadInt32();
}

// @0x1405b5ec0
void Unk_LapenItem::Write(COutputStream* s) const
{
    s->WriteInt64(m_nUid);
    s->WriteInt32(m_nItem);
    s->WriteInt32(m_nSlot);
}

// @0x1405b5f30
void Unk_LapenItem::Read(CInPacket& p)
{
    m_nUid = p.ReadInt64();
    m_nItem = p.ReadInt32();
    m_nSlot = p.ReadInt32();
}

// @0x1405b5fd0
void Unk_LapenUpgrade::Write(COutputStream* s) const
{
    Unk_LapenItem::Write(s);
    s->WriteInt32(m_fodder.GetCount());
    for (POSITION pos = m_fodder.GetStartPosition(); pos != 0; m_fodder.GetNext(pos))
    {
        unsigned __int64 nUid = m_fodder.GetKeyAt(pos);
        unsigned nAmount = m_fodder.GetValueAt(pos);
        s->WriteInt64(nUid);
        s->WriteInt32(nAmount);
    }
    s->WriteInt32(m_nTail);
}

// @0x1405b60e0
void Unk_LapenUpgrade::Read(CInPacket& p)
{
    Unk_LapenItem::Read(p);
    unsigned nCount = p.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned __int64 nUid = p.ReadInt64();
        unsigned nAmount = p.ReadInt32();
        m_fodder.SetAt(nUid, nAmount);
    }
    m_nTail = p.ReadInt32();
}

// @0x1405b61e0
void Unk_LapenUpgradeResult::Write(COutputStream* s) const
{
    Unk_LapenItem::Write(s);
    s->WriteBool(m_bSuccess);
}

// @0x1405b6220
void Unk_LapenUpgradeResult::Read(CInPacket& p)
{
    Unk_LapenItem::Read(p);
    m_bSuccess = p.ReadBool();
}

// @0x1405b6280
void Unk_LapenAddFodder::Write(COutputStream* s) const
{
    Unk_LapenItem::Write(s);
    s->WriteInt32(m_nAmount);
}

// @0x1405b62c0
void Unk_LapenAddFodder::Read(CInPacket& p)
{
    Unk_LapenItem::Read(p);
    m_nAmount = p.ReadInt32();
}

// @0x1405b6320
void Unk_LapenPreview::Write(COutputStream* s) const
{
    s->WriteInt32(m_nRate);
}

// @0x1405b6360
void Unk_LapenPreview::Read(CInPacket& p)
{
    m_nRate = p.ReadInt32();
}

// @0x1405b7430
void CItemLapenshardTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemLapenshardTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405bccd0
void CItemLapenshardTable::SetInit(bool b)
{
    s_bInit = b;
}
