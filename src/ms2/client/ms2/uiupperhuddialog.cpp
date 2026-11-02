// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiupperhuddialog.cpp (.text$mn
// 0x141353540-0x14135fc40, .text$di 0x1400f1000-0x1400f1760, .text$yd 0x142cb0a10-0x142cb0cf5).
//
// UIUpperHudDialog: the upper HUD (token pocket, maid status, PC bang, keyboard / mouse / game pad mode, search box,
// clock, notice ticker). The unit also holds four small UI classes that follow it in the file: UIVisitorsBookDialog,
// UIVisualEffectDialog, UIWeaponDummyDialog and UIWebBrowserBase.
// MS2-UNIT: client\ms2\uiupperhuddialog.cpp
// MS2-RANGE: 0x1400f1000-0x1400f1760 .text$di
// MS2-RANGE: 0x142cb0a10-0x142cb0cf5 .text$yd
// MS2-RANGE: 0x141353540-0x14135fc40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VUIUpperHudDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIUpperHudDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x1413597b0 ; unique
// MS2-PIN: ??$?8PEAVUIUpperHudDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141359910 ; prop
// MS2-PIN: ??$?8PEAVUIUpperHudDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141359980 ; prop
// MS2-PIN: ??$?8PEAVUIUpperHudDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1413599f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x14135a010 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x14135a150 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a690 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a6f0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a750 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x14135a7b0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14135a7e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x14135a810 ; unique
// MS2-PIN: ??$Call@VUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x14135a840 ; prop
// MS2-PIN: ??$Call@VUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14135a880 ; prop
// MS2-PIN: ??$Call@VUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x14135a8c0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14135a900 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14135a960 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14135a9c0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_ASVideoPlayer@@@@QEBAPEAVUnk_ASVideoPlayer@@XZ 0x14135b3d0 ; prop
// MS2-PIN: ??_EUIVisitorsBookDialog@@WBHI@EAAPEAXI@Z 0x14135bbb8 ; unique
// MS2-PIN: ??_GUIVisitorsBookDialog@@UEAAPEAXI@Z 0x14135bbd0 ; prop
// MS2-PIN: ??_GUIVisualEffectDialog@@UEAAPEAXI@Z 0x14135dda0 ; unique
// MS2-PIN: ??_GUIWeaponDummyDialog@@UEAAPEAXI@Z 0x14135ea70 ; unique
// MS2-PIN: ??_EUIWebBrowserBase@@WBHI@EAAPEAXI@Z 0x14135fad0 ; unique
// MS2-PIN: ??_GUIWebBrowserBase@@UEAAPEAXI@Z 0x14135fae0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIVisitorsBookDialog@@UEAA@XZ 0x14135bba0
// MS2-PIN: ?get@?$MS2Ptr@VUnk_ASVideoPlayer@@@@QEBAPEAVUnk_ASVideoPlayer@@XZ 0x14135b3c0
// MS2-PIN: ?GetData@NiGlobalConstantEntry@@QEBAXAEAIAEAPEBX@Z 0x14135de60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiupperhuddialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiupperhuddialog.h"
#include "ms2/placeholder/uivideocontents.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include <NiFixedString.h>
#include <NiPoint2.h>
#include <NiShaderFactory.h>
#include <NiGlobalConstantEntry.h>
#include <NiNode.h>
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asslider.h"   // C3: ASSlider (was Unk_HudSlider members)
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/weaponattachtransformnode.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/unnamed/unit_140ad1860.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/commonfiles/maidgradejockpottable.h"
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include <atlcoll.h>
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/placeholder/packethandlermanager.h"  // C3: PacketHandlerManager::RegisterHandler/UnregisterHandler
#include "ms2/placeholder/cinputkeyhandler.h"  // C3: CInputKeyHandler::FUN_14116d9c0
#include "ms2/placeholder/asbutton.h"  // C3: AScript::FUN_140bbe640<ASButton>
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef
#include "ms2/placeholder/astextinput.h"  // C3: ASTextInput::FUN_1422e0ab0

class PCBase;
class UIPcBangDialog;

// ---- statics (the exe runs them in this order; the header-local objects come twice, with the key input, the
// string constants and the handle in between) ----

class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100

static CString s_sort8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400f1000
static CString s_sort7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                      // @0x1400f10d0
static CString s_skill = "skill";                                                                   // @0x1400f1190
static CString s_stun = "stun";                                                                     // @0x1400f11c0
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);                                      // @0x1400f11f0
static UICommon::CMyPCKeyInputController s_keyInput;                                                // @0x1400f1240
static CString s_jobCode = "jobCode";                                                               // @0x1400f1270
static CString s_sortValue = "sortValue";                                                           // @0x1400f12a0
static CString s_tabIndex = "tabIndex";                                                             // @0x1400f12d0
static CString s_maidFinish = "maid_Finish";                                                        // @0x1400f1300
static Unk_Handle1401cd100 s_handle(0);                                                             // @0x1400f1330
static CString s_skill2 = "skill";                                                                  // @0x1400f1350
static CString s_stun2 = "stun";                                                                    // @0x1400f1380
static CString s_sort7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                    // @0x1400f13b0
static CString s_skill3 = "skill";                                                                  // @0x1400f1470
static CString s_stun3 = "stun";                                                                    // @0x1400f14a0
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);                                     // @0x1400f14d0
static CString s_sort8b[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"}; // @0x1400f1520
static CString s_sort7c[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};                    // @0x1400f15f0
static CString s_skill4 = "skill";                                                                  // @0x1400f16b0
static CString s_stun4 = "stun";                                                                    // @0x1400f16e0
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);                                     // @0x1400f1710

// ---- unit-local views of exe objects (names assumed; layouts only as far as this unit reads them) ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> HudClickDelegate;

class Unk_HudButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const HudClickDelegate& onClick, int nFlags);            // click callback
    void FUN_1422c1fe0(int bOn);                                               // toggled state
};

class Unk_HudInput : public ASDisplayObject
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool bFocus);                                          // 24 set the focus
};

class Unk_HudText : public ASTextField
{
public:
};

class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

class Unk_HudUIMgr
{
public:
    float FUN_141adbe70();                                                      // the ui scale
};

class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
class Unk_HudPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);
};
class Unk_140bccd50* FUN_140bccd50();   // C3: was FUN_140bccd50

// The notice payloads (NotifyObject is 0x18 bytes).
class Unk_HudNotifyFlag : public NotifyObject { public: unsigned char m_bFlag; };                       // +0x18 keyboard / mouse
class Unk_HudNotifyMoney : public NotifyObject { public: char m_pad_18[0x10]; __int64 m_nAmount; };   // +0x28 token money

// The local player and the game event manager.
class Unk_HudEnvPtr;
class Unk_HudPlayerMgr { public: PCBase* FUN_141bd0cc0(); Unk_HudEnvPtr FUN_141bd30a0(); };
int FUN_141658f30(PCBase* pPc);                                                 // pc level
class Unk_HudEventMgr : public CGameRule {};
void* FUN_1401c0d90();   // C3: was FUN_1401c0d90


// The maids.
class Unk_HudMaidRec : public CPtred
{
public:
    char m_pad_18[8];
    __int64 m_20;                                                               // +0x20 key
    char m_pad_28[0x24];
    int m_4c;                                                                   // +0x4c state
};
class Unk_HudMaidList
{
public:
    void* FUN_1412dd700();                                                      // head position
    MS2Ptr<Unk_HudMaidRec>& FUN_1412dd780(void* pos);
    void FUN_1412dd720(void*& pos);                                             // next
};
class Unk_HudMaidOwner;
int FUN_141276180(const CString& strSound, const CString& strArg);

// Misc.
class GFxManager { public: CStringW Localize(const CString& strKey); float FUN_1422afec0(int nMovieId); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_HudKeys : public CInputKeyHandler   // FUN_14116d9c0 (key pressed) from the base
{
public:
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
                         // game time in seconds
class Unk_HudRenderOpt;
class Unk_HudSound;
class Unk_AeGameOption { public: class Unk_AeGraphicOption* FUN_1409a8ac0(); };   // C3: unit-local view (def in applyeffect)
class Unk_HudConfig { public: unsigned char* FUN_140a58500(); Unk_HudSound* FUN_140d13c70(); };
void FUN_14125f670(struct Unk_GpState*, bool, bool);   // C3: was FUN_14125f670
                           // controller on
__int64 GetServerTime();                                                        // the server time
void FUN_140710590(COutPacket& packet);

CStringW GetStringCommonByKey(const CStringW& strKey);                                 // string table text
CStringW GetStringCommon(int nId);                                                // string table text by id
CStringW FUN_14083bdc0(const CMsTime& t, bool n, CStringW strSep, CStringW strSep2);
CStringW FUN_140f48210(int nHour, int nMinute);                                 // the clock text
CStringW FUN_1409404f0(__int64 n);                                              // the number as text
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                         // has the AS object been released
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);                         // narrows a string
CString FUN_14016a5c0(const char* psz, int nCodePage);
CStringW FUN_141900120(int nCurrency, bool bIcon, bool bNewline);

std::vector<__int64>* FUN_140930580();                                          // the merat amounts by kind
bool FUN_140930200(unsigned int nIndex);
CStringW FUN_1418fe590();
CStringW FUN_1418fe5d0(unsigned int nIndex);
__int64 FUN_140930250();
__int64 FUN_140930240();
__int64 FUN_140930ae0();
bool FUN_1406a5720();
bool FUN_1406a5930();

void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int bOn);
void FUN_140cffef0(const Scaleform::GFx::Value& root, CString strName, CString strFrame);
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strFrame);

extern __int64 DAT_143ab2898;                                                   // the meso the player carries

// ---- the dialog ----

// @0x141353540
UIUpperHudDialog::UIUpperHudDialog()
    : m_nHour(0), m_nMinute(0), m_nMaidReady(0), m_tokenPocket(0), m_maidStatus(0), m_pcBang(0), m_fishingBook(0),
      m_keyboardGuide(0), m_keyboardMode(0), m_mouseMode(0), m_gamePadOn(0), m_gamePadOff(0), m_search(0),
      m_searchInput(0), m_nHotTime(0)
{
    m_bNoticeOnce = false;
    m_fNoticeSpeed = 50.0f;
    m_fNoticePos = 0.0f;
    m_nNoticeY = 0;
    m_nNoticeWidth = 0;
    FUN_1422dc3b0(1);
    m_2c = 0xb;
    ((class PacketHandlerManager*)FUN_140bccd50())->RegisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIUpperHudDialog::FUN_141357ac0));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357300));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357330));
}

// @0x141353a70
UIUpperHudDialog::~UIUpperHudDialog()
{
    ((class PacketHandlerManager*)FUN_140bccd50())->UnregisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIUpperHudDialog::FUN_141357ac0));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357300));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357330));
}

// @0x141353e80
CString UIUpperHudDialog::GetTypeName()
{
    return "UpperHudDialog";
}
MS2_REPLACE_METHOD(0x141353E80, UIUpperHudDialog, GetTypeName, 61, 0xF83C7D54);

// @0x141353ed0
void UIUpperHudDialog::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140b632f0()->AddToLayer(this, 4);
    do { m_30->FUN_140bc71c0("m_searchDungeon", m_searchDungeon); if (m_searchDungeon == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(85), __FUNCTION__)); } while (0);
    do { m_30->FUN_140bc71c0("m_eventText", m_eventText); if (m_eventText == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(86), __FUNCTION__)); } while (0);
    if (m_eventText->FUN_140beaf20("textField", m_noticeText) == 0)
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(89), __FUNCTION__));
    m_nNoticeY = (int)m_noticeText->FUN_1422c1110();
    m_eventText->FUN_1422c2a70(HudClickDelegate(this, &UIUpperHudDialog::OpenEventBrowser), (void*)0);
    if (FUN_140bc6d10("m_tokenPocketButton", m_tokenPocket))
        m_tokenPocket->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356cd0), 0);
    if (FUN_140bc6d10("m_maidStatusButton", m_maidStatus))
        m_maidStatus->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356d00), 0);
    do { m_30->FUN_140bbe640<ASButton>("m_pcBangButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_pcBang)); if (m_pcBang == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(101), __FUNCTION__)); } while (0);
    do { m_30->FUN_140bbe640<ASButton>("m_pcBangButtonCn1", reinterpret_cast<MS2Ptr<ASButton>&>(m_pcBangCn1)); if (m_pcBangCn1 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(102), __FUNCTION__)); } while (0);
    do { m_30->FUN_140bbe640<ASButton>("m_pcBangButtonCn2", reinterpret_cast<MS2Ptr<ASButton>&>(m_pcBangCn2)); if (m_pcBangCn2 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(103), __FUNCTION__)); } while (0);
    m_pcBang->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::SendPcBangBonus), 0);
    m_pcBangCn1->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::SendPcBangBonus), 0);
    m_pcBangCn2->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::SendPcBangBonus), 0);
    if (FUN_140bc6d10("m_fishingBookButton", m_fishingBook))
        m_fishingBook->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356dc0), 0);
    if (FUN_140bc6d10("m_keyboardGuideButton", m_keyboardGuide))
        m_keyboardGuide->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356df0), 0);
    if (FUN_140bc6d10("m_searchButton", m_search))
    {
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x2f) == true)
            m_search->Invoke("changeTooltipText", reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_gamedictionary_tooltip_search"));
        m_search->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356f90), 0);
    }
    if (FUN_14129a040("m_searchInput", m_searchInput))
    {
        reinterpret_cast<ASInteractiveObject*>(m_searchInput.get())->FUN_1422de780(HudClickDelegate(this, &UIUpperHudDialog::FUN_141357050), 0, 0);
        m_searchInput->vfunc_3(0);
    }
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xaf) == true)
    {
        if (FUN_140bc6d10("m_keyboardMode", m_keyboardMode))
        {
            m_keyboardMode->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e20), 0);
            m_keyboardMode->vfunc_4(TSingleton<CMouseController>::GetInstance()->HasMode() == 0);
        }
        if (FUN_140bc6d10("m_mouseMode", m_mouseMode))
        {
            m_mouseMode->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e20), 0);
            m_mouseMode->vfunc_3(TSingleton<CMouseController>::GetInstance()->HasMode());
        }
    }
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb5) == true)
    {
        if (FUN_140bc6d10("m_gamePadOn", m_gamePadOn))
            m_gamePadOn->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::OnGamePadOnClick), 0);
        if (FUN_140bc6d10("m_gamePadOff", m_gamePadOff))
            m_gamePadOff->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::OnGamePadOffClick), 0);
        SetGamePadMode(*reinterpret_cast<Unk_HudConfig*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500());
    }
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xc9) == true)
    {
        MS2Ptr<ASTextField> spVersion = GetChild<ASTextField>("m_version");
        if (spVersion)
        {
            spVersion->vfunc_4(true);
            CStringW strVersion = GetStringCommonByKey(L"s_upper_hud_version");
            spVersion->SetTextHTMLW(strVersion);
        }
    }
    {
        MS2Ptr<ASTextField> spVersion = GetChild<ASTextField>("m_version");
        if (spVersion)
        {
            spVersion->vfunc_4(true);
            spVersion->SetMultiline(1);
        }
    }
    FUN_140cff840((*m_maidStatus).FUN_1422bb890(), "badge", 0);
    FUN_140cfee80(FUN_1422dbc00(), "mesoText", FUN_1409404f0(DAT_143ab2898));
    FUN_140cfee80(FUN_1422dbc00(), "maratText", FUN_1409404f0(FUN_140930240()));
    FUN_141358020(1);
    ShowPendingNotice();
    ResetClock();
    RefreshPcBang();
    UpdateSearchDungeon();
    FUN_141358490();
    m_30->Invoke("arrangePos");
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyPcBang", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::OnPcBangNotify));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::OnTokenMoneyChanged));
    FUN_141357d90(1);
}

class UIPcBangDialog : public UIDialog
{
public:
    int GetPcBangGrade();
    int GetReceivableCount();
};
class UIWebBrowser* FUN_140c43790(int);   // C3: was FUN_140c43790
UIPcBangDialog* FUN_141359de0(int nUiId);

// @0x1413561c0
void UIUpperHudDialog::vfunc_26()
{
    UIObject::vfunc_26();
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::OnTokenMoneyChanged));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyPcBang", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::OnPcBangNotify));
    FUN_140b632f0()->RemoveFromLayer(this, 4);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    m_tokenPocket = 0;
    m_maidStatus = 0;
    m_pcBang = 0;
    m_pcBangCn1 = 0;
    m_pcBangCn2 = 0;
    m_fishingBook = 0;
    m_keyboardGuide = 0;
    m_keyboardMode = 0;
    m_mouseMode = 0;
    m_gamePadOn = 0;
    m_gamePadOff = 0;
    m_search = 0;
    m_searchInput = 0;
    m_searchDungeon = 0;
    m_nMaidReady = 0;
    m_nHotTime = 0;
    m_eventText = 0;
    m_noticeText = 0;
}
MS2_REPLACE_METHOD(0x1413561C0, UIUpperHudDialog, vfunc_26, 949, 0x89EDECA7);

// @0x141356580
void UIUpperHudDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
}
MS2_REPLACE_METHOD(0x141356580, UIUpperHudDialog, vfunc_45, 54, 0x9E4ACA8C);

// @0x1413565c0
void UIUpperHudDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CString strName = pArgs->FUN_1422b8d30();
    if ((strName == "m_tokenPocketButton"))
        FUN_1413586c0(pRetVal);
    else if ((strName == "m_effectHotTime"))
        FUN_141358b20(pRetVal);
    else if ((strName == "m_marat"))
        FUN_141358df0(pRetVal);
}
MS2_REPLACE_METHOD(0x1413565C0, UIUpperHudDialog, vfunc_49, 182, 0xDF2014D0);

// @0x141356680
int UIUpperHudDialog::vfunc_13()
{
    if (UISwfEntity::vfunc_13() != 0)
        return 1;
    if (reinterpret_cast<ASUIComponent*>(m_searchInput.get())->GetFocused() != 0)
    {
        if (((class Unk_HudKeys*)FUN_14025e7c0())->FUN_14116d9c0(0x1c, 0, 0))
        {
            CStringW strText = reinterpret_cast<ASTextInput*>(m_searchInput.get())->GetText();
            if (!strText.IsEmpty())
                CUserCommandCli::GetInstance()->Execute(StringFormat<CStringW>(L"/search {0}", strText));
            reinterpret_cast<ASUIComponent*>(m_searchInput.get())->SetFocused(0);
            return 1;
        }
        else if (((class Unk_HudKeys*)FUN_14025e7c0())->FUN_14116d840())
        {
            reinterpret_cast<ASUIComponent*>(m_searchInput.get())->SetFocused(0);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141356680, UIUpperHudDialog, vfunc_13, 346, 0x1DB0987E);

// @0x1413567f0
void UIUpperHudDialog::vfunc_15()
{
    if (reinterpret_cast<Unk_IntervalTimer&>(m_timer).Check(1000))
    {
        FUN_141357b30();
        FUN_141357d90(0);
        FUN_141358020(0);
    }
    FUN_1413581f0();
}
MS2_REPLACE_METHOD(0x1413567F0, UIUpperHudDialog, vfunc_15, 86, 0xAEFD3A19);

// @0x141356850
void UIUpperHudDialog::vfunc_oa0_11(void* a1)
{
    if (m_30 == 0)
        return;
    FUN_140cfee80(FUN_1422dbc00(), "mesoText", FUN_1409404f0(reinterpret_cast<__int64>(a1)));
    m_30->Invoke("arrangePos");
}

// @0x141356950
void UIUpperHudDialog::vfunc_oa0_14(void* a1, int a2)
{
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x3d))
        return;
    if (FUN_140ba28d0(&m_30, 0))
        return;
    FUN_140cfee80(FUN_1422dbc00(), "maratText", FUN_1409404f0(reinterpret_cast<__int64>(a1)));
    m_30->Invoke("arrangePos");
    if (a2 > 0)
    {
        FUN_140cff840(FUN_1422dbc00(), "m_effectMerat", 1);
        FUN_140cffef0(FUN_1422dbc00(), "m_effectMerat", "1");
    }
}

// @0x141356b80
int UIUpperHudDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30 == 0)
        return 0;
    if (MS2Ptr<ASMovieClip> spMarat = m_30->FUN_140acce30<ASMovieClip>("m_marat"))
    {
        if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x3d))
            spMarat->vfunc_4(false);
    }
    m_30->Invoke("arrangePos");
    return 1;
}
MS2_REPLACE_METHOD(0x141356B80, UIUpperHudDialog, vfunc_46, 321, 0xF0950323);

// @0x141356cd0
void UIUpperHudDialog::FUN_141356cd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4ece)));
}

// @0x141356d00
void UIUpperHudDialog::FUN_141356d00(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4ec9)));
}

// @0x141356d30
void UIUpperHudDialog::SendPcBangBonus(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (TSingleton<CUIService>::GetInstance()->FUN_141adc890((eUIClassID)0x4ecf))
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ecf);
    }
    else
    {
        COutPacket packet(static_cast<int>(SendOp::PcBangBonus), 0);
        packet.Encode1(0);
        packet.Encode1(1);
        FUN_140710590(packet);
    }
}

// @0x141356dc0
void UIUpperHudDialog::FUN_141356dc0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4ee6)));
}

// @0x141356df0
void UIUpperHudDialog::FUN_141356df0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f0f)));
}

// @0x141356e20
void UIUpperHudDialog::FUN_141356e20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f65)));
}

// @0x141356e50
void UIUpperHudDialog::OnGamePadOnClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_14125f670((struct Unk_GpState*)(reinterpret_cast<Unk_HudConfig*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()), false, false);
}

// @0x141356e90
void UIUpperHudDialog::OnGamePadOffClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_14125f670((struct Unk_GpState*)(reinterpret_cast<Unk_HudConfig*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()), true, true);
}

// @0x141356ed0
void UIUpperHudDialog::OpenEventBrowser(const Scaleform::GFx::FunctionHandler::Params& params)
{
    CStringW strUrl = ((class Unk_HudEventMgr*)FUN_1401c0d90())->FUN_14047db50();
    if (strUrl.IsEmpty())
        return;
    UIWebBrowserBase* pBrowser = ((class UIWebBrowserBase*)FUN_140c43790(0x4e6a));
    if (pBrowser != 0)
        pBrowser->FUN_14135ec00(FUN_1401d4330(strUrl, 0), true);
}

// @0x141356f90
void UIUpperHudDialog::FUN_141356f90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x2f) == true)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f0b)));
    else
    {
        reinterpret_cast<ASUIComponent*>(m_searchInput.get())->SetFocused(1);
        m_searchInput->vfunc_3(1);
        m_search->FUN_1422c1fe0(false);
    }
}

// @0x141357050
void UIUpperHudDialog::FUN_141357050(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_searchInput->GetVisible())
    {
        if (reinterpret_cast<ASUIComponent*>(m_searchInput.get())->GetFocused() == 0)
        {
            m_searchInput->vfunc_3(0);
            reinterpret_cast<ASTextInput*>(m_searchInput.operator->())->SetTextW(L"");
            m_searchInput->vfunc_24(1);
            m_search->FUN_1422c1fe0(true);
        }
    }
}

// @0x141357180
void UIUpperHudDialog::OnPcBangNotify(NotifyObject* pObj)
{
    if (m_30 == 0)
        return;
    RefreshPcBang();
    m_30->Invoke("arrangePos");
}

// @0x1413571f0
void UIUpperHudDialog::OnTokenMoneyChanged(NotifyObject* pObj)
{
    Unk_HudNotifyMoney* pMoney = static_cast<Unk_HudNotifyMoney*>(pObj);
    if (pMoney->m_nAmount > 0)
    {
        FUN_140cff840(FUN_1422dbc00(), "m_effectTokenPocket", 1);
        FUN_140cffef0(FUN_1422dbc00(), "m_effectTokenPocket", "1");
    }
}

// @0x141357300
void UIUpperHudDialog::FUN_141357300(NotifyObject* pObj)
{
    ShowPendingNotice();
}

// @0x141357330
void UIUpperHudDialog::FUN_141357330(NotifyObject* pObj)
{
    Unk_HudNotifyFlag* pFlag = static_cast<Unk_HudNotifyFlag*>(pObj);
    if (pFlag == 0)
        return;
    int bKeyboard = pFlag->m_bFlag == 0 ? 1 : 0;
    if (m_keyboardMode)
        m_keyboardMode->FUN_1422c1fe0(bKeyboard);
    if (m_mouseMode)
        m_mouseMode->FUN_1422c1fe0(bKeyboard);
}

// @0x141357400
void UIUpperHudDialog::SetNoticeSpeed(float f)
{
    m_fNoticeSpeed = f;
}

// @0x141357430
void UIUpperHudDialog::SetNotice(CStringW strText)
{
    m_strNotice = strText;
    m_bNoticeOnce = true;
    if (m_nNoticeWidth == 0)
        FUN_141358490();
}

// @0x1413574a0
void UIUpperHudDialog::SetGamePadMode(int nMode)
{
    if (!((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb5))
        return;
    if (m_gamePadOn)
        m_gamePadOn->vfunc_3(nMode);
    if (m_gamePadOff)
        m_gamePadOff->vfunc_4(nMode == 0);
}

// @0x141357580
void UIUpperHudDialog::SetInputMode(int nMode)
{
    if (m_keyboardMode)
        m_keyboardMode->vfunc_3(nMode);
    if (m_mouseMode)
        m_mouseMode->vfunc_4(nMode == 0);
}

// @0x141357640
void UIUpperHudDialog::FUN_141357640(__int64 tTime, __int64 nBonus)
{
    MS2Ptr<ASTextField> spVersion = GetChild<ASTextField>("m_version");
    if (spVersion == 0)
        return;
    if (!spVersion->GetVisible())
        return;
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xc9) == true)
    {
        spVersion->SetTextHTMLW(StringFormat(L"{0}\n{1}\t{2:+#}", GetStringCommonByKey(L"s_upper_hud_version"),
                                              FUN_14083bdc0(tTime, true, L"/", L":"), nBonus));
    }
    else
    {
        spVersion->SetTextHTMLW(StringFormat(L"{0}\t{1:+#}", FUN_14083bdc0(tTime, true, L"/", L":"), nBonus));
    }
}

// @0x1413579d0
bool UIUpperHudDialog::ToggleVersionText()
{
    MS2Ptr<ASTextField> spVersion = GetChild<ASTextField>("m_version");
    if (spVersion == 0)
        return false;
    spVersion->vfunc_4(!spVersion->GetVisible());
    return spVersion->GetVisible();
}

// @0x141357ac0
void UIUpperHudDialog::FUN_141357ac0(CInPacket& packet)
{
    UpdateSearchDungeon();
}

// @0x141357af0
void UIUpperHudDialog::ResetClock()
{
    m_nHour = 0;
    m_nMinute = 0;
    FUN_141357b30();
}

// @0x141357b30
void UIUpperHudDialog::FUN_141357b30()
{
    CMsTime tm(GetServerTime());
    int nHour = tm.GetHour();
    int nMinute = tm.GetMinute();
    if (m_nHour != nHour || m_nMinute != nMinute)
    {
        m_nHour = nHour;
        m_nMinute = nMinute;
        CStringW strTime = FUN_140f48210(nHour, nMinute);
        if (MS2Ptr<ASMovieClip> spTime = GetChild<ASMovieClip>("m_time"))
            FUN_140cfee80(spTime->FUN_1422bb890(), "timeText", strTime);
        FUN_140cffca0(FUN_1422dbc00(), "m_clockIcon", "clock");
    }
}

// @0x141357d90
void UIUpperHudDialog::FUN_141357d90(int nQuiet)
{
    if (m_30 == 0)
        return;
    int nReady = 0;
    Unk_HudMaidList* pList = ((class Unk_HudMaidList*)((class CUserMaidManager*)(class Unk_HudMaidOwner*)(reinterpret_cast<Unk_HudMaidOwner*>(TSingleton<CUserMaidManager>::GetInstance())))->GetMaidMap());
    for (void* pos = pList->FUN_1412dd700(); pos; pList->FUN_1412dd720(pos))
    {
        MS2Ptr<Unk_HudMaidRec> spMaid = pList->FUN_1412dd780(pos);
        if (spMaid.IsNull())
            continue;
        if (spMaid->m_4c <= 0)
            continue;
        MS2Ptr<CManufacture> spItem(0);
        if (TSingleton<CManufactureManager>::GetInstance()->Lookup(spMaid->m_20, spItem))
        {
            MS2Ptr<CMaidRecipe> spInfo = TSingleton<CMaidRecipeTable>::GetInstance()->Find(spItem->FUN_1409eedf0());
            if (spInfo)
            {
                if (spItem->FUN_140694170() <= GetServerTime())
                    ++nReady;
            }
        }
    }
    if (m_nMaidReady != nReady)
    {
        if (m_nMaidReady < nReady && nQuiet == 0)
            FUN_141276180(s_maidFinish, "");
        m_nMaidReady = nReady;
        SetButtonBadge(m_maidStatus, m_nMaidReady);
    }
}

// @0x141358020
void UIUpperHudDialog::FUN_141358020(bool bForce)
{
    if (m_30 == 0)
        return;
    PCBase* pPc = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    int nHot = ((class Unk_HudEventMgr*)FUN_1401c0d90())->FUN_140477640(FUN_141658f30(pPc));
    if (bForce || m_nHotTime != nHot)
    {
        MS2Ptr<ASMovieClip> spHot = m_30->FUN_1409b4560("m_effectHotTime");
        if (spHot)
        {
            spHot->vfunc_3(nHot);
            if (nHot != 0)
            {
                MS2Ptr<ASMovieClip> spEff = spHot->FUN_1409b4560("eff");
                if (spEff)
                    spEff->vfunc_12(1);
            }
        }
        m_nHotTime = nHot;
    }
}

// @0x1413581f0
void UIUpperHudDialog::FUN_1413581f0()
{
    if (m_noticeText == 0)
        return;
    if (m_nNoticeWidth == 0)
        return;
    float fDelta = TSingleton<CMainSystem>::GetInstance()->GetLastGameTimeDelta();
    m_fNoticePos -= m_fNoticeSpeed * fDelta;
    int x = (int)m_fNoticePos;
    if (!m_bNoticeOnce)
    {
        if (x < -m_nNoticeWidth)
        {
            m_fNoticePos = 0.0f;
            x = 0;
        }
        m_noticeText->SetPositionInt(x, m_nNoticeY);
    }
    else if (x > -m_noticeText->FUN_1422c1340())
        m_noticeText->SetPositionInt(x, m_nNoticeY);
    else
        FUN_141358490();
}

// @0x141358360
void UIUpperHudDialog::RefreshPcBang()
{
    int nState = -1;
    UIPcBangDialog* pDlg = FUN_141359de0(0x4ecf);
    if (pDlg != 0)
    {
        nState = pDlg->GetPcBangGrade();
        SetButtonBadge(m_pcBang, pDlg->GetReceivableCount());
    }
    if (m_30 == 0)
        return;
    SetPcBangState(nState);
}

// @0x141358420
void UIUpperHudDialog::UpdateSearchDungeon()
{
    if (m_searchDungeon == 0)
        return;
    bool bOn = TSingleton<CPartyManager>::GetInstance()->IsAnySearching();
    m_searchDungeon->vfunc_4(bOn);
}

// @0x141358490
void UIUpperHudDialog::FUN_141358490()
{
    if (m_noticeText == 0)
        return;
    if (m_strNotice.IsEmpty())
    {
        m_nNoticeWidth = 0;
        m_eventText->vfunc_3(0);
        return;
    }
    m_eventText->vfunc_3(1);
    m_noticeText->SetTextHTMLW(m_strNotice);
    m_nNoticeWidth = (int)m_noticeText->GetTextWidth();
    int nTotal = m_nNoticeWidth + 0x1d6;
    int nCount = nTotal / m_nNoticeWidth + 1;
    CStringW strRepeat;
    for (int i = 0; i < nCount; i++)
        strRepeat += m_strNotice;
    m_noticeText->SetTextHTMLW(strRepeat);
    m_noticeText->SetWidthInt((int)(m_noticeText->GetTextWidth() + 20.0));
    m_fNoticePos = 470.0f;
    m_bNoticeOnce = false;
    FUN_1413581f0();
}

// @0x1413586c0
void UIUpperHudDialog::FUN_1413586c0(Scaleform::GFx::Value* pRetVal)
{
    ASTooltip tip(1, 2);
    tip.SetTooltipClass("export_common_tooltip_tooltipText");
    tip.SetOnDelay(0);
    tip.SetTooltipAlign(7);
    tip.SetOffsetX(5);
    tip.SetOffsetY(0x16);
    CStringW strText = GetStringCommon(0x9c4);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x11))
        strText += FUN_141900120(4, true, true);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x2e))
        strText += FUN_141900120(5, true, true);
    strText += FUN_141900120(6, true, true);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xc))
        strText += FUN_141900120(7, true, true);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x76))
        strText += FUN_141900120(0xc, true, true);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x91))
    {
        strText += FUN_141900120(0xd, true, true);
        strText += FUN_141900120(0xe, true, true);
    }
    if (FUN_1406a5930())
        strText += FUN_141900120(0xf, true, true);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xf3))
        strText += FUN_141900120(0x10, true, true);
    tip.SetText(strText);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141358b20
void UIUpperHudDialog::FUN_141358b20(Scaleform::GFx::Value* pRetVal)
{
    ATL::CAtlList<MS2Ptr<SAHotTimeEventContext> > list(10);
    ((class Unk_HudEventMgr*)FUN_1401c0d90())->GetHotTimeEvents(list);
    if (list.IsEmpty())
        return;
    PCBase* pPc = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    CStringW strText;
    for (POSITION pos = list.GetHeadPosition(); pos; list.GetNext(pos))
    {
        MS2Ptr<SAHotTimeEventContext> spHot = list.GetAt(pos);
        if (spHot == 0)
            continue;
        if (spHot->m_30 != 0 && FUN_141658f30(pPc) == 0)
            continue;
        if (spHot->m_28.IsEmpty())
            continue;
        strText.Append(spHot->m_28);
        if (pos != list.GetTailPosition())
            strText.Append(L"\n");
    }
    if (strText.IsEmpty())
        return;
    ASTooltip tip(1, 2);
    tip.SetTooltipClass("export_common_tooltip_tooltipText");
    tip.SetOnDelay(0);
    tip.SetTooltipAlign(7);
    tip.SetText(strText);
    tip.SetOffsetX(0x16);
    tip.SetOffsetY(8);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141358df0
void UIUpperHudDialog::FUN_141358df0(Scaleform::GFx::Value* pRetVal)
{
    const std::vector<__int64>* pMerat = FUN_140930580();
    if (pMerat->empty() == 1)
        return;
    ASTooltip tip(1, 2);
    tip.SetTooltipClass("export_common_tooltip_tooltipText");
    tip.SetOnDelay(0);
    tip.SetTooltipAlign(7);
    tip.SetOffsetX(5);
    tip.SetOffsetY(0x19);
    CStringW strTitle = GetStringCommon(0x9c9);
    CStringW strLine = GetStringCommon(0x9ca);
    CStringW strFormat = GetStringCommon(0x987);
    CStringW strList;
    size_t nCount = pMerat->size();
    __int64 nMerat = FUN_140930250();
    CStringW strName = FUN_1418fe590();
    CStringW strValue = StringFormat<CStringW>(strFormat, FUN_1409404f0(nMerat));
    strList.Append(StringFormat<CStringW, CStringW>(strLine, strName, strValue));
    for (size_t i = 0; i < nCount; i++)
    {
        if (FUN_140930200((unsigned int)i) == true)
            continue;
        __int64 nAmount = (*pMerat)[i];
        if (nAmount == 0)
            continue;
        CStringW strItemName = FUN_1418fe5d0((unsigned int)i);
        CStringW strItemValue = StringFormat<CStringW>(strFormat, FUN_1409404f0(nAmount));
        strList.Append(StringFormat<CStringW, CStringW>(strLine, strItemName, strItemValue));
    }
    if (FUN_1406a5720())
    {
        CStringW strRedName = GetStringCommonByKey(L"s_common_meratname_red");
        CStringW strRedValue = FUN_14028dfa0<CStringW>(L"s_common_redmerat", FUN_1409404f0(FUN_140930ae0()));
        strList.Append(StringFormat<CStringW, CStringW>(strLine, strRedName, strRedValue));
    }
    CStringW strText = StringFormat<CStringW>(strTitle, strList);
    tip.SetText(strText);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141359340
void UIUpperHudDialog::ShowPendingNotice()
{
    CStringW strNotice;
    if (!((class Unk_HudEventMgr*)FUN_1401c0d90())->FUN_14047d970(strNotice))
        return;
    SetNotice(CStringW(strNotice));
}

// @0x1413593d0
void UIUpperHudDialog::SetButtonBadge(MS2Ptr<Unk_HudButton> spButton, int nCount)
{
    FUN_140cff840(spButton->FUN_1422bb890(), "badge", nCount > 0);
    FUN_140cfee80(spButton->FUN_1422bb890(), "badgeCount", StringFormat<int>(L"{0}", nCount));
}

// @0x141359510
void UIUpperHudDialog::SetPcBangState(int nState)
{
    m_pcBang->vfunc_3(0);
    m_pcBangCn1->vfunc_3(0);
    m_pcBangCn2->vfunc_3(0);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036e4c0() || ((class CFeatureManager*)FUN_140166410())->IsRegionJP())
    {
        if (nState >= 0)
            m_pcBang->vfunc_3(1);
    }
    else if (((class CFeatureManager*)FUN_140166410())->IsRegionCN())
    {
        switch (nState)
        {
        case 1:
        case 2:
        case 3:
            m_pcBangCn1->vfunc_3(1);
            break;
        case 0:
        case 4:
            m_pcBangCn2->vfunc_3(1);
            break;
        }
    }
}

// @0x141359de0
UIPcBangDialog* FUN_141359de0(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (ref.get() != 0)
            return dynamic_cast<UIPcBangDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x14135a570
int UIUpperHudDialog::vfunc_48()
{
    return 0x4ebe;
}

// ==== UIVideoContents ====

class Unk_HudSound { public: unsigned char m_bMuted; };
MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);

// @0x14135b110
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x14135b1c0
template <> MS2Ptr<Unk_ASVideoPlayer> AScript::FUN_140accef0<Unk_ASVideoPlayer>(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (v.IsObject())
        return Unk_ASCreate<Unk_ASVideoPlayer>(m_nMovieId, v);
    return MS2Ptr<Unk_ASVideoPlayer>(0);
}

// @0x14135b280
template <> MS2Ptr<Unk_ASVideoPlayer> UISwfEntity::GetChild<Unk_ASVideoPlayer>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_ASVideoPlayer>(0);
    return m_30->FUN_140accef0<Unk_ASVideoPlayer>(strName);
}

// @0x14135aa20
UIVideoContents::UIVideoContents()
    : m_68(0), m_strPath("")
{
    m_2c = 0xc;
}

// @0x14135aaa0
UIVideoContents::~UIVideoContents()
{
}

// @0x14135aaf0
CString UIVideoContents::GetTypeName()
{
    return "VideoContents";
}

// @0x14135ab40
int UIVideoContents::vfunc_52(const CString& strPath, float fVolume)
{
    m_strPath = strPath;
    m_68 = fVolume;
    if (m_strPath.IsEmpty())
        return 0;
    if (m_4c != 0)
    {
        if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer"))
        {
            Unk_HudSound* pSound = reinterpret_cast<Unk_HudConfig*>(TSingleton<CGameOption>::GetInstance())->FUN_140d13c70();
            if (pSound != 0)
            {
                float fSound;
                if (pSound->m_bMuted != 0)
                    fSound = 0;
                else
                    fSound = ((struct Unk_SoundState*)(class Unk_HudSound*)(pSound))->FUN_1412602e0();
                spPlayer->FUN_1422e9490(fSound);
            }
            spPlayer->FUN_1422e95b0(strPath);
            spPlayer->FUN_1422e9690(fVolume);
            return 1;
        }
    }
    else
    {
        FUN_1422dbf00(m_2c, 0, 0);
        return 1;
    }
    return 0;
}

// @0x14135ad10
int UIVideoContents::vfunc_53()
{
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer"))
    {
        spPlayer->FUN_1422e9650();
        return 1;
    }
    return 0;
}

// @0x14135adc0
int UIVideoContents::vfunc_54(float fTimeout)
{
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer"))
    {
        Scaleform::GFx::Value vStream = spPlayer->Invoke("getNetStream");
        if (vStream.IsObject())
        {
            MS2Ptr<AScript> spStream = FUN_1409e7dc0(m_28, vStream);
            if (spStream.get() != 0)
            {
                static_cast<ASObj*>(spStream.operator->())->FUN_1409c4a30("openTimeout", fTimeout);
                return 1;
            }
        }
    }
    return 0;
}

// @0x14135af20
void UIVideoContents::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    vfunc_54(30.0f);
    vfunc_52(m_strPath, 0);
}

// @0x14135af90
int UIVideoContents::vfunc_13()
{
    return 0;
}

// @0x14135afa0
void UIVideoContents::FUN_14135afa0(int bMute)
{
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer"))
    {
        float fSound = 1.0f;
        Unk_HudSound* pSound = reinterpret_cast<Unk_HudConfig*>(TSingleton<CGameOption>::GetInstance())->FUN_140d13c70();
        if (pSound != 0)
            fSound = ((struct Unk_SoundState*)(class Unk_HudSound*)(pSound))->FUN_1412602e0();
        float fVolume;
        if (bMute != 0)
            fVolume = 0;
        else
            fVolume = fSound;
        spPlayer->FUN_1422e9490(fVolume);
    }
}

// @0x14135b0a0
void UIVideoContents::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140acca70(m_28, root);
}

// @0x14135b420
int UIVideoContents::vfunc_48()
{
    return 0x3ee;
}

// ==== UIWebBrowserBase / UIVisitorsBookDialog (the exe has the visitors book first) ====

class Unk_HudBrowserInst;
class Unk_HudBrowserTex;
class Unk_HudBrowserMgr : public CWebBrowserService
{
};
class NiDX9TextureData   // C3: member view for the former free stand-ins
{
public:
    struct IDirect3DBaseTexture9* GetD3DTexture() const;
};
void FUN_14272b7f0(void* pTarget, void* pTex);

void* FUN_140aadf80();   // C3: was FUN_140aadf80
float FUN_14028aed0(float f);                                                   // round

class Unk_HudHome : public CubeMapInformationService { };                      // the owner name
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
CString FUN_1401d9af0(const char* pszFormat, const __int64& a1);               // StringFormat, one narrow argument

class Unk_HudUrlCfg { public: CString& FUN_140298f80(); };
class Unk_HudClientData
{
public:
    char m_pad_0000[0x7478];
    Unk_HudUrlCfg m_url;                                                        // +0x7478
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
const char* FUN_14135bb70(Unk_HudUrlCfg* pCfg);

class ASDialog : public ASDisplayObject
{
public:
    float FUN_1422c1110();                                                      // y
};

// The slot 24 call on the TPtr of vfunc_25.
class Unk_UISwfEntity_25
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void* vfunc_24(void* p);
};

// @0x14135b540
UIVisitorsBookDialog::UIVisitorsBookDialog()
    : UIWebBrowserBase(1)
{
    FUN_1422dc3b0(1);
}

// @0x14135b5c0
CString UIVisitorsBookDialog::GetTypeName()
{
    return "VisitorsBookDialog";
}

// @0x14135b610
void UIVisitorsBookDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    float fScale = reinterpret_cast<Unk_HudUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adbe70();
    int nWidth = (int)(__int64)(1290.0f / fScale);
    int nHeight = (int)(__int64)(1290.0f / fScale);
    FUN_14135eda0(nWidth, nHeight);
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->SendNewsNotification(true, m_nBrowserId);
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        float fX = 0;
        float fY = 0;
        pDialog->GetPosition(&fX, &fY);
        fX = FUN_14028aed0(fX);
        fY = FUN_14028aed0(fY);
        pDialog->SetPositionFloat(fX, fY);
    }
    ASDialog* pDialog2 = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog2 != 0)
    {
        CStringW strOwner = ((class Unk_HudHome*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c31d0();
        pDialog2->Invoke("setHomeOwnerName", strOwner);
    }
    vfunc_84(true);
    __int64 nOwnerId = ((class CubeMapInformationService*)(class Unk_HudHome*)(((class Unk_HudHome*)Unk_AkoHouseSvc::GetInstance())))->FUN_1410c3180();
    CString strUrl = FUN_1401d9af0(FUN_14135bb70(&((class Unk_HudClientData*)FUN_1401d3200())->m_url), nOwnerId);
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x5c)) {}   // empty body in the exe (movzx, no branch)
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b794e0(m_strUrl, strUrl);
}

// @0x14135b8d0
int UIVisitorsBookDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIWebBrowserBase::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}

// @0x14135b920
void UIVisitorsBookDialog::vfunc_87(SIZE* pSize)
{
    pSize->cx = 0x230;
    pSize->cy = 700;
}

// @0x14135b950
bool UIVisitorsBookDialog::vfunc_90(POINT* pPos)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return false;
    POINT kOrig;
    kOrig.x = pPos->x;
    kOrig.y = pPos->y;
    pPos->x -= pDialog->FUN_1422c10a0();
    pPos->y -= pDialog->FUN_1422c1110();
    MS2Ptr<ASUIComponent> spTarget = pDialog->FUN_140accfb0<ASUIComponent>("m_renderTarget");
    if (spTarget == 0)
        return false;
    pPos->x -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(spTarget.operator->()))->FUN_1422c10a0();
    pPos->y -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(spTarget.operator->()))->FUN_1422c1110();
    if (pPos->x < 0 || pPos->y < 0 || pPos->x > m_size.cx || pPos->y > m_size.cy)
        return false;
    return true;
}

// @0x14135bb70
const char* FUN_14135bb70(Unk_HudUrlCfg* pCfg)
{
    return pCfg->FUN_140298f80();
}

// @0x14135bc10
int UIVisitorsBookDialog::vfunc_48()
{
    return 0x4ed9;
}

// ==== UIVisualEffectDialog ====

class Unk_HudSlider : public ASDisplayObject
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool b);
};

class Unk_HudRenderOpt { public: char m_pad_00[0x1e]; bool m_bOutGlow; };      // +0x1e outer glow

// The post process service (0x1409a8b20) and the post effect manager (0x1409a8b00).
class Unk_HudPPEffect;
class Unk_PostProcessSvc : public PostProcessingService
{
public:
};
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
void* FUN_1411782c0(void*, int);   // C3: was FUN_1411782c0
class Unk_PostEffectMgr : public ApplyEffect
{
public:
};

bool FUN_1409a5770(class NiFixedString&, float const*, int);   // C3: was FUN_1409a5770
bool FUN_1409a5850(class NiFixedString&, bool const*, unsigned int);   // C3: was FUN_1409a5850
void FUN_1411781e0(const NiFixedString& kName, const NiPoint2* pk, int n);
extern NiFixedString DAT_143ae5348;
extern NiFixedString DAT_143ae5350;
extern NiFixedString DAT_143ae5358;
extern NiFixedString DAT_143ae5360;
extern NiFixedString DAT_143ae5370;
extern NiFixedString DAT_143ae5378;
extern NiFixedString DAT_143ae53b0;
extern NiFixedString DAT_143ae53b8;
extern NiFixedString DAT_143ae53c0;
extern NiFixedString DAT_143ae53d0;
extern NiFixedString DAT_143ae5430;
extern NiFixedString DAT_143ae5440;
extern NiFixedString DAT_143ae5450;
extern NiFixedString DAT_143ae5458;
extern NiRTTI DAT_143ae0e88;
extern float DAT_1439f824c;
extern float DAT_1439f8250;
extern float DAT_1439f8254;

// The 16-byte constant the shader takes (the DOF / colour perspective ranges).
class Unk_ShaderVec4
{
public:
    Unk_ShaderVec4();                                                           // 0x141480230
    Unk_ShaderVec4(float a, float b, float c, float d);                         // 0x14135dcd0
    void Assign(float a, float b, float c, float d);                            // 0x14135e000
    float FUN_14135dfc0(unsigned nIndex, float f);
    float FUN_14135dd50(int nIndex) const;
    void FUN_14135e0b0(float f);
    void FUN_14135e0e0(float f);
    void FUN_14135e110(float f);
    void FUN_14135e080(float f);
    float FUN_14135e160() const;
    float FUN_14135e180() const;
    float FUN_14135e1a0() const;
    float FUN_14135e140() const;
    int FUN_14135deb0() const;                                                 // every component is finite
private:
    float m_af[4];
};
MS2_CHECK_SIZE(Unk_ShaderVec4, 0x10);
class Unk_ShaderColor : public Unk_ShaderVec4
{
public:
    Unk_ShaderColor(float a, float b, float c, float d);                        // 0x14135dc80
};
MS2_CHECK_SIZE(Unk_ShaderColor, 0x10);

// The motion blur post effect: +0x20 the mode (0: everything, 1: characters).
class Unk_HudMotionBlur : public NiObject
{
public:
    int GetMode() const;
    void SetMode(int nMode);
private:
    char m_pad_10[0x10];
    int m_nMode;                                                                // +0x20
};
class Unk_HudMotionBlurPtr
{
public:
    Unk_HudMotionBlurPtr(Unk_HudMotionBlur* p);                                 // 0x14135dc40
    ~Unk_HudMotionBlurPtr();                                                    // 0x14135dd20
    Unk_HudMotionBlur* m_p;
};
Unk_HudMotionBlur* FUN_14135dd70(Unk_HudMotionBlurPtr* p);
Unk_HudMotionBlur* FUN_14135dd80(Unk_HudMotionBlurPtr* p);

// The effect behind the post process step (the smart pointer FUN_1409a74a0 / FUN_1409a7b30).
class Unk_HudPPEffectPtr
{
public:
    Unk_HudPPEffectPtr(Unk_HudPPEffect* p);                                     // 0x1409a74a0
    ~Unk_HudPPEffectPtr();                                                      // 0x1409a7b30
    Unk_HudPPEffect* m_p;
};
Unk_HudPPEffect* FUN_14135dd90(Unk_HudPPEffectPtr* p);
class NiViewRenderClick   // C3: member view for the former free stand-ins
{
public:
    class NiRenderListProcessor* GetProcessor() const;
};
Unk_HudMotionBlur* FUN_14135de30(const NiRTTI* pRTTI, NiObject* pObject);
Unk_HudMotionBlur* FUN_14135dde0(NiObject* pObject, const NiRTTI* pRTTI);
bool FUN_14135df60(NiObject* pObject, const NiRTTI* pRTTI);
bool FUN_14135dba0(const NiFixedString& kName, const Unk_ShaderVec4* pv, int n);
void FUN_14135db70(const NiFixedString& kName, const Unk_ShaderColor* pv, int n);
float FUN_14135dad0(const char* pszName);
void FUN_14135d9d0(int nMode);

// A 12-byte rgb with the default (inline) copy: the glow colour assignment is a rep movsb in the exe. The ctor is
// only declared: an all-float 12-byte aggregate counts as a GS buffer, the exe's frame has no cookie.
struct Unk_HudColor3
{
    Unk_HudColor3();
    float r, g, b;
};

// The world environment behind the player table (0x141bd30a0).
class Unk_HudEnvData
{
public:
    char m_pad_00[0x17c];
    Unk_HudColor3 m_glowColor;                                                     // +0x17c
    char m_pad_188[0x74];
    char m_bGlow;                                                               // +0x1fc
};
class Unk_HudEnvPtr
{
public:
    ~Unk_HudEnvPtr();                                                           // 0x1408850f0
    Unk_HudEnvData* FUN_140885340() const;                                      // operator->
private:
    void* m_unk;
    Unk_HudEnvData* m_p;
};
Unk_HudColor3 FUN_140a56db0(float r, float g, float b);

// @0x14135bc20
UIVisualEffectDialog::UIVisualEffectDialog()
{
    m_40 = 1;
}

// @0x14135bc70
UIVisualEffectDialog::~UIVisualEffectDialog()
{
}

// @0x14135bcb0
CString UIVisualEffectDialog::GetTypeName()
{
    return "VisualEffectDialog";
}

// @0x14135bd00
void UIVisualEffectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    bool bEnable = false;
    bEnable = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(7);
    obj.FUN_1407cbbe0("blackAndWhiteEnable", bEnable);
    {
        Unk_HudPPEffectPtr spEffect(((class Unk_HudPPEffect*)FUN_1411782c0((void*)(((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())), 3)));
        Unk_HudMotionBlurPtr spBlur(FUN_14135de30(&DAT_143ae0e88, ((class NiObject*)((class NiViewRenderClick*)(class Unk_HudPPEffect*)(FUN_14135dd90(&spEffect)))->GetProcessor())));
        bool bAll = false;
        if (FUN_14135dd70(&spBlur) != 0)
            bAll = FUN_14135dd80(&spBlur)->GetMode() == 0;
        obj.FUN_1407cbbe0("motionBlurAll", bAll);
        obj.FUN_1409c4a30("motionBlurValue", FUN_14135dad0((const char*)DAT_143ae5450));
        bEnable = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(9);
        obj.FUN_1407cbbe0("radiarBlurEnable", bEnable);
        obj.FUN_1409c4a30("radiarBlurValue", FUN_14135dad0((const char*)DAT_143ae5458));
        bEnable = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(8);
        obj.FUN_1407cbbe0("screenMaskEnable", bEnable);
        obj.FUN_1409c4a30("hdrBPThreshold", FUN_14135dad0((const char*)DAT_143ae5358));
        obj.FUN_1409c4a30("hdrBPOffset", FUN_14135dad0((const char*)DAT_143ae5360));
        obj.FUN_1409c4a30("hdrBloomScale", FUN_14135dad0((const char*)DAT_143ae5370));
        obj.FUN_1409c4a30("hdrGlowScale", FUN_14135dad0((const char*)DAT_143ae5378));
        bEnable = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(0xc);
        obj.FUN_1407cbbe0("shimmerEnable", bEnable);
        obj.FUN_1409c4a30("shimmerMultiplier", FUN_14135dad0((const char*)DAT_143ae5430));
        obj.FUN_1409c4a30("shimmerBrightness", FUN_14135dad0((const char*)DAT_143ae5440));
        bEnable = reinterpret_cast<Unk_HudRenderOpt*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bOutGlow;
        obj.FUN_1407cbbe0("outGlowEnable", bEnable);
        unsigned int nSize = 0xc;
        float fRed = 0;
        float fGreen = 0;
        float fBlue = 0;
        NiShaderFactory::GetInstance();
        const void* pData;
        if (NiShaderFactory::RetrieveGlobalShaderConstant(DAT_143ae5348, nSize, pData))
        {
            const Unk_HudXyz* pColor = static_cast<const Unk_HudXyz*>(pData);
            fRed = pColor->x;
            fGreen = pColor->y;
            fBlue = pColor->z;
        }
        obj.FUN_1409c4a30("outGlowRed", fRed);
        obj.FUN_1409c4a30("outGlowGreen", fGreen);
        obj.FUN_1409c4a30("outGlowBlue", fBlue);
        obj.FUN_1407cbbe0("effectDetailEnable", false);
        obj.FUN_1409c4a30("effectTime1", DAT_1439f824c);
        obj.FUN_1409c4a30("effectTime2", DAT_1439f8250);
        obj.FUN_1409c4a30("effectTime3", DAT_1439f8254);
        obj.FUN_1407cbbe0("gaussianBlurEnable", false);
        float fGaussian = 0;
        obj.FUN_1409c4a30("gaussianBlur", fGaussian);
        float fNear = 0;
        float fFar = 0;
        NiGlobalConstantEntry* pDof = NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(DAT_143ae53b0);
        if (pDof != 0)
        {
            pDof->GetData(nSize, pData);
            const Unk_ShaderVec4* pRange = static_cast<const Unk_ShaderVec4*>(pData);
            fNear = pRange->FUN_14135e160();
            fFar = pRange->FUN_14135e180();
        }
        obj.FUN_1409c4a30("dofNear", fNear);
        obj.FUN_1409c4a30("dofFar", fFar);
        bEnable = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(5);
        obj.FUN_1407cbbe0("colorPersEnable", bEnable);
        NiGlobalConstantEntry* pPers = NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(DAT_143ae53d0);
        if (pPers != 0)
        {
            unsigned int nPersSize;
            const void* pPersData;
            pPers->GetData(nPersSize, pPersData);
            const Unk_ShaderVec4* pColorPers = static_cast<const Unk_ShaderVec4*>(pPersData);
            float afRange[4] = {pColorPers->FUN_14135e160(), pColorPers->FUN_14135e180(), pColorPers->FUN_14135e1a0(),
                                pColorPers->FUN_14135e140()};
            for (int i = 0; i < 3; i++)
                afRange[i + 1] = (std::max)(afRange[i], afRange[i + 1]);
            CString astrName[4] = {"colorPersNearStart", "colorPersNearEnd", "colorPersFarStart", "colorPersFarEnd"};
            for (int i = 0; i < 4; i++)
                obj.FUN_1409c4a30(astrName[i], afRange[i]);
        }
    }
    m_30->Invoke("initData", obj.FUN_1422bb870());
    if (MS2Ptr<Unk_HudSlider> spSlider = m_30->FUN_140accef0<Unk_HudSlider>("m_sliderGaussianBlur"))
    {
        reinterpret_cast<ASSlider*>(spSlider.get())->FUN_1422ce6a0(3.0f);
        reinterpret_cast<ASSlider*>(spSlider.get())->FUN_1422ce8b0(0.1f);
        spSlider->vfunc_24(true);
    }
}

// @0x14135c5f0
int UIVisualEffectDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onCheckBlackWhiteEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d310(bValue);
        }
        return 1;
    }
    else if (_stricmp("onSelectRadioMotionBlurAll", szMethod) == 0)
    {
        OnSelectRadioMotionBlurAll();
        return 1;
    }
    else if (_stricmp("onSelectRadioMotionBlurCharacter", szMethod) == 0)
    {
        OnSelectRadioMotionBlurCharacter();
        return 1;
    }
    else if (_stricmp("onChangeSliderMotionBlur", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5450, fValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckRadialBlurEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d410(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderRadialBlur", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5458, fValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckScreenMaskEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d440(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderHdrBPThreshold", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5358, fValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderHdrBPOffset", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5360, fValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderHdrBloomScale", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5370, fValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderHdrGlowScale", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5378, fValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckShimmerEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d490(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderShimmerMultiplier", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5430, fValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderShimmerBrightness", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            SetShaderFloat(DAT_143ae5440, fValue);
        }
        return 1;
    }
    else if (_stricmp("onCheckOutGlowEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            SetGlowEnabled(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderOutGlowColor", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fRed = data.PopFloat();
            float fGreen = data.PopFloat();
            float fBlue = data.PopFloat();
            SetGlowColor(fRed, fGreen, fBlue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderEffectTime", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            DAT_1439f824c = data.PopFloat();
            DAT_1439f8250 = data.PopFloat();
            DAT_1439f8254 = data.PopFloat();
        }
        return 1;
    }
    else if (_stricmp("onCheckGaussianBlurEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d630(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderGaussianBlur", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fValue = data.PopFloat();
            FUN_14135d660(fValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderDOF", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fNear = data.PopFloat();
            float fFar = data.PopFloat();
            SetNearFarRange(fNear, fFar);
        }
        return 1;
    }
    else if (_stricmp("onCheckColorPersEnable", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            bool bValue = data.PopBool();
            FUN_14135d700(bValue);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderColorPerspective", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_14135d730(data);
        return 1;
    }
    return 0;
}

// @0x14135d2d0
void UIVisualEffectDialog::SetShaderFloat(const NiFixedString& kName, float fValue)
{
    FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(kName), &fValue, 1);
}

// @0x14135d310
void UIVisualEffectDialog::FUN_14135d310(bool bOn)
{
    float f = 0;
    FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae5350), &f, 1);
    if (bOn)
        ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(7, true);
    else
        ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(7, false);
}

// @0x14135d380
void UIVisualEffectDialog::OnSelectRadioMotionBlurAll()
{
    FUN_14135d9d0(0);
}

// @0x14135d3a0
void UIVisualEffectDialog::OnSelectRadioMotionBlurCharacter()
{
    FUN_14135d9d0(1);
    bool bEnabled = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(10);
    if (!bEnabled)
    {
        ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(10, bEnabled);
        ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416aa450(3, bEnabled);
    }
}

// @0x14135d410
void UIVisualEffectDialog::FUN_14135d410(bool bOn)
{
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(9, bOn);
}

// @0x14135d440
void UIVisualEffectDialog::FUN_14135d440(bool bOn)
{
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(8, bOn);
    reinterpret_cast<Unk_PostEffectMgr*>(TSingleton<ApplyEffect>::GetInstance())->SetFeature8(bOn, true);
}

// @0x14135d490
void UIVisualEffectDialog::FUN_14135d490(bool bOn)
{
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416aa450(6, bOn);
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(0xc, bOn);
    FUN_1409a5850(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae53c0), &bOn, 1);
}

// @0x14135d4f0
void UIVisualEffectDialog::SetGlowEnabled(bool bOn)
{
    Unk_HudEnvPtr spEnv = reinterpret_cast<Unk_HudPlayerMgr*>(WorldService::GetInstance())->FUN_141bd30a0();
    if (reinterpret_cast<Unk_HudEnvData*>(reinterpret_cast<const MS2Ptr<CFieldDataCli>&>(spEnv).get()) != 0)
        spEnv.FUN_140885340()->m_bGlow = bOn;
    reinterpret_cast<Unk_HudRenderOpt*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bOutGlow = bOn;
    reinterpret_cast<Unk_PostEffectMgr*>(TSingleton<ApplyEffect>::GetInstance())->ApplyOuterGlowOption();
}

// @0x14135d580
void UIVisualEffectDialog::SetGlowColor(float fRed, float fGreen, float fBlue)
{
    Unk_HudEnvPtr spEnv = reinterpret_cast<Unk_HudPlayerMgr*>(WorldService::GetInstance())->FUN_141bd30a0();
    if (reinterpret_cast<Unk_HudEnvData*>(reinterpret_cast<const MS2Ptr<CFieldDataCli>&>(spEnv).get()) != 0)
    {
        spEnv.FUN_140885340()->m_glowColor = FUN_140a56db0(fRed, fGreen, fBlue);
    }
}

// @0x14135d630
void UIVisualEffectDialog::FUN_14135d630(bool bOn)
{
    reinterpret_cast<Unk_PostEffectMgr*>(TSingleton<ApplyEffect>::GetInstance())->SetFeatureB(bOn);
}

// @0x14135d660
void UIVisualEffectDialog::FUN_14135d660(float fValue)
{
    reinterpret_cast<Unk_PostEffectMgr*>(TSingleton<ApplyEffect>::GetInstance())->SetScreenRatio(fValue);
}

// @0x14135d690
void UIVisualEffectDialog::SetNearFarRange(float fNear, float fFar)
{
    NiPoint2 kRange(fNear, fFar);
    FUN_1411781e0(DAT_143ae53b0, &kRange, 1);
    FUN_1409a5770(*(class NiFixedString*)&static_cast<class NiFixedString const&>(DAT_143ae53b8), &fNear, 1);
}

// @0x14135d700
void UIVisualEffectDialog::FUN_14135d700(bool bOn)
{
    ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->SetStepActive(5, bOn);
}

// @0x14135d730
void UIVisualEffectDialog::FUN_14135d730(ASData& data)
{
    float fNearStart = data.PopFloat();
    float fNearEnd = data.PopFloat();
    float fFarStart = data.PopFloat();
    float fFarEnd = data.PopFloat();
    float afRange[4] = {fNearStart, fNearEnd, fFarStart, fFarEnd};
    for (int i = 0; i < 3; i++)
        afRange[i + 1] = (std::max)(afRange[i], afRange[i + 1]);
    Unk_ShaderColor kColor(afRange[0], afRange[1], afRange[2], afRange[3]);
    FUN_14135db70(DAT_143ae53d0, &kColor, 1);
    CStringA astrName[4] = {"m_sliderColorPersNearStart", "m_sliderColorPersNearEnd", "m_sliderColorPersFarStart", "m_sliderColorPersFarEnd"};
    for (int i = 0; i < 4; i++)
        SetSliderValue(astrName[i], afRange[i]);
}

// @0x14135d960
void UIVisualEffectDialog::SetSliderValue(const CString& strName, float fValue)
{
    MS2Ptr<Unk_HudSlider> spSlider = GetChild<Unk_HudSlider>(strName);
    if (static_cast<Unk_HudSlider*>(spSlider) != 0)
        reinterpret_cast<ASSlider*>(spSlider.get())->FUN_1422ce5f0(fValue);
}

// @0x14135d9d0
void FUN_14135d9d0(int nMode)
{
    Unk_HudPPEffectPtr spEffect(((class Unk_HudPPEffect*)FUN_1411782c0((void*)(((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())), 3)));
    Unk_HudMotionBlurPtr spBlur(FUN_14135de30(&DAT_143ae0e88, ((class NiObject*)((class NiViewRenderClick*)(class Unk_HudPPEffect*)(FUN_14135dd90(&spEffect)))->GetProcessor())));
    if (FUN_14135dd70(&spBlur) != 0)
        FUN_14135dd80(&spBlur)->SetMode(nMode);
    bool bOk = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsStepActive(10);
    if (!bOk)
    {
        bOk = ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a37a0(10, true);
        ((class Unk_PostProcessSvc*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416aa450(3, bOk);
    }
}

// @0x14135dad0
float FUN_14135dad0(const char* pszName)
{
    const void* pData = 0;
    unsigned int nSize = 4;
    float fValue = 0;
    NiGlobalConstantEntry* pEntry = NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(pszName);
    if (pEntry)
    {
        pEntry->GetData(nSize, pData);
        fValue = *static_cast<const float*>(pData);
        return fValue;
    }
    return 0;
}

// @0x14135db70
void FUN_14135db70(const NiFixedString& kName, const Unk_ShaderColor* pv, int n)
{
    FUN_14135dba0(kName, pv, n);
}

// @0x14135dba0
bool FUN_14135dba0(const NiFixedString& kName, const Unk_ShaderVec4* pv, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!pv[i].FUN_14135deb0())
        {
            throw 13;
        }
    }
    if (NiShaderFactory::UpdateGlobalShaderConstant(kName, n * sizeof(Unk_ShaderVec4), pv))
        return true;
    return false;
}

// @0x14135dc40
Unk_HudMotionBlurPtr::Unk_HudMotionBlurPtr(Unk_HudMotionBlur* p)
{
    m_p = p;
    if (m_p != 0)
        m_p->IncRefCount();
}

// @0x14135dc80
Unk_ShaderColor::Unk_ShaderColor(float a, float b, float c, float d)
    : Unk_ShaderVec4(a, b, c, d)
{
}

// @0x14135dcd0
Unk_ShaderVec4::Unk_ShaderVec4(float a, float b, float c, float d)
{
    Assign(a, b, c, d);
}

// @0x14135dd20
Unk_HudMotionBlurPtr::~Unk_HudMotionBlurPtr()
{
    if (m_p != 0)
        m_p->DecRefCount();
}

// @0x14135dd50
float Unk_ShaderVec4::FUN_14135dd50(int nIndex) const
{
    return m_af[nIndex];
}

// @0x14135dd70
Unk_HudMotionBlur* FUN_14135dd70(Unk_HudMotionBlurPtr* p)
{
    return p->m_p;
}

// @0x14135dd80
Unk_HudMotionBlur* FUN_14135dd80(Unk_HudMotionBlurPtr* p)
{
    return p->m_p;
}

// @0x14135dd90
Unk_HudPPEffect* FUN_14135dd90(Unk_HudPPEffectPtr* p)
{
    return p->m_p;
}

// @0x14135dde0
Unk_HudMotionBlur* FUN_14135dde0(NiObject* pObject, const NiRTTI* pRTTI)
{
    Unk_HudMotionBlur* pResult;
    if (FUN_14135df60(pObject, pRTTI))
        pResult = reinterpret_cast<Unk_HudMotionBlur*>(pObject);
    else
        pResult = 0;
    return pResult;
}

// @0x14135de30
Unk_HudMotionBlur* FUN_14135de30(const NiRTTI* pRTTI, NiObject* pObject)
{
    if (pObject == 0)
        return 0;
    return FUN_14135dde0(pObject, pRTTI);
}

// @0x14135de90
int Unk_HudMotionBlur::GetMode() const
{
    return m_nMode;
}

// @0x14135dea0
int UIVisualEffectDialog::vfunc_48()
{
    return 0x4eb3;
}

// @0x14135deb0
int Unk_ShaderVec4::FUN_14135deb0() const
{
    if ((_fpclass(m_af[0]) & 0x207) != 0 || (_fpclass(m_af[1]) & 0x207) != 0
        || (_fpclass(m_af[2]) & 0x207) != 0 || (_fpclass(m_af[3]) & 0x207) != 0)
        return 0;
    else
        return 1;
}

// @0x14135df60
bool FUN_14135df60(NiObject* pObject, const NiRTTI* pRTTI)
{
    const NiRTTI* pCur = pObject->GetRTTI();
    while (pCur)
    {
        if (pCur == pRTTI)
            return true;
        pCur = pCur->GetBaseRTTI();
    }
    return false;
}

// @0x14135dfc0
float Unk_ShaderVec4::FUN_14135dfc0(unsigned nIndex, float f)
{
    m_af[nIndex] = f;
    return m_af[nIndex];
}

// @0x14135e000
void Unk_ShaderVec4::Assign(float a, float b, float c, float d)
{
    FUN_14135e0b0(a);
    FUN_14135e0e0(b);
    FUN_14135e110(c);
    FUN_14135e080(d);
}

// @0x14135e060
void Unk_HudMotionBlur::SetMode(int nMode)
{
    m_nMode = nMode;
}

// @0x14135e080
void Unk_ShaderVec4::FUN_14135e080(float f)
{
    FUN_14135dfc0(3, f);
}

// @0x14135e0b0
void Unk_ShaderVec4::FUN_14135e0b0(float f)
{
    FUN_14135dfc0(0, f);
}

// @0x14135e0e0
void Unk_ShaderVec4::FUN_14135e0e0(float f)
{
    FUN_14135dfc0(1, f);
}

// @0x14135e110
void Unk_ShaderVec4::FUN_14135e110(float f)
{
    FUN_14135dfc0(2, f);
}

// @0x14135e140
float Unk_ShaderVec4::FUN_14135e140() const
{
    return FUN_14135dd50(3);
}

// @0x14135e160
float Unk_ShaderVec4::FUN_14135e160() const
{
    return FUN_14135dd50(0);
}

// @0x14135e180
float Unk_ShaderVec4::FUN_14135e180() const
{
    return FUN_14135dd50(1);
}

// @0x14135e1a0
float Unk_ShaderVec4::FUN_14135e1a0() const
{
    return FUN_14135dd50(2);
}

// ==== UIWeaponDummyDialog ====

extern Unk_HudStreamPoint DAT_143b01a60;
extern char DAT_143aad1e0;
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);

// @0x14135e1c0
UIWeaponDummyDialog::UIWeaponDummyDialog()
    : m_rotation(&DAT_143b01a60), m_translation(&DAT_143b01a60)
{
    m_40 = 1;
}

// @0x14135e250
UIWeaponDummyDialog::~UIWeaponDummyDialog()
{
}

// @0x14135e290
CString UIWeaponDummyDialog::GetTypeName()
{
    return "WeaponDummyDialog";
}

// @0x14135e2e0
void UIWeaponDummyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    DAT_143aad1e0 = 1;
    ASObj obj(2);
    obj.FUN_1407cba60("defaultTargetNode", FUN_14016a5c0("Weapon_Hand_L_Point", 0));
    obj.FUN_1407cb9c0("defaultSliderValue", 0);
    m_30->Invoke("initData", obj.FUN_1422bb870());
}

// @0x14135e3f0
int UIWeaponDummyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderRotation", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_14135e660(data);
        return 1;
    }
    else if (_stricmp("onChangeSliderTranslation", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            FUN_14135e7a0(data);
        return 1;
    }
    return 0;
}

// @0x14135e540
void UIWeaponDummyDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    DAT_143aad1e0 = 0;
}

// @0x14135e570
CString UIWeaponDummyDialog::FUN_14135e570()
{
    if (MS2Ptr<ASTextField> spInput = GetChild<ASTextField>("m_inputTargetNode"))
        return spInput->GetTextA();
    return FUN_14016a5c0("", 0);
}

// @0x14135e660
void UIWeaponDummyDialog::FUN_14135e660(ASData& data)
{
    Unk_HudStreamPoint kRot;
    kRot.x = (float)data.PopInt();
    kRot.y = (float)data.PopInt();
    kRot.z = (float)data.PopInt();
    kRot = kRot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f);
    m_rotation = kRot;
    FUN_14135e880(FUN_14135e570(), kRot, m_translation);
}

// @0x14135e7a0
void UIWeaponDummyDialog::FUN_14135e7a0(ASData& data)
{
    Unk_HudStreamPoint kTrans;
    kTrans.x = (float)data.PopInt();
    kTrans.y = (float)data.PopInt();
    kTrans.z = (float)data.PopInt();
    m_translation = kTrans;
    FUN_14135e880(FUN_14135e570(), m_rotation, kTrans);
}

// @0x14135e880
void UIWeaponDummyDialog::FUN_14135e880(const CString& strNode, const Unk_HudStreamPoint& kRot, const Unk_HudStreamPoint& kTrans)
{
    if (strNode.IsEmpty())
        return;
    PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(pPlayer->FUN_14123c410()));
    if (pRoot != 0)
    {
        NiNode* pNode = NiDynamicCast(NiNode, pRoot->GetObjectByName((const char*)strNode));
        if (pNode != 0)
        {
            NiAVObject* pChild = 0;
            for (unsigned int i = 0; i < pNode->GetArrayCount(); i++)
            {
                pChild = pNode->GetAt(i);
                if (pChild != 0 && pChild->GetName().Contains("Weapon_Attach_Transform"))
                    break;
            }
            WeaponAttachTransformNode* pAttach = NiDynamicCast(WeaponAttachTransformNode, pChild);
            if (pAttach != 0)
            {
                NiMatrix3 kMatrix;
                kMatrix.FromEulerAnglesXYZ(kRot.x, kRot.y, kRot.z);
                pAttach->SetBaseRotate(kMatrix);
                // the exe passes the xyz itself as the NiPoint3
                pAttach->SetBasePosition(*reinterpret_cast<const NiPoint3*>(&kTrans));
            }
        }
    }
}

// @0x14135eab0
int UIWeaponDummyDialog::vfunc_48()
{
    return 0x4eb4;
}

// ==== UIWebBrowserBase ====

// @0x14135eac0
UIWebBrowserBase::UIWebBrowserBase(int nBrowserId)
    : m_nBrowserId(nBrowserId), m_bVisible(false), m_b18d(true)
{
}

// @0x14135eb80
UIWebBrowserBase::~UIWebBrowserBase()
{
}

// @0x14135ec00
void UIWebBrowserBase::FUN_14135ec00(const CString& strUrl, bool bOnce)
{
    CString strResolved("");
    m_b18d = bOnce;
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b794e0(strResolved, (const char*)strUrl);
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->Navigate(m_nBrowserId, (const char*)strResolved);
    else
        m_strUrl = strResolved;
    if (FUN_141924630() == 0)
        FUN_141924680();
}

// @0x14135ed30
void UIWebBrowserBase::vfunc_84(bool bVisible)
{
    m_bVisible = bVisible;
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->ShowBrowser(m_nBrowserId, m_bVisible);
}

// @0x14135ed80
int UIWebBrowserBase::IsVisible() const
{
    return m_bVisible;
}

// @0x14135eda0
void UIWebBrowserBase::FUN_14135eda0(int nWidth, int nHeight)
{
    if (m_30 != 0)
    {
        static_cast<ASObj*>(m_30.operator->())->FUN_1409c0d20("m_targetWidth", nWidth);
        static_cast<ASObj*>(m_30.operator->())->FUN_1409c0d20("m_targetHeight", nHeight);
    }
}

// @0x14135ee20
void UIWebBrowserBase::vfunc_85()
{
    if (m_30 != 0)
        m_30->Invoke("loadRenderTarget");
}

// @0x14135ee80
void UIWebBrowserBase::vfunc_86()
{
    if (m_30 != 0)
        m_30->Invoke("unloadRenderTarget");
}

// @0x14135eee0
void UIWebBrowserBase::vfunc_87(SIZE* pSize)
{
    if (m_30 == 0)
        return;
    float fScale = reinterpret_cast<Unk_HudUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adbe70();
    pSize->cx = (int)FUN_14028aed0((float)m_30->Invoke("getViewWidth").GetInt() / fScale);
    pSize->cy = (int)FUN_14028aed0((float)m_30->Invoke("getViewHeight").GetInt() / fScale);
}

// @0x14135f010
int UIWebBrowserBase::vfunc_88()
{
    return 0;
}

// @0x14135f020
int UIWebBrowserBase::vfunc_73()
{
    return UIDialog::vfunc_73();
}

// @0x14135f040
void UIWebBrowserBase::vfunc_26()
{
    UIDialog::vfunc_26();
    vfunc_86();
}

// @0x14135f080
void UIWebBrowserBase::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_14135f7f0();
}

// @0x14135f0b0
void UIWebBrowserBase::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2.get() == 0)
        return;
    if (p3 == 0)
        return;
    Unk_HudBrowserInst* pInst = (Unk_HudBrowserInst*)reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b786a0(m_nBrowserId);
    if (pInst != 0)
    {
        Unk_HudBrowserTex* pTex = ((class Unk_HudBrowserTex*)((class NiTexture*)(class Unk_HudBrowserInst*)(pInst))->GetRendererData());
        if (pTex != 0)
        {
            void* pTarget = p2->vfunc_24(p3);
            if (pTarget != 0)
                FUN_14272b7f0(pTarget, ((void*)((class NiDX9TextureData*)(class Unk_HudBrowserTex*)(pTex))->GetD3DTexture()));
        }
    }
}

// @0x14135f1b0
void UIWebBrowserBase::vfunc_15()
{
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b789d0(m_nBrowserId);
}

// @0x14135f1e0
int UIWebBrowserBase::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onResize") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float fWidth = data.PopFloat();
            float fHeight = data.PopFloat();
            float fScale = reinterpret_cast<Unk_HudUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adbe70();
            m_size.cx = (int)FUN_14028aed0(fWidth / fScale);
            m_size.cy = (int)FUN_14028aed0(fHeight / fScale);
            reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->ResizeBrowser(m_nBrowserId, m_size.cx, m_size.cy);
        }
    }
    else if (_stricmp(szMethod, "onFocusIn") == 0)
        vfunc_84(true);
    else if (_stricmp(szMethod, "onFocusOut") == 0)
        vfunc_84(false);
    return 0;
}

// @0x14135f3c0
void UIWebBrowserBase::vfunc_16()
{
    UISwfEntity::vfunc_16();
    vfunc_86();
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b78a10(m_nBrowserId);
}

// @0x14135f410
bool UIWebBrowserBase::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    if (!reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b78a50(m_nBrowserId))
        return false;
    vfunc_85();
    return true;
}

// @0x14135f480
int UIWebBrowserBase::vfunc_74(int a1, void* p2, void* p3)
{
    if (m_nBrowserId == -1)
        return UIDialog::vfunc_74(a1, p2, p3);
    if (!IsVisible())
        return UIDialog::vfunc_74(a1, p2, p3);
    POINT kPoint;
    kPoint.x = (short)LOWORD(p3);   // GET_X_LPARAM
    kPoint.y = (short)HIWORD(p3);   // GET_Y_LPARAM
    if ((unsigned int)a1 == 0x20a)
        ScreenToClient(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef(), &kPoint);
    kPoint.x *= reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422afec0(m_28);
    kPoint.y *= reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422afec0(m_28);
    // one bool for the hit test and the forward result (WM_MOUSEFIRST..WM_MOUSELAST, unsigned)
    bool bResult = vfunc_90(&kPoint);
    if (!bResult && (unsigned int)a1 >= 0x200 && (unsigned int)a1 <= 0x20d)
        return UIDialog::vfunc_74(a1, p2, p3);
    bResult = reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b78910(m_nBrowserId, a1, (WPARAM)p2, (LPARAM)p3, kPoint.x, kPoint.y);
    if (bResult == 1)
        return bResult;
    return UIDialog::vfunc_74(a1, p2, p3);
}

// @0x14135f660
void UIWebBrowserBase::vfunc_89(const CString& strUrl)
{
    const char* pszFrom = 0;
    if (0 < m_strUrl.GetLength())
        pszFrom = m_strUrl;
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->FUN_141b781e0(m_nBrowserId, pszFrom, (const char*)strUrl, vfunc_88());
    m_strUrl = "";
    vfunc_85();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        vfunc_87(&m_size);
        reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->ResizeBrowser(m_nBrowserId, m_size.cx, m_size.cy);
    }
    vfunc_84(m_bVisible);
}

// @0x14135f7f0
void UIWebBrowserBase::FUN_14135f7f0()
{
    vfunc_84(false);
    reinterpret_cast<Unk_HudBrowserMgr*>(TSingleton<CWebBrowserService>::GetInstance())->CloseBrowser(m_nBrowserId);
}

// @0x14135f840
bool UIWebBrowserBase::vfunc_90(POINT* pPos)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return false;
    POINT ptOrg = { pPos->x, pPos->y };   // an unused copy of the screen position
    pPos->x -= pDialog->FUN_1422c10a0();
    pPos->y -= pDialog->FUN_1422c1110();
    MS2Ptr<ASUIComponent> spTarget = pDialog->FUN_140accfb0<ASUIComponent>("m_renderTarget");
    if (spTarget == 0)
        return false;
    pPos->x -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(spTarget.operator->()))->FUN_1422c10a0();
    pPos->y -= static_cast<ASDialog*>(static_cast<ASDisplayObject*>(spTarget.operator->()))->FUN_1422c1110();
    pPos->x /= reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422afec0(m_28);
    pPos->y /= reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422afec0(m_28);
    if (pPos->x < 0 || pPos->y < 0 || pPos->x > m_size.cx || pPos->y > m_size.cy)
        return false;
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();   // 0x14135fb20
