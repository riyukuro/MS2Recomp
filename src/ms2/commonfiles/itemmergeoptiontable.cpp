// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemMergeOptionTable: Table/itemMergeOptionBase.xml, the value
// ranges an item merge (option transfer) can roll, and the records the merge dialog receives (CItemMergeOptionProxy).
// MS2-UNIT: commonfiles\itemmergeoptiontable.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1405bea40-0x1405caed0 .text$mn
// MS2-RANGE: 0x1400ba410-0x1400ba590 .text$di
// MS2-PIN: ??_7?$TSingleton@VCItemMergeOptionTable@@@@6B@ 0x142d65288
// MS2-PIN: ??_7?$CValidData@VCItemMergeOptionTable@@@@6B@ 0x142d65298
// MS2-PIN: ??_7CItemMergeOptionTable@@6B?$TSingleton@VCItemMergeOptionTable@@@@@ 0x142d652a8
// MS2-PIN: ??_7CItemMergeOptionTable@@6B?$CValidData@VCItemMergeOptionTable@@@@@ 0x142d652b8
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@@Z 0x1405c2690 ; unique
// MS2-PIN: ??0?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@IMMMI@Z 0x1405c3640 ; prop
// MS2-PIN: ??0?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@IMMMI@Z 0x1405c3730 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItemMergeOption@@@@QEAA@PEAVCItemMergeOption@@@Z 0x1405c3910 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItemMergeOptionData@@@@QEAA@H@Z 0x1405c39d0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItemMergeOptionData@@@@QEAA@PEAVCItemMergeOptionData@@@Z 0x1405c39f0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItemMergeOptionVariation@@@@QEAA@PEAVCItemMergeOptionVariation@@@Z 0x1405c3a60 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@AEBW4MergeNormalOption@@I@Z 0x1405c3fe0 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@AEBW4MergeSpecialOption@@I@Z 0x1405c4020 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@IEAA@AEBW4MergeNormalOption@@@Z 0x1405c4060 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@IEAA@AEBW4MergeSpecialOption@@@Z 0x1405c40a0 ; prop
// MS2-PIN: ??1?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@XZ 0x1405c4160 ; prop
// MS2-PIN: ??1?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA@XZ 0x1405c4190 ; prop
// MS2-PIN: ??1?$pair@U?$pair@HH@std@@V?$MS2Ptr@VCItemMergeOptionData@@@@@std@@QEAA@XZ 0x1405c44b0 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@VCItemOption@@@@QEBA_NXZ 0x1405c4720 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemMergeOption@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOption@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemMergeOption@@@@_K@Z 0x1405c48d0 ; prop
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemMergeOptionVariation@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOptionVariation@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemMergeOptionVariation@@@@_K@Z 0x1405c4910 ; unique
// MS2-PIN: ?get@?$Unk_EnchantPtr@VBaseOption@@@@QEBAPEAVBaseOption@@XZ 0x1405c4950 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCItemMergeOptionData@@@@QEBAPEAVCItemMergeOptionData@@XZ 0x1405c4970 ; unique
// MS2-PIN: ??_GCNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAPEAXI@Z 0x1405c5110 ; prop
// MS2-PIN: ??_GCNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAPEAXI@Z 0x1405c5150 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCItemMergeOption@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOption@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCItemMergeOption@@@@@Z 0x1405c5190 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCItemMergeOptionVariation@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOptionVariation@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCItemMergeOptionVariation@@@@@Z 0x1405c5240 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAPEAVCNode@12@AEBW4MergeSpecialOption@@II@Z 0x1405c5460 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAPEAVCNode@12@AEBW4MergeNormalOption@@II@Z 0x1405c54e0 ; prop
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXXZ 0x1405c5560 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXXZ 0x1405c5580 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXXZ 0x1405c55a0 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXXZ 0x1405c55c0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x1405c5760 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x1405c5860 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXXZ 0x1405c5960 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXXZ 0x1405c59b0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCItemMergeOption@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOption@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1405c6040 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCItemMergeOptionVariation@@@@V?$CElementTraits@V?$MS2Ptr@VCItemMergeOptionVariation@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1405c61e0 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA_NI_N@Z 0x1405c63b0 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAA_NI_N@Z 0x1405c64d0 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEBA_NXZ 0x1405c6650 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEBA_NXZ 0x1405c6680 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAPEAVCNode@12@AEBW4MergeNormalOption@@II@Z 0x1405c66b0 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAPEAVCNode@12@AEBW4MergeSpecialOption@@II@Z 0x1405c68c0 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEBAI_K@Z 0x1405c6ad0 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEBAI_K@Z 0x1405c6bc0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXI@Z 0x1405c6cb0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXI@Z 0x1405c6ee0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1405c73b0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1405c74a0 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1405c7590 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1405c7650 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@W4MergeSpecialOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeSpecialOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAPEAU__POSITION@@AEBW4MergeSpecialOption@@AEBVCItemMergeOptionVariation@@@Z 0x1405c7710 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@W4MergeNormalOption@@VCItemMergeOptionVariation@@V?$CElementTraits@W4MergeNormalOption@@@ATL@@V?$CElementTraits@VCItemMergeOptionVariation@@@4@@ATL@@QEAAPEAU__POSITION@@AEBW4MergeNormalOption@@AEBVCItemMergeOptionVariation@@@Z 0x1405c77c0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$?0AEAHH$0A@@?$pair@HH@std@@QEAA@AEAH$$QEAH@Z 0x1405c20a0 ; make_pair(lvalue, rvalue): forward<int&> then forward<int>
// MS2-PIN: ??$?0HAEAH$0A@@?$pair@HH@std@@QEAA@$$QEAHAEAH@Z 0x1405c2230 ; make_pair(rvalue, lvalue)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemmergeoptiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citemmergeoptiontable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itemoption.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Sort names of the item lists (header statics of this unit).
#ifndef MS2_HOOK_DLL
static const CString s_mergeSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static const CString s_mergeShopSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* psz, int n);
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
CString FUN_1401d9af0(const char* pszFormat, const unsigned __int64& nArg);   // StringFormat, one numeric argument
extern MS2Ptr<CItemData> FUN_14053f870(int);
int FUN_14082ee80(const CString& strName);          // normal option id by name (-1: none)
int FUN_14081d2f0(const CString& strName);          // special option id by name (0: none)
int FUN_14082f2d0(int nNormal);
int FUN_14081dd50(int nSpecial);
void FUN_1403d7960(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& nA, const unsigned& nB);

// Two-argument log call with the packed category (template instance 0x1405c2380).
// @0x1405c2380
template <class T, class U>
inline void Unk_MergeLog(CLogString* log, unsigned __int64 a, unsigned __int64 b, int category,
                         const wchar_t* format, const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406536f0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// Option text helpers of the item tooltip (string table lookups and highlight).
class Unk_StringTableRef;
Unk_StringTableRef* FUN_1401a9d70();
class Unk_FeatureSet;
Unk_FeatureSet* FUN_14025e7c0();
bool FUN_14116d720(Unk_FeatureSet* p);                                  // the option ids are shown (debug)
CStringW FUN_141811980(Unk_StringTableRef* p, int nTable, int nId);
CStringW FUN_140631600(int nStat, BaseOption* pOption);                  // the text of a normal stat option
CStringW FUN_140631830(int nStat, int nValue, Unk_ItemEquipData* pData);   // the text of a special stat option
CStringW FUN_1401d0080(const CStringW& a, const CStringW& b);           // a + b
CStringW FUN_14052bd00(int nStringId, const CStringW& str);             // the highlighted text
bool FUN_1409c5210(CStringW& strOut, MS2Ptr<CItem> spItem, int nStat, int nGroup, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strText);
bool FUN_1409c56f0(CStringW& strOut, MS2Ptr<CItem> spItem, int nStat, int nGroup, Unk_EnchantPtr<BaseOption> spOption, const CStringW& strText);
int FUN_140408410(const ATL::CAtlArray<unsigned>* pArray, const int* pValue);   // the index of a value, -1 when absent
bool FUN_1405c7ba0(const Unk_MergeRange* pRange);
bool FUN_1403ef200(const Unk_MergeRange* pRange, int nValue);                    // the value lies in the range

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CItemMergeOptionTable::s_bInit;
#endif

// The weighted pools (ctors 0x1405c3840 / 0x1405c3870, dtors 0x1405c41e0 / 0x1405c4200).
template <class T> MergePoolRecord<T>::MergePoolRecord() : m_nTotal(0)
{
}
template <class T> MergePoolRecord<T>::~MergePoolRecord()
{
}
template struct MergePoolRecord<CItemMergeOption>;
template struct MergePoolRecord<CItemMergeOptionVariation>;

// @0x1405c4670
CItemMergeOptionVariation& CItemMergeOptionVariation::operator=(const CItemMergeOptionVariation& o)
{
    CPtred::operator=(o);
    m_range = o.m_range;
    m_nIndex = o.m_nIndex;
    return *this;
}

// @0x1405c6380
void Unk_MergeRange::Set(int nMin, int nMax)
{
    m_nMin = nMin;
    m_nMax = nMax;
}

// @0x1405bea40
CItemMergeOptionVariation::CItemMergeOptionVariation() : m_nIndex(0)
{
}

// @0x1405c4590
CItemMergeOptionVariation::~CItemMergeOptionVariation() = default;

// @0x1405beaa0
int CItemMergeOptionVariation::FUN_1405beaa0()
{
    return m_range.m_nMax - m_range.m_nMin + 1;
}

// @0x1405beac0
int CItemMergeOptionVariation::FUN_1405beac0()
{
    return m_range.m_nMin;
}

// @0x1405beae0
int CItemMergeOptionVariation::FUN_1405beae0()
{
    return m_range.m_nMax;
}

// @0x1405beb00
float CItemMergeOptionVariation::FUN_1405beb00()
{
    return (float)m_range.m_nMin / 1000.0f;
}

// @0x1405beb20
float CItemMergeOptionVariation::FUN_1405beb20()
{
    return (float)m_range.m_nMax / 1000.0f;
}

// @0x1405beb40
CItemMergeOptionProxy::CItemMergeOptionProxy() : m_nMeso(0)
{
}

// @0x1405c4530
CItemMergeOptionProxy::~CItemMergeOptionProxy() = default;

// @0x1405bec30
void CItemMergeOptionProxy::FUN_1405bec30(COutputStream& stream)
{
    stream.vfunc_o10_4(m_nMeso);
    m_ingredients.FUN_14026bfd0(stream);
    stream.vfunc_o10_3((unsigned)m_values.GetCount());
    for (size_t i = 0; i < m_values.GetCount(); i++)
        stream.vfunc_o10_3(m_values[i]);
    stream.vfunc_o10_3((unsigned)m_normal.GetCount());
    for (POSITION pos = m_normal.GetStartPosition(); pos != 0; m_normal.GetNext(pos))
    {
        MergeNormalOption key = m_normal.GetKeyAt(pos);
        CItemMergeOptionVariation* pRange = &m_normal.GetValueAt(pos);
        stream.vfunc_o10_2((unsigned short)key);
        stream.vfunc_o10_3(pRange->m_range.m_nMin);
        stream.vfunc_o10_3(pRange->m_range.m_nMax);
    }
    stream.vfunc_o10_3((unsigned)m_special.GetCount());
    for (POSITION pos = m_special.GetStartPosition(); pos != 0; m_special.GetNext(pos))
    {
        MergeSpecialOption key = m_special.GetKeyAt(pos);
        CItemMergeOptionVariation* pRange = &m_special.GetValueAt(pos);
        stream.vfunc_o10_2((unsigned short)key);
        stream.vfunc_o10_3(pRange->m_range.m_nMin);
        stream.vfunc_o10_3(pRange->m_range.m_nMax);
    }
}

// @0x1405bef60
void CItemMergeOptionProxy::FUN_1405bef60(CInPacket& packet)
{
    m_nMeso = packet.vfunc_o8_4();
    m_ingredients.FUN_14026c0b0(packet);
    unsigned nValues = packet.vfunc_o8_3();
    for (unsigned __int64 i = 0; i < nValues; i++)
        m_values.Add(packet.vfunc_o8_3());
    unsigned nNormal = packet.vfunc_o8_3();
    for (unsigned __int64 i = 0; i < nNormal; i++)
    {
        CItemMergeOptionVariation range;
        MergeNormalOption key = (MergeNormalOption)packet.vfunc_o8_2();
        range.m_range.m_nMin = packet.vfunc_o8_3();
        range.m_range.m_nMax = packet.vfunc_o8_3();
        m_normal.SetAt(key, range);
    }
    unsigned nSpecial = packet.vfunc_o8_3();
    for (unsigned __int64 i = 0; i < nSpecial; i++)
    {
        CItemMergeOptionVariation range;
        MergeSpecialOption key = (MergeSpecialOption)packet.vfunc_o8_2();
        range.m_range.m_nMin = packet.vfunc_o8_3();
        range.m_range.m_nMax = packet.vfunc_o8_3();
        m_special.SetAt(key, range);
    }
}

// @0x1405bf2e0
CItemMergeOption::CItemMergeOption() : m_nNormal(-1), m_nSpecial(0)
{
}

// @0x1405c44d0
CItemMergeOption::~CItemMergeOption() = default;

// @0x1405bf380
CItemMergeOptionData::CItemMergeOptionData() : m_nId(0), m_nProbVer(1)
{
}

// @0x1405bf410
CItemMergeOptionData::~CItemMergeOptionData()
{
}

// @0x1405bf470
// The <slot> element: its options and, per option, the steps idx0_max..idx9_max the value range is cut into.
int CItemMergeOptionData::Load(Unk_140165cf0* pSlot)
{
    FUN_140873220(pSlot, "probVer", (unsigned&)m_nProbVer);
    FUN_1408731e0(pSlot, "part", m_nId);
    XmlTokenList(pSlot, "partLimit", m_aPartLimit);
    for (Unk_140165cf0* pElem = pSlot->FUN_140165cf0("option"); pElem != 0; pElem = pElem->FUN_140168650("option"))
    {
        CString strName;
        unsigned nPrev = 0;
        int nCategory = 0;
        MS2Ptr<CItemMergeOption> spOption(new CItemMergeOption);
        FUN_1408733e0(pElem, "optionName", strName);
        FUN_140873220(pElem, "min", nPrev);
        int nNormal = FUN_14082ee80(strName);
        if (nNormal == -1)
        {
            int nSpecial = FUN_14081d2f0(strName);
            spOption->m_nSpecial = nSpecial;
            nCategory = FUN_14081dd50(nSpecial);
        }
        else
        {
            spOption->m_nNormal = nNormal;
            nCategory = FUN_14082f2d0(nNormal);
        }
        if (spOption->m_nNormal == -1 && spOption->m_nSpecial == 0)
            return 0;
        ATL::CAtlArray<MS2Ptr<CItemMergeOptionVariation> > aSteps;
        for (unsigned __int64 i = 0; i < 10; i++)
        {
            MS2Ptr<CItemMergeOptionVariation> spStep(new CItemMergeOptionVariation);
            spStep->m_nIndex = (int)i;
            unsigned nMax = 0;
            FUN_140873220(pElem, FUN_1401d9af0("idx{0}_max", i), nMax);
            if (nMax == 0)
                break;
            if (nMax <= nPrev)
            {
                (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemmergeoptiontable.cpp", 0xcf), 0));
                FUN_1403d7960(FUN_140166440(), 1, 0x13, L"ItemMergeError {0} {1}", nPrev, nMax);
            }
            spStep->m_range.Set(nPrev + 1, nMax);
            aSteps.Add(spStep);
            nPrev = nMax;
        }
        if (aSteps.GetCount() != 0)
        {
            spOption->m_kFirst.m_range.m_nMin = aSteps[0]->m_range.m_nMin;
            spOption->m_kFirst.m_range.m_nMax = aSteps[aSteps.GetCount() - 1]->m_range.m_nMax;
            size_t nPick = 0;
            switch (aSteps.GetCount() - 1)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                nPick = aSteps.GetCount() - 1;
                break;
            case 4:
            case 5:
                nPick = aSteps.GetCount() - 2;
                break;
            case 6:
            case 7:
                nPick = aSteps.GetCount() - 3;
                break;
            case 8:
                nPick = aSteps.GetCount() - 4;
                break;
            case 9:
                nPick = aSteps.GetCount() - 5;
            }
            spOption->m_kSecond.m_range.m_nMin = aSteps[nPick]->m_range.m_nMin;
            spOption->m_kSecond.m_range.m_nMax = aSteps[aSteps.GetCount() - 1]->m_range.m_nMax;
            if (aSteps.GetCount() > 2)
            {
                size_t nLast = aSteps.GetCount() - 1;
                spOption->m_kThird.m_range.m_nMin = aSteps[nLast]->m_range.m_nMin;
                spOption->m_kThird.m_range.m_nMax = aSteps[nLast]->m_range.m_nMax;
            }
        }
        m_aOptions.Add(spOption);
    }
    return 1;
}

// @0x1405bfb80
int CItemMergeOptionData::FUN_1405bfb80()
{
    return m_nProbVer;
}

// @0x1405bfba0
CItemMergeOptionTable::CItemMergeOptionTable()
{
}

// @0x1405bfc10
CItemMergeOptionTable::~CItemMergeOptionTable()
{
}

// @0x1405bfc70
void CItemMergeOptionTable::LoadItemMergeOptionBase()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0("Table", "itemMergeOptionBase.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[{0}]", strPath);
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "mergeOption", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        int nItemType = 0;
        FUN_1408731e0(pNode, "id", nItemType);
        if (nItemType == 0)
            continue;
        for (Unk_140165cf0* pSlot : pNode->FUN_140165cf0("slot"))
        {
            DataPtr spData(new CItemMergeOptionData);
            if (!spData->Load(pSlot))
            {
                Unk_MergeLog(CLogString::GetInstance(), 0, 0, 0x72, L"Invalid Item merge option [ID:{0}, Part:{1}]", nItemType, spData->m_nId);
                continue;
            }
            m_data.insert(std::make_pair(std::make_pair(nItemType, spData->m_nId), spData));
        }
    }
    SetInit(true);
}

// @0x1405c00e0
CItemMergeOptionTable::DataPtr CItemMergeOptionTable::FUN_1405c00e0(int nItemId, int nMaterialId)
{
    CheckInit();
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    MS2Ptr<CItemData> spMaterial = FUN_14053f870(nMaterialId);
    if (spItem.get() == 0 || spMaterial.get() == 0)
        return DataPtr(0);
    DataPtr spData = FUN_1405c1d20(nItemId, nMaterialId);
    if (spData.IsNull())
        return DataPtr(0);
    int nPart = spItem->FUN_14053c620();
    if (spData->m_aPartLimit.GetCount() != 0)
    {
        if (FUN_140408410(&spData->m_aPartLimit, &nPart) == -1)
            return DataPtr(0);
    }
    unsigned short nItemLevel = (unsigned short)spItem->limit.levelLimit;
    if (nItemLevel < 0x32)
        return DataPtr(0);
    if ((unsigned short)spMaterial->limit.levelLimit < nItemLevel)
        return DataPtr(0);
    return spData;
}

// @0x1405c03d0
bool CItemMergeOptionTable::FUN_1405c03d0(int nCategory, int* pNormal)
{
    DataPtr spData = FUN_1405c1f40(nCategory);
    if (spData.IsNull())
        return false;
    for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
    {
        if (spData->m_aOptions[i]->m_nNormal != -1)
        {
            *pNormal = spData->m_aOptions[i]->m_nNormal;
            return true;
        }
    }

    return false;
}

// @0x1405c04f0
bool CItemMergeOptionTable::FUN_1405c04f0(int nCategory, int* pSpecial)
{
    DataPtr spData = FUN_1405c1f40(nCategory);
    if (spData.IsNull())
        return false;
    for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
    {
        if (spData->m_aOptions[i]->m_nSpecial != 0)
        {
            *pSpecial = spData->m_aOptions[i]->m_nSpecial;
            return true;
        }
    }

    return false;
}

// @0x1405c0610
CItemMergeOptionVariation* CItemMergeOptionTable::FUN_1405c0610(int nCategory, int nNormal)
{
    DataPtr spData = FUN_1405c1f40(nCategory);
    if (spData.IsNull())
        return 0;
    for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
    {
        if (spData->m_aOptions[i]->m_nNormal == nNormal)
            return &spData->m_aOptions[i]->m_kFirst;
    }

    return 0;
}

// @0x1405c0740
CItemMergeOptionVariation* CItemMergeOptionTable::FUN_1405c0740(int nCategory, int nSpecial)
{
    DataPtr spData = FUN_1405c1f40(nCategory);
    if (spData.IsNull())
        return 0;
    for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
    {
        if (spData->m_aOptions[i]->m_nSpecial == nSpecial)
            return &spData->m_aOptions[i]->m_kFirst;
    }

    return 0;
}

// @0x1405c0870
// The value of the normal option lies inside the rolled range of the slot's option.
bool CItemMergeOptionTable::FUN_1405c0870(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue)
{
    if (spValue.get() != 0)
    {
        DataPtr spData = FUN_1405c1d20(nItemId, nMaterialId);
        if (!spData.IsNull())
        {
            for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
            {
                if (spData->m_aOptions[i]->m_nNormal == nOption && FUN_1405c7ba0(&spData->m_aOptions[i]->m_kSecond.m_range))
                    return FUN_1403ef200(&spData->m_aOptions[i]->m_kSecond.m_range, spValue->FUN_140266e30());
            }
        }
    }
    return false;
}

// @0x1405c0a70
bool CItemMergeOptionTable::FUN_1405c0a70(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue)
{
    if (spValue.get() != 0)
    {
        DataPtr spData = FUN_1405c1d20(nItemId, nMaterialId);
        if (!spData.IsNull())
        {
            for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
            {
                if (spData->m_aOptions[i]->m_nSpecial == nOption && FUN_1405c7ba0(&spData->m_aOptions[i]->m_kSecond.m_range))
                    return FUN_1403ef200(&spData->m_aOptions[i]->m_kSecond.m_range, spValue->FUN_140266e30());
            }
        }
    }
    return false;
}

// @0x1405c0c70
// The value of the normal option reaches the maximum of the slot's option.
bool CItemMergeOptionTable::FUN_1405c0c70(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue)
{
    if (spValue.get() != 0)
    {
        DataPtr spData = FUN_1405c1d20(nItemId, nMaterialId);
        if (!spData.IsNull())
        {
            for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
            {
                if (spData->m_aOptions[i]->m_nNormal == nOption && FUN_1405c7ba0(&spData->m_aOptions[i]->m_kFirst.m_range))
                {
                    CItemMergeOption* pOption = spData->m_aOptions[i].get();
                    return pOption->m_kFirst.m_range.m_nMax == spValue->FUN_140266e30();
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

// @0x1405c0e80
bool CItemMergeOptionTable::FUN_1405c0e80(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue)
{
    if (spValue.get() != 0)
    {
        DataPtr spData = FUN_1405c1d20(nItemId, nMaterialId);
        if (!spData.IsNull())
        {
            for (size_t i = 0; i < spData->m_aOptions.GetCount(); i++)
            {
                if (spData->m_aOptions[i]->m_nSpecial == nOption && FUN_1405c7ba0(&spData->m_aOptions[i]->m_kFirst.m_range))
                {
                    CItemMergeOption* pOption = spData->m_aOptions[i].get();
                    return pOption->m_kFirst.m_range.m_nMax == spValue->FUN_140266e30();
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

// @0x1405c1090
// MS2-FUNCTIONAL: the string temporaries of the two option loops differ from the exe
CStringW CItemMergeOptionTable::FUN_1405c1090(MS2Ptr<CItem> spItem, int nFlag)
{
    if (spItem.IsNull())
        return CStringW(L"");
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
    if (pStatus == 0)
        return CStringW(L"");
    MS2Ptr<CItemOption> spOption = pStatus->m_spOption;
    if (spOption.IsNull())
        return CStringW(L"");
    bool bSpecial = pStatus->FUN_140630810();
    CStringW strResult;
    CStringW strLines;
    int nMergeId = spOption->FUN_1405cb380();
    CStringW strTag;
    if (FUN_14116d720(FUN_14025e7c0()) && nMergeId != 0)
        strTag = StringFormat(L"[{0}]", FUN_141811980(FUN_1401a9d70(), 1, nMergeId));
    Unk_EnchantMap& rNormal = spOption->FUN_1405cb8a0(4);
    Unk_SocketSpecialMap& rSpecial = spOption->FUN_1405cb8d0(4);
    for (POSITION pos = rNormal.GetStartPosition(); pos != 0; rNormal.GetNext(pos))
    {
        int nStat = rNormal.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spValue = rNormal.GetValueAt(pos);
        if (spValue.get() == 0)
            continue;
        CStringW strLine;
        CStringW strExtra;
        strLine = FUN_1401d0080(FUN_140631600(nStat, spValue.get()), strTag);
        if (FUN_1405c0870(spItem->FUN_1405276c0(), nMergeId, bSpecial, nStat, spValue))
        {
            if (FUN_1405c0c70(spItem->FUN_1405276c0(), nMergeId, bSpecial, nStat, spValue))
                strLine = FUN_14052bd00(0x48d, strLine);
            strLine = FUN_14028dfa0(CStringW(L"s_word_stat_max_color"), strLine);
        }
        if (nFlag == 0)
            return strLine;
        if (FUN_1409c5210(strExtra, spItem, nStat, 4, spValue, strLine))
            strLines.Append(strExtra);
    }
    for (POSITION pos = rSpecial.GetStartPosition(); pos != 0; rSpecial.GetNext(pos))
    {
        int nStat = rSpecial.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spValue = rSpecial.GetValueAt(pos);
        if (spValue.get() == 0)
            continue;
        CStringW strLine = FUN_1401d0080(FUN_140631830(nStat, spValue->FUN_140266e30(), spItem->FUN_140527840()), strTag);
        CStringW strExtra;
        if (FUN_1405c0a70(spItem->FUN_1405276c0(), nMergeId, bSpecial, nStat, spValue))
        {
            if (FUN_1405c0e80(spItem->FUN_1405276c0(), nMergeId, bSpecial, nStat, spValue))
                strLine = FUN_14052bd00(0x48d, strLine);
            strLine = FUN_14028dfa0(CStringW(L"s_word_stat_max_color"), strLine);
        }
        if (nFlag == 0)
            return strLine;
        if (FUN_1409c56f0(strExtra, spItem, nStat, 4, spValue, strLine))
            strLines.Append(strExtra);
    }
    strResult.Append(strLines);
    strResult.TrimRight();
    return strResult;
}

// @0x1405c1d20
CItemMergeOptionTable::DataPtr CItemMergeOptionTable::FUN_1405c1d20(int nItemId, int nMaterialId)
{
    CheckInit();
    MS2Ptr<CItemData> spMaterial = FUN_14053f870(nMaterialId);
    if (spMaterial.get() != 0)
    {
        if (spMaterial->FUN_14053c5c0() == 0x13)
        {
            int nPart = 0;
            if (spMaterial->FUN_14053c5e0() == 1)
            {
                MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
                if (!spItem)
                    return DataPtr(nullptr);
                nPart = spItem->FUN_14053c620();
            }
            std::map<std::pair<int, int>, DataPtr>::iterator it = m_data.find(std::make_pair(spMaterial->FUN_14053de10(), nPart));
            if (it != m_data.end())
                return it->second;
            return DataPtr(nullptr);
        }
    }
    return DataPtr(nullptr);
}

// @0x1405c1f40
CItemMergeOptionTable::DataPtr CItemMergeOptionTable::FUN_1405c1f40(int nCategory)
{
    std::map<std::pair<int, int>, DataPtr>::iterator it = m_data.find(std::make_pair(nCategory, 0));
    if (it != m_data.end())
        return it->second;
    return DataPtr(nullptr);
}

// @0x1405c7ba0
bool FUN_1405c7ba0(const Unk_MergeRange* pRange)
{
    if (pRange->m_nMax < pRange->m_nMin)
        return false;
    if (pRange->m_nMin == 0 && pRange->m_nMax == 0)
        return false;
    return true;
}

// @0x1405c53b0
void CItemMergeOptionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemMergeOptionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1405c79d0
void CItemMergeOptionTable::SetInit(bool b)
{
    s_bInit = b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b190-0x142c9b1f0 .text$yd
