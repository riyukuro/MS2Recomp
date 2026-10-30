// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMyInfoDialog: the player's own character info window
// (UI id 0x2711): equipment / gem pages, stat points, title, today's memo, the codi tab period, the screenshot upload.
// The range ends with the Delegate glue of its callbacks.
// MS2-UNIT: client\ms2\uimyinfodialog.cpp
// MS2-RANGE: 0x140118fe0-0x140119150 .text$di
// MS2-RANGE: 0x141a58040-0x141a5e3c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401190a0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1401190d0 ; probe
// MS2-PIN: ??$?0VUIMyInfoDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIMyInfoDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x141a5d730 ; unique
// MS2-PIN: ??$?8PEAVUIMyInfoDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141a5d960 ; prop
// MS2-PIN: ??$?8PEAVUIMyInfoDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141a5d9d0 ; prop
// MS2-PIN: ??$?8PEAVUIMyInfoDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIMyInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141a5da40 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141a5dc80 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a5e020 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a5e080 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141a5e0e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a5e140 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141a5e170 ; unique
// MS2-PIN: ??$Call@VUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141a5e1e0 ; prop
// MS2-PIN: ??$Call@VUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141a5e220 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a5e2a0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a5e300 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMyInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141a5e360 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIMyInfoDialog@@UEAA@XZ 0x141a5de20
// MS2-PIN: ??_GUIMyInfoDialog@@UEAAPEAXI@Z 0x141a5dfd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimyinfodialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uimyinfodialog.h"
#include "ms2/client/ms2/uimodelview.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/invenslot.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/statpointmanager.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local stand-ins for the unrecovered callee types ----

class ASDialog : public ASMovieClip                             // the movie root
{
};
class Unk_MiItem;

// The world singleton (FUN_1403ed2d0).
class Unk_MiWorld
{
public:
    MyPC* FUN_141bd0cc0();                                      // the player
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // the current field
};
Unk_MiWorld* FUN_1403ed2d0();

class Unk_MiUIMgr
{
public:
    void FUN_141adc530(int nId);                                // open
    void FUN_141adc750(int nId);                                // open (toggle)
};
Unk_MiUIMgr* FUN_1403ed2b0();

class Unk_MiFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_MiFeatures* FUN_140166410();

// The notify centre (FUN_140939a10), the listener hubs.
NotifySystem* FUN_140939a10();
class Unk_MiItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* p);                 // register
    void FUN_1419caeb0(UIItemEventListener* p);                 // unregister
};
Unk_MiItemEvents* FUN_140a6a840();
class Unk_MiStatusEvents
{
public:
    void FUN_141b0cd00(UIStatusEventListener* p);
    void FUN_141b0cd90(UIStatusEventListener* p);
};
Unk_MiStatusEvents* FUN_140aa6d40();
class Unk_MiDialogEvents
{
public:
    void FUN_141928050(UIDialogEventListener* p);
    void FUN_1419280e0(UIDialogEventListener* p);
};
Unk_MiDialogEvents* FUN_14140ea40();
class Unk_MiEntityEvents
{
public:
    void FUN_1419308c0(UIEntityEventListener* p);
    void FUN_141930950(UIEntityEventListener* p);
};
Unk_MiEntityEvents* FUN_140c607b0();

// The player actor (MyPC) members used here.
class Unk_MiPc : public MyPC
{
public:
    MS2Ptr<CStatPointManager> FUN_140c25130();                  // the stat point manager
    unsigned short FUN_141661e00();                             // the symbol the player wears
    unsigned char FUN_141658f10();                              // the PcBang flag
    CStringW* FUN_141656d90();                                  // the memo of the player
};
void* FUN_1405a8e70(void* pHandle);
void* FUN_1405a8ed0(void* pHandle);
void FUN_1405a85f0(void* pHandle);
void* FUN_1401c0180(void* pSp);
void FUN_1401bfde0(void* pHandle);
void* FUN_14052cd70(void* pHandle);
void FUN_140526c10(void* pItem, int n);
// The equipped-item handle of a slot and the item handle it holds (unit_1414210f0.cpp Unk_AvatarItemHandle).
struct Unk_MiSlotHandle { void* m_p[2]; ~Unk_MiSlotHandle() { FUN_1405a85f0(this); } };
struct Unk_MiItemHandle { void* m_p[2]; ~Unk_MiItemHandle() { FUN_1401bfde0(this); } };
struct Unk_MiSlotPc { Unk_MiSlotHandle FUN_141655e10(int nSlot); };   // PC: the handle of an equip slot
struct Unk_MiSlotEquip { Unk_MiItemHandle FUN_1411dc7a0(); };         // the item handle of the equip
PC* FUN_14099eef0(GameObject* pObj);
// The equip holder of the player and its title record.
class Unk_MiTitleData
{
public:
    int FUN_1411df830();                                        // the state of the title (0 none, 1 timed, 3 expired, 4)
    bool FUN_1411df810();                                       // the active flag
    char m_pad_00[0x28];
    CMsTime m_28;                                               // +0x28 the end time
};
struct Unk_MiTitleRef
{
    void* m_00;
    Unk_MiTitleData* m_p;
};
bool FUN_140d28fe0(Unk_MiTitleRef* p, int n);                   // == null
Unk_MiTitleData* FUN_140d290c0(Unk_MiTitleRef* p);              // operator->
void FUN_140d28f70(Unk_MiTitleRef* p);                          // dtor
struct Unk_MiTitlePtr : Unk_MiTitleRef { ~Unk_MiTitlePtr() { FUN_140d28f70(this); } };
// the worn title (Unk_PCEquipSet::GetTitle, 0x140d29440)
class Unk_MiEquipSet { public: void FUN_140d29440(Unk_MiTitleRef* pOut); Unk_MiTitlePtr FUN_140d29440(); };
Unk_MiTitleData* FUN_1411f7e30(Unk_MiTitleRef* p);              // get()

// The movie children bound through the ASObj helpers.
class Unk_MiScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ed1090(const char* szMethod, CStringW strA, CStringW strB, int b);
};

void* FUN_140a50b50(void* pDragSource);
CString FUN_140be2000(const char* szFormat, const char* a1, const char* a2, const int& a3, const char* a4);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);
bool FUN_140a467d0(const MS2Ptr<AScript>* pAS);
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
CStringW FUN_1409eec40(int nId);                                // string table text by id
CStringW FUN_14062b4f0(CStringW strKey, const int* pArg);       // formatted text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void FUN_140d73aa0(CStringW strText, int nType, void* pData, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
__int64 FUN_140869440();                                        // the server time
void FUN_14187fb30(void* p);                                    // open the profile helper
void* FUN_14052d220();
int FUN_14028d260(float f);
int FUN_1408694b0(int n);
int FUN_140869490(int n);
int FUN_14086d270(void* pSpan);

// @0x143af4550 (the flag of the open animation)
static int s_nUseOpenAnim = 0;

// @0x141a5d0a0
void FUN_141a5d0a0(int n)
{
    s_nUseOpenAnim = n;
}

class Unk_MiIdList { public: int FUN_140408410(const int& nId); };   // index of an id (-1: none)
void FUN_1408377d0(ATL::CAtlArray<void*>* pOut);                // the stat keys shown
void FUN_1408377d0(ATL::CAtlArray<int>& ids);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff740(const Scaleform::GFx::Value& root, CString strName, unsigned nColor);
unsigned __int64 FUN_1409eecc0(ATL::CAtlArray<void*>* pArr);                 // count
int* FUN_1409eec00(ATL::CAtlArray<void*>* pArr, __int64 nIndex);   // element
struct Unk_MiConsts { char m_pad_00[0x9100]; unsigned m_aStatCap[1]; };   // the data table: the cap of each stat
Unk_MiConsts* FUN_1401d3200();
MS2Ptr<CItem> FUN_140ccac60(MS2Ptr<CItem> spItem);               // a copy of the item
void* FUN_1422c8e90(const CString& strName);                     // the bound data of a slot bag
void* FUN_140c544d0(void* pBind);                                // its bag
void FUN_1422cca90(void* pBag);                                  // refresh the slots
class Unk_MiTabClip { public: void FUN_1422e31e0(int nIndex); };   // the tab bar
class Unk_MiNtMgr
{
public:
    CStringW FUN_1406c61a0(short nId, MyPC* pPlayer);            // icon path
    int FUN_1406c5d60(short nId);                                // owned
};
Unk_MiNtMgr* FUN_14131e120();
class Unk_MiNtStrings { public: CStringW FUN_141811980(int nId, int nArg); };   // string of (id, symbol)
Unk_MiNtStrings* FUN_1401a9d70();
class Unk_MiScore { public: int FUN_140267c10(); };              // the trophy points
class Unk_MiTrophy { public: Unk_MiScore* FUN_140938ad0(); };
Unk_MiTrophy* FUN_1406c7600();
unsigned __int64 FUN_140837770(int nId, unsigned nCount);
void FUN_1418bee30(ASObj* pObj, int n);
void FUN_1407cbbe0(ASObj* pObj, const char* szName, bool b);
AvatarPC* FUN_140a535c0(GameObject* pObj);
class Unk_MiItemEvent { public: CItem* FUN_140526a50(); };       // the item event (the item pointer at +0x40)
class Unk_MiProxyObj { public: int FUN_1416c1ff0(); };
class Unk_MiEntityRef
{
public:
    void* FUN_1406c71b0();
    Unk_MiProxyObj* FUN_1406c71d0();
    void FUN_1406c70a0();
};
extern Unk_Inventory DAT_143ab2a90;
extern int DAT_1439f9284;
CString FUN_14021c050(int nType);

// ---- the dialog ----

// @0x141a58040
UIMyInfoDialog::UIMyInfoDialog()
    : m_208(0), m_20c(0), m_210(false), m_250(0), m_254(false), m_258(0), m_270(false), m_274(1000), m_278(false)
{
    m_strGemBag = "MyPcInfoDialog.Gem";
    m_strEquipBag = "MyPcInfoDialog.Equip";
    m_290.SetMode(1);
}

// @0x141a58270
int UIMyInfoDialog::vfunc_il1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x141a582c0
int UIMyInfoDialog::vfunc_oa0_1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x141a58310
// MS2-FUNCTIONAL: delegate temporaries
int UIMyInfoDialog::vfunc_65()
{
    if (UIPCInfoDialog::vfunc_65() == 0)
        return 0;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    m_spInfo.AssignRaw(new PCInfo());
    pPc->vfunc_125(reinterpret_cast<MS2Ptr<Unk_PCArg125>&>(m_spInfo));
    m_spAvatar.AssignRaw(new UIAvatarPC(static_cast<PC*>(pPc), 0));
    m_spAvatar->vfunc_1(static_cast<IUIAvatarEventListener*>(this));
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
        pAvatar->FUN_1418bd1d0()->FUN_1410885b0(true);
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyActiveMyCodiTab"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c1a0));
    return 1;
}

// @0x141a58630
void UIMyInfoDialog::vfunc_67()
{
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_14140ea40()->FUN_1419280e0(static_cast<UIDialogEventListener*>(this));
    FUN_140c607b0()->FUN_141930950(static_cast<UIEntityEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyChangeBuff"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5a640));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyActiveMyCodiTab"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c220));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c220));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyPcBang"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c2a0));
    m_spAvatar = 0;
    m_20c = 0;
    m_208 = 0;
    m_218.FUN_1408687f0();
    m_210 = false;
    m_270 = false;
    m_274 = 0;
    m_268.Init();
    m_278 = false;
    m_250 = 0;
    m_254 = false;
    UIPCInfoDialog::vfunc_67();
}

// @0x141a58b90
void UIMyInfoDialog::vfunc_26()
{
    UIPCInfoDialog::vfunc_26();
    m_258 = 0;
    m_280 = 0;
}

// @0x141a58be0
void UIMyInfoDialog::vfunc_43()
{
    if (s_nUseOpenAnim != 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
            pDialog->vfunc_2(3, 200, 0);
        FUN_141923710(0);
    }
    else
    {
        UIDialog::vfunc_43();
    }
}

// @0x141a58c80
void UIMyInfoDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x141a58ca0
void UIMyInfoDialog::OnLoadComplete()
{
    UIPCInfoDialog::OnLoadComplete();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_14140ea40()->FUN_141928050(static_cast<UIDialogEventListener*>(this));
    FUN_140c607b0()->FUN_1419308c0(static_cast<UIEntityEventListener*>(this));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyChangeBuff"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5a640));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c220));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyPcBang"), Delegate<void(NotifyObject*)>(this, &UIMyInfoDialog::FUN_141a5c2a0));
    FUN_1419260d0("m_webGuideButton", 0);
    do
    {
        m_30->FUN_140bbe640<ASButton>("m_closet", m_280);
        if (m_280 == 0)
            throw new GfxExceptionSwfLoad(FUN_140be2000("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(171), "UIMyInfoDialog::OnLoadComplete"));
    } while (0);
    if (m_280.get() != 0)
    {
        if (FUN_140166410()->FUN_14036d570(0xe3))
        {
            m_280->vfunc_4(true);   // exe: call [rax+0x20] (slot 4, bool), not slot 3
            m_280->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMyInfoDialog::FUN_141a5d690), 0);
        }
        else
        {
            m_280->vfunc_4(false);
        }
    }
}

// @0x141a593c0
int UIMyInfoDialog::vfunc_13()
{
    return UIDialog::vfunc_13();
}

// @0x141a593e0
void UIMyInfoDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() != 0 || FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (m_208 != 0)
    {
        FUN_141a5ab10(1, 0, m_20c);
        m_208 = 0;
        m_20c = 0;
    }
    if (m_218.FUN_140868c00() != 0)
    {
        FUN_141a5ab10(0, 1, 0);
        if (m_210)
        {
            if (m_spAvatar.get() != 0)
            {
                AvatarPC* pAvatar = dynamic_cast<AvatarPC*>(m_spAvatar->vfunc_24());
                if (pAvatar != 0)
                    pAvatar->FUN_1409f64a0();
            }
            m_210 = false;
        }
        m_218.FUN_1408687f0();
    }
    if (m_270 && m_268.Check(m_274) == 1)
        FUN_141a5b6c0();
}

// @0x141a595a0
int UIMyInfoDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIPCInfoDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData kData;
    if (_stricmp("OnChangeProfile", szMethod) == 0)
    {
        OnChangeProfile();
        return 1;
    }
    else if (_stricmp("OnChangeTodayMemo", szMethod) == 0)
    {
        OnChangeTodayMemo();
        return 1;
    }
    else if (_stricmp("OnConfig", szMethod) == 0)
    {
        if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nConfig = kData.FUN_1422b8a10();
            FUN_141a5a9f0(nConfig);
        }
    }
    else if (_stricmp("OnTitleChange", szMethod) == 0)
    {
        if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nTitle = kData.FUN_1422b8b10();
            FUN_141a5a8d0(nTitle);
        }
    }
    else if (_stricmp("onSymbolClick", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4ed5);
    }
    else if (_stricmp("OnScreenshot", szMethod) == 0)
    {
        if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int a = kData.FUN_1422b8a10();
            int b = kData.FUN_1422b8a10();
            int c = kData.FUN_1422b8a10();
            int d = kData.FUN_1422b8a10();
            FUN_141a5aab0(a, b, c, d);
        }
    }
    else if (_stricmp(szMethod, "onWedding") == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4f8c);
    }
    else if (_stricmp("OnAddStatPointRepeat", szMethod) == 0)
    {
        if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nStat = kData.FUN_1422b8a10() - 1;
            FUN_141a5b080(nStat);
        }
    }
    else if (_stricmp(szMethod, "OnAddStatPointStop") == 0)
    {
        if (kData.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nStat = kData.FUN_1422b8a10() - 1;
            FUN_141a5cf30(nStat);
        }
    }
    if ((m_spAvatar.get() != 0 ? true : false) && m_spAvatar->vfunc_27(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// @0x141a599a0
void UIMyInfoDialog::vfunc_oa0_2()
{
    m_254 = false;
    FUN_141a5a560();
}

// @0x141a599d0
void UIMyInfoDialog::vfunc_oa0_3(int a1, int a2)
{
    FUN_141a5a560();
}

// @0x141a59a00
void UIMyInfoDialog::vfunc_oa0_4(int a1, int a2)
{
    FUN_141a5a560();
}

// @0x141a59a30
void UIMyInfoDialog::vfunc_oa0_5(int a1, int a2)
{
    FUN_141a5a560();
}

// @0x141a59a60
void UIMyInfoDialog::vfunc_oa0_6(void* a1, void* a2)
{
    FUN_141a5a560();
}

// @0x141a59aa0
void UIMyInfoDialog::vfunc_oa0_9(unsigned short a1)
{
    FUN_141a5a560();
}

// @0x141a59ad0
void UIMyInfoDialog::vfunc_oa0_10(CStringW s)
{
    FUN_141a5a560();
}

// @0x141a59b20
void UIMyInfoDialog::vfunc_oa0_7(int a1, CStringW s)
{
    FUN_141a5a560();
}

// @0x141a59b70
void UIMyInfoDialog::vfunc_oa0_29()
{
    FUN_141a5a560();
}

// @0x141a59ba0
void UIMyInfoDialog::vfunc_oa0_30(int a1)
{
    FUN_141a5a560();
}

// @0x141a59bd0
void UIMyInfoDialog::vfunc_21(void* p)
{
    FUN_141a5a560();
    m_20c = 1;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0)
    {
        MS2Ptr<CItem> spItem = FUN_140ccac60(*static_cast<MS2Ptr<CItem>*>(p));
        spItem->FUN_140526b30(pAvatar->vfunc_25());
        pAvatar->FUN_1418baf40(spItem.get());
    }
}

// @0x141a59cf0
void UIMyInfoDialog::vfunc_22(void* p)
{
    FUN_141a5a560();
    m_20c = 1;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0)
        pAvatar->FUN_1418bbc70(static_cast<Unk_MiItemEvent*>(p)->FUN_140526a50());
}

// @0x141a59d80
void UIMyInfoDialog::vfunc_il23(void* p)
{
    FUN_141a5a560();
    m_20c = 1;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0)
    {
        PC* pPc = FUN_14099eef0(pAvatar->vfunc_24());
        if (pPc != 0)
        {
            Unk_MiSlotHandle hOne = reinterpret_cast<Unk_MiSlotPc*>(pPc)->FUN_141655e10(4);
            Unk_MiSlotHandle hTwo = reinterpret_cast<Unk_MiSlotPc*>(pPc)->FUN_141655e10(5);
            if (FUN_1405a8e70(&hOne) != 0)
            {
                Unk_MiItemHandle hItem = static_cast<Unk_MiSlotEquip*>(FUN_1405a8ed0(&hOne))->FUN_1411dc7a0();
                if (FUN_14052cd70(&hItem) != 0)
                {
                    FUN_140526c10(FUN_1401c0180(&hItem), 5);
                    pPc->vfunc_127(static_cast<CItem*>(FUN_14052cd70(&hItem)), 0);
                }
            }
            if (FUN_1405a8e70(&hTwo) != 0)
            {
                Unk_MiItemHandle hItem = static_cast<Unk_MiSlotEquip*>(FUN_1405a8ed0(&hTwo))->FUN_1411dc7a0();
                if (FUN_14052cd70(&hItem) != 0)
                {
                    FUN_140526c10(FUN_1401c0180(&hItem), 4);
                    pPc->vfunc_127(static_cast<CItem*>(FUN_14052cd70(&hItem)), 0);
                }
            }
        }
    }
}

// @0x141a59fa0
void UIMyInfoDialog::vfunc_30(void* p)
{
    FUN_141a5a560();
    m_20c = 1;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
        reinterpret_cast<PCGemEquip*>(pAvatar->FUN_1418bd1d0()->FUN_14165f460())->FUN_141270bf0(MS2Ptr<CItem>(*static_cast<MS2Ptr<CItem>*>(p)));
}

// @0x141a5a090
void UIMyInfoDialog::vfunc_31(void* p)
{
    FUN_141a5a560();
    m_20c = 1;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
        reinterpret_cast<PCGemEquip*>(pAvatar->FUN_1418bd1d0()->FUN_14165f460())->FUN_1412709d0(MS2Ptr<CItem>(*static_cast<MS2Ptr<CItem>*>(p)));
}

// @0x141a5a190
void UIMyInfoDialog::vfunc_32(void* p, int a, int b)
{
    FUN_141a5a560();
    m_20c = 1;
}

// @0x141a5a1e0
void UIMyInfoDialog::vfunc_el5(MS2Ptr<CProxyGameObject> spActor, int n)
{
    if ((reinterpret_cast<Unk_MiEntityRef*>(&spActor)->FUN_1406c71b0() ? true : false)
        && reinterpret_cast<Unk_MiEntityRef*>(&spActor)->FUN_1406c71d0()->FUN_1416c1ff0() != 0)
        FUN_141a5a560();
}

// @0x141a5a260
void UIMyInfoDialog::vfunc_33(int nClass, int n)
{
    if (nClass == 0x6200004)
    {
        FUN_141a5a560();
        m_20c = 1;
    }
    else if (nClass == 0x6200044)
    {
        UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
        if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
            pAvatar->FUN_1418bd1d0()->FUN_141087390();
    }
}

// @0x141a5a320
void UIMyInfoDialog::vfunc_dl_3(void* p)
{
    void* pSlot = FUN_140a50b50(p);
    if (pSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(static_cast<InvenSlot*>(pSlot)->GetItemUid());
        if (spItem.get() != 0)
        {
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDialog != 0)
            {
                CString strKind;
                if (reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053c5c0() == 7)
                    strKind = "gem";
                else
                    strKind = FUN_14021c050(reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053eba0()->FUN_14054b400());
                pDialog->Invoke("onDragStart", CString(strKind));
            }
        }
    }
}

// @0x141a5a4e0
void UIMyInfoDialog::vfunc_dl_4(void* p)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("onDragEnd");
}

// @0x141a5a560
void UIMyInfoDialog::FUN_141a5a560()
{
    if (vfunc_55() != 0)
        return;
    m_208 = 1;
    m_218.FUN_140868750(100);
}

// @0x141a5a5c0
void UIMyInfoDialog::FUN_141a5a5c0()
{
    if (vfunc_55() != 0)
        return;
    FUN_141a5a560();
    m_20c = 1;
}

// @0x141a5a610
int UIMyInfoDialog::vfunc_46()
{
    if (UIPCInfoDialog::vfunc_46() == 0)
        return 0;
    return 1;
}

// @0x141a5a640
void UIMyInfoDialog::FUN_141a5a640(NotifyObject* pNotify)
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    NotifyChangeBuff* pBuff = dynamic_cast<NotifyChangeBuff*>(pNotify);
    if (pBuff != 0)
    {
        MS2Ptr<AdditionalCli> spCli = pBuff->m_spCli;
        if ((spCli.get() ? true : false) && spCli->FUN_14096d6b0())
            m_210 = true;
    }
}

// @0x141a5a720
void UIMyInfoDialog::OnChangeProfile()
{
    FUN_14187fb30(FUN_14052d220());
}

// @0x141a5a750
void UIMyInfoDialog::OnChangeTodayMemo()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(5, FUN_1409eec40(0x301), static_cast<IMessageListener*>(this), L"changeTodayMemo");
    if (spBox.get() != 0)
    {
        spBox->FUN_141a01d30(0, *static_cast<Unk_MiPc*>(pPc)->FUN_141656d90(), 0x14, 0, 0);
        FUN_140d73c60(spBox);
    }
}

// @0x141a5a8d0
void UIMyInfoDialog::FUN_141a5a8d0(int nTitle)
{
    if ((m_spInfo == 0))
        return;
    if (nTitle == 0)
    {
        COutPacket pkt(static_cast<int>(SendOp::RequestUserEnv), 0);
        pkt.Encode1(1);
        pkt.Encode4(0);
        FUN_140710590(pkt);
    }
    else
    {
        Unk_MiIdList* pTitles = reinterpret_cast<Unk_MiIdList*>(&m_spInfo->m_aIds);
        if (pTitles->FUN_140408410(nTitle) == -1)
            return;
        COutPacket pkt(static_cast<int>(SendOp::RequestUserEnv), 0);
        pkt.Encode1(1);
        pkt.Encode4(nTitle);
        FUN_140710590(pkt);
    }
}

// @0x141a5a9f0
void UIMyInfoDialog::FUN_141a5a9f0(int nConfig)
{
    if ((m_spInfo == 0))
        return;
    MS2Ptr<CItem> spItem = m_spInfo->FUN_140dba560(nConfig);
    if (spItem == 0)
        return;
    DAT_1439f9284 = spItem->FUN_140526b50();
    FUN_1403ed2b0()->FUN_141adc530(0x4e75);
}

// @0x141a5aab0
void UIMyInfoDialog::FUN_141a5aab0(int a, int b, int c, int d)
{
    m_290.SetImage(a, b, c, d);
    m_290.BeginImage();
}

// @0x141a5ab10
void UIMyInfoDialog::FUN_141a5ab10(int bRefresh, int bStatLists, int bBag)
{
    if ((m_spInfo == 0))
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    m_spInfo.AssignRaw(new PCInfo());
    pPc->vfunc_125(reinterpret_cast<MS2Ptr<Unk_PCArg125>&>(m_spInfo));
    if (bRefresh != 0)
        vfunc_84();
    if (bStatLists != 0)
        vfunc_86();         // exe: call [rax+0x2b0], the stat lists
    if (bBag != 0)
        vfunc_88(m_nTab);   // exe: call [rax+0x2c0], the equip / gem bag
}

// @0x141a5ac90
void UIMyInfoDialog::FUN_141a5ac90(unsigned short nLevel)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    CStringW strName = FUN_1401a9d70()->FUN_141811980(0x27, nLevel);      // string table 0x27: the symbol's name text
    CStringW strIcon = FUN_14131e120()->FUN_1406c61a0(nLevel, pPc);       // ranked icon path
    int bOwned = FUN_14131e120()->FUN_1406c5d60(nLevel) == 0;
    // AS3 setSymbol(name, icon, enabled): the exe passes the name text first (r9) and the icon second
    static_cast<Unk_MiScript*>((AScript*)m_30)->FUN_140ed1090("setSymbol", CStringW(strName), CStringW(strIcon), bOwned);
}

// @0x141a5ae40
void UIMyInfoDialog::vfunc_84()
{
    UIPCInfoDialog::vfunc_84();
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0)
        FUN_141a5ac90(static_cast<Unk_MiPc*>(pPc)->FUN_141661e00());
}

// @0x141a5ae90
void UIMyInfoDialog::vfunc_104(int nTrophy)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    m_30->Invoke("setTrophy", FUN_1406c7600()->FUN_140938ad0()->FUN_140267c10());
}

// @0x141a5af10
void UIMyInfoDialog::vfunc_91(int nStat)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (m_spInfo == 0)
        return;
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (vfunc_93() == 0)
        return;
    ATL::CAtlArray<void*> aStats;
    FUN_1408377d0(&aStats);
    if (nStat < 0 || (int)FUN_1409eecc0(&aStats) <= nStat)
        return;
    int* pStat = FUN_1409eec00(&aStats, nStat);
    static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->RequestAdd(*pStat, 1);
    m_250 = 0;
}

// @0x141a5b080
void UIMyInfoDialog::FUN_141a5b080(int nStat)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (m_spInfo == 0)
        return;
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (vfunc_93() == 0)
        return;
    ATL::CAtlArray<void*> aStats;
    FUN_1408377d0(&aStats);
    if (nStat < 0 || (int)FUN_1409eecc0(&aStats) <= nStat)
        return;
    int nKey = *FUN_1409eec00(&aStats, nStat);
    unsigned nTotal = static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->GetStatPoints(static_cast<CStatPointManager::Unk_StatKey>(nKey)) + m_250;
    unsigned nRemaining = static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->GetRemaining();
    if (nRemaining <= m_250 || FUN_1401d3200()->m_aStatCap[nKey] <= nTotal)
    {
        FUN_141a5cf30(nStat);
        return;
    }
    if (!m_254)
    {
        m_250++;
        FUN_141a5c7c0(nStat);
    }
}

// @0x141a5b2c0
void UIMyInfoDialog::vfunc_92()
{
    if (m_spInfo == 0)
        return;
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (vfunc_93() == 0)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    m_250 = 0;
    m_254 = false;
    static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->RequestReset();
}

// @0x141a5b3b0
void UIMyInfoDialog::vfunc_90(int nTab)
{
    int nOld = m_nTab;
    UIPCInfoDialog::vfunc_90(nTab);
    if (nTab == 3)
    {
        FUN_141a5c410(nOld, nTab);
        FUN_141a5b6c0();
    }
    else if (m_258.get() != 0)
    {
        m_258->FUN_1422c4cd0(L"");
    }
}

// @0x141a5b470
int UIMyInfoDialog::vfunc_93()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    if (pPc->vfunc_65() != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_skillbook_set_disable_battle"), 0, 0, CStringW(L""));
        return 0;
    }
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if (spField->FUN_140375660(0x10) != 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_msg_skillbook_set_disable_field"), 0, 0, CStringW(L""));
        return 0;
    }
    return 1;
}

// @0x141a5b690
void UIMyInfoDialog::vfunc_99(const CStringW& strMemo)
{
    UIPCInfoDialog::vfunc_99(strMemo);
}

// @0x141a5b6c0
void UIMyInfoDialog::FUN_141a5b6c0()
{
    if (FUN_140ba28d0(&m_30, 0) != 0 || m_nTab != 3)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    Unk_MiEquipSet* pEquip = reinterpret_cast<Unk_MiEquipSet*>(pPc->FUN_1416561a0());
    Unk_MiTitlePtr kTitle = pEquip->FUN_140d29440();
    if (FUN_140d28fe0(&kTitle, 0) != 0)
        return;
    int nState = FUN_140d290c0(&kTitle)->FUN_1411df830();
    CStringW strPeriod;
    m_268.Init();
    m_274 = 0;
    m_270 = false;
    switch (nState)
    {
    case 1:
    {
        CMsTime tNow(FUN_140869440());
        CMsTime tEnd(FUN_140d290c0(&kTitle)->m_28);
        if (tNow < tEnd)
        {
            CStringW strRemain;
            CTimeSpan kSpan = tEnd - tNow;
            int nDays = (int)kSpan.GetDays();
            int nHours = kSpan.GetHours();
            int nMinutes = FUN_14086d270(&kSpan);
            int nSeconds = kSpan.GetSeconds();
            if (nDays > 0)
            {
                strRemain = FUN_14062b4f0(CStringW(L"s_item_word_d"), &nDays);
                if (nHours == 0 && nMinutes == 0)
                    m_274 = FUN_14028d260((float)nSeconds);
                else
                    m_274 = nHours > 0 ? FUN_14028d260((float)FUN_140869490(nHours)) : FUN_14028d260((float)FUN_1408694b0(nMinutes));
            }
            else if (nHours > 0)
            {
                strRemain = FUN_14062b4f0(CStringW(L"s_item_word_h"), &nHours);
                m_274 = nMinutes > 0 ? FUN_14028d260((float)FUN_1408694b0(nMinutes)) : FUN_14028d260((float)nSeconds);
            }
            else if (nMinutes > 0)
            {
                strRemain = FUN_14062b4f0(CStringW(L"s_item_word_m"), &nMinutes);
                m_274 = FUN_14028d260((float)nSeconds);
            }
            else
            {
                strRemain = GetStringCommonByKey(L"s_item_word_s_shortly");
                m_274 = FUN_14028d260((float)nSeconds);
            }
            strPeriod = FUN_1405c2690(CStringW(L"s_char_info_codi_tab_period_fmt"), strRemain);
            if (m_274 == 0)
                m_274 = 1000;
        }
        break;
    }
    case 3:
        strPeriod = GetStringCommonByKey(L"s_char_info_codi_tab_expired");
        break;
    }
    if (m_30.get() != 0)
    {
        if (m_258 == 0)
        {
            if (MS2Ptr<ASMovieClip> spEquip = m_30->FUN_1409b4560("m_equip"))
                m_258 = spEquip->FUN_1409b4620("m_period");
        }
        if (m_258.get() != 0)
            m_258->FUN_1422c4f00(strPeriod);
    }
    m_270 = (unsigned int)m_274 > 0;
}

// @0x141a5bed0
void UIMyInfoDialog::FUN_141a5bed0()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    Unk_MiEquipSet* pEquip = reinterpret_cast<Unk_MiEquipSet*>(pPc->FUN_1416561a0());
    Unk_MiTitlePtr kTitle = pEquip->FUN_140d29440();
    if (FUN_140d28fe0(&kTitle, 0) != 0)
        return;
    if (FUN_140d290c0(&kTitle)->FUN_1411df810() != m_278)
    {
        UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
        if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
            pAvatar->FUN_1418bd1d0()->FUN_1410873b0();
        m_278 = FUN_140d290c0(&kTitle)->FUN_1411df810();
        if ((m_30.get() ? true : false) && m_nTab == 3)
        {
            void* pBag = FUN_140c544d0(FUN_1422c8e90(m_strEquipBag));
            if (pBag != 0)
                FUN_1422cca90(pBag);
        }
    }
}

// @0x141a5c080
void UIMyInfoDialog::FUN_141a5c080()
{
    if (FUN_140ba28d0(&m_30, 0) != 0 || (m_spAvatar == 0))
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>(m_spAvatar.get());
    if (pAvatar != 0 && pAvatar->FUN_1418bd1d0() != 0)
    {
        Unk_MiTitlePtr kTitle = reinterpret_cast<Unk_MiEquipSet*>(pPc->FUN_1416561a0())->FUN_140d29440();
        if (FUN_1411f7e30(&kTitle) != 0)
            m_278 = FUN_140d290c0(&kTitle)->FUN_1411df810();
    }
}

// @0x141a5c1a0
void UIMyInfoDialog::FUN_141a5c1a0(NotifyObject* pNotify)
{
    if (m_spAvatar == 0 || m_spAvatar->vfunc_24() == 0)
        return;
    FUN_141a5b6c0();
}

// @0x141a5c220
void UIMyInfoDialog::FUN_141a5c220(NotifyObject* pNotify)
{
    if (m_spAvatar == 0 || m_spAvatar->vfunc_24() == 0)
        return;
    FUN_141a5bed0();
}

// @0x141a5c2a0
void UIMyInfoDialog::FUN_141a5c2a0(NotifyObject* pNotify)
{
    if (m_spAvatar == 0 || m_spAvatar->vfunc_24() == 0)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    AvatarPC* pAvatar = dynamic_cast<AvatarPC*>(m_spAvatar->vfunc_24());
    if (pAvatar != 0)
        pAvatar->FUN_141658ed0(static_cast<Unk_MiPc*>(pPc)->FUN_141658f10());
}

// @0x141a5c3a0
bool UIMyInfoDialog::FUN_141a5c3a0()
{
    if (vfunc_55() != 0)
        return false;
    return m_278 == true && m_nTab == 3;
}

// @0x141a5c410
void UIMyInfoDialog::FUN_141a5c410(int nTab, int nNewTab)
{
    if (nNewTab != 3)
        return;
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    Unk_MiEquipSet* pEquip = reinterpret_cast<Unk_MiEquipSet*>(pPc->FUN_1416561a0());
    Unk_MiTitlePtr kTitle = pEquip->FUN_140d29440();
    if (FUN_140d28fe0(&kTitle, 0) != 0)
        return;
    int nState = FUN_140d290c0(&kTitle)->FUN_1411df830();
    if (nState == 0 || nState == 4)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommonByKey(L"s_char_info_changetab_not_active_codi_tab"), 0);
        if (spBox.get() != 0)
        {
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMyInfoDialog::FUN_141a5c640));
            spBox->FUN_140533ff0(nTab);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x141a5c640
bool UIMyInfoDialog::FUN_141a5c640(int nButton, const CMsgBoxData& kData)
{
    if (nButton == 0)
    {
        int nTab = kData.FUN_141a02e50(0, m_nTab);
        if ((m_30.get() ? true : false) && nTab != m_nTab && (m_spInfo.get() ? true : false) && m_spInfo->m_mapEquip2.IsEmpty() == true)
        {
            MS2Ptr<ASMovieClip> spTab = m_30->FUN_140be23c0<ASMovieClip>("m_tab");
            if (spTab.get() != 0)
                reinterpret_cast<Unk_MiTabClip*>(spTab.operator->())->FUN_1422e31e0(nTab);
        }
    }
    return true;
}

// @0x141a5c7a0
int UIMyInfoDialog::GetTab()
{
    return m_nTab;
}

// @0x141a5c7c0
void UIMyInfoDialog::FUN_141a5c7c0(int nStat)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (m_spInfo == 0)
        return;
    if (m_spInfo->FUN_140dba1c0() == 0)
        return;
    ATL::CAtlArray<int> aStats;
    FUN_1408377d0(aStats);
    unsigned nRemain = 0;
    unsigned nUsed = 0;
    nRemain = static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->GetRemaining();
    nUsed = static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->GetUsed();
    nRemain -= m_250;
    nUsed += m_250;
    CString strRow = StringFormat("m_statPoint{0}", nStat + 1);
    {
        MS2Ptr<ASMovieClip> spRow = FUN_140ba7930(strRow);
        if (spRow)
        {
            int nKey = aStats[nStat];
            __int64 nValue = 0;
            if (nKey == 4)
                nValue = m_spInfo->m_aStats0[nKey];
            else
                nValue = m_spInfo->m_aStats2[nKey];
            nValue += FUN_140837770(nKey, m_250);
            CStringW strValue = StringFormat(L"{0}", nValue);
            FUN_140cfee80((*spRow).FUN_1422bb890(), "m_point", strValue);
            unsigned nColor = 0xffffff;
            unsigned nSpent = static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->GetStatPoints(static_cast<CStatPointManager::Unk_StatKey>(nKey));
            if (nSpent > 0 || (unsigned)m_250 > 0)
                nColor = 0xffa200;
            FUN_140cff740((*spRow).FUN_1422bb890(), "m_point", nColor);
            if (MS2Ptr<ASButton> spPlus = spRow->FUN_140acce30<ASButton>("m_plus"))
            {
                if (nRemain == 0 || FUN_1401d3200()->m_aStatCap[nKey] <= nSpent + m_250)
                    spPlus->FUN_1422c1fe0(0);
            }
        }
    }
    if (MS2Ptr<ASButton> spReset = FUN_140bb4b10("m_resetStatPoint"))
        spReset->FUN_1422c1fe0(nUsed > 0 ? 1 : 0);
    if (MS2Ptr<ASMovieClip> spRemain = FUN_140ba7930("m_remainPoint"))
    {
        if (MS2Ptr<ASTextField> spText = spRemain->FUN_1409b4620("m_remainStatPoint"))
        {
            CStringW strRemain = StringFormat(L"{0}", nRemain);
            spText->FUN_1422c4cd0(strRemain);
            unsigned nColor2 = 0xffffff;
            if (nRemain > 0)
                nColor2 = 0xffa200;
            spText->FUN_1422c50e0(nColor2);
        }
    }
}

// @0x141a5cf30
void UIMyInfoDialog::FUN_141a5cf30(int nStat)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if ((unsigned)m_250 <= 0)
        return;
    ATL::CAtlArray<void*> aStats;
    FUN_1408377d0(&aStats);
    if (FUN_1409eecc0(&aStats) < (unsigned __int64)nStat)
        return;
    int* pStat = FUN_1409eec00(&aStats, nStat);
    static_cast<Unk_MiPc*>(pPc)->FUN_140c25130()->RequestAdd(*pStat, m_250);
    m_250 = 0;
    m_254 = true;
}

// @0x141a5d060
void UIMyInfoDialog::vfunc_87()
{
    if (m_254 == true)
        return;
    UIPCInfoDialog::vfunc_87();
}

// @0x141a5d0c0
// MS2-FUNCTIONAL: vector temporaries
void UIMyInfoDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (vfunc_55() != 0 || FUN_140ba28d0(&m_30, 0) != 0 || (m_spAvatar == 0))
        return;
    if (p2.get() != 0 && p3 != 0)
    {
        GameObject* pObj = m_spAvatar->vfunc_24();
        if (pObj == 0)
            return;
        m_spAvatar->vfunc_28(p1, p2, p3, p4);
        Unk_ModelViewCamera kCamera;
        kCamera.FUN_141b48530();
        kCamera.m_fMinDistance = 300.0f;
        kCamera.m_fMaxDistance = 150.0f;
        kCamera.m_kTarget += pObj->vfunc_18() + NiPoint3(0.0f, 0.0f, -5.0f);
        kCamera.m_kPosition += kCamera.m_kTarget + NiPoint3(-30.0f, 0.0f, 0.0f);
        kCamera.m_nSteps = 5;
        m_spAvatar->GetView()->vfunc_13(kCamera);
    }
}

// @0x141a5d3e0
void UIMyInfoDialog::vfunc_16()
{
    UIPCInfoDialog::vfunc_16();
    FUN_141a5d630();
}

// @0x141a5d410
bool UIMyInfoDialog::vfunc_17()
{
    if (!UIPCInfoDialog::vfunc_17())
        return false;
    FUN_141a5d5d0();
    return true;
}

// @0x141a5d450
int UIMyInfoDialog::vfunc_o178_1(void* pAvatar)
{
    if (pAvatar == 0)
        return 0;
    FUN_141a5d5d0();
    ASObj kObj(2);
    AvatarPC* pAv = FUN_140a535c0(static_cast<UIAvatarBase*>(pAvatar)->vfunc_24());
    if (pAv != 0)
    {
        if (pAv->GetType() == 1)
            FUN_1418bee30(&kObj, 10000);
        FUN_1407cbbe0(&kObj, "showActionList", true);
    }
    if (m_30.get() != 0)
        m_30->Invoke("initData", kObj.FUN_1422bb870());
    FUN_141a5c080();
    return 1;
}

// @0x141a5d5d0
void UIMyInfoDialog::FUN_141a5d5d0()
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    m_30->Invoke("loadRenderTarget");
}

// @0x141a5d630
void UIMyInfoDialog::FUN_141a5d630()
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    m_30->Invoke("unloadRenderTarget");
}

// @0x141a5d690
void UIMyInfoDialog::FUN_141a5d690(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_140ba28d0(&m_30, 0) != 0 || m_280 == 0)
        return;
    FUN_1403ed2b0()->FUN_141adc750(0x4f76);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc0dc0-0x142cc0e50 .text$yd
