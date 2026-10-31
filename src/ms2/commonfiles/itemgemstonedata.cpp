// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemGemStoneUpgradeTable: Table/itemGemstoneUpgrade.xml.
// MS2-UNIT: ?\itemgemstonedata.cpp
// MS2-RANGE: 0x1405b0b70-0x1405b38e0 .text$mn
// MS2-RANGE: 0x1400ba1d0-0x1400ba350 .text$di
// MS2-RANGE: 0x142c9b100-0x142c9b160 .text$yd
// MS2-PIN: ??_7CItemGemStoneUpgradeTable@@6B?$TSingleton@VCItemGemStoneUpgradeTable@@@@@ 0x142d639d0
// MS2-PIN: ??_7CItemGemStoneUpgradeTable@@6B?$CValidData@VCItemGemStoneUpgradeTable@@@@@ 0x142d639f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgemstonedata.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)   // the TU-local memcpy_s calls memcpy/memset out of line
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)
#include "itemgemstonedata.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// Sort names of the item lists (header statics of this unit).
#ifndef MS2_HOOK_DLL
static const CString s_gemSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static const CString s_gemShopSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408731a0(Unk_140165cf0* pElem, const char* pszName, unsigned short& nOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CStringA& strOut);
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);
extern MS2Ptr<CItemData> FUN_14053f870(int);
CString FUN_140719210(long n);                                           // number text
CString FUN_1401d2b10(const CString& a, const CString& b);               // a + b
void FUN_140275080(CString&, Unk_StrVec*, const char*);                  // split at a separator
void FUN_140177f30(CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);   // split into numbers

// The three-argument log call of this unit (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
// @0x1405b1bd0
// @0x1405b1f30
template <class A, class B, class C>
inline void Unk_GemLog(CLogString* log, int level, int category, const wchar_t* format, const A& a, const B& b, const C& c)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c), args));
}

// The ingredient's tag setter (an inline member of CIngredientInfo in the exe).
// @0x1405b3610
inline void Unk_GemIngredientTag(CIngredientInfo* pInfo, int nTag)
{
    pInfo->m_b = nTag;
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CItemGemStoneUpgradeTable::s_bInit;
#endif

// @0x1405b0b70
CItemGemStoneData::CItemGemStoneData() : m_nSlot(0), m_nLinked(0), m_nMask(7)
{
}

// @0x1405b0c00
CItemGemStoneData::~CItemGemStoneData()
{
}

// @0x1405b0c50
CItemGemStoneUpgradeTable::CItemGemStoneUpgradeTable() : m_rows(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1405b0d20
CItemGemStoneUpgradeTable::~CItemGemStoneUpgradeTable()
{
}

// @0x1405b0dc0
int CItemGemStoneUpgradeTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemGemstoneUpgrade.xml");
    FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    const CString& strKey = "key";
    const CString& strItemId = "ItemId";
    const CString& strLevel = "GemLevel";
    const CString& strNext = "NextItemID";
    const CString& strIngredient = "IngredientItemID";
    const CString& strCount = "IngredientCount";
    const CString& strIcon = "IconId";
    const CString& strPart = "EquipPart";
    const int nIngredients = 4;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0(strKey); pNode != 0; pNode = pNode->FUN_140168650(strKey))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nItemId;
        FUN_140873220(pNode, strItemId, nItemId);
        if (nItemId == 0)
            continue;
        DataPtr data(new CItemGemStoneData);
        if (data == 0)
            continue;
        FUN_1408731a0(pNode, strLevel, data->m_nSlot);
        FUN_140873220(pNode, strNext, (unsigned&)data->m_nLinked);
        FUN_140873420(pNode, strIcon, data->m_strName);
        if (!FUN_1406af060(FUN_1406aeee0()))
        {
            int nTransfer = 0;
            {
                MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
                if (item.get() != 0)
                    nTransfer = item->limit.transferType;
            }
            MS2Ptr<CItemData> next = FUN_14053f870(data->m_nLinked);
            if (next.get() != 0 && nTransfer != next->limit.transferType)
            {
                unsigned nNextId = next->FUN_14053c510();
                Unk_GemLog(CLogString::GetInstance(), 2, 0x13,
                           L"젬스톤 거래타입(귀속,거래불가 등)이 같지않습니다(itemID: {0}, nextItemID: {1}). itemProperty transferType을 확인해 주세요. [{2}]",
                           nItemId, nNextId, strPath);
            }
        }
        data->m_ingredients.FUN_14026bfa0(4);
        CIngredientContainer* pIngredients = &data->m_ingredients;
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
                    {
                        Unk_StrVec tokens;
                        FUN_140275080(strValue, &tokens, ":");
                        if (tokens.FUN_14028b4c0() > 0)
                            nId = FUN_1407181d0(tokens.FUN_14027f1c0(0));
                        if (tokens.FUN_14028b4c0() > 1)
                            nTag = FUN_140557640(FUN_140281980(), tokens.FUN_14027f1c0(1));
                    }
                    Unk_IngRef info(new CIngredientInfo(nId, nAmount, 0));
                    Unk_GemIngredientTag(info.operator->(), nTag);
                    pIngredients->FUN_14026bca0(info);
                }
            }
        }
        CStringA strParts;
        FUN_1408733e0(pNode, strPart, strParts);
        strParts.Trim();
        if (!strParts.IsEmpty())
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
                    nMask |= 1 << nPart;
                }
                data->m_nMask = nMask;
            }
        }
        else
        {
            data->m_nMask = 7;
        }
        if ((data->m_nMask & 8) > 0 && data->m_nMask != 8)
        {
            Unk_GemLog(CLogString::GetInstance(), 2, 0x13, L"equipPart itemID: {0}, equipPart:{1}, [{2}]", nItemId, strParts, strPath);
            return 0;
        }
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            m_rows.SetAt(nItemId, data);
        }
    }
    SetInit(true);
    return 1;
}

// @0x1405b1a60
CItemGemStoneUpgradeTable::DataPtr CItemGemStoneUpgradeTable::FUN_1405b1a60(unsigned nId)
{
    CheckInit();
    if (m_rows.IsEmpty())
        return DataPtr(0);
    DataPtr data(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_rows.Lookup(nId, data);
    }
    return data;
}

// @0x1405b1b50
int CItemGemStoneUpgradeTable::Reload()
{
    int nResult = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_rows.RemoveAll();
        nResult = Load();
    }
    return nResult;
}

// @0x1405b27c0
void CItemGemStoneUpgradeTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemGemStoneUpgradeTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405b36e0
void CItemGemStoneUpgradeTable::SetInit(bool b)
{
    s_bInit = b;
}
