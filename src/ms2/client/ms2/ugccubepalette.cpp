// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: ?\ugccubepalette.cpp (.text$mn
// 0x140def070-0x140dfa160, .text$di 0x1400d6940-0x1400d6b50).
//
// The cube palette of the UGC editor: the list of cubes the player can pick (UGCCube), how the list is filtered
// (Unk_CubePaletteFilter), sorted (five sort orders) and where the cubes come from (the bag, the stock of the plot, the
// cube items of the item table that the player does not own, the cubes of a box). The tail of the unit is template glue:
// std::sort over a vector of cube pointers, CAtlArray / CAtlMap / CAtlList / CRBMultiMap of the builders and the smart
// pointers they hold.
// MS2-UNIT: ?\ugccubepalette.cpp
// MS2-RANGE: 0x1400d6940-0x1400d6b50 .text$di
// MS2-RANGE: 0x140def070-0x140dfa160 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1UGCCubePalette@@UEAA@XZ 0x140df5920
// MS2-PIN: ??1UGCCube@UGCCubePalette@@UEAA@XZ 0x140df58d0
// MS2-PIN: ??1Unk_CubeUsage@@QEAA@XZ 0x140df5890
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VUnk_UgcStock@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_UgcStock@@@@@ATL@@@ATL@@QEBA_KXZ 0x140df66e0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCItemData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140df68d0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CDefaultElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@AEBIAEAI1AEAPEAV312@@Z 0x140df69c0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@XZ 0x140df4e50
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@AEBV0@@Z 0x140df5140
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA@XZ 0x140df55d0
// MS2-PIN: ??8?$MS2Ptr@VCItem@@@@QEBA_NPEAVCItem@@@Z 0x140df59d0
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140df6660
// MS2-PIN: ??C?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x140df5ae0
// MS2-PIN: ?get@?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x140df5af0
// MS2-PIN: ??_G?$MS2Ptr@VCItem@@@@QEAAPEAXI@Z 0x140df5bb0
// MS2-PIN: ?AddRef@?$MS2Ptr@VCItem@@@@AEBAXXZ 0x140df9600
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItem@@@@AEBAXPEAX@Z 0x140df96a0
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140df5f10
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x140df6cc0
#include "ms2/placeholder/ms2stdafx.h"
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugccubepalette.cpp"    // assumed (npcdata.h pulls in ms2recover.h)

#include <algorithm>
#include <vector>

#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ugccubepalette.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

typedef UGCCubePalette::UGCCube UGCCube;
typedef UGCCubePalette::CubePtr CubePtr;
typedef UGCCubePalette::CubeArray CubeArray;

// ---- statics (the exe runs them in this order: the box table, the shared header, the handle, the condition, the key
// input) ----

typedef ATL::CAtlMap<unsigned, Unk_FieldIdListPtr, ATL::CDefaultElementTraits<unsigned> > Unk_BoxMap;
static Unk_BoxMap s_mapBoxes(17, 0.75f, 0.25f, 2.25f, 10);                         // @0x1400d6940
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/ugccubepalette_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;                                       // @0x1400d6b20

// ---- unit-local views of exe types (names assumed; layouts only as far as this unit reads them) ----

class CItemDataTable;



// Names of the npc / strings tables.

#include "ms2/commonfiles/npcdata.h"  // C3: CNpcData (FindNpcData)
MS2Ptr<CNpcData> FindNpcData(int nNpcId);


class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

void* GetGameRule();   // C3: was GetGameRule

CStringW GetIconName(int nType, unsigned nId);
int FUN_141901d20(int, __int64, __int64);   // C3: was FUN_141901d20
int FUN_141901f70(int, __int64, __int64);   // C3: was FUN_141901f70
CStringW FUN_14016a730(const char* sz, int nCodePage);

#include "ms2/client/ms2/ugcmapitem.h"
#include "ms2/client/ms2/achievemanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/itemdatatable.h"
// The stock of the plot: the cubes the player has stored.
class Unk_UgcStock : public CUGCMapItem
{
};

#include "ms2/client/ms2/warehouseitem.h"     // DAT_143ab2e20, the warehouse item table
#include "ms2/client/ms2/worldservice.h"


class PCBase;
class Unk_CubeWorld : public WorldService
{
public:
    PCBase* FUN_141bd0cc0();
};
class PC   // C3: member view
{
public:
    int FUN_141663080();
};
class MyPC   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1415302e0(int);
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The home / mastery service: the state of a box.
class Unk_NametagTrophy* GetAchieveManager();   // C3: was GetAchieveManager

// ---- the cubes already taken (the usage of the bag, the stock and the table while a list is built) ----

class Unk_CubeUsage
{
public:
    Unk_CubeUsage();                                                                           // 0x140df1380
    bool FUN_140df13e0(int nItemId);
    bool FUN_140df15e0(MS2Ptr<CItem> spItem, Unk_CubePaletteFilter* pFilter);
    bool FUN_140df1680(MS2Ptr<Unk_UgcStock> spStock, Unk_CubePaletteFilter* pFilter);
    bool FUN_140df1720(int nItemId, unsigned __int64 nInstance, unsigned __int64 nUgc, Unk_CubePaletteFilter* pFilter);
private:
    ATL::CAtlList<unsigned int> m_listIds;              // +0x00 the items taken
    ATL::CAtlList<__int64> m_listInstances;             // +0x30 the item instances taken
    ATL::CRBMultiMap<unsigned int, __int64> m_mapUgc;   // +0x60 the ugc looks taken, by item
};
MS2_CHECK_SIZE(Unk_CubeUsage, 0x90);

// The sorter: orders a list by the sort type of the filter and numbers the cubes.
class Unk_CubeSorter
{
public:
    Unk_CubeSorter(CubeArray& cubes, Unk_CubePaletteFilter* pFilter);                          // 0x140df01c0
};

// ---- UGCCube ----

UGCCube::UGCCube(int itemId)                                                                   // @0x140def070
    : index(0)
{
    itemData = FUN_14053f870(itemId);
    ingredient = TSingleton<CItemDataTable>::GetInstance()->GetHousing(itemId);
    info.AssignRaw(new CubeItemInfo(itemId, 0, 0, 0));
}

UGCCube::UGCCube(int itemId, __int64 uid, __int64 count, CUgcItemLook* pLook)                  // @0x140def210
    : index(0)
{
    itemData = FUN_14053f870(itemId);
    ingredient = TSingleton<CItemDataTable>::GetInstance()->GetHousing(itemId);
    info.AssignRaw(new CubeItemInfo(itemId, uid, count, pLook));
}

MS2Ptr<CubeItemInfo> UGCCube::GetInfo()                                                  // @0x140def3d0
{
    return info;
}

bool UGCCube::IsLocked()                                                                  // @0x140def420
{
    if (itemData == 0)
        return true;
    PCBase* pPC = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return true;
    if (0 < itemData->GetVipLevel())
    {
        if (reinterpret_cast<PC*>(pPC)->FUN_141663080() < itemData->GetVipLevel())
            return true;
    }
    return ((class MyPC*)(class PCBase*)(pPC))->FUN_1415302e0(itemData->GetItemId());
}

bool UGCCube::FUN_140def4f0()                                                                  // @0x140def4f0
{
    if (itemData == 0)
        return false;
    if (itemData->HasMaidId() && FUN_140defe70() > 0)
        return false;
    if (ingredient && ingredient->hasPrice == 0)
        return false;
    return true;
}

int UGCCube::GetItemId()                                                                   // @0x140def5a0
{
    if (itemData.get() != 0)
        return itemData->GetItemId();
    return 0;
}

__int64 UGCCube::GetInstanceId()                                                               // @0x140def5f0
{
    return info->instanceId;
}

__int64 UGCCube::FUN_140def620()                                                               // @0x140def620
{
    if (ingredient.get() != 0)
        return reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047bc50((Unk_SaleHousingKey)ingredient->filter, ingredient->priceCount, ingredient->price);
    return 0;
}

__int64 UGCCube::FUN_140def6c0()                                                               // @0x140def6c0
{
    if (ingredient.get() != 0)
        return ingredient->price;
    return 0;
}

CStringW UGCCube::GetName()                                                              // @0x140def710
{
    MS2Ptr<CUgcItemLook> spLook = info->look;
    if (spLook.get() != 0)
    {
        CStringW strTitle(spLook->m_str28);
        if (!strTitle.IsEmpty())
            return strTitle;
    }
    if (itemData.get() != 0)
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, itemData->GetItemId());
    return L"";
}

CStringW UGCCube::GetIconPath()                                                              // @0x140def880
{
    MS2Ptr<CUgcItemLook> spLook = info->look;
    if (spLook.get() != 0)
    {
        CStringW strName = FUN_14016a730(spLook->GetLocalPath(), 0);
        if (!strName.IsEmpty())
            return strName;
    }
    if (itemData->HasMaidId() && FUN_140defe70() > 0)
    {
        TPtrValue<MaidInfo> spNpc = TSingleton<CMaidInfoTable>::GetInstance()->Find(itemData->GetMaidId());
        if (spNpc.get() != 0)
        {
            MS2Ptr<CNpcData> spData = FindNpcData(spNpc.operator->()->npcId);
            if (spData.get())
                return FUN_14016a730(spData->m_strPortrait, 0);
        }
    }
    if (itemData.get() != 0)
        return FUN_14016a730(itemData->GetIconPath(), 0);
    return L"";
}

__int64 UGCCube::GetUgcUid()                                                               // @0x140defba0
{
    MS2Ptr<CUgcItemLook> spLook = info->look;
    if (spLook.get() != 0)
        return spLook->m_n18;
    return 0;
}

int UGCCube::GetCategoryIndex()                                                                   // @0x140defc30
{
    if (ingredient.get() != 0)
        return ingredient->categoryIndex;
    return 10000;
}

int UGCCube::GetFilter()                                                                   // @0x140defc80
{
    if (ingredient.get() != 0)
        return ingredient->filter;
    return 100;
}

int UGCCube::GetPriceCount()                                                                   // @0x140defcd0
{
    if (ingredient.get() != 0)
        return ingredient->priceCount;
    return 1;
}

CStringW UGCCube::GetPaymentIcon()                                                              // @0x140defd20
{
    int nTier = GetPriceCount();
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d710(0x61) && nTier == 3)
        return GetIconName(10, GetItemId());
    return GetIconName(nTier, GetItemId());
}

bool UGCCube::HasCategoryTag(int nId)                                                           // @0x140defdd0
{
    if (ingredient == 0)
        return false;
    std::vector<unsigned>& ids = ingredient->categoryTag;
    for (size_t i = 0; i < ids.size(); ++i)
    {
        if (ids[i] == nId)
            return true;
    }
    return false;
}

unsigned UGCCube::FUN_140defe70()                                                                   // @0x140defe70
{
    return FUN_141901d20(GetItemId(), GetInstanceId(), GetUgcUid());
}

unsigned UGCCube::FUN_140defed0()                                                                   // @0x140defed0
{
    return FUN_141901f70(GetItemId(), GetInstanceId(), GetUgcUid());
}

bool UGCCube::FUN_140deff30()                                                                  // @0x140deff30
{
    if (itemData == 0)
        return false;
    PCBase* pPC = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return false;
    if (!(reinterpret_cast<PC*>(pPC)->FUN_141663080() > 0))
        return false;
    if (!(itemData->GetVipLevel() > 0))
        return false;
    if (reinterpret_cast<PC*>(pPC)->FUN_141663080() >= itemData->GetVipLevel())
        return true;
    return false;
}

int UGCCube::GetIndex()                                                                   // @0x140defff0
{
    return index;
}

void UGCCube::SetIndex(int nIndex)                                                        // @0x140df0010
{
    index = nIndex;
}

// ---- the filter ----

Unk_CubePaletteFilter::Unk_CubePaletteFilter()                                                 // @0x140df0030
    : includeOwned(true), flag1(false), flag2(false), category(1), text("")
{
    field10 = 0;
    field14 = 5;
    field18 = 100;
}

bool Unk_CubePaletteFilter::FUN_140df00b0()                                                    // @0x140df00b0
{
    if (field18 >= 101)
        return true;
    return false;
}

bool Unk_CubePaletteFilter::FUN_140df00d0()                                                    // @0x140df00d0
{
    if (field18 >= 101)
        return false;
    return true;
}

bool Unk_CubePaletteFilter::FUN_140df00f0()                                                    // @0x140df00f0
{
    if (field18 >= 101)
        return true;
    return false;
}

int Unk_CubePaletteFilter::FUN_140df0110()                                                     // @0x140df0110
{
    if (field18 >= 101)
        return 0;
    return field14;
}

void Unk_CubePaletteFilter::FUN_140df0140(int nSort)                                           // @0x140df0140
{
    field14 = nSort;
}

int Unk_CubePaletteFilter::FUN_140df0160()                                                     // @0x140df0160
{
    return field18;
}

void Unk_CubePaletteFilter::FUN_140df0180(int nBox)                                            // @0x140df0180
{
    field18 = nBox;
}

int Unk_CubePaletteFilter::GetCategory()                                                     // @0x140df01a0
{
    return category;
}

// ---- the sort orders ----

static bool FUN_140df04d0(const CubePtr& a, const CubePtr& b)                                  // @0x140df04d0
{
    if (a->IsLocked() && !b->IsLocked())
        return false;
    if (!a->IsLocked() && b->IsLocked())
        return true;
    if (a->GetPriceCount() < b->GetPriceCount())
        return false;
    if (a->GetPriceCount() > b->GetPriceCount())
        return true;
    if (a->FUN_140def620() < b->FUN_140def620())
        return false;
    if (a->FUN_140def620() > b->FUN_140def620())
        return true;
    if ((unsigned)a->GetItemId() > (unsigned)b->GetItemId())
        return false;
    if (a->GetFilter() == 0x5b && b->GetFilter() == 0x5b && a->GetItemId() == b->GetItemId()
        && (unsigned __int64)a->GetInstanceId() > 0 && b->GetInstanceId() == 0)
        return false;
    return true;
}

static bool FUN_140df0710(const CubePtr& a, const CubePtr& b)                                  // @0x140df0710
{
    if (a->IsLocked() && !b->IsLocked())
        return false;
    if (!a->IsLocked() && b->IsLocked())
        return true;
    if (a->GetPriceCount() > b->GetPriceCount())
        return false;
    if (a->GetPriceCount() < b->GetPriceCount())
        return true;
    if (a->FUN_140def620() > b->FUN_140def620())
        return false;
    if (a->FUN_140def620() < b->FUN_140def620())
        return true;
    if ((unsigned)a->GetItemId() > (unsigned)b->GetItemId())
        return false;
    if (a->GetFilter() == 0x5b && b->GetFilter() == 0x5b && a->GetItemId() == b->GetItemId()
        && (unsigned __int64)a->GetInstanceId() > 0 && b->GetInstanceId() == 0)
        return false;
    return true;
}

static bool FUN_140df0950(const CubePtr& a, const CubePtr& b)                                  // @0x140df0950
{
    if (a->IsLocked() && !b->IsLocked())
        return false;
    if (!a->IsLocked() && b->IsLocked())
        return true;
    if (a->GetName() > b->GetName())
        return false;
    if (a->GetName() < b->GetName())
        return true;
    if (a->GetPriceCount() > b->GetPriceCount())
        return false;
    if (a->GetPriceCount() < b->GetPriceCount())
        return true;
    if (a->FUN_140def620() > b->FUN_140def620())
        return false;
    if (a->FUN_140def620() < b->FUN_140def620())
        return true;
    if ((unsigned)a->GetItemId() > (unsigned)b->GetItemId())
        return false;
    if (a->GetFilter() == 0x5b && b->GetFilter() == 0x5b && a->GetItemId() == b->GetItemId()
        && (unsigned __int64)a->GetInstanceId() > 0 && b->GetInstanceId() == 0)
        return false;
    return true;
}

static bool FUN_140df0cf0(const CubePtr& a, const CubePtr& b)                                  // @0x140df0cf0
{
    if (a->IsLocked() && !b->IsLocked())
        return false;
    if (!a->IsLocked() && b->IsLocked())
        return true;
    if (a->GetName() < b->GetName())
        return false;
    if (a->GetName() > b->GetName())
        return true;
    if (a->GetPriceCount() > b->GetPriceCount())
        return false;
    if (a->GetPriceCount() < b->GetPriceCount())
        return true;
    if (a->FUN_140def620() > b->FUN_140def620())
        return false;
    if (a->FUN_140def620() < b->FUN_140def620())
        return true;
    if ((unsigned)a->GetItemId() > (unsigned)b->GetItemId())
        return false;
    if (a->GetFilter() == 0x5b && b->GetFilter() == 0x5b && a->GetItemId() == b->GetItemId()
        && (unsigned __int64)a->GetInstanceId() > 0 && b->GetInstanceId() == 0)
        return false;
    return true;
}

static bool FUN_140df1090(const CubePtr& a, const CubePtr& b)                                  // @0x140df1090
{
    if (a->FUN_140deff30())
        return true;
    if (b->FUN_140deff30())
        return false;
    if (a->IsLocked() && !b->IsLocked())
        return false;
    if (!a->IsLocked() && b->IsLocked())
        return true;
    if (a->GetCategoryIndex() > b->GetCategoryIndex())
        return false;
    if (a->GetCategoryIndex() < b->GetCategoryIndex())
        return true;
    if (a->GetPriceCount() > b->GetPriceCount())
        return false;
    if (a->GetPriceCount() < b->GetPriceCount())
        return true;
    if (a->FUN_140def620() > b->FUN_140def620())
        return false;
    if (a->FUN_140def620() < b->FUN_140def620())
        return true;
    if ((unsigned)a->GetItemId() > (unsigned)b->GetItemId())
        return false;
    if (a->GetFilter() == 0x5b && b->GetFilter() == 0x5b && a->GetItemId() == b->GetItemId()
        && (unsigned __int64)a->GetInstanceId() > 0 && b->GetInstanceId() == 0)
        return false;
    return true;
}

Unk_CubeSorter::Unk_CubeSorter(CubeArray& cubes, Unk_CubePaletteFilter* pFilter)               // @0x140df01c0
{
    std::vector<CubePtr> vecCubes;
    for (unsigned i = 0; i < cubes.GetCount(); ++i)
        vecCubes.push_back(cubes[i]);
    switch (pFilter->FUN_140df0110())
    {
    case 1: std::sort(vecCubes.begin(), vecCubes.end(), FUN_140df04d0); break;
    case 2: std::sort(vecCubes.begin(), vecCubes.end(), FUN_140df0710); break;
    case 3: std::sort(vecCubes.begin(), vecCubes.end(), FUN_140df0950); break;
    case 4: std::sort(vecCubes.begin(), vecCubes.end(), FUN_140df0cf0); break;
    case 5: std::sort(vecCubes.begin(), vecCubes.end(), FUN_140df1090); break;
    }
    cubes.RemoveAll();
    for (std::vector<CubePtr>::const_iterator it = vecCubes.begin(); it != vecCubes.end(); ++it)
    {
        CubePtr spCube = *it;
        cubes.Add(spCube);
        spCube->SetIndex((int)cubes.GetCount());
    }
}

// ---- the usage ----

Unk_CubeUsage::Unk_CubeUsage()                                                                 // @0x140df1380
    : m_listIds(10)
    , m_listInstances(10)
    , m_mapUgc(10)
{
}

bool Unk_CubeUsage::FUN_140df13e0(int nItemId)                                                 // @0x140df13e0
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return false;
    MS2Ptr<ItemHousing> spIng = TSingleton<CItemDataTable>::GetInstance()->GetHousing(nItemId);
    if (spIng && spIng->hasPrice == 0)
        return false;
    if (spData->HasCubeTextureMesh())
        return false;
    if (spData->HasMaidId())
        return true;
    if (m_listIds.Find(nItemId) != 0)
        return false;
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FindItemById(nItemId);
    if (spItem.get() != 0)
        return false;
    return true;
}

bool Unk_CubeUsage::FUN_140df15e0(MS2Ptr<CItem> spItem, Unk_CubePaletteFilter* pFilter)        // @0x140df15e0
{
    return FUN_140df1720(spItem->GetItemId(), spItem->GetItemUid(), spItem->GetUgcUid(), pFilter);
}

bool Unk_CubeUsage::FUN_140df1680(MS2Ptr<Unk_UgcStock> spStock, Unk_CubePaletteFilter* pFilter)  // @0x140df1680
{
    return FUN_140df1720(spStock->GetItemId(), spStock->GetUid(), spStock->GetLookId(), pFilter);
}

bool Unk_CubeUsage::FUN_140df1720(int nItemId, unsigned __int64 nInstance, unsigned __int64 nUgc, Unk_CubePaletteFilter* pFilter)   // @0x140df1720
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return false;
    if (pFilter->FUN_140df00b0() && spData->HasMaidId())
        return false;
    if (m_listInstances.Find(nInstance) != 0)
        return false;
    if (m_listIds.Find(nItemId) != 0)
    {
        if (spData->HasMaidId())
            return true;
        if (spData->HasCubeTextureMesh())
        {
            POSITION pos = m_mapUgc.FindFirstWithKey(nItemId);
            while (pos != 0)
            {
                __int64 nValue = m_mapUgc.GetNextValueWithKey(pos, nItemId);
                if (nUgc == nValue)
                    return false;
            }
            if (nUgc >= 0)
                m_mapUgc.Insert(nItemId, nUgc);
            return true;
        }
        return false;
    }
    m_listIds.AddTail(nItemId);
    if (nInstance > 0)
        m_listInstances.AddTail(nInstance);
    if (spData->HasCubeTextureMesh() && nUgc >= 0)
        m_mapUgc.Insert(nItemId, nUgc);
    return true;
}

// ---- the palette ----

static bool FUN_140df3350(const CStringW& strFilter, const CStringW& strName);


UGCCubePalette::UGCCubePalette()                                                               // @0x140df19b0
    : mapItems(17, 0.75f, 0.25f, 2.25f, 10)
{
    FUN_140df2250();
}

unsigned UGCCubePalette::FUN_140df1a40(CubeArray& out, Unk_CubePaletteFilter& filter)    // @0x140df1a40
{
    CubeArray cubes;
    if (filter.FUN_140df00f0())
        FUN_140df2bc0(cubes, &filter);
    else
        FUN_140df23f0(cubes, &filter);
    for (unsigned i = 0; i < cubes.GetCount(); ++i)
    {
        CubePtr spCube = cubes[i];
        if (spCube == 0)
            continue;
        if (!filter.includeOwned)
        {
            MS2Ptr<CItemData> spData;
            if (mapItems.Lookup(spCube->GetItemId(), spData))
            {
                MS2Ptr<ItemHousing> spIng = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId());
                if (spIng && TSingleton<UGCCubeCategoryTable>::GetInstance()->HasAnyField(spIng->categoryTag))
                    continue;
            }
        }
        if (filter.flag2 && spCube->IsLocked())
            continue;
        if (!filter.text.IsEmpty())
        {
            if (!FUN_140df3350(filter.text, spCube->GetName()))
                continue;
        }
        if (filter.field10 != 0)
        {
            if (!spCube->HasCategoryTag(filter.field10))
                continue;
        }
        out.Add(spCube);
    }
    Unk_CubeSorter sorter(out, &filter);
    return out.GetCount() > 0;
}

// ---- the box table ----

void FUN_140df1e00();
#ifndef MS2_HOOK_DLL
void FUN_140df1e00()                                                                           // @0x140df1e00
{
    if (s_mapBoxes.Lookup(0x65) != 0)
        return;
    s_mapBoxes.SetAt(0x65, Unk_FieldIdListPtr(Unk_FieldNewTag(0)));
}
#endif

void FUN_140df1e90(unsigned nBox, unsigned nItemId)                                            // @0x140df1e90
{
    Unk_FieldIdListPtr spList;
    if (s_mapBoxes.Lookup(nBox, spList))
    {
        POSITION pos = spList->Find(nItemId);
        if (pos == 0)
            spList->AddHead(nItemId);
        else
            spList->MoveToHead(pos);
    }
}

void FUN_140df1f40(unsigned nBox, unsigned nItemId);
#ifndef MS2_HOOK_DLL
void FUN_140df1f40(unsigned nBox, unsigned nItemId)                                            // @0x140df1f40
{
    Unk_FieldIdListPtr spList;
    if (s_mapBoxes.Lookup(nBox, spList))
    {
        POSITION pos = spList->Find(nItemId);
        if (pos == 0)
            spList->AddTail(nItemId);
        else
            spList->MoveToTail(pos);
    }
}
#endif

void FUN_140df1ff0(unsigned nBox, Unk_FieldIdList* pOut)                                       // @0x140df1ff0
{
    Unk_FieldIdListPtr spList;
    if (s_mapBoxes.Lookup(nBox, spList))
    {
        for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
            pOut->AddTail(spList->GetAt(pos));
    }
}

unsigned AddBoxById(unsigned nArgA, unsigned nArgB);
#ifndef MS2_HOOK_DLL
unsigned AddBoxById(unsigned nArgA, unsigned nArgB)                                         // @0x140df20a0
{
    unsigned nBox = TSingleton<UGCCubeCategoryTable>::GetInstance()->AddMenuById(nArgA, nArgB);
    s_mapBoxes.SetAt(nBox, Unk_FieldIdListPtr(Unk_FieldNewTag(0)));
    return nBox;
}
#endif

unsigned AddBoxByName(CStringW strName, unsigned nArg);
#ifndef MS2_HOOK_DLL
unsigned AddBoxByName(CStringW strName, unsigned nArg)                                        // @0x140df2130
{
    unsigned nBox = TSingleton<UGCCubeCategoryTable>::GetInstance()->AddMenu(strName, nArg);
    s_mapBoxes.SetAt(nBox, Unk_FieldIdListPtr(Unk_FieldNewTag(0)));
    return nBox;
}
#endif

void RemoveBox(unsigned nBox);
#ifndef MS2_HOOK_DLL
void RemoveBox(unsigned nBox)                                                              // @0x140df2210
{
    TSingleton<UGCCubeCategoryTable>::GetInstance()->RemoveMenu(nBox);
    s_mapBoxes.RemoveKey(nBox);
}
#endif

// ---- the palette ----

void UGCCubePalette::FUN_140df2250()                                                           // @0x140df2250
{
    mapItems.RemoveAll();
    std::vector<unsigned> vecIds;
    TSingleton<CItemDataTable>::GetInstance()->LoadItemNameIds(vecIds);
    for (size_t i = 0; i < vecIds.size(); ++i)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(vecIds[i]);
        if (spData == 0)
            continue;
        if (!spData->IsInstallItem())
            continue;
        if (TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId()) == 0)
            continue;
        mapItems.SetAt(spData->GetItemId(), spData);
    }
}

void UGCCubePalette::FUN_140df23f0(CubeArray& out, Unk_CubePaletteFilter* pFilter)             // @0x140df23f0
{
    MS2Ptr<CFieldDataCli> spField = reinterpret_cast<Unk_CubeWorld*>(WorldService::GetInstance())->FUN_141bd30a0();
    if (spField == 0)
        return;
    Unk_CubeUsage usage;
    {
        ATL::CAtlArray<MS2Ptr<CItem> > items;
        DAT_143ab2e20.FUN_1408fbc70(items);
        for (size_t i = 0; i < items.GetCount(); ++i)
        {
            MS2Ptr<CItem> spItem = items[i];
            if (spItem == 0)
                continue;
            int nItemId = spItem->GetItemId();
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData == 0)
                continue;
            if (FUN_140df3100(spField, spData, pFilter))
                continue;
            if (usage.FUN_140df15e0(spItem, pFilter))
            {
                CubePtr spNew(new UGCCube(nItemId, spItem->GetItemUid(), spItem->FUN_140528910(), spItem->GetUgcLook()));
                out.Add(spNew);
            }
        }
    }
    {
        ATL::CAtlArray<MS2Ptr<Unk_UgcStock> > stocks;
        DAT_143ab2e50.FUN_140dfc750(*reinterpret_cast<ATL::CAtlArray<MS2Ptr<CUGCMapItem> >*>(&stocks));
        for (size_t i = 0; i < stocks.GetCount(); ++i)
        {
            MS2Ptr<Unk_UgcStock> spStock = stocks[i];
            if (spStock == 0)
                continue;
            int nItemId = spStock->GetItemId();
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData == 0)
                continue;
            if (FUN_140df3100(spField, spData, pFilter))
                continue;
            if (usage.FUN_140df1680(spStock, pFilter))
            {
                out.Add(new UGCCube(nItemId, spStock->GetUid(), spStock->GetCount(), spStock->GetLook().get()));
            }
        }
    }
    if (!pFilter->flag1)
    {
        for (POSITION pos = mapItems.GetStartPosition(); pos != 0; mapItems.GetNext(pos))
        {
            int nItemId = mapItems.GetKeyAt(pos);
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData == 0)
                continue;
            if (FUN_140df3100(spField, spData, pFilter))
                continue;
            if (usage.FUN_140df13e0(nItemId))
            {
                CubePtr spNew(new UGCCube(nItemId));
                out.Add(spNew);
            }
        }
    }
}

void UGCCubePalette::FUN_140df2bc0(CubeArray& out, Unk_CubePaletteFilter* pFilter)             // @0x140df2bc0
{
    MS2Ptr<CFieldDataCli> spField = reinterpret_cast<Unk_CubeWorld*>(WorldService::GetInstance())->FUN_141bd30a0();
    if (spField == 0)
        return;
    Unk_FieldIdListPtr spList;
    if (!s_mapBoxes.Lookup(pFilter->FUN_140df0160(), spList))
        return;
    for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
    {
        unsigned nItemId = spList->GetAt(pos);
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData == 0)
            continue;
        if (FUN_140df3100(spField, spData, pFilter))
            continue;
        MS2Ptr<CItem> spItem = DAT_143ab2e20.FindItemById(nItemId);
        if (spItem.get() != 0)
        {
            out.Add(new UGCCube(nItemId, spItem->GetItemUid(), spItem->FUN_140528910(), spItem->GetUgcLook()));
            continue;
        }
        MS2Ptr<CUGCMapItem> spStock = DAT_143ab2e50.FUN_140dfc800(nItemId);
        if (spStock.get() != 0)
        {
            out.Add(new UGCCube(nItemId, spStock->GetUid(), spStock->GetCount(), spStock->GetLook().get()));
            continue;
        }
        if (!pFilter->flag1)
        {
            CubePtr spNew(new UGCCube(nItemId));
            out.Add(spNew);
        }
    }
}

bool UGCCubePalette::FUN_140df3100(const MS2Ptr<CFieldDataCli>& spField, const MS2Ptr<CItemData>& spData, Unk_CubePaletteFilter* pFilter)   // @0x140df3100
{
    if (spField->FUN_140375100())
    {
        if (!spData->install.FUN_140548d10())
            return true;
    }
    if (spField->IsIndoor())
    {
        if (!spData->install.FUN_140548cd0())
            return true;
    }
    MS2Ptr<ItemHousing> spIng = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId());
    if (spIng == 0)
        return false;
    if (pFilter->FUN_140df0160() != spIng->filter)
    {
        if (pFilter->FUN_140df00f0())
            return false;
        return true;
    }
    int nBoxId = spIng->trophyID;
    int nBoxArg = spIng->trophyLevel;
    if (reinterpret_cast<CAchieveManager*>(GetAchieveManager())->IsGradeCleared(nBoxId, nBoxArg) == 0)
    {
        MS2Ptr<CAchieve> spBox = reinterpret_cast<CAchieveManager*>(GetAchieveManager())->Find(nBoxId);
        if (spBox && spBox.get()->GetData68() != 0)
            return true;
    }
    return false;
}

static bool FUN_140df3350(const CStringW& strFilter, const CStringW& strName)                  // @0x140df3350
{
    CStringW strKey(strFilter);
    CStringW strTarget(strName);
    strKey.Trim(L"\"\"");
    strKey.MakeLower();
    strTarget.MakeLower();
    if (strKey.GetLength() < strFilter.GetLength())
    {
        if (strName.Find(strKey, 0) != -1)
            return true;
    }
    else
    {
        strKey.Replace(L" ", L"");
        strTarget.Replace(L" ", L"");
        if (strTarget.Find(strKey, 0) != -1)
            return true;
    }
    return false;
}

// ---- hooks (members that read no mutable unit static) ----
MS2_REPLACE_METHOD(0x140DEF420, UGCCube, IsLocked, 191, 0x53A80095);
MS2_REPLACE_METHOD(0x140DEF4F0, UGCCube, FUN_140def4f0, 168, 0xCDF7544C);
MS2_REPLACE_METHOD(0x140DEF5A0, UGCCube, GetItemId, 65, 0x0250E2B3);
MS2_REPLACE_METHOD(0x140DEFC30, UGCCube, GetCategoryIndex, 63, 0x84911D1F);
MS2_REPLACE_METHOD(0x140DEFC80, UGCCube, GetFilter, 63, 0x9B115DD9);
MS2_REPLACE_METHOD(0x140DEFCD0, UGCCube, GetPriceCount, 63, 0x4A3A45AA);
MS2_REPLACE_METHOD(0x140DEFDD0, UGCCube, HasCategoryTag, 146, 0x7A5AE522);
MS2_REPLACE_METHOD(0x140DEFE70, UGCCube, FUN_140defe70, 77, 0x26B3D68E);
MS2_REPLACE_METHOD(0x140DEFED0, UGCCube, FUN_140defed0, 77, 0xA7BDAFEE);
MS2_REPLACE_METHOD(0x140DEFF30, UGCCube, FUN_140deff30, 178, 0x06DA54A2);
MS2_REPLACE_METHOD(0x140DEFFF0, UGCCube, GetIndex, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140DF0010, UGCCube, SetIndex, 22, 0x068001AB);
MS2_REPLACE_METHOD(0x140DF00B0, Unk_CubePaletteFilter, FUN_140df00b0, 23, 0xF8A6CA9A);
MS2_REPLACE_METHOD(0x140DF00D0, Unk_CubePaletteFilter, FUN_140df00d0, 23, 0x5B0BD116);
MS2_REPLACE_METHOD(0x140DF00F0, Unk_CubePaletteFilter, FUN_140df00f0, 23, 0xF8A6CA9A);
MS2_REPLACE_METHOD(0x140DF0110, Unk_CubePaletteFilter, FUN_140df0110, 29, 0x28CCC832);
MS2_REPLACE_METHOD(0x140DF0140, Unk_CubePaletteFilter, FUN_140df0140, 22, 0x3E6244BF);
MS2_REPLACE_METHOD(0x140DF0160, Unk_CubePaletteFilter, FUN_140df0160, 14, 0x72E52537);
MS2_REPLACE_METHOD(0x140DF0180, Unk_CubePaletteFilter, FUN_140df0180, 22, 0x068001AB);
MS2_REPLACE_METHOD(0x140DF01A0, Unk_CubePaletteFilter, GetCategory, 14, 0x7AB52803);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5fa0-0x142ca6070 .text$yd
