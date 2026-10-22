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
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiscenegame.cpp"
#include "ms2/placeholder/ms2stdafx.h"

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
static CString s_systemKillSlayer = "System_KillSlayer";
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
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/delegate.h"
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "hook/ms2hook.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

class Unk_GsUI                                          // the UI service (FUN_1403ed2b0)
{
public:
    int FUN_141adbe00(float f, int n);
    void FUN_141adbcd0(int n);
    void FUN_141adbf00();
    void FUN_141add6e0(int nUiId);
    void FUN_141ada6f0(int nSceneId);
    void FUN_141add040(int nUiId);
    void FUN_141adad20(int nSceneId);
    void FUN_141adbb40();
    void FUN_141adbbb0();
    void FUN_141adc530(int nUiId);
    void FUN_141adc5d0(int nUiId);
    int FUN_141adc940(int nUiId);
    void FUN_141adb4c0(int n);
    void FUN_141ada610(int nSceneId);
    void FUN_141add0b0(int nUiId);
    void FUN_141ad9e50(int nSceneId);
    void FUN_141add1b0(int a, int b);
    void FUN_141adcb60(int n);
    void FUN_141adc750(int nUiId);
    void FUN_141ad9b30();
    void FUN_141adbca0(int n);
    void FUN_141ad9650();
};
class Unk_GsSettings { public: char FUN_1401d1320(); void FUN_140556ea0(); };
class Unk_GsNpcMgr { public: int FUN_140428830(); };
class Unk_GsPubtest { public: Unk_GsNpcMgr* FUN_1403ed9c0(); };
class Unk_GsLogin
{
public:
    bool FUN_14116d9c0(int a, bool b, int c);
    bool FUN_14116dd30(int a, int b, int c);
    bool FUN_14116d950(int a, bool b, int c);
    bool FUN_14116dcb0(int a, int b, int c);
    bool FUN_14116d7a0(int a);
    bool FUN_14116d840();
    bool FUN_14116d720();
    void FUN_14116d5d0(bool b);
};
class Unk_GsCamArg { public: Unk_GsCamArg(); int m_0, m_4, m_8, m_c, m_10, m_14, m_18, m_1c, m_20, m_24; };
MS2_CHECK_SIZE(Unk_GsCamArg, 0x28);
class Unk_GsWindow { public: int FUN_141b712e0(); };
class Unk_GsSceneId;
class Unk_GsServerDlg : public UIDialog { public: void FUN_141ad2ef0(); };

Unk_GsUI* FUN_1403ed2b0();
Unk_GsLogin* FUN_14025e7c0();
Unk_GsWindow* FUN_140aadf80();
Unk_GsSceneId* FUN_1408e57f0();
Unk_GsSettings* FUN_140281980();
Unk_GsPubtest* FUN_140302b00();
int FUN_1422b9e00(Unk_GsSceneId* p);
void FUN_1422b9fd0(Unk_GsSceneId* p, int nScene);
extern int DAT_143ab0248;
extern int DAT_143ab2914;
CStringW FUN_141850100(int a, int b);
CStringW GetStringCommon(int nId);
CStringW GetStringCommonByKey(const CStringW& str);
void FUN_1412751b0(const CStringW& str, int nFlags);
void FUN_141b91b20(bool b);
void FUN_141a60d40(int n);
class Unk_GsA { public: void FUN_14162a480(); };
class Unk_GsB { public: void FUN_1413b5f90(); };
class Unk_GsC { public: void FUN_14137e190(); };
class Unk_GsD { public: void FUN_140b2ab00(); };
class Unk_GsE { public: void FUN_140b14c50(); };
class Unk_GsF { public: void FUN_141b20af0(); int FUN_141b20ac0(); void FUN_141b1feb0(); };
class Unk_GsDlg1 { public: void FUN_14129cb20(); };
class Unk_GsDlg2 { public: void FUN_140ef6920(); };
class Unk_GsDlg3 { public: void FUN_140be18a0(); void FUN_140be1910(int n); };
Unk_GsA* FUN_1409670d0();
Unk_GsB* FUN_1403ed290();
Unk_GsC* FUN_141484720();
Unk_GsD* FUN_140b2e980();
Unk_GsE* FUN_140e0d900();
Unk_GsF* FUN_140967100();
Unk_GsDlg1* FUN_140bc1870(int nUiId);
Unk_GsDlg2* FUN_141742590(int nUiId);
Unk_GsDlg3* FUN_141815ed0();

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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGame::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    if (FUN_140281980()->FUN_1401d1320() != 0) FUN_140281980()->FUN_140556ea0();
    FUN_141a60d40(1);
    static int s_bWelcomeShown;
    if (s_bWelcomeShown == 0) {
        if (FUN_140302b00()->FUN_1403ed9c0()->FUN_140428830() == 0) {
            FUN_1412751b0(GetStringCommon(0x2d6), 0x14);
        } else {
            FUN_1412751b0(GetStringCommonByKey(CStringW(L"s_msg_chatting_welcome_pubtest2")), 0x14);
        }
        s_bWelcomeShown = 1;
    }
    FUN_1422e7a40(0x620001d);
    FUN_1403ed2b0()->FUN_141add6e0(0x3ed);
    FUN_1422e7950();
}

// @0x141ac74f0
void UISceneGame::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_1409670d0()->FUN_14162a480();
    FUN_1403ed290()->FUN_1413b5f90();
    FUN_141484720()->FUN_14137e190();
    FUN_140b2e980()->FUN_140b2ab00();
    FUN_140e0d900()->FUN_140b14c50();
    FUN_1403ed2b0()->FUN_141adb4c0(1);
    FUN_1403ed2b0()->FUN_141ada610(0x620001d);
    FUN_1403ed2b0()->FUN_141adad20(0x620001d);
    FUN_141a60d40(0);
    FUN_1403ed2b0()->FUN_141add0b0(0x4e55);
    FUN_1403ed2b0()->FUN_141add0b0(0x4e41);
    Unk_GsDlg1* pDlg1 = FUN_140bc1870(0x4edd);
    if (pDlg1 != 0) pDlg1->FUN_14129cb20();
    Unk_GsDlg2* pDlg2 = FUN_141742590(0x4efd);
    if (pDlg2 != 0) pDlg2->FUN_140ef6920();
    Unk_GsDlg3* pDlg3 = FUN_141815ed0();
    if (pDlg3 != 0) pDlg3->FUN_140be18a0();
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac74f0, UISceneGame, vfunc_49, 298, 0x93FAE665);

// @0x141ac7620
void UISceneGame::vfunc_15()
{
    UISwfEntity::vfunc_15();
    FUN_140967100()->FUN_141b20af0();
}
MS2_REPLACE_METHOD(0x141ac7620, UISceneGame, vfunc_15, 37, 0x043AEAC5);

// @0x141ac7650
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
int UISceneGame::vfunc_13()
{
    if (UISwfEntity::vfunc_13()) return 1;
    if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0) == 0) {
        if (FUN_14025e7c0()->FUN_14116dd30(0x493ef, 0, 0)) {
            FUN_141850100(0, 0);
            return 1;
        }
    } else {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x16, 1, 0)) {
            if (FUN_14025e7c0()->FUN_14116d950(0x38, 1, 0)) {
                if (FUN_140aadf80() != 0) {
                    int n = FUN_140aadf80()->FUN_141b712e0();
                    FUN_141b91b20(n == 1);
                }
                return 1;
            }
            if (DAT_143ab0248 != 2 || DAT_143ab2914 >= 0x34) FUN_1403ed2b0()->FUN_141adbb40();
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x14, 1, 0)) {
            if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d) {
                FUN_1422e7a40(0x6200020);
            } else if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200020) {
                FUN_1422e7a40(0x620001d);
            }
            return 1;
        }
    }
    return FUN_140967100()->FUN_141b20ac0();
}
MS2_REPLACE_METHOD(0x141ac7650, UISceneGame, vfunc_13, 467, 0xEE67B3FF);

// @0x141ac7830
int UISceneGame::vfunc_14()
{
    if (UISwfEntity::vfunc_14()) return 1;
    if (FUN_14025e7c0()->FUN_14116dd30(0x493ef, 0, 0) != 0) {
        FUN_141850100(0, 0);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac7830, UISceneGame, vfunc_14, 101, 0x48E1F71D);

// @0x141ac78a0
void UISceneGame::vfunc_55()
{
    UISceneEntity::vfunc_55();
    FUN_1403ed2b0()->FUN_141add040(0x4e55);
    FUN_1403ed2b0()->FUN_141add040(0x4e41);
}
MS2_REPLACE_METHOD(0x141ac78a0, UISceneGame, vfunc_55, 60, 0x44521706);

// @0x141ac78f0
void UISceneGame::vfunc_56()
{
    UISceneEntity::vfunc_56();
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d) {
        FUN_1422e7a40(0x620001d);
        FUN_140967100()->FUN_141b1feb0();
    }
    FUN_1403ed2b0()->FUN_141add0b0(0x4e55);
    FUN_1403ed2b0()->FUN_141add0b0(0x4e41);
}
MS2_REPLACE_METHOD(0x141ac78f0, UISceneGame, vfunc_56, 108, 0xF5771772);

// The scene-list glue (CAtlList<Unk_ScenePtr<UISceneEntity> >: 0x141ac7960-0x141ac7d50, 0x141ac7da0) is paired by tplpin.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UISceneGameBeautyShop

#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/commandchat.h"

class Unk_GsEnt { public: Vector3 FUN_14169d2f0(); };
class Unk_GsObjRef { public: void* FUN_140c9b7d0(); Unk_GsEnt* FUN_140965960(); void FUN_140964a70(); void* m_0; void* m_8; };
MS2_CHECK_SIZE(Unk_GsObjRef, 0x10);
class Unk_GsMode { public: void FUN_140953310(); bool FUN_140953410(); };
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
    int FUN_1416764d0();                                // is riding
    void FUN_14152c280(RideOffActionBeautyShop* pAction);
    void FUN_14166d8e0(Vector3 kDir);
    void FUN_14166cc40(int n);
    int FUN_14166c930();
    int FUN_14166ce30();
    Unk_GsMode* FUN_140a7b810();
    char FUN_141527280();
    int FUN_1416595d0();
    void FUN_14152feb0(int a, int b);
    void FUN_141530200();
};
class Unk_GsWorld
{
public:
    Unk_GsPlayer* FUN_141bd0cc0();
    Unk_GsPlayer* FUN_141bd1320(int nId);
    Unk_GsObjRef FUN_141bc2800(int nId);
    void FUN_141bd3c00(bool b);
    unsigned FUN_141bd3060();
    void FUN_141bd2fa0();
    void FUN_141bdabb0();
    int FUN_141bda9f0();
    void FUN_141bda9c0(int n);
};
class Unk_GsCamParam
{
public:
    int m_0; float m_4; Vector3 m_8; Vector3 m_14; Vector3 m_20; char m_pad2c[4];
    Vector3 m_30; Vector3 m_3c; Vector3 m_48; char m_pad54[0x10]; Vector3 m_64; char m_pad70[0x10];
};
MS2_CHECK_SIZE(Unk_GsCamParam, 0x80);
class Unk_GsCamera2                                     // the active camera state (FUN_140af24f0)
{
public:
    float FUN_140ad4b30();
    float FUN_140af7ef0();
    float FUN_140af7e90();
    Vector3 FUN_140af8260();
};
class Unk_GsCamera                                      // the camera service (FUN_1409478c0)
{
public:
    char m_pad_00[0xe0];
    Vector3 m_e0;                               // +0xe0
    int FUN_140a18070();
    void FUN_140aefa70();
    float FUN_140ad4b40();
    float FUN_140af7f00();
    float FUN_140af7ea0();
    Vector3 FUN_140a17e10();
    Vector3 FUN_140af8290();
    int FUN_140af0210();
    Unk_GsCamera2* FUN_140af24f0();
    void FUN_140aed580(Unk_GsCamParam* pParam, int n, float f);
    void FUN_140aed750(int a, int b);
};
class Unk_GsPhysics;
int FUN_14168a310(Unk_GsPhysics* pPhysics, const Vector3* pFrom, Vector3* pHit, void* pInfo, float fRange, __int64 n, int nMask);
class Unk_GsGround { public: int FUN_1410d2f10(); };

Unk_GsWorld* FUN_1403ed2d0();
Unk_GsCamera* FUN_1409478c0();
Unk_GsGround* FUN_1409670e0();
Unk_GsPhysics* FUN_1409f7ca0();
void FUN_141901390(int nRelease, int nUiType);
void FUN_14151f200();
void FUN_141ac9310(Vector3* pRot, Vector3* pDir, Vector3* pOut);
void FUN_140947440(Unk_GsCamParam* pParam);                 // the camera parameter ctor
void FUN_140ae7de0(Vector3* pDst, const Vector3* pSrc);
extern Vector3 DAT_143a08cf8;                       // the up vector
struct Unk_GsMatrix3
{
    Unk_GsMatrix3() {}                                      // 0x1409f72e0
    void FUN_142083d40(float fX, float fY, float fZ);       // efd::Matrix3::FromEulerAnglesXYZ
    void FUN_140a01190(unsigned uiCol, Vector3& kCol) const;   // GetCol
    float m_afEntry[3][3];
};
MS2_CHECK_SIZE(Unk_GsMatrix3, 0x24);
Vector3 FUN_1420834e0(Vector3* pPt, Unk_GsMatrix3* pMat);    // efd::operator*(Point3, Matrix3)
Vector3 FUN_140afdd40(Vector3* pA, Vector3* pB, Vector3* pC);
class Unk_GsUIMsg : public UIMsg
{
public:
    Unk_GsUIMsg();                                          // 0x1422e4490
    ~Unk_GsUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    int FUN_1422b8b10();
    void* m_pad[10];
};
Unk_GsServerDlg* FUN_140c300a0(int nUiId);

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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
    FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
    FUN_141901390(0, 0x3eb);
    FUN_1403ed2b0()->FUN_141adbe00(1.0f, 0);
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0) {
        FUN_1422b9fd0(FUN_1408e57f0(), n);
    } else if (pPlayer->FUN_1416764d0() == 0) {
        FUN_141ac8e90();
    } else {
        pPlayer->FUN_14152c280(new RideOffActionBeautyShop(0));
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
    FUN_1403ed2b0()->FUN_141ada610(m_6c);
    FUN_1403ed2b0()->FUN_141adad20(m_6c);
    FUN_1403ed2b0()->FUN_141adc5d0(m_ac);
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

class Unk_GsFn { public: void* m_pad_00[5]; };
MS2_CHECK_SIZE(Unk_GsFn, 40);
class Unk_GsAS : public AScript { public: Unk_GsFn FUN_1422bb330(const char* szName); };
AScript* FUN_1409ee240(MS2Ptr<AScript>* p);
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
void FUN_140614800(const Unk_GsFn& fn);

// @0x141ac8290
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::vfunc_50()
{
    UISceneEntity::vfunc_50();
    if (m_ac == 0x4e24) {
        if (FUN_1409ee240(&m_30) != 0) {
            FUN_140614800(static_cast<Unk_GsAS*>(FUN_1409ee290(&m_30))->FUN_1422bb330("setItemEditMode"));
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
int UISceneGameBeautyShop::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp("OnExit", szMethod) != 0) return 0;
    if (m_ac == 0) {
        FUN_1422e7a40(0x620001d);
    } else {
        Unk_GsUIMsg msg;
        msg.FUN_1422b82b0(szMethod);
        Unk_GsServerDlg* pDlg = FUN_140c300a0(m_ac);
        if (pDlg != 0) pDlg->OnMessage(this, &msg);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141ac8370, UISceneGameBeautyShop, vfunc_28, 287, 0x626F67EB);

// @0x141ac84a0
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
int UISceneGameBeautyShop::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    UISwfEntity::OnMessage(pSender, pMsg);
    if (pMsg->FUN_1422e4520() != 0) return 0;
    CString strMethod = pMsg->FUN_1422b8d30();
    if (_stricmp("moveMyPC", strMethod) == 0) {
        m_b0 = pMsg->FUN_1422b8a10();
        m_b4 = static_cast<Unk_GsUIMsg*>(pMsg)->FUN_1422b8b10();
        return 1;
    }
    if (_stricmp("openDialog", strMethod) == 0) {
        m_ac = pMsg->FUN_1422b8a10();
        return 1;
    }
    if (_stricmp("setCubeID", strMethod) == 0) {
        m_b8 = pMsg->FUN_1422b8d30();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac84a0, UISceneGameBeautyShop, OnMessage, 425, 0x799116AE);

// @0x141ac8660
void UISceneGameBeautyShop::FUN_141ac8660()
{
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0) return;
    if (FUN_1409478c0()->FUN_140a18070() == 0) return;
    pPlayer->FUN_14166d8e0(Vector3(0.0f, -1.0f, 0.0f));
    pPlayer->vfunc_59(0xe, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x141ac8660, UISceneGameBeautyShop, FUN_141ac8660, 160, 0xC0E3A86A);

// @0x141ac8710
void UISceneGameBeautyShop::FUN_141ac8710()
{
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0) {
        pPlayer->FUN_14166d8e0(Vector3(0.0f, -1.0f, 0.0f));
        pPlayer->FUN_14166cc40(0x4d);
        pPlayer->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x141ac8710, UISceneGameBeautyShop, FUN_141ac8710, 154, 0x8790D479);

// @0x141ac87b0
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::FUN_141ac87b0()
{
    if (FUN_1409478c0()->FUN_140a18070() != 0) {
        Unk_GsCamParam param;
        FUN_140947440(&param);
        param.m_0 = 1;
        param.m_4 = 0.8f;
        param.m_8.x = FUN_1409478c0()->FUN_140ad4b40();
        param.m_8.y = FUN_1409478c0()->FUN_140af7f00();
        param.m_8.z = FUN_1409478c0()->FUN_140af7ea0();
        param.m_14 = FUN_1409478c0()->FUN_140a17e10();
        param.m_20 = FUN_1409478c0()->FUN_140af8290();
        param.m_30.x = param.m_8.x;
        param.m_30.y = param.m_8.y;
        param.m_30.z = param.m_8.z;
        FUN_141ac8b00(&param.m_3c, &param.m_48, &param.m_64);
        FUN_1409478c0()->FUN_140aed580(&param, 1, 1.0f);
        FUN_1409478c0()->FUN_140aed750(4, 0);
    }
}
MS2_REPLACE_METHOD(0x141ac87b0, UISceneGameBeautyShop, FUN_141ac87b0, 319, 0x5E0960A6);

// @0x141ac8900
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::FUN_141ac8900()
{
    if (FUN_1409478c0()->FUN_140a18070() != 0) {
        Unk_GsCamParam param;
        FUN_140947440(&param);
        param.m_0 = 1;
        param.m_4 = 1.0f;
        param.m_8.x = FUN_1409478c0()->FUN_140ad4b40();
        param.m_8.y = FUN_1409478c0()->FUN_140af7f00();
        param.m_8.z = FUN_1409478c0()->FUN_140af7ea0();
        param.m_14 = FUN_1409478c0()->FUN_140a17e10();
        param.m_20 = FUN_1409478c0()->FUN_140af8290();
        if (FUN_1409670e0()->FUN_1410d2f10() == 0) {
            FUN_140ae7de0(&param.m_30, &param.m_8);
            param.m_30.x = FUN_1409478c0()->FUN_140af24f0()->FUN_140ad4b30();
            param.m_30.y = FUN_1409478c0()->FUN_140af24f0()->FUN_140af7ef0();
            param.m_30.z = FUN_1409478c0()->FUN_140af24f0()->FUN_140af7e90();
            param.m_48 = FUN_1409478c0()->FUN_140af24f0()->FUN_140af8260();
            FUN_1409478c0()->FUN_140aed580(&param, 1, 1.0f);
            FUN_1409478c0()->FUN_140aed750(2, 1);
        } else {
            FUN_140ae7de0(&param.m_30, &FUN_1409478c0()->m_e0);
            FUN_1409478c0()->FUN_140aed580(&param, 1, 1.0f);
            FUN_1409478c0()->FUN_140aed750(0x11, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x141ac8900, UISceneGameBeautyShop, FUN_141ac8900, 491, 0x9741E8D2);

// @0x141ac8b00
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::FUN_141ac8b00(Vector3* pOut1, Vector3* pOut2, Vector3* pOut3)
{
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0) return;
    Vector3 kA;
    Vector3 kB;
    if (FUN_1409670e0()->FUN_1410d2f10() != 0 && FUN_1409478c0()->FUN_140af0210() != 0) {
        Vector3 kEuler = FUN_1409478c0()->FUN_140af8290().FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
        Unk_GsMatrix3 mX;
        mX.FUN_142083d40(-90.0f, 0.0f, 0.0f);
        Unk_GsMatrix3 mY;
        mY.FUN_142083d40(kEuler.x, kEuler.y, kEuler.z);
        mY.FUN_140a01190(0, kA);
        kA = FUN_1420834e0(&kA, &mX);
        kA.z = 0.0f;
        kA.FUN_140968990();
        kB = kA.FUN_140a00e10(DAT_143a08cf8).FUN_1409f7960();
    } else {
        Vector3 kCam = FUN_1409478c0()->FUN_140af8290();
        FUN_141ac9310(&kCam, &kA, &kB);
    }
    kA = kA.FUN_1409f7960();
    Vector3 kP = pPlayer->vfunc_18().FUN_14097fd50(kA.FUN_14097fc90(350.0f));
    kP.z += 80.0f;
    Vector3 kQ = pPlayer->vfunc_18().FUN_14097fd50(kB.FUN_14097fc90(-50.0f));
    kQ.z += 80.0f;
    *pOut3 = kQ;
    *pOut1 = kP;
    *pOut2 = FUN_140afdd40(pOut3, &kP, &DAT_143a08cf8);
}
MS2_REPLACE_METHOD(0x141ac8b00, UISceneGameBeautyShop, FUN_141ac8b00, 867, 0x333C6E82);

// @0x141ac8e70
void UISceneGameBeautyShop::FUN_141ac8e70(int nDialogMode)
{
    m_a8 = nDialogMode;
}
MS2_REPLACE_METHOD(0x141ac8e70, UISceneGameBeautyShop, FUN_141ac8e70, 25, 0xD3EC7A67);

// @0x141ac8e90
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameBeautyShop::FUN_141ac8e90()
{
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0) return;
    bool bMoved = false;
    if (m_b0 != 0) {
        Unk_GsObjRef ref = FUN_1403ed2d0()->FUN_141bc2800(m_b0);
        if (ref.FUN_140c9b7d0() != 0) {
            Vector3 kHit;
            Vector3 kFrom = ref.FUN_140965960()->FUN_14169d2f0();
            if (FUN_14168a310(FUN_1409f7ca0(), &kFrom, &kHit, 0, 0.0f, 0, 0) != 0) {
                kHit.z += 1.0f;
                pPlayer->vfunc_19(kHit);
                bMoved = true;
            }
        }
        ref.FUN_140964a70();
    }
    if (!bMoved && m_b4 != 0) {
        Unk_GsPlayer* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_b4);
        if (pNpc != 0) {
            Vector3 kHit;
            Vector3 kDir = pPlayer->vfunc_18().FUN_140965c40(FUN_1409478c0()->FUN_140a17e10());
            kDir.FUN_140968990();
            kDir.z = 0.0f;
            Vector3 kFrom = pNpc->vfunc_18().FUN_140965c40(kDir.FUN_14097fc90(100.0f));
            if (FUN_14168a310(FUN_1409f7ca0(), &kFrom, &kHit, 0, 0.0f, 0, 0) != 0) {
                kHit.z += 1.0f;
                pPlayer->vfunc_19(kHit);
            }
        }
    }
    FUN_141ac8660();
    FUN_141ac87b0();
    FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
    FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
    m_ac = (m_a8 == 0) ? m_ac : 0x4e79;
    if (m_ac != 0) FUN_1403ed2b0()->FUN_141adc530(m_ac);
}
MS2_REPLACE_METHOD(0x141ac8e90, UISceneGameBeautyShop, FUN_141ac8e90, 979, 0xB916CD23);

// @0x141ac9270
void UISceneGameBeautyShop::FUN_141ac9270()
{
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0) {
        if (pPlayer->FUN_14166c930() != 0xe) pPlayer->vfunc_59(0xe, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x141ac9270, UISceneGameBeautyShop, FUN_141ac9270, 93, 0xEF3CF752);

// @0x141ac9310
void FUN_141ac9310(Vector3* pRot, Vector3* pDir, Vector3* pOut)
{
    *pRot = pRot->FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
    Unk_GsMatrix3 m;
    m.FUN_142083d40(pRot->x, pRot->y, pRot->z);
    m.FUN_140a01190(0, *pDir);
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
class Unk_GsScale
{
public:
    float FUN_1422afec0(int nLayer);
    int FUN_1422aff10(float fScale);
    void FUN_1422aed30(int n);
    int FUN_1422aeed0(int n);
};
class Unk_GsTutMgr
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6();                             // 0x30
    char FUN_1410af770();
};
Unk_GsCineMgr* FUN_140a94350();
Unk_GsTalkTarget* FUN_141482e80();
void FUN_141a251f0(void* pTarget, int n);
Unk_GsScale* FUN_14025e7a0();
Unk_GsTutMgr* FUN_140b632f0();
float FUN_141ac9b00();
extern Vector3 DAT_143b01a60;
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
    Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0) pPlayer->vfunc_22(DAT_143b01a60);
    FUN_141901390(0, vfunc_65());
    FUN_1403ed2d0()->FUN_141bd3c00(false);
    FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
    FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
    FUN_140a94350()->vfunc_10(0xb);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9520, UISceneGameCinematicCutScene, vfunc_48, 237, 0x608CA992);

// @0x141ac9620
void UISceneGameCinematicCutScene::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_141901390(1, vfunc_65());
    FUN_1403ed2d0()->FUN_141bd3c00(true);
    FUN_1403ed2b0()->FUN_141ada610(m_6c);
    FUN_1403ed2b0()->FUN_141adad20(m_6c);
    FUN_140a94350()->vfunc_10(0);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9620, UISceneGameCinematicCutScene, vfunc_49, 158, 0x0B53EFBE);

// @0x141ac96d0
void UISceneGameCinematicCutScene::vfunc_54()
{
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameCinematicTalk::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
    FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
    FUN_1403ed2b0()->FUN_141add1b0(4, 1);
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0) {
        if (FUN_141482e80()->m_48 != 0) FUN_141a251f0(FUN_141482e80()->m_48, 0);
    }
    m_b0 = FUN_14025e7a0()->FUN_1422afec0(m_28);
    float fScale = FUN_141ac9b00();
    if (FUN_14025e7a0()->FUN_1422aff10(fScale) != 0) FUN_140b632f0()->vfunc_6();
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac98a0, UISceneGameCinematicTalk, vfunc_48, 253, 0xDD0D19F1);

// @0x141ac99b0
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameCinematicTalk::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_1403ed2b0()->FUN_141ada610(m_6c);
    FUN_1403ed2b0()->FUN_141adad20(m_6c);
    FUN_1403ed2b0()->FUN_141add1b0(4, 0);
    FUN_1403ed2d0()->FUN_141bd0cc0();
    if (FUN_141482e80()->m_48 != 0) FUN_141a251f0(FUN_141482e80()->m_48, 1);
    if (FUN_14025e7a0()->FUN_1422aff10(m_b0) != 0) FUN_140b632f0()->vfunc_6();
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

class Unk_GsMouseEff { public: void FUN_1411a8880(int n); };
class Unk_GsInvis { public: char FUN_140d9f5d0(int n); };
class Unk_GsTexReload
{
public:
    char m_pad_00[0xcc];
    int m_cc;
    int FUN_141acccb0() { return m_cc; }                    // 0x141acccb0
    void FUN_141accee0(int n) { m_cc = n; }                 // 0x141accee0
};
class Unk_GsDlgA { public: void FUN_1419246f0(); };
class Unk_GsStrTbl { public: void FUN_141811960(); };
class Unk_GsSnd { public: void FUN_140259930(); };
class Unk_GsPal { public: void FUN_141815db0(); };
class Unk_GsRel { public: void FUN_141021140(); };
class Unk_GsDbgLog { public: char FUN_141168310(); void FUN_141168270(); void FUN_1411682d0(); void FUN_1411683e0(const char* szFormat, int n); };
class Unk_GsHk { public: void FUN_14142b300(int nId); };
class Unk_GsHk2 { public: int FUN_14138c900(int n); };
class Unk_GsDlgB { public: void FUN_14193b750(); void FUN_14193bf70(); void FUN_14193bfd0(); void FUN_14193bfa0(); };
class Unk_GsDlgC { public: void FUN_141a39e40(); };
class Unk_GsUnit { public: void FUN_1419f5ab0(); };
class Unk_GsHud { public: void FUN_140d406d0(int n); };
class Unk_GsHudInfo { public: char m_pad_00[8]; float m_8; };
class Unk_GsFlags2 { public: char FUN_14036d570(int n); };
class Unk_GsFx { public: void FUN_1416ca670(); };
class Unk_GsNotices { public: void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb); void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
class Unk_GsMapPtr
{
public:
    ~Unk_GsMapPtr();                                        // 0x1408850f0
    void* FUN_1409657a0();
    CFieldData* FUN_140885340();
    void* m_pad_00; CFieldData* m_p;
};
class Unk_GsAppG;
class Unk_GsCa { public: void FUN_1402b7200(); };
Unk_GsCa* FUN_1401d3200();
void FUN_141acc5a0(float fValue);
int FUN_141acc5f0(int nSceneId);
int FUN_141acc6c0(int nSceneId);
class Unk_GsCommon;
Unk_GsHud* FUN_1409bb9e0();
void* FUN_1409a8b10();
Unk_GsHudInfo* FUN_140e09150(void* p);
void FUN_141b70290();
void FUN_141242990(void* p);
char* FUN_140a58500(void* p);
void FUN_14125f670(char* p, char a, int b);
char* FUN_140c58ac0(void* p);
void FUN_14125bd20(char* p, char a);
Unk_GsUnit* FUN_140e01890(int nId);
void FUN_1408e48f0(void* p);
extern char DAT_143ab2ee0;
Unk_GsFx* FUN_140764020();
Unk_GsNotices* FUN_140939a10();
Unk_GsMapPtr FUN_140a55460(unsigned nFieldId);
void FUN_141275260(int nId, int a, int b);
void FUN_141276180(const CString& a, const CString& b);
extern CString DAT_143af6008;
int FUN_1418fcb70();
Unk_GsMouseEff* FUN_1403ed280();
Unk_GsInvis* FUN_140931510();
Unk_GsTexReload* FUN_140a0afd0();
Unk_GsDlgA* FUN_14167a900(int nId);
Unk_GsStrTbl* FUN_1401a9d70();
Unk_GsSnd* FUN_14025e7d0();
Unk_GsPal* FUN_141371b20();
Unk_GsRel* FUN_141371b30();
void FUN_140c9cb10();
void FUN_1417af7a0();
void FUN_1409c51f0();
void FUN_141a0df10();
void FUN_140710590(COutPacket& packet);
void FUN_141276f80(const struct Unk_CommandChat& cmd);
void FUN_1418508e0(int n);
void* FUN_140994450();
void FUN_1427d5c10(void* p, unsigned char b);
void* FUN_1414a56c0();
void FUN_1422ea210(unsigned char b);
Unk_GsDbgLog* FUN_141168200();
void* FUN_14127bf80(Unk_GsAppG* p);
void FUN_1414ea8b0(void* p);
Unk_GsHk* FUN_1409331f0();
Unk_GsHk2* FUN_1409331e0();
Unk_GsDlgC* FUN_140c9b540(int nId);
Unk_GsDlgB* FUN_140938b90(int nId);
Unk_GsFlags2* FUN_140166410();
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
extern Unk_GsAppG DAT_143b059e8;

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).

// @0x141ac9d30
UISceneGamePlay::UISceneGamePlay()
{
    m_6c = 0x620001d;
    m_c8 = 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeEnableFeature", Delegate<void(NotifyObject*)>(this, &UISceneGamePlay::FUN_141acc510));
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGamePlay::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_141acc5a0(FUN_140e09150(FUN_1409a8b10())->m_8);
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0) {
        FUN_1403ed2b0()->FUN_141ada610(m_6c);
    } else {
        if (FUN_141acc6c0(n) == 0) {
            FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
            FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
        } else {
            if (m_6c == 0x620001d) FUN_1403ed2b0()->FUN_141adb4c0(1);
            if (FUN_140b632f0()->FUN_1410af770() != 0) FUN_14025e7a0()->FUN_1422aed30(1);
        }
        for (unsigned __int64 i = 0; i < m_a8.GetCount(); i++) {
            if (FUN_1403ed2b0()->FUN_141adc940(m_a8[i]) != 0) FUN_1403ed2b0()->FUN_141adc530(m_a8[i]);
        }
        m_a8.RemoveAll();
        FUN_141b70290();
    }
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141ac9f20, UISceneGamePlay, vfunc_48, 415, 0x83342379);

// @0x141aca0d0
void UISceneGamePlay::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    if (FUN_141acc6c0(n) != 0) {
        if ((unsigned char)FUN_140b632f0()->FUN_1410af770() != 0) FUN_14025e7a0()->FUN_1422aed30(0);
        if (m_6c == 0x620001d) FUN_1403ed2b0()->FUN_141adb4c0(0);
    } else {
        FUN_1403ed2b0()->FUN_141ada610(m_6c);
        FUN_1403ed2b0()->FUN_141adad20(m_6c);
    }
    if (FUN_141acc5f0(n) != 0) FUN_141acc5a0(1.0f);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141aca0d0, UISceneGamePlay, vfunc_49, 189, 0xE218ED84);

// @0x141aca1a0
void UISceneGamePlay::vfunc_11()
{
    FUN_1403ed2b0()->FUN_141adb4c0(1);
    FUN_1403ed2b0()->FUN_141ad9e50(m_6c);
    FUN_1403ed2b0()->FUN_141ada6f0(m_6c);
    FUN_141b70290();
    FUN_141242990(FUN_1409a8b10());
    FUN_14125f670(FUN_140a58500(FUN_1409a8b10()), *FUN_140a58500(FUN_1409a8b10()), 0);
    FUN_14125bd20(FUN_140c58ac0(FUN_1409a8b10()), *FUN_140c58ac0(FUN_1409a8b10()));
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
int UISceneGamePlay::vfunc_14()
{
    if (UISwfEntity::vfunc_14() != 0) return 1;
    if (FUN_14025e7c0()->FUN_14116d840() != 0) return FUN_1418fcb70();
    if (FUN_14025e7c0()->FUN_14116dd30(0x49404, 0, 0) != 0) {
        FUN_1403ed2b0()->FUN_141adbbb0();
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0) != 0) {
        Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0 && pPlayer->FUN_14166ce30() == 0 && pPlayer->vfunc_63() != 0) pPlayer->FUN_140a7b810()->FUN_140953310();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141aca2b0, UISceneGamePlay, vfunc_14, 237, 0x5EDB9347);

// @0x141aca3b0
void UISceneGamePlay::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (FUN_14025e7c0()->FUN_14116dcb0(0x49406, 0, 0) != 0) FUN_1409bb9e0()->FUN_140d406d0(1);
    else FUN_1409bb9e0()->FUN_140d406d0(0);
    if (FUN_14025e7c0()->FUN_14116d950(0x2a, 0, 0) != 0 || FUN_14025e7c0()->FUN_14116d950(0x36, 0, 0) != 0) FUN_1403ed2b0()->FUN_141adcb60(1);
    else FUN_1403ed2b0()->FUN_141adcb60(0);
    FUN_1408e48f0(&DAT_143ab2ee0);
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
    Unk_GsUnit* pUnit = FUN_140e01890(0x4e4c);
    if (pUnit != 0) pUnit->FUN_1419f5ab0();
    FUN_1403ed2b0()->FUN_141ada610(m_6c);
    FUN_1403ed2b0()->FUN_141adad20(m_6c);
}
MS2_REPLACE_METHOD(0x141aca500, UISceneGamePlay, vfunc_56, 99, 0xDBBEB784);

// @0x141aca570
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGamePlay::vfunc_58()
{
    FUN_140764020()->FUN_1416ca670();
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyFadeInComplete));
    Unk_GsMapPtr spMap = FUN_140a55460(FUN_1403ed2d0()->FUN_141bd3060());
    if (spMap.FUN_1409657a0() != 0 && spMap.FUN_140885340()->FUN_1403754f0() != 0) {
        if (m_c8 != 0 && spMap.FUN_140885340()->GetPkMode() == 0) {
            FUN_141275260(0x96f, 4, 0);
            FUN_1412751b0(GetStringCommon(0x970), 0x14);
            FUN_141276180(DAT_143af6008, CString(""));
            m_c8 = 0;
        } else if (m_c8 == 0) {
            if (spMap.FUN_140885340()->GetPkMode() != 0) {
                FUN_141275260(0x96d, 4, 0);
                FUN_1412751b0(GetStringCommon(0x96e), 0x14);
                FUN_141276180(DAT_143af6008, CString(""));
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
int UISceneGamePlay::FUN_141aca870()
{
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf) != 0) return 0;
    if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0) != 0) {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x3d, 0, 0) != 0) {
            FUN_141610410((FUN_140ae1c10() + 1) % 5);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x21, 1, 0) != 0) {
            FUN_1403ed2d0()->FUN_141bd2fa0();
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, 1, 0) != 0) {
            if (FUN_14025e7c0()->FUN_14116d9c0(0x1e, 1, 0) != 0) {
                FUN_141371b30()->FUN_141021140();
                FUN_1412751b0(CStringW(L"Script reloaded"), 0x14);
                return 1;
            }
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1e, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            DAT_143ae0fb8 = (DAT_143ae0fb8 == 0);
            CStringW strMsg;
            strMsg.Format(L"월드맵 모든맵 발견모드 : %s", DAT_143ae0fb8 == 0 ? DAT_142fde938 : DAT_142fde930);
            FUN_1412751b0(strMsg, 0x14);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x13, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            unsigned char nMode = (unsigned char)((unsigned char)DAT_143ae0fb0 + 1U) % 3;
            DAT_143ae0fb0 = nMode;
            COutPacket packet(static_cast<int>(SendOp::SetDebugMode), 0);
            packet.WriteUInt8(0);
            packet.WriteUInt8(nMode);
            FUN_140710590(packet);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x2e, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x33) return 0;
            if (FUN_140931510()->FUN_140d9f5d0(1) != 0) {
                FUN_1412751b0(CStringW(L"Error InvisibleFromAll On"), 0x14);
                return 1;
            }
            Unk_CommandChat cmd;
            cmd.kind = 0;
            cmd.message = CStringW(L"/ToggleInvisibleFromNpc");
            FUN_141276f80(cmd);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x19, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x3b) return 0;
            Unk_CommandChat cmd;
            cmd.kind = 0;
            cmd.message = CStringW(L"/ToggleDeathPower");
            FUN_141276f80(cmd);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x11, 1, 0) != 0) {
            unsigned nOld = FUN_140a0afd0()->FUN_141acccb0();
            FUN_140a0afd0()->FUN_141accee0(nOld ^ 1);
            CStringW strMsg;
            strMsg.Format(L"텍스쳐 리로드 : %s", (nOld ^ 1) == 0 ? DAT_142fdea00 : DAT_142fde9f4);
            FUN_1412751b0(strMsg, 0x14);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x20, 1, 0) != 0) {
            Unk_GsDlgA* pDlg = FUN_14167a900(0x4e44);
            if (pDlg != 0) pDlg->FUN_1419246f0();
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x80, 1, 0) != 0) {
            FUN_1403ed2b0()->FUN_141adc750(0x4e50);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x26, 1, 0) != 0) {
            DAT_1439fa008 = DAT_1439fa008 - 1;
            if (DAT_1439fa008 == 0) DAT_1439fa008 = 3;
            CStringW strMsg;
            strMsg.Format(L"Effect LOD : %d", DAT_1439fa008);
            FUN_1412751b0(strMsg, 0x14);
            FUN_1403ed280()->FUN_1411a8880(DAT_1439fa008);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116dd30(0x927c1, 1, 0) != 0) {
            FUN_1403ed2b0()->FUN_141adc750(0x4ea3);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x22, 1, 0) != 0) return 1;
        if (FUN_14025e7c0()->FUN_14116d9c0(0x17, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            FUN_1403ed2b0()->FUN_141adc750(0x4e25);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x18, 1, 0) != 0) {
            FUN_1403ed2b0()->FUN_141adc750(0x4ecd);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x2d, 1, 0) != 0) {
            FUN_1403ed2b0()->FUN_141adc750(0x4e8f);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x2c, 1, 0) != 0) {
            FUN_1403ed2b0()->FUN_141adc750(0x4ea6);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x31, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
            if (FUN_14025e7c0()->FUN_14116d950(0x38, 0, 0) == 0) FUN_1403ed2b0()->FUN_141adc750(0x4e46);
            else FUN_1403ed2b0()->FUN_141adc750(0x4e89);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x32, 1, 0) != 0) {
            if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x33) return 0;
            FUN_1403ed2b0()->FUN_141adc750(0x4e2a);
            return 1;
        }
        if (FUN_14025e7c0()->FUN_14116d9c0(0x10, 1, 0) == 0) {
            if (FUN_14025e7c0()->FUN_14116d9c0(0x30, 1, 0) != 0) {
                if (DAT_143ab0248 == 2 && DAT_143ab2914 < 0x34) return 0;
                FUN_1403ed2b0()->FUN_141adc750(0x4e4b);
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x24, 1, 0) != 0) {
                FUN_1403ed2d0()->FUN_141bdabb0();
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x3f, 1, 0) != 0) {
                FUN_1412751b0(CStringW(L"Reload sound resource & string & colorPalette"), 0x14);
                FUN_1401a9d70()->FUN_141811960();
                FUN_140c9cb10();
                FUN_1417af7a0();
                if (FUN_140281980()->FUN_1401d1320() != 0) FUN_140281980()->FUN_140556ea0();
                FUN_14025e7d0()->FUN_140259930();
                FUN_1409c51f0();
                FUN_141a0df10();
                FUN_141371b20()->FUN_141815db0();
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x41, 1, 0) != 0) {
                int nProxy = FUN_1403ed2d0()->FUN_141bda9f0();
                FUN_1403ed2d0()->FUN_141bda9c0(nProxy == 0);
                CStringW strMsg;
                strMsg.Format(L"Proxy 보기 : %s", nProxy == 0 ? L"True" : L"False");
                FUN_1412751b0(strMsg, 0x14);
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x42, 1, 0) != 0) {
                FUN_1427d5c10(FUN_140994450(), DAT_1439fa00c);
                if (FUN_1414a56c0() != 0) {
                    FUN_1414a56c0();
                    FUN_1422ea210(DAT_1439fa00c);
                }
                DAT_1439fa00c = DAT_1439fa00c ^ 1;
                FUN_141168200()->FUN_1411683e0("SetForceLostDevice : %d", DAT_1439fa00c);
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x44, 1, 0) != 0) {
                FUN_1418508e0(0);
                FUN_1412751b0(CStringW(L"SaveScreenShotToPNG"), 0x14);
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x55, 1, 0) != 0) {
                if (FUN_141168200()->FUN_141168310() == 0) FUN_141168200()->FUN_141168270();
                else FUN_141168200()->FUN_1411682d0();
                return 1;
            }
            if (FUN_14025e7c0()->FUN_14116d9c0(0x56, 1, 0) != 0) {
                if (AfxMessageBox(DAT_142fdeb28, 1, 0) != 1) return 1;
                void* pNet = FUN_14127bf80(&DAT_143b059e8);
                if (pNet != 0) FUN_1414ea8b0(pNet);
                throw 0xd;
            }
        } else {
            Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer != 0 && pPlayer->FUN_141527280() != 0) {
                FUN_1403ed2b0()->FUN_141adc750(0x4e8c);
                return 1;
            }
        }
    }

    int nResult;
    if (FUN_14025e7c0()->FUN_14116dd30(0x927c1, 0, 0)) {
        bool bOn = FUN_14025e7c0()->FUN_14116d720();
        FUN_14025e7c0()->FUN_14116d5d0(bOn == 0);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a82, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a82);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a81, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a81);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a85, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a85);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a86, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a86);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a87, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a87);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a89, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a89);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x493ee, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x493ee);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8f, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a8f);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a90, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a90);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8a, 0, 0)) {
        if (0x31 < DAT_143ab2914) FUN_1409331f0()->FUN_14142b300(0x61a8a);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8b, 0, 0)) {
        if (0x31 < DAT_143ab2914) FUN_1409331f0()->FUN_14142b300(0x61a8b);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dcb0(0x493e2, 0, 0)) {
        Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0 && pPlayer->FUN_14166ce30() == 0 && pPlayer->vfunc_63() != 0) {
            if (pPlayer->FUN_140a7b810()->FUN_140953410() == 0) {
                if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0)) pPlayer->FUN_140a7b810()->FUN_140953310();
            }
        }
        nResult = 0;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8c, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a8c);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x493ed, 0, 0)) {
        if (FUN_1409331e0()->FUN_14138c900(0x13) == 0) {
            Unk_GsPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer != 0) {
                if (pPlayer->FUN_1416595d0() == 0) pPlayer->FUN_14152feb0(1, 0);
                else pPlayer->FUN_141530200();
            }
        }
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a88, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a88);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x493f6, 0, 0)) {
        if (FUN_1409478c0()->FUN_140a18070() != 0) {
            FUN_1409478c0()->FUN_140aefa70();
            Unk_GsDlgC* pDlg = FUN_140c9b540(0x4e29);
            if (pDlg != 0) pDlg->FUN_141a39e40();
        }
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8d, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a8d);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a8e, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a8e);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x49403, 0, 0)) {
        Unk_GsDlgB* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0) pDlg->FUN_14193b750();
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x4940a, 0, 0)) {
        Unk_GsDlgB* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0) pDlg->FUN_14193bf70();
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x4940b, 0, 0)) {
        Unk_GsDlgB* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0) pDlg->FUN_14193bfd0();
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x4940c, 0, 0)) {
        Unk_GsDlgB* pDlg = FUN_140938b90(0x4e28);
        if (pDlg != 0) pDlg->FUN_14193bfa0();
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x49404, 0, 0)) {
        FUN_1403ed2b0()->FUN_141adbbb0();
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116d840()) {
        nResult = FUN_1418fcb70();
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a91, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a91);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a92, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a92);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a93, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a93);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a94, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a94);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a95, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a95);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a96, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a96);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa4, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa4);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa5, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa5);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa6, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa6);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0xc3504, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0xc3504);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a97, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a97);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a98, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a98);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a99, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a99);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9a, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9a);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9b, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9b);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9c, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9c);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9d, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9d);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9e, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9e);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61a9f, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61a9f);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa0, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa0);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa1, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa1);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa2, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa2);
        nResult = 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x61aa3, 0, 0)) {
        FUN_1409331f0()->FUN_14142b300(0x61aa3);
        nResult = 1;
    }
    else {
        nResult = 0;
        if (FUN_140166410()->FUN_14036d570(0xe3)) {
            for (int nKey = 0xdbba1; nKey < 0xdbbab; nKey++) {
                if (FUN_14025e7c0()->FUN_14116dd30(nKey, 0, 0)) {
                    Unk_GsDlg3* pDlg = FUN_141815ed0();
                    if (pDlg != 0) pDlg->FUN_140be1910(nKey);
                    return 1;
                }
            }
        }
    }
return nResult;
    return nResult;
}

// @0x141acc510
void UISceneGamePlay::FUN_141acc510(NotifyObject* pNotify)
{
    NotifyChangeEnableFeature* pChange = dynamic_cast<NotifyChangeEnableFeature*>(pNotify);
    if (pChange == 0) return;
    FUN_1401d3200()->FUN_1402b7200();
    FUN_1401a9d70()->FUN_141811960();
    FUN_14025e7d0()->FUN_140259930();
    FUN_1409c51f0();
    FUN_141371b20()->FUN_141815db0();
}
MS2_REPLACE_METHOD(0x141acc510, UISceneGamePlay, FUN_141acc510, 125, 0x4F19D812);

// @0x141acc5a0
void FUN_141acc5a0(float fValue)
{
    if (FUN_1403ed2b0()->FUN_141adbe00(fValue, 0) != 0) FUN_140b632f0()->vfunc_6();
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
struct Unk_GsEntIter { void* m_a; void* m_b; };                 // iterator over the world's entities
struct Unk_Gs16 { void* m_0; void* m_8; };
class Unk_GsSvc { public: int FUN_1413d6890(egf::Entity* pEntity); void* FUN_1413d66b0(egf::Entity* pEntity); };
class Unk_GsSvcPtr                                              // smart pointer to a framework service
{
public:
    Unk_GsSvcPtr(Unk_GsSvc* p);                                 // 0x14098c7d0
    ~Unk_GsSvcPtr();                                            // 0x14098cc60
    void* FUN_14098d090() const;
    Unk_GsSvc* FUN_14098d0e0() const;
private:
    Unk_GsSvc* m_p;
};
class Unk_GsApp2 { public: void FUN_141489ff0(Unk_Gs16 kValue); };
Unk_GsEntMgr* FUN_1409670f0();
void FUN_1411ce4c0(Unk_GsEntMgr* p, Unk_GsEntIter* pIter);
bool FUN_1411ce510(Unk_GsEntMgr* p, Unk_GsEntIter* pIter, egf::Entity** ppOut);
egf::Entity* FUN_1411cf440(Unk_GsEntMgr* p, const egf::EntityID& id);
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
int FUN_1408a20a0(egf::Entity* pEntity, unsigned nHash, bool* pbOut);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned nHash, bool* pbValue);
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
Unk_GsSvc* FUN_14098c5b0(Unk_GsAppG* p);
void FUN_1413f9c40(bool bFlag);
Unk_Gs16 FUN_140987930(const Unk_Gs16* p);
Unk_GsApp2* FUN_140aae430();
extern char DAT_142fdef20[];
extern Unk_Gs16 DAT_143a09680;

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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameScreenShot::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    m_a8.RemoveAll();
    Unk_GsEntIter kIter;
    FUN_1411ce4c0(FUN_1409670f0(), &kIter);
    egf::Entity* pEntity;
    while (FUN_1411ce510(FUN_1409670f0(), &kIter, &pEntity)) {
        bool bSkip = false;
        bool bChar = FUN_1408a9bd0(pEntity)->ContainsModel(efd::utf8string(DAT_142fdef20)) || FUN_1408a9bd0(pEntity)->ContainsModel(efd::utf8string("Actor"));
        if (bChar) {
            Unk_GsSvcPtr spSvc(FUN_14098c5b0(&DAT_143b059e8));
            if (spSvc.FUN_14098d090() != 0) {
                if (spSvc.FUN_14098d0e0()->FUN_1413d6890(pEntity) == 0) bSkip = spSvc.FUN_14098d0e0()->FUN_1413d66b0(pEntity) != 0;
                else bSkip = true;
            }
            if (!bSkip) {
                bool bValue = true;
                if (FUN_1408a20a0(pEntity, 0xa0b6b179, &bValue) == 0 && bValue) m_a8.AddTail(*FUN_1408b76f0(pEntity));
            }
        }
    }
    POSITION pos = m_a8.GetHeadPosition();
    while (pos != 0) {
        egf::EntityID id;
        FUN_1408b6b20(&id, &m_a8.GetAt(pos));
        egf::Entity* pHidden = FUN_1411cf440(FUN_1409670f0(), id);
        if (pHidden != 0) {
            bool bShown = false;
            FUN_14098c6e0(pHidden, 0xa0b6b179, &bShown);
        }
        m_a8.GetNext(pos);
    }
    FUN_1413f9c40(false);
    FUN_1403ed2b0()->FUN_141ad9b30();
    FUN_1403ed2b0()->FUN_141adbca0(0);
    ShowCursor(TRUE);
    FUN_1422e7950();
}
MS2_REPLACE_METHOD(0x141acd290, UISceneGameScreenShot, vfunc_48, 838, 0x4471B5A7);

// @0x141acd5e0
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
void UISceneGameScreenShot::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    POSITION pos = m_a8.GetHeadPosition();
    while (pos != 0) {
        egf::EntityID id;
        FUN_1408b6b20(&id, &m_a8.GetAt(pos));
        egf::Entity* pHidden = FUN_1411cf440(FUN_1409670f0(), id);
        if (pHidden != 0) {
            bool bShown = true;
            FUN_14098c6e0(pHidden, 0xa0b6b179, &bShown);
        }
        m_a8.GetNext(pos);
    }
    FUN_1413f9c40(true);
    FUN_1403ed2b0()->FUN_141ad9650();
    FUN_1403ed2b0()->FUN_141adbca0(1);
    Unk_Gs16 kValue = FUN_140987930(&DAT_143a09680);
    FUN_140aae430()->FUN_141489ff0(kValue);
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
    if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0) != 0) {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x14, 1, 0) != 0) {
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
// MS2-FUNCTIONAL: not byte-exact yet (stack frame / branch layout differ)
UISceneGameScreenShot::~UISceneGameScreenShot()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc20d0-0x142cc23d0 .text$yd
