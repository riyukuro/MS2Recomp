// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item socket tables (Table/itemSocket.xml), see
// itemsocketsystemutil.h. The unit also holds CItemStatus / CItemUgc / CItemTransfer and the template glue of its
// containers (not recovered yet).
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\itemsocketsystemutil.cpp
// MS2-RANGE: 0x1400baa10-0x1400bae70 .text$di
// MS2-RANGE: 0x140626a20-0x140635ec0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GEnableSocketUnlockFunction@CItemSocketSystemUtil@@UEAAPEAXI@Z 0x14062c240 ; unique
// MS2-PIN: memmove_s 0x14062c690 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCItemSocketDataContainer@@@@QEAAAEAV1@PEAVCItemSocketDataContainer@@@Z 0x14062e0b0 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCItemSocketData@@@@QEBAPEAVCItemSocketData@@XZ 0x14062e160 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCItemSocketDataContainer@@@@QEBAPEAVCItemSocketDataContainer@@XZ 0x14062e170 ; prop
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemSocketData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemSocketData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemSocketData@@@@_K@Z 0x14062e6b0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItemSocketData@@@@AEBAXPEAX@Z 0x14062f880 ; unique
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140633100 ; unique
// MS2-PIN: ??1?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140633210 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x1406333e0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCItemData@@@@CAXPEAVCItemData@@@Z 0x140633620 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItemTransfer@@@@QEAA@$$QEAV0@@Z 0x140635bf0 ; unique
// MS2-PIN: ??D?$MS2Ptr@VCItemBinding@CItemTransfer@@@@QEBAAEAVCItemBinding@CItemTransfer@@XZ 0x140635e60 ; unique
// MS2-PIN: ??D?$MS2Ptr@VCItemTransfer@@@@QEBAAEAVCItemTransfer@@XZ 0x140635e70 ; unique
// MS2-PIN: ?begin@?$vector@_JV?$allocator@_J@std@@@std@@QEBA?AV?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@_J@std@@@std@@@2@XZ 0x14062c4c0 ; unique
// MS2-PIN: ?end@?$vector@_JV?$allocator@_J@std@@@std@@QEBA?AV?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@_J@std@@@std@@@2@XZ 0x14062c5f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GCItemUgc@@UEAAPEAXI@Z 0x140633490
// MS2-PIN: ??$_Ucopy@PEB_J@?$vector@_JV?$allocator@_J@std@@@std@@AEAAPEA_JPEB_J0PEA_J@Z 0x14062be30
// MS2-PIN: ??_7CItemSocketTable@@6B?$TSingleton@VCItemSocketTable@@@@@ 0x142d6bd60
// MS2-PIN: ?at@?$vector@_JV?$allocator@_J@std@@@std@@QEAAAEA_J_K@Z 0x14062c480
// MS2-PIN: ?at@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEBAAEBV?$MS2Ptr@VCItem@@@@_K@Z 0x14062c440
// MS2-PIN: ??$_Assign_range@PEB_J@?$vector@_JV?$allocator@_J@std@@@std@@AEAAXPEB_J0Uforward_iterator_tag@1@@Z 0x14062b9b0
// MS2-PIN: ?clear@?$vector@_JV?$allocator@_J@std@@@std@@QEAAXXZ 0x14062c520
// MS2-PIN: ?size@?$vector@V?$MS2Ptr@VCItem@@@@V?$allocator@V?$MS2Ptr@VCItem@@@@@std@@@std@@QEBA_KXZ 0x14062c650
// MS2-PIN: ??$FormatStringId@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBV01@0@Z 0x140632a60
// MS2-PIN: ?AssignRaw@?$Unk_EnchantPtr@VCItemEnchantInfo@@@@QEAAAEAV1@PEAVCItemEnchantInfo@@@Z 0x1406332d0
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUnlimitedEnchantInfo@@@@QEAAAEAV1@PEAVUnlimitedEnchantInfo@@@Z 0x140633340
// MS2-PIN: ??D?$MS2Ptr@VCItemBinding@CItemTransfer@@@@QEBAAEAVCItemBinding@CItemTransfer@@XZ 0x140635e60
// MS2-PIN: ??D?$MS2Ptr@VCItemTransfer@@@@QEBAAEAVCItemTransfer@@XZ 0x140635e70
// MS2-PIN: ?_Buy@?$vector@_JV?$allocator@_J@std@@@std@@AEAA_N_K@Z 0x14062c290
// MS2-PIN: memmove_s 0x14062c690
// MS2-PIN: ??$StringFormat@M@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBM@Z 0x1406329c0
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@G@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@1AEBG@Z 0x140632d70
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x1406333e0
// MS2-PIN: ??C?$MS2Ptr@VCItemSocketDataContainer@@@@QEBAPEAVCItemSocketDataContainer@@XZ 0x14062e170
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemsocketsystemutil.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "itemsocketsystemutil.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemgemstonedata.h"
#include "ms2/placeholder/cinpacket.h"
#include <vector>
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include "hook/ms2hook.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/itemutiltransfer.h"

// The header statics of this unit: the sort-name tables of two headers, header_statics_a.h's four, then a second
// copy of the four (two more headers that carry the same statics).
static CString s_strSortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static CString s_strSortNamesC[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// The by-value Delegate argument of FUN_14062a3d0 (the confirm-box result callback): copy = clone the implementation.
// @0x14062c060
template<> inline Delegate<bool(int, const CMsgBoxData&)>::Delegate(const Delegate& o) {
    if (o.m_pImpl == 0) m_pImpl = 0;
    else m_pImpl = o.m_pImpl->vfunc_1();
}

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char*);                      // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char*);                      // NextSiblingElement
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(Unk_140165cf0*);                                 // the element is usable
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned int&);
int FUN_14015f500(Unk_140165cf0*, const char*, int*);
int FUN_140178670(Unk_140165cf0*, const char*, ATL::CAtlArray<int>&);

// Item accessors (the CItem members are declared in citem.h; the rest are unrecovered members taken as free functions).
int FUN_14053c560(void* pData);             // kind of the item data record
void* FUN_140527840(CItem* pItem);          // the item's data record
void* FUN_1405279c0(CItem* pItem);          // the item's enhance record (null for none)
int FUN_140620a20(void* pEnhance);          // enhance level
int FUN_140620a50(void* pEnhance);
unsigned char FUN_1406211f0(void* pEnhance);
unsigned char FUN_140528980(CItem* pItem);
int FUN_140525ca0(CItem* pItem);
int FUN_140525db0(CItem* pItem);
unsigned char FUN_140528e20(CItem* pItem);

// @0x140626aa0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Init(MS2Ptr<CItem> pItem, int nSocketMode, int nUnlockMode)
{
    if (pItem == (CItem*)0 || FUN_1405279c0(pItem.get()) == 0)
        return false;
    m_n18 = FUN_14053c560(FUN_140527840(pItem.get()));
    m_n1C = pItem.get()->FUN_140526bd0();
    m_n20 = pItem.get()->FUN_140526a50();
    m_n28 = FUN_140620a20(FUN_1405279c0(pItem.get()));
    m_nSocketMode = nSocketMode;
    m_nUnlockMode = nUnlockMode;
    return true;
}

// @0x140626bc0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Matches(MS2Ptr<CItem> pItem)
{
    if (pItem == (CItem*)0)
        return false;
    if (m_n20 == (unsigned __int64)pItem.get()->FUN_140526a50())
        return false;
    if (m_n18 != FUN_14053c560(FUN_140527840(pItem.get())) || m_n1C != pItem.get()->FUN_140526bd0())
        return false;
    void* pEnhance = FUN_1405279c0(pItem.get());
    if (pEnhance == 0 || FUN_140620a50(pEnhance) == 0)
        return false;
    if (m_n28 != FUN_140620a20(pEnhance))
        return false;
    if (FUN_140528980(pItem.get()) == 0)
        return false;
    if (FUN_140525ca0(pItem.get()) != 0 && m_nSocketMode == 0)
        return false;
    if (FUN_140525db0(pItem.get()) != 0 && m_nUnlockMode == 0)
        return false;
    if (FUN_140528e20(pItem.get()) != 0)
        return false;
    if (FUN_1406211f0(pEnhance) != 0)
        return false;
    return true;
}

// @0x140626e20
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::InitPair(MS2Ptr<CItem> pItem, MS2Ptr<CItem> pOther, int nSocketMode, int nUnlockMode)
{
    if (!Init(pItem, nSocketMode, nUnlockMode))
        return false;
    return Matches(pOther);
}

// ---- the gemstone upgrade rows and the socket scroll rules (0x140626f20-0x14062c1xx) ----------------------------
// The table singleton (TSingleton<CItemGemStoneUpgradeTable>::s_instance).
extern void* DAT_143aafd18;
class Unk_Random;
class CIngredientContainer;
CItemGemStoneUpgradeTable* FUN_14062c280();
void FUN_14026bd10(CIngredientContainer* pCost, int nCount, int nItemId);       // add an ingredient (0x60 / 0x58 = the item id)
int FUN_1406516b0();                                                // the language / region id
int FUN_140408410(const ATL::CAtlArray<int>& a, const int& nValue);    // the index of a value in an array, else -1
unsigned FUN_140478f60(void* pOwner);                               // the minimum of a stat
void* FUN_1401c0d90();
void* FUN_1401d3200();
int FUN_1406198a0(int nBase, float fRate);                          // (int)(nBase * fRate + 1e-6)
__int64 FUN_140482050(unsigned nBase, unsigned nRate);              // nBase * (1 - nRate / 10000.0)
void* FUN_1401c0db0();
void FUN_140677a70(void* pSvc, int nType, int nGrade, unsigned short nLevel, int nSubType, int* pOut);
int FUN_140673fb0(void* pSvc, double dValue, int nDigits);          // round a value to a number of digits
CStringW FUN_141277410(int nType);                                  // the name of a slot type
CStringW FUN_14028de60(int nStringId);                              // a string table text

// One row of the socket scroll table (names invented; layout read from the validators below).
class Unk_ItemSocketScrollData : public CPtred
{
public:
    int m_pad_18;
    int m_nTargetMask;                      // +0x1c bit 1 / bit 2: the kind of item it can be used on
    unsigned short m_nLevelMin;             // +0x20
    unsigned short m_nLevelMax;             // +0x22 (0 = no upper bound)
    int m_pad_24;
    ATL::CAtlArray<int> m_aSlotKinds;       // +0x28 the item slot kinds it accepts
    ATL::CAtlArray<int> m_aRanks;           // +0x48 the item ranks it accepts
};
MS2_CHECK_OFFSET(Unk_ItemSocketScrollData, m_nTargetMask, 0x1c);
MS2_CHECK_OFFSET(Unk_ItemSocketScrollData, m_aSlotKinds, 0x28);
MS2_CHECK_OFFSET(Unk_ItemSocketScrollData, m_aRanks, 0x48);

void* FUN_140166410();
bool FUN_14036d570(void* pThis, int nId);
bool FUN_140627d70(MS2Ptr<CItemData> spData);
// The socket record of an item (CItemSocket, itemsocket.cpp): members not recovered yet.
int FUN_140620940(void* pEnhance);
int FUN_140620a70(void* pEnhance);
bool FUN_140627930(MS2Ptr<CItemData> spData, MS2Ptr<Unk_ItemSocketScrollData> spScroll);
bool FUN_140627020(MS2Ptr<CItemGemStoneData> spRow);
bool FUN_1406271b0(MS2Ptr<CItemGemStoneData> spRow, short* pMin, short* pMax, int* pError);
int FUN_140627b80(int nA, unsigned nWanted);
int FUN_140627e80(MS2Ptr<CItem> spItem);
int FUN_140628050(MS2Ptr<CItem> spItem);

// @0x140626f20
unsigned short FUN_140626f20(unsigned nId)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FUN_1405b1a60(nId);
    if (spRow == 0)
        return 0;
    return spRow->m_nSlot;
}
MS2_REPLACE(0x140626F20, FUN_140626f20, 123, 0x077283A7);

// @0x140626fb0
bool FUN_140626fb0(unsigned nId)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FUN_1405b1a60(nId);
    return FUN_140627020(spRow);
}
MS2_REPLACE(0x140626FB0, FUN_140626fb0, 105, 0xC554095B);

// @0x140627020
bool FUN_140627020(MS2Ptr<CItemGemStoneData> spRow)
{
    bool bResult;
    if (spRow == 0)
        return false;
    int nLinked = spRow->m_nLinked;
    bResult = nLinked == 0;
    if (!bResult)
    {
        MS2Ptr<CItemGemStoneData> spLinked = FUN_14062c280()->FUN_1405b1a60(nLinked);
        bResult = spLinked == 0 ? true : false;
    }
    return bResult;
}
MS2_REPLACE(0x140627020, FUN_140627020, 225, 0xC4BBD2F2);

// @0x140627110
bool FUN_140627110(unsigned nId, short* pMin, short* pMax, int* pError)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FUN_1405b1a60(nId);
    return FUN_1406271b0(spRow, pMin, pMax, pError);
}
MS2_REPLACE(0x140627110, FUN_140627110, 141, 0x833B2DEF);

// @0x1406271b0
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
bool FUN_1406271b0(MS2Ptr<CItemGemStoneData> spRow, short* pMin, short* pMax, int* pError)
{
    *pMin = 0;
    *pMax = 0;
    *pError = 0;
    if (spRow == 0)
    {
        *pError = 7;
        return false;
    }
    bool bMaxed = FUN_140627020(spRow);
    if (bMaxed)
    {
        *pMin = spRow->m_nSlot;
        *pMax = *pMin;
        *pError = 0x14;
        return false;
    }
    *pMin = spRow->m_nSlot;
    *pMax = *pMin + 1;
    return true;
}
MS2_REPLACE(0x1406271B0, FUN_1406271b0, 308, 0x26C469AB);

// @0x1406272f0
bool FUN_1406272f0(unsigned nMask, MS2Ptr<CItemGemStoneData> spRow)
{
    if (nMask == 0 || spRow == 0)
        return false;
    if ((spRow->m_nMask & nMask) > 0)
        return true;
    return false;
}
MS2_REPLACE(0x1406272F0, FUN_1406272f0, 140, 0x04DF3904);

// @0x140627390
CStringW FUN_140627390(unsigned nId)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FUN_1405b1a60(nId);
    if ((CItemGemStoneData*)spRow)
        return CStringW(spRow->m_strName);
    return CStringW(L"");
}
MS2_REPLACE(0x140627390, FUN_140627390, 174, 0x0188DA8B);

// @0x140627450
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
// The socket scroll can be used on the item: 0 = yes, else the error code of the first rule that fails.
int FUN_140627450(MS2Ptr<CItem> spItem, MS2Ptr<Unk_ItemSocketScrollData> spScroll)
{
    if (spItem == 0)
        return 1;
    if (spScroll == 0)
        return 2;
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    if (spData == 0)
        return 1;
    if (!FUN_140627930(spData, spScroll))
        return 8;
    int nSlotKind = spData->FUN_14053c620();
    if (FUN_140408410(spScroll->m_aSlotKinds, nSlotKind) == -1)
        return 5;
    int nRank = spItem->FUN_140526bd0();
    if (FUN_140408410(spScroll->m_aRanks, nRank) == -1)
        return 6;
    int nLevel = spData->limit.levelLimit;
    if (spScroll->m_nLevelMax == 0)
    {
        if (nLevel < (int)spScroll->m_nLevelMin)
            return 7;
    }
    else
    {
        if (nLevel < (int)spScroll->m_nLevelMin || (int)spScroll->m_nLevelMax < nLevel)
            return 7;
    }
    if (spItem->FUN_1405279c0() != 0 && spItem->FUN_140529560() != 0)
    {
        CItemSocket* pSocket = spItem->FUN_1405279c0();
        if (FUN_140620a50(pSocket) == 0)
            return 3;
        if (FUN_140620a70(pSocket) == 0)
            return 4;
        return 0;
    }
    return 3;
}
MS2_REPLACE(0x140627450, FUN_140627450, 1234, 0xF69E6543);

// @0x140627930
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
bool FUN_140627930(MS2Ptr<CItemData> spData, MS2Ptr<Unk_ItemSocketScrollData> spScroll)
{
    if (spData == 0 || spScroll == 0)
        return false;
    int nKind;
    if (spData->FUN_14053cf90())
        nKind = 2;
    else
        nKind = 1;
    bool bResult = (spScroll->m_nTargetMask & nKind) > 0;
    return bResult;
}
MS2_REPLACE(0x140627930, FUN_140627930, 226, 0xEA957CAF);

// @0x140627a20
int FUN_140627a20(unsigned nFlags, unsigned* pOut, unsigned nWanted)
{
    unsigned nMin = FUN_140478f60(FUN_1401c0d90());
    unsigned nResult = nMin > nWanted ? nMin : nWanted;
    if ((nFlags & 8) > 0)
        nResult = 0;
    *pOut = nResult;
    int nCode = 0;
    if (nResult > 0)
    {
        if (nMin == nResult)
            nCode = 1;
        else
            nCode = 2;
    }
    return nCode;
}
MS2_REPLACE(0x140627A20, FUN_140627a20, 153, 0x5568A8E7);

// @0x140627ac0
int FUN_140627ac0(int nFlag, unsigned* pOut, unsigned nWanted)
{
    unsigned nMin = 0;
    unsigned nResult = nMin > nWanted ? nMin : nWanted;
    if (0 < nFlag)
        nResult = 0;
    *pOut = nResult;
    int nCode = 0;
    if (nResult > 0)
    {
        if (nMin == nResult)
            nCode = 1;
        else
            nCode = 2;
    }
    return nCode;
}
MS2_REPLACE(0x140627AC0, FUN_140627ac0, 135, 0x81AC7E4E);

// @0x140627b50
void FUN_140627b50(int nA, Unk_ItemSocketScrollData* pScroll)
{
    FUN_140627b80(nA, pScroll->m_nTargetMask);
}
MS2_REPLACE(0x140627B50, FUN_140627b50, 35, 0xCFF64D85);

// @0x140627b80
int FUN_140627b80(int nA, unsigned nWanted)
{
    nWanted = nWanted < FUN_1406198a0(10000, *(float*)((char*)FUN_1401d3200() + 0x90fc)) ? nWanted : FUN_1406198a0(10000, *(float*)((char*)FUN_1401d3200() + 0x90fc));
    unsigned nResult = (unsigned)FUN_140482050(nA, nWanted);
    return nResult < 1 ? 1 : nResult;
}
MS2_REPLACE(0x140627B80, FUN_140627b80, 137, 0x9251C7E8);

// @0x140627c10
bool FUN_140627c10(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return false;
    return !reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053cf90();
}
MS2_REPLACE(0x140627C10, FUN_140627c10, 162, 0x0B1DA3C6);

// @0x140627cc0
bool FUN_140627cc0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return false;
    return FUN_140627d70(MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(spItem->FUN_140527840())));
}
MS2_REPLACE(0x140627CC0, FUN_140627cc0, 162, 0x7D4C7F44);

// @0x140627d70
bool FUN_140627d70(MS2Ptr<CItemData> spData)
{
    bool bResult;
    if (spData == 0)
        return false;
    bResult = spData->FUN_14053cf90();
    if (!bResult && spData->FUN_14053d840() == 1)
    {
        MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FUN_1405b1a60(spData->FUN_14053c510());
        bResult = FUN_1406272f0(8, spRow);
    }
    return bResult;
}
MS2_REPLACE(0x140627D70, FUN_140627d70, 259, 0xA98525E6);

// @0x140627e80
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
// The item is an equip with a socket record that is unlocked (and not yet used).
int FUN_140627e80(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return 0;
    if (!reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053cf90())
        return 0;
    if (reinterpret_cast<CItemTransfer*>(spItem->FUN_140527930())->FUN_140635900() == 0)
        return 0;
    if (spItem->FUN_1405279c0() != 0)
    {
        if (spItem->FUN_140529560() != 0)
        {
            if (FUN_140620a20(spItem->FUN_1405279c0()) == 0)
                return 0;
            if (FUN_140620940(spItem->FUN_1405279c0()) != 0)
                return 0;
            if (spItem->FUN_140526160() == 1)
                return 0;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x140627E80, FUN_140627e80, 458, 0xBE0452AB);

// @0x140628050
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
int FUN_140628050(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return 0;
    if (!reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053cf90())
        return 0;
    if (reinterpret_cast<CItemTransfer*>(spItem->FUN_140527930())->FUN_140635900() == 0)
        return 0;
    if (spItem->FUN_1405279c0() != 0)
    {
        if (spItem->FUN_140529560() != 0)
        {
            if (FUN_140620a20(spItem->FUN_1405279c0()) != 0)
                return 0;
            if (FUN_140620940(spItem->FUN_1405279c0()) != 0)
                return 0;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x140628050, FUN_140628050, 411, 0x17EB2A1D);

// @0x140628200
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
int FUN_140628200(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    if (FUN_140627e80(spA) != 0 && FUN_140628050(spB) != 0)
    {
        int nA = FUN_140620a50(spA->FUN_1405279c0());
        int nB = FUN_140620a50(spB->FUN_1405279c0());
        if (nA != nB)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x140628200, FUN_140628200, 322, 0x2F05C1F7);

// @0x140628350
int FUN_140628350()
{
    if (FUN_14036d570(FUN_140166410(), 0xfd))
        return 2;
    return 1;
}
MS2_REPLACE(0x140628350, FUN_140628350, 46, 0x44081EAA);

// @0x140628390
// The ingredients to refine a socket: 0x58 (item 0x2b2) when nCount >= 1, else 0x60 priced by the level.
void FUN_140628390(int nLevel, unsigned short nRate, int nCount, CIngredientContainer* pCost)
{
    if (nCount > 0)
    {
        FUN_14026bd10(pCost, 0x58, 0x2b2);
    }
    else
    {
        int nPrice = 0;
        if (nRate < 0x32)
            nRate = 0x32;
        if (FUN_1406516b0() != 3)
        {
            unsigned short nCap = 0x38;
            nRate = (std::min)(nCap, nRate);
        }
        else
            nRate = 0x32;
        int nZero = 0;
        int nSteps = nRate - 0x32;
        int nOne = 1;
        int nWeight = nLevel - 3;
        int nBase = (std::max)(nSteps, nZero) * 0x14 + 200;
        nPrice = nBase * (std::max)(nWeight, nOne);
        FUN_14026bd10(pCost, 0x60, nPrice);
    }
}
MS2_REPLACE(0x140628390, FUN_140628390, 258, 0xD78D8834);

// @0x1406284a0
void FUN_1406284a0(int nLevel, int nFlag, int* pItemId, int* pPrice)
{
    *pItemId = 0x58;
    *pPrice = 0;
    if (nFlag == 0)
        return;
    *pPrice = nLevel * 200;
}
MS2_REPLACE(0x1406284A0, FUN_1406284a0, 65, 0x4E86E702);

// @0x1406284f0
void FUN_1406284f0(unsigned short nRate, int nCount, int* pItemId, int* pPrice)
{
    *pItemId = 0x60;
    *pPrice = 0;
    if (nCount > 0)
        return;
    if (FUN_1406516b0() == 3)
    {
        if (nRate <= 7)
        {
            *pPrice = nRate * nRate * 100 + 100;
        }
        else
        {
            *pPrice = nRate * nRate * 200 + -0x12c0;
            *pPrice = FUN_140673fb0(FUN_1401c0db0(), (double)*pPrice, -3);
        }
    }
    else
    {
        *pPrice = nRate * 2 + 8;
    }
}
MS2_REPLACE(0x1406284F0, FUN_1406284f0, 209, 0x5C53BEEB);

// @0x1406285d0
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
// The names of the slot kinds in a mask, ", "-separated.
CStringW FUN_1406285d0(unsigned nMask)
{
    if (nMask < 0xf)
    {
        CStringW strSep(L", ");
        CStringW strOut;
        if ((nMask & 1) != 0)
            strOut = FUN_141277410(1);
        if ((nMask & 2) != 0)
        {
            if (!strOut.IsEmpty())
                strOut.Append(strSep);
            strOut.Append(FUN_141277410(2));
        }
        if ((nMask & 4) != 0)
        {
            if (!strOut.IsEmpty())
                strOut.Append(strSep);
            strOut.Append(FUN_141277410(3));
        }
        if ((nMask & 8) != 0)
        {
            if (!strOut.IsEmpty())
                strOut.Append(strSep);
            strOut.Append(FUN_14028de60(0x594));
        }
        return CStringW(strOut);
    }
    return CStringW(L"");
}


// ---- the socket-system packet codecs (0x140628840-0x14062a230) ---------------------------------------------------
// Record layouts are read from the codecs; names invented. Writers take a COutputStream, readers a CInPacket (the
// exe passes its CInputStream subobject at +8).
// The exe calls the itemsocket copy (0x140623630); a local COMDAT would take the CEnchantOption dtor slot here.
template <> MS2Ptr<TSocketGemStoneInfo>::~MS2Ptr();

struct Unk_SSGGemEquip
{
    __int64 m_nItemUid;
    int m_nSlot;
    MS2Ptr<TSocketGemStoneInfo> m_spGem;
};
struct Unk_SSGGemUnequip
{
    __int64 m_nItemUid;
    __int64 m_nGemUid;
    int m_nSlot;
};
struct Unk_SockUidCountSlot
{
    // @0x14062c130
    Unk_SockUidCountSlot() : m_nUid(0), m_nCount(0), m_nSlot(0) {}
    __int64 m_nUid;
    __int64 m_nCount;
    int m_nSlot;
};
struct Unk_SockUidPair
{
    __int64 m_nFirst;
    __int64 m_nSecond;
};
struct Unk_SockUidIntByte
{
    __int64 m_nUid;
    int m_nValue;
    int m_nByte;
};
struct Unk_SockUidList
{
    __int64 m_nUid;
    std::vector<__int64> m_aUids;
};

void FUN_14061ff90(TSocketGemStoneInfo* pInfo, COutputStream& out);
void FUN_140620080(TSocketGemStoneInfo* pInfo, CInputStream& in);
MS2_REPLACE(0x1406285D0, FUN_1406285d0, 616, 0x5E21D38A);

// @0x140628840
void FUN_140628840(Unk_SockUidCountSlot& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nUid);
    out.vfunc_o10_4(v.m_nCount);
    out.vfunc_o10_1(v.m_nSlot);
}
MS2_REPLACE(0x140628840, FUN_140628840, 93, 0x94B22953);

// @0x1406288b0
void FUN_1406288b0(Unk_SockUidCountSlot& v, CInPacket& in)
{
    v.m_nUid = in.vfunc_o8_4();
    v.m_nCount = in.vfunc_o8_4();
    v.m_nSlot = in.vfunc_o8_1();
}
MS2_REPLACE(0x1406288B0, FUN_1406288b0, 149, 0x931EED25);

// @0x140628950
void FUN_140628950(Unk_SSGGemEquip& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nItemUid);
    out.vfunc_o10_1(v.m_nSlot);
    if (v.m_spGem.get() != 0)
    {
        out.vfunc_o10_0(true);
        FUN_14061ff90(v.m_spGem.operator->(), out);
    }
    else
    {
        out.vfunc_o10_0(false);
    }
}
MS2_REPLACE(0x140628950, FUN_140628950, 156, 0x7C5AC520);

// @0x140628a00
void FUN_140628a00(Unk_SSGGemEquip& v, CInPacket& in)
{
    v.m_nItemUid = in.vfunc_o8_4();
    v.m_nSlot = in.vfunc_o8_1();
    bool bGem = in.vfunc_o8_0();
    if (bGem)
    {
        v.m_spGem.AssignRaw(new TSocketGemStoneInfo);
        if (v.m_spGem.get() != 0)
            FUN_140620080(v.m_spGem.operator->(), in);
    }
}
MS2_REPLACE(0x140628A00, FUN_140628a00, 348, 0xF3CBE4F7);

// @0x140628b70
void FUN_140628b70(Unk_SSGGemUnequip& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nItemUid);
    out.vfunc_o10_1(v.m_nSlot);
    out.vfunc_o10_4(v.m_nGemUid);
}
MS2_REPLACE(0x140628B70, FUN_140628b70, 93, 0x3C1A5047);

// @0x140628be0
void FUN_140628be0(Unk_SSGGemUnequip& v, CInPacket& in)
{
    v.m_nItemUid = in.vfunc_o8_4();
    v.m_nSlot = in.vfunc_o8_1();
    v.m_nGemUid = in.vfunc_o8_4();
}
MS2_REPLACE(0x140628BE0, FUN_140628be0, 149, 0x24338E7B);

// @0x140628c80
void FUN_140628c80(Unk_SockUidList& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nUid);
    unsigned char nCount = (unsigned char)v.m_aUids.size();
    out.vfunc_o10_1(nCount);
    for (unsigned char i = 0; i < nCount; i++)
    {
        __int64 nUid = v.m_aUids.at(i);
        out.vfunc_o10_4(nUid);
    }
}
MS2_REPLACE(0x140628C80, FUN_140628c80, 169, 0x708F44EE);

// @0x140628d30
void FUN_140628d30(Unk_SockUidList& v, CInPacket& in)
{
    v.m_nUid = in.vfunc_o8_4();
    v.m_aUids.clear();
    unsigned char nCount = in.vfunc_o8_1();
    v.m_aUids.reserve(nCount);
    for (unsigned char i = 0; i < nCount; i++)
    {
        __int64 nUid = in.vfunc_o8_4();
        v.m_aUids.push_back(nUid);
    }
}
MS2_REPLACE(0x140628D30, FUN_140628d30, 232, 0x60A61AD2);

// @0x140628e20
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
// The uid list of an item list (0 for an empty slot).
void FUN_140628e20(Unk_SockUidList& v, const __int64& nUid, const std::vector<MS2Ptr<CItem> >& aItems)
{
    v.m_nUid = nUid;
    v.m_aUids.clear();
    if (!aItems.empty())
    {
        unsigned __int64 nCount = aItems.size();
        v.m_aUids.reserve(nCount);
        for (unsigned __int64 i = 0; i < nCount; ++i)
        {
            MS2Ptr<CItem> spItem = aItems.at(i);
            if (spItem.get() == 0)
            {
                __int64 nZero = 0;
                v.m_aUids.push_back(nZero);
            }
            else
            {
                __int64 nItemUid = spItem->FUN_140526a50();
                v.m_aUids.push_back(nItemUid);
            }
        }
    }
}
MS2_REPLACE(0x140628E20, FUN_140628e20, 311, 0xF06FA885);

// @0x140628f60
void FUN_140628f60(Unk_SockUidList& v, const __int64& nUid, const std::vector<__int64>& aUids)
{
    v.m_nUid = nUid;
    v.m_aUids.clear();
    if (!aUids.empty())
        v.m_aUids.assign(aUids.begin(), aUids.end());
}
MS2_REPLACE(0x140628F60, FUN_140628f60, 134, 0xAB162D3C);

// @0x140629340
void FUN_140629340(Unk_SockUidPair& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nFirst);
    out.vfunc_o10_4(v.m_nSecond);
}
MS2_REPLACE(0x140629340, FUN_140629340, 68, 0x0FA3158C);

// @0x140629390
void FUN_140629390(Unk_SockUidPair& v, CInPacket& in)
{
    v.m_nFirst = in.vfunc_o8_4();
    v.m_nSecond = in.vfunc_o8_4();
}
MS2_REPLACE(0x140629390, FUN_140629390, 104, 0x1A92EBE0);

// @0x140629f30
void FUN_140629f30(Unk_SockUidIntByte& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nUid);
    out.vfunc_o10_3(v.m_nValue);
    out.vfunc_o10_1(v.m_nByte);
}
MS2_REPLACE(0x140629F30, FUN_140629f30, 92, 0x8D3D87D3);

// @0x140629fa0
void FUN_140629fa0(Unk_SockUidIntByte& v, CInPacket& in)
{
    v.m_nUid = in.vfunc_o8_4();
    v.m_nValue = in.vfunc_o8_3();
    v.m_nByte = in.vfunc_o8_1();
}
MS2_REPLACE(0x140629FA0, FUN_140629fa0, 148, 0xF627C3D9);

// @0x14062a040
void FUN_14062a040(Unk_SockUidPair& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nFirst);
    out.vfunc_o10_4(v.m_nSecond);
}
MS2_REPLACE(0x14062A040, FUN_14062a040, 68, 0x0FA3158C);

// @0x14062a090
void FUN_14062a090(Unk_SockUidPair& v, CInPacket& in)
{
    v.m_nFirst = in.vfunc_o8_4();
    v.m_nSecond = in.vfunc_o8_4();
}

// The messages with a vftable: the shared base codec (uid + byte), then the fields of each message.
struct Unk_SockMsg
{
    void* m_pVtbl;
    __int64 m_nUid;
    int m_nByte;
};
struct Unk_SockMsgI64 : Unk_SockMsg
{
    __int64 m_nExtra;                       // +0x18
};
struct Unk_SockMsgF : Unk_SockMsg
{
    __int64 m_nExtra;                       // +0x18
    float m_fValue;                         // +0x20
};
struct Unk_SockMsgGem : Unk_SockMsg
{
    MS2Ptr<TSocketGemStoneInfo> m_spGem;    // +0x18
    __int64 m_n28;
    int m_nB30;
    bool m_bB34;
};
struct Unk_SockMsgIIL
{
    void* m_pVtbl;
    int m_nB8;                              // +8 (a byte on the wire)
    int m_nC;
    __int64 m_n10;
    int m_n18;
};
struct Unk_SockItemMsg
{
    bool m_bValid;                          // +0
    MS2Ptr<CItem> m_spItem;                 // +8
    int m_nByte;                            // +0x18
};
struct Unk_SockItemPair
{
    MS2Ptr<CItem> m_spA;                    // +0
    MS2Ptr<CItem> m_spB;                    // +0x10
};
struct Unk_SockItemOne
{
    bool m_bFlag;                           // +0
    __int64 m_nUid;                         // +8
    MS2Ptr<CItem> m_spItem;                 // +0x10
    int m_nByte;                            // +0x20
};
MS2_REPLACE(0x14062A090, FUN_14062a090, 104, 0x1A92EBE0);

// @0x140628ff0
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_140628ff0(Unk_SockItemMsg& v, COutputStream& out, bool bTransfer)
{
    if (!(v.m_spItem == 0))
    {
        if (v.m_spItem->FUN_1405279c0() != 0)
        {
            out.vfunc_o10_1(v.m_bValid);
            out.vfunc_o10_4(v.m_spItem->FUN_140526a50());
            if (v.m_bValid)
            {
                out.vfunc_o10_1(v.m_nByte);
                v.m_spItem->FUN_1405279c0()->FUN_1406205e0(out);
                out.vfunc_o10_0(bTransfer);
                if (bTransfer)
                    reinterpret_cast<CItemTransfer*>(v.m_spItem->FUN_140527930())->vfunc_1(out);
            }
        }
    }
}
MS2_REPLACE(0x140628FF0, FUN_140628ff0, 322, 0x2CF4AD29);

// @0x140629140
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_140629140(Unk_SockItemMsg& v, CInPacket& in)
{
    if (!(v.m_spItem == 0))
    {
        if (v.m_spItem->FUN_1405279c0() != 0)
        {
            char cValid = in.vfunc_o8_1();
            v.m_bValid = cValid == 1;
            __int64 nUid = in.vfunc_o8_4();
            if (v.m_bValid)
            {
                v.m_nByte = in.vfunc_o8_1();
                if (v.m_spItem->FUN_140526a50() == nUid)
                {
                    v.m_spItem->FUN_1405279c0()->FUN_140620700(in);
                    if (in.vfunc_o8_0())
                        reinterpret_cast<CItemTransfer*>(v.m_spItem->FUN_140527930())->vfunc_2(in);
                }
            }
        }
    }
}
MS2_REPLACE(0x140629140, FUN_140629140, 502, 0x90571525);

// @0x140629400
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_140629400(Unk_SockItemPair& v, COutputStream& out, int nMode)
{
    if (!(v.m_spA == 0))
    {
        if (v.m_spA->FUN_1405279c0() != 0 && !(v.m_spB == 0))
        {
            if (v.m_spB->FUN_1405279c0() != 0)
            {
                out.vfunc_o10_4(v.m_spA->FUN_140526a50());
                v.m_spA->FUN_1405279c0()->FUN_1406205e0(out);
                out.vfunc_o10_4(v.m_spB->FUN_140526a50());
                v.m_spB->FUN_1405279c0()->FUN_1406205e0(out);
                out.vfunc_o10_0(nMode == 1);
                if (nMode != 0)
                    reinterpret_cast<CItemTransfer*>(v.m_spB->FUN_140527930())->vfunc_1(out);
            }
        }
    }
}
MS2_REPLACE(0x140629400, FUN_140629400, 411, 0x09CAED1C);

// @0x1406295b0
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_1406295b0(Unk_SockItemPair& v, CInPacket& in)
{
    if (!(v.m_spA == 0))
    {
        if (v.m_spA->FUN_1405279c0() != 0 && !(v.m_spB == 0))
        {
            if (v.m_spB->FUN_1405279c0() != 0)
            {
                __int64 nUidA = in.vfunc_o8_4();
                if (v.m_spA->FUN_140526a50() == nUidA)
                {
                    v.m_spA->FUN_1405279c0()->FUN_140620700(in);
                    __int64 nUidB = in.vfunc_o8_4();
                    if (v.m_spB->FUN_140526a50() == nUidB)
                    {
                        v.m_spB->FUN_1405279c0()->FUN_140620700(in);
                        if (in.vfunc_o8_0())
                            reinterpret_cast<CItemTransfer*>(v.m_spB->FUN_140527930())->vfunc_2(in);
                    }
                }
            }
        }
    }
}
MS2_REPLACE(0x1406295B0, FUN_1406295b0, 550, 0x1BE1882E);

// @0x1406297e0
void FUN_1406297e0(Unk_SockMsg& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_nUid);
    out.vfunc_o10_1(v.m_nByte);
}
MS2_REPLACE(0x1406297E0, FUN_1406297e0, 69, 0x6F3F2B16);

// @0x140629830
void FUN_140629830(Unk_SockMsg& v, CInPacket& in)
{
    v.m_nUid = in.vfunc_o8_4();
    v.m_nByte = in.vfunc_o8_1();
}
MS2_REPLACE(0x140629830, FUN_140629830, 107, 0xCFBFF993);

// @0x1406298b0
void FUN_1406298b0(Unk_SockMsgI64& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.vfunc_o10_4(v.m_nExtra);
}
MS2_REPLACE(0x1406298B0, FUN_1406298b0, 59, 0x4EE11B41);

// @0x140629900
void FUN_140629900(Unk_SockMsgI64& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.vfunc_o8_4();
}
MS2_REPLACE(0x140629900, FUN_140629900, 77, 0xA282943C);

// @0x140629960
void FUN_140629960(Unk_SockMsgGem& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.vfunc_o10_1(v.m_bB34);
    out.vfunc_o10_1(v.m_nB30);
    out.vfunc_o10_4(v.m_n28);
    if (v.m_spGem.get() != 0)
    {
        out.vfunc_o10_0(true);
        FUN_14061ff90(v.m_spGem.operator->(), out);
    }
    else
    {
        out.vfunc_o10_0(false);
    }
}
MS2_REPLACE(0x140629960, FUN_140629960, 197, 0x2250C583);

// @0x140629a30
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_140629a30(Unk_SockMsgGem& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_bB34 = in.vfunc_o8_1() == 1;
    v.m_nB30 = in.vfunc_o8_1();
    v.m_n28 = in.vfunc_o8_4();
    bool bGem = in.vfunc_o8_0();
    if (bGem)
    {
        v.m_spGem.AssignRaw(new TSocketGemStoneInfo);
        if (v.m_spGem.get() != 0)
            FUN_140620080(v.m_spGem.operator->(), in);
    }
}
MS2_REPLACE(0x140629A30, FUN_140629a30, 446, 0xEFAC776D);

// @0x140629c00
int FUN_140629c00(Unk_SockMsgGem& v)
{
    if (v.m_spGem.get() != 0)
        return v.m_spGem->m_nGemId;
    return 0;
}
MS2_REPLACE(0x140629C00, FUN_140629c00, 60, 0x86CE9CA5);

// @0x140629c50
void FUN_140629c50(Unk_SockMsgI64& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.vfunc_o10_4(v.m_nExtra);
}
MS2_REPLACE(0x140629C50, FUN_140629c50, 59, 0xF7C3B48D);

// @0x140629ca0
void FUN_140629ca0(Unk_SockMsgI64& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.vfunc_o8_4();
}
MS2_REPLACE(0x140629CA0, FUN_140629ca0, 77, 0x91494D98);

// @0x140629d00
void FUN_140629d00(Unk_SockMsgF& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.vfunc_o10_4(v.m_nExtra);
    out.vfunc_o10_5(v.m_fValue);
}
MS2_REPLACE(0x140629D00, FUN_140629d00, 85, 0x051D76EA);

// @0x140629d60
void FUN_140629d60(Unk_SockMsgF& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.vfunc_o8_4();
    v.m_fValue = in.vfunc_o8_5();
}
MS2_REPLACE(0x140629D60, FUN_140629d60, 121, 0x3D3788D8);

// @0x140629de0
void FUN_140629de0(Unk_SockMsgIIL& v, COutputStream& out)
{
    out.vfunc_o10_1(v.m_nB8);
    out.vfunc_o10_3(v.m_nC);
    out.vfunc_o10_4(v.m_n10);
    out.vfunc_o10_3(v.m_n18);
}
MS2_REPLACE(0x140629DE0, FUN_140629de0, 117, 0x8AFB7A3C);

// @0x140629e60
void FUN_140629e60(Unk_SockMsgIIL& v, CInPacket& in)
{
    v.m_nB8 = in.vfunc_o8_1();
    v.m_nC = in.vfunc_o8_3();
    v.m_n10 = in.vfunc_o8_4();
    v.m_n18 = in.vfunc_o8_3();
}
MS2_REPLACE(0x140629E60, FUN_140629e60, 191, 0xB6E1E065);

// @0x14062a100
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_14062a100(Unk_SockItemOne& v, COutputStream& out)
{
    if (!(v.m_spItem == 0))
    {
        if (v.m_spItem->FUN_1405279c0() != 0)
        {
            out.vfunc_o10_1(v.m_bFlag);
            v.m_nUid = v.m_spItem->FUN_140526a50();
            out.vfunc_o10_4(v.m_nUid);
            out.vfunc_o10_1(v.m_nByte);
            if (v.m_bFlag)
            {
                out.vfunc_o10_3(v.m_spItem->FUN_1405273a0());
                v.m_spItem->FUN_1405279c0()->FUN_1406205e0(out);
            }
        }
    }
}
MS2_REPLACE(0x14062A100, FUN_14062a100, 291, 0x952C6E87);

// @0x14062a230
// MS2-FUNCTIONAL: not byte-identical yet (temp/branch layout differs from the exe)
void FUN_14062a230(Unk_SockItemOne& v, CInPacket& in)
{
    if (!(v.m_spItem == 0))
    {
        if (v.m_spItem->FUN_1405279c0() != 0)
        {
            char cFlag = in.vfunc_o8_1();
            v.m_bFlag = cFlag == 1;
            v.m_nUid = in.vfunc_o8_4();
            v.m_nByte = in.vfunc_o8_1();
            if (v.m_bFlag)
            {
                if (v.m_spItem->FUN_140526a50() == v.m_nUid)
                {
                    int nCount = in.vfunc_o8_3();
                    v.m_spItem->FUN_1405273f0(nCount);
                    v.m_spItem->FUN_1405279c0()->FUN_140620700(in);
                }
            }
        }
    }
}
MS2_REPLACE(0x14062A230, FUN_14062a230, 405, 0x1D985FE6);

class Unk_CmnStrings
{
public:
    CStringW FUN_141811980(int nTable, int nIndex);
    CStringW FUN_141812290(int nBuffId, unsigned short nLevel, CString strKey);
};
Unk_CmnStrings* FUN_1401a9d70();
MS2Ptr<CItem> FUN_141425750(__int64 nUid, bool* pbEquipped);   // the inventory item with this uid
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                      // show it
class Unk_IngTable;
Unk_IngTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_IngTable*, int);                       // the item's name id
void FUN_1412752d0(const CStringW& strKey, int nType);           // system notice by string key
class Unk_ItemEquipData : public CItemData
{
};
int FUN_140620ac0(void* pSocket, unsigned nIndex);                // the gem in socket nIndex (0: empty)
bool FUN_140621020(void* pSocket, int nIndex);                    // socket nIndex is open and empty

// @0x14062a3d0
// Put a gemstone into a socket of spItem (nSlot -1: the first free one): checks, then the confirm box (free, or with
// the fee item and count) whose result goes to cb.
bool FUN_14062a3d0(MS2Ptr<CItem> spItem, int nSlot, MS2Ptr<CItem> spGem, Delegate<bool(int, const CMsgBoxData&)> cb)
{
    if (spItem == (CItem*)0 || spItem->FUN_140527840() == 0 || spGem == (CItem*)0)
        return false;
    void* pSocket = spItem->FUN_1405279c0();
    if (pSocket == 0)
        return false;
    if (FUN_140620a50(pSocket) == 0)
        return false;
    int nMax = FUN_140620a20(pSocket);
    if (nMax == 0) {
        FUN_1412752d0(L"s_itemsocketsystem_error_socket_lock_all", 1);
        return false;
    }
    if (nSlot >= nMax) {
        FUN_1412752d0(L"s_itemsocketsystem_error_socket_lock", 1);
        return false;
    }
    int nTarget = -1;
    if (nSlot == -1) {
        for (unsigned i = 0; i < nMax; i++) {
            int nGem = FUN_140620ac0(pSocket, i);
            if (nGem == 0) {
                nTarget = i;
                break;
            }
        }
    } else {
        if (!FUN_140621020(pSocket, nSlot)) {
            FUN_1412752d0(L"s_itemsocketsystem_error_socket_used", 1);
            return false;
        }
        nTarget = nSlot;
    }
    if (nTarget == -1) {
        FUN_1412752d0(L"s_itemsocketsystem_error_socket_used", 1);
        return false;
    }
    unsigned short nRate = FUN_140626f20(spGem->FUN_1405276c0());
    int nFeeItem = 0;
    int nFeeCount = 0;
    FUN_1406284f0(nRate, spItem->FUN_140527840()->FUN_14053de40(), &nFeeItem, &nFeeCount);
    CStringW strMsg;
    int nSocketNo = nTarget + 1;
    unsigned nFeeName = FUN_1405575b0(FUN_140281980(), nFeeItem);
    if (nFeeCount > 0)
        strMsg = FUN_14028dfa0(L"s_itemsocketsystem_msg_ask_gemstone_put_on", nSocketNo,
                               FUN_1401a9d70()->FUN_141811980(1, nFeeName), nFeeCount);
    else
        strMsg = FUN_14028dfa0(L"s_itemsocketsystem_msg_ask_gemstone_put_on_free", nSocketNo);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strMsg, 0, L"");
    if (spBox == (CMsgBoxData*)0)
        return false;
    spBox->FUN_141a027c0(cb);
    spBox->FUN_141a024a0(0);
    spBox->FUN_1405340b0(spGem->FUN_140526a50());
    spBox->FUN_140533ff0(nTarget);
    FUN_140d73c60(spBox);
    return true;
}
MS2_REPLACE(0x14062A3D0, FUN_14062a3d0, 2007, 0xA6CFDB87);

// @0x14062abb0
// The socket unlock confirm box result: request the unlock (packet 0x88, mode 8) with the box's count and slot.
bool FUN_14062abb0(MS2Ptr<CItem> spItem, const CMsgBoxData& box)
{
    if (spItem == (CItem*)0)
        return false;
    __int64 nUid = spItem->FUN_140526a50();
    if (FUN_141425750(nUid, 0) == (CItem*)0) {
        FUN_1412752d0(L"s_itemsocketsystem_error_invalid_target", 1);
        return false;
    }
    __int64 nCount = box.FUN_141a02f10(0, 0);
    int nSlot = box.FUN_141a02e50(1, 0);
    Unk_SockUidCountSlot kMsg;
    kMsg.m_nCount = nCount;
    kMsg.m_nUid = nUid;
    kMsg.m_nSlot = nSlot;
    COutPacket packet(0x88, 0);
    packet.Encode1(8);
    FUN_140628840(kMsg, packet);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE(0x14062ABB0, FUN_14062abb0, 443, 0xB6C836FB);

class Unk_ItemEnchantData : public CItemStatus {};
CStringW FUN_14028b8e0(const CStringW& str);
class Unk_OptionFactory
{
public:
    MS2Ptr<CItemOption> FUN_1405f4ff0(MS2Ptr<CItemData> spData, int nRank, Unk_Random& kRandom);
};
Unk_OptionFactory* FUN_140166430();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);
CStringW FUN_140631600(int nStat, BaseOption* pBase);
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);

// The first option text of an option record: the first random option, else the first extra one.
// @0x14062b020
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_14062b020(MS2Ptr<CItemOption> spOption)
{
    if (spOption == (CItemOption*)0)
        return CStringW(L"");
    CStringW str;
    Unk_EnchantMap& mapRandom = spOption->FUN_1405cb8a0(0);
    for (POSITION pos = mapRandom.GetStartPosition(); pos; mapRandom.GetNext(pos))
    {
        int nType = mapRandom.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spBase = mapRandom.GetValueAt(pos);
        if (!(spBase == (BaseOption*)0))
            return FUN_140631600(nType, spBase.get());
    }
    Unk_SocketSpecialMap& mapExtra = spOption->FUN_1405cb8d0(0);
    for (POSITION pos = mapExtra.GetStartPosition(); pos; mapExtra.GetNext(pos))
    {
        int nType = mapExtra.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spBase = mapExtra.GetValueAt(pos);
        if (!(spBase == (BaseOption*)0))
            return FUN_140631830(nType, spBase->FUN_140266e30(), 0);
    }
    return str;
}
MS2_REPLACE(0x14062B020, FUN_14062b020, 733, 0x424D87E9);

// @0x14062ad80
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_14062ad80(MS2Ptr<CItem> spItem)
{
    if (!(spItem == (CItem*)0))
    {
        Unk_ItemEnchantData* pStatus = spItem->FUN_1405278a0();
        if (pStatus != 0)
            return FUN_14062b020(spItem->FUN_1405278a0()->m_spOption);
    }
    return CStringW(L"");
}
MS2_REPLACE(0x14062AD80, FUN_14062ad80, 215, 0x5D6DA17D);

// @0x14062aeb0
CStringW FUN_14062aeb0(int nItemId, int nRank)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == (CItemData*)0)
        return CStringW(L"");
    Unk_Random kRandom(0);
    MS2Ptr<CItemOption> spOption = FUN_140166430()->FUN_1405f4ff0(spData, nRank, kRandom);
    return FUN_14062b020(spOption);
}
MS2_REPLACE(0x14062AEB0, FUN_14062aeb0, 351, 0x74D6C1BF);

// @0x14062ae60
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_14062ae60(int nItemId)
{
    return FUN_14062aeb0(nItemId, FUN_14053feb0(nItemId));
}
MS2_REPLACE(0x14062AE60, FUN_14062ae60, 74, 0x2E79F9D4);

// The tooltip row text of a socket: locked or unlocked gemstone row.
// @0x14062b310
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> spSocket)
{
    CStringW str;
    if (spSocket.get() != 0 && spSocket->FUN_14061fbb0())
    {
        MS2Ptr<TSocketGemStoneLock> spSlot = spSocket->FUN_140620280();
        if (spSlot.get() == 0 || spSlot->FUN_140623e20() != 1)
            str = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_unlock_gemstone"));
        else
            str = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_lock_gemstone"));
    }
    return str;
}
MS2_REPLACE(0x14062B310, FUN_14062b310, 472, 0x9DD26D8D);

// @0x14062c280
CItemGemStoneUpgradeTable* FUN_14062c280()
{
    return static_cast<CItemGemStoneUpgradeTable*>(DAT_143aafd18);
}
MS2_REPLACE(0x14062C280, FUN_14062c280, 8, 0x554E67F2);

// @0x14062c7b0
CItemSocketData::CItemSocketData() : m_nGrade(0), m_nMaxCount(0), m_nOpenType(0)
{
}

// @0x14062c830
CItemSocketData::~CItemSocketData()
{
}

// @0x14062c860
CItemSocketDataContainer::CItemSocketDataContainer()
{
}

// @0x14062c8b0
CItemSocketDataContainer::~CItemSocketDataContainer()
{
    m_rows.RemoveAll();
}

// @0x14062c900
MS2Ptr<CItemSocketData> CItemSocketDataContainer::Find(int nGrade)
{
    if (m_rows.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    size_t nRows = m_rows.GetCount();
    MS2Ptr<CItemSocketData> spDefault(0);
    for (size_t i = 0; i < nRows; i++)
    {
        MS2Ptr<CItemSocketData> spRow = m_rows[i];
        if (spRow == (CItemSocketData*)0)
            continue;
        if (spRow->m_nGrade == nGrade)
            return spRow;
        if (spRow->m_nGrade == 0)
            spDefault = spRow;
    }
    return spDefault;
}
MS2_REPLACE_METHOD(0x14062C900, CItemSocketDataContainer, Find, 404, 0x6684FDD1);

// @0x14062caa0
CItemSocketTable::CItemSocketTable() : m_items(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14062cb50
CItemSocketTable::~CItemSocketTable()
{
}

// @0x14062cbc0
// MS2-FUNCTIONAL: first-pass source; temp order and the CString locals are not byte-compared
int CItemSocketTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("itemSocket.xml"));
    FUN_1401d1160(CString(strPath));
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
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("itemSocket"); pNode != 0; pNode = pNode->FUN_140168650("itemSocket"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nItemId = 0;
        FUN_1408731e0(pNode, "id", nItemId);
        if (nItemId == 0)
            continue;
        ContainerPtr spContainer(0);
        if (!m_items.Lookup(nItemId, spContainer))
            spContainer.AssignRaw(new CItemSocketDataContainer);
        MS2Ptr<CItemSocketData> spData(new CItemSocketData);
        if (spData.IsNull())
            continue;
        FUN_14015f500(pNode, "grade", &spData->m_nGrade);
        FUN_140873220(pNode, "maxCount", spData->m_nMaxCount);
        int nOpenType = 0;
        FUN_1408731e0(pNode, "openType", nOpenType);
        spData->m_nOpenType = nOpenType;
        if (nOpenType == 1)
        {
            ATL::CAtlArray<int> range;
            FUN_140178670(pNode, "randomOpenRange", range);
            if (range.GetCount() == 2)
            {
                spData->m_range.m_nMin = range[0];
                spData->m_range.m_nMax = range[1];
            }
        }
        else if (nOpenType == 0)
        {
            unsigned nCount = 0;
            FUN_140873220(pNode, "fixOpenCount", nCount);
            spData->m_range.m_nMin = nCount;
            spData->m_range.m_nMax = nCount;
        }
        spContainer->m_rows.Add(spData);
        Unk_LockGuard guard(m_lock);
        if (guard == 0)
            m_items.SetAt(nItemId, spContainer);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14062CBC0, CItemSocketTable, Load, 1884, 0x1D6D1303);

// @0x14062d330
// MS2-FUNCTIONAL: exe branches 'if (guard) skip' as je+jmp (not jne); rest identical
MS2Ptr<CItemSocketData> CItemSocketTable::Find(unsigned nItemId, int nGrade)
{
    if (m_items.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    MS2Ptr<CItemSocketData> spResult(0);
    ContainerPtr spContainer(0);
    {
        Unk_LockGuard guard(m_lock);
        if (guard == 0 && m_items.Lookup(nItemId, spContainer))
            spResult = spContainer->Find(nGrade);
    }
    return spResult;
}
MS2_REPLACE_METHOD(0x14062D330, CItemSocketTable, Find, 366, 0x63FC37F3);

// @0x14062d4b0
unsigned CItemSocketTable::FUN_14062d4b0(int nSocketId, int nGrade, MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return 0;
    if (!FUN_14062d8d0(spData))
        return 0;
    if (spData->FUN_14053d8c0())
        return 0;
    if (nSocketId == 0)
    {
        int nCount = 0;
        unsigned short nLevel = (unsigned short)spData->limit.levelLimit;
        int nItemType = spData->FUN_14053c620();
        int nSubType = spData->FUN_14053de40();
        FUN_140677a70(FUN_1401c0db0(), nItemType, nGrade, nLevel, nSubType, &nCount);
        return nCount;
    }
    MS2Ptr<CItemSocketData> spRow = Find(nSocketId, nGrade);
    if (spRow == 0)
        return 0;
    return spRow->m_nMaxCount;
}
MS2_REPLACE_METHOD(0x14062D4B0, CItemSocketTable, FUN_14062d4b0, 557, 0x9F3A57AF);

// @0x14062d6f0
// MS2-FUNCTIONAL: exe frame is 0x10 larger (extra 16-byte temp slot); no source form found
unsigned CItemSocketTable::FUN_14062d6f0(int nSocketId, int nGrade, MS2Ptr<CItemData> spData)
{
    unsigned nCount = 0;
    if (nSocketId == 0)
        return 0;
    if (spData == 0)
        return 0;
    if (!FUN_14062d8d0(spData))
        return 1;
    MS2Ptr<CItemSocketData> spRow = Find(nSocketId, nGrade);
    if (spRow == 0)
        return 0;
    if (spRow->m_nOpenType == 0)
        nCount = spRow->m_range.m_nMin;
    return nCount;
}
MS2_REPLACE_METHOD(0x14062D6F0, CItemSocketTable, FUN_14062d6f0, 400, 0x7C262BE8);

// @0x14062d890
bool CItemSocketTable::FUN_14062d890(int nArg1, int nArg2, int nArg3, MS2Ptr<CItem> spItem)
{
    return true;
}

// @0x14062d8d0
bool CItemSocketTable::FUN_14062d8d0(MS2Ptr<CItemData> spData)
{
    bool bEnabled = FUN_14036d570(FUN_140166410(), 0x2e);
    if (bEnabled && (spData.get() != 0 ? true : false))
    {
        if (spData->FUN_14053cf90())
            bEnabled = FUN_14036d570(FUN_140166410(), 0x5e);
    }
    return bEnabled;
}
MS2_REPLACE_METHOD(0x14062D8D0, CItemSocketTable, FUN_14062d8d0, 166, 0xE858BA21);

// @0x14062d980
bool CItemSocketTable::FUN_14062d980(MS2Ptr<CItemData> spData, int nGrade)
{
    if (spData == 0)
        return false;
    int nSocketId = spData->property.socketDataId;
    if (nSocketId == 0)
        return true;
    MS2Ptr<CItemSocketData> spRow = Find(nSocketId, nGrade);
    if (spRow == 0)
        return false;
    unsigned nMax = FUN_14062d4b0(nSocketId, nGrade, spData);
    unsigned nStart = FUN_14062d6f0(nSocketId, nGrade, spData);
    if (nMax > nStart)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14062D980, CItemSocketTable, FUN_14062d980, 454, 0xA0BEA5F1);

// @0x14062db50
int CItemSocketTable::FUN_14062db50()
{
    int nResult = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_items.RemoveAll();
        nResult = Load();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14062DB50, CItemSocketTable, FUN_14062db50, 115, 0x5F0288EB);

// @0x140626a20
CItemSocketSystemUtil::EnableSocketUnlockFunction::EnableSocketUnlockFunction()
    : m_n18(0), m_n1C(0), m_n20(0), m_n28(0), m_nSocketMode(0), m_nUnlockMode(0)
{
}

// @0x14062c160
// ---- CItemTransfer / CItemTransfer::CItemBinding ----------------------------------------------------------------
CItemSocketTable* FUN_14052d200();
void* FUN_140166410();
bool FUN_14036d570(void* pThis, int nId);      // item.cpp: the socket table singleton (TSingleton<CItemSocketTable>::s_instance)

// ---- CItemStatus ------------------------------------------------------------------------------------------------
// Unrecovered helpers of the option / stat text code.
class Unk_SaInfo { };
struct Unk_SaTable { };                                 // the special ability table (0x20 byte rows, DAT_143ab1a40)
extern Unk_SaTable DAT_143ab1a40;
struct Unk_SaRow
{
    void* m_00;
    int m_nValueType;                                   // +0x08 eOptionValue (0 none, 2 percent)
    int m_0c;
    CStringW m_strFormat;                               // +0x10
    CStringW m_strName;                                 // +0x18
};
Unk_SaRow* FUN_140184750(Unk_SaTable* pTable, __int64 nIndex);
bool FUN_14081dcd0(int nSaType);                        // the SA value is a percent
int FUN_14081d9e0(int nSaType);                         // the SA is a skill level up tier (0x4d - 0x5a)
int FUN_14081da20(int nSaType);                         // the tier of it
bool FUN_14082f250(int nStat);                          // the stat value is a percent
CStringW FUN_14082f000(unsigned nStat);                 // the stat name
CStringW FUN_1409e0900(int nValue);
CStringW FUN_1409e0a90(float fValue);
CStringW FUN_1409e0970(int nStat, int nValue);
CStringW FUN_1409e0bf0(int nStat, int nValue);
bool FUN_14080c370(unsigned nTier, unsigned nJob, ATL::CAtlArray<unsigned>& aSa);   // the SA types a tier grants a job
void FUN_140222be0(ATL::CAtlArray<int>& aJobs);         // the job ids
bool FUN_140187930(ATL::CAtlArray<unsigned>& a);        // IsEmpty
unsigned __int64 FUN_140186270(ATL::CAtlArray<unsigned>& a);   // GetCount
unsigned* FUN_140184510(ATL::CAtlArray<unsigned>& a, unsigned __int64 n);   // operator[]
class Unk_ObjTable { };
Unk_ObjTable* FUN_1403ed2d0();
class Unk_Actor { };
Unk_Actor* FUN_141bd0cc0(Unk_ObjTable*);                // the player's actor
int FUN_141654700(Unk_Actor*);                          // its job
class Unk_JobTable { };
Unk_JobTable* FUN_1401d7a50();
int FUN_140644bb0(Unk_JobTable*, int nJob);             // the job's name id
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FormatStringId(int nId, const fmt::ArgList& args);                 // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
Unk_OptionFactory* FUN_140166430();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);
CStringW FUN_140630ea0(int nSaType, unsigned short nValue, CItemData* pData);
__int64 FUN_140632990(__int64 nValue, float fRate);
void FUN_1406334d0(CStringW& str);
void FUN_140892c70(CUgcItemLook* pLook);
void FUN_140892da0(CUgcItemLook* pDest, const CUgcItemLook* pSource);
void FUN_140893070(CUgcItemLook* pLook, COutputStream* pStream);
void FUN_140893250(CUgcItemLook* pLook, CInputStream* pStream);
int FUN_1408934f0(CUgcItemLook* pLook);
int FUN_140893520(CUgcItemLook* pLook);

// @0x14062fa00
CItemStatus::CItemStatus(unsigned nItemId, unsigned nRarity, unsigned nArg)
{
    m_spOption.AssignRaw(new CItemOption(nItemId));
    m_spEnchant.AssignRaw(new CItemEnchantInfo(nItemId, nRarity));
    m_spUnlimited.AssignRaw(new UnlimitedEnchantInfo(nItemId, nRarity));
}

// @0x140631ce0
CItemStatus::CItemStatus(CItemOption* pOption, CItemEnchantInfo* pEnchant, UnlimitedEnchantInfo* pUnlimited)
    : m_spOption(pOption), m_spEnchant(pEnchant), m_spUnlimited(pUnlimited)
{
}

// @0x140631d70
CItemUgc::CItemUgc()
{
    FUN_140631e50();
}

// @0x140631de0
CItemUgc::~CItemUgc()
{
    FUN_140631e50();
}

// @0x140631e50
void CItemUgc::FUN_140631e50()
{
    FUN_140892c70(&m_look);
}
MS2_REPLACE_METHOD(0x140631E50, CItemUgc, FUN_140631e50, 31, 0xB73A08F6);

// @0x140631e80
MS2Ptr<CItemUgc> CItemUgc::FUN_140631e80()
{
    MS2Ptr<CItemUgc> spNew(new CItemUgc());
    FUN_140892da0(&spNew->m_look, &m_look);
    return spNew;
}
MS2_REPLACE_METHOD(0x140631E80, CItemUgc, FUN_140631e80, 196, 0x5C94FB68);

// @0x140631f50
void CItemUgc::FUN_140631f50(COutputStream& out)
{
    FUN_140893070(&m_look, &out);
    m_blueprint.Write(out);
}
MS2_REPLACE_METHOD(0x140631F50, CItemUgc, FUN_140631f50, 65, 0xD959A128);

// @0x140631fa0
void CItemUgc::FUN_140631fa0(CInputStream& in)
{
    FUN_140893250(&m_look, &in);
    m_blueprint.Read(in);
}
MS2_REPLACE_METHOD(0x140631FA0, CItemUgc, FUN_140631fa0, 65, 0xBF3AE4BB);

// @0x140631ff0
void CItemUgc::FUN_140631ff0(CUgcItemLook* pLook)
{
    FUN_140631e50();
    FUN_140892da0(&m_look, pLook);
}
MS2_REPLACE_METHOD(0x140631FF0, CItemUgc, FUN_140631ff0, 51, 0x47EF6E9A);

// @0x140632030
unsigned __int64 CItemUgc::FUN_140632030()
{
    return m_look.m_n18;
}
MS2_REPLACE_METHOD(0x140632030, CItemUgc, FUN_140632030, 15, 0xAC153A31);

// @0x140632050
int CItemUgc::FUN_140632050()
{
    return m_look.m_n60;
}
MS2_REPLACE_METHOD(0x140632050, CItemUgc, FUN_140632050, 14, 0xB1F80757);

// @0x140632070
void CItemUgc::FUN_140632070(CBlueprintItemData* pBlueprint)
{
    m_blueprint.Clear();
    m_blueprint.CopyFrom(*pBlueprint);
}
MS2_REPLACE_METHOD(0x140632070, CItemUgc, FUN_140632070, 62, 0xBB4AA826);

// @0x1406320c0
__int64 CItemUgc::FUN_1406320c0()
{
    return m_blueprint.m_n18;
}
MS2_REPLACE_METHOD(0x1406320C0, CItemUgc, FUN_1406320c0, 18, 0xB95413A9);

// @0x1406320e0
int CItemUgc::FUN_1406320e0()
{
    return m_look.m_n30;
}
MS2_REPLACE_METHOD(0x1406320E0, CItemUgc, FUN_1406320e0, 14, 0x921EE467);

// @0x140632100
CString CItemUgc::FUN_140632100()
{
    return m_look.GetLocalPath();
}
MS2_REPLACE_METHOD(0x140632100, CItemUgc, FUN_140632100, 65, 0x2B0AA445);

// @0x140632150
CStringW CItemUgc::FUN_140632150()
{
    return m_look.m_str28;
}
MS2_REPLACE_METHOD(0x140632150, CItemUgc, FUN_140632150, 66, 0x1C4EBE1A);

// @0x1406321a0
int CItemUgc::FUN_1406321a0()
{
    return FUN_1408934f0(&m_look);
}
MS2_REPLACE_METHOD(0x1406321A0, CItemUgc, FUN_1406321a0, 31, 0xA34D9BC7);

// @0x1406321d0
int CItemUgc::FUN_1406321d0()
{
    return FUN_140893520(&m_look);
}
MS2_REPLACE_METHOD(0x1406321D0, CItemUgc, FUN_1406321d0, 31, 0xA34D9BC7);

// @0x140632200
void CItemUgc::FUN_140632200(CItemUgc* pSource)
{
    if (pSource == 0)
        return;
    FUN_140892da0(&m_look, &pSource->m_look);
}
MS2_REPLACE_METHOD(0x140632200, CItemUgc, FUN_140632200, 55, 0x51B741FA);

// @0x140632240
CItemCustomMusicScore::~CItemCustomMusicScore()
{
}

// @0x1406322c0
MS2Ptr<CItemCustomMusicScore> CItemCustomMusicScore::FUN_1406322c0()
{
    MS2Ptr<CItemCustomMusicScore> spNew(new CItemCustomMusicScore());
    spNew->m_n18 = m_n18;
    spNew->m_n1c = m_n1c;
    spNew->m_str28 = m_str28;
    spNew->m_str20 = m_str20;
    spNew->m_str30 = m_str30;
    spNew->m_n38 = m_n38;
    spNew->m_n40 = m_n40;
    spNew->m_n48 = m_n48;
    spNew->m_note.m_n00 = m_note.m_n00;
    spNew->m_note.m_n08 = m_note.m_n08;
    spNew->m_note.m_n10 = m_note.m_n10;
    spNew->m_note.m_str18 = m_note.m_str18;
    return spNew;
}
MS2_REPLACE_METHOD(0x1406322C0, CItemCustomMusicScore, FUN_1406322c0, 556, 0x32D48641);

// @0x140632500
void CItemCustomMusicScore::FUN_140632500(COutputStream& out)
{
    out.vfunc_o10_3(m_n18);
    out.vfunc_o10_3(m_n1c);
    out.vfunc_o10_8(m_str28);
    out.vfunc_o10_8(m_str20);
    out.vfunc_o10_3(m_note.m_n00);
    out.vfunc_o10_4(m_note.m_n08);
    out.vfunc_o10_1(m_n38);
    out.vfunc_o10_4(m_n40);
    out.vfunc_o10_4(m_n48);
}
MS2_REPLACE_METHOD(0x140632500, CItemCustomMusicScore, FUN_140632500, 267, 0x7A2583B5);

// @0x140632620
void CItemCustomMusicScore::FUN_140632620(CInputStream& in)
{
    m_n18 = in.vfunc_o8_3();
    m_n1c = in.vfunc_o8_3();
    m_str28 = in.vfunc_o8_8();
    m_str20 = in.vfunc_o8_8();
    m_note.m_n00 = in.vfunc_o8_3();
    m_note.m_n08 = in.vfunc_o8_4();
    m_n38 = in.vfunc_o8_1();
    m_n40 = in.vfunc_o8_4();
    m_n48 = in.vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x140632620, CItemCustomMusicScore, FUN_140632620, 344, 0x07AB5DCE);

// @0x140632780
bool CItemCustomMusicScore::FUN_140632780()
{
    if (m_str20.IsEmpty())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140632780, CItemCustomMusicScore, FUN_140632780, 45, 0x11A618AD);

// A market listing's music score (uimeratmarketcommon.cpp passes the record at +0x3a0 of its listing).
struct Unk_MusicScoreInfo
{
    char m_pad00[0x20];
    int m_n20;                                                      // +0x20
    int m_n24;
    CStringW m_str28;                                               // +0x28
    CStringW m_str30;                                               // +0x30
    CString m_str38;                                                // +0x38
    Unk_MusicNoteBlock m_note;                                      // +0x40
};
MS2_CHECK_OFFSET(Unk_MusicScoreInfo, m_note, 0x40);

// @0x1406327c0
void CItemCustomMusicScore::FUN_1406327c0(const Unk_MusicScoreInfo& info)
{
    FUN_1406328c0();
    m_n18 = info.m_n20;
    m_n1c = info.m_n24;
    m_str28 = info.m_str30;
    m_str20 = info.m_str28;
    m_str30 = info.m_str38;
    const Unk_MusicNoteBlock& kNote = info.m_note;
    m_note.m_n00 = kNote.m_n00;
    m_note.m_n08 = kNote.m_n08;
    m_note.m_n10 = kNote.m_n10;
    m_note.m_str18 = kNote.m_str18;
    m_n38 = 1;
}
MS2_REPLACE_METHOD(0x1406327C0, CItemCustomMusicScore, FUN_1406327c0, 246, 0x61EED0DA);

// @0x1406328c0
void CItemCustomMusicScore::FUN_1406328c0()
{
    m_n18 = 0;
    m_n1c = 0;
    m_b70 = 0;
    m_b70b = 0;
    m_n70c = 0;
    m_str20.Empty();
    m_str28.Empty();
    m_str30.Empty();
    m_n38 = 0;
    m_n48 = 0;
    m_n40 = 0;
    m_note.FUN_14052d040();
}
MS2_REPLACE_METHOD(0x1406328C0, CItemCustomMusicScore, FUN_1406328c0, 204, 0x4570B3DE);

// @0x140633280
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CItemStatus::~CItemStatus()
{
}

// @0x14062fbc0
MS2Ptr<CItemStatus> CItemStatus::FUN_14062fbc0()
{
    return MS2Ptr<CItemStatus>(new CItemStatus(m_spOption->FUN_1405caf90(), m_spEnchant->FUN_14058c3b0(), m_spUnlimited->FUN_1408bba60()));
}
MS2_REPLACE_METHOD(0x14062FBC0, CItemStatus, FUN_14062fbc0, 473, 0x2DCD2F3E);

// @0x14062fda0
void CItemStatus::FUN_14062fda0(COutputStream& out)
{
    m_spOption->FUN_1405cbeb0(out);
    m_spEnchant->FUN_14058c9c0(reinterpret_cast<Unk_EnchantWrite&>(out));
    m_spUnlimited->FUN_1408bbd30(out);
}
MS2_REPLACE_METHOD(0x14062FDA0, CItemStatus, FUN_14062fda0, 109, 0x4F2E960D);

// @0x14062fe20
void CItemStatus::FUN_14062fe20(CInputStream& in)
{
    m_spOption->FUN_1405cc190(in);
    m_spEnchant->FUN_14058cb20(reinterpret_cast<Unk_EnchantRead&>(in));
    m_spUnlimited->FUN_1408bbef0(in);
}
MS2_REPLACE_METHOD(0x14062FE20, CItemStatus, FUN_14062fe20, 109, 0xBA262CEC);

// @0x14062fea0
int CItemStatus::FUN_14062fea0(unsigned nType)
{
    int nValue = m_spOption->FUN_1405cb3a0(nType);
    if (FUN_140630dc0(nType))
    {
        int nEnchant = FUN_14062ffb0(nType, 1, 5);
        int nExtra = nEnchant + FUN_14062ffb0(nType, 2, 5);
        if (nType == 0x14)
            nExtra = (int)((float)nExtra * 0.159f);
        nValue += nExtra;
    }
    return nValue;
}
MS2_REPLACE_METHOD(0x14062FEA0, CItemStatus, FUN_14062fea0, 189, 0x47444B3B);

// @0x14062ff70
void CItemStatus::FUN_14062ff70(unsigned nType)
{
    m_spOption->FUN_1405cb440(nType);
}
MS2_REPLACE_METHOD(0x14062FF70, CItemStatus, FUN_14062ff70, 47, 0x04A83391);

// @0x14062ffb0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
int CItemStatus::FUN_14062ffb0(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult = m_spOption->FUN_1405cb3a0(nType);
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb760(nSub, nType);
            if (spBase.get() != 0)
                nResult = spBase->FUN_140266e30();
        }
    }
    if (nWhich == 3 || nWhich == 1)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spEnchant->FUN_14058cde0(nType);
        if (spBase.get() != 0)
        {
            if (!FUN_140630dc0(nType))
            {
                nResult += spBase->FUN_140266e30();
            }
            else
            {
                __int64 nBase = FUN_14062ffb0(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += (int)nScaled;
            }
        }
    }
    if (nWhich == 3 || nWhich == 2)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spUnlimited->FUN_1408bc210(nType);
        if (spBase.get() != 0)
        {
            if (!FUN_140630dc0(nType))
            {
                nResult += spBase->FUN_140266e30();
            }
            else
            {
                __int64 nBase = FUN_14062ffb0(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += (int)nScaled;
            }
        }
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14062FFB0, CItemStatus, FUN_14062ffb0, 717, 0x6B640166);

// @0x140630290
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
int CItemStatus::FUN_140630290(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult = m_spOption->FUN_1405cb440(nType);
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb800(nSub, nType);
            if (spBase.get() != 0)
                nResult = spBase->FUN_140266e30();
        }
    }
    if ((nWhich == 3 || nWhich == 2) && nSub == 5)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spUnlimited->FUN_1408bc2f0(nType);
        if (spBase.get() != 0)
            nResult += spBase->FUN_140266e30();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x140630290, CItemStatus, FUN_140630290, 325, 0x45267C83);

// @0x1406303e0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
float CItemStatus::FUN_1406303e0(unsigned nType)
{
    Unk_EnchantPtr<BaseOption> spBase = m_spEnchant->FUN_14058cde0(nType);
    if (spBase == 0)
    {
        if (FUN_140630dc0(nType))
            return spBase->FUN_140266e10();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1406303E0, CItemStatus, FUN_1406303e0, 197, 0xE7166FB6);

// @0x1406304b0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
bool CItemStatus::FUN_1406304b0(int nSub, int nWhich, unsigned nType)
{
    if (nSub != 5)
    {
        if (nWhich == 0)
        {
            BaseOption* pBase = m_spOption->FUN_1405cb760(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
        else if (nWhich == 1)
        {
            BaseOption* pBase = m_spOption->FUN_1405cb800(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1406304B0, CItemStatus, FUN_1406304b0, 289, 0xE66A0E7F);

// @0x1406305e0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW CItemStatus::FUN_1406305e0(int nSub, unsigned nType, void* pData)
{
    CStringW str;
    Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb800(nSub, nType);
    if (spBase.get() != 0)
    {
        int nValue = spBase->FUN_140266e30();
        str = FUN_140631830(nType, nValue, reinterpret_cast<CItemData*>(pData));
    }
    return str;
}
MS2_REPLACE_METHOD(0x1406305E0, CItemStatus, FUN_1406305e0, 263, 0xC97769C1);

// @0x1406306f0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
void CItemStatus::FUN_1406306f0(int nItemId, int nRank, int nSeed)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.get() == 0)
        return;
    Unk_Random kRandom(nSeed);
    m_spOption = FUN_140166430()->FUN_1405f4ff0(spData, nRank, kRandom);
}
MS2_REPLACE_METHOD(0x1406306F0, CItemStatus, FUN_1406306f0, 280, 0x03F00F7D);

// @0x140630810
bool CItemStatus::FUN_140630810()
{
    return m_spOption->FUN_1405cc410();
}
MS2_REPLACE_METHOD(0x140630810, CItemStatus, FUN_140630810, 39, 0xEC3C6A18);

// @0x140630840
void CItemStatus::FUN_140630840()
{
    if (FUN_140630810())
    {
        m_spOption->FUN_1405cb190(4);
        m_spOption->FUN_1405cb360(0);
    }
}
MS2_REPLACE_METHOD(0x140630840, CItemStatus, FUN_140630840, 88, 0x4E3181F8);

// @0x1406308a0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
bool CItemStatus::FUN_1406308a0(MS2Ptr<CItemStatus> spOther)
{
    if (spOther == (CItemStatus*)0)
        return false;
    bool bChanged = false;
    for (unsigned i = 0; i < 0x23; ++i)
    {
        Unk_EnchantPtr<BaseOption> spSource = spOther->m_spOption->FUN_1405cb760(4, i);
        if (spSource.get() != 0)
        {
            Unk_EnchantPtr<BaseOption> spCopy(new BaseOption());
            spCopy->FUN_140266da0(spSource.get());
            m_spOption->FUN_1405cb200(4, i, spCopy);
            if (m_spOption->FUN_1405cb380() == 0)
                m_spOption->FUN_1405cb360(spOther->m_spOption->FUN_1405cb380());
            bChanged = true;
        }
    }
    for (unsigned i = 0; i < 0xcf; ++i)
    {
        Unk_EnchantPtr<BaseOption> spSource = spOther->m_spOption->FUN_1405cb800(4, i);
        if (spSource.get() != 0)
        {
            Unk_EnchantPtr<BaseOption> spCopy(new BaseOption());
            spCopy->FUN_140266da0(spSource.get());
            m_spOption->FUN_1405cb2a0(4, i, spCopy);
            if (m_spOption->FUN_1405cb380() == 0)
                m_spOption->FUN_1405cb360(spOther->m_spOption->FUN_1405cb380());
            bChanged = true;
        }
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x1406308A0, CItemStatus, FUN_1406308a0, 1103, 0xFA56D793);

// @0x140630d00
unsigned short CItemStatus::FUN_140630d00()
{
    return m_spEnchant->FUN_14058c5f0();
}
MS2_REPLACE_METHOD(0x140630D00, CItemStatus, FUN_140630d00, 39, 0x3E09AE77);

// @0x140630d30
CItemOption* CItemStatus::FUN_140630d30()
{
    return m_spOption;
}
MS2_REPLACE_METHOD(0x140630D30, CItemStatus, FUN_140630d30, 31, 0xF8C26528);

// @0x140630d60
CItemEnchantInfo* CItemStatus::FUN_140630d60()
{
    return m_spEnchant;
}
MS2_REPLACE_METHOD(0x140630D60, CItemStatus, FUN_140630d60, 31, 0xA4FF07D8);

// @0x140630d90
Unk_ItemPlusInfo* CItemStatus::FUN_140630d90()
{
    return reinterpret_cast<Unk_ItemPlusInfo*>(static_cast<UnlimitedEnchantInfo*>(m_spUnlimited));
}
MS2_REPLACE_METHOD(0x140630D90, CItemStatus, FUN_140630d90, 31, 0x7F01B568);

// @0x140630dc0
bool CItemStatus::FUN_140630dc0(int nType)
{
    return nType == 0x1b || nType == 0x1c || nType == 0x14;
}
MS2_REPLACE_METHOD(0x140630DC0, CItemStatus, FUN_140630dc0, 59, 0x69FAA13A);

// @0x140630e10
CStringW FUN_140630e10(int nSaType)
{
    CStringW str;
    str = FUN_140184750(&DAT_143ab1a40, nSaType)->m_strName;
    return str;
}
MS2_REPLACE(0x140630E10, FUN_140630e10, 128, 0x6BB2121D);

// @0x140630ea0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140630ea0(int nSaType, unsigned short nValue, CItemData* pData)
{
    CStringW strResult;
    Unk_Actor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor != 0)
    {
        if (FUN_14081d9e0(nSaType) != 0)
        {
            ATL::CAtlArray<int> aJobs;
            FUN_140222be0(aJobs);
            for (unsigned i = 0; i < aJobs.GetCount(); i++)
            {
                int nJob = aJobs[i];
                bool bMyJob = FUN_141654700(pActor) == nJob;
                if (pData == 0 || pData->FUN_14053c8e0(nJob) != 0)
                {
                    ATL::CAtlArray<unsigned> aSa;
                    FUN_14080c370(FUN_14081da20(nSaType), nJob, aSa);
                    if (!FUN_140187930(aSa))
                    {
                        int nJobName = FUN_140644bb0(FUN_1401d7a50(), nJob);
                        CStringW strJob = FUN_1401a9d70()->FUN_141811980(6, nJobName);
                        CStringW strList;
                        for (unsigned k = 0; k < FUN_140186270(aSa); k++)
                        {
                            unsigned* pSa = FUN_140184510(aSa, k);
                            strList.Append(StringFormat(L", {0}", FUN_1401a9d70()->FUN_141811980(4, *pSa)));
                        }
                        FUN_1406334d0(strList);
                        if (strResult.IsEmpty())
                            strResult.Append(FUN_140630e10(nSaType));
                        CStringW strLine;
                        if (!strResult.IsEmpty())
                            strLine.Append(L"\n   -");
                        unsigned short nTier = nValue;
                        strLine.Append(FUN_14028dfa0(CStringW(L"s_item_opt_sa_skill_levelup_tier_v"), strJob, strList, nTier));
                        if (bMyJob)
                            strLine = FUN_1405c2690(CStringW(L"s_item_opt_sa_skill_levelup_tier_v_active"), strLine);
                        strResult.Append(strLine);
                    }
                }
            }
        }
    }
    return strResult;
}
MS2_REPLACE(0x140630EA0, FUN_140630ea0, 1348, 0xF81FC732);

// @0x1406313f0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_1406313f0(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (!FUN_14082f250(nStat))
        str = FormatStringId(0x48b, FUN_14082f000(nStat), FUN_1409e0900(pBase->FUN_140266e30()));
    else
        str = FormatStringId(0x48b, FUN_14082f000(nStat), FUN_1409e0a90(pBase->FUN_140266e10()));
    return str;
}
MS2_REPLACE(0x1406313F0, FUN_1406313f0, 515, 0x242D2E53);

// @0x140631600
CStringW FUN_140631600(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (!(!FUN_14082f250(nStat)))
        str = FUN_1409e0bf0(nStat, pBase->FUN_140266e30());
    else
        str = FUN_1409e0970(nStat, pBase->FUN_140266e30());
    return str;
}
MS2_REPLACE(0x140631600, FUN_140631600, 274, 0xEA930C7D);

// @0x140631720
CStringW FUN_140631720(int nStat, int nValue, bool bPercent)
{
    CStringW str;
    if (bPercent)
        str = FUN_1409e0bf0(nStat, nValue);
    else
        str = FUN_1409e0970(nStat, nValue);
    return str;
}
MS2_REPLACE(0x140631720, FUN_140631720, 256, 0x7787FE96);

// @0x140631830
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData)
{
    CStringW str;
    if (!FUN_14081dcd0(nStat))
    {
        if (FUN_14081d9e0(nStat) != 0)
            return FUN_140630ea0(nStat, nValue, pData);
        str = StringFormat(FUN_140184750(&DAT_143ab1a40, nStat)->m_strFormat, nValue);
    }
    else
    {
        float fValue = (float)nValue / 10.0f;
        str = StringFormat(FUN_140184750(&DAT_143ab1a40, nStat)->m_strFormat, fValue);
    }
    return str;
}
MS2_REPLACE(0x140631830, FUN_140631830, 437, 0xF776E1D4);

// @0x1406319f0
CStringW FUN_1406319f0(int nBuffId, unsigned short nLevel)
{
    CStringW str;
    str = FUN_1401a9d70()->FUN_141812290(nBuffId, nLevel, CString("name"));
    return str;
}
MS2_REPLACE(0x1406319F0, FUN_1406319f0, 240, 0xFB0E0A77);

// @0x140631af0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140631af0(int nStat, Unk_EnchantPtr<BaseOption> spBase, CItemStatus* pStatus)
{
    CStringW strResult;
    if (spBase->FUN_140266ce0())
    {
        __int64 nBase = pStatus->FUN_14062ffb0(nStat, 0, 0);
        float fBase = (float)nBase;
        unsigned __int64 nExtra = (unsigned __int64)(fBase * spBase->FUN_140266e10());
        CStringW strUnused;
        if (nExtra == 0)
            strResult = FormatStringId(0x48c, FUN_14082f000(nStat));
        else
            strResult = FUN_1409e0970(nStat, (int)nExtra);
    }
    return strResult;
}
MS2_REPLACE(0x140631AF0, FUN_140631af0, 475, 0xFEACA2BC);

// @0x1406334d0
void FUN_1406334d0(CStringW& str)
{
    if (str.IsEmpty())
        return;
    if (str[0] == L',')
        str = str.Mid(1);
    if (str.IsEmpty())
        return;
    if (str[str.GetLength() - 1] == L',')
        str = str.Mid(0, str.GetLength() - 1);
}
MS2_REPLACE(0x1406334D0, FUN_1406334d0, 264, 0x8473584E);

// @0x140632990
__int64 FUN_140632990(__int64 nValue, float fRate)
{
    return (__int64)((double)nValue * (double)fRate + 0.5);
}
MS2_REPLACE(0x140632990, FUN_140632990, 42, 0xC9ADCF11);

// The per-action "can the item be X'd" checks: the item must exist, its transfer
// (trade/bind) state must allow it, its gem sockets must allow it, and for some
// actions the enchant record must allow it too. The reason variants report which
// part refused (1 = transfer/enchant, 2 = socket).
class Unk_ItemOwnerRef : public CItemTransfer {};
bool FUN_140633e40(MS2Ptr<CItem> spItem, int* pReason);
bool FUN_140633fb0(MS2Ptr<CItem> spItem, int* pReason);
bool FUN_140634120(MS2Ptr<CItem> spItem, int* pReason);
bool FUN_140634290(MS2Ptr<CItem> spItem, int* pReason);

// @0x140633700
bool FUN_140633700(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635520() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622750() == 0)
        return false;
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->FUN_140630d60();
    if (pEnchant != 0 && pEnchant->FUN_14058c9a0() == false)
        return false;
    return true;
}
MS2_REPLACE(0x140633700, FUN_140633700, 302, 0x29CDDF00);

// @0x140633840
bool FUN_140633840(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_1406354d0() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622720() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140633840, FUN_140633840, 221, 0x7431F417);

// @0x140633930
bool FUN_140633930(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635580() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622780() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140633930, FUN_140633930, 221, 0x7B0A99FE);

// @0x140633a20
bool FUN_140633a20(MS2Ptr<CItem> spItem)
{
    int nReason = 0;
    return FUN_140633e40(spItem, &nReason);
}
MS2_REPLACE(0x140633A20, FUN_140633a20, 95, 0x4EE47894);

// @0x140633a90
bool FUN_140633a90(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635630() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_1406227c0() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140633A90, FUN_140633a90, 221, 0x8E6352DF);

// @0x140633b80
bool FUN_140633b80(MS2Ptr<CItem> spItem)
{
    int nReason = 0;
    return FUN_140633fb0(spItem, &nReason);
}
MS2_REPLACE(0x140633B80, FUN_140633b80, 95, 0x84758196);

// @0x140633bf0
bool FUN_140633bf0(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635770() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622820() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140633BF0, FUN_140633bf0, 221, 0xC088C53D);

// @0x140633ce0
bool FUN_140633ce0(MS2Ptr<CItem> spItem)
{
    int nReason = 0;
    return FUN_140634120(spItem, &nReason);
}
MS2_REPLACE(0x140633CE0, FUN_140633ce0, 95, 0x329E53DE);

// @0x140633d50
bool FUN_140633d50(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_1406358c0() == 0)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622880() == 0)
        return false;
    return true;
}
MS2_REPLACE(0x140633D50, FUN_140633d50, 221, 0x00269DAF);

// @0x140633e40
bool FUN_140633e40(MS2Ptr<CItem> spItem, int* pReason)
{
    *pReason = 0;
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635590() == 0)
    {
        *pReason = 1;
        return false;
    }
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622790() == 0)
    {
        *pReason = 2;
        return false;
    }
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->FUN_140630d60();
    if (pEnchant != 0 && pEnchant->FUN_14058c9a0() == false)
    {
        *pReason = 1;
        return false;
    }
    return true;
}
MS2_REPLACE(0x140633E40, FUN_140633e40, 351, 0x4DA816AE);

// @0x140633fb0
bool FUN_140633fb0(MS2Ptr<CItem> spItem, int* pReason)
{
    *pReason = 0;
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635690() == 0)
    {
        *pReason = 1;
        return false;
    }
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_1406227f0() == 0)
    {
        *pReason = 2;
        return false;
    }
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->FUN_140630d60();
    if (pEnchant != 0 && pEnchant->FUN_14058c9a0() == false)
    {
        *pReason = 1;
        return false;
    }
    return true;
}
MS2_REPLACE(0x140633FB0, FUN_140633fb0, 351, 0xF045CBEF);

// @0x140634120
bool FUN_140634120(MS2Ptr<CItem> spItem, int* pReason)
{
    *pReason = 0;
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635870() == 0)
    {
        *pReason = 1;
        return false;
    }
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622850() == 0)
    {
        *pReason = 2;
        return false;
    }
    return true;
}
MS2_REPLACE(0x140634120, FUN_140634120, 259, 0xC62C7B4D);

// @0x140634230
bool FUN_140634230(MS2Ptr<CItem> spItem)
{
    int nReason;
    return FUN_140634290(spItem, &nReason);
}
MS2_REPLACE(0x140634230, FUN_140634230, 87, 0x70A27980);

// The item is bound (by transfer state or socketed gems); pReason says which.
// @0x140634290
bool FUN_140634290(MS2Ptr<CItem> spItem, int* pReason)
{
    *pReason = 0;
    if (spItem == (CItem*)0)
    {
        *pReason = 1;
        return false;
    }
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635940() == true)
    {
        *pReason = 1;
        return true;
    }
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_1406228d0() == true)
    {
        *pReason = 2;
        return true;
    }
    return false;
}
MS2_REPLACE(0x140634290, FUN_140634290, 278, 0xA3E57979);

// @0x1406343b0
bool FUN_1406343b0(MS2Ptr<CItem> spItem, const __int64* pCharacterId)
{
    if (spItem == (CItem*)0)
        return false;
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    if (pTransfer != 0 && pTransfer->FUN_140635980(pCharacterId) == false)
        return false;
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622a00(pCharacterId) == false)
        return false;
    return true;
}
MS2_REPLACE(0x1406343B0, FUN_1406343b0, 242, 0x380B7BEC);

// Whether the character may take the item; on refusal fills the binding owner.
// @0x1406344b0
bool FUN_1406344b0(MS2Ptr<CItem> spItem, const __int64* pCharacterId, ItemUtilTransfer::TOutBindingParam* pOut)
{
    pOut->kind = 0;
    if (spItem == (CItem*)0)
    {
        pOut->kind = 1;
        return false;
    }
    Unk_ItemOwnerRef* pTransfer = spItem->FUN_140527930();
    bool bBound = false;
    if (pTransfer != 0 && pTransfer->FUN_140635940())
    {
        if ((unsigned __int64)spItem->FUN_140527930()->FUN_140635160()->FUN_14052d1c0() > 0)
            bBound = true;
    }
    if (spItem->FUN_140527840()->FUN_14053d7c0())
        bBound = true;
    if (bBound && pTransfer != 0 && pTransfer->FUN_140635980(pCharacterId) == false)
    {
        pOut->kind = 1;
        pTransfer->FUN_1406359c0(&pOut->characterId, &pOut->name);
        return false;
    }
    CItemSocket* pSocket = spItem->FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140622a00(pCharacterId) == false)
    {
        pOut->kind = 2;
        pSocket->FUN_140622b40(&pOut->characterId, &pOut->name);
        return false;
    }
    return true;
}
MS2_REPLACE(0x1406344B0, FUN_1406344b0, 487, 0xAC86C104);

// @0x1406346a0
void CItemTransfer::CItemBinding::FUN_1406346a0(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    out.vfunc_o10_8(m_str20);
}

// @0x140634700
void CItemTransfer::CItemBinding::FUN_140634700(CInputStream& in)
{
    m_n18 = in.vfunc_o8_4();
    m_str20 = in.vfunc_o8_8();
}

// @0x140634790
bool CItemTransfer::CItemBinding::FUN_140634790(void* pId)
{
    return reinterpret_cast<void*>(m_n18) == pId;
}

// @0x1406347d0
bool CItemTransfer::CItemBinding::FUN_1406347d0(const __int64& nId, const CStringW& strName)
{
    m_n18 = nId;
    m_str20 = strName;
    return true;
}

// @0x140635c90
CItemTransfer::CItemBinding& CItemTransfer::CItemBinding::operator=(const CItemBinding& o)
{
    CPtred::operator=(o);
    m_n18 = o.m_n18;
    m_str20 = o.m_str20;
    return *this;
}

// @0x140634820
CItemTransfer::CItemTransfer()
    : m_pItem(0), m_nRule(0), m_n24(0), m_nType(0), m_b2C(0), m_nCount(0), m_nMax(0), m_b38(0), m_b39(0), m_b3A(0),
      m_b3B(0), m_b3C(0), m_b3D(0), m_b3E(0), m_b3F(0), m_b40(0), m_b41(0), m_b42(0)
{
}

// @0x140634930
CItemTransfer::~CItemTransfer()
{
}

// @0x140634970
void CItemTransfer::FUN_140634970(CItem* pItem)
{
    m_pItem = pItem;
}
MS2_REPLACE_METHOD(0x140634970, CItemTransfer, FUN_140634970, 25, 0xAB8BF0FB);

// @0x140634990
// MS2-FUNCTIONAL: MS2Ptr temp and extra local layout differ from the exe
void CItemTransfer::FUN_140634990(CItem* pItem)
{
    m_pItem = pItem;
    if (m_pItem != 0)
    {
        CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
        if (pData != 0)
        {
            m_nType = pData->limit.transferType;
            m_b39 = (unsigned char)pData->limit.shopSell;
            if (pData->limit.enableBreak == 0)
                m_b3E = 1;
            m_b3A = pData->FUN_14053db80() ? true : false;
            m_nCount = pData->FUN_14053d800() ? 1 : 0;
            int nId = pItem->FUN_140526bd0();
            m_b41 = FUN_14052d200()->FUN_14062d980(MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(pItem->FUN_140527840())), nId);
            m_b42 = m_b41;
            FUN_140635a60();
        }
    }
}
MS2_REPLACE_METHOD(0x140634990, CItemTransfer, FUN_140634990, 401, 0x66C6DDFC);

// @0x140634b30
// MS2-FUNCTIONAL: clone temp layout differs from the exe
MS2Ptr<CItemTransfer> CItemTransfer::FUN_140634b30()
{
    MS2Ptr<CItemTransfer> spNew(new CItemTransfer);
    *spNew = *this;
    if (m_spBinding.get() != 0)
    {
        MS2Ptr<CItemBinding> spBinding(new CItemBinding);
        *spBinding = *m_spBinding;
        (*spNew).m_spBinding = spBinding;
    }
    return spNew;
}
MS2_REPLACE_METHOD(0x140634B30, CItemTransfer, FUN_140634b30, 386, 0x652A96FC);

// @0x140634cc0
int CItemTransfer::FUN_140634cc0()
{
    if (m_pItem == 0)
        return 0;
    if (m_pItem->FUN_140527030() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140634CC0, CItemTransfer, FUN_140634cc0, 57, 0xF1D55D66);

// @0x140634d00
// MS2-FUNCTIONAL: stack frame differs (flag temp)
void CItemTransfer::vfunc_1(COutputStream& out)
{
    out.vfunc_o10_3(m_nRule);
    out.vfunc_o10_0(m_b38);
    out.vfunc_o10_3(m_nCount);
    out.vfunc_o10_3(m_nMax);
    out.vfunc_o10_1(m_b3F);
    out.vfunc_o10_1(m_b42);
    if (m_spBinding.get() == 0 || FUN_140635100() == 0)
    {
        out.vfunc_o10_0(false);
    }
    else
    {
        out.vfunc_o10_0(true);
        m_spBinding->FUN_1406346a0(out);
    }
}
MS2_REPLACE_METHOD(0x140634D00, CItemTransfer, vfunc_1, 288, 0xD1BB41E7);

// @0x140634e30
// MS2-FUNCTIONAL: CInputStream::vfunc_o8_1 is declared unsigned char (stream.h); the exe tests the byte without widening
void CItemTransfer::vfunc_2(CInputStream& in)
{
    m_nRule = in.vfunc_o8_3();
    m_b38 = in.vfunc_o8_0();
    m_nCount = in.vfunc_o8_3();
    m_nMax = in.vfunc_o8_3();
    m_b3F = in.vfunc_o8_1() != 0;
    m_b42 = in.vfunc_o8_1() != 0;
    if (in.vfunc_o8_0())
    {
        m_spBinding.AssignRaw(new CItemBinding);
        m_spBinding->FUN_140634700(in);
    }
}
MS2_REPLACE_METHOD(0x140634E30, CItemTransfer, vfunc_2, 352, 0xD2333264);

// @0x140634fa0
int CItemTransfer::FUN_140634fa0()
{
    return m_nCount;
}
MS2_REPLACE_METHOD(0x140634FA0, CItemTransfer, FUN_140634fa0, 14, 0x828204CF);

// @0x140634fc0
void CItemTransfer::FUN_140634fc0(unsigned n)
{
    m_nCount = n;
}
MS2_REPLACE_METHOD(0x140634FC0, CItemTransfer, FUN_140634fc0, 22, 0x16BC4503);

// @0x140634fe0
int CItemTransfer::FUN_140634fe0()
{
    return m_nMax;
}
MS2_REPLACE_METHOD(0x140634FE0, CItemTransfer, FUN_140634fe0, 14, 0x9A8B24F3);

// @0x140635000
void CItemTransfer::FUN_140635000(unsigned n)
{
    m_nMax = n;
}
MS2_REPLACE_METHOD(0x140635000, CItemTransfer, FUN_140635000, 22, 0xFEAFFEDF);

// @0x140635020
int CItemTransfer::FUN_140635020()
{
    if ((m_nRule & 0x10) != 0 && m_nCount > 0)
    {
        --m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635020, CItemTransfer, FUN_140635020, 59, 0x48337623);

// @0x140635070
int CItemTransfer::FUN_140635070()
{
    if (m_pItem == 0)
        return 0;
    if ((m_nRule & 0x10) != 0)
    {
        if (m_nCount > 0)
            return 0;
        if (m_nMax >= (int)m_pItem->FUN_1405274e0())
            return 0;
        ++m_nMax;
        ++m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635070, CItemTransfer, FUN_140635070, 133, 0x995E53BE);

// @0x140635100
unsigned CItemTransfer::FUN_140635100()
{
    return m_nRule & 8;
}
MS2_REPLACE_METHOD(0x140635100, CItemTransfer, FUN_140635100, 17, 0xB9EB22D4);

// @0x140635120
int CItemTransfer::FUN_140635120()
{
    return m_spBinding.get() != 0 ? 1 : 0;
}
MS2_REPLACE_METHOD(0x140635120, CItemTransfer, FUN_140635120, 58, 0x06ED1646);

// @0x140635160
CItemTransfer::CItemBinding* CItemTransfer::FUN_140635160()
{
    return m_spBinding.get();
}
MS2_REPLACE_METHOD(0x140635160, CItemTransfer, FUN_140635160, 31, 0x379A5C2F);

// @0x140635190
int CItemTransfer::FUN_140635190()
{
    return m_nType;
}
MS2_REPLACE_METHOD(0x140635190, CItemTransfer, FUN_140635190, 14, 0xD26D6807);

// @0x1406351b0
bool CItemTransfer::FUN_1406351b0()
{
    switch (m_nType)
    {
    case 3:
    case 4:
        return true;
    default:
        return false;
    }
}
MS2_REPLACE_METHOD(0x1406351B0, CItemTransfer, FUN_1406351b0, 45, 0x9C2A80F2);

// @0x1406351f0
unsigned char CItemTransfer::FUN_1406351f0(void* pId, void* pName)
{
    m_spBinding.AssignRaw(new CItemBinding);
    if (m_spBinding.get() != 0)
        return m_spBinding->FUN_1406347d0(*static_cast<const __int64*>(pId), *static_cast<const CStringW*>(pName));
    return 0;
}
MS2_REPLACE_METHOD(0x1406351F0, CItemTransfer, FUN_1406351f0, 175, 0x3EF4D3CA);

// @0x1406352b0
unsigned char CItemTransfer::FUN_1406352b0()
{
    m_pItem->vfunc_5(true);
    m_spBinding = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406352B0, CItemTransfer, FUN_1406352b0, 61, 0x61774D6B);

// @0x140635300
void CItemTransfer::FUN_140635300()
{
    m_b3F = 1;
}
MS2_REPLACE_METHOD(0x140635300, CItemTransfer, FUN_140635300, 15, 0x03EFC008);

// @0x140635320
void CItemTransfer::FUN_140635320(bool b)
{
    m_b40 = 1;
    m_b42 = b;
}
MS2_REPLACE_METHOD(0x140635320, CItemTransfer, FUN_140635320, 32, 0xB7D9EF8D);

// The binding owner's name: the actor's own name when the actor is the owner, else the stored name.
// @0x140635350
void CItemTransfer::FUN_140635350(PCBase* pPc, CStringW* pName)
{
    CItemBinding* pBinding = FUN_140635160();
    if (pBinding != 0)
    {
        if (pPc != 0 && pPc->FUN_141656a80() == pBinding->FUN_14052d1c0())
        {
            *pName = pPc->vfunc_77();
            return;
        }
        *pName = pBinding->FUN_14052d1b0();
    }
}
MS2_REPLACE_METHOD(0x140635350, CItemTransfer, FUN_140635350, 196, 0x7287F0A9);

// @0x140635470
bool CItemTransfer::FUN_140635470(const __int64* pId)
{
    if (m_spBinding.get() != 0)
    {
        if (!m_spBinding->FUN_140634790(reinterpret_cast<void*>(*pId)))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140635470, CItemTransfer, FUN_140635470, 87, 0x4FDB0514);

// @0x140635420
bool FUN_140635420(CItemTransfer* pTransfer, PCBase* pPc)
{
    if (pPc != 0)
    {
        __int64 nId = pPc->FUN_141656a80();
        return pTransfer->FUN_140635470(&nId);
    }
    return true;
}
MS2_REPLACE(0x140635420, FUN_140635420, 61, 0x538A89AA);

// @0x1406354d0
int CItemTransfer::FUN_1406354d0()
{
    if (m_pItem == 0)
        return false;
    if (m_b39 == 0)
        return false;
    if (FUN_140635870() == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406354D0, CItemTransfer, FUN_1406354d0, 70, 0x2CA2E2B6);

// @0x140635520
unsigned CItemTransfer::FUN_140635520()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    return m_nRule & 4;
}
MS2_REPLACE_METHOD(0x140635520, CItemTransfer, FUN_140635520, 79, 0x47E3BE8B);

// @0x140635580
int CItemTransfer::FUN_140635580()
{
    return 0;
}
MS2_REPLACE_METHOD(0x140635580, CItemTransfer, FUN_140635580, 8, 0x7F371472);

// @0x140635590
unsigned CItemTransfer::FUN_140635590()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    unsigned nResult = 0;
    if ((m_nRule & 0x10) != 0)
        nResult = 0 < m_nCount ? 1 : 0;
    if (nResult == 0)
        nResult = m_nRule & 4;
    return nResult;
}
MS2_REPLACE_METHOD(0x140635590, CItemTransfer, FUN_140635590, 154, 0xE947292A);

// @0x140635630
int CItemTransfer::FUN_140635630()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if ((m_nRule & 0x10) == 0)
        return 0;
    if (m_nCount == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140635630, CItemTransfer, FUN_140635630, 89, 0xAC2D2E1A);

// @0x140635690
unsigned CItemTransfer::FUN_140635690()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (m_pItem == 0)
        return 0;
    if (m_pItem->FUN_140525790())
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    unsigned nResult = 0;
    if ((m_nRule & 0x10) != 0)
        nResult = 0 < m_nCount ? 1 : 0;
    if (nResult == 0)
        nResult = m_nRule & 4;
    return nResult;
}
MS2_REPLACE_METHOD(0x140635690, CItemTransfer, FUN_140635690, 204, 0x23D70D12);

// @0x140635770
int CItemTransfer::FUN_140635770()
{
    if (m_pItem == 0)
        return 0;
    if (m_b3F != 0)
        return 0;
    if (m_b3E != 0)
        return 0;
    if (m_pItem->FUN_140525ca0() != 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    if (m_pItem->FUN_1405258b0() != 0)
    {
        if (!FUN_14036d570(FUN_140166410(), 0x3a))
            return 0;
        if (m_pItem->FUN_140525f10() != 0 && m_pItem->FUN_1405279c0() != 0)
        {
            if (FUN_140620a20(m_pItem->FUN_1405279c0()) == 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140635770, CItemTransfer, FUN_140635770, 235, 0xAE1E60FC);

// @0x140635870
int CItemTransfer::FUN_140635870()
{
    if (m_pItem == 0)
        return false;
    if (m_pItem->FUN_140528e20() == true)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140635870, CItemTransfer, FUN_140635870, 61, 0xD0B35AF7);

// @0x1406358c0
int CItemTransfer::FUN_1406358c0()
{
    if (FUN_140634cc0() == 0)
        return false;
    if (m_b3A == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406358C0, CItemTransfer, FUN_1406358c0, 54, 0x431A3034);

// @0x140635900
int CItemTransfer::FUN_140635900()
{
    if (m_b42 == 0)
        return false;
    if (m_b41 == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140635900, CItemTransfer, FUN_140635900, 45, 0xF1A2447C);

// @0x140635940
bool CItemTransfer::FUN_140635940()
{
    return FUN_140635120() == 1;
}
MS2_REPLACE_METHOD(0x140635940, CItemTransfer, FUN_140635940, 52, 0xE032FB84);

// @0x140635980
bool CItemTransfer::FUN_140635980(const __int64* pId)
{
    if (FUN_140635470(pId))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140635980, CItemTransfer, FUN_140635980, 47, 0xDBE87C5F);

// @0x1406359c0
void CItemTransfer::FUN_1406359c0(__int64* pId, CStringW* pName)
{
    if (m_spBinding.get() != 0)
    {
        *pId = m_spBinding->FUN_14052d1c0();
        *pName = m_spBinding->FUN_14052d1b0();
    }
    else
    {
        *pId = 0;
        pName->Empty();
    }
}
MS2_REPLACE_METHOD(0x1406359C0, CItemTransfer, FUN_1406359c0, 143, 0x27AF4741);

// @0x140635a60
void CItemTransfer::FUN_140635a60()
{
    if (m_pItem == 0)
        return;
    if (m_pItem->FUN_140527840() == 0)
        return;
    CItemData* pData = reinterpret_cast<CItemData*>(m_pItem->FUN_140527840());
    m_nRule = FUN_140635ae0(m_nType, pData, m_pItem->FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x140635A60, CItemTransfer, FUN_140635a60, 111, 0xE6CA5D84);

// @0x140635ae0
unsigned CItemTransfer::FUN_140635ae0(int nType, CItemData* pData, int nId)
{
    if (pData == 0)
        return 0;
    unsigned nRule = 0;
    switch (nType)
    {
    case 0:
        nRule = 4;
        break;
    case 1:
        nRule = 0;
        break;
    case 5:
        nRule = 0x10;
        break;
    case 2:
        nRule = 8;
        break;
    case 4:
        nRule = 8;
        break;
    case 3:
        nRule = 0x18;
    }
    return nRule;
}
MS2_REPLACE(0x140635AE0, CItemTransfer::FUN_140635ae0, 136, 0x921CFB58);

// @0x140635b90
bool FUN_140635b90(unsigned a, unsigned b)
{
    return (a & b) == b;
}
MS2_REPLACE(0x140635B90, FUN_140635b90, 55, 0xCE1FD842);

// @0x140635cf0
CItemTransfer& CItemTransfer::operator=(const CItemTransfer& o)
{
    CPtred::operator=(o);
    m_pItem = o.m_pItem;
    m_nRule = o.m_nRule;
    m_n24 = o.m_n24;
    m_nType = o.m_nType;
    m_b2C = o.m_b2C;
    m_nCount = o.m_nCount;
    m_nMax = o.m_nMax;
    m_b38 = o.m_b38;
    m_b39 = o.m_b39;
    m_b3A = o.m_b3A;
    m_b3B = o.m_b3B;
    m_b3C = o.m_b3C;
    m_b3D = o.m_b3D;
    m_b3E = o.m_b3E;
    m_b3F = o.m_b3F;
    m_b40 = o.m_b40;
    m_b41 = o.m_b41;
    m_b42 = o.m_b42;
    m_spBinding = o.m_spBinding;
    return *this;
}

template class MS2Ptr<CItemTransfer>;
MS2_REPLACE_METHOD(0x140635CF0, CItemTransfer, operator=, 367, 0xBAC8BFAA);
