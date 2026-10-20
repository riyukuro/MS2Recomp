// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The pet window ("PetSystemDialog"); see uipetsystemdialog.h.
// One of the five TUs of the queue unit ?\uiotherpetsystemdialog.cpp (UIOtherPetSystemDialog, UIOxQuizDialog,
// UIPaybackDialog, UIPetExtractionScrollDialog, UIPetSystemDialog). The MS2Ptr / CAtlMap COMDATs that
// uiotherpetsystemdialog.cpp also uses (dtors, RemoveAll, FreeNode, ...) were kept by that earlier obj.
// MS2-UNIT: ?\uiotherpetsystemdialog.cpp
// MS2-RANGE: 0x140e733a0-0x140e75ea0 .text$mn
// MS2-RANGE: 0x1400d9d30-0x1400d9ef0 .text$di
// MS2-PIN: ?get@?$MS2Ptr@VPetSystemTabContents@@@@QEBAPEAVPetSystemTabContents@@XZ 0x140e75780
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipetsystemdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uipetsystemdialog.h"
#include "tabcontentspetinfo.h"
#include "tabcontentspetcompose.h"
#include "tabcontentspetcollect.h"
#include "tabcontentspetremakeoption.h"
#include "tabcontentspetevolution.h"
#include "inventory.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/commonfiles/featuremanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the unit's headers ----

static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strPremiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                          "EnumEnd"};

// ---- out-of-unit callees (names describe uses) ----

struct Unk_IsItemEvents;
Unk_IsItemEvents* FUN_140a6a840();                                          // the item event hub
void FUN_1419cae20(Unk_IsItemEvents* pHub, UIItemEventListener* pListener); // add a listener
void FUN_1419caeb0(Unk_IsItemEvents* pHub, UIItemEventListener* pListener); // remove it

class Unk_PsBanFlags { public: int FUN_1402c4c90(int nFlag); };            // blocked-action flag set
struct Unk_PsConfig { char m_0[8]; Unk_PsBanFlags m_8; };                   // global client config
Unk_PsConfig* FUN_14025e7b0();
CFeatureManager* FUN_140166410();                                           // the feature switches

CPetManager* FUN_140535320();
extern Unk_Inventory DAT_143ab2a90;                                         // the player's inventory

int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);
MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
void FUN_1412761e0(MS2Ptr<AScript> spMovie, int n);
CStringW FUN_14028de60(int nId);                                            // a common string by id

// The page factories (null when the dialog shows no pages or the feature is off).
static MS2Ptr<PetSystemTabContents> FUN_140e74b50(int nPages);
static MS2Ptr<PetSystemTabContents> FUN_140e74be0(int nPages);
static MS2Ptr<PetSystemTabContents> FUN_140e74d00(int nPages);
static MS2Ptr<PetSystemTabContents> FUN_140e74df0(int nPages);
static MS2Ptr<PetSystemTabContents> FUN_140e74ee0(int nPages);

// @0x140e733a0
UIPetSystemDialog::TabInfo::TabInfo(int nStrId, MS2Ptr<PetSystemTabContents> spPage, CString strName)
    : m_18(nStrId), m_20(strName), m_28(spPage)
{
}

// @0x140e73440
UIPetSystemDialog::UIPetSystemDialog()
    : m_180(0), m_188(0)
{
    m_164 = 1;
    FUN_141924170(1);
}

// @0x140e73540
CString UIPetSystemDialog::vfunc_1()
{
    return "PetSystemDialog";
}

// @0x140e73590
void UIPetSystemDialog::FUN_140e73590(int n)
{
    FUN_1412761e0(m_30, n);
}

// @0x140e735e0
// MS2-FUNCTIONAL: the five TabInfo temporaries keep different stack slots than the exe
int UIPetSystemDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    m_198.SetAt(0, MS2Ptr<TabInfo>(new TabInfo(0xccd, FUN_140e74b50(vfunc_84()), "petInfo")));
    m_198.SetAt(1, MS2Ptr<TabInfo>(new TabInfo(0xcce, FUN_140e74be0(vfunc_84()), "petCompose")));
    m_198.SetAt(2, MS2Ptr<TabInfo>(new TabInfo(0xccf, FUN_140e74ee0(vfunc_84()), "petEvolution")));
    m_198.SetAt(3, MS2Ptr<TabInfo>(new TabInfo(0xcd1, FUN_140e74df0(vfunc_84()), "petRemakeOption")));
    m_198.SetAt(4, MS2Ptr<TabInfo>(new TabInfo(0xcd0, FUN_140e74d00(vfunc_84()), "petCollect")));
    FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    return 0;
}

// @0x140e73c20
void UIPetSystemDialog::vfunc_67()
{
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140e74910();
    for (POSITION pos = m_198.GetStartPosition(); pos != NULL; m_198.GetNext(pos))
    {
        MS2Ptr<TabInfo> spTab = m_198.GetValueAt(pos);
        if (spTab == 0)
            continue;
        if (spTab->m_28 == 0)
            continue;
        spTab->m_28->vfunc_1();
    }
    m_180 = 0;
    m_198.RemoveAll();
    m_188 = 0;
    UIDialog::vfunc_67();
}

// @0x140e73db0
// MS2-FUNCTIONAL: the GetChild / CStringW temporaries keep different stack slots than the exe
void UIPetSystemDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    int nSel = FUN_140e74790();
    MS2Ptr<ASButtonBar> spBar = GetChild<ASButtonBar>("m_buttonBar");
    if (spBar)
    {
        for (POSITION pos = m_198.GetStartPosition(); pos != NULL; m_198.GetNext(pos))
        {
            MS2Ptr<TabInfo> spTab = m_198.GetValueAt(pos);
            if (spTab == 0)
                continue;
            CString& strFrame = spTab->m_20;
            if (spTab->m_28 == 0)
                continue;
            ASObj obj(2);
            obj.FUN_1407cbb20("label", FUN_14028de60(spTab->m_18));
            obj.FUN_1407cba60("frame", strFrame);
            spBar->FUN_1422e3460(obj);
        }
        spBar->vfunc_24(true);
        spBar->FUN_1422e31e0(nSel);
    }
    FUN_1419260d0("m_webGuideButton", 0);
}

// @0x140e74090
void UIPetSystemDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (m_188)
        m_188->vfunc_5(pRetVal, (void*)&strMethod, pArgs);
}

// @0x140e74120
// MS2-FUNCTIONAL: the ASData / argument temporaries are laid out differently
int UIPetSystemDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this) != 0)
        return 1;
    if (m_188)
    {
        if (m_188->vfunc_6(szMethod, pArgs, nArgs) != 0)
            return 1;
    }
    ASData data;
    if (_stricmp("OnRemoveTab", szMethod) == 0)
    {
        FUN_140e74910();
        return 1;
    }
    if (_stricmp("OnChangeTab", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        CString strName = data.FUN_1422b8d30();
        Scaleform::GFx::Value root = data.FUN_1422b9260();
        FUN_140e74970(strName, root);
        return 1;
    }
    return 0;
}

// @0x140e74360
void UIPetSystemDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (m_188)
        m_188->vfunc_7(p1, p2, p3, p4);
}

// @0x140e74420
int UIPetSystemDialog::vfunc_82()
{
    if (m_188 == 0)
        return -1;
    return m_188->vfunc_8();
}

// @0x140e74480
void UIPetSystemDialog::vfunc_79(void* p)
{
    if (m_188)
        m_188->vfunc_9(p);
}

// @0x140e744e0
void UIPetSystemDialog::vfunc_3(void* pItem, bool b)
{
    if (m_188)
        m_188->vfunc_10(pItem, b);
}

// @0x140e74550
// MS2-FUNCTIONAL: the GetChild / CStringW temporaries keep different stack slots than the exe
void UIPetSystemDialog::FUN_140e74550(int nGroup)
{
    MS2Ptr<ASButtonBar> spBar = GetChild<ASButtonBar>("m_buttonBar");
    if (spBar)
    {
        m_180 = nGroup;
        int nTab = FUN_140e74790();
        if (spBar->FUN_1422e3210() != nTab)
            spBar->FUN_1422e31e0(nTab);
    }
    else
    {
        m_180 = nGroup;
        FUN_141924680();
    }
}

// @0x140e74640
void UIPetSystemDialog::FUN_140e74640(int nEvent)
{
    if (vfunc_55() != 0)
        return;
    if (m_188)
        m_188->vfunc_2(nEvent);
}

// @0x140e746c0
MS2Ptr<PetSystemTabContents> UIPetSystemDialog::FUN_140e746c0()
{
    return m_188;
}

// @0x140e74710
int UIPetSystemDialog::vfunc_84()
{
    return 1;
}

// @0x140e74730
MS2Ptr<CItem> UIPetSystemDialog::vfunc_85()
{
    return DAT_143ab2a90.FUN_140a5d680(FUN_140535320()->FUN_140c8b2e0());
}

// @0x140e74790
// MS2-FUNCTIONAL: the loop temporaries keep different stack slots than the exe
int UIPetSystemDialog::FUN_140e74790()
{
    if (m_180 != 0)
    {
        int nIndex = 0;
        for (POSITION pos = m_198.GetStartPosition(); pos != NULL; m_198.GetNext(pos))
        {
            MS2Ptr<TabInfo> spTab = m_198.GetValueAt(pos);
            if (spTab == 0)
                continue;
            if (spTab->m_28 == 0)
                continue;
            if (spTab->m_20 == "petCollect")
            {
                static_cast<TabContentsPetCollect*>(spTab->m_28.get())->FUN_140cad8a0(m_180);
                return nIndex;
            }
            ++nIndex;
        }
    }
    return 0;
}

// @0x140e74910
void UIPetSystemDialog::FUN_140e74910()
{
    if (m_188)
        m_188->vfunc_4();
}

// @0x140e74970
void UIPetSystemDialog::FUN_140e74970(CString strName, const Scaleform::GFx::Value& root)
{
    MS2Ptr<TabInfo> spFound(0);
    for (POSITION pos = m_198.GetStartPosition(); pos != NULL; m_198.GetNext(pos))
    {
        MS2Ptr<TabInfo> spTab = m_198.GetValueAt(pos);
        if (spTab)
        {
            if (spTab->m_20 == strName)
            {
                m_188 = spTab->m_28;
                if (m_188)
                {
                    MS2Ptr<ASUIComponent> spUi = FUN_140acca70(m_28, root);
                    if (spUi.get() != 0)
                        m_188->vfunc_3(spUi);
                }
            }
        }
    }
}

// @0x140e74b50
static MS2Ptr<PetSystemTabContents> FUN_140e74b50(int nPages)
{
    return MS2Ptr<PetSystemTabContents>(new TabContentsPetInfo(nPages));
}

// @0x140e74be0
// MS2-FUNCTIONAL: the nested feature checks are laid out differently
static MS2Ptr<PetSystemTabContents> FUN_140e74be0(int nPages)
{
    if (nPages == 0)
        return MS2Ptr<PetSystemTabContents>(0);
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x37) == 0)
    {
        if (FUN_140166410()->FUN_14036d570(0x8d))
            return MS2Ptr<PetSystemTabContents>(new TabContentsPetCompose());   // ctor 0x140cb3db0 (tabcontentspetcompose.cpp)
        return MS2Ptr<PetSystemTabContents>(0);
    }
    return MS2Ptr<PetSystemTabContents>(0);
}

// @0x140e74d00
static MS2Ptr<PetSystemTabContents> FUN_140e74d00(int nPages)
{
    if (nPages == 0)
        return MS2Ptr<PetSystemTabContents>(0);
    if (FUN_140166410()->FUN_14036d570(0x8d))
        return MS2Ptr<PetSystemTabContents>(new TabContentsPetCollect());
    return MS2Ptr<PetSystemTabContents>(0);
}

// @0x140e74df0
static MS2Ptr<PetSystemTabContents> FUN_140e74df0(int nPages)
{
    if (nPages == 0)
        return MS2Ptr<PetSystemTabContents>(0);
    if (FUN_140166410()->FUN_14036d570(0x9a))
        return MS2Ptr<PetSystemTabContents>(new TabContentsPetRemakeOption());
    return MS2Ptr<PetSystemTabContents>(0);
}

// @0x140e74ee0
static MS2Ptr<PetSystemTabContents> FUN_140e74ee0(int nPages)
{
    if (nPages == 0)
        return MS2Ptr<PetSystemTabContents>(0);
    if (FUN_140166410()->FUN_14036d570(0xeb))
        return MS2Ptr<PetSystemTabContents>(new TabContentsPetEvolution());
    return MS2Ptr<PetSystemTabContents>(0);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca7450-0x142ca74d0 .text$yd
