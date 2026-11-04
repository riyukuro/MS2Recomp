// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: ?\uimainplayerinfo.cpp (.text$mn
// 0x1419ee140-0x1419f55d0, .text$di 0x140116360-0x1401166e0).
//
// UIMainPlayerInfo: the HUD panel of the local player (see uimainplayerinfo.h). The tail of the unit is template glue:
// the CAtlMap<int, MS2Ptr<Unk_AsBuff> > of the pending buffs, the Delegate<void(NotifyObject*)> impl of the three
// notice handlers, UISwfEntity::GetChild<ASEffectManager> and the (CStringW, float) localized-string formatter.
// MS2-UNIT: ?\uimainplayerinfo.cpp
// MS2-RANGE: 0x140116360-0x1401166e0 .text$di
// MS2-RANGE: 0x1419ee140-0x1419f55d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VUnk_AsBuff@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_AsBuff@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1419f4670 ; unique
// MS2-PIN: ?vfunc_48@UIMainPlayerInfo@@UEAAHXZ 0x1419f4800 ; unique
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "uimainplayerinfo.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifykeytable.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- statics (the exe runs them in this order: the refresh timer, the shared header, the handle, the condition, the
// key input, the error text, then a second copy of the shared header without the handle) ----

static Unk_AsTimer s_refreshTimer;                                                         // @0x140116360
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uimainplayerinfo_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/client/ms2/skillslot.h"
#include "ms2/client/ms2/skillsystem.h"   // C3: CSkillSystem::GetSkillSet
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"  // C3: CHomePrivilege complete for the headers above
#include "ms2/client/ms2/uirenderview.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<Unk_Service6100017>::operator->
#include "ms2/placeholder/ssquickentry.h"
#include "ms2/placeholder/cskillsettable.h"
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/gfxui/notifyhandler.h"
class Unk_Service6100017;   // C3: efd::SmartPointer<Unk_Service6100017>::operator->
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;                                       // @0x140116510
static CString s_strNotThisPlace = "system_notice_error_warningNotThisPlace";              // @0x140116540
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x140116570
static CString s_strSkill2 = "skill";                                                      // @0x140116630
static CString s_strStun2 = "stun";                                                        // @0x140116660
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);                        // @0x140116690

// ---- unit-local views of exe types (names assumed; layouts only as far as this unit reads them) ----

// The AS objects of the movie (helpers of the Invoke family that only this unit uses).
class Unk_MpScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ea5e70(const char* szMethod, unsigned short a1);
    Scaleform::GFx::Value FUN_141931d80(const char* szMethod, int a1, int a2, int a3);
    
    MS2Ptr<ASEffectManager> FUN_1419f3a40(const CString& strName);
};
#define MP_AS(p) reinterpret_cast<Unk_MpScript*>((p).operator->())
class Unk_RsScript { public: Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2); };   // C3: unit-local view (def in unit_14129ba60); Invoke(int, string)

// The portrait clip: slot 24 shows it.
class Unk_MpInfoClip : public ASUIComponent
{
public:
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool bShow);
};

class ASDialog : public ASDisplayObject
{
public:
};

// The shortkey slots of the slot manager.
class Unk_MpWnd;
class Unk_MpSlot
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void vfunc_10();                                            // refresh
    virtual void vfunc_11();                                            // clear the cooldown
};
class Unk_MpSlotBar : public SkillSlotBag
{
public:
};
class Unk_MpSlotBox
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void vfunc_11(void* p);
    virtual void vfunc_12(void* p);
};
SkillSlotBag* FUN_141763cb0(NotifyContext::BindData* pWnd);
DragSlotBag* FUN_140c544d0(NotifyContext::BindData* pWnd);
class SkillSlot* FUN_141761e60(class DragSlot*);   // C3: was FUN_141761e60
void FUN_1417634a0(const CString& strName);                             // drop the slot bar
void FUN_1417633f0(const CString& strName, int nCount);                 // create the slot bar


// The skill set of the player.

// The key table.
class Unk_MpKeyPages { public: int FUN_1414370a0(); };
class CKeyTable   // C3: member view (real class not in this TU)
{
public:
    int FUN_14142ca40(int, int);
    __int64 GetKeyAction(int);
    int FindQuickSlotBySkillAndItemUid(int, __int64);
    void FUN_14142f1c0(int, int, __int64);
    void FUN_141431ae0(int, bool);
    void SendKeyTableMode1(int);
    int FUN_14142c940(__int64, int);
    void LoadKeySetting(CString);
    CStringW FUN_141431820(int);
    bool GetQuickSlotEntry(unsigned nSlot, Unk_SsQuickEntry& entry);
    void ApplySkillSetToQuickSlots(MS2Ptr<CSkillSet> spSet);
    int FUN_140a700b0();                                    // the current quick slot page
};
class Unk_MpKeyTable
{
public:
    int FUN_1419f4760();
    char m_pad_00[0x1a0];
    Unk_MpKeyPages m_1a0;                                               // +0x1a0 the pages
};
class Unk_SoundSink* FUN_1409331f0();   // C3: was FUN_1409331f0

// @0x1419f4760
int Unk_MpKeyTable::FUN_1419f4760()
{
    return m_1a0.FUN_1414370a0();
}

void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
struct Unk_MpCfgData { bool m_bExpand; bool m_bShowSkillName; };
class Unk_MpCfg { public: Unk_MpCfgData* FUN_140a58500(); };
class MS2InputService* FUN_140a58540();   // C3: was FUN_140a58540
class CMyCharacter   // C3: member view (cmycharacter.h needs MS2_THIS_FILE via stream.h)
{
public:
    bool FUN_140d9f5d0(int nIndex);
    CStringW FUN_140d9f600(int nIndex);
};
class CMyCharacter* FUN_140931510();   // C3: was FUN_140931510
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
class Unk_ItemEventSystem   // C3: member view (real class not in this TU)
{
public:
    void FUN_1419cae20(UIItemEventListener*);
    void FUN_1419caeb0(UIItemEventListener*);
};
class Unk_MpItemEvents
{
public:
};
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840

// The mount of the player.
struct Unk_AdvMountRow;
struct Unk_MpMountRow
{
    char m_pad_00[0x30];
    int m_30;                                                           // +0x30 ridee name id
    char m_pad_34[0x64 - 0x34];
    int m_64;                                                           // +0x64 ride off
    int m_68;                                                           // +0x68 0 = no ridee avatar
    int m_6c;                                                           // +0x6c riding type (2 = hides the tag)
    char m_pad_70[0x250 - 0x70];
    efd::Point3 m_250;                                                  // +0x250 render target camera target
    efd::Point3 m_25c;                                                  // +0x25c render target camera eye
};
class Unk_AdvMountPtr
{
public:
    Unk_AdvMountPtr(const Unk_AdvMountPtr& o);
    ~Unk_AdvMountPtr();                                                 // 0x140788ed0
    Unk_AdvMountRow* FUN_1407895d0() const;                             // operator->
    void* m_pad_00;
    Unk_AdvMountRow* m_p;
};
#define MP_ROW(p) reinterpret_cast<Unk_MpMountRow*>((p).FUN_1407895d0())
class Ridee : public PCBase { public: Unk_AdvMountPtr FUN_141707750(); };   // C3: member view (held through efd::SmartPointer<Ridee>)

// The ridee avatar (UIAvatarRidee, 0xd8; slot 1 binds the event listener, slot 28 forwards the render target).
struct Unk_MpCamData
{
    Unk_MpCamData();                                                    // 0x140cb13b0
    NiPoint3 m_eye;
    NiPoint3 m_target;
    float m_18, m_1c, m_20, m_24;                                       // the ctor zeroes +0x18..+0x24
    int m_28;                                                           // 1
    int m_2c;                                                           // 0
};
class Unk_MpCamera
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual void vfunc_13(const Unk_MpCamData& data);
};
class UIAvatarBase
{
public:
    efd::SmartPointer<UIRenderView> GetView();
};
class UIAvatarRidee
{
public:
    UIAvatarRidee(Unk_AdvMountPtr spMount);                             // 0x1418bdfd0 (the mount by value)
    virtual void s0();
    virtual void vfunc_1(void* pListener);
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25();
    virtual void s26(); virtual void s27();
    virtual void vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);
    Unk_AdvMountPtr FUN_1418be810();
    char m_pad_08[0xd0];
};
MS2_CHECK_SIZE(UIAvatarRidee, 0xd8);
// The exe calls uiavatarbase.cpp's UIAvatarRidee(Unk_RideePtr) (0x1418bdfd0): this view spells the row pointer
// Unk_AdvMountPtr, so the full exe binds the name to that constructor.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:??0UIAvatarRidee@@QEAA@VUnk_AdvMountPtr@@@Z=??0UIAvatarRidee@@QEAA@VUnk_RideePtr@@@Z")
#endif

// The ride-off request (0x28 bytes, ctor(int) 0x14031b2a0).
class RideOffActionRidingUI { public: RideOffActionRidingUI(int n); char m_pad_00[0x28]; };   // C3: view (rideonaction.h needs MS2_THIS_FILE)

// The ridee controller of the player ("remove" / "create" messages).
class Unk_MpRideeCtl : public Unk_PCCubeCraft
{
};
struct Unk_MpWeaponRow { char m_pad_00[0x18]; __int64 m_18; };
class Cube;
template <> MS2Ptr<Cube>::MS2Ptr(Cube* p);                              // 0x140884fb0
template <> MS2Ptr<Cube>::~MS2Ptr();                                    // 0x140885120
template <> MS2Ptr<Cube>::operator Cube*() const;                       // 0x140885330
template <> Cube* MS2Ptr<Cube>::operator->() const;                     // 0x140885350
class CubeMapInformationService { public: Cube* GetCubeAtPoint(Vector3 pt); };   // C3: member view (cubemapinformationservice_3.h)
template <> efd::SmartPointer<Unk_Service6100017>::SmartPointer(Unk_Service6100017* pObject);   // 0x1401cd0b0
template <> efd::SmartPointer<Unk_Service6100017>::~SmartPointer();                             // 0x1401cd150
template <> efd::SmartPointer<Unk_Service6100017>::operator Unk_Service6100017*() const;        // 0x140885310
class Unk_Service6100017* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(Unk_EntityAppFramework*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8

// The actor state of the player.
class JobSystem   // C3: member view (jobsystem.h needs MS2_THIS_FILE)
{
public:
    JobDataPtr GetJobData();
};
class AdditionalCliList   // C3: member view (real class not in this TU)
{
public:
    float FUN_140970fb0();
    bool IsInfinitySP();
};
class Unk_MpStat { public:   };

class AdditionalCustomCli;
class Unk_MpPC : public MyPC
{
public:
};
class Unk_MpWorld : public WorldService { public: Unk_MpPC* FUN_141bd0cc0();};

// The buff object behind MS2Ptr<Unk_AsBuff> (AdditionalCustomCli, new 0x78).
class AdditionalCustomCli : public Unk_AsBuff
{
public:
    AdditionalCustomCli(PCBase* pOwner, int nKey, int nId, unsigned int nLevel, unsigned int n);   // 0x14096b490
    __int64 m_28[10];
};
MS2_CHECK_SIZE(AdditionalCustomCli, 0x78);
class AdditionalCli   // C3: member view for the former free stand-ins
{
public:
    int IsValid();
    int GetKey();
};

// The achievement of a progress notice.
class CAchieve   // C3: member view (real class not in this TU)
{
public:
    __int64 GetGoal();
    unsigned int GetId();
    __int64 GetProgress();
    int GetState();
    MS2Ptr<CAchieveData> GetDataRef();
};
class Unk_MpAchieve
{
public:
    char m_pad_00[0x18];
    float m_18;                                                         // +0x18 last notified percentage
};

class CItemData;
class CItem
{
public:
    CItemData* FUN_140527840();
    __int64 GetItemUid();
    int FUN_1405276c0();
    int HasCubeTextureMesh();
    int FUN_140526010();
};
class CItemData   // C3: member view for the former free stand-ins
{
public:
    int FUN_14053dc20();
    bool FUN_14053e460();
};
#define MP_ITEM(p) static_cast<CItem*>(p)

void FUN_14151f200();
bool FUN_140930d70();
int FUN_1418dd0c0();
int FUN_1418dd110();
int FUN_141472bc0();
void FUN_141b706a0(unsigned int, unsigned int*, unsigned int*, unsigned int*);   // C3: was FUN_141b706a0
bool FUN_14028d470(float a, float b);
void FUN_1412751f0(const CStringW& str, int a, int b);
CStringW FUN_140298ea0(CStringW strKey);
CStringW BlockFormat(int nId);
int FUN_141276180(const CString& a, const CString& b);
CStringW FUN_14093b970(int nId);
extern unsigned int DAT_143af3960;                                      // pending refresh flags of the panel

// The localized-string formatter (see partyvotecli.cpp): the (CStringW, float) instance is this unit's COMDAT.
CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_MpFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong mp_make_type(const T& arg) { return MakeValue<Unk_MpFormatter>::type(arg); }
struct Unk_MpArgType {
    ULongLong type;
    Unk_MpArgType() : type(0) {}
    template <typename T> Unk_MpArgType(const T& arg) : type(mp_make_type(arg)) {}
};
inline ULongLong mp_make_type(Unk_MpArgType t0 = Unk_MpArgType(), Unk_MpArgType t1 = Unk_MpArgType(), Unk_MpArgType t2 = Unk_MpArgType(),
                              Unk_MpArgType t3 = Unk_MpArgType(), Unk_MpArgType t4 = Unk_MpArgType(), Unk_MpArgType t5 = Unk_MpArgType(),
                              Unk_MpArgType t6 = Unk_MpArgType(), Unk_MpArgType t7 = Unk_MpArgType(), Unk_MpArgType t8 = Unk_MpArgType(),
                              Unk_MpArgType t9 = Unk_MpArgType(), Unk_MpArgType t10 = Unk_MpArgType(), Unk_MpArgType t11 = Unk_MpArgType(),
                              Unk_MpArgType t12 = Unk_MpArgType(), Unk_MpArgType t13 = Unk_MpArgType(), Unk_MpArgType t14 = Unk_MpArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define MP_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_MpFormatter>(v##n)
#define MP_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, MP_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::mp_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
MP_WRAP(2)

void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
void FUN_1419f37f0(unsigned int nFlags);
Unk_MpRideeCtl* FUN_1419f3810();

// ---- template glue ----

// @0x1419f3990
MS2Ptr<ASEffectManager> FUN_1419f3990(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASEffectManager> sp(new ASEffectManager(v, nMovieId));
    return sp;
}

// @0x1419f3a40
MS2Ptr<ASEffectManager> Unk_MpScript::FUN_1419f3a40(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(v))->IsObject())
        return FUN_1419f3990(m_nMovieId, v);
    return MS2Ptr<ASEffectManager>(0);
}

// @0x1419f3b00
template <> MS2Ptr<ASEffectManager> UISwfEntity::GetChild<ASEffectManager>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASEffectManager>(0);
    return MP_AS(m_30)->FUN_1419f3a40(strName);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1419ee140
UIMainPlayerInfo::UIMainPlayerInfo()
    : m_playerInfo(0), m_effectManager(0), m_pending(17, 0.75f, 0.25f, 2.25f, 10), m_strSlotName("SlotInfo.skill"),
      m_nLastTick(0), m_bInfinity(0), m_bSkillMinimize(0), m_bCommonMinimize(0), m_nSlotMode(0), m_nHideMask(0),
      m_ridee(0), m_camera(0)
{
    ResetGauges();
    m_80 = 1;
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyDebugState", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::FUN_1419f14b0));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyShortkeyPage", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::OnShortkeyPageNotify));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::OnSkillSetModeNotify));
}

// @0x1419ee5d0
UIMainPlayerInfo::~UIMainPlayerInfo()
{
    m_effectManager = 0;
    m_playerInfo = 0;
    m_pending.RemoveAll();
    m_ridee = 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    ((Unk_ItemEventSystem*)(Unk_MpItemEvents*)(((class Unk_MpItemEvents*)FUN_140a6a840())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyDebugState", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::FUN_1419f14b0));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyShortkeyPage", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::OnShortkeyPageNotify));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifySkillSetMode", Delegate<void(NotifyObject*)>(this, &UIMainPlayerInfo::OnSkillSetModeNotify));
}

// @0x1419eea30
CString UIMainPlayerInfo::GetTypeName()
{
    return "MainPlayerInfo";
}

// @0x1419eea80
int UIMainPlayerInfo::vfunc_il1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x1419eead0
int UIMainPlayerInfo::vfunc_oa0_1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x1419eeb20
int UIMainPlayerInfo::vfunc_53(void* pCfg)
{
    XmlSetAttr((class TiXmlElement*)(pCfg), "skillMinimize", m_bSkillMinimize);
    XmlSetAttr((class TiXmlElement*)(pCfg), "commonMinimize", m_bCommonMinimize);
    return 1;
}

// @0x1419eeb80
int UIMainPlayerInfo::vfunc_54(void* pCfg)
{
    XmlGetAttr((class TiXmlElement*)(pCfg), "skillMinimize", m_bSkillMinimize);
    XmlGetAttr((class TiXmlElement*)(pCfg), "commonMinimize", m_bCommonMinimize);
    return 1;
}

// @0x1419eebe0
int UIMainPlayerInfo::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x1419eec10
void UIMainPlayerInfo::vfunc_67()
{
    UIBuiltInDialog::vfunc_67();
    FUN_1417634a0(GetSlotName());
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    ((Unk_ItemEventSystem*)(Unk_MpItemEvents*)(((class Unk_MpItemEvents*)FUN_140a6a840())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    m_effectManager = 0;
    m_playerInfo = 0;
    m_ridee = 0;
    m_pending.RemoveAll();
    m_nHideMask = 0;
}

// @0x1419eed40
void UIMainPlayerInfo::OnLoadInit()
{
    UIBuiltInDialog::OnLoadInit();
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    m_nEP[0] = pPc->FUN_141670a00(10);
    m_nHP[0] = pPc->FUN_141670a00(4);
    m_nSP[0] = pPc->FUN_141670a00(7);
    m_nEP[1] = pPc->FUN_141670a30(10);
    m_nHP[1] = pPc->FUN_141670a30(4);
    m_nSP[1] = pPc->FUN_141670a30(7);
    if ((m_effectManager = GetChild<ASEffectManager>("m_effectManager")).get())
    {
        int nMax = 0x15;
        int nColumns = 7;
        bool bUp = true;
        m_effectManager->SetE0(5);
        m_effectManager->SetMax(0x15);
        m_effectManager->SetColumns(7);
        m_effectManager->SetUp(true);
        FUN_1419f21b0();
        for (POSITION pos = m_pending.GetStartPosition(); pos != 0; m_pending.GetNext(pos))
            AddBuffEffect(m_pending.GetValueAt(pos));
        m_pending.RemoveAll();
    }
    FUN_1419f13b0(!((AdditionalCliList*)(Unk_MpStat*)(((Unk_MpStat*)((PCBase*)(Unk_MpPC*)(pPc))->FUN_1416749a0())))->IsInfinitySP() ? 1 : 0, 1);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    ((Unk_ItemEventSystem*)(Unk_MpItemEvents*)(((class Unk_MpItemEvents*)FUN_140a6a840())))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
}

// @0x1419ef110
void UIMainPlayerInfo::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    m_nSlotMode = 0;
    m_playerInfo = GetChild<ASUIComponent>("m_playerInfo");
    FUN_1419f1da0(reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bExpand);
    FUN_1419f2eb0();
    FUN_1419f19c0();
    vfunc_oa0_20(pPc->FUN_1416764d0());
    if (ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30))
    {
        dialog->Invoke("enabledExpansionSlotToggle", 1);
        dialog->FUN_1409ba0d0("expansionSlotActive", m_bSkillMinimize, m_bCommonMinimize);
    }
    int nPage = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_140a700b0() + 1;
    FUN_1419f24f0(nPage);
}

// @0x1419ef330
void UIMainPlayerInfo::vfunc_26()
{
    UIDialog::vfunc_26();
    m_effectManager = 0;
    UnloadRenderTarget();
}

// @0x1419ef370
void UIMainPlayerInfo::vfunc_43()
{
    if (ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30))
        dialog->vfunc_2(2, 0, (FUN_1418dd0c0() + FUN_1418dd110()) * -1);
}

// @0x1419ef400
int UIMainPlayerInfo::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0)
    {
        int nType = pMsg->PopInt();
        if (nType == 0)
        {
            CStringW strCmd = pMsg->FUN_1422b8f40();
            if (strCmd == "remove")
            {
                if (Unk_MpRideeCtl* pCtl = FUN_1419f3810())
                {
                    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xd4))
                    {
                        efd::SmartPointer<Unk_Service6100017> phys(FUN_1401cd040((struct Unk_EntityAppFramework*)(&DAT_143b059e8)));
                        if (phys.operator Unk_Service6100017*() != 0)
                        {
                            MS2Ptr<Cube> weapon(reinterpret_cast<CubeMapInformationService*>(phys.operator->())->GetCubeAtPoint(pCtl->GetPtCell()));
                            if (weapon.operator Cube*() != 0)
                            {
                                if (Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()))
                                    pPc->FUN_14152f140(reinterpret_cast<Unk_MpWeaponRow*>(weapon.operator->())->m_18);
                            }
                        }
                    }
                    pCtl->FUN_1410abb40();
                }
            }
            else if (strCmd == "create")
            {
                if (Unk_MpRideeCtl* pCtl = FUN_1419f3810())
                    pCtl->FUN_1410aad50();
            }
        }
        FUN_14151f200();
    }
    return 1;
}

// @0x1419ef5f0
int UIMainPlayerInfo::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData args;
    if (_stricmp("OnToggleSkillExpansionSlot", szMethod) == 0)
    {
        if (args.SetArgsIfAny(pArgs, nArgs) != 0)
            m_bSkillMinimize = args.PopBool();
        return 1;
    }
    else if (_stricmp("OnToggleCommonExpansionSlot", szMethod) == 0)
    {
        if (args.SetArgsIfAny(pArgs, nArgs) != 0)
            m_bCommonMinimize = args.PopBool();
        return 1;
    }
    else if (_stricmp("onRideOff", szMethod) == 0)
    {
        OnRideOff();
        return 1;
    }
    else if (_stricmp("onPrevPage", szMethod) == 0)
    {
        OnPrevPage();
        return 1;
    }
    else if (_stricmp("onNextPage", szMethod) == 0)
    {
        OnNextPage();
        return 1;
    }
    return 0;
}

// @0x1419ef820
void UIMainPlayerInfo::vfunc_15()
{
    if (FUN_1422dc2d0() == 0)
        return;
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    m_effectManager->Update();
    int nEnd = ((PC*)(Unk_MpPC*)(pPc))->FUN_141661a80();
    if (nEnd != 0)
    {
        int nNow = FUN_141472bc0();
        if ((unsigned)(nNow - m_nLastTick) > 1000)
        {
            m_nLastTick = nNow;
            int nHour = 0;
            int nMin = 0;
            int nSec = 0;
            FUN_141b706a0(nEnd - nNow, (unsigned int*)(&nHour), (unsigned int*)(&nMin), (unsigned int*)(&nSec));
        }
    }
    if (reinterpret_cast<Unk_IntervalTimer&>(s_refreshTimer).Check(200) != 0)
        FUN_1419f3590();
}

// @0x1419ef930
int UIMainPlayerInfo::vfunc_13()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    if (pPc->FUN_141659690() != 0)
        return 0;
    if (pPc->IsCubeMode1() != 0)
        return 0;
    if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x493e1, 0, 0) && reinterpret_cast<Unk_MpWorld*>(WorldService::GetInstance())->FUN_141bdb660(0) != 0)
    {
        FUN_1412751f0(BlockFormat(0x60), 1, 1);
        FUN_141276180(s_strNotThisPlace, "");
    }
    if (FUN_1419f2b60())
        return 1;
    return 0;
}

// @0x1419efa60
void UIMainPlayerInfo::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2.get() == 0 || p3 == 0)
        return;
    m_camera = 0;
    if (m_ridee.get() != 0)
    {
        m_ridee->vfunc_28(p1, p2, p3, p4);
        m_camera = reinterpret_cast<UIAvatarBase*>(m_ridee.operator->())->GetView();
        Unk_AdvMountPtr spMount = m_ridee->FUN_1418be810();
        Unk_MpCamData data;
        data.m_target = MP_ROW(spMount)->m_250;
        data.m_eye = MP_ROW(spMount)->m_25c;
        reinterpret_cast<Unk_MpCamera*>(m_camera.operator->())->vfunc_13(data);
    }
}

// @0x1419efcb0
void UIMainPlayerInfo::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadRenderTarget();
}

// @0x1419efce0
bool UIMainPlayerInfo::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    if (m_nSlotMode != 1)
        return true;
    LoadRenderTarget();
    return true;
}

// @0x1419efd30
void UIMainPlayerInfo::vfunc_oa0_7(int nJob, CStringW s)
{
    if (m_playerInfo.get() != 0)
        reinterpret_cast<Unk_RsScript*>(m_playerInfo.operator->())->FUN_14129cce0("setJob", nJob, s);
}

// @0x1419efe00
void UIMainPlayerInfo::vfunc_oa0_8(CStringW s)
{
    UpdateName();
}

// @0x1419efe50
void UIMainPlayerInfo::vfunc_oa0_9(unsigned short nLevel)
{
    if (m_playerInfo.get() != 0)
        MP_AS(m_playerInfo)->FUN_140ea5e70("setLevel", nLevel);
    FUN_1419f37f0(1);
}

// @0x1419efec0
void UIMainPlayerInfo::vfunc_oa0_3(int nCur, int nMax)
{
    if (m_nHP[0] == nCur && m_nHP[1] == nMax)
        return;
    if (m_playerInfo.get() != 0)
    {
        m_playerInfo->Invoke("setHP", nCur, nMax);
        m_nHP[0] = nCur;
        m_nHP[1] = nMax;
    }
    if (Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()))
    {
        if (!FUN_14028d470(((AdditionalCliList*)(Unk_MpStat*)(((Unk_MpStat*)((PCBase*)(Unk_MpPC*)(pPc))->FUN_1416749a0())))->FUN_140970fb0(), 0.0f))
            FUN_1419f37f0(1);
    }
}

// @0x1419effe0
void UIMainPlayerInfo::vfunc_oa0_4(int nCur, int nMax)
{
    if (m_nSP[0] == nCur && m_nSP[1] == nMax)
        return;
    if (m_playerInfo.get() != 0)
    {
        m_playerInfo->Invoke("setSP", nCur, nMax);
        m_nSP[0] = nCur;
        m_nSP[1] = nMax;
    }
    FUN_1419f37f0(1);
}

// @0x1419f00d0
void UIMainPlayerInfo::vfunc_oa0_5(int nCur, int nMax)
{
    if (m_nEP[0] == nCur && m_nEP[1] == nMax)
        return;
    if (m_playerInfo.get() != 0)
    {
        MP_AS(m_playerInfo)->FUN_141931d80("setEP", m_nEP[0], nCur, nMax);
        m_nEP[0] = nCur;
        m_nEP[1] = nMax;
    }
    FUN_1419f37f0(1);
}

// @0x1419f01f0
void UIMainPlayerInfo::vfunc_oa0_24(int n)
{
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        pBar->FUN_141763b00(n);
}

// @0x1419f0280
void UIMainPlayerInfo::vfunc_oa0_25(void* p)
{
    if (Unk_MpSlotBox* pBox = (Unk_MpSlotBox*)FUN_140c544d0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        pBox->vfunc_11(p);
}

// @0x1419f0320
void UIMainPlayerInfo::vfunc_oa0_26(void* p)
{
    if (Unk_MpSlotBox* pBox = (Unk_MpSlotBox*)FUN_140c544d0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        pBox->vfunc_12(p);
}

// @0x1419f03c0
void UIMainPlayerInfo::vfunc_oa0_27(int a1, int a2)
{
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        pBar->FUN_141763bd0(a1, a2);
}

// @0x1419f0460
void UIMainPlayerInfo::vfunc_oa0_20(int bRiding)
{
    if (m_playerInfo == 0)
        return;
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    if (FUN_1419f16b0() == 0)
        return;
    UnloadRenderTarget();
    m_ridee = 0;
    int nMode = 0;
    ASObj obj(2);
    obj.FUN_1407cb9c0("riding", bRiding);
    obj.FUN_1409c1180("curHP", pPc->FUN_141670a00(4));
    obj.FUN_1409c1180("maxHP", pPc->FUN_141670a30(4));
    obj.FUN_1409c1180("curSP", pPc->FUN_141670a00(7));
    obj.FUN_1409c1180("maxSP", pPc->FUN_141670a30(7));
    do
    {
        if (bRiding == 0)
            break;
        efd::SmartPointer<Ridee> holder(((Ridee*)((PCBase*)(Unk_MpPC*)(pPc))->FUN_1416764a0()));
        if (holder == 0)
            break;
        bool bNoAvatar = MP_ROW(holder->FUN_141707750())->m_68 == 0;
        if (bNoAvatar)
            break;
        nMode = 1;
        obj.FUN_1407cb9c0("rideOff", MP_ROW(holder->FUN_141707750())->m_64);
        obj.FUN_1407cbb20("rideeName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x31, MP_ROW(holder->FUN_141707750())->m_30));
        m_ridee.AssignRaw(new UIAvatarRidee(holder->FUN_141707750()));
        m_ridee->vfunc_1(0);
    } while (0);
    if (m_nSlotMode == nMode)
        return;
    m_nSlotMode = nMode;
    SyncSlotMode();
    m_playerInfo->Invoke("onRiding", obj);
    if (m_nSlotMode == 1)
        LoadRenderTarget();
}

// @0x1419f0960
void UIMainPlayerInfo::vfunc_21(void* pItem)
{
    FUN_1419f2d90(MP_ITEM(pItem));
    FUN_1419f37f0(1);
}

// @0x1419f09a0
void UIMainPlayerInfo::vfunc_22(void* pItem)
{
    FUN_1419f2e60(MP_ITEM(pItem));
    FUN_1419f37f0(1);
}

// @0x1419f09e0
void UIMainPlayerInfo::vfunc_2(void* pItem)
{
    if (((class CItemData*)(class CItemData*)(MP_ITEM(pItem)->FUN_140527840()))->FUN_14053e460())
        FUN_1419f2e10(MP_ITEM(pItem));
    ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_14142f1c0(((class CItemData*)(class CItemData*)(MP_ITEM(pItem)->FUN_140527840()))->FUN_14053dc20(), MP_ITEM(pItem)->FUN_1405276c0(), MP_ITEM(pItem)->GetItemUid());
}

// @0x1419f0a80
void UIMainPlayerInfo::vfunc_3(void* pItem, bool b)
{
    if (((class CItemData*)(class CItemData*)(MP_ITEM(pItem)->FUN_140527840()))->FUN_14053e460())
    {
        int nKey = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_14142ca40(((class CItemData*)(class CItemData*)(MP_ITEM(pItem)->FUN_140527840()))->FUN_14053dc20(), 0);
        ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->SendKeyTableMode1(nKey);
        FUN_1419f2e10(MP_ITEM(pItem));
    }
}

// @0x1419f0b10
void UIMainPlayerInfo::vfunc_4(void* pItem, int n)
{
    if (pItem == 0)
        return;
    if (((class CItemData*)(class CItemData*)(MP_ITEM(pItem)->FUN_140527840()))->FUN_14053e460())
        FUN_1419f2e10(MP_ITEM(pItem));
}

// @0x1419f0b70
void UIMainPlayerInfo::vfunc_33(int nClassId, int)
{
    if (nClassId == 0x6200004)
        FUN_1419f37f0(1);
}

// @0x1419f0bb0
void UIMainPlayerInfo::FUN_1419f0bb0(Unk_MpAchieve* pAchieve)
{
    if (((class CGuideManager*)FUN_1409331e0())->IsRestricted(0x16) != 0)
        return;
    if (((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetState() != 2)
        return;
    float fPercent = (float)((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetProgress() / (float)((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetGoal() * 100.0f;
    if (fPercent >= 99.0f)
    {
        CStringW strMessage = FUN_14028dfa0(CStringW(L"s_achieve_progress_notify_float"), FUN_14093b970(((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetId()), fPercent);
        AppendMessage(strMessage, "achieve");
    }
    else
    {
        int nStep = (float)(int)fPercent - pAchieve->m_18;
        float fStep = nStep;
        bool bNotify = fStep >= (float)((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetDataRef()->m_nNoticePercent && fPercent >= 1.0f;
        if (bNotify)
        {
            pAchieve->m_18 = fPercent;
            int nPercent = (int)fPercent;
            CStringW strMessage = FUN_14028dfa0<CStringW, int>(CStringW(L"s_achieve_progress_notify_integer"), FUN_14093b970(((CAchieve*)(Unk_MpAchieve*)(pAchieve))->GetId()), nPercent);
            AppendMessage(strMessage, "achieve");
        }
    }
}

// @0x1419f0ef0
void UIMainPlayerInfo::AppendMessage(const CStringW& strMessage, const CString& strType)
{
    if (m_30.get() != 0)
        ((AScript*)(Unk_MpScript*)(MP_AS(m_30)))->Invoke("appendMessage", strMessage, strType);
}

// @0x1419f0fe0
void UIMainPlayerInfo::AddBuffEffect(MS2Ptr<Unk_AsBuff> spBuff)
{
    if (m_effectManager.get() != 0)
        m_effectManager->AddEffect(spBuff);
    else
        m_pending.SetAt(((AdditionalCli*)(Unk_AsBuff*)spBuff.operator->())->GetKey(), spBuff);
    FUN_1419f37f0(5);
}

// @0x1419f10b0
void UIMainPlayerInfo::UpdateBuffEffect(MS2Ptr<Unk_AsBuff> spBuff)
{
    if (m_effectManager.get() != 0)
        m_effectManager->UpdateEffect(spBuff);
    else
        m_pending.SetAt(((AdditionalCli*)(Unk_AsBuff*)spBuff.operator->())->GetKey(), spBuff);
    FUN_1419f37f0(5);
}

// @0x1419f1180
void UIMainPlayerInfo::RemoveBuffEffect(int nBuffId)
{
    if (m_effectManager.get() != 0)
        m_effectManager->RemoveEffect(nBuffId);
    else
        m_pending.RemoveKey(nBuffId);
    FUN_1419f37f0(5);
}

// @0x1419f1200
void UIMainPlayerInfo::FUN_1419f1200(int nId, int nLevel)
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    FUN_1419f1370(nId);
    MS2Ptr<Unk_AsBuff> spBuff(new AdditionalCustomCli((PCBase*)pPc, FUN_1419f3400(nId), nId, nLevel, 1));
    if ((bool)spBuff.get() && ((class AdditionalCli*)(class Unk_AsBuff*)(spBuff.operator->()))->IsValid())
        AddBuffEffect(spBuff);
    FUN_1419f37f0(5);
}

// @0x1419f1370
void UIMainPlayerInfo::FUN_1419f1370(int nId)
{
    RemoveBuffEffect(FUN_1419f3400(nId));
    FUN_1419f37f0(5);
}

// @0x1419f13b0
void UIMainPlayerInfo::FUN_1419f13b0(int bInfinity, int bForce)
{
    if (m_bInfinity == bInfinity && bForce == 0)
        return;
    if (m_ridee.get() != 0)
        return;
    if (m_playerInfo == 0)
        return;
    {
        m_bInfinity = bInfinity;
        if (m_bInfinity != 0)
            m_playerInfo->Invoke("onHideInfinity");
        else
            m_playerInfo->Invoke("onShowInfinity");
    }
}

// @0x1419f14b0
void UIMainPlayerInfo::FUN_1419f14b0(NotifyObject* pNotify)
{
    UpdateName();
}

// @0x1419f14e0
void UIMainPlayerInfo::OnShortkeyPageNotify(NotifyObject* pNotify)
{
    NotifyShortkeyPage* pPage = dynamic_cast<NotifyShortkeyPage*>(pNotify);
    if (pPage == 0)
        return;
    FUN_1419f24f0(pPage->m_nCur + 1);
    bool bChanged = pPage->m_nPrev != pPage->m_nCur ? true : false;
    FUN_1419f2560(bChanged);
}

// @0x1419f1580
void UIMainPlayerInfo::OnSkillSetModeNotify(NotifyObject* pNotify)
{
    NotifySkillSetMode* pMode = dynamic_cast<NotifySkillSetMode*>(pNotify);
    if (pMode == 0)
        return;
    FUN_1419f26b0(pMode->m_bMode == 0);
}

// @0x1419f1600
void UIMainPlayerInfo::UpdateName()
{
    if (m_playerInfo == 0)
        return;
    m_playerInfo->Invoke("setName", GetPlayerNameWithTitles());
}

// @0x1419f16b0
int UIMainPlayerInfo::FUN_1419f16b0()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    int bVisible = 1;
    efd::SmartPointer<Ridee> holder(((Ridee*)((PCBase*)(Unk_MpPC*)(pPc))->FUN_1416764a0()));
    int nType = 0;
    if (holder != 0)
    {
        nType = MP_ROW(holder->FUN_141707750())->m_6c;
        if (nType != 0)
            bVisible = 0;
    }
    bool bShow = true;
    if (nType == 2)
        bShow = false;
    if (m_playerInfo.get() != 0)
        m_playerInfo->Invoke("visibleTag", bVisible);
    SetHideReason(4, bShow);
    return bShow;
}

// @0x1419f1820
void UIMainPlayerInfo::PlayHit()
{
    if (m_playerInfo.get() != 0)
        m_playerInfo->Invoke("hit");
}

// @0x1419f1880
void UIMainPlayerInfo::SetBattle(int bBattle)
{
    if (m_playerInfo.get() != 0)
        m_playerInfo->Invoke("setBattle", bBattle);
}

// @0x1419f18f0
void UIMainPlayerInfo::SyncSlotMode()
{
    if (MS2Ptr<ASUIComponent> spSlot = GetChild<ASUIComponent>("m_slot"))
        spSlot->Invoke("onSlotModeChange", m_nSlotMode);
    FUN_1419f37f0(1);
}

// @0x1419f19c0
void UIMainPlayerInfo::FUN_1419f19c0()
{
    FUN_1417634a0(GetSlotName());
    FUN_1417633f0(GetSlotName(), 0x19);
    if (MS2Ptr<ASUIComponent> spSlot = GetChild<ASUIComponent>("m_slot"))
        spSlot->Invoke("updateBindSlot", reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bExpand);
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    MS2Ptr<CSkillSet> spSet = ((MyPC*)(Unk_MpPC*)(pPc))->FUN_141523bc0()->GetSkillSet();
    if (spSet.get() != 0)
    {
        ((CKeyTable*)FUN_1409331f0())->ApplySkillSetToQuickSlots(spSet);
        if (spSet->m_nSlotLock == 0)
        {
            CString strName = Unk_SocketFormat("SkillSet{0}_{1}", reinterpret_cast<const int&>(spSet->m_nId), spSet->m_nVersion);
            ((CKeyTable*)FUN_1409331f0())->LoadKeySetting(strName);
        }
    }
}

// @0x1419f1c80
void UIMainPlayerInfo::FUN_1419f1c80()
{
    unsigned nCount = 0x19;
    for (unsigned i = 0; i < nCount; i++)
    {
        int nKey = i + 500001;
        if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(nKey, 0, 0))
        {
            if (Unk_MpSlot* pSlot = FUN_1419f2930(i))
                ((SkillSlot*)(Unk_MpSlot*)(pSlot))->FUN_14175f200();
        }
    }
}

// @0x1419f1d10
void UIMainPlayerInfo::SetHideReason(unsigned int nMask, bool bShow)
{
    if (!bShow)
        m_nHideMask |= nMask;
    else
        m_nHideMask &= ~nMask;
    if (m_nHideMask == 0)
        UIDialog::vfunc_8(1);
    else
        UIDialog::vfunc_8(0);
}

// @0x1419f1da0
void UIMainPlayerInfo::FUN_1419f1da0(int nSlot)
{
    if (m_30 == 0)
        return;
    int bShowKey = FUN_140a58540()->FUN_140d8ee40() == 2 ? 0 : 1;
    MP_AS(m_30)->FUN_1409ba0d0("changeSkillSlot", nSlot, bShowKey);
    FUN_1419f1e60();
    FUN_1419f21b0();
    SyncSlotMode();
}

// @0x1419f1e60
void UIMainPlayerInfo::FUN_1419f1e60()
{
    if (m_30 == 0)
        return;
    if (reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bExpand)
    {
        int nKey1 = ((CKeyTable*)FUN_1409331f0())->FUN_14142c940(800001, 2);
        int nKey2 = ((CKeyTable*)FUN_1409331f0())->FUN_14142c940(800002, 2);
        int nKey3 = ((CKeyTable*)FUN_1409331f0())->FUN_14142c940(800003, 2);
        CStringW strKey1 = ((CKeyTable*)FUN_1409331f0())->FUN_141431820(nKey1).MakeUpper();
        CStringW strKey2 = ((CKeyTable*)FUN_1409331f0())->FUN_141431820(nKey2).MakeUpper();
        CStringW strKey3 = ((CKeyTable*)FUN_1409331f0())->FUN_141431820(nKey3).MakeUpper();
        ASObj obj(2);
        obj.FUN_1407cbb20("modifiedKey1", strKey1);
        obj.FUN_1407cbb20("modifiedKey2", strKey2);
        obj.FUN_1407cbb20("modifiedKey3", strKey3);
        m_30->Invoke("setModifiedKey", obj.FUN_1422bb870());
    }
}

// @0x1419f21b0
void UIMainPlayerInfo::FUN_1419f21b0()
{
    if (m_effectManager == 0)
        return;
    int x = -395;
    int y = -12;
    if (reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bExpand)
    {
        x = -478;
        y = -60;
    }
    m_effectManager->SetPosA(x, y);
    x = 0x48;
    y = -12;
    if (reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bExpand)
    {
        x = 0x5d;
        y = -60;
    }
    m_effectManager->SetPosB(x, y);
}

// @0x1419f22a0
void UIMainPlayerInfo::FUN_1419f22a0(int nKey, int bPress)
{
    if (m_30.IsNull())
        return;
    __int64 nSlotKey = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->GetKeyAction(nKey);
    int nIndex = nSlotKey - 800001;
    int nFirst = nIndex * 8;
    ASObj obj(2);
    obj.FUN_1407cb9c0("index", nIndex);
    obj.FUN_1407cb9c0("bPress", bPress);
    obj.FUN_1407cbbe0("showSkillName", reinterpret_cast<Unk_MpCfg*>(TSingleton<CGameOption>::GetInstance())->FUN_140a58500()->m_bShowSkillName);
    ASArray names(2);
    for (int i = nFirst; i < nFirst + 8; i++)
    {
        Unk_MpSlot* pSlot = FUN_1419f2930(i);
        if (pSlot != 0)
            names.PushWString(((SkillSlot*)(Unk_MpSlot*)(pSlot))->FUN_14175fe60());
        else
            names.PushString("");
    }
    obj.FUN_1409eb1d0("slotNames", names);
    m_30->Invoke("showModifiedKeySelect", obj.FUN_1422bb870());
}

// @0x1419f24f0
void UIMainPlayerInfo::FUN_1419f24f0(int nPage)
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("setShortkeyPageNumber", nPage);
}

// @0x1419f2560
void UIMainPlayerInfo::FUN_1419f2560(bool bForce)
{
    static int s_order[25] = {4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    int* pOrder = s_order;
    for (int i = 0; i < 0x19u; i++)
    {
        int nSlot = pOrder[i];
        Unk_MpSlot* pSlot = FUN_1419f2930(nSlot);
        if (pSlot == 0)
            continue;
        Unk_SsQuickEntry data;
        if (!((CKeyTable*)FUN_1409331f0())->GetQuickSlotEntry(nSlot, data))
        {
            pSlot->vfunc_11();
            pSlot->vfunc_10();
            continue;
        }
        if (!bForce && ((SkillSlot*)(Unk_MpSlot*)(pSlot))->GetSkillId() == data.m_nSkillId && ((SkillSlot*)(Unk_MpSlot*)(pSlot))->GetItemUid() == data.m_nItemUid && ((SkillSlot*)(Unk_MpSlot*)(pSlot))->GetItemId() == data.m_nItemId)
            continue;
        pSlot->vfunc_11();
        ((SkillSlot*)(Unk_MpSlot*)(pSlot))->SetSkillId(data.m_nSkillId);
        ((SkillSlot*)(Unk_MpSlot*)(pSlot))->SetItemUid(data.m_nItemUid);
        ((SkillSlot*)(Unk_MpSlot*)(pSlot))->SetItemId(data.m_nItemId);
        pSlot->vfunc_10();
    }
}

// @0x1419f26b0
void UIMainPlayerInfo::FUN_1419f26b0(bool bEnable)
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("enablePageButton", bEnable);
}

// @0x1419f2720
void UIMainPlayerInfo::SetHideAndSeekSlotMode(bool bHideAndSeek)
{
    if (m_playerInfo == 0)
        return;
    int nMode = 0;
    if (bHideAndSeek)
        nMode = 1;
    if (m_nSlotMode == nMode)
        return;
    m_nSlotMode = nMode;
    SyncSlotMode();
    m_playerInfo->Invoke("onHideAndSeek", bHideAndSeek);
}

// @0x1419f27e0
Unk_MpSlot* UIMainPlayerInfo::FindSlotForItem(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    __int64 nUid = 0;
    if (pItem->HasCubeTextureMesh() != 0 || pItem->FUN_140526010() != 0)
        nUid = pItem->GetItemUid();
    Unk_MpSlot* pSlot = 0;
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        pSlot = ((Unk_MpSlot*)((SkillSlotBag*)(Unk_MpSlotBar*)(pBar))->FindSlotByItemId(pItem->FUN_1405276c0()));
    if (pSlot == 0)
    {
        int nSlot = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FindQuickSlotBySkillAndItemUid(((class CItemData*)(class CItemData*)(pItem->FUN_140527840()))->FUN_14053dc20(), nUid);
        pSlot = FUN_1419f2930(nSlot);
    }
    return pSlot;
}

// @0x1419f2930
Unk_MpSlot* UIMainPlayerInfo::FUN_1419f2930(int nIndex)
{
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        return ((class Unk_MpSlot*)FUN_141761e60((class DragSlot*)(((Unk_MpWnd*)((DragSlotBag*)(Unk_MpSlotBar*)(pBar))->FUN_1422cd070(nIndex)))));
    return 0;
}

// @0x1419f29c0
int UIMainPlayerInfo::FUN_1419f29c0()
{
    static int s_order[25] = {4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
    {
        for (unsigned i = 0; i < 0x19; i++)
        {
            Unk_MpSlot* pSlot = ((class Unk_MpSlot*)FUN_141761e60((class DragSlot*)(((Unk_MpWnd*)((DragSlotBag*)(Unk_MpSlotBar*)(pBar))->FUN_1422cd070(s_order[i])))));
            if (pSlot != 0 && ((SkillSlot*)(Unk_MpSlot*)(pSlot))->GetSkillId() == 0)
                return 0;
        }
    }
    return 1;
}

// @0x1419f2a90
void UIMainPlayerInfo::FUN_1419f2a90()
{
    static int s_order[25] = {4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
    {
        for (unsigned i = 0; i < 0x19; i++)
        {
            Unk_MpSlot* pSlot = ((class Unk_MpSlot*)FUN_141761e60((class DragSlot*)(((Unk_MpWnd*)((DragSlotBag*)(Unk_MpSlotBar*)(pBar))->FUN_1422cd070(s_order[i])))));
            if (pSlot == 0)
                continue;
            pSlot->vfunc_11();
        }
    }
}

// @0x1419f2b60
int UIMainPlayerInfo::FUN_1419f2b60()
{
    if (FUN_140930d70())
    {
        bool bKey = ((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x49411, 0, 0) || ((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x4940e, 0, 0) ||
                    ((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x4940f, 0, 0) || ((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x49410, 0, 0) ? true : false;
        if (bKey)
        {
            FUN_1412751f0(FUN_140298ea0(CStringW(L"s_err_cannot_change_shortkey_page")), 1, 1);
            return 1;
        }
        return 0;
    }
    if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x4940e, 0, 0))
    {
        ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_141431ae0(0, true);
        return 1;
    }
    else if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x4940f, 0, 0))
    {
        ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_141431ae0(1, true);
        return 1;
    }
    else if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x49410, 0, 0))
    {
        ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_141431ae0(2, true);
        return 1;
    }
    else if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x49411, 0, 0))
    {
        OnNextPage();
        return 1;
    }
    return 0;
}

// @0x1419f2d90
void UIMainPlayerInfo::FUN_1419f2d90(CItem* pItem)
{
    if (pItem == 0)
        return;
    Unk_MpSlot* pSlot = FindSlotForItem(pItem);
    if (pSlot != 0)
    {
        ((SkillSlot*)(Unk_MpSlot*)(pSlot))->SetSkillId(((class CItemData*)(class CItemData*)(pItem->FUN_140527840()))->FUN_14053dc20());
        pSlot->vfunc_10();
    }
    else
    {
        FUN_1419f19c0();
    }
}

// @0x1419f2e10
void UIMainPlayerInfo::FUN_1419f2e10(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (Unk_MpSlot* pSlot = FindSlotForItem(pItem))
        pSlot->vfunc_10();
}

// @0x1419f2e60
void UIMainPlayerInfo::FUN_1419f2e60(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (Unk_MpSlot* pSlot = FindSlotForItem(pItem))
        pSlot->vfunc_11();
}

// @0x1419f2eb0
void UIMainPlayerInfo::FUN_1419f2eb0()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    if (((JobSystem*)((PC*)(Unk_MpPC*)(pPc))->FUN_1416546d0())->GetJobData() == 0)
        return;
    if (m_playerInfo.get() != 0)
    {
        reinterpret_cast<Unk_MpInfoClip*>(m_playerInfo.operator->())->vfunc_24(true);
        ASObj obj(2);
        obj.FUN_1407cb9c0("riding", pPc->FUN_1416764d0());
        obj.FUN_1409c48f0("level", pPc->vfunc_78());
        obj.FUN_140bd0d90("jobCode", pPc->FUN_141654730());
        obj.FUN_1407cbb20("jobName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, pPc->FUN_141654730()));
        obj.FUN_1407cbb20("name", GetPlayerNameWithTitles());
        obj.FUN_1409c1180("curHP", pPc->FUN_141670a00(4));
        obj.FUN_1409c1180("curSP", pPc->FUN_141670a00(7));
        obj.FUN_1409c1180("curEP", pPc->FUN_141670a00(10));
        obj.FUN_1409c1180("maxEP", pPc->FUN_141670a30(10));
        obj.FUN_1407cb9c0("battle", pPc->vfunc_65());
        obj.FUN_1409c1180("maxHP", pPc->FUN_141670a30(4));
        obj.FUN_1409c1180("maxSP", pPc->FUN_141670a30(7));
        m_playerInfo->Invoke("init", obj);
    }
    UpdateName();
}

// @0x1419f31f0
CString UIMainPlayerInfo::GetSlotName()
{
    CString str;
    str.Format("%s.%d", (const char*)m_strSlotName, 0);
    return str;
}

// @0x1419f3280
void UIMainPlayerInfo::LoadRenderTarget()
{
    if (m_playerInfo == 0)
        return;
    m_playerInfo->Invoke("loadRenderTarget");
}

// @0x1419f32f0
void UIMainPlayerInfo::UnloadRenderTarget()
{
    m_camera = 0;
    if (m_playerInfo == 0)
        return;
    m_playerInfo->Invoke("unloadRenderTarget");
}

// @0x1419f3370
void UIMainPlayerInfo::OnRideOff()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    ((MyPC*)(Unk_MpPC*)(pPc))->SendRequestRideMode1((RideOffAction*)(RideOffActionRidingUI*)(new RideOffActionRidingUI(0)));
}

// @0x1419f3400
int UIMainPlayerInfo::FUN_1419f3400(int nId)
{
    return nId + 1000000000;
}

// @0x1419f3420
CStringW UIMainPlayerInfo::GetPlayerNameWithTitles()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return L"";
    CStringW strName = pPc->vfunc_77();
    for (int i = 0; i < 7; i++)
    {
        if (FUN_140931510()->FUN_140d9f5d0(i))
            strName += StringFormat<CStringW>(L" {0}", FUN_140931510()->FUN_140d9f600(i));
    }
    return strName;
}

// @0x1419f3590
void UIMainPlayerInfo::FUN_1419f3590()
{
    if (DAT_143af3960 == 0)
        return;
    if (Unk_MpSlotBar* pBar = (Unk_MpSlotBar*)FUN_141763cb0(Unk_NotifyContext::FUN_1422c8e90(GetSlotName())))
        ((SkillSlotBag*)(Unk_MpSlotBar*)(pBar))->FUN_141763640(DAT_143af3960);
    DAT_143af3960 = 0;
}

// @0x1419f3630
bool UIMainPlayerInfo::OnPrevPage()
{
    if (FUN_140930d70())
        return false;
    int nPages = ((class Unk_MpKeyTable*)FUN_1409331f0())->FUN_1419f4760();
    if (nPages <= 0)
        return false;
    int nCur = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_140a700b0();
    int nPage = nCur - 1;
    if (nPage < 0)
        nPage = nPages + nPage;
    ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_141431ae0(nPage, true);
    return true;
}

// @0x1419f36c0
bool UIMainPlayerInfo::OnNextPage()
{
    if (FUN_140930d70())
        return false;
    int nPages = ((class Unk_MpKeyTable*)FUN_1409331f0())->FUN_1419f4760();
    if (nPages <= 0)
        return false;
    int nCur = ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_140a700b0();
    int nNext = (nCur + 1) % nPages;
    ((CKeyTable*)(Unk_MpKeyTable*)(((class Unk_MpKeyTable*)FUN_1409331f0())))->FUN_141431ae0(nNext, true);
    return true;
}

// @0x1419f3740
void UIMainPlayerInfo::ResetGauges()
{
    m_nHP[1] = 0;
    m_nHP[0] = 0;
    m_nSP[1] = 0;
    m_nSP[0] = 0;
    m_nEP[1] = 0;
    m_nEP[0] = 0;
}

// @0x1419f37f0
void FUN_1419f37f0(unsigned int nFlags)
{
    DAT_143af3960 |= nFlags;
}

// @0x1419f3810
Unk_MpRideeCtl* FUN_1419f3810()
{
    Unk_MpPC* pPc = ((Unk_MpPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    return ((Unk_MpRideeCtl*)((MyPC*)(Unk_MpPC*)(pPc))->GetActiveCubeCraft());
}

// @0x1419f41d0
Unk_MpRideePtr& Unk_MpRideePtr::operator=(int nNull)
{
    Release();
    return *this;
}

// @0x1419f4200
Unk_MpRideePtr& Unk_MpRideePtr::AssignRaw(UIAvatarRidee* p)
{
    Unk_MpRideePtr tmp(p);
    UIAvatarRidee* pOld = m_p;
    m_p = tmp.m_p;
    tmp.m_p = pOld;
    return *this;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419EEA30, UIMainPlayerInfo, GetTypeName, 61, 0x5EF64259);
MS2_REPLACE_METHOD_VIA(0x1419EEA80, UIMainPlayerInfo, UIItemEventListener, vfunc_il1, 69, 0x830FFD61);
MS2_REPLACE_METHOD_VIA(0x1419EEAD0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_1, 69, 0x93DD6E81);
MS2_REPLACE_METHOD(0x1419EEB20, UIMainPlayerInfo, vfunc_53, 82, 0x25F910F7);
MS2_REPLACE_METHOD(0x1419EEB80, UIMainPlayerInfo, vfunc_54, 86, 0xD78E7073);
MS2_REPLACE_METHOD(0x1419EEBE0, UIMainPlayerInfo, vfunc_65, 37, 0x9F0544ED);
MS2_REPLACE_METHOD(0x1419EEC10, UIMainPlayerInfo, vfunc_67, 288, 0x7E1D8C00);
MS2_REPLACE_METHOD(0x1419EED40, UIMainPlayerInfo, OnLoadInit, 966, 0xAD035A76);
MS2_REPLACE_METHOD(0x1419EF110, UIMainPlayerInfo, OnLoadComplete, 529, 0xBB565A9A);
MS2_REPLACE_METHOD(0x1419EF330, UIMainPlayerInfo, vfunc_26, 55, 0x3423E3F5);
MS2_REPLACE_METHOD(0x1419EF370, UIMainPlayerInfo, vfunc_43, 138, 0x9DCE8942);
MS2_REPLACE_METHOD_VIA(0x1419EF400, UIMainPlayerInfo, IMessageListener, OnMessage, 478, 0x41BEAABF);
MS2_REPLACE_METHOD(0x1419EF5F0, UIMainPlayerInfo, vfunc_28, 533, 0xFBB69F6C);
MS2_REPLACE_METHOD(0x1419EFA60, UIMainPlayerInfo, vfunc_25, 578, 0xF459F540);
MS2_REPLACE_METHOD(0x1419EFCB0, UIMainPlayerInfo, vfunc_16, 34, 0xFCD56621);
MS2_REPLACE_METHOD(0x1419EFCE0, UIMainPlayerInfo, vfunc_17, 65, 0xA83D4020);
MS2_REPLACE_METHOD_VIA(0x1419EFD30, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_7, 191, 0xBD19E377);
MS2_REPLACE_METHOD_VIA(0x1419EFE00, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_8, 59, 0x7C590124);
MS2_REPLACE_METHOD_VIA(0x1419EFE50, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_9, 104, 0x842772B7);
MS2_REPLACE_METHOD_VIA(0x1419EFEC0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_3, 280, 0x434C6D3A);
MS2_REPLACE_METHOD_VIA(0x1419EFFE0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_4, 224, 0x2594EA56);
MS2_REPLACE_METHOD_VIA(0x1419F00D0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_5, 269, 0xFA26EB8F);
MS2_REPLACE_METHOD_VIA(0x1419F01F0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_24, 132, 0xB93EF935);
MS2_REPLACE_METHOD_VIA(0x1419F0280, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_25, 140, 0x7B3234B9);
MS2_REPLACE_METHOD_VIA(0x1419F0320, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_26, 140, 0xA7569D65);
MS2_REPLACE_METHOD_VIA(0x1419F03C0, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_27, 142, 0xFF557233);
MS2_REPLACE_METHOD_VIA(0x1419F0460, UIMainPlayerInfo, UIStatusEventListener, vfunc_oa0_20, 1263, 0x7E0C27D0);
MS2_REPLACE_METHOD_VIA(0x1419F0960, UIMainPlayerInfo, UIItemEventListener, vfunc_21, 53, 0x6A058ADF);
MS2_REPLACE_METHOD_VIA(0x1419F09A0, UIMainPlayerInfo, UIItemEventListener, vfunc_22, 53, 0xF42AF2CF);
MS2_REPLACE_METHOD_VIA(0x1419F09E0, UIMainPlayerInfo, UIItemEventListener, vfunc_2, 153, 0xF2D0BFB6);
MS2_REPLACE_METHOD_VIA(0x1419F0A80, UIMainPlayerInfo, UIItemEventListener, vfunc_3, 138, 0xD3C75819);
MS2_REPLACE_METHOD_VIA(0x1419F0B10, UIMainPlayerInfo, UIItemEventListener, vfunc_4, 83, 0xDCAC17BD);
MS2_REPLACE_METHOD_VIA(0x1419F0B70, UIMainPlayerInfo, UIItemEventListener, vfunc_33, 43, 0xB8DCC875);
MS2_REPLACE_METHOD(0x1419F0BB0, UIMainPlayerInfo, FUN_1419f0bb0, 823, 0x9BF67C5F);
MS2_REPLACE_METHOD(0x1419F0EF0, UIMainPlayerInfo, AppendMessage, 222, 0x263E63E5);
MS2_REPLACE_METHOD(0x1419F0FE0, UIMainPlayerInfo, AddBuffEffect, 190, 0x7C987E59);
MS2_REPLACE_METHOD(0x1419F10B0, UIMainPlayerInfo, UpdateBuffEffect, 190, 0xC67F1BD0);
MS2_REPLACE_METHOD(0x1419F1180, UIMainPlayerInfo, RemoveBuffEffect, 108, 0x761E4F33);
MS2_REPLACE_METHOD(0x1419F1200, UIMainPlayerInfo, FUN_1419f1200, 349, 0x8B1F721E);
MS2_REPLACE_METHOD(0x1419F1370, UIMainPlayerInfo, FUN_1419f1370, 54, 0x9DB578D2);
MS2_REPLACE_METHOD(0x1419F13B0, UIMainPlayerInfo, FUN_1419f13b0, 246, 0x5A39A3D8);
MS2_REPLACE_METHOD(0x1419F14B0, UIMainPlayerInfo, FUN_1419f14b0, 29, 0xD55DF626);
MS2_REPLACE_METHOD(0x1419F14E0, UIMainPlayerInfo, OnShortkeyPageNotify, 144, 0x2F1083FC);
MS2_REPLACE_METHOD(0x1419F1580, UIMainPlayerInfo, OnSkillSetModeNotify, 108, 0x1B831F22);
MS2_REPLACE_METHOD(0x1419F1600, UIMainPlayerInfo, UpdateName, 157, 0x34C03AC0);
MS2_REPLACE_METHOD(0x1419F16B0, UIMainPlayerInfo, FUN_1419f16b0, 349, 0xE5B867E5);
MS2_REPLACE_METHOD(0x1419F1820, UIMainPlayerInfo, PlayHit, 87, 0x667862EF);
MS2_REPLACE_METHOD(0x1419F1880, UIMainPlayerInfo, SetBattle, 96, 0xDCB1F1C6);
MS2_REPLACE_METHOD(0x1419F18F0, UIMainPlayerInfo, SyncSlotMode, 198, 0x57B33E07);
MS2_REPLACE_METHOD(0x1419F19C0, UIMainPlayerInfo, FUN_1419f19c0, 697, 0x9C99E173);
MS2_REPLACE_METHOD(0x1419F1C80, UIMainPlayerInfo, FUN_1419f1c80, 134, 0x22C63536);
MS2_REPLACE_METHOD(0x1419F1D10, UIMainPlayerInfo, SetHideReason, 137, 0x1C97C8F6);
MS2_REPLACE_METHOD(0x1419F1DA0, UIMainPlayerInfo, FUN_1419f1da0, 183, 0x5402C73D);
MS2_REPLACE_METHOD(0x1419F1E60, UIMainPlayerInfo, FUN_1419f1e60, 827, 0xBBCC7252);
MS2_REPLACE_METHOD(0x1419F21B0, UIMainPlayerInfo, FUN_1419f21b0, 223, 0x89B31DC3);
MS2_REPLACE_METHOD(0x1419F22A0, UIMainPlayerInfo, FUN_1419f22a0, 581, 0xB96455DF);
MS2_REPLACE_METHOD(0x1419F24F0, UIMainPlayerInfo, FUN_1419f24f0, 96, 0x1555250E);
MS2_REPLACE_METHOD(0x1419F2560, UIMainPlayerInfo, FUN_1419f2560, 326, 0x786BC2A8);
MS2_REPLACE_METHOD(0x1419F26B0, UIMainPlayerInfo, FUN_1419f26b0, 97, 0x7B8BEE4A);
MS2_REPLACE_METHOD(0x1419F2720, UIMainPlayerInfo, SetHideAndSeekSlotMode, 172, 0x6C5F70FB);
MS2_REPLACE_METHOD(0x1419F27E0, UIMainPlayerInfo, FindSlotForItem, 319, 0x2FEBCF48);
MS2_REPLACE_METHOD(0x1419F2930, UIMainPlayerInfo, FUN_1419f2930, 135, 0x3F90CB89);
MS2_REPLACE_METHOD(0x1419F29C0, UIMainPlayerInfo, FUN_1419f29c0, 202, 0xA12B305E);
MS2_REPLACE_METHOD(0x1419F2A90, UIMainPlayerInfo, FUN_1419f2a90, 197, 0x5DCAC1E1);
MS2_REPLACE_METHOD(0x1419F2B60, UIMainPlayerInfo, FUN_1419f2b60, 533, 0x342FE6D6);
MS2_REPLACE_METHOD(0x1419F2D90, UIMainPlayerInfo, FUN_1419f2d90, 115, 0x678D1F9A);
MS2_REPLACE_METHOD(0x1419F2E10, UIMainPlayerInfo, FUN_1419f2e10, 73, 0xD95939D7);
MS2_REPLACE_METHOD(0x1419F2E60, UIMainPlayerInfo, FUN_1419f2e60, 73, 0xF047AE4F);
MS2_REPLACE_METHOD(0x1419F2EB0, UIMainPlayerInfo, FUN_1419f2eb0, 821, 0xA5BAA5BC);
MS2_REPLACE_METHOD(0x1419F31F0, UIMainPlayerInfo, GetSlotName, 135, 0x5DB83B85);
MS2_REPLACE_METHOD(0x1419F3280, UIMainPlayerInfo, LoadRenderTarget, 93, 0x7BA66163);
MS2_REPLACE_METHOD(0x1419F32F0, UIMainPlayerInfo, UnloadRenderTarget, 114, 0x5EB8B805);
MS2_REPLACE_METHOD(0x1419F3370, UIMainPlayerInfo, OnRideOff, 127, 0x36031C45);
MS2_REPLACE_METHOD(0x1419F3400, UIMainPlayerInfo, FUN_1419f3400, 19, 0x06877B61);
MS2_REPLACE_METHOD(0x1419F3420, UIMainPlayerInfo, GetPlayerNameWithTitles, 356, 0x96096A55);
MS2_REPLACE_METHOD(0x1419F3590, UIMainPlayerInfo, FUN_1419f3590, 142, 0xCC7D34E8);
MS2_REPLACE_METHOD(0x1419F3630, UIMainPlayerInfo, OnPrevPage, 130, 0x0A1506CF);
MS2_REPLACE_METHOD(0x1419F36C0, UIMainPlayerInfo, OnNextPage, 114, 0x49D79FEE);
MS2_REPLACE_METHOD(0x1419F3740, UIMainPlayerInfo, ResetGauges, 156, 0xD5EE2B40);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbf3f0-0x142cbf550 .text$yd
