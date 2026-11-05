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
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCItemEnchantInfo@@@@QEAAAEAV1@PEAVCItemEnchantInfo@@@Z 0x1406332d0
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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/itemsocketscrolldata.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/citemoptiontable.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/client/ms2/skilltieroptionmanager.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
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
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int Unk_ReadRank(class Unk_XmlNode*, char const*, int*);   // C3: was FUN_14015f500

// Item accessors (the CItem members are declared in citem.h; the rest are unrecovered members taken as free functions).

// @0x140626aa0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Init(MS2Ptr<CItem> pItem, int nSocketMode, int nUnlockMode)
{
    if (pItem == (CItem*)0 || pItem.get()->GetSocket() == 0)
        return false;
    m_n18 = ((class CItemData*)(void*)(pItem.get()->FUN_140527840()))->GetOriginOrItemId();
    m_n1C = pItem.get()->GetRarity();
    m_n20 = pItem.get()->GetItemUid();
    m_n28 = ((class CItemSocket*)(void*)(pItem.get()->GetSocket()))->GetOpenSlotCount();
    m_nSocketMode = nSocketMode;
    m_nUnlockMode = nUnlockMode;
    return true;
}

// @0x140626bc0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Matches(MS2Ptr<CItem> pItem)
{
    if (pItem == (CItem*)0)
        return false;
    if (m_n20 == (unsigned __int64)pItem.get()->GetItemUid())
        return false;
    if (m_n18 != ((class CItemData*)(void*)(pItem.get()->FUN_140527840()))->GetOriginOrItemId() || m_n1C != pItem.get()->GetRarity())
        return false;
    void* pEnhance = pItem.get()->GetSocket();
    if (pEnhance == 0 || ((class CItemSocket*)(void*)(pEnhance))->GetMaxSlot() == 0)
        return false;
    if (m_n28 != ((class CItemSocket*)(void*)(pEnhance))->GetOpenSlotCount())
        return false;
    if (pItem.get()->FUN_140528980() == 0)
        return false;
    if (pItem.get()->FUN_140525ca0() != 0 && m_nSocketMode == 0)
        return false;
    if (((class CItem*)(class CItem*)(pItem.get()))->FUN_140525db0() != 0 && m_nUnlockMode == 0)
        return false;
    if (pItem.get()->FUN_140528e20() != 0)
        return false;
    if (reinterpret_cast<CItemSocket*>(pEnhance)->HasLockedGem() != 0)
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
class CItemGemStoneUpgradeTable;
class Unk_Random;
class CIngredientContainer;
CItemGemStoneUpgradeTable* FUN_14062c280();
int FUN_1406516b0();                                                // the language / region id
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);
class CGameRule   // C3: member view for the former free stand-ins
{
public:
    unsigned int GetSaleGemStoneUpgradeRate();
};
void* FUN_1401c0d90();
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
int FUN_1406198a0(int nBase, float fRate);                          // (int)(nBase * fRate + 1e-6)
unsigned int FUN_140482050(unsigned int, unsigned int);  // C3: the definition's signature
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
class CLua   // C3: member view for the former free stand-ins
{
public:
    bool CalcItemSocketMaxCount(int, int, unsigned short, int, int*);
    int Round(double, int);
};
CStringW FUN_141277410(int nType);                                  // the name of a slot type
CStringW GetStringCommon(int nStringId);                              // a string table text


class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
bool FUN_140627d70(MS2Ptr<CItemData> spData);
// The socket record of an item (CItemSocket, itemsocket.cpp): members not recovered yet.
bool FUN_140627930(MS2Ptr<CItemData> spData, MS2Ptr<CItemSocketScrollData> spScroll);
bool FUN_140627020(MS2Ptr<CItemGemStoneData> spRow);
bool FUN_1406271b0(MS2Ptr<CItemGemStoneData> spRow, short* pMin, short* pMax, int* pError);
int FUN_140627b80(int nA, unsigned nWanted);
int FUN_140627e80(MS2Ptr<CItem> spItem);
int FUN_140628050(MS2Ptr<CItem> spItem);

// @0x140626f20
unsigned short FUN_140626f20(unsigned nId)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(nId);
    if (spRow == 0)
        return 0;
    return spRow->m_nSlot;
}
MS2_REPLACE(0x140626F20, FUN_140626f20, 123, 0x077283A7);

// @0x140626fb0
bool FUN_140626fb0(unsigned nId)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(nId);
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
        MS2Ptr<CItemGemStoneData> spLinked = FUN_14062c280()->FindData(nLinked);
        bResult = spLinked == 0 ? true : false;
    }
    return bResult;
}
MS2_REPLACE(0x140627020, FUN_140627020, 225, 0xC4BBD2F2);

// @0x140627110
bool FUN_140627110(unsigned nId, short* pMin, short* pMax, int* pError)
{
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(nId);
    return FUN_1406271b0(spRow, pMin, pMax, pError);
}
MS2_REPLACE(0x140627110, FUN_140627110, 141, 0x833B2DEF);

// @0x1406271b0
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
    *pMax = (unsigned short)*pMin + 1;
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
    MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(nId);
    if ((CItemGemStoneData*)spRow)
        return CStringW(spRow->m_strName);
    return CStringW(L"");
}
MS2_REPLACE(0x140627390, FUN_140627390, 174, 0x0188DA8B);

// @0x140627450
// The socket scroll can be used on the item: 0 = yes, else the error code of the first rule that fails.
int FUN_140627450(MS2Ptr<CItem> spItem, MS2Ptr<CItemSocketScrollData> spScroll)
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
    unsigned nSlotKind = spData->GetEquipSubtype();
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(spScroll->m_arrSlot), reinterpret_cast<const int&>(nSlotKind)) == -1)
        return 5;
    unsigned nRank = spItem->GetRarity();
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(spScroll->m_arrRank), reinterpret_cast<const int&>(nRank)) == -1)
        return 6;
    int nLevel = spData->limit.levelLimit;
    if (spScroll->m_nMaxLv == 0)
    {
        if (nLevel < (int)spScroll->m_nMinLv)
            return 7;
    }
    else
    {
        if (nLevel < (int)spScroll->m_nMinLv || nLevel > (int)spScroll->m_nMaxLv)
            return 7;
    }
    if (spItem->GetSocket() == 0 || spItem->FUN_140529560() == 0)
        return 3;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket->GetMaxSlot() == 0)
        return 3;
    int nLeft = pSocket->GetLockedSlotCount();
    if (nLeft == 0)
        return 4;
    return 0;
}
MS2_REPLACE(0x140627450, FUN_140627450, 1234, 0xF69E6543);

// @0x140627930
bool FUN_140627930(MS2Ptr<CItemData> spData, MS2Ptr<CItemSocketScrollData> spScroll)
{
    if (spData == 0 || spScroll == 0)
        return false;
    int nKind = spData->HasSkinType() ? 2 : 1;
    return (spScroll->m_nUnk1c & nKind) > 0;
}
MS2_REPLACE(0x140627930, FUN_140627930, 226, 0xEA957CAF);

// @0x140627a20
int FUN_140627a20(unsigned nFlags, unsigned* pOut, unsigned nWanted)
{
    unsigned nMin = ((class CGameRule*)(void*)(FUN_1401c0d90()))->GetSaleGemStoneUpgradeRate();
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
void FUN_140627b50(int nA, CItemSocketScrollData* pScroll)
{
    FUN_140627b80(nA, pScroll->m_nUnk1c);
}
MS2_REPLACE(0x140627B50, FUN_140627b50, 35, 0xCFF64D85);

// @0x140627b80
int FUN_140627b80(int nA, unsigned nWanted)
{
    nWanted = nWanted < FUN_1406198a0(10000, *(float*)((char*)((void*)FUN_1401d3200()) + 0x90fc)) ? nWanted : FUN_1406198a0(10000, *(float*)((char*)((void*)FUN_1401d3200()) + 0x90fc));
    unsigned nResult = (unsigned)FUN_140482050(nA, nWanted);
    return nResult < 1 ? 1 : nResult;
}
MS2_REPLACE(0x140627B80, FUN_140627b80, 137, 0x9251C7E8);

// @0x140627c10
bool FUN_140627c10(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return false;
    return !reinterpret_cast<CItemData*>(spItem->FUN_140527840())->HasSkinType();
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
    bResult = spData->HasSkinType();
    if (!bResult && spData->FUN_14053d840() == 1)
    {
        MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(spData->GetItemId());
        bResult = FUN_1406272f0(8, spRow);
    }
    return bResult;
}
MS2_REPLACE(0x140627D70, FUN_140627d70, 259, 0xA98525E6);

// @0x140627e80
// The item is an equip with a socket record that is unlocked (and not yet used).
int FUN_140627e80(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return 0;
    if (!reinterpret_cast<CItemData*>(spItem->FUN_140527840())->HasSkinType())
        return 0;
    if (reinterpret_cast<CItemTransfer*>(spItem->FUN_140527930())->CanTransferSocket() == 0)
        return 0;
    if (spItem->GetSocket() == 0 || spItem->FUN_140529560() == 0)
        return 0;
    if (((class CItemSocket*)(void*)(spItem->GetSocket()))->GetOpenSlotCount() == 0)
        return 0;
    if (((class CItemSocket*)(void*)(spItem->GetSocket()))->GetFilledSlotCount() != 0)
        return 0;
    if (spItem->FUN_140526160() == 1)
        return 0;
    return 1;
}
MS2_REPLACE(0x140627E80, FUN_140627e80, 458, 0xBE0452AB);

// @0x140628050
int FUN_140628050(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || reinterpret_cast<CItemData*>(spItem->FUN_140527840()) == 0)
        return 0;
    if (!reinterpret_cast<CItemData*>(spItem->FUN_140527840())->HasSkinType())
        return 0;
    if (reinterpret_cast<CItemTransfer*>(spItem->FUN_140527930())->CanTransferSocket() == 0)
        return 0;
    if (spItem->GetSocket() == 0 || spItem->FUN_140529560() == 0)
        return 0;
    if (((class CItemSocket*)(void*)(spItem->GetSocket()))->GetOpenSlotCount() != 0)
        return 0;
    if (((class CItemSocket*)(void*)(spItem->GetSocket()))->GetFilledSlotCount() != 0)
        return 0;
    return 1;
}
MS2_REPLACE(0x140628050, FUN_140628050, 411, 0x17EB2A1D);

// @0x140628200
int FUN_140628200(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    if (FUN_140627e80(spA) == 0 || FUN_140628050(spB) == 0)
        return 0;
    if (((class CItemSocket*)(void*)(spA->GetSocket()))->GetMaxSlot() != ((class CItemSocket*)(void*)(spB->GetSocket()))->GetMaxSlot())
        return 0;
    return 1;
}
MS2_REPLACE(0x140628200, FUN_140628200, 322, 0x2F05C1F7);

// @0x140628350
int FUN_140628350()
{
    if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0xfd))
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
        ((class CIngredientContainer*)(class CIngredientContainer*)(pCost))->FUN_14026bd10(0x58, 0x2b2);
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
        ((class CIngredientContainer*)(class CIngredientContainer*)(pCost))->FUN_14026bd10(0x60, nPrice);
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
            *pPrice = ((class CLua*)(void*)(((void*)FUN_1401c0db0())))->Round((double)*pPrice, -3);
        }
    }
    else
    {
        *pPrice = nRate * 2 + 8;
    }
}
MS2_REPLACE(0x1406284F0, FUN_1406284f0, 209, 0x5C53BEEB);

// @0x1406285d0
// The names of the slot kinds in a mask, ", "-separated.
CStringW FUN_1406285d0(unsigned nMask)
{
    if (nMask < 0xf)
    {
        const CStringW& strSep = CStringW(L", ");
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
            strOut.Append(GetStringCommon(0x594));
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

MS2_REPLACE(0x1406285D0, FUN_1406285d0, 616, 0x5E21D38A);

// @0x140628840
void FUN_140628840(Unk_SockUidCountSlot& v, COutputStream& out)
{
    out.WriteInt64(v.m_nUid);
    out.WriteInt64(v.m_nCount);
    out.WriteUInt8(v.m_nSlot);
}
MS2_REPLACE(0x140628840, FUN_140628840, 93, 0x94B22953);

// @0x1406288b0
void FUN_1406288b0(Unk_SockUidCountSlot& v, CInPacket& in)
{
    v.m_nUid = in.ReadInt64();
    v.m_nCount = in.ReadInt64();
    v.m_nSlot = in.ReadUInt8();
}
MS2_REPLACE(0x1406288B0, FUN_1406288b0, 149, 0x931EED25);

// @0x140628950
void FUN_140628950(Unk_SSGGemEquip& v, COutputStream& out)
{
    out.WriteInt64(v.m_nItemUid);
    out.WriteUInt8(v.m_nSlot);
    if (v.m_spGem.get() != 0)
    {
        out.WriteBool(true);
        ((class TSocketGemStoneInfo*)(class TSocketGemStoneInfo*)(v.m_spGem.operator->()))->WriteToStream(out);
    }
    else
    {
        out.WriteBool(false);
    }
}
MS2_REPLACE(0x140628950, FUN_140628950, 156, 0x7C5AC520);

// @0x140628a00
void FUN_140628a00(Unk_SSGGemEquip& v, CInPacket& in)
{
    v.m_nItemUid = in.ReadInt64();
    v.m_nSlot = in.ReadUInt8();
    bool bGem = in.ReadBool();
    if (bGem)
    {
        v.m_spGem.AssignRaw(new TSocketGemStoneInfo);
        if (v.m_spGem.get() != 0)
            ((class TSocketGemStoneInfo*)(class TSocketGemStoneInfo*)(v.m_spGem.operator->()))->ReadFromStream(in);
    }
}
MS2_REPLACE(0x140628A00, FUN_140628a00, 348, 0xF3CBE4F7);

// @0x140628b70
void FUN_140628b70(Unk_SSGGemUnequip& v, COutputStream& out)
{
    out.WriteInt64(v.m_nItemUid);
    out.WriteUInt8(v.m_nSlot);
    out.WriteInt64(v.m_nGemUid);
}
MS2_REPLACE(0x140628B70, FUN_140628b70, 93, 0x3C1A5047);

// @0x140628be0
void FUN_140628be0(Unk_SSGGemUnequip& v, CInPacket& in)
{
    v.m_nItemUid = in.ReadInt64();
    v.m_nSlot = in.ReadUInt8();
    v.m_nGemUid = in.ReadInt64();
}
MS2_REPLACE(0x140628BE0, FUN_140628be0, 149, 0x24338E7B);

// @0x140628c80
void FUN_140628c80(Unk_SockUidList& v, COutputStream& out)
{
    out.WriteInt64(v.m_nUid);
    unsigned char nCount = (unsigned char)v.m_aUids.size();
    out.WriteUInt8(nCount);
    for (unsigned char i = 0; i < nCount; i++)
    {
        __int64 nUid = v.m_aUids.at(i);
        out.WriteInt64(nUid);
    }
}
MS2_REPLACE(0x140628C80, FUN_140628c80, 169, 0x708F44EE);

// @0x140628d30
void FUN_140628d30(Unk_SockUidList& v, CInPacket& in)
{
    v.m_nUid = in.ReadInt64();
    v.m_aUids.clear();
    unsigned char nCount = in.ReadUInt8();
    v.m_aUids.reserve(nCount);
    for (unsigned char i = 0; i < nCount; i++)
    {
        __int64 nUid = in.ReadInt64();
        v.m_aUids.push_back(nUid);
    }
}
MS2_REPLACE(0x140628D30, FUN_140628d30, 232, 0x60A61AD2);

// @0x140628e20
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
            if (spItem.get() != 0)
                v.m_aUids.push_back(spItem->GetItemUid());
            else
                v.m_aUids.push_back(0);
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
    out.WriteInt64(v.m_nFirst);
    out.WriteInt64(v.m_nSecond);
}
MS2_REPLACE(0x140629340, FUN_140629340, 68, 0x0FA3158C);

// @0x140629390
void FUN_140629390(Unk_SockUidPair& v, CInPacket& in)
{
    v.m_nFirst = in.ReadInt64();
    v.m_nSecond = in.ReadInt64();
}
MS2_REPLACE(0x140629390, FUN_140629390, 104, 0x1A92EBE0);

// @0x140629f30
void FUN_140629f30(Unk_SockUidIntByte& v, COutputStream& out)
{
    out.WriteInt64(v.m_nUid);
    out.WriteInt32(v.m_nValue);
    out.WriteUInt8(v.m_nByte);
}
MS2_REPLACE(0x140629F30, FUN_140629f30, 92, 0x8D3D87D3);

// @0x140629fa0
void FUN_140629fa0(Unk_SockUidIntByte& v, CInPacket& in)
{
    v.m_nUid = in.ReadInt64();
    v.m_nValue = in.ReadInt32();
    v.m_nByte = in.ReadUInt8();
}
MS2_REPLACE(0x140629FA0, FUN_140629fa0, 148, 0xF627C3D9);

// @0x14062a040
void FUN_14062a040(Unk_SockUidPair& v, COutputStream& out)
{
    out.WriteInt64(v.m_nFirst);
    out.WriteInt64(v.m_nSecond);
}
MS2_REPLACE(0x14062A040, FUN_14062a040, 68, 0x0FA3158C);

// @0x14062a090
void FUN_14062a090(Unk_SockUidPair& v, CInPacket& in)
{
    v.m_nFirst = in.ReadInt64();
    v.m_nSecond = in.ReadInt64();
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
namespace CCItemSocketSystemPacket {
// the debug fill-ingredient request (a view; the pages units declare its ctor / vdtor)
class ForceFillIngredient
{
public:
    void* m_pVtbl;
    int m_nB8;                              // +8 (a byte on the wire)
    int m_nC;
    __int64 m_n10;
    int m_n18;
};
}
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
void FUN_140628ff0(Unk_SockItemMsg& v, COutputStream& out, bool bTransfer)
{
    if (v.m_spItem == 0 || v.m_spItem->GetSocket() == 0)
        return;
    out.WriteUInt8(v.m_bValid);
    out.WriteInt64(v.m_spItem->GetItemUid());
    if (v.m_bValid)
    {
        out.WriteUInt8(v.m_nByte);
        v.m_spItem->GetSocket()->WriteToStream(out);
        out.WriteBool(bTransfer);
        if (bTransfer)
            reinterpret_cast<CItemTransfer*>(v.m_spItem->FUN_140527930())->vfunc_1(out);
    }
}
MS2_REPLACE(0x140628FF0, FUN_140628ff0, 322, 0x2CF4AD29);

// @0x140629140
void FUN_140629140(Unk_SockItemMsg& v, CInPacket& in)
{
    if (v.m_spItem == 0 || v.m_spItem->GetSocket() == 0)
        return;
    v.m_bValid = in.ReadUInt8() == 1 ? true : false;
    __int64 nUid = in.ReadInt64();
    if (v.m_bValid)
    {
        v.m_nByte = in.ReadUInt8();
        if (v.m_spItem->GetItemUid() == nUid)
        {
            v.m_spItem->GetSocket()->ReadFromStream(in);
            bool bTransfer = in.ReadBool();
            if (bTransfer)
                reinterpret_cast<CItemTransfer*>(v.m_spItem->FUN_140527930())->vfunc_2(in);
        }
    }
}
MS2_REPLACE(0x140629140, FUN_140629140, 502, 0x90571525);

// @0x140629400
void FUN_140629400(Unk_SockItemPair& v, COutputStream& out, int nMode)
{
    if (v.m_spA == 0 || v.m_spA->GetSocket() == 0)
        return;
    if (v.m_spB == 0 || v.m_spB->GetSocket() == 0)
        return;
    out.WriteInt64(v.m_spA->GetItemUid());
    v.m_spA->GetSocket()->WriteToStream(out);
    out.WriteInt64(v.m_spB->GetItemUid());
    v.m_spB->GetSocket()->WriteToStream(out);
    out.WriteBool(nMode == 1);
    if (nMode != 0)
        reinterpret_cast<CItemTransfer*>(v.m_spB->FUN_140527930())->vfunc_1(out);
}
MS2_REPLACE(0x140629400, FUN_140629400, 411, 0x09CAED1C);

// @0x1406295b0
void FUN_1406295b0(Unk_SockItemPair& v, CInPacket& in)
{
    if (v.m_spA == 0 || v.m_spA->GetSocket() == 0)
        return;
    if (v.m_spB == 0 || v.m_spB->GetSocket() == 0)
        return;
    __int64 nUidA = in.ReadInt64();
    if (v.m_spA->GetItemUid() != nUidA)
        return;
    v.m_spA->GetSocket()->ReadFromStream(in);
    __int64 nUidB = in.ReadInt64();
    if (v.m_spB->GetItemUid() != nUidB)
        return;
    v.m_spB->GetSocket()->ReadFromStream(in);
    int bTransfer = in.ReadBool();
    if (bTransfer != 0)
        reinterpret_cast<CItemTransfer*>(v.m_spB->FUN_140527930())->vfunc_2(in);
}
MS2_REPLACE(0x1406295B0, FUN_1406295b0, 550, 0x1BE1882E);

// @0x1406297e0
void FUN_1406297e0(Unk_SockMsg& v, COutputStream& out)
{
    out.WriteInt64(v.m_nUid);
    out.WriteUInt8(v.m_nByte);
}
MS2_REPLACE(0x1406297E0, FUN_1406297e0, 69, 0x6F3F2B16);

// @0x140629830
void FUN_140629830(Unk_SockMsg& v, CInPacket& in)
{
    v.m_nUid = in.ReadInt64();
    v.m_nByte = in.ReadUInt8();
}
MS2_REPLACE(0x140629830, FUN_140629830, 107, 0xCFBFF993);

// @0x1406298b0
void FUN_1406298b0(Unk_SockMsgI64& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.WriteInt64(v.m_nExtra);
}
MS2_REPLACE(0x1406298B0, FUN_1406298b0, 59, 0x4EE11B41);

// @0x140629900
void FUN_140629900(Unk_SockMsgI64& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.ReadInt64();
}
MS2_REPLACE(0x140629900, FUN_140629900, 77, 0xA282943C);

// @0x140629960
void FUN_140629960(Unk_SockMsgGem& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.WriteUInt8(v.m_bB34);
    out.WriteUInt8(v.m_nB30);
    out.WriteInt64(v.m_n28);
    if (v.m_spGem.get() != 0)
    {
        out.WriteBool(true);
        ((class TSocketGemStoneInfo*)(class TSocketGemStoneInfo*)(v.m_spGem.operator->()))->WriteToStream(out);
    }
    else
    {
        out.WriteBool(false);
    }
}
MS2_REPLACE(0x140629960, FUN_140629960, 197, 0x2250C583);

// @0x140629a30
void FUN_140629a30(Unk_SockMsgGem& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_bB34 = in.ReadUInt8() == 1 ? true : false;
    v.m_nB30 = in.ReadUInt8();
    v.m_n28 = in.ReadInt64();
    bool bGem = in.ReadBool();
    if (bGem)
    {
        v.m_spGem.AssignRaw(new TSocketGemStoneInfo);
        if (v.m_spGem.get() != 0)
            ((class TSocketGemStoneInfo*)(class TSocketGemStoneInfo*)(v.m_spGem.operator->()))->ReadFromStream(in);
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
    out.WriteInt64(v.m_nExtra);
}
MS2_REPLACE(0x140629C50, FUN_140629c50, 59, 0xF7C3B48D);

// @0x140629ca0
void FUN_140629ca0(Unk_SockMsgI64& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.ReadInt64();
}
MS2_REPLACE(0x140629CA0, FUN_140629ca0, 77, 0x91494D98);

// @0x140629d00
void FUN_140629d00(Unk_SockMsgF& v, COutputStream& out)
{
    FUN_1406297e0(v, out);
    out.WriteInt64(v.m_nExtra);
    out.WriteFloat(v.m_fValue);
}
MS2_REPLACE(0x140629D00, FUN_140629d00, 85, 0x051D76EA);

// @0x140629d60
void FUN_140629d60(Unk_SockMsgF& v, CInPacket& in)
{
    FUN_140629830(v, in);
    v.m_nExtra = in.ReadInt64();
    v.m_fValue = in.ReadFloat();
}
MS2_REPLACE(0x140629D60, FUN_140629d60, 121, 0x3D3788D8);

// @0x140629de0
void FUN_140629de0(CCItemSocketSystemPacket::ForceFillIngredient& v, COutputStream& out)
{
    out.WriteUInt8(v.m_nB8);
    out.WriteInt32(v.m_nC);
    out.WriteInt64(v.m_n10);
    out.WriteInt32(v.m_n18);
}
MS2_REPLACE(0x140629DE0, FUN_140629de0, 117, 0x8AFB7A3C);

// @0x140629e60
void FUN_140629e60(CCItemSocketSystemPacket::ForceFillIngredient& v, CInPacket& in)
{
    v.m_nB8 = in.ReadUInt8();
    v.m_nC = in.ReadInt32();
    v.m_n10 = in.ReadInt64();
    v.m_n18 = in.ReadInt32();
}
MS2_REPLACE(0x140629E60, FUN_140629e60, 191, 0xB6E1E065);

// @0x14062a100
void FUN_14062a100(Unk_SockItemOne& v, COutputStream& out)
{
    if (v.m_spItem == 0 || v.m_spItem->GetSocket() == 0)
        return;
    out.WriteUInt8(v.m_bFlag);
    v.m_nUid = v.m_spItem->GetItemUid();
    out.WriteInt64(v.m_nUid);
    out.WriteUInt8(v.m_nByte);
    if (v.m_bFlag)
    {
        out.WriteInt32(v.m_spItem->GetTransferCount());
        v.m_spItem->GetSocket()->WriteToStream(out);
    }
}
MS2_REPLACE(0x14062A100, FUN_14062a100, 291, 0x952C6E87);

// @0x14062a230
void FUN_14062a230(Unk_SockItemOne& v, CInPacket& in)
{
    if (v.m_spItem == 0 || v.m_spItem->GetSocket() == 0)
        return;
    v.m_bFlag = in.ReadUInt8() == 1 ? true : false;
    v.m_nUid = in.ReadInt64();
    v.m_nByte = in.ReadUInt8();
    if (v.m_bFlag)
    {
        if (v.m_spItem->GetItemUid() == v.m_nUid)
        {
            int nCount = in.ReadInt32();
            v.m_spItem->SetTransferCount(nCount);
            v.m_spItem->GetSocket()->ReadFromStream(in);
        }
    }
}
MS2_REPLACE(0x14062A230, FUN_14062a230, 405, 0x1D985FE6);

MS2Ptr<CItem> FUN_141425750(__int64 nUid, bool* pbEquipped);   // the inventory item with this uid
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pUnk, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                      // show it
void FUN_1412752d0(const CStringW& strKey, int nType);           // system notice by string key
class Unk_ItemEquipData : public CItemData
{
};

// @0x14062a3d0
// Put a gemstone into a socket of spItem (nSlot -1: the first free one): checks, then the confirm box (free, or with
// the fee item and count) whose result goes to cb.
bool FUN_14062a3d0(MS2Ptr<CItem> spItem, int nSlot, MS2Ptr<CItem> spGem, Delegate<bool(int, const CMsgBoxData&)> cb)
{
    if (spItem == (CItem*)0 || spItem->FUN_140527840() == 0 || spGem == (CItem*)0)
        return false;
    void* pSocket = spItem->GetSocket();
    if (pSocket == 0)
        return false;
    if (((class CItemSocket*)(void*)(pSocket))->GetMaxSlot() == 0)
        return false;
    int nMax = ((class CItemSocket*)(void*)(pSocket))->GetOpenSlotCount();
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
            int nGem = ((class CItemSocket*)(void*)(pSocket))->GetGemId(i);
            if (nGem == 0) {
                nTarget = i;
                break;
            }
        }
    } else {
        if (!((class CItemSocket*)(void*)(pSocket))->IsSlotEmpty(nSlot)) {
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
    FUN_1406284f0(nRate, spItem->FUN_140527840()->GetSkinType(), &nFeeItem, &nFeeCount);
    CStringW strMsg;
    int nSocketNo = nTarget + 1;
    unsigned nFeeName = TSingleton<CItemDataTable>::GetInstance()->GetTagItemId((ItemTagKey)nFeeItem);
    if (nFeeCount > 0)
        strMsg = FUN_14028dfa0(L"s_itemsocketsystem_msg_ask_gemstone_put_on", nSocketNo,
                               ((class CStringTable*)TSingleton<CStringTable>::GetInstance())->FUN_141811980(1, nFeeName), nFeeCount);
    else
        strMsg = FUN_14028dfa0(L"s_itemsocketsystem_msg_ask_gemstone_put_on_free", nSocketNo);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strMsg, 0, L"");
    if (spBox == (CMsgBoxData*)0)
        return false;
    spBox->SetCallback(cb);
    spBox->FUN_141a024a0(0);
    spBox->Append<__int64>(spGem->GetItemUid());
    spBox->Append<int>(nTarget);
    FUN_140d73c60(spBox);
    return true;
}
MS2_REPLACE(0x14062A3D0, FUN_14062a3d0, 2007, 0xA6CFDB87);

// @0x14062abb0
// The socket unlock confirm box result: request the unlock (packet 0x88, mode 8) with the box's count and slot.
bool SendItemSocketSystem(MS2Ptr<CItem> spItem, const CMsgBoxData& box)
{
    if (spItem == (CItem*)0)
        return false;
    __int64 nUid = spItem->GetItemUid();
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
    COutPacket packet(static_cast<int>(SendOp::ItemSocketSystem), 0);
    packet.Encode1(8);
    FUN_140628840(kMsg, packet);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE(0x14062ABB0, SendItemSocketSystem, 443, 0xB6C836FB);

// C3: Unk_ItemEnchantData = CItemStatus (CItem::m_spStatus +0xf8)
CStringW GetStringCommonByKey(const CStringW& str);
class Unk_140166430* FUN_140166430();   // C3: was FUN_140166430
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);
CStringW FUN_140631600(int nStat, BaseOption* pBase);
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);

// The first option text of an option record: the first random option, else the first extra one.
// @0x14062b020
CStringW FUN_14062b020(MS2Ptr<CItemOption> spOption)
{
    if (spOption == (CItemOption*)0)
        return CStringW(L"");
    CStringW str;
    Unk_EnchantMap& mapRandom = spOption->GetStatMap(0);
    if (!mapRandom.IsEmpty())
    {
        for (POSITION pos = mapRandom.GetStartPosition(); pos; mapRandom.GetNext(pos))
        {
            int nType = mapRandom.GetKeyAt(pos);
            MS2Ptr<BaseOption> spBase = mapRandom.GetValueAt(pos);
            if (spBase == (BaseOption*)0)
                continue;
            return FUN_140631600(nType, spBase.get());
        }
    }
    Unk_SocketSpecialMap& mapExtra = spOption->GetSpecialMap(0);
    if (!mapExtra.IsEmpty())
    {
        for (POSITION pos = mapExtra.GetStartPosition(); pos; mapExtra.GetNext(pos))
        {
            int nType = mapExtra.GetKeyAt(pos);
            MS2Ptr<BaseOption> spBase = mapExtra.GetValueAt(pos);
            if (spBase == (BaseOption*)0)
                continue;
            return FUN_140631830(nType, spBase->GetValue(), 0);
        }
    }
    return str;
}
MS2_REPLACE(0x14062B020, FUN_14062b020, 733, 0x424D87E9);

// @0x14062ad80
CStringW FUN_14062ad80(MS2Ptr<CItem> spItem)
{
    if (spItem == (CItem*)0 || spItem->FUN_1405278a0() == 0)
        return CStringW(L"");
    return FUN_14062b020(spItem->FUN_1405278a0()->m_spOption);
}
MS2_REPLACE(0x14062AD80, FUN_14062ad80, 215, 0x5D6DA17D);

// @0x14062aeb0
CStringW FUN_14062aeb0(int nItemId, int nRank)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == (CItemData*)0)
        return CStringW(L"");
    Unk_Random kRandom(0);
    MS2Ptr<CItemOption> spOption = reinterpret_cast<CItemOptionTable*>(FUN_140166430())->FUN_1405f4ff0(spData, nRank, &kRandom);
    return FUN_14062b020(spOption);
}
MS2_REPLACE(0x14062AEB0, FUN_14062aeb0, 351, 0x74D6C1BF);

// @0x14062ae60
CStringW FUN_14062ae60(int nItemId)
{
    int nGrade = FUN_14053feb0(nItemId);
    return FUN_14062aeb0(nItemId, nGrade);
}
MS2_REPLACE(0x14062AE60, FUN_14062ae60, 74, 0x2E79F9D4);

// The tooltip row text of a socket: locked or unlocked gemstone row.
// @0x14062b310
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> spSocket)
{
    CStringW str;
    if ((spSocket.get() ? true : false) && spSocket->IsLocked())
    {
        MS2Ptr<TSocketGemStoneLock> spSlot = spSocket->GetLock();
        if ((spSlot.get() ? true : false) && spSlot->FUN_140623e20() == 1)
            str = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_lock_gemstone");
        else
            str = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_unlock_gemstone");
    }
    return str;
}
MS2_REPLACE(0x14062B310, FUN_14062b310, 472, 0x9DD26D8D);

// @0x14062c280
CItemGemStoneUpgradeTable* FUN_14062c280()
{
    return static_cast<CItemGemStoneUpgradeTable*>(reinterpret_cast<void*>(TSingleton<CItemGemStoneUpgradeTable>::s_instance));
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
int CItemSocketTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "itemSocket.xml");
    FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 1;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    const CString& strItemSocket = "itemSocket";
    const CString& strId = "id";
    const CString& strGrade = "grade";
    const CString& strMaxCount = "maxCount";
    const CString& strOpenType = "openType";
    const CString& strRandomOpenRange = "randomOpenRange";
    const CString& strFixOpenCount = "fixOpenCount";
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild(strItemSocket)); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling(strItemSocket)))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        int nItemId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), strId, nItemId);
        if (nItemId == 0)
            continue;
        ContainerPtr spContainer(0);
        if (!m_items.Lookup(nItemId, spContainer))
            spContainer.AssignRaw(new CItemSocketDataContainer);
        MS2Ptr<CItemSocketData> spData(new CItemSocketData);
        if (spData == 0)
            continue;
        Unk_ReadRank((class Unk_XmlNode*)(pNode), strGrade, &spData->m_nGrade);
        XmlGetAttr((class TiXmlElement*)(pNode), strMaxCount, spData->m_nMaxCount);
        int nOpenType = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), strOpenType, nOpenType);
        spData->m_nOpenType = nOpenType;
        if (nOpenType == 1)
        {
            ATL::CAtlArray<unsigned> range;
            XmlTokenList(pNode, strRandomOpenRange, range);
            if (range.GetCount() == 2)
                spData->m_range.Range(range.GetAt(0), range.GetAt(1));
        }
        else if (nOpenType == 0)
        {
            int nCount = 0;
            XmlGetAttr((class TiXmlElement*)(pNode), strFixOpenCount, nCount);
            spData->m_range.Range(nCount, nCount);
        }
        spContainer->m_rows.Add(spData);
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
            m_items.SetAt(nItemId, spContainer);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14062CBC0, CItemSocketTable, Load, 1884, 0x1D6D1303);

// @0x14062d330
MS2Ptr<CItemSocketData> CItemSocketTable::Find(unsigned nItemId, int nGrade)
{
    if (m_items.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    MS2Ptr<CItemSocketData> spResult(0);
    ContainerPtr spContainer(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else if (m_items.Lookup(nItemId, spContainer))
        spResult = spContainer->Find(nGrade);
    return spResult;
}
MS2_REPLACE_METHOD(0x14062D330, CItemSocketTable, Find, 366, 0x63FC37F3);

// @0x14062d4b0
unsigned CItemSocketTable::GetMaxSocketCount(int nSocketId, int nGrade, MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return 0;
    if (!IsSocketFeatureEnabled(spData))
        return 0;
    if (spData->IsLapenshardType())
        return 0;
    if (nSocketId == 0)
    {
        int nCount = 0;
        unsigned short nLevel = (unsigned short)spData->limit.levelLimit;
        int nItemType = spData->GetEquipSubtype();
        int nSubType = spData->GetSkinType();
        ((class CLua*)(void*)(((void*)FUN_1401c0db0())))->CalcItemSocketMaxCount(nItemType, nGrade, nLevel, nSubType, &nCount);
        return nCount;
    }
    MS2Ptr<CItemSocketData> spRow = Find(nSocketId, nGrade);
    if (spRow == 0)
        return 0;
    return spRow->m_nMaxCount;
}
MS2_REPLACE_METHOD(0x14062D4B0, CItemSocketTable, GetMaxSocketCount, 557, 0x9F3A57AF);

// @0x14062d6f0
unsigned CItemSocketTable::GetInitialSocketCount(int nSocketId, int nGrade, MS2Ptr<CItemData> spData)
{
    unsigned nCount = 0;
    if (nSocketId == 0)
        return 0;
    if (spData == 0)
        return 0;
    if (!IsSocketFeatureEnabled(spData))
        return 1;
    MS2Ptr<CItemSocketData> spRow = Find(nSocketId, nGrade);
    if (spRow == 0)
        return 0;
    int nOpenType = spRow->m_nOpenType;
    if (nOpenType == 0)
        nCount = spRow->m_range.m_min;
    return nCount;
}
MS2_REPLACE_METHOD(0x14062D6F0, CItemSocketTable, GetInitialSocketCount, 400, 0x7C262BE8);

// @0x14062d890
bool CItemSocketTable::FUN_14062d890(int nArg1, int nArg2, int nArg3, MS2Ptr<CItem> spItem)
{
    return true;
}

// @0x14062d8d0
bool CItemSocketTable::IsSocketFeatureEnabled(MS2Ptr<CItemData> spData)
{
    bool bEnabled = ((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x2e);
    if (bEnabled && (spData.get() != 0 ? true : false))
    {
        if (spData->HasSkinType())
            bEnabled = ((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x5e);
    }
    return bEnabled;
}
MS2_REPLACE_METHOD(0x14062D8D0, CItemSocketTable, IsSocketFeatureEnabled, 166, 0xE858BA21);

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
    unsigned nMax = GetMaxSocketCount(nSocketId, nGrade, spData);
    unsigned nStart = GetInitialSocketCount(nSocketId, nGrade, spData);
    if (nMax > nStart)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14062D980, CItemSocketTable, FUN_14062d980, 454, 0xA0BEA5F1);

// @0x14062db50
int CItemSocketTable::Reload()
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
MS2_REPLACE_METHOD(0x14062DB50, CItemSocketTable, Reload, 115, 0x5F0288EB);

// @0x140626a20
CItemSocketSystemUtil::EnableSocketUnlockFunction::EnableSocketUnlockFunction()
    : m_n18(0), m_n1C(0), m_n20(0), m_n28(0), m_nSocketMode(0), m_nUnlockMode(0)
{
}

// @0x14062c160
// ---- CItemTransfer / CItemTransfer::CItemBinding ----------------------------------------------------------------
void * FUN_14052d200(void);  // C3: the definition's signature

// ---- CItemStatus ------------------------------------------------------------------------------------------------
// Unrecovered helpers of the option / stat text code.
class Unk_SaInfo { };
struct SpecialAbilityInfo;
extern std::vector<SpecialAbilityInfo> DAT_143ab1a40;   // skilltieroptionmanager.cpp
struct Unk_SATypeInfo                                   // uiitemmergeoptiondialog's view of a DAT_143ab1a40 row
{
    void* m_00;
    int m_nValueType;                                   // +0x08 eOptionValue (0 none, 2 percent)
    int m_0c;
    CStringW m_strFormat;                               // +0x10
    CStringW m_strName;                                 // +0x18
};
bool FUN_14081dcd0(int nSaType);                        // the SA value is a percent
int FUN_14081d9e0(int nSaType);                         // the SA is a skill level up tier (0x4d - 0x5a)
int FUN_14081da20(int nSaType);                         // the tier of it
bool IsStatKindTwo(int nStat);                          // the stat value is a percent
CStringW GetStatCommonText(unsigned nStat);             // the stat name
CStringW FUN_1409e0900(int nValue);
CStringW FUN_1409e0a90(float fValue);
CStringW FUN_1409e0970(int nStat, int nValue);
CStringW FUN_1409e0bf0(int nStat, int nValue);
int FUN_14080c370(unsigned nTier, eJobCode eJob, ATL::CAtlArray<unsigned>* paSa);   // the SA types a tier grants a job
enum Unk_LevelEntry; void FUN_140222be0(ATL::CAtlArray<Unk_LevelEntry>& aJobs);   // the job ids (the unit_1402226b0 def)
class Unk_ObjTable { };
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
class Unk_Actor { };
class PC   // C3: member view for the former free stand-ins
{
public:
    int FUN_141654700();
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);
CStringW FUN_140630ea0(int nSaType, int nValue, CItemData* pData);
__int64 FUN_140632990(__int64 nValue, float fRate);
void FUN_1406334d0(CStringW& str);

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
    ResetLook();
}

// @0x140631de0
CItemUgc::~CItemUgc()
{
    ResetLook();
}

// @0x140631e50
void CItemUgc::ResetLook()
{
    ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->Clear();
}
MS2_REPLACE_METHOD(0x140631E50, CItemUgc, ResetLook, 31, 0xB73A08F6);

// @0x140631e80
MS2Ptr<CItemUgc> CItemUgc::Clone()
{
    MS2Ptr<CItemUgc> spNew(new CItemUgc());
    ((class CUgcItemLook*)(class CUgcItemLook*)(&spNew->m_look))->CopyFrom(&m_look);
    return spNew;
}
MS2_REPLACE_METHOD(0x140631E80, CItemUgc, Clone, 196, 0x5C94FB68);

// @0x140631f50
void CItemUgc::WriteToStream(COutputStream& out)
{
    ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->Write(*(class COutputStream*)(&out));
    m_blueprint.Write(out);
}
MS2_REPLACE_METHOD(0x140631F50, CItemUgc, WriteToStream, 65, 0xD959A128);

// @0x140631fa0
void CItemUgc::ReadFromStream(CInputStream& in)
{
    ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->Read(*(class CInputStream*)(&in));
    m_blueprint.Read(in);
}
MS2_REPLACE_METHOD(0x140631FA0, CItemUgc, ReadFromStream, 65, 0xBF3AE4BB);

// @0x140631ff0
void CItemUgc::SetLook(CUgcItemLook* pLook)
{
    ResetLook();
    ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->CopyFrom(pLook);
}
MS2_REPLACE_METHOD(0x140631FF0, CItemUgc, SetLook, 51, 0x47EF6E9A);

// @0x140632030
unsigned __int64 CItemUgc::GetUgcId()
{
    return m_look.m_n18;
}
MS2_REPLACE_METHOD(0x140632030, CItemUgc, GetUgcId, 15, 0xAC153A31);

// @0x140632050
int CItemUgc::FUN_140632050()
{
    return m_look.m_n60;
}
MS2_REPLACE_METHOD(0x140632050, CItemUgc, FUN_140632050, 14, 0xB1F80757);

// @0x140632070
void CItemUgc::SetBlueprint(CBlueprintItemData* pBlueprint)
{
    m_blueprint.Clear();
    m_blueprint.CopyFrom(*pBlueprint);
}
MS2_REPLACE_METHOD(0x140632070, CItemUgc, SetBlueprint, 62, 0xBB4AA826);

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
CString CItemUgc::GetLookLocalPath()
{
    return m_look.GetLocalPath();
}
MS2_REPLACE_METHOD(0x140632100, CItemUgc, GetLookLocalPath, 65, 0x2B0AA445);

// @0x140632150
CStringW CItemUgc::FUN_140632150()
{
    return m_look.m_str28;
}
MS2_REPLACE_METHOD(0x140632150, CItemUgc, FUN_140632150, 66, 0x1C4EBE1A);

// @0x1406321a0
int CItemUgc::FUN_1406321a0()
{
    return ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->FUN_1408934f0();
}
MS2_REPLACE_METHOD(0x1406321A0, CItemUgc, FUN_1406321a0, 31, 0xA34D9BC7);

// @0x1406321d0
int CItemUgc::FUN_1406321d0()
{
    return ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->FUN_140893520();
}
MS2_REPLACE_METHOD(0x1406321D0, CItemUgc, FUN_1406321d0, 31, 0xA34D9BC7);

// @0x140632200
void CItemUgc::CopyLookFrom(CItemUgc* pSource)
{
    if (pSource == 0)
        return;
    ((class CUgcItemLook*)(class CUgcItemLook*)(&m_look))->CopyFrom(&pSource->m_look);
}
MS2_REPLACE_METHOD(0x140632200, CItemUgc, CopyLookFrom, 55, 0x51B741FA);

// @0x140632240
CItemCustomMusicScore::~CItemCustomMusicScore()
{
}

// @0x1406322c0
MS2Ptr<CItemCustomMusicScore> CItemCustomMusicScore::Clone()
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
MS2_REPLACE_METHOD(0x1406322C0, CItemCustomMusicScore, Clone, 556, 0x32D48641);

// @0x140632500
void CItemCustomMusicScore::WriteToStream(COutputStream& out)
{
    out.WriteInt32(m_n18);
    out.WriteInt32(m_n1c);
    out.WriteUnicodeString(m_str28);
    out.WriteUnicodeString(m_str20);
    out.WriteInt32(m_note.m_n00);
    out.WriteInt64(m_note.m_n08);
    out.WriteUInt8(m_n38);
    out.WriteInt64(m_n40);
    out.WriteInt64(m_n48);
}
MS2_REPLACE_METHOD(0x140632500, CItemCustomMusicScore, WriteToStream, 267, 0x7A2583B5);

// @0x140632620
void CItemCustomMusicScore::ReadFromStream(CInputStream& in)
{
    m_n18 = in.ReadInt32();
    m_n1c = in.ReadInt32();
    m_str28 = in.ReadUnicodeString();
    m_str20 = in.ReadUnicodeString();
    m_note.m_n00 = in.ReadInt32();
    m_note.m_n08 = in.ReadInt64();
    m_n38 = in.ReadUInt8();
    m_n40 = in.ReadInt64();
    m_n48 = in.ReadInt64();
}
MS2_REPLACE_METHOD(0x140632620, CItemCustomMusicScore, ReadFromStream, 344, 0x07AB5DCE);

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
void CItemCustomMusicScore::SetFromScoreInfo(const Unk_MusicScoreInfo& info)
{
    Reset();
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
MS2_REPLACE_METHOD(0x1406327C0, CItemCustomMusicScore, SetFromScoreInfo, 246, 0x61EED0DA);

// @0x1406328c0
void CItemCustomMusicScore::Reset()
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
MS2_REPLACE_METHOD(0x1406328C0, CItemCustomMusicScore, Reset, 204, 0x4570B3DE);

// @0x14062fbc0
MS2Ptr<CItemStatus> CItemStatus::Clone()
{
    return MS2Ptr<CItemStatus>(new CItemStatus(m_spOption->Clone(), m_spEnchant->Clone(), m_spUnlimited->FUN_1408bba60()));
}
MS2_REPLACE_METHOD(0x14062FBC0, CItemStatus, Clone, 473, 0x2DCD2F3E);

// @0x14062fda0
void CItemStatus::WriteToStream(COutputStream& out)
{
    m_spOption->Serialize(out);
    m_spEnchant->Write(reinterpret_cast<Unk_EnchantWrite&>(out));
    m_spUnlimited->FUN_1408bbd30(out);
}
MS2_REPLACE_METHOD(0x14062FDA0, CItemStatus, WriteToStream, 109, 0x4F2E960D);

// @0x14062fe20
void CItemStatus::ReadFromStream(CInputStream& in)
{
    m_spOption->Deserialize(in);
    m_spEnchant->Read(reinterpret_cast<Unk_EnchantRead&>(in));
    m_spUnlimited->FUN_1408bbef0(in);
}
MS2_REPLACE_METHOD(0x14062FE20, CItemStatus, ReadFromStream, 109, 0xBA262CEC);

// @0x14062fea0
int CItemStatus::FUN_14062fea0(unsigned nType)
{
    int nValue = m_spOption->SumStatValue(nType);
    if (IsRatioStat(nType))
    {
        int nEnchant = GetStatValue(nType, 1, 5);
        int nExtra = nEnchant + GetStatValue(nType, 2, 5);
        if (nType == 0x14)
            nExtra = (int)((float)nExtra * 0.159f);
        nValue += nExtra;
    }
    return nValue;
}
MS2_REPLACE_METHOD(0x14062FEA0, CItemStatus, FUN_14062fea0, 189, 0x47444B3B);

// @0x14062ff70
int CItemStatus::FUN_14062ff70(unsigned nType)
{
    return m_spOption->SumSpecialValue(nType);
}
MS2_REPLACE_METHOD(0x14062FF70, CItemStatus, FUN_14062ff70, 47, 0x04A83391);

// @0x14062ffb0
int CItemStatus::GetStatValue(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult += m_spOption->SumStatValue(nType);
        }
        else
        {
            MS2Ptr<BaseOption> spBase = m_spOption->GetStatOption(nSub, nType);
            if (spBase.get() != 0)
                nResult += spBase->GetValue();
        }
    }
    if (nWhich == 3 || nWhich == 1)
    {
        MS2Ptr<BaseOption> spBase = m_spEnchant->GetOption(nType);
        if (spBase.get() != 0)
        {
            if (IsRatioStat(nType))
            {
                __int64 nBase = GetStatValue(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += nScaled;
            }
            else
            {
                nResult += spBase->GetValue();
            }
        }
    }
    if (nWhich == 3 || nWhich == 2)
    {
        MS2Ptr<BaseOption> spBase = m_spUnlimited->FindOption(nType);
        if (spBase.get() != 0)
        {
            if (IsRatioStat(nType))
            {
                __int64 nBase = GetStatValue(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += nScaled;
            }
            else
            {
                nResult += spBase->GetValue();
            }
        }
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14062FFB0, CItemStatus, GetStatValue, 717, 0x6B640166);

// @0x140630290
int CItemStatus::FUN_140630290(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult += m_spOption->SumSpecialValue(nType);
        }
        else
        {
            MS2Ptr<BaseOption> spBase = m_spOption->GetSpecialOption(nSub, nType);
            if (spBase.get() != 0)
                nResult += spBase->GetValue();
        }
    }
    if ((nWhich == 3 || nWhich == 2) && nSub == 5)
    {
        MS2Ptr<BaseOption> spBase = m_spUnlimited->FindSecondaryOption(nType);
        if (spBase.get() != 0)
            nResult += spBase->GetValue();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x140630290, CItemStatus, FUN_140630290, 325, 0x45267C83);

// @0x1406303e0
float CItemStatus::GetEnchantRatio(unsigned nType)
{
    MS2Ptr<BaseOption> spBase = m_spEnchant->GetOption(nType);
    if (spBase == (BaseOption*)0)
        return 0;
    if (!IsRatioStat(nType))
        return 0;
    return spBase->FUN_140266e10();
}
MS2_REPLACE_METHOD(0x1406303E0, CItemStatus, GetEnchantRatio, 197, 0xE7166FB6);

// @0x1406304b0
int CItemStatus::HasOptionEntry(int nSub, int nWhich, unsigned nType)
{
    if (nSub != 5)
    {
        if (nWhich == 0)
        {
            BaseOption* pBase = m_spOption->GetStatOption(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
        else if (nWhich == 1)
        {
            BaseOption* pBase = m_spOption->GetSpecialOption(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1406304B0, CItemStatus, HasOptionEntry, 289, 0xE66A0E7F);

// @0x1406305e0
CStringW CItemStatus::GetSpecialStatText(int nSub, unsigned nType, void* pData)
{
    CStringW str;
    {
        MS2Ptr<BaseOption> spBase = m_spOption->GetSpecialOption(nSub, nType);
        if (spBase.get() != 0)
        {
            str = FUN_140631830(nType, spBase->GetValue(), reinterpret_cast<CItemData*>(pData));
        }
    }
    return str;
}
MS2_REPLACE_METHOD(0x1406305E0, CItemStatus, GetSpecialStatText, 263, 0xC97769C1);

// @0x1406306f0
void CItemStatus::GenerateOptions(int nItemId, int nRank, int nSeed)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    Unk_Random kRandom(nSeed);
    m_spOption = reinterpret_cast<CItemOptionTable*>(FUN_140166430())->FUN_1405f4ff0(spData, nRank, &kRandom);
}
MS2_REPLACE_METHOD(0x1406306F0, CItemStatus, GenerateOptions, 280, 0x03F00F7D);

// @0x140630810
bool CItemStatus::FUN_140630810()
{
    return m_spOption->HasGroup4Options();
}
MS2_REPLACE_METHOD(0x140630810, CItemStatus, FUN_140630810, 39, 0xEC3C6A18);

// @0x140630840
void CItemStatus::FUN_140630840()
{
    if (FUN_140630810())
    {
        m_spOption->ClearGroup(4);
        m_spOption->FUN_1405cb360(0);
    }
}
MS2_REPLACE_METHOD(0x140630840, CItemStatus, FUN_140630840, 88, 0x4E3181F8);

// @0x1406308a0
int CItemStatus::CopyGroup4From(MS2Ptr<CItemStatus> spOther)
{
    if (spOther.IsNull()) return 0;
    int bChanged = 0;
    for (unsigned i = 0; i < 0x23; ++i)
    {
        int nId = i;
        MS2Ptr<BaseOption> spSource = spOther->m_spOption->GetStatOption(4, nId);
        if (spSource.get() != 0)
        {
            MS2Ptr<BaseOption> spCopy(new BaseOption());
            spCopy->FUN_140266da0(spSource.get());
            m_spOption->TrySetStatOption(4, nId, spCopy);
            if (m_spOption->FUN_1405cb380() == 0)
                m_spOption->FUN_1405cb360(spOther->m_spOption->FUN_1405cb380());
            bChanged = 1;
        }
    }
    for (unsigned i = 0; i < 0xcf; ++i)
    {
        int nId = i;
        MS2Ptr<BaseOption> spSource = spOther->m_spOption->GetSpecialOption(4, nId);
        if (spSource.get() != 0)
        {
            MS2Ptr<BaseOption> spCopy(new BaseOption());
            spCopy->FUN_140266da0(spSource.get());
            m_spOption->TrySetSpecialOption(4, nId, spCopy);
            if (m_spOption->FUN_1405cb380() == 0)
                m_spOption->FUN_1405cb360(spOther->m_spOption->FUN_1405cb380());
            bChanged = 1;
        }
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x1406308A0, CItemStatus, CopyGroup4From, 1103, 0xFA56D793);

// @0x140630d00
unsigned CItemStatus::GetEnchantLevel()
{
    return m_spEnchant->GetLevel();
}
MS2_REPLACE_METHOD(0x140630D00, CItemStatus, GetEnchantLevel, 39, 0x3E09AE77);

// @0x140630d30
CItemOption* CItemStatus::GetOption()
{
    return m_spOption;
}
MS2_REPLACE_METHOD(0x140630D30, CItemStatus, GetOption, 31, 0xF8C26528);

// @0x140630d60
CItemEnchantInfo* CItemStatus::GetEnchant()
{
    return m_spEnchant;
}
MS2_REPLACE_METHOD(0x140630D60, CItemStatus, GetEnchant, 31, 0xA4FF07D8);

// @0x140630d90
Unk_ItemPlusInfo* CItemStatus::FUN_140630d90()
{
    return reinterpret_cast<Unk_ItemPlusInfo*>(static_cast<UnlimitedEnchantInfo*>(m_spUnlimited));
}
MS2_REPLACE_METHOD(0x140630D90, CItemStatus, FUN_140630d90, 31, 0x7F01B568);

// @0x140630dc0
bool CItemStatus::IsRatioStat(int nType)
{
    return nType == 0x1b || nType == 0x1c || nType == 0x14;
}
MS2_REPLACE_METHOD(0x140630DC0, CItemStatus, IsRatioStat, 59, 0x69FAA13A);

// @0x140630e10
CStringW FUN_140630e10(int nSaType)
{
    CStringW str;
    str = reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[nSaType].m_strName;
    return str;
}
MS2_REPLACE(0x140630E10, FUN_140630e10, 128, 0x6BB2121D);

// @0x140630ea0
// One line per job that can use the option, built from its skill list. The job the player
// is on gets the active form.
CStringW FUN_140630ea0(int nSaType, int nValue, CItemData* pData)
{
    CStringW strResult;
    Unk_Actor* pActor = ((class Unk_Actor*)((class WorldService*)(class Unk_ObjTable*)(((class Unk_ObjTable*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pActor == 0)
        return strResult;
    if (FUN_14081d9e0(nSaType) != 0)
    {
        ATL::CAtlArray<int> aJobs;
        FUN_140222be0(reinterpret_cast<ATL::CAtlArray<Unk_LevelEntry>&>(aJobs));
        for (unsigned i = 0; i < aJobs.GetCount(); i++)
        {
            int nJob = aJobs[i];
            int bMyJob = ((class PC*)(class Unk_Actor*)(pActor))->FUN_141654700() == nJob;
            if (pData != 0 && pData->IsJobAllowed(nJob) == 0)
                continue;
            ATL::CAtlArray<unsigned> aSa;
            FUN_14080c370(FUN_14081da20(nSaType), (eJobCode)nJob, &aSa);
            if (((ATL::CAtlArray<unsigned int, ATL::CElementTraits<unsigned int>>*)&(aSa))->IsEmpty())
                continue;
            CStringW strJob =
                ((class CStringTable*)TSingleton<CStringTable>::GetInstance())->FUN_141811980(6, TSingleton<JobTable>::GetInstance()->GetSubJob1(nJob));
            CStringW strList;
            for (unsigned k = 0; k < aSa.GetCount(); k++)
            {
                unsigned* pSa = &aSa[k];
                strList.Append(StringFormat(L", {0}", ((class CStringTable*)TSingleton<CStringTable>::GetInstance())->FUN_141811980(4, *pSa)));
            }
            FUN_1406334d0(strList);
            if (strResult.IsEmpty())
                strResult.Append(FUN_140630e10(nSaType));
            CStringW strLine;
            if (!strResult.IsEmpty())
                strLine.Append(L"\n   -");
            unsigned short nTier = nValue;
            strLine.Append(
                FUN_14028dfa0(CStringW(L"s_item_opt_sa_skill_levelup_tier_v"), strJob, strList, nTier));
            if (bMyJob)
                strLine =
                    FUN_14028dfa0<CStringW>(CStringW(L"s_item_opt_sa_skill_levelup_tier_v_active"), strLine);
            strResult.Append(strLine);
        }
    }
    return strResult;
}
MS2_REPLACE(0x140630EA0, FUN_140630ea0, 1348, 0xF81FC732);

// @0x1406313f0
CStringW FUN_1406313f0(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (IsStatKindTwo(nStat))
        str = FormatStringId(0x48b, GetStatCommonText(nStat), FUN_1409e0a90(pBase->FUN_140266e10()));
    else
        str = FormatStringId(0x48b, GetStatCommonText(nStat), FUN_1409e0900(pBase->GetValue()));
    return str;
}
MS2_REPLACE(0x1406313F0, FUN_1406313f0, 515, 0x242D2E53);

// @0x140631600
CStringW FUN_140631600(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (!(!IsStatKindTwo(nStat)))
        str = FUN_1409e0bf0(nStat, pBase->GetValue());
    else
        str = FUN_1409e0970(nStat, pBase->GetValue());
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
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData)
{
    CStringW str;
    if (FUN_14081dcd0(nStat))
    {
        float fValue = (float)nValue / 10.0f;
        str = StringFormat(reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[nStat].m_strFormat, fValue);
    }
    else
    {
        if (FUN_14081d9e0(nStat) != 0)
            return FUN_140630ea0(nStat, nValue, pData);
        str = StringFormat(reinterpret_cast<std::vector<Unk_SATypeInfo>&>(DAT_143ab1a40)[nStat].m_strFormat, nValue);
    }
    return str;
}
MS2_REPLACE(0x140631830, FUN_140631830, 437, 0xF776E1D4);

// @0x1406319f0
CStringW FUN_1406319f0(int nBuffId, unsigned short nLevel)
{
    CStringW str;
    str = ((class CStringTable*)TSingleton<CStringTable>::GetInstance())->FUN_141812290(nBuffId, nLevel, CString("name"));
    return str;
}
MS2_REPLACE(0x1406319F0, FUN_1406319f0, 240, 0xFB0E0A77);

// @0x140631af0
CStringW FUN_140631af0(int nStat, MS2Ptr<BaseOption> spBase, CItemStatus* pStatus)
{
    CStringW strResult;
    if (spBase->HasValue())
    {
        __int64 nBase = pStatus->GetStatValue(nStat, 0, 0);
        float fBase = (float)nBase;
        __int64 nExtra = (__int64)(fBase * spBase->FUN_140266e10());
        CStringW strUnused;
        if (nExtra == 0)
            strResult = FormatStringId(0x48c, GetStatCommonText(nStat));
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
    return (__int64)((double)nValue * (double)fRate + 0.000001);
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
    if (pTransfer != 0 && pTransfer->CanDestroy() == 0)
        return false;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->FUN_140622750() == 0)
        return false;
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->GetEnchant();
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
    if (pTransfer != 0 && pTransfer->IsSellable() == 0)
        return false;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->CheckGemsShopSellable() == 0)
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
    CItemSocket* pSocket = spItem->GetSocket();
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
    if (pTransfer != 0 && pTransfer->HasTradeCountLeft() == 0)
        return false;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->CheckNoBoundGem() == 0)
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
    if (pTransfer != 0 && pTransfer->CanBreak() == 0)
        return false;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->CheckGemsBreakable() == 0)
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
    if (pTransfer != 0 && pTransfer->CanRegisterMeratMarket() == 0)
        return false;
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->CheckGemsMeratMarketRegistrable() == 0)
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
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->FUN_140622790() == 0)
    {
        *pReason = 2;
        return false;
    }
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->GetEnchant();
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
    if (pTransfer != 0 && pTransfer->CanListOnBlackMarket() == 0)
    {
        *pReason = 1;
        return false;
    }
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->FUN_1406227f0() == 0)
    {
        *pReason = 2;
        return false;
    }
    CItemEnchantInfo* pEnchant = spItem->FUN_1405278a0()->GetEnchant();
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
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->CheckNoLockedGem() == 0)
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
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->HasBoundGem() == true)
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
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->AllGemsUsableByCharacter(pCharacterId) == false)
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
        if ((unsigned __int64)spItem->FUN_140527930()->GetBinding()->FUN_14052d1c0() > 0)
            bBound = true;
    }
    if (spItem->FUN_140527840()->FUN_14053d7c0())
        bBound = true;
    if (bBound && pTransfer != 0 && pTransfer->FUN_140635980(pCharacterId) == false)
    {
        pOut->kind = 1;
        pTransfer->GetBindingInfo(&pOut->characterId, &pOut->name);
        return false;
    }
    CItemSocket* pSocket = spItem->GetSocket();
    if (pSocket != 0 && pSocket->AllGemsUsableByCharacter(pCharacterId) == false)
    {
        pOut->kind = 2;
        pSocket->GetGemBindOwner(&pOut->characterId, &pOut->name);
        return false;
    }
    return true;
}
MS2_REPLACE(0x1406344B0, FUN_1406344b0, 487, 0xAC86C104);

// @0x1406346a0
void CItemTransfer::CItemBinding::FUN_1406346a0(COutputStream& out)
{
    out.WriteInt64(m_n18);
    out.WriteUnicodeString(m_str20);
}

// @0x140634700
void CItemTransfer::CItemBinding::FUN_140634700(CInputStream& in)
{
    m_n18 = in.ReadInt64();
    m_str20 = in.ReadUnicodeString();
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
void CItemTransfer::SetItem(CItem* pItem)
{
    m_pItem = pItem;
}
MS2_REPLACE_METHOD(0x140634970, CItemTransfer, SetItem, 25, 0xAB8BF0FB);

// @0x140634990
void CItemTransfer::InitFromItem(CItem* pItem)
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
            m_b3A = pData->CanRegisterMeratMarket() ? true : false;
            m_nCount = pData->FUN_14053d800() ? 1 : 0;
            m_b41 = ((class CItemSocketTable*)FUN_14052d200())->FUN_14062d980(reinterpret_cast<CItemData*>(pItem->FUN_140527840()), pItem->GetRarity());
            m_b42 = m_b41;
            RefreshRule();
        }
    }
}
MS2_REPLACE_METHOD(0x140634990, CItemTransfer, InitFromItem, 401, 0x66C6DDFC);

// @0x140634b30
MS2Ptr<CItemTransfer> CItemTransfer::Clone()
{
    MS2Ptr<CItemTransfer> spNew(new CItemTransfer);
    *spNew = *this;
    if (m_spBinding.get() != 0)
    {
        MS2Ptr<CItemBinding> spBinding(new CItemBinding);
        *spBinding = *m_spBinding;
        spNew->m_spBinding = spBinding;
    }
    return spNew;
}
MS2_REPLACE_METHOD(0x140634B30, CItemTransfer, Clone, 386, 0x652A96FC);

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
void CItemTransfer::vfunc_1(COutputStream& out)
{
    out.WriteInt32(m_nRule);
    out.WriteBool(m_b38);
    out.WriteInt32(m_nCount);
    out.WriteInt32(m_nMax);
    out.WriteUInt8(m_b3F);
    out.WriteUInt8(m_b42);
    if ((bool)m_spBinding.get() && HasBindingRule() != 0)
    {
        out.WriteBool(true);
        m_spBinding->FUN_1406346a0(out);
    }
    else
    {
        out.WriteBool(false);
    }
}
MS2_REPLACE_METHOD(0x140634D00, CItemTransfer, vfunc_1, 288, 0xD1BB41E7);

// @0x140634e30
void CItemTransfer::vfunc_2(CInputStream& in)
{
    m_nRule = in.ReadInt32();
    m_b38 = in.ReadBool();
    m_nCount = in.ReadInt32();
    m_nMax = in.ReadInt32();
    m_b3F = (bool)in.ReadUInt8();
    m_b42 = (bool)in.ReadUInt8();
    bool bBinding = in.ReadBool();
    if (bBinding)
    {
        m_spBinding.AssignRaw(new CItemBinding);
        m_spBinding->FUN_140634700(in);
    }
}
MS2_REPLACE_METHOD(0x140634E30, CItemTransfer, vfunc_2, 352, 0xD2333264);

// @0x140634fa0
int CItemTransfer::GetCount()
{
    return m_nCount;
}
MS2_REPLACE_METHOD(0x140634FA0, CItemTransfer, GetCount, 14, 0x828204CF);

// @0x140634fc0
void CItemTransfer::SetCount(unsigned n)
{
    m_nCount = n;
}
MS2_REPLACE_METHOD(0x140634FC0, CItemTransfer, SetCount, 22, 0x16BC4503);

// @0x140634fe0
int CItemTransfer::GetMax()
{
    return m_nMax;
}
MS2_REPLACE_METHOD(0x140634FE0, CItemTransfer, GetMax, 14, 0x9A8B24F3);

// @0x140635000
void CItemTransfer::SetMax(unsigned n)
{
    m_nMax = n;
}
MS2_REPLACE_METHOD(0x140635000, CItemTransfer, SetMax, 22, 0xFEAFFEDF);

// @0x140635020
int CItemTransfer::DecrementTransferCount()
{
    if ((m_nRule & 0x10) != 0 && m_nCount > 0)
    {
        --m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635020, CItemTransfer, DecrementTransferCount, 59, 0x48337623);

// @0x140635070
int CItemTransfer::IncrementTransferCount()
{
    if (m_pItem == 0)
        return 0;
    if ((m_nRule & 0x10) != 0)
    {
        if (m_nCount > 0)
            return 0;
        if (m_nMax >= (int)m_pItem->GetRepackLimitCount())
            return 0;
        ++m_nMax;
        ++m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635070, CItemTransfer, IncrementTransferCount, 133, 0x995E53BE);

// @0x140635100
unsigned CItemTransfer::HasBindingRule()
{
    return m_nRule & 8;
}
MS2_REPLACE_METHOD(0x140635100, CItemTransfer, HasBindingRule, 17, 0xB9EB22D4);

// @0x140635120
int CItemTransfer::HasBinding()
{
    return m_spBinding.get() != 0 ? 1 : 0;
}
MS2_REPLACE_METHOD(0x140635120, CItemTransfer, HasBinding, 58, 0x06ED1646);

// @0x140635160
CItemTransfer::CItemBinding* CItemTransfer::GetBinding()
{
    return m_spBinding.get();
}
MS2_REPLACE_METHOD(0x140635160, CItemTransfer, GetBinding, 31, 0x379A5C2F);

// @0x140635190
int CItemTransfer::GetType()
{
    return m_nType;
}
MS2_REPLACE_METHOD(0x140635190, CItemTransfer, GetType, 14, 0xD26D6807);

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
unsigned char CItemTransfer::SetBinding(const __int64& nCharId, const CStringW& strName)
{
    m_spBinding.AssignRaw(new CItemBinding);
    if (m_spBinding.get() != 0)
        return m_spBinding->FUN_1406347d0(nCharId, strName);
    return 0;
}
MS2_REPLACE_METHOD(0x1406351F0, CItemTransfer, SetBinding, 175, 0x3EF4D3CA);

// @0x1406352b0
unsigned char CItemTransfer::ClearBinding()
{
    m_pItem->vfunc_5(true);
    m_spBinding = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406352B0, CItemTransfer, ClearBinding, 61, 0x61774D6B);

// @0x140635300
void CItemTransfer::FUN_140635300()
{
    m_b3F = 1;
}
MS2_REPLACE_METHOD(0x140635300, CItemTransfer, FUN_140635300, 15, 0x03EFC008);

// @0x140635320
void CItemTransfer::SetSocketTransferFlag(bool b)
{
    m_b40 = 1;
    m_b42 = b;
}
MS2_REPLACE_METHOD(0x140635320, CItemTransfer, SetSocketTransferFlag, 32, 0xB7D9EF8D);

// The binding owner's name: the actor's own name when the actor is the owner, else the stored name.
// @0x140635350
void CItemTransfer::GetBindingOwnerName(PCBase* pPc, CStringW* pName)
{
    CItemBinding* pBinding = GetBinding();
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
MS2_REPLACE_METHOD(0x140635350, CItemTransfer, GetBindingOwnerName, 196, 0x7287F0A9);

// @0x140635470
bool CItemTransfer::IsBindingCompatible(const __int64* pId)
{
    if (m_spBinding.get() != 0)
    {
        if (!m_spBinding->FUN_140634790(reinterpret_cast<void*>(*pId)))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140635470, CItemTransfer, IsBindingCompatible, 87, 0x4FDB0514);

// @0x140635420
bool FUN_140635420(CItemTransfer* pTransfer, PCBase* pPc)
{
    if (pPc != 0)
    {
        __int64 nId = pPc->FUN_141656a80();
        return pTransfer->IsBindingCompatible(&nId);
    }
    return true;
}
MS2_REPLACE(0x140635420, FUN_140635420, 61, 0x538A89AA);

// @0x1406354d0
int CItemTransfer::IsSellable()
{
    if (m_pItem == 0)
        return false;
    if (m_b39 == 0)
        return false;
    if (FUN_140635870() == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406354D0, CItemTransfer, IsSellable, 70, 0x2CA2E2B6);

// @0x140635520
unsigned CItemTransfer::CanDestroy()
{
    if (HasBinding() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    return m_nRule & 4;
}
MS2_REPLACE_METHOD(0x140635520, CItemTransfer, CanDestroy, 79, 0x47E3BE8B);

// @0x140635580
int CItemTransfer::FUN_140635580()
{
    return 0;
}
MS2_REPLACE_METHOD(0x140635580, CItemTransfer, FUN_140635580, 8, 0x7F371472);

// @0x140635590
unsigned CItemTransfer::FUN_140635590()
{
    if (HasBinding() != 0)
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
int CItemTransfer::HasTradeCountLeft()
{
    if (HasBinding() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if ((m_nRule & 0x10) == 0)
        return 0;
    if (m_nCount == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140635630, CItemTransfer, HasTradeCountLeft, 89, 0xAC2D2E1A);

// @0x140635690
unsigned CItemTransfer::CanListOnBlackMarket()
{
    if (HasBinding() != 0)
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
MS2_REPLACE_METHOD(0x140635690, CItemTransfer, CanListOnBlackMarket, 204, 0x23D70D12);

// @0x140635770
int CItemTransfer::CanBreak()
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
    if (m_pItem->HasSkin() != 0)
    {
        if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x3a))
            return 0;
        if (m_pItem->HasCubeTextureMesh() != 0 && m_pItem->GetSocket() != 0)
        {
            if (((class CItemSocket*)(void*)(m_pItem->GetSocket()))->GetOpenSlotCount() == 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140635770, CItemTransfer, CanBreak, 235, 0xAE1E60FC);

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
int CItemTransfer::CanRegisterMeratMarket()
{
    if (FUN_140634cc0() == 0)
        return false;
    if (m_b3A == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406358C0, CItemTransfer, CanRegisterMeratMarket, 54, 0x431A3034);

// @0x140635900
int CItemTransfer::CanTransferSocket()
{
    if (m_b42 == 0)
        return false;
    if (m_b41 == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140635900, CItemTransfer, CanTransferSocket, 45, 0xF1A2447C);

// @0x140635940
bool CItemTransfer::FUN_140635940()
{
    return HasBinding() == 1;
}
MS2_REPLACE_METHOD(0x140635940, CItemTransfer, FUN_140635940, 52, 0xE032FB84);

// @0x140635980
bool CItemTransfer::FUN_140635980(const __int64* pId)
{
    if (IsBindingCompatible(pId))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140635980, CItemTransfer, FUN_140635980, 47, 0xDBE87C5F);

// @0x1406359c0
void CItemTransfer::GetBindingInfo(__int64* pId, CStringW* pName)
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
MS2_REPLACE_METHOD(0x1406359C0, CItemTransfer, GetBindingInfo, 143, 0x27AF4741);

// @0x140635a60
void CItemTransfer::RefreshRule()
{
    if (m_pItem == 0)
        return;
    if (m_pItem->FUN_140527840() == 0)
        return;
    CItemData* pData = reinterpret_cast<CItemData*>(m_pItem->FUN_140527840());
    m_nRule = ComputeRule(m_nType, pData, m_pItem->GetRarity());
}
MS2_REPLACE_METHOD(0x140635A60, CItemTransfer, RefreshRule, 111, 0xE6CA5D84);

// @0x140635ae0
unsigned CItemTransfer::ComputeRule(int nType, CItemData* pData, int nId)
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
MS2_REPLACE(0x140635AE0, CItemTransfer::ComputeRule, 136, 0x921CFB58);

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
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b310-0x142c9b490 .text$yd
