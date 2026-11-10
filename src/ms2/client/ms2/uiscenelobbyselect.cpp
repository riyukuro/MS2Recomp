// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The lobby scene family: see uiscenelobbyselect.h.
// MS2-UNIT: client\ms2\uiscenelobbyselect.cpp
// MS2-RANGE: 0x14011cbf0-0x14011d080 .text$di
// MS2-RANGE: 0x141acd890-0x141aceab0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiscenelobbyselect.cpp"
#include "ms2/placeholder/ms2stdafx.h"

// The shared header statics of this unit (each header brings its own copies, constructed in include order).
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static CString s_skill1 = "skill";
static CString s_stun1 = "stun";
static egf::EntityID s_handle1(0);   // @0x14011cc50
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill2 = "skill";
static CString s_stun2 = "stun";
static egf::EntityID s_handle2(0);   // @0x14011cd90
static CString s_skill3 = "skill";
static CString s_stun3 = "stun";
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill4 = "skill";
static CString s_stun4 = "stun";
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_sortNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill5 = "skill";
static CString s_stun5 = "stun";

#include "uiscenelobbyselect.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/homeblockmanager.h"
#include "ms2/client/ms2/uicharacterlistdialog.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::FUN_141adc5d0
#include "ms2/client/ms2/cameramode.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/client/ms2/uiserverlistdialog.h"   // C3 type identity: UIServerListDialog
#include "ms2/commonfiles/os.h"
class CUserMail { public: static __int64 GetGFxSceneService(); };  // C3: member view (0x1408e57f0, the scene-service global)

// ---- unit-local views of exe types (unrecovered helpers) ----

class Unk_LsLogin : public CInputKeyHandler
{
public:
};
class Unk_LsPlayerState { public: int m_pad0; int m_pad4; int m_8; };
class CameraMgr;
template <> class TSingleton<CameraMgr>   // C3: as camera.h declares it (camera.h would add the egf ID statics)
{
public:
    static CameraMgr* GetInstance();      // 0x1409478c0
};
class CameraMgr
{
public:
    int FUN_140a18070();
    void FUN_140aec8a0(bool bKeep);
    bool GetSavedSetting(Unk_CameraSetting& kSetting);
    void FUN_140aed720(const Unk_CameraSetting& kSetting);
    void SetMode(int a, int b);
};
class Unk_LsCharSelect : public UICharacterListDialog
{
};
using Unk_LsServerDlg = UIServerListDialog;   // C3 type identity: Unk_LsServerDlg stood in for UIServerListDialog
class Unk_LsDevice
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
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
};
typedef UIMsg Unk_LsUIMsg;

class CUIService;
class WorldService { public: static WorldService* GetInstance(); void* FUN_141bd0cc0(); int FUN_141bcfbd0(); };   // C3: worldservice.h would add the efd ID statics
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
class Unk_SoundSink* GetKeyTable();   // C3: was GetKeyTable
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class CBuddyManager;
class Unk_InventoryStateManager* GetBlockManager();   // C3: the real function (0x140a6a830, inventory.cpp): the CBlockManager singleton
class HomeBlockManager;
template <class T> T* Unk_MMDialog(int nId);   // C3: mentoringmanager.cpp
class UIDamageText;
template <class T> T* Unk_DmgFindUI(int nId);
int FUN_141b712e0();
extern int DAT_143ab0248;
extern int DAT_143ab2914;
int FUN_141acdeb0();
class UIDialog* FindDialog(int);   // C3: was FindDialog
void* FindServerListDialog(int);   // C3: was FindServerListDialog
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetPrevSubSceneId();
};
int FUN_140e85580(class Unk_SmPlayerState*);   // C3: was FUN_140e85580
CStringW TakeScreenshotJpg(int a, int b);
void FUN_140930150(int n);
void FUN_14151f460(int n);
void FUN_141b91b20(bool b);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141acd890
UISceneLobby::UISceneLobby()
{
    m_6c = 0x620000d;
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneLobbyServer);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneLobbySelect);
        m_78.AddTail(ref);
    }
    {
        Unk_ScenePtr<UISceneEntity> ref(new UISceneLobbyCreate);
        m_78.AddTail(ref);
    }
}

// @0x141acda60
UISceneLobby::~UISceneLobby()
{
}

// @0x141acdaa0
CString UISceneLobby::GetTypeName()
{
    return "SceneLobby";
}
MS2_REPLACE_METHOD(0x141ACDAA0, UISceneLobby, GetTypeName, 61, 0xA1D151FD);

// @0x141acdaf0
int UISceneLobby::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    if (n == 0x6200009) SetSubSceneId(0x620001a);
    TSingleton<CUIService>::GetInstance()->FUN_141adbe00(1.0f, 0);
    TSingleton<CUIService>::GetInstance()->FUN_141adbcd0(0);
    TSingleton<CUIService>::GetInstance()->FUN_141adbf00();
    TSingleton<CUIService>::GetInstance()->SetMode(0x3ef);
    TSingleton<CUIService>::GetInstance()->FUN_141ada6f0(m_6c);
    TSingleton<CBuddyManager>::GetInstance()->FUN_140ae5190();
    reinterpret_cast<CBlockManager*>(GetBlockManager())->ClearBlocks();
    TSingleton<HomeBlockManager>::GetInstance()->Clear();
    {
        MS2Ptr<UIHeadUpDisplay> spTutorial(reinterpret_cast<UIHeadUpDisplay*>(Unk_DmgFindUI<UIDamageText>(0x4e32)));
        if (spTutorial.get() != 0) {
            if (spTutorial->FUN_141986d30() == 0) TSingleton<CUIService>::GetInstance()->FUN_141add040((eUIClassID)0x4e32);
        }
    }
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACDAF0, UISceneLobby, vfunc_48, 296, 0x894BC46E);

// @0x141acdc20
int UISceneLobby::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    TSingleton<CUIService>::GetInstance()->FUN_141adad20(m_6c);
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACDC20, UISceneLobby, vfunc_49, 63, 0x0F698270);

// @0x141acdc70
int UISceneLobby::vfunc_13()
{
    if (FUN_141acdeb0()) {
        TakeScreenshotJpg(1, 0);
        return 1;
    }
    if (((class Unk_LsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x927c1, 0, 0)) {
        FUN_140930150(0x32);
        ((class Unk_LsLogin*)FUN_14025e7c0())->SetDebugMode(((class Unk_LsLogin*)FUN_14025e7c0())->IsDebugMode() == 0);
    } else {
        if (((class Unk_LsLogin*)FUN_14025e7c0())->IsKeyDown(0x1d, 0, 0)) {
            if (((class Unk_LsLogin*)FUN_14025e7c0())->WasKeyPressed(0x16, 1, 0)) {
                if (((class Unk_LsLogin*)FUN_14025e7c0())->IsKeyDown(0x38, 1, 0)) {
                    if (FUN_140aadf80() != 0) {
                        FUN_141b91b20((FUN_140aadf80(), FUN_141b712e0()) == 1);
                    }
                    return 1;
                }
                bool bOpen = true;
                if (DAT_143ab0248 == 2)
                    bOpen = DAT_143ab2914 >= 0x34;
                if (bOpen) TSingleton<CUIService>::GetInstance()->CycleCursor();
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ACDC70, UISceneLobby, vfunc_13, 394, 0xCC53711C);

// @0x141acde00
int UISceneLobby::vfunc_14()
{
    if (UISwfEntity::vfunc_14()) return 1;
    if (FUN_141acdeb0()) {
        TakeScreenshotJpg(1, 0);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ACDE00, UISceneLobby, vfunc_14, 82, 0xE19C8DA6);

// @0x141acde60
int UISceneLobby::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ACDE60, UISceneLobby, vfunc_28, 67, 0x774DFD16);

// @0x141acdeb0
int FUN_141acdeb0()
{
    if (FUN_140e85580((class Unk_SmPlayerState*)(((class Unk_LsPlayerState*)GetKeyTable()))) == 0) return ((class Unk_LsLogin*)FUN_14025e7c0())->WasKeyPressed(0x75, 0, 0);
    return ((class Unk_LsLogin*)FUN_14025e7c0())->FUN_14116dd30(0x493ef, 0, 0);
}
MS2_REPLACE(0x141ACDEB0, FUN_141acdeb0, 82, 0xD9098B92);

// @0x141acdf50
UISceneLobbyCreate::UISceneLobbyCreate()
{
    m_6c = 0x620001c;
}

// @0x141acdfa0
UISceneLobbyCreate::~UISceneLobbyCreate()
{
}

// @0x141acdfe0
CString UISceneLobbyCreate::GetTypeName()
{
    return "SceneLobbyCreate";
}
MS2_REPLACE_METHOD(0x141ACDFE0, UISceneLobbyCreate, GetTypeName, 61, 0x8A27D619);

// @0x141ace030
void UISceneLobbyCreate::OnLoadComplete()
{
    UISwfEntity::OnLoadComplete();
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0) {
        if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)0x4e26) != 0) {
            (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4e26)));
            (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef2)));
        }
    }
}
MS2_REPLACE_METHOD(0x141ACE030, UISceneLobbyCreate, OnLoadComplete, 108, 0xAE336B86);

// @0x141ace0b0
int UISceneLobbyCreate::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACE0B0, UISceneLobbyCreate, vfunc_48, 42, 0x00235EB3);

// @0x141ace0e0
int UISceneLobbyCreate::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e26);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef2);
    TSingleton<CameraMgr>::GetInstance()->FUN_140aec8a0(0);
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
        Unk_CameraSetting arg;
        if (TSingleton<CameraMgr>::GetInstance()->GetSavedSetting(arg)) {
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed720(arg);
            TSingleton<CameraMgr>::GetInstance()->SetMode(4, 1);
        }
    }
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACE0E0, UISceneLobbyCreate, vfunc_49, 187, 0x95E5AF8B);

// @0x141ace1b0
void UISceneLobbyCreate::vfunc_12()
{
    UISwfEntity::vfunc_12();
    if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)0x4e26) != 0) {
        (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4e26)));
        (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef2)));
    }
}
MS2_REPLACE_METHOD(0x141ACE1B0, UISceneLobbyCreate, vfunc_12, 82, 0xF8577C97);

// @0x141ace250
UISceneLobbySelect::UISceneLobbySelect() : m_a8(0)
{
    m_6c = 0x620001b;
}

// @0x141ace2b0
UISceneLobbySelect::~UISceneLobbySelect()
{
}

// @0x141ace2f0
CString UISceneLobbySelect::GetTypeName()
{
    return "SceneLobbySelect";
}
MS2_REPLACE_METHOD(0x141ACE2F0, UISceneLobbySelect, GetTypeName, 61, 0x90748085);

// @0x141ace340
int UISceneLobbySelect::vfunc_48(int n)
{
    return UISceneEntity::vfunc_48(n);
}
MS2_REPLACE_METHOD(0x141ACE340, UISceneLobbySelect, vfunc_48, 32, 0x8AFA6F73);

// @0x141ace370
int UISceneLobbySelect::vfunc_49(int n)
{
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef1);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef2);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef3);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4eea);
    FUN_14151f460(1);
    TSingleton<CameraMgr>::GetInstance()->FUN_140aec8a0(0);
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0) {
        Unk_CameraSetting arg;
        if (TSingleton<CameraMgr>::GetInstance()->GetSavedSetting(arg)) {
            TSingleton<CameraMgr>::GetInstance()->FUN_140aed720(arg);
            TSingleton<CameraMgr>::GetInstance()->SetMode(4, 1);
        }
    }
    m_a8 = 0;
    return UISceneEntity::vfunc_49(n);
}
MS2_REPLACE_METHOD(0x141ACE370, UISceneLobbySelect, vfunc_49, 239, 0xE013CE78);

// @0x141ace470
void UISceneLobbySelect::vfunc_58()
{
    UISceneEntity::vfunc_58();
    if (m_a8 != 0) m_a8->FUN_1418f1fd0();
    ((class Unk_LsDevice*)((void*)GetClientPlatform()))->vfunc_62();
}
MS2_REPLACE_METHOD(0x141ACE470, UISceneLobbySelect, vfunc_58, 85, 0x7872DA7D);

// @0x141ace4d0
void UISceneLobbySelect::vfunc_12()
{
    UISwfEntity::vfunc_12();
    TSingleton<CUIService>::GetInstance()->FUN_141adba40();
    if (m_a8 != 0) m_a8->FUN_1418f1f10();
}
MS2_REPLACE_METHOD(0x141ACE4D0, UISceneLobbySelect, vfunc_12, 69, 0x38B7346F);

// @0x141ace520
void UISceneLobbySelect::OnLoadInit()
{
    UISceneEntity::OnLoadInit();
    m_a8 = (Unk_LsCharSelect*)Unk_MMDialog<UICharacterListDialog>(0x4ef1);
    if (m_a8 == 0) {
        MS2_ASSERT_AT(71, 0);
    } else {
        if (((class GFxSceneService*)CUserMail::GetGFxSceneService())->GetPrevSubSceneId() == 0x620001a && m_a8->GetCharacterCount() == 0 && m_a8->IsBurningLevelupEventRunning() == 0) {
            (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef1)));
            (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4eea)));
        } else {
            (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef1)));
        }
    }
}
MS2_REPLACE_METHOD(0x141ACE520, UISceneLobbySelect, OnLoadInit, 218, 0x26989DD5);

// @0x141ace600
void UISceneLobbySelect::vfunc_57()
{
    UISceneEntity::vfunc_57();
}
MS2_REPLACE_METHOD(0x141ACE600, UISceneLobbySelect, vfunc_57, 24, 0xC6F7F2EB);

// @0x141ace620
int UISceneLobbySelect::vfunc_62()
{
    if (m_a8 != 0 && m_a8->FUN_1418f1c70() != 0) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ACE620, UISceneLobbySelect, vfunc_62, 59, 0xEDC66F2A);

// @0x141ace670
int UISceneLobbySelect::vfunc_63()
{
    if (m_a8 != 0 && m_a8->FUN_1418f1c70() != 0) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141ACE670, UISceneLobbySelect, vfunc_63, 59, 0xD99FC813);

// @0x141ace6c0
void UISceneLobbySelect::vfunc_64()
{
    Unk_LsCharSelect* pSelect = (Unk_LsCharSelect*)Unk_MMDialog<UICharacterListDialog>(0x4ef1);
    if (pSelect != 0) pSelect->ShowPopup();
}
MS2_REPLACE_METHOD(0x141ACE6C0, UISceneLobbySelect, vfunc_64, 47, 0x331A49C0);

// @0x141ace730
UISceneLobbyServer::UISceneLobbyServer()
{
    m_6c = 0x620001a;
}

// @0x141ace780
UISceneLobbyServer::~UISceneLobbyServer()
{
}

// @0x141ace7c0
CString UISceneLobbyServer::GetTypeName()
{
    return "SceneLobbyServer";
}
MS2_REPLACE_METHOD(0x141ACE7C0, UISceneLobbyServer, GetTypeName, 61, 0x87DB86F3);

// @0x141ace810
int UISceneLobbyServer::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACE810, UISceneLobbyServer, vfunc_48, 42, 0xCE0DE2F6);

// @0x141ace840
int UISceneLobbyServer::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    if (n == 0) ResetServerDialog();
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef0);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef3);
    FUN_14151f460(1);
    return GetSceneId();
}
MS2_REPLACE_METHOD(0x141ACE840, UISceneLobbyServer, vfunc_49, 105, 0xF2D63327);

// @0x141ace8b0
void UISceneLobbyServer::OnLoadInit()
{
    UISceneEntity::OnLoadInit();
    if (WorldService::GetInstance()->FUN_141bcfbd0() != 0) (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef0)));
}
MS2_REPLACE_METHOD(0x141ACE8B0, UISceneLobbyServer, OnLoadInit, 59, 0x9081FF50);

// @0x141ace900
void UISceneLobbyServer::vfunc_60(MS2Ptr<AScript> spBackground)
{
    if (spBackground.get() != 0) {
        spBackground.operator->()->FUN_140e262c0("bgGotoAndPlay", "endTitleAni");
    }
}
MS2_REPLACE_METHOD(0x141ACE900, UISceneLobbyServer, vfunc_60, 101, 0x9A873225);

// @0x141ace970
void UISceneLobbyServer::vfunc_55()
{
    (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ef0)));
}
MS2_REPLACE_METHOD(0x141ACE970, UISceneLobbyServer, vfunc_55, 32, 0x8489FABA);

// @0x141ace9a0
void UISceneLobbyServer::vfunc_64()
{
    Unk_LsServerDlg* pDlg = ((Unk_LsServerDlg*)FindServerListDialog(0x4ef0));
    if (pDlg != 0) pDlg->FUN_141ad2ef0();
}
MS2_REPLACE_METHOD(0x141ACE9A0, UISceneLobbyServer, vfunc_64, 47, 0x6342EA2F);

// @0x141ace9e0
void UISceneLobbyServer::ResetServerDialog()
{
    Unk_LsServerDlg* pDlg = ((Unk_LsServerDlg*)FindDialog(0x4ef0));
    if (pDlg != 0) {
        Unk_LsUIMsg msg;
        msg.AddString("OnReset");
        pDlg->OnMessage(this, &msg);
    }
}
MS2_REPLACE_METHOD(0x141ACE9E0, UISceneLobbyServer, ResetServerDialog, 137, 0xB3007A1B);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc23d0-0x142cc25c0 .text$yd
