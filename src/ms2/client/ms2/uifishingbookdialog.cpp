// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIFishingBookDialog: see uifishingbookdialog.h.
// MS2-UNIT: ?\uifishingbookdialog.cpp
// MS2-RANGE: 0x1400df250-0x1400df560 .text$di
// MS2-RANGE: 0x140f41250-0x140f43df0 .text$mn
// MS2-PIN: ??$max@H@std@@YAAEBHAEBH0@Z 0x140f43be0
// MS2-PIN: ??1UIFishingBookDialog@@UEAA@XZ 0x140f43c90
// MS2-PIN: ??_GUIFishingBookDialog@@UEAAPEAXI@Z 0x140f43d30
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
#include <algorithm>
#include <stdlib.h>

// The header statics of the including TU come from header_statics_a.h; then the book's own "open" sound, and the second
// copy of the header statics the link order puts behind it.
static CString s_strBookOpen("System_Fishing_BookOpen");
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects ----

void FUN_140159b70(long hr);                                    // AtlThrowImpl
void FUN_141276180(const CString& strName, const CString& strArg);       // play a system sound
WorldService* FUN_1403ed2d0();
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
CStringW FUN_141b720b0(int nId, __int64 nValue);
CStringW FUN_1401d0160(const wchar_t* szFirst, const CStringW& strSecond);   // szFirst + strSecond
CStringW FUN_1401ceea0(const wchar_t* szFmt, int n);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1409e9bc0(int nId, const int& a, const int& b);
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);
CStringTable* FUN_1401a9d70();
bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
void FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member

// The record of a fish (the fish table's row).
class Unk_FbFishRec
{
public:
    CStringW FUN_1403b1600();                                   // icon path
    CStringW FUN_1403b1650();                                   // fish name
    CStringW FUN_1403b16b0(int nKnown);                         // description

    void* m_00; void* m_08; void* m_10;
    int m_18;                                                   // +0x18 fish id
    unsigned m_1c;                                              // +0x1c mastery area
    int m_20;                                                   // +0x20 tab (0 / 1 / 2..6 / 7)
    int m_24;                                                   // +0x24 grade
    __int64 m_28; __int64 m_30; __int64 m_38; __int64 m_40;
    int m_48;                                                   // +0x48 0 = a single spot
    int m_4c;
    int m_50;                                                   // +0x50 the parent fish
};

// The record the player holds for a fish.
class Unk_FbItemRec
{
public:
    void* m_00; void* m_08; void* m_10;
    int m_18;                                                   // +0x18 fish id
    int m_1c;                                                   // +0x1c total catch count
    int m_20;                                                   // +0x20 big-size catch count
    int m_24;                                                   // +0x24 best record
    int m_28;
    int m_2c;                                                   // +0x2c new mark
};

void FUN_1403b3920(void*);
void FUN_1403b3510(void*, int);
void FUN_1403b3b50(void*, const void*);
void FUN_140cdf6d0(void*);
void FUN_140cdf250(void*, int);
void FUN_140cdf210(void*, const void*);
void FUN_140cdf810(void*, const void*);
void FUN_140acd710(void*);
void FUN_1409b4ac0(void*);

// A smart reference to a fish row (16 bytes; ctor / copy / dtor are exe functions).
struct Unk_FbFishRef
{
    void* m_0;
    Unk_FbFishRec* m_p;
    Unk_FbFishRef() : m_0(0), m_p(0) {}
    Unk_FbFishRef(int n) { FUN_1403b3510(this, n); }
    ~Unk_FbFishRef() { FUN_1403b3920(this); }
    Unk_FbFishRef& operator=(const Unk_FbFishRef& o) { FUN_1403b3b50(this, &o); return *this; }
    bool FUN_140cd8bd0();                                       // the row is missing
    Unk_FbFishRec* FUN_140cdf9b0();                             // the row, null if the id is unknown
    Unk_FbFishRec* FUN_1403b3c80();                             // the row
};

// A smart reference to the player's record of a fish.
struct Unk_FbItemRef
{
    void* m_0;
    Unk_FbItemRec* m_p;
    Unk_FbItemRef() : m_0(0), m_p(0) {}
    Unk_FbItemRef(int n) { FUN_140cdf250(this, n); }
    Unk_FbItemRef(const Unk_FbItemRef& o) { FUN_140cdf210(this, &o); }
    ~Unk_FbItemRef() { FUN_140cdf6d0(this); }
    Unk_FbItemRef& operator=(const Unk_FbItemRef& o) { FUN_140cdf810(this, &o); return *this; }
    Unk_FbItemRec* FUN_140cdf9a0();                             // the record, null if none
    Unk_FbItemRec* FUN_140cdf9d0();                             // the record
};

// The list control and the text field of the movie.
class Unk_FbCtl : public ASMovieClip
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
    virtual void vfunc_24(int n);
    void FUN_1422dcca0(int nIndex);                             // scroll to the entry
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& obj);                       // add an entry
};
struct Unk_FbListRef
{
    void* m_0;
    void* m_p;
    Unk_FbListRef() : m_0(0), m_p(0) {}
    ~Unk_FbListRef() { FUN_140acd710(this); }
    long FUN_140acd9d0();
    Unk_FbCtl* FUN_140acd9f0();
};
struct Unk_FbTextRef
{
    void* m_0;
    void* m_p;
    Unk_FbTextRef() : m_0(0), m_p(0) {}
    ~Unk_FbTextRef() { FUN_1409b4ac0(this); }
    long FUN_140b9a800();
    ASTextField* FUN_1409b4c70();
};

// The fish table, the item table and the mastery table, and the objects behind a few switches.
class Unk_FbItemArray;
class Unk_FbFishTable
{
public:
    Unk_FbFishRef FUN_1403b2d30(int nFishId);
    void FUN_1403b30b0(FbIdArray& rIds, int nTab, int bFlag);   // the ids of a tab
    CStringW FUN_1403b2240(int nId);
};
Unk_FbFishTable* FUN_1403b4740();
class Unk_FbMastery
{
public:
    int FUN_14066b050(int nKind);                               // max grade
    int FUN_14066b310(int nKind, int nGrade);                   // the exp where the grade starts
    int FUN_14066af60(int nKind, int nArea);
};
Unk_FbMastery* FUN_1409670c0();
class Unk_FbTitleMgr
{
public:
    int FUN_1409365a0(int nId);
};
Unk_FbTitleMgr* FUN_1406c7600();
class Unk_FbTitleSet
{
public:
    int FUN_14087a930(CString strName);
};
Unk_FbTitleSet* FUN_140933210();
int FUN_140931450(CString strName);
class Unk_FbDebugCfg { public: bool FUN_14116d720(); };
Unk_FbDebugCfg* FUN_14025e7c0();
const unsigned& FUN_1402cf010(const unsigned& a, const unsigned& b);

// The array of the player's fish records (an exe CAtlArray look-alike; ctor / dtor / GetAt / GetCount are in this unit).
class Unk_FbItemArray
{
public:
    Unk_FbItemArray();                                          // 0x140f43c10
    ~Unk_FbItemArray() throw();                                 // 0x140f43c50
    Unk_FbItemRef& FUN_140f43cb0(unsigned __int64 nIndex);      // GetAt
    unsigned __int64 FUN_140f43dd0();                           // GetCount
private:
    Unk_FbItemRef* m_pData;
    unsigned __int64 m_nSize;
    unsigned __int64 m_nMaxSize;
    int m_nGrowBy;
};
class Unk_FbItemTable
{
public:
    Unk_FbItemRef FUN_140cdba00(int nFishId);
    void FUN_140cdba90(Unk_FbItemArray& rOut);
    int FUN_140cdc380(int nFishId);
    int FUN_140cdc280(int nFishId);
};
Unk_FbItemTable* FUN_140953f20();

// The AS invokes of the movie root the exe has one instance of per argument list.
class Unk_FbAS
{
public:
    Scaleform::GFx::Value FUN_140c19160(const char* szMethod, unsigned __int64 nIndex, int nValue);   // Invoke(name, index, value)
};

void FUN_140f43d70(Unk_FbItemRef* pItems, unsigned __int64 nCount);
Unk_FbItemRef* FUN_140f43cf0(Unk_FbItemRef* p, unsigned int nFlags);
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
CString UIFishingBookDialog::vfunc_1()
{
    return "FishingBookDialog";
}

// @0x140f41330
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nPage = 0;
    m_nTab = 0;
    FUN_140f42790(m_nTab);
    FUN_140f41a10();
    Unk_FbListRef spBag = FUN_140ba4b70("m_bag");
    if (spBag.FUN_140acd9d0() != 0)
        spBag.FUN_140acd9f0()->FUN_1422dcca0(0);
    FUN_141276180(s_strBookOpen, "");
}

// @0x140f41440
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onChangeFish") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140f42100(data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onTabChange") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nTab = data.FUN_1422b8a10();
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
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
    {
        CStringW strText;
        int nExp = pPC->FUN_141662750(1);
        int nGrade = pPC->FUN_1416627d0(1);
        if (nGrade == FUN_1409670c0()->FUN_14066b050(1))
        {
            strText = FUN_14028b8e0(CStringW(L"s_fishing_mastery_tooltip_level_max"));
        }
        else
        {
            int nBase = FUN_1409670c0()->FUN_14066b310(1, nGrade);
            int nNextGrade = nGrade + 1;
            int nNextBase = FUN_1409670c0()->FUN_14066b310(1, nNextGrade);
            int nMax = nNextBase - nBase;
            int nCur = nExp - nBase;
            strText = FUN_1409e9bc0(0xbeb, nCur, nMax);
        }
        ASTooltip tooltip(1, 2);
        tooltip.FUN_1409c6d70("export_common_tooltip_tooltipText");
        tooltip.FUN_1409c6e00(300);
        tooltip.FUN_1409c6e30(60000);
        tooltip.FUN_1409c6dc0(1);
        tooltip.FUN_1409c6cb0(strText);
        FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
    }
}

// @0x140f41940
void UIFishingBookDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    Unk_FbItemArray items;
    FUN_140953f20()->FUN_140cdba90(items);
    for (unsigned __int64 i = 0; i < items.FUN_140f43dd0(); i++)
        items.FUN_140f43cb0(i).FUN_140cdf9d0()->m_2c = 0;
}

// @0x140f419e0
void UIFishingBookDialog::FUN_140f419e0()
{
    FUN_140f42790(m_nTab);
}

// @0x140f41a10
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::FUN_140f41a10()
{
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
    {
        int nExp = pPC->FUN_141662750(1);
        int nGrade = pPC->FUN_1416627d0(1);
        int nBase = FUN_1409670c0()->FUN_14066b310(1, nGrade);
        int nNextBase = FUN_1409670c0()->FUN_14066b310(1, nGrade + 1);
        int nTitle = FUN_140f42ed0();
        CStringW strTitle = (nTitle != 0) ? FUN_141b720b0(nTitle, 0) : FUN_14028b8e0(CStringW(L"s_fishing_none_title"));
        CStringW strGrade = FUN_140f432e0(nGrade);
        if (nGrade == FUN_1409670c0()->FUN_14066b050(1))
            strGrade += FUN_1401d0160(L" ", FUN_14028b8e0(CStringW(L"s_fishing_mastery_gauge_level_max")));
        ASObj obj(2);
        obj.FUN_1409c0d20("fisherTitleID", nTitle);
        obj.FUN_1407cbb20("fisherTitle", CStringW(strTitle));
        obj.FUN_1407cbb20("fisherGradeName", CStringW(strGrade));
        obj.FUN_1409c0d20("curMastery", nExp - nBase);
        obj.FUN_1409c0d20("maxMastery", nNextBase - nBase);
        if (m_30.get() != 0)
            m_30->FUN_140acd1f0("setFisher", AScript(obj));
    }
}

// @0x140f41e90
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::FUN_140f41e90()
{
    if (m_30.get() != 0)
    {
        Unk_FbItemArray items;
        FUN_140953f20()->FUN_140cdba90(items);
        int aNew[4] = {0};
        for (unsigned __int64 i = 0; i < items.FUN_140f43dd0(); i++)
        {
            Unk_FbItemRef item = items.FUN_140f43cb0(i);
            if (item.FUN_140cdf9d0()->m_2c == 0)
                continue;
            Unk_FbItemRec* pRec = item.FUN_140cdf9d0();
            Unk_FbFishRef fish = FUN_1403b4740()->FUN_1403b2d30(pRec->m_18);
            if (fish.FUN_140cd8bd0() != 0)
                continue;
            int nTab = fish.FUN_1403b3c80()->m_20;
            if (nTab == 0)
                aNew[0] = 1;
            else if (nTab == 1)
                aNew[1] = 1;
            else if (nTab == 7)
                aNew[3] = 1;
            else
                aNew[2] = 1;
        }
        for (unsigned __int64 j = 0; j < 4; j++)
            reinterpret_cast<Unk_FbAS*>(m_30.operator->())->FUN_140c19160("setTabNew", j, aNew[j]);
    }
}

// @0x140f42100
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::FUN_140f42100(int nFishId)
{
    if (!FUN_140a467d0(&m_30))
    {
        ASObj obj(2);
        Unk_FbFishRef fish = FUN_1403b4740()->FUN_1403b2d30(nFishId);
        if (fish.FUN_140cdf9b0() == 0)
        {
            obj.FUN_1407cb9c0("acquire", 0);
            obj.FUN_1407cb9c0("medal", 0);
        }
        else
        {
            Unk_FbItemRef item = FUN_140953f20()->FUN_140cdba00(nFishId);
            Unk_FbFishRec* pRec = fish.FUN_1403b3c80();
            int nArea = FUN_1409670c0()->FUN_14066af60(1, pRec->m_1c);
            obj.FUN_1407cbb20("iconPath", fish.FUN_1403b3c80()->FUN_1403b1600());
            obj.FUN_1407cbb20("fishName", fish.FUN_1403b3c80()->FUN_1403b1650());
            bool bSingle = fish.FUN_1403b3c80()->m_48 == 0;
            obj.FUN_1407cbb20("fishingExp", bSingle ? FUN_140f432e0(nArea) : FUN_14028b8e0(CStringW(L"s_fishing_all_spot")));
            obj.FUN_1409adc90("fishRank", fish.FUN_1403b3c80()->m_24);
            obj.FUN_1407cbb20("fishGradeName", FUN_14052bd00(0xbda, FUN_1401a9d70()->FUN_141813150(fish.FUN_1403b3c80()->m_24)));
            int nKnown = FUN_140f43330(fish.FUN_1403b3c80()->m_18);
            obj.FUN_1407cbb20("desc", fish.FUN_1403b3c80()->FUN_1403b16b0(nKnown));
            obj.FUN_1407cb9c0("acquire", FUN_140f43330(fish.FUN_1403b3c80()->m_18));
            obj.FUN_140f43b40("medal", FUN_140f43540(nFishId));
            if (FUN_140f43330(fish.FUN_1403b3c80()->m_18) != 0)
            {
                unsigned nTotal = FUN_140f43610(nFishId);
                obj.FUN_1407cbb20("totalCatchCount", FUN_1409e97f0(0xbdb, nTotal));
                unsigned nBig = FUN_140f436f0(nFishId);
                obj.FUN_1407cbb20("bigSizeCatchCount", FUN_1409e97f0(0xbdb, nBig));
                unsigned nBest = FUN_140f437d0(nFishId);
                obj.FUN_1407cbb20("bestRecord", FUN_1409e97f0(0xbdc, nBest));
            }
        }
        m_30->FUN_140acd1f0("setFish", AScript(obj));
    }
}

// @0x140f42790
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
void UIFishingBookDialog::FUN_140f42790(int nTab)
{
    FbIdArray ids;
    FUN_140f42d90(ids);
    size_t nCount = ids.GetCount();
    qsort(ids.GetData(), nCount, 4, (int (*)(const void*, const void*))FUN_140f438b0);
    Unk_FbListRef spBag = FUN_140ba4b70("m_bag");
    if (spBag.FUN_140acd9d0() != 0)
    {
        spBag.FUN_140acd9f0()->FUN_1422dd1d0();
        for (unsigned __int64 i = 0; i < 0x14; i++)
        {
            ASObj obj(2);
            Unk_FbItemRef item(0);
            Unk_FbFishRef fish(0);
            int nIndex = m_nPage * 0x14 + (int)i;
            if (-1 < nIndex)
            {
                if (nIndex < (int)ids.GetCount())
                {
                    int* pId = &ids[nIndex];
                    fish = FUN_1403b4740()->FUN_1403b2d30(*pId);
                    item = FUN_140953f20()->FUN_140cdba00(fish.FUN_1403b3c80()->m_18);
                }
            }
            if (fish.FUN_140cdf9b0() != 0)
            {
                obj.FUN_1409c0d20("id", fish.FUN_1403b3c80()->m_18);
                obj.FUN_1407cbb20("iconPath", fish.FUN_1403b3c80()->FUN_1403b1600());
                obj.FUN_1407cb9c0("acquire", FUN_140f43330(fish.FUN_1403b3c80()->m_18));
                obj.FUN_1409adc90("grade", fish.FUN_1403b3c80()->m_24);
                obj.FUN_140f43b40("medal", FUN_140f43540(fish.FUN_1403b3c80()->m_18));
                obj.FUN_1407cb9c0("isNew", FUN_140f43380(fish.FUN_1403b3c80()->m_18));
            }
            spBag.FUN_140acd9f0()->FUN_1422dd230(obj);
        }
        spBag.FUN_140acd9f0()->vfunc_24(1);
    }
    Unk_FbTextRef spPage = FUN_140bb4cf0("m_page");
    if (spPage.FUN_140b9a800() != 0)
    {
        int nCur = m_nPage + 1;
        spPage.FUN_1409b4c70()->FUN_1422c4cd0(FUN_1401ceea0(L"{0}", nCur));
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
        FUN_1403b4740()->FUN_1403b30b0(rIds, 0, 1);
    }
    else if (m_nTab == 1)
    {
        FUN_1403b4740()->FUN_1403b30b0(rIds, 1, 1);
    }
    else if (m_nTab == 2)
    {
        FUN_1403b4740()->FUN_1403b30b0(rIds, 2, 1);
        FUN_1403b4740()->FUN_1403b30b0(rIds, 3, 1);
        FUN_1403b4740()->FUN_1403b30b0(rIds, 4, 1);
        FUN_1403b4740()->FUN_1403b30b0(rIds, 5, 1);
        FUN_1403b4740()->FUN_1403b30b0(rIds, 6, 1);
    }
    else
    {
        FUN_1403b4740()->FUN_1403b30b0(rIds, 7, 1);
    }
}

// @0x140f42ed0
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::FUN_140f42ed0()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (FUN_140931450("fisherChampion") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607bb8) != 0)
        return FUN_140933210()->FUN_14087a930("fisherChampion");
    if (FUN_140931450("fisherPro") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607bb7) != 0)
        return FUN_140933210()->FUN_14087a930("fisherPro");
    if (FUN_140931450("fisherMaster") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607aea) != 0)
        return FUN_140933210()->FUN_14087a930("fisherMaster");
    if (FUN_140931450("fisherExpert") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607ae9) != 0)
        return FUN_140933210()->FUN_14087a930("fisherExpert");
    if (FUN_140931450("fisherIntermediate") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607ae8) != 0)
        return FUN_140933210()->FUN_14087a930("fisherIntermediate");
    if (FUN_140931450("fisherBeginner") != 0 || FUN_1406c7600()->FUN_1409365a0(0x1607ae7) != 0)
        return FUN_140933210()->FUN_14087a930("fisherBeginner");
    return 0;
}

// @0x140f432e0
CStringW UIFishingBookDialog::FUN_140f432e0(int nTitleId)
{
    return FUN_1403b4740()->FUN_1403b2240(nTitleId);
}

// @0x140f43330
int UIFishingBookDialog::FUN_140f43330(int nFishId)
{
    if (FUN_14025e7c0()->FUN_14116d720() != 0)
        return 1;
    return FUN_140953f20()->FUN_140cdc380(nFishId);
}

// @0x140f43380
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::FUN_140f43380(int nFishId)
{
    Unk_FbItemRef item = FUN_140953f20()->FUN_140cdba00(nFishId);
    if (item.FUN_140cdf9a0() == 0 || item.FUN_140cdf9d0()->m_2c == 0)
    {
        int nParent = FUN_140f434b0(nFishId);
        Unk_FbItemRef parent = FUN_140953f20()->FUN_140cdba00(nParent);
        if (parent.FUN_140cdf9a0() == 0 || parent.FUN_140cdf9d0()->m_2c == 0)
            return 0;
        return 1;
    }
    return 1;
}

// @0x140f434b0
int UIFishingBookDialog::FUN_140f434b0(int nFishId)
{
    Unk_FbFishRef fish = FUN_1403b4740()->FUN_1403b2d30(nFishId);
    if (fish.FUN_140cd8bd0() != 0)
        return 0;
    return fish.FUN_1403b3c80()->m_50;
}

// @0x140f43540
int UIFishingBookDialog::FUN_140f43540(int nFishId)
{
    Unk_FbFishRef fish = FUN_1403b4740()->FUN_1403b2d30(nFishId);
    if (fish.FUN_140cd8bd0() != 0)
        return 0;
    int nA = FUN_140953f20()->FUN_140cdc280(nFishId);
    Unk_FbFishRec* pRec = fish.FUN_1403b3c80();
    int nB = FUN_140953f20()->FUN_140cdc280(pRec->m_50);
    return (std::max)(nA, nB);
}

// @0x140f43610
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::FUN_140f43610(int nFishId)
{
    int nTotal = 0;
    {
        Unk_FbItemRef item = FUN_140953f20()->FUN_140cdba00(nFishId);
        if (item.FUN_140cdf9a0() != 0)
            nTotal += item.FUN_140cdf9d0()->m_1c;
    }
    int nParent = FUN_140f434b0(nFishId);
    {
        Unk_FbItemRef parent = FUN_140953f20()->FUN_140cdba00(nParent);
        if (parent.FUN_140cdf9a0() != 0)
            nTotal += parent.FUN_140cdf9d0()->m_1c;
    }
    return nTotal;
}

// @0x140f436f0
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::FUN_140f436f0(int nFishId)
{
    int nTotal = 0;
    {
        Unk_FbItemRef item = FUN_140953f20()->FUN_140cdba00(nFishId);
        if (item.FUN_140cdf9a0() != 0)
            nTotal += item.FUN_140cdf9d0()->m_20;
    }
    int nParent = FUN_140f434b0(nFishId);
    {
        Unk_FbItemRef parent = FUN_140953f20()->FUN_140cdba00(nParent);
        if (parent.FUN_140cdf9a0() != 0)
            nTotal += parent.FUN_140cdf9d0()->m_20;
    }
    return nTotal;
}

// @0x140f437d0
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int UIFishingBookDialog::FUN_140f437d0(int nFishId)
{
    unsigned nBest = 0;
    unsigned nParentBest = 0;
    {
        Unk_FbItemRef item = FUN_140953f20()->FUN_140cdba00(nFishId);
        if (item.FUN_140cdf9a0() != 0)
            nBest = item.FUN_140cdf9d0()->m_24;
    }
    int nParent = FUN_140f434b0(nFishId);
    {
        Unk_FbItemRef parent = FUN_140953f20()->FUN_140cdba00(nParent);
        if (parent.FUN_140cdf9a0() != 0)
            nParentBest = parent.FUN_140cdf9d0()->m_24;
    }
    return FUN_1402cf010(nBest, nParentBest);
}

// @0x140f438b0
// MS2-FUNCTIONAL: exe materialises bool temps / return slots in a branch layout the source form for which is not found
int FUN_140f438b0(const int* pA, const int* pB)
{
    Unk_FbFishRef fishA = FUN_1403b4740()->FUN_1403b2d30(*pA);
    Unk_FbFishRef fishB = FUN_1403b4740()->FUN_1403b2d30(*pB);
    if (fishA.FUN_140cd8bd0() != 0 || fishB.FUN_140cd8bd0() != 0)
        return 1;
    if (fishA.FUN_1403b3c80()->m_1c != fishB.FUN_1403b3c80()->m_1c)
    {
        if (fishB.FUN_1403b3c80()->m_1c < fishA.FUN_1403b3c80()->m_1c)
            return 1;
        return -1;
    }
    if (fishA.FUN_1403b3c80()->m_24 == fishB.FUN_1403b3c80()->m_24)
    {
        CStringW strA = FUN_1401a9d70()->FUN_141811980(0x1d, *pA);
        CStringW strB = FUN_1401a9d70()->FUN_141811980(0x1d, *pB);
        return wcscmp(strA.GetBuffer(0), strB.GetBuffer(0));
    }
    if (fishB.FUN_1403b3c80()->m_24 < fishA.FUN_1403b3c80()->m_24)
        return 1;
    return -1;
}

// @0x140f43b40
void ASObj::FUN_140f43b40(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
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
Unk_FbItemRef& Unk_FbItemArray::FUN_140f43cb0(unsigned __int64 nIndex)
{
    if (nIndex >= m_nSize)
        FUN_140159b70(0x80070057);
    return m_pData[nIndex];
}

// @0x140f43cf0
Unk_FbItemRef* FUN_140f43cf0(Unk_FbItemRef* p, unsigned int nFlags)
{
    FUN_140cdf6d0(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x140f43d70
void FUN_140f43d70(Unk_FbItemRef* pItems, unsigned __int64 nCount)
{
    for (unsigned __int64 i = 0; i < nCount; i++)
        FUN_140f43cf0(&pItems[i], 0);
}

// @0x140f43dd0
unsigned __int64 Unk_FbItemArray::FUN_140f43dd0()
{
    return m_nSize;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9560-0x142ca96a0 .text$yd
