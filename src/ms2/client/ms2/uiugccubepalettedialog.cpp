// uiugccubepalettedialog.cpp - the cube palette of the UGC editor (UIUGCCubePaletteDialog, "UGCCubePaletteDialog",
// 0x4f16), its key controller (UGCKeyController + the two key modes) and the buy / install / remove flow of the picked
// cube. Header name assumed from the __FILE__ string.
// MS2-UNIT: ?\uiugccubepalettedialog.cpp
// MS2-RANGE: 0x140ee9c90-0x140ef4f10 .text$mn
// MS2-RANGE: 0x1400dd160-0x1400dd530 .text$di
// MS2-PIN: ??0?$MS2Ptr@VUIUGCItemEditDialog@@@@QEAA@PEAVUIUGCItemEditDialog@@@Z 0x140ef02e0
// MS2-PIN: ??1?$MS2Ptr@VUIUGCItemEditDialog@@@@QEAA@XZ 0x140ef0440
// MS2-PIN: ?AddRef@?$MS2Ptr@VUIUGCItemEditDialog@@@@AEBAXXZ 0x140ef18c0
// MS2-PIN: ?Reference@?$MS2Ptr@VUIUGCItemEditDialog@@@@CAXPEAVUIUGCItemEditDialog@@@Z 0x140ef1910
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUIUGCItemEditDialog@@@@AEBAXPEAX@Z 0x140ef1930
// MS2-PIN: ?Release@?$MS2Ptr@VUIUGCItemEditDialog@@@@AEAAXXZ 0x140ef19a0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUIUGCItemEditDialog@@@@AEAAXPEAX@Z 0x140ef1a30
// MS2-PIN: ??_EUIUGCCubePaletteDialog@@WBHI@EAAPEAXI@Z 0x140ef0770
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140ef0780
// MS2-PIN: ??1?$CRBMap@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAA@XZ 0x140ef0390
// MS2-PIN: ??0CNode@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAA@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef0310
// MS2-PIN: ??0CPair@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEAA@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef0360
// MS2-PIN: ?NewNode@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAPEAVCNode@12@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef0f80
// MS2-PIN: ?InsertImpl@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAPEAVCNode@12@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef0c50
// MS2-PIN: ?RBInsert@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEAAPEAVCNode@12@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef12b0
// MS2-PIN: ?Find@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEBAPEAVCNode@12@AEBW4Unk_UGCPaletteKey@@@Z 0x140ef08d0
// MS2-PIN: ?SetAt@?$CRBMap@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAPEAU__POSITION@@AEBW4Unk_UGCPaletteKey@@H@Z 0x140ef1720
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VUGCCube@UGCCubePalette@@@@QEBAPEAVUGCCube@UGCCubePalette@@XZ 0x140ef0740 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VUIUGCItemEditDialog@@@@QEBAPEAVUIUGCItemEditDialog@@XZ 0x140ef0760 ; unique
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@W4Unk_UGCPaletteKey@@@ATL@@SA_NAEBW4Unk_UGCPaletteKey@@0@Z 0x140ef0840 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4Unk_UGCPaletteKey@@@ATL@@SAHAEBW4Unk_UGCPaletteKey@@0@Z 0x140ef0890 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140ef09c0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140ef0b00 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBAAEBW4Unk_UGCPaletteKey@@PEAU__POSITION@@@Z 0x140ef0b30 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140ef0b90 ; unique
// MS2-PIN: ?vfunc_48@UIUGCCubePaletteDialog@@UEAAHXZ 0x140ef0be0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAAEAHPEAU__POSITION@@@Z 0x140ef0bf0 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEBA_NPEAVCNode@12@@Z 0x140ef0d50 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140ef0d90 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef0ea0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef0f10 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef11e0 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140ef15b0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140ef1610 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140ef1780 ; unique
// MS2-PIN: ?Successor@?$CRBTree@W4Unk_UGCPaletteKey@@HV?$CElementTraits@W4Unk_UGCPaletteKey@@@ATL@@V?$CElementTraits@H@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef17f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ef1a80 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140ef1ae0 ; unique
// MS2-PIN: ??$Call@VUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140ef1b20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIUGCCubePaletteDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140ef1b60 ; unique
// MS2-PIN: ??_GUGCKeyMode1@@UEAAPEAXI@Z 0x140ef4d10 ; prop
// MS2-PIN: ??_GUGCKeyMode@@UEAAPEAXI@Z 0x140ef4d90 ; prop
// MS2-PIN: ?vfunc_4@UGCKeyMode@@UEAAXPEAXMM@Z 0x140ef4df0 ; unique
// MS2-PIN: ?vfunc_3@UGCKeyMode@@UEAAXPEAXMM@Z 0x140ef4e10 ; unique
// MS2-PIN: ?vfunc_2@UGCKeyMode@@UEAAXPEAXMM@Z 0x140ef4e30 ; unique
// MS2-PIN: ?vfunc_6@UGCKeyMode@@UEAAXPEAXMM@Z 0x140ef4e50 ; unique
// MS2-PIN: ?vfunc_5@UGCKeyMode@@UEAAXPEAXMM@Z 0x140ef4e70 ; unique
// MS2-PIN: ?vfunc_7@UGCKeyMode@@UEAAXPEAXMMM@Z 0x140ef4e90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_iconPath@@YAXXZ 0x1400dd160
// MS2-PIN: ??__Es_itemCount@@YAXXZ 0x1400dd190
// MS2-PIN: ??__Es_itemID@@YAXXZ 0x1400dd1c0
// MS2-PIN: ??__Es_itemLock@@YAXXZ 0x1400dd1f0
// MS2-PIN: ??__Es_itemMaxCount@@YAXXZ 0x1400dd220
// MS2-PIN: ??__Es_itemName@@YAXXZ 0x1400dd250
// MS2-PIN: ??__Es_itemPrice@@YAXXZ 0x1400dd280
// MS2-PIN: ??__Es_label@@YAXXZ 0x1400dd2b0
// MS2-PIN: ??__Es_originPrice@@YAXXZ 0x1400dd2e0
// MS2-PIN: ??__Es_paymentIcon@@YAXXZ 0x1400dd310
// MS2-PIN: ??__Es_strBuyTypeNames@@YAXXZ 0x1400dd340
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400dd410
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400dd4d0
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400dd500
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugccubepalettedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/gfxmanager.h"

#include "uiugccubepalettedialog.h"
#include "ms2/client/ms2/cubemapinformationservice_2.h"   // C3: CubeHolderManager
#include "ms2/commonfiles/ugccubecategorytable.h"   // C3: the menu, sort and tab handles

#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/nipoint3.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/commonfiles/itemdatatable.h"   // C3: CItemDataTable::GetHousing
#include "ms2/client/ms2/fielddatacli.h"   // C3: WorldService::FUN_141bd30a0 returns MS2Ptr<CFieldDataCli>
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/placeholder/blockformat.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"   // C3: Unk_Int3, the cube cell
#include "ms2/placeholder/cube.h"   // C3: Cube (was the unit-local views Cube/Unk_CubeInfo)

// ---- statics (the .di initializers; the strings are the AS member names) ----

static CString s_iconPath("iconPath");
static CString s_itemCount("itemCount");
static CString s_itemID("itemID");
static CString s_itemLock("itemLock");
static CString s_itemMaxCount("itemMaxCount");
static CString s_itemName("itemName");
static CString s_itemPrice("itemPrice");
static CString s_label("label");
static CString s_originPrice("originPrice");
static CString s_paymentIcon("paymentIcon");
static CString s_strBuyTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- handles: a smart reference whose destructor is the exe function REL ----

template <void (*REL)(void*)>
struct Unk_Ref
{
    void* m_0;
    void* m_p;
    Unk_Ref() : m_0(0), m_p(0) {}
    ~Unk_Ref() { REL(this); }
};

void FUN_140888b50(void*);
void FUN_140888ac0(void*);
void FUN_140888b80(void*);
void FUN_140888af0(void*);
void FUN_140888bb0(void*);
void FUN_140888b20(void*);
void FUN_140acd6e0(void*);
void FUN_140a583d0(void*);
void FUN_140acd710(void*);
void FUN_14056c300(void*);
void FUN_1403e5630(void*);
void FUN_1401cd150(void*);

typedef Unk_Ref<FUN_140888b50> RTypeTbl;
typedef Unk_Ref<FUN_140888ac0> RTypeElem;
typedef Unk_Ref<FUN_140888b80> RSortTbl;
typedef Unk_Ref<FUN_140888af0> RSortElem;
typedef Unk_Ref<FUN_140888bb0> RCatTbl;
typedef Unk_Ref<FUN_140888b20> RCatElem;
typedef Unk_Ref<FUN_140acd6e0> RButton;
typedef Unk_Ref<FUN_140a583d0> RCheck;
typedef Unk_Ref<FUN_140acd710> RCubeList;
typedef Unk_Ref<FUN_14056c300> RItemMeta;
typedef Unk_Ref<FUN_1403e5630> Unk_UIRef;

class ASDialog : public ASDisplayObject
{
};

class Unk_SndMgr
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43(int a, int b, int c);
};

// ---- local views of the objects the unit talks to ----

// A control of the dialog (the AS display object of a list / combo / button / check box / edit).
class Unk_CubeCtl : public ASMovieClip
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

class UIMainPlayerInfo : public UIDialog   // C3: member view (real class not in this TU)
{
public:
    void SetHideReason(unsigned int a, bool b);
};

class UIHomeMenuDialog : public UIDialog
{
public:
    void FUN_140c29600(bool b);
};

class UIUGCHousingPointDialog : public UIDialog
{
public:
    int RefreshFoldButton();
};

class UIUGCItemEditDialog : public UIDialog
{
public:
    void SetEditItem(MS2Ptr<CItem> spItem);
};

// the input service and the key service
class Unk_InputSvc : public GFxManager
{
};

class Unk_KeySvc
{
public:
};

class CWindowService   // C3: member view (real class not in this TU)
{
public:
    int GetCursorClientPos(float*, float*);
};
class Unk_FpsSvc
{
public:
};

class Unk_UserSvc : public CFeatureManager
{
};

class Unk_ItemData
{
};


class Unk_CubeKind
{
public:
    int FUN_140ef4dd0();
    char m_pad[0x540];
    int m_540;
};

#include <ecr/PickService.h>

class Unk_CubeHolder : public Unk_PCCubeCraft
{
};

class Unk_KmPt   // private members: non-POD, so no /GS cookie
{
    float x, y, z;
};

class Unk_CubePlayer
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(Vector3 pt);
    virtual Unk_KmPt vfunc_20();   // a ctor-less point: the exe copies the return into the local
};

// NiPoint3 : efd::Point3 as a by-value efd::Point3 argument: the slice copies to a temp, then into the argument
struct Unk_PalNiPoint3 : Vector3 {};
// the refcounted cube manager (a COM-like interface: slot 1 AddRef, slot 2 Release)
class CubeMapInformationService   // C3: member view (real class not in this TU)
{
public:
    bool FUN_1410c3600(int);
    bool HasCubeAtPoint(Vector3 pt);
    class Cube* GetCubeAtPoint(Vector3 pt);
    bool FUN_1410c35c0();
    __int64 GetOwnerId(int nA, int nB);
    class Cube* FUN_1410b8790(Unk_Int3 pt);
    int FUN_1410cdd80(Vector3 ptFrom, Vector3 ptTo, float fDist, Unk_Int3 kOffset);
    bool FUN_1410d55d0(int a, int b);
};
class Unk_CubeMgr
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
void FUN_140ef2fb0();
CStringW FUN_140ef4540();
UIUGCCubePaletteDialog* FUN_140ef4a50(int nId);
UIHomeMenuDialog* FUN_140ef49b0(int nId);
UIUGCHousingPointDialog* FUN_140ef4af0(int nId);


struct Unk_CubeSpRef
{
    Unk_CubeMgr* m_p;
    Unk_CubeSpRef(Unk_CubeMgr* p) : m_p(p) { if (m_p) m_p->vfunc_1(); }
    ~Unk_CubeSpRef() { if (m_p) m_p->vfunc_2(); }
    // C3: FUN_140ef4cb0 is efd::SmartPointer<CubeMapInformationService>::operator== (below)
};


// 0x140885320 is MS2Ptr<CUgcItemLook>::get (the null test of the look pointer)





// ---- exe functions: managers and singletons ----

class Unk_WorldMgr : public WorldService
{
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CReservedWordTable;
class CItemDataTable;
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class UGCCubeCategoryTable;
class CGameOption;
class Unk_ItemPreview* FUN_1409bb9e0();   // C3: was FUN_1409bb9e0
class CMouseController;
class UISwfEntityManager* FUN_140b632f0();   // C3: was FUN_140b632f0
class UISwfEntityManager   // C3: member view
{
public:
    int FUN_1422d4e20(CStringA str);
};
int FUN_1418dd0c0();
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
UGCCubePalette* GetUGCCubePalette();
class Unk_CubeStock   // C3: member view for the former free stand-ins
{
public:
    int FUN_140dfcb00(int);
};

#include "ms2/client/ms2/warehouseitem.h"     // DAT_143ab2e20, the warehouse item table
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uioxquizdialog.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<CubeMapInformationService>::operator->
class ASTextInput : public ASMovieClip { public: CStringW GetText(); };   // C3: member view (astextinput.h clashes with the local ASUIComponent)
#include <NiPick.h>
#include <NiMesh.h>
#include <ecr/PickService.h>
class MS2StandardMaterial { public: static const NiRTTI ms_RTTI; };   // C3: the cube material RTTI
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
class CubeMapInformationService;   // C3: efd::SmartPointer<CubeMapInformationService>::operator->
extern Unk_CubeStock DAT_143ab2e50;
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
extern int DAT_1439f4a7c;
extern __int64 DAT_143ab2820;                   // the own account id
extern Unk_Int3 DAT_143ab2398;
extern unsigned char DAT_142e6b390[];
extern unsigned char DAT_142e6b1bc[];

// ---- tables ----

struct Unk_Arr16 { char* m_pData; unsigned __int64 m_nCount; };


bool FUN_140ef0630(RTypeTbl* p, __int64 n);
bool FUN_140ef0670(RSortTbl* p, __int64 n);
bool FUN_140ef06b0(RCatTbl* p, __int64 n);
void* FUN_140ef0750(RCatTbl* p);
// C3: FUN_14088cfc0 / FUN_14088d5d0 are Unk_CubePtr<TabInfo>::AddRef / Release,
// reached through the Unk_CubePtrAccess friend (FUN_140ef0500 below).
unsigned __int64 FUN_140ef0ae0(void* pTbl);
unsigned __int64 FUN_140ef0af0(void* pTbl);
void* FUN_140ef0a60(void* pTbl, unsigned __int64 n);
void* FUN_140ef0aa0(void* pTbl, unsigned __int64 n);
struct Unk_CubePtrAccess { static UGCCubeCategoryTable::TabPtr* FUN_140ef0500(UGCCubeCategoryTable::TabPtr* pDst, UGCCubeCategoryTable::TabPtr* pSrc); };
bool FUN_140ef05f0(RSortElem* p, __int64 n);
unsigned char FUN_140930c50();
unsigned char FUN_140930ce0();

// ---- controls ----

// the UISwfEntity::GetChild<T> instances: members returning the handle by value, named by the literal
class UIItemPetBoxDialog   // C3: was Unk_UcpChildGet
{
public: MS2Ptr<ASCheckBox> FindCheckBox(const CString& strName);   // 0x140e52670
};
void FUN_140ba4b70(void* pDlg, RCubeList* pRet, const CString& strName);
class UIDailyMissionDialog   // C3: member view (the list getter folds with this unit's)
{
public:
    MS2Ptr<ASScrollingList> FUN_140c02900(const CString& strName);
};
int FUN_140ba4ee0(RCubeList* p, int n);
Unk_CubeCtl* FUN_140acd9f0(RCubeList* p);

// ---- items, strings, message boxes ----

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);
int FUN_140885250(RItemMeta* p, int n);
CStringW FUN_1409404f0(__int64 n);
CStringW GetStringCommon(int nStringId);
CStringW FUN_1418fec00(int nCurrency, __int64 nPrice, bool b);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* pOwner, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> sp);
void FUN_140d73aa0(CStringW strMsg, int n, void* pOwner, CStringW strTag);
void FUN_140d73bc0(int nStringId, int n, void* pOwner, CStringW strTag);
void FUN_141275260(int nStringId, int a, int b);
void FUN_1412752d0(const CStringW& strKey, int n);
class UIHomeInfoDialog   // C3: member view for the former free stand-ins
{
public:
    int FUN_1412c72d0();
};
class CGameOption   // C3: member view for the former free stand-ins
{
public:
    void SaveCharacterSettings();
    struct Unk_GoEtc* FUN_140c9b8b0();                      // 0x140c9b8b0 (&m_etc)
};
void FUN_140df5180(MS2Ptr<CUgcItemLook>* pDst, void* pSrc);
void XmlSetChildAttr(class TiXmlElement*, char const*, char const*, int, bool);   // C3: was FUN_140874440
void FUN_140df1e00();
void FUN_140df1e90(unsigned nBox, unsigned nItemId);
void FUN_140df1f40(unsigned int, unsigned int);   // C3: was FUN_140df1f40
void FUN_140df1ff0(unsigned int nId, ATL::CAtlList<unsigned int>* pList);
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()
void FUN_141925e70(int a, int b);
int FUN_14138c930(void* p, int n);
class CGuideManager   // C3: member view for the former free stand-ins
{
public:
    enum TriggerType {};
    int IsActionRestricted(int);
    void AddTrigger(TriggerType, int, int);
};
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14116d840();
    bool FUN_14116d9c0(int, bool, int);
    bool FUN_14116da30(int, bool, int);
    bool FUN_14116db80(int, bool, int);
    bool FUN_14116dd30(int, bool, int);
};
int FUN_14151f6e0();
int FUN_1418dd110();
class CMouseController   // C3: member view for the former free stand-ins
{
public:
    int HasMode();
};
class ItemPreviewMgr   // C3: member view for the former free stand-ins
{
public:
    int IsHudOn();
    int OpenPreview(MS2Ptr<CItem> sp, int n);
};
class UIHomeInfoDialog* FUN_140bbea00(int);   // C3: was FUN_140bbea00
UIOxQuizDialog* FUN_140e01930(int nId);

// ---- world / editor ----

class UIMainPlayerInfo* FUN_140931900(int);   // C3: was FUN_140931900
class PCBase   // C3: member view for the former free stand-ins
{
public:
    __int64 FUN_141656a80();
    int IsDead();
};
int FUN_1408a18d0(__int64 p);
bool FUN_1408a07b0(int nMapId, int a, __int64 nAccountId);
Unk_Int3 FUN_1408a1430(NiPoint3 pt);
int FUN_1408b54c0(int nKind);
int FUN_1408b5570(int nKind);
int FUN_1408b5820(int nKind);
int FUN_1408b5aa0(int nKind);
int FUN_1408b5b50(int nKind);
class PC   // C3: member view for the former free stand-ins
{
public:
    int IsInCubeMode();
    int IsCubeMode1();
    int FUN_141659690();
    __int64 FUN_141656ad0();
    class CConstructionGuideObject* FUN_1416625b0();
};
class MyPC   // C3: member view for the former free stand-ins
{
public:
    void SendCraftModeOff();
    class Unk_PCCubeCraft* GetActiveCubeCraft();
    void FUN_14152f140(__int64);
};
class CReservedWordTable   // C3: member view (real class not in this TU)
{
public:
    void ReplaceValueWords(CStringW&);
};


UIUGCItemEditDialog* FUN_140eeff60(int nId);


class Unk_ItemEventSystem   // C3: member view (real class not in this TU)
{
public:
    void FUN_1419cae20(UIItemEventListener*);
    void FUN_1419caeb0(UIItemEventListener*);
};
struct Unk_ItemEvtMgr
{
};
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
extern unsigned char DAT_142e6b398[];
extern const char DAT_142e6b3a0[];   // "sort"
extern unsigned char DAT_142e6b224[];
__int64 GetServerTime();
void FUN_140710590(COutPacket& p);
struct Unk_CubeUiData { __int64 m_0; __int64 m_8; };
// C3: the Unk_QnState view is now the CGameOption view's FUN_140c9b8b0
//
//
//

void FUN_140ef37d0();
void FUN_140ef3840();
void FUN_140ef3f00();
void FUN_140ef3f70();
void FUN_140ef3fc0();
void FUN_140ef4010();
void FUN_140ef41b0(int nIndex);
void FUN_140ef44f0();

// @0x140ef0000
void ASObj::FUN_140ef0000(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x140ef00a0
void ASObj::FUN_140ef00a0(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}


// @0x140ef4cb0
template <> bool efd::SmartPointer<CubeMapInformationService>::operator==(CubeMapInformationService* pObject) const
{
    return m_pObject == pObject;
}

// @0x140ef4dd0
int Unk_CubeKind::FUN_140ef4dd0()
{
    return m_540;
}

// MS2-PIN: ??1UGCKeyMode@@UEAA@XZ 0x140ef4c20 ; implicit virtual dtor (no vptr reset, like the exe)

// MS2-PIN: ??1UGCKeyMode1@@UEAA@XZ 0x140ef4be0 ; implicit virtual dtor (no vptr reset, like the exe)

// MS2-PIN: ??1UGCKeyMode2@@UEAA@XZ 0x140ef4c00 ; implicit virtual dtor (no vptr reset, like the exe)
// ---- cube focus / timer helpers ----

// @0x140ee9c90
Unk_CubeFocus::Unk_CubeFocus()
{
    m_bActive = false;
    m_nIndex = 0;
    m_nCubeId = 0;
}

// @0x140ee9cd0
bool Unk_CubeFocus::IsActive()
{
    return m_bActive;
}

// @0x140ee9cf0
void Unk_CubeFocus::FUN_140ee9cf0(int nIndex, int nCubeId)
{
    m_bActive = true;
    m_nIndex = nIndex < 0 ? 0 : nIndex;
    m_nCubeId = nCubeId;
}

// @0x140ee9d50
void Unk_CubeFocus::FUN_140ee9d50()
{
    m_bActive = false;
}

// @0x140ee9d70
int Unk_CubeFocus::FUN_140ee9d70()
{
    if (m_nCubeId == 0)
        return m_nIndex;
    UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByItemId(m_nCubeId);
    if (spCube.get() != 0)
        return (unsigned)(spCube->FUN_140defff0() - 1) < 0 ? 0 : spCube->FUN_140defff0() - 1;
    return m_nIndex;
}

// @0x140ee9e40
Unk_CubeTimer::Unk_CubeTimer()
{
    m_nValue = 0;
}

// @0x140ee9e80
bool Unk_CubeTimer::FUN_140ee9e80()
{
    if (m_timer.FUN_140868c00())
        return true;
    return false;
}

// @0x140ee9eb0
void Unk_CubeTimer::FUN_140ee9eb0(int n)
{
    m_timer.FUN_140868750(200);
    m_nValue = n < 0 ? 0 : n;
}

// @0x140ee9f00
void Unk_CubeTimer::FUN_140ee9f00()
{
    m_timer.FUN_1408687f0();
}

// @0x140ee9f30
int Unk_CubeTimer::GetValue()
{
    return m_nValue;
}

// ---- UIUGCCubePaletteDialog ----

// @0x140ee9f50
UIUGCCubePaletteDialog::UIUGCCubePaletteDialog()
    : m_map(10)
{
    m_80 = 1;
    m_88 = 1;
    m_58 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
    m_map.SetAt(Unk_UGCPaletteKey(2), 1);
    m_map.SetAt(Unk_UGCPaletteKey(3), 2);
    m_map.SetAt(Unk_UGCPaletteKey(4), 3);
    m_map.SetAt(Unk_UGCPaletteKey(5), 4);
    m_map.SetAt(Unk_UGCPaletteKey(6), 5);
    m_map.SetAt(Unk_UGCPaletteKey(7), 6);
    m_map.SetAt(Unk_UGCPaletteKey(8), 7);
    m_map.SetAt(Unk_UGCPaletteKey(9), 8);
    m_map.SetAt(Unk_UGCPaletteKey(10), 9);
    m_map.SetAt(Unk_UGCPaletteKey(11), 10);
}

// @0x140eea200
UIUGCCubePaletteDialog::~UIUGCCubePaletteDialog()
{
    ((Unk_ItemEventSystem*)(Unk_ItemEvtMgr*)(((struct Unk_ItemEvtMgr*)FUN_140a6a840())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
}

// @0x140eea300
CString UIUGCCubePaletteDialog::GetTypeName()
{
    return "UGCCubePaletteDialog";
}

// @0x140eea350
int UIUGCCubePaletteDialog::vfunc_53(void* pCfg)
{
    if (m_80 != 0)
    {
        ATL::CAtlList<int> list(10);
        FUN_140df1ff0(0x65, reinterpret_cast<ATL::CAtlList<unsigned int>*>(&list));
        for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
        {
            int nId = list.GetAt(pos);
            XmlSetChildAttr((class TiXmlElement*)(pCfg), (char const*)(DAT_142e6b390), (char const*)(DAT_142e6b1bc), nId, false);
        }
    }
    return 1;
}

// @0x140eea420
int UIUGCCubePaletteDialog::vfunc_54(void* pCfg)
{
    if (m_80 != 0)
    {
        FUN_140df1e00();
        for (void* pNode = ((void*)((class Unk_XmlNode*)(void*)(pCfg))->FirstChild((char const*)(DAT_142e6b398))); pNode != 0; pNode = ((void*)((class Unk_XmlNode*)(void*)(pNode))->NextSibling(DAT_142e6b3a0)))
        {
            int nId;
            XmlGetAttr((class TiXmlElement*)(pNode), (char const*)(DAT_142e6b224), *(unsigned int*)(&nId));
            FUN_140df1f40(0x65, nId);
        }
    }
    return 1;
}

// @0x140eea4b0 (UIItemEventListener slot 1: the dialog may be closed while the player is not building)
int UIUGCCubePaletteDialog::vfunc_il1()
{
    if (vfunc_55() != 0)    // the 0x1b8 slot of the UISwfEntity sub-object is vfunc_55 (closed)
        return 0;
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (((class PC*)(void*)(pPlayer))->FUN_141659690() != 0)
        return 0;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pPlayer))->GetActiveCubeCraft());
    if (pEditor == 0)
        return 0;
    return 1;
}

// @0x140eea550
void UIUGCCubePaletteDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    ((Unk_ItemEventSystem*)(Unk_ItemEvtMgr*)(((struct Unk_ItemEvtMgr*)FUN_140a6a840())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    m_focus.FUN_140ee9d50();
    m_timer.FUN_140ee9f00();
    m_filter = Unk_CubePaletteFilter();
    TSingleton<CUIService>::GetInstance()->FUN_141adbdc0(1);
}

// @0x140eea620
void UIUGCCubePaletteDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pPlayer))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (((class PC*)(void*)(pPlayer))->FUN_141659690() != 0)
        return;
    if (((class PC*)(void*)(pPlayer))->IsInCubeMode() == 0)
        return;
    FUN_140df1e00();
    FUN_140eeca50();
    FUN_140eefc50(1);
    ((class Unk_SndMgr*)((void*)GetClientPlatform()))->vfunc_43(0xe, 0, 1000);
    ((Unk_ItemEventSystem*)(Unk_ItemEvtMgr*)(((struct Unk_ItemEvtMgr*)FUN_140a6a840())))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
}

// @0x140eea720
void UIUGCCubePaletteDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.get());
    if (pDlg != 0)
    {
        int a = FUN_1418dd0c0();
        pDlg->vfunc_2(8, 5, (a + FUN_1418dd110()) * -1);
    }
}

// @0x140eea7c0
void UIUGCCubePaletteDialog::vfunc_15()
{
    if (FUN_1422dc2d0() == 0)
        return;
    m_keys.vfunc_0();
    if (m_focus.IsActive())
    {
        FUN_140eed620(1);
        m_focus.FUN_140ee9d50();
    }
    if (m_timer.FUN_140ee9e80())
    {
        FUN_140eeea80(m_timer.GetValue());
        m_timer.FUN_140ee9f00();
    }
}

// @0x140eea8a0
int UIUGCCubePaletteDialog::vfunc_13()
{
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (((class PC*)(void*)(pPlayer))->FUN_141659690() != 0)
    {
        // building mode: the quick-slot / rotate keys place the cube
        if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116dd30(0x493e2, 0, 0) != 0)
        {
            FUN_140ef37d0();
            return 1;
        }
        else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116dd30(0x49401, 0, 0) != 0)
        {
            FUN_140ef37d0();
            return 1;
        }
        unsigned int nCount = 0x19;
        for (unsigned int i = 0; i < nCount; i++)
        {
            int nKey = i + 0x7a121;
            if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116dd30(nKey, 0, 0) != 0)
            {
                FUN_140ef37d0();
                return 1;
            }
        }
    }
    else if (((class PC*)(void*)(pPlayer))->IsCubeMode1() != 0)
    {
        if (((class PC*)(void*)(pPlayer))->IsInCubeMode() == 0)
            return 0;
        if (((class Unk_CubeHolder*)((class MyPC*)(void*)(pPlayer))->GetActiveCubeCraft()) == 0)
            return 0;
        if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x1c, 0, 0) != 0)
        {
            // Enter in the search box
            if (((void*)FUN_140b632f0()) != 0)
            {
                if (FUN_140b632f0()->FUN_1422d4e20(m_20) == 0)
                    return 0;
            }
            ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.get());
            if (pDlg != 0)
            {
                if (MS2Ptr<ASTextInput> spEdit = GetChild<ASTextInput>("m_cubeSearch"))
                {
                    if (((class ASUIComponent*)(void*)(spEdit.operator->()))->GetFocused() != 0)
                    {
                        bool bEnter = ((class Unk_CubeCtl*)(void*)(spEdit.operator->()))->Invoke("processEnterKey").GetBool();
                        if (bEnter)
                        {
                            ((class ASUIComponent*)(void*)(pDlg))->SetFocused(1);
                            ((class ASUIComponent*)(void*)(spEdit.operator->()))->SetFocused(0);
                        }
                        FUN_140eef510(spEdit->GetText());
                    }
                    else
                    {
                        ((class ASUIComponent*)(void*)(pDlg))->SetFocused(0);
                        ((class ASUIComponent*)(void*)(spEdit.operator->()))->SetFocused(1);
                    }
                }
                return 1;
            }
        }
        else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0xe, 0, 0) != 0)
        {
            // Escape: leave the search box
            if (((void*)FUN_140b632f0()) != 0)
            {
                if (FUN_140b632f0()->FUN_1422d4e20(m_20) == 0)
                    return 0;
            }
            ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.get());
            if (pDlg != 0)
            {
                if (MS2Ptr<ASTextInput> spEdit = GetChild<ASTextInput>("m_cubeSearch"))
                {
                    if (((class ASUIComponent*)(void*)(spEdit.operator->()))->GetFocused() != 0)
                    {
                        FUN_140eef510(spEdit->GetText());
                    }
                }
                return 1;
            }
        }
        else
        {
            if (((class GFxManager*)(class Unk_InputSvc*)(((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())))->IsTextFieldFocused(m_28) == 0)
            {
                if (((class CInputKeyHandler*)(class Unk_KeySvc*)(((class Unk_KeySvc*)FUN_14025e7c0())))->FUN_14116d840() != 0)
                {
                    FUN_140ef4010();
                    return 1;
                }
                else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116dd30(0x493ed, 0, 0) != 0)
                {
                    if (FUN_14138c930(((void*)FUN_1409331e0()), 0x493ed) != 0)
                        return 0;
                    FUN_140ef4010();
                    return 1;
                }
                return FUN_140eee630();
            }
        }
    }
    return 0;
}

// @0x140eeaee0
void UIUGCCubePaletteDialog::vfunc_38(void* p, float x, float y)
{
    m_keys.vfunc_1(p, x, y);
}

// @0x140eeaf40
void UIUGCCubePaletteDialog::vfunc_32(void* p, float x, float y)
{
    m_keys.vfunc_2(p, x, y);
}

// @0x140eeafa0
void UIUGCCubePaletteDialog::vfunc_33(void* p, float x, float y)
{
    m_keys.vfunc_3(p, x, y);
}

// @0x140eeb000
void UIUGCCubePaletteDialog::vfunc_35(void* p, float x, float y)
{
    m_keys.vfunc_4(p, x, y);
}

// @0x140eeb060
void UIUGCCubePaletteDialog::vfunc_36(void* p, float x, float y)
{
    m_keys.vfunc_5(p, x, y);
}

// @0x140eeb0c0
void UIUGCCubePaletteDialog::vfunc_39(void* p, float x, float y, float f)
{
    m_keys.vfunc_6(p, x, y, f);
}

// @0x140eeb130 (UIItemEventListener slot 14: an item's uid / count changed)
void UIUGCCubePaletteDialog::vfunc_14(void* pItem)
{
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (((class PC*)(void*)(pPlayer))->IsInCubeMode() == 0)
        return;
    Unk_CubeHolder* pHolder = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pPlayer))->GetActiveCubeCraft());
    if (pHolder == 0)
        return;
    if (reinterpret_cast<CItemData*>(((CItem*)pItem)->FUN_140527840())->HasMaidId() != 0)
    {
        FUN_140eefc50(2);
        return;
    }
    int nItemId = ((CItem*)pItem)->FUN_1405276c0();
    __int64 nUid = ((CItem*)pItem)->GetItemUid();
    UGCCubePalette::CubeArray arr;
    reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetCubes(arr);
    for (unsigned int i = 0; i < arr.GetCount(); i++)
    {
        UGCCubePalette::CubePtr spCube = arr.GetAt(i);
        if (spCube == (UGCCubePalette::UGCCube*)0)
            continue;
        if (spCube->FUN_140def5a0() != nItemId)
            continue;
        if (((CItem*)pItem)->HasCubeTextureMesh() != 0)
        {
            if (spCube->FUN_140defba0() != (__int64)((CItem*)pItem)->GetUgcUid())
                continue;
        }
        spCube->FUN_140def3d0()->instanceId = nUid;
    }
    CubeItemInfo* pSel = pHolder->FUN_1410ad670();
    if (pSel != 0 && pSel->itemId == nItemId)
    {
        if (((CItem*)pItem)->HasCubeTextureMesh() != 0)
        {
            MS2Ptr<CUgcItemLook> spLook = pSel->look;
            if (spLook.get() ? true : false)
            {
                if (spLook->m_n18 == (__int64)((CItem*)pItem)->GetUgcUid())
                    pSel->instanceId = nUid;
            }
        }
        else
        {
            pSel->instanceId = nUid;
        }
    }
    FUN_140eefc50(2);
}

// @0x140eeb480
void UIUGCCubePaletteDialog::vfunc_15(void*)
{
    FUN_140eefc50(3);
}

// @0x140eeb4c0
void UIUGCCubePaletteDialog::vfunc_16(void*)
{
    FUN_140eefc50(4);
}

// @0x140eeb500
void UIUGCCubePaletteDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (_stricmp("getTooltipFromItemID", (const char*)strMethod) == 0)
    {
        int nIndex = pArgs->PopUInt() + 1;
        UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByIndex(nIndex);
        if (spCube == (UGCCubePalette::UGCCube*)0)
            return;
        MS2Ptr<CubeItemInfo> spInfo = spCube->FUN_140def3d0();
        if (spInfo == (CubeItemInfo*)0)
            return;
        int nItemId = spCube->FUN_140def5a0();
        __int64 nUid = spCube->FUN_140def5f0();
        int nRank = FUN_14053feb0(nItemId);
        __int64 nCount = spInfo->count;
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nItemId, nRank, 0) != 0)
        {
            spItem->SetItemUid(nUid);
            spItem->FUN_1405288e0(nCount);
            MS2Ptr<CUgcItemLook> spLook = spInfo->look;
            if (spLook.get() != 0)   // C3: the second get is the MS2Ptr<UGCKeyMode> fold, as below
                spItem->SetUgcLook(reinterpret_cast<CUgcItemLook*>(reinterpret_cast<MS2Ptr<UGCKeyMode>*>(&spLook)->get()));
            ASTooltip tooltip(pPlayer, 8, 2);
            if (tooltip.FUN_1409e0d40(spItem.get()) != 0)
            {
                tooltip.SetTooltipAlign(7);
                tooltip.FUN_1409db7b0(spItem);
                *pRetVal = tooltip.FUN_1422bb870();
            }
        }
    }
}

// @0x140eeb860
int UIUGCCubePaletteDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnItemChange", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int n = data.PopInt();
            FUN_140ef41b0(n + 1);
            FUN_140eefdd0(n);
        }
        return 1;
    }
    else if (_stricmp("OnCubeTypeChange", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_filter.category = data.PopUInt();
            m_filter.FUN_140df0180(data.PopUInt());
            FUN_140eed2d0();
            FUN_140eede00(m_filter.category);
            FUN_140eee160(m_filter.category, 0);
            FUN_140eefc50(7);
        }
        return 1;
    }
    else if (_stricmp("OnMainCategoryChange", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nMain = data.PopInt();
            FUN_140eee160(m_filter.category, nMain);
            FUN_140eefc50(7);
        }
    }
    else if (_stricmp("OnSubCategoryChange", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_filter.field10 = data.PopUInt();
            FUN_140eefc50(7);
        }
    }
    else if (_stricmp("OnSortCategoryChange", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_filter.FUN_140df0140(data.PopUInt());
            FUN_140eefc50(5);
        }
    }
    else if (_stricmp("OnUseableCube", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_filter.flag2 = data.PopBool();
            FUN_140eefc50(8);
        }
    }
    else if (_stricmp("OnOwnershipCube", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_filter.flag1 = data.PopBool();
            FUN_140eefc50(9);
        }
    }
    else if (_stricmp("onSearchCubeItem", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            const CStringW& strSearch = data.FUN_1422b8f40();
            FUN_140eef510(strSearch);
        }
    }
    else if (_stricmp("OnDestroyCubeItem", szMethod) == 0)
    {
        OnDestroyCubeItem();
    }
    else if (_stricmp("OnClickPreview", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopUInt() + 1;
            UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByIndex(nIndex);
            if (spCube == (UGCCubePalette::UGCCube*)0)
                return 0;
            MS2Ptr<CubeItemInfo> spInfo = spCube->FUN_140def3d0();
            if (spInfo == (CubeItemInfo*)0)
                return 0;
            int nItemId = spCube->FUN_140def5a0();
            __int64 nUid = spCube->FUN_140def5f0();
            int nRank = FUN_14053feb0(nItemId);
            __int64 nCount = spInfo->count;
            MS2Ptr<CItem> spItem(new CItem);
            if (spItem->FUN_140523c40(nItemId, nRank, 0) != 0)
            {
                spItem->SetItemUid(nUid);
                spItem->FUN_1405288e0(nCount);
                MS2Ptr<CUgcItemLook> spLook = spInfo->look;
                if (spLook.get() != 0)   // C3: the exe folds the second get onto MS2Ptr<UGCKeyMode>'s
                    spItem->SetUgcLook(reinterpret_cast<CUgcItemLook*>(reinterpret_cast<MS2Ptr<UGCKeyMode>*>(&spLook)->get()));
                if (((class ItemPreviewMgr*)(void*)(((void*)FUN_1409bb9e0())))->IsHudOn() != 0)
                    ((class ItemPreviewMgr*)(void*)(((void*)FUN_1409bb9e0())))->OpenPreview(spItem, 0);
            }
        }
    }
    else if (_stricmp("OnDoubleClickCube", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int n = data.PopUInt() + 1;
            FUN_140eef7e0(n);
            return 1;
        }
    }
    return 0;
}

// @0x140eec0b0
void UIUGCCubePaletteDialog::FUN_140eec0b0(unsigned __int64 uid)
{
    void* pPlayer = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (((class PC*)(void*)(pPlayer))->IsInCubeMode() == 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(uid);
    if (spItem == (CItem*)0)
        return;
    Unk_CubeHolder* pHolder = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pPlayer))->GetActiveCubeCraft());
    if (pHolder == 0)
        return;
    if (reinterpret_cast<CItemData*>(spItem->FUN_140527840())->HasMaidId())
    {
        FUN_140eed620(0);
        UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByInstanceId(uid);
        if (spCube.get() != 0)
        {
            int nItemId = spItem->FUN_1405276c0();
            __int64 nItemUid = spItem->GetItemUid();
            FUN_140eef560(spCube->FUN_140defff0());
            CubeItemInfo* pSel = pHolder->FUN_1410ad670();
            if (pSel != 0 && pSel->itemId == nItemId)
            {
                if (spItem->HasCubeTextureMesh())
                {
                    MS2Ptr<CUgcItemLook> spLook = pSel->look;
                    if (static_cast<bool>(spLook.get()))
                    {
                        if (spLook->m_n18 == (__int64)spItem->GetUgcUid())
                            pSel->instanceId = nItemUid;
                    }
                }
                else
                {
                    pSel->instanceId = nItemUid;
                }
            }
            FUN_140ef37d0();
        }
    }
    else
    {
        reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->SelectByInstanceId(uid);
        FUN_140ef37d0();
    }
}

// @0x140eec330 (delegate callback: the buy-cube message box was answered)
bool UIUGCCubePaletteDialog::FUN_140eec330(int nBtn, const CMsgBoxData& data)
{
    if (nBtn == 0)
    {
        UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelected();
        if (spCube == (UGCCubePalette::UGCCube*)0)
            return true;
        COutPacket pkt(static_cast<int>(SendOp::FurnishingStorage), 0);
        pkt.Encode1(6);
        pkt.Encode8(spCube->FUN_140def5f0());
        FUN_140710590(pkt);
    }
    return true;
}

// @0x140eec410
bool UIUGCCubePaletteDialog::FUN_140eec410(int nBtn, const CMsgBoxData& data)
{
    if (nBtn == 0)
    {
        if (const_cast<CMsgBoxData&>(data).IsCheckbox0Checked() != 0)
        {
            __int64 n = GetServerTime();
            ((struct Unk_CubeUiData*)((class CGameOption*)(void*)(TSingleton<CGameOption>::GetInstance()))->FUN_140c9b8b0())->m_8 = n;
            ((class CGameOption*)(void*)(TSingleton<CGameOption>::GetInstance()))->SaveCharacterSettings();
        }
        FUN_140ef37d0();
    }
    return true;
}

// @0x140eec480
void UIUGCCubePaletteDialog::FUN_140eec480()
{
    if (vfunc_il1() == 0)
        return;
    FUN_140eefc50(4);
}

// @0x140eec4d0 (the screen position of the list row of a cube type; false when the type or the row is missing)
int UIUGCCubePaletteDialog::FUN_140eec4d0(int nTypeId, Vector3* pPos)
{
    UGCCubeCategoryTable::MenuArrayPtr spTypes = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetMenus();
    if (FUN_140ef0630(reinterpret_cast<RTypeTbl*>(&spTypes), 0) != 0)
        return 0;
    MS2Ptr<ASDisplayObject> spRoot(dynamic_cast<ASDisplayObject*>(m_30.get()));
    if (spRoot == 0)
        return 0;
    MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_cubeTypeList");
    if (spList == 0)
        return 0;
    for (unsigned int i = 0; i < spTypes.operator->()->GetCount(); i++)
    {
        UGCCubeCategoryTable::MenuPtr spType(spTypes.operator->()->GetAt(i));
        if (spType == 0)
            continue;
        if ((FUN_140930c50() == 0 || spType.operator->()->m_nDelegator != 0) && spType.operator->()->m_nCategory == nTypeId)
        {
            *pPos = Vector3(spRoot->FUN_1422c10a0(), spRoot->FUN_1422c1110(), spRoot->GetZ());
            (*pPos += Vector3(((ASDisplayObject*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->FUN_1422c10a0(), ((ASDisplayObject*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->FUN_1422c1110(), ((ASDisplayObject*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->GetZ()));
            Scaleform::GFx::Value vRow = ((Unk_CubeCtl*)spList.operator->())->Invoke("getRendererAt", i);
            if (((Scaleform::GFx::Value*)(void*)(&vRow))->IsDisplayObject() == 0)
                return 0;
            MS2Ptr<ASDisplayObject> spRow(new ASDisplayObject(vRow, m_28));
            (*pPos += Vector3(spRow->FUN_1422c10a0(), spRow->FUN_1422c1110(), spRow->GetZ()));
            return 1;
        }
    }
    return 0;
}

// @0x140eeca50 (fill the controls from the filter)
void UIUGCCubePaletteDialog::FUN_140eeca50()
{
    m_filter.includeOwned = FUN_140930c50() == 0 ? true : false;
    FUN_140eecfe0();
    FUN_140eed2d0();
    if (MS2Ptr<ASScrollingList> spCtl = GetChild<ASScrollingList>("m_cubeTypeList"))
        spCtl->FUN_1422c1fe0(1);
    if (MS2Ptr<ASButton> spCtl = GetChild<ASButton>("m_buyCube"))
    {
        spCtl->FUN_1422c1fe0(0);
        ((Unk_CubeCtl*)(void*)(spCtl.operator->()))->vfunc_3(0);
    }
    if (MS2Ptr<ASCheckBox> spCtl = GetChild<ASCheckBox>("m_useable"))
    {
        spCtl->FUN_1422c1fe0(1);
        spCtl->FUN_1422ce090(m_filter.flag2);
    }
    if (MS2Ptr<ASCheckBox> spCtl = GetChild<ASCheckBox>("m_ownership"))
    {
        if (FUN_140930c50() != 0)
        {
            spCtl->FUN_1422c1fe0(0);
        }
        else
        {
            spCtl->FUN_1422c1fe0(1);
            spCtl->FUN_1422ce090(m_filter.flag1);
        }
    }
    if (MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_mainCategory"))
        spCtl->FUN_1422c1fe0(m_filter.FUN_140df00d0());
    if (MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_subCategory"))
        spCtl->FUN_1422c1fe0(m_filter.FUN_140df00d0());
    if (MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_sortCategory"))
        spCtl->FUN_1422c1fe0(m_filter.FUN_140df00d0());
}

// @0x140eecfe0 (fill the cube type list from the type table)
void UIUGCCubePaletteDialog::FUN_140eecfe0()
{
    UGCCubeCategoryTable::MenuArrayPtr spTypes = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetMenus();
    if (FUN_140ef0630(reinterpret_cast<RTypeTbl*>(&spTypes), 0) != 0)
        return;
    MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_cubeTypeList");
    if (spList == 0)
        return;
    for (unsigned int i = 0; i < spTypes.operator->()->GetCount(); i++)
    {
        UGCCubeCategoryTable::MenuPtr spType(spTypes.operator->()->GetAt(i));
        if (spType == 0)
            continue;
        if (FUN_140930c50() == 0 || spType.operator->()->m_nDelegator != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20((const char*)s_label, CStringW(spType.operator->()->m_strName));
            obj.FUN_1409c0d20("categoryID", spType.operator->()->m_nCategory);
            obj.FUN_140ef0000("filter", spType.operator->()->m_nFilter);
            ((class ASCoreList*)(class Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->AddItem(*(ASObj const*)&static_cast<ASObj&>(obj));
        }
    }
    int nIndex;
    if (((class ASCoreList*)(class Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->GetItemCount() > 7)
        nIndex = 7;
    else
        nIndex = ((class ASCoreList*)(class Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->GetItemCount();
    ((class ASCoreList*)(class Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->SetRowCount(nIndex);
    ((class ASCoreList*)(class Unk_CubeCtl*)(((Unk_CubeCtl*)spList.operator->())))->SetSelectedIndex(0);
    ((Unk_CubeCtl*)spList.operator->())->vfunc_24(1);
}

// @0x140eed2d0 (fill the sort list from the sort table)
void UIUGCCubePaletteDialog::FUN_140eed2d0()
{
    MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_sortCategory");
    if (spCtl == 0)
        return;
    if (m_filter.FUN_140df00d0())
    {
        UGCCubeCategoryTable::SortArrayPtr spSorts = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetSorts();
        if (FUN_140ef0670(reinterpret_cast<RSortTbl*>(&spSorts), 0) != 0)
            return;
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(1);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        for (unsigned int i = 0; i < FUN_140ef0ae0(spSorts.operator->()); i++)
        {
            UGCCubeCategoryTable::SortPtr spSort(*static_cast<UGCCubeCategoryTable::SortPtr*>(FUN_140ef0a60(spSorts.operator->(), i)));
            if (FUN_140ef05f0(reinterpret_cast<RSortElem*>(&spSort), 0) != 0)
                continue;
            ASObj obj(2);
            obj.FUN_1407cbb20((const char*)s_label, CStringW(spSort.operator->()->m_strName));
            obj.FUN_140ef00a0("sortOrder", spSort.operator->()->m_nOrder);
            ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->AddItemRow(obj);
        }
        int nIndex;
        if (((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount() > 5)
            nIndex = 5;
        else
            nIndex = ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount();
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetMenuRowCount(nIndex);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetSelectedIndex(0);
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
    }
    else
    {
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(0);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
    }
}

#ifndef MS2_HOOK_DLL
// @0x140eed620 (rebuild the cube list; nSelect: scroll to the focused cube)
void UIUGCCubePaletteDialog::FUN_140eed620(int nSelect)
{
    MS2Ptr<ASTileList> spList = GetChild<ASTileList>("m_cubeList");
    if (spList == (ASTileList*)0)
        return;
    UGCCubePalette::CubeArray arr;
    reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->LoadCubes(m_filter);
    reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetCubes(arr);
    spList.operator->()->FUN_1422dd1d0();
    for (unsigned int i = 0; i < arr.GetCount(); i++)
    {
        UGCCubePalette::CubePtr spCube = arr.GetAt(i);
        if (spCube == (UGCCubePalette::UGCCube*)0)
            continue;
        MS2Ptr<CItemData> spInfo = FUN_14053f870(spCube->FUN_140def5a0());
        if (spInfo == (CItemData*)0)
            continue;
        MS2Ptr<ItemHousing> spMeta = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spCube->FUN_140def5a0());
        if (spMeta == (ItemHousing*)0)
            continue;
        ASObj obj(2);
        obj.FUN_1409c0d20((const char*)s_itemID, spCube->FUN_140def5a0());
        obj.FUN_1407cbb20((const char*)s_iconPath, spCube->FUN_140def880());
        obj.FUN_1407cbbe0((const char*)s_itemLock, spCube->FUN_140def420());
        __int64 nCur = spCube->FUN_140def620();
        __int64 nMax = spCube->FUN_140def6c0();
        if (nCur < nMax)
        {
            float fRate = (float)nCur / (float)nMax;
            int nSale = (int)((1.0f - fRate) * 100.0f + 0.5f);
            CStringW strSale;
            strSale = FormatStringId<CStringW>(0x98e, StringFormat<int>(L"{0}", nSale));
            obj.FUN_1407cbb20("sale", CStringW(strSale));
        }
        if (spMeta->FUN_140549470(spCube->FUN_140def5a0(), spCube->FUN_140def5f0(), spCube->FUN_140defba0()) != 0)
            obj.FUN_1407cbb20((const char*)s_paymentIcon, spCube->FUN_140defd20());
        bool bDoubleClick = spInfo.operator->()->HasCubeTextureMesh() && (spCube->FUN_140def3d0().get() ? true : false) && spCube->FUN_140def3d0()->FUN_1408b3860() == 0;
        if (bDoubleClick)
            obj.FUN_1407cbbe0("enableDBClick", true);
        spList.operator->()->AddItem(*(ASObj const*)&static_cast<ASObj&>(obj));
    }
    if (nSelect != 0)
    {
        int nFocus = m_focus.FUN_140ee9d70();
        spList.operator->()->SetSelectedIndex(nFocus);
        reinterpret_cast<Unk_CubeCtl*>(spList.operator->())->vfunc_24(1);
        FUN_140ef41b0(nFocus + 1);
        FUN_140eefdd0(nFocus);
    }
    else
    {
        reinterpret_cast<Unk_CubeCtl*>(spList.operator->())->vfunc_24(1);
    }
}
#endif

// @0x140eede00 (fill the main category list of a cube type)
void UIUGCCubePaletteDialog::FUN_140eede00(int nCubeType)
{
    MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_mainCategory");
    if (spCtl == 0)
        return;
    if (m_filter.FUN_140df00d0())
    {
        UGCCubeCategoryTable::TabArrayPtr spCats = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetTabs(nCubeType);
        if (FUN_140ef06b0(reinterpret_cast<RCatTbl*>(&spCats), 0) != 0)
            return;
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(1);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        for (unsigned int i = 0; i < FUN_140ef0af0(FUN_140ef0750(reinterpret_cast<RCatTbl*>(&spCats))); i++)
        {
            UGCCubeCategoryTable::TabPtr spCat(*static_cast<UGCCubeCategoryTable::TabPtr*>(FUN_140ef0aa0(FUN_140ef0750(reinterpret_cast<RCatTbl*>(&spCats)), i)));
            if (spCat == 0)
                continue;
            if (FUN_140930c50() == 0 || spCat.operator->()->m_nDelegator != 0)
            {
                ASObj obj(2);
                obj.FUN_1407cbb20((const char*)s_label, CStringW(spCat.operator->()->m_strName));
                ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->AddItemRow(obj);
            }
        }
        int nIndex;
        if (((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount() > 0xf)
            nIndex = 0xf;
        else
            nIndex = ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount();
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetMenuRowCount(nIndex);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetSelectedIndex(0);
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
    }
    else
    {
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(0);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
    }
}

// @0x140eee160 (fill the sub category list of a main category)
void UIUGCCubePaletteDialog::FUN_140eee160(int nCubeType, unsigned int nMainCategory)
{
    MS2Ptr<ASDropdownMenu> spCtl = GetChild<ASDropdownMenu>("m_subCategory");
    if (spCtl == 0)
        return;
    if (m_filter.FUN_140df00d0())
    {
        UGCCubeCategoryTable::TabArrayPtr spCats = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetTabs(nCubeType);
        if (FUN_140ef06b0(reinterpret_cast<RCatTbl*>(&spCats), 0) != 0)
            return;
        if (FUN_140ef0af0(FUN_140ef0750(reinterpret_cast<RCatTbl*>(&spCats))) <= nMainCategory)
            return;
        UGCCubeCategoryTable::TabPtr spMain(*static_cast<UGCCubeCategoryTable::TabPtr*>(FUN_140ef0aa0(FUN_140ef0750(reinterpret_cast<RCatTbl*>(&spCats)), (__int64)(int)nMainCategory)));
        if (spMain == 0)
            return;
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(1);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        UGCCubeCategoryTable::TabPtr spFirst(0);
        for (unsigned int i = 0; i < FUN_140ef0af0(&spMain.operator->()->m_children); i++)
        {
            UGCCubeCategoryTable::TabPtr spSub(*static_cast<UGCCubeCategoryTable::TabPtr*>(FUN_140ef0aa0(&spMain.operator->()->m_children, i)));
            if (spSub == 0)
                continue;
            if (FUN_140930c50() == 0 || spSub.operator->()->m_nDelegator != 0)
            {
                ASObj obj(2);
                obj.FUN_1407cbb20((const char*)s_label, CStringW(spSub.operator->()->m_strName));
                obj.FUN_1409c0d20("categorylist", spSub.operator->()->m_nCategory);
                ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->AddItemRow(obj);
                if (spFirst == 0)
                    Unk_CubePtrAccess::FUN_140ef0500(&spFirst, &spSub);
            }
        }
        int nIndex;
        if (((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount() > 0xf)
            nIndex = 0xf;
        else
            nIndex = ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->GetItemCount();
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetMenuRowCount(nIndex);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->SetSelectedIndex(0);
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
        if (reinterpret_cast<MS2Ptr<UGCKeyMode>*>(&spFirst)->operator->() != 0)   // C3: the exe folds this operator-> onto MS2Ptr<UGCKeyMode>'s
            m_filter.field10 = spFirst.operator->()->m_nCategory;
    }
    else
    {
        m_filter.field10 = 0;
        ((ASMovieClip*)(Unk_CubeCtl*)(((Unk_CubeCtl*)spCtl.operator->())))->FUN_1422c1fe0(0);
        ((class ASDropdownMenu*)(((Unk_CubeCtl*)spCtl.operator->())))->ClearItems();
        ((Unk_CubeCtl*)spCtl.operator->())->vfunc_24(1);
    }
}

// @0x140eee630 (the hot keys of the palette; the player must not be building)
int UIUGCCubePaletteDialog::FUN_140eee630()
{
    if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x39, 0, 0) != 0)
    {
        if (FUN_14138c930(((void*)FUN_1409331e0()), 0x493ed) != 0)
            return 0;
        FUN_140eefe00();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x1e, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x1e) != 0)
            return 0;
        if (((class CMouseController*)(void*)(TSingleton<CMouseController>::GetInstance()))->HasMode() != 0)
            return 0;
        (TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e85)));
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x12, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x12) != 0)
            return 0;
        FUN_140ef3840();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x13, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x13) != 0)
            return 0;
        FUN_140ef3f00();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x11, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x11) != 0)
            return 0;
        if (((class CMouseController*)(void*)(TSingleton<CMouseController>::GetInstance()))->HasMode() != 0)
            return 0;
        FUN_140ef3f70();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x1f, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x1f) != 0)
            return 0;
        if (((class CMouseController*)(void*)(TSingleton<CMouseController>::GetInstance()))->HasMode() != 0)
            return 0;
        FUN_140ef3fc0();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x2e, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x2e) != 0)
            return 0;
        FUN_140ef44f0();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x7a, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x7a) != 0)
            return 0;
        reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GoToPrevPage();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x7f, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x7f) != 0)
            return 0;
        reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GoToNextPage();
        return 1;
    }
    else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(0x21, 0, 0) != 0)
    {
        if (((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->IsActionRestricted(0x21) != 0)
            return 0;
        reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->SelectNext();
        return 1;
    }
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        int nKey = m_map.GetKeyAt(pos);
        int nValue = m_map.GetValueAt(pos);
        if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116d9c0(nKey, 0, 0) != 0)
        {
            FUN_140eef670(nValue);
            return 1;
        }
    }
    return 0;
}

#ifndef MS2_HOOK_DLL
// @0x140eeea80 (select / preview the cube of a list row)
void UIUGCCubePaletteDialog::FUN_140eeea80(int nRow)
{
    int nIndex = nRow + 1;
    ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.operator AScript*());
    if (pDlg != 0)
    {
        UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByIndex(nIndex);
        if (spCube.get() != 0)
        {
            MS2Ptr<CItemData> spInfo = FUN_14053f870(spCube->FUN_140def5a0());
            if (spInfo == (CItemData*)0)
                return;
            MS2Ptr<ItemHousing> spMeta = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spCube->FUN_140def5a0());
            if (spMeta == (ItemHousing*)0)
                return;
            bool bHide = false;
            if (FUN_140930c50() != 0)
                bHide = true;
            unsigned int nCount = 0;
            unsigned int nMax = 0;
            if (!bHide)
            {
                nCount = spCube->FUN_140defe70();
                nMax = spCube->FUN_140defed0();
            }
            ASObj obj(2);
            obj.FUN_1409c0d20((const char*)s_itemID, spCube->FUN_140def5a0());
            obj.FUN_1407cbb20((const char*)s_itemName, spCube->FUN_140def710());
            obj.FUN_1407cbb20((const char*)s_iconPath, spCube->FUN_140def880());
            obj.FUN_1407cbbe0((const char*)s_itemLock, spCube->FUN_140def420());
            if (!bHide)
            {
                if (spInfo.operator->()->HasMaidId() != 0)
                {
                    if (nCount > 0)
                    {
                        obj.FUN_1409c0d20((const char*)s_itemCount, nMax);
                        obj.FUN_1409c0d20((const char*)s_itemMaxCount, nCount);
                    }
                }
                else
                {
                    obj.FUN_1409c0d20((const char*)s_itemCount, nMax);
                    obj.FUN_1409c0d20((const char*)s_itemMaxCount, nCount);
                }
            }
            if (spMeta->FUN_140549470(spCube->FUN_140def5a0(), spCube->FUN_140def5f0(), spCube->FUN_140defba0()) != 0)
            {
                __int64 nPrice = spCube->FUN_140def620();
                __int64 nOrigin = spCube->FUN_140def6c0();
                obj.FUN_1407cbb20((const char*)s_paymentIcon, spCube->FUN_140defd20());
                obj.FUN_1407cbb20((const char*)s_itemPrice, FUN_1409404f0(nPrice));
                if (nPrice < nOrigin)
                    obj.FUN_1407cbb20((const char*)s_originPrice, FUN_1409404f0(nOrigin));
            }
            if ((unsigned __int64)spCube->FUN_140defba0() > 0)
            {
                int nHave = 0;
                int nNeed = 0;
                if (!bHide)
                {
                    nHave = spCube->FUN_140defe70();
                    nNeed = spCube->FUN_140defed0();
                }
                if ((unsigned)nNeed < (unsigned)nHave)
                    obj.FUN_1407cbbe0("destroy", true);
            }
            obj.FUN_1407cb9c0("selectedindex", nRow);
            Scaleform::GFx::Value res = pDlg->FUN_140acd1f0("previewCube", AScript(obj));
        }
        else
        {
            pDlg->Invoke("clearPreviewCube");
        }
    }
}
#endif

// @0x140eef140 (the destroy-cube message box of the selected cube)
void UIUGCCubePaletteDialog::OnDestroyCubeItem()
{
    MS2Ptr<CubeItemInfo> spSel = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedInfo();
    if (spSel == (CubeItemInfo*)0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(spSel->instanceId);
    if (spItem == (CItem*)0)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, BlockFormat<unsigned int>(0xdf, spItem->GetCount()), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01600(spItem->GetItemUid());
        spBox->FUN_141a024a0(0);
        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), spItem->GetRarity(), spItem->GetCount(), -1, -1, 1);
        spBox->SetButtonLabelIds(0x475, 0x476, 0);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIUGCCubePaletteDialog::FUN_140eec330));
        FUN_140d73c60(spBox);
    }
}

// @0x140eef510 (set the search text, refresh)
void UIUGCCubePaletteDialog::FUN_140eef510(const CStringW& str)
{
    m_filter.text = str;
    FUN_140eefc50(6);
}

// @0x140eef560 (select a row of the cube list, clamped to the last)
void UIUGCCubePaletteDialog::FUN_140eef560(int nRow)
{
    FUN_140ef41b0(nRow);
    if (MS2Ptr<ASTileList> spList = GetChild<ASTileList>("m_cubeList"))
    {
        unsigned int nIndex = (unsigned)(nRow - 1) < spList->GetItemCount() - 1 ? nRow - 1 : spList->GetItemCount() - 1;
        spList->SetSelectedIndex(nIndex);
    }
}

// @0x140eef670 (select a row of the page: the 10-per-page cube list)
void UIUGCCubePaletteDialog::FUN_140eef670(int nRow)
{
    if (MS2Ptr<ASTileList> spList = GetChild<ASTileList>("m_cubeList"))
    {
        int nIndex = spList->FUN_1422cf520() * 10 + nRow;
        int nResult = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FUN_1410b6060(nIndex);
        if (nResult == 3)
        {
            if (WorldService::GetInstance()->FUN_141bd30a0()->FUN_140375130())
                FUN_141275260(0x6f7, 1, 1);
            else
                FUN_141275260(0x6f6, 1, 1);
        }
        spList->SetSelectedIndex(nIndex - 1);
    }
}

// @0x140eefc50 (what to refresh: 1/5..9 reset the focus, 2 buy, 3/4 page, 10 focus the first)
void UIUGCCubePaletteDialog::FUN_140eefc50(int nState)
{
    int nIndex = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedIndex() - 1;
    switch (nState)
    {
    case 1:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        m_focus.FUN_140ee9cf0(0, 0);
        break;
    case 10:
        m_focus.FUN_140ee9cf0(0, reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedItemId());
        break;
    case 2:
    {
        MS2Ptr<CItemData> spInfo = FUN_14053f870(reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedItemId());
        if ((spInfo.operator CItemData*() ? true : false) && spInfo.operator->()->HasMaidId() != 0)
            m_focus.FUN_140ee9cf0(0, reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedItemId());
        else
            FUN_140eefdd0(nIndex);
    }
    break;
    case 3:
    case 4:
        FUN_140eefdd0(nIndex);
        break;
    }
}

// @0x140eefdd0 (arm the scroll timer)
void UIUGCCubePaletteDialog::FUN_140eefdd0(int nIndex)
{
    m_timer.FUN_140ee9eb0(nIndex);
}

// @0x140eefe00
void UIUGCCubePaletteDialog::FUN_140eefe00()
{
    FUN_140ef2fb0();
}

// @0x140eeff60 (the UGC item edit dialog of a UI id)
UIUGCItemEditDialog* FUN_140eeff60(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UIUGCItemEditDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x140eef7e0 (install the cube at a list index into the open UGC item editor)
void UIUGCCubePaletteDialog::FUN_140eef7e0(int nCubeIndex)
{
    MS2Ptr<UIUGCItemEditDialog> spEdit(FUN_140eeff60(0x4e69));
    if (spEdit.get()->vfunc_55() == 0)
        return;
    UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByIndex(nCubeIndex);
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    int nId = spCube->FUN_140def5a0();
    MS2Ptr<CItemData> spInfo = FUN_14053f870(nId);
    if (spInfo == (CItemData*)0 || spInfo.operator->()->HasCubeTextureMesh() == 0)
        return;
    MS2Ptr<CubeItemInfo> spCubeInfo = spCube->FUN_140def3d0();
    if (spCubeInfo == (CubeItemInfo*)0 || spCubeInfo->FUN_1408b3860() == 1)
        return;
    if (spCube->FUN_140defed0() > 0)
    {
        FUN_1412752d0(L"s_construct_edit_design_install_empty_ugc", 1);
        return;
    }
    __int64 nUid = spCube->FUN_140def5f0();
    int nRank = FUN_14053feb0(nId);
    __int64 nCount = spCubeInfo->count;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_140523c40(nId, nRank, 0))
    {
        spItem->SetItemUid(nUid);
        spItem->FUN_1405288e0(nCount);
        spItem->SetCountClamped(spCube->FUN_140defe70());
        MS2Ptr<CUgcItemLook> spLook(spCubeInfo->look);
        if (spLook.get() != 0)
            spItem->SetUgcLook(spLook.operator->());
        spEdit.get()->SetEditItem(spItem);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e69)));
    }
}

// ---- key modes ----

// @0x140ef1bc0
UGCKeyMode::UGCKeyMode()
{
}

// @0x140ef1c00
void UGCKeyMode::vfunc_1()
{
    TSingleton<CUIService>::GetInstance()->FUN_141adbdc0(1);
}

// @0x140ef1c30
UGCKeyMode1::UGCKeyMode1()
{
}

// @0x140ef1c70 (ray cast under the cursor: preview the picked cube)
// MS2-FUNCTIONAL: transliterated from the decompile
void UGCKeyMode1::vfunc_1()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (((class PC*)(void*)(pWorld))->IsInCubeMode() == 0)
        return;
    Unk_CubePlayer* pPlayer = ((class Unk_CubePlayer*)((class PC*)(void*)(pWorld))->FUN_1416625b0());
    if (pPlayer == 0)
        return;
    TSingleton<CUIService>::GetInstance()->FUN_141adbdc0(0);
    if (((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0 && ((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116db80(0, 0, 0) != 0)
    {
        float fX = 0;
        float fY = 0;
        ((CWindowService*)(Unk_FpsSvc*)(((class Unk_FpsSvc*)FUN_140aadf80())))->GetCursorClientPos(&fX, &fY);
        efd::SmartPointer<ecr::PickService::PickRecord> spPick = TSingleton<CameraMgr>::GetInstance()->FUN_140af0850(fX, fY, true, true, false, 0);
        if ((ecr::PickService::PickRecord*)spPick == 0)
            return;
        for (unsigned int i = 0; i < spPick->GetPickResult()->GetSize(); i++)
        {
            NiPick::Record* pHit = spPick->GetPickResult()->GetAt(i);
            if (pHit == 0)
                continue;
            NiObject* pObj = NiObject::DynamicCast(&NiMesh::ms_RTTI, pHit->GetAVObject());
            if (pObj == 0)
                continue;
            void* pOwner = reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())->FUN_141bd1050(pHit->GetAVObject());
            if (pOwner != 0)
                continue;
            Unk_CubeKind* pKind = reinterpret_cast<Unk_CubeKind*>(NiMaterial::DynamicCast(&MS2StandardMaterial::ms_RTTI, static_cast<NiRenderObject*>(static_cast<NiMesh*>(pObj))->GetActiveMaterial()));
            if (pKind != 0)
            {
                if (pKind->FUN_140ef4dd0() == 1)
                    continue;
                if (pKind->FUN_140ef4dd0() == 2)
                    continue;
                if (pKind->FUN_140ef4dd0() == 3)
                    continue;
            }
            NiPoint3 vUp(0, 0, 250.0f);
            Vector3 vPos = *((Vector3*)&static_cast<NiAVObject*>(static_cast<NiMesh*>(pObj))->GetWorldTranslate());
            Unk_NiPoint3 vEnd(*reinterpret_cast<const Vector3*>(&static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(vPos) + NiPoint3(0, 0, 75.0f))));
            // by value, right to left: DAT_143ab2398 and the vfunc_20 point are copied into argument temps, vPos twice
            if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410cdd80(reinterpret_cast<const Unk_PalNiPoint3&>(vPos), reinterpret_cast<const Vector3&>(static_cast<const Unk_KmPt&>(pPlayer->vfunc_20())), 200.0f, DAT_143ab2398) != 0)
            {
                Vector3 vAt = *reinterpret_cast<Vector3*>(&vEnd);
                void* pCube = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->GetCubeAtPoint(vAt);
                if (pCube != 0)
                {
                    Unk_NiPoint3 vTop(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((*reinterpret_cast<Vector3*>(&vEnd)))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(*reinterpret_cast<Vector3*>(&vUp))))));
                    Vector3 vCellPt = *reinterpret_cast<Vector3*>(&vEnd);
                    if (pCube == ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410b8790(FUN_1408a1430(*reinterpret_cast<NiPoint3*>(&vCellPt))))
                        vTop.z += 150.0f;
                    Vector3 vSet = *reinterpret_cast<Vector3*>(&vTop);
                    pPlayer->vfunc_19(vSet);
                    break;
                }
            }
        }
    }
}

// @0x140ef21c0 (place / remove)
void UGCKeyMode1::vfunc_5(void*, float, float)
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    Unk_CubeSpRef spMgr(((class Unk_CubeMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>()));
    if ((reinterpret_cast<efd::SmartPointer<CubeMapInformationService>&>(spMgr) == (CubeMapInformationService*)0) != 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->HasCubeAtPoint(((class Unk_PCCubeCraft*)(void*)(pEditor))->GetPtCell()))
        FUN_140ef3840();
    else
        FUN_140ef2fb0();
}

// @0x140ef22d0 (wheel: next / previous cube)
void UGCKeyMode1::vfunc_7(void*, float, float, float f)
{
    UIUGCCubePaletteDialog* pDlg = FUN_140ef4a50(0x4f16);
    if (pDlg != 0)
    {
        if (f > 0.0f)
            FUN_140ef3f70();
        else
            FUN_140ef3fc0();
    }
}

// @0x140ef2330
UGCKeyMode2::UGCKeyMode2()
{
}

// @0x140ef2370
// MS2-FUNCTIONAL: transliterated from the decompile
void UGCKeyMode2::vfunc_1()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (((class PC*)(void*)(pWorld))->IsInCubeMode() == 0)
        return;
    Unk_CubePlayer* pPlayer = ((class Unk_CubePlayer*)((class PC*)(void*)(pWorld))->FUN_1416625b0());
    if (pPlayer == 0)
        return;
    TSingleton<CUIService>::GetInstance()->FUN_141adbdc0(1);
    if (((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0 && ((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116db80(0, 0, 0) != 0)
    {
        float fX = 0;
        float fY = 0;
        ((CWindowService*)(Unk_FpsSvc*)(((class Unk_FpsSvc*)FUN_140aadf80())))->GetCursorClientPos(&fX, &fY);
        efd::SmartPointer<ecr::PickService::PickRecord> spPick = TSingleton<CameraMgr>::GetInstance()->FUN_140af0850(fX, fY, true, true, false, 0);
        if ((ecr::PickService::PickRecord*)spPick == 0)
            return;
        for (unsigned int i = 0; i < spPick->GetPickResult()->GetSize(); i++)
        {
            NiPick::Record* pHit = spPick->GetPickResult()->GetAt(i);
            if (pHit == 0)
                continue;
            NiObject* pObj = NiObject::DynamicCast(&NiMesh::ms_RTTI, pHit->GetAVObject());
            if (pObj == 0)
                continue;
            NiPoint3 vUp(0, 0, 250.0f);
            Vector3 vPos = *((Vector3*)&static_cast<NiAVObject*>(static_cast<NiMesh*>(pObj))->GetWorldTranslate());
            Unk_NiPoint3 vEnd(*reinterpret_cast<const Vector3*>(&static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(vPos) + NiPoint3(0, 0, 75.0f))));
            // by value, right to left: DAT_143ab2398 and the vfunc_20 point are copied into argument temps, vPos twice
            if (((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410cdd80(reinterpret_cast<const Unk_PalNiPoint3&>(vPos), reinterpret_cast<const Vector3&>(static_cast<const Unk_KmPt&>(pPlayer->vfunc_20())), 200.0f, DAT_143ab2398) != 0)
            {
                Vector3 vAt = *reinterpret_cast<Vector3*>(&vEnd);
                void* pCube = ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->GetCubeAtPoint(vAt);
                if (pCube != 0)
                {
                    Unk_NiPoint3 vTop(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((*reinterpret_cast<Vector3*>(&vEnd)))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(*reinterpret_cast<Vector3*>(&vUp))))));
                    Vector3 vCellPt = *reinterpret_cast<Vector3*>(&vEnd);
                    if (pCube == ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410b8790(FUN_1408a1430(*reinterpret_cast<NiPoint3*>(&vCellPt))))
                        vTop.z += 150.0f;
                    Vector3 vSet = *reinterpret_cast<Vector3*>(&vTop);
                    pPlayer->vfunc_19(vSet);
                    break;
                }
            }
        }
    }
}

// @0x140ef2810
void UGCKeyMode2::vfunc_5(void*, float, float)
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    Unk_CubeSpRef spMgr(((class Unk_CubeMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>()));
    if ((reinterpret_cast<efd::SmartPointer<CubeMapInformationService>&>(spMgr) == (CubeMapInformationService*)0) != 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->HasCubeAtPoint(((class Unk_PCCubeCraft*)(void*)(pEditor))->GetPtCell()))
        FUN_140ef3840();
    else
        FUN_140ef2fb0();
}

// ---- key controller ----

// @0x140ef2920
UGCKeyController::UGCKeyController()
{
    m_mode.AssignRaw(new UGCKeyMode1());
}

// @0x140ef29c0 (per-frame: switch the mode by the hot keys, then let the mode update)
void UGCKeyController::vfunc_0()
{
    if (!FUN_140ef4970())
        return;
    {
        if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116da30(0x3b, 0, 0))
            m_mode.AssignRaw(new UGCKeyMode());
        else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116da30(0x3c, 0, 0))
            m_mode.AssignRaw(new UGCKeyMode1());
        else if (((class CInputKeyHandler*)((class Unk_KeySvc*)FUN_14025e7c0()))->FUN_14116da30(0x3d, 0, 0))
            m_mode.AssignRaw(new UGCKeyMode2());
        if (m_mode.get() != 0)
            m_mode->vfunc_1();
    }
}

// @0x140ef2ba0
void UGCKeyController::vfunc_1(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if (m_mode.get())
        m_mode->vfunc_2(p, x, y);
}

// @0x140ef2c30
void UGCKeyController::vfunc_2(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && ((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_3(p, x, y);
}

// @0x140ef2ce0
void UGCKeyController::vfunc_3(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && ((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_4(p, x, y);
}

// @0x140ef2d90
void UGCKeyController::vfunc_4(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && ((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_5(p, x, y);
}

// @0x140ef2e40
void UGCKeyController::vfunc_5(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && ((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_6(p, x, y);
}

// @0x140ef2ef0
void UGCKeyController::vfunc_6(void* p, float x, float y, float f)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && ((Unk_InputSvc*)SingletonClass<GFxManager>::GetInstance())->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_7(p, x, y, f);
}

// ---- buy / install / remove flow ----

// @0x140ef2fb0 (buy the selected cube, then install it)
// MS2-FUNCTIONAL: transliterated from the decompile
void FUN_140ef2fb0()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (((class Unk_PCCubeCraft*)pEditor)->GetPending() != 0)
        return;
    Unk_CubeSpRef spMgr(((class Unk_CubeMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>()));
    if ((reinterpret_cast<efd::SmartPointer<CubeMapInformationService>&>(spMgr) == (CubeMapInformationService*)0) != 0)
        return;
    UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelected();
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    if (spCube->FUN_140def420() != 0)
    {
        FUN_141275260(0xcac, 1, 1);
    }
    else
    {
        unsigned int nCount = spCube->FUN_140defe70();
        unsigned int nMax = spCube->FUN_140defed0();
        int nMapId = reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())->FUN_141bd3060();
        int nStyle = FUN_1408a18d0((__int64)((class PCBase*)(pWorld))->FUN_141656a80());
        if (((CubeMapInformationService*)(Unk_CubeMgr*)(reinterpret_cast<Unk_CubeMgr*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())))->FUN_1410c3600(1) != 0 || ((CubeMapInformationService*)(Unk_CubeMgr*)(reinterpret_cast<Unk_CubeMgr*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())))->FUN_1410c3600(3) != 0 || nCount > nMax ||
            ((CubeMapInformationService*)(Unk_CubeMgr*)(reinterpret_cast<Unk_CubeMgr*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())))->FUN_1410d55d0(nMapId, nStyle) != 0 || FUN_1408a07b0(nMapId, DAT_1439f4a7c, DAT_143ab2820) != 0 ||
            FUN_140930ce0() != 0 || FUN_140930c50() != 0)
        {
            FUN_140ef37d0();
        }
        else if (spCube->FUN_140def4f0() != 0)
        {
            __int64 nNow = GetServerTime();
            __int64 nLast = ((struct Unk_CubeUiData*)((class CGameOption*)(void*)(TSingleton<CGameOption>::GetInstance()))->FUN_140c9b8b0())->m_8;
            __int64 nPrice = spCube->FUN_140def620();
            __int64 nOrigin = spCube->FUN_140def6c0();
            if (nLast + 0x15180 > nNow || nPrice == 0)
            {
                FUN_140ef37d0();
            }
            else if (FUN_14151f6e0() != 0)
            {
                UIUGCCubePaletteDialog* pDlg = FUN_140ef4a50(0x4f16);
                if (pDlg != 0)
                {
                    CStringW strOrigin = FUN_1409404f0(nOrigin);
                    CStringW strMsg = FUN_140ef4540();
                    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strMsg, 0, CStringW(L""));
                    if (spBox.get() != 0)
                    {
                        MS2Ptr<CItem> spItem(new CItem());
                        if (spItem->FUN_140523c40(spCube->FUN_140def5a0(), 1, 0))
                        {
                            spItem->SetUgcLook(spCube->FUN_140def3d0()->look.get());
                            spBox->FUN_141a01800(1);
                            spBox->FUN_141a01600(spItem->GetItemUid());
                            spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 1, 1, (int)nPrice, 1);
                            spBox->SetCheckbox0Enabled(((class Unk_UserSvc*)FUN_140166410())->IsRegionJP() ? false : true);
                            spBox->SetCheckbox0(GetStringCommon(0x29f), 0);
                            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(pDlg, &UIUGCCubePaletteDialog::FUN_140eec410));
                            if (nPrice < nOrigin)
                                spBox->SetStrike(strOrigin);
                            FUN_140d73c60(spBox);
                        }
                    }
                }
            }
        }
        else
        {
            FUN_141275260(0xcad, 1, 1);
        }
    }
}

// @0x140ef37d0 (install the selected cube without buying)
void FUN_140ef37d0()
{
    void* pEditor;
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410aad50();
    FUN_140df1e90(0x65, ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ad610());
}

// @0x140ef3840 (remove the cube under the editor cursor)
// MS2-FUNCTIONAL: transliterated from the decompile
void FUN_140ef3840()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (((class PCBase*)(pWorld))->IsDead() != 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410a8ab0() != 0)
        return;
    Unk_CubeSpRef spMgr(((class Unk_CubeMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>()));
    if ((reinterpret_cast<efd::SmartPointer<CubeMapInformationService>&>(spMgr) == (CubeMapInformationService*)0) != 0)
        return;
    UIMainPlayerInfo* pDlg = FUN_140931900(0x4e5f);
    if (pDlg == 0)
        return;
    bool bShown = false;
    if (reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->HasCubeAtPoint(((class Unk_PCCubeCraft*)(void*)(pEditor))->GetPtCell()) != 0)
    {
        MS2Ptr<Cube> spCube(reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->GetCubeAtPoint(((class Unk_PCCubeCraft*)(void*)(pEditor))->GetPtCell()));
        void* pLayer = (void*)reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->GetOwnerId(spCube.get()->field50, spCube.get()->field54);
        if ((void*)((class PC*)pWorld)->FUN_141656ad0() == pLayer)
        {
            if (FUN_1408b5570(((class Cube*)(spCube.get(), spCube.get()))->FUN_1408b4f20()) != 0)
            {
                FUN_140d73bc0(0x46f, 1, static_cast<IMessageListener*>(pDlg), CStringW(L"remove"));
                bShown = true;
            }
            else if (FUN_1408b54c0(((class Cube*)(spCube.get(), spCube.get()))->FUN_1408b4f20()) != 0)
            {
                if (reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->FUN_1410c35c0() == 0)
                {
                    int nStr = 0x470;
                    if (((class Unk_UserSvc*)FUN_140166410())->FUN_14036d570(0xd4) != 0)
                        nStr = 0x471;
                    FUN_140d73bc0(nStr, 1, static_cast<IMessageListener*>(pDlg), CStringW(L"remove"));
                    bShown = true;
                }
                if (((class Unk_UserSvc*)FUN_140166410())->FUN_14036d570(0xd4) != 0 && !bShown)
                    ((class MyPC*)(void*)(pWorld))->FUN_14152f140((__int64)spCube.get()->field18);
            }
            else
            {
                if (FUN_1408b5aa0(((class Cube*)(spCube.get(), spCube.get()))->FUN_1408b4f20()) != 0)
                {
                    FUN_140d73bc0(0x472, 1, static_cast<IMessageListener*>(pDlg), CStringW(L"remove"));
                    bShown = true;
                }
                else if (FUN_1408b5820(((class Cube*)(spCube.get(), spCube.get()))->FUN_1408b4f20()) != 0)
                {
                    if (reinterpret_cast<CubeMapInformationService*>(reinterpret_cast<const efd::SmartPointer<CubeMapInformationService>&>(spMgr).operator->())->FUN_1410c35c0() == 0)
                    {
                        FUN_140d73bc0(0x473, 1, static_cast<IMessageListener*>(pDlg), CStringW(L"remove"));
                        bShown = true;
                    }
                }
                else if (FUN_1408b5b50(((class Cube*)(spCube.get(), spCube.get()))->FUN_1408b4f20()) != 0)
                {
                    CStringW strMsg = FormatStringId<CStringW>(0x474, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, ((class Cube*)(spCube.get()))->FUN_1408b4f20()));
                    ((class CReservedWordTable*)TSingleton<CReservedWordTable>::GetInstance())->ReplaceValueWords(strMsg);
                    FUN_140d73aa0(CStringW(strMsg), 1, static_cast<IMessageListener*>(pDlg), CStringW(L"remove"));
                    bShown = true;
                }
            }
        }
    }
    if (!bShown)
        ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410abb40();
}

// @0x140ef3f00
void FUN_140ef3f00()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ab5a0();
    ((class CGuideManager*)(void*)(((void*)FUN_1409331e0())))->AddTrigger((CGuideManager::TriggerType)10, 0, 0);
}

// @0x140ef3f70
void FUN_140ef3f70()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ac1c0();
}

// @0x140ef3fc0
void FUN_140ef3fc0()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ac380();
}

// @0x140ef4010 (toggle the UGC edit mode)
void FUN_140ef4010()
{
    if (TSingleton<CUIService>::GetInstance()->FUN_141adc890((eUIClassID)(0x4e3b)) != 0)
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e3b);
    }
    else
    {
        void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
        if (pWorld == 0)
            return;
        ((class MyPC*)(void*)(pWorld))->SendCraftModeOff();
    }
}

// @0x140ef4070 (focus a palette row, pick that cube in the editor)
void FUN_140ef4070(int nIndex)
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410a8ab0() != 0)
        return;
    reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->SelectByItemId(nIndex);
    MS2Ptr<CubeItemInfo> spSel = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelectedInfo();
    if (spSel.get() != 0)
    {
        if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ad640() != spSel->instanceId)
            ((class Unk_PCCubeCraft*)(void*)(pEditor))->RequestCube(spSel.get());
        else if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ad610() != spSel->itemId)
            ((class Unk_PCCubeCraft*)(void*)(pEditor))->RequestCube(spSel.get());
    }
    else if (((class Unk_PCCubeCraft*)(void*)(pEditor))->GetMode() != 1)
        ((class Unk_PCCubeCraft*)(void*)(pEditor))->SendRequestCubeMode0(1);
}

// @0x140ef41b0 (same for the cube in a palette row)
void FUN_140ef41b0(int nIndex)
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410a8ab0() != 0)
        return;
    UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FindByIndex(nIndex);
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    MS2Ptr<CubeItemInfo> spSel = spCube->FUN_140def3d0();
    if (spSel.get() != 0)
    {
        if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ad640() != spSel->instanceId)
            ((class Unk_PCCubeCraft*)(void*)(pEditor))->RequestCube(spSel.get());
        else if (((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ad610() != spSel->itemId)
            ((class Unk_PCCubeCraft*)(void*)(pEditor))->RequestCube(spSel.get());
    }
    else if (((class Unk_PCCubeCraft*)(void*)(pEditor))->GetMode() != 1)
        ((class Unk_PCCubeCraft*)(void*)(pEditor))->SendRequestCubeMode0(1);
}

// @0x140ef4330 (switch between the palette and the other edit-mode dialogs)
void FUN_140ef4330()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (((class PC*)(void*)(pWorld))->IsInCubeMode() == 0 || ((class PC*)(void*)(pWorld))->FUN_141659690() != 0)
    {
        if (UIOxQuizDialog* pParty = FUN_140e01930(0x4f7d))
            pParty->FUN_140e6e610(false);
        if (UIHomeMenuDialog* pHome = FUN_140ef49b0(0x4f7c))
            pHome->FUN_140c29600(false);
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f16);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e28)));
        if (UIMainPlayerInfo* pEdit = FUN_140931900(0x4e5f))
            pEdit->SetHideReason(1, true);
    }
    else
    {
        if (UIOxQuizDialog* pParty = FUN_140e01930(0x4f7d))
            pParty->FUN_140e6e610(true);
        if (UIHomeMenuDialog* pHome = FUN_140ef49b0(0x4f7c))
            pHome->FUN_140c29600(true);
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e28);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4f16)));
        if (UIMainPlayerInfo* pEdit = FUN_140931900(0x4e5f))
            pEdit->SetHideReason(1, false);
    }
    if (void* pDlg = ((void*)FUN_140bbea00(0x4ed8)))
        ((class UIHomeInfoDialog*)(void*)(pDlg))->FUN_1412c72d0();
    if (UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28))
        pPoint->RefreshFoldButton();
}

// @0x140ef44f0
void FUN_140ef44f0()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    void* pEditor = ((class Unk_CubeHolder*)((class MyPC*)(void*)(pWorld))->GetActiveCubeCraft());
    if (pEditor == 0)
        return;
    ((class Unk_PCCubeCraft*)(void*)(pEditor))->FUN_1410ac540();
}

// @0x140ef4540 (the buy-and-install confirmation text of the selected cube)
CStringW FUN_140ef4540()
{
    UGCCubePalette::CubePtr spCube = reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->GetSelected();
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return CStringW(L"");
    MS2Ptr<CItemData> spInfo = FUN_14053f870(spCube->FUN_140def5a0());
    if (spInfo == (CItemData*)0)
        return CStringW(L"");
    __int64 nPrice = spCube->FUN_140def620();
    __int64 nOrigin = spCube->FUN_140def6c0();
    CStringW strPay = FUN_1418fec00(spCube->FUN_140defcd0(), nPrice, true);
    CStringW strOrigin = FUN_1409404f0(nOrigin);
    if (spInfo.operator->()->HasMaidId() != 0)
    {
        int nHave = ((class CWarehouseItemTable*)(void*)(&DAT_143ab2e20))->FUN_1408fc1b0(spCube->FUN_140def5a0());
        int nHave2 = DAT_143ab2e50.FUN_140dfcb00(spCube->FUN_140def5a0());
        if (0 < nHave || 0 < nHave2)
        {
            if (nPrice < nOrigin)
                return FUN_14028dfa0(CStringW(L"s_home_buycube_sale_and_install_confirm"), strOrigin, strPay);
            return FUN_14028dfa0<CStringW>(CStringW(L"s_home_buycube_and_install_confirm"), strPay);
        }
    }
    if (nPrice < nOrigin)
        return FUN_14028dfa0(CStringW(L"s_home_buycube_sale_and_install"), strOrigin, strPay);
    return FUN_14028dfa0<CStringW>(CStringW(L"s_home_buycube_and_install"), strPay);
}

// @0x140ef4970 (in a UGC edit session)
bool UGCKeyController::FUN_140ef4970()
{
    void* pWorld = ((class WorldService*)(class Unk_WorldMgr*)(reinterpret_cast<Unk_WorldMgr*>(WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pWorld == 0)
        return false;
    if (((class PC*)(void*)(pWorld))->IsInCubeMode() == 0)
        return false;
    return true;
}

// @0x140ef49b0
UIHomeMenuDialog* FUN_140ef49b0(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UIHomeMenuDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x140ef4a50
UIUGCCubePaletteDialog* FUN_140ef4a50(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UIUGCCubePaletteDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x140ef4af0
UIUGCHousingPointDialog* FUN_140ef4af0(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UIUGCHousingPointDialog*>(ref.operator UIObject*());
    }
    return 0;
}


// ---- local-type helpers (all COMDAT-sized inline accessors of the handle types) ----

// @0x140ef04a0
Unk_CubePaletteFilter::~Unk_CubePaletteFilter()
{
}

// @0x140ef04c0
Unk_CubeTimer::~Unk_CubeTimer()
{
}

// MS2-PIN: ??1UGCKeyController@@QEAA@XZ 0x140ef04e0 ; implicit dtor (~MS2Ptr<UGCKeyMode>)

// @0x140ef0500
UGCCubeCategoryTable::TabPtr* Unk_CubePtrAccess::FUN_140ef0500(UGCCubeCategoryTable::TabPtr* pDst, UGCCubeCategoryTable::TabPtr* pSrc)
{
    pSrc->AddRef();
    pDst->Release();
    pDst->m_p = pSrc->m_p;
    return pDst;
}

// @0x140ef05f0
bool FUN_140ef05f0(RSortElem* p, __int64 n)
{
    return p->m_p == (void*)n;
}

// @0x140ef0630
bool FUN_140ef0630(RTypeTbl* p, __int64 n)
{
    return p->m_p == (void*)n;
}

// @0x140ef0670
bool FUN_140ef0670(RSortTbl* p, __int64 n)
{
    return p->m_p == (void*)n;
}

// @0x140ef06b0
bool FUN_140ef06b0(RCatTbl* p, __int64 n)
{
    return p->m_p == (void*)n;
}

// @0x140ef0750
void* FUN_140ef0750(RCatTbl* p)
{
    return p->m_p;
}

// @0x140ef0ae0
unsigned __int64 FUN_140ef0ae0(void* pTbl)
{
    return ((Unk_Arr16*)pTbl)->m_nCount;
}

// @0x140ef0af0
unsigned __int64 FUN_140ef0af0(void* pTbl)
{
    return ((Unk_Arr16*)pTbl)->m_nCount;
}

// @0x140ef4cf0
unsigned __int64 FUN_140ef4cf0(Unk_Arr16* p)
{
    return p->m_nCount;
}

// @0x140ef4d00
unsigned __int64 FUN_140ef4d00(Unk_Arr16* p)
{
    return p->m_nCount;
}

// @0x140ef0a60
void* FUN_140ef0a60(void* pTbl, unsigned __int64 n)
{
    if (n >= ((Unk_Arr16*)pTbl)->m_nCount)
        ATL::AtlThrowImpl(0x80070057);
    return ((Unk_Arr16*)pTbl)->m_pData + n * 0x10;
}

// @0x140ef0aa0
void* FUN_140ef0aa0(void* pTbl, unsigned __int64 n)
{
    if (n >= ((Unk_Arr16*)pTbl)->m_nCount)
        ATL::AtlThrowImpl(0x80070057);
    return ((Unk_Arr16*)pTbl)->m_pData + n * 0x10;
}

// @0x140ef0b20
UGCCubePalette* GetUGCCubePalette()
{
    return reinterpret_cast<UGCCubePalette*>(TSingleton<CubeHolderManager>::s_instance);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140EE9CD0, Unk_CubeFocus, IsActive, 14, 0xDA496095);
MS2_REPLACE_METHOD(0x140EE9D50, Unk_CubeFocus, FUN_140ee9d50, 14, 0x322C4B62);
MS2_REPLACE_METHOD(0x140EE9F00, Unk_CubeTimer, FUN_140ee9f00, 27, 0x6AA3A4C7);
MS2_REPLACE_METHOD(0x140EE9F30, Unk_CubeTimer, GetValue, 14, 0xB2976B17);
MS2_REPLACE_METHOD(0x140EEA300, UIUGCCubePaletteDialog, GetTypeName, 61, 0x31979C2E);
MS2_REPLACE_METHOD(0x140EEA420, UIUGCCubePaletteDialog, vfunc_54, 135, 0xD6F6CE30);
MS2_REPLACE_METHOD(0x140EEAEE0, UIUGCCubePaletteDialog, vfunc_38, 87, 0xA2B2B2A4);
MS2_REPLACE_METHOD(0x140EEAF40, UIUGCCubePaletteDialog, vfunc_32, 87, 0x415D381C);
MS2_REPLACE_METHOD(0x140EEAFA0, UIUGCCubePaletteDialog, vfunc_33, 87, 0x4A0031B4);
MS2_REPLACE_METHOD(0x140EEB000, UIUGCCubePaletteDialog, vfunc_35, 87, 0xBEBA076C);
MS2_REPLACE_METHOD(0x140EEB060, UIUGCCubePaletteDialog, vfunc_36, 87, 0x5A6DFD84);
MS2_REPLACE_METHOD(0x140EEB0C0, UIUGCCubePaletteDialog, vfunc_39, 99, 0x8A653DE3);
MS2_REPLACE_METHOD(0x140EEC410, UIUGCCubePaletteDialog, FUN_140eec410, 99, 0x07B11F90);
MS2_REPLACE_METHOD(0x140EEF510, UIUGCCubePaletteDialog, FUN_140eef510, 59, 0x6136A9A1);
MS2_REPLACE_METHOD(0x140EEFDD0, UIUGCCubePaletteDialog, FUN_140eefdd0, 41, 0x28FA1DAF);
MS2_REPLACE_METHOD(0x140EEFE00, UIUGCCubePaletteDialog, FUN_140eefe00, 19, 0x479565AE);
MS2_REPLACE_METHOD(0x140EF0000, ASObj, FUN_140ef0000, 152, 0x0A3D18BD);
MS2_REPLACE_METHOD(0x140EF00A0, ASObj, FUN_140ef00a0, 152, 0x654F363F);
MS2_REPLACE_METHOD(0x140EF1C00, UGCKeyMode, vfunc_1, 32, 0x851BA29F);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca88a0-0x142ca8a80 .text$yd
