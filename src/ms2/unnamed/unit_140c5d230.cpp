// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Lapenshard system window (UILapenshardSystemDialog and its
// "equip" / "upgrade" pages and sections) and the Lapenshard shield bar HUD; see unit_140c5d230.h. Sibling of the pet system
// dialog's pages (client\ms2\tabcontentspetcompose.cpp). Names of the classes are the RTTI names; the member names are invented.
// MS2-UNIT: unit_140c5d230
// MS2-RANGE: 0x140c5d230-0x140c6b300 .text$mn
// MS2-RANGE: 0x1400ce050-0x1400ce500 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "unit_140c5d230.h"

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the headers this unit includes (three translation units folded into one: the .di of each constructs them
// in this order; the third and fourth sets also carry a CMyPCKeyInputController) ----

void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142ca31f0();
void FUN_142ca3220();
void FUN_142ca3240();
void FUN_142ca3260();
void FUN_142ca3280();
void FUN_142ca32b0();
void FUN_142ca32d0();
void FUN_142ca32f0();
void FUN_142ca3310();
void FUN_142ca3330();
void FUN_142ca3360();
void FUN_142ca3380();
void FUN_142ca33a0();
void FUN_142ca33c0();
struct Unk_RegMarker {};

namespace Unk_LsHeaderA
{
// @0x1400ce050
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce110
static CString s_strSkill = "skill";
// @0x1400ce140
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce170
static char s_marker[0x48];
static Unk_RegMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca3260), Unk_RegMarker());
#endif
}

namespace Unk_LsHeaderB
{
// @0x1400ce1c0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce280
static CString s_strSkill = "skill";
// @0x1400ce2b0
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce2e0
static char s_marker[0x48];
static Unk_RegMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca32f0), Unk_RegMarker());
#endif
// @0x1400ce330
static UICommon::CMyPCKeyInputController s_keyInput;
}

namespace Unk_LsHeaderC
{
// @0x1400ce360
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400ce420
static CString s_strSkill = "skill";
// @0x1400ce450
static CString s_strStun = "stun";
#ifndef MS2_HOOK_DLL
// @0x1400ce480
static char s_marker[0x48];
static Unk_RegMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca33a0), Unk_RegMarker());
#endif
// @0x1400ce4d0
static UICommon::CMyPCKeyInputController s_keyInput;
}

// ---- unit-local views of the exe objects and unrecovered callees ----------------------------------------------------

class Unk_LsWorld { public: MyPC* FUN_141bd0cc0(); };                   // the local player
Unk_LsWorld* FUN_1403ed2d0();

// The item bag control inside a section clip (as Unk_PetItemBag in tabcontentspetcompose.cpp).
class Unk_LsBag : public ASMovieClip
{
public:
    Unk_LsBag(const Scaleform::GFx::Value& v, int nMovieId);            // 0x1422cf330
    void FUN_1422dcca0(unsigned nIndex);                                // select a slot (-1: none)
    void FUN_1422dd1d0();                                               // refresh the registered bag
#define LS_V(n) virtual void vfunc_##n();
    LS_V(16) LS_V(17) LS_V(18) LS_V(19) LS_V(20) LS_V(21) LS_V(22) LS_V(23)
#undef LS_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_LsBag, 0x88);

typedef MS2Ptr<CItem> ItemPtr;
typedef ATL::CAtlArray<ItemPtr> ItemArray;

// The item bag registry (a name -> item list map of the inventory dialogs).
void FUN_140a704a0(CString* pstrBag);                                   // unbind the bag name
void FUN_140a702f0(CString* pstrBag, ItemArray* pItems, int nFlag);     // bind the bag name to the items
// The inventory: the bag lookup used by FUN_140c60920 below.
void FUN_140c60920(ItemArray* pOut, int bAll, int bEquip, int bMerge, int bSkill, int nKind, __int64 nOwner);   // 0x140c60920

// @0x140c610a0
static void BindBag(CString* pstrBag, ItemArray* pItems, int nFlag)
{
    FUN_140a704a0(pstrBag);
    FUN_140a702f0(pstrBag, pItems, nFlag);
}

// ---- LapenshardSystemTabPanelBase / LapenshardSystemTabContents (the shared defaults) ----

// @0x140c5e4d0
LapenshardSystemTabPanelBase::LapenshardSystemTabPanelBase()
{
}

// @0x140c5e620
LapenshardSystemTabPanelBase::~LapenshardSystemTabPanelBase()
{
}

// @0x140c5e4a0
LapenshardSystemTabContents::LapenshardSystemTabContents()
{
}

// @0x140c5e5f0
LapenshardSystemTabContents::~LapenshardSystemTabContents()
{
}

// @0x140c5ec40
void LapenshardSystemTabPanelBase::vfunc_1()
{
}

// @0x140c5eca0
void LapenshardSystemTabPanelBase::vfunc_2()
{
}

// @0x140c5e900
void LapenshardSystemTabPanelBase::vfunc_3()
{
}

// @0x140c5e8f0
void LapenshardSystemTabPanelBase::vfunc_4()
{
}

// @0x140c5ed60
void LapenshardSystemTabPanelBase::vfunc_5(int nEvent)
{
    (void)nEvent;
}

// @0x140c5ed00
void LapenshardSystemTabPanelBase::vfunc_6(MS2Ptr<CItem> spA, MS2Ptr<CItem> spB)
{
    (void)spA;
    (void)spB;
}

// @0x140c5ec20
void LapenshardSystemTabPanelBase::vfunc_7()
{
}

// @0x140c5ec70
int LapenshardSystemTabPanelBase::vfunc_8(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    (void)szMethod;
    (void)pArgs;
    (void)nArgs;
    return 0;
}

// @0x140c5ec30
void LapenshardSystemTabContents::vfunc_1()
{
}

// @0x140c5ed50
void LapenshardSystemTabContents::vfunc_2(int nEvent)
{
    (void)nEvent;
}

// @0x140c5ec90
void LapenshardSystemTabContents::vfunc_4()
{
}

// @0x140c5ed30
void LapenshardSystemTabContents::vfunc_5(void* a1, void* a2, void* a3)
{
    (void)a1;
    (void)a2;
    (void)a3;
}

// @0x140c5ec50
int LapenshardSystemTabContents::vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    (void)szMethod;
    (void)pArgs;
    (void)nArgs;
    return 0;
}

// @0x140c5ecb0
void LapenshardSystemTabContents::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    (void)a1;
    (void)a3;
    (void)a4;
}

// @0x140c5ece0
void LapenshardSystemTabContents::vfunc_9(CInPacket& packet)
{
    (void)packet;
}

// @0x140c5ecf0
void LapenshardSystemTabContents::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}

// @0x140c608f0
void LapenshardSystemTabContents::vfunc_11()
{
    FUN_1403ed2d0()->FUN_141bd0cc0();
}

// ---- LapenshardItemSlotBagPanel ----

// @0x140c5d230
LapenshardItemSlotBagPanel::LapenshardItemSlotBagPanel(UILapenshardEquipTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c5e5c0
LapenshardItemSlotBagPanel::~LapenshardItemSlotBagPanel()
{
}

// @0x140c5d290
void LapenshardItemSlotBagPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c5d2c0
void LapenshardItemSlotBagPanel::vfunc_2()
{
    vfunc_4();
}

// @0x140c5d2f0
void LapenshardItemSlotBagPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    m_strBag = "LapenshardItemSlotBag";
    MS2Ptr<Unk_LsBag> bag = m_ui->FUN_140accef0<Unk_LsBag>("m_itemBag");
    if (bag.get() != 0)
    {
        bag->Invoke("resetRenderer");
        bag->FUN_1422dcca0(0xffffffff);
        ItemArray items;
        FUN_140c60920(&items, 1, 1, 0, 0, 0, 0);
        BindBag(&m_strBag, &items, 1);
        bag->FUN_1422dd1d0();
        bag->FUN_1407cba60("bagId", m_strBag);
        bag->vfunc_24(1);
    }
}

// @0x140c5d530
void LapenshardItemSlotBagPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(&m_strBag);
        m_strBag.Empty();
    }
}

// @0x140c5d580
void LapenshardItemSlotBagPanel::vfunc_5(int nEvent)
{
    if (-1 < nEvent && nEvent < 3)
        vfunc_3();
}

// ---- LapenshardEquipSlotPanel ----

// @0x140c5d5c0
LapenshardEquipSlotPanel::LapenshardEquipSlotPanel(UILapenshardEquipTab* pTab)
    : m_pTab(pTab)
{
}

// @0x140c5e590
LapenshardEquipSlotPanel::~LapenshardEquipSlotPanel()
{
}

// @0x140c5d620
void LapenshardEquipSlotPanel::vfunc_1()
{
    vfunc_4();
}

// @0x140c5d650
void LapenshardEquipSlotPanel::vfunc_2()
{
    vfunc_4();
}

// ---- unit-local views, second part ----

// The bag registry entry of a name (FUN_140c610e0): per-slot ids.
class Unk_LsBagReg
{
public:
#define LS_R(n) virtual void vfunc_##n();
    LS_R(0) LS_R(1) LS_R(2) LS_R(3) LS_R(4) LS_R(5) LS_R(6) LS_R(7) LS_R(8) LS_R(9) LS_R(10) LS_R(11) LS_R(12) LS_R(13) LS_R(14)
#undef LS_R
    virtual CString vfunc_15(unsigned nIndex);                          // 15 (+0x78) the bag id of slot nIndex
};
Unk_LsBagReg* FUN_140a703d0(CString* pstrBag);                          // the bag of a name
class Unk_LsTable { public: int FUN_1405b5810(unsigned nSlot); };        // lapenshard slot -> equip kind
Unk_LsTable* FUN_1409c4b30();
struct Unk_LsSlotArg { unsigned m_n; Unk_LsSlotArg() : m_n(0) {} };      // 0x140c5e480
void FUN_1405b5e40(Unk_LsSlotArg* pArg, COutPacket* pPacket);            // write it
Unk_LsBagReg* FUN_140a70b70(void* pEntry);                              // the bag component (class id 0x6200084) of a registry entry
void* FUN_1422c8e90(CString* pstrBag);                                   // the registry entry of a bag name
UILapenshardSystemDialog* FUN_140a6ff40(int nId);                      // the open Lapenshard window
CFeatureManager* FUN_140166410();
int FUN_140c62520();                                                    // the window may be used (not in battle / disabled field)

// @0x140c610e0
static Unk_LsBagReg* BindBagReg(CString* pstrBag)
{
    FUN_140a704a0(pstrBag);
    return FUN_140a703d0(pstrBag);
}

// ---- LapenshardEquipSlotPanel ----

// @0x140c5d680
void LapenshardEquipSlotPanel::vfunc_3()
{
    if (m_pTab == 0)
        return;
    vfunc_4();
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_strBag = "LapenshardEquipSlotBag";
    Unk_LsBagReg* pReg = BindBagReg(&m_strBag);
    if (pReg == 0)
        return;
    for (unsigned i = 1; i < 7; ++i)
    {
        CString strName;
        strName.Format("m_equipSlot%d", i);
        MS2Ptr<ASMovieClip> slot = m_ui->FUN_1409b4560(strName);
        if (slot.get() != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cba60("bindID", pReg->vfunc_15(i - 1));
            obj.FUN_1409c0d20("slotIndex", i);
            obj.FUN_1407cb9c0("isEquip", pPlayer->FUN_14152f770((Unk_MyPCLapenSlot)i) != 0);
            slot->FUN_140acd1f0("setData", AScript(obj));
        }
    }
}

// @0x140c5d900
void LapenshardEquipSlotPanel::vfunc_4()
{
    if (!m_strBag.IsEmpty())
    {
        FUN_140a704a0(&m_strBag);
        m_strBag.Empty();
    }
}

// @0x140c5d950
void LapenshardEquipSlotPanel::vfunc_5(int nEvent)
{
    if (-1 < nEvent)
    {
        if (nEvent < 3)
            vfunc_3();
        else if (nEvent == 10)
            FUN_140c5d9c0(1);
        else if (nEvent == 0xb)
            FUN_140c5d9c0(0);
    }
}

// @0x140c5d9c0
void LapenshardEquipSlotPanel::FUN_140c5d9c0(int bOn)
{
    Unk_LsBagReg* pReg = FUN_140a70b70(FUN_1422c8e90(&m_strBag));
    if (pReg == 0)
        return;
    int nKind = 0;
    UILapenshardSystemDialog* pDlg = FUN_140a6ff40(0x4f6d);
    if (pDlg != 0)
        nKind = pDlg->FUN_140c62500();
    if (nKind == 0)
        return;
    for (unsigned i = 1; i < 7; ++i)
    {
        if (nKind == FUN_1409c4b30()->FUN_1405b5810(i))
        {
            CString strName;
            strName.Format("m_equipSlot%d", i);
            MS2Ptr<ASMovieClip> slot = m_ui->FUN_1409b4560(strName);
            if (slot.get() != 0)
            {
                MS2Ptr<ASMovieClip> effect = slot->FUN_1409b4560(CString("m_equipEffect"));
                if (effect.get() != 0)
                    effect->vfunc_3(bOn);
            }
        }
    }
}

// ---- LapenshardSystemTabPanelBase ----

// @0x140c5ee50
void LapenshardSystemTabPanelBase::FUN_140c5ee50(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
}

// ---- UILapenshardEquipTab ----

// @0x140c5dba0
UILapenshardEquipTab::UILapenshardEquipTab()
    : m_panels(10), m_ui(0)
{
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardItemSlotBagPanel(this)));
    m_panels.AddTail(LapenshardPanelPtr(new LapenshardEquipSlotPanel(this)));
}

// @0x140c5e660
UILapenshardEquipTab::~UILapenshardEquipTab()
{
}

// @0x140c5dd20
void UILapenshardEquipTab::vfunc_1()
{
    POSITION pos = m_panels.GetHeadPosition();
    while (pos != 0)
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (!(p == 0))
            p->vfunc_1();
        m_panels.GetNext(pos);
    }
    m_panels.RemoveAll();
    m_ui = 0;
}

// @0x140c5de10
void UILapenshardEquipTab::vfunc_4()
{
    POSITION pos = m_panels.GetHeadPosition();
    while (pos != 0)
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (!(p == 0))
            p->vfunc_2();
        m_panels.GetNext(pos);
    }
}

// @0x140c5dee0
void UILapenshardEquipTab::vfunc_2(int nEvent)
{
    if (m_ui == 0)
        return;
    POSITION pos = m_panels.GetHeadPosition();
    while (pos != 0)
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (!(p == 0))
            p->vfunc_5(nEvent);
        m_panels.GetNext(pos);
    }
}

// @0x140c5dfd0
void UILapenshardEquipTab::vfunc_3(MS2Ptr<ASUIComponent> ui)
{
    m_ui = ui;
    POSITION pos = m_panels.GetHeadPosition();
    while (pos != 0)
    {
        LapenshardPanelPtr p = m_panels.GetAt(pos);
        if (!(p == 0))
        {
            p->FUN_140c5ee50(ui);
            p->vfunc_4();
            p->vfunc_3();
        }
        m_panels.GetNext(pos);
    }
}

// @0x140c5e140
int UILapenshardEquipTab::vfunc_6(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (_stricmp("OnUnmountEquipSlot", szMethod) != 0)
        return 0;
    if (FUN_140c62520() == 0)
        return 1;
    ASData data;
    if (data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        int nSlot = data.FUN_1422b8a10();
        if (pPlayer->FUN_14152f770((Unk_MyPCLapenSlot)nSlot) != 0)
        {
            COutPacket pkt(0xad, 0);
            pkt.vfunc_o10_1(2);
            Unk_LsSlotArg arg;
            arg.m_n = nSlot;
            FUN_1405b5e40(&arg, &pkt);
            FUN_140710590(pkt);
        }
    }
    return 1;
}

// @0x140c5e290
int UILapenshardEquipTab::vfunc_8()
{
    return 1;
}

// @0x140c5e2b0
void UILapenshardEquipTab::vfunc_9(CInPacket& packet)
{
    if (packet.FUN_14070fe80() == 0x11b)
    {
        char nKind = packet.vfunc_o8_1();
        if (nKind == 0)
            vfunc_2(2);
        else if (nKind == 1)
            vfunc_2(0);
        else if (nKind == 2)
            vfunc_2(1);
    }
}

// @0x140c5e370
void UILapenshardEquipTab::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}

// ---- UILapenshardSystemDialog ----

// "m_buttonBar": the tab strip.
class Unk_LsTabBar : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bVisible);
    void FUN_1422e3460(const ASObj& row);                       // add a tab
    void FUN_1422e31e0(int nIndex);                             // select a tab
};

class Unk_LsItemEvents;
Unk_LsItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_LsItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_LsItemEvents*, UIItemEventListener*);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);
MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
CStringW FUN_14028b8e0(const CStringW& str);

// @0x140c61110
UILapenshardSystemDialog::TabInfo::TabInfo(CString strName, CStringW strLabel, LapenshardTabPtr spPage)
    : m_strName(strName), m_strLabel(strLabel), m_spPage(spPage)
{
}

// @0x140c62b50
UILapenshardSystemDialog::TabInfo::~TabInfo()
{
}

// @0x140c611d0
UILapenshardSystemDialog::UILapenshardSystemDialog()
    : m_spPage(0), m_nSlot(0)
{
    m_164 = 1;
    FUN_141924170(1);
}

// @0x140c62ba0
UILapenshardSystemDialog::~UILapenshardSystemDialog()
{
}

// @0x140c612a0
CString UILapenshardSystemDialog::vfunc_1()
{
    return "LapenshardSystemDialog";
}

// @0x140c616f0
void UILapenshardSystemDialog::vfunc_67()
{
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140c62740();
    for (unsigned i = 0; i < m_tabs.GetCount(); ++i)
    {
        TabInfoPtr spTab = m_tabs[i];
        if (!(spTab == 0))
        {
            if (!(spTab->m_spPage == 0))
                spTab->m_spPage->vfunc_1();
        }
    }
    m_tabs.RemoveAll();
    m_spPage = 0;
    UIModalDialog::vfunc_67();
}

// @0x140c61870
void UILapenshardSystemDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    MS2Ptr<Unk_LsTabBar> spBar = FUN_140c02870("m_buttonBar");
    if (spBar.get() != 0)
    {
        for (unsigned i = 0; i < m_tabs.GetCount(); ++i)
        {
            TabInfoPtr spTab = m_tabs[i];
            if (!(spTab == 0))
            {
                if (!(spTab->m_spPage == 0))
                {
                    ASObj row(2);
                    row.FUN_1409c0d20("tabIndex", i);
                    row.FUN_1407cbb20("label", spTab->m_strLabel);
                    row.FUN_1407cba60("frame", spTab->m_strName);
                    spBar->FUN_1422e3460(row);
                }
            }
        }
        spBar->vfunc_24(true);
        spBar->FUN_1422e31e0(0);
    }
    FUN_1419260d0("m_webGuideButton", 0);
}

// @0x140c61b50
void UILapenshardSystemDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (m_spPage.get() != 0)
        m_spPage->vfunc_5(pRetVal, (void*)&strMethod, pArgs);
}

// @0x140c61be0
int UILapenshardSystemDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this) != 0)
        return 1;
    if (m_spPage.get() != 0)
    {
        if (m_spPage->vfunc_6(szMethod, pArgs, nArgs) != 0)
            return 1;
    }
    ASData data;
    if (_stricmp("OnLeaveTab", szMethod) == 0)
    {
        FUN_140c62740();
        return 1;
    }
    if (_stricmp("OnChangeTab", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        unsigned nTab = data.FUN_1422b8b10();
        FUN_140c627a0(nTab, data.FUN_1422b9260());
        return 1;
    }
    return 0;
}

// @0x140c61de0
void UILapenshardSystemDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_7(p1, p2, p3, p4);
}

// @0x140c61ea0
int UILapenshardSystemDialog::vfunc_82()
{
    if (m_spPage == 0)
        return -1;
    return m_spPage->vfunc_8();
}

// @0x140c61f00
void UILapenshardSystemDialog::vfunc_79(void* p)
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_9(*static_cast<CInPacket*>(p));
}

// @0x140c61f60
void UILapenshardSystemDialog::vfunc_3(void* pItem, bool b)
{
    if (pItem != 0 && static_cast<CItem*>(pItem)->FUN_140526100() != 0)
    {
        FUN_140c623c0(2);
        if (m_spPage.get() != 0)
            m_spPage->vfunc_10(pItem, b);
    }
}

// @0x140c62390
bool UILapenshardSystemDialog::vfunc_75()
{
    return FUN_140166410()->FUN_14036d570(0xd3);
}

// @0x140c623c0
void UILapenshardSystemDialog::FUN_140c623c0(int nEvent)
{
    if (vfunc_55() == 0 && m_spPage.get() != 0)
        m_spPage->vfunc_2(nEvent);
}

// @0x140c62490
void UILapenshardSystemDialog::FUN_140c62490(int nSlot)
{
    m_nSlot = nSlot;
    FUN_140c623c0(10);
}

// @0x140c624d0
void UILapenshardSystemDialog::FUN_140c624d0()
{
    FUN_140c623c0(11);
}

// @0x140c62740
void UILapenshardSystemDialog::FUN_140c62740()
{
    if (m_spPage.get() != 0)
        m_spPage->vfunc_4();
}

// @0x140c627a0
void UILapenshardSystemDialog::FUN_140c627a0(unsigned nTab, const Scaleform::GFx::Value& root)
{
    if (nTab < m_tabs.GetCount())
    {
        TabInfoPtr spTab = m_tabs[nTab];
        if (spTab.get() != 0)
        {
            m_spPage = spTab->m_spPage;
            if (m_spPage.get() != 0)
            {
                MS2Ptr<ASUIComponent> spUi = FUN_140acca70(m_28, root);
                if (spUi.get() != 0)
                    m_spPage->vfunc_3(spUi);
            }
        }
    }
}

// ---- UILapenshardShieldBar ----

class UIRewardNotify;
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmainsystem.h"

extern Unk_LsEntityEvents* DAT_143abf028;                               // the entity event hub
void FUN_1419308c0(Unk_LsEntityEvents* pHub, UIEntityEventListener* pListener);
void FUN_141930950(Unk_LsEntityEvents* pHub, UIEntityEventListener* pListener);
void FUN_1422c8f70(const CString& strName);                             // unbind a bag / slot name
UIRewardNotify* FUN_140938cd0(int nId);
UIObject* FUN_14096e340(int nId);                                       // a shown UI by id
unsigned FUN_141472bc0();                                               // the server tick
float FUN_14028d280(unsigned nMs);                                      // ms -> s

// @0x140c607b0
Unk_LsEntityEvents* FUN_140c607b0()
{
    return DAT_143abf028;
}

// @0x140c5efa0
UILapenshardShieldBar::UILapenshardShieldBar()
    : m_spBuff(0), m_nPending(0), m_bImpending(0), m_bEnded(0)
{
    m_58 = 0;
    m_2c = 0x12;
}

// @0x140c5f090
UILapenshardShieldBar::~UILapenshardShieldBar()
{
}

// @0x140c5f120
CString UILapenshardShieldBar::vfunc_1()
{
    return "LapenshardShieldBar";
}

// @0x140c5f170
void UILapenshardShieldBar::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1419308c0(FUN_140c607b0(), static_cast<UIEntityEventListener*>(this));
}

// @0x140c5f1d0
void UILapenshardShieldBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140c5fbd0();
}

// @0x140c5f200
void UILapenshardShieldBar::vfunc_26()
{
    UIObject::vfunc_26();
    FUN_141930950(FUN_140c607b0(), static_cast<UIEntityEventListener*>(this));
    if (!m_strBind.IsEmpty())
        FUN_1422c8f70(m_strBind);
    m_strBind.Empty();
}

// @0x140c5f2a0
void UILapenshardShieldBar::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(m_30.operator->()));
    if (spEntity.get() != 0)
    {
        int nX = (int)spEntity->FUN_1422c10a0();
        int nY = (int)spEntity->FUN_1422c1110();
        spEntity->vfunc_2(1, 0, 0);
        spEntity->vfunc_3(1);
        int nOffset = 0x96;
        UIObject* pHpBar = FUN_14096e340(0x4e3d);
        if (pHpBar != 0)
        {
            MS2Ptr<ASGameEntity> spHp(dynamic_cast<ASGameEntity*>(pHpBar->FUN_1422dba00().operator->()));
            if (spHp.get() != 0)
                nOffset = (int)(spHp->FUN_1422c1110() + (float)spHp->FUN_1422c13b0() + 30.0f);
        }
        spEntity->vfunc_2(1, 0, nOffset);
        int nW = (int)spEntity->FUN_1422c10a0();
        int nH = (int)spEntity->FUN_1422c1110();
        m_30->Invoke("alignmentWithHpBarOffsetY", nOffset, nX, nY, nW, nH);
    }
}

// @0x140c5f5b0
void UILapenshardShieldBar::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    m_spBuff = 0;
    UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
    if (pReward != 0)
        pReward->FUN_141ac1f40();
}

// @0x140c5f610
void UILapenshardShieldBar::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (!(m_30 == 0) && !(m_spBuff == 0))
    {
        if (m_nPending != 0)
            FUN_140c5fbd0();
        if (m_bEnded == 0 && m_tick.FUN_140268870(100) != 0)
        {
            if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
            {
                if (m_bImpending == 0)
                {
                    if (m_spBuff->FUN_14096d2e0() < 5000)
                    {
                        m_30->Invoke("impending");
                        m_bImpending = 1;
                    }
                }
                if (m_spBuff->FUN_14096d2e0() != 0)
                {
                    CStringW strLeft = FUN_140c5f9e0();
                    m_30->Invoke("setValue", m_spBuff->m_nId, FUN_14096d810(m_spBuff.operator->())->m_nValue, strLeft);
                }
            }
        }
    }
}

// @0x140c5f870
int UILapenshardShieldBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onEndComplete", szMethod) == 0)
    {
        vfunc_3();
        return 1;
    }
    return 0;
}

// @0x140c5f8f0
void UILapenshardShieldBar::FUN_140c5f8f0(MS2Ptr<Unk_LsBuff> spBuff)
{
    if (m_spBuff.get() != spBuff.get())
    {
        if (FUN_141986d30() == 0)
            vfunc_2();
        m_spBuff = spBuff;
        m_nPending = 1;
    }
}

// @0x140c5f990
MS2Ptr<Unk_LsBuff> UILapenshardShieldBar::FUN_140c5f990()
{
    return m_spBuff;
}

// @0x140c5f9e0
CStringW UILapenshardShieldBar::FUN_140c5f9e0()
{
    if (m_spBuff == 0)
        return L"";
    ATL::CTimeSpan span = CMsTime((__int64)FUN_14028d280(m_spBuff->m_nEnd)) - CMsTime((__int64)FUN_14028d280(FUN_141472bc0()));
    int nSeconds = (int)span.GetSeconds();
    int nMinutes = (int)(span.GetTotalMinutes() - span.GetTotalHours() * 60);
    return StringFormat(L"{0:02}:{1:02}", nMinutes, nSeconds);
}

// @0x140c5faf0
void UILapenshardShieldBar::FUN_140c5faf0()
{
    if (m_bEnded == 0 && !(m_30 == 0) && !(m_spBuff == 0))
    {
        m_bEnded = 1;
        m_30->Invoke("end", m_spBuff->m_nId);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x140c607d0


// The Invoke COMDATs of this unit.
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x140c60370
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, int a3, int a4, int a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60480
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60520
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c60620
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3, CString a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bce70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}
