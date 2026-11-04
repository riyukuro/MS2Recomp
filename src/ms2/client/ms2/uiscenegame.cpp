// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The in-game scene family: see uiscenegame.h.
// MS2-UNIT: ?\uiscenegame.cpp
// MS2-RANGE: 0x14011c3e0-0x14011cbf0 .text$di
// MS2-RANGE: 0x141ac6fa0-0x141acd890 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x141ac7da0 ; unique
// MS2-PIN: ??_GUISceneGameBeautyShop@@UEAAPEAXI@Z 0x141ac92d0 ; unique
// MS2-PIN: ??_GUISceneGameCinematicCutScene@@UEAAPEAXI@Z 0x141ac9770 ; unique
// MS2-PIN: ??_GUISceneGameCinematicTalk@@UEAAPEAXI@Z 0x141ac9bc0 ; unique
// MS2-PIN: ??_GUISceneGameScreenShot@@UEAAPEAXI@Z 0x141acd850 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_handle1@@YAXXZ 0x14011c5c0 ; the three Unk_Handle1401cd100 statics (byte-identical to the egf kENTITY/kEVT_INVALID copies)
// MS2-PIN: ??__Es_handle2@@YAXXZ 0x14011c980
// MS2-PIN: ??__Es_handle3@@YAXXZ 0x14011cb10
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiscenegame.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "ms2/placeholder/gfxmanager.h"

// The shared header statics of this unit (each header brings its own copies, constructed in include order).
#include "ms2/placeholder/unk_1402a9d70.h"
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill1 = "skill";
static CString s_stun1 = "stun";
static Unk_Handle1401cd100 s_handle1(0);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController1;
static CString s_sortNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill2 = "skill";
static CString s_stun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController2;
static CString s_skill3 = "skill";
static CString s_stun3 = "stun";
static CString s_sortNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill4 = "skill";
static CString s_stun4 = "stun";
static Unk_Handle1401cd100 s_handle2(0);
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController3;
#ifndef MS2_HOOK_DLL   // s_systemKillSlayer: the exe's object at 0x143af6008, which other units reach as DAT_143af6008 (the hook DLL binds it)
CString DAT_143af6008 = "System_KillSlayer";
#else
extern CString DAT_143af6008;
#endif
static CString s_sortNames5[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static Unk_Handle1401cd100 s_handle3(0);
static CString s_sortNames6[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#include "uiscenegame.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/delegate.h"
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "hook/ms2hook.h"
#include <efd/Helpers.h>
#include <NiColor.h>
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/groupchatmanager.h"
#include "ms2/placeholder/uirecallscrollnotifydialog.h"
#include "ms2/client/ms2/clubcli.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/client/ms2/gamerankingcli.h"
#include "ms2/client/ms2/uiclosetdialog.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/os.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxPhysics.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/client/ms2/physxhelper.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

class Unk_GsUI : public CUIService                                          // the UI service (FUN_1403ed2b0)
{
public:
    void FUN_141adbcd0(int n);
    void FUN_141adbf00();
};
class Unk_GsSettings : public CItemDataTable { };
unsigned char FUN_1401d1320(class CCacheData* p);
class Unk_GsNpcMgr : public CGameEventValuePublicTest { };
class Unk_GsPubtest { };
class Unk_GsLogin : public CInputKeyHandler { };
class Unk_GsCamArg { public: Unk_GsCamArg(); int m_0, m_4, m_8, m_c, m_10, m_14, m_18, m_1c, m_20, m_24; };
MS2_CHECK_SIZE(Unk_GsCamArg, 0x28);
class Unk_GsWindow { };
int FUN_141b712e0();
class Unk_GsSceneId;
class Unk_GsServerDlg : public UIDialog { public: void FUN_141ad2ef0(); };

void* FUN_14025e7c0();
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class CGameEventValueManager;
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9fd0(int);
    int GetSubSceneId();
};
extern int DAT_143ab0248;
extern int DAT_143ab2914;
CStringW TakeScreenshotJpg(int a, int b);
CStringW GetStringCommon(int nId);
CStringW GetStringCommonByKey(const CStringW& str);
void FUN_1412751b0(const CStringW& str, int nFlags);
void FUN_141b91b20(bool b);
void FUN_141a60d40(int n);
class UIArcadeMainDialog   // C3: member view (real class not in this TU)
{
public:
    void FUN_140ef6920();
};
class Unk_GsDlg2 { public:  };
class Unk_GsDlg3 : public UIClosetDialog { public:  };
class Unk_ClubManager* FUN_140e0d900();   // C3: was FUN_140e0d900
class Unk_AkoCutscene   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoCutscene* GetInstance();
};
UIRecallScrollNotifyDialog* FUN_140bc1870(int nUiId);
template <class T> T* Unk_SSGGetDialog(int nUiId);
class UIClosetDialog* FUN_141815ed0();   // C3: was FUN_141815ed0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141ac6fa0
UISceneGame::UISceneGame()
{
    m_6c = 0x620000c;
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGamePlay);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGameBeautyShop);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGameCinematicTalk);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGameScreenShot);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGameCinematicCutScene);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneGameCinematicPlay);
        m_78.AddTail(ref);
    }
}

// @0x141ac7310
UISceneGame::~UISceneGame()
{
}

// @0x141ac7350
CString UISceneGame::GetTypeName()
{
    return "SceneGame";
}
MS2_REPLACE_METHOD(0x141ac7350, UISceneGame, GetTypeName, 61, 0x12E28071);

// @0x141ac73a0
void UISceneGame::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    if (FUN_1401d1320(reinterpret_cast<CCacheData*>(TSingleton<CItemDataTable>::GetInstance())) != 0) reinterpret_cast<Unk_GsSettings*>(TSingleton<CItemDataTable>::GetInstance())->Reload();
    FUN_141a60d40(1);
    static int s_bWelcomeShown;
    if (s_bWelcomeShown == 0) {
        if (((Unk_GsNpcMgr*)TSingleton<CGameEventValueManager>::GetInstance()->GetPublicTest())->GetValue() != 0) {
            FUN_1412751b0(GetStringCommonByKey(L"s_msg_chatting_welcome_pubtest2"), 0x14);
        } else {
            FUN_1412751b0(GetStringCommon(0x2d6), 0x14);
        }
        s_bWelcomeShown = 1;
    }
    FUN_1422e7a40(0x620001d);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->SetMode(0x3ed);
    FUN_1422e7950();
}

// @0x141ac74f0
void UISceneGame::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    TSingleton<CPartyManager>::GetInstance()->FUN_14162a480();
    TSingleton<CGuildManager>::GetInstance()->FUN_1413b5f90();
    TSingleton<CGroupChatManager>::GetInstance()->FUN_14137e190();
    TSingleton<CGameRankingCli>::GetInstance()->ClearPersonal();
    ((class CClubClientManager*)FUN_140e0d900())->ClearClubsAndInvites();
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adb4c0(1);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(0x620001d);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(0x620001d);
    FUN_141a60d40(0);
    TSingleton<CUIService>::GetInstance()->FUN_141add0b0((eUIClassID)0x4e55);
    TSingleton<CUIService>::GetInstance()->FUN_141add0b0((eUIClassID)0x4e41);
    UIRecallScrollNotifyDialog* pDlg1 = FUN_140bc1870(0x4edd);
    if (pDlg1 != 0) pDlg1->FUN_14129cb20();
    Unk_GsDlg2* pDlg2 = (Unk_GsDlg2*)Unk_SSGGetDialog<UIArcadeMainDialog>(0x4efd);
    if (pDlg2 != 0) ((UIArcadeMainDialog*)(Unk_GsDlg2*)(pDlg2))->FUN_140ef6920();
    Unk_GsDlg3* pDlg3 = ((class Unk_GsDlg3*)FUN_141815ed0());
    if (pDlg3 != 0) pDlg3->ResetTabs();
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac74f0, UISceneGame, vfunc_49, 298, 0x93FAE665);

// @0x141ac7620
void UISceneGame::vfunc_15()
{
    UISwfEntity::vfunc_15();
    ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b20af0();
}
MS2_REPLACE_METHOD(0x141ac7620, UISceneGame, vfunc_15, 37, 0x043AEAC5);

class CUserMail   // C3: member view for the former free stand-ins
{
public:
    void FUN_1408e48f0();
    static __int64 FUN_1408e57f0();   // the scene-service global
};
extern CUserMail g_143ab2ee0;   // C3: was extern char DAT_143ab2ee0 (as scenestategame.cpp)
// @0x141ac7650
int UISceneGame::vfunc_13()
{
    if (UISwfEntity::vfunc_13()) return 1;
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x1d, false, 0)) {
        if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x16, true, 0)) {
            if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x38, true, 0)) {
                if (((class Unk_GsWindow*)FUN_140aadf80()) != 0) FUN_141b91b20((FUN_140aadf80(), FUN_141b712e0()) == 1);
                return 1;
            }
            bool bShow = true;
            if (DAT_143ab0248 == 2) bShow = DAT_143ab2914 >= 0x34;
            if (bShow) ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->CycleCursor();
            return 1;
        } else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x14, true, 0)) {
            if (((class GFxSceneService*)(class Unk_GsSceneId*)(((Unk_GsSceneId*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() == 0x620001d) {
                FUN_1422e7a40(0x6200020);
            } else if (((class GFxSceneService*)(class Unk_GsSceneId*)(((Unk_GsSceneId*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() == 0x6200020) {
                FUN_1422e7a40(0x620001d);
            }
            return 1;
        }
    } else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493ef, 0, 0)) {
        TakeScreenshotJpg(0, 0);
        return 1;
    }
    return ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b20ac0();
}
MS2_REPLACE_METHOD(0x141ac7650, UISceneGame, vfunc_13, 467, 0xEE67B3FF);

// @0x141ac7830
int UISceneGame::vfunc_14()
{
    if (UISwfEntity::vfunc_14()) return 1;
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493ef, 0, 0) != 0) {
        TakeScreenshotJpg(0, 0);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac7830, UISceneGame, vfunc_14, 101, 0x48E1F71D);

// @0x141ac78a0
void UISceneGame::vfunc_55()
{
    UISceneEntity::vfunc_55();
    TSingleton<CUIService>::GetInstance()->FUN_141add040((eUIClassID)0x4e55);
    TSingleton<CUIService>::GetInstance()->FUN_141add040((eUIClassID)0x4e41);
}
MS2_REPLACE_METHOD(0x141ac78a0, UISceneGame, vfunc_55, 60, 0x44521706);

// @0x141ac78f0
void UISceneGame::vfunc_56()
{
    UISceneEntity::vfunc_56();
    if (((class GFxSceneService*)(class Unk_GsSceneId*)(((Unk_GsSceneId*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() != 0x620001d) {
        FUN_1422e7a40(0x620001d);
        ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
    }
    TSingleton<CUIService>::GetInstance()->FUN_141add0b0((eUIClassID)0x4e55);
    TSingleton<CUIService>::GetInstance()->FUN_141add0b0((eUIClassID)0x4e41);
}
MS2_REPLACE_METHOD(0x141ac78f0, UISceneGame, vfunc_56, 108, 0xF5771772);

// The scene-list glue (CAtlList<Unk_ScenePtr<UISceneEntity> >: 0x141ac7960-0x141ac7d50, 0x141ac7da0) is paired by tplpin.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UISceneGameBeautyShop

#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/commandchat.h"
#include "ms2/client/ms2/uiminimapentity.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cscripttable.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/client/ms2/uimassiveevent.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/debugconsole.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/actionkeyobject.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/placeholder/clientconstants.h"
#include <NiDX9Renderer.h>   // NiDX9Renderer::SetDeviceLostHeld

class Unk_GsMode : public Unk_ActionKeyManager { };
struct Unk_MiActionState* Unk_PlayerActionState(struct Unk_MiPlayer*);
class Unk_GsPlayer                                      // the local player (slots used by the camera code)
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();                 // 0x90 position
    virtual void vfunc_19(Vector3 kPos);        // 0x98 set position
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(Vector3 kDir);        // 0xb0 set direction
    virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30();
    virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34();
    virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38();
    virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46();
    virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50();
    virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54();
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58();
    virtual void vfunc_59(int a, int b, int c, int d);  // 0x1d8 state change
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62();
    virtual int vfunc_63();                             // 0x1f8
    void FUN_14166d8e0(Vector3 kDir);
};
class Unk_GsGround : public CubeMapInformationService { };

class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
void FUN_141901390(int nRelease, int nUiType);
void FUN_14151f200();
void FUN_141ac9310(Vector3 kRot, Vector3* pDir, Vector3* pOut);
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z) // C3: was extern Vector3 DAT_143a08cf8; the up vector
struct Unk_GsMatrix3
{
    Unk_GsMatrix3() {}                                      // 0x1409f72e0
    float m_afEntry[3][3];
};
MS2_CHECK_SIZE(Unk_GsMatrix3, 0x24);
Vector3 FUN_1420834e0(Vector3* pPt, Unk_GsMatrix3* pMat);    // efd::operator*(Point3, Matrix3)
typedef UIMsg Unk_GsUIMsg;
class UIDialog* FUN_140c300a0(int);   // C3: was FUN_140c300a0

// @0x141ac7da0
MS2_EMIT_CRT_MEMMOVE_S();

// @0x141ac7ec0
UISceneGameBeautyShop::UISceneGameBeautyShop()
    : m_a8(0), m_ac(0), m_b0(0), m_b4(0)
{
    m_6c = 0x620001f;
}

// @0x141ac7f60
UISceneGameBeautyShop::~UISceneGameBeautyShop()
{
}

// @0x141ac7fc0
CString UISceneGameBeautyShop::GetTypeName()
{
    return "SceneGameBeautyShop";
}
MS2_REPLACE_METHOD(0x141ac7fc0, UISceneGameBeautyShop, GetTypeName, 61, 0xBAE50A9C);

// @0x141ac8010
void UISceneGameBeautyShop::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
    FUN_141901390(0, 0x3eb);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbe00(1.0f, 0);
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0) {
        if (reinterpret_cast<PCBase*>(pPlayer)->FUN_1416764d0() != 0) {
            reinterpret_cast<MyPC*>(pPlayer)->SendRequestRideMode1(new RideOffActionBeautyShop(0));
        } else {
            FUN_141ac8e90();
        }
    } else {
        ((class GFxSceneService*)(class Unk_GsSceneId*)(((Unk_GsSceneId*)CUserMail::FUN_1408e57f0())))->FUN_1422b9fd0(n);
    }
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac8010, UISceneGameBeautyShop, vfunc_48, 276, 0x6FC9E2EA);

// @0x141ac8130
void UISceneGameBeautyShop::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_141ac8710();
    FUN_141ac8900();
    FUN_141901390(1, 0x3eb);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(m_6c);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)m_ac);
    m_ac = 0;
    m_b0 = 0;
    m_b4 = 0;
    FUN_14151f200();
    FUN_141ac8e70(0);
    if (!m_b8.IsEmpty()) {
        COutPacket pkt(static_cast<int>(SendOp::FunctionCube), 0);
        pkt.WriteUInt8(7);
        pkt.WriteUnicodeStringA(m_b8);
        FUN_140710590(pkt);
        m_b8 = "";
    }
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac8130, UISceneGameBeautyShop, vfunc_49, 344, 0x482C92FF);


// @0x141ac8290
void UISceneGameBeautyShop::vfunc_50()
{
    UISceneEntity::vfunc_50();
    if (m_ac == 0x4e24) {
        if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0) {
            ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("setItemEditMode");
        }
    }
}
MS2_REPLACE_METHOD(0x141ac8290, UISceneGameBeautyShop, vfunc_50, 110, 0x9C2574F9);

// @0x141ac8310
void UISceneGameBeautyShop::vfunc_52()
{
    UISceneEntity::vfunc_52();
    FUN_1422e7a40(0x620001d);
}
MS2_REPLACE_METHOD(0x141ac8310, UISceneGameBeautyShop, vfunc_52, 39, 0x70D86E74);

// @0x141ac8340
int UISceneGameBeautyShop::vfunc_13()
{
    if (UISwfEntity::vfunc_13()) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ac8340, UISceneGameBeautyShop, vfunc_13, 37, 0xE794AF82);

// @0x141ac8370
int UISceneGameBeautyShop::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp("OnExit", szMethod) == 0) {
        if (m_ac != 0) {
            Unk_GsUIMsg msg;
            ((ASData*)(Unk_GsUIMsg*)&(msg))->AddString(szMethod);
            Unk_GsServerDlg* pDlg = ((class Unk_GsServerDlg*)FUN_140c300a0(m_ac));
            if (pDlg != 0) pDlg->OnMessage(this, &msg);
        } else {
            FUN_1422e7a40(0x620001d);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac8370, UISceneGameBeautyShop, vfunc_28, 287, 0x626F67EB);

// @0x141ac84a0
int UISceneGameBeautyShop::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    UISwfEntity::OnMessage(pSender, pMsg);
    if (pMsg->FUN_1422e4520() == 0) {
        CString strMethod = pMsg->FUN_1422b8d30();
        if (_stricmp("moveMyPC", strMethod) == 0) {
            m_b0 = pMsg->PopInt();
            m_b4 = static_cast<Unk_GsUIMsg*>(pMsg)->PopUInt();
            return 1;
        } else if (_stricmp("openDialog", strMethod) == 0) {
            m_ac = pMsg->PopInt();
            return 1;
        } else if (_stricmp("setCubeID", strMethod) == 0) {
            m_b8 = pMsg->FUN_1422b8d30();
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac84a0, UISceneGameBeautyShop, OnMessage, 425, 0x799116AE);

// @0x141ac8660
void UISceneGameBeautyShop::FUN_141ac8660()
{
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0) return;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() == 0) return;
    pPlayer->FUN_14166d8e0(Vector3(0.0f, -1.0f, 0.0f));
    pPlayer->vfunc_59(0xe, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x141ac8660, UISceneGameBeautyShop, FUN_141ac8660, 160, 0xC0E3A86A);

// @0x141ac8710
void UISceneGameBeautyShop::FUN_141ac8710()
{
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0) {
        pPlayer->FUN_14166d8e0(Vector3(0.0f, -1.0f, 0.0f));
        reinterpret_cast<PCBase*>(pPlayer)->FUN_14166cc40(0x4d);
        pPlayer->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x141ac8710, UISceneGameBeautyShop, FUN_141ac8710, 154, 0x8790D479);

// @0x141ac87b0
void UISceneGameBeautyShop::FUN_141ac87b0()
{
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() == 0) return;
    Unk_CameraFlyBy param;
    param.m_nKind = 1;
    param.m_fDuration = 0.8f;
    param.m_from.m_0 = ((Unk_CameraManager*)TSingleton<CameraMgr>::GetInstance())->FUN_140ad4b40();
    param.m_from.m_4 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7f00();
    param.m_from.m_8 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7ea0();
    param.m_from.m_c = TSingleton<CameraMgr>::GetInstance()->FUN_140a17e10();
    param.m_from.m_18 = TSingleton<CameraMgr>::GetInstance()->FUN_140af8290();
    param.m_to.m_0 = param.m_from.m_0;
    param.m_to.m_4 = param.m_from.m_4;
    param.m_to.m_8 = param.m_from.m_8;
    FUN_141ac8b00(&param.m_to.m_c, &param.m_to.m_18, &param.m_return.m_c);
    TSingleton<CameraMgr>::GetInstance()->FUN_140aed580(&param, 1, 1.0f);
    TSingleton<CameraMgr>::GetInstance()->FUN_140aed750(4, 0);
}
MS2_REPLACE_METHOD(0x141ac87b0, UISceneGameBeautyShop, FUN_141ac87b0, 319, 0x5E0960A6);

// @0x141ac8900
void UISceneGameBeautyShop::FUN_141ac8900()
{
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
        Unk_CameraFlyBy param;
        param.m_nKind = 1;
        param.m_fDuration = 1.0f;
        param.m_from.m_0 = ((Unk_CameraManager*)TSingleton<CameraMgr>::GetInstance())->FUN_140ad4b40();
        param.m_from.m_4 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7f00();
        param.m_from.m_8 = TSingleton<CameraMgr>::GetInstance()->FUN_140af7ea0();
        param.m_from.m_c = TSingleton<CameraMgr>::GetInstance()->FUN_140a17e10();
        param.m_from.m_18 = TSingleton<CameraMgr>::GetInstance()->FUN_140af8290();
        if (((class Unk_GsGround*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d2f10() != 0) {
            param.m_to = TSingleton<CameraMgr>::GetInstance()->m_homeSetting;
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed580(&param, 1, 1.0f);
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed750(0x11, 0);
        } else {
            param.m_to = param.m_from;
            param.m_to.m_0 = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_140ad4b30();
            param.m_to.m_4 = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_140af7ef0();
            param.m_to.m_8 = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_140af7e90();
            param.m_to.m_18 = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_140af8260();
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed580(&param, 1, 1.0f);
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed750(2, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x141ac8900, UISceneGameBeautyShop, FUN_141ac8900, 491, 0x9741E8D2);

// @0x141ac8b00
void UISceneGameBeautyShop::FUN_141ac8b00(Vector3* pOut1, Vector3* pOut2, Vector3* pOut3)
{
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0) return;
    Vector3 kA;
    Vector3 kB;
    if (((class Unk_GsGround*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d2f10() != 0 && TSingleton<CameraMgr>::GetInstance()->FUN_140af0210() != 0) {
        Vector3 kEuler = TSingleton<CameraMgr>::GetInstance()->FUN_140af8290().FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
        Unk_GsMatrix3 mX;
        ((efd::Matrix3*)(Unk_GsMatrix3*)&(mX))->FromEulerAnglesXYZ(-90.0f, 0.0f, 0.0f);
        Unk_GsMatrix3 mY;
        ((efd::Matrix3*)(Unk_GsMatrix3*)&(mY))->FromEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
        ((efd::Matrix3*)(Unk_GsMatrix3*)&(mY))->GetCol(0, *(efd::Point3*)(Vector3*)&(kA));
        kA = FUN_1420834e0(&kA, &mX);
        kA.z = 0.0f;
        kA.FUN_140968990();
        kB = kA.FUN_140a00e10(DAT_143a08cf8).FUN_1409f7960();
    } else {
        FUN_141ac9310(TSingleton<CameraMgr>::GetInstance()->FUN_140af8290(), &kA, &kB);
    }
    kA = kA.FUN_1409f7960();
    Vector3 kP = pPlayer->vfunc_18().FUN_14097fd50(kA.FUN_14097fc90(350.0f));
    kP.z += 80.0f;
    Vector3 kQ = pPlayer->vfunc_18().FUN_14097fd50(kB.FUN_14097fc90(-50.0f));
    kQ.z += 80.0f;
    *pOut3 = kQ;
    *pOut1 = kP;
    *pOut2 = CCameraMode::FUN_140afdd40(*pOut3, kP, DAT_143a08cf8);
}
MS2_REPLACE_METHOD(0x141ac8b00, UISceneGameBeautyShop, FUN_141ac8b00, 867, 0x333C6E82);

// @0x141ac8e70
void UISceneGameBeautyShop::FUN_141ac8e70(int nDialogMode)
{
    m_a8 = nDialogMode;
}
MS2_REPLACE_METHOD(0x141ac8e70, UISceneGameBeautyShop, FUN_141ac8e70, 25, 0xD3EC7A67);

// @0x141ac8e90
void UISceneGameBeautyShop::FUN_141ac8e90()
{
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0) return;
    int bMoved = 0;
    if (m_b0 != 0) {
        MS2Ptr<CPortal> ref = WorldService::GetInstance()->FUN_141bc2800(m_b0);
        if (((void*)ref.get()) != 0) {
            Vector3 kHit;
            if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFixedDirection(ref->FUN_14169d2f0(), kHit, (Unk_RayCastInfo*)0, 0.0f, (Vector3*)0, 0) != 0) {
                kHit.z += 1.0f;
                pPlayer->vfunc_19(kHit);
                bMoved = 1;
            }
        }
    }
    if (!bMoved && m_b4 > 0) {
        Unk_GsPlayer* pNpc = reinterpret_cast<Unk_GsPlayer*>(WorldService::GetInstance()->FUN_141bd1320(m_b4));
        if (pNpc != 0) {
            Vector3 kHit;
            Vector3 kDir = pPlayer->vfunc_18().FUN_140965c40(TSingleton<CameraMgr>::GetInstance()->FUN_140a17e10());
            kDir.FUN_140968990();
            kDir.z = 0.0f;
            Vector3 kFrom = pNpc->vfunc_18().FUN_140965c40(kDir.FUN_14097fc90(100.0f));
            if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFixedDirection(kFrom, kHit, (Unk_RayCastInfo*)0, 0.0f, (Vector3*)0, 0) != 0) {
                kHit.z += 1.0f;
                pPlayer->vfunc_19(kHit);
            }
        }
    }
    FUN_141ac8660();
    FUN_141ac87b0();
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
    m_ac = (m_a8 != 0) ? 0x4e79 : m_ac;
    if (m_ac != 0) (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(m_ac)));
}
MS2_REPLACE_METHOD(0x141ac8e90, UISceneGameBeautyShop, FUN_141ac8e90, 979, 0xB916CD23);

// @0x141ac9270
void UISceneGameBeautyShop::FUN_141ac9270()
{
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0) {
        if (reinterpret_cast<PCBase*>(pPlayer)->GetCurStateId() != 0xe) pPlayer->vfunc_59(0xe, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x141ac9270, UISceneGameBeautyShop, FUN_141ac9270, 93, 0xEF3CF752);

// @0x141ac9310
void FUN_141ac9310(Vector3 kRot, Vector3* pDir, Vector3* pOut)
{
    kRot = kRot.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
    Unk_GsMatrix3 m;
    ((efd::Matrix3*)(Unk_GsMatrix3*)&(m))->FromEulerAnglesXYZ(kRot.x, kRot.y, kRot.z);
    ((efd::Matrix3*)(Unk_GsMatrix3*)&(m))->GetCol(0, *(efd::Point3*)(Vector3*)&(*pDir));
    pDir->z = 0.0f;
    pDir->FUN_140968990();
    *pOut = pDir->FUN_140a00e10(DAT_143a08cf8).FUN_1409f7960();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UISceneGameCinematicCutScene / UISceneGameCinematicTalk

class Unk_GsCineMgr
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);                       // 0x50
};
class Unk_GsTalkTarget { public: char m_pad_00[0x48]; void* m_48; };
class Unk_C2UiMgr   // C3: member view (real class not in this TU)
{
public:
    bool FUN_1410af770();
};
class Unk_GsTutMgr
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6();                             // 0x30
};
namespace ChromaSDK { class IChromaManager; IChromaManager* GetChromaManager(); }
struct Unk_MdState* FUN_141482e80();   // C3: was FUN_141482e80
class UIMessengerBrowser   // C3: member view for the former free stand-ins
{
public:
    void FUN_141a251f0(int);
};
class UISwfEntityManager* FUN_140b632f0();   // C3: was FUN_140b632f0
float FUN_141ac9b00();
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
extern unsigned DAT_143af62d4;
extern unsigned DAT_143af62d8;

// @0x141ac9430
UISceneGameCinematicCutScene::UISceneGameCinematicCutScene()
{
    m_6c = 0x6200041;
}

// @0x141ac9480
UISceneGameCinematicCutScene::~UISceneGameCinematicCutScene()
{
}

// @0x141ac94c0
CString UISceneGameCinematicCutScene::GetTypeName()
{
    return "SceneGameCinematicCutScene";
}
MS2_REPLACE_METHOD(0x141ac94c0, UISceneGameCinematicCutScene, GetTypeName, 61, 0x85846A94);

// @0x141ac9510
bool UISceneGameCinematicCutScene::vfunc_47()
{
    return false;
}
MS2_REPLACE_METHOD(0x141ac9510, UISceneGameCinematicCutScene, vfunc_47, 8, 0x41132FCD);

// @0x141ac9520
void UISceneGameCinematicCutScene::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0) pPlayer->vfunc_22(DAT_143b01a60);
    FUN_141901390(0, vfunc_65());
    WorldService::GetInstance()->FUN_141bd3c00(false);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
    ((Unk_GsCineMgr*)ChromaSDK::GetChromaManager())->vfunc_10(0xb);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9520, UISceneGameCinematicCutScene, vfunc_48, 237, 0x608CA992);

// @0x141ac9620
void UISceneGameCinematicCutScene::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_141901390(1, vfunc_65());
    WorldService::GetInstance()->FUN_141bd3c00(true);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(m_6c);
    ((Unk_GsCineMgr*)ChromaSDK::GetChromaManager())->vfunc_10(0);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9620, UISceneGameCinematicCutScene, vfunc_49, 158, 0x0B53EFBE);

// @0x141ac96d0
void UISceneGameCinematicCutScene::vfunc_54()
{
    ((class GFxSceneService*)(class Unk_GsSceneId*)(((Unk_GsSceneId*)CUserMail::FUN_1408e57f0())))->FUN_1422b9fd0(0x620001d);
}
MS2_REPLACE_METHOD(0x141ac96d0, UISceneGameCinematicCutScene, vfunc_54, 32, 0x21320207);

// @0x141ac9700
void UISceneGameCinematicCutScene::vfunc_52()
{
    UISceneEntity::vfunc_52();
}
MS2_REPLACE_METHOD(0x141ac9700, UISceneGameCinematicCutScene, vfunc_52, 24, 0xA9B9DF0A);

// @0x141ac9720
int UISceneGameCinematicCutScene::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ac9720, UISceneGameCinematicCutScene, vfunc_28, 67, 0xF60BC26E);

// @0x141ac97b0
int UISceneGameCinematicCutScene::vfunc_65()
{
    return 0x4e58;
}
MS2_REPLACE_METHOD(0x141ac97b0, UISceneGameCinematicCutScene, vfunc_65, 11, 0xE17E89D9);

// @0x141ac97c0
UISceneGameCinematicTalk::UISceneGameCinematicTalk()
{
    m_6c = 0x6200031;
}

// @0x141ac9810
UISceneGameCinematicTalk::~UISceneGameCinematicTalk()
{
}

// @0x141ac9850
CString UISceneGameCinematicTalk::GetTypeName()
{
    return "SceneGameCinematicTalk";
}
MS2_REPLACE_METHOD(0x141ac9850, UISceneGameCinematicTalk, GetTypeName, 61, 0x17D40321);

// @0x141ac98a0
void UISceneGameCinematicTalk::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141add1b0(4, true);
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0) {
        if (((class Unk_GsTalkTarget*)FUN_141482e80())->m_48 != 0) ((class UIMessengerBrowser*)(void*)(((class Unk_GsTalkTarget*)FUN_141482e80())->m_48))->FUN_141a251f0(0);
    }
    m_b0 = FUN_14025e7a0()->FUN_1422afec0(m_28);
    float fScale = FUN_141ac9b00();
    if (FUN_14025e7a0()->FUN_1422aff10(fScale) != 0) ((class Unk_GsTutMgr*)FUN_140b632f0())->vfunc_6();
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac98a0, UISceneGameCinematicTalk, vfunc_48, 253, 0xDD0D19F1);

// @0x141ac99b0
void UISceneGameCinematicTalk::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141add1b0(4, false);
    Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (((class Unk_GsTalkTarget*)FUN_141482e80())->m_48 != 0) ((class UIMessengerBrowser*)(void*)(((class Unk_GsTalkTarget*)FUN_141482e80())->m_48))->FUN_141a251f0(1);
    if (FUN_14025e7a0()->FUN_1422aff10(m_b0) != 0) ((class Unk_GsTutMgr*)FUN_140b632f0())->vfunc_6();
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac99b0, UISceneGameCinematicTalk, vfunc_49, 210, 0xAF714157);

// @0x141ac9a90
void UISceneGameCinematicTalk::vfunc_52()
{
    UISceneEntity::vfunc_52();
}
MS2_REPLACE_METHOD(0x141ac9a90, UISceneGameCinematicTalk, vfunc_52, 24, 0xEA7E60A3);

// @0x141ac9ab0
int UISceneGameCinematicTalk::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ac9ab0, UISceneGameCinematicTalk, vfunc_28, 67, 0x9BB14E4A);

// @0x141ac9b00
float FUN_141ac9b00()
{
    float fWide = (float)DAT_143af62d8 * 1.6f;
    float fRatio = (float)DAT_143af62d8 / (float)DAT_143af62d4;
    float fScale = 0.0f;
    if (fWide < (float)DAT_143af62d4 && fRatio > 0.5) {
        fScale = (float)DAT_143af62d4 / 1920.0f;
    } else {
        fScale = (float)DAT_143af62d8 / 1200.0f;
    }
    fScale = 1.0f / fScale;
    return fScale;
}

// @0x141ac9c00
int UISceneGameCinematicTalk::vfunc_65()
{
    return 0x4e3f;
}
MS2_REPLACE_METHOD(0x141ac9c00, UISceneGameCinematicTalk, vfunc_65, 11, 0x5D5019E0);

// @0x141ac9c10
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UISceneGamePlay

class Unk_GsTexReload
{
public:
    char m_pad_00[0xcc];
    int m_cc;
    int FUN_141acccb0() { return m_cc; }                    // 0x141acccb0
    void FUN_141accee0(int n) { m_cc = n; }                 // 0x141accee0
};
class Unk_GsDlgA : public UIDialog { };
void FUN_141815db0(void* p);
class Unk_GsDbgLog : public CDebugConsole { };
class CKeyTable   // C3: member view (real class not in this TU)
{
public:
    int FUN_14142b300(int);
};
class Unk_GsHk { public:  };
class Unk_GsHudInfo { public: char m_pad_00[8]; float m_8; };
class Unk_GsAppG;
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
void FUN_141acc5a0(float fValue);
int FUN_141acc5f0(int nSceneId);
int FUN_141acc6c0(int nSceneId);
class Unk_GsCommon;
class Unk_ItemPreview* FUN_1409bb9e0();   // C3: was FUN_1409bb9e0
class CGameOption;
class Unk_ChaosSettings   // C3: member view for the former free stand-ins
{
public:
    struct Unk_ChaosOpt* FUN_140e09150();
};
void FUN_141b70290();
class CGameOption   // C3: member view for the former free stand-ins
{
public:
    int LoadCharacterOption();
};
struct Unk_GpState* FUN_140a58500(class Unk_GpSettings*);   // C3: was FUN_140a58500
void FUN_14125f670(struct Unk_GpState*, bool, bool);   // C3: was (char*, char, int)
void* FUN_140c58ac0(class Unk_KsInputState*);   // C3: was FUN_140c58ac0
void FUN_14125bd20(struct Unk_InterfaceFlag*, bool);   // C3: was (char*, char)
UIMassiveEvent* FUN_140e01890(int nId);
void* FUN_140764020();   // C3: was FUN_140764020
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
void FUN_141275260(int nId, int a, int b);
int FUN_141276180(const CString& a, const CString& b);
extern CString DAT_143af6008;
int FUN_1418fcb70();
CMyCharacter* FUN_140931510();
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0
class UIDPSDialog;
template <class T> T* PCBaseDialog(int nId);
void* FUN_141371b20();   // C3: was FUN_141371b20
void* FUN_141371b30();   // C3: was FUN_141371b30
class CSoundService* FUN_140c9cb10();   // C3: was FUN_140c9cb10
int FUN_1417af7a0();   // C3: was FUN_1417af7a0
void FUN_1409c51f0();
class UIMessenger   // C3: member view for the former free stand-ins
{
public:
    static bool ReloadDebugChatCommands();
};
void FUN_140710590(COutPacket& packet);
int FUN_141276f80(struct Unk_CommandChat* pCmd);
void TakeScreenshotPng(int n);
class Unk_SingletonObj* FUN_1414a56c0();   // C3: was FUN_1414a56c0
class GFxService   // C3: member view for the former free stand-ins
{
public:
    static void FUN_1422ea210(int);
};
namespace ecr { class RenderService; }
ecr::RenderService* Unk_GetRenderService(char* pCell);
class MS2RenderService   // C3: member view for the former free stand-ins
{
public:
    void CheckRenderState();
};
class Unk_SoundSink* FUN_1409331f0();   // C3: was FUN_1409331f0
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
UIMinimapDialog* FUN_140c9b540(int nId);
class UIGameMenuDialog* FUN_140938b90(int);   // C3: was FUN_140938b90
class Unk_140166410* FUN_140166410();
int FUN_140ae1c10();
void FUN_141610410(int n);
extern unsigned DAT_143ae0fb8;
extern unsigned DAT_143ae0fb0;
extern int DAT_1439fa008;
extern unsigned char DAT_1439fa00c;
extern wchar_t DAT_142fde938[];
extern wchar_t DAT_142fde930[];
extern wchar_t DAT_142fdea00[];
extern wchar_t DAT_142fde9f4[];
extern char DAT_142fdeb28[];
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(Unk_GsAppG*)&egf::g_bapiContext)          // C3: was extern Unk_GsAppG DAT_143b059e8

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).

// @0x141ac9d30
UISceneGamePlay::UISceneGamePlay()
{
    m_6c = 0x620001d;
    m_c8 = 0;
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangeEnableFeature", Delegate<void(NotifyObject*)>(this, &UISceneGamePlay::FUN_141acc510));
}

// @0x141ac9e80
UISceneGamePlay::~UISceneGamePlay()
{
}

// @0x141ac9ed0
CString UISceneGamePlay::GetTypeName()
{
    return "SceneGamePlay";
}
MS2_REPLACE_METHOD(0x141ac9ed0, UISceneGamePlay, GetTypeName, 61, 0x893C87BE);

// @0x141ac9f20
void UISceneGamePlay::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_141acc5a0(((class Unk_GsHudInfo*)((class Unk_ChaosSettings*)(void*)((void*)TSingleton<CGameOption>::GetInstance()))->FUN_140e09150())->m_8);
    if (((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0()) != 0) {
        if (FUN_141acc6c0(n) != 0) {
            if (m_6c == 0x620001d) ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adb4c0(1);
            if (((Unk_C2UiMgr*)(Unk_GsTutMgr*)(((class Unk_GsTutMgr*)FUN_140b632f0())))->FUN_1410af770() != 0) FUN_14025e7a0()->FUN_1422aed30(true);
        } else {
            ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
            ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
        }
        for (unsigned __int64 i = 0; i < m_a8.GetCount(); i++) {
            if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)m_a8[i]) != 0) (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(m_a8[i])));
        }
        m_a8.RemoveAll();
        FUN_141b70290();
    } else {
        ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
    }
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9f20, UISceneGamePlay, vfunc_48, 415, 0x83342379);

// @0x141aca0d0
void UISceneGamePlay::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    if (FUN_141acc6c0(n) != 0) {
        if (((Unk_C2UiMgr*)(Unk_GsTutMgr*)(((class Unk_GsTutMgr*)FUN_140b632f0())))->FUN_1410af770()) FUN_14025e7a0()->FUN_1422aed30(false);
        if (m_6c == 0x620001d) ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adb4c0(0);
    } else {
        ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
        ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(m_6c);
    }
    if (FUN_141acc5f0(n) != 0) FUN_141acc5a0(1.0f);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141aca0d0, UISceneGamePlay, vfunc_49, 189, 0xE218ED84);

// @0x141aca1a0
void UISceneGamePlay::vfunc_11()
{
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adb4c0(1);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9e50(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada6f0(m_6c);
    FUN_141b70290();
    ((class CGameOption*)(void*)((void*)TSingleton<CGameOption>::GetInstance()))->LoadCharacterOption();
    FUN_14125f670(FUN_140a58500((class Unk_GpSettings*)((void*)TSingleton<CGameOption>::GetInstance())), *((bool*)FUN_140a58500((class Unk_GpSettings*)((void*)TSingleton<CGameOption>::GetInstance()))), false);
    FUN_14125bd20(((struct Unk_InterfaceFlag*)FUN_140c58ac0((class Unk_KsInputState*)((void*)TSingleton<CGameOption>::GetInstance()))), *((bool*)FUN_140c58ac0((class Unk_KsInputState*)((void*)TSingleton<CGameOption>::GetInstance()))));
}
MS2_REPLACE_METHOD(0x141aca1a0, UISceneGamePlay, vfunc_11, 189, 0x2CECF6E0);

// @0x141aca270
int UISceneGamePlay::vfunc_13()
{
    if (UISwfEntity::vfunc_13()) return 1;
    return FUN_141aca870();
}
MS2_REPLACE_METHOD(0x141aca270, UISceneGamePlay, vfunc_13, 45, 0xD0F20584);

// @0x141aca2b0
int UISceneGamePlay::vfunc_14()
{
    if (UISwfEntity::vfunc_14() != 0) return 1;
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d840() != 0) {
        return FUN_1418fcb70();
    } else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x49404, 0, 0) != 0) {
        ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbbb0();
        return 1;
    } else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493e2, 0, 0) != 0) {
        Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0 && reinterpret_cast<PCBase*>(pPlayer)->IsDead() == 0 && pPlayer->vfunc_63() != 0) ((Unk_GsMode*)Unk_PlayerActionState((struct Unk_MiPlayer*)(pPlayer)))->ActivateCurrentAction();
        return 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141aca2b0, UISceneGamePlay, vfunc_14, 237, 0x5EDB9347);

// @0x141aca3b0
void UISceneGamePlay::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dcb0(0x49406, false, 0) != 0) ((class ItemPreviewMgr*)FUN_1409bb9e0())->SetHudMode(1);
    else ((class ItemPreviewMgr*)FUN_1409bb9e0())->SetHudMode(0);
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x2a, 0, 0) != 0 || ((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x36, 0, 0) != 0) ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adcb60(1);
    else ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adcb60(0);
    (&g_143ab2ee0)->FUN_1408e48f0();
}
MS2_REPLACE_METHOD(0x141aca3b0, UISceneGamePlay, vfunc_15, 199, 0x6836B94F);

// @0x141aca480
void UISceneGamePlay::vfunc_34(void* p, float x, float y)
{
    if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0) return;
    UISwfEntity::vfunc_34(p, x, y);
}
MS2_REPLACE_METHOD(0x141aca480, UISceneGamePlay, vfunc_34, 82, 0x597C7D9E);

// @0x141aca4e0
void UISceneGamePlay::vfunc_55()
{
    UISceneEntity::vfunc_55();
}
MS2_REPLACE_METHOD(0x141aca4e0, UISceneGamePlay, vfunc_55, 24, 0x6A6ADC0B);

// @0x141aca500
void UISceneGamePlay::vfunc_56()
{
    UISceneEntity::vfunc_56();
    UIMassiveEvent* pUnit = FUN_140e01890(0x4e4c);
    if (pUnit != 0) pUnit->FUN_1419f5ab0();
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ada610(m_6c);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adad20(m_6c);
}
MS2_REPLACE_METHOD(0x141aca500, UISceneGamePlay, vfunc_56, 99, 0xDBBEB784);

// @0x141aca570
void UISceneGamePlay::vfunc_58()
{
    ((class CQuestManager*)FUN_140764020())->FUN_1416ca670();
    ((class NotifySystem*)FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifyFadeInComplete));
    int nMapId = WorldService::GetInstance()->FUN_141bd3060();
    MS2Ptr<CFieldDataCli> spMap = CFieldDataCli::Find(nMapId);
    if ((((void*)spMap.get()) ? true : false) && spMap->FUN_1403754f0() != 0) {
        if (m_c8 != 0 && spMap->GetPkMode() == 0) {
            FUN_141275260(0x96f, 4, 0);
            FUN_1412751b0(GetStringCommon(0x970), 0x14);
            FUN_141276180(DAT_143af6008, "");
            m_c8 = 0;
        } else if (m_c8 == 0) {
            if (spMap->GetPkMode() != 0) {
                FUN_141275260(0x96d, 4, 0);
                FUN_1412751b0(GetStringCommon(0x96e), 0x14);
                FUN_141276180(DAT_143af6008, "");
                m_c8 = 1;
            }
        }
    } else {
        m_c8 = 0;
    }
}
MS2_REPLACE_METHOD(0x141aca570, UISceneGamePlay, vfunc_58, 705, 0x57099858);

// @0x141aca840
void UISceneGamePlay::FUN_141aca840(int nUiId)
{
    m_a8.Add(reinterpret_cast<Unk_GsUiId&>(nUiId));
}
MS2_REPLACE_METHOD(0x141aca840, UISceneGamePlay, FUN_141aca840, 42, 0x89200DCD);

// @0x141aca870
int UISceneGamePlay::FUN_141aca870()
{
    if (((CInputKeyHandler*)(Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d7a0(0xf) != 0) return 0;
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x1d, 0, 0) != 0) {
        if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x3d, 0, 0) != 0) {
            int nMode = (FUN_140ae1c10() + 1) % 5;
            FUN_141610410(nMode);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x21, 1, 0) != 0) {
            WorldService::GetInstance()->FUN_141bd2fa0();
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x2a, 1, 0) != 0 && ((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x1e, 1, 0) != 0) {
            ((class CScriptTable*)FUN_141371b30())->Reload();
            FUN_1412751b0(StringFormat(L"Script reloaded"), 0x14);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x1e, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            DAT_143ae0fb8 = (DAT_143ae0fb8 == 0);
            CStringW strMsg;
            strMsg.Format(L"월드맵 모든맵 발견모드 : %s", DAT_143ae0fb8 != 0 ? DAT_142fde930 : DAT_142fde938);
            FUN_1412751b0(strMsg, 0x14);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x13, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            unsigned char nMode = (unsigned char)DAT_143ae0fb0;
            nMode++;
            nMode = nMode % 3;
            DAT_143ae0fb0 = nMode;
            COutPacket packet(static_cast<int>(SendOp::SetDebugMode), 0);
            packet.WriteUInt8(0);
            packet.WriteUInt8(nMode);
            FUN_140710590(packet);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x2e, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x33) return 0;
            if (FUN_140931510()->FUN_140d9f5d0(1) != 0) {
                FUN_1412751b0(L"Error InvisibleFromAll On", 0x14);
                return 1;
            }
            Unk_CommandChat cmd;
            cmd.kind = 0;
            cmd.message = StringFormat(L"/ToggleInvisibleFromNpc");
            FUN_141276f80(&cmd);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x19, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x3b) return 0;
            Unk_CommandChat cmd;
            cmd.kind = 0;
            cmd.message = StringFormat(L"/ToggleDeathPower");
            FUN_141276f80(&cmd);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x11, 1, 0) != 0) {
            int nReload = ((class Unk_GsTexReload*)FUN_140a0afd0())->FUN_141acccb0();
            nReload ^= 1;
            ((class Unk_GsTexReload*)FUN_140a0afd0())->FUN_141accee0(nReload);
            CStringW strMsg;
            strMsg.Format(L"텍스쳐 리로드 : %s", nReload != 0 ? DAT_142fde9f4 : DAT_142fdea00);
            FUN_1412751b0(strMsg, 0x14);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x20, 1, 0) != 0) {
            Unk_GsDlgA* pDlg = (Unk_GsDlgA*)PCBaseDialog<UIDPSDialog>(0x4e44);
            if (pDlg != 0) pDlg->FUN_1419246f0();
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x80, 1, 0) != 0) {
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e50));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x26, 1, 0) != 0) {
            DAT_1439fa008 = DAT_1439fa008 - 1;
            if (DAT_1439fa008 == 0) DAT_1439fa008 = 3;
            CStringW strMsg;
            strMsg.Format(L"Effect LOD : %d", DAT_1439fa008);
            FUN_1412751b0(strMsg, 0x14);
            TSingleton<CEffectService>::GetInstance()->FUN_1411a8880(DAT_1439fa008);
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x927c1, 1, 0) != 0) {
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4ea3));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x22, 1, 0) != 0) return 1;
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x17, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e25));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x18, 1, 0) != 0) {
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4ecd));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x2d, 1, 0) != 0) {
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e8f));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x2c, 1, 0) != 0) {
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4ea6));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x31, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x38, 0, 0) != 0) TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e89));
            else TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e46));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x32, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x33) return 0;
            TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e2a));
            return 1;
        }
        else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x10, 1, 0) != 0) {
            Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
            if (pPlayer != 0 && reinterpret_cast<MyPC*>(pPlayer)->FUN_141527280() != 0) {
                TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e8c));
                return 1;
            }
        } else {
            if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x30, 1, 0) != 0) {
                if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
                TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)(0x4e4b));
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x24, 1, 0) != 0) {
                WorldService::GetInstance()->ShowResearchAndDevelopmentDialog();
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x3f, 1, 0) != 0) {
                FUN_1412751b0(L"Reload sound resource & string & colorPalette", 0x14);
                TSingleton<CStringTable>::GetInstance()->FUN_141811960();
                FUN_140c9cb10();
                FUN_1417af7a0();
                if (FUN_1401d1320(reinterpret_cast<CCacheData*>(TSingleton<CItemDataTable>::GetInstance())) != 0) reinterpret_cast<Unk_GsSettings*>(TSingleton<CItemDataTable>::GetInstance())->Reload();
                TSingleton<CommonString>::GetInstance()->Reload();
                FUN_1409c51f0();
                UIMessenger::ReloadDebugChatCommands();
                FUN_141815db0((void*)FUN_141371b20());
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x41, 1, 0) != 0) {
                int bShow = WorldService::GetInstance()->FUN_141bda9f0() == 0;
                WorldService::GetInstance()->FUN_141bda9c0(bShow);
                CStringW strMsg;
                strMsg.Format(L"Proxy 보기 : %s", bShow != 0 ? L"True" : L"False");
                FUN_1412751b0(strMsg, 0x14);
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x42, 1, 0) != 0) {
                void* pDevice = ((void*)NiRenderer::GetRenderer());
                ((NiDX9Renderer*)pDevice)->SetDeviceLostHeld(reinterpret_cast<bool&>(DAT_1439fa00c));
                if (((void*)FUN_1414a56c0()) != 0) {
                    ((void*)FUN_1414a56c0());
                    GFxService::FUN_1422ea210(DAT_1439fa00c);
                }
                DAT_1439fa00c = DAT_1439fa00c ^ 1;
                CDebugConsole::FUN_141168200()->FUN_1411683e0("SetForceLostDevice : %d", DAT_1439fa00c);
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x44, 1, 0) != 0) {
                TakeScreenshotPng(0);
                FUN_1412751b0(L"SaveScreenShotToPNG", 0x14);
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x55, 1, 0) != 0) {
                if (((class Unk_GsDbgLog*)CDebugConsole::FUN_141168200())->FUN_141168310() != 0) ((class Unk_GsDbgLog*)CDebugConsole::FUN_141168200())->FUN_1411682d0();
                else ((CDebugConsole*)(Unk_GsDbgLog*)(((class Unk_GsDbgLog*)CDebugConsole::FUN_141168200())))->FUN_141168270();
                return 1;
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x56, 1, 0) != 0) {
                if (AfxMessageBox(DAT_142fdeb28, 1, 0) == 1) {
                    void* pNet = Unk_GetRenderService((char*)&DAT_143b059e8);
                    if (pNet != 0) ((class MS2RenderService*)(void*)(pNet))->CheckRenderState();
                    throw 0xd;
                }
                return 1;
            }
        }
    }

    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x927c1, 0, 0)) {
        ((Unk_GsLogin*)FUN_14025e7c0())->SetDebugMode(!((Unk_GsLogin*)FUN_14025e7c0())->IsDebugMode());
        return 1;
    }
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a82, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a82);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a81, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a81);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a85, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a85);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a86, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a86);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a87, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a87);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a89, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a89);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493ee, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x493ee);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8f, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8f);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a90, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a90);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8a, 0, 0)) {
        if (DAT_143ab2914 >= 0x32) ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8a);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8b, 0, 0)) {
        if (DAT_143ab2914 >= 0x32) ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8b);
        return 1;
    }
    else if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dcb0(0x493e2, false, 0)) {
        Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0 && reinterpret_cast<PCBase*>(pPlayer)->IsDead() == 0 && pPlayer->vfunc_63() != 0) {
            if (((Unk_GsMode*)Unk_PlayerActionState((struct Unk_MiPlayer*)(pPlayer)))->TryActivateCurrentAction()) {
            }
            else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493e2, 0, 0)) ((Unk_GsMode*)Unk_PlayerActionState((struct Unk_MiPlayer*)(pPlayer)))->ActivateCurrentAction();
        }
        return 0;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8c, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8c);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493ed, 0, 0)) {
        if (((class CGuideManager*)FUN_1409331e0())->IsRestricted(0x13) != 0) return 1;
        Unk_GsPlayer* pPlayer = ((Unk_GsPlayer*)WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0) {
            if (reinterpret_cast<PC*>(pPlayer)->IsInCubeMode() == 0) reinterpret_cast<MyPC*>(pPlayer)->FUN_14152feb0(1, false);
            else reinterpret_cast<MyPC*>(pPlayer)->SendCraftModeOff();
        }
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a88, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a88);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493f6, 0, 0)) {
        if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
            TSingleton<CameraMgr>::GetInstance()->FUN_140aefa70();
            UIMinimapDialog* pDlg = FUN_140c9b540(0x4e29);
            if (pDlg != 0) pDlg->FUN_141a39e40();
        }
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8d, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8d);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a8e, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a8e);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x49403, 0, 0)) {
        UIGameMenuDialog* pDlg = ((class UIGameMenuDialog*)FUN_140938b90(0x4e28));
        if (pDlg != 0) pDlg->FUN_14193b750();
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x4940a, 0, 0)) {
        UIGameMenuDialog* pDlg = ((class UIGameMenuDialog*)FUN_140938b90(0x4e28));
        if (pDlg != 0) pDlg->FUN_14193bf70();
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x4940b, 0, 0)) {
        UIGameMenuDialog* pDlg = ((class UIGameMenuDialog*)FUN_140938b90(0x4e28));
        if (pDlg != 0) pDlg->FUN_14193bfd0();
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x4940c, 0, 0)) {
        UIGameMenuDialog* pDlg = ((class UIGameMenuDialog*)FUN_140938b90(0x4e28));
        if (pDlg != 0) pDlg->FUN_14193bfa0();
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x49404, 0, 0)) {
        ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbbb0();
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d840()) {
        return FUN_1418fcb70();
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a91, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a91);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a92, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a92);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a93, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a93);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a94, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a94);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a95, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a95);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a96, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a96);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa4, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa4);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa5, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa5);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa6, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa6);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0xc3504, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0xc3504);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a97, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a97);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a98, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a98);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a99, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a99);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9a, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9a);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9b, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9b);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9c, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9c);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9d, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9d);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9e, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9e);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61a9f, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61a9f);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa0, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa0);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa1, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa1);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa2, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa2);
        return 1;
    }
    else if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x61aa3, 0, 0)) {
        ((CKeyTable*)(Unk_GsHk*)(((class Unk_GsHk*)FUN_1409331f0())))->FUN_14142b300(0x61aa3);
        return 1;
    }
    else {
        if (((CFeatureManager*)FUN_140166410())->FUN_14036d570(0xe3)) {
            for (int nKey = 0xdbba1; nKey <= 0xdbbaa; nKey++) {
                if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116dd30(nKey, 0, 0)) {
                    Unk_GsDlg3* pDlg = ((class Unk_GsDlg3*)FUN_141815ed0());
                    if (pDlg != 0) ((UIClosetDialog*)(Unk_GsDlg3*)(pDlg))->RequestById(nKey);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// @0x141acc510
void UISceneGamePlay::FUN_141acc510(NotifyObject* pNotify)
{
    NotifyChangeEnableFeature* pChange = dynamic_cast<NotifyChangeEnableFeature*>(pNotify);
    if (pChange == 0) return;
    reinterpret_cast<Common::Constants*>(FUN_1401d3200())->Load();
    TSingleton<CStringTable>::GetInstance()->FUN_141811960();
    TSingleton<CommonString>::GetInstance()->Reload();
    FUN_1409c51f0();
    FUN_141815db0((void*)FUN_141371b20());
}
MS2_REPLACE_METHOD(0x141acc510, UISceneGamePlay, FUN_141acc510, 125, 0x4F19D812);

// @0x141acc5a0
void FUN_141acc5a0(float fValue)
{
    if (((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbe00(fValue, 0) != 0) ((class Unk_GsTutMgr*)FUN_140b632f0())->vfunc_6();
}

// @0x141acc5f0
int FUN_141acc5f0(int nSceneId)
{
    if (nSceneId != 0) {
        switch (nSceneId) {
        case 0x620001f:
        case 0x6200020:
        case 0x6200022:
        case 0x6200031:
        case 0x6200041:
        case 0x620007f:
            return 1;
        }
    }
    return 0;
}

// @0x141acc6c0
int FUN_141acc6c0(int nSceneId)
{
    switch (nSceneId) {
    case 0x620001f:
    case 0x6200022:
    case 0x6200031:
    case 0x6200041:
    case 0x620007f:
        return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UISceneGameScreenShot

class Unk_GsEntMgr;
class Unk_HwService : public HardwareInstancingService { };     // the framework's hardware instancing service
#include "ms2/client/ms2/ms2.h"   // C3: MS2::SetBackgroundColor (the app's clear colour)
class EntityWorldManager;
void FUN_14098c6e0(class Unk_CachedEntity* pEntity, unsigned int nHash, const bool& bValue);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
class Unk_HwService* FUN_14098c5b0(struct Unk_EntityAppFramework*);   // C3: was FUN_14098c5b0
void FUN_1413f9c40(bool bFlag);
void* FUN_140aae430();   // C3: was FUN_140aae430
extern char DAT_142fdef20[];

// @0x141acd1c0
UISceneGameScreenShot::UISceneGameScreenShot() : m_a8(10)
{
    m_6c = 0x6200020;
}

// @0x141acd230
CString UISceneGameScreenShot::GetTypeName()
{
    return "";
}
MS2_REPLACE_METHOD(0x141acd230, UISceneGameScreenShot, GetTypeName, 61, 0x17DAEDA3);

// @0x141acd280
bool UISceneGameScreenShot::vfunc_47()
{
    return false;
}
MS2_REPLACE_METHOD(0x141acd280, UISceneGameScreenShot, vfunc_47, 8, 0x41132FCD);

// @0x141acd290
void UISceneGameScreenShot::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    m_a8.RemoveAll();
    Unk_WorldEntityMap::iterator kIter = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411ce4c0();
    egf::Entity* pEntity;
    while (TSingleton<EntityWorldManager>::GetInstance()->FUN_1411ce510(kIter, pEntity)) {
        bool bSkip = false;
        bool bChar = pEntity->GetModel()->ContainsModel(DAT_142fdef20) || pEntity->GetModel()->ContainsModel("Actor");
        if (bChar) {
            efd::SmartPointer<Unk_HwService> spSvc(FUN_14098c5b0((struct Unk_EntityAppFramework*)(&DAT_143b059e8)));
            if ((Unk_HwService*)spSvc != 0) {
                if (spSvc->FUN_1413d6890(pEntity) != 0) bSkip = true;
                else bSkip = ((void*)((HardwareInstancingService*)(spSvc.operator->()))->FUN_1413d66b0(pEntity)) ? true : false;
            }
            if (!bSkip) {
                bool bValue = true;
                if (pEntity->GetPropertyValue<bool>(0xa0b6b179, bValue) == 0 && bValue) m_a8.AddTail(pEntity->GetEntityID());
            }
        }
    }
    for (POSITION pos = m_a8.GetHeadPosition(); pos != 0; m_a8.GetNext(pos)) {
        egf::EntityID id = m_a8.GetAt(pos);
        egf::Entity* pHidden = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(id);
        if (pHidden != 0) {
            bool bShown = false;
            FUN_14098c6e0((class Unk_CachedEntity*)pHidden, 0xa0b6b179, bShown);
        }
    }
    FUN_1413f9c40(false);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9b30();
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbca0(0);
    ShowCursor(TRUE);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141acd290, UISceneGameScreenShot, vfunc_48, 838, 0x4471B5A7);

// @0x141acd5e0
void UISceneGameScreenShot::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    for (POSITION pos = m_a8.GetHeadPosition(); pos != 0; m_a8.GetNext(pos)) {
        egf::EntityID id = m_a8.GetAt(pos);
        egf::Entity* pHidden = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(id);
        if (pHidden != 0) {
            bool bShown = true;
            FUN_14098c6e0((class Unk_CachedEntity*)pHidden, 0xa0b6b179, bShown);
        }
    }
    FUN_1413f9c40(true);
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141ad9650();
    ((class Unk_GsUI*)TSingleton<CUIService>::GetInstance())->FUN_141adbca0(1);
    ((class MS2*)FUN_140aae430())->SetBackgroundColor(efd::ColorA::BLACK);
    ShowCursor(FALSE);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141acd5e0, UISceneGameScreenShot, vfunc_49, 329, 0xC3B72AAD);

// @0x141acd730
void UISceneGameScreenShot::vfunc_57()
{
    UISceneEntity::vfunc_57();
}
MS2_REPLACE_METHOD(0x141acd730, UISceneGameScreenShot, vfunc_57, 24, 0xDE7FCC7E);

// @0x141acd750
int UISceneGameScreenShot::vfunc_13()
{
    if (UISwfEntity::vfunc_13()) return 1;
    if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d950(0x1d, 0, 0) != 0) {
        if (((Unk_GsLogin*)FUN_14025e7c0())->FUN_14116d9c0(0x14, 1, 0) != 0) {
            FUN_1422e7a40(0x620001d);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141acd750, UISceneGameScreenShot, vfunc_13, 121, 0x77A86C42);

// @0x141acd7d0
int UISceneGameScreenShot::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141acd7d0, UISceneGameScreenShot, vfunc_28, 67, 0x32BD72BD);

// @0x141acd820
// ~UISceneGameScreenShot is implicit (the exe dtor has no vftable store); emitted via ??_G.
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc20d0-0x142cc23d0 .text$yd
// The skill/stun header-static initializers and atexit thunks are byte look-alikes (pinned).
// MS2-PIN: ??__Es_skill1@@YAXXZ 0x14011c560 ; probe
// MS2-PIN: ??__Es_stun1@@YAXXZ 0x14011c590 ; probe
// MS2-PIN: ??__Es_skill2@@YAXXZ 0x14011c720 ; probe
// MS2-PIN: ??__Es_stun2@@YAXXZ 0x14011c750 ; probe
// MS2-PIN: ??__Es_skill3@@YAXXZ 0x14011c800 ; probe
// MS2-PIN: ??__Es_stun3@@YAXXZ 0x14011c830 ; probe
// MS2-PIN: ??__Es_skill4@@YAXXZ 0x14011c920 ; probe
// MS2-PIN: ??__Es_stun4@@YAXXZ 0x14011c950 ; probe
// MS2-PIN: ??__Fs_skill1@@YAXXZ 0x142cc2130 ; probe
// MS2-PIN: ??__Fs_stun1@@YAXXZ 0x142cc2150 ; probe
// MS2-PIN: ??__Fs_skill2@@YAXXZ 0x142cc21e0 ; probe
// MS2-PIN: ??__Fs_stun2@@YAXXZ 0x142cc2200 ; probe
// MS2-PIN: ??__Fs_skill3@@YAXXZ 0x142cc2260 ; probe
// MS2-PIN: ??__Fs_stun3@@YAXXZ 0x142cc2280 ; probe
// MS2-PIN: ??__Fs_skill4@@YAXXZ 0x142cc22d0 ; probe
// MS2-PIN: ??__Fs_stun4@@YAXXZ 0x142cc22f0 ; probe
