// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoption.cpp: the CGameOption store of the
// option tabs (XML load/save, benchmark level) and the battle, camera, community and graphic tab pages.
// MS2-UNIT: client\ms2\gameoption.cpp
// MS2-RANGE: 0x1400ea4e0-0x1400ea840 .text$di
// MS2-RANGE: 0x141241810-0x141250a80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoption.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/bgtransparencymgr.h"
#include "ms2/client/ms2/localtargetcameramode.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <map>
#include <utility>
#include <atlcoll.h>

// ---- header statics (dynamic initializers 0x1400ea4e0..0x1400ea810) ----
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";

// ---- unit-local placeholders ----

// A checkbox AS entity of the option dialog (0x88 bytes).
class Unk_GoCheck : public CPtred
{
public:
    void FUN_1422ce090(int bChecked);
    bool FUN_1422ce0e0();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// A radio-button AS entity of the option dialog (0x88 bytes); same setters as the checkbox.
class Unk_GoRadio : public CPtred
{
public:
    void FUN_1422ce090(int bChecked);
    bool FUN_1422ce0e0();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// A slider AS entity of the option dialog (0x88 bytes); the value is a float.
class Unk_GoSlider : public CPtred
{
public:
    void FUN_1422ce5f0(float f);
    float FUN_1422ce630();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// View of UIGameOptionDialog: the child lookups by name (getTabChild).
class Unk_GoDialog
{
public:
    MS2Ptr<Unk_GoCheck> FUN_140a57f50(CString name, int nIndex);
    MS2Ptr<Unk_GoSlider> FUN_140a58110(CString name, int nIndex);
    MS2Ptr<Unk_GoRadio> FUN_140a46480(CString name, int nIndex);
};

// The state blocks' methods (declared here; they live in client\ms2\gameoptionstruct.cpp).
void FUN_14125b400(Unk_CameraState* p);
void FUN_14125b430(Unk_CameraState* p);
int FUN_14125b480(Unk_CameraState* p, TiXmlDocument* pDoc);
void FUN_14125b6b0(Unk_CameraState* pDst, const Unk_CameraState* pSrc);
int FUN_14125b6e0(const Unk_CameraState* p);
void FUN_14125b720(Unk_CameraState* p, int n);
void FUN_14125ca80(Unk_BattleState* p);
void FUN_14125cab0(Unk_BattleState* p);
int FUN_14125cb20(Unk_BattleState* p, TiXmlDocument* pDoc);
void FUN_14125d100(Unk_BattleState* pDst, const Unk_BattleState* pSrc);

void FUN_14125d130(Unk_CommunityStateA* p);
void FUN_14125d160(Unk_CommunityStateA* p);
int FUN_14125d190(Unk_CommunityStateA* p, TiXmlDocument* pDoc);
void FUN_14125d2a0(Unk_CommunityStateA* pDst, const Unk_CommunityStateA* pSrc);
int FUN_14125d2d0(const Unk_CommunityStateA* p, const Unk_CommunityStateA* q);
void FUN_14125d330(Unk_CommunityStateB* p);
void FUN_14125d360(Unk_CommunityStateB* p);
int FUN_14125d3d0(Unk_CommunityStateB* p, TiXmlDocument* pDoc);
void FUN_14125d710(Unk_CommunityStateB* pDst, const Unk_CommunityStateB* pSrc);
int FUN_14125d740(const Unk_CommunityStateB* p, const Unk_CommunityStateB* q);

// ---- CGameOptionBattle ----
// @0x141246d40
CGameOptionBattle::CGameOptionBattle(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125ca80(&m_state);
}

// @0x141246da0
CGameOptionBattle::~CGameOptionBattle()
{
}

// @0x141246dd0
void CGameOptionBattle::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125d100(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_141248630());
    CBaseOption::vfunc_3(n);
}

// @0x141246e20
void CGameOptionBattle::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141246e50
int CGameOptionBattle::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141246e70
void CGameOptionBattle::vfunc_6()
{
    Unk_GoDialog* pDlg = (Unk_GoDialog*)GetOptionDialog();
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayMyGiveRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[0]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayMyTakeRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[1]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayPartyRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[2]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayGetMeso"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[3]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayGetExp"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[4]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayEpGauge"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b[5]);
    }
    MS2Ptr<Unk_GoRadio> spRadio(0);
    if (m_state.m_n08 == 1)
        spRadio = pDlg->FUN_140a46480(CString("m_giveDamageMine"), -1);
    else if (m_state.m_n08 == 3)
        spRadio = pDlg->FUN_140a46480(CString("m_giveDamageParty"), -1);
    else if (m_state.m_n08 == 7)
        spRadio = pDlg->FUN_140a46480(CString("m_giveDamageAll"), -1);
    if (static_cast<Unk_GoRadio*>(spRadio) != 0)
        spRadio->FUN_1422ce090(1);
    spRadio = 0;
    if (m_state.m_n0c == 1)
        spRadio = pDlg->FUN_140a46480(CString("m_takeDamageMine"), -1);
    else if (m_state.m_n0c == 3)
        spRadio = pDlg->FUN_140a46480(CString("m_takeDamageParty"), -1);
    else if (m_state.m_n0c == 7)
        spRadio = pDlg->FUN_140a46480(CString("m_takeDamageAll"), -1);
    if (static_cast<Unk_GoRadio*>(spRadio) != 0)
        spRadio->FUN_1422ce090(1);
    unsigned nDiff = m_state.m_n10;
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_diffSize"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(nDiff & 1);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_diffAlpha"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(nDiff & 2);
    }
}

// @0x141247770
void CGameOptionBattle::vfunc_7()
{
    Unk_GoDialog* pDlg = (Unk_GoDialog*)GetOptionDialog();
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayMyGiveRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[0] = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayMyTakeRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[1] = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = pDlg->FUN_140a57f50(CString("m_displayPartyRecovery"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[2] = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayGetMeso"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[3] = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayGetExp"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[4] = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayEpGauge"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b[5] = sp->FUN_1422ce0e0();
    }
    ATL::CAtlArray<std::pair<CString, int> > arrGive;
    int nGiveMine = 1;
    arrGive.Add(std::pair<CString, int>("m_giveDamageMine", nGiveMine));
    int nGiveParty = 3;
    arrGive.Add(std::pair<CString, int>("m_giveDamageParty", nGiveParty));
    int nGiveAll = 7;
    arrGive.Add(std::pair<CString, int>("m_giveDamageAll", nGiveAll));
    for (size_t i = 0; i < arrGive.GetCount(); i++)
    {
        const std::pair<CString, int>& opt = arrGive[i];
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString(opt.first), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0 && sp->FUN_1422ce0e0())
        {
            m_state.m_n08 = opt.second;
            break;
        }
    }
    ATL::CAtlArray<std::pair<CString, int> > arrTake;
    int nTakeMine = 1;
    arrTake.Add(std::pair<CString, int>("m_takeDamageMine", nTakeMine));
    int nTakeParty = 3;
    arrTake.Add(std::pair<CString, int>("m_takeDamageParty", nTakeParty));
    int nTakeAll = 7;
    arrTake.Add(std::pair<CString, int>("m_takeDamageAll", nTakeAll));
    for (size_t i = 0; i < arrTake.GetCount(); i++)
    {
        const std::pair<CString, int>& opt = arrTake[i];
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString(opt.first), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0 && sp->FUN_1422ce0e0())
        {
            m_state.m_n0c = opt.second;
            break;
        }
    }
    unsigned nDiff = 0;
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_diffSize"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
        {
            nDiff = sp->FUN_1422ce0e0() ? 1 : 0;
            m_state.m_n10 = nDiff;
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_diffAlpha"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
        {
            if (sp->FUN_1422ce0e0())
                nDiff |= 2;
            m_state.m_n10 = nDiff;
        }
    }
}

// @0x141248140
void CGameOptionBattle::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125d100(TSingleton<CGameOption>::GetInstance()->FUN_141248630(), &m_state);
}

// @0x141248190
void CGameOptionBattle::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125cab0(&m_state);
    FUN_14125cb20(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x1412481f0
CString CGameOptionBattle::vfunc_1()
{
    return CString("GameOptionBattle");
}

// MS2-FUNCTIONAL: the exe returns the raw memcmp int from a bool-declared slot (no setne)
// @0x141248240
bool CGameOptionBattle::vfunc_14()
{
    return memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_141248630(), 0x14);
}

// ---- CGameOptionCamera ----
// @0x141248830
CGameOptionCamera::CGameOptionCamera(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125b400(&m_state);
}

// @0x141248890
CGameOptionCamera::~CGameOptionCamera()
{
}

// @0x1412488c0
void CGameOptionCamera::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125b6b0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140af7de0());
    CBaseOption::vfunc_3(n);
}

// @0x141248910
void CGameOptionCamera::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141248940
int CGameOptionCamera::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141248960
void CGameOptionCamera::vfunc_6()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableBgTransparency"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b00);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableVibrateEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_b01);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_cameraLooseStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_n04);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_cameraFovStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)FUN_14125b6e0(&m_state));
    }
}

// @0x141248c40
void CGameOptionCamera::vfunc_7()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableBgTransparency"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b00 = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enableVibrateEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_b01 = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_cameraLooseStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_n04 = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_cameraFovStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            FUN_14125b720(&m_state, (int)sp->FUN_1422ce630());
    }
}

// A float table value of the client configuration (FUN_1401d3200).
class Unk_GoCfgValue
{
public:
    const float& FUN_140298f40();
private:
    char m_pad[0x58];
};
struct Unk_GoConfig
{
    char m_pad_0000[0x1a80];
    Unk_GoCfgValue m_1a80;
    Unk_GoCfgValue m_1ad8;
    Unk_GoCfgValue m_1b30;
};
Unk_GoConfig* FUN_1401d3200();

// WorldService singleton (FUN_1403ed2d0): the current field and the camera scale.
class Unk_1403ed2d0
{
public:
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // the current field data
    float FUN_141bcfc50();                                      // camera scale of the local player
    MyPC* FUN_141bd0cc0();                                      // the local player
};
Unk_1403ed2d0* FUN_1403ed2d0();

// @0x141248f10
void CGameOptionCamera::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125b6b0(TSingleton<CGameOption>::GetInstance()->FUN_140af7de0(), &m_state);
    int nApply = 1;
    if (static_cast<CFieldDataCli*>(FUN_1403ed2d0()->FUN_141bd30a0()) != 0)
        nApply = FUN_1403ed2d0()->FUN_141bd30a0()->m_nApplyCameraOption;
    if (nApply != 0)
    {
        float fScale = FUN_1403ed2d0()->FUN_141bcfc50();
        TSingleton<CameraMgr>::GetInstance()->FUN_140ad4ff0(fScale);
        float fStep = (float)m_state.m_n04 / 100.0f;
        float f1 = FUN_1401d3200()->m_1a80.FUN_140298f40();
        float f2 = FUN_1401d3200()->m_1ad8.FUN_140298f40();
        float f3 = FUN_1401d3200()->m_1b30.FUN_140298f40();
        TSingleton<CameraMgr>::GetInstance()->FUN_140aeb880(f1 * fStep, f2 * fStep, f3 * fStep);
        CCameraMode* pMode = TSingleton<CameraMgr>::GetInstance()->FUN_140af2520();
        if (pMode != 0)
        {
            if (pMode->vfunc_1() == 0x10)
                static_cast<CLocalTargetCameraMode*>(pMode)->FUN_140d4fa10(fScale);
            CCameraMode* pTarget = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0();
            if (pTarget != 0)
            {
                pTarget->vfunc_11(fScale);
                pTarget->vfunc_29(f1 * fStep, f2 * fStep, f3 * fStep);
            }
        }
    }
    TSingleton<BGTransparencyMgr>::GetInstance()->SetUserFlags(m_state.m_b00 != 0);
}

// @0x1412491c0
void CGameOptionCamera::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125b430(&m_state);
    FUN_14125b480(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x141249220
CString CGameOptionCamera::vfunc_1()
{
    return CString("GameOptionCamera");
}

// MS2-FUNCTIONAL: the exe returns the raw memcmp int from a bool-declared slot (no setne)
// @0x141249270
bool CGameOptionCamera::vfunc_14()
{
    return memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_140af7de0(), 0x10);
}

// ---- CGameOptionCommunity ----
// @0x1412492f0
CGameOptionCommunity::CGameOptionCommunity(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125d130(&m_stateA);
    FUN_14125d330(&m_stateB);
}

// @0x141249370
CGameOptionCommunity::~CGameOptionCommunity()
{
}

// @0x1412493a0
void CGameOptionCommunity::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125d2a0(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_14124ab20());
        FUN_14125d710(&m_stateB, TSingleton<CGameOption>::GetInstance()->FUN_140ae6540());
    }
    CBaseOption::vfunc_3(n);
}

// @0x141249410
void CGameOptionCommunity::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x141249440
int CGameOptionCommunity::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}

// @0x141249460
void CGameOptionCommunity::vfunc_6()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateA.m_b[0]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayOtherChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateA.m_b[1]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableSingleRiding"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateA.m_b[2]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmSuper"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[0]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmWorld"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[1]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmChannel"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[2]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disablePartyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[3]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableBuddyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[4]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableGuildRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[5]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableGroupRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[6]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableWhisperNotify"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[7]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableTradeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[8]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableHomeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[9]);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableCoupleEmotionRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_stateB.m_b[10]);
    }
}

// @0x141249e50
void CGameOptionCommunity::vfunc_7()
{
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayMyChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_b[0] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayOtherChatBalloon"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_b[1] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableSingleRiding"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateA.m_b[2] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmSuper"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[0] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmWorld"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[1] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_displayChatComfirmChannel"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[2] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disablePartyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[3] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableBuddyRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[4] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableGuildRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[5] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableGroupRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[6] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableWhisperNotify"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[7] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableTradeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[8] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableHomeRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[9] = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_disableCoupleEmotionRequest"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_stateB.m_b[10] = sp->FUN_1422ce0e0() != 0;
    }
}

// @0x14124a8d0
void CGameOptionCommunity::vfunc_10()
{
    CBaseOption::vfunc_10();
    if (TSingleton<CGameOption>::GetInstance()->FUN_14124ab20()->m_b[2] != m_stateA.m_b[2])
    {
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            pPlayer->FUN_14152dff0(m_stateA.m_b[2]);
    }
    FUN_14125d2a0(TSingleton<CGameOption>::GetInstance()->FUN_14124ab20(), &m_stateA);
    FUN_14125d710(TSingleton<CGameOption>::GetInstance()->FUN_140ae6540(), &m_stateB);
}

// @0x14124a990
void CGameOptionCommunity::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125d360(&m_stateB);
    FUN_14125d160(&m_stateA);
    FUN_14125d3d0(&m_stateB, TSingleton<CGameOption>::GetInstance()->FUN_1412442c0());
    FUN_14125d190(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x14124aa20
CString CGameOptionCommunity::vfunc_1()
{
    return CString("GameOptionCommunity");
}

// @0x14124aa70
bool CGameOptionCommunity::vfunc_14()
{
    if (FUN_14125d2d0(&m_stateA, TSingleton<CGameOption>::GetInstance()->FUN_14124ab20()))
        return true;
    return FUN_14125d740(&m_stateB, TSingleton<CGameOption>::GetInstance()->FUN_140ae6540()) ? true : false;
}

