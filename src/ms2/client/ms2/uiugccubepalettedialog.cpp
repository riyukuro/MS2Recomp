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
// MS2-PIN: ??1?$CRBMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@XZ 0x140ef0390
// MS2-PIN: ??0CNode@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@HH@Z 0x140ef0310
// MS2-PIN: ??0CPair@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEAA@HH@Z 0x140ef0360
// MS2-PIN: ?NewNode@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HH@Z 0x140ef0f80
// MS2-PIN: ?InsertImpl@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HH@Z 0x140ef0c50
// MS2-PIN: ?RBInsert@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEAAPEAVCNode@12@HH@Z 0x140ef12b0
// MS2-PIN: ?Find@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEBAPEAVCNode@12@H@Z 0x140ef08d0
// MS2-PIN: ?SetAt@?$CRBMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@HH@Z 0x140ef1720
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VUGCCube@UGCCubePalette@@@@QEBAPEAVUGCCube@UGCCubePalette@@XZ 0x140ef0740 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VUIUGCItemEditDialog@@@@QEBAPEAVUIUGCItemEditDialog@@XZ 0x140ef0760 ; unique
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x140ef0840 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@H@ATL@@SAHAEBH0@Z 0x140ef0890 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140ef09c0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAPEAU__POSITION@@XZ 0x140ef0b00 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x140ef0b30 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140ef0b90 ; unique
// MS2-PIN: ?vfunc_48@UIUGCCubePaletteDialog@@UEAAHXZ 0x140ef0be0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAAEAHPEAU__POSITION@@@Z 0x140ef0bf0 ; unique
// MS2-PIN: ?IsNil@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBA_NPEAVCNode@12@@Z 0x140ef0d50 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140ef0d90 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef0ea0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef0f10 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef11e0 ; unique
// MS2-PIN: ?RemovePostOrder@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140ef15b0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140ef1610 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140ef1780 ; unique
// MS2-PIN: ?Successor@?$CRBTree@HHV?$CElementTraits@H@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140ef17f0 ; unique
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

#include "uiugccubepalettedialog.h"

#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/nipoint3.h"
#include "hook/ms2hook.h"

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
void FUN_140bcbb50(void*);
void FUN_140d03070(void*);
void FUN_140acd6e0(void*);
void FUN_140a583d0(void*);
void FUN_140bbfda0(void*);
void FUN_140bbfdd0(void*);
void FUN_140acd710(void*);
void FUN_1401b50d0(void*);
void FUN_14056c300(void*);
void FUN_1403e5630(void*);
void FUN_140a16120(void*);
void FUN_1401cd150(void*);

typedef Unk_Ref<FUN_140888b50> RTypeTbl;
typedef Unk_Ref<FUN_140888ac0> RTypeElem;
typedef Unk_Ref<FUN_140888b80> RSortTbl;
typedef Unk_Ref<FUN_140888af0> RSortElem;
typedef Unk_Ref<FUN_140888bb0> RCatTbl;
typedef Unk_Ref<FUN_140888b20> RCatElem;
typedef Unk_Ref<FUN_140bcbb50> RTypeList;
typedef Unk_Ref<FUN_140d03070> RDisp;
typedef Unk_Ref<FUN_140acd6e0> RButton;
typedef Unk_Ref<FUN_140a583d0> RCheck;
typedef Unk_Ref<FUN_140bbfda0> RCombo;
typedef Unk_Ref<FUN_140bbfdd0> Unk_SearchRef;
typedef Unk_Ref<FUN_140acd710> RCubeList;
typedef Unk_Ref<FUN_1401b50d0> RItemInfo;
typedef Unk_Ref<FUN_14056c300> RItemMeta;
typedef Unk_Ref<FUN_1403e5630> Unk_UIRef;

class ASDialog : public ASDisplayObject
{
};

// ---- records behind the table handles ----

struct Unk_TypeRec
{
    char pad_00[0x18];
    CString name;           // +0x18
    int id;                 // +0x20
    int filter;             // +0x24
    int flag;               // +0x28
};

struct Unk_SortRec
{
    char pad_00[0x18];
    CString name;           // +0x18
    int order;              // +0x20
};

struct Unk_CatRec
{
    char pad_00[0x18];
    CString name;           // +0x18
    int id;                 // +0x20
    char pad_24[0x4];
    void* subs;             // +0x28
    char pad_30[0x18];
    int flag;               // +0x48
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
    virtual void vfunc_24(int n);
    float FUN_1422c10a0();                                  // x
    float FUN_1422c1110();                                  // y
    float FUN_1422c1180();                                  // z
    void FUN_1422c1fe0(int n);                              // enable
    void FUN_1422ce090(int n);                              // check
    Scaleform::GFx::Value FUN_140ba26d0(const char* szMethod, unsigned int n);
    CStringW FUN_1422e0b00();
};

// The shared edit-mode manager of the UI (UI id -> dialog).
class Unk_UIMgr
{
public:
    void FUN_141adc530(int nId);
    void FUN_141adc5d0(int nId);
    int FUN_141adc890(int nId);
    Unk_UIRef FUN_141adcea0(int nId);
    void FUN_141adbdc0(int n);
};

class Unk_CubeEditDlg : public UIDialog
{
public:
    void FUN_1419f1d10(int a, bool b);
};

class UIHomeMenuDialog : public UIDialog
{
public:
    void FUN_140c29600(bool b);
};

class UIUGCHousingPointDialog : public UIDialog
{
public:
    void FUN_140fae0f0();
};

class UIUGCItemEditDialog : public UIDialog
{
public:
    void FUN_141b463b0(MS2Ptr<CItem> spItem);
};

// the input service and the key service
class Unk_InputSvc
{
public:
    int FUN_1422aeed0(int n);
};

class Unk_KeySvc
{
public:
    int FUN_14116da30(int a, int b, int c);
    int FUN_14116db80(int a, int b, int c);
};

class Unk_FpsSvc
{
public:
    void FUN_141b90e30(float* pX, float* pY);
};

class Unk_UserSvc
{
public:
    bool FUN_14036d570(int n);
};

class Unk_MetaMgr
{
public:
    int FUN_140549470(int a, int b, int c);
};

class Unk_ItemData
{
};

class Unk_InfoRec
{
public:
    int FUN_14053cde0();
    int FUN_14053d6f0();
};

class Unk_CubeInfo : public CPtred
{
public:
    int FUN_1408b4f20();                                    // cube kind
    void* m_18;
    char pad_20[0x30];
    int m_50;
    int m_54;
};

class Unk_CubeKind
{
public:
    int FUN_140ef4dd0();
    char m_pad[0x540];
    int m_540;
};

class Unk_CubeObject
{
public:
    Unk_StreamPoint* FUN_140947900();
    int FUN_140a17cd0();
};

class Unk_CubeObjMgr
{
public:
    Unk_CubeObject* FUN_14098d8d0(int nId);
};

class Unk_CubeKindMgr
{
public:
    Unk_CubeKind* FUN_140a17af0(int nId);
};

class Unk_CubePickHit
{
public:
    int FUN_140a17cb0();
};

class Unk_CubePickList
{
public:
    Unk_CubePickHit* FUN_140a17d70(unsigned int n);
    unsigned int FUN_140a17ea0();
};

class Unk_CubePickBox
{
public:
    Unk_CubePickList* FUN_140a17e00();
};

struct Unk_CubePickPtr
{
    void* m_0;
    void* m_p;
    Unk_CubePickPtr() : m_0(0), m_p(0) {}
    ~Unk_CubePickPtr() { FUN_140a16120(this); }
    int FUN_140a16c00();                                    // empty
    Unk_CubePickBox* FUN_140a16c30();
};

class Unk_CubePicker
{
public:
    Unk_CubePickPtr FUN_140af0850(float x, float y, bool a, bool b, bool c, int d);
};

class Unk_CubeHolder
{
public:
    CubeItemInfo* FUN_1410ad670();
};

class Unk_CubeRenderer : public ASDisplayObject
{
public:
    Unk_CubeRenderer(const Scaleform::GFx::Value& v, int n);   // 0x1422bf7c0 (the exe allocates 0x80 = sizeof(ASDisplayObject))
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
    virtual void vfunc_19(Unk_StreamPoint pt);
    virtual Unk_StreamPoint vfunc_20();
};

// the refcounted cube manager (a COM-like interface: slot 1 AddRef, slot 2 Release)
class Unk_CubeMgr
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int FUN_1410b7e80(const Unk_StreamPoint& pt);
    int FUN_1410c35c0();
    bool FUN_1410c3600(int n);
    void* FUN_1410c8030(int a, int b);
    int FUN_1410d55d0(int a, int b);
    void* FUN_1410b8790(Unk_StreamPoint pt);
    void* FUN_1410b8ab0(Unk_StreamPoint pt);
    int FUN_1410cdd80(Unk_StreamPoint a, Unk_StreamPoint b, float f, Unk_StreamPoint c);
};
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
UIObject* FUN_1403e8a70(Unk_UIRef* p);                          // the held object
UIObject* FUN_1403ed9e0(Unk_UIRef* p);
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
    Unk_CubeMgr* FUN_1401cd1a0();
    bool FUN_140ef4cb0(Unk_CubeMgr* p);
};

// ---- exe functions: managers and singletons ----

Unk_UIMgr* FUN_1403ed2b0();
class Unk_PalPtred298 : public CPtred {};   // WorldService::m_298 (worldservice.h Unk_WsPtred298)
class Unk_WorldMgr
{
public:
    int FUN_141bd1050(int n);
    int FUN_141bd3060();
    MS2Ptr<Unk_PalPtred298> FUN_141bd30a0();   // copy of m_298 (by value: hidden return in rdx)
};
Unk_WorldMgr* FUN_1403ed2d0();
Unk_InputSvc* FUN_14025e7a0();
Unk_KeySvc* FUN_14025e7c0();
Unk_FpsSvc* FUN_140aadf80();
Unk_UserSvc* FUN_140166410();
void* FUN_1403b4750();
void* FUN_140281980();
void* FUN_1409331e0();
void* FUN_1409eed80();
void* FUN_1409a8b10();
void* FUN_1409bb9e0();
void* FUN_140953f30();
void* FUN_140b632f0();
int FUN_1418dd0c0();
Unk_CubePicker* FUN_1409478c0();
Unk_CubeMgr* FUN_1409670e0();
Unk_CubeSpRef FUN_1401cd040(void* pSingleton);
UGCCubePalette* FUN_140ef0b20();
struct Unk_ItemMgr { MS2Ptr<CItem> FUN_1408fbf90(unsigned __int64 uid); };
int FUN_1408fc1b0(void* pBag, int nItemId);
int FUN_140dfcb00(void* pBag, int nItemId);

extern Unk_ItemMgr DAT_143ab2e20;
extern char DAT_143ab2e50;
extern Unk_CubeObjMgr DAT_143afbbb0;
extern Unk_CubeKindMgr DAT_143d69198;
extern char DAT_143b059e8;
extern int DAT_1439f4a7c;
extern int DAT_143ab2820;
extern Unk_StreamPoint DAT_143ab2398;
extern char DAT_142e6b390;
extern char DAT_142e6b1bc;

// ---- tables ----

struct Unk_Arr16 { char* m_pData; unsigned __int64 m_nCount; };
void FUN_140159b70(long hr);
extern UGCCubePalette* DAT_143ac90f0;


void FUN_140886490(void* pMgr, RTypeTbl* pRet);
void FUN_1408864e0(void* pMgr, RSortTbl* pRet);
void FUN_140886530(void* pMgr, RCatTbl* pRet, int nCubeType);
bool FUN_140ef0630(RTypeTbl* p, __int64 n);
bool FUN_140ef0670(RSortTbl* p, __int64 n);
bool FUN_140ef06b0(RCatTbl* p, __int64 n);
void* FUN_140889050(RTypeTbl* p);
void* FUN_140889060(RSortTbl* p);
void* FUN_140ef0750(RCatTbl* p);
void FUN_14088cfc0(RCatElem* p);
void FUN_14088d5d0(RCatElem* p);
unsigned int FUN_140889fb0(void* pTbl);
unsigned __int64 FUN_140ef0ae0(void* pTbl);
unsigned __int64 FUN_140ef0af0(void* pTbl);
void* FUN_140889f70(void* pTbl, unsigned int n);
void* FUN_140ef0a60(void* pTbl, unsigned __int64 n);
void* FUN_140ef0aa0(void* pTbl, unsigned __int64 n);
void FUN_140888330(RTypeElem* p, void* pElem);
void FUN_1408883e0(RSortElem* p, void* pElem);
void FUN_140888480(RCatElem* p, void* pElem);
void FUN_1408884f0(RCatElem* p, int n);
void FUN_140ef0500(RCatElem* pDst, RCatElem* pSrc);
int FUN_140888ed0(RTypeElem* p, int n);
bool FUN_140ef05f0(RSortElem* p, __int64 n);
int FUN_140888f10(RCatElem* p, int n);
int FUN_140ef0730(RCatElem* p);
Unk_TypeRec* FUN_140889020(RTypeElem* p);
Unk_SortRec* FUN_140889030(RSortElem* p);
Unk_CatRec* FUN_140889040(RCatElem* p);
int FUN_140930c50();
int FUN_140930ce0();

// ---- controls ----

void FUN_140c02900(void* pDlg, RTypeList* pRet, CString strName);
void FUN_140bb4b10(void* pDlg, RButton* pRet, CString strName);
void FUN_140e52670(void* pDlg, RCheck* pRet, CString strName);
void FUN_140c28560(void* pDlg, RCombo* pRet, CString strName);
void FUN_140e35bd0(void* pDlg, Unk_SearchRef* pRet, CString strName);
void FUN_140ba4b70(void* pDlg, RCubeList* pRet, CString strName);
int FUN_140c02d70(RTypeList* p);
int FUN_140bcc0c0(RTypeList* p, int n);
Unk_CubeCtl* FUN_140bcc3f0(RTypeList* p);
int FUN_140acd9c0(RButton* p);
Unk_CubeCtl* FUN_140acd9e0(RButton* p);
int FUN_140a58460(RCheck* p);
Unk_CubeCtl* FUN_140a58490(RCheck* p);
int FUN_140bc03e0(RCombo* p, int n);
int FUN_140bc04f0(RCombo* p);
Unk_CubeCtl* FUN_140bc0530(RCombo* p);
int FUN_140bc0500(Unk_SearchRef* p);
Unk_CubeCtl* FUN_140bc0550(Unk_SearchRef* p);
int FUN_140ba4ee0(RCubeList* p, int n);
Unk_CubeCtl* FUN_140acd9f0(RCubeList* p);
void FUN_140d02fa0(RDisp* p, ASDisplayObject* pObj);
int FUN_140d03130(RDisp* p, int n);
Unk_CubeCtl* FUN_140d03230(RDisp* p);
ASDialog* FUN_140ba7c60(void* pRef);
int FUN_1422c76c0(Unk_CubeCtl* p);
void FUN_1422c7630(void* pDlg, int n);
int FUN_1422cf520(Unk_CubeCtl* p);
int FUN_1422d4e20(void* p, const CString& str);
void FUN_1422dcca0(Unk_CubeCtl* p, int n);
void FUN_1422dd000(Unk_CubeCtl* p, int n);
unsigned int FUN_1422dd150(Unk_CubeCtl* p);
void FUN_1422dd1d0(Unk_CubeCtl* p);
void FUN_1422dd230(Unk_CubeCtl* p, ASObj& obj);
void FUN_1422df5f0(Unk_CubeCtl* p, int n);
void FUN_1422df690(Unk_CubeCtl* p, int n);
unsigned int FUN_1422dfb90(Unk_CubeCtl* p);
void FUN_1422dfc10(Unk_CubeCtl* p);
void FUN_1422dfc70(Unk_CubeCtl* p, ASObj& obj);
int FUN_1407cce10(Scaleform::GFx::Value* p);
int FUN_1409c1720(void* p);

// ---- items, strings, message boxes ----

int FUN_1401b5240(RItemInfo* p, int n);
Unk_InfoRec* FUN_1401b52a0(RItemInfo* p);
int FUN_140203c60(RItemInfo* p);
void FUN_14053f870(RItemInfo* pRet, int nItemId);
bool FUN_14053cde0(Unk_ItemEquipData* p);
int FUN_14053feb0(int nItemId);
void FUN_1405566e0(void* pMgr, RItemMeta* pRet, int nItemId);
int FUN_140885250(RItemMeta* p, int n);
Unk_MetaMgr* FUN_14056d580(RItemMeta* p);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1401ceea0(const wchar_t* szFmt, int n);
CStringW FUN_1409404f0(int n);
CStringW FUN_1409e97f0(int nId, int* pArg);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1418fec00(int nCurrency, int nPrice, int n);
class Unk_PalStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);   // string table lookup (exe member: this=rcx, hidden return=rdx)
};
Unk_PalStrings* FUN_1401a9d70();
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& strA, const CStringW& strB);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strA);
bool FUN_140375130(void* p);
int FUN_14036e5b0(Unk_UserSvc* p);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int n, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> sp);
void FUN_140d73aa0(CStringW strMsg, int n, void* pOwner, CStringW strTag);
void FUN_140d73bc0(int nStringId, int n, void* pOwner, CStringW strTag);
void FUN_1416fb340(void* pChat, const CStringW& strMsg);
void FUN_141275260(int nStringId, int a, int b);
void FUN_1412752d0(const CStringW& strKey, int n);
void FUN_1412c72d0(void* p);
void FUN_141243540(void* p);
void FUN_140df5180(MS2Ptr<CUgcItemLook>* pDst, void* pSrc);
void FUN_140874440(void* pCfg, void* pA, void* pB, int n, int m);
void FUN_140df1e00();
void FUN_140df1e90(unsigned nBox, unsigned nItemId);
void FUN_140df1f40(int nId, int n);
void FUN_140df1ff0(int nId, ATL::CAtlList<int>* pList);
Unk_SndMgr* FUN_140d86260();
void FUN_141925e70(int a, int b);
void FUN_14138bf00(void* p, int a, int b, int c);
int FUN_14138c930(void* p, int n);
int FUN_14138c9c0(void* p, int n);
bool FUN_14116d840(Unk_KeySvc* p);
int FUN_14116d9c0(Unk_KeySvc* p, int a, int b, int c);
bool FUN_14116dd30(Unk_KeySvc* p, int a, int b, int c);
int FUN_1422af2d0(Unk_InputSvc* p, int n);
int FUN_14151f6e0();
int FUN_1418dd110();
int FUN_140ad21b0(void* p);
int FUN_140d40670(void* p);
void FUN_140d40120(void* p, MS2Ptr<CItem> sp, int n);
void* FUN_140bbea00(int nId);
struct Unk_PartyDlg { void FUN_140e6e610(bool b); };
Unk_PartyDlg* FUN_140e01930(int nId);

// ---- world / editor ----

Unk_CubeEditDlg* FUN_140931900(int nId);
void* FUN_141656a80(void* pWorld);
int FUN_1408a18d0(void* p);
int FUN_1408a07b0(int nMapId, int a, int b);
Unk_StreamPoint FUN_1408a1430(Unk_StreamPoint pt);
int FUN_1408b54c0(int nKind);
int FUN_1408b5570(int nKind);
int FUN_1408b5820(int nKind);
int FUN_1408b5aa0(int nKind);
int FUN_1408b5b50(int nKind);
Unk_CubePlayer* FUN_1416625b0(void* pWorld);
Unk_CubeHolder* FUN_141530290(void* p);
int FUN_141659610(void* pPlayer);
int FUN_141659690(void* pPlayer);
int FUN_1416595d0(void* pPlayer);
int FUN_14166ce30(void* pWorld);
void* FUN_141656ad0(void* pWorld);
void FUN_141530200(void* pWorld);
void FUN_14152f140(void* pWorld, void* p);
void FUN_1410a8a20(void* pEditor, int n);
int FUN_1410a8a90(void* pEditor);
int FUN_1410a8ab0(void* pEditor);
void FUN_1410aa0c0(void* pEditor, CubeItemInfo* p);
struct Unk_PalEditorView { Unk_StreamPoint FUN_1410aa520(); };   // cursor cell (member: this=rcx, hidden return=rdx)
void FUN_1410aad50(void* pEditor);
void FUN_1410ab5a0(void* p);
void FUN_1410abb40(void* pEditor);
void FUN_1410ac1c0(void* p);
void FUN_1410ac380(void* p);
void FUN_1410ac540(void* p);
int FUN_1410ad5f0(void* pEditor);
int FUN_1410ad610(void* pEditor);
__int64 FUN_1410ad640(void* pEditor);


UIUGCItemEditDialog* FUN_140eeff60(int nId);


void* FUN_141bd0cc0(Unk_WorldMgr* p);
struct Unk_ItemEvtMgr
{
    void FUN_1419caeb0(UIItemEventListener* p);
    void FUN_1419cae20(UIItemEventListener* p);
};
Unk_ItemEvtMgr* FUN_140a6a840();
void FUN_141adbdc0(Unk_UIMgr* p, int n);
void FUN_141adc750(Unk_UIMgr* p, int nId);
void* FUN_140165cf0(void* pCfg, void* pName);
void* FUN_140168650(void* pNode, void* pName);
void FUN_140873220(void* pNode, void* pName, int* pOut);
extern char DAT_142e6b398;
extern char DAT_142e6b3a0;
extern char DAT_142e6b224;
__int64 FUN_140869440();
void FUN_140710590(COutPacket* p);
struct Unk_CubeUiData { __int64 m_0; __int64 m_8; };
Unk_CubeUiData* FUN_140c9b8b0(void* p);

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
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140ef00a0
void ASObj::FUN_140ef00a0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}


// @0x140ef4cb0
bool Unk_CubeSpRef::FUN_140ef4cb0(Unk_CubeMgr* p)
{
    return m_p == p;
}

// @0x140ef4dd0
int Unk_CubeKind::FUN_140ef4dd0()
{
    return m_540;
}

// @0x140ef4c20
UGCKeyMode::~UGCKeyMode()
{
}

// @0x140ef4be0
UGCKeyMode1::~UGCKeyMode1()
{
}

// @0x140ef4c00
UGCKeyMode2::~UGCKeyMode2()
{
}
// ---- cube focus / timer helpers ----

// @0x140ee9c90
Unk_CubeFocus::Unk_CubeFocus()
{
    m_bActive = false;
    m_nIndex = 0;
    m_nCubeId = 0;
}

// @0x140ee9cd0
bool Unk_CubeFocus::FUN_140ee9cd0()
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
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b5930(m_nCubeId);
    if (spCube.get() == 0)
        return m_nIndex;
    spCube->FUN_140defff0();
    return spCube->FUN_140defff0() - 1;
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
int Unk_CubeTimer::FUN_140ee9f30()
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
    m_map.SetAt(2, 1);
    m_map.SetAt(3, 2);
    m_map.SetAt(4, 3);
    m_map.SetAt(5, 4);
    m_map.SetAt(6, 5);
    m_map.SetAt(7, 6);
    m_map.SetAt(8, 7);
    m_map.SetAt(9, 8);
    m_map.SetAt(10, 9);
    m_map.SetAt(11, 10);
}

// @0x140eea200
UIUGCCubePaletteDialog::~UIUGCCubePaletteDialog()
{
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
}

// @0x140eea300
CString UIUGCCubePaletteDialog::vfunc_1()
{
    return "UGCCubePaletteDialog";
}

// @0x140eea350
int UIUGCCubePaletteDialog::vfunc_53(void* pCfg)
{
    if (m_80 != 0)
    {
        ATL::CAtlList<int> list(10);
        FUN_140df1ff0(0x65, &list);
        POSITION pos = list.GetHeadPosition();
        while (pos != 0)
        {
            int* pId = &list.GetAt(pos);
            FUN_140874440(pCfg, &DAT_142e6b390, &DAT_142e6b1bc, *pId, 0);
            list.GetNext(pos);
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
        for (void* pNode = FUN_140165cf0(pCfg, &DAT_142e6b398); pNode != 0; pNode = FUN_140168650(pNode, &DAT_142e6b3a0))
        {
            int nId;
            FUN_140873220(pNode, &DAT_142e6b224, &nId);
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
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    if (FUN_141659690(pPlayer) != 0)
        return 0;
    void* pEditor = FUN_141530290(pPlayer);
    if (pEditor == 0)
        return 0;
    return 1;
}

// @0x140eea550
void UIUGCCubePaletteDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    m_focus.FUN_140ee9d50();
    m_timer.FUN_140ee9f00();
    Unk_CubePaletteFilter filter;
    m_filter = filter;
    FUN_141adbdc0(FUN_1403ed2b0(), 1);
}

// @0x140eea620
void UIUGCCubePaletteDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0 && FUN_141530290(pPlayer) != 0 && FUN_141659690(pPlayer) == 0 && FUN_1416595d0(pPlayer) != 0)
    {
        FUN_140df1e00();
        FUN_140eeca50();
        FUN_140eefc50(1);
        FUN_140d86260()->vfunc_43(0xe, 0, 1000);
        FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    }
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
    if (FUN_1422dc2d0() != 0)
    {
        m_keys.vfunc_0();
        if (m_focus.FUN_140ee9cd0())
        {
            FUN_140eed620(1);
            m_focus.FUN_140ee9d50();
        }
        if (m_timer.FUN_140ee9e80())
        {
            int n = m_timer.FUN_140ee9f30();
            FUN_140eeea80(n);
            m_timer.FUN_140ee9f00();
        }
    }
}

// @0x140eea8a0
int UIUGCCubePaletteDialog::vfunc_13()
{
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    if (FUN_141659690(pPlayer) != 0)
    {
        // building mode: the quick-slot / rotate keys place the cube
        if (FUN_14116dd30(FUN_14025e7c0(), 0x493e2, 0, 0) != 0)
        {
            FUN_140ef37d0();
            return 1;
        }
        if (FUN_14116dd30(FUN_14025e7c0(), 0x49401, 0, 0) != 0)
        {
            FUN_140ef37d0();
            return 1;
        }
        for (unsigned int i = 0; i < 0x19; i++)
        {
            if (FUN_14116dd30(FUN_14025e7c0(), i + 0x7a121, 0, 0) != 0)
            {
                FUN_140ef37d0();
                return 1;
            }
        }
        return 0;
    }
    if (FUN_141659610(pPlayer) == 0)
        return 0;
    if (FUN_1416595d0(pPlayer) == 0)
        return 0;
    if (FUN_141530290(pPlayer) == 0)
        return 0;
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x1c, 0, 0) != 0)
    {
        // Enter in the search box
        if (FUN_140b632f0() != 0)
        {
            CString strKey(m_20);
            if (FUN_1422d4e20(FUN_140b632f0(), strKey) == 0)
                return 0;
        }
        ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.get());
        if (pDlg != 0)
        {
            Unk_SearchRef spEdit;
            FUN_140e35bd0(this, &spEdit, CString("m_cubeSearch"));
            if (FUN_140bc0500(&spEdit) != 0)
            {
                if (FUN_1422c76c0(FUN_140bc0550(&spEdit)) == 0)
                {
                    FUN_1422c7630(pDlg, 0);
                    FUN_1422c7630(FUN_140bc0550(&spEdit), 1);
                }
                else
                {
                    char bEnter;
                    {
                        Scaleform::GFx::Value res = FUN_140bc0550(&spEdit)->Invoke("processEnterKey");
                        bEnter = FUN_1409c1720(&res);
                    }
                    if (bEnter != 0)
                    {
                        FUN_1422c7630(pDlg, 1);
                        FUN_1422c7630(FUN_140bc0550(&spEdit), 0);
                    }
                    FUN_140eef510(FUN_140bc0550(&spEdit)->FUN_1422e0b00());
                }
            }
            return 1;
        }
    }
    else if (FUN_14116d9c0(FUN_14025e7c0(), 0xe, 0, 0) == 0)
    {
        if (FUN_1422af2d0(FUN_14025e7a0(), m_28) == 0)
        {
            if (FUN_14116d840(FUN_14025e7c0()) != 0)
            {
                FUN_140ef4010();
                return 1;
            }
            if (FUN_14116dd30(FUN_14025e7c0(), 0x493ed, 0, 0) != 0)
            {
                if (FUN_14138c930(FUN_1409331e0(), 0x493ed) != 0)
                    return 0;
                FUN_140ef4010();
                return 1;
            }
            return FUN_140eee630();
        }
    }
    else
    {
        // Escape: leave the search box
        if (FUN_140b632f0() != 0)
        {
            CString strKey(m_20);
            if (FUN_1422d4e20(FUN_140b632f0(), strKey) == 0)
                return 0;
        }
        ASDialog* pDlg = dynamic_cast<ASDialog*>(m_30.get());
        if (pDlg != 0)
        {
            Unk_SearchRef spEdit;
            FUN_140e35bd0(this, &spEdit, CString("m_cubeSearch"));
            if (FUN_140bc0500(&spEdit) != 0)
            {
                if (FUN_1422c76c0(FUN_140bc0550(&spEdit)) != 0)
                {
                    FUN_140eef510(FUN_140bc0550(&spEdit)->FUN_1422e0b00());
                }
            }
            return 1;
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
void UIUGCCubePaletteDialog::vfunc_14(void* pItemArg)
{
    CItem* pItem = (CItem*)pItemArg;
    
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0 || FUN_1416595d0(pPlayer) == 0)
        return;
    Unk_CubeHolder* pHolder = FUN_141530290(pPlayer);
    if (pHolder == 0)
        return;
    if (FUN_14053cde0(pItem->FUN_140527840()) != 0)
    {
        FUN_140eefc50(2);
        return;
    }
    int nItemId = pItem->FUN_1405276c0();
    __int64 nUid = pItem->FUN_140526a50();
    UGCCubePalette::CubeArray arr;
    FUN_140ef0b20()->FUN_1410b5030(arr);
    for (unsigned int i = 0; i < arr.GetCount(); i++)
    {
        UGCCubePalette::CubePtr spCube = arr.GetAt(i);
        if (!(spCube == (UGCCubePalette::UGCCube*)0))
        {
            if (spCube->FUN_140def5a0() == nItemId)
            {
                if (pItem->FUN_140525f10() != 0)
                {
                    if (spCube->FUN_140defba0() != (__int64)pItem->FUN_1405283d0())
                        continue;
                }
                MS2Ptr<CubeItemInfo> spInfo = spCube->FUN_140def3d0();
                spInfo->instanceId = nUid;
            }
        }
    }
    CubeItemInfo* pSel = pHolder->FUN_1410ad670();
    if (pSel != 0 && pSel->itemId == nItemId)
    {
        if (pItem->FUN_140525f10() == 0)
        {
            pSel->instanceId = nUid;
        }
        else
        {
            MS2Ptr<CUgcItemLook> spLook = pSel->look;
            if (spLook.get() != 0)
            {
                if (spLook->m_n18 == (__int64)pItem->FUN_1405283d0())
                    pSel->instanceId = nUid;
            }
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
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    if (_stricmp("getTooltipFromItemID", (const char*)strMethod) != 0)
        return;
    int nIndex = pArgs->FUN_1422b8b10();
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57f0(nIndex + 1);
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
    if (spItem->FUN_140523c40(nItemId, nRank, 0) == 0)
        return;
    spItem->FUN_140526a70(nUid);
    spItem->FUN_1405288e0(nCount);
    MS2Ptr<CUgcItemLook> spLook = spInfo->look;
    if (spLook.get() != 0)
        spItem->FUN_140528300(spLook.get());
    ASTooltip tooltip(pPlayer, 8, 2);
    if (tooltip.FUN_1409e0d40(spItem.get()) != 0)
    {
        tooltip.FUN_1409c6dc0(7);
        tooltip.FUN_1409db7b0(spItem);
        *pRetVal = tooltip.FUN_1422bb870();
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int n = data.FUN_1422b8a10();
            FUN_140ef41b0(n + 1);
            FUN_140eefdd0(n);
        }
        return 1;
    }
    if (_stricmp("OnCubeTypeChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_filter.category = data.FUN_1422b8b10();
            m_filter.FUN_140df0180(data.FUN_1422b8b10());
            FUN_140eed2d0();
            FUN_140eede00(m_filter.category);
            FUN_140eee160(m_filter.category, 0);
            FUN_140eefc50(7);
        }
        return 1;
    }
    if (_stricmp("OnMainCategoryChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            FUN_140eee160(m_filter.category, data.FUN_1422b8a10());
            FUN_140eefc50(7);
        }
    }
    else if (_stricmp("OnSubCategoryChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_filter.field10 = data.FUN_1422b8b10();
            FUN_140eefc50(7);
        }
    }
    else if (_stricmp("OnSortCategoryChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_filter.FUN_140df0140(data.FUN_1422b8b10());
            FUN_140eefc50(5);
        }
    }
    else if (_stricmp("OnUseableCube", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_filter.flag2 = data.FUN_1422b8a90();
            FUN_140eefc50(8);
        }
    }
    else if (_stricmp("OnOwnershipCube", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_filter.flag1 = data.FUN_1422b8a90();
            FUN_140eefc50(9);
        }
    }
    else if (_stricmp("onSearchCubeItem", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140eef510(data.FUN_1422b8f40());
    }
    else if (_stricmp("OnDestroyCubeItem", szMethod) == 0)
    {
        OnDestroyCubeItem();
    }
    else if (_stricmp("OnClickPreview", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8b10();
            UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57f0(nIndex + 1);
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
                spItem->FUN_140526a70(nUid);
                spItem->FUN_1405288e0(nCount);
                MS2Ptr<CUgcItemLook> spLook = spInfo->look;
                if (spLook.get() != 0)
                    spItem->FUN_140528300(spLook.get());
                if (FUN_140d40670(FUN_1409bb9e0()) != 0)
                    FUN_140d40120(FUN_1409bb9e0(), spItem, 0);
            }
        }
    }
    else if (_stricmp("OnDoubleClickCube", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            FUN_140eef7e0(data.FUN_1422b8b10() + 1);
            return 1;
        }
    }
    return 0;
}

// @0x140eec0b0
void UIUGCCubePaletteDialog::FUN_140eec0b0(unsigned __int64 uid)
{
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    if (FUN_1416595d0(pPlayer) == 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(uid);
    if (spItem == (CItem*)0)
        return;
    Unk_CubeHolder* pHolder = FUN_141530290(pPlayer);
    if (pHolder == 0)
        return;
    if (FUN_14053cde0(spItem->FUN_140527840()))
    {
        FUN_140eed620(0);
        UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b5a70(uid);
        if (spCube.get() != 0)
        {
            int nItemId = spItem->FUN_1405276c0();
            __int64 nItemUid = spItem->FUN_140526a50();
            FUN_140eef560(spCube->FUN_140defff0());
            CubeItemInfo* pSel = pHolder->FUN_1410ad670();
            if (pSel != 0 && pSel->itemId == nItemId)
            {
                if (spItem->FUN_140525f10())
                {
                    MS2Ptr<CUgcItemLook> spLook = pSel->look;
                    if (static_cast<bool>(spLook.get()))
                    {
                        if (spLook->m_n18 == (__int64)spItem->FUN_1405283d0())
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
        FUN_140ef0b20()->FUN_1410b54d0(uid);
        FUN_140ef37d0();
    }
}

// @0x140eec330 (delegate callback: the buy-cube message box was answered)
bool UIUGCCubePaletteDialog::FUN_140eec330(int nBtn, const CMsgBoxData& data)
{
    if (nBtn == 0)
    {
        UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57a0();
        if (!(spCube == (UGCCubePalette::UGCCube*)0))
        {
            COutPacket pkt(0x53, 0);
            pkt.Encode1(6);
            pkt.Encode8(spCube->FUN_140def5f0());
            FUN_140710590(&pkt);
        }
    }
    return true;
}

// @0x140eec410
bool UIUGCCubePaletteDialog::FUN_140eec410(int nBtn, const CMsgBoxData& data)
{
    if (nBtn == 0)
    {
        if (const_cast<CMsgBoxData&>(data).FUN_141a04aa0() != 0)
        {
            __int64 n = FUN_140869440();
            FUN_140c9b8b0(FUN_1409a8b10())->m_8 = n;
            FUN_141243540(FUN_1409a8b10());
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
int UIUGCCubePaletteDialog::FUN_140eec4d0(int nTypeId, Unk_StreamPoint* pPos)
{
    RTypeTbl spTypes;
    FUN_140886490(FUN_1409eed80(), &spTypes);
    if (FUN_140ef0630(&spTypes, 0) != 0)
        return 0;
    RDisp spRoot;
    FUN_140d02fa0(&spRoot, dynamic_cast<ASDisplayObject*>(m_30.get()));
    if (FUN_140d03130(&spRoot, 0) != 0)
        return 0;
    RTypeList spList;
    FUN_140c02900(this, &spList, CString("m_cubeTypeList"));
    if (FUN_140bcc0c0(&spList, 0) != 0)
        return 0;
    for (unsigned int i = 0; i < FUN_140889fb0(FUN_140889050(&spTypes)); i++)
    {
        RTypeElem spType;
        FUN_140888330(&spType, FUN_140889f70(FUN_140889050(&spTypes), i));
        if (FUN_140888ed0(&spType, 0) != 0)
            continue;
        if ((FUN_140930c50() == 0 || FUN_140889020(&spType)->flag != 0) && FUN_140889020(&spType)->id == nTypeId)
        {
            Unk_CubeCtl* pRoot = FUN_140d03230(&spRoot);
            *pPos = Unk_StreamPoint(pRoot->FUN_1422c10a0(), pRoot->FUN_1422c1110(), pRoot->FUN_1422c1180());
            Unk_CubeCtl* pList = FUN_140bcc3f0(&spList);
            pPos->FUN_140a4e560(Unk_StreamPoint(pList->FUN_1422c10a0(), pList->FUN_1422c1110(), pList->FUN_1422c1180()));
            Scaleform::GFx::Value vRow = FUN_140bcc3f0(&spList)->FUN_140ba26d0("getRendererAt", i);
            if (FUN_1407cce10(&vRow) == 0)
                return 0;
            RDisp spRow;
            FUN_140d02fa0(&spRow, new Unk_CubeRenderer(vRow, m_28));
            Unk_CubeCtl* pRow = FUN_140d03230(&spRow);
            pPos->FUN_140a4e560(Unk_StreamPoint(pRow->FUN_1422c10a0(), pRow->FUN_1422c1110(), pRow->FUN_1422c1180()));
            return 1;
        }
    }
    return 0;
}

// @0x140eeca50 (fill the controls from the filter)
void UIUGCCubePaletteDialog::FUN_140eeca50()
{
    m_filter.includeOwned = FUN_140930c50() == 0;
    FUN_140eecfe0();
    FUN_140eed2d0();
    {
        RTypeList spCtl;
        FUN_140c02900(this, &spCtl, CString("m_cubeTypeList"));
        if (FUN_140c02d70(&spCtl) != 0)
            FUN_140bcc3f0(&spCtl)->FUN_1422c1fe0(1);
    }
    {
        RButton spCtl;
        FUN_140bb4b10(this, &spCtl, CString("m_buyCube"));
        if (FUN_140acd9c0(&spCtl) != 0)
        {
            FUN_140acd9e0(&spCtl)->FUN_1422c1fe0(0);
            FUN_140acd9e0(&spCtl)->vfunc_3(0);
        }
    }
    {
        RCheck spCtl;
        FUN_140e52670(this, &spCtl, CString("m_useable"));
        if (FUN_140a58460(&spCtl) != 0)
        {
            FUN_140a58490(&spCtl)->FUN_1422c1fe0(1);
            FUN_140a58490(&spCtl)->FUN_1422ce090(m_filter.flag2);
        }
    }
    {
        RCheck spCtl;
        FUN_140e52670(this, &spCtl, CString("m_ownership"));
        if (FUN_140a58460(&spCtl) != 0)
        {
            if (FUN_140930c50() == 0)
            {
                FUN_140a58490(&spCtl)->FUN_1422c1fe0(1);
                FUN_140a58490(&spCtl)->FUN_1422ce090(m_filter.flag1);
            }
            else
            {
                FUN_140a58490(&spCtl)->FUN_1422c1fe0(0);
            }
        }
    }
    {
        RCombo spCtl;
        FUN_140c28560(this, &spCtl, CString("m_mainCategory"));
        if (FUN_140bc04f0(&spCtl) != 0)
            FUN_140bc0530(&spCtl)->FUN_1422c1fe0(m_filter.FUN_140df00d0());
    }
    {
        RCombo spCtl;
        FUN_140c28560(this, &spCtl, CString("m_subCategory"));
        if (FUN_140bc04f0(&spCtl) != 0)
            FUN_140bc0530(&spCtl)->FUN_1422c1fe0(m_filter.FUN_140df00d0());
    }
    {
        RCombo spCtl;
        FUN_140c28560(this, &spCtl, CString("m_sortCategory"));
        if (FUN_140bc04f0(&spCtl) != 0)
            FUN_140bc0530(&spCtl)->FUN_1422c1fe0(m_filter.FUN_140df00d0());
    }
}

// @0x140eecfe0 (fill the cube type list from the type table)
void UIUGCCubePaletteDialog::FUN_140eecfe0()
{
    RTypeTbl spTypes;
    FUN_140886490(FUN_1409eed80(), &spTypes);
    if (FUN_140ef0630(&spTypes, 0) != 0)
        return;
    RTypeList spList;
    FUN_140c02900(this, &spList, CString("m_cubeTypeList"));
    if (FUN_140bcc0c0(&spList, 0) != 0)
        return;
    for (unsigned int i = 0; i < FUN_140889fb0(FUN_140889050(&spTypes)); i++)
    {
        RTypeElem spType;
        FUN_140888330(&spType, FUN_140889f70(FUN_140889050(&spTypes), i));
        if (FUN_140888ed0(&spType, 0) != 0)
            continue;
        if (FUN_140930c50() == 0 || FUN_140889020(&spType)->flag != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20((const char*)s_label, CStringW(FUN_140889020(&spType)->name));
            obj.FUN_1409c0d20("categoryID", FUN_140889020(&spType)->id);
            obj.FUN_140ef0000("filter", FUN_140889020(&spType)->filter);
            FUN_1422dd230(FUN_140bcc3f0(&spList), obj);
        }
    }
    unsigned int nSel = FUN_1422dd150(FUN_140bcc3f0(&spList));
    int nIndex = 7;
    if (nSel < 8)
        nIndex = FUN_1422dd150(FUN_140bcc3f0(&spList));
    FUN_1422dd000(FUN_140bcc3f0(&spList), nIndex);
    FUN_1422dcca0(FUN_140bcc3f0(&spList), 0);
    FUN_140bcc3f0(&spList)->vfunc_24(1);
}

// @0x140eed2d0 (fill the sort list from the sort table)
void UIUGCCubePaletteDialog::FUN_140eed2d0()
{
    RCombo spCtl;
    FUN_140c28560(this, &spCtl, CString("m_sortCategory"));
    if (FUN_140bc03e0(&spCtl, 0) != 0)
        return;
    if (m_filter.FUN_140df00d0() == 0)
    {
        FUN_140bc0530(&spCtl)->FUN_1422c1fe0(0);
        FUN_1422dfc10(FUN_140bc0530(&spCtl));
        FUN_140bc0530(&spCtl)->vfunc_24(1);
        return;
    }
    RSortTbl spSorts;
    FUN_1408864e0(FUN_1409eed80(), &spSorts);
    if (FUN_140ef0670(&spSorts, 0) != 0)
        return;
    FUN_140bc0530(&spCtl)->FUN_1422c1fe0(1);
    FUN_1422dfc10(FUN_140bc0530(&spCtl));
    for (unsigned int i = 0; i < FUN_140ef0ae0(FUN_140889060(&spSorts)); i++)
    {
        RSortElem spSort;
        FUN_1408883e0(&spSort, FUN_140ef0a60(FUN_140889060(&spSorts), i));
        if (FUN_140ef05f0(&spSort, 0) != 0)
            continue;
        ASObj obj(2);
        obj.FUN_1407cbb20((const char*)s_label, CStringW(FUN_140889030(&spSort)->name));
        obj.FUN_140ef00a0("sortOrder", FUN_140889030(&spSort)->order);
        FUN_1422dfc70(FUN_140bc0530(&spCtl), obj);
    }
    unsigned int nSel = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    int nIndex = 5;
    if (nSel < 6)
        nIndex = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    FUN_1422df5f0(FUN_140bc0530(&spCtl), nIndex);
    FUN_1422df690(FUN_140bc0530(&spCtl), 0);
    FUN_140bc0530(&spCtl)->vfunc_24(1);
}

#ifndef MS2_HOOK_DLL
// @0x140eed620 (rebuild the cube list; nSelect: scroll to the focused cube)
void UIUGCCubePaletteDialog::FUN_140eed620(int nSelect)
{
    RCubeList spList;
    FUN_140ba4b70(this, &spList, CString("m_cubeList"));
    if (FUN_140ba4ee0(&spList, 0) != 0)
        return;
    UGCCubePalette::CubeArray arr;
    FUN_140ef0b20()->FUN_1410b4f60(&m_filter);
    FUN_140ef0b20()->FUN_1410b5030(arr);
    FUN_1422dd1d0(FUN_140acd9f0(&spList));
    for (unsigned int i = 0; i < arr.GetCount(); i++)
    {
        UGCCubePalette::CubePtr spCube = arr.GetAt(i);
        if (spCube == (UGCCubePalette::UGCCube*)0)
            continue;
        RItemInfo spInfo;
        FUN_14053f870(&spInfo, spCube->FUN_140def5a0());
        if (FUN_1401b5240(&spInfo, 0) != 0)
            continue;
        RItemMeta spMeta;
        FUN_1405566e0(FUN_140281980(), &spMeta, spCube->FUN_140def5a0());
        if (FUN_140885250(&spMeta, 0) != 0)
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
            int nSale = (int)((1.0 - fRate) * 100.0 + 0.5);
            CStringW strSale;
            strSale = FUN_14052bd00(0x98e, FUN_1401ceea0(L"{0}", nSale));
            obj.FUN_1407cbb20("sale", CStringW(strSale));
        }
        __int64 nUgc = spCube->FUN_140defba0();
        __int64 nUid = spCube->FUN_140def5f0();
        int nId = spCube->FUN_140def5a0();
        if (FUN_14056d580(&spMeta)->FUN_140549470(nId, nUid, nUgc) != 0)
            obj.FUN_1407cbb20((const char*)s_paymentIcon, spCube->FUN_140defd20());
        bool bDoubleClick = false;
        if (FUN_1401b52a0(&spInfo)->FUN_14053d6f0() != 0)
        {
            MS2Ptr<CubeItemInfo> spA = spCube->FUN_140def3d0();
            if (spA.get() != 0)
            {
                MS2Ptr<CubeItemInfo> spB = spCube->FUN_140def3d0();
                if (spB->FUN_1408b3860() == 0)
                    bDoubleClick = true;
            }
        }
        if (bDoubleClick)
            obj.FUN_1407cbbe0("enableDBClick", true);
        FUN_1422dd230(FUN_140acd9f0(&spList), obj);
    }
    if (nSelect == 0)
    {
        FUN_140acd9f0(&spList)->vfunc_24(1);
    }
    else
    {
        int nFocus = m_focus.FUN_140ee9d70();
        FUN_1422dcca0(FUN_140acd9f0(&spList), nFocus);
        FUN_140acd9f0(&spList)->vfunc_24(1);
        FUN_140ef41b0(nFocus + 1);
        FUN_140eefdd0(nFocus);
    }
}
#endif

// @0x140eede00 (fill the main category list of a cube type)
void UIUGCCubePaletteDialog::FUN_140eede00(int nCubeType)
{
    RCombo spCtl;
    FUN_140c28560(this, &spCtl, CString("m_mainCategory"));
    if (FUN_140bc03e0(&spCtl, 0) != 0)
        return;
    if (m_filter.FUN_140df00d0() == 0)
    {
        FUN_140bc0530(&spCtl)->FUN_1422c1fe0(0);
        FUN_1422dfc10(FUN_140bc0530(&spCtl));
        FUN_140bc0530(&spCtl)->vfunc_24(1);
        return;
    }
    RCatTbl spCats;
    FUN_140886530(FUN_1409eed80(), &spCats, nCubeType);
    if (FUN_140ef06b0(&spCats, 0) != 0)
        return;
    FUN_140bc0530(&spCtl)->FUN_1422c1fe0(1);
    FUN_1422dfc10(FUN_140bc0530(&spCtl));
    for (unsigned int i = 0; i < FUN_140ef0af0(FUN_140ef0750(&spCats)); i++)
    {
        RCatElem spCat;
        FUN_140888480(&spCat, FUN_140ef0aa0(FUN_140ef0750(&spCats), i));
        if (FUN_140888f10(&spCat, 0) != 0)
            continue;
        if (FUN_140930c50() == 0 || FUN_140889040(&spCat)->flag != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20((const char*)s_label, CStringW(FUN_140889040(&spCat)->name));
            FUN_1422dfc70(FUN_140bc0530(&spCtl), obj);
        }
    }
    unsigned int nSel = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    int nIndex = 0xf;
    if (nSel < 0x10)
        nIndex = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    FUN_1422df5f0(FUN_140bc0530(&spCtl), nIndex);
    FUN_1422df690(FUN_140bc0530(&spCtl), 0);
    FUN_140bc0530(&spCtl)->vfunc_24(1);
}

// @0x140eee160 (fill the sub category list of a main category)
void UIUGCCubePaletteDialog::FUN_140eee160(int nCubeType, unsigned int nMainCategory)
{
    RCombo spCtl;
    FUN_140c28560(this, &spCtl, CString("m_subCategory"));
    if (FUN_140bc03e0(&spCtl, 0) != 0)
        return;
    if (m_filter.FUN_140df00d0() == 0)
    {
        m_filter.field10 = 0;
        FUN_140bc0530(&spCtl)->FUN_1422c1fe0(0);
        FUN_1422dfc10(FUN_140bc0530(&spCtl));
        FUN_140bc0530(&spCtl)->vfunc_24(1);
        return;
    }
    RCatTbl spCats;
    FUN_140886530(FUN_1409eed80(), &spCats, nCubeType);
    if (FUN_140ef06b0(&spCats, 0) != 0)
        return;
    if (FUN_140ef0af0(FUN_140ef0750(&spCats)) <= nMainCategory)
        return;
    RCatElem spMain;
    FUN_140888480(&spMain, FUN_140ef0aa0(FUN_140ef0750(&spCats), (__int64)(int)nMainCategory));
    if (FUN_140888f10(&spMain, 0) != 0)
        return;
    FUN_140bc0530(&spCtl)->FUN_1422c1fe0(1);
    FUN_1422dfc10(FUN_140bc0530(&spCtl));
    RCatElem spFirst;
    FUN_1408884f0(&spFirst, 0);
    for (unsigned int i = 0; i < FUN_140ef0af0(&FUN_140889040(&spMain)->subs); i++)
    {
        RCatElem spSub;
        FUN_140888480(&spSub, FUN_140ef0aa0(&FUN_140889040(&spMain)->subs, i));
        if (FUN_140888f10(&spSub, 0) != 0)
            continue;
        if (FUN_140930c50() == 0 || FUN_140889040(&spSub)->flag != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20((const char*)s_label, CStringW(FUN_140889040(&spSub)->name));
            obj.FUN_1409c0d20("categorylist", FUN_140889040(&spSub)->id);
            FUN_1422dfc70(FUN_140bc0530(&spCtl), obj);
            if (FUN_140888f10(&spFirst, 0) != 0)
                FUN_140ef0500(&spFirst, &spSub);
        }
    }
    unsigned int nSel = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    int nIndex = 0xf;
    if (nSel < 0x10)
        nIndex = FUN_1422dfb90(FUN_140bc0530(&spCtl));
    FUN_1422df5f0(FUN_140bc0530(&spCtl), nIndex);
    FUN_1422df690(FUN_140bc0530(&spCtl), 0);
    FUN_140bc0530(&spCtl)->vfunc_24(1);
    if (FUN_140ef0730(&spFirst) != 0)
        m_filter.field10 = FUN_140889040(&spFirst)->id;
}

// @0x140eee630 (the hot keys of the palette; the player must not be building)
int UIUGCCubePaletteDialog::FUN_140eee630()
{
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x39, 0, 0) != 0)
    {
        if (FUN_14138c930(FUN_1409331e0(), 0x493ed) != 0)
            return 0;
        FUN_140eefe00();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x1e, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x1e) != 0)
            return 0;
        if (FUN_140ad21b0(FUN_140953f30()) != 0)
            return 0;
        FUN_141adc750(FUN_1403ed2b0(), 0x4e85);
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x12, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x12) != 0)
            return 0;
        FUN_140ef3840();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x13, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x13) != 0)
            return 0;
        FUN_140ef3f00();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x11, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x11) != 0)
            return 0;
        if (FUN_140ad21b0(FUN_140953f30()) != 0)
            return 0;
        FUN_140ef3f70();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x1f, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x1f) != 0)
            return 0;
        if (FUN_140ad21b0(FUN_140953f30()) != 0)
            return 0;
        FUN_140ef3fc0();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x2e, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x2e) != 0)
            return 0;
        FUN_140ef44f0();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x7a, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x7a) != 0)
            return 0;
        FUN_140ef0b20()->FUN_1410b6210();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x7f, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x7f) != 0)
            return 0;
        FUN_140ef0b20()->FUN_1410b6260();
        return 1;
    }
    if (FUN_14116d9c0(FUN_14025e7c0(), 0x21, 0, 0) != 0)
    {
        if (FUN_14138c9c0(FUN_1409331e0(), 0x21) != 0)
            return 0;
        FUN_140ef0b20()->FUN_1410b62d0();
        return 1;
    }
    POSITION pos = m_map.GetHeadPosition();
    while (pos != 0)
    {
        int nKey = m_map.GetKeyAt(pos);
        int nValue = m_map.GetValueAt(pos);
        if (FUN_14116d9c0(FUN_14025e7c0(), nKey, 0, 0) != 0)
        {
            FUN_140eef670(nValue);
            return 1;
        }
        m_map.GetNext(pos);
    }
    return 0;
}

#ifndef MS2_HOOK_DLL
// @0x140eeea80 (select / preview the cube of a list row)
void UIUGCCubePaletteDialog::FUN_140eeea80(int nRow)
{
    int nIndex = nRow + 1;
    ASDialog* pDlg = dynamic_cast<ASDialog*>(FUN_140ba7c60(&m_30));
    if (pDlg == 0)
        return;
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57f0(nIndex);
    if (spCube.get() == 0)
    {
        ASObj res(2);
        pDlg->Invoke("clearPreviewCube", res);
        return;
    }
    RItemInfo spInfo;
    FUN_14053f870(&spInfo, spCube->FUN_140def5a0());
    if (FUN_1401b5240(&spInfo, 0) != 0)
        return;
    int nItemId = spCube->FUN_140def5a0();
    RItemMeta spMeta;
    FUN_1405566e0(FUN_140281980(), &spMeta, nItemId);
    if (FUN_140885250(&spMeta, 0) != 0)
        return;
    bool bShowCount = FUN_140930c50() == 0;
    int nCount = 0;
    int nMax = 0;
    if (bShowCount)
    {
        nCount = spCube->FUN_140defe70();
        nMax = spCube->FUN_140defed0();
    }
    ASObj obj(2);
    obj.FUN_1409c0d20((const char*)s_itemID, spCube->FUN_140def5a0());
    obj.FUN_1407cbb20((const char*)s_itemName, spCube->FUN_140def710());
    obj.FUN_1407cbb20((const char*)s_iconPath, spCube->FUN_140def880());
    obj.FUN_1407cbbe0((const char*)s_itemLock, spCube->FUN_140def420());
    if (bShowCount)
    {
        if (FUN_1401b52a0(&spInfo)->FUN_14053cde0() == 0)
        {
            obj.FUN_1409c0d20((const char*)s_itemCount, nMax);
            obj.FUN_1409c0d20((const char*)s_itemMaxCount, nCount);
        }
        else if (nCount != 0)
        {
            obj.FUN_1409c0d20((const char*)s_itemCount, nMax);
            obj.FUN_1409c0d20((const char*)s_itemMaxCount, nCount);
        }
    }
    __int64 nUgc = spCube->FUN_140defba0();
    __int64 nUid = spCube->FUN_140def5f0();
    int nId = spCube->FUN_140def5a0();
    if (FUN_14056d580(&spMeta)->FUN_140549470(nId, nUid, nUgc) != 0)
    {
        __int64 nPrice = spCube->FUN_140def620();
        __int64 nOrigin = spCube->FUN_140def6c0();
        obj.FUN_1407cbb20((const char*)s_paymentIcon, spCube->FUN_140defd20());
        obj.FUN_1407cbb20((const char*)s_itemPrice, FUN_1409404f0(nPrice));
        if (nPrice < nOrigin)
            obj.FUN_1407cbb20((const char*)s_originPrice, FUN_1409404f0(nOrigin));
    }
    if (spCube->FUN_140defba0() != 0)
    {
        int nHave = 0;
        int nNeed = 0;
        if (bShowCount)
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
#endif

// @0x140eef140 (the destroy-cube message box of the selected cube)
void UIUGCCubePaletteDialog::OnDestroyCubeItem()
{
    MS2Ptr<CubeItemInfo> spSel = FUN_140ef0b20()->FUN_1410b55b0();
    if (spSel.get() == 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2e20.FUN_1408fbf90(spSel->instanceId);
    if (spItem == (CItem*)0)
        return;
    int nCount = spItem->FUN_140526c50();
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, FUN_1409e97f0(0xdf, &nCount), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01600(spItem->FUN_140526a50());
        spBox->FUN_141a024a0(0);
        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), spItem->FUN_140526bd0(), spItem->FUN_140526c50(), -1, -1, 1);
        spBox->FUN_141a01700(0x475, 0x476, 0);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIUGCCubePaletteDialog::FUN_140eec330));
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
    RCubeList spList;
    FUN_140ba4b70(this, &spList, CString("m_cubeList"));
    if (FUN_140ba4ee0(&spList, 0) == 0)
    {
        if ((unsigned)(FUN_1422dd150(FUN_140acd9f0(&spList)) - 1) <= (unsigned)(nRow - 1))
            nRow = FUN_1422dd150(FUN_140acd9f0(&spList));
        FUN_1422dcca0(FUN_140acd9f0(&spList), nRow - 1);
    }
}

// @0x140eef670 (select a row of the page: the 10-per-page cube list)
void UIUGCCubePaletteDialog::FUN_140eef670(int nRow)
{
    RCubeList spList;
    FUN_140ba4b70(this, &spList, CString("m_cubeList"));
    if (FUN_140ba4ee0(&spList, 0) == 0)
    {
        nRow = FUN_1422cf520(FUN_140acd9f0(&spList)) * 10 + nRow;
        if (FUN_140ef0b20()->FUN_1410b6060(nRow) == 3)
        {
            if (FUN_140375130(FUN_1403ed2d0()->FUN_141bd30a0().get()) == 0)
                FUN_141275260(0x6f6, 1, 1);
            else
                FUN_141275260(0x6f7, 1, 1);
        }
        FUN_1422dcca0(FUN_140acd9f0(&spList), nRow - 1);
    }
}

// @0x140eefc50 (what to refresh: 1/5..9 reset the focus, 2 buy, 3/4 page, 10 focus the first)
void UIUGCCubePaletteDialog::FUN_140eefc50(int nState)
{
    int nCount = FUN_140ef0b20()->FUN_1410b5d70();
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
    case 2:
    {
        RItemInfo spInfo;
        FUN_14053f870(&spInfo, FUN_140ef0b20()->FUN_1410b5bc0());
        if (FUN_140203c60(&spInfo) == 0 || FUN_1401b52a0(&spInfo)->FUN_14053cde0() == 0)
            FUN_140eefdd0(nCount - 1);
        else
            m_focus.FUN_140ee9cf0(0, FUN_140ef0b20()->FUN_1410b5bc0());
        break;
    }
    case 3:
    case 4:
        FUN_140eefdd0(nCount - 1);
        break;
    case 10:
        m_focus.FUN_140ee9cf0(0, FUN_140ef0b20()->FUN_1410b5bc0());
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
    if (FUN_1403ed2b0() != 0)
    {
        Unk_UIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (FUN_1403e8a70(&ref) != 0)
            return dynamic_cast<UIUGCItemEditDialog*>(FUN_1403ed9e0(&ref));
    }
    return 0;
}

// @0x140eef7e0 (install the cube at a list index into the open UGC item editor)
void UIUGCCubePaletteDialog::FUN_140eef7e0(int nCubeIndex)
{
    MS2Ptr<UIUGCItemEditDialog> spEdit(FUN_140eeff60(0x4e69));
    if (spEdit.get()->vfunc_55() == 0)
        return;
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57f0(nCubeIndex);
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    int nId = spCube->FUN_140def5a0();
    RItemInfo spInfo;
    FUN_14053f870(&spInfo, nId);
    if (FUN_1401b5240(&spInfo, 0) != 0)
        return;
    if (FUN_1401b52a0(&spInfo)->FUN_14053d6f0() == 0)
        return;
    MS2Ptr<CubeItemInfo> spCubeInfo = spCube->FUN_140def3d0();
    if (spCubeInfo.get() != 0 && spCubeInfo->FUN_1408b3860() != 1)
    {
        if (spCube->FUN_140defed0() != 0)
        {
            FUN_1412752d0(CStringW(L"s_construct_edit_design_install_empty_ugc"), 1);
            return;
        }
        __int64 nUid = spCube->FUN_140def5f0();
        int nRank = FUN_14053feb0(nId);
        __int64 nCount = spCubeInfo->count;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nId, nRank, 0))
        {
            spItem->FUN_140526a70(nUid);
            spItem->FUN_1405288e0(nCount);
            spItem->FUN_140526c70(spCube->FUN_140defe70());
            MS2Ptr<CUgcItemLook> spLook(spCubeInfo->look);
            if (spLook.get() != 0)
                spItem->FUN_140528300(spLook.get());
            spEdit.get()->FUN_141b463b0(spItem);
            FUN_1403ed2b0()->FUN_141adc530(0x4e69);
        }
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
    FUN_1403ed2b0()->FUN_141adbdc0(1);
}

// @0x140ef1c30
UGCKeyMode1::UGCKeyMode1()
{
}

// @0x140ef1c70 (ray cast under the cursor: preview the picked cube)
// MS2-FUNCTIONAL: transliterated from the decompile
void UGCKeyMode1::vfunc_1()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0 || FUN_1416595d0(pWorld) == 0)
        return;
    Unk_CubePlayer* pPlayer = FUN_1416625b0(pWorld);
    if (pPlayer == 0)
        return;
    FUN_1403ed2b0()->FUN_141adbdc0(0);
    if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
        return;
    if (FUN_14025e7c0()->FUN_14116db80(0, 0, 0) == 0)
        return;
    float fX = 0;
    float fY = 0;
    FUN_140aadf80()->FUN_141b90e30(&fX, &fY);
    Unk_CubePickPtr spPick = FUN_1409478c0()->FUN_140af0850(fX, fY, true, true, false, 0);
    if (spPick.FUN_140a16c00() == 0)
        return;
    for (unsigned int i = 0;; i++)
    {
        if (i >= spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0())
            return;
        Unk_CubePickHit* pHit = spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i);
        if (pHit == 0)
            continue;
        Unk_CubeObject* pObj = DAT_143afbbb0.FUN_14098d8d0(pHit->FUN_140a17cb0());
        if (pObj == 0)
            continue;
        if (FUN_1403ed2d0()->FUN_141bd1050(pHit->FUN_140a17cb0()) != 0)
            continue;
        Unk_CubeKind* pKind = DAT_143d69198.FUN_140a17af0(pObj->FUN_140a17cd0());
        if (pKind != 0 && (pKind->FUN_140ef4dd0() == 1 || pKind->FUN_140ef4dd0() == 2 || pKind->FUN_140ef4dd0() == 3))
            continue;
        Unk_StreamPoint vUp(0, 0, 250.0f);
        Unk_StreamPoint vPos = *pObj->FUN_140947900();
        Unk_NiPoint3 vEnd(vPos.FUN_14097fd50(Unk_StreamPoint(0, 0, 75.0f)));
        if (FUN_1409670e0()->FUN_1410cdd80(vPos, pPlayer->vfunc_20(), 200.0f, DAT_143ab2398) == 0)
            continue;
        void* pCube = FUN_1409670e0()->FUN_1410b8ab0(Unk_StreamPoint(vEnd.x, vEnd.y, vEnd.z));
        if (pCube == 0)
            continue;
        Unk_NiPoint3 vTop(Unk_StreamPoint(vEnd.x, vEnd.y, vEnd.z).FUN_14097fd50(vUp));
        Unk_StreamPoint vCell = FUN_1408a1430(Unk_StreamPoint(vTop.x, vTop.y, vTop.z));
        if (pCube == FUN_1409670e0()->FUN_1410b8790(vCell))
            vTop.z += 150.0f;
        pPlayer->vfunc_19(Unk_StreamPoint(vTop.x, vTop.y, vTop.z));
        return;
    }
}

// @0x140ef21c0 (place / remove)
void UGCKeyMode1::vfunc_5(void*, float, float)
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    Unk_CubeSpRef spMgr(FUN_1401cd040(&DAT_143b059e8));
    if (spMgr.FUN_140ef4cb0(0) != 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    Unk_StreamPoint pt = static_cast<Unk_PalEditorView*>(pEditor)->FUN_1410aa520();
    if (spMgr.FUN_1401cd1a0()->FUN_1410b7e80(pt) == 0)
        FUN_140ef2fb0();
    else
        FUN_140ef3840();
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
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0 || FUN_1416595d0(pWorld) == 0)
        return;
    Unk_CubePlayer* pPlayer = FUN_1416625b0(pWorld);
    if (pPlayer == 0)
        return;
    FUN_1403ed2b0()->FUN_141adbdc0(1);
    if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
        return;
    if (FUN_14025e7c0()->FUN_14116db80(0, 0, 0) == 0)
        return;
    float fX = 0;
    float fY = 0;
    FUN_140aadf80()->FUN_141b90e30(&fX, &fY);
    Unk_CubePickPtr spPick = FUN_1409478c0()->FUN_140af0850(fX, fY, true, true, false, 0);
    if (spPick.FUN_140a16c00() == 0)
        return;
    for (unsigned int i = 0;; i++)
    {
        if (i >= spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0())
            return;
        Unk_CubePickHit* pHit = spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i);
        if (pHit == 0)
            continue;
        Unk_CubeObject* pObj = DAT_143afbbb0.FUN_14098d8d0(pHit->FUN_140a17cb0());
        if (pObj == 0)
            continue;
        Unk_StreamPoint vUp(0, 0, 250.0f);
        Unk_StreamPoint vPos = *pObj->FUN_140947900();
        Unk_NiPoint3 vEnd(vPos.FUN_14097fd50(Unk_StreamPoint(0, 0, 75.0f)));
        if (FUN_1409670e0()->FUN_1410cdd80(vPos, pPlayer->vfunc_20(), 200.0f, DAT_143ab2398) == 0)
            continue;
        void* pCube = FUN_1409670e0()->FUN_1410b8ab0(Unk_StreamPoint(vEnd.x, vEnd.y, vEnd.z));
        if (pCube == 0)
            continue;
        Unk_NiPoint3 vTop(Unk_StreamPoint(vEnd.x, vEnd.y, vEnd.z).FUN_14097fd50(vUp));
        Unk_StreamPoint vCell = FUN_1408a1430(Unk_StreamPoint(vTop.x, vTop.y, vTop.z));
        if (pCube == FUN_1409670e0()->FUN_1410b8790(vCell))
            vTop.z += 150.0f;
        pPlayer->vfunc_19(Unk_StreamPoint(vTop.x, vTop.y, vTop.z));
        return;
    }
}

// @0x140ef2810
void UGCKeyMode2::vfunc_5(void*, float, float)
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    Unk_CubeSpRef spMgr(FUN_1401cd040(&DAT_143b059e8));
    if (spMgr.FUN_140ef4cb0(0) != 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    Unk_StreamPoint pt = static_cast<Unk_PalEditorView*>(pEditor)->FUN_1410aa520();
    if (spMgr.FUN_1401cd1a0()->FUN_1410b7e80(pt) == 0)
        FUN_140ef2fb0();
    else
        FUN_140ef3840();
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
        if (FUN_14025e7c0()->FUN_14116da30(0x3b, 0, 0) == 0)
        {
            if (FUN_14025e7c0()->FUN_14116da30(0x3c, 0, 0) == 0)
            {
                if (FUN_14025e7c0()->FUN_14116da30(0x3d, 0, 0) != 0)
                    m_mode.AssignRaw(new UGCKeyMode2());
            }
            else
            {
                m_mode.AssignRaw(new UGCKeyMode1());
            }
        }
        else
        {
            m_mode.AssignRaw(new UGCKeyMode());
        }
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
    if ((bool)m_mode.get() && FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_3(p, x, y);
}

// @0x140ef2ce0
void UGCKeyController::vfunc_3(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_4(p, x, y);
}

// @0x140ef2d90
void UGCKeyController::vfunc_4(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_5(p, x, y);
}

// @0x140ef2e40
void UGCKeyController::vfunc_5(void* p, float x, float y)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_6(p, x, y);
}

// @0x140ef2ef0
void UGCKeyController::vfunc_6(void* p, float x, float y, float f)
{
    if (!FUN_140ef4970())
        return;
    if ((bool)m_mode.get() && FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
        m_mode->vfunc_7(p, x, y, f);
}

// ---- buy / install / remove flow ----

// @0x140ef2fb0 (buy the selected cube, then install it)
// MS2-FUNCTIONAL: transliterated from the decompile
void FUN_140ef2fb0()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    if (FUN_1410ad5f0(pEditor) != 0)
        return;
    Unk_CubeSpRef spMgr(FUN_1401cd040(&DAT_143b059e8));
    if (spMgr.FUN_140ef4cb0(0) != 0)
        return;
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57a0();
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    if (spCube->FUN_140def420() != 0)
    {
        FUN_141275260(0xcac, 1, 1);
        return;
    }
    unsigned int nCount = spCube->FUN_140defe70();
    unsigned int nMax = spCube->FUN_140defed0();
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    int nStyle = FUN_1408a18d0(FUN_141656a80(pWorld));
    if (spMgr.FUN_1401cd1a0()->FUN_1410c3600(1) == 0 && spMgr.FUN_1401cd1a0()->FUN_1410c3600(3) == 0 && nCount <= nMax &&
        spMgr.FUN_1401cd1a0()->FUN_1410d55d0(nMapId, nStyle) == 0 && FUN_1408a07b0(nMapId, DAT_1439f4a7c, DAT_143ab2820) == 0 &&
        FUN_140930ce0() == 0 && FUN_140930c50() == 0)
    {
        if (spCube->FUN_140def4f0() == 0)
        {
            FUN_141275260(0xcad, 1, 1);
            return;
        }
        __int64 nNow = FUN_140869440();
        __int64 nLast = FUN_140c9b8b0(FUN_1409a8b10())->m_8;
        __int64 nPrice = spCube->FUN_140def620();
        __int64 nOrigin = spCube->FUN_140def6c0();
        if (nNow < nLast + 0x15180 || nPrice == 0)
        {
            FUN_140ef37d0();
            return;
        }
        UIUGCCubePaletteDialog* pDlg = 0;
        if (FUN_14151f6e0() != 0 && (pDlg = FUN_140ef4a50(0x4f16)) != 0)
        {
            CStringW strOrigin = FUN_1409404f0(nOrigin);
            CStringW strMsg = FUN_140ef4540();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strMsg, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                MS2Ptr<CItem> spItem(new CItem());
                if (spItem->FUN_140523c40(spCube->FUN_140def5a0(), 1, 0))
                {
                    spItem->FUN_140528300(spCube->FUN_140def3d0()->look.get());
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a01600(spItem->FUN_140526a50());
                    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 1, 1, (int)nPrice, 1);
                    spBox->FUN_141a02670(FUN_14036e5b0(FUN_140166410()) == 0);
                    spBox->FUN_141a024e0(FUN_14028de60(0x29f), 0);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(pDlg, &UIUGCCubePaletteDialog::FUN_140eec410));
                    if (nPrice < nOrigin)
                        spBox->FUN_141a01c70(strOrigin);
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
    else
    {
        FUN_140ef37d0();
    }
}

// @0x140ef37d0 (install the selected cube without buying)
void FUN_140ef37d0()
{
    void* pEditor;
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    FUN_1410aad50(pEditor);
    FUN_140df1e90(0x65, FUN_1410ad610(pEditor));
}

// @0x140ef3840 (remove the cube under the editor cursor)
// MS2-FUNCTIONAL: transliterated from the decompile
void FUN_140ef3840()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0 || FUN_14166ce30(pWorld) != 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0 || FUN_1410a8ab0(pEditor) != 0)
        return;
    Unk_CubeSpRef spMgr(FUN_1401cd040(&DAT_143b059e8));
    if (spMgr.FUN_140ef4cb0(0) != 0)
        return;
    Unk_CubeEditDlg* pDlg = FUN_140931900(0x4e5f);
    if (pDlg == 0)
        return;
    bool bShown = false;
    if (spMgr.FUN_1401cd1a0()->FUN_1410b7e80(static_cast<Unk_PalEditorView*>(pEditor)->FUN_1410aa520()) != 0)
    {
        MS2Ptr<Unk_CubeInfo> spCube((Unk_CubeInfo*)spMgr.FUN_1401cd1a0()->FUN_1410b8ab0(static_cast<Unk_PalEditorView*>(pEditor)->FUN_1410aa520()));
        IMessageListener* pOwner = static_cast<IMessageListener*>(pDlg);
        Unk_CubeInfo* pInfo = spCube.get();
        void* pLayer = spMgr.FUN_1401cd1a0()->FUN_1410c8030(pInfo->m_50, pInfo->m_54);
        if (FUN_141656ad0(pWorld) == pLayer)
        {
            int nKind = spCube.get()->FUN_1408b4f20();
            if (FUN_1408b5570(nKind) != 0)
            {
                FUN_140d73bc0(0x46f, 1, pOwner, CStringW(L"remove"));
                bShown = true;
            }
            else if (FUN_1408b54c0(nKind) != 0)
            {
                if (FUN_1408b5aa0(nKind) != 0)
                {
                    if (FUN_1408b5820(nKind) != 0)
                    {
                        if (FUN_1408b5b50(nKind) != 0)
                        {
                            CStringW strMsg = FUN_14052bd00(0x474, FUN_1401a9d70()->FUN_141811980(1, nKind));
                            FUN_1416fb340(FUN_1403b4750(), strMsg);
                            FUN_140d73aa0(CStringW(strMsg), 1, pOwner, CStringW(L"remove"));
                            bShown = true;
                        }
                    }
                    else if (spMgr.FUN_1401cd1a0()->FUN_1410c35c0() == 0)
                    {
                        FUN_140d73bc0(0x473, 1, pOwner, CStringW(L"remove"));
                        bShown = true;
                    }
                }
                else
                {
                    FUN_140d73bc0(0x472, 1, pOwner, CStringW(L"remove"));
                    bShown = true;
                }
            }
            else
            {
                if (spMgr.FUN_1401cd1a0()->FUN_1410c35c0() == 0)
                {
                    int nStr = 0x470;
                    if (FUN_140166410()->FUN_14036d570(0xd4) != 0)
                        nStr = 0x471;
                    FUN_140d73bc0(nStr, 1, pOwner, CStringW(L"remove"));
                    bShown = true;
                }
                if (FUN_140166410()->FUN_14036d570(0xd4) != 0 && !bShown)
                    FUN_14152f140(pWorld, spCube.get()->m_18);
            }
        }
    }
    if (!bShown)
        FUN_1410abb40(pEditor);
}

// @0x140ef3f00
void FUN_140ef3f00()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    FUN_1410ab5a0(pEditor);
    FUN_14138bf00(FUN_1409331e0(), 10, 0, 0);
}

// @0x140ef3f70
void FUN_140ef3f70()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    FUN_1410ac1c0(pEditor);
}

// @0x140ef3fc0
void FUN_140ef3fc0()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    FUN_1410ac380(pEditor);
}

// @0x140ef4010 (toggle the UGC edit mode)
void FUN_140ef4010()
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4e3b) != 0)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e3b);
    }
    else
    {
        void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pWorld != 0)
            FUN_141530200(pWorld);
    }
}

// @0x140ef4070 (focus a palette row, pick that cube in the editor)
void FUN_140ef4070(int nIndex)
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0 || FUN_1410a8ab0(pEditor) != 0)
        return;
    FUN_140ef0b20()->FUN_1410b5460(nIndex);
    MS2Ptr<CubeItemInfo> spSel = FUN_140ef0b20()->FUN_1410b55b0();
    if (spSel.get() == 0)
    {
        if (FUN_1410a8a90(pEditor) != 1)
            FUN_1410a8a20(pEditor, 1);
    }
    else if (FUN_1410ad640(pEditor) == spSel->instanceId)
    {
        if (FUN_1410ad610(pEditor) != spSel->itemId)
            FUN_1410aa0c0(pEditor, spSel.get());
    }
    else
    {
        FUN_1410aa0c0(pEditor, spSel.get());
    }
}

// @0x140ef41b0 (same for the cube in a palette row)
void FUN_140ef41b0(int nIndex)
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0 || FUN_1410a8ab0(pEditor) != 0)
        return;
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57f0(nIndex);
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return;
    MS2Ptr<CubeItemInfo> spSel = spCube->FUN_140def3d0();
    if (spSel.get() == 0)
    {
        if (FUN_1410a8a90(pEditor) != 1)
            FUN_1410a8a20(pEditor, 1);
    }
    else if (FUN_1410ad640(pEditor) == spSel->instanceId)
    {
        if (FUN_1410ad610(pEditor) != spSel->itemId)
            FUN_1410aa0c0(pEditor, spSel.get());
    }
    else
    {
        FUN_1410aa0c0(pEditor, spSel.get());
    }
}

// @0x140ef4330 (switch between the palette and the other edit-mode dialogs)
void FUN_140ef4330()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    if (FUN_1416595d0(pWorld) == 0 || FUN_141659690(pWorld) != 0)
    {
        if (Unk_PartyDlg* pParty = FUN_140e01930(0x4f7d))
            pParty->FUN_140e6e610(false);
        if (UIHomeMenuDialog* pHome = FUN_140ef49b0(0x4f7c))
            pHome->FUN_140c29600(false);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f16);
        FUN_1403ed2b0()->FUN_141adc530(0x4e28);
        if (Unk_CubeEditDlg* pEdit = FUN_140931900(0x4e5f))
            pEdit->FUN_1419f1d10(1, true);
    }
    else
    {
        if (Unk_PartyDlg* pParty = FUN_140e01930(0x4f7d))
            pParty->FUN_140e6e610(true);
        if (UIHomeMenuDialog* pHome = FUN_140ef49b0(0x4f7c))
            pHome->FUN_140c29600(true);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e28);
        FUN_1403ed2b0()->FUN_141adc530(0x4f16);
        if (Unk_CubeEditDlg* pEdit = FUN_140931900(0x4e5f))
            pEdit->FUN_1419f1d10(1, false);
    }
    if (void* pDlg = FUN_140bbea00(0x4ed8))
        FUN_1412c72d0(pDlg);
    if (UIUGCHousingPointDialog* pPoint = FUN_140ef4af0(0x4f28))
        pPoint->FUN_140fae0f0();
}

// @0x140ef44f0
void FUN_140ef44f0()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return;
    void* pEditor = FUN_141530290(pWorld);
    if (pEditor == 0)
        return;
    FUN_1410ac540(pEditor);
}

// @0x140ef4540 (the buy-and-install confirmation text of the selected cube)
CStringW FUN_140ef4540()
{
    UGCCubePalette::CubePtr spCube = FUN_140ef0b20()->FUN_1410b57a0();
    if (spCube == (UGCCubePalette::UGCCube*)0)
        return CStringW(L"");
    RItemInfo spInfo;
    FUN_14053f870(&spInfo, spCube->FUN_140def5a0());
    if (FUN_1401b5240(&spInfo, 0) != 0)
        return CStringW(L"");
    __int64 nPrice = spCube->FUN_140def620();
    __int64 nOrigin = spCube->FUN_140def6c0();
    CStringW strPay = FUN_1418fec00(spCube->FUN_140defcd0(), nPrice, 1);
    CStringW strOrigin = FUN_1409404f0(nOrigin);
    if (FUN_1401b52a0(&spInfo)->FUN_14053cde0() != 0)
    {
        int nHave = FUN_1408fc1b0(&DAT_143ab2e20, spCube->FUN_140def5a0());
        int nHave2 = FUN_140dfcb00(&DAT_143ab2e50, spCube->FUN_140def5a0());
        if (0 < nHave || 0 < nHave2)
        {
            if (nPrice < nOrigin)
                return FUN_1408f71a0(CStringW(L"s_home_buycube_sale_and_install_confirm"), strOrigin, strPay);
            return FUN_1405c2690(CStringW(L"s_home_buycube_and_install_confirm"), strPay);
        }
    }
    if (nPrice < nOrigin)
        return FUN_1408f71a0(CStringW(L"s_home_buycube_sale_and_install"), strOrigin, strPay);
    return FUN_1405c2690(CStringW(L"s_home_buycube_and_install"), strPay);
}

// @0x140ef4970 (in a UGC edit session)
bool UGCKeyController::FUN_140ef4970()
{
    void* pWorld = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pWorld == 0)
        return false;
    if (FUN_1416595d0(pWorld) == 0)
        return false;
    return true;
}

// @0x140ef49b0
UIHomeMenuDialog* FUN_140ef49b0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_UIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (FUN_1403e8a70(&ref) != 0)
            return dynamic_cast<UIHomeMenuDialog*>(FUN_1403ed9e0(&ref));
    }
    return 0;
}

// @0x140ef4a50
UIUGCCubePaletteDialog* FUN_140ef4a50(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_UIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (FUN_1403e8a70(&ref) != 0)
            return dynamic_cast<UIUGCCubePaletteDialog*>(FUN_1403ed9e0(&ref));
    }
    return 0;
}

// @0x140ef4af0
UIUGCHousingPointDialog* FUN_140ef4af0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_UIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (FUN_1403e8a70(&ref) != 0)
            return dynamic_cast<UIUGCHousingPointDialog*>(FUN_1403ed9e0(&ref));
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

// @0x140ef04e0
// MS2-FUNCTIONAL: implicit destructor (~MS2Ptr<UGCKeyMode>)
UGCKeyController::~UGCKeyController()
{
}

// @0x140ef0500
void FUN_140ef0500(RCatElem* pDst, RCatElem* pSrc)
{
    FUN_14088cfc0(pSrc);
    FUN_14088d5d0(pDst);
    pDst->m_p = pSrc->m_p;
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
        FUN_140159b70(0x80070057);
    return ((Unk_Arr16*)pTbl)->m_pData + n * 0x10;
}

// @0x140ef0aa0
void* FUN_140ef0aa0(void* pTbl, unsigned __int64 n)
{
    if (n >= ((Unk_Arr16*)pTbl)->m_nCount)
        FUN_140159b70(0x80070057);
    return ((Unk_Arr16*)pTbl)->m_pData + n * 0x10;
}

// @0x140ef0b20
UGCCubePalette* FUN_140ef0b20()
{
    return DAT_143ac90f0;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140EE9CD0, Unk_CubeFocus, FUN_140ee9cd0, 14, 0xDA496095);
MS2_REPLACE_METHOD(0x140EE9D50, Unk_CubeFocus, FUN_140ee9d50, 14, 0x322C4B62);
MS2_REPLACE_METHOD(0x140EE9F00, Unk_CubeTimer, FUN_140ee9f00, 27, 0x6AA3A4C7);
MS2_REPLACE_METHOD(0x140EE9F30, Unk_CubeTimer, FUN_140ee9f30, 14, 0xB2976B17);
MS2_REPLACE_METHOD(0x140EEA300, UIUGCCubePaletteDialog, vfunc_1, 61, 0x31979C2E);
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
