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
// MS2-PIN: ?IsNull@?$MS2Ptr@VUnk_MScrollRec@@@@QEBA_NXZ 0x140ebaa50 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCItem@@@@QEBAPEAVCItem@@XZ 0x140ebab90 ; order
// MS2-PIN: ?GetCount@?$CAtlArray@UItemEntity@@V?$CElementTraits@UItemEntity@@@ATL@@@ATL@@QEBA_KXZ 0x140ebaba0 ; order
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_MHouseLevel@@@@CAXPEAVUnk_MHouseLevel@@@Z 0x140ebb250 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ebb330 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMasteryDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ebb390 ; unique
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400dc190
// MS2-PIN: ??$?0$$BY00_W@ArgType@internal@fmt@@QEAA@AEAY00$$CB_W@Z 0x140eb9370
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@AEBV0@@Z 0x140eba830
// MS2-PIN: ??1?$MS2Ptr@VUnk_MFurn@@@@QEAA@XZ 0x140eba9f0
// MS2-PIN: ?IsNull@?$MS2Ptr@VAScript@@@@QEBA_NXZ 0x140ebaa20
// MS2-PIN: ??8?$MS2Ptr@VUnk_MItemDef@@@@QEBA_NPEAVUnk_MItemDef@@@Z 0x140ebaa80
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
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VUnk_MFurn@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_MFurn@@@@@ATL@@@ATL@@QEAA@XZ 0x140eba6b0
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
#include "ms2/placeholder/ms2stdafx.h"

#include "uimasterydialog.h"
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

// ---- the unit's statics (after the shared header statics) ----
static UICommon::CMyPCKeyInputController s_keyInput;                                                                // @0x1400dc200
static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400dc230

// ---- unit-local placeholders (unrecovered singletons / helpers) ----
using ATL::CAtlArray;
typedef ATL::CAtlArray<ItemEntity> Unk_MItemArray;

// The feature flags (global via FUN_140166410).
class Unk_MFeatures
{
public:
    bool FUN_14036d570(int nId);
};
Unk_MFeatures* FUN_140166410();

// The notice hub (global via FUN_140939a10).
class Unk_MNotices
{
public:
    void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>);
    void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>);
};
Unk_MNotices* FUN_140939a10();

// The item event hub (global via FUN_140a6a840).
class Unk_MEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* listener);      // register (once)
    void FUN_1419caeb0(UIItemEventListener* listener);      // unregister
};
Unk_MEvents* FUN_140a6a840();

// The world (global via FUN_1403ed2d0): the own character.
class Unk_MWorld
{
public:
    MyPC* FUN_141bd0cc0();
};
Unk_MWorld* FUN_1403ed2d0();

// The casting bar dialog (global lookup FUN_140ac2270(id)).
class Unk_MCastingBar
{
public:
    void FUN_1418e1390();                                   // cancel
    void FUN_1418e12f0(ICastingEventListener* listener, CStringW strText, int nTime, int a, int b, CStringW strIcon);
};
Unk_MCastingBar* FUN_140ac2270(int nId);


// The AS value setters / getters used by the Invoke helpers of this unit.
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, unsigned __int64 n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // the value as an int

// The AS array helpers (push an int / an object).
class Unk_MArray : public ASArray
{
public:
    void FUN_1422bbc60(int n);
    void FUN_1422bbf00(const ASObj& obj);
};

// One mastery recipe record (the mastery table of the data singleton). CPtred header 0x18.
class Unk_MRec : public CPtred
{
public:
    CString FUN_140669980();                                // the recipe icon name
    int m_nId;                                              // +0x18
    int m_nType;                                            // +0x1c category (8 / 9 housing, ...)
    unsigned short m_nNeedLevel;                            // +0x20
    unsigned short m_22;
    unsigned int m_nNeedMastery;                            // +0x24
    __int64 m_nMeso;                                        // +0x28
    void* m_30; void* m_38; void* m_40; void* m_48;
    CIngredientContainer m_ingredients;                     // +0x50
    int m_80;
    int m_nCastTime;                                        // +0x84
    void* m_88;
    CStringW m_strPlace;                                    // +0x90
    ATL::CAtlArray<ItemEntity> m_rewards;                   // +0x98
};
typedef ATL::CAtlArray<MS2Ptr<Unk_MRec> > Unk_MRecArray;

// The mastery data singleton (global via FUN_1409670c0).
class Unk_MData
{
public:
    MS2Ptr<Unk_MRec> FUN_14066aa00(int nId);                // recipe by id (NULL when unknown)
    void FUN_14066aa90(int nType, Unk_MRecArray& out);      // the recipes of a category
    int FUN_14066af60(int nType, unsigned int nMastery);    // grade of a mastery value
    int FUN_14066b050(int nType);                           // max grade
    int FUN_14066b310(int nType, int nGrade);               // mastery needed for a grade
    CStringW FUN_14066c690(int nType, int nGrade);          // grade name
    CStringW FUN_14066bdd0(int nType);                      // category name
    ItemEntity* FUN_14066b640(int nId);                     // reward entry of a recipe id
    int FUN_14066b910(int nType, int nId);
    void FUN_14066b100(int nId, int nJob, Unk_MItemArray& out);
    int FUN_14066b500(int nType, int nIdx);
    int FUN_14066bb00(MS2Ptr<Unk_MRec> spRec);
    int FUN_14066bb80(int nType);
    int FUN_14066ba00(int nType);
    CStringW FUN_14066c110(int nType, int nId, int n);
    int FUN_14066ab90(int nId, unsigned int nMastery);
};
Unk_MData* FUN_1409670c0();

// The mastery points service (global via FUN_140e5ca20).
class Unk_MPoints
{
public:
    int FUN_140b6d330(int nId);
    int FUN_140b6d470(int nId);
    int FUN_140b6d140(int nType);
    int FUN_140b6d250(int nType, int nIdx);
    void FUN_140b6d710(int nCode);
};
Unk_MPoints* FUN_140e5ca20();

// The string table (global via FUN_1401a9d70).
class Unk_MStrings
{
public:
    CStringW FUN_141811980(int nKind, int nId);
};
Unk_MStrings* FUN_1401a9d70();

// The inventory counters (global at 0x143ab2a90).
class Unk_MInv
{
public:
    int FUN_140a5f180(int nItemId, int a);
    int FUN_140a5f780(int nItemId, int a);
    int FUN_140a5f7b0(int nItemId, int a);
};
extern Unk_MInv DAT_143ab2a90;

class Unk_MDebug { };
Unk_MDebug* FUN_14025e7c0();
unsigned char FUN_14116d720(Unk_MDebug*);

// MyPC accessors.
unsigned int FUN_141662750(MyPC* pPc, int nType);           // mastery value of a category
int FUN_141654700(MyPC* pPc);                               // job
int FUN_14053feb0(int nItemId);                             // default rank of an item
CStringW FUN_1419021b0(int nHave, int nNeed);               // "have/need" count text
#include "ms2/commonfiles/commonutil.h"
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a, const CStringW& b);
CStringW FUN_14062b4f0(CStringW strKey, const int* p);
CStringW FUN_1409e8820(CStringW strKey, const unsigned short& n);
CStringW FUN_1409e8970(CStringW strKey, const int& a, const int& b);
void FUN_140d432d0(ItemSlotBinder* pBinder, int n);
void FUN_140d43990(ItemSlotBinder* pBinder);
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
    virtual void vfunc_24(int n);
    void FUN_1409c0dc0(const char* szName, const char* szValue);     // the ASObj setters, applied to the control
    void FUN_1407cb9c0(const char* szName, int n);
    MS2Ptr<Unk_MGroup> FUN_140eb9cf0(const CString& strName);        // child lookups (in-unit COMDATs)
    MS2Ptr<class Unk_MToggle> FUN_140e28bc0(const CString& strName);
};

// "m_mainTab" / "m_gradeGroup" (a button group: selectedIndex).
class Unk_MGroup : public Unk_MCtl { public: Unk_MGroup(const Scaleform::GFx::Value& v, int nMovieId); char m_pad40[0x40]; };    // 0x1422c3090, 0x80 bytes
// "m_grade00" ... (a toggle button).
class Unk_MToggle : public Unk_MCtl { };
// "m_subTab": the category button strip.
class Unk_MSubTab : public Unk_MCtl
{
public:
    void FUN_1422e3400();                                   // clear
    void FUN_1422e34d0(const CStringW& strText);            // add a tab
};
// "m_guideBar" of the level control.
class Unk_MGuide : public Unk_MCtl { };
// "m_objectList": the mastery list.
class Unk_MList : public Unk_MCtl
{
public:
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dcca0(int n);
    void FUN_1422e17f0(int n);
    void FUN_1422dd230(const ASObj& row);                   // append a row
    int FUN_1422dccd0();                                    // scroll position
    int FUN_1422e1820();                                    // first visible row
    void FUN_1422e1970(int nIndex, const ASObj& row);       // set a row
    void FUN_1422e1a00(int nIndex, const ASObj& row);       // refresh a row
};
// "m_levelControl" / "m_magicScrollControl".
class Unk_MLevelCtrl : public Unk_MCtl
{
public:
    Scaleform::GFx::Value FUN_140eb9e40(const char* szMethod, int a1, int a2, CStringW a3, int a4);
    Scaleform::GFx::Value FUN_140eb9f50(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3, int a4);
    Scaleform::GFx::Value FUN_140eba060(const char* szMethod, const AScript& a1, unsigned int a2);
    Scaleform::GFx::Value FUN_140eba120(const char* szMethod, const AScript& a1, unsigned __int64 a2, int a3);
    Scaleform::GFx::Value FUN_140eba380(const char* szMethod, unsigned __int64 a1, unsigned int a2, CStringW a3, int a4);
};
// "m_magicScroll": the magic scroll page.
class Unk_MScroll : public Unk_MCtl { };


// The notify of the local character being damaged (RTTI .?AVNotifyDamagedMyPC@@).
class Unk_MDamage
{
public:
    __int64 FUN_14175ac30();                                // the hp change (negative = damage)
};
class NotifyDamagedMyPC : public NotifyObject
{
public:
    NotifyDamagedMyPC();
    virtual ~NotifyDamagedMyPC();
    virtual CStringW GetTypeName();
    Unk_MDamage* m_pDamage;                                 // +0x18
};
bool FUN_140841300(const CStringW& str, const char* sz);   // equal to a char literal


typedef ATL::CAtlArray<ItemEntity> Unk_MItemArray;
void FUN_141a015d0(CMsgBoxData* pBox, CStringW strTitle);     // sets the title
// message box helpers
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_141a02a30(CMsgBoxData* pBox, ATL::CAtlArray<ItemEntity>& rewards);
void FUN_141275260(int nStringId, int nA, int nB);
int FUN_1407181a0(const CStringW& str);
class Unk_MHome { public: int FUN_1410d2f10(); bool FUN_1410d5640(); };
Unk_MHome* FUN_1409670e0();
CStringW FUN_1405c2690(CStringW strKey, CStringW strArg);
class Unk_MHomeSvc { public: int FUN_140936640(int a, int b); };
Unk_MHomeSvc* FUN_1406c7600();
int FUN_140eb8cd0(MS2Ptr<Unk_MFurn> spFurn);
int FUN_140eb8eb0(MS2Ptr<Unk_MFurn> spFurn);
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                 // the value is an object
int FUN_1407cccd0(const Scaleform::GFx::Value* v);                  // the value type
unsigned __int64 FUN_1401d49f0(const void* p);                      // fmt make_type
unsigned __int64 FUN_140889fd0(const void* p);                      // the map key hash
void FUN_14034ed60(void* p);                                        // MS2Ptr<Unk_MScrollRec> dtor
void FUN_14066d5b0(void* p);
void FUN_14056c300(void* p);
__declspec(noreturn) void FUN_140159b70(long hr);                   // ATL throw
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
// ---- housing / furniture / scroll tables ----
class Unk_MHouseLevel : public CPtred { public: int m_n1c; };
class Unk_MHousing
{
public:
    void FUN_140663010(unsigned short nLevel, int nJob, Unk_MItemArray& out);
    int FUN_1406631b0(unsigned short nLevel);
    MS2Ptr<Unk_MHouseLevel> FUN_1406635c0(unsigned short nLevel);
    unsigned int GetMaxLevel();                           // COMDAT: the highest level
    char m_pad[8]; unsigned int m_nMaxLevel;
};
Unk_MHousing* FUN_140933200();
class Unk_MHouseSet { public: int FUN_1402bacf0(const int* p); };
extern Unk_MHouseSet DAT_143ab32b8;
class Unk_MHouseRec : public CPtred { public: char m_pad[8]; unsigned short m_nLevel; };    // m_nLevel +0x20
typedef ATL::CAtlMap<unsigned int, MS2Ptr<Unk_MHouseRec> > Unk_MHouseMap;
class Unk_MHouseTable
{
public:
    Unk_MHouseMap& FUN_140886640();
    MS2Ptr<Unk_MHouseRec> FUN_1408865b0(int nId);
};
Unk_MHouseTable* FUN_1409eed80();
class Unk_MItemDef : public CPtred { public: CString FUN_14053fdd0(); };
MS2Ptr<Unk_MItemDef> FUN_14053f870(unsigned int nId);
class Unk_MFurn : public CPtred
{
public:
    unsigned int FUN_1405494e0();
    __int64 m_n18;
    char m_pad20[0x1c];
    int m_n3c; int m_n40; int m_n44; int m_n48;
    unsigned short m_w4c;
    char m_pad4e;
    char m_bOwned;
};
typedef ATL::CAtlArray<MS2Ptr<Unk_MFurn> > Unk_MFurnArray;
class Unk_MFurnTable { public: void FUN_140557920(int nId, Unk_MFurnArray& out); };
static inline Unk_MFurnTable* MFurnTable() { return reinterpret_cast<Unk_MFurnTable*>(FUN_140281980()); }
class Unk_MFurnState { public: bool FUN_140534e50(); };
class Unk_MFurnInv { public: Unk_MFurnState FUN_1408fbe90(unsigned int nId); };
extern Unk_MFurnInv DAT_143ab2e20;


class Unk_MScrollDef : public CPtred { public: int m_n18; int m_n1c; };
class Unk_MScrollRec : public CPtred
{
public:
    CString FUN_14034dbe0();
    int m_nId; int m_n1c; int m_n20; int m_nSlot; int m_nState;
    int m_n2c;
    ItemEntity m_result;                                    // +0x30
    __int64 m_nMeso;                                        // +0x60
    CIngredientContainer m_ingredients;                     // +0x68
    ATL::CAtlArray<ItemEntity> m_rewards;                   // +0x98
};
typedef ATL::CAtlArray<MS2Ptr<Unk_MScrollRec> > Unk_MScrollArray;
class Unk_MScrollTable
{
public:
    int FUN_14034e5e0(int nTab, int k);
    void FUN_14034e460(int nTab, int nSlot, int nSub, Unk_MScrollArray& out);
    MS2Ptr<Unk_MScrollRec> FUN_14034e3e0(int nId);
    MS2Ptr<Unk_MScrollDef> FUN_14034e360(int nId);
};
Unk_MScrollTable* FUN_14034f780();
class Unk_MJobRec : public CPtred { public: char m_pad[8]; int m_n20; };
class Unk_MJobTable { public: MS2Ptr<Unk_MJobRec> FUN_140644880(int nJob); };
Unk_MJobTable* FUN_1401d7a50();
class Unk_MFormula
{
public:
    int FUN_140677c60(int nCount, unsigned int nNeed, unsigned int nMastery);
    unsigned __int64 FUN_140677e20(int nNeed, unsigned int nMastery, unsigned int nCount);
};
Unk_MFormula* FUN_1401c0db0();
class Unk_MStats { public: float FUN_1411e1110(int nCode); };
Unk_MStats* FUN_1416561a0(MyPC* pPc);
int FUN_1406198a0(int n, float f);
int FUN_1404820b0(int n, float f);
CStringW FUN_14183e9c0(CStringW str, int nRank);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strName, const int& nCount);   // string table format (name, count): the FMT_VARIADIC_W <CStringW, int> instance
int FUN_140930e10();
CString FUN_140c43630(const char* szFmt, const unsigned __int64& n);
CStringW FUN_140938ae0(CStringW strKey, const int& n);
class Unk_MChat { public: void FUN_141a25770(CStringW str, int n); };
Unk_MChat* FUN_140a3ab70(int nId);
class Unk_MMap { public: void FUN_140361ab0(unsigned int nId, int* pOut); };
extern Unk_MMap DAT_143ab31a0;
extern __int64 DAT_143ab2898;
extern unsigned short DAT_143ab291c;
extern int DAT_143ab2930;

// a page array (ctor 0x1422deec0)
class Unk_MPageArray : public ASArray
{
public:
    void FUN_1422bbf00(const ASObj& obj);
};
// the handle of the movie page (Invoke glue on a bare AScript)
class Unk_MInvoker : public AScript
{
public:
    Scaleform::GFx::Value FUN_140bbeaa0(const char* szMethod, const ASArray& page);   // Invoke(method, array): returns the result
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
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyDamagedMyPC"), Delegate<void(NotifyObject*)>(this, &UIMasteryDialog::FUN_140eb5320));
    m_2f8 = FUN_140166410()->FUN_14036d570(0xd1) ? 10 : 6;
    memset(&m_310, 0, 0x30);
}

// @0x140eae2d0
UIMasteryDialog::~UIMasteryDialog()
{
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyDamagedMyPC"), Delegate<void(NotifyObject*)>(this, &UIMasteryDialog::FUN_140eb5320));
}

// @0x140eae470
CString UIMasteryDialog::GetTypeName()
{
    return CString("MasteryDialog");
}

// @0x140eae4c0
int UIMasteryDialog::vfunc_65()
{
    FUN_140a6a840()->FUN_1419cae20(this);
    return UIDialog::vfunc_65();
}

// @0x140eae520
void UIMasteryDialog::vfunc_67()
{
    if (m_craft.HasTotal()) {
        Unk_MCastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
    m_magicScroll = 0;
    m_craft.FUN_140eadda0();
    FUN_140d43990(&m_reward);
    FUN_140d43990(&m_require);
    FUN_140d43990(&m_mastery);
    m_nSelected = 0;
    if (m_30.get()) {
        Scaleform::GFx::Value last = m_30->FUN_1422baa20("m_lastSelectedIndex");
        if (last.IsArray()) {
            Scaleform::GFx::Value item[4];
            for (unsigned int i = 0; i < 4; i++) {
                last.GetElement(i, &item[i]);
                if (!item[i].IsNumber())
                    m_lastSelected[i] = 0;
                else
                    m_lastSelected[i] = FUN_1409c1750(item[i]);
            }
        }
        MS2Ptr<Unk_MGroup> spTab = FUN_140eb9db0(CString("m_mainTab"));
        if (spTab.get()) {
            Scaleform::GFx::Value sel = spTab->FUN_1422baa20("selectedIndex");
            m_nMainTab = FUN_1409c1750(sel);
        }
    }
    FUN_140a6a840()->FUN_1419caeb0(this);
    UIDialog::vfunc_67();
}

// @0x140eae8a0
void UIMasteryDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419260d0(CString("m_webGuideButton"), 0);
    ASArray last(2);
    for (unsigned int i = 0; i < 4; i++)
        reinterpret_cast<Unk_MArray&>(last).FUN_1422bbc60(m_lastSelected[i]);
    reinterpret_cast<ASObj*>(m_30.operator->())->FUN_1409eb1d0("m_lastSelectedIndex", last);
    MS2Ptr<Unk_MLevelCtrl> spScrollCtrl = FUN_140c02990(CString("m_magicScrollControl"));
    if (spScrollCtrl.get())
        spScrollCtrl->Invoke("setSelectedSlotIndex", FUN_140eb6870() - 1);
    MS2Ptr<Unk_MGroup> spMainTab = FUN_140eb9db0(CString("m_mainTab"));
    if (spMainTab.get())
        spMainTab->Invoke("setSelectedButtonByIndex", m_nMainTab);
    m_30->FUN_140bbe640(CString("m_magicScroll"), m_magicScroll);
    if (m_magicScroll == 0)
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(272), __FUNCTION__));
    if (!FUN_140166410()->FUN_14036d570(0x5a))
        m_magicScroll->vfunc_3(0);
    FUN_140eb7e30();
}

// @0x140eaed30
void UIMasteryDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CStringW strName = pArgs->FUN_1422b8f40();
    if (FUN_140841300(strName, "housingSlot")) {
        int nId = pArgs->FUN_1422b8b10();
        int nRank = FUN_14053feb0(nId);
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nId, nRank, 0)) {
            ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 8, 2);
            if (tip.FUN_1409e0d40(spItem.get())) {
                tip.FUN_1409c6dc0(7);
                *pRetVal = tip.FUN_1422bb870();
            }
        }
    } else if (FUN_140841300(strName, "masteryRecipe")) {
        if (FUN_140eb5040() == 1) {
            int nId = pArgs->FUN_1422b8a10();
            ItemEntity* pEntry = FUN_1409670c0()->FUN_14066b640(nId);
            if (pEntry) {
                MS2Ptr<CItem> spItem(new CItem);
                int nRank = pEntry->vfunc_o18_1();
                if (spItem->FUN_140523c40(pEntry->m_itemId, nRank, 0)) {
                    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x800, 2);
                    if (tip.FUN_1409e0d40(spItem.get())) {
                        tip.FUN_1409c6dc0(7);
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
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140eafde0();
        return 1;
    }
    if (!_stricmp(szMethod, "onSelectMastery")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140eb53a0();
        return 1;
    }
    if (!_stricmp(szMethod, "onSelectList")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nIndex = data.FUN_1422b8a10();
            FUN_140eb5450(nIndex);
        }
        return 1;
    }
    if (!_stricmp(szMethod, "onReceiveItem")) {
        ASData data;
        int nTab;
        if (data.FUN_1422b9620(pArgs, nArgs) && (nTab = FUN_140eb5040(), -1 < nTab)) {
            if (nTab < 2) {
                int nId = data.FUN_1422b8b10();
                COutPacket pkt(0x92, 0);
                pkt.Encode1(1);
                pkt.Encode4(nId);
                FUN_140710590(pkt);
            } else if (nTab == 2) {
                if (FUN_140eb86b0() == 8) {
                    int nId = data.FUN_1422b8a10();
                    COutPacket pkt(0x37, 0);
                    pkt.Encode1(0x29);
                    pkt.Encode1((unsigned char)nId);
                    FUN_140710590(pkt);
                } else if (FUN_140eb86b0() == 9) {
                    int nId = data.FUN_1422b8b10();
                    COutPacket pkt(0x92, 0);
                    pkt.Encode1(1);
                    pkt.Encode4(nId);
                    FUN_140710590(pkt);
                }
            }
        }
        return 1;
    }
    if (!_stricmp(szMethod, "onCraftOk")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nId = data.FUN_1422b8a10();
            int nTab = FUN_140eb5040();
            if (nTab == 1)
                FUN_140eb55e0(nId);
            else if (nTab == 2)
                FUN_140eb5e30(nId);
            else if (nTab == 3)
                FUN_140eb5e60(nId);
        }
        return 1;
    }
    if (!_stricmp(szMethod, "onDebug")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strCommand;
            CStringW strFormat(L"/ManufacturingMastery {0} {1}");
            int nTab = FUN_140eb5040();
            if (nTab == 1) {
                int nId = data.FUN_1422b8a10();
                strCommand = StringFormat((const wchar_t*)strFormat, nId, "");
            } else if (nTab == 3) {
                int nId = data.FUN_1422b8a10();
                strCommand = StringFormat((const wchar_t*)strFormat, nId, "magicscroll");
            }
            Unk_MChat* pChat = FUN_140a3ab70(0x4e61);
            if (pChat)
                pChat->FUN_141a25770(CStringW(strCommand), 0);
        }
        return 0;
    }
    if (!_stricmp(szMethod, "onChangeFilter")) {
        FUN_140eb3460();
        return 0;
    }
    if (!_stricmp(szMethod, "onScrollPosition")) {
        if (m_304 != 0)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nSlot = FUN_140eb86b0();
            m_scroll[nSlot] = data.FUN_1422b8a10();
        }
        return 1;
    }
    return 0;
}

// @0x140eaf840
void UIMasteryDialog::OnCastingFinished()
{
    if (m_craft.FUN_140eaddf0()) {
        COutPacket pkt(0x92, 0);
        pkt.Encode1(2);
        pkt.Encode4(m_craft.m_nId);
        FUN_140710590(pkt);
    } else if (m_craft.FUN_140eade30()) {
        COutPacket pkt(0x71, 0);
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
            MS2Ptr<Unk_MRec> spRec = FUN_1409670c0()->FUN_14066aa00(m_craft.m_nId);
            if (spRec.get())
                nTime = spRec->m_nCastTime;
        }
        Unk_MCastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar) {
            const wchar_t* szKey = m_craft.FUN_140eaddf0() ? L"s_mastery_manufacture_progress" : L"s_mastery_magicscroll_progress";
            pBar->FUN_1418e12f0(this, FUN_1409e8970(CStringW(szKey), m_craft.m_nDone, m_craft.m_nTotal), nTime, 0, 1, CStringW(L""));
        }
        m_craft.m_nPending = 0;
    }
    if (m_nPendingSub == 0) {
        if (m_nPendingList != 0) {
            if (FUN_140eb8a90() == m_nPendingList) {
                FUN_140eb0da0(m_nPendingList, true);
                FUN_140eb1770(m_nSelected, true);
            }
            m_nPendingList = 0;
        }
    } else {
        FUN_140eb05b0(m_nPendingSub, true);
        if (FUN_140eb8a90() == m_nPendingList)
            FUN_140eb1770(m_nSelected, true);
        m_nPendingSub = 0;
        m_nPendingList = 0;
    }
}

// @0x140eafdb0
void UIMasteryDialog::SetMainTab(int nMainTab)
{
    m_nMainTab = nMainTab;
}

// @0x140eafde0
void UIMasteryDialog::FUN_140eafde0()
{
    if (!vfunc_46())
        return;
    MS2Ptr<Unk_MSubTab> spSub = FUN_140c02870(CString("m_subTab"));
    if (!spSub.get())
        return;
    spSub->FUN_1422e3400();
    int nTab = FUN_140eb5040();
    if (nTab == 0) {
        spSub->FUN_1422e34d0(FUN_140eb7c50(3));
        spSub->FUN_1422e34d0(FUN_140eb7c50(5));
        if (FUN_140166410()->FUN_14036d570(0x59)) {
            spSub->FUN_1422e34d0(FUN_140eb7c50(4));
            spSub->FUN_1422e34d0(FUN_140eb7c50(6));
        }
    } else if (nTab == 1) {
        spSub->FUN_1422e34d0(FUN_140eb7c50(7));
        spSub->FUN_1422e34d0(FUN_140eb7c50(8));
        if (FUN_140166410()->FUN_14036d570(0x59)) {
            spSub->FUN_1422e34d0(FUN_140eb7c50(9));
            spSub->FUN_1422e34d0(FUN_140eb7c50(10));
        }
    } else if (nTab == 2) {
        spSub->FUN_1422e34d0(FUN_140eb7d40());
        if (FUN_140166410()->FUN_14036d570(0x8d))
            spSub->FUN_1422e34d0(FUN_140eb7c50(0xb));
    } else if (nTab == 3) {
        if (FUN_140166410()->FUN_14036d570(0x5a)) {
            if (FUN_140166410()->FUN_14036d570(0x7c))
                spSub->FUN_1422e34d0(GetStringCommonByKey(CStringW(L"s_mastery_magicscroll_enchant_scroll_tab")));
            if (FUN_140166410()->FUN_14036d570(0x7d))
                spSub->FUN_1422e34d0(GetStringCommonByKey(CStringW(L"s_mastery_magicscroll_restore_scroll_tab")));
            if (FUN_140166410()->FUN_14036d570(0x7e))
                spSub->FUN_1422e34d0(GetStringCommonByKey(CStringW(L"s_mastery_magicscroll_fracto_scroll_tab")));
            if (FUN_140166410()->FUN_14036d570(0x7f))
                spSub->FUN_1422e34d0(GetStringCommonByKey(CStringW(L"s_mastery_magicscroll_protected_scroll_tab")));
        }
    }
    spSub->vfunc_24(1);
}

// @0x140eb0540
void UIMasteryDialog::FUN_140eb0540()
{
    FUN_140d43990(&m_reward);
    FUN_140d43990(&m_require);
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
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb0610(int nType, bool bKeep)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    int nOld = FUN_140eb8630(nType);
    int nNow = (int)FUN_141662750(pPc, nType);
    MS2Ptr<Unk_MLevelCtrl> spLevel = FUN_140c02990(CString("m_levelControl"));
    if (!spLevel.get())
        return;
    int nGrade = FUN_1409670c0()->FUN_14066af60(nType, nNow);
    int nMaxGrade = FUN_1409670c0()->FUN_14066b050(nType);
    int nBase = FUN_1409670c0()->FUN_14066b310(nType, nGrade);
    int nNext = FUN_1409670c0()->FUN_14066b310(nType, nGrade + 1);
    bool bGradeChanged = false;
    if (nNow != nOld) {
        FUN_140eb8670(nType, nNow);
        bGradeChanged = nGrade != FUN_1409670c0()->FUN_14066af60(nType, nOld);
    }
    if (!bKeep || nNow != nOld) {
        CStringW strGrade = FUN_140656190(L"{0} {1}", FUN_1409670c0()->FUN_14066bdd0(nType), FUN_1409670c0()->FUN_14066c690(nType, nGrade));
        spLevel->FUN_140eb9f50("setPcGrade", nNow - nBase, nNext - nBase, CStringW(strGrade), nGrade == nMaxGrade);
        MS2Ptr<Unk_MGuide> spGuide = spLevel->FUN_140accfb0<Unk_MGuide>(CString("m_guideBar"));
        if (spGuide.get())
            spGuide->Invoke("setPC", (unsigned int)nNow);
    }
    if (!bKeep || bGradeChanged) {
        FUN_140d43990(&m_mastery);
        spLevel->Invoke("removeGradeAll");
        int nCount = FUN_1409670c0()->FUN_14066b050(nType);
        ASArray arr(2);
        for (int i = 1; i <= nCount; i++) {
            ASObj obj(2);
            FUN_140eb6920(nType, i, obj);
            reinterpret_cast<Unk_MArray&>(arr).FUN_1422bbf00(obj);
        }
        spLevel->FUN_140eba060("setGrade", arr, nNow);
    }
}

// @0x140eb0bf0
void UIMasteryDialog::FUN_140eb0bf0(int nType, int nIndex)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    MS2Ptr<Unk_MLevelCtrl> spLevel = FUN_140c02990(CString("m_levelControl"));
    if (spLevel.get()) {
        MS2Ptr<Unk_MGuide> spGuide = spLevel->FUN_140accfb0<Unk_MGuide>(CString("m_guideBar"));
        if (spGuide.get()) {
            ASObj obj(2);
            FUN_140eb6920(nType, nIndex, obj);
            spGuide->Invoke("addLevelGuide", obj);
        }
    }
}

// @0x140eb0da0
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb0da0(int nType, bool bKeep)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    unsigned int nMastery = FUN_141662750(pPc, nType);
    if (!bKeep) {
        FUN_140eb0540();
        MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
        if (spList.get()) {
            spList->FUN_1422dd1d0();
            spList->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_mastery");
            spList->FUN_1407cb9c0("rowHeight", 0x4c);
            Unk_MRecArray recs;
            FUN_1409670c0()->FUN_14066aa90(nType, recs);
            for (size_t i = 0; i < recs.GetCount(); i++) {
                MS2Ptr<Unk_MRec> spRec(recs[i]);
                if (FUN_140e5ca20()->FUN_140b6d330(recs[i]->m_nId) == 0)
                    continue;
                ASObj row(2);
                row.FUN_1407cb9c0("id", spRec->m_nId);
                row.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(0x2f, spRec->m_nId));
                row.FUN_1407cbb20("state", FUN_140eb71a0(MS2Ptr<Unk_MRec>(spRec)));
                bool bActive = nMastery >= (unsigned int)spRec->m_nNeedMastery && FUN_140eb8550(MS2Ptr<Unk_MRec>(spRec)) != 0;
                row.FUN_1407cbbe0("active", bActive);
                row.FUN_1407cba60("icon", spRec->FUN_140669980());
                if (nType == 0xb && spRec->m_rewards.GetCount() != 0)
                    row.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
                spList->FUN_1422dd230(row);
            }
            FUN_140eb8b20();
        }
    } else {
        MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
        if (spList.get()) {
            Unk_MRecArray recs;
            FUN_1409670c0()->FUN_14066aa90(nType, recs);
            int nCount = (int)recs.GetCount();
            int nScroll = spList->FUN_1422dccd0();
            if (nScroll < nCount) {
                int nFirst = spList->FUN_1422e1820();
                int nRow = 0;
                for (int i = 0; i < nCount; i++) {
                    MS2Ptr<Unk_MRec> spRec(recs[i]);
                    if (FUN_140e5ca20()->FUN_140b6d330(recs[i]->m_nId) == 0)
                        continue;
                    ASObj row(2);
                    row.FUN_1407cb9c0("id", spRec->m_nId);
                    row.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(0x2f, spRec->m_nId));
                    row.FUN_1407cbb20("state", FUN_140eb71a0(MS2Ptr<Unk_MRec>(spRec)));
                    bool bActive = nMastery >= (unsigned int)spRec->m_nNeedMastery && FUN_140eb8550(MS2Ptr<Unk_MRec>(spRec)) != 0;
                    row.FUN_1407cbbe0("active", bActive);
                    row.FUN_1407cba60("icon", spRec->FUN_140669980());
                    if (nType == 0xb && spRec->m_rewards.GetCount() != 0)
                        row.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
                    if (nRow < nFirst || nFirst + 5 < nRow) {
                        spList->FUN_1422e1970(nRow, row);
                    } else {
                        spList->FUN_1422e1970(nRow, row);
                        spList->FUN_1422e1a00(nRow, row);
                    }
                    nRow++;
                }
            }
            spList->vfunc_23();
        }
    }
}

// @0x140eb1770
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb1770(int nId, bool bKeep)
{
    if (m_30.IsNull())
        return;
    if (!FUN_1403ed2d0()->FUN_141bd0cc0())
        return;
    if (!bKeep) {
        FUN_140eb0540();
        if (!m_30.get())
            return;
        MS2Ptr<Unk_MRec> spRec = FUN_1409670c0()->FUN_14066aa00(nId);
        if (spRec.IsNull())
            return;
        ASObj page(2);
        unsigned int nMastery = FUN_140eb7bb0(spRec->m_nType);
        int bCanCraft = (nMastery >= (unsigned int)spRec->m_nNeedMastery && !m_craft.HasTotal()) ? 1 : 0;
        for (size_t i = 0; i < spRec->m_rewards.GetCount(); i++) {
            ItemEntity& rew = spRec->m_rewards[i];
            int nRank = FUN_140eb79b0(spRec->m_nType, spRec->m_nNeedMastery, &rew);
            page.FUN_1407cba60(FUN_140c43630("binding{0}", i), m_reward.FUN_140d43310(rew.m_itemId, rew.vfunc_o18_1(), nRank));
        }
        int bEnough = 1;
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            int nNeed = FUN_140eb7b40(spRec->m_nType, spRec->m_nNeedMastery, ref->m_c);
            int nHave;
            if (ref->m_b == 0)
                nHave = DAT_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
            else
                nHave = DAT_143ab2a90.FUN_140a5f780(ref->m_b, 0);
            if (nHave < nNeed)
                bEnough = 0;
            int nItem = ref->FUN_14026b500();
            int nItemRank = FUN_14053feb0(nItem);
            int nCount = ref->m_c;
            CStringW strCnt = FUN_1419021b0(nHave, nNeed);
            ASObj req(2);
            req.FUN_1407cba60("binding", m_require.FUN_140d43310(nItem, nItemRank, nCount));
            req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
            page.FUN_1409eb270(FUN_140c43630("require{0}", i), req);
        }
        int bState = FUN_140eb8550(MS2Ptr<Unk_MRec>(spRec));
        page.FUN_1407cb9c0("id", nId);
        page.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(0x2f, nId));
        int nShown = FUN_140eb8120(MS2Ptr<Unk_MRec>(spRec));
        page.FUN_1407cbb20("mastery", FUN_140938ae0(CStringW(L"s_mastery_reward_mastery"), nShown));
        page.FUN_1407cbb20("desc", FUN_1401a9d70()->FUN_141811980(0x30, nId));
        page.FUN_1407cbb20("place", CStringW(spRec->m_strPlace));
        page.FUN_1407cba60("icon", spRec->FUN_140669980());
        page.FUN_1409c1180("meso", spRec->m_nMeso);
        page.FUN_1407cbbe0("enabled", bCanCraft && bEnough && bState);
        page.FUN_1407cbbe0("debug", FUN_14116d720(FUN_14025e7c0()));
        if (spRec->m_nType == 0xb && spRec->m_rewards.GetCount() != 0)
            page.FUN_1409adc90("grade", spRec->m_rewards[0].vfunc_o18_1());
        m_30->Invoke("setPage", page);
    } else {
        if (!m_30.get())
            return;
        MS2Ptr<Unk_MRec> spRec = FUN_1409670c0()->FUN_14066aa00(nId);
        if (spRec.IsNull())
            return;
        ASObj page(2);
        for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
            Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
            int nNeed = FUN_140eb7b40(spRec->m_nType, spRec->m_nNeedMastery, ref->m_c);
            int nHave;
            if (ref->m_b == 0)
                nHave = DAT_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
            else
                nHave = DAT_143ab2a90.FUN_140a5f780(ref->m_b, 0);
            CStringW strCnt = FUN_1419021b0(nHave, nNeed);
            ASObj req(2);
            req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
            page.FUN_1409eb270(FUN_140c43630("require{0}", i), req);
        }
        m_30->Invoke("refreshPage", page);
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
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb24a0()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    MS2Ptr<Unk_MLevelCtrl> spLevel = FUN_140c02990(CString("m_levelControl"));
    if (!spLevel.get())
        return;
    FUN_140d43990(&m_mastery);
    spLevel->Invoke("removeGradeAll");
    unsigned short nCur = DAT_143ab291c;
    unsigned short nMax = FUN_140933200()->GetMaxLevel();
    int nSum = 0;
    unsigned int nSumCur = 0;
    ASArray rows(2);
    for (int nLevel = 1; nLevel <= (int)nMax; nLevel++) {
        Unk_MItemArray items;
        FUN_140933200()->FUN_140663010(nLevel, FUN_141654700(pPc), items);
        if (nLevel != 1 && items.GetCount() == 0)
            continue;
        int nAdd = FUN_140933200()->FUN_1406631b0(nLevel);
        nSum += nAdd;
        if (nLevel <= (int)nCur)
            nSumCur += nAdd;
        ASObj row(2);
        row.FUN_1407cb9c0("id", nLevel);
        row.FUN_1409c0d20("level", nSum);
        row.FUN_1407cbb20("levelStr", FUN_14062b4f0(CStringW(L"s_mastery_housing_grade"), &nLevel));
        bool bInactive = DAT_143ab32b8.FUN_1402bacf0(&nLevel) != -1;
        CString strState;
        if (!bInactive)
            strState = (nCur < nLevel) ? "lock" : "active";
        else
            strState = "inactive";
        row.FUN_1407cba60("state", CString(strState));
        if (items.GetCount() != 0) {
            ItemEntity& item0 = items[0];
            row.FUN_1407cba60("binding", m_mastery.FUN_140d43310(item0.m_itemId, item0.vfunc_o18_1(), item0.m_count));
        }
        reinterpret_cast<Unk_MArray&>(rows).FUN_1422bbf00(row);
    }
    spLevel->FUN_140eba120("setGrade", rows, nSumCur + DAT_143ab2930, 0);
    CStringW strGrade = FUN_140656190(L"{0} {1}", FUN_140298ea0(CStringW(L"s_mastery_housing")), FUN_1409e8820(CStringW(L"s_mastery_housing_grade"), DAT_143ab291c));
    if (DAT_143ab291c == FUN_140933200()->GetMaxLevel()) {
        spLevel->FUN_140eb9e40("setPcGrade", 1, 1, CStringW(strGrade), 1);
    } else {
        MS2Ptr<Unk_MHouseLevel> spNext = FUN_140933200()->FUN_1406635c0((unsigned short)(DAT_143ab291c + 1));
        if (spNext.get())
            spLevel->FUN_140eba380("setPcGrade", DAT_143ab2930, spNext->m_n1c, CStringW(strGrade), 0);
    }
}

// @0x140eb2d10
void UIMasteryDialog::FUN_140eb2d10()
{
    if (!FUN_1403ed2d0()->FUN_141bd0cc0() || m_30.IsNull())
        return;
    FUN_140eb0540();
    unsigned short nCur = DAT_143ab291c;
    MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
    if (!spList.get())
        return;
    spList->FUN_1422dd1d0();
    spList->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_housing");
    spList->FUN_1407cb9c0("rowHeight", 0x39);
    if (FUN_140166410()->FUN_14036d570(0xdb)) {
        Unk_MHouseMap& map = FUN_1409eed80()->FUN_140886640();
        POSITION pos = map.GetStartPosition();
        while (pos) {
            unsigned int nKey = map.GetAt(pos)->m_key;
            MS2Ptr<Unk_MHouseRec> spRec(map.GetAt(pos)->m_value);
            ASObj row(2);
            reinterpret_cast<Unk_MObjSetter&>(row).FUN_140eba4a0("id", nKey);
            row.FUN_1409c48f0("level", spRec->m_nLevel);
            row.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(0x32, nKey));
            row.FUN_1407cbbe0("active", (int)spRec->m_nLevel <= (int)nCur);
            spList->FUN_1422dd230(row);
            map.GetNext(pos);
        }
    }
    FUN_140eb8b20();
}

// @0x140eb3010
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb3010(int nId)
{
    if (m_30.IsNull())
        return;
    FUN_140eb0540();
    if (!FUN_1403ed2d0()->FUN_141bd0cc0())
        return;
    MS2Ptr<Unk_MHouseRec> spHouse = FUN_1409eed80()->FUN_1408865b0(nId);
    if (spHouse.IsNull())
        return;
    if (!m_30.get())
        return;
    Unk_MFurnArray furn;
    MFurnTable()->FUN_140557920(nId, furn);
    qsort(furn.GetData(), furn.GetCount(), 0x10, &UIMasteryDialog::FUN_140eb8f40);
    ASDataProvider page(2);
    for (size_t i = 0; i < furn.GetCount(); i++) {
        MS2Ptr<Unk_MFurn> spFurn(furn[i]);
        MS2Ptr<Unk_MItemDef> spDef = FUN_14053f870(spFurn->FUN_1405494e0());
        if (spDef == 0)
            continue;
        if (!spFurn->m_bOwned && DAT_143ab2e20.FUN_1408fbe90(spFurn->FUN_1405494e0()).FUN_140534e50())
            continue;
        ASObj row(2);
        row.FUN_1409c0d20("id", spFurn->FUN_1405494e0());
        row.FUN_1407cba60("icon", spDef->FUN_14053fdd0());
        row.FUN_1407cbbe0("lock", FUN_140eb8cd0(MS2Ptr<Unk_MFurn>(spFurn)) == 0);
        reinterpret_cast<Unk_MPageArray&>(page).FUN_1422bbf00(row);
    }
    MPage(m_30)->FUN_140bbeaa0("setPage", page);
}

// @0x140eb3460
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb3460()
{
    if (!FUN_140166410()->FUN_14036d570(0x5a))
        return;
    int nTab = FUN_140eb8ac0();
    MS2Ptr<Unk_MLevelCtrl> spCtrl = FUN_140c02990(CString("m_magicScrollControl"));
    if (spCtrl.get()) {
        if (FUN_140166410()->FUN_14036d570(0xd1))
            spCtrl->Invoke("setExpansion");
        int nG0 = FUN_14034f780()->FUN_14034e5e0(nTab, 4);
        int nG1 = FUN_14034f780()->FUN_14034e5e0(nTab, 5);
        int nG2 = FUN_14034f780()->FUN_14034e5e0(nTab, 6);
        MS2Ptr<Unk_MGroup> spGroup = spCtrl->FUN_140eb9cf0(CString("m_gradeGroup"));
        if (spGroup.get()) {
            int nSel = FUN_1409c1750(spGroup->FUN_1422baa20("selectedIndex"));
            if (nG1 == 0 && nSel == 1)
                spGroup->Invoke("setSelectedButtonByIndex", 0);
            if (nG2 == 0 && nSel == 2)
                spGroup->Invoke("setSelectedButtonByIndex", 0);
        }
        MS2Ptr<Unk_MToggle> spT0 = spCtrl->FUN_140e28bc0(CString("m_grade00"));
        if (spT0.get())
            spT0->vfunc_3(nG0);
        MS2Ptr<Unk_MToggle> spT1 = spCtrl->FUN_140e28bc0(CString("m_grade01"));
        if (spT1.get())
            spT1->vfunc_3(nG1);
        MS2Ptr<Unk_MToggle> spT2 = spCtrl->FUN_140e28bc0(CString("m_grade02"));
        if (spT2.get())
            spT2->vfunc_3(nG2);
    }
    MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
    if (!spList.get())
        return;
    spList->FUN_1422dd1d0();
    spList->FUN_1409c0dc0("itemRendererName", "UIMasteryDialog_renderer_mastery");
    spList->FUN_1407cb9c0("rowHeight", 0x4c);
    int nSub = FUN_140eb8410();
    int nSlot = FUN_140eb82e0();
    Unk_MScrollArray recs;
    FUN_14034f780()->FUN_14034e460(nTab, nSlot, nSub, recs);
    qsort(recs.GetData(), recs.GetCount(), 0x10, &UIMasteryDialog::FUN_140eb9160);
    if (recs.GetCount() == 0) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d74390(GetStringCommonByKey(CStringW(L"s_mastery_magicscroll_no_recipe")), 0, Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::FUN_140eb4e30));
        return;
    }
    for (size_t i = 0; i < recs.GetCount(); i++) {
        MS2Ptr<Unk_MScrollRec> spRec(recs[i]);
        if (spRec->m_nSlot != nSlot)
            continue;
        int nRank = spRec->m_result.vfunc_o18_1();
        CStringW strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(0x35, spRec->m_nId), nRank);
        CStringW strState = FUN_14062b4f0(CStringW(L"s_mastery_magicscroll_list_state"), &spRec->m_nState);
        ASObj row(2);
        row.FUN_1407cb9c0("id", spRec->m_nId);
        row.FUN_1407cbb20("name", CStringW(strName));
        row.FUN_1407cbb20("state", CStringW(strState));
        row.FUN_1407cb9c0("active", 1);
        row.FUN_1407cba60("icon", spRec->FUN_14034dbe0());
        row.FUN_1409adc90("grade", spRec->m_result.vfunc_o18_1());
        spList->FUN_1422dd230(row);
    }
    MS2Ptr<Unk_MLevelCtrl> spCtrl2 = FUN_140c02990(CString("m_magicScrollControl"));
    if (spCtrl2.get()) {
        MS2Ptr<Unk_MGroup> spGrade = spCtrl2->FUN_140eb9cf0(CString("m_gradeGroup"));
        if (spGrade.get())
            m_30c = FUN_1409c1750(spGrade->FUN_1422baa20("selectedIndex"));
        MS2Ptr<Unk_MGroup> spSlot = spCtrl2->FUN_140eb9cf0(CString("m_slotGroup"));
        if (spSlot.get())
            m_308 = FUN_1409c1750(spSlot->FUN_1422baa20("selectedIndex"));
    }
    FUN_140eb8b20();
}

// @0x140eb4210
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb4210(int nId)
{
    if (m_30.IsNull())
        return;
    if (!FUN_140166410()->FUN_14036d570(0x5a))
        return;
    FUN_140eb0540();
    if (!FUN_1403ed2d0()->FUN_141bd0cc0())
        return;
    MS2Ptr<Unk_MScrollRec> spRec = FUN_14034f780()->FUN_14034e3e0(nId);
    if (spRec.IsNull())
        return;
    ASObj page(2);
    page.FUN_1407cba60("binding0", m_require.FUN_140d43310(spRec->m_result.m_itemId, spRec->m_result.vfunc_o18_1(), spRec->m_result.m_count));
    for (size_t i = 0; i < spRec->m_rewards.GetCount(); i++) {
        ItemEntity& rew = spRec->m_rewards[i];
        size_t nNext = i + 1;
        page.FUN_1407cba60(FUN_140c43630("binding{0}", nNext), m_reward.FUN_140d43310(rew.m_itemId, rew.vfunc_o18_1(), rew.m_count));
    }
    int bEnough = 1;
    for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
        Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
        if (ref == 0)
            continue;
        unsigned int nHave;
        if (ref->m_b == 0)
            nHave = DAT_143ab2a90.FUN_140a5f180(ref->m_a, 0);
        else
            nHave = DAT_143ab2a90.FUN_140a5f7b0(ref->m_b, 0);
        unsigned int nNeed = ref->m_c;
        if (nHave < nNeed)
            bEnough = 0;
        CStringW strCnt = FUN_1419021b0(nHave, nNeed);
        int nRank = FUN_14053feb0(ref->m_a);
        ASObj req(2);
        req.FUN_1407cba60("binding", m_mastery.FUN_140d43310(ref->m_a, nRank, ref->m_c));
        req.FUN_1407cbb20("itemCnt", CStringW(strCnt));
        page.FUN_1409eb270(FUN_140c43630("require{0}", i), req);
    }
    int bWarn = 1;
    int nSlot = FUN_140eb82e0();
    if (nSlot == 1 || nSlot == 3 || nSlot == 2)
        bWarn = (nSlot == FUN_140eb6870());
    int nRank = spRec->m_result.vfunc_o18_1();
    CStringW strName = FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(0x35, nId), nRank);
    CStringW strState = FUN_14062b4f0(CStringW(L"s_mastery_magicscroll_list_state"), &spRec->m_nState);
    page.FUN_1407cb9c0("id", nId);
    page.FUN_1407cbb20("name", CStringW(strName));
    page.FUN_1407cba60("icon", spRec->FUN_14034dbe0());
    page.FUN_1409adc90("grade", spRec->m_result.vfunc_o18_1());
    page.FUN_1409c1180("meso", spRec->m_nMeso);
    page.FUN_1407cbb20("mastery", CStringW(strState));
    page.FUN_1407cbbe0("enabled", bEnough && !m_craft.HasTotal());
    page.FUN_1409c0dc0("goto", bWarn ? "normal" : "warn");
    page.FUN_1407cbbe0("debug", FUN_14116d720(FUN_14025e7c0()));
    m_30->Invoke("setPage", page);
}

// @0x140eb4ba0
void UIMasteryDialog::FUN_140eb4ba0()
{
    if (FUN_140eb5040() != 3)
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
        FUN_140eb5260(nType);
}

// @0x140eb4c70
bool UIMasteryDialog::FUN_140eb4c70(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    FUN_140eb6c80();
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
bool UIMasteryDialog::FUN_140eb4d40(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    FUN_140eb6c80();
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
bool UIMasteryDialog::FUN_140eb4e30(int nResult, const CMsgBoxData&)
{
    if (nResult == 0) {
        MS2Ptr<Unk_MLevelCtrl> spCtrl = FUN_140c02990(CString("m_magicScrollControl"));
        if (spCtrl.get()) {
            spCtrl->Invoke("setSelectedSlotIndex", m_308);
            spCtrl->Invoke("setSelectedGradeIndex", m_30c);
        }
        FUN_140eb3460();
    }
    return true;
}

// @0x140eb4f60
void UIMasteryDialog::vfunc_2(void* pArg)
{
    UIDialog* pDlg = this;
    if (pDlg->vfunc_55() == 0)
        FUN_140eb6660(pArg);
}

// @0x140eb4fd0
void UIMasteryDialog::vfunc_4(void* pArg, int)
{
    UIDialog* pDlg = this;
    if (pDlg->vfunc_55() == 0)
        FUN_140eb6660(pArg);
}

// @0x140eb5040
int UIMasteryDialog::FUN_140eb5040()
{
    if (m_30.IsNull())
        return -1;
    MS2Ptr<Unk_MGroup> spTab = FUN_140eb9db0(CString("m_mainTab"));
    if (spTab.IsNull())
        return -1;
    return FUN_1409c1750(spTab->FUN_1422baa20("selectedIndex"));
}

// @0x140eb5150
int UIMasteryDialog::FUN_140eb5150()
{
    if (m_30.IsNull())
        return -1;
    MS2Ptr<Unk_MSubTab> spTab = FUN_140c02870(CString("m_subTab"));
    if (spTab.get() == 0)
        return -1;
    return FUN_1409c1750(spTab->FUN_1422baa20("selectedIndex"));
}

// @0x140eb5260
void UIMasteryDialog::FUN_140eb5260(int nType)
{
    if (vfunc_55())
        return;
    if (FUN_140eb8a90() != nType)
        return;
    m_nPendingSub = nType;
}

// @0x140eb52c0
void UIMasteryDialog::FUN_140eb52c0(int nType)
{
    if (vfunc_55())
        return;
    if (FUN_140eb8a90() != nType)
        return;
    m_nPendingList = nType;
}

// @0x140eb5320
void UIMasteryDialog::FUN_140eb5320(NotifyObject* pNotify)
{
    NotifyDamagedMyPC* p = dynamic_cast<NotifyDamagedMyPC*>(pNotify);
    if (p) {
        if (!p->m_pDamage)
            return;
        if (p->m_pDamage->FUN_14175ac30() < 0)
            FUN_140eb6c80();
    }
}

// @0x140eb53a0
void UIMasteryDialog::FUN_140eb53a0()
{
    switch (FUN_140eb5040()) {
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
    int nTab = FUN_140eb5040();
    if (-1 < nTab) {
        if (nTab < 2) {
            FUN_140eb1770(nIndex, false);
        } else if (nTab == 2) {
            int nSlot = FUN_140eb86b0();
            if (nSlot == 8)
                FUN_140eb3010(nIndex);
            else if (nSlot == 9)
                FUN_140eb1770(nIndex, false);
        } else if (nTab == 3) {
            FUN_140eb4210(nIndex);
        }
    }
    m_nSelected = nIndex;
    MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
    if (spList.get())
        m_268[FUN_140eb86b0()] = spList->FUN_1422dccd0();
}

// @0x140eb55e0
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb55e0(int nId)
{
    MS2Ptr<Unk_MRec> spRec = FUN_1409670c0()->FUN_14066aa00(nId);
    if (spRec.IsNull())
        return;
    int nPoints = FUN_140e5ca20()->FUN_140b6d470(spRec->m_nId);
    if (nPoints != 0) {
        FUN_140e5ca20()->FUN_140b6d710(nPoints);
        return;
    }
    if (spRec->m_rewards.GetCount() == 0)
        return;
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
        ent.m_count = FUN_140eb7b40(spRec->m_nType, spRec->m_nNeedMastery, ref->m_c);
        ingredients.Add(ent);
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x23, GetStringCommonByKey(CStringW(L"s_craft_messagebox_desc")), static_cast<IMessageListener*>(this), CStringW(L""));
    if (spBox.get()) {
        spBox->FUN_140533ff0(spRec->m_nId);
        FUN_141a015d0(spBox.get(), GetStringCommonByKey(CStringW(L"s_craft_messagebox_title")));
        spBox->FUN_141a01690(GetStringCommonByKey(CStringW(L"s_word_cancel")), GetStringCommonByKey(CStringW(L"s_word_craft")), CStringW(L""));
        int nHave = FUN_140eb6d40(0, spRec->m_nId);
        spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 1, nHave, spRec->m_nMeso, 1);
        spBox->FUN_141a024a0(0);
        FUN_141a02a30(spBox.get(), ingredients);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::FUN_140eb4c70));
        FUN_140d73c60(spBox);
    }
}

// @0x140eb5e30
void UIMasteryDialog::FUN_140eb5e30(int nId)
{
    FUN_140eb55e0(nId);
}

// @0x140eb5e60
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb5e60(int nId)
{
    MS2Ptr<Unk_MScrollRec> spRec = FUN_14034f780()->FUN_14034e3e0(nId);
    if (spRec.IsNull())
        return;
    if (DAT_143ab2898 < spRec->m_nMeso) {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    if (spRec->m_result.m_itemId == 0 && spRec->m_rewards.GetCount() == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem);
    if (!spItem->FUN_140523c40(spRec->m_result.m_itemId, spRec->m_result.vfunc_o18_1(), 0))
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
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x23, GetStringCommonByKey(CStringW(L"s_magicscroll_craft_messagebox_desc")), static_cast<IMessageListener*>(this), CStringW(L""));
    if (spBox.get()) {
        spBox->FUN_140533ff0(spRec->m_nId);
        FUN_141a015d0(spBox.get(), GetStringCommonByKey(CStringW(L"s_magicscroll_craft_messagebox_title")));
        spBox->FUN_141a01690(GetStringCommonByKey(CStringW(L"s_word_cancel")), GetStringCommonByKey(CStringW(L"s_magicscroll_word_craft")), CStringW(L""));
        int nHave = FUN_140eb6d40(1, spRec->m_nId);
        spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 1, nHave, (int)spRec->m_nMeso, 1);
        spBox->FUN_141a024a0(0);
        FUN_141a02a30(spBox.get(), ingredients);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMasteryDialog::FUN_140eb4d40));
        FUN_140d73c60(spBox);
    }
}

// @0x140eb6660
void UIMasteryDialog::FUN_140eb6660(void* pArg)
{
    CItem* pItem = static_cast<CItem*>(pArg);
    if (!pItem)
        return;
    int nItemId = pItem->FUN_1405276c0();
    int nTab = FUN_140eb5040();
    if (nTab == 1) {
        int nType = FUN_140eb8a90();
        if (FUN_1409670c0()->FUN_14066b910(nType, nItemId) != 0)
            FUN_140eb52c0(nType);
    } else if (nTab == 3) {
        if (FUN_140166410()->FUN_14036d570(0x5a)) {
            MS2Ptr<Unk_MScrollRec> spRec = FUN_14034f780()->FUN_14034e3e0(m_nSelected);
            if (spRec.get()) {
                bool bFound = false;
                for (size_t i = 0; i < spRec->m_ingredients.FUN_14026bee0(); i++) {
                    Unk_IngRef ref = spRec->m_ingredients.FUN_14026bdc0(i);
                    if (ref == 0)
                        continue;
                    if (ref->m_b != 0 && pItem->FUN_1405277e0(ref->m_b)) {
                        bFound = true;
                        break;
                    }
                    if (ref->m_a == nItemId) {
                        bFound = true;
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
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return 0;
    MS2Ptr<Unk_MJobRec> spJob = FUN_1401d7a50()->FUN_140644880(FUN_141654700(pPc));
    if (spJob.IsNull())
        return 0;
    return spJob->m_n20;
}

// @0x140eb6920
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
void UIMasteryDialog::FUN_140eb6920(int nType, int nIndex, ASObj& obj)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    unsigned int nNeed = FUN_1409670c0()->FUN_14066b310(nType, nIndex);
    unsigned int nId = FUN_1409670c0()->FUN_14066b500(nType, nIndex);
    obj.FUN_1409c0d20("id", nId);
    obj.FUN_1409c0d20("level", nNeed);
    obj.FUN_1407cbb20("levelStr", FUN_1409670c0()->FUN_14066c690(nType, nIndex));
    int nFlag = 0;
    DAT_143ab31a0.FUN_140361ab0(nId, &nFlag);
    CString strState;
    if (nFlag == 0 && FUN_140e5ca20()->FUN_140b6d250(nType, nIndex) != 0)
        strState = (FUN_141662750(pPc, nType) < nNeed) ? "lock" : "active";
    else
        strState = "inactive";
    obj.FUN_1407cba60("state", CString(strState));
    Unk_MItemArray items;
    FUN_1409670c0()->FUN_14066b100(nId, FUN_141654700(pPc), items);
    if (items.GetCount() != 0) {
        ItemEntity& item0 = items[0];
        obj.FUN_1407cba60("binding", m_mastery.FUN_140d43310(item0.m_itemId, item0.vfunc_o18_1(), item0.m_count));
    }
}

// @0x140eb6c80
void UIMasteryDialog::FUN_140eb6c80()
{
    if (m_craft.HasTotal()) {
        Unk_MCastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
        BOOL bSame = m_nSelected == m_craft.m_nId;
        m_craft.FUN_140eadda0();
        if (bSame)
            FUN_140eb5450(m_nSelected);
    }
}

// @0x140eb6d40
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
int UIMasteryDialog::FUN_140eb6d40(int nKind, int nId)
{
    int nMax = 1000;
    if (nKind == 0) {
        MS2Ptr<Unk_MRec> spRec = FUN_1409670c0()->FUN_14066aa00(nId);
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
            int nNeed = FUN_140eb7b40(spRec->m_nType, spRec->m_nNeedMastery, ref->m_c);
            if (ref->m_b == 0)
                nHave = DAT_143ab2a90.FUN_140a5f180(ref->FUN_14026b500(), 0);
            else
                nHave = DAT_143ab2a90.FUN_140a5f780(ref->m_b, 0);
            int nCan = nHave / nNeed;
            nMax = (std::min)(nCan, nMax);
        }
        return nMax;
    } else if (nKind == 1) {
        MS2Ptr<Unk_MScrollRec> spRec = FUN_14034f780()->FUN_14034e3e0(nId);
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
            if (ref->m_b == 0)
                nHave = DAT_143ab2a90.FUN_140a5f180(ref->m_a, FUN_14053feb0(ref->m_a));
            else
                nHave = DAT_143ab2a90.FUN_140a5f7b0(ref->m_b, 0);
            int nNeed = ref->m_c;
            int nCan = nHave / nNeed;
            nMax = (std::min)(nCan, nMax);
        }
        return nMax;
    }
    MS2_ASSERT_AT(0x433, 0);
    return 0;
}

// @0x140eb71a0
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
CStringW UIMasteryDialog::FUN_140eb71a0(MS2Ptr<Unk_MRec> spRec)
{
    CStringW strErr;
    if (FUN_140eb8550(MS2Ptr<Unk_MRec>(spRec)) == 0)
        strErr = FUN_1409e8820(CStringW(L"s_mastery_need_level"), spRec->m_nNeedMastery);
    unsigned int nMastery = FUN_140eb7bb0(spRec->m_nType);
    if (nMastery < (unsigned int)spRec->m_nNeedMastery) {
        int nGrade = FUN_1409670c0()->FUN_14066af60(spRec->m_nType, spRec->m_nNeedMastery);
        CStringW strNeed = FUN_1405c2690(CStringW(L"s_mastery_need_mastery"), FUN_1409670c0()->FUN_14066c690(spRec->m_nType, nGrade));
        if (strErr.GetLength() == 0)
            return strNeed;
        return FUN_140656190(L"{0}, {1}", strErr, strNeed);
    }
    if (strErr.GetLength() >= 1)
        return strErr;
    if (FUN_1409670c0()->FUN_14066bb00(MS2Ptr<Unk_MRec>(spRec)) == 0) {
        int nCount = FUN_140eb6d40(0, spRec->m_nId);
        if (nCount == 1000)
            return FUN_14062b4f0(CStringW(L"s_mastery_manufacture_count_max"), &nCount);
        return FUN_14062b4f0(CStringW(L"s_mastery_manufacture_count"), &nCount);
    }
    CStringW strHome;
    if (FUN_1409670e0()->FUN_1410d2f10() == 0)
        return FUN_1409670c0()->FUN_14066c110(spRec->m_nType, spRec->m_nId, 1);
    int nType = spRec->m_nType;
    if (4 < nType && nType < 7) {
        if (!FUN_1409670e0()->FUN_1410d5640())
            strHome = GetStringCommonByKey(CStringW(L"s_mastery_otherhome"));
        else
            strHome = GetStringCommonByKey(CStringW(L"s_mastery_myhome"));
    }
    return FUN_140656190(L"{0} {1}", strHome, FUN_1409670c0()->FUN_14066c110(spRec->m_nType, spRec->m_nId, 1));
}

// @0x140eb79b0
// MS2-FUNCTIONAL: control flow follows the exe; temporaries differ.
int UIMasteryDialog::FUN_140eb79b0(int nType, unsigned int nNeedMastery, ItemEntity* pEntry)
{
    int nCount;
    if (FUN_1409670c0()->FUN_14066ba00(nType) == 0) {
        nCount = pEntry->m_count;
    } else {
        unsigned int nMastery = FUN_140eb7bb0(nType);
        nCount = FUN_1401c0db0()->FUN_140677c60(pEntry->m_count, nNeedMastery, nMastery);
    }
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc) {
        float fStat = 0;
        if (nType == 3)
            fStat = FUN_1416561a0(pPc)->FUN_1411e1110(0x43);
        else if (nType == 4)
            fStat = FUN_1416561a0(pPc)->FUN_1411e1110(0x47);
        else if (nType == 5)
            fStat = FUN_1416561a0(pPc)->FUN_1411e1110(0x44);
        else if (nType == 6)
            fStat = FUN_1416561a0(pPc)->FUN_1411e1110(0x48);
        float fOne = 1.0f;
        nCount = FUN_1406198a0(nCount, *(std::max)(&fStat, &fOne) + 1.0f);
    }
    return nCount;
}

// @0x140eb7b40
unsigned __int64 UIMasteryDialog::FUN_140eb7b40(int nType, int nNeedMastery, unsigned int nCount)
{
    if (FUN_1409670c0()->FUN_14066bb80(nType)) {
        unsigned int nMastery = FUN_140eb7bb0(nType);
        return FUN_1401c0db0()->FUN_140677e20(nCount, nNeedMastery, nMastery);
    }
    return nCount;
}

// @0x140eb7bb0
unsigned __int64 UIMasteryDialog::FUN_140eb7bb0(int nType)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return 0;
    return FUN_141662750(pPc, nType);
}

// @0x140eb7c00
void UIMasteryDialog::FUN_140eb7c00(int nType)
{
    unsigned int nMastery = FUN_140eb7bb0(nType);
    FUN_1409670c0()->FUN_14066af60(nType, nMastery);
}

// @0x140eb7c50
CStringW UIMasteryDialog::FUN_140eb7c50(int nType)
{
    CStringW strName = FUN_1409670c0()->FUN_14066bdd0(nType);
    int nRewards = FUN_140e5ca20()->FUN_140b6d140(nType);
    if (nRewards != 0)
        return FUN_140bfa7f0(CStringW(L"s_mastery_subtab_mastery_name_and_reward"), strName, nRewards);
    return strName;
}

// @0x140eb7d40
CStringW UIMasteryDialog::FUN_140eb7d40()
{
    CStringW strName = GetStringCommonByKey(L"s_mastery_housing");
    int nRewards = FUN_140930e10();
    if (nRewards != 0)
        return FUN_140bfa7f0(CStringW(L"s_mastery_subtab_mastery_name_and_reward"), strName, nRewards);
    return strName;
}

// @0x140eb7e30
void UIMasteryDialog::FUN_140eb7e30()
{
    if (m_30.IsNull())
        return;
    int nCount = FUN_140e5ca20()->FUN_140b6d140(3);
    nCount += FUN_140e5ca20()->FUN_140b6d140(5);
    if (FUN_140166410()->FUN_14036d570(0x59)) {
        int a = FUN_140e5ca20()->FUN_140b6d140(4);
        int b = FUN_140e5ca20()->FUN_140b6d140(6);
        nCount = nCount + a + b;
    }
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 0, 0 < nCount);
    nCount = FUN_140e5ca20()->FUN_140b6d140(7);
    nCount += FUN_140e5ca20()->FUN_140b6d140(8);
    if (FUN_140166410()->FUN_14036d570(0x59)) {
        int a = FUN_140e5ca20()->FUN_140b6d140(9);
        int b = FUN_140e5ca20()->FUN_140b6d140(10);
        nCount = nCount + a + b;
    }
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 1, 0 < nCount);
    nCount = FUN_140930e10();
    if (FUN_140166410()->FUN_14036d570(0x8d))
        nCount += FUN_140e5ca20()->FUN_140b6d140(0xb);
    MPage(m_30)->FUN_140eba2c0("setMainTabReward", 2, 0 < nCount);
    MPage(m_30)->FUN_140eba200("setMainTabReward", 3, 0);
}

// @0x140eb8120
int UIMasteryDialog::FUN_140eb8120(MS2Ptr<Unk_MRec> spRec)
{
    if (spRec == 0)
        return 0;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return 0;
    unsigned int nMastery = FUN_141662750(pPc, spRec->m_nType);
    int nValue = FUN_1409670c0()->FUN_14066ab90(spRec->m_nId, nMastery);
    float fBonus = 0.0f;
    int nType = spRec->m_nType;
    if (nType == 7)
        fBonus = FUN_1416561a0(pPc)->FUN_1411e1110(0x45);
    else if (nType == 8)
        fBonus = FUN_1416561a0(pPc)->FUN_1411e1110(0x46);
    else if (nType == 9)
        fBonus = FUN_1416561a0(pPc)->FUN_1411e1110(0x49);
    else if (nType == 10)
        fBonus = FUN_1416561a0(pPc)->FUN_1411e1110(0x4a);
    return FUN_1404820b0(nValue, fBonus + 1.0f);
}

// @0x140eb82e0
int UIMasteryDialog::FUN_140eb82e0()
{
    MS2Ptr<Unk_MLevelCtrl> spCtrl = FUN_140c02990(CString("m_magicScrollControl"));
    if (spCtrl.get() == 0)
        return 1;
    int nSlot = FUN_1409c1750(spCtrl->Invoke("getSelectedSlotIndex"));
    nSlot = nSlot + 1;
    if (nSlot < 0)
        nSlot = 0;
    if (m_2f8 < nSlot)
        nSlot = m_2f8;
    return nSlot;
}

// @0x140eb8410
int UIMasteryDialog::FUN_140eb8410()
{
    MS2Ptr<Unk_MLevelCtrl> spCtrl = FUN_140c02990(CString("m_magicScrollControl"));
    if (spCtrl.get()) {
        int nGrade = FUN_1409c1750(spCtrl->Invoke("getSelectedGradeIndex"));
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
int UIMasteryDialog::FUN_140eb8550(MS2Ptr<Unk_MRec> spRec)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return 0;
    if (spRec->m_nNeedLevel != 0)
        return (unsigned short)pPc->vfunc_78() >= spRec->m_nNeedLevel;
    return 1;
}

// @0x140eb8630
int UIMasteryDialog::FUN_140eb8630(int nType)
{
    if (nType < 0 || nType >= 0xc)
        return 0;
    return m_310[nType];
}

// @0x140eb8670
void UIMasteryDialog::FUN_140eb8670(int nType, int nValue)
{
    if (nType < 0 || nType >= 0xc)
        return;
    m_310[nType] = nValue;
}

// @0x140eb86b0
int UIMasteryDialog::FUN_140eb86b0()
{
    int nTab = FUN_140eb5040();
    int nSub = FUN_140eb5150();
    if (nSub < 0)
        return 0xe;
    ATL::CAtlArray<int> slots;
    if (nTab == 0) {
        slots.Add(0);
        slots.Add(1);
        if (FUN_140166410()->FUN_14036d570(0x59)) {
            slots.Add(2);
            slots.Add(3);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 1) {
        slots.Add(5);
        slots.Add(4);
        if (FUN_140166410()->FUN_14036d570(0x59)) {
            slots.Add(6);
            slots.Add(7);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 2) {
        slots.Add(8);
        if (FUN_140166410()->FUN_14036d570(0x8d))
            slots.Add(9);
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    } else if (nTab == 3) {
        if (FUN_140166410()->FUN_14036d570(0x5a)) {
            if (FUN_140166410()->FUN_14036d570(0x7c))
                slots.Add(10);
            if (FUN_140166410()->FUN_14036d570(0x7d))
                slots.Add(0xb);
            if (FUN_140166410()->FUN_14036d570(0x7e))
                slots.Add(0xc);
            if (FUN_140166410()->FUN_14036d570(0x7f))
                slots.Add(0xd);
        }
        if (nSub < (int)slots.GetCount())
            return slots[nSub];
    }
    return 0xe;
}

// @0x140eb89e0
int UIMasteryDialog::FUN_140eb89e0(int nSlot)
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
    return FUN_140eb89e0(FUN_140eb86b0());
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
    MS2Ptr<Unk_MList> spList = FUN_140c02900(CString("m_objectList"));
    if (spList.get()) {
        m_304 = 1;
        int nSlot = FUN_140eb86b0();
        spList->FUN_1422dcca0(-1);
        spList->vfunc_24(1);
        spList->FUN_1422dcca0(m_268[nSlot]);
        spList->vfunc_24(1);
        spList->FUN_1422e17f0(m_scroll[nSlot]);
        spList->vfunc_24(1);
        m_304 = 0;
    }
}

// @0x140eb8cd0
int FUN_140eb8cd0(MS2Ptr<Unk_MFurn> spFurn)
{
    unsigned short nCur = DAT_143ab291c;
    if (spFurn->m_n40 == 3)
        return 1;
    if (nCur < spFurn->m_w4c)
        return 0;
    MS2Ptr<Unk_MHouseRec> spHouse = FUN_1409eed80()->FUN_1408865b0(spFurn->m_n3c);
    nCur = DAT_143ab291c;
    if (spHouse.IsNull())
        return 0;
    if (nCur < spHouse->m_nLevel)
        return 0;
    if (spFurn->m_n44 == 0)
        return 1;
    return FUN_1406c7600()->FUN_140936640(spFurn->m_n44, spFurn->m_n48);
}

// @0x140eb8eb0
int FUN_140eb8eb0(MS2Ptr<Unk_MFurn> spFurn)
{
    if (spFurn->m_n40 == 1)
        return 1;
    if (spFurn->m_n40 == 3)
        return 2;
    return 3;
}

// @0x140eb8f40
int UIMasteryDialog::FUN_140eb8f40(const void* pA, const void* pB)
{
    MS2Ptr<Unk_MFurn> spA = *(const MS2Ptr<Unk_MFurn>*)pA;
    MS2Ptr<Unk_MFurn> spB = *(const MS2Ptr<Unk_MFurn>*)pB;
    int nLockA = FUN_140eb8cd0(spA);
    int nLockB = FUN_140eb8cd0(spB);
    if (nLockA == nLockB) {
        int nKindB;
        int nKindA = FUN_140eb8eb0(spA);
        nKindB = FUN_140eb8eb0(spB);
        if (nKindA == nKindB)
            return spA->m_n18 > spB->m_n18 ? 1 : -1;
        return nKindA > nKindB ? 1 : -1;
    }
    return nLockA != 0 ? -1 : 1;
}

// @0x140eb9160
int UIMasteryDialog::FUN_140eb9160(const void* pA, const void* pB)
{
    MS2Ptr<Unk_MScrollRec> spA = *(const MS2Ptr<Unk_MScrollRec>*)pA;
    MS2Ptr<Unk_MScrollRec> spB = *(const MS2Ptr<Unk_MScrollRec>*)pB;
    if (spA->m_nState == spB->m_nState) {
        MS2Ptr<Unk_MScrollDef> spDefA = FUN_14034f780()->FUN_14034e360(spA->m_n20);
        MS2Ptr<Unk_MScrollDef> spDefB = FUN_14034f780()->FUN_14034e360(spB->m_n20);
        if (spDefA.IsNull() || spDefB.IsNull())
            return -1;
        return spDefA->m_n1c < spDefB->m_n1c ? -1 : 1;
    }
    return spA->m_nState < spB->m_nState ? -1 : 1;
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
MS2Ptr<Unk_MGroup> FUN_140eb9620(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<Unk_MGroup> sp(new Unk_MGroup(v, nMovieId));
    return sp;
}

// @0x140eb9cf0
MS2Ptr<Unk_MGroup> Unk_MCtl::FUN_140eb9cf0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (!FUN_1409b4d40(v))
        return MS2Ptr<Unk_MGroup>(0);
    return FUN_140eb9620(m_nMovieId, v);
}

// @0x140eb9db0
MS2Ptr<Unk_MGroup> UIMasteryDialog::FUN_140eb9db0(const CString& strName)
{
    if (m_30.IsNull())
        return MS2Ptr<Unk_MGroup>(0);
    return reinterpret_cast<Unk_MCtl*>(m_30.get())->FUN_140eb9cf0(strName);
}

// @0x140eb9e40
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eb9e40(const char* szMethod, int a1, int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eb9f50
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eb9f50(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba060
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eba060(const char* szMethod, const AScript& a1, unsigned int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba120
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eba120(const char* szMethod, const AScript& a1, unsigned __int64 a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba200
Scaleform::GFx::Value Unk_MInvoker::FUN_140eba200(const char* szMethod, int a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba2c0
Scaleform::GFx::Value Unk_MInvoker::FUN_140eba2c0(const char* szMethod, int a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba380
Scaleform::GFx::Value Unk_MLevelCtrl::FUN_140eba380(const char* szMethod, unsigned __int64 a1, unsigned int a2, CStringW a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140eba4a0
void Unk_MObjSetter::FUN_140eba4a0(const char* szName, unsigned int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140eba610
unsigned __int64 FUN_140eba610(const void* p)
{
    return FUN_1401d49f0(p);
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
    FUN_14034ed60(p);
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// @0x140ebac90
void* FUN_140ebac90(void* p, unsigned int nFlags)
{
    FUN_14066d5b0(p);
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// @0x140ebacd0
void* FUN_140ebacd0(void* p, unsigned int nFlags)
{
    FUN_14056c300(p);
    if (nFlags & 1)
        operator delete(p, (size_t)0x10);
    return p;
}

// @0x140ebae70
Unk_MMapNode* FUN_140ebae70(Unk_MMapRaw* pMap, Unk_MMapNode* pNode)
{
    Unk_MMapNode* pNext;
    if (pNode == 0) {
        pNext = 0;
    } else if (pNode->m_pNext == 0) {
        pNext = 0;
        unsigned __int64 nHash = FUN_140889fd0(pNode);
        unsigned int nBin = (unsigned int)((nHash & 0xffffffff) % (unsigned __int64)pMap->m_nBins);
        while (nBin = nBin + 1, pNext == 0 && nBin < pMap->m_nBins) {
            if (pMap->m_ppBins[nBin] != 0)
                pNext = pMap->m_ppBins[nBin];
        }
    } else {
        pNext = pNode->m_pNext;
    }
    return pNext;
}

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
            FUN_140159b70(0x80004005);
    } while (0);
    void* pNode = p;
    return pNode;
}

// @0x140ebb020
unsigned int Unk_MHousing::GetMaxLevel()
{
    return m_nMaxLevel;
}

// @0x140ebb030
Unk_MMapNode* FUN_140ebb030(Unk_MMapRaw* pMap, Unk_MMapNode** ppPos)
{
    do {} while (0);
    Unk_MMapNode* pOld = *ppPos;
    Unk_MMapNode* pNext = FUN_140ebae70(pMap, pOld);
    *ppPos = pNext;
    return pOld;
}

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
            FUN_140159b70(0x80004005);
    } while (0);
    char* pNode = p;
    return pNode + 8;
}

// @0x140ebb170
bool FUN_140ebb170(const Scaleform::GFx::Value* v)
{
    return FUN_1407cccd0(v) == 9;
}

// @0x140ebb1b0
bool FUN_140ebb1b0(Unk_MMapRaw* pMap)
{
    return pMap->m_nElements == 0;
}

// @0x140ebb1e0
bool FUN_140ebb1e0(const Scaleform::GFx::Value* v)
{
    return FUN_1407cccd0(v) == 3;
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
MS2_REPLACE_METHOD(0x140EB4C70, UIMasteryDialog, FUN_140eb4c70, 200, 0x6AB6368B);
MS2_REPLACE_METHOD(0x140EB4D40, UIMasteryDialog, FUN_140eb4d40, 221, 0xEC9AAF40);
MS2_REPLACE_METHOD(0x140EB4E30, UIMasteryDialog, FUN_140eb4e30, 284, 0x3D7166D4);
MS2_REPLACE_METHOD(0x140EB5040, UIMasteryDialog, FUN_140eb5040, 262, 0x20B8A843);
MS2_REPLACE_METHOD(0x140EB5150, UIMasteryDialog, FUN_140eb5150, 262, 0x96FE42B1);
MS2_REPLACE_METHOD(0x140EB5260, UIMasteryDialog, FUN_140eb5260, 76, 0x2CC1527B);
MS2_REPLACE_METHOD(0x140EB52C0, UIMasteryDialog, FUN_140eb52c0, 76, 0x88AF847F);
MS2_REPLACE_METHOD(0x140EB53A0, UIMasteryDialog, FUN_140eb53a0, 168, 0xE87AEB17);
MS2_REPLACE_METHOD(0x140EB5450, UIMasteryDialog, FUN_140eb5450, 383, 0x59943791);
MS2_REPLACE_METHOD(0x140EB55E0, UIMasteryDialog, FUN_140eb55e0, 2107, 0xE774B82B);
MS2_REPLACE_METHOD(0x140EB5E30, UIMasteryDialog, FUN_140eb5e30, 32, 0x88F3761A);
MS2_REPLACE_METHOD(0x140EB5E60, UIMasteryDialog, FUN_140eb5e60, 2035, 0xF71AE862);
MS2_REPLACE_METHOD(0x140EB6660, UIMasteryDialog, FUN_140eb6660, 514, 0x8F8B8549);
MS2_REPLACE_METHOD(0x140EB6870, UIMasteryDialog, FUN_140eb6870, 165, 0xAD0EE20F);
MS2_REPLACE_METHOD(0x140EB6920, UIMasteryDialog, FUN_140eb6920, 847, 0x1994F4C2);
MS2_REPLACE_METHOD(0x140EB6C80, UIMasteryDialog, FUN_140eb6c80, 171, 0xA584C675);
MS2_REPLACE_METHOD(0x140EB6D40, UIMasteryDialog, FUN_140eb6d40, 1103, 0xDD4A5FC7);
MS2_REPLACE_METHOD(0x140EB71A0, UIMasteryDialog, FUN_140eb71a0, 2049, 0x55889835);
MS2_REPLACE_METHOD(0x140EB79B0, UIMasteryDialog, FUN_140eb79b0, 391, 0x4D8BEAD2);
MS2_REPLACE_METHOD(0x140EB7B40, UIMasteryDialog, FUN_140eb7b40, 102, 0x4F669A99);
MS2_REPLACE_METHOD(0x140EB7BB0, UIMasteryDialog, FUN_140eb7bb0, 62, 0x938E275E);
MS2_REPLACE_METHOD(0x140EB7C00, UIMasteryDialog, FUN_140eb7c00, 60, 0x46DE8ABD);
MS2_REPLACE_METHOD(0x140EB7C50, UIMasteryDialog, FUN_140eb7c50, 223, 0xB1E1DDF9);
MS2_REPLACE_METHOD(0x140EB7D40, UIMasteryDialog, FUN_140eb7d40, 228, 0x419DFDA2);
MS2_REPLACE_METHOD(0x140EB7E30, UIMasteryDialog, FUN_140eb7e30, 741, 0xAA124871);
MS2_REPLACE_METHOD(0x140EB8120, UIMasteryDialog, FUN_140eb8120, 431, 0x592D5F7A);
MS2_REPLACE_METHOD(0x140EB82E0, UIMasteryDialog, FUN_140eb82e0, 289, 0xDA605BC7);
MS2_REPLACE_METHOD(0x140EB8410, UIMasteryDialog, FUN_140eb8410, 300, 0xCF3E9804);
MS2_REPLACE_METHOD(0x140EB8550, UIMasteryDialog, FUN_140eb8550, 211, 0x84314BC4);
MS2_REPLACE_METHOD(0x140EB8630, UIMasteryDialog, FUN_140eb8630, 45, 0x6A62DAA1);
MS2_REPLACE_METHOD(0x140EB8670, UIMasteryDialog, FUN_140eb8670, 52, 0xA410EB4C);
MS2_REPLACE_METHOD(0x140EB86B0, UIMasteryDialog, FUN_140eb86b0, 806, 0xBECB6CA9);
MS2_REPLACE_METHOD(0x140EB89E0, UIMasteryDialog, FUN_140eb89e0, 119, 0xC05B67C2);
MS2_REPLACE_METHOD(0x140EB8A90, UIMasteryDialog, FUN_140eb8a90, 36, 0x9BF96619);
MS2_REPLACE_METHOD(0x140EB8AC0, UIMasteryDialog, FUN_140eb8ac0, 88, 0xA2E18639);
MS2_REPLACE_METHOD(0x140EB8B20, UIMasteryDialog, FUN_140eb8b20, 419, 0x27518734);
MS2_REPLACE_METHOD_VIA(0x140EB4F60, UIMasteryDialog, UIItemEventListener, vfunc_2, 91, 0xB308A7BA);
MS2_REPLACE_METHOD_VIA(0x140EB4FD0, UIMasteryDialog, UIItemEventListener, vfunc_4, 96, 0x85CF0DB2);
MS2_REPLACE_METHOD_VIA(0x140EAF840, UIMasteryDialog, ICastingEventListener, OnCastingFinished, 443, 0x4DD2CA94);
MS2_REPLACE_METHOD_VIA(0x140EAFA10, UIMasteryDialog, ICastingEventListener, OnCastingCancelled, 52, 0x5127663B);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca81c0-0x142ca82a0 .text$yd
