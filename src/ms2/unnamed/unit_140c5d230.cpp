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

class Unk_LsPlayer;
class Unk_LsWorld { public: Unk_LsPlayer* FUN_141bd0cc0(); };           // the local player
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
