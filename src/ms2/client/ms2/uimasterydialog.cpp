// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The mastery window ("MasteryDialog": manufacturing /
// housing / magic scroll mastery lists, the required-material and reward slots and the craft casting bar).
// MS2-UNIT: client\ms2\uimasterydialog.cpp
// MS2-RANGE: 0x140eadd70-0x140ebb6c0 .text$mn
// MS2-RANGE: 0x1400dc070-0x1400dc300 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$StringFormat@H$$BY00D@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEAY00$$CBD@Z 0x140eb96d0 ; order
// MS2-PIN: ??$StringFormat@H$$BY0M@D@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEAY0M@$$CBD@Z 0x140eb99e0 ; order
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140eba630 ; order
// MS2-PIN: ??0?$CAtlArray@UItemEntity@@V?$CElementTraits@UItemEntity@@@ATL@@@ATL@@QEAA@XZ 0x140eba670 ; order
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140eba6f0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@PEAVCItem@@@Z 0x140eba8c0 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@VCEnchantScrollRecipe@@@@QEBA_NXZ 0x140ebaa50 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x140ebab90 ; order
// MS2-PIN: ?GetCount@?$CAtlArray@UItemEntity@@V?$CElementTraits@UItemEntity@@@ATL@@@ATL@@QEBA_KXZ 0x140ebaba0 ; order
// MS2-PIN: ?Reference@?$MS2Ptr@UMasteryInteriorInfo@@@@CAXPEAUMasteryInteriorInfo@@@Z 0x140ebb250 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ebb330 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ebb390 ; unique
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400dc190
// MS2-PIN: ??$?0$$BY00_W@ArgType@internal@fmt@@QEAA@AEAY00$$CB_W@Z 0x140eb9370
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@AEBV0@@Z 0x140eba830
// MS2-PIN: ??1?$MS2Ptr@VItemHousing@@@@QEAA@XZ 0x140eba9f0
// MS2-PIN: ?IsNull@?$MS2Ptr@VAScript@@@@QEBA_NXZ 0x140ebaa20
// MS2-PIN: ??8?$MS2Ptr@VCItemData@@@@QEBA_NPEAVCItemData@@@Z 0x140ebaa80
// MS2-PIN: ??C?$MS2Ptr@VAScript@@@@QEBAPEAVAScript@@XZ 0x140ebab80
// MS2-PIN: ?get@?$MS2Ptr@VAScript@@@@QEBAPEAVAScript@@XZ 0x140ebaf30
// MS2-PIN: ?get@?$MS2Ptr@VCMsgBoxData@@@@QEBAPEAVCMsgBoxData@@XZ 0x140ebaf40
// MS2-PIN: ?AddRef@?$MS2Ptr@VCItem@@@@AEBAXXZ 0x140ebb220
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItem@@@@AEBAXPEAX@Z 0x140ebb270
// MS2-PIN: ?Release@?$MS2Ptr@VCItem@@@@AEAAXXZ 0x140ebb2a0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCItem@@@@AEAAXPEAX@Z 0x140ebb2e0
// MS2-PIN: ?vfunc_48@UIMasteryDialog@@UEAAHXZ 0x140ebb0f0
// MS2-PIN: ??_GUIMasteryDialog@@UEAAPEAXI@Z 0x140ebad10
// MS2-PIN: ??_EUIMasteryDialog@@WBIA@EAAPEAXI@Z 0x140ebabc0
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VItemHousing@@@@V?$CElementTraits@V?$MS2Ptr@VItemHousing@@@@@ATL@@@ATL@@QEAA@XZ 0x140eba6b0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140eba9b0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140eba9d0
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140ebabd0
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140ebac10
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140ebb420
// MS2-PIN: ??$Call@VUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140ebb4a0
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140ebb3f0
// MS2-PIN: ??$Call@VUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140ebb460
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimasterydialog.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asradiobutton.h"   // the "m_grade00".. toggles

#include "uimasterydialog.h"
#include "uidailymissiondialog.h"   // C3: UIDailyMissionDialog::FUN_140c02870 (the tab strip lookup)
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include <stdlib.h>
#include <atlcoll.h>

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uicastingbar.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/placeholder/cmasterymanager.h"

// ---- the unit's statics (after the shared header statics) ----
static UICommon::CMyPCKeyInputController s_keyInput;                                                                // @0x1400dc200
static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400dc230

// ---- unit-local placeholders (unrecovered singletons / helpers) ----
using ATL::CAtlArray;
typedef ATL::CAtlArray<MS2Ptr<ItemEntity> > Unk_MItemArray;   // reward lists hold item pointers (CMasteryTable::Rewards)

// The feature flags (global via FUN_140166410).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

// The notice hub (global via FUN_140939a10).
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10

// The item event hub (global via FUN_140a6a840); the view of the definition in uiitemenchantdialog.cpp.
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* listener);      // register (once)
    void FUN_1419caeb0(UIItemEventListener* listener);      // unregister
};
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840

// The world (global via FUN_1403ed2d0): the own character.
class Unk_MWorld
{
public:
    MyPC* FUN_141bd0cc0();
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};

// The casting bar dialog (global lookup FUN_140ac2270(id)).
class Unk_MCastingBar : public UICastingBar
{
};
class UICastingBar* FUN_140ac2270(int);   // C3: was FUN_140ac2270


// The AS value setters / getters used by the Invoke helpers of this unit.
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);

// The AS array helpers (push an int / an object).
class Unk_MArray : public ASArray
{
};

typedef ATL::CAtlArray<MS2Ptr<CMasteryReceipe> > Unk_MRecArray;

// The mastery data singleton (global via FUN_1409670c0).
class Unk_MData : public CMasteryTable
{
public:
};
Unk_MData* FUN_1409670c0();

// The mastery points service (global via FUN_140e5ca20).
class Unk_MPoints : public CMasteryManager
{
};

// The string table (global via TSingleton<CStringTable>::GetInstance).

extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90)

class Unk_MDebug { };
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool IsDebugMode();
};

// MyPC accessors.
int FUN_14053feb0(int nItemId);                             // default rank of an item
CStringW FUN_1419021b0(unsigned nHave, unsigned nNeed);               // "have/need" count text
#include "ms2/commonfiles/commonutil.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/placeholder/asuicomponent.h"   // C3 type identity: ASUIComponent
#include "ms2/placeholder/wcformat.h"
void FUN_140d432d0(ItemSlotBinder* pBinder, int n);
void FUN_140710590(COutPacket& pkt);

// The AS controls of the movie. Slot 3 / 23 / 24 are the ones the dialog calls.
class Unk_MCtl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(int n);
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool b);
    void FUN_1409c0dc0(const char* szName, const char* szValue);     // the ASObj setters, applied to the control
    void FUN_1407cb9c0(const char* szName, int n);
};

// "m_mainTab" / "m_gradeGroup" (a button group: selectedIndex).
template<> MS2Ptr<ASEventDispatcher> AScript::FUN_140eb9cf0<ASEventDispatcher>(const CString& strName);
// "m_guideBar" of the level control.
using Unk_MGuide = ASUIComponent;   // C3 type identity: Unk_MGuide stood in for ASUIComponent
// "m_levelControl" / "m_magicScrollControl".
class Unk_MLevelCtrl : public Unk_MCtl
{
public:
    Scaleform::GFx::Value FUN_140eb9e40(const char* szMethod, int a1, int a2, CStringW a3, int a4);
    Scaleform::GFx::Value FUN_140eb9f50(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3, int a4);
    // C3: FUN_140eba060 is AScript::FUN_140eba060(const char*, const AScript&, unsigned) (ascript.h)
    Scaleform::GFx::Value FUN_140eba120(const char* szMethod, const AScript& a1, unsigned __int64 a2, int a3);
    Scaleform::GFx::Value FUN_140eba380(const char* szMethod, unsigned __int64 a1, unsigned int a2, CStringW a3, int a4);
};


// The notify of the local character being damaged (RTTI .?AVNotifyDamagedMyPC@@).
class NotifyDamagedMyPC : public NotifyObject
{
public:
    NotifyDamagedMyPC();
    virtual ~NotifyDamagedMyPC();
    virtual CStringW GetTypeName();
    CDamageRecord* m_pDamage;                               // +0x18
};


typedef ATL::CAtlArray<MS2Ptr<ItemEntity> > Unk_MItemArray;   // reward lists hold item pointers (CMasteryTable::Rewards)
// message box helpers
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_141275260(int nStringId, int nA, int nB);
int FUN_1407181a0(const CStringW& str);
#include "ms2/client/ms2/cubemapinformationservice_3.h"   // B22 follow-up: was a local member view (the Unk_BuddyHandle clash is gone)
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
class CAchieveManager { public: BOOL IsGradeCleared(unsigned nId, int nGrade); };   // C3: member view (achievemanager.h)
class Unk_NametagTrophy* FUN_1406c7600();   // C3: was FUN_1406c7600
int FUN_140eb8cd0(MS2Ptr<ItemHousing> spFurn);
int FUN_140eb8eb0(MS2Ptr<ItemHousing> spFurn);
bool FUN_140ebb1e0(const Scaleform::GFx::Value* v);                // Value::IsInt
// (FUN_140889fd0 decl gone: 0x140889fd0 is the real InteriorMap CNode::GetHash, reached through FindNextNode below)
// ---- housing / furniture / scroll tables ----
class CMasteryInteriorTable;
CMasteryInteriorTable* FUN_140933200();
namespace Common { template <class T> int FindElement(const ATL::CAtlArray<T>& arr, const T& v); }   // C3: was FUN_1402bacf0; index of the value (-1 when absent)
extern ATL::CAtlArray<int> DAT_143ab32b8;   // scenestategame.cpp
class Unk_MHouseRec : public CPtred { public: char m_pad[8]; unsigned short m_nLevel; };    // m_nLevel +0x20
typedef ATL::CAtlMap<unsigned int, MS2Ptr<Unk_MHouseRec> > Unk_MHouseMap;
// C3: the Unk_MHouseTable view is gone. FUN_140886640 / FUN_1408865b0 are
// UGCCubeCategoryTable::GetBonusInteriors / GetInterior (ugccubecategorytable.h).
// Unk_CubePtr<Interior> shares its copy ctor / dtor / operator-> VAs with
// MS2Ptr<Unk_MHouseRec>; IsNull (0x140ebaa20) is read through a reference cast.


MS2Ptr<CItemData> FUN_14053f870(int nItemId);
typedef ATL::CAtlArray<MS2Ptr<ItemHousing> > Unk_MFurnArray;
// The warehouse item table (warehouseitem.h CWarehouseItemTable::FUN_1408fbe90): the first stored item with this id, as a
// 16-byte MS2Ptr (hidden return; the exe tests it with MS2Ptr::operator! 0x140534e50 and releases the temp).
#include "ms2/client/ms2/warehouseitem.h"     // DAT_143ab2e20, the warehouse item table
#include "ms2/commonfiles/enchantscrolldata.h"
#include "ms2/commonfiles/itemdatatable.h"   // C3: CItemDataTable, ItemHousing, CItemData
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/masteryinteriortable.h"   // C3: CMasteryInteriorTable
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_1416561a0
#include "ms2/placeholder/asbuttonbar.h"  // C3: ASButtonBar::FUN_1422e3400

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog


typedef ATL::CAtlArray<MS2Ptr<CEnchantScrollRecipe> > Unk_MScrollArray;
class CLua   // C3: member view (luautil.h)
{
public:
    unsigned int CalcGatheringReceipeRewardItemCount(unsigned int a, unsigned int b, unsigned int c);
    unsigned int CalcCraftReceipeRequireItemCount(unsigned int a, unsigned int b, unsigned int c);
};
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
#include "ms2/client/ms2/equipment.h"   // CEquipment (was a local member view)
int FUN_1406198a0(int n, float f);
__int64 FUN_1404820b0(unsigned n, float f);
CStringW FUN_14183e9c0(CStringW str, int nRank);
CStringW FUN_140298ea0(CStringW strKey);
int FUN_140930e10();
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);   // C3: was FUN_140c43630
class UIMessengerBrowser* FUN_140a3ab70(int);   // C3: was FUN_140a3ab70
class UIMessengerBrowser { public: void FUN_141a25770(CStringW strText, bool bHistory); };   // C3: member view (uimessenger.h)
extern ATL::CAtlMap<unsigned int, int> DAT_143ab31a0;   // scenestategame.cpp
extern __int64 DAT_143ab2898;
extern unsigned short DAT_143ab291c;
extern __int64 DAT_143ab2930;

// a page array (ctor 0x1422deec0)
class Unk_MPageArray : public ASArray {};
// the handle of the movie page (Invoke glue on a bare AScript)
class Unk_MInvoker : public AScript
{
public:
    Scaleform::GFx::Value FUN_140eba200(const char* szMethod, int a1, int a2);
    Scaleform::GFx::Value FUN_140eba2c0(const char* szMethod, int a1, bool a2);
};
static inline Unk_MInvoker* MPage(const MS2Ptr<AScript>& p) { return reinterpret_cast<Unk_MInvoker*>(p.get()); }
class Unk_MObjSetter : public AScript { public: void FUN_140eba4a0(const char* szName, unsigned int n); };

// ==TYPES-END==

// @0x140eadd70
Unk_MasteryCraft::Unk_MasteryCraft()
{
    FUN_140eadda0();
}

// @0x140eadda0
void Unk_MasteryCraft::FUN_140eadda0()
{
    m_nType = 2;
    m_nTotal = 0;
    m_nDone = 0;
    m_nId = 0;
    m_nPending = 0;
}

// @0x140eaddf0
BOOL Unk_MasteryCraft::FUN_140eaddf0()
{
    return m_nType == 0;
}

// @0x140eade30
BOOL Unk_MasteryCraft::FUN_140eade30()
{
    return m_nType == 1;
}

// @0x140eade70
BOOL Unk_MasteryCraft::HasTotal()
{
    return m_nTotal != 0;
}

// @0x140eadeb0
UIMasteryDialog::UIMasteryDialog()
    : m_mastery(CString("MasteryDialog_Mastery"))
    , m_reward(CString("MasteryDialog_Reward"))
    , m_require(CString("MasteryDialog_Require"))
{
    m_308 = 0;
    m_30c = 0;
    m_7c = 1;
    m_80 = 0;
    m_nMainTab = 0;
    m_nSelected = 0;
    memset(m_lastSelected, 0, sizeof(m_lastSelected));
    memset(m_268, 0, sizeof(m_268));
    memset(m_scroll, 0, sizeof(m_scroll));
    FUN_141924170(1);
    FUN_140d432d0(&m_reward, 0x11);
    FUN_140d432d0(&m_require, 1);
    FUN_140d432d0(&m_mastery, 0x11);
    m_nPendingSub = 0;
    m_nPendingList = 0;
    m_304 = 0;
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyDamagedMyPC"), Delegate<void(NotifyObject*)>(this, &UIMasteryDialog::OnDamagedMyPC));
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xd1))
        m_2f8 = 10;
    else
        m_2f8 = 6;
    memset(&m_310, 0, 0x30);
}

// @0x140eae2d0
UIMasteryDialog::~UIMasteryDialog()
{
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyDamagedMyPC"), Delegate<void(NotifyObject*)>(this, &UIMasteryDialog::OnDamagedMyPC));
}

// @0x140eae470
CString UIMasteryDialog::GetTypeName()
{
    return CString("MasteryDialog");
}

// @0x140eae4c0
int UIMasteryDialog::vfunc_65()
{
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419cae20(this);
    return UIDialog::vfunc_65();
}

// @0x140eae520
void UIMasteryDialog::vfunc_67()
{
    if (m_craft.HasTotal()) {
        Unk_MCastingBar* pBar = ((class Unk_MCastingBar*)FUN_140ac2270(0x4e72));
        if (pBar)
            pBar->FUN_1418e1390();
    }
    m_magicScroll = 0;
    m_craft.FUN_140eadda0();
    ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_reward))->FUN_140d43990();
    ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_require))->FUN_140d43990();
    ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_mastery))->FUN_140d43990();
    m_nSelected = 0;
    if (m_30.get()) {
        Scaleform::GFx::Value last = m_30->GetMember("m_lastSelectedIndex");
        if (last.IsArray()) {
            Scaleform::GFx::Value item[4];
            for (size_t i = 0; i < 4; i++) {
                last.GetElement(i, &item[i]);
                if (FUN_140ebb1e0(&item[i]))
                    m_lastSelected[i] = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(item[i]))->GetInt();
                else
                    m_lastSelected[i] = 0;
            }
        }
        if (MS2Ptr<ASEventDispatcher> spTab = FindControl("m_mainTab")) {
            m_nMainTab = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spTab->GetMember("selectedIndex")))->GetInt();
        }
    }
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419caeb0(this);
    UIDialog::vfunc_67();
}

// @0x140eae8a0
void UIMasteryDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419260d0(CString("m_webGuideButton"), 0);
    ASArray last(2);
    for (size_t i = 0; i < 4; i++)
        reinterpret_cast<Unk_MArray&>(last).PushInt(m_lastSelected[i]);
    reinterpret_cast<ASObj*>(m_30.operator->())->FUN_1409eb1d0("m_lastSelectedIndex", last);
    if (MS2Ptr<ASUIComponent> spScrollCtrl = GetChild<ASUIComponent>("m_magicScrollControl"))
        spScrollCtrl->Invoke("setSelectedSlotIndex", FUN_140eb6870() - 1);
    if (MS2Ptr<ASEventDispatcher> spMainTab = FindControl("m_mainTab"))
        spMainTab->Invoke("setSelectedButtonByIndex", m_nMainTab);
    do { m_30->FUN_140bbe640("m_magicScroll", m_magicScroll); if (m_magicScroll == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(272), __FUNCTION__)); } while (0);
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a))
        m_magicScroll->vfunc_3(0);
    FUN_140eb7e30();
}

// @0x140eaed30
void UIMasteryDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CStringW strName = pArgs->FUN_1422b8f40();
    if (strName == "housingSlot") {
        int nId = pArgs->PopUInt();
        int nRank = FUN_14053feb0(nId);
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nId, nRank, 0)) {
            ASTooltip tip(((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()), 8, 2);
            if (tip.FUN_1409e0d40(spItem.get())) {
                tip.SetTooltipAlign(7);
                *pRetVal = tip.FUN_1422bb870();
            }
        }
    } else if (strName == "masteryRecipe") {
        if (GetMainTabIndex() == 1) {
            int nId = pArgs->PopInt();
            ItemEntity* pEntry = FUN_1409670c0()->FirstItem(nId);
            if (pEntry) {
                MS2Ptr<CItem> spItem(new CItem);
                if (spItem->FUN_140523c40(pEntry->m_itemId, pEntry->vfunc_o18_1(), 0)) {
                    ASTooltip tip(((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()), 0x800, 2);
                    if (tip.FUN_1409e0d40(spItem.get())) {
                        tip.SetTooltipAlign(7);
                        *pRetVal = tip.FUN_1422bb870();
                    }
                }
            }
        }
    }
}

// @0x140eaf090
int UIMasteryDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (!_stricmp(szMethod, "onSelectCategory")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_140eafde0();
        return 1;
    } else if (!_stricmp(szMethod, "onSelectMastery")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_140eb53a0();
        return 1;
    } else if (!_stricmp(szMethod, "onSelectList")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nIndex = data.PopInt();
            FUN_140eb5450(nIndex);
        }
        return 1;
    } else if (!_stricmp(szMethod, "onReceiveItem")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            switch (GetMainTabIndex()) {
            case 0:
            case 1: {
                int nId = data.PopUInt();
                COutPacket pkt(static_cast<int>(SendOp::Mastery), 0);
                pkt.Encode1(1);
                pkt.Encode4(nId);
                FUN_140710590(pkt);
                break;
            }
            case 2:
                if (FUN_140eb86b0() == 8) {
                    int nId = data.PopInt();
                    COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
                    pkt.Encode1(0x29);
                    pkt.Encode1((unsigned char)nId);
                    FUN_140710590(pkt);
                } else if (FUN_140eb86b0() == 9) {
                    int nId = data.PopUInt();
                    COutPacket pkt(static_cast<int>(SendOp::Mastery), 0);
                    pkt.Encode1(1);
                    pkt.Encode4(nId);
                    FUN_140710590(pkt);
                }
                break;
            }
        }
        return 1;
    } else if (!_stricmp(szMethod, "onCraftOk")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nId = data.PopInt();
            switch (GetMainTabIndex()) {
            case 1:
                FUN_140eb55e0(nId);
                break;
            case 2:
                FUN_140eb5e30(nId);
                break;
            case 3:
                FUN_140eb5e60(nId);
                break;
            }
        }
        return 1;
    } else if (!_stricmp(szMethod, "onDebug")) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            CStringW strCommand;
            CStringW strFormat(L"/ManufacturingMastery {0} {1}");
            switch (GetMainTabIndex()) {
            case 1: {
                int nId = data.PopInt();
                strCommand = StringFormat((const wchar_t*)strFormat, nId, "");
                break;
            }
            case 3: {
                int nId = data.PopInt();
                strCommand = StringFormat((const wchar_t*)strFormat, nId, "magicscroll");
                break;
            }
            }
            UIMessengerBrowser* pChat = FUN_140a3ab70(0x4e61);
            if (pChat)
                pChat->FUN_141a25770(CStringW(strCommand), false);
        }
    } else if (!_stricmp(szMethod, "onChangeFilter")) {
        FUN_140eb3460();
    } else if (!_stricmp(szMethod, "onScrollPosition")) {
        if (m_304 != 0)
            return 1;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nSlot = FUN_140eb86b0();
            int nPos = data.PopInt();
            m_scroll[nSlot] = nPos;
        }
        return 1;
    }
    return 0;
}

// @0x140eaf840
void UIMasteryDialog::OnCastingFinished()
{
    if (m_craft.FUN_140eaddf0()) {
        COutPacket pkt(static_cast<int>(SendOp::Mastery), 0);
        pkt.Encode1(2);
        pkt.Encode4(m_craft.m_nId);
        FUN_140710590(pkt);
    } else if (m_craft.FUN_140eade30()) {
        COutPacket pkt(static_cast<int>(SendOp::EnchantScroll), 0);
        pkt.Encode1(4);
        pkt.Encode4(m_craft.m_nId);
        FUN_140710590(pkt);
    } else {
        MS2_ASSERT_AT(0x5ac, 0);
        return;
    }
    m_craft.m_nDone++;
    int nResult = FUN_140eb6d40(m_craft.m_nType, m_craft.m_nId);
    if (m_craft.m_nDone <= m_craft.m_nTotal && nResult != 0)
        m_craft.m_nPending = 1;
    else
        m_craft.FUN_140eadda0();
}

// @0x140eafa10
void UIMasteryDialog::OnCastingCancelled()
{
    m_craft.FUN_140eadda0();
    FUN_140eb8b20();
}

// @0x140eafa50
void UIMasteryDialog::vfunc_72()
{
    if (m_craft.HasTotal() && m_craft.m_nPending != 0) {
        int nTime = 2000;
        if (m_craft.FUN_140eaddf0()) {
            MS2Ptr<CMasteryReceipe> spRec = FUN_1409670c0()->Find(m_craft.m_nId);
            if (spRec.get())
                nTime = spRec->m_nGatheringTime;
        }
        Unk_MCastingBar* pBar = ((class Unk_MCastingBar*)FUN_140ac2270(0x4e72));
        if (pBar) {
            CStringW strKey = m_craft.FUN_140eaddf0() ? L"s_mastery_manufacture_progress" : L"s_mastery_magicscroll_progress";
            CStringW strText = FUN_14028dfa0(strKey, m_craft.m_nDone, m_craft.m_nTotal);
            pBar->StartCastingText((ICastingEventListener*)this, strText, nTime, false, true, L"");
        }
        m_craft.m_nPending = 0;
    }
    if (m_nPendingSub != 0) {
        FUN_140eb05b0(m_nPendingSub, true);
        if (FUN_140eb8a90() == m_nPendingList)
            FUN_140eb1770(m_nSelected, true);
        m_nPendingSub = 0;
        m_nPendingList = 0;
    } else if (m_nPendingList != 0) {
        if (FUN_140eb8a90() == m_nPendingList) {
            FUN_140eb0da0(m_nPendingList, true);
            FUN_140eb1770(m_nSelected, true);
        }
        m_nPendingList = 0;
    }
}

// @0x140eafdb0
void UIMasteryDialog::SetMainTab(int nMainTab, int)
{
    m_nMainTab = nMainTab;
}

// @0x140eafde0
void UIMasteryDialog::FUN_140eafde0()
{
    if (!FUN_141924630())
        return;
    if (MS2Ptr<ASButtonBar> spSub = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02870("m_subTab")) {
        spSub.operator->()->FUN_1422e3400();
        switch (GetMainTabIndex()) {
        case 0:
            spSub.operator->()->AddLabelItem(GetMasteryTabName(3));
            spSub.operator->()->AddLabelItem(GetMasteryTabName(5));
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
                spSub.operator->()->AddLabelItem(GetMasteryTabName(4));
                spSub.operator->()->AddLabelItem(GetMasteryTabName(6));
            }
            break;
        case 1:
            spSub.operator->()->AddLabelItem(GetMasteryTabName(7));
            spSub.operator->()->AddLabelItem(GetMasteryTabName(8));
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
                spSub.operator->()->AddLabelItem(GetMasteryTabName(9));
                spSub.operator->()->AddLabelItem(GetMasteryTabName(10));
            }
            break;
        case 2:
            spSub.operator->()->AddLabelItem(GetHousingTabName());
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x8d))
                spSub.operator->()->AddLabelItem(GetMasteryTabName(0xb));
            break;
        case 3:
            if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a))
                break;
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7c))
                spSub.operator->()->AddLabelItem(GetStringCommonByKey(L"s_mastery_magicscroll_enchant_scroll_tab"));
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7d))
                spSub.operator->()->AddLabelItem(GetStringCommonByKey(L"s_mastery_magicscroll_restore_scroll_tab"));
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7e))
                spSub.operator->()->AddLabelItem(GetStringCommonByKey(L"s_mastery_magicscroll_fracto_scroll_tab"));
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7f))
                spSub.operator->()->AddLabelItem(GetStringCommonByKey(L"s_mastery_magicscroll_protected_scroll_tab"));
            break;
        }
        spSub->vfunc_24(true);
    }
}

// @0x140eb0540
void UIMasteryDialog::FUN_140eb0540()
{
    ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_reward))->FUN_140d43990();
    ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_require))->FUN_140d43990();
    m_30->Invoke("removePage");
}

// @0x140eb05b0
void UIMasteryDialog::FUN_140eb05b0(int nType, bool bKeep)
{
    if (FUN_140eb8a90() != nType)
        return;
    FUN_140eb0610(nType, bKeep);
    FUN_140eb0da0(nType, bKeep);
}

// @0x140eb0610
void UIMasteryDialog::FUN_140eb0610(int nType, bool bKeep)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    int nOld = GetCachedTypeValue(nType);
    int nNow = (int)reinterpret_cast<PC*>(pPc)->GetMastery(nType);
    if (MS2Ptr<ASUIComponent> spLevel = GetChild<ASUIComponent>("m_levelControl")) {
        int nGrade = FUN_1409670c0()->Grade(nType, nNow);
        int bMax = nGrade == FUN_1409670c0()->MaxGrade(nType);
        int nBase = FUN_1409670c0()->Value(nType, nGrade);
        int nNext = FUN_1409670c0()->Value(nType, nGrade + 1);
        int nCur = nNow - nBase;
        int nMax = nNext - nBase;
        bool bChanged = nNow != nOld;
        bool bGradeChanged = false;
        if (bChanged) {
            SetTypeValue(nType, nNow);
            int nOldGrade = FUN_1409670c0()->Grade(nType, nOld);
            bGradeChanged = nGrade != nOldGrade;
        }
        if (!bKeep || bChanged) {
            CStringW strGrade = StringFormat(L"{0} {1}", FUN_1409670c0()->TypeName(nType), FUN_1409670c0()->GradeName(nType, nGrade));
            reinterpret_cast<Unk_MLevelCtrl*>(spLevel.operator->())->FUN_140eb9f50("setPcGrade", nCur, nMax, strGrade, bMax);
            if (MS2Ptr<Unk_MGuide> spGuide = spLevel->FUN_140accfb0<Unk_MGuide>("m_guideBar"))
                spGuide->Invoke("setPC", (unsigned int)nNow);
        }
        if (!bKeep || bGradeChanged) {
            ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_mastery))->FUN_140d43990();
            spLevel->Invoke("removeGradeAll");
            int nCount = FUN_1409670c0()->MaxGrade(nType);
            ASArray arr(2);
            for (int i = 1; i <= nCount; i++) {
                ASObj obj(2);
                FUN_140eb6920(nType, i, obj);
                reinterpret_cast<Unk_MArray&>(arr).PushObj(obj);
            }
            spLevel->FUN_140eba060("setGrade", arr, nNow);
        }
    }
}

// @0x140eb0bf0
void UIMasteryDialog::FUN_140eb0bf0(int nType, int nIndex)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    if (MS2Ptr<ASUIComponent> spLevel = GetChild<ASUIComponent>("m_levelControl")) {
        if (MS2Ptr<Unk_MGuide> spGuide = spLevel->FUN_140accfb0<Unk_MGuide>("m_guideBar")) {
            ASObj obj(2);
            FUN_140eb6920(nType, nIndex, obj);
            spGuide->Invoke("addLevelGuide", obj);
        }
    }
}

// @0x140eb0da0
void UIMasteryDialog::FUN_140eb0da0(int nType, bool bKeep)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    unsigned int nMastery = reinterpret_cast<PC*>(pPc)->GetMastery(nType);
    if (bKeep) {
        if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList")) {
            Unk_MRecArray recs;
            FUN_1409670c0()->Receipes(nType, recs);
            int nCount = (int)recs.GetCount();
            int nScroll = spList->GetSelectedIndex();
            if (nScroll < nCount) {
                int nFirst = spList->FUN_1422e1820();
                int nRow = 0;
                for (int i = 0; i < nCount; i++) {
                    MS2Ptr<CMasteryReceipe> spRec(recs[i]);
                    if (((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d330(recs[i]->m_nId) == 0)
                        continue;
                    ASObj row(2);
                    row.FUN_1407cb9c0("id", spRec->m_nId);
                    row.FUN_1407cbb20("name", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x2f, spRec->m_nId));
                    row.FUN_1407cbb20("state", FUN_140eb71a0(MS2Ptr<CMasteryReceipe>(spRec)));
                    row.FUN_1407cbbe0("active", (nMastery >= (unsigned int)spRec->m_nRequireMastery && HasRequiredLevel(MS2Ptr<CMasteryReceipe>(spRec)) != 0) ? true : false);
                    row.FUN_1407cba60("icon", spRec->IconPath());
                    if (nType == 0xb && spRec->m_rewards.GetCount() > 0)
                        row.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
                    if (nRow >= nFirst && nRow <= nFirst + 5) {
                        spList->FUN_1422e1970(nRow, row);
                        spList->FUN_1422e1a00(nRow, row);
                    } else {
                        spList->FUN_1422e1970(nRow, row);
                    }
                    nRow++;
                }
            }
            spList->vfunc_23();
        }
    } else {
        FUN_140eb0540();
        if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList")) {
            spList->FUN_1422dd1d0();
            static_cast<ASObj*>(static_cast<AScript*>(spList.operator->()))->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_mastery");
            spList->FUN_1407cb9c0("rowHeight", 0x4c);
            Unk_MRecArray recs;
            FUN_1409670c0()->Receipes(nType, recs);
            for (size_t i = 0; i < recs.GetCount(); i++) {
                MS2Ptr<CMasteryReceipe> spRec(recs[i]);
                if (((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d330(recs[i]->m_nId) == 0)
                    continue;
                ASObj row(2);
                row.FUN_1407cb9c0("id", spRec->m_nId);
                row.FUN_1407cbb20("name", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x2f, spRec->m_nId));
                row.FUN_1407cbb20("state", FUN_140eb71a0(MS2Ptr<CMasteryReceipe>(spRec)));
                row.FUN_1407cbbe0("active", (nMastery >= (unsigned int)spRec->m_nRequireMastery && HasRequiredLevel(MS2Ptr<CMasteryReceipe>(spRec)) != 0) ? true : false);
                row.FUN_1407cba60("icon", spRec->IconPath());
                if (nType == 0xb && spRec->m_rewards.GetCount() > 0)
                    row.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
                spList->AddItem(row);
            }
            FUN_140eb8b20();
        }
    }
}

// @0x140eb1770
void UIMasteryDialog::FUN_140eb1770(int nId, bool bKeep)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return;
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    if (bKeep) {
        if (m_30.get()) {
            MS2Ptr<CMasteryReceipe> spRec = FUN_1409670c0()->Find(nId);
            if (spRec.IsNull())
                return;
            ASObj page(2);
            for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
                Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
                int nNeed = CalcIngredientCount(spRec->m_nType, spRec->m_nRequireMastery, ref->m_c);
                int nHave = 0;
                if (ref->m_b != 0)
                    nHave = g_143ab2a90.FUN_140a5f780(ref->m_b, 0);
                else
                    nHave = g_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
                CStringW strCnt = FUN_1419021b0(nHave, nNeed);
                ASObj req(2);
                req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
                page.FUN_1409eb270(Unk_SocketFormat<unsigned __int64>("require{0}", i), req);
            }
            m_30->Invoke("refreshPage", page);
        }
    } else {
        FUN_140eb0540();
        if (m_30.get()) {
            MS2Ptr<CMasteryReceipe> spRec = FUN_1409670c0()->Find(nId);
            if (spRec.IsNull())
                return;
            ASObj page(2);
            int bCanCraft = (GetMyMastery(spRec->m_nType) >= spRec->m_nRequireMastery && !m_craft.HasTotal()) ? 1 : 0;
            for (size_t i = 0; i < spRec->m_rewards.GetCount(); i++) {
                ItemEntity& rew = spRec->m_rewards[i];
                int nRank = CalcAdjustedItemCount(spRec->m_nType, spRec->m_nRequireMastery, &rew);
                page.FUN_1407cba60(Unk_SocketFormat<unsigned __int64>("binding{0}", i), m_reward.BindNewItem(rew.m_itemId, rew.vfunc_o18_1(), nRank));
            }
            int bEnough = 1;
            for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
                Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
                int nNeed = CalcIngredientCount(spRec->m_nType, spRec->m_nRequireMastery, ref->m_c);
                int nHave = 0;
                if (ref->m_b != 0)
                    nHave = g_143ab2a90.FUN_140a5f780(ref->m_b, 0);
                else
                    nHave = g_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
                if (nHave < nNeed)
                    bEnough = 0;
                int nItem = ref->FUN_14026b500();
                int nItemRank = FUN_14053feb0(nItem);
                int nCount = ref->m_c;
                CStringW strCnt = FUN_1419021b0(nHave, nNeed);
                ASObj req(2);
                req.FUN_1407cba60("binding", m_require.BindNewItem(nItem, nItemRank, nCount));
                req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
                page.FUN_1409eb270(Unk_SocketFormat<unsigned __int64>("require{0}", i), req);
            }
            int bState = HasRequiredLevel(MS2Ptr<CMasteryReceipe>(spRec));
            page.FUN_1407cb9c0("id", nId);
            page.FUN_1407cbb20("name", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x2f, nId));
            page.FUN_1407cbb20("mastery", FUN_14028dfa0(CStringW(L"s_mastery_reward_mastery"), (unsigned)FUN_140eb8120(MS2Ptr<CMasteryReceipe>(spRec))));
            page.FUN_1407cbb20("desc", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x30, nId));
            page.FUN_1407cbb20("place", CStringW(spRec->m_strHabitat));
            page.FUN_1407cba60("icon", spRec->IconPath());
            page.FUN_1409c1180("meso", spRec->m_nRequireMeso);
            page.FUN_1407cbbe0("enabled", bCanCraft && bEnough && bState);
            page.FUN_1407cbbe0("debug", ((class CInputKeyHandler*)(class Unk_MDebug*)(((class Unk_MDebug*)FUN_14025e7c0())))->IsDebugMode());
            if (spRec->m_nType == 0xb && spRec->m_rewards.GetCount() > 0)
                page.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
            m_30->Invoke("setPage", page);
        }
    }
}

// @0x140eb2460
void UIMasteryDialog::FUN_140eb2460()
{
    if (FUN_140eb86b0() != 8)
        return;
    FUN_140eb24a0();
    FUN_140eb2d10();
}

// @0x140eb24a0
void UIMasteryDialog::FUN_140eb24a0()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    if (MS2Ptr<ASUIComponent> spLevel = GetChild<ASUIComponent>("m_levelControl")) {
        ((class ItemSlotBinder*)(class ItemSlotBinder*)(&m_mastery))->FUN_140d43990();
        spLevel->Invoke("removeGradeAll");
        unsigned short nCur = DAT_143ab291c;
        unsigned short nMax = FUN_140933200()->FUN_140ebb020();
        int nSum = 0;
        unsigned int nSumCur = 0;
        ASArray rows(2);
        for (int nLevel = 1; nLevel <= (int)nMax; nLevel++) {
            Unk_MItemArray items;
            FUN_140933200()->GetInteriorItems(nLevel, reinterpret_cast<PC*>(pPc)->FUN_141654700(), items);
            if (nLevel != 1 && items.GetCount() == 0)
                continue;
            int nAdd = FUN_140933200()->GetMasteryValue(nLevel);
            nSum += nAdd;
            if (nLevel <= (int)nCur)
                nSumCur += nAdd;
            ASObj row(2);
            row.FUN_1407cb9c0("id", nLevel);
            row.FUN_1409c0d20("level", nSum);
            row.FUN_1407cbb20("levelStr", FUN_14028dfa0(CStringW(L"s_mastery_housing_grade"), nLevel));
            int bInactive = Common::FindElement<int>(DAT_143ab32b8, nLevel) != -1;
            CString strState;
            if (bInactive)
                strState = "inactive";
            else
                strState = (nCur >= nLevel) ? "active" : "lock";
            row.FUN_1407cba60("state", CString(strState));
            if (items.GetCount() > 0) {
                MS2Ptr<ItemEntity> spItem0(items[0]);
                row.FUN_1407cba60("binding", m_mastery.BindNewItem(spItem0->m_itemId, spItem0->vfunc_o18_1(), spItem0->m_count));
            }
            reinterpret_cast<Unk_MArray&>(rows).PushObj(row);
        }
        reinterpret_cast<Unk_MLevelCtrl*>(spLevel.operator->())->FUN_140eba120("setGrade", rows, nSumCur + DAT_143ab2930, 0);
        CStringW strGrade = StringFormat(L"{0} {1}", FUN_140298ea0(CStringW(L"s_mastery_housing")), FUN_14028dfa0(CStringW(L"s_mastery_housing_grade"), DAT_143ab291c));
        if (DAT_143ab291c == FUN_140933200()->FUN_140ebb020()) {
            reinterpret_cast<Unk_MLevelCtrl*>(spLevel.operator->())->FUN_140eb9e40("setPcGrade", 1, 1, CStringW(strGrade), 1);
        } else {
            MS2Ptr<MasteryInteriorInfo> spNext = FUN_140933200()->GetMastery((unsigned short)(DAT_143ab291c + 1));
            if (spNext)
                reinterpret_cast<Unk_MLevelCtrl*>(spLevel.operator->())->FUN_140eba380("setPcGrade", DAT_143ab2930, spNext->m_nValue, CStringW(strGrade), 0);
        }
    }
}

// @0x140eb2d10
void UIMasteryDialog::FUN_140eb2d10()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    if (m_30.IsNull())
        return;
    FUN_140eb0540();
    unsigned short nCur = DAT_143ab291c;
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList")) {
        spList->FUN_1422dd1d0();
        static_cast<ASObj*>(static_cast<AScript*>(spList.operator->()))->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_housing");
        spList->FUN_1407cb9c0("rowHeight", 0x39);
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xdb)) {
            Unk_MHouseMap& map = reinterpret_cast<Unk_MHouseMap&>(TSingleton<UGCCubeCategoryTable>::GetInstance()->GetBonusInteriors());
            for (POSITION pos = map.GetStartPosition(); pos; map.GetNext(pos)) {
                unsigned int nKey = map.GetKeyAt(pos);
                MS2Ptr<Unk_MHouseRec> spRec(map.GetValueAt(pos));
                ASObj row(2);
                reinterpret_cast<Unk_MObjSetter&>(row).FUN_140eba4a0("id", nKey);
                row.FUN_1409c48f0("level", spRec->m_nLevel);
                row.FUN_1407cbb20("name", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x32, nKey));
                row.FUN_1407cbbe0("active", nCur >= spRec->m_nLevel);
                spList->AddItem(row);
            }
        }
        FUN_140eb8b20();
    }
}

// @0x140eb3010
void UIMasteryDialog::FUN_140eb3010(int nId)
{
    if (m_30.IsNull())
        return;
    FUN_140eb0540();
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    UGCCubeCategoryTable::InteriorPtr spHouse = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(nId);
    if (reinterpret_cast<MS2Ptr<Unk_MHouseRec>&>(spHouse).IsNull())
        return;
    if (m_30.get()) {
        Unk_MFurnArray furn;
        TSingleton<CItemDataTable>::GetInstance()->GetHousingByCategory(nId, furn);
        qsort(furn.GetData(), furn.GetCount(), 0x10, &UIMasteryDialog::FUN_140eb8f40);
        ASDataProvider page(2);
        for (size_t i = 0; i < furn.GetCount(); i++) {
            MS2Ptr<ItemHousing> spFurn(furn[i]);
            MS2Ptr<CItemData> spDef = FUN_14053f870(spFurn->FUN_1405494e0());
            if (spDef == 0)
                continue;
            if (!spFurn->hasPrice && !DAT_143ab2e20.FUN_1408fbe90(spFurn->FUN_1405494e0()))
                continue;
            ASObj row(2);
            row.FUN_1409c0d20("id", spFurn->FUN_1405494e0());
            row.FUN_1407cba60("icon", spDef->GetIconPath());
            row.FUN_1407cbbe0("lock", FUN_140eb8cd0(MS2Ptr<ItemHousing>(spFurn)) == 0);
            reinterpret_cast<Unk_MPageArray&>(page).PushObj(row);
        }
        MPage(m_30)->Invoke("setPage", reinterpret_cast<const ASDataProvider&>(page));
    }
}

// @0x140eb3460
void UIMasteryDialog::FUN_140eb3460()
{
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a))
        return;
    int nTab = FUN_140eb8ac0();
    if (MS2Ptr<ASUIComponent> spCtrl = GetChild<ASUIComponent>("m_magicScrollControl")) {
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xd1))
            spCtrl->Invoke("setExpansion");
        int nG0 = TSingleton<CEnchantScrollTable>::GetInstance()->HasRecipe(nTab, 4);
        int nG1 = TSingleton<CEnchantScrollTable>::GetInstance()->HasRecipe(nTab, 5);
        int nG2 = TSingleton<CEnchantScrollTable>::GetInstance()->HasRecipe(nTab, 6);
        if (MS2Ptr<ASEventDispatcher> spGroup = spCtrl->FUN_140eb9cf0<ASEventDispatcher>("m_gradeGroup")) {
            int nSel = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spGroup->GetMember("selectedIndex")))->GetInt();
            if (nG1 == 0 && nSel == 1)
                spGroup->Invoke("setSelectedButtonByIndex", 0);
            if (nG2 == 0 && nSel == 2)
                spGroup->Invoke("setSelectedButtonByIndex", 0);
        }
        if (MS2Ptr<ASRadioButton> spT0 = spCtrl->FUN_140e159f0<ASRadioButton>("m_grade00"))
            spT0->vfunc_3(nG0);
        if (MS2Ptr<ASRadioButton> spT1 = spCtrl->FUN_140e159f0<ASRadioButton>("m_grade01"))
            spT1->vfunc_3(nG1);
        if (MS2Ptr<ASRadioButton> spT2 = spCtrl->FUN_140e159f0<ASRadioButton>("m_grade02"))
            spT2->vfunc_3(nG2);
    }
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList")) {
        spList->FUN_1422dd1d0();
        static_cast<ASObj*>(static_cast<AScript*>(spList.operator->()))->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_mastery");
        spList->FUN_1407cb9c0("rowHeight", 0x4c);
        int nSub = GetSelectedMagicScrollGrade();
        int nSlot = GetSelectedMagicScrollSlot();
        Unk_MScrollArray recs;
        TSingleton<CEnchantScrollTable>::GetInstance()->FindRecipes(nTab, nSlot, nSub, recs);
        qsort(recs.GetData(), recs.GetCount(), 0x10, &UIMasteryDialog::FUN_140eb9160);
        if (recs.GetCount() == 0) {
            FUN_140d74390(GetStringCommonByKey(L"s_mastery_magicscroll_no_recipe"), 0, Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::OnRestoreMagicScrollSelectionMsgBox));
            return;
        }
        for (size_t i = 0; i < recs.GetCount(); i++) {
            MS2Ptr<CEnchantScrollRecipe> spRec(recs[i]);
            if (spRec->m_nSlot != nSlot)
                continue;
            CStringW strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x35, spRec->m_nId), spRec->m_scroll.vfunc_o18_1());
            CStringW strState = FUN_14028dfa0(CStringW(L"s_mastery_magicscroll_list_state"), spRec->m_nMaxLv);
            ASObj row(2);
            row.FUN_1407cb9c0("id", spRec->m_nId);
            row.FUN_1407cbb20("name", CStringW(strName));
            row.FUN_1407cbb20("state", CStringW(strState));
            row.FUN_1407cb9c0("active", 1);
            row.FUN_1407cba60("icon", spRec->GetRewardName());
            row.FUN_1409adc90("grade", spRec->m_scroll.vfunc_o18_1());
            spList->AddItem(row);
        }
        if (MS2Ptr<ASUIComponent> spCtrl2 = GetChild<ASUIComponent>("m_magicScrollControl")) {
            if (MS2Ptr<ASEventDispatcher> spGrade = spCtrl2->FUN_140eb9cf0<ASEventDispatcher>("m_gradeGroup"))
                m_30c = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spGrade->GetMember("selectedIndex")))->GetInt();
            if (MS2Ptr<ASEventDispatcher> spSlot = spCtrl2->FUN_140eb9cf0<ASEventDispatcher>("m_slotGroup"))
                m_308 = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spSlot->GetMember("selectedIndex")))->GetInt();
        }
        FUN_140eb8b20();
    }
}

// @0x140eb4210
void UIMasteryDialog::FUN_140eb4210(int nId)
{
    if (m_30.IsNull())
        return;
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a))
        return;
    FUN_140eb0540();
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    MS2Ptr<CEnchantScrollRecipe> spRec = TSingleton<CEnchantScrollTable>::GetInstance()->FindRecipe(nId);
    if (spRec.IsNull())
        return;
    ASObj page(2);
    ItemEntity& res = spRec->m_scroll;
    page.FUN_1407cba60("binding0", m_reward.BindNewItem(res.m_itemId, res.vfunc_o18_1(), res.m_count));
    for (size_t i = 0; i < spRec->m_rewards.GetCount(); i++) {
        ItemEntity& rew = spRec->m_rewards[i];
        page.FUN_1407cba60(Unk_SocketFormat<unsigned __int64>("binding{0}", i + 1), m_reward.BindNewItem(rew.m_itemId, rew.vfunc_o18_1(), rew.m_count));
    }
    int bEnough = 1;
    for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
        Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
        if (ref == 0)
            continue;
        unsigned int nHave = 0;
        if (ref->m_b == 0)
            nHave = g_143ab2a90.FUN_140a5f180(ref->m_a, 0);
        else
            nHave = g_143ab2a90.FUN_140a5f7b0(ref->m_b, 0);
        unsigned int nNeed = ref->m_c;
        if (nHave < nNeed)
            bEnough = 0;
        CStringW strCnt = FUN_1419021b0(nHave, nNeed);
        int nRank = FUN_14053feb0(ref->m_a);
        ASObj req(2);
        req.FUN_1407cba60("binding", m_require.BindNewItem(ref->m_a, nRank, ref->m_c));
        req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
        page.FUN_1409eb270(Unk_SocketFormat<unsigned __int64>("require{0}", i), req);
    }
    int bWarn = 1;
    int nSlot = GetSelectedMagicScrollSlot();
    if (nSlot == 1 || nSlot == 3 || nSlot == 2)
        bWarn = (nSlot == FUN_140eb6870());
    CStringW strName = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x35, nId), spRec->m_scroll.vfunc_o18_1());
    CStringW strState = FUN_14028dfa0(CStringW(L"s_mastery_magicscroll_list_state"), spRec->m_nMaxLv);
    page.FUN_1407cb9c0("id", nId);
    page.FUN_1407cbb20("name", CStringW(strName));
    page.FUN_1407cba60("icon", spRec->GetRewardName());
    page.FUN_1409adc90("grade", spRec->m_scroll.vfunc_o18_1());
    page.FUN_1409c1180("meso", spRec->m_nMeso);
    page.FUN_1407cbb20("mastery", CStringW(strState));
    page.FUN_1407cbbe0("enabled", bEnough && !m_craft.HasTotal());
    page.FUN_1409c0dc0("goto", bWarn ? "normal" : "warn");
    page.FUN_1407cbbe0("debug", ((class CInputKeyHandler*)(class Unk_MDebug*)(((class Unk_MDebug*)FUN_14025e7c0())))->IsDebugMode());
    m_30->Invoke("setPage", page);
}

// @0x140eb4ba0
void UIMasteryDialog::FUN_140eb4ba0()
{
    if (GetMainTabIndex() != 3)
        return;
    FUN_140eb4210(m_nSelected);
}

// @0x140eb4be0
void UIMasteryDialog::FUN_140eb4be0()
{
    FUN_140eafde0();
    FUN_140eb7e30();
}

// @0x140eb4c10
void UIMasteryDialog::FUN_140eb4c10(int nType, int bRefreshTabs)
{
    if (!FUN_141924630())
        return;
    if (bRefreshTabs)
        FUN_140eb4be0();
    if (nType == FUN_140eb8a90())
        SetPendingSub(nType);
}

// @0x140eb4c70
bool UIMasteryDialog::OnRecipeCraftCountInput(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    CancelCraft();
    CStringW strInput = box.FUN_141a02d50();
    strInput.Remove(L',');
    m_craft.m_nType = 0;
    m_craft.m_nTotal = FUN_1407181a0(strInput);
    m_craft.m_nId = box.FUN_141a02e50(0, 0);
    m_craft.m_nDone = 1;
    m_craft.m_nPending = 1;
    return true;
}

// @0x140eb4d40
bool UIMasteryDialog::OnMagicScrollCraftConfirm(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    CancelCraft();
    CStringW strInput = box.FUN_141a02d50();
    strInput.Remove(L',');
    m_craft.m_nType = 1;
    m_craft.m_nTotal = FUN_1407181a0(strInput);
    m_craft.m_nId = box.FUN_141a02e50(0, 0);
    m_craft.m_nDone = 1;
    m_craft.m_nPending = 1;
    FUN_140eb4210(m_craft.m_nId);
    return true;
}

// @0x140eb4e30
bool UIMasteryDialog::OnRestoreMagicScrollSelectionMsgBox(int nResult, const CMsgBoxData&)
{
    if (nResult != 0)
        return true;
    if (MS2Ptr<ASUIComponent> spCtrl = GetChild<ASUIComponent>("m_magicScrollControl")) {
        spCtrl->Invoke("setSelectedSlotIndex", m_308);
        spCtrl->Invoke("setSelectedGradeIndex", m_30c);
    }
    FUN_140eb3460();
    return true;
}

// @0x140eb4f60
void UIMasteryDialog::vfunc_2(void* pArg)
{
    if (vfunc_55()) {
    } else {
        FUN_140eb6660(pArg);
    }
}

// @0x140eb4fd0
void UIMasteryDialog::vfunc_4(void* pArg, int)
{
    if (vfunc_55()) {
    } else {
        FUN_140eb6660(pArg);
    }
}

// @0x140eb5040
int UIMasteryDialog::GetMainTabIndex()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return -1;
    if (MS2Ptr<ASEventDispatcher> spTab = FindControl("m_mainTab"))
        return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spTab->GetMember("selectedIndex")))->GetInt();
    return -1;
}

// @0x140eb5150
int UIMasteryDialog::GetSubTabIndex()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return -1;
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02870("m_subTab"))
        return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spTab->GetMember("selectedIndex")))->GetInt();
    return -1;
}

// @0x140eb5260
void UIMasteryDialog::SetPendingSub(int nType)
{
    if (vfunc_55())
        return;
    if (FUN_140eb8a90() != nType)
        return;
    m_nPendingSub = nType;
}

// @0x140eb52c0
void UIMasteryDialog::SetPendingList(int nType)
{
    if (vfunc_55())
        return;
    if (FUN_140eb8a90() != nType)
        return;
    m_nPendingList = nType;
}

// @0x140eb5320
void UIMasteryDialog::OnDamagedMyPC(NotifyObject* pNotify)
{
    NotifyDamagedMyPC* p = dynamic_cast<NotifyDamagedMyPC*>(pNotify);
    if (p) {
        if (!p->m_pDamage)
            return;
        if (p->m_pDamage->GetTotalDamage() < 0)
            CancelCraft();
    }
}

// @0x140eb53a0
void UIMasteryDialog::FUN_140eb53a0()
{
    switch (GetMainTabIndex()) {
    case 0:
    case 1:
        FUN_140eb05b0(FUN_140eb8a90(), false);
        break;
    case 2:
        switch (FUN_140eb86b0()) {
        case 8:
            FUN_140eb2460();
            break;
        case 9:
            FUN_140eb05b0(FUN_140eb8a90(), false);
            break;
        }
        break;
    case 3:
        FUN_140eb3460();
        break;
    }
}

// @0x140eb5450
void UIMasteryDialog::FUN_140eb5450(int nIndex)
{
    switch (GetMainTabIndex()) {
    case 0:
    case 1:
        FUN_140eb1770(nIndex, false);
        break;
    case 2:
        switch (FUN_140eb86b0()) {
        case 8:
            FUN_140eb3010(nIndex);
            break;
        case 9:
            FUN_140eb1770(nIndex, false);
            break;
        }
        break;
    case 3:
        FUN_140eb4210(nIndex);
        break;
    }
    m_nSelected = nIndex;
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList"))
        m_268[FUN_140eb86b0()] = spList->GetSelectedIndex();
}

// @0x140eb55e0
void UIMasteryDialog::FUN_140eb55e0(int nId)
{
    MS2Ptr<CMasteryReceipe> spRec = FUN_1409670c0()->Find(nId);
    if (spRec.IsNull())
        return;
    int nPoints = ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d470(spRec->m_nId);
    if (nPoints != 0) {
        ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d710((Unk_MasteryResult)nPoints);
        return;
    }
    if (spRec->m_rewards.GetCount() > 0) {
        ItemEntity& rew = spRec->m_rewards[0];
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(rew.m_itemId, rew.vfunc_o18_1(), 0))
            return;
        ATL::CAtlArray<ItemEntity> ingredients;
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            ItemEntity ent;
            ent.m_itemId = ref->FUN_14026b500();
            ent.SetRank(FUN_14053feb0(ent.m_itemId));
            ent.m_count = CalcIngredientCount(spRec->m_nType, spRec->m_nRequireMastery, ref->m_c);
            ingredients.Add(ent);
        }
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x23, GetStringCommonByKey(L"s_craft_messagebox_desc"), static_cast<IMessageListener*>(this), CStringW(L""))) {
            spBox->Append(spRec->m_nId);
            ((class CMsgBoxData*)(class CMsgBoxData*)(spBox.get()))->SetTitle(GetStringCommonByKey(L"s_craft_messagebox_title"));
            spBox->SetButtonLabels(GetStringCommonByKey(L"s_word_cancel"), GetStringCommonByKey(L"s_word_craft"), L"");
            spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 1, FUN_140eb6d40(0, spRec->m_nId), spRec->m_nRequireMeso, 1);
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a02a30(ingredients);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::OnRecipeCraftCountInput));
            FUN_140d73c60(spBox);
        }
    }
}

// @0x140eb5e30
void UIMasteryDialog::FUN_140eb5e30(int nId)
{
    FUN_140eb55e0(nId);
}

// @0x140eb5e60
void UIMasteryDialog::FUN_140eb5e60(int nId)
{
    MS2Ptr<CEnchantScrollRecipe> spRec = TSingleton<CEnchantScrollTable>::GetInstance()->FindRecipe(nId);
    if (spRec.IsNull())
        return;
    if (DAT_143ab2898 < spRec->m_nMeso) {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    if (spRec->m_scroll.m_itemId != 0 || spRec->m_rewards.GetCount() > 0) {
        ItemEntity& rew = spRec->m_scroll;
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(rew.m_itemId, rew.vfunc_o18_1(), 0))
            return;
        ATL::CAtlArray<ItemEntity> ingredients;
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            if (ref == 0)
                continue;
            ItemEntity ent;
            ent.m_itemId = ref->m_a;
            ent.m_count = ref->m_c;
            ent.SetRank(FUN_14053feb0(ref->m_a));
            ingredients.Add(ent);
        }
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x23, GetStringCommonByKey(L"s_magicscroll_craft_messagebox_desc"), static_cast<IMessageListener*>(this), CStringW(L""))) {
            spBox->Append(spRec->m_nId);
            ((class CMsgBoxData*)(class CMsgBoxData*)(spBox.get()))->SetTitle(GetStringCommonByKey(L"s_magicscroll_craft_messagebox_title"));
            spBox->SetButtonLabels(GetStringCommonByKey(L"s_word_cancel"), GetStringCommonByKey(L"s_magicscroll_word_craft"), L"");
            spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 1, FUN_140eb6d40(1, spRec->m_nId), (int)spRec->m_nMeso, 1);
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a02a30(ingredients);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::OnMagicScrollCraftConfirm));
            FUN_140d73c60(spBox);
        }
    }
}

// @0x140eb6660
void UIMasteryDialog::FUN_140eb6660(void* pArg)
{
    if (!pArg)
        return;
    int nItemId = static_cast<CItem*>(pArg)->FUN_1405276c0();
    int nTab = GetMainTabIndex();
    if (nTab == 1) {
        int nType = FUN_140eb8a90();
        if (FUN_1409670c0()->HasTypeIngredient(nType, nItemId) != 0)
            SetPendingList(nType);
    } else if (nTab == 3) {
        if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a))
            return;
        {
            MS2Ptr<CEnchantScrollRecipe> spRec = TSingleton<CEnchantScrollTable>::GetInstance()->FindRecipe(m_nSelected);
            if (spRec.get()) {
                int bFound = 0;
                for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
                    Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
                    if (ref == 0)
                        continue;
                    if (ref->m_b != 0 && static_cast<CItem*>(pArg)->HasStringTag(ref->m_b)) {
                        bFound = 1;
                        break;
                    }
                    if (ref->m_a == nItemId) {
                        bFound = 1;
                        break;
                    }
                }
                if (bFound)
                    FUN_140eb4210(m_nSelected);
            }
        }
    }
}

// @0x140eb6870
int UIMasteryDialog::FUN_140eb6870()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return 0;
    MS2Ptr<JobData> spJob = TSingleton<JobTable>::GetInstance()->GetJobData(reinterpret_cast<PC*>(pPc)->FUN_141654700());
    if (spJob.IsNull())
        return 0;
    return spJob->m_defaultWeaponSlot;
}

// @0x140eb6920
void UIMasteryDialog::FUN_140eb6920(int nType, int nIndex, ASObj& obj)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return;
    unsigned int nNeed = FUN_1409670c0()->Value(nType, nIndex);
    unsigned int nId = FUN_1409670c0()->MakeID(nType, nIndex);
    obj.FUN_1409c0d20("id", nId);
    obj.FUN_1409c0d20("level", nNeed);
    obj.FUN_1407cbb20("levelStr", FUN_1409670c0()->GradeName(nType, nIndex));
    int nFlag = 0;
    DAT_143ab31a0.Lookup(nId, nFlag);
    CString strState;
    if (nFlag != 0 || ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->HasRewards(nType, nIndex) == 0)
        strState = "inactive";
    else
        strState = (reinterpret_cast<PC*>(pPc)->GetMastery(nType) >= nNeed) ? "active" : "lock";
    obj.FUN_1407cba60("state", CString(strState));
    Unk_MItemArray items;
    FUN_1409670c0()->Rewards(nId, reinterpret_cast<PC*>(pPc)->FUN_141654700(), items);
    if (items.GetCount() > 0) {
        MS2Ptr<ItemEntity> spItem0(items[0]);
        obj.FUN_1407cba60("binding", m_mastery.BindNewItem(spItem0->m_itemId, spItem0->vfunc_o18_1(), spItem0->m_count));
    }
}

// @0x140eb6c80
void UIMasteryDialog::CancelCraft()
{
    if (m_craft.HasTotal()) {
        Unk_MCastingBar* pBar = ((class Unk_MCastingBar*)FUN_140ac2270(0x4e72));
        if (pBar)
            pBar->FUN_1418e1390();
        BOOL bSame = m_nSelected == m_craft.m_nId;
        m_craft.FUN_140eadda0();
        if (bSame)
            FUN_140eb5450(m_nSelected);
    }
}

// @0x140eb6d40
int UIMasteryDialog::FUN_140eb6d40(int nKind, int nId)
{
    int nMax = 1000;
    if (nKind == 0) {
        MS2Ptr<CMasteryReceipe> spRec = FUN_1409670c0()->Find(nId);
        if (spRec.IsNull())
            return 0;
        if (spRec->m_nRequireMeso != 0) {
            __int64 nByMeso = DAT_143ab2898 / spRec->m_nRequireMeso;
            if (nByMeso < nMax)
                nMax = (int)nByMeso;
        }
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            int nHave = 0;
            int nNeed = CalcIngredientCount(spRec->m_nType, spRec->m_nRequireMastery, ref->m_c);
            if (ref->m_b != 0)
                nHave = g_143ab2a90.FUN_140a5f780(ref->m_b, 0);
            else
                nHave = g_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
            int nCan = nHave / nNeed;
            nMax = (std::min)(nCan, nMax);
        }
    } else if (nKind == 1) {
        MS2Ptr<CEnchantScrollRecipe> spRec = TSingleton<CEnchantScrollTable>::GetInstance()->FindRecipe(nId);
        if (spRec.IsNull())
            return 0;
        if (spRec->m_nMeso != 0) {
            __int64 nByMeso = DAT_143ab2898 / spRec->m_nMeso;
            if (nByMeso < nMax)
                nMax = (int)nByMeso;
        }
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            int nHave = 0;
            if (ref->m_b != 0) {
                nHave = g_143ab2a90.FUN_140a5f7b0(ref->m_b, 0);
            } else {
                int nRank = FUN_14053feb0(ref->m_a);
                nHave = g_143ab2a90.FUN_140a5f180(ref->m_a, nRank);
            }
            int nNeed = ref->m_c;
            int nCan = nHave / nNeed;
            nMax = (std::min)(nCan, nMax);
        }
    } else {
        MS2_ASSERT_AT(0x433, 0);
        return 0;
    }
    return nMax;
}

// @0x140eb71a0
CStringW UIMasteryDialog::FUN_140eb71a0(MS2Ptr<CMasteryReceipe> spRec)
{
    CStringW strErr;
    if (HasRequiredLevel(MS2Ptr<CMasteryReceipe>(spRec)) == 0)
        strErr = FUN_14028dfa0(CStringW(L"s_mastery_need_level"), spRec->m_nLevel);
    if (GetMyMastery(spRec->m_nType) < spRec->m_nRequireMastery) {
        int nGrade = FUN_1409670c0()->Grade(spRec->m_nType, spRec->m_nRequireMastery);
        CStringW strGrade = FUN_1409670c0()->GradeName(spRec->m_nType, nGrade);
        CStringW strNeed = FUN_14028dfa0(L"s_mastery_need_mastery", strGrade);
        if (strErr.GetLength() != 0)
            return StringFormat(L"{0}, {1}", strErr, strNeed);
        return strNeed;
    }
    if (strErr.GetLength() > 0)
        return strErr;
    if (FUN_1409670c0()->IsProduction(MS2Ptr<CMasteryReceipe>(spRec))) {
        CStringW strHome;
        if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d2f10()) {
            switch (spRec->m_nType) {
            case 5:
            case 6:
                strHome = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5640() ? GetStringCommonByKey(L"s_mastery_myhome") : GetStringCommonByKey(L"s_mastery_otherhome");
            }
            return StringFormat(L"{0} {1}", strHome, FUN_1409670c0()->SuccessDescription(spRec->m_nType, spRec->m_nId, 1));
        }
        return FUN_1409670c0()->SuccessDescription(spRec->m_nType, spRec->m_nId, 1);
    }
    int nCount = FUN_140eb6d40(0, spRec->m_nId);
    if (nCount == 1000)
        return FUN_14028dfa0(CStringW(L"s_mastery_manufacture_count_max"), nCount);
    return FUN_14028dfa0(CStringW(L"s_mastery_manufacture_count"), nCount);
}

// @0x140eb79b0
int UIMasteryDialog::CalcAdjustedItemCount(int nType, unsigned int nNeedMastery, ItemEntity* pEntry)
{
    int nCount = 0;
    if (FUN_1409670c0()->IsProductionType(nType))
        nCount = ((class CLua*)FUN_1401c0db0())->CalcGatheringReceipeRewardItemCount(pEntry->m_count, nNeedMastery, GetMyMastery(nType));
    else
        nCount = pEntry->m_count;
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return nCount;
    float fStat = 0;
    switch (nType) {
    case 3:
        fStat = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x43);
        break;
    case 5:
        fStat = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x44);
        break;
    case 4:
        fStat = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x47);
        break;
    case 6:
        fStat = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x48);
        break;
    }
    float fOne = 1.0f;
    nCount = FUN_1406198a0(nCount, 1.0f + (std::min)(fStat, fOne));
    return nCount;
}

// @0x140eb7b40
unsigned int UIMasteryDialog::CalcIngredientCount(int nType, int nNeedMastery, unsigned int nCount)
{
    if (FUN_1409670c0()->IsOther(nType)) {
        return ((class CLua*)FUN_1401c0db0())->CalcCraftReceipeRequireItemCount(nCount, nNeedMastery, GetMyMastery(nType));
    }
    return nCount;
}

// @0x140eb7bb0
unsigned int UIMasteryDialog::GetMyMastery(int nType)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return 0;
    return reinterpret_cast<PC*>(pPc)->GetMastery(nType);
}

// @0x140eb7c00
void UIMasteryDialog::UpdateMasteryGrade(int nType)
{
    FUN_1409670c0()->Grade(nType, GetMyMastery(nType));
}

// @0x140eb7c50
CStringW UIMasteryDialog::GetMasteryTabName(int nType)
{
    CStringW strName = FUN_1409670c0()->TypeName(nType);
    int nRewards = ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(nType);
    if (nRewards != 0)
        return FUN_14028dfa0(CStringW(L"s_mastery_subtab_mastery_name_and_reward"), strName, nRewards);
    return strName;
}

// @0x140eb7d40
CStringW UIMasteryDialog::GetHousingTabName()
{
    CStringW strName = GetStringCommonByKey(L"s_mastery_housing");
    int nRewards = FUN_140930e10();
    if (nRewards != 0)
        return FUN_14028dfa0(CStringW(L"s_mastery_subtab_mastery_name_and_reward"), strName, nRewards);
    return strName;
}

// @0x140eb7e30
void UIMasteryDialog::FUN_140eb7e30()
{
    if (m_30.IsNull())
        return;
    int nCount = 0;
    nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(3);
    nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(5);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
        nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(4);
        nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(6);
    }
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 0, 0 < nCount);
    nCount = 0;
    nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(7);
    nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(8);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
        nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(9);
        nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(10);
    }
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 1, 0 < nCount);
    nCount = FUN_140930e10();
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x8d))
        nCount += ((class Unk_MPoints*)TSingleton<CMasteryManager>::GetInstance())->CountClaimableRewardLevels(0xb);
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 2, 0 < nCount);
    MPage(m_30)->FUN_140eba200("setMainTabReward", 3, 0);
}

// @0x140eb8120
int UIMasteryDialog::FUN_140eb8120(MS2Ptr<CMasteryReceipe> spRec)
{
    if (spRec == 0)
        return 0;
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return 0;
    int nValue = FUN_1409670c0()->Factor(spRec->m_nId, reinterpret_cast<PC*>(pPc)->GetMastery(spRec->m_nType));
    float fBonus = 0.0f;
    switch (spRec->m_nType) {
    case 7:
        fBonus = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x45);
        break;
    case 8:
        fBonus = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x46);
        break;
    case 9:
        fBonus = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x49);
        break;
    case 10:
        fBonus = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x4a);
        break;
    }
    nValue = (int)FUN_1404820b0(nValue, 1.0f + fBonus);
    return nValue;
}

// @0x140eb82e0
int UIMasteryDialog::GetSelectedMagicScrollSlot()
{
    if (MS2Ptr<ASUIComponent> spCtrl = GetChild<ASUIComponent>("m_magicScrollControl")) {
        int nSlot = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spCtrl->Invoke("getSelectedSlotIndex")))->GetInt() + 1;
        if (nSlot < 0)
            nSlot = 0;
        if (nSlot > m_2f8)
            nSlot = m_2f8;
        return nSlot;
    }
    return 1;
}

// @0x140eb8410
int UIMasteryDialog::GetSelectedMagicScrollGrade()
{
    if (MS2Ptr<ASUIComponent> spCtrl = GetChild<ASUIComponent>("m_magicScrollControl")) {
        int nGrade = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spCtrl->Invoke("getSelectedGradeIndex")))->GetInt();
        if (nGrade == 0)
            return 4;
        if (nGrade == 1)
            return 5;
        if (nGrade == 2)
            return 6;
    }
    return 0;
}

// @0x140eb8550
int UIMasteryDialog::HasRequiredLevel(MS2Ptr<CMasteryReceipe> spRec)
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPc)
        return 0;
    if (spRec->m_nLevel != 0)
        return (unsigned short)pPc->vfunc_78() >= spRec->m_nLevel;
    return 1;
}

// @0x140eb8630
int UIMasteryDialog::GetCachedTypeValue(int nType)
{
    if (nType < 0 || nType >= 0xc)
        return 0;
    return m_310[nType];
}

// @0x140eb8670
void UIMasteryDialog::SetTypeValue(int nType, int nValue)
{
    if (nType < 0 || nType >= 0xc)
        return;
    m_310[nType] = nValue;
}

// @0x140eb86b0
int UIMasteryDialog::FUN_140eb86b0()
{
    int nTab = GetMainTabIndex();
    int nSub = GetSubTabIndex();
    if (nSub < 0)
        return 0xe;
    ATL::CAtlArray<int> slots;
    if (nTab == 0) {
        slots.Add(0);
        slots.Add(1);
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
            slots.Add(2);
            slots.Add(3);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 1) {
        slots.Add(5);
        slots.Add(4);
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x59)) {
            slots.Add(6);
            slots.Add(7);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 2) {
        slots.Add(8);
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x8d))
            slots.Add(9);
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 3) {
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5a)) {
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7c))
                slots.Add(10);
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7d))
                slots.Add(0xb);
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7e))
                slots.Add(0xc);
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x7f))
                slots.Add(0xd);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    }
    return 0xe;
}

// @0x140eb89e0
int UIMasteryDialog::GetTypeForSlot(int nSlot)
{
    switch (nSlot) {
    case 0:
        return 3;
    case 1:
        return 5;
    case 4:
        return 8;
    case 5:
        return 7;
    case 2:
        return 4;
    case 3:
        return 6;
    case 6:
        return 9;
    case 7:
        return 10;
    case 9:
        return 0xb;
    default:
        return 0;
    }
}

// @0x140eb8a90
int UIMasteryDialog::FUN_140eb8a90()
{
    return GetTypeForSlot(FUN_140eb86b0());
}

// @0x140eb8ac0
int UIMasteryDialog::FUN_140eb8ac0()
{
    switch (FUN_140eb86b0()) {
    case 10:
        return 1;
    case 0xb:
        return 2;
    case 0xc:
        return 3;
    case 0xd:
        return 4;
    }
    return 0;
}

// @0x140eb8b20
void UIMasteryDialog::FUN_140eb8b20()
{
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_objectList")) {
        m_304 = 1;
        int nSlot = FUN_140eb86b0();
        spList->SetSelectedIndex(-1);
        spList->vfunc_24(true);
        spList->SetSelectedIndex(m_268[nSlot]);
        spList->vfunc_24(true);
        spList->FUN_1422e17f0(m_scroll[nSlot]);
        spList->vfunc_24(true);
        m_304 = 0;
    }
}

// @0x140eb8cd0
int FUN_140eb8cd0(MS2Ptr<ItemHousing> spFurn)
{
    if (spFurn->priceCount == 3)
        return 1;
    if (DAT_143ab291c < spFurn->interiorLevel)
        return 0;
    UGCCubeCategoryTable::InteriorPtr spHouse = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(spFurn->categoryIndex);
    if (reinterpret_cast<MS2Ptr<Unk_MHouseRec>&>(spHouse).IsNull())
        return 0;
    if (DAT_143ab291c < spHouse->m_nRequireLevel)
        return 0;
    if (spFurn->trophyID == 0)
        return 1;
    return ((class CAchieveManager*)FUN_1406c7600())->IsGradeCleared(spFurn->trophyID, spFurn->trophyLevel);
}

// @0x140eb8eb0
int FUN_140eb8eb0(MS2Ptr<ItemHousing> spFurn)
{
    if (spFurn->priceCount == 1)
        return 1;
    if (spFurn->priceCount == 3)
        return 2;
    return 3;
}

// @0x140eb8f40
int UIMasteryDialog::FUN_140eb8f40(const void* pA, const void* pB)
{
    MS2Ptr<ItemHousing> spA = *(const MS2Ptr<ItemHousing>*)pA;
    MS2Ptr<ItemHousing> spB = *(const MS2Ptr<ItemHousing>*)pB;
    int nLockA = FUN_140eb8cd0(spA);
    int nLockB = FUN_140eb8cd0(spB);
    if (nLockA == nLockB) {
        int nKindB;
        int nKindA = FUN_140eb8eb0(spA);
        nKindB = FUN_140eb8eb0(spB);
        if (nKindA == nKindB)
            return spA->price > spB->price ? 1 : -1;
        return nKindA > nKindB ? 1 : -1;
    }
    return nLockA != 0 ? -1 : 1;
}

// @0x140eb9160
int UIMasteryDialog::FUN_140eb9160(const void* pA, const void* pB)
{
    MS2Ptr<CEnchantScrollRecipe> spA = *(const MS2Ptr<CEnchantScrollRecipe>*)pA;
    MS2Ptr<CEnchantScrollRecipe> spB = *(const MS2Ptr<CEnchantScrollRecipe>*)pB;
    if (spA->m_nMaxLv == spB->m_nMaxLv) {
        MS2Ptr<CEnchantScrollData> spDefA = TSingleton<CEnchantScrollTable>::GetInstance()->FindScroll(spA->m_nScrollId);
        MS2Ptr<CEnchantScrollData> spDefB = TSingleton<CEnchantScrollTable>::GetInstance()->FindScroll(spB->m_nScrollId);
        if (spDefA.IsNull() || spDefB.IsNull())
            return -1;
        return spDefA->m_nGrade < spDefB->m_nGrade ? -1 : 1;
    }
    return spA->m_nMaxLv < spB->m_nMaxLv ? -1 : 1;
}


// ---- the unit's tail: in-unit AS glue and the helper COMDATs (bodies per element type) ----
struct Unk_MRawPtr { void* m_vt; void* m_p; };                           // an MS2Ptr<T> seen as raw memory
struct Unk_MMapNode { char m_pad[0x18]; Unk_MMapNode* m_pNext; };
struct Unk_MMapRaw { Unk_MMapNode** m_ppBins; unsigned __int64 m_nElements; unsigned int m_nBins; };
class Unk_MSink
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(void* a, int b, void* c);
};
struct Unk_MSinkRef { Unk_MSink* m_pObj; void* m_p8; void* m_pIdx; };

// @0x140eb9620
MS2Ptr<ASEventDispatcher> FUN_140eb9620(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASEventDispatcher> sp(new ASEventDispatcher(v, nMovieId));
    return sp;
}

// @0x140eb9cf0
template<> MS2Ptr<ASEventDispatcher> AScript::FUN_140eb9cf0<ASEventDispatcher>(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(v))->IsObject())
        return FUN_140eb9620(m_nMovieId, v);
    return MS2Ptr<ASEventDispatcher>(0);
}

// @0x140eb9db0
MS2Ptr<ASEventDispatcher> UIMasteryDialog::FindControl(const CString& strName)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0))
        return MS2Ptr<ASEventDispatcher>(0);
    return reinterpret_cast<AScript*>(m_30.get())->FUN_140eb9cf0<ASEventDispatcher>(strName);
}

// @0x140eb9e40
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eb9e40(const char* szMethod, int a1, int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    FUN_1422bcea0(&args[2], a3);
    FUN_1422bccb0(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eb9f50
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eb9f50(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcd10(&args[0], a1);
    FUN_1422bcd10(&args[1], a2);
    FUN_1422bcea0(&args[2], a3);
    FUN_1422bccb0(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba060
Scaleform::GFx::Value AScript::FUN_140eba060(const char* szMethod, const AScript& a1, unsigned int a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bce40(&args[0], a1);
    FUN_1422bcd10(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba120
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eba120(const char* szMethod, const AScript& a1, unsigned __int64 a2, int a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bce40(&args[0], a1);
    FUN_1422bcdd0(&args[1], a2);
    FUN_1422bccb0(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba200
Scaleform::GFx::Value Unk_MInvoker::FUN_140eba200(const char* szMethod, int a1, int a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba2c0
Scaleform::GFx::Value Unk_MInvoker::FUN_140eba2c0(const char* szMethod, int a1, bool a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bcce0(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba380
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eba380(const char* szMethod, unsigned __int64 a1, unsigned int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcdd0(&args[0], a1);
    FUN_1422bcd10(&args[1], a2);
    FUN_1422bcea0(&args[2], a3);
    FUN_1422bccb0(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba4a0
void Unk_MObjSetter::FUN_140eba4a0(const char* szName, unsigned int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x140eba610
unsigned __int64 FUN_140eba610(const void* p)
{
    return fmt::internal::MakeValue<fmt::BasicFormatter<char>>::type((char const*)(p));
}

// @0x140eba870
Unk_MRawPtr* FUN_140eba870(Unk_MRawPtr* a, Unk_MRawPtr* b)
{
    a->m_p = b->m_p;
    b->m_p = 0;
    return a;
}

// @0x140eba8a0
Unk_MRawPtr* FUN_140eba8a0(Unk_MRawPtr* a, int)
{
    a->m_p = 0;
    return a;
}

// @0x140ebabb0
void* FUN_140ebabb0(Unk_MRawPtr* a)
{
    return a->m_p;
}

// @0x140ebac50
void* FUN_140ebac50(void* p, unsigned int nFlags)
{
    reinterpret_cast<MS2Ptr<CEnchantScrollRecipe>*>(p)->MS2Ptr<CEnchantScrollRecipe>::~MS2Ptr();
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// @0x140ebac90
void* FUN_140ebac90(void* p, unsigned int nFlags)
{
    reinterpret_cast<MS2Ptr<CMasteryReceipe>*>(p)->MS2Ptr<CMasteryReceipe>::~MS2Ptr();
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// @0x140ebacd0
void* FUN_140ebacd0(void* p, unsigned int nFlags)
{
    reinterpret_cast<MS2Ptr<ItemHousing>*>(p)->MS2Ptr<ItemHousing>::~MS2Ptr();
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// 0x140ebae70 = UGCCubeCategoryTable::InteriorMap::FindNextNode (private), 0x140ebb030 = its GetNext:
// the explicit instantiation of the real GetNext below (exe name, MS2-PIN at EOF) emits both, and the
// CNode::GetHash (0x140889fd0) FindNextNode calls.
template UGCCubeCategoryTable::InteriorMap::CPair* UGCCubeCategoryTable::InteriorMap::GetNext(POSITION& pos) throw();















// @0x140ebaf50
void* FUN_140ebaf50(void** pArray)
{
    return *pArray;
}

// @0x140ebaf60
void* FUN_140ebaf60(void** pArray)
{
    return *pArray;
}

// @0x140ebaf70
void FUN_140ebaf70(Unk_MSinkRef* p, int a, void* b)
{
    p->m_pObj->s12(p->m_pIdx, a, b);
}

// @0x140ebafb0
void* FUN_140ebafb0(void*, void* p)
{
    do {
        int nCond = !!(p != 0);
        do {} while (0);
        if (!nCond)
            ATL::AtlThrowImpl(0x80004005);
    } while (0);
    void* pNode = p;
    return pNode;
}

// @0x140ebb020
int CMasteryInteriorTable::FUN_140ebb020()
{
    return m_nMaxGrade;
}

// (0x140ebb030 GetNext: see the explicit instantiation above)








// @0x140ebb080
Unk_MMapNode* FUN_140ebb080(Unk_MMapRaw* pMap);
bool FUN_140ebb1b0(Unk_MMapRaw* pMap);
Unk_MMapNode* FUN_140ebb080(Unk_MMapRaw* pMap)
{
    if (FUN_140ebb1b0(pMap))
        return 0;
    for (unsigned int i = 0; i < pMap->m_nBins; i++) {
        if (pMap->m_ppBins[i] != 0)
            return pMap->m_ppBins[i];
    }
    return 0;
}

// @0x140ebb100
void* FUN_140ebb100(void*, char* p)
{
    do {
        int nCond = !!(p != 0);
        do {} while (0);
        if (!nCond)
            ATL::AtlThrowImpl(0x80004005);
    } while (0);
    char* pNode = p;
    return pNode + 8;
}

// @0x140ebb170
bool FUN_140ebb170(const Scaleform::GFx::Value* v)
{
    return v->GetType() == 9;
}

// @0x140ebb1b0
bool FUN_140ebb1b0(Unk_MMapRaw* pMap)
{
    return pMap->m_nElements == 0;
}

// @0x140ebb1e0
bool FUN_140ebb1e0(const Scaleform::GFx::Value* v)
{
    return v->GetType() == 3;
}


// ---- hooks ----
MS2_REPLACE_METHOD(0x140EAE470, UIMasteryDialog, GetTypeName, 61, 0xA6827744);
MS2_REPLACE_METHOD(0x140EAE4C0, UIMasteryDialog, vfunc_65, 77, 0x453D55F6);
MS2_REPLACE_METHOD(0x140EAE520, UIMasteryDialog, vfunc_67, 877, 0x92A97E57);
MS2_REPLACE_METHOD(0x140EAE8A0, UIMasteryDialog, OnLoadComplete, 1128, 0xDFE59100);
MS2_REPLACE_METHOD(0x140EAED30, UIMasteryDialog, vfunc_49, 854, 0xCABA0319);
MS2_REPLACE_METHOD(0x140EAF090, UIMasteryDialog, vfunc_28, 1909, 0x1C41E7B5);
MS2_REPLACE_METHOD(0x140EAFA50, UIMasteryDialog, vfunc_72, 854, 0x26543527);
MS2_REPLACE_METHOD(0x140EAFDB0, UIMasteryDialog, SetMainTab, 30, 0xCCD60FF0);
MS2_REPLACE_METHOD(0x140EAFDE0, UIMasteryDialog, FUN_140eafde0, 1873, 0xB1D4732E);
MS2_REPLACE_METHOD(0x140EB0540, UIMasteryDialog, FUN_140eb0540, 99, 0xC5E0DBBE);
MS2_REPLACE_METHOD(0x140EB05B0, UIMasteryDialog, FUN_140eb05b0, 81, 0x46902322);
MS2_REPLACE_METHOD(0x140EB0610, UIMasteryDialog, FUN_140eb0610, 1491, 0x7BE87C52);
MS2_REPLACE_METHOD(0x140EB0BF0, UIMasteryDialog, FUN_140eb0bf0, 415, 0xF903DA28);
MS2_REPLACE_METHOD(0x140EB0DA0, UIMasteryDialog, FUN_140eb0da0, 2498, 0x789089B1);
MS2_REPLACE_METHOD(0x140EB1770, UIMasteryDialog, FUN_140eb1770, 3301, 0xC0091B5B);
MS2_REPLACE_METHOD(0x140EB2460, UIMasteryDialog, FUN_140eb2460, 51, 0x0C8FF59D);
MS2_REPLACE_METHOD(0x140EB24A0, UIMasteryDialog, FUN_140eb24a0, 2139, 0xCA371192);
MS2_REPLACE_METHOD(0x140EB2D10, UIMasteryDialog, FUN_140eb2d10, 760, 0xD85E09ED);
MS2_REPLACE_METHOD(0x140EB3010, UIMasteryDialog, FUN_140eb3010, 1085, 0x50FFDE62);
MS2_REPLACE_METHOD(0x140EB3460, UIMasteryDialog, FUN_140eb3460, 3498, 0x8881EAB6);
MS2_REPLACE_METHOD(0x140EB4210, UIMasteryDialog, FUN_140eb4210, 2430, 0x488FEEFD);
MS2_REPLACE_METHOD(0x140EB4BA0, UIMasteryDialog, FUN_140eb4ba0, 52, 0x51EBCE4F);
MS2_REPLACE_METHOD(0x140EB4BE0, UIMasteryDialog, FUN_140eb4be0, 34, 0xA36B67C8);
MS2_REPLACE_METHOD(0x140EB4C10, UIMasteryDialog, FUN_140eb4c10, 86, 0xFF84B02A);
MS2_REPLACE_METHOD(0x140EB4C70, UIMasteryDialog, OnRecipeCraftCountInput, 200, 0x6AB6368B);
MS2_REPLACE_METHOD(0x140EB4D40, UIMasteryDialog, OnMagicScrollCraftConfirm, 221, 0xEC9AAF40);
MS2_REPLACE_METHOD(0x140EB4E30, UIMasteryDialog, OnRestoreMagicScrollSelectionMsgBox, 284, 0x3D7166D4);
MS2_REPLACE_METHOD(0x140EB5040, UIMasteryDialog, GetMainTabIndex, 262, 0x20B8A843);
MS2_REPLACE_METHOD(0x140EB5150, UIMasteryDialog, GetSubTabIndex, 262, 0x96FE42B1);
MS2_REPLACE_METHOD(0x140EB5260, UIMasteryDialog, SetPendingSub, 76, 0x2CC1527B);
MS2_REPLACE_METHOD(0x140EB52C0, UIMasteryDialog, SetPendingList, 76, 0x88AF847F);
MS2_REPLACE_METHOD(0x140EB53A0, UIMasteryDialog, FUN_140eb53a0, 168, 0xE87AEB17);
MS2_REPLACE_METHOD(0x140EB5450, UIMasteryDialog, FUN_140eb5450, 383, 0x59943791);
MS2_REPLACE_METHOD(0x140EB55E0, UIMasteryDialog, FUN_140eb55e0, 2107, 0xE774B82B);
MS2_REPLACE_METHOD(0x140EB5E30, UIMasteryDialog, FUN_140eb5e30, 32, 0x88F3761A);
MS2_REPLACE_METHOD(0x140EB5E60, UIMasteryDialog, FUN_140eb5e60, 2035, 0xF71AE862);
MS2_REPLACE_METHOD(0x140EB6660, UIMasteryDialog, FUN_140eb6660, 514, 0x8F8B8549);
MS2_REPLACE_METHOD(0x140EB6870, UIMasteryDialog, FUN_140eb6870, 165, 0xAD0EE20F);
MS2_REPLACE_METHOD(0x140EB6920, UIMasteryDialog, FUN_140eb6920, 847, 0x1994F4C2);
MS2_REPLACE_METHOD(0x140EB6C80, UIMasteryDialog, CancelCraft, 171, 0xA584C675);
MS2_REPLACE_METHOD(0x140EB6D40, UIMasteryDialog, FUN_140eb6d40, 1103, 0xDD4A5FC7);
MS2_REPLACE_METHOD(0x140EB71A0, UIMasteryDialog, FUN_140eb71a0, 2049, 0x55889835);
MS2_REPLACE_METHOD(0x140EB79B0, UIMasteryDialog, CalcAdjustedItemCount, 391, 0x4D8BEAD2);
MS2_REPLACE_METHOD(0x140EB7B40, UIMasteryDialog, CalcIngredientCount, 102, 0x4F669A99);
MS2_REPLACE_METHOD(0x140EB7BB0, UIMasteryDialog, GetMyMastery, 62, 0x938E275E);
MS2_REPLACE_METHOD(0x140EB7C00, UIMasteryDialog, UpdateMasteryGrade, 60, 0x46DE8ABD);
MS2_REPLACE_METHOD(0x140EB7C50, UIMasteryDialog, GetMasteryTabName, 223, 0xB1E1DDF9);
MS2_REPLACE_METHOD(0x140EB7D40, UIMasteryDialog, GetHousingTabName, 228, 0x419DFDA2);
MS2_REPLACE_METHOD(0x140EB7E30, UIMasteryDialog, FUN_140eb7e30, 741, 0xAA124871);
MS2_REPLACE_METHOD(0x140EB8120, UIMasteryDialog, FUN_140eb8120, 431, 0x592D5F7A);
MS2_REPLACE_METHOD(0x140EB82E0, UIMasteryDialog, GetSelectedMagicScrollSlot, 289, 0xDA605BC7);
MS2_REPLACE_METHOD(0x140EB8410, UIMasteryDialog, GetSelectedMagicScrollGrade, 300, 0xCF3E9804);
MS2_REPLACE_METHOD(0x140EB8550, UIMasteryDialog, HasRequiredLevel, 211, 0x84314BC4);
MS2_REPLACE_METHOD(0x140EB8630, UIMasteryDialog, GetCachedTypeValue, 45, 0x6A62DAA1);
MS2_REPLACE_METHOD(0x140EB8670, UIMasteryDialog, SetTypeValue, 52, 0xA410EB4C);
MS2_REPLACE_METHOD(0x140EB86B0, UIMasteryDialog, FUN_140eb86b0, 806, 0xBECB6CA9);
MS2_REPLACE_METHOD(0x140EB89E0, UIMasteryDialog, GetTypeForSlot, 119, 0xC05B67C2);
MS2_REPLACE_METHOD(0x140EB8A90, UIMasteryDialog, FUN_140eb8a90, 36, 0x9BF96619);
MS2_REPLACE_METHOD(0x140EB8AC0, UIMasteryDialog, FUN_140eb8ac0, 88, 0xA2E18639);
MS2_REPLACE_METHOD(0x140EB8B20, UIMasteryDialog, FUN_140eb8b20, 419, 0x27518734);
MS2_REPLACE_METHOD_VIA(0x140EB4F60, UIMasteryDialog, UIItemEventListener, vfunc_2, 91, 0xB308A7BA);
MS2_REPLACE_METHOD_VIA(0x140EB4FD0, UIMasteryDialog, UIItemEventListener, vfunc_4, 96, 0x85CF0DB2);
MS2_REPLACE_METHOD_VIA(0x140EAF840, UIMasteryDialog, ICastingEventListener, OnCastingFinished, 443, 0x4DD2CA94);
MS2_REPLACE_METHOD_VIA(0x140EAFA10, UIMasteryDialog, ICastingEventListener, OnCastingCancelled, 52, 0x5127663B);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca81c0-0x142ca82a0 .text$yd
// MS2-PIN: ?GetNext@?$CAtlMap@W4ECubeCategory@@V?$Unk_CubePtr@VInterior@UGCCubeCategoryTable@@@@V?$CElementTraits@W4ECubeCategory@@@ATL@@V?$CElementTraits@V?$Unk_CubePtr@VInterior@UGCCubeCategoryTable@@@@@4@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140ebb030
// MS2-PIN: ?FindNextNode@?$CAtlMap@W4ECubeCategory@@V?$Unk_CubePtr@VInterior@UGCCubeCategoryTable@@@@V?$CElementTraits@W4ECubeCategory@@@ATL@@V?$CElementTraits@V?$Unk_CubePtr@VInterior@UGCCubeCategoryTable@@@@@4@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140ebae70
