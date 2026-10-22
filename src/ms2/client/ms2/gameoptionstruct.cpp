// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptionstruct.cpp: the interface, sound and
// status tab pages of UIGameOptionDialog, and the option state blocks CGameOption keeps for every tab (defaults, XML
// load/save, copy and compare), CPersonalInfoAgreement (the house visit agreement and its message boxes), plus the
// TinyXML read/write helpers they share. Names other than the RTTI classes and
// the XML keys are invented. The state-block helpers are written as free functions over the block, as gameoption.cpp
// declares them.
// MS2-UNIT: client\ms2\gameoptionstruct.cpp
// MS2-RANGE: 0x1400ea9f0-0x1400eadb0 .text$di
// MS2-RANGE: 0x1412558c0-0x1412646a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionstruct.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/asdropdownmenu.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uiupperhpbar.h"
#include "ms2/client/ms2/uiexpbar.h"
#include "ms2/client/ms2/uidamageeffect.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/gfxservice.h"
#include "ms2/unnamed/unit_140ba6b20.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uiupperhuddialog.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "ms2/client/ms2/gameoptiongraphicdefault.h"
#include <ecr/LightService.h>
#include "ms2/client/ms2/depthoffieldmanager.h"
#include <d3d9.h>
#include <NiString.h>
#include <ctype.h>
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uigameoptiondialog.h"
#include "ms2/client/ms2/uisystemmenudialog.h"
#include "ms2/client/ms2/soundeventmgr.h"
#include "ms2/client/ms2/soundservice.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- header statics (dynamic initializers 0x1400ea9f0..0x1400ead60) ----
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local placeholders ----

// View of UIGameOptionDialog: the child lookups by name (getTabChild).
class Unk_GsDialog
{
public:
    MS2Ptr<ASButton> FUN_140a57f50(CString name, int nIndex);
    MS2Ptr<ASSlider> FUN_140a58110(CString name, int nIndex);
    MS2Ptr<ASDropdownMenu> FUN_140cfcf10(CString name, int nIndex);
    MS2Ptr<ASMovieClip> FUN_1412587a0(CString name, int nIndex);

    char m_pad[0x28];
    int m_nId;                                                      // +0x28 the option id
    int m_pad2;
    MS2Ptr<AScript> m_root;                                         // +0x30 the AS root
};

MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v);
bool FUN_1407cce10(const Scaleform::GFx::Value* p);                 // the value is a display object

CStringW FUN_1409eec40(int nStringId);                              // a string table text
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);   // message box
void FUN_14151f200();
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);        // equal
UIUpperHpBar* FUN_14096e340(eUIClassID nId);
UIDamageEffect* FUN_140ac55a0(eUIClassID nId);
class Unk_GsInputSvc { public: void FUN_140d0a5b0(bool b); int FUN_140d07390(); void FUN_140d0a510(); };   // reloads the sound settings
Unk_GsInputSvc* FUN_140c8dac0();

// The state blocks' methods (this unit).
void FUN_14125b430(Unk_CameraState* p);
void FUN_14125c8b0(Unk_StatusFlag* p);
void FUN_14125cab0(Unk_BattleState* p);
void FUN_14125d160(Unk_CommunityStateA* p);
void FUN_14125d360(Unk_CommunityStateB* p);
void FUN_14125d8c0(Unk_GraphicState* p);
void FUN_14125ec50(Unk_GraphicState2* p);
void FUN_14125f0c0(Unk_LgState* p);
void FUN_14125f2c0(Unk_GpState* p);
struct Unk_GsAutoLoot;
void FUN_141260ed0(Unk_GsAutoLoot* p);
void FUN_1412616a0(Unk_GoChroma* p);
struct Unk_GsEtc;
void FUN_141261780(Unk_GsEtc* p);
void FUN_14125b7a0(Unk_InterfaceState* p);
int LoadGameOptionInterface(Unk_InterfaceState* p, TiXmlDocument* pDoc);
void FUN_14125bb60(Unk_InterfaceState* pDst, const Unk_InterfaceState* pSrc);
bool FUN_14125bb90(const Unk_InterfaceState* p);
bool FUN_14125bbe0(const Unk_InterfaceState* p);
void FUN_14125bc60(Unk_InterfaceFlag* p);
int FUN_14125bc80(Unk_InterfaceFlag* p, TiXmlDocument* pDoc);
void FUN_14125bd00(Unk_InterfaceFlag* pDst, const Unk_InterfaceFlag* pSrc);
void FUN_14125bd20(Unk_InterfaceFlag* p, bool b);
void FUN_14125bdd0(Unk_StatusState* p);
int FUN_14125bee0(Unk_StatusState* p, TiXmlDocument* pDoc);
void FUN_14125c5a0(Unk_StatusState* pDst, const Unk_StatusState* pSrc);
int FUN_14125c8d0(Unk_StatusFlag* p, TiXmlDocument* pDoc);
void FUN_14125c950(Unk_StatusFlag* pDst, const Unk_StatusFlag* pSrc);
void FUN_14125f740(Unk_SoundState* p);
int LoadGameOptionSound(Unk_SoundState* p, TiXmlDocument* pDoc);
void FUN_14125fdf0(Unk_SoundState* pDst, const Unk_SoundState* pSrc);
void FUN_14125fe20(Unk_SoundState* p);
void FUN_1412603b0(Unk_SoundFlag* p);
int FUN_1412603d0(Unk_SoundFlag* p, TiXmlDocument* pDoc);
void FUN_141260450(Unk_SoundFlag* pDst, const Unk_SoundFlag* pSrc);
Unk_InterfaceState* FUN_14125b770(Unk_InterfaceState* p);
Unk_InterfaceFlag* FUN_14125bc30(Unk_InterfaceFlag* p);
Unk_StatusState* FUN_14125bda0(Unk_StatusState* p);
Unk_StatusFlag* FUN_14125c880(Unk_StatusFlag* p);
Unk_SoundState* FUN_14125f710(Unk_SoundState* p);
Unk_SoundFlag* FUN_141260380(Unk_SoundFlag* p);

// A UI object by class id, cast to its class.
template <class T> T* Unk_GsFindUI(eUIClassID nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// ---- CGameOptionInterface ----
// @0x1412558c0
CGameOptionInterface::CGameOptionInterface(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125b770(&m_state);
    FUN_14125bc30(&m_flag);
}

// @0x141255960
CGameOptionInterface::~CGameOptionInterface()
{
}

// @0x1412559a0
void CGameOptionInterface::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125bb60(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140e09150());
        FUN_14125bd00(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_140c58ac0());
    }
    CBaseOption::vfunc_3(n);
}
MS2_REPLACE_METHOD(0x1412559A0, CGameOptionInterface, vfunc_3, 99, 0x2E65AB2F);

// @0x141255a10
void CGameOptionInterface::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}
MS2_REPLACE_METHOD(0x141255A10, CGameOptionInterface, vfunc_4, 32, 0x754BF020);

// @0x141255a40
int CGameOptionInterface::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    if (CBaseOption::vfunc_5(pszName, pArg, nArg))
        return 1;
    if (_stricmp("onResetUILayout", pszName) == 0)
        FUN_140d73aa0(FUN_1409eec40(0x852), 1, this, CStringW(L"resetSwfLayout"));
    return 0;
}
MS2_REPLACE_METHOD(0x141255A40, CGameOptionInterface, vfunc_5, 256, 0xA70A78FA);

// The answer of the "reset the UI layout" confirm box.
// @0x141255b50
int CGameOptionInterface::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        if (nResult == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (FUN_1403b3c40(strTag, L"resetSwfLayout"))
                FUN_140b632f0()->FUN_1422d21b0();
        }
        FUN_14151f200();
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x141255B50, CGameOptionInterface, IMessageListener, OnMessage, 183, 0xAA2C522E);

// @0x141255c10
void CGameOptionInterface::vfunc_6()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableMouseControl"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_flag.m_b);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_closeDialogAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b00);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_autoDesc"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b01);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showTipText"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b02);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showDamageMeter"), -1);
        if (static_cast<ASButton*>(sp) != 0)
        {
            sp->FUN_1422c1fe0(m_state.m_b14);
            sp->FUN_1422ce090(m_state.m_b03);
        }
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showChaosDamageMeter"), -1);
        if (static_cast<ASButton*>(sp) != 0)
        {
            sp->FUN_1422c1fe0(m_state.m_b15);
            sp->FUN_1422ce090(m_state.m_b04);
        }
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sliderUI"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0(200.0f - m_state.m_f08 * 100.0f);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_damageTextScaleStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_n10);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_damageEffectAlphaStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_n0c);
    }
}
MS2_REPLACE_METHOD(0x141255C10, CGameOptionInterface, vfunc_6, 1746, 0x6CE23490);

// @0x1412562f0
void CGameOptionInterface::vfunc_7()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableMouseControl"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_flag.m_b = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_closeDialogAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b00 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_autoDesc"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b01 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showTipText"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b02 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showDamageMeter"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b03 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showChaosDamageMeter"), -1);
        if (static_cast<ASButton*>(sp) != 0)
        {
            if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xbe))
                m_state.m_b04 = sp->FUN_1422ce0e0() ? true : false;
        }
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sliderUI"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_f08 = (float)(200 - (int)sp->FUN_1422ce630()) / 100.0f;
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_damageTextScaleStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_n10 = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_damageEffectAlphaStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_n0c = (int)sp->FUN_1422ce630();
    }
}
MS2_REPLACE_METHOD(0x1412562F0, CGameOptionInterface, vfunc_7, 1691, 0x3B0C34FA);

// Apply: the damage meters follow their switches, then the blocks go back to the store and the character file.
// @0x1412569a0
void CGameOptionInterface::vfunc_10()
{
    CBaseOption::vfunc_10();
    if (FUN_14125bb90(&m_state))
    {
        if (FUN_1408e57f0()->GetSubSceneId() == 0x620001d)
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4edf);
    }
    else if (!FUN_14125bb90(&m_state))
    {
        CUIService::GetInstance()->FUN_141adc5d0((eUIClassID)0x4edf);
    }
    if (FUN_14125bbe0(&m_state))
    {
        if (TSingleton<CPartyManager>::GetInstance()->FUN_14162ab20())
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4f23);
    }
    else if (!FUN_14125bbe0(&m_state))
    {
        CUIService::GetInstance()->FUN_141adc5d0((eUIClassID)0x4f23);
    }
    FUN_14125bd20(&m_flag, m_flag.m_b);
    FUN_14125bb60(TSingleton<CGameOption>::GetInstance()->FUN_140e09150(), &m_state);
    FUN_14125bd00(TSingleton<CGameOption>::GetInstance()->FUN_140c58ac0(), &m_flag);
    UIDamageEffect* pEffect = FUN_140ac55a0((eUIClassID)0x4e3c);
    if (pEffect != 0)
        pEffect->FUN_141910b30((float)TSingleton<CGameOption>::GetInstance()->FUN_140e09150()->m_n0c);
    TSingleton<CGameOption>::GetInstance()->FUN_141243540();
}
MS2_REPLACE_METHOD(0x1412569A0, CGameOptionInterface, vfunc_10, 415, 0x86CDC5AF);

// @0x141256b50
void CGameOptionInterface::vfunc_11()
{
    int nChanged = CUIService::GetInstance()->FUN_141adbe00(m_state.m_f08, 0);
    if (nChanged != 0)
        FUN_140b632f0()->vfunc_6();
}
MS2_REPLACE_METHOD(0x141256B50, CGameOptionInterface, vfunc_11, 77, 0x24106CC8);

// Back to the shipped defaults.
// @0x141256bb0
void CGameOptionInterface::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125b7a0(&m_state);
    LoadGameOptionInterface(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    FUN_14125bc60(&m_flag);
    FUN_14125bc80(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
    FUN_140b632f0()->FUN_1422d21b0();
}
MS2_REPLACE_METHOD(0x141256BB0, CGameOptionInterface, vfunc_12, 147, 0x6286211F);

// @0x141256c50
CString CGameOptionInterface::GetTypeName()
{
    return CString("GameOptionInterface");
}
MS2_REPLACE_METHOD(0x141256C50, CGameOptionInterface, GetTypeName, 61, 0x01A065A6);

// @0x141256ca0
int CGameOptionInterface::vfunc_14()
{
    return memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140e09150(), 0x18);
}
MS2_REPLACE_METHOD(0x141256CA0, CGameOptionInterface, vfunc_14, 50, 0x3A2AC844);

// ---- CGameOptionSoundDefault ----
// @0x141256d20
CGameOptionSoundDefault::CGameOptionSoundDefault(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125f710(&m_state);
    FUN_141260380(&m_flag);
}

// @0x141256da0
CGameOptionSoundDefault::~CGameOptionSoundDefault()
{
}

// @0x141256dd0
void CGameOptionSoundDefault::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125fdf0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140d13c70());
        FUN_141260450(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_1411b1f30());
    }
    CBaseOption::vfunc_3(n);
}
MS2_REPLACE_METHOD(0x141256DD0, CGameOptionSoundDefault, vfunc_3, 99, 0x31ECDE0A);

// @0x141256e40
void CGameOptionSoundDefault::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}
MS2_REPLACE_METHOD(0x141256E40, CGameOptionSoundDefault, vfunc_4, 32, 0x7DB0A4BC);

// @0x141256e70
int CGameOptionSoundDefault::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141256E70, CGameOptionSoundDefault, vfunc_5, 23, 0x192A1B0B);

// MS2-FUNCTIONAL: the two child lookups keep their MS2Ptr temps in other frame slots; same calls and arguments
// @0x141256e90
void CGameOptionSoundDefault::vfunc_6()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bMuteAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b00);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bPlayAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b01);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableJobSound"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_flag.m_b);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_mainSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nMainSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_effectSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nEffectSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_enviromentSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nEnviromentSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_uiSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nUiSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_npcSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nNpcSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_bossSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nBossSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_bgmSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nBgmSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_systemSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nSystemSoundStep);
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_movieSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nMovieSoundStep);
    }
    {
        MS2Ptr<ASMovieClip> spClip = ((Unk_GsDialog*)GetOptionDialog())->FUN_1412587a0(CString("m_playInstrumentStep"), -1);
        if (static_cast<ASMovieClip*>(spClip) != 0)
        {
            if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(10))
            {
                spClip->vfunc_3(1);
                MS2Ptr<ASSlider> spSlider = spClip->FUN_140fafed0<ASSlider>(CString("m_slider"));
                if (static_cast<ASSlider*>(spSlider) != 0)
                    spSlider->FUN_1422ce5f0((float)m_state.m_n2c);
                MS2Ptr<ASButton> spOff = spClip->FUN_140c11f50<ASButton>(CString("m_isOffBgm"));
                if (static_cast<ASButton*>(spOff) != 0)
                    spOff->FUN_1422ce090(m_state.m_b30);
            }
            else
            {
                spClip->vfunc_3(0);
            }
        }
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_charSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_n28);
    }
}
MS2_REPLACE_METHOD(0x141256E90, CGameOptionSoundDefault, vfunc_6, 3054, 0x71243925);

// MS2-FUNCTIONAL: the two child lookups keep their MS2Ptr temps in other frame slots; same calls and arguments
// @0x141257a90
void CGameOptionSoundDefault::vfunc_7()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bMuteAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b00 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bPlayAll"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_b01 = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableJobSound"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_flag.m_b = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_mainSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nMainSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_effectSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nEffectSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_enviromentSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nEnviromentSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_uiSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nUiSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_npcSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nNpcSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_bossSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nBossSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_bgmSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nBgmSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_systemSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nSystemSoundStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_movieSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_nMovieSoundStep = (int)sp->FUN_1422ce630();
    }
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(10))
    {
        MS2Ptr<ASMovieClip> spClip = ((Unk_GsDialog*)GetOptionDialog())->FUN_1412587a0(CString("m_playInstrumentStep"), -1);
        if (static_cast<ASMovieClip*>(spClip) != 0)
        {
            MS2Ptr<ASSlider> spSlider = spClip->FUN_140fafed0<ASSlider>(CString("m_slider"));
            if (static_cast<ASSlider*>(spSlider) != 0)
                m_state.m_n2c = (int)spSlider->FUN_1422ce630();
            MS2Ptr<ASButton> spOff = spClip->FUN_140c11f50<ASButton>(CString("m_isOffBgm"));
            if (static_cast<ASButton*>(spOff) != 0)
                m_state.m_b30 = spOff->FUN_1422ce0e0() ? true : false;
        }
    }
    {
        MS2Ptr<ASSlider> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a58110(CString("m_charSoundStep"), -1);
        if (static_cast<ASSlider*>(sp) != 0)
            m_state.m_n28 = (int)sp->FUN_1422ce630();
    }
}
MS2_REPLACE_METHOD(0x141257A90, CGameOptionSoundDefault, vfunc_7, 2817, 0x76C79C43);

// @0x1412585a0
void CGameOptionSoundDefault::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125fe20(&m_state);
    FUN_14125fdf0(TSingleton<CGameOption>::GetInstance()->FUN_140d13c70(), &m_state);
    FUN_141260450(TSingleton<CGameOption>::GetInstance()->FUN_1411b1f30(), &m_flag);
    FUN_140c8dac0()->FUN_140d0a5b0(true);
    TSingleton<CGameOption>::GetInstance()->FUN_141243540();
}
MS2_REPLACE_METHOD(0x1412585A0, CGameOptionSoundDefault, vfunc_10, 155, 0x23023006);

// @0x141258650
void CGameOptionSoundDefault::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125f740(&m_state);
    LoadGameOptionSound(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    FUN_1412603b0(&m_flag);
    FUN_1412603d0(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}
MS2_REPLACE_METHOD(0x141258650, CGameOptionSoundDefault, vfunc_12, 134, 0xA4359286);

// @0x1412586e0
CString CGameOptionSoundDefault::GetTypeName()
{
    return CString("GameOptionSound");
}
MS2_REPLACE_METHOD(0x1412586E0, CGameOptionSoundDefault, GetTypeName, 61, 0xC94FE1B4);

// Differs only when both blocks differ (as the exe has it).
// @0x141258730
int CGameOptionSoundDefault::vfunc_14()
{
    if (memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140d13c70(), 0x34) == 0)
        return 0;
    if (memcmp(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_1411b1f30(), 1) == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141258730, CGameOptionSoundDefault, vfunc_14, 107, 0x53B53E3B);

// getTabChild for a movie clip.
// @0x1412587a0
MS2Ptr<ASMovieClip> Unk_GsDialog::FUN_1412587a0(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASMovieClip>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<ASMovieClip> sp = FUN_1409b40c0(m_nId, child);
        if (static_cast<ASMovieClip*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASMovieClip>(0);
}
MS2_REPLACE_METHOD(0x1412587A0, Unk_GsDialog, FUN_1412587a0, 443, 0xFB1BF18C);

// ---- CGameOptionStatus ----
// @0x1412589a0
CGameOptionStatus::CGameOptionStatus(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125bda0(&m_state);
    FUN_14125c880(&m_flag);
}

// @0x141258a20
CGameOptionStatus::~CGameOptionStatus()
{
}

// @0x141258a50
void CGameOptionStatus::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125c5a0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140b123b0());
        FUN_14125c950(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_140ea41a0());
    }
    CBaseOption::vfunc_3(n);
}
MS2_REPLACE_METHOD(0x141258A50, CGameOptionStatus, vfunc_3, 99, 0x650AD0F4);

// @0x141258ac0
void CGameOptionStatus::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}
MS2_REPLACE_METHOD(0x141258AC0, CGameOptionStatus, vfunc_4, 32, 0x5091EC4B);

// @0x141258af0
int CGameOptionStatus::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141258AF0, CGameOptionStatus, vfunc_5, 23, 0x192A1B0B);
// @0x141258b10
void CGameOptionStatus::vfunc_6()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMyName);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPlayerSymbol"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayPlayerSymbol);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayFriendlyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayFriendlyName);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayEnemyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayEnemyName);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayNpcName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayNpcName);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMonsterName);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPcIllust"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayPcIllust);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterGaugeValue"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMonsterGaugeValue);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayExpValue"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayExpValue);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayOnlyMyEffectToMonster"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayOnlyMyEffectToMonster);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMyHpGauge);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyShieldGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMyShieldGauge);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayPartyHpGauge);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyShieldGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayPartyShieldGauge);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayMonsterHpGauge);
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_bossMonsterNotify"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            sp->FUN_1422df690(m_state.m_n18);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayNormalChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayNormalChatBalloon);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayPartyChatBalloon);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayGuildChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayGuildChatBalloon);
    }
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8c))
    {
        {
            MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayShowOnlyMyPet"), -1);
            if (static_cast<ASButton*>(sp) != 0)
                sp->FUN_1422ce090(m_state.m_bDisplayShowOnlyMyPet);
        }
        {
            MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideMyPet"), -1);
            if (static_cast<ASButton*>(sp) != 0)
                sp->FUN_1422ce090(m_state.m_bDisplayHideMyPet);
        }
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideSmartPush"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayHideSmartPush);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayLearningQuest"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_flag.m_b);
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideHighlightMenu"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bDisplayHideHighlightMenu);
    }
}
MS2_REPLACE_METHOD(0x141258B10, CGameOptionStatus, vfunc_6, 4394, 0xBCEF88D7);

// @0x141259c40
void CGameOptionStatus::vfunc_7()
{
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMyName = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPlayerSymbol"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayPlayerSymbol = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayFriendlyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayFriendlyName = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayEnemyName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayEnemyName = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayNpcName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayNpcName = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterName"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMonsterName = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPcIllust"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayPcIllust = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterGaugeValue"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMonsterGaugeValue = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayExpValue"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayExpValue = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayOnlyMyEffectToMonster"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayOnlyMyEffectToMonster = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMyHpGauge = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyShieldGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMyShieldGauge = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayPartyHpGauge = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyShieldGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayPartyShieldGauge = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMonsterHpGauge"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayMonsterHpGauge = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASDropdownMenu> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_bossMonsterNotify"), -1);
        if (static_cast<ASDropdownMenu*>(sp) != 0)
            m_state.m_n18 = sp->FUN_1422df6c0();
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayNormalChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayNormalChatBalloon = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayPartyChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayPartyChatBalloon = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayGuildChatBalloon"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayGuildChatBalloon = sp->FUN_1422ce0e0() ? true : false;
    }
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8c))
    {
        {
            MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayShowOnlyMyPet"), -1);
            if (static_cast<ASButton*>(sp) != 0)
                m_state.m_bDisplayShowOnlyMyPet = sp->FUN_1422ce0e0() ? true : false;
        }
        {
            MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideMyPet"), -1);
            if (static_cast<ASButton*>(sp) != 0)
                m_state.m_bDisplayHideMyPet = sp->FUN_1422ce0e0() ? true : false;
        }
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideSmartPush"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayHideSmartPush = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayLearningQuest"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_flag.m_b = sp->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASButton> sp = ((Unk_GsDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayHideHighlightMenu"), -1);
        if (static_cast<ASButton*>(sp) != 0)
            m_state.m_bDisplayHideHighlightMenu = sp->FUN_1422ce0e0() ? true : false;
    }
}
MS2_REPLACE_METHOD(0x141259C40, CGameOptionStatus, vfunc_7, 4615, 0xD10475C2);

// Apply: the hud bars follow the switches; the pet switches are forwarded when they changed.
// @0x14125ae50
void CGameOptionStatus::vfunc_10()
{
    CBaseOption::vfunc_10();
    UIUpperHpBar* pHpBar = FUN_14096e340((eUIClassID)0x4e3d);
    if (pHpBar != 0)
    {
        pHpBar->FUN_141b4ce20(m_state.m_bDisplayMonsterGaugeValue);
        pHpBar->FUN_141b4ceb0(m_state.m_bDisplayOnlyMyEffectToMonster);
    }
    UIExpBar* pExpBar = Unk_GsFindUI<UIExpBar>((eUIClassID)0x4e27);
    if (pExpBar != 0)
        pExpBar->FUN_141932380(m_state.m_bDisplayExpValue);
    UIAdventureLevelExpBar* pAdvBar = Unk_GsFindUI<UIAdventureLevelExpBar>((eUIClassID)0x4f66);
    if (pAdvBar != 0)
        pAdvBar->FUN_140ba7080(m_state.m_bDisplayExpValue);
    if (m_state.m_bDisplayShowOnlyMyPet != TSingleton<CGameOption>::GetInstance()->FUN_140b123b0()->m_bDisplayShowOnlyMyPet)
        FUN_14125b130(m_state.m_bDisplayShowOnlyMyPet);
    if (m_state.m_bDisplayHideMyPet != TSingleton<CGameOption>::GetInstance()->FUN_140b123b0()->m_bDisplayHideMyPet)
        FUN_14125b140(m_state.m_bDisplayHideMyPet);
    FUN_14125c5a0(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0(), &m_state);
    FUN_14125c950(TSingleton<CGameOption>::GetInstance()->FUN_140ea41a0(), &m_flag);
    TSingleton<CGameOption>::GetInstance()->FUN_141243540();
}
MS2_REPLACE_METHOD(0x14125AE50, CGameOptionStatus, vfunc_10, 386, 0x5770892F);

// @0x14125afe0
void CGameOptionStatus::vfunc_12()
{
    FUN_14125bdd0(&m_state);
    FUN_14125bee0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    FUN_14125c8d0(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}
MS2_REPLACE_METHOD(0x14125AFE0, CGameOptionStatus, vfunc_12, 107, 0xA053E36E);

// @0x14125b060
CString CGameOptionStatus::GetTypeName()
{
    return CString("GameOptionStatus");
}
MS2_REPLACE_METHOD(0x14125B060, CGameOptionStatus, GetTypeName, 61, 0x02CA1024);

// @0x14125b0b0
int CGameOptionStatus::vfunc_14()
{
    if (memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140b123b0(), 0x1c) != 0)
        return 1;
    if (memcmp(&m_flag, TSingleton<CGameOption>::GetInstance()->FUN_140ea41a0(), 1) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14125B0B0, CGameOptionStatus, vfunc_14, 110, 0x0A1D6BC6);

// The pet switches' change hooks (empty in this build).
// @0x14125b130
void CGameOptionStatus::FUN_14125b130(bool b)
{
}
MS2_REPLACE_METHOD(0x14125B130, CGameOptionStatus, FUN_14125b130, 10, 0x208A1D67);

// @0x14125b140
void CGameOptionStatus::FUN_14125b140(bool b)
{
}
MS2_REPLACE_METHOD(0x14125B140, CGameOptionStatus, FUN_14125b140, 10, 0x208A1D67);

// ---- the option state blocks ----

// The TinyXML read/write helpers of the blocks (this unit, 0x141262f40..0x141263d30). The readers return 1 when the
// attribute was found.
void WriteGameOptionBool(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, bool bValue);
void WriteGameOptionInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, int nValue);
void WriteGameOptionFloat(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, float fValue);
void WriteGameOptionString(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, const CString& strValue);
void WriteGameOptionStringW(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, const CStringW& strValue);
void WriteGameOptionInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, __int64 nValue);
void WriteGameOptionUInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned __int64 nValue);
void WriteGameOptionUInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned nValue);
int ReadGameOptionBool(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, bool* pbValue);
int ReadGameOptionInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, int* pnValue);
int ReadGameOptionUInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned* pnValue);
int ReadGameOptionFloat(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, float* pfValue);
int ReadGameOptionString(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, CString* pstrValue);
int ReadGameOptionStringW(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, CStringW* pstrValue);
int ReadGameOptionInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, __int64* pnValue);
int ReadGameOptionUInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned __int64* pnValue);
void FUN_141263d30(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey);

// The mouse-control switch of the camera.
class Unk_GsMouseCtl
{
public:
    int FUN_140ad20f0(int bEnable);                                 // switch the controller on / off
    int FUN_140ad21b0();                                            // is the controller on
};
Unk_GsMouseCtl* FUN_140953f30();
class Unk_GsMyPC
{
public:
    __int64 FUN_141658eb0();                                    // the character creation time (+0xfe8)
    int FUN_141527e00();                                        // no house
    void FUN_141530720(int nVisit, CStringW strPassword, bool bNotify);   // set the house visit permission
};
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);                         // the npc table row
char* FUN_1401d3200();                                              // the game constants
int* FUN_1402056b0(char* pValue);                                   // an int constant

// The damage-form enum strings of the battle block.
CString FUN_140219790(int nForm);                                   // giveDamage / takeDamage value -> text
CString FUN_140219830(int nForm);                                   // otherDamageform value -> text
int FUN_140219900(const CString& str);
int FUN_140219960(const CString& str);

// CommunityStateB is 11 bytes (the copy moves 0xb); the shared header pads it to 0xc.
struct Unk_GsCommunityB
{
    bool m_b[0xb];
};

// @0x14125b400
Unk_CameraState* FUN_14125b400(Unk_CameraState* p)
{
    FUN_14125b430(p);
    return p;
}
MS2_REPLACE(0x14125B400, FUN_14125b400, 29, 0xFD4A1B24);

// @0x14125b430
void FUN_14125b430(Unk_CameraState* p)
{
    p->m_b00 = true;
    p->m_b01 = true;
    p->m_n04 = 100;
    p->m_n08 = 100;
    p->m_n0c = 0x82;
}
MS2_REPLACE(0x14125B430, FUN_14125b430, 59, 0x0F68ACC0);

// @0x14125b480
int LoadGameOptionCamera(Unk_CameraState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "camera", "bgTransparency", &p->m_b00);
    ReadGameOptionBool(pDoc, "camera", "vibrateEffect", &p->m_b01);
    ReadGameOptionInt(pDoc, "camera", "cameraLooseStep", &p->m_n04);
    ReadGameOptionInt(pDoc, "camera", "cameraFovStep", &p->m_n08);
    ReadGameOptionInt(pDoc, "camera", "cameraFovStepMouseMode", &p->m_n0c);
    if (p->m_n04 < 20)
        p->m_n04 = 20;
    if (p->m_n04 > 120)
        p->m_n04 = 120;
    if (p->m_n08 < 70)
        p->m_n08 = 70;
    if (p->m_n08 > 130)
        p->m_n08 = 130;
    if (p->m_n0c < 70)
        p->m_n0c = 70;
    if (p->m_n0c > 130)
        p->m_n0c = 130;
    return 1;
}
MS2_REPLACE(0x14125B480, LoadGameOptionCamera, 343, 0x9298A67F);

// The mouse-mode fov step is read back instead of written (as the exe has it).
// @0x14125b5e0
void SaveGameOptionCamera(Unk_CameraState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "camera", "bgTransparency", p->m_b00);
    WriteGameOptionBool(pDoc, "camera", "vibrateEffect", p->m_b01);
    WriteGameOptionInt(pDoc, "camera", "cameraLooseStep", p->m_n04);
    WriteGameOptionInt(pDoc, "camera", "cameraFovStep", p->m_n08);
    ReadGameOptionInt(pDoc, "camera", "cameraFovStepMouseMode", &p->m_n0c);
}
MS2_REPLACE(0x14125B5E0, SaveGameOptionCamera, 188, 0xC19837D2);

// @0x14125b6b0
void FUN_14125b6b0(Unk_CameraState* pDst, const Unk_CameraState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125B6B0, FUN_14125b6b0, 32, 0x0136D6DC);

// The fov step of the current camera mode.
// @0x14125b6e0
int FUN_14125b6e0(const Unk_CameraState* p)
{
    if (FUN_140953f30()->FUN_140ad21b0() != 0)
        return p->m_n0c;
    return p->m_n08;
}
MS2_REPLACE(0x14125B6E0, FUN_14125b6e0, 49, 0xB1836D80);

// @0x14125b720
void FUN_14125b720(Unk_CameraState* p, int n)
{
    if (FUN_140953f30()->FUN_140ad21b0() != 0)
        p->m_n0c = n;
    else
        p->m_n08 = n;
}
MS2_REPLACE(0x14125B720, FUN_14125b720, 61, 0x96BC0594);

// @0x14125b770
Unk_InterfaceState* FUN_14125b770(Unk_InterfaceState* p)
{
    FUN_14125b7a0(p);
    return p;
}
MS2_REPLACE(0x14125B770, FUN_14125b770, 29, 0xFD4A1B24);

// @0x14125b7a0
void FUN_14125b7a0(Unk_InterfaceState* p)
{
    p->m_b00 = false;
    p->m_b01 = true;
    p->m_b02 = true;
    p->m_b03 = false;
    p->m_b04 = false;
    p->m_f08 = 1.0f;
    p->m_n0c = 100;
    p->m_n10 = 100;
    p->m_b14 = true;
    p->m_b15 = true;
}
MS2_REPLACE(0x14125B7A0, FUN_14125b7a0, 110, 0x18FE6E62);

// @0x14125b820
int LoadGameOptionInterface(Unk_InterfaceState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "interface", "EnableCloseAllDlg", &p->m_b00);
    ReadGameOptionBool(pDoc, "interface", "EnableAutoDesc", &p->m_b01);
    ReadGameOptionBool(pDoc, "interface", "EnableShowTipText", &p->m_b02);
    ReadGameOptionBool(pDoc, "interface", "EnableIndividualDamageMeter", &p->m_b03);
    ReadGameOptionBool(pDoc, "interface", "EnableChaosDamageMeter", &p->m_b04);
    ReadGameOptionFloat(pDoc, "interface", "UIScale", &p->m_f08);
    ReadGameOptionInt(pDoc, "interface", "DamageTextScaleStep", &p->m_n10);
    ReadGameOptionInt(pDoc, "interface", "damageEffectAlpha", &p->m_n0c);
    if (p->m_f08 < 0.8f)
        p->m_f08 = 0.8f;
    if (p->m_f08 > 1.2f)
        p->m_f08 = 1.2f;
    if (p->m_n10 < 50)
        p->m_n10 = 50;
    if (p->m_n10 > 150)
        p->m_n10 = 150;
    if (p->m_n0c < 0)
        p->m_n0c = 0;
    if (p->m_n0c > 100)
        p->m_n0c = 100;
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xbe))
        p->m_b04 = false;
    return 1;
}
MS2_REPLACE(0x14125B820, LoadGameOptionInterface, 510, 0x1CFDA126);

// @0x14125ba30
void SaveGameOptionInterface(Unk_InterfaceState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "interface", "EnableCloseAllDlg", p->m_b00);
    WriteGameOptionBool(pDoc, "interface", "EnableAutoDesc", p->m_b01);
    WriteGameOptionBool(pDoc, "interface", "EnableShowTipText", p->m_b02);
    WriteGameOptionBool(pDoc, "interface", "EnableIndividualDamageMeter", p->m_b03);
    WriteGameOptionBool(pDoc, "interface", "EnableChaosDamageMeter", p->m_b04);
    WriteGameOptionFloat(pDoc, "interface", "UIScale", p->m_f08);
    WriteGameOptionInt(pDoc, "interface", "DamageTextScaleStep", p->m_n10);
    WriteGameOptionInt(pDoc, "interface", "damageEffectAlpha", p->m_n0c);
}
MS2_REPLACE(0x14125BA30, SaveGameOptionInterface, 288, 0x5AF41E6A);

// @0x14125bb60
void FUN_14125bb60(Unk_InterfaceState* pDst, const Unk_InterfaceState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125BB60, FUN_14125bb60, 32, 0xB57C9844);

// The individual damage meter is on.
// @0x14125bb90
bool FUN_14125bb90(const Unk_InterfaceState* p)
{
    return p->m_b03 && p->m_b14;
}
MS2_REPLACE(0x14125BB90, FUN_14125bb90, 60, 0xDBA8AFED);

// The chaos damage meter is on.
// @0x14125bbe0
bool FUN_14125bbe0(const Unk_InterfaceState* p)
{
    return p->m_b04 && p->m_b15;
}
MS2_REPLACE(0x14125BBE0, FUN_14125bbe0, 60, 0xDDB74B71);

// @0x14125bc30
Unk_InterfaceFlag* FUN_14125bc30(Unk_InterfaceFlag* p)
{
    FUN_14125bc60(p);
    return p;
}
MS2_REPLACE(0x14125BC30, FUN_14125bc30, 29, 0xFD4A1B24);

// @0x14125bc60
void FUN_14125bc60(Unk_InterfaceFlag* p)
{
    p->m_b = false;
}
MS2_REPLACE(0x14125BC60, FUN_14125bc60, 14, 0x322C4B62);

// @0x14125bc80
int FUN_14125bc80(Unk_InterfaceFlag* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "interface", "EnableMouseControl", &p->m_b);
    return 1;
}
MS2_REPLACE(0x14125BC80, FUN_14125bc80, 56, 0x21B48804);

// @0x14125bcc0
void FUN_14125bcc0(Unk_InterfaceFlag* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "interface", "EnableMouseControl", p->m_b);
}
MS2_REPLACE(0x14125BCC0, FUN_14125bcc0, 52, 0xF4D04A6F);

// @0x14125bd00
void FUN_14125bd00(Unk_InterfaceFlag* pDst, const Unk_InterfaceFlag* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125BD00, FUN_14125bd00, 26, 0x0A97A110);

// The mouse control switch: the controller and the hud button follow it.
// @0x14125bd20
void FUN_14125bd20(Unk_InterfaceFlag* p, bool b)
{
    p->m_b = b;
    FUN_140953f30()->FUN_140ad20f0(b);
    UIUpperHudDialog* pHud = Unk_GsFindUI<UIUpperHudDialog>((eUIClassID)0x4ebe);
    if (pHud != 0)
        pHud->FUN_141357580(b == false);
}
MS2_REPLACE(0x14125BD20, FUN_14125bd20, 122, 0x29455619);

// @0x14125bda0
Unk_StatusState* FUN_14125bda0(Unk_StatusState* p)
{
    FUN_14125bdd0(p);
    return p;
}
MS2_REPLACE(0x14125BDA0, FUN_14125bda0, 29, 0xFD4A1B24);

// @0x14125bdd0
void FUN_14125bdd0(Unk_StatusState* p)
{
    p->m_bDisplayMyName = true;
    p->m_bDisplayPlayerSymbol = true;
    p->m_bDisplayFriendlyName = true;
    p->m_bDisplayEnemyName = true;
    p->m_bDisplayNpcName = true;
    p->m_bDisplayMonsterName = false;
    p->m_bDisplayMonsterGaugeValue = true;
    p->m_bDisplayExpValue = true;
    p->m_bDisplayOnlyMyEffectToMonster = false;
    p->m_bDisplayMyHpGauge = false;
    p->m_bDisplayMyShieldGauge = true;
    p->m_bDisplayPartyHpGauge = false;
    p->m_bDisplayPartyShieldGauge = true;
    p->m_bDisplayMonsterHpGauge = false;
    p->m_bDisplayNormalChatBalloon = true;
    p->m_bDisplayPartyChatBalloon = true;
    p->m_bDisplayGuildChatBalloon = true;
    p->m_bDisplayShowOnlyMyPet = false;
    p->m_bDisplayHideMyPet = false;
    p->m_bDisplayHideSmartPush = false;
    p->m_bDisplayHideHighlightMenu = false;
    p->m_n18 = 0;
    p->m_bDisplayPcIllust = false;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036e4c0())
        p->m_bDisplayPcIllust = true;
}
MS2_REPLACE(0x14125BDD0, FUN_14125bdd0, 252, 0x9CBFCD59);

// @0x14125bee0
int FUN_14125bee0(Unk_StatusState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "status", "DisplayMyName", &p->m_bDisplayMyName);
    ReadGameOptionBool(pDoc, "status", "DisplayPlayerSymbol", &p->m_bDisplayPlayerSymbol);
    ReadGameOptionBool(pDoc, "status", "DisplayFriendlyName", &p->m_bDisplayFriendlyName);
    ReadGameOptionBool(pDoc, "status", "DisplayEnemyName", &p->m_bDisplayEnemyName);
    ReadGameOptionBool(pDoc, "status", "DisplayNpcName", &p->m_bDisplayNpcName);
    ReadGameOptionBool(pDoc, "status", "DisplayMonsterName", &p->m_bDisplayMonsterName);
    ReadGameOptionBool(pDoc, "status", "DisplayPcIllust", &p->m_bDisplayPcIllust);
    ReadGameOptionBool(pDoc, "status", "DisplayMonsterGaugeValue", &p->m_bDisplayMonsterGaugeValue);
    ReadGameOptionBool(pDoc, "status", "DisplayExpValue", &p->m_bDisplayExpValue);
    ReadGameOptionBool(pDoc, "status", "DisplayOnlyMyEffectToMonster", &p->m_bDisplayOnlyMyEffectToMonster);
    ReadGameOptionBool(pDoc, "status", "DisplayMyHpGauge", &p->m_bDisplayMyHpGauge);
    ReadGameOptionBool(pDoc, "status", "DisplayMyShieldGauge", &p->m_bDisplayMyShieldGauge);
    ReadGameOptionBool(pDoc, "status", "DisplayPartyHpGauge", &p->m_bDisplayPartyHpGauge);
    ReadGameOptionBool(pDoc, "status", "DisplayPartyShieldGauge", &p->m_bDisplayPartyShieldGauge);
    ReadGameOptionBool(pDoc, "status", "DisplayMonsterHpGauge", &p->m_bDisplayMonsterHpGauge);
    ReadGameOptionInt(pDoc, "status", "DisplayBossMonsterNotify", &p->m_n18);
    ReadGameOptionBool(pDoc, "status", "DisplayNormalChatBalloon", &p->m_bDisplayNormalChatBalloon);
    ReadGameOptionBool(pDoc, "status", "DisplayPartyChatBalloon", &p->m_bDisplayPartyChatBalloon);
    ReadGameOptionBool(pDoc, "status", "DisplayGuildChatBalloon", &p->m_bDisplayGuildChatBalloon);
    ReadGameOptionBool(pDoc, "status", "DisplayShowOnlyMyPet", &p->m_bDisplayShowOnlyMyPet);
    ReadGameOptionBool(pDoc, "status", "DisplayHideMyPet", &p->m_bDisplayHideMyPet);
    ReadGameOptionBool(pDoc, "status", "DisplayHideSmartPush", &p->m_bDisplayHideSmartPush);
    ReadGameOptionBool(pDoc, "status", "DisplayHideHighlightMenu", &p->m_bDisplayHideHighlightMenu);
    if (p->m_n18 < 0)
        p->m_n18 = 0;
    if (p->m_n18 > 2)
        p->m_n18 = 2;
    return 1;
}
MS2_REPLACE(0x14125BEE0, FUN_14125bee0, 893, 0x3971AAC4);

// @0x14125c270
void SaveGameOptionStatus(Unk_StatusState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "status", "DisplayMyName", p->m_bDisplayMyName);
    WriteGameOptionBool(pDoc, "status", "DisplayPlayerSymbol", p->m_bDisplayPlayerSymbol);
    WriteGameOptionBool(pDoc, "status", "DisplayFriendlyName", p->m_bDisplayFriendlyName);
    WriteGameOptionBool(pDoc, "status", "DisplayEnemyName", p->m_bDisplayEnemyName);
    WriteGameOptionBool(pDoc, "status", "DisplayNpcName", p->m_bDisplayNpcName);
    WriteGameOptionBool(pDoc, "status", "DisplayMonsterName", p->m_bDisplayMonsterName);
    WriteGameOptionBool(pDoc, "status", "DisplayPcIllust", p->m_bDisplayPcIllust);
    WriteGameOptionBool(pDoc, "status", "DisplayMonsterGaugeValue", p->m_bDisplayMonsterGaugeValue);
    WriteGameOptionBool(pDoc, "status", "DisplayExpValue", p->m_bDisplayExpValue);
    WriteGameOptionBool(pDoc, "status", "DisplayOnlyMyEffectToMonster", p->m_bDisplayOnlyMyEffectToMonster);
    WriteGameOptionBool(pDoc, "status", "DisplayMyHpGauge", p->m_bDisplayMyHpGauge);
    WriteGameOptionBool(pDoc, "status", "DisplayMyShieldGauge", p->m_bDisplayMyShieldGauge);
    WriteGameOptionBool(pDoc, "status", "DisplayPartyHpGauge", p->m_bDisplayPartyHpGauge);
    WriteGameOptionBool(pDoc, "status", "DisplayPartyShieldGauge", p->m_bDisplayPartyShieldGauge);
    WriteGameOptionBool(pDoc, "status", "DisplayMonsterHpGauge", p->m_bDisplayMonsterHpGauge);
    WriteGameOptionInt(pDoc, "status", "DisplayBossMonsterNotify", p->m_n18);
    WriteGameOptionBool(pDoc, "status", "DisplayNormalChatBalloon", p->m_bDisplayNormalChatBalloon);
    WriteGameOptionBool(pDoc, "status", "DisplayPartyChatBalloon", p->m_bDisplayPartyChatBalloon);
    WriteGameOptionBool(pDoc, "status", "DisplayGuildChatBalloon", p->m_bDisplayGuildChatBalloon);
    WriteGameOptionBool(pDoc, "status", "DisplayShowOnlyMyPet", p->m_bDisplayShowOnlyMyPet);
    WriteGameOptionBool(pDoc, "status", "DisplayHideMyPet", p->m_bDisplayHideMyPet);
    WriteGameOptionBool(pDoc, "status", "DisplayHideSmartPush", p->m_bDisplayHideSmartPush);
    WriteGameOptionBool(pDoc, "status", "DisplayHideHighlightMenu", p->m_bDisplayHideHighlightMenu);
}
MS2_REPLACE(0x14125C270, SaveGameOptionStatus, 799, 0xDD0F9536);

// @0x14125c5a0
void FUN_14125c5a0(Unk_StatusState* pDst, const Unk_StatusState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125C5A0, FUN_14125c5a0, 32, 0xE7104ED8);

// Whether the boss-monster notice of an npc is shown, and how (*pnType 0 = by level, 1 = by quest, 2 = none).
// MS2-FUNCTIONAL: temp layout of the boss-notice branch differs; same calls and stores
// @0x14125c5d0
int FUN_14125c5d0(Unk_StatusState* p, int nNpcId, int* pnType, int* pnValue)
{
    *pnType = 2;
    *pnValue = 0;
    if (TSingleton<CGameOption>::GetInstance()->FUN_140b123b0()->m_n18 == 1)
    {
        if (TSingleton<CQuestManager>::GetInstance()->FUN_1416cede0(nNpcId, (unsigned*)pnValue) == 0)
            return 0;
        *pnType = 1;
        return 1;
    }
    if (TSingleton<CGameOption>::GetInstance()->FUN_140b123b0()->m_n18 == 0)
    {
        if (TSingleton<CQuestManager>::GetInstance()->FUN_1416cede0(nNpcId, (unsigned*)pnValue) != 0)
        {
            *pnType = 1;
            return 1;
        }
        PCBase* pPlayer = (PCBase*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
        MS2Ptr<CNpcData> spNpc = FUN_1406cd330(nNpcId);
        if (spNpc.IsNull())
            return 0;
        if (spNpc->GetLevel() < 50)
        {
            int nLevel = (unsigned short)pPlayer->vfunc_78();
            int nDiff = abs(nLevel - spNpc->GetLevel());
            if (*FUN_1402056b0(FUN_1401d3200() + 0xcf88) < nDiff)
                return 0;
            *pnType = 0;
            return 1;
        }
        if ((unsigned short)pPlayer->vfunc_78() >= 50)
        {
            *pnType = 0;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x14125C5D0, FUN_14125c5d0, 578, 0x95152BEA);

// The chat balloon switch of a chat type.
// @0x14125c820
int FUN_14125c820(const Unk_StatusState* p, int nType)
{
    if (nType == 0)
        return p->m_bDisplayNormalChatBalloon;
    else if (nType == 7)
        return p->m_bDisplayPartyChatBalloon;
    else if (nType == 8)
        return p->m_bDisplayGuildChatBalloon;
    else if (nType == 0x17)
        return p->m_bDisplayGuildChatBalloon;
    return 0;
}
MS2_REPLACE(0x14125C820, FUN_14125c820, 84, 0x5B5B7B67);

// @0x14125c880
Unk_StatusFlag* FUN_14125c880(Unk_StatusFlag* p)
{
    FUN_14125c8b0(p);
    return p;
}
MS2_REPLACE(0x14125C880, FUN_14125c880, 29, 0xFD4A1B24);

// @0x14125c8b0
void FUN_14125c8b0(Unk_StatusFlag* p)
{
    p->m_b = false;
}
MS2_REPLACE(0x14125C8B0, FUN_14125c8b0, 14, 0x322C4B62);

// @0x14125c8d0
int FUN_14125c8d0(Unk_StatusFlag* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "status", "displayLearningQuestV2", &p->m_b);
    return 1;
}
MS2_REPLACE(0x14125C8D0, FUN_14125c8d0, 56, 0x5911D3D6);

// @0x14125c910
void FUN_14125c910(Unk_StatusFlag* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "status", "displayLearningQuestV2", p->m_b);
}
MS2_REPLACE(0x14125C910, FUN_14125c910, 52, 0xD8B62C79);

// @0x14125c950
void FUN_14125c950(Unk_StatusFlag* pDst, const Unk_StatusFlag* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125C950, FUN_14125c950, 26, 0x0A97A110);

// A character file without the learning-quest switch: on for characters created before 2017-06-29.
// @0x14125c970
int FUN_14125c970(Unk_StatusFlag* p, TiXmlDocument* pDoc)
{
    bool bValue = false;
    if (ReadGameOptionBool(pDoc, "status", "displayLearningQuestV2", &bValue) == 0)
    {
        Unk_GsMyPC* pPlayer = (Unk_GsMyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            CMsTime timeLimit(2017, 6, 29, 0, 0, 0);
            CMsTime timeCreate(pPlayer->FUN_141658eb0());
            if (timeCreate < timeLimit)
                bValue = true;
            p->m_b = bValue;
            WriteGameOptionBool(pDoc, "status", "displayLearningQuestV2", p->m_b);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x14125C970, FUN_14125c970, 258, 0xDD7483DE);

// @0x14125ca80
Unk_BattleState* FUN_14125ca80(Unk_BattleState* p)
{
    FUN_14125cab0(p);
    return p;
}
MS2_REPLACE(0x14125CA80, FUN_14125ca80, 29, 0xFD4A1B24);

// @0x14125cab0
void FUN_14125cab0(Unk_BattleState* p)
{
    p->m_bDisplayMyGiveRecovery = true;
    p->m_bDisplayMyTakeRecovery = true;
    p->m_bDisplayPartyRecovery = true;
    p->m_bDisplayGetMeso = true;
    p->m_bDisplayGetExp = true;
    p->m_bDisplayEpGauge = true;
    p->m_n08 = 7;
    p->m_n0c = 3;
    p->m_n10 = 3;
}
MS2_REPLACE(0x14125CAB0, FUN_14125cab0, 95, 0x347A1EFF);

// The damage forms come from the "damage" section; older files only have the battle switches.
// MS2-FUNCTIONAL: temp layout differs; same reads and clamps
// @0x14125cb20
int FUN_14125cb20(Unk_BattleState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "battle", "DisplayGetMeso", &p->m_bDisplayGetMeso);
    ReadGameOptionBool(pDoc, "battle", "DisplayGetExp", &p->m_bDisplayGetExp);
    ReadGameOptionBool(pDoc, "battle", "DisplayEpGauge", &p->m_bDisplayEpGauge);
    ReadGameOptionBool(pDoc, "battle", "DisplayMyGiveRecovery", &p->m_bDisplayMyGiveRecovery);
    ReadGameOptionBool(pDoc, "battle", "DisplayMyTakeRecovery", &p->m_bDisplayMyTakeRecovery);
    ReadGameOptionBool(pDoc, "battle", "DisplayPartyRecovery", &p->m_bDisplayPartyRecovery);
    CString strGive;
    if (ReadGameOptionString(pDoc, "damage", "giveDamage", &strGive) == 0)
    {
        bool bAll = TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x66);
        if (!bAll)
        {
            bool bMine = true;
            bool bParty = false;
            ReadGameOptionBool(pDoc, "battle", "DisplayMyGiveDamage", &bMine);
            ReadGameOptionBool(pDoc, "battle", "DisplayPartyGiveDamage", &bParty);
            if (bMine && !bParty)
                p->m_n08 = 1;
            else
                p->m_n08 = 3;
        }
        else
        {
            p->m_n08 = 7;
        }
        bool bMineTake = true;
        bool bPartyTake = false;
        ReadGameOptionBool(pDoc, "battle", "DisplayMyTakeDamage", &bMineTake);
        ReadGameOptionBool(pDoc, "battle", "DisplayPartyTakeDamage", &bPartyTake);
        if (bMineTake && !bPartyTake)
            p->m_n0c = 1;
        else
            p->m_n0c = 3;
        p->m_n10 = 3;
    }
    else
    {
        p->m_n08 = FUN_140219900(strGive);
        CString strTake;
        ReadGameOptionString(pDoc, "damage", "takeDamage", &strTake);
        p->m_n0c = FUN_140219900(strTake);
        CString strOther;
        ReadGameOptionString(pDoc, "damage", "otherDamageform", &strOther);
        p->m_n10 = FUN_140219960(strOther);
    }
    return 1;
}
MS2_REPLACE(0x14125CB20, FUN_14125cb20, 756, 0xFCD95ED1);

// The old battle damage switches are dropped when the block is saved.
// @0x14125ce20
void FUN_14125ce20(Unk_BattleState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "battle", "DisplayMyGiveRecovery", p->m_bDisplayMyGiveRecovery);
    WriteGameOptionBool(pDoc, "battle", "DisplayMyTakeRecovery", p->m_bDisplayMyTakeRecovery);
    WriteGameOptionBool(pDoc, "battle", "DisplayPartyRecovery", p->m_bDisplayPartyRecovery);
    WriteGameOptionBool(pDoc, "battle", "DisplayGetMeso", p->m_bDisplayGetMeso);
    WriteGameOptionBool(pDoc, "battle", "DisplayGetExp", p->m_bDisplayGetExp);
    WriteGameOptionBool(pDoc, "battle", "DisplayEpGauge", p->m_bDisplayEpGauge);
    FUN_141263d30(pDoc, "battle", "DisplayDropIcon");
    FUN_141263d30(pDoc, "battle", "DisplayMyGiveDamage");
    FUN_141263d30(pDoc, "battle", "DisplayPartyGiveDamage");
    FUN_141263d30(pDoc, "battle", "DisplayMyTakeDamage");
    FUN_141263d30(pDoc, "battle", "DisplayPartyTakeDamage");
    FUN_141263d30(pDoc, "battle", "DiffColor");
    FUN_141263d30(pDoc, "battle", "DiffSize");
    FUN_141263d30(pDoc, "battle", "DiffAlpha");
    WriteGameOptionString(pDoc, "damage", "giveDamage", FUN_140219790(p->m_n08));
    WriteGameOptionString(pDoc, "damage", "takeDamage", FUN_140219790(p->m_n0c));
    WriteGameOptionString(pDoc, "damage", "otherDamageform", FUN_140219830(p->m_n10));
}
MS2_REPLACE(0x14125CE20, FUN_14125ce20, 723, 0xDBA396EF);

// @0x14125d100
void FUN_14125d100(Unk_BattleState* pDst, const Unk_BattleState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125D100, FUN_14125d100, 32, 0xF011C8B0);

// @0x14125d130
Unk_CommunityStateA* FUN_14125d130(Unk_CommunityStateA* p)
{
    FUN_14125d160(p);
    return p;
}
MS2_REPLACE(0x14125D130, FUN_14125d130, 29, 0xFD4A1B24);

// @0x14125d160
void FUN_14125d160(Unk_CommunityStateA* p)
{
    p->m_bDisplayMyChatBalloon = true;
    p->m_bDisplayOtherChatBalloon = true;
    p->m_bDisableSingleRiding = false;
}
MS2_REPLACE(0x14125D160, FUN_14125d160, 32, 0xFCBEDFB9);

// @0x14125d190
int FUN_14125d190(Unk_CommunityStateA* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "community", "displayMyChatBalloon", &p->m_bDisplayMyChatBalloon);
    ReadGameOptionBool(pDoc, "community", "displayOtherChatBalloon", &p->m_bDisplayOtherChatBalloon);
    ReadGameOptionBool(pDoc, "community", "disableSingleRiding", &p->m_bDisableSingleRiding);
    return 1;
}
MS2_REPLACE(0x14125D190, FUN_14125d190, 127, 0x605F6137);

// @0x14125d220
void FUN_14125d220(Unk_CommunityStateA* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "community", "displayMyChatBalloon", p->m_bDisplayMyChatBalloon);
    WriteGameOptionBool(pDoc, "community", "displayOtherChatBalloon", p->m_bDisplayOtherChatBalloon);
    WriteGameOptionBool(pDoc, "community", "disableSingleRiding", p->m_bDisableSingleRiding);
}
MS2_REPLACE(0x14125D220, FUN_14125d220, 120, 0x2160F316);

// @0x14125d2a0
void FUN_14125d2a0(Unk_CommunityStateA* pDst, const Unk_CommunityStateA* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125D2A0, FUN_14125d2a0, 32, 0x28C5FB01);

// @0x14125d2d0
bool FUN_14125d2d0(const Unk_CommunityStateA* p, const Unk_CommunityStateA* q)
{
    if (p->m_bDisplayMyChatBalloon != q->m_bDisplayMyChatBalloon)
        return true;
    if (p->m_bDisplayOtherChatBalloon != q->m_bDisplayOtherChatBalloon)
        return true;
    if (p->m_bDisableSingleRiding != q->m_bDisableSingleRiding)
        return true;
    return false;
}
MS2_REPLACE(0x14125D2D0, FUN_14125d2d0, 89, 0x69F743A1);

// @0x14125d330
Unk_CommunityStateB* FUN_14125d330(Unk_CommunityStateB* p)
{
    FUN_14125d360(p);
    return p;
}
MS2_REPLACE(0x14125D330, FUN_14125d330, 29, 0xFD4A1B24);

// @0x14125d360
void FUN_14125d360(Unk_CommunityStateB* p)
{
    p->m_bDisplayChatComfirmSuper = true;
    p->m_bDisplayChatComfirmWorld = true;
    p->m_bDisplayChatComfirmChannel = true;
    p->m_bDisablePartyRequest = false;
    p->m_bDisableBuddyRequest = false;
    p->m_bDisableGuildRequest = false;
    p->m_bDisableGroupRequest = false;
    p->m_bDisableWhisperNotify = false;
    p->m_bDisableTradeRequest = false;
    p->m_bDisableHomeRequest = false;
    p->m_bDisableCouplemotionRequest = false;
}
MS2_REPLACE(0x14125D360, FUN_14125d360, 104, 0xC8A648D8);

// @0x14125d3d0
int FUN_14125d3d0(Unk_CommunityStateB* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "community", "displayChatComfirmSuper", &p->m_bDisplayChatComfirmSuper);
    ReadGameOptionBool(pDoc, "community", "displayChatComfirmWorld", &p->m_bDisplayChatComfirmWorld);
    ReadGameOptionBool(pDoc, "community", "displayChatComfirmChannel", &p->m_bDisplayChatComfirmChannel);
    ReadGameOptionBool(pDoc, "community", "disablePartyRequest", &p->m_bDisablePartyRequest);
    ReadGameOptionBool(pDoc, "community", "disableBuddyRequest", &p->m_bDisableBuddyRequest);
    ReadGameOptionBool(pDoc, "community", "disableGuildRequest", &p->m_bDisableGuildRequest);
    ReadGameOptionBool(pDoc, "community", "disableGroupRequest", &p->m_bDisableGroupRequest);
    ReadGameOptionBool(pDoc, "community", "disableWhisperNotify", &p->m_bDisableWhisperNotify);
    ReadGameOptionBool(pDoc, "community", "disableTradeRequest", &p->m_bDisableTradeRequest);
    ReadGameOptionBool(pDoc, "community", "disableHomeRequest", &p->m_bDisableHomeRequest);
    ReadGameOptionBool(pDoc, "community", "disableCouplemotionRequest", &p->m_bDisableCouplemotionRequest);
    return 1;
}
MS2_REPLACE(0x14125D3D0, FUN_14125d3d0, 415, 0x3E37BCD3);

// @0x14125d580
void FUN_14125d580(Unk_CommunityStateB* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "community", "displayChatComfirmSuper", p->m_bDisplayChatComfirmSuper);
    WriteGameOptionBool(pDoc, "community", "displayChatComfirmWorld", p->m_bDisplayChatComfirmWorld);
    WriteGameOptionBool(pDoc, "community", "displayChatComfirmChannel", p->m_bDisplayChatComfirmChannel);
    WriteGameOptionBool(pDoc, "community", "disablePartyRequest", p->m_bDisablePartyRequest);
    WriteGameOptionBool(pDoc, "community", "disableBuddyRequest", p->m_bDisableBuddyRequest);
    WriteGameOptionBool(pDoc, "community", "disableGuildRequest", p->m_bDisableGuildRequest);
    WriteGameOptionBool(pDoc, "community", "disableGroupRequest", p->m_bDisableGroupRequest);
    WriteGameOptionBool(pDoc, "community", "disableWhisperNotify", p->m_bDisableWhisperNotify);
    WriteGameOptionBool(pDoc, "community", "disableTradeRequest", p->m_bDisableTradeRequest);
    WriteGameOptionBool(pDoc, "community", "disableHomeRequest", p->m_bDisableHomeRequest);
    WriteGameOptionBool(pDoc, "community", "disableCouplemotionRequest", p->m_bDisableCouplemotionRequest);
}
MS2_REPLACE(0x14125D580, FUN_14125d580, 392, 0xBFF9E235);

// @0x14125d710
void FUN_14125d710(Unk_CommunityStateB* pDst, const Unk_CommunityStateB* pSrc)
{
    *(Unk_GsCommunityB*)pDst = *(const Unk_GsCommunityB*)pSrc;
}
MS2_REPLACE(0x14125D710, FUN_14125d710, 32, 0x1FC48129);

// @0x14125d740
bool FUN_14125d740(const Unk_CommunityStateB* p, const Unk_CommunityStateB* q)
{
    if (p->m_bDisplayChatComfirmSuper != q->m_bDisplayChatComfirmSuper)
        return true;
    if (p->m_bDisplayChatComfirmWorld != q->m_bDisplayChatComfirmWorld)
        return true;
    if (p->m_bDisplayChatComfirmChannel != q->m_bDisplayChatComfirmChannel)
        return true;
    if (p->m_bDisablePartyRequest != q->m_bDisablePartyRequest)
        return true;
    if (p->m_bDisableBuddyRequest != q->m_bDisableBuddyRequest)
        return true;
    if (p->m_bDisableGuildRequest != q->m_bDisableGuildRequest)
        return true;
    if (p->m_bDisableGroupRequest != q->m_bDisableGroupRequest)
        return true;
    if (p->m_bDisableWhisperNotify != q->m_bDisableWhisperNotify)
        return true;
    if (p->m_bDisableTradeRequest != q->m_bDisableTradeRequest)
        return true;
    if (p->m_bDisableHomeRequest != q->m_bDisableHomeRequest)
        return true;
    if (p->m_bDisableCouplemotionRequest != q->m_bDisableCouplemotionRequest)
        return true;
    return false;
}
MS2_REPLACE(0x14125D740, FUN_14125d740, 315, 0x8E566C7D);


// ---- graphics helpers: the services and renderer views they use ----------------------------------------------------
// The current field's data (WorldService::FUN_141bd30a0): the field can switch effects off.
struct Unk_GsFieldFlags
{
    char m_pad0[0x1fc];
    bool m_b1fc;                                                // +0x1fc
    bool m_b1fd;                                                // +0x1fd
    char m_pad1fe[0x220 - 0x1fe];
    bool m_b220;                                                // +0x220 hdr allowed
};
// The post effect manager (FUN_1409a8b00).
class Unk_GsPostEffectMgr
{
public:
    bool FUN_1409a4c60(bool bHdr, int n);                       // hdr on / off; true when it took
    void FUN_1409a5190(bool bEnable);
};
Unk_GsPostEffectMgr* FUN_1409a8b00();
PostProcessingService* FUN_1409a8b20();
void FUN_1409a5850(void* pDst, const void* pSrc, int nSize);
extern char DAT_143ae53c0;
// The renderer's display mode list (see gameoption.cpp).
struct Unk_GsRawMode
{
    int m_nWidth;
    int m_nHeight;
    int m_nFormat;
};
struct Unk_GsModeSource
{
    Unk_GsRawMode* FUN_14124fee0(unsigned int nIndex);          // the nIndex-th mode (or null)
    unsigned int FUN_14124ff10();                               // count
};
class Unk_GsRenderer
{
public:
    Unk_GsModeSource* FUN_14124fea0();                          // +0x728 the display mode source
};
Unk_GsRenderer* FUN_140994450();                                // NiRenderer::GetRenderer()
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);
extern const NiRTTI DAT_143d6eb58;                              // NiDX9Renderer::ms_RTTI
IDirect3DDevice9* FUN_140d89690(NiObject* pRenderer);           // NiDX9Renderer::GetD3DDevice
// The application window.
class Unk_GsApp
{
public:
    void FUN_1412642e0(bool b);
    bool FUN_141b91010(bool bFullscreen, int nWidth, int nHeight);
    char m_pad[0xd0];
    bool m_bd0;                                                 // +0xd0
};
Unk_GsApp* FUN_140aadf80();
ecr::SceneGraphService* FUN_1413f98b0();
COptimizer* FUN_1409f7c90();
// The network service's callbacks (slot 65 takes the hide-others level).
class Unk_GsNetCallbacks
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34();
    virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44();
    virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54();
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64();
    virtual void vfunc_65(int nOptimalHide);
};
Unk_GsNetCallbacks* FUN_140d86260();
// MS2LightService's scene light scale (a member past ecr::LightService).
void FUN_1414c0820(ecr::LightService* pService, float fScale);
// GetService<T>: the framework's service manager, asked for system service T (instance 0x141264100 -> 0x141264120).
Unk_ServiceManager* FUN_1413f9850();
template <class T> T* GetService() { return FUN_1413f9850()->GetSystemServiceAs<T>(); }

// The quality-level table: the hdr / dof / shimmer flags of a level.
class Unk_GsQuality
{
public:
    int FUN_141376510(int nLevel);                                  // hdr
    int FUN_141376580(int nLevel);
    int FUN_1413765f0(int nLevel);                                  // shimmer
};
Unk_GsQuality* FUN_140ae1c00();
void FUN_14125eb00(Unk_GraphicState* p, int nWidth, int nHeight);
void FUN_14125e300(Unk_GraphicState* p, int b);

// @0x14125d890
Unk_GraphicState* FUN_14125d890(Unk_GraphicState* p)
{
    FUN_14125d8c0(p);
    return p;
}
MS2_REPLACE(0x14125D890, FUN_14125d890, 29, 0xFD4A1B24);

// @0x14125d8c0
void FUN_14125d8c0(Unk_GraphicState* p)
{
    p->m_nQuality = 3;
    p->m_nResIdx = 0;
    p->m_nScreenMode = 1;
    p->m_n0c = 1;
    p->m_nEffectStep = 3;
    p->m_bShowFrameRate = false;
    p->m_b15 = false;
    p->m_nWidth = 0x400;
    p->m_nHeight = 0x300;
    p->m_nShadow = 2;
    p->m_nMultisampling = 0;
    p->m_b18 = true;
    p->m_b1a = false;
    p->m_b1b = false;
    p->m_bHdr = false;
    p->m_bShimmer = false;
    p->m_b1f = true;
    p->m_b1d = true;
    p->m_b1e = true;
    p->m_bVsync = true;
    p->m_bEnchantEffect = true;
}
MS2_REPLACE(0x14125D8C0, FUN_14125d8c0, 221, 0x0BAE5914);

// nDefault: the shipped defaults; the quality follows the benchmark and the resolution the desktop.
// @0x14125d9b0
int FUN_14125d9b0(Unk_GraphicState* p, TiXmlDocument* pDoc, int nDefault)
{
    if (nDefault != 0)
    {
        p->m_nQuality = TSingleton<CGameOption>::GetInstance()->FUN_1412438f0();
        p->m_bHdr = FUN_140ae1c00()->FUN_141376510(p->m_nQuality) ? true : false;
        p->m_bShimmer = FUN_140ae1c00()->FUN_1413765f0(p->m_nQuality) ? true : false;
        p->m_nMultisampling = 0;
        p->m_nEffectStep = p->m_nQuality;
        p->m_nShadow = p->m_nQuality;
        if (p->m_nEffectStep < 1)
            p->m_nEffectStep = 1;
        if (p->m_nEffectStep > 3)
            p->m_nEffectStep = 3;
        FUN_14125eb00(p, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    }
    else
    {
        ReadGameOptionBool(pDoc, "graphic", "displayHdr", &p->m_bHdr);
        ReadGameOptionBool(pDoc, "graphic", "displayShimmer", &p->m_bShimmer);
        ReadGameOptionInt(pDoc, "graphic", "multisamplingIdx", &p->m_nMultisampling);
        ReadGameOptionInt(pDoc, "graphic", "resolutionWidth", &p->m_nWidth);
        ReadGameOptionInt(pDoc, "graphic", "resolutionHeight", &p->m_nHeight);
        ReadGameOptionInt(pDoc, "graphic", "resolution", &p->m_nResIdx);
        ReadGameOptionInt(pDoc, "graphic", "quality", &p->m_nQuality);
        ReadGameOptionInt(pDoc, "graphic", "effectStep", &p->m_nEffectStep);
        ReadGameOptionInt(pDoc, "graphic", "shadowLevel", &p->m_nShadow);
        if (p->m_nQuality < 0)
            p->m_nQuality = 0;
        if (p->m_nQuality > 3)
            p->m_nQuality = 3;
        if (p->m_nEffectStep < 1)
            p->m_nEffectStep = 1;
        if (p->m_nEffectStep > 3)
            p->m_nEffectStep = 3;
        if (p->m_nShadow < 0)
            p->m_nShadow = 0;
        if (p->m_nShadow > 4)
            p->m_nShadow = 4;
        if (p->m_nMultisampling < 0)
            p->m_nMultisampling = 0;
        if (p->m_nMultisampling > 2)
            p->m_nMultisampling = 2;
    }
    ReadGameOptionInt(pDoc, "graphic", "fullScreen", &p->m_nScreenMode);
    ReadGameOptionInt(pDoc, "graphic", "brightness", &p->m_n0c);
    ReadGameOptionBool(pDoc, "graphic", "showFramerate", &p->m_bShowFrameRate);
    ReadGameOptionBool(pDoc, "graphic", "advancedEffect", &p->m_b15);
    ReadGameOptionBool(pDoc, "graphic", "vsync", &p->m_bVsync);
    ReadGameOptionBool(pDoc, "graphic", "showEnchantEffect", &p->m_bEnchantEffect);
    p->m_b1a = p->m_b15;
    p->m_b1b = p->m_b15;
    p->m_b1f = FUN_140ae1c00()->FUN_141376580(p->m_nQuality) ? true : false;
    return 1;
}
MS2_REPLACE(0x14125D9B0, FUN_14125d9b0, 1092, 0xF1FFDCB9);

// @0x14125de00
void SaveGameOptionGraphic(Unk_GraphicState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionInt(pDoc, "graphic", "quality", p->m_nQuality);
    WriteGameOptionInt(pDoc, "graphic", "resolution", p->m_nResIdx);
    WriteGameOptionInt(pDoc, "graphic", "fullScreen", p->m_nScreenMode);
    WriteGameOptionInt(pDoc, "graphic", "brightness", p->m_n0c);
    WriteGameOptionBool(pDoc, "graphic", "showFramerate", p->m_bShowFrameRate);
    WriteGameOptionInt(pDoc, "graphic", "effectStep", p->m_nEffectStep);
    WriteGameOptionInt(pDoc, "graphic", "resolutionWidth", p->m_nWidth);
    WriteGameOptionInt(pDoc, "graphic", "resolutionHeight", p->m_nHeight);
    WriteGameOptionBool(pDoc, "graphic", "displayHdr", p->m_bHdr);
    WriteGameOptionBool(pDoc, "graphic", "displayShimmer", p->m_bShimmer);
    WriteGameOptionInt(pDoc, "graphic", "multisamplingIdx", p->m_nMultisampling);
    WriteGameOptionInt(pDoc, "graphic", "shadowLevel", p->m_nShadow);
    WriteGameOptionBool(pDoc, "graphic", "vsync", p->m_bVsync);
    WriteGameOptionBool(pDoc, "graphic", "showEnchantEffect", p->m_bEnchantEffect);
}
MS2_REPLACE(0x14125DE00, SaveGameOptionGraphic, 485, 0xF73079B7);

// @0x14125dff0
void FUN_14125dff0(Unk_GraphicState* pDst, const Unk_GraphicState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125DFF0, FUN_14125dff0, 32, 0x03873F7C);

// The current field can switch the effects off (field data flags).
// @0x14125e020
bool FUN_14125e020(const Unk_GraphicState* p)
{
    MS2Ptr<Unk_WsPtred298> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (static_cast<Unk_WsPtred298*>(spField) != 0 && ((Unk_GsFieldFlags*)spField.operator->())->m_b1fd == false)
        return false;
    return p->m_b18;
}
MS2_REPLACE(0x14125E020, FUN_14125e020, 128, 0x83CC57EA);

// @0x14125e0b0
bool FUN_14125e0b0(const Unk_GraphicState* p)
{
    MS2Ptr<Unk_WsPtred298> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (static_cast<Unk_WsPtred298*>(spField) != 0 && ((Unk_GsFieldFlags*)spField.operator->())->m_b220 == false)
        return false;
    return p->m_bHdr;
}
MS2_REPLACE(0x14125E0B0, FUN_14125e0b0, 128, 0xE039F315);

// @0x14125e140
bool FUN_14125e140(const Unk_GraphicState* p)
{
    return p->m_b1d;
}
MS2_REPLACE(0x14125E140, FUN_14125e140, 15, 0x1AEA23D8);

// @0x14125e160
bool FUN_14125e160(const Unk_GraphicState* p)
{
    MS2Ptr<Unk_WsPtred298> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (static_cast<Unk_WsPtred298*>(spField) != 0 && ((Unk_GsFieldFlags*)spField.operator->())->m_b1fc == false)
        return false;
    return p->m_b1e;
}
MS2_REPLACE(0x14125E160, FUN_14125e160, 128, 0x9EA98AE1);

// Set the quality; bFollow also moves the shadow / effect steps and the hdr switch with it.
// @0x14125e1f0
void FUN_14125e1f0(Unk_GraphicState* p, int nQuality, int bFollow)
{
    Unk_GsQuality* pTable = FUN_140ae1c00();
    p->m_nQuality = nQuality;
    p->m_b1f = pTable->FUN_141376580(p->m_nQuality) ? true : false;
    if (bFollow != 0)
    {
        p->m_nShadow = p->m_nQuality;
        p->m_nEffectStep = p->m_nQuality;
        if (p->m_nEffectStep < 1)
            p->m_nEffectStep = 1;
        if (p->m_nEffectStep > 3)
            p->m_nEffectStep = 3;
        if (p->m_bHdr != (pTable->FUN_141376510(nQuality) != 0))
            FUN_14125e300(p, pTable->FUN_141376510(nQuality));
    }
}
MS2_REPLACE(0x14125E1F0, FUN_14125e1f0, 254, 0xE1E58952);

// The hdr switch: the renderer's hdr and the scene brightness follow it.
// @0x14125e300
void FUN_14125e300(Unk_GraphicState* p, int b)
{
    p->m_bHdr = b != 0;
    bool bOk = FUN_1409a8b00()->FUN_1409a4c60(p->m_bHdr, 0);
    ecr::LightService* pService = GetService<ecr::LightService>();
    float fScale = 1.1f;
    if (p->m_bHdr && bOk)
        fScale = 1.0f;
    FUN_1414c0820(pService, fScale);
}
MS2_REPLACE(0x14125E300, FUN_14125e300, 161, 0xABBDCCC4);

// The shimmer switch (post-process click 6); switching it off also drops step 12.
// @0x14125e3b0
void FUN_14125e3b0(Unk_GraphicState* p, int b)
{
    p->m_bShimmer = b != 0;
    if (FUN_1409a8b20()->FUN_1416aa850(6) != p->m_bShimmer)
        FUN_1409a8b20()->FUN_1416aa450(6, p->m_bShimmer ? true : false);
    if (!p->m_bShimmer)
    {
        PostProcessEffect* pStep = FUN_1409a8b20()->FUN_1416a3a90(0xc);
        if (pStep != 0 && pStep->GetActive())
            FUN_1409a8b20()->FUN_1416a37a0(0xc, true);
        char cOff = 0;
        FUN_1409a5850(&DAT_143ae53c0, &cOff, 1);
    }
}
MS2_REPLACE(0x14125E3B0, FUN_14125e3b0, 249, 0x8F21A58B);

// @0x14125e4b0
void FUN_14125e4b0(Unk_GraphicState* p, int n)
{
}
MS2_REPLACE(0x14125E4B0, FUN_14125e4b0, 10, 0x96F6F902);

// The advanced effect switch: dof and the second effect follow it.
// @0x14125e4c0
void FUN_14125e4c0(Unk_GraphicState* p, int b)
{
    p->m_b15 = b != 0;
    if (p->m_b1b != (b != 0))
    {
        p->m_b1b = p->m_b15;
        FUN_1409a8b00()->FUN_1409a5190(p->m_b1b);
    }
    if (p->m_b1a != (b != 0))
    {
        p->m_b1a = p->m_b15;
        FUN_1409a8b20()->GetDoF()->FUN_141178020(p->m_b1a);
    }
}
MS2_REPLACE(0x14125E4C0, FUN_14125e4c0, 222, 0x0F1B671C);

// @0x14125e5b0
void FUN_14125e5b0(Unk_GraphicState* p, int b)
{
}
MS2_REPLACE(0x14125E5B0, FUN_14125e5b0, 10, 0x96F6F902);

// The brightness: a gamma ramp shifted by n.
// @0x14125e5c0
void FUN_14125e5c0(Unk_GraphicState* p, int n)
{
    D3DGAMMARAMP ramp;
    for (int i = 0; i < 0x100; i++)
    {
        if (i + n < 0)
        {
            ramp.red[i] = 0;
            ramp.green[i] = 0;
            ramp.blue[i] = 0;
        }
        else if (i + n > 0xff)
        {
            ramp.red[i] = 0xff;
            ramp.green[i] = 0xff;
            ramp.blue[i] = 0xff;
        }
        else
        {
            ramp.red[i] = i + n;
            ramp.green[i] = i + n;
            ramp.blue[i] = i + n;
        }
        ramp.red[i] += ramp.red[i] << 8;
        ramp.green[i] += ramp.green[i] << 8;
        ramp.blue[i] += ramp.blue[i] << 8;
    }
    NiObject* pRenderer = FUN_14098d8d0(&DAT_143d6eb58, (NiObject*)FUN_140994450());
    if (pRenderer != 0 && FUN_140d89690(pRenderer) != 0)
    {
        IDirect3DDevice9* pDevice = FUN_140d89690(pRenderer);
        pDevice->SetGammaRamp(0, D3DSGR_CALIBRATE, &ramp);
    }
}
MS2_REPLACE(0x14125E5C0, FUN_14125e5c0, 537, 0xAD5DAB0C);

// A display mode the client can use: 32 bit, at least 1024x720.
// @0x14125e7e0
bool FUN_14125e7e0(Unk_GraphicState* p, int nFormat, unsigned nWidth, unsigned nHeight)
{
    if (!(nFormat == 0x20 && nWidth >= 0x400 && nHeight >= 0x2d0))
        return false;
    return true;
}
MS2_REPLACE(0x14125E7E0, FUN_14125e7e0, 53, 0xCA567DD9);

// The adapter has the mode.
// @0x14125e820
bool FUN_14125e820(Unk_GraphicState* p, int nWidth, int nHeight)
{
    Unk_GsRenderer* pRenderer = FUN_140994450();
    if (pRenderer != 0)
    {
        Unk_GsModeSource* pModes = pRenderer->FUN_14124fea0();
        if (pModes != 0)
        {
            for (unsigned i = 0; i < pModes->FUN_14124ff10(); i++)
            {
                Unk_GsRawMode* pMode = pModes->FUN_14124fee0(i);
                if (pMode != 0)
                {
                    int nModeWidth = pMode->m_nWidth;
                    int nModeHeight = pMode->m_nHeight;
                    if (!FUN_14125e7e0(p, pMode->m_nFormat, nModeWidth, nModeHeight))
                        continue;
                    if (nModeWidth != nWidth)
                        continue;
                    if (nModeHeight != nHeight)
                        continue;
                    return true;
                }
            }
        }
    }
    return false;
}
MS2_REPLACE(0x14125E820, FUN_14125e820, 233, 0xEA3354E9);

// Switch the screen mode / resolution row (falls back to 1024x768).
// @0x14125e910
void FUN_14125e910(Unk_GraphicState* p, int nScreenMode, int nResIdx)
{
    bool bWindowed = nScreenMode == 0;
    bool bFullWindow = nScreenMode == 2;
    Unk_GsRenderer* pRenderer = FUN_140994450();
    if (pRenderer != 0)
    {
        Unk_GsModeSource* pModes = pRenderer->FUN_14124fea0();
        if (pModes != 0)
        {
            bool bApplied = nResIdx >= 0 && nResIdx < (int)pModes->FUN_14124ff10();
            if (bApplied)
            {
                Unk_GsRawMode* pMode = pModes->FUN_14124fee0(nResIdx);
                if (pMode != 0)
                {
                    int nWidth = pMode->m_nWidth;
                    int nHeight = pMode->m_nHeight;
                    bApplied = FUN_14125e7e0(p, pMode->m_nFormat, nWidth, nHeight);
                    if (bApplied)
                    {
                        FUN_140aadf80()->FUN_1412642e0(bFullWindow);
                        FUN_140aadf80()->FUN_141b91010(bWindowed, nWidth, nHeight);
                        p->m_nWidth = nWidth;
                        p->m_nHeight = nHeight;
                        TSingleton<CGameOption>::GetInstance()->FUN_1412432d0();
                    }
                }
            }
            if (!bApplied && FUN_14125e820(p, 0x400, 0x300))
            {
                FUN_140aadf80()->FUN_1412642e0(bFullWindow);
                FUN_140aadf80()->FUN_141b91010(bWindowed, 0x400, 0x300);
            }
            static_cast<MS2SceneGraphService*>(FUN_1413f98b0())->ClearAllCachedShaders();
        }
    }
}
MS2_REPLACE(0x14125E910, FUN_14125e910, 479, 0x48A44F42);

// Pick the resolution row of a size.
// @0x14125eb00
void FUN_14125eb00(Unk_GraphicState* p, int nWidth, int nHeight)
{
    Unk_GsRenderer* pRenderer = FUN_140994450();
    if (pRenderer != 0)
    {
        Unk_GsModeSource* pModes = pRenderer->FUN_14124fea0();
        if (pModes != 0)
        {
            unsigned nFound = 0xffffffff;
            for (unsigned i = 0; i < pModes->FUN_14124ff10(); i++)
            {
                Unk_GsRawMode* pMode = pModes->FUN_14124fee0(i);
                if (pMode != 0)
                {
                    int nModeWidth = pMode->m_nWidth;
                    int nModeHeight = pMode->m_nHeight;
                    if (nWidth == nModeWidth && nHeight == nModeHeight && FUN_14125e7e0(p, pMode->m_nFormat, nWidth, nHeight))
                        nFound = i;
                }
            }
            if (nFound != 0xffffffff)
            {
                p->m_nResIdx = nFound;
                p->m_nWidth = nWidth;
                p->m_nHeight = nHeight;
            }
        }
    }
}
MS2_REPLACE(0x14125EB00, FUN_14125eb00, 277, 0x0A010D0E);

// @0x14125ec20
Unk_GraphicState2* FUN_14125ec20(Unk_GraphicState2* p)
{
    FUN_14125ec50(p);
    return p;
}
MS2_REPLACE(0x14125EC20, FUN_14125ec20, 29, 0xFD4A1B24);

// @0x14125ec50
void FUN_14125ec50(Unk_GraphicState2* p)
{
    p->m_nOptimalHide = 0;
    p->m_bHideAlways = true;
    p->m_bHideBossBattle = false;
    p->m_bShowGuild = false;
    p->m_bShowParty = false;
    p->m_bShowCustom = false;
    p->m_nCustomInput = 0;
    p->m_b10 = true;
    p->m_bShowPhysx = false;
}
MS2_REPLACE(0x14125EC50, FUN_14125ec50, 92, 0x97A4BCCF);

// @0x14125ecc0
int LoadGameOptionOptimizer(Unk_GraphicState2* p, TiXmlDocument* pDoc)
{
    ReadGameOptionInt(pDoc, "optimizer", "optimalHide", &p->m_nOptimalHide);
    ReadGameOptionBool(pDoc, "optimizer", "hideAlways", &p->m_bHideAlways);
    ReadGameOptionBool(pDoc, "optimizer", "hideBossBattle", &p->m_bHideBossBattle);
    ReadGameOptionBool(pDoc, "optimizer", "showGuild", &p->m_bShowGuild);
    ReadGameOptionBool(pDoc, "optimizer", "showParty", &p->m_bShowParty);
    ReadGameOptionBool(pDoc, "optimizer", "showCustom", &p->m_bShowCustom);
    ReadGameOptionInt(pDoc, "optimizer", "customCount", &p->m_nCustomInput);
    ReadGameOptionBool(pDoc, "optimizer", "showphysx", &p->m_bShowPhysx);
    if (p->m_nOptimalHide < 0)
        p->m_nOptimalHide = 0;
    if (p->m_nOptimalHide > 2)
        p->m_nOptimalHide = 2;
    return 1;
}
MS2_REPLACE(0x14125ECC0, LoadGameOptionOptimizer, 350, 0x5E0C9BE5);

// @0x14125ee30
void SaveGameOptionOptimizer(Unk_GraphicState2* p, TiXmlDocument* pDoc)
{
    WriteGameOptionInt(pDoc, "optimizer", "optimalHide", p->m_nOptimalHide);
    WriteGameOptionBool(pDoc, "optimizer", "hideAlways", p->m_bHideAlways);
    WriteGameOptionBool(pDoc, "optimizer", "hideBossBattle", p->m_bHideBossBattle);
    WriteGameOptionBool(pDoc, "optimizer", "showGuild", p->m_bShowGuild);
    WriteGameOptionBool(pDoc, "optimizer", "showParty", p->m_bShowParty);
    WriteGameOptionBool(pDoc, "optimizer", "showCustom", p->m_bShowCustom);
    WriteGameOptionInt(pDoc, "optimizer", "customCount", p->m_nCustomInput);
    WriteGameOptionBool(pDoc, "optimizer", "showphysx", p->m_bShowPhysx);
}
MS2_REPLACE(0x14125EE30, SaveGameOptionOptimizer, 288, 0x73ED29C2);

// @0x14125ef60
void FUN_14125ef60(Unk_GraphicState2* pDst, const Unk_GraphicState2* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125EF60, FUN_14125ef60, 32, 0xF011C8B0);

// Apply the hide-others setting to the optimizer and the network service.
// MS2-FUNCTIONAL: the exe copies the hide-level compare into a second temp before the call; same arguments
// @0x14125ef90
void FUN_14125ef90(Unk_GraphicState2* p)
{
    int nFlags = 0;
    if (p->m_nOptimalHide != 0)
    {
        nFlags = 1;
        if (p->m_bShowParty)
            nFlags |= 2;
        if (p->m_bShowGuild)
            nFlags |= 4;
        if (p->m_bShowCustom)
            nFlags |= 8;
    }
    else
    {
        nFlags = 0;
    }
    FUN_1409f7c90()->FUN_14161cc80(nFlags, p->m_nCustomInput, p->m_bHideBossBattle, p->m_nOptimalHide == 1 ? 1 : 0);
    FUN_140d86260()->vfunc_65(p->m_nOptimalHide);
}
MS2_REPLACE(0x14125EF90, FUN_14125ef90, 248, 0xD4DDBD27);

// ---- language / gamepad / sound / connect / auto looting / chroma / etc blocks -------------------------------------
// The gamepad input switch (MS2InputService).
class Unk_GsGamepadInput
{
public:
    void FUN_140d8b900(bool bEnable, bool bNotify);             // enable / disable gamepad input
};
Unk_GsGamepadInput* FUN_140a58540();
UIMainPlayerInfo* FUN_140931900(int nUiId);
extern int DAT_143af7d40;                                       // input enabled
extern int DAT_143ab0248;                                       // the service region (0 Korea, 1 Japan, 2 global, 3 China)
class Unk_ItemEquipData : public CItemData {};                  // CItem::FUN_140527840's record
CSoundService* FUN_140c9cb10();
// The connect block's character id list (a CAtlArray<unsigned __int64>).
class Unk_GsIdArray
{
public:
    void FUN_1403f19e0();                                       // RemoveAll
    void FUN_140212bf0(unsigned __int64 nId);                   // Add
    unsigned __int64 FUN_1403ed0f0();                           // GetCount
    unsigned __int64* FUN_1403ed000(unsigned __int64 nIndex);   // the nIndex-th id
    void FUN_140acde40(const Unk_GsIdArray& src);               // Copy
};
// The connect block (Unk_GoConnect) with its fields named.
struct Unk_GsConnect
{
    CStringW m_strRegion;                                       // +0x00
    CStringW m_strWorldName;                                    // +0x08
    CString m_strChannel;                                       // +0x10
    CString m_strUserName;                                      // +0x18
    CStringW m_strCharName;                                     // +0x20
    unsigned __int64 m_nCharSN;                                 // +0x28
    bool m_bSaveUserName;                                       // +0x30
    bool m_bLoginByLocaleName;                                  // +0x31
    char m_pad32[6];
    Unk_GsIdArray m_charList;                                   // +0x38 (CAtlArray, 0x20 bytes)
};
CStringA FUN_140719530(unsigned __int64 nId);
unsigned __int64 FUN_1404082e0(const CString& str);
CString FUN_1402bad60(const char* szFormat, const int* pn);    // format one int
// The auto looting block (Unk_GoAutoLoot).
struct Unk_GsAutoLoot
{
    bool m_bEquip;                                              // +0x00
    bool m_bConsume;                                            // +0x01
    bool m_bEtc;                                                // +0x02
    bool m_bMeso;                                               // +0x03
    bool m_bMerat;                                              // +0x04
    bool m_bToken;                                              // +0x05
    bool m_bOther;                                              // +0x06
    bool m_bGemStone;                                           // +0x07
    bool m_bPet;                                                // +0x08
    int m_nEquipGrade;                                          // +0x0c
};
bool FUN_14053f900(unsigned nItemId);
// The etc block (Unk_GoEtc).
struct Unk_GsEtc
{
    bool m_bInformGuildArenaMatching;                           // +0x00
    bool m_bInformRankDuelMatchingObserve;                      // +0x01
    __int64 m_nLastCheckDontAskCubeBuy;                         // +0x08
    __int64 m_nLastCheckDontAskOpenBoxMessage;                  // +0x10
    __int64 m_nLastCheckDontAskCurrencyOverflow;                // +0x18
    bool m_bDisplayEpicQuest;                                   // +0x20
    bool m_bDisplayWorldQuestV2;                                // +0x21
    bool m_bDisplayRepeatQuest;                                 // +0x22
    int m_nAutoFishingLastPackageIndex;                         // +0x24
    int m_nAutoPlayInstrumentLastPackageIndex;                  // +0x28
    int m_nAutoFishingLastExtendMoneyType;                      // +0x2c
    unsigned m_nTracingQuestID;                                 // +0x30
};
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);                 // the quest table row (NULL when unknown)
bool FUN_140764040(CQuestData* pQuest);                         // epic
bool FUN_140764080(CQuestData* pQuest);
bool FUN_1407640c0(CQuestData* pQuest);                         // repeat
int FUN_14074b050(CQuestData* pQuest);                          // the quest type
void FUN_141263f00(CString& str, Unk_GsIdArray* pArr, const char* pszTokens);
void FUN_141260ce0(Unk_GsConnect* p);
void FUN_141260550(Unk_GsConnect* p);

// @0x14125f090
Unk_LgState* FUN_14125f090(Unk_LgState* p)
{
    FUN_14125f0c0(p);
    return p;
}
MS2_REPLACE(0x14125F090, FUN_14125f090, 29, 0xFD4A1B24);

// The language / voice of the service region.
// @0x14125f0c0
void FUN_14125f0c0(Unk_LgState* p)
{
    switch (DAT_143ab0248)
    {
    case 0:
        p->m_nLanguage = 0;
        p->m_nVoice = 0;
        break;
    case 1:
        p->m_nLanguage = 1;
        p->m_nVoice = 1;
        break;
    case 2:
        p->m_nLanguage = 2;
        p->m_nVoice = 2;
        break;
    case 3:
        p->m_nLanguage = 3;
        p->m_nVoice = 3;
        break;
    default:
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionstruct.cpp", 0x5a6), 0));
        break;
    }
}
MS2_REPLACE(0x14125F0C0, FUN_14125f0c0, 188, 0xAC912855);

// @0x14125f190
int LoadGameOptionLanguage(Unk_LgState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionInt(pDoc, "language", "languageIndex", &p->m_nLanguage);
    ReadGameOptionInt(pDoc, "language", "voiceIndex", &p->m_nVoice);
    return 1;
}
MS2_REPLACE(0x14125F190, LoadGameOptionLanguage, 92, 0x8E30F7A4);

// @0x14125f200
void SaveGameOptionLanguage(Unk_LgState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionInt(pDoc, "language", "languageIndex", p->m_nLanguage);
    WriteGameOptionInt(pDoc, "language", "voiceIndex", p->m_nVoice);
}
MS2_REPLACE(0x14125F200, SaveGameOptionLanguage, 84, 0x0ABF8DE1);

// @0x14125f260
void FUN_14125f260(Unk_LgState* pDst, const Unk_LgState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125F260, FUN_14125f260, 27, 0x7FDED043);

// @0x14125f290
Unk_GpState* FUN_14125f290(Unk_GpState* p)
{
    FUN_14125f2c0(p);
    return p;
}
MS2_REPLACE(0x14125F290, FUN_14125f290, 29, 0xFD4A1B24);

// @0x14125f2c0
void FUN_14125f2c0(Unk_GpState* p)
{
    p->m_bUse = false;
    p->m_bShowSkillName = true;
    p->m_bVibration = false;
    p->m_fSensitivityH = 0.25f;
    p->m_fSensitivityV = 0.25f;
    p->m_nLStickSensitivity = *FUN_1402056b0(FUN_1401d3200() + 0xe5b0);
}
MS2_REPLACE(0x14125F2C0, FUN_14125f2c0, 105, 0x15717390);

// @0x14125f330
int LoadGameOptionGamepad(Unk_GpState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "gamepad", "bGamePadUse", &p->m_bUse);
    ReadGameOptionBool(pDoc, "gamepad", "bShowSkillName", &p->m_bShowSkillName);
    ReadGameOptionFloat(pDoc, "gamepad", "sensitivityH", &p->m_fSensitivityH);
    ReadGameOptionFloat(pDoc, "gamepad", "sensitivityV", &p->m_fSensitivityV);
    if (p->m_fSensitivityH < 0.01f)
        p->m_fSensitivityH = 0.01f;
    if (p->m_fSensitivityH > 0.5f)
        p->m_fSensitivityH = 0.5f;
    if (p->m_fSensitivityV < 0.01f)
        p->m_fSensitivityV = 0.01f;
    if (p->m_fSensitivityV > 0.5f)
        p->m_fSensitivityV = 0.5f;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xc3))
        ReadGameOptionBool(pDoc, "gamepad", "bVibration", &p->m_bVibration);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xd6))
    {
        ReadGameOptionInt(pDoc, "gamepad", "gamePadLStickMoveSensitivity", &p->m_nLStickSensitivity);
        if (p->m_nLStickSensitivity < 0)
            p->m_nLStickSensitivity = 0;
        if (p->m_nLStickSensitivity > 100)
            p->m_nLStickSensitivity = 100;
    }
    return 1;
}
MS2_REPLACE(0x14125F330, LoadGameOptionGamepad, 479, 0x2289B370);

// @0x14125f520
void SaveGameOptionGamepad(Unk_GpState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "gamepad", "bGamePadUse", p->m_bUse);
    WriteGameOptionBool(pDoc, "gamepad", "bShowSkillName", p->m_bShowSkillName);
    WriteGameOptionFloat(pDoc, "gamepad", "sensitivityH", p->m_fSensitivityH);
    WriteGameOptionFloat(pDoc, "gamepad", "sensitivityV", p->m_fSensitivityV);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xc3))
        WriteGameOptionBool(pDoc, "gamepad", "bVibration", p->m_bVibration);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0xd6))
        WriteGameOptionInt(pDoc, "gamepad", "gamePadLStickMoveSensitivity", p->m_nLStickSensitivity);
}
MS2_REPLACE(0x14125F520, SaveGameOptionGamepad, 271, 0x07E9F562);

// @0x14125f640
void FUN_14125f640(Unk_GpState* pDst, const Unk_GpState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125F640, FUN_14125f640, 32, 0x0136D6DC);

// Switch the gamepad on / off: the input service, the player info and the upper hud follow it.
// @0x14125f670
void FUN_14125f670(Unk_GpState* p, bool bUse, bool bNotify)
{
    p->m_bUse = bUse;
    FUN_140a58540()->FUN_140d8b900(bUse, bNotify);
    UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo != 0)
        pInfo->FUN_1419f1da0(bUse);
    UIUpperHudDialog* pHud = Unk_GsFindUI<UIUpperHudDialog>((eUIClassID)0x4ebe);
    if (pHud != 0)
        pHud->FUN_1413574a0(bUse);
    TSingleton<CGameOption>::GetInstance()->FUN_141243540();
}
MS2_REPLACE(0x14125F670, FUN_14125f670, 152, 0xA1D71C34);

// @0x14125f710
Unk_SoundState* FUN_14125f710(Unk_SoundState* p)
{
    FUN_14125f740(p);
    return p;
}
MS2_REPLACE(0x14125F710, FUN_14125f710, 29, 0xFD4A1B24);

// @0x14125f740
void FUN_14125f740(Unk_SoundState* p)
{
    p->m_b00 = false;
    p->m_b01 = false;
    p->m_nMainSoundStep = 0;
    p->m_nEffectSoundStep = 0;
    p->m_nEnviromentSoundStep = 0;
    p->m_nUiSoundStep = 0;
    p->m_nNpcSoundStep = 0;
    p->m_nBossSoundStep = 0;
    p->m_nBgmSoundStep = 0;
    p->m_nSystemSoundStep = 0;
    p->m_nMovieSoundStep = 0;
    p->m_n28 = 7;
    p->m_n2c = 10;
    p->m_b30 = true;
}
MS2_REPLACE(0x14125F740, FUN_14125f740, 164, 0x9E1D1C29);

// @0x14125f7f0
int LoadGameOptionSound(Unk_SoundState* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "sound", "bMuteAll", &p->m_b00);
    ReadGameOptionBool(pDoc, "sound", "bPlayAll", &p->m_b01);
    ReadGameOptionInt(pDoc, "sound", "mainSoundStep", &p->m_nMainSoundStep);
    ReadGameOptionInt(pDoc, "sound", "effectSoundStep", &p->m_nEffectSoundStep);
    ReadGameOptionInt(pDoc, "sound", "enviromentSound", &p->m_nEnviromentSoundStep);
    ReadGameOptionInt(pDoc, "sound", "uiSoundStep", &p->m_nUiSoundStep);
    ReadGameOptionInt(pDoc, "sound", "npcSoundStep", &p->m_nNpcSoundStep);
    ReadGameOptionInt(pDoc, "sound", "bossSoundStep", &p->m_nBossSoundStep);
    ReadGameOptionInt(pDoc, "sound", "bgmSoundStep", &p->m_nBgmSoundStep);
    ReadGameOptionInt(pDoc, "sound", "systemSoundStep", &p->m_nSystemSoundStep);
    ReadGameOptionInt(pDoc, "sound", "movieSoundStep", &p->m_nMovieSoundStep);
    ReadGameOptionInt(pDoc, "sound", "instrumentSoundStep", &p->m_n2c);
    ReadGameOptionInt(pDoc, "sound", "charSoundStep", &p->m_n28);
    ReadGameOptionBool(pDoc, "sound", "bOffBgmWhilePlayInstrument", &p->m_b30);
    if (p->m_nMainSoundStep < 0)
        p->m_nMainSoundStep = 0;
    if (p->m_nMainSoundStep > 10)
        p->m_nMainSoundStep = 10;
    if (p->m_nBgmSoundStep < 0)
        p->m_nBgmSoundStep = 0;
    if (p->m_nBgmSoundStep > 10)
        p->m_nBgmSoundStep = 10;
    if (p->m_nEffectSoundStep < 0)
        p->m_nEffectSoundStep = 0;
    if (p->m_nEffectSoundStep > 10)
        p->m_nEffectSoundStep = 10;
    if (p->m_nUiSoundStep < 0)
        p->m_nUiSoundStep = 0;
    if (p->m_nUiSoundStep > 10)
        p->m_nUiSoundStep = 10;
    if (p->m_nEnviromentSoundStep < 0)
        p->m_nEnviromentSoundStep = 0;
    if (p->m_nEnviromentSoundStep > 10)
        p->m_nEnviromentSoundStep = 10;
    if (p->m_nMovieSoundStep < 0)
        p->m_nMovieSoundStep = 0;
    if (p->m_nMovieSoundStep > 10)
        p->m_nMovieSoundStep = 10;
    if (p->m_nNpcSoundStep < 0)
        p->m_nNpcSoundStep = 0;
    if (p->m_nNpcSoundStep > 10)
        p->m_nNpcSoundStep = 10;
    if (p->m_nBossSoundStep < 0)
        p->m_nBossSoundStep = 0;
    if (p->m_nBossSoundStep > 10)
        p->m_nBossSoundStep = 10;
    if (p->m_nSystemSoundStep < 0)
        p->m_nSystemSoundStep = 0;
    if (p->m_nSystemSoundStep > 10)
        p->m_nSystemSoundStep = 10;
    if (p->m_n2c < 0)
        p->m_n2c = 0;
    if (p->m_n2c > 10)
        p->m_n2c = 10;
    if (p->m_n28 < 0)
        p->m_n28 = 0;
    if (p->m_n28 > 10)
        p->m_n28 = 10;
    return 1;
}
MS2_REPLACE(0x14125F7F0, LoadGameOptionSound, 1029, 0x16C55A33);

// @0x14125fc00
void SaveGameOptionSound(Unk_SoundState* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "sound", "bMuteAll", p->m_b00);
    WriteGameOptionBool(pDoc, "sound", "bPlayAll", p->m_b01);
    WriteGameOptionInt(pDoc, "sound", "mainSoundStep", p->m_nMainSoundStep);
    WriteGameOptionInt(pDoc, "sound", "effectSoundStep", p->m_nEffectSoundStep);
    WriteGameOptionInt(pDoc, "sound", "enviromentSound", p->m_nEnviromentSoundStep);
    WriteGameOptionInt(pDoc, "sound", "uiSoundStep", p->m_nUiSoundStep);
    WriteGameOptionInt(pDoc, "sound", "npcSoundStep", p->m_nNpcSoundStep);
    WriteGameOptionInt(pDoc, "sound", "bossSoundStep", p->m_nBossSoundStep);
    WriteGameOptionInt(pDoc, "sound", "bgmSoundStep", p->m_nBgmSoundStep);
    WriteGameOptionInt(pDoc, "sound", "systemSoundStep", p->m_nSystemSoundStep);
    WriteGameOptionInt(pDoc, "sound", "movieSoundStep", p->m_nMovieSoundStep);
    WriteGameOptionInt(pDoc, "sound", "instrumentSoundStep", p->m_n2c);
    WriteGameOptionInt(pDoc, "sound", "charSoundStep", p->m_n28);
    WriteGameOptionBool(pDoc, "sound", "bOffBgmWhilePlayInstrument", p->m_b30);
}
MS2_REPLACE(0x14125FC00, SaveGameOptionSound, 483, 0x0F3B23E0);

// @0x14125fdf0
void FUN_14125fdf0(Unk_SoundState* pDst, const Unk_SoundState* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x14125FDF0, FUN_14125fdf0, 32, 0x7262FAD0);

float FUN_141260110(Unk_SoundState* p, int nCategory);

// Hand the category volumes to the sound event manager (the bgm is silent while an instrument plays).
// @0x14125fe20
void FUN_14125fe20(Unk_SoundState* p)
{
    float fBgm = FUN_141260110(p, 2);
    if (p->m_b30 && FUN_140c8dac0() != 0 && FUN_140c8dac0()->FUN_140d07390() > 0)
        fBgm = 0.0f;
    FUN_140d13c40()->FUN_14177da80(0, FUN_141260110(p, 0));
    FUN_140d13c40()->FUN_14177da80(9, FUN_141260110(p, 0));
    FUN_140d13c40()->FUN_14177da80(1, FUN_141260110(p, 1));
    FUN_140d13c40()->FUN_14177da80(2, fBgm);
    FUN_140d13c40()->FUN_14177da80(3, FUN_141260110(p, 3));
    FUN_140d13c40()->FUN_14177da80(4, FUN_141260110(p, 4));
    FUN_140d13c40()->FUN_14177da80(7, FUN_141260110(p, 7));
    FUN_140d13c40()->FUN_14177da80(5, FUN_141260110(p, 5));
    FUN_140d13c40()->FUN_14177da80(8, FUN_141260110(p, 8));
    FUN_140d13c40()->FUN_14177da80(6, FUN_141260110(p, 6));
    FUN_140d13c40()->FUN_14177da80(10, FUN_141260110(p, 10));
    FUN_140d13c40()->FUN_14177dc80(p->m_b00);
    if (DAT_143af7d40 == 0 && !p->m_b01)
    {
        FUN_140d13c40()->FUN_14177dc80(1);
        if (FUN_140c8dac0() != 0)
            FUN_140c8dac0()->FUN_140d0a510();
    }
    if (FUN_140c9cb10() != 0)
        FUN_140c9cb10()->FUN_1417ae760((float)(p->m_nMainSoundStep * 10) / 100.0f);
}
MS2_REPLACE(0x14125FE20, FUN_14125fe20, 732, 0x9FEE8CE2);

// The volume of a sound category: its step times the main step, in percent.
// @0x141260110
float FUN_141260110(Unk_SoundState* p, int nCategory)
{
    if (nCategory == 0)
        return (float)(p->m_nEffectSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 9)
        return (float)(p->m_nEffectSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 1)
        return (float)(p->m_nEnviromentSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 2)
        return (float)(p->m_nBgmSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 3)
        return (float)(p->m_nUiSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 4)
        return (float)(p->m_nNpcSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 7)
        return (float)(p->m_n28 * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 5)
        return (float)(p->m_nSystemSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 8)
        return (float)(p->m_nSystemSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 6)
        return (float)(p->m_nBossSoundStep * p->m_nMainSoundStep) / 100.0f;
    if (nCategory == 10)
        return (float)(p->m_nNpcSoundStep * p->m_nMainSoundStep) / 100.0f;
    return 0.0f;
}
MS2_REPLACE(0x141260110, FUN_141260110, 452, 0x6FF85B39);

// @0x1412602e0
float Unk_SoundState::FUN_1412602e0()
{
    return (float)(m_nMovieSoundStep * m_nMainSoundStep) / 100.0f;
}
MS2_REPLACE_METHOD(0x1412602E0, Unk_SoundState, FUN_1412602e0, 35, 0x9BD8005D);

// The instrument volume as a MIDI velocity (0..127).
// @0x141260310
int FUN_141260310(Unk_SoundState* p)
{
    if (p->m_b00)
        return 0;
    int nVolume = p->m_n2c * p->m_nMainSoundStep;
    if (nVolume < 0)
        nVolume = 0;
    if (nVolume > 100)
        nVolume = 100;
    nVolume = (int)((float)nVolume * 1.27f);
    return nVolume;
}
MS2_REPLACE(0x141260310, FUN_141260310, 99, 0xB89F9496);

// @0x141260380
Unk_SoundFlag* FUN_141260380(Unk_SoundFlag* p)
{
    FUN_1412603b0(p);
    return p;
}
MS2_REPLACE(0x141260380, FUN_141260380, 29, 0xFD4A1B24);

// @0x1412603b0
void FUN_1412603b0(Unk_SoundFlag* p)
{
    p->m_b = false;
}
MS2_REPLACE(0x1412603B0, FUN_1412603b0, 14, 0x322C4B62);

// @0x1412603d0
int FUN_1412603d0(Unk_SoundFlag* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "sound", "disableJobSound", &p->m_b);
    return 1;
}
MS2_REPLACE(0x1412603D0, FUN_1412603d0, 56, 0x701F4CE5);

// @0x141260410
void FUN_141260410(Unk_SoundFlag* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "sound", "disableJobSound", p->m_b);
}
MS2_REPLACE(0x141260410, FUN_141260410, 52, 0x42DE2D8F);

// @0x141260450
void FUN_141260450(Unk_SoundFlag* pDst, const Unk_SoundFlag* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x141260450, FUN_141260450, 26, 0x0A97A110);

// The job sound is off (KR only).
// @0x141260470
int FUN_141260470(Unk_SoundFlag* p)
{
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036e4c0())
        return 0;
    return p->m_b;
}
MS2_REPLACE(0x141260470, FUN_141260470, 46, 0x9678D6EB);

// @0x1412604b0
Unk_GoConnect::Unk_GoConnect()
{
    FUN_141260550((Unk_GsConnect*)this);
}

// @0x141260550
void FUN_141260550(Unk_GsConnect* p)
{
    p->m_strRegion = L"";
    p->m_strWorldName = L"";
    p->m_strChannel = "";
    p->m_strUserName = "";
    p->m_strCharName = L"";
    p->m_nCharSN = 0;
    p->m_bSaveUserName = false;
    p->m_bLoginByLocaleName = false;
}
MS2_REPLACE(0x141260550, FUN_141260550, 166, 0xD45BD42F);

// @0x141260600
int LoadGameOptionConnect(Unk_GsConnect* p, TiXmlDocument* pDoc)
{
    ReadGameOptionStringW(pDoc, "connect", "Region", &p->m_strRegion);
    ReadGameOptionStringW(pDoc, "connect", "WorldName", &p->m_strWorldName);
    ReadGameOptionString(pDoc, "connect", "Channel", &p->m_strChannel);
    ReadGameOptionString(pDoc, "connect", "UserName", &p->m_strUserName);
    ReadGameOptionUInt64(pDoc, "connect", "CharSN", &p->m_nCharSN);
    ReadGameOptionStringW(pDoc, "connect", "CharName", &p->m_strCharName);
    p->m_charList.FUN_1403f19e0();
    CString strList;
    ReadGameOptionString(pDoc, "connect", "CharList", &strList);
    if (!strList.IsEmpty())
        FUN_141263f00(strList, &p->m_charList, ",");
    ReadGameOptionBool(pDoc, "connect", "LoginByLocaleName", &p->m_bLoginByLocaleName);
    return 1;
}
MS2_REPLACE(0x141260600, LoadGameOptionConnect, 404, 0x859D1061);

// @0x1412607a0
void SaveGameOptionConnect(Unk_GsConnect* p, TiXmlDocument* pDoc)
{
    WriteGameOptionStringW(pDoc, "connect", "Region", p->m_strRegion);
    WriteGameOptionStringW(pDoc, "connect", "WorldName", p->m_strWorldName);
    WriteGameOptionString(pDoc, "connect", "Channel", p->m_strChannel);
    WriteGameOptionString(pDoc, "connect", "UserName", p->m_strUserName);
    WriteGameOptionStringW(pDoc, "connect", "CharName", p->m_strCharName);
    WriteGameOptionUInt64(pDoc, "connect", "CharSN", p->m_nCharSN);
    p->m_strCharName = "";
    FUN_141260ce0(p);
    WriteGameOptionBool(pDoc, "connect", "LoginByLocaleName", p->m_bLoginByLocaleName);
}
MS2_REPLACE(0x1412607A0, SaveGameOptionConnect, 297, 0x02C59038);

// @0x1412608d0
void FUN_1412608d0(Unk_GsConnect* pDst, const Unk_GsConnect* pSrc)
{
    pDst->m_strRegion = pSrc->m_strRegion;
    pDst->m_strWorldName = pSrc->m_strWorldName;
    pDst->m_strChannel = pSrc->m_strChannel;
    pDst->m_strUserName = pSrc->m_strUserName;
    pDst->m_nCharSN = pSrc->m_nCharSN;
    pDst->m_strCharName = pSrc->m_strCharName;
    pDst->m_bSaveUserName = pSrc->m_bSaveUserName;
    pDst->m_bLoginByLocaleName = pSrc->m_bLoginByLocaleName;
    pDst->m_charList.FUN_140acde40(pSrc->m_charList);
}
MS2_REPLACE(0x1412608D0, FUN_1412608d0, 224, 0x583AC658);

// @0x1412609c0
void FUN_1412609c0(Unk_GsConnect* p, const CStringW& strRegion)
{
    p->m_strRegion = strRegion;
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionStringW(pDoc, "connect", "Region", p->m_strRegion);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x1412609C0, FUN_1412609c0, 101, 0x0F9E1263);

// @0x141260a30
void FUN_141260a30(Unk_GsConnect* p, const CStringW& strWorldName)
{
    p->m_strWorldName = strWorldName;
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionStringW(pDoc, "connect", "WorldName", p->m_strWorldName);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260A30, FUN_141260a30, 109, 0x5FC78FF4);

// @0x141260ab0
void FUN_141260ab0(Unk_GsConnect* p, int nChannel)
{
    p->m_strChannel = FUN_1402bad60("{0}", &nChannel);
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionString(pDoc, "connect", "Channel", p->m_strChannel);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260AB0, FUN_141260ab0, 166, 0x41FFF08B);

// @0x141260b60
void FUN_141260b60(Unk_GsConnect* p, const CString& strUserName)
{
    if (p->m_bSaveUserName)
        p->m_strUserName = strUserName;
    else
        p->m_strUserName = "";
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionString(pDoc, "connect", "UserName", p->m_strUserName);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260B60, FUN_141260b60, 149, 0xD20113B6);

// @0x141260c00
void FUN_141260c00(Unk_GsConnect* p, const unsigned __int64& nCharSN)
{
    p->m_nCharSN = nCharSN;
    p->m_strCharName = L"";
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionUInt64(pDoc, "connect", "CharSN", p->m_nCharSN);
    WriteGameOptionStringW(pDoc, "connect", "CharName", p->m_strCharName);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260C00, FUN_141260c00, 161, 0x6FB68DB0);

// @0x141260cb0
void FUN_141260cb0(Unk_GsConnect* p)
{
    FUN_141260ce0(p);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260CB0, FUN_141260cb0, 37, 0xE2AC6BFD);

// Write the character list ("id,id,...").
// @0x141260ce0
void FUN_141260ce0(Unk_GsConnect* p)
{
    unsigned __int64 nCount = p->m_charList.FUN_1403ed0f0();
    CString strList;
    for (unsigned __int64 i = 0; i < nCount; i++)
    {
        if (!strList.IsEmpty())
            strList.Append(",");
        strList.Append(FUN_140719530(*p->m_charList.FUN_1403ed000(i)));
    }
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionString(pDoc, "connect", "CharList", strList);
}
MS2_REPLACE(0x141260CE0, FUN_141260ce0, 271, 0xECBFCDCB);

// @0x141260e00
void FUN_141260e00(Unk_GsConnect* p, bool b)
{
    p->m_bLoginByLocaleName = b;
    TiXmlDocument* pDoc = TSingleton<CGameOption>::GetInstance()->FUN_1412442e0();
    WriteGameOptionBool(pDoc, "connect", "LoginByLocaleName", p->m_bLoginByLocaleName);
    TSingleton<CGameOption>::GetInstance()->FUN_141243450();
}
MS2_REPLACE(0x141260E00, FUN_141260e00, 96, 0xDCA96A2F);

// @0x141260e70
void FUN_141260e70(Unk_GsConnect* p)
{
    TSingleton<CGameOption>::GetInstance()->LoadGameOption();
}
MS2_REPLACE(0x141260E70, FUN_141260e70, 27, 0x0AC960EC);

// @0x141260ea0
Unk_GsAutoLoot* FUN_141260ea0(Unk_GsAutoLoot* p)
{
    FUN_141260ed0(p);
    return p;
}
MS2_REPLACE(0x141260EA0, FUN_141260ea0, 29, 0xFD4A1B24);

// @0x141260ed0
void FUN_141260ed0(Unk_GsAutoLoot* p)
{
    p->m_bEquip = false;
    p->m_bConsume = false;
    p->m_bEtc = false;
    p->m_bMeso = false;
    p->m_bMerat = false;
    p->m_bToken = false;
    p->m_bOther = false;
    p->m_bGemStone = false;
    p->m_nEquipGrade = 1;
    p->m_bPet = true;
}
MS2_REPLACE(0x141260ED0, FUN_141260ed0, 98, 0x4B6CFCBE);

// @0x141260f40
int LoadGameOptionAutoLooting(Unk_GsAutoLoot* p, TiXmlDocument* pDoc)
{
    int nGrade = p->m_nEquipGrade;
    ReadGameOptionBool(pDoc, "autoLooting", "isEnableEquip", &p->m_bEquip);
    ReadGameOptionInt(pDoc, "autoLooting", "equipGrade", &nGrade);
    ReadGameOptionBool(pDoc, "autoLooting", "isEnableConsume", &p->m_bConsume);
    ReadGameOptionBool(pDoc, "autoLooting", "isEnableETC", &p->m_bEtc);
    ReadGameOptionBool(pDoc, "autoLooting", "isEnableMeso", &p->m_bMeso);
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036e510())
    {
        if (ReadGameOptionBool(pDoc, "autoLooting", "isEnableMerat", &p->m_bMerat) == 0)
            p->m_bMerat = p->m_bMeso;
    }
    if (ReadGameOptionBool(pDoc, "autoLooting", "isEnableToken", &p->m_bToken) == 0)
        p->m_bToken = p->m_bMeso;
    ReadGameOptionBool(pDoc, "autoLooting", "isEnableOther", &p->m_bOther);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x2e) == true)
        ReadGameOptionBool(pDoc, "autoLooting", "IsEnableGemStone", &p->m_bGemStone);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8c))
        ReadGameOptionBool(pDoc, "autoLooting", "isEnablePet", &p->m_bPet);
    p->m_nEquipGrade = nGrade;
    return 1;
}
MS2_REPLACE(0x141260F40, LoadGameOptionAutoLooting, 509, 0xB969B3F5);

// @0x141261150
void SaveGameOptionAutoLooting(Unk_GsAutoLoot* p, TiXmlDocument* pDoc)
{
    int nGrade = p->m_nEquipGrade;
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableEquip", p->m_bEquip);
    WriteGameOptionInt(pDoc, "autoLooting", "equipGrade", nGrade);
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableConsume", p->m_bConsume);
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableETC", p->m_bEtc);
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableMeso", p->m_bMeso);
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036e510())
        WriteGameOptionBool(pDoc, "autoLooting", "isEnableMerat", p->m_bMerat);
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableToken", p->m_bToken);
    WriteGameOptionBool(pDoc, "autoLooting", "isEnableOther", p->m_bOther);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x2e) == true)
        WriteGameOptionBool(pDoc, "autoLooting", "IsEnableGemStone", p->m_bGemStone);
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x8c))
        WriteGameOptionBool(pDoc, "autoLooting", "isEnablePet", p->m_bPet);
}
MS2_REPLACE(0x141261150, SaveGameOptionAutoLooting, 436, 0x5ADE5DCC);

// @0x141261310
void FUN_141261310(Unk_GsAutoLoot* pDst, const Unk_GsAutoLoot* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE(0x141261310, FUN_141261310, 32, 0x0136D6DC);

// Should the dropped item be picked up (bAuto: by the auto looting, which the "other" switch gates).
// @0x141261340
bool FUN_141261340(Unk_GsAutoLoot* p, CItem* pItem, bool bAuto)
{
    if (bAuto && !p->m_bOther)
        return false;
    if (FUN_14053f900(pItem->FUN_1405276c0()))
        return true;
    PCBase* pPC = (PCBase*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    if ((unsigned short)pPC->vfunc_78() < 1)
        return false;
    if (pItem->FUN_140525640() != 0)
        return p->m_bPet;
    if (pItem->FUN_140527840()->FUN_14053d840() || pItem->FUN_140527840()->FUN_14053c5c0() == 0xe)
        return p->m_bGemStone;
    if (pItem->FUN_1405258f0() != 0)
        return p->m_bMeso;
    if (pItem->FUN_140525920() != 0)
        return p->m_bMerat;
    if (pItem->FUN_140525950() != 0 || pItem->FUN_140527840()->FUN_14053c5c0() == 0x14)
        return p->m_bToken;
    if (pItem->FUN_140527840()->FUN_14053c5c0() == 2)
        return p->m_bConsume;
    if (pItem->FUN_140527840()->FUN_14053cbc0())
    {
        if (p->m_bEquip && pItem->FUN_140526bd0() >= p->m_nEquipGrade)
            return true;
        return false;
    }
    return p->m_bEtc;
}
MS2_REPLACE(0x141261340, FUN_141261340, 453, 0xF0E6FCE8);

// @0x141261510
bool FUN_141261510(Unk_GsAutoLoot* p)
{
    return p->m_bMeso;
}
MS2_REPLACE(0x141261510, FUN_141261510, 15, 0x330CDBE2);

// @0x141261530
void FUN_141261530(Unk_GsAutoLoot* p, bool b)
{
    p->m_bEquip = b;
}
MS2_REPLACE(0x141261530, FUN_141261530, 22, 0xD0B21995);

// @0x141261550
void FUN_141261550(Unk_GsAutoLoot* p, int n)
{
    p->m_nEquipGrade = n;
}
MS2_REPLACE(0x141261550, FUN_141261550, 22, 0x4E9E8817);

// @0x141261570
void FUN_141261570(Unk_GsAutoLoot* p, bool b)
{
    p->m_bConsume = b;
}
MS2_REPLACE(0x141261570, FUN_141261570, 23, 0x49E0BF44);

// @0x141261590
void FUN_141261590(Unk_GsAutoLoot* p, bool b)
{
    p->m_bEtc = b;
}
MS2_REPLACE(0x141261590, FUN_141261590, 23, 0xF1E40653);

// @0x1412615b0
void FUN_1412615b0(Unk_GsAutoLoot* p, bool b)
{
    p->m_bMeso = b;
}
MS2_REPLACE(0x1412615B0, FUN_1412615b0, 23, 0x19E816E2);

// @0x1412615d0
void FUN_1412615d0(Unk_GsAutoLoot* p, bool b)
{
    p->m_bMerat = b;
}
MS2_REPLACE(0x1412615D0, FUN_1412615d0, 23, 0x11D6C129);

// @0x1412615f0
void FUN_1412615f0(Unk_GsAutoLoot* p, bool b)
{
    p->m_bToken = b;
}
MS2_REPLACE(0x1412615F0, FUN_1412615f0, 23, 0x31D79F20);

// @0x141261610
void FUN_141261610(Unk_GsAutoLoot* p, bool b)
{
    p->m_bOther = b;
}
MS2_REPLACE(0x141261610, FUN_141261610, 23, 0x59DBAFAF);

// @0x141261630
void FUN_141261630(Unk_GsAutoLoot* p, bool b)
{
    p->m_bGemStone = b;
}
MS2_REPLACE(0x141261630, FUN_141261630, 23, 0x01DBD0BE);

// @0x141261650
void FUN_141261650(Unk_GsAutoLoot* p, bool b)
{
    p->m_bPet = b;
}
MS2_REPLACE(0x141261650, FUN_141261650, 23, 0x59F22195);

// @0x141261670
Unk_GoChroma* FUN_141261670(Unk_GoChroma* p)
{
    FUN_1412616a0(p);
    return p;
}
MS2_REPLACE(0x141261670, FUN_141261670, 29, 0xFD4A1B24);

// @0x1412616a0
void FUN_1412616a0(Unk_GoChroma* p)
{
    p->m_bDisable = false;
}
MS2_REPLACE(0x1412616A0, FUN_1412616a0, 14, 0x322C4B62);

// @0x1412616c0
int FUN_1412616c0(Unk_GoChroma* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "chroma", "disable", &p->m_bDisable);
    return 1;
}
MS2_REPLACE(0x1412616C0, FUN_1412616c0, 56, 0xD013648D);

// @0x141261700
void FUN_141261700(Unk_GoChroma* p, TiXmlDocument* pDoc)
{
    if (p->m_bDisable)
        WriteGameOptionBool(pDoc, "chroma", "disable", p->m_bDisable);
}
MS2_REPLACE(0x141261700, FUN_141261700, 64, 0x860376F9);

// @0x141261750
Unk_GsEtc* FUN_141261750(Unk_GsEtc* p)
{
    FUN_141261780(p);
    return p;
}
MS2_REPLACE(0x141261750, FUN_141261750, 29, 0xFD4A1B24);

// @0x141261780
void FUN_141261780(Unk_GsEtc* p)
{
    p->m_bInformGuildArenaMatching = true;
    p->m_bInformRankDuelMatchingObserve = false;
    p->m_nLastCheckDontAskCubeBuy = 0;
    p->m_nLastCheckDontAskOpenBoxMessage = 0;
    p->m_nLastCheckDontAskCurrencyOverflow = 0;
    p->m_bDisplayEpicQuest = true;
    p->m_bDisplayWorldQuestV2 = true;
    p->m_bDisplayRepeatQuest = true;
    p->m_nAutoFishingLastPackageIndex = 2;
    p->m_nAutoPlayInstrumentLastPackageIndex = 2;
    p->m_nAutoFishingLastExtendMoneyType = -1;
    p->m_nTracingQuestID = 0;
}
MS2_REPLACE(0x141261780, FUN_141261780, 137, 0xE1CF642C);

// @0x141261810
int LoadGameOptionEtc(Unk_GsEtc* p, TiXmlDocument* pDoc)
{
    ReadGameOptionBool(pDoc, "etc", "informGuildArenaMatching", &p->m_bInformGuildArenaMatching);
    ReadGameOptionBool(pDoc, "etc", "informRankDuelMatchingObserve", &p->m_bInformRankDuelMatchingObserve);
    ReadGameOptionInt64(pDoc, "etc", "lastCheckDontAskCubeBuy", &p->m_nLastCheckDontAskCubeBuy);
    ReadGameOptionInt64(pDoc, "etc", "lastCheckDontAskOpenBoxMessage", &p->m_nLastCheckDontAskOpenBoxMessage);
    ReadGameOptionInt64(pDoc, "etc", "lastCheckDontAskCurrencyOverflow", &p->m_nLastCheckDontAskCurrencyOverflow);
    ReadGameOptionBool(pDoc, "etc", "displayEpicQuest", &p->m_bDisplayEpicQuest);
    ReadGameOptionBool(pDoc, "etc", "displayWorldQuestV2", &p->m_bDisplayWorldQuestV2);
    ReadGameOptionBool(pDoc, "etc", "displayRepeatQuest", &p->m_bDisplayRepeatQuest);
    ReadGameOptionInt(pDoc, "etc", "autoFishingLastPackageIndex", &p->m_nAutoFishingLastPackageIndex);
    ReadGameOptionInt(pDoc, "etc", "autoPlayInstrumentLastPackageIndex", &p->m_nAutoPlayInstrumentLastPackageIndex);
    ReadGameOptionInt(pDoc, "etc", "autoFishingLastExtendMoneyType", &p->m_nAutoFishingLastExtendMoneyType);
    ReadGameOptionUInt(pDoc, "etc", "tracingQuestID", &p->m_nTracingQuestID);
    return 1;
}
MS2_REPLACE(0x141261810, LoadGameOptionEtc, 451, 0xBA04600F);

// @0x1412619e0
void SaveGameOptionEtc(Unk_GsEtc* p, TiXmlDocument* pDoc)
{
    WriteGameOptionBool(pDoc, "etc", "informGuildArenaMatching", p->m_bInformGuildArenaMatching);
    WriteGameOptionBool(pDoc, "etc", "informRankDuelMatchingObserve", p->m_bInformRankDuelMatchingObserve);
    WriteGameOptionInt64(pDoc, "etc", "lastCheckDontAskCubeBuy", p->m_nLastCheckDontAskCubeBuy);
    WriteGameOptionInt64(pDoc, "etc", "lastCheckDontAskOpenBoxMessage", p->m_nLastCheckDontAskOpenBoxMessage);
    WriteGameOptionInt64(pDoc, "etc", "lastCheckDontAskCurrencyOverflow", p->m_nLastCheckDontAskCurrencyOverflow);
    WriteGameOptionBool(pDoc, "etc", "displayEpicQuest", p->m_bDisplayEpicQuest);
    WriteGameOptionBool(pDoc, "etc", "displayWorldQuestV2", p->m_bDisplayWorldQuestV2);
    WriteGameOptionBool(pDoc, "etc", "displayRepeatQuest", p->m_bDisplayRepeatQuest);
    WriteGameOptionInt(pDoc, "etc", "autoFishingLastPackageIndex", p->m_nAutoFishingLastPackageIndex);
    WriteGameOptionInt(pDoc, "etc", "autoPlayInstrumentLastPackageIndex", p->m_nAutoPlayInstrumentLastPackageIndex);
    WriteGameOptionInt(pDoc, "etc", "autoFishingLastExtendMoneyType", p->m_nAutoFishingLastExtendMoneyType);
    WriteGameOptionUInt(pDoc, "etc", "tracingQuestID", p->m_nTracingQuestID);
}
MS2_REPLACE(0x1412619E0, SaveGameOptionEtc, 419, 0x9ACA52B7);

// Show the quest on the quest list (by its kind).
// @0x141261b90
int FUN_141261b90(Unk_GsEtc* p, int nQuestId)
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
    if (!spQuest)
        return 0;
    if (FUN_140764040(spQuest.operator->()))
        return p->m_bDisplayEpicQuest;
    else if (FUN_140764080(spQuest.operator->()))
        return 1;
    else if (FUN_1407640c0(spQuest.operator->()))
        return p->m_bDisplayRepeatQuest;
    else if (FUN_14074b050(spQuest.operator->()) == 1)
        return p->m_bDisplayWorldQuestV2;
    return 1;
}
MS2_REPLACE(0x141261B90, FUN_141261b90, 323, 0x1360F8F3);

class Unk_140acd6e0 : public ASDisplayObject {};                // the button wrapper (uisystemmenudialog.h members)

// ---- CPersonalInfoAgreement: the personal information agreements (house visit) ------------------------------------
// The UIs the agreement updates.
class Unk_GsUiAgreeIcon { public: void FUN_1419394a0(bool b); void FUN_141939320(bool b); };   // 0x4e28
Unk_GsUiAgreeIcon* FUN_140938b90(int nUiId);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);   // a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                     // show it
CStringW GetStringCommonByKey(const CStringW& str);                      // string table text by key
CStringW FUN_140298ea0(CStringW str);                             // string table text by key
class Unk_GsUiHomeNotice { public: void FUN_140c29b70(); };                                     // 0x4f7c
Unk_GsUiHomeNotice* FUN_140ef49b0(int nUiId);
class Unk_GsUiHomeLink { public: void FUN_14135ec00(const CString& strUrl, bool b); };           // 0x4e6a
Unk_GsUiHomeLink* FUN_140c43790(int nUiId);
// The house service (cube map information) behind its smart pointer (see uirealestatesell.cpp).
class Unk_HoService
{
public:
    int FUN_1410d2f10();                                        // in a house
    __int64 FUN_1410c3180();                                    // the account id of the house owner
};
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
class Unk_HoServicePtr
{
public:
    Unk_HoServicePtr(Unk_HoService* p);                             // 0x1401cd0b0
    ~Unk_HoServicePtr();                                            // 0x1401cd150
    bool FUN_140c2b790(int n);                                      // != null
    bool FUN_140ef4cb0(int n);                                      // == null
    Unk_HoService* FUN_1401cd1a0();                                 // operator->
    Unk_HoService* m_p;
};
Unk_HoService* FUN_1401cd040(Unk_EntityAppFramework* framework);
extern __int64 DAT_143ab2820;                                       // my account id
void FUN_140d73bc0(int nStringId, int a2, int a3, CStringW strTag);  // system message box by string id
void FUN_14151f200();

class CPersonalInfoAgreement
{
public:
    CPersonalInfoAgreement();
    void FUN_141261d20();
    int FUN_141261d40();
    void FUN_141261d90();
    void FUN_141261da0(const CPersonalInfoAgreement* pSrc);
    void FUN_141261dd0(int nGroup);
    void FUN_141261e40(int nGroup, unsigned nFlags);
    void FUN_141261e90(unsigned nFlags);
    bool FUN_141261ec0(unsigned nMask);
    bool FUN_141261f00(int nGroup);
    void FUN_141261fd0(int nGroup);
    void FUN_141262060(unsigned nFlags);
    void FUN_141262090();
    void FUN_141262180();
    void FUN_141262650();
    void FUN_1412627c0(CString strUrl);
    bool FUN_141262830(int nResult, const CMsgBoxData& data);
    bool FUN_141262b70(int nResult, const CMsgBoxData& data);
    bool FUN_141262f10(int nResult, const CMsgBoxData& data);

    bool m_bAgreeVisitHome;                                     // +0x00
    unsigned m_nFlags;                                          // +0x04 the agreement bits (2/4: group 0, 8/0x10/0x20: group 1)
    bool m_bAnswered;                                           // +0x08 the house visit question was answered
};
MS2_CHECK_SIZE(CPersonalInfoAgreement, 0xc);

// @0x141261cf0
CPersonalInfoAgreement::CPersonalInfoAgreement()
    : m_bAgreeVisitHome(false), m_nFlags(0), m_bAnswered(false)
{
}

// @0x141261d20
void CPersonalInfoAgreement::FUN_141261d20()
{
    m_bAgreeVisitHome = false;
}
MS2_REPLACE_METHOD(0x141261D20, CPersonalInfoAgreement, FUN_141261d20, 14, 0x322C4B62);

// @0x141261d40
int CPersonalInfoAgreement::FUN_141261d40()
{
    if (FUN_141261ec0(2))
        m_bAgreeVisitHome = true;
    else
        m_bAgreeVisitHome = false;
    return 1;
}
MS2_REPLACE_METHOD(0x141261D40, CPersonalInfoAgreement, FUN_141261d40, 59, 0xA9524250);

// @0x141261d90
void CPersonalInfoAgreement::FUN_141261d90()
{
}
MS2_REPLACE_METHOD(0x141261D90, CPersonalInfoAgreement, FUN_141261d90, 6, 0xA9AF6E37);

// @0x141261da0
void CPersonalInfoAgreement::FUN_141261da0(const CPersonalInfoAgreement* pSrc)
{
    *this = *pSrc;
}
MS2_REPLACE_METHOD(0x141261DA0, CPersonalInfoAgreement, FUN_141261da0, 32, 0x2CDC0648);

// Send the agreement of a group to the server.
// @0x141261dd0
void CPersonalInfoAgreement::FUN_141261dd0(int nGroup)
{
    COutPacket packet(0xc0, 0);
    packet.Encode4(nGroup);
    packet.Encode4(m_nFlags);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141261DD0, CPersonalInfoAgreement, FUN_141261dd0, 99, 0xBEC3F05B);

// @0x141261e40
void CPersonalInfoAgreement::FUN_141261e40(int nGroup, unsigned nFlags)
{
    FUN_141261fd0(nGroup);
    FUN_141262060(nFlags);
    FUN_141261d40();
}
MS2_REPLACE_METHOD(0x141261E40, CPersonalInfoAgreement, FUN_141261e40, 61, 0xFCFDCD1C);

// @0x141261e90
void CPersonalInfoAgreement::FUN_141261e90(unsigned nFlags)
{
    m_nFlags = nFlags;
    FUN_141261d40();
}
MS2_REPLACE_METHOD(0x141261E90, CPersonalInfoAgreement, FUN_141261e90, 40, 0xBBFEF17F);

// @0x141261ec0
bool CPersonalInfoAgreement::FUN_141261ec0(unsigned nMask)
{
    return (m_nFlags & nMask) != 0 ? true : false;
}
MS2_REPLACE_METHOD(0x141261EC0, CPersonalInfoAgreement, FUN_141261ec0, 50, 0xE1FE8F9F);

// Any agreement of the group given.
// @0x141261f00
bool CPersonalInfoAgreement::FUN_141261f00(int nGroup)
{
    if (nGroup == 0)
        return FUN_141261ec0(2) || FUN_141261ec0(4);
    else if (nGroup == 1)
        return FUN_141261ec0(8) || FUN_141261ec0(0x10) || FUN_141261ec0(0x20);
    return false;
}
MS2_REPLACE_METHOD(0x141261F00, CPersonalInfoAgreement, FUN_141261f00, 194, 0x2EA97AFB);

// @0x141261fd0
void CPersonalInfoAgreement::FUN_141261fd0(int nGroup)
{
    switch (nGroup)
    {
    case 0:
        m_nFlags &= ~2;
        m_nFlags &= ~4;
        break;
    case 1:
        m_nFlags &= ~8;
        m_nFlags &= ~0x10;
        m_nFlags &= ~0x20;
        break;
    }
}
MS2_REPLACE_METHOD(0x141261FD0, CPersonalInfoAgreement, FUN_141261fd0, 136, 0x19DA7D8E);

// @0x141262060
void CPersonalInfoAgreement::FUN_141262060(unsigned nFlags)
{
    m_nFlags |= nFlags;
}
MS2_REPLACE_METHOD(0x141262060, CPersonalInfoAgreement, FUN_141262060, 32, 0xA1BFFC18);

// Show the agreement reminders while group 0 is not agreed.
// @0x141262090
void CPersonalInfoAgreement::FUN_141262090()
{
    if (WorldService::GetInstance()->FUN_141bcb0a0())
        return;
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x117))
        return;
    bool bShow = !FUN_141261f00(0);
    Unk_GsUiAgreeIcon* pIcon = FUN_140938b90(0x4e28);
    if (pIcon != 0)
        pIcon->FUN_1419394a0(bShow);
    UISystemMenuDialog* pMenu = Unk_GsFindUI<UISystemMenuDialog>((eUIClassID)0x4e21);
    if (pMenu != 0)
        pMenu->FUN_141b144f0(bShow);
    UIGameOptionDialog* pAgreeMenu = FUN_140a02e60(0x4ef3);
    if (pAgreeMenu != 0)
        pAgreeMenu->FUN_141943900(bShow);
}
MS2_REPLACE_METHOD(0x141262090, CPersonalInfoAgreement, FUN_141262090, 229, 0xC7403854);

// In my own house without a house visit agreement: ask who may visit it.
// MS2-FUNCTIONAL: message box temps / frame slots differ; same calls, texts and callback
// @0x141262180
void CPersonalInfoAgreement::FUN_141262180()
{
    if (WorldService::GetInstance()->FUN_141bcb0a0())
        return;
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x117))
        return;
    Unk_GsMyPC* pPC = (Unk_GsMyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    bool bAgreed = FUN_141261f00(1);
    int nNoHouse = pPC->FUN_141527e00();
    bool bShow = nNoHouse == 0 && !bAgreed;
    Unk_GsUiAgreeIcon* pIcon = FUN_140938b90(0x4e28);
    if (pIcon != 0)
        pIcon->FUN_141939320(bShow);
    if (nNoHouse != 0 || bAgreed)
        return;
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    if (spService.FUN_140c2b790(0))
    {
        bool bMyHouse = spService.FUN_1401cd1a0()->FUN_1410d2f10() != 0 && spService.FUN_1401cd1a0()->FUN_1410c3180() == DAT_143ab2820;
        if (bMyHouse)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(4, FUN_140298ea0(CStringW(L"s_personal_infomaion_agreement_visit_myhome_content")), 0, CStringW(L""));
            if (spBox.get())
            {
                CStringW strPublic = GetStringCommonByKey(CStringW(L"s_personal_infomaion_agreement_visit_myhome_btn_public"));
                CStringW strPassword = GetStringCommonByKey(CStringW(L"s_personal_infomaion_agreement_visit_myhome_btn_password"));
                CStringW strPrivate = GetStringCommonByKey(CStringW(L"s_personal_infomaion_agreement_visit_myhome_btn_private"));
                spBox->SetTitle(GetStringCommonByKey(CStringW(L"s_personal_infomaion_agreement_title")));
                spBox->FUN_141a024a0(0);
                spBox->FUN_141a024c0();
                spBox->SetAlign(0);
                spBox->FUN_141a01690(strPublic, strPassword, strPrivate);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CPersonalInfoAgreement::FUN_141262830));
                FUN_140d73c60(spBox);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141262180, CPersonalInfoAgreement, FUN_141262180, 1224, 0x1F15A354);

// Leaving my house after answering: close the house notice.
// @0x141262650
void CPersonalInfoAgreement::FUN_141262650()
{
    if (WorldService::GetInstance()->FUN_141bcb0a0())
        return;
    if (!TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x117))
        return;
    Unk_GsMyPC* pPC = (Unk_GsMyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (pPC->FUN_141527e00() != 0)
        return;
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    if (spService.FUN_140ef4cb0(0))
        return;
    bool bMyHouse = spService.FUN_1401cd1a0()->FUN_1410d2f10() != 0 && spService.FUN_1401cd1a0()->FUN_1410c3180() == DAT_143ab2820;
    if (!bMyHouse)
        return;
    if (m_bAnswered)
    {
        Unk_GsUiHomeNotice* pNotice = FUN_140ef49b0(0x4f7c);
        if (pNotice != 0)
            pNotice->FUN_140c29b70();
        m_bAnswered = false;
    }
}
MS2_REPLACE_METHOD(0x141262650, CPersonalInfoAgreement, FUN_141262650, 350, 0x37901087);

// Open the home page link UI.
// @0x1412627c0
void CPersonalInfoAgreement::FUN_1412627c0(CString strUrl)
{
    Unk_GsUiHomeLink* pLink = FUN_140c43790(0x4e6a);
    if (pLink == 0)
        return;
    pLink->FUN_14135ec00(strUrl, true);
}
MS2_REPLACE_METHOD(0x1412627C0, CPersonalInfoAgreement, FUN_1412627c0, 94, 0xA1CF5C66);

// The house visit question: 0 public, 1 password (asks for it), 2 private.
// MS2-FUNCTIONAL: message box temps / frame slots differ; same calls, texts and callback
// @0x141262830
bool CPersonalInfoAgreement::FUN_141262830(int nResult, const CMsgBoxData& data)
{
    Unk_GsMyPC* pPC = (Unk_GsMyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    if (nResult == 0)
    {
        m_bAnswered = true;
        pPC->FUN_141530720(0, CStringW(L""), true);
        Unk_GsUiAgreeIcon* pIcon = FUN_140938b90(0x4e28);
        if (pIcon != 0)
            pIcon->FUN_141939320(false);
    }
    else if (nResult == 1)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, GetStringCommonByKey(CStringW(L"s_personal_infomaion_agreement_visit_myhome_input_password")), 0, CStringW(L""));
        if (spBox.get())
        {
            spBox->FUN_141a01d30(2, CStringW(L""), 6, 0, 0);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CPersonalInfoAgreement::FUN_141262b70));
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        m_bAnswered = true;
        pPC->FUN_141530720(2, CStringW(L""), true);
        Unk_GsUiAgreeIcon* pIcon = FUN_140938b90(0x4e28);
        if (pIcon != 0)
            pIcon->FUN_141939320(false);
    }
    return true;
}
MS2_REPLACE_METHOD(0x141262830, CPersonalInfoAgreement, FUN_141262830, 824, 0x6C3EC8FF);

// The house password: six digits.
// MS2-FUNCTIONAL: message box temps / frame slots differ; same checks, calls and callback
// @0x141262b70
bool CPersonalInfoAgreement::FUN_141262b70(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        CStringW strPassword = data.FUN_141a02d50().Trim(L',');
        if (strPassword.GetLength() != 6)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, GetStringCommonByKey(CStringW(L"s_home_password_string_error")), 0, CStringW(L""));
            if (spBox.get())
            {
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CPersonalInfoAgreement::FUN_141262f10));
                FUN_140d73c60(spBox);
            }
            return false;
        }
        for (int i = 0; i < strPassword.GetLength(); i++)
        {
            if (!isdigit((unsigned short)strPassword.GetAt(i)))
            {
                FUN_140d73bc0(0xb0a, 0, 0, CStringW(L""));
                FUN_141262180();
                return false;
            }
        }
        Unk_GsMyPC* pPC = (Unk_GsMyPC*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            m_bAnswered = true;
            pPC->FUN_141530720(1, CStringW(strPassword), false);
        }
        FUN_14151f200();
    }
    else
    {
        FUN_141262180();
    }
    return true;
}
MS2_REPLACE_METHOD(0x141262B70, CPersonalInfoAgreement, FUN_141262b70, 911, 0x6F50D814);

// @0x141262f10
bool CPersonalInfoAgreement::FUN_141262f10(int nResult, const CMsgBoxData& data)
{
    FUN_141262180();
    return true;
}
MS2_REPLACE_METHOD(0x141262F10, CPersonalInfoAgreement, FUN_141262f10, 35, 0x556A5A8F);

// ---- XML helpers: <section key="value"/> under the document root ---------------------------------------------------
class TiXmlElement
{
public:
    TiXmlElement(const char* szName);                           // 0x14086f2f0
private:
    void* m_pad[0x90 / sizeof(void*)];
};
TiXmlElement* FUN_14081b310(TiXmlDocument* pDoc);               // RootElement
TiXmlElement* FUN_140165cf0(TiXmlElement* pElem, const char* pszName);  // FirstChildElement
void FUN_14086e090(TiXmlElement* pParent, TiXmlElement* pChild); // LinkEndChild
const char* FUN_14086f4b0(TiXmlElement* pElem, const char* pszName);    // Attribute
const char* FUN_14086f500(TiXmlElement* pElem, const char* pszName, int* pn);   // Attribute (int)
const char* FUN_14086f580(TiXmlElement* pElem, const char* pszName, double* pf);    // Attribute (double)
void FUN_14086f8d0(TiXmlElement* pElem, const char* pszName, const char* pszValue); // SetAttribute
void FUN_14086f920(TiXmlElement* pElem, const char* pszName, int nValue);           // SetAttribute (int)
void FUN_14086f970(TiXmlElement* pElem, const char* pszName, double fValue);        // SetDoubleAttribute
void FUN_14086fa40(TiXmlElement* pElem, const char* pszName);                       // RemoveAttribute
int FUN_140873220(TiXmlElement* pElem, const char* pszName, unsigned* pn);          // QueryUnsignedAttribute (0 = ok)
int FUN_1408732e0(TiXmlElement* pElem, const char* pszName, __int64* pn);
int FUN_140873320(TiXmlElement* pElem, const char* pszName, unsigned __int64* pn);
void FUN_140873ce0(TiXmlElement* pElem, const char* pszName, unsigned nValue);
void FUN_140873eb0(TiXmlElement* pElem, const char* pszName, const __int64& nValue);
void FUN_140873f20(TiXmlElement* pElem, const char* pszName, const unsigned __int64& nValue);
CStringW FUN_1408767c0(const char* sz);                         // a UTF-8 string as a wide CString
CString FUN_140390ea0(const wchar_t* psz, int nCodePage);       // a wide string as a UTF-8 CString

// @0x141262f40
void WriteGameOptionBool(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, bool bValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_14086f8d0(pSection, pszKey, bValue ? "true" : "false");
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_14086f8d0(pNew, pszKey, bValue ? "true" : "false");
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141262F40, WriteGameOptionBool, 326, 0x3B08BE16);

// @0x141263090
void WriteGameOptionInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, int nValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_14086f920(pSection, pszKey, nValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_14086f920(pNew, pszKey, nValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141263090, WriteGameOptionInt, 244, 0xB61D45E2);

// @0x141263190
void WriteGameOptionFloat(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, float fValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_14086f970(pSection, pszKey, fValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_14086f970(pNew, pszKey, fValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141263190, WriteGameOptionFloat, 253, 0xE0441726);

// @0x1412632a0
void WriteGameOptionString(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, const CString& strValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_14086f8d0(pSection, pszKey, strValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_14086f8d0(pNew, pszKey, strValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x1412632A0, WriteGameOptionString, 265, 0x33BA8204);

// @0x1412633b0
void WriteGameOptionStringW(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, const CStringW& strValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_14086f8d0(pSection, pszKey, FUN_140390ea0(strValue, 0));
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_14086f8d0(pNew, pszKey, FUN_140390ea0(strValue, 0));
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x1412633B0, WriteGameOptionStringW, 391, 0x6A3756CD);

// @0x141263540
void WriteGameOptionInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, __int64 nValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_140873eb0(pSection, pszKey, nValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_140873eb0(pNew, pszKey, nValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141263540, WriteGameOptionInt64, 244, 0x6403AA0D);

// @0x141263640
void WriteGameOptionUInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned __int64 nValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_140873f20(pSection, pszKey, nValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_140873f20(pNew, pszKey, nValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141263640, WriteGameOptionUInt64, 244, 0xDA07D754);

// @0x141263740
void WriteGameOptionUInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned nValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
        {
            FUN_140873ce0(pSection, pszKey, nValue);
        }
        else
        {
            TiXmlElement* pNew = new TiXmlElement(pszSection);
            if (pNew != 0)
            {
                FUN_140873ce0(pNew, pszKey, nValue);
                FUN_14086e090(pRoot, pNew);
            }
        }
    }
}
MS2_REPLACE(0x141263740, WriteGameOptionUInt, 244, 0x4A2D9A5C);

// @0x141263840
int ReadGameOptionBool(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, bool* pbValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pSection;
    if (pRoot != 0 && (pSection = FUN_140165cf0(pRoot, pszSection)) != 0)
    {
        NiString strValue(FUN_14086f4b0(pSection, pszKey));
        if (!strValue.IsEmpty())
        {
            if (strValue.Compare("true") == 0)
                *pbValue = true;
            if (strValue.Compare("false") == 0)
                *pbValue = false;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x141263840, ReadGameOptionBool, 237, 0x3A837688);

// @0x141263940
int ReadGameOptionInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, int* pnValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_14086f500(pElem, pszKey, pnValue) != 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141263940, ReadGameOptionInt, 114, 0xEE6BB2B0);

// @0x1412639c0
int ReadGameOptionUInt(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned* pnValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_140873220(pElem, pszKey, pnValue) == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x1412639C0, ReadGameOptionUInt, 113, 0x607BE37F);

// @0x141263a40
int ReadGameOptionFloat(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, float* pfValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0)
    {
        double fValue = 0.0;
        if (FUN_14086f580(pElem, pszKey, &fValue) != 0)
        {
            *pfValue = (float)fValue;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x141263A40, ReadGameOptionFloat, 138, 0xF8EF9F96);

// @0x141263ad0
int ReadGameOptionString(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, CString* pstrValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_14086f4b0(pElem, pszKey) != 0)
    {
        *pstrValue = FUN_14086f4b0(pElem, pszKey);
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x141263AD0, ReadGameOptionString, 138, 0x5B5595A6);

// @0x141263b60
int ReadGameOptionStringW(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, CStringW* pstrValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_14086f4b0(pElem, pszKey) != 0)
    {
        *pstrValue = FUN_1408767c0(FUN_14086f4b0(pElem, pszKey));
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x141263B60, ReadGameOptionStringW, 189, 0x405B97F8);

// @0x141263c30
int ReadGameOptionInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, __int64* pnValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_1408732e0(pElem, pszKey, pnValue) != 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141263C30, ReadGameOptionInt64, 113, 0xD30995A9);

// @0x141263cb0
int ReadGameOptionUInt64(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey, unsigned __int64* pnValue)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    TiXmlElement* pElem;
    if (pRoot != 0 && (pElem = FUN_140165cf0(pRoot, pszSection)) != 0 && FUN_140873320(pElem, pszKey, pnValue) != 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141263CB0, ReadGameOptionUInt64, 113, 0x8F7453E9);

// @0x141263d30
void FUN_141263d30(TiXmlDocument* pDoc, const char* pszSection, const char* pszKey)
{
    TiXmlElement* pRoot = FUN_14081b310(pDoc);
    if (pRoot != 0)
    {
        TiXmlElement* pSection = FUN_140165cf0(pRoot, pszSection);
        if (pSection != 0)
            FUN_14086fa40(pSection, pszKey);
    }
}
MS2_REPLACE(0x141263D30, FUN_141263d30, 90, 0xE379D4E2);

// Split the "a,b,c" id list into the array.
// @0x141263f00
void FUN_141263f00(CString& str, Unk_GsIdArray* pArr, const char* pszTokens)
{
    int nPos = 0;
    CString strToken = str.Tokenize(pszTokens, nPos);
    while (!strToken.IsEmpty())
    {
        pArr->FUN_140212bf0(FUN_1404082e0(strToken));
        strToken = str.Tokenize(pszTokens, nPos);
    }
}
MS2_REPLACE(0x141263F00, FUN_141263f00, 191, 0xD9D8E263);

// @0x1412642e0
void Unk_GsApp::FUN_1412642e0(bool b)
{
    m_bd0 = b;
}
MS2_REPLACE_METHOD(0x1412642E0, Unk_GsApp, FUN_1412642e0, 26, 0x269BA765);

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
// @0x141264430
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_gs_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnGsMemcpyS)(void*, size_t, const void*, size_t) = &ms2_gs_memcpy_s;

// The UCRT memmove_s copies of this unit.
// @0x14125b2e0
MS2_EMIT_CRT_MEMMOVE_S();
// @0x141264580
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// MS2-PIN: ??__Es_pointer1@@YAXXZ 0x1400ead40
// MS2-RANGE: 0x142cae0f0-0x142cae240 .text$yd
