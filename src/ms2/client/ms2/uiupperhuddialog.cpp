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
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a690 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a6f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIUpperHudDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14135a750 ; unique
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
#include <NiShaderFactory.h>
#include <NiGlobalConstantEntry.h>
#include <NiNode.h>
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/guess/usercommandcli.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>

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
    int FUN_1422c76c0();                                                        // is focused
    void FUN_1422c7630(int bFocus);
    CStringW FUN_1422e0b00();                                                   // the text
    void FUN_1422e0ab0(const CStringW& strText);
    void FUN_1422de780(const HudClickDelegate& onEvent, int a1, int a2);
};

class Unk_HudText : public ASTextField
{
public:
    float FUN_1422c1110();                                                      // the text field height
    double FUN_1422c5970();                                                     // the text width
    void FUN_1422c0e20(int nWidth);
    void FUN_1422c5200(int n);
    CString FUN_1422c4d20();                                                    // the text
};

class Unk_HudFeatures
{
public:
    bool FUN_14036d570(int nFeature);
    bool FUN_14036e4c0();
    bool FUN_14036e510();
    bool FUN_14036e5b0();
};
Unk_HudFeatures* FUN_140166410();

class Unk_HudUIRef
{
public:
    ~Unk_HudUIRef();                                                            // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* unknown;
    UIObject* object;
};
MS2_CHECK_SIZE(Unk_HudUIRef, 0x10);
class Unk_HudUIMgr
{
public:
    void FUN_141adc750(int nUiId);                                              // open
    int FUN_141adc890(int nUiId);                                               // is open
    void FUN_141adc5d0(int nUiId);                                              // close
    float FUN_141adbe70();                                                      // the ui scale
    Unk_HudUIRef FUN_141adcea0(int nUiId);
};
Unk_HudUIMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_HudUIRef&);

class Unk_HudStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);                       // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);                       // unregister
};
Unk_HudStatusMgr* FUN_140aa6d40();
class Unk_HudNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> handler);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> handler);
};
Unk_HudNotices* FUN_140939a10();
class Unk_HudPackets
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);
};
Unk_HudPackets* FUN_140bccd50();

// The notice payloads (NotifyObject is 0x18 bytes).
class Unk_HudNotifyFlag : public NotifyObject { public: char m_bFlag; };                       // +0x18 keyboard / mouse
class Unk_HudNotifyMoney : public NotifyObject { public: char m_pad_18[0x10]; __int64 m_nAmount; };   // +0x28 token money

// The local player and the game event manager.
class Unk_HudEnvPtr;
class Unk_HudPlayerMgr { public: PCBase* FUN_141bd0cc0(); Unk_HudEnvPtr FUN_141bd30a0(); };
Unk_HudPlayerMgr* FUN_1403ed2d0();
int FUN_141658f30(PCBase* pPc);                                                 // pc level
class Unk_HudEventMgr
{
public:
    void FUN_140477590(ATL::CAtlList<MS2Ptr<class Unk_HudHot> >& list);        // the active hot time events
    int FUN_140477640(int nLevel);                                              // the hot time bonus
    bool FUN_14047d970(CStringW& strNotice);                                    // the game event notice
    CStringW FUN_14047db50();                                                   // the web url
};
Unk_HudEventMgr* FUN_1401c0d90();

class Unk_HudHot : public CPtred
{
public:
    char m_pad_18[0x10];
    CStringW m_28;                                                              // +0x28 description
    int m_30;                                                                   // +0x30 level gate
};

// The maids.
class Unk_HudMaidRec : public CPtred
{
public:
    char m_pad_18[8];
    __int64 m_20;                                                               // +0x20 key
    char m_pad_28[0x24];
    int m_4c;                                                                   // +0x4c state
};
class Unk_HudMaidItem : public CPtred
{
public:
    __int64 FUN_1409eedf0();
    __int64 FUN_140694170();                                                    // the time the maid is ready
};
class Unk_HudMaidInfo : public CPtred {};
class Unk_HudMaidItems { public: int FUN_140d51370(__int64 nKey, MS2Ptr<Unk_HudMaidItem>& out); };
class Unk_HudMaidInfos { public: MS2Ptr<Unk_HudMaidInfo> FUN_1406855c0(__int64 nId); };
class Unk_HudMaidList
{
public:
    void* FUN_1412dd700();                                                      // head position
    MS2Ptr<Unk_HudMaidRec>& FUN_1412dd780(void* pos);
    void FUN_1412dd720(void*& pos);                                             // next
};
class Unk_HudMaidOwner;
Unk_HudMaidOwner* FUN_1409eed60();
Unk_HudMaidList* FUN_14127eff0(Unk_HudMaidOwner*);
Unk_HudMaidItems* FUN_1409eed40();
Unk_HudMaidInfos* FUN_1409eed30();
void FUN_141276180(const CString& strSound, const CString& strArg);

// Misc.
class Unk_HudKeys
{
public:
    bool FUN_14116d9c0(int nKey, int a1, int a2);                               // key pressed
    bool FUN_14116d840();                                                       // escape pressed
    CStringW FUN_1422b0570(const CString& strKey);                              // string table text of "$..." keys
    float FUN_1422afec0(int nUiId);                                             // the ui scale of a movie
};
Unk_HudKeys* FUN_14025e7c0();
Unk_HudKeys* FUN_14025e7a0();
class Unk_HudClock { public: float FUN_141473230(); };                         // game time in seconds
Unk_HudClock* FUN_14086d260();
class Unk_HudRenderOpt;
class Unk_HudSound;
class Unk_HudConfig { public: unsigned char* FUN_140a58500(); Unk_HudRenderOpt* FUN_1409a8ac0(); Unk_HudSound* FUN_140d13c70(); };
Unk_HudConfig* FUN_1409a8b10();
void FUN_14125f670(void* pCfg, bool a1, bool a2);
class Unk_HudMouse { public: int FUN_140ad21b0(); };                           // controller on
Unk_HudMouse* FUN_140953f30();
class Unk_HudParty { public: bool FUN_14162ac40(); };
Unk_HudParty* FUN_1409670d0();
__int64 FUN_140869440();                                                        // the server time
bool FUN_140184310(const CString& str, const char* psz);                        // str == psz
void FUN_140710590(COutPacket& packet);

CStringW FUN_14028b8e0(const CStringW& strKey);                                 // string table text
CStringW FUN_14028de60(int nId);                                                // string table text by id
CStringW FUN_14083bdc0(const CMsTime& t, int n, CStringW strSep, CStringW strSep2);
CStringW FUN_140f48210(int nHour, int nMinute);                                 // the clock text
CStringW FUN_1402761d0(const wchar_t* szFormat, const CStringW& a1, const __int64& a2);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a1);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a1, const CStringW& a2);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a1);
CStringW FUN_1409404f0(__int64 n);                                              // the number as text
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);
CStringW FUN_141900120(int nCurrency, bool bIcon, bool bNewline);

class Unk_HudMerat
{
public:
    int FUN_140358390();
    int FUN_140358770();
    __int64* FUN_140356840(int nIndex);
};
Unk_HudMerat* FUN_140930580();
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
    : m_tokenPocket(0), m_maidStatus(0), m_pcBang(0), m_fishingBook(0), m_keyboardGuide(0), m_keyboardMode(0),
      m_mouseMode(0), m_gamePadOn(0), m_gamePadOff(0), m_search(0), m_searchInput(0)
{
    m_nHour = 0;
    m_nMinute = 0;
    m_nMaidReady = 0;
    m_nHotTime = 0;
    m_bNoticeOnce = false;
    m_fNoticeSpeed = 50.0f;
    m_fNoticePos = 0.0f;
    m_nNoticeY = 0;
    m_nNoticeWidth = 0;
    FUN_1422dc3b0(1);
    m_2c = 0xb;
    FUN_140bccd50()->FUN_140da5180(0x53, Delegate<void(CInPacket&)>(this, &UIUpperHudDialog::FUN_141357ac0));
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357300));
    FUN_140939a10()->FUN_140da4e40(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357330));
}

// @0x141353a70
UIUpperHudDialog::~UIUpperHudDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x53, Delegate<void(CInPacket&)>(this, &UIUpperHudDialog::FUN_141357ac0));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357300));
    FUN_140939a10()->FUN_140da4eb0(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357330));
}

// @0x141353e80
CString UIUpperHudDialog::vfunc_1()
{
    return "UpperHudDialog";
}
MS2_REPLACE_METHOD(0x141353E80, UIUpperHudDialog, vfunc_1, 61, 0xF83C7D54);

// @0x141353ed0
void UIUpperHudDialog::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140b632f0()->FUN_1422d4780(this, 4);
    do { m_30->FUN_140bc71c0("m_searchDungeon", m_searchDungeon); if (m_searchDungeon == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(85), __FUNCTION__)); } while (0);
    do { m_30->FUN_140bc71c0("m_eventText", m_eventText); if (m_eventText == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(86), __FUNCTION__)); } while (0);
    do { if (m_eventText->FUN_140beaf20("textField", m_noticeText) == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(89), __FUNCTION__)); } while (0);
    m_nNoticeY = (int)m_noticeText->FUN_1422c1110();
    m_eventText->FUN_1422c2a70(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356ed0), 0);
    if (FUN_140bc6d10("m_tokenPocketButton", m_tokenPocket))
        m_tokenPocket->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356cd0), 0);
    if (FUN_140bc6d10("m_maidStatusButton", m_maidStatus))
        m_maidStatus->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356d00), 0);
    m_30->FUN_140bbe640("m_pcBangButton", m_pcBang);
    if (m_pcBang == 0)
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(101), __FUNCTION__));
    do { m_30->FUN_140bbe640("m_pcBangButtonCn1", m_pcBangCn1); if (m_pcBangCn1 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(102), __FUNCTION__)); } while (0);
    do { m_30->FUN_140bbe640("m_pcBangButtonCn2", m_pcBangCn2); if (m_pcBangCn2 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(103), __FUNCTION__)); } while (0);
    m_pcBang->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356d30), 0);
    m_pcBangCn1->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356d30), 0);
    m_pcBangCn2->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356d30), 0);
    if (FUN_140bc6d10("m_fishingBookButton", m_fishingBook))
        m_fishingBook->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356dc0), 0);
    if (FUN_140bc6d10("m_keyboardGuideButton", m_keyboardGuide))
        m_keyboardGuide->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356df0), 0);
    if (FUN_140bc6d10("m_searchButton", m_search))
    {
        if (FUN_140166410()->FUN_14036d570(0x2f) == true)
            m_search->Invoke("changeTooltipText", FUN_14025e7a0()->FUN_1422b0570("$s_gamedictionary_tooltip_search"));
        m_search->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356f90), 0);
    }
    if (FUN_14129a040("m_searchInput", m_searchInput))
    {
        m_searchInput->FUN_1422de780(HudClickDelegate(this, &UIUpperHudDialog::FUN_141357050), 0, 0);
        m_searchInput->vfunc_3(0);
    }
    if (FUN_140166410()->FUN_14036d570(0xaf) == true)
    {
        if (FUN_140bc6d10("m_keyboardMode", m_keyboardMode))
        {
            m_keyboardMode->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e20), 0);
            m_keyboardMode->vfunc_4(FUN_140953f30()->FUN_140ad21b0() == 0);
        }
        if (FUN_140bc6d10("m_mouseMode", m_mouseMode))
        {
            m_mouseMode->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e20), 0);
            m_mouseMode->vfunc_3(FUN_140953f30()->FUN_140ad21b0());
        }
    }
    if (FUN_140166410()->FUN_14036d570(0xb5) == true)
    {
        if (FUN_140bc6d10("m_gamePadOn", m_gamePadOn))
            m_gamePadOn->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e50), 0);
        if (FUN_140bc6d10("m_gamePadOff", m_gamePadOff))
            m_gamePadOff->FUN_1422ce240(HudClickDelegate(this, &UIUpperHudDialog::FUN_141356e90), 0);
        FUN_1413574a0(*FUN_1409a8b10()->FUN_140a58500());
    }
    if (FUN_140166410()->FUN_14036d570(0xc9) == true)
    {
        MS2Ptr<Unk_HudText> spVersion = FUN_140bb4cf0("m_version");
        if (spVersion)
        {
            spVersion->vfunc_4(true);
            spVersion->FUN_1422c4f00(FUN_14028b8e0(L"s_upper_hud_version"));
        }
    }
    {
        MS2Ptr<Unk_HudText> spVersion = FUN_140bb4cf0("m_version");
        if (spVersion)
        {
            spVersion->vfunc_4(true);
            spVersion->FUN_1422c5200(1);
        }
    }
    FUN_140cff840(m_maidStatus->FUN_1422bb890(), "badge", 0);
    FUN_140cfee80(FUN_1422dbc00(), "mesoText", FUN_1409404f0(DAT_143ab2898));
    FUN_140cfee80(FUN_1422dbc00(), "maratText", FUN_1409404f0(FUN_140930240()));
    FUN_141358020(1);
    FUN_141359340();
    FUN_141357af0();
    FUN_141358360();
    FUN_141358420();
    FUN_141358490();
    m_30->Invoke("arrangePos");
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_140939a10()->FUN_140da4e40(L"NotifyPcBang", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357180));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_1413571f0));
    FUN_141357d90(1);
}

class UIPcBangDialog : public UIDialog
{
public:
    int FUN_141324d80();
    int FUN_141324db0();
};
UIWebBrowserBase* FUN_140c43790(int nUiId);
UIPcBangDialog* FUN_141359de0(int nUiId);

// @0x1413561c0
void UIUpperHudDialog::vfunc_26()
{
    UIObject::vfunc_26();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_1413571f0));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyPcBang", Delegate<void(NotifyObject*)>(this, &UIUpperHudDialog::FUN_141357180));
    FUN_140b632f0()->FUN_1422d4840(this, 4);
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
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
    if (FUN_140184310(strName, "m_tokenPocketButton"))
        FUN_1413586c0(pRetVal);
    else if (FUN_140184310(strName, "m_effectHotTime"))
        FUN_141358b20(pRetVal);
    else if (FUN_140184310(strName, "m_marat"))
        FUN_141358df0(pRetVal);
}
MS2_REPLACE_METHOD(0x1413565C0, UIUpperHudDialog, vfunc_49, 182, 0xDF2014D0);

// @0x141356680
int UIUpperHudDialog::vfunc_13()
{
    if (UISwfEntity::vfunc_13() != 0)
        return 1;
    if (m_searchInput->FUN_1422c76c0() != 0)
    {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        {
            CStringW strText = m_searchInput->FUN_1422e0b00();
            if (!strText.IsEmpty())
                CUserCommandCli::GetInstance()->Execute(FUN_1401e8510(L"/search {0}", strText));
            m_searchInput->FUN_1422c7630(0);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d840())
        {
            m_searchInput->FUN_1422c7630(0);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141356680, UIUpperHudDialog, vfunc_13, 346, 0x1DB0987E);

// @0x1413567f0
void UIUpperHudDialog::vfunc_15()
{
    if (m_timer.FUN_140268870(1000))
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
    if (FUN_140166410()->FUN_14036d570(0x3d) && m_30 != 0)
    {
        FUN_140cfee80(FUN_1422dbc00(), "maratText", FUN_1409404f0(reinterpret_cast<__int64>(a1)));
        m_30->Invoke("arrangePos");
        if (a2 > 0)
        {
            FUN_140cff840(FUN_1422dbc00(), "m_effectMerat", 1);
            FUN_140cffef0(FUN_1422dbc00(), "m_effectMerat", "1");
        }
    }
}

// @0x141356b80
int UIUpperHudDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30 == 0)
        return 0;
    {
        MS2Ptr<ASMovieClip> spMarat = m_30->FUN_140acce30<ASMovieClip>("m_marat");
        if (spMarat && !FUN_140166410()->FUN_14036d570(0x3d))
            spMarat->vfunc_4(false);
    }
    m_30->Invoke("arrangePos");
    return 1;
}
MS2_REPLACE_METHOD(0x141356B80, UIUpperHudDialog, vfunc_46, 321, 0xF0950323);

// @0x141356cd0
void UIUpperHudDialog::FUN_141356cd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4ece);
}

// @0x141356d00
void UIUpperHudDialog::FUN_141356d00(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4ec9);
}

// @0x141356d30
void UIUpperHudDialog::FUN_141356d30(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4ecf) == 0)
    {
        COutPacket packet(0x67, 0);
        packet.Encode1(0);
        packet.Encode1(1);
        FUN_140710590(packet);
    }
    else
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ecf);
}

// @0x141356dc0
void UIUpperHudDialog::FUN_141356dc0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4ee6);
}

// @0x141356df0
void UIUpperHudDialog::FUN_141356df0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4f0f);
}

// @0x141356e20
void UIUpperHudDialog::FUN_141356e20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4f65);
}

// @0x141356e50
void UIUpperHudDialog::FUN_141356e50(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_14125f670(FUN_1409a8b10()->FUN_140a58500(), false, false);
}

// @0x141356e90
void UIUpperHudDialog::FUN_141356e90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_14125f670(FUN_1409a8b10()->FUN_140a58500(), true, true);
}

// @0x141356ed0
void UIUpperHudDialog::FUN_141356ed0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    CStringW strUrl = FUN_1401c0d90()->FUN_14047db50();
    if (strUrl.IsEmpty())
        return;
    UIWebBrowserBase* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser != 0)
        pBrowser->FUN_14135ec00(CString(strUrl), true);
}

// @0x141356f90
void UIUpperHudDialog::FUN_141356f90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_140166410()->FUN_14036d570(0x2f) == true)
        FUN_1403ed2b0()->FUN_141adc750(0x4f0b);
    else
    {
        m_searchInput->FUN_1422c7630(1);
        m_searchInput->vfunc_3(1);
        m_search->FUN_1422c1fe0(false);
    }
}

// @0x141357050
void UIUpperHudDialog::FUN_141357050(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_searchInput->FUN_1422bfca0())
    {
        if (m_searchInput->FUN_1422c76c0() == 0)
        {
            m_searchInput->vfunc_3(0);
            m_searchInput->FUN_1422e0ab0(L"");
            m_searchInput->vfunc_24(1);
            m_search->FUN_1422c1fe0(true);
        }
    }
}

// @0x141357180
void UIUpperHudDialog::FUN_141357180(NotifyObject* pObj)
{
    if (m_30 == 0)
        return;
    FUN_141358360();
    m_30->Invoke("arrangePos");
}

// @0x1413571f0
void UIUpperHudDialog::FUN_1413571f0(NotifyObject* pObj)
{
    if (static_cast<Unk_HudNotifyMoney*>(pObj)->m_nAmount > 0)
    {
        FUN_140cff840(FUN_1422dbc00(), "m_effectTokenPocket", 1);
        FUN_140cffef0(FUN_1422dbc00(), "m_effectTokenPocket", "1");
    }
}

// @0x141357300
void UIUpperHudDialog::FUN_141357300(NotifyObject* pObj)
{
    FUN_141359340();
}

// @0x141357330
void UIUpperHudDialog::FUN_141357330(NotifyObject* pObj)
{
    if (pObj != 0)
    {
        bool bKeyboard = static_cast<Unk_HudNotifyFlag*>(pObj)->m_bFlag == 0;
        if (m_keyboardMode)
            m_keyboardMode->FUN_1422c1fe0(bKeyboard);
        if (m_mouseMode)
            m_mouseMode->FUN_1422c1fe0(bKeyboard);
    }
}

// @0x141357400
void UIUpperHudDialog::FUN_141357400(float f)
{
    m_fNoticeSpeed = f;
}

// @0x141357430
void UIUpperHudDialog::FUN_141357430(CStringW strText)
{
    m_strNotice = strText;
    m_bNoticeOnce = true;
    if (m_nNoticeWidth == 0)
        FUN_141358490();
}

// @0x1413574a0
void UIUpperHudDialog::FUN_1413574a0(int nMode)
{
    if (FUN_140166410()->FUN_14036d570(0xb5))
    {
        if (m_gamePadOn)
            m_gamePadOn->vfunc_3(nMode);
        if (m_gamePadOff)
            m_gamePadOff->vfunc_4(nMode == 0);
    }
}

// @0x141357580
void UIUpperHudDialog::FUN_141357580(int nMode)
{
    if (m_keyboardMode)
        m_keyboardMode->vfunc_3(nMode);
    if (m_mouseMode)
        m_mouseMode->vfunc_4(nMode == 0);
}

// @0x141357640
void UIUpperHudDialog::FUN_141357640(__int64 tTime, __int64 nBonus)
{
    MS2Ptr<Unk_HudText> spVersion = FUN_140bb4cf0("m_version");
    if (!(spVersion == 0))
    {
        if (!spVersion->FUN_1422bfca0())
            return;
        if (FUN_140166410()->FUN_14036d570(0xc9) == true)
        {
            CMsTime tm(tTime);
            spVersion->FUN_1422c4f00(StringFormat(L"{0}\n{1}\t{2:+#}", FUN_14028b8e0(L"s_upper_hud_version"),
                                                  FUN_14083bdc0(tm, 1, CStringW(L"/"), CStringW(L":")), nBonus));
        }
        else
        {
            CMsTime tm(tTime);
            spVersion->FUN_1422c4f00(FUN_1402761d0(L"{0}\t{1:+#}", FUN_14083bdc0(tm, 1, CStringW(L"/"), CStringW(L":")), nBonus));
        }
    }
}

// @0x1413579d0
bool UIUpperHudDialog::FUN_1413579d0()
{
    MS2Ptr<Unk_HudText> spVersion = FUN_140bb4cf0("m_version");
    if (!(spVersion == 0))
    {
        bool bVisible = spVersion->FUN_1422bfca0();
        spVersion->vfunc_4(!bVisible);
        return spVersion->FUN_1422bfca0();
    }
    return false;
}

// @0x141357ac0
void UIUpperHudDialog::FUN_141357ac0(CInPacket& packet)
{
    FUN_141358420();
}

// @0x141357af0
void UIUpperHudDialog::FUN_141357af0()
{
    m_nHour = 0;
    m_nMinute = 0;
    FUN_141357b30();
}

// @0x141357b30
void UIUpperHudDialog::FUN_141357b30()
{
    CMsTime tm(FUN_140869440());
    int nHour = tm.GetHour();
    int nMinute = tm.GetMinute();
    if (m_nHour != nHour || m_nMinute != nMinute)
    {
        m_nHour = nHour;
        m_nMinute = nMinute;
        CStringW strTime = FUN_140f48210(nHour, nMinute);
        {
            MS2Ptr<ASMovieClip> spTime = FUN_140ba7930("m_time");
            if (spTime)
                FUN_140cfee80(spTime->FUN_1422bb890(), "timeText", strTime);
        }
        FUN_140cffca0(FUN_1422dbc00(), "m_clockIcon", "clock");
    }
}

// @0x141357d90
void UIUpperHudDialog::FUN_141357d90(int nQuiet)
{
    if (m_30 == 0)
        return;
    int nReady = 0;
    Unk_HudMaidList* pList = FUN_14127eff0(FUN_1409eed60());
    for (void* pos = pList->FUN_1412dd700(); pos; pList->FUN_1412dd720(pos))
    {
        MS2Ptr<Unk_HudMaidRec> spMaid = pList->FUN_1412dd780(pos);
        if (spMaid.IsNull())
            continue;
        if (spMaid->m_4c < 1)
            continue;
        MS2Ptr<Unk_HudMaidItem> spItem(0);
        if (FUN_1409eed40()->FUN_140d51370(spMaid->m_20, spItem))
        {
            MS2Ptr<Unk_HudMaidInfo> spInfo = FUN_1409eed30()->FUN_1406855c0(spItem->FUN_1409eedf0());
            if (spInfo)
            {
                if (spItem->FUN_140694170() <= FUN_140869440())
                    ++nReady;
            }
        }
    }
    if (m_nMaidReady != nReady)
    {
        if (m_nMaidReady < nReady && nQuiet == 0)
            FUN_141276180(s_maidFinish, "");
        m_nMaidReady = nReady;
        FUN_1413593d0(m_maidStatus, m_nMaidReady);
    }
}

// @0x141358020
void UIUpperHudDialog::FUN_141358020(bool bForce)
{
    if (m_30 == 0)
        return;
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    int nHot = FUN_1401c0d90()->FUN_140477640(FUN_141658f30(pPc));
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
    if (m_noticeText == 0 || m_nNoticeWidth == 0)
        return;
    m_fNoticePos -= m_fNoticeSpeed * FUN_14086d260()->FUN_141473230();
    int x = (int)m_fNoticePos;
    if (!m_bNoticeOnce)
    {
        if (x < -m_nNoticeWidth)
        {
            m_fNoticePos = 0.0f;
            x = 0;
        }
        m_noticeText->FUN_1422bffe0(x, m_nNoticeY);
    }
    else if (-m_noticeText->FUN_1422c1340() < x)
        m_noticeText->FUN_1422bffe0(x, m_nNoticeY);
    else
        FUN_141358490();
}

// @0x141358360
void UIUpperHudDialog::FUN_141358360()
{
    int nState = -1;
    UIPcBangDialog* pDlg = FUN_141359de0(0x4ecf);
    if (pDlg != 0)
    {
        nState = pDlg->FUN_141324d80();
        FUN_1413593d0(m_pcBang, pDlg->FUN_141324db0());
    }
    if (!(m_30 == 0))
        FUN_141359510(nState);
}

// @0x141358420
void UIUpperHudDialog::FUN_141358420()
{
    if (m_searchDungeon == 0)
        return;
    m_searchDungeon->vfunc_4(FUN_1409670d0()->FUN_14162ac40());
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
    m_noticeText->FUN_1422c4f00(m_strNotice);
    m_nNoticeWidth = (int)m_noticeText->FUN_1422c5970();
    CStringW strRepeat;
    for (int i = 0; i < (m_nNoticeWidth + 0x1d6) / m_nNoticeWidth + 1; i++)
        strRepeat += m_strNotice;
    m_noticeText->FUN_1422c4f00(strRepeat);
    m_noticeText->FUN_1422c0e20((int)(m_noticeText->FUN_1422c5970() + 20.0));
    m_fNoticePos = 470.0f;
    m_bNoticeOnce = false;
    FUN_1413581f0();
}

// @0x1413586c0
void UIUpperHudDialog::FUN_1413586c0(Scaleform::GFx::Value* pRetVal)
{
    ASTooltip tip(1, 2);
    tip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tip.FUN_1409c6e00(0);
    tip.FUN_1409c6dc0(7);
    tip.FUN_1409c6e60(5);
    tip.FUN_1409c6e90(0x16);
    CStringW strText = FUN_14028de60(0x9c4);
    if (FUN_140166410()->FUN_14036d570(0x11))
        strText += FUN_141900120(4, true, true);
    if (FUN_140166410()->FUN_14036d570(0x2e))
        strText += FUN_141900120(5, true, true);
    strText += FUN_141900120(6, true, true);
    if (FUN_140166410()->FUN_14036d570(0xc))
        strText += FUN_141900120(7, true, true);
    if (FUN_140166410()->FUN_14036d570(0x76))
        strText += FUN_141900120(0xc, true, true);
    if (FUN_140166410()->FUN_14036d570(0x91))
    {
        strText += FUN_141900120(0xd, true, true);
        strText += FUN_141900120(0xe, true, true);
    }
    if (FUN_1406a5930())
        strText += FUN_141900120(0xf, true, true);
    if (FUN_140166410()->FUN_14036d570(0xf3))
        strText += FUN_141900120(0x10, true, true);
    tip.FUN_1409c6cb0(strText);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141358b20
void UIUpperHudDialog::FUN_141358b20(Scaleform::GFx::Value* pRetVal)
{
    ATL::CAtlList<MS2Ptr<Unk_HudHot> > list(10);
    FUN_1401c0d90()->FUN_140477590(list);
    if (list.IsEmpty())
        return;
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    CStringW strText;
    for (POSITION pos = list.GetHeadPosition(); pos; list.GetNext(pos))
    {
        MS2Ptr<Unk_HudHot> spHot = list.GetAt(pos);
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
    tip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tip.FUN_1409c6e00(0);
    tip.FUN_1409c6dc0(7);
    tip.FUN_1409c6cb0(strText);
    tip.FUN_1409c6e60(0x16);
    tip.FUN_1409c6e90(8);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141358df0
void UIUpperHudDialog::FUN_141358df0(Scaleform::GFx::Value* pRetVal)
{
    Unk_HudMerat* pMerat = FUN_140930580();
    if (pMerat->FUN_140358390() == 1)
        return;
    ASTooltip tip(1, 2);
    tip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tip.FUN_1409c6e00(0);
    tip.FUN_1409c6dc0(7);
    tip.FUN_1409c6e60(5);
    tip.FUN_1409c6e90(0x19);
    CStringW strTitle = FUN_14028de60(0x9c9);
    CStringW strLine = FUN_14028de60(0x9ca);
    CStringW strFormat = FUN_14028de60(0x987);
    CStringW strList;
    int nCount = pMerat->FUN_140358770();
    strList.Append(FUN_140656190(strLine, FUN_1418fe590(), FUN_1401e8510(strFormat, FUN_1409404f0(FUN_140930250()))));
    for (int i = 0; i < nCount; i++)
    {
        if (FUN_140930200(i) == true)
            continue;
        __int64 nAmount = *pMerat->FUN_140356840(i);
        if (nAmount != 0)
            strList.Append(FUN_140656190(strLine, FUN_1418fe5d0(i), FUN_1401e8510(strFormat, FUN_1409404f0(nAmount))));
    }
    if (FUN_1406a5720())
        strList.Append(FUN_140656190(strLine, FUN_14028b8e0(L"s_common_meratname_red"),
                                     FUN_1405c2690(L"s_common_redmerat", FUN_1409404f0(FUN_140930ae0()))));
    tip.FUN_1409c6cb0(FUN_1401e8510(strTitle, strList));
    *pRetVal = tip.FUN_1422bb870();
}

// @0x141359340
void UIUpperHudDialog::FUN_141359340()
{
    CStringW strNotice;
    if (FUN_1401c0d90()->FUN_14047d970(strNotice))
        FUN_141357430(CStringW(strNotice));
}

// @0x1413593d0
void UIUpperHudDialog::FUN_1413593d0(MS2Ptr<Unk_HudButton> spButton, int nCount)
{
    FUN_140cff840(spButton->FUN_1422bb890(), "badge", nCount > 0);
    FUN_140cfee80(spButton->FUN_1422bb890(), "badgeCount", FUN_1401ceea0(L"{0}", nCount));
}

// @0x141359510
void UIUpperHudDialog::FUN_141359510(int nState)
{
    m_pcBang->vfunc_3(0);
    m_pcBangCn1->vfunc_3(0);
    m_pcBangCn2->vfunc_3(0);
    if (FUN_140166410()->FUN_14036e4c0() || FUN_140166410()->FUN_14036e5b0())
    {
        if (nState >= 0)
            m_pcBang->vfunc_3(1);
        return;
    }
    if (!FUN_140166410()->FUN_14036e510())
        return;
    if (nState != 0)
    {
        if (nState < 1)
            return;
        if (nState < 4)
        {
            m_pcBangCn1->vfunc_3(1);
            return;
        }
        if (nState != 4)
            return;
    }
    m_pcBangCn2->vfunc_3(1);
}

// @0x141359de0
UIPcBangDialog* FUN_141359de0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_HudUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<UIPcBangDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x14135a570
int UIUpperHudDialog::vfunc_48()
{
    return 0x4ebe;
}

// ==== UIVideoContents ====

class Unk_HudSound { public: char m_bMuted; };
MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
float FUN_1412602e0(Unk_HudSound* pSound);                                      // the volume of the sound option

// @0x14135b110
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x14135b1c0
template <> MS2Ptr<Unk_ASVideoPlayer> AScript::FUN_140accef0<Unk_ASVideoPlayer>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
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
CString UIVideoContents::vfunc_1()
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
    if (m_4c == 0)
    {
        FUN_1422dbf00(m_2c, 0, 0);
        return 1;
    }
    MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer");
    if (spPlayer.get() == 0)
        return 0;
    Unk_HudSound* pSound = FUN_1409a8b10()->FUN_140d13c70();
    if (pSound != 0)
    {
        float fSound;
        if (pSound->m_bMuted == 0)
            fSound = FUN_1412602e0(pSound);
        else
            fSound = 0;
        spPlayer->FUN_1422e9490(fSound);
    }
    spPlayer->FUN_1422e95b0(strPath);
    spPlayer->FUN_1422e9690(fVolume);
    return 1;
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
    MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer");
    if (spPlayer.get() != 0)
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
    MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer");
    if (spPlayer.get() != 0)
    {
        float fSound = 1.0f;
        Unk_HudSound* pSound = FUN_1409a8b10()->FUN_140d13c70();
        if (pSound != 0)
            fSound = FUN_1412602e0(pSound);
        float fVolume;
        if (bMute == 0)
            fVolume = fSound;
        else
            fVolume = 0;
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
class Unk_HudBrowserMgr
{
public:
    void FUN_141b794e0(CString& strOut, const char* pszUrl);                    // resolve the url
    void FUN_141b786f0(int nId, const char* pszUrl);                            // navigate
    void FUN_141b78840(int nId, bool bVisible);
    void FUN_141b788b0(int nId, int nWidth, int nHeight);
    void FUN_141b78a10(int nId);
    bool FUN_141b78a50(int nId);
    bool FUN_141b78910(int nId, int nMsg, void* p2, void* p3, int x, int y);   // forward an input message
    Unk_HudBrowserInst* FUN_141b786a0(int nId);
    void FUN_141b78b40(int a1, int nId);
    void FUN_141b789d0(int nId);
    void FUN_141b784f0(int nId);
    void FUN_141b781e0(int nId, const char* pszFrom, const char* pszTo, int n);
};
Unk_HudBrowserMgr* FUN_140cc18a0();
Unk_HudBrowserTex* FUN_140980440(Unk_HudBrowserInst* pInst);
void* FUN_140980360(Unk_HudBrowserTex* pTex);
void FUN_14272b7f0(void* pTarget, void* pTex);

class Unk_HudApp { public: HWND FUN_14209c720(); };
Unk_HudApp* FUN_140aadf80();
float FUN_14028aed0(float f);                                                   // round

class Unk_HudHome { public: };
Unk_HudHome* FUN_1409670e0();
void FUN_1410c31d0(Unk_HudHome* pHome, CStringW& strOut);                       // the owner name
__int64 FUN_1410c3180(Unk_HudHome* pHome);                                      // the owner id
CString FUN_1401d9af0(const char* pszFormat, const __int64& a1);               // StringFormat, one narrow argument

class Unk_HudUrlCfg { public: CString& FUN_140298f80(); };
class Unk_HudClientData
{
public:
    char m_pad_0000[0x7478];
    Unk_HudUrlCfg m_url;                                                        // +0x7478
};
Unk_HudClientData* FUN_1401d3200();
const char* FUN_14135bb70(Unk_HudUrlCfg* pCfg);

class ASDialog : public ASDisplayObject
{
public:
    float FUN_1422c10a0();                                                      // x
    float FUN_1422c1110();                                                      // y
    void FUN_1422c0f60(float* pX, float* pY);
    void FUN_1422c00f0(float x, float y);
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
CString UIVisitorsBookDialog::vfunc_1()
{
    return "VisitorsBookDialog";
}

// @0x14135b610
void UIVisitorsBookDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    float fScale = FUN_1403ed2b0()->FUN_141adbe70();
    int nSize = (int)(__int64)(1290.0f / fScale);
    FUN_14135eda0(nSize, nSize);
    FUN_140cc18a0()->FUN_141b78b40(1, m_nBrowserId);
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        float fX = 0;
        float fY = 0;
        pDialog->FUN_1422c0f60(&fX, &fY);
        fX = FUN_14028aed0(fX);
        fY = FUN_14028aed0(fY);
        pDialog->FUN_1422c00f0(fX, fY);
    }
    ASDialog* pDialog2 = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog2 != 0)
    {
        CStringW strOwner;
        FUN_1410c31d0(FUN_1409670e0(), strOwner);
        pDialog2->Invoke("setHomeOwnerName", strOwner);
    }
    vfunc_84(true);
    __int64 nOwnerId = FUN_1410c3180(FUN_1409670e0());
    CString strUrl = FUN_1401d9af0(FUN_14135bb70(&FUN_1401d3200()->m_url), nOwnerId);
    FUN_140166410()->FUN_14036d570(0x5c);
    FUN_140cc18a0()->FUN_141b794e0(m_strUrl, strUrl);
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
    int nX = pPos->x;
    int nY = pPos->y;
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
    virtual void vfunc_24(int n);
    void FUN_1422ce6a0(float f);
    void FUN_1422ce8b0(float f);
    void FUN_1422ce5f0(float f);                                                // the slider value
};

class Unk_HudRenderOpt { public: char m_pad_00[0x1e]; char m_bOutGlow; };      // +0x1e outer glow

// The post process service (0x1409a8b20) and the post effect manager (0x1409a8b00).
class Unk_HudPPEffect;
class Unk_PostProcessSvc
{
public:
    bool FUN_1416a3a00(int nId);                                                // step enabled
    void FUN_1416a3920(int nId, bool bOn);
    void FUN_1416aa450(int nId, bool bOn);
    bool FUN_1416a37a0(int nId, bool bOn);
};
Unk_PostProcessSvc* FUN_1409a8b20();
Unk_HudPPEffect* FUN_1411782c0(Unk_PostProcessSvc* pSvc, int nId);
class Unk_PostEffectMgr
{
public:
    void FUN_1409a5100(bool b, bool b2);
    void FUN_1409a4ed0();
    void FUN_1409a4f10(char b);
    void FUN_1409a4f40(float f);
};
Unk_PostEffectMgr* FUN_1409a8b00();

void FUN_1409a5770(const NiFixedString& kName, const float* pf, int n);
void FUN_1409a5850(const NiFixedString& kName, const bool* pb, int n);
void FUN_1411781e0(const NiFixedString& kName, const efd::Point2* pk, int n);
const char* FUN_142087e50(const NiFixedString& kName);
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
    int FUN_14135de90() const;
    void FUN_14135e060(int nMode);
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
NiObject* FUN_1409a8c40(Unk_HudPPEffect* pEffect);                              // the post effect's motion blur object
Unk_HudMotionBlur* FUN_14135de30(const NiRTTI* pRTTI, NiObject* pObject);
Unk_HudMotionBlur* FUN_14135dde0(NiObject* pObject, const NiRTTI* pRTTI);
bool FUN_14135df60(NiObject* pObject, const NiRTTI* pRTTI);
bool FUN_14135dba0(const NiFixedString& kName, const Unk_ShaderVec4* pv, int n);
void FUN_14135db70(const NiFixedString& kName, const Unk_ShaderColor* pv, int n);
float FUN_14135dad0(const char* pszName);
void FUN_14135d9d0(int nMode);
void FUN_14135d380();

// The world environment behind the player table (0x141bd30a0).
class Unk_HudEnvData
{
public:
    char m_pad_00[0x17c];
    Unk_HudStreamPoint m_glowColor;                                                // +0x17c
    char m_pad_188[0x74];
    char m_bGlow;                                                               // +0x1fc
};
class Unk_HudEnvPtr
{
public:
    ~Unk_HudEnvPtr();                                                           // 0x1408850f0
    long FUN_1409657a0() const;                                                 // not null
    Unk_HudEnvData* FUN_140885340() const;                                      // operator->
private:
    void* m_unk;
    Unk_HudEnvData* m_p;
};
Unk_HudStreamPoint FUN_140a56db0(float r, float g, float b);

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
CString UIVisualEffectDialog::vfunc_1()
{
    return "VisualEffectDialog";
}

// @0x14135bd00
void UIVisualEffectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    bool bEnable = false;
    bEnable = FUN_1409a8b20()->FUN_1416a3a00(7);
    obj.FUN_1407cbbe0("blackAndWhiteEnable", bEnable);
    Unk_HudPPEffectPtr spEffect(FUN_1411782c0(FUN_1409a8b20(), 3));
    Unk_HudMotionBlurPtr spBlur(FUN_14135de30(&DAT_143ae0e88, FUN_1409a8c40(FUN_14135dd90(&spEffect))));
    bool bAll = false;
    if (FUN_14135dd70(&spBlur) != 0)
        bAll = FUN_14135dd80(&spBlur)->FUN_14135de90() == 0;
    obj.FUN_1407cbbe0("motionBlurAll", bAll);
    obj.FUN_1409c4a30("motionBlurValue", FUN_14135dad0(FUN_142087e50(DAT_143ae5450)));
    bEnable = FUN_1409a8b20()->FUN_1416a3a00(9);
    obj.FUN_1407cbbe0("radiarBlurEnable", bEnable);
    obj.FUN_1409c4a30("radiarBlurValue", FUN_14135dad0(FUN_142087e50(DAT_143ae5458)));
    bEnable = FUN_1409a8b20()->FUN_1416a3a00(8);
    obj.FUN_1407cbbe0("screenMaskEnable", bEnable);
    obj.FUN_1409c4a30("hdrBPThreshold", FUN_14135dad0(FUN_142087e50(DAT_143ae5358)));
    obj.FUN_1409c4a30("hdrBPOffset", FUN_14135dad0(FUN_142087e50(DAT_143ae5360)));
    obj.FUN_1409c4a30("hdrBloomScale", FUN_14135dad0(FUN_142087e50(DAT_143ae5370)));
    obj.FUN_1409c4a30("hdrGlowScale", FUN_14135dad0(FUN_142087e50(DAT_143ae5378)));
    bEnable = FUN_1409a8b20()->FUN_1416a3a00(0xc);
    obj.FUN_1407cbbe0("shimmerEnable", bEnable);
    obj.FUN_1409c4a30("shimmerMultiplier", FUN_14135dad0(FUN_142087e50(DAT_143ae5430)));
    obj.FUN_1409c4a30("shimmerBrightness", FUN_14135dad0(FUN_142087e50(DAT_143ae5440)));
    bEnable = FUN_1409a8b10()->FUN_1409a8ac0()->m_bOutGlow;
    obj.FUN_1407cbbe0("outGlowEnable", bEnable);
    unsigned int nSize = 0xc;
    float fRed = 0;
    float fGreen = 0;
    float fBlue = 0;
    NiShaderFactory::GetInstance();
    const void* pData;
    if (NiShaderFactory::RetrieveGlobalShaderConstant(DAT_143ae5348, nSize, pData))
    {
        const float* pf = static_cast<const float*>(pData);
        fRed = pf[0];
        fGreen = pf[1];
        fBlue = pf[2];
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
    bEnable = FUN_1409a8b20()->FUN_1416a3a00(5);
    obj.FUN_1407cbbe0("colorPersEnable", bEnable);
    NiGlobalConstantEntry* pPers = NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(DAT_143ae53d0);
    if (pPers != 0)
    {
        unsigned int nPersSize;
        const void* pPersData;
        pPers->GetData(nPersSize, pPersData);
        const Unk_ShaderVec4* pColorPers = static_cast<const Unk_ShaderVec4*>(pPersData);
        float afRange[4];
        afRange[0] = pColorPers->FUN_14135e160();
        afRange[1] = pColorPers->FUN_14135e180();
        afRange[2] = pColorPers->FUN_14135e1a0();
        afRange[3] = pColorPers->FUN_14135e140();
        for (int i = 0; i < 3; i++)
            afRange[i + 1] = (std::max)(afRange[i], afRange[i + 1]);
        CString astrName[4] = {"colorPersNearStart", "colorPersNearEnd", "colorPersFarStart", "colorPersFarEnd"};
        for (int i = 0; i < 4; i++)
            obj.FUN_1409c4a30(astrName[i], afRange[i]);
    }
    m_30->Invoke("initData", obj.FUN_1422bb870());
    MS2Ptr<Unk_HudSlider> spSlider = m_30->FUN_140accef0<Unk_HudSlider>("m_sliderGaussianBlur");
    if (spSlider.get() != 0)
    {
        spSlider->FUN_1422ce6a0(3.0f);
        spSlider->FUN_1422ce8b0(0.1f);
        spSlider->vfunc_24(1);
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
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d310(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onSelectRadioMotionBlurAll", szMethod) == 0)
    {
        FUN_14135d380();
        return 1;
    }
    if (_stricmp("onSelectRadioMotionBlurCharacter", szMethod) == 0)
    {
        FUN_14135d3a0();
        return 1;
    }
    if (_stricmp("onChangeSliderMotionBlur", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5450, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onCheckRadialBlurEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d410(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderRadialBlur", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5458, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onCheckScreenMaskEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d440(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderHdrBPThreshold", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5358, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onChangeSliderHdrBPOffset", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5360, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onChangeSliderHdrBloomScale", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5370, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onChangeSliderHdrGlowScale", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5378, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onCheckShimmerEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d490(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderShimmerMultiplier", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5430, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onChangeSliderShimmerBrightness", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d2d0(DAT_143ae5440, data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onCheckOutGlowEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d4f0(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderOutGlowColor", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float fRed = data.FUN_1422b8c10();
            float fGreen = data.FUN_1422b8c10();
            float fBlue = data.FUN_1422b8c10();
            FUN_14135d580(fRed, fGreen, fBlue);
        }
        return 1;
    }
    if (_stricmp("onChangeSliderEffectTime", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            DAT_1439f824c = data.FUN_1422b8c10();
            DAT_1439f8250 = data.FUN_1422b8c10();
            DAT_1439f8254 = data.FUN_1422b8c10();
        }
        return 1;
    }
    if (_stricmp("onCheckGaussianBlurEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d630(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderGaussianBlur", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d660(data.FUN_1422b8c10());
        return 1;
    }
    if (_stricmp("onChangeSliderDOF", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float fNear = data.FUN_1422b8c10();
            float fFar = data.FUN_1422b8c10();
            FUN_14135d690(fNear, fFar);
        }
        return 1;
    }
    if (_stricmp("onCheckColorPersEnable", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d700(data.FUN_1422b8a90());
        return 1;
    }
    if (_stricmp("onChangeSliderColorPerspective", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135d730(data);
        return 1;
    }
    return 0;
}

// @0x14135d2d0
void UIVisualEffectDialog::FUN_14135d2d0(const NiFixedString& kName, float fValue)
{
    FUN_1409a5770(kName, &fValue, 1);
}

// @0x14135d310
void UIVisualEffectDialog::FUN_14135d310(bool bOn)
{
    float f = 0;
    FUN_1409a5770(DAT_143ae5350, &f, 1);
    if (bOn)
        FUN_1409a8b20()->FUN_1416a3920(7, true);
    else
        FUN_1409a8b20()->FUN_1416a3920(7, false);
}

// @0x14135d380
void UIVisualEffectDialog::FUN_14135d380()
{
    FUN_14135d9d0(0);
}

// @0x14135d3a0
void UIVisualEffectDialog::FUN_14135d3a0()
{
    FUN_14135d9d0(1);
    bool bEnabled = FUN_1409a8b20()->FUN_1416a3a00(10);
    if (!bEnabled)
    {
        FUN_1409a8b20()->FUN_1416a3920(10, bEnabled);
        FUN_1409a8b20()->FUN_1416aa450(3, bEnabled);
    }
}

// @0x14135d410
void UIVisualEffectDialog::FUN_14135d410(bool bOn)
{
    FUN_1409a8b20()->FUN_1416a3920(9, bOn);
}

// @0x14135d440
void UIVisualEffectDialog::FUN_14135d440(bool bOn)
{
    FUN_1409a8b20()->FUN_1416a3920(8, bOn);
    FUN_1409a8b00()->FUN_1409a5100(bOn, true);
}

// @0x14135d490
void UIVisualEffectDialog::FUN_14135d490(bool bOn)
{
    FUN_1409a8b20()->FUN_1416aa450(6, bOn);
    FUN_1409a8b20()->FUN_1416a3920(0xc, bOn);
    FUN_1409a5850(DAT_143ae53c0, &bOn, 1);
}

// @0x14135d4f0
void UIVisualEffectDialog::FUN_14135d4f0(bool bOn)
{
    Unk_HudEnvPtr spEnv = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spEnv.FUN_1409657a0() != 0)
        spEnv.FUN_140885340()->m_bGlow = bOn;
    FUN_1409a8b10()->FUN_1409a8ac0()->m_bOutGlow = bOn;
    FUN_1409a8b00()->FUN_1409a4ed0();
}

// @0x14135d580
void UIVisualEffectDialog::FUN_14135d580(float fRed, float fGreen, float fBlue)
{
    Unk_HudEnvPtr spEnv = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spEnv.FUN_1409657a0() != 0)
    {
        Unk_HudStreamPoint color = FUN_140a56db0(fRed, fGreen, fBlue);
        spEnv.FUN_140885340()->m_glowColor = color;
    }
}

// @0x14135d630
void UIVisualEffectDialog::FUN_14135d630(bool bOn)
{
    FUN_1409a8b00()->FUN_1409a4f10(bOn);
}

// @0x14135d660
void UIVisualEffectDialog::FUN_14135d660(float fValue)
{
    FUN_1409a8b00()->FUN_1409a4f40(fValue);
}

// @0x14135d690
void UIVisualEffectDialog::FUN_14135d690(float fNear, float fFar)
{
    float afRange[2] = {fNear, fFar};
    efd::Point2 kRange(fNear, fFar);
    FUN_1411781e0(DAT_143ae53b0, &kRange, 1);
    FUN_1409a5770(DAT_143ae53b8, afRange, 1);
}

// @0x14135d700
void UIVisualEffectDialog::FUN_14135d700(bool bOn)
{
    FUN_1409a8b20()->FUN_1416a3920(5, bOn);
}

// @0x14135d730
void UIVisualEffectDialog::FUN_14135d730(ASData& data)
{
    float afRange[4];
    afRange[0] = data.FUN_1422b8c10();
    afRange[1] = data.FUN_1422b8c10();
    afRange[2] = data.FUN_1422b8c10();
    afRange[3] = data.FUN_1422b8c10();
    for (int i = 0; i < 3; i++)
        afRange[i + 1] = (std::max)(afRange[i], afRange[i + 1]);
    Unk_ShaderColor kColor(afRange[0], afRange[1], afRange[2], afRange[3]);
    FUN_14135db70(DAT_143ae53d0, &kColor, 1);
    CStringA astrName[4] = {"m_sliderColorPersNearStart", "m_sliderColorPersNearEnd", "m_sliderColorPersFarStart", "m_sliderColorPersFarEnd"};
    for (int i = 0; i < 4; i++)
        FUN_14135d960(astrName[i], afRange[i]);
}

// @0x14135d960
void UIVisualEffectDialog::FUN_14135d960(const CString& strName, float fValue)
{
    MS2Ptr<Unk_HudSlider> spSlider = GetChild<Unk_HudSlider>(strName);
    if (static_cast<Unk_HudSlider*>(spSlider) != 0)
        spSlider->FUN_1422ce5f0(fValue);
}

// @0x14135d9d0
void FUN_14135d9d0(int nMode)
{
    Unk_HudPPEffectPtr spEffect(FUN_1411782c0(FUN_1409a8b20(), 3));
    Unk_HudMotionBlurPtr spBlur(FUN_14135de30(&DAT_143ae0e88, FUN_1409a8c40(FUN_14135dd90(&spEffect))));
    if (FUN_14135dd70(&spBlur) != 0)
        FUN_14135dd80(&spBlur)->FUN_14135e060(nMode);
    if (!FUN_1409a8b20()->FUN_1416a3a00(10))
    {
        bool bOk = FUN_1409a8b20()->FUN_1416a37a0(10, true);
        FUN_1409a8b20()->FUN_1416aa450(3, bOk);
    }
}

// @0x14135dad0
float FUN_14135dad0(const char* pszName)
{
    unsigned int nSize = 4;
    const void* pData = 0;
    NiFixedString kName(pszName);
    NiGlobalConstantEntry* pEntry = NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(kName);
    if (pEntry == 0)
        return 0;
    pEntry->GetData(nSize, pData);
    return *static_cast<const float*>(pData);
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
    return NiShaderFactory::UpdateGlobalShaderConstant(kName, n * 0x10, pv);
}

// @0x14135dc40
Unk_HudMotionBlurPtr::Unk_HudMotionBlurPtr(Unk_HudMotionBlur* p)
{
    m_p = p;
    if (m_p != 0)
        FUN_140980460(m_p);
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
        FUN_1405a93d0(m_p);
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
int Unk_HudMotionBlur::FUN_14135de90() const
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
    if ((_fpclass(m_af[0]) & 0x207) == 0 && (_fpclass(m_af[1]) & 0x207) == 0
        && (_fpclass(m_af[2]) & 0x207) == 0 && (_fpclass(m_af[3]) & 0x207) == 0)
        return 1;
    return 0;
}

// @0x14135df60
bool FUN_14135df60(NiObject* pObject, const NiRTTI* pRTTI)
{
    const NiRTTI* pCur = pObject->GetRTTI();
    while (true)
    {
        if (pCur == 0)
            return false;
        if (pCur == pRTTI)
            break;
        pCur = pCur->GetBaseRTTI();
    }
    return true;
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
void Unk_HudMotionBlur::FUN_14135e060(int nMode)
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
    : m_rotation(DAT_143b01a60), m_translation(DAT_143b01a60)
{
    m_40 = 1;
}

// @0x14135e250
UIWeaponDummyDialog::~UIWeaponDummyDialog()
{
}

// @0x14135e290
CString UIWeaponDummyDialog::vfunc_1()
{
    return "WeaponDummyDialog";
}

// @0x14135e2e0
void UIWeaponDummyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    DAT_143aad1e0 = 1;
    ASObj obj(2);
    obj.FUN_1407cba60("defaultTargetNode", CString("Weapon_Hand_L_Point"));
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
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14135e660(data);
        return 1;
    }
    if (_stricmp("onChangeSliderTranslation", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
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
    MS2Ptr<Unk_HudText> spInput = FUN_140bb4cf0("m_inputTargetNode");
    if (static_cast<Unk_HudText*>(spInput) == 0)
        return CString("");
    return spInput->FUN_1422c4d20();
}

// @0x14135e660
void UIWeaponDummyDialog::FUN_14135e660(ASData& data)
{
    Unk_HudStreamPoint kRot;
    kRot.x = (float)data.FUN_1422b8a10();
    kRot.y = (float)data.FUN_1422b8a10();
    kRot.z = (float)data.FUN_1422b8a10();
    kRot = kRot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f);
    m_rotation = kRot;
    FUN_14135e880(FUN_14135e570(), kRot, m_translation);
}

// @0x14135e7a0
void UIWeaponDummyDialog::FUN_14135e7a0(ASData& data)
{
    Unk_HudStreamPoint kTrans;
    kTrans.x = (float)data.FUN_1422b8a10();
    kTrans.y = (float)data.FUN_1422b8a10();
    kTrans.z = (float)data.FUN_1422b8a10();
    m_translation = kTrans;
    FUN_14135e880(FUN_14135e570(), m_rotation, kTrans);
}

// @0x14135e880
void UIWeaponDummyDialog::FUN_14135e880(const CString& strNode, const Unk_HudStreamPoint& kRot, const Unk_HudStreamPoint& kTrans)
{
    if (strNode.IsEmpty())
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(pPlayer->FUN_14123c410()));
    if (pRoot == 0)
        return;
    NiNode* pNode = NiDynamicCast(NiNode, pRoot->GetObjectByName(NiFixedString((const char*)strNode)));
    if (pNode == 0)
        return;
    NiAVObject* pChild = 0;
    for (unsigned int i = 0; i < pNode->GetArrayCount(); i++)
    {
        pChild = pNode->GetAt(i);
        if (pChild != 0 && pChild->GetName().Contains("Weapon_Attach_Transform"))
            break;
    }
    NiAVObject* pAttach = NiDynamicCast(NiAVObject, pChild);
    if (pAttach != 0)
    {
        NiMatrix3 kMatrix;
        kMatrix.FromEulerAnglesXYZ(kRot.x, kRot.y, kRot.z);
        pAttach->SetRotate(kMatrix);
        pAttach->SetTranslate(NiPoint3(kTrans.x, kTrans.y, kTrans.z));
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
{
    m_nBrowserId = nBrowserId;
    m_bVisible = false;
    m_b18d = true;
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
    FUN_140cc18a0()->FUN_141b794e0(strResolved, (const char*)strUrl);
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        FUN_140cc18a0()->FUN_141b786f0(m_nBrowserId, (const char*)strResolved);
    else
        m_strUrl = strResolved;
    if (FUN_141924630() == 0)
        FUN_141924680();
}

// @0x14135ed30
void UIWebBrowserBase::vfunc_84(bool bVisible)
{
    m_bVisible = bVisible;
    FUN_140cc18a0()->FUN_141b78840(m_nBrowserId, m_bVisible);
}

// @0x14135ed80
bool UIWebBrowserBase::FUN_14135ed80() const
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
    float fScale = FUN_1403ed2b0()->FUN_141adbe70();
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
    Unk_HudBrowserInst* pInst = FUN_140cc18a0()->FUN_141b786a0(m_nBrowserId);
    if (pInst != 0)
    {
        Unk_HudBrowserTex* pTex = FUN_140980440(pInst);
        if (pTex != 0)
        {
            void* pTarget = p2->vfunc_24(p3);
            if (pTarget != 0)
                FUN_14272b7f0(pTarget, FUN_140980360(pTex));
        }
    }
}

// @0x14135f1b0
void UIWebBrowserBase::vfunc_15()
{
    FUN_140cc18a0()->FUN_141b789d0(m_nBrowserId);
}

// @0x14135f1e0
int UIWebBrowserBase::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onResize") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float fWidth = data.FUN_1422b8c10();
            float fHeight = data.FUN_1422b8c10();
            float fScale = FUN_1403ed2b0()->FUN_141adbe70();
            m_size.cx = (int)FUN_14028aed0(fWidth / fScale);
            m_size.cy = (int)FUN_14028aed0(fHeight / fScale);
            FUN_140cc18a0()->FUN_141b788b0(m_nBrowserId, m_size.cx, m_size.cy);
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
    FUN_140cc18a0()->FUN_141b78a10(m_nBrowserId);
}

// @0x14135f410
bool UIWebBrowserBase::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    if (!FUN_140cc18a0()->FUN_141b78a50(m_nBrowserId))
        return false;
    vfunc_85();
    return true;
}

// @0x14135f480
int UIWebBrowserBase::vfunc_74(int a1, void* p2, void* p3)
{
    unsigned int nMsg = a1;
    if (m_nBrowserId == -1)
        return UIDialog::vfunc_74(a1, p2, p3);
    if (!FUN_14135ed80())
        return UIDialog::vfunc_74(a1, p2, p3);
    POINT kPoint;
    kPoint.x = (short)(__int64)p3;
    kPoint.y = (short)((unsigned __int64)p3 >> 16);
    if (nMsg == 0x20a)
        ScreenToClient(FUN_140aadf80()->FUN_14209c720(), &kPoint);
    kPoint.x = (LONG)((float)kPoint.x * FUN_14025e7a0()->FUN_1422afec0(m_28));
    kPoint.y = (LONG)((float)kPoint.y * FUN_14025e7a0()->FUN_1422afec0(m_28));
    if (!vfunc_90(&kPoint) && 0x1ff < nMsg && nMsg < 0x20e)
        return UIDialog::vfunc_74(a1, p2, p3);
    if (FUN_140cc18a0()->FUN_141b78910(m_nBrowserId, nMsg, p2, p3, kPoint.x, kPoint.y) == 1)
        return 1;
    return UIDialog::vfunc_74(a1, p2, p3);
}

// @0x14135f660
void UIWebBrowserBase::vfunc_89(const CString& strUrl)
{
    const char* pszFrom = 0;
    if (0 < m_strUrl.GetLength())
        pszFrom = m_strUrl;
    FUN_140cc18a0()->FUN_141b781e0(m_nBrowserId, pszFrom, (const char*)strUrl, vfunc_88());
    m_strUrl = "";
    vfunc_85();
    if (dynamic_cast<ASDialog*>((AScript*)m_30) != 0)
    {
        vfunc_87(&m_size);
        FUN_140cc18a0()->FUN_141b788b0(m_nBrowserId, m_size.cx, m_size.cy);
    }
    vfunc_84(m_bVisible);
}

// @0x14135f7f0
void UIWebBrowserBase::FUN_14135f7f0()
{
    vfunc_84(false);
    FUN_140cc18a0()->FUN_141b784f0(m_nBrowserId);
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
    pPos->x /= FUN_14025e7a0()->FUN_1422afec0(m_28);
    pPos->y /= FUN_14025e7a0()->FUN_1422afec0(m_28);
    if (pPos->x < 0 || pPos->y < 0 || pPos->x > m_size.cx || pPos->y > m_size.cy)
        return false;
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();   // 0x14135fb20
