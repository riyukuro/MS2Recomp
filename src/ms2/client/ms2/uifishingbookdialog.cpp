// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIFishingBookDialog: see uifishingbookdialog.h.
// MS2-UNIT: ?\uifishingbookdialog.cpp
// MS2-RANGE: 0x1400df250-0x1400df560 .text$di
// MS2-RANGE: 0x140f41250-0x140f43df0 .text$mn
// MS2-PIN: ??$max@H@std@@YAAEBHAEBH0@Z 0x140f43be0
// MS2-PIN: ??1UIFishingBookDialog@@UEAA@XZ 0x140f43c90
// MS2-PIN: ??_GUIFishingBookDialog@@UEAAPEAXI@Z 0x140f43d30
// MS2-PIN: ??B?$MS2Ptr@VASTileList@@@@QEBAPEAVASTileList@@XZ 0x140acd9d0
// MS2-PIN: ??B?$MS2Ptr@VASTextField@@@@QEBAPEAVASTextField@@XZ 0x140b9a800
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uifishingbookdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uifishingbookdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/fishsimultedata.h"
#include "ms2/placeholder/fishingmanager.h"
#include <algorithm>
#include <stdlib.h>
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/blockformat.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/client/ms2/achievemanager.h"
#include "ms2/commonfiles/titletable.h"

// The header statics of the including TU come from header_statics_a.h; then the book's own "open" sound, and the second
// copy of the header statics the link order puts behind it.
static CString s_strBookOpen("System_Fishing_BookOpen");
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects ----

int FUN_141276180(const CString& strName, const CString& strArg);       // play a system sound
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
CStringW FUN_141b720b0(int nId, __int64 nValue);
template <class A> CStringW FormatStringId(int nStringId, const A& a);


// The list control of the movie: slot 24 is not named on ASCoreList.
class Unk_FbCtl : public ASCoreList
{
public:
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool b);
};
// The mastery table and the objects behind a few switches.
class Unk_MData* FUN_1409670c0();
class Unk_NametagTrophy* FUN_1406c7600();   // C3: was FUN_1406c7600
class Unk_ItemSlotTable* FUN_140933210();   // C3: was FUN_140933210
unsigned FUN_140931450(CString strName);
CInputKeyHandler* FUN_14025e7c0();
const unsigned& FUN_1402cf010(const unsigned& a, const unsigned& b);

// The array of the player's fish records (an exe CAtlArray look-alike; ctor / dtor / GetAt / GetCount are in this unit).
class Unk_FbItemArray
{
public:
    Unk_FbItemArray();                                          // 0x140f43c10
    ~Unk_FbItemArray() throw();                                 // 0x140f43c50
    MS2Ptr<CFish>& FUN_140f43cb0(unsigned __int64 nIndex);      // GetAt
    unsigned __int64 GetSize();                           // GetCount
private:
    MS2Ptr<CFish>* m_pData;
    unsigned __int64 m_nSize;
    unsigned __int64 m_nMaxSize;
    int m_nGrowBy;
};
// The AS invokes of the movie root the exe has one instance of per argument list.
class Unk_GalleryAS
{
public:
    template<class A, class B> Scaleform::GFx::Value Invoke2(const char* method, A a, B b);
};

void FUN_140f43d70(MS2Ptr<CFish>* pItems, unsigned __int64 nCount);
MS2Ptr<CFish>* FUN_140f43cf0(MS2Ptr<CFish>* p, unsigned int nFlags);
int FUN_140f438b0(const int* pA, const int* pB);

// @0x140f41250
UIFishingBookDialog::UIFishingBookDialog()
{
    FUN_141924170(1);
    m_164 = 1;
    m_nPage = 0;
    m_nTab = 0;
}

// @0x140f412e0
CString UIFishingBookDialog::GetTypeName()
{
    return "FishingBookDialog";
}

// @0x140f41330
void UIFishingBookDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nPage = 0;
    m_nTab = 0;
    FUN_140f42790(m_nTab);
    FUN_140f41a10();
    if (MS2Ptr<ASTileList> spBag = GetChild<ASTileList>("m_bag"))
        spBag->SetSelectedIndex(0);
    FUN_141276180(s_strBookOpen, "");
}

// @0x140f41440
int UIFishingBookDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onChangeFish") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nFishId = data.PopUInt();
            FUN_140f42100(nFishId);
        }
    }
    else if (_stricmp(szMethod, "onTabChange") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_nTab = data.PopInt();
            m_nPage = 0;
            FUN_140f42790(m_nTab);
        }
    }
    else if (_stricmp(szMethod, "onPrevPage") == 0)
    {
        if (FUN_140f42cd0(m_nPage - 1) != 0)
        {
            m_nPage = m_nPage - 1;
            FUN_140f42790(m_nTab);
        }
    }
    else if (_stricmp(szMethod, "onNextPage") == 0 && FUN_140f42cd0(m_nPage + 1) != 0)
    {
        m_nPage = m_nPage + 1;
        FUN_140f42790(m_nTab);
    }
    return 0;
}

// @0x140f416b0
void UIFishingBookDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    CStringW strText;
    int nExp = pPC->GetMastery(1);
    int nGrade = pPC->GetMasteryGrade(1);
    if (nGrade == reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->MaxGrade(1))
    {
        strText = GetStringCommonByKey(L"s_fishing_mastery_tooltip_level_max");
    }
    else
    {
        int nBase = reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->Value(1, nGrade);
        int nNextBase = reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->Value(1, nGrade + 1);
        int nMax = nNextBase - nBase;
        int nCur = nExp - nBase;
        strText = BlockFormat<unsigned, unsigned>(0xbeb, reinterpret_cast<const unsigned&>(nCur), reinterpret_cast<const unsigned&>(nMax));
    }
    ASTooltip tooltip(1, 2);
    tooltip.SetTooltipClass("export_common_tooltip_tooltipText");
    tooltip.SetOnDelay(300);
    tooltip.SetOffDelay(60000);
    tooltip.SetTooltipAlign(1);
    tooltip.SetText(strText);
    *pRetVal = tooltip.FUN_1422bb870();
}

// @0x140f41940
void UIFishingBookDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    Unk_FbItemArray items;
    TSingleton<CFishingManager>::GetInstance()->GetAllFish(reinterpret_cast<ATL::CAtlArray<MS2Ptr<CFish> >&>(items));
    for (unsigned __int64 i = 0; i < items.GetSize(); i++)
        items.FUN_140f43cb0(i)->m_bNew = 0;
}

// @0x140f419e0
void UIFishingBookDialog::FUN_140f419e0()
{
    FUN_140f42790(m_nTab);
}

// @0x140f41a10
void UIFishingBookDialog::FUN_140f41a10()
{
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    int nExp = pPC->GetMastery(1);
    int nGrade = pPC->GetMasteryGrade(1);
    int nBase = reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->Value(1, nGrade);
    int nNextBase = reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->Value(1, nGrade + 1);
    int nTitle = FUN_140f42ed0();
    CStringW strTitle = (nTitle == 0) ? GetStringCommonByKey(L"s_fishing_none_title") : FUN_141b720b0(nTitle, 0);
    CStringW strGrade = FUN_140f432e0(nGrade);
    if (nGrade == reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->MaxGrade(1))
        strGrade += L" " + GetStringCommonByKey(L"s_fishing_mastery_gauge_level_max");
    ASObj obj(2);
    obj.FUN_1409c0d20("fisherTitleID", nTitle);
    obj.FUN_1407cbb20("fisherTitle", CStringW(strTitle));
    obj.FUN_1407cbb20("fisherGradeName", CStringW(strGrade));
    obj.FUN_1409c0d20("curMastery", nExp - nBase);
    obj.FUN_1409c0d20("maxMastery", nNextBase - nBase);
    if (m_30.get() != 0)
        m_30->FUN_140acd1f0("setFisher", AScript(obj));
}

// @0x140f41e90
void UIFishingBookDialog::FUN_140f41e90()
{
    if (m_30.get() != 0)
    {
        Unk_FbItemArray items;
        TSingleton<CFishingManager>::GetInstance()->GetAllFish(reinterpret_cast<ATL::CAtlArray<MS2Ptr<CFish> >&>(items));
        int aNew[4] = {0};
        for (unsigned __int64 i = 0; i < items.GetSize(); i++)
        {
            MS2Ptr<CFish> item = items.FUN_140f43cb0(i);
            if (item->m_bNew == 0)
                continue;
            CFish* pRec = item.operator->();
            MS2Ptr<CFishData> fish = TSingleton<CFishingTable>::GetInstance()->GetFish(pRec->m_nId);
            if (fish.IsNull() != 0)
                continue;
            switch (fish->m_nHabitat)
            {
            case 0:
                aNew[0] = 1;
                break;
            case 1:
                aNew[1] = 1;
                break;
            case 7:
                aNew[3] = 1;
                break;
            default:
                aNew[2] = 1;
                break;
            }
        }
        for (unsigned __int64 j = 0; j < 4; j++)
            reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<size_t, int>("setTabNew", j, aNew[j]);
    }
}

// @0x140f42100
void UIFishingBookDialog::FUN_140f42100(int nFishId)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ASObj obj(2);
    MS2Ptr<CFishData> fish = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
    if (fish.get() != 0)
    {
        MS2Ptr<CFish> item = TSingleton<CFishingManager>::GetInstance()->FindFish(nFishId);
        CFishData* pRec = fish.operator->();
        int nArea = reinterpret_cast<CMasteryTable*>(FUN_1409670c0())->Grade(1, pRec->m_nMastery);
        obj.FUN_1407cbb20("iconPath", fish->FUN_1403b1600());
        obj.FUN_1407cbb20("fishName", fish->FUN_1403b1650());
        obj.FUN_1407cbb20("fishingExp", fish->m_nIgnoreSpotMastery != 0 ? GetStringCommonByKey(L"s_fishing_all_spot") : FUN_140f432e0(nArea));
        obj.FUN_1409adc90("fishRank", fish->m_nRank);
        obj.FUN_1407cbb20("fishGradeName", FormatStringId<CStringW>(0xbda, TSingleton<CStringTable>::GetInstance()->GetRankName(fish->m_nRank)));
        obj.FUN_1407cbb20("desc", fish->FUN_1403b16b0(FUN_140f43330(fish->m_nId)));
        obj.FUN_1407cb9c0("acquire", FUN_140f43330(fish->m_nId));
        obj.FUN_140f43b40("medal", FUN_140f43540(nFishId));
        if (FUN_140f43330(fish->m_nId) != 0)
        {
            obj.FUN_1407cbb20("totalCatchCount", BlockFormat<unsigned>(0xbdb, (unsigned)FUN_140f43610(nFishId)));
            obj.FUN_1407cbb20("bigSizeCatchCount", BlockFormat<unsigned>(0xbdb, (unsigned)FUN_140f436f0(nFishId)));
            obj.FUN_1407cbb20("bestRecord", BlockFormat<unsigned>(0xbdc, (unsigned)FUN_140f437d0(nFishId)));
        }
    }
    else
    {
        obj.FUN_1407cb9c0("acquire", 0);
        obj.FUN_1407cb9c0("medal", 0);
    }
    m_30->FUN_140acd1f0("setFish", AScript(obj));
}

// @0x140f42790
void UIFishingBookDialog::FUN_140f42790(int nTab)
{
    FbIdArray ids;
    FUN_140f42d90(ids);
    qsort(ids.GetData(), ids.GetCount(), 4, (int (*)(const void*, const void*))FUN_140f438b0);
    if (MS2Ptr<ASTileList> spBag = GetChild<ASTileList>("m_bag"))
    {
        spBag->FUN_1422dd1d0();
        for (unsigned __int64 i = 0; i < 0x14; i++)
        {
            ASObj obj(2);
            MS2Ptr<CFish> item(0);
            MS2Ptr<CFishData> fish(0);
            int nIndex = m_nPage * 0x14 + i;
            if (nIndex >= 0)
            {
                if (nIndex < (int)ids.GetCount())
                {
                    int* pId = &ids[nIndex];
                    fish = TSingleton<CFishingTable>::GetInstance()->GetFish(*pId);
                    item = TSingleton<CFishingManager>::GetInstance()->FindFish(fish->m_nId);
                }
            }
            if (fish.get() != 0)
            {
                obj.FUN_1409c0d20("id", fish->m_nId);
                obj.FUN_1407cbb20("iconPath", fish->FUN_1403b1600());
                obj.FUN_1407cb9c0("acquire", FUN_140f43330(fish->m_nId));
                obj.FUN_1409adc90("grade", fish->m_nRank);
                obj.FUN_140f43b40("medal", FUN_140f43540(fish->m_nId));
                obj.FUN_1407cb9c0("isNew", FUN_140f43380(fish->m_nId));
            }
            spBag->AddItem(obj);
        }
        reinterpret_cast<Unk_FbCtl*>(spBag.operator->())->vfunc_24(true);
    }
    if (MS2Ptr<ASTextField> spPage = GetChild<ASTextField>("m_page"))
    {
        int nCur = m_nPage + 1;
        spPage->SetTextW(StringFormat<int>(L"{0}", nCur));
    }
    FUN_140f41e90();
}

// @0x140f42cd0
int UIFishingBookDialog::FUN_140f42cd0(int nPage)
{
    FbIdArray ids;
    FUN_140f42d90(ids);
    int nPages = (int)(ids.GetCount() / 0x14);
    if (ids.GetCount() % 0x14 != 0)
        nPages = nPages + 1;
    if (nPage < 0 || nPage >= nPages)
        return 0;
    return 1;
}

// @0x140f42d90
void UIFishingBookDialog::FUN_140f42d90(FbIdArray& rIds)
{
    if (m_nTab == 0)
    {
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 0, 1);
    }
    else if (m_nTab == 1)
    {
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 1, 1);
    }
    else if (m_nTab == 2)
    {
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 2, 1);
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 3, 1);
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 4, 1);
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 5, 1);
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 6, 1);
    }
    else
    {
        TSingleton<CFishingTable>::GetInstance()->FUN_1403b30b0(reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&rIds), 7, 1);
    }
}

// @0x140f42ed0
int UIFishingBookDialog::FUN_140f42ed0()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_140931450("fisherChampion") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607bb8) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherChampion");
    if (FUN_140931450("fisherPro") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607bb7) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherPro");
    if (FUN_140931450("fisherMaster") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607aea) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherMaster");
    if (FUN_140931450("fisherExpert") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607ae9) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherExpert");
    if (FUN_140931450("fisherIntermediate") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607ae8) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherIntermediate");
    if (FUN_140931450("fisherBeginner") != 0 || reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsCompleted(0x1607ae7) != 0)
        return reinterpret_cast<CTitleTable*>(FUN_140933210())->FindTitleId("fisherBeginner");
    return 0;
}

// @0x140f432e0
CStringW UIFishingBookDialog::FUN_140f432e0(int nTitleId)
{
    return TSingleton<CFishingTable>::GetInstance()->FUN_1403b2240(nTitleId);
}

// @0x140f43330
int UIFishingBookDialog::FUN_140f43330(int nFishId)
{
    if (FUN_14025e7c0()->IsDebugMode() != 0)
        return 1;
    return TSingleton<CFishingManager>::GetInstance()->FUN_140cdc380(nFishId);
}

// @0x140f43380
int UIFishingBookDialog::FUN_140f43380(int nFishId)
{
    MS2Ptr<CFish> item = TSingleton<CFishingManager>::GetInstance()->FindFish(nFishId);
    if ((item.get() ? true : false) && item->m_bNew != 0)
        return 1;
    MS2Ptr<CFish> parent = TSingleton<CFishingManager>::GetInstance()->FindFish(FUN_140f434b0(nFishId));
    if ((parent.get() ? true : false) && parent->m_bNew != 0)
        return 1;
    return 0;
}

// @0x140f434b0
int UIFishingBookDialog::FUN_140f434b0(int nFishId)
{
    MS2Ptr<CFishData> fish = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
    if (fish.IsNull() != 0)
        return 0;
    return fish->m_nCompanion;
}

// @0x140f43540
int UIFishingBookDialog::FUN_140f43540(int nFishId)
{
    MS2Ptr<CFishData> fish = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
    if (fish.IsNull() != 0)
        return 0;
    int nA = TSingleton<CFishingManager>::GetInstance()->FUN_140cdc280(nFishId);
    CFishData* pRec = fish.operator->();
    int nB = TSingleton<CFishingManager>::GetInstance()->FUN_140cdc280(pRec->m_nCompanion);
    return (std::max)(nA, nB);
}

// @0x140f43610
int UIFishingBookDialog::FUN_140f43610(int nFishId)
{
    int nTotal = 0;
    {
        MS2Ptr<CFish> item = TSingleton<CFishingManager>::GetInstance()->FindFish(nFishId);
        if (item.get() != 0)
            nTotal += item->m_n1c;
    }
    {
        MS2Ptr<CFish> parent = TSingleton<CFishingManager>::GetInstance()->FindFish(FUN_140f434b0(nFishId));
        if (parent.get() != 0)
            nTotal += parent->m_n1c;
    }
    return nTotal;
}

// @0x140f436f0
int UIFishingBookDialog::FUN_140f436f0(int nFishId)
{
    int nTotal = 0;
    {
        MS2Ptr<CFish> item = TSingleton<CFishingManager>::GetInstance()->FindFish(nFishId);
        if (item.get() != 0)
            nTotal += item->m_n20;
    }
    {
        MS2Ptr<CFish> parent = TSingleton<CFishingManager>::GetInstance()->FindFish(FUN_140f434b0(nFishId));
        if (parent.get() != 0)
            nTotal += parent->m_n20;
    }
    return nTotal;
}

// @0x140f437d0
int UIFishingBookDialog::FUN_140f437d0(int nFishId)
{
    unsigned nBest = 0;
    unsigned nParentBest = 0;
    {
        MS2Ptr<CFish> item = TSingleton<CFishingManager>::GetInstance()->FindFish(nFishId);
        if (item.get() != 0)
            nBest = item->m_nSize;
    }
    {
        MS2Ptr<CFish> parent = TSingleton<CFishingManager>::GetInstance()->FindFish(FUN_140f434b0(nFishId));
        if (parent.get() != 0)
            nParentBest = parent->m_nSize;
    }
    return FUN_1402cf010(nBest, nParentBest);
}

// the exe calls the ucrt wcscmp through its import slot here
extern "C" int(__cdecl* __imp_wcscmp)(const wchar_t* psz1, const wchar_t* psz2);

// @0x140f438b0
int FUN_140f438b0(const int* pA, const int* pB)
{
    const int& nA = *pA;
    const int& nB = *pB;
    MS2Ptr<CFishData> fishA = TSingleton<CFishingTable>::GetInstance()->GetFish(nA);
    MS2Ptr<CFishData> fishB = TSingleton<CFishingTable>::GetInstance()->GetFish(nB);
    if (fishA.IsNull() != 0 || fishB.IsNull() != 0)
        return 1;
    if (fishA->m_nMastery == fishB->m_nMastery)
    {
        if (fishA->m_nRank == fishB->m_nRank)
        {
            CStringW strA = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x1d, nA);
            CStringW strB = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x1d, nB);
            return __imp_wcscmp(strA.GetBuffer(0), strB.GetBuffer(0));
        }
        else
            return fishA->m_nRank > fishB->m_nRank ? 1 : -1;
    }
    return fishA->m_nMastery > fishB->m_nMastery ? 1 : -1;
}

// @0x140f43b40
void ASObj::FUN_140f43b40(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x140f43be0 (std::max<int>)

// @0x140f43c10
Unk_FbItemArray::Unk_FbItemArray() : m_pData(0), m_nSize(0), m_nMaxSize(0), m_nGrowBy(0)
{
}

// @0x140f43c50
Unk_FbItemArray::~Unk_FbItemArray() throw()
{
    if (m_pData != 0)
    {
        FUN_140f43d70(m_pData, m_nSize);
        free(m_pData);
    }
}

// @0x140f43cb0
MS2Ptr<CFish>& Unk_FbItemArray::FUN_140f43cb0(unsigned __int64 nIndex)
{
    if (nIndex >= m_nSize)
        ATL::AtlThrowImpl(0x80070057);
    return m_pData[nIndex];
}

// @0x140f43cf0
MS2Ptr<CFish>* FUN_140f43cf0(MS2Ptr<CFish>* p, unsigned int nFlags)
{
    p->MS2Ptr<CFish>::~MS2Ptr();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x140f43d70
void FUN_140f43d70(MS2Ptr<CFish>* pItems, unsigned __int64 nCount)
{
    for (unsigned __int64 i = 0; i < nCount; i++)
        FUN_140f43cf0(&pItems[i], 0);
}

// @0x140f43dd0
unsigned __int64 Unk_FbItemArray::GetSize()
{
    return m_nSize;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9560-0x142ca96a0 .text$yd
