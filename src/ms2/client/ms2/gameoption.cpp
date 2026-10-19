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
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/ms2format.h"

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
class Unk_GoCombo;
class Unk_GoInput;
class Unk_GoDialog
{
public:
    MS2Ptr<Unk_GoCheck> FUN_140a57f50(CString name, int nIndex);
    MS2Ptr<Unk_GoSlider> FUN_140a58110(CString name, int nIndex);
    MS2Ptr<Unk_GoRadio> FUN_140a46480(CString name, int nIndex);
    MS2Ptr<Unk_GoCombo> FUN_140cfcf10(CString name, int nIndex);
    MS2Ptr<ASTextField> FUN_14124e120(CString name, int nIndex);
    MS2Ptr<Unk_GoInput> FUN_14124e2e0(CString name, int nIndex);
    MS2Ptr<ASUIComponent> FUN_14124ff50(int nIndex);

    char m_pad[0x28];
    int m_nId;                                                      // +0x28 the option id
    int m_pad2;
    MS2Ptr<AScript> m_root;                                         // +0x30 the AS root
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
    void FUN_141bd4260();                                       // enchant effect off
    void FUN_141bd41d0();                                       // enchant effect on
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

// ---- CGameOptionGraphicDefault ----

// More option-dialog controls. A combo box, a text input; both derive from the AS component (0x88 bytes).
class Unk_GoCombo : public ASUIComponent
{
public:
    virtual void vfunc_16();                                    // 16..23 (ASUIComponent slots)
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                       // 24 validateNow
    void FUN_1422dfc10();                                       // remove all rows
    void FUN_1422dfc70(ASObj& item);                            // add a row
    void FUN_1422df5f0(unsigned int nRows);                     // visible rows
    void FUN_1422df690(int nRow);                               // select a row
    int FUN_1422df6c0();                                        // selected row
    void FUN_1422df8c0(const CStringW& strIcon);                // the dropdown icon
};
class Unk_GoInput : public ASUIComponent
{
public:
    void FUN_1422e0ab0(const CStringW& strText);
    CStringW FUN_1422e0b00();
};

// The lookups of the dialog view by child name (more instances of the getTabChild template); the first three live in this unit.
MS2Ptr<ASTextField> FUN_1409b41a0(int nId, const Scaleform::GFx::Value& v);
MS2Ptr<Unk_GoInput> FUN_140bbe1d0(int nId, const Scaleform::GFx::Value& v);
MS2Ptr<ASUIComponent> FUN_140acca70(int nId, const Scaleform::GFx::Value& v);
bool FUN_1407cce10(const Scaleform::GFx::Value* v);
int FUN_1409c1750(const Scaleform::GFx::Value& v);              // the value as an int
int FUN_1407181a0(const CStringW& str);
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);   // formats one number
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);    // notice
int FUN_14151f6e0();

static std::pair<int, int> FUN_14124d9d0(int nWidth, int nHeight);
CStringW FormatStringId(int nId, const fmt::ArgList& args);   // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// @0x14124ff50
MS2Ptr<ASUIComponent> Unk_GoDialog::FUN_14124ff50(int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASUIComponent>(0);
    Scaleform::GFx::Value comp = m_root->Invoke("getTabComponent", nIndex);
    if (FUN_1407cce10(&comp))
    {
        MS2Ptr<ASUIComponent> sp = FUN_140acca70(m_nId, comp);
        if (static_cast<ASUIComponent*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASUIComponent>(0);
}

// @0x14124e120
MS2Ptr<ASTextField> Unk_GoDialog::FUN_14124e120(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASTextField>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<ASTextField> sp = FUN_1409b41a0(m_nId, child);
        if (static_cast<ASTextField*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<ASTextField>(0);
}

// @0x14124e2e0
MS2Ptr<Unk_GoInput> Unk_GoDialog::FUN_14124e2e0(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<Unk_GoInput>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<Unk_GoInput> sp = FUN_140bbe1d0(m_nId, child);
        if (static_cast<Unk_GoInput*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<Unk_GoInput>(0);
}

// The device name holder (DAT_143ad5158): the adapter's name at +0x18.
class Unk_GoDeviceInfo
{
public:
    CStringW FUN_141245ab0();                                   // copy of the adapter name
    char m_pad[0x18];
    CStringW m_strName;                                         // +0x18
};
extern Unk_GoDeviceInfo* DAT_143ad5158;

// @0x141245ab0
CStringW Unk_GoDeviceInfo::FUN_141245ab0()
{
    return CStringW(m_strName);
}

// @0x141245b20
Unk_GoDeviceInfo* FUN_141245b20()
{
    return DAT_143ad5158;
}

// The renderer's display mode list: raw modes (width, height, format) behind a counted pointer array.
struct Unk_GoRawMode
{
    int m_nWidth;
    int m_nHeight;
    int m_nFormat;
};
struct Unk_GoModeArray
{
    char m_pad0[8];
    Unk_GoRawMode** m_ppData;                                   // +0x08
    short m_s10;
    unsigned short m_nCount;                                    // +0x12
    Unk_GoRawMode** FUN_14124fec0(unsigned int nIndex);         // slot of the nIndex-th mode
    unsigned short FUN_14124ff40();                             // count
};
struct Unk_GoModeSource
{
    char m_pad[0x458];
    Unk_GoModeArray m_modes;                                    // +0x458
    Unk_GoRawMode* FUN_14124fee0(unsigned int nIndex);          // the nIndex-th mode (or null)
    unsigned short FUN_14124ff10();                             // count
};
class Unk_GoGfxDevice
{
public:
    Unk_GoModeSource* FUN_14124fea0();                          // +0x728 the display mode source
    char m_pad[0x728];
    Unk_GoModeSource* m_pModes;                                 // +0x728
};
Unk_GoGfxDevice* FUN_140994450();

// @0x14124fea0
Unk_GoModeSource* Unk_GoGfxDevice::FUN_14124fea0()
{
    return m_pModes;
}

// @0x14124fec0
Unk_GoRawMode** Unk_GoModeArray::FUN_14124fec0(unsigned int nIndex)
{
    return m_ppData + nIndex;
}

// @0x14124fee0
Unk_GoRawMode* Unk_GoModeSource::FUN_14124fee0(unsigned int nIndex)
{
    return *m_modes.FUN_14124fec0(nIndex);
}

// @0x14124ff10
unsigned short Unk_GoModeSource::FUN_14124ff10()
{
    return m_modes.FUN_14124ff40();
}

// @0x14124ff40
unsigned short Unk_GoModeArray::FUN_14124ff40()
{
    return m_nCount;
}

// One row of the resolution combo: the mode's index and its size. Sorted by size.
struct Unk_GoResMode
{
    int m_nIndex;
    std::pair<int, int> m_size;
    Unk_GoResMode(int nIndex, int nWidth, int nHeight) : m_nIndex(nIndex), m_size(nWidth, nHeight) {}
};
struct Unk_GoResModeLess
{
    bool operator()(const Unk_GoResMode& a, const Unk_GoResMode& b) const;
};

// @0x14124fdc0
bool Unk_GoResModeLess::operator()(const Unk_GoResMode& a, const Unk_GoResMode& b) const
{
    if (a.m_size.first == b.m_size.first)
        return a.m_size.second < b.m_size.second;
    return a.m_size.first < b.m_size.first;
}

// More members of the singletons used here.
class Unk_GoRenderCfg
{
public:
    int FUN_141376510(int nLevel);                              // the hdr flag of a quality level
    int FUN_141376790(int nIndex);                              // the framebuffer format of a multisampling row
};
Unk_GoRenderCfg* FUN_140ae1c00();
class Unk_GoEffectMgr { public: void FUN_1411a8880(int n); };
Unk_GoEffectMgr* FUN_1403ed280();
class Unk_GoUiMgr { public: void FUN_141adc5d0(int nUiId); void FUN_141adc530(int nUiId); };
Unk_GoUiMgr* FUN_1403ed2b0();

// The graphic state blocks' methods (client\ms2\gameoptionstruct.cpp).
void FUN_14125d890(Unk_GraphicState* p);
void FUN_14125d8c0(Unk_GraphicState* p);
int FUN_14125d9b0(Unk_GraphicState* p, TiXmlDocument* pDoc, int n);
void FUN_14125dff0(Unk_GraphicState* pDst, const Unk_GraphicState* pSrc);
void FUN_14125e1f0(Unk_GraphicState* p, int nQuality, int n);
void FUN_14125e300(Unk_GraphicState* p, bool b);
void FUN_14125e3b0(Unk_GraphicState* p, bool b);
void FUN_14125e4b0(Unk_GraphicState* p, int n);
void FUN_14125e5b0(Unk_GraphicState* p, bool b);
bool FUN_14125e7e0(Unk_GraphicState* p, int nFormat, int nWidth, int nHeight);
void FUN_14125e910(Unk_GraphicState* p, int nScreenMode, int nResIdx);
void FUN_14125ec20(Unk_GraphicState2* p);
void FUN_14125ec50(Unk_GraphicState2* p);
int FUN_14125ecc0(Unk_GraphicState2* p, TiXmlDocument* pDoc);
void FUN_14125ef60(Unk_GraphicState2* pDst, const Unk_GraphicState2* pSrc);
void FUN_14125ef90(Unk_GraphicState2* p);

// @0x14124ab20
Unk_CommunityStateA* CGameOption::FUN_14124ab20()
{
    return &m_communityA;
}

// @0x14124ab30
CGameOptionGraphicDefault::CGameOptionGraphicDefault(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125d890(&m_state);
    FUN_14125ec20(&m_state2);
    m_n74 = 0;
}

// @0x14124abb0
CGameOptionGraphicDefault::~CGameOptionGraphicDefault()
{
}

// @0x14124abe0
void CGameOptionGraphicDefault::vfunc_3(int n)
{
    if (n == 0)
    {
        FUN_14125dff0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0());
        FUN_14125ef60(&m_state2, TSingleton<CGameOption>::GetInstance()->FUN_140c77560());
    }
    m_n74 = 0;
    CBaseOption::vfunc_3(n);
}

// @0x14124ac60
void CGameOptionGraphicDefault::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}

// @0x14124ac90
int CGameOptionGraphicDefault::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    if (_stricmp(pszName, "onDisplayQuality") == 0 && m_n74 != 0)
    {
        ASData data;
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)pArg, nArg))
        {
            int nLevel = data.FUN_1422b8a10();
            {
                MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_hdr"), -1);
                if (static_cast<Unk_GoCheck*>(sp) != 0)
                    sp->FUN_1422ce090(FUN_140ae1c00()->FUN_141376510(nLevel));
            }
            {
                MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
                if (static_cast<Unk_GoCombo*>(sp) != 0)
                {
                    if (nLevel < 3)
                    {
                        if (nLevel < 2)
                        {
                            if (nLevel >= 0)
                                sp->FUN_1422df690(0);
                        }
                        else
                            sp->FUN_1422df690(1);
                    }
                    else
                        sp->FUN_1422df690(2);
                }
            }
            {
                MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_effectStep"), -1);
                if (static_cast<Unk_GoSlider*>(sp) != 0)
                {
                    int nMin = 1;
                    sp->FUN_1422ce5f0((float)(std::max)(nLevel, nMin));
                }
            }
            int nBenchmark = TSingleton<CGameOption>::GetInstance()->FUN_1412438f0();
            if (nBenchmark < nLevel && nLevel != m_state.m_nQuality && FUN_14151f6e0() != 0)
                FUN_140d73bc0(0x84d, 0, 0, CStringW(L""));
        }
    }
    return 0;
}

// @0x14124aff0
void CGameOptionGraphicDefault::vfunc_6()
{
    FUN_14124d080();
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_screenModeWindow"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_nScreenMode == 1);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_screenModeFullWindow"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_nScreenMode == 2);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showFrameRate"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bShowFrameRate);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_effectStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nEffectStep);
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_quality"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)m_state.m_nQuality);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_hdr"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bHdr != 0);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_shimmer"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bShimmer != 0);
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_multisampling"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
            sp->FUN_1422df690(m_state.m_nMultisampling);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_vsync"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bVsync);
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enchantEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state.m_bEnchantEffect);
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
        {
            int nShadow = m_state.m_nShadow;
            if (nShadow < 3)
            {
                if (nShadow < 2)
                {
                    if (nShadow >= 0)
                        sp->FUN_1422df690(0);
                }
                else
                    sp->FUN_1422df690(1);
            }
            else
                sp->FUN_1422df690(2);
        }
    }
    {
        MS2Ptr<ASTextField> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_14124e120(CString("m_devicename"), -1);
        if (static_cast<ASTextField*>(sp) != 0)
            sp->FUN_1422c4cd0(FUN_141245b20()->FUN_141245ab0());
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_optimalHide"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
            sp->FUN_1422df690(m_state2.m_nOptimalHide);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_hideAlways"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bHideAlways);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_hideBossBattle"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bHideBossBattle);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showParty"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bShowParty);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showGuild"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bShowGuild);
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showCustom"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bShowCustom);
    }
    {
        MS2Ptr<Unk_GoInput> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_14124e2e0(CString("m_customInput"), -1);
        if (static_cast<Unk_GoInput*>(sp) != 0)
            sp->FUN_1422e0ab0(FUN_1401ceea0(L"%d", m_state2.m_nCustomInput));
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showPhysx"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            sp->FUN_1422ce090(m_state2.m_bShowPhysx);
    }
    m_n74 = 1;
}

// @0x14124bf20
void CGameOptionGraphicDefault::vfunc_7()
{
    {
        MS2Ptr<ASUIComponent> spComp = ((Unk_GoDialog*)GetOptionDialog())->FUN_14124ff50(m_nType);
        if (static_cast<ASUIComponent*>(spComp) != 0)
        {
            int nRes = FUN_1409c1750(spComp->Invoke("getResolution"));
            if (nRes != -1)
            {
                m_state.m_nResIdx = nRes;
                FUN_14124d5f0(m_state.m_nResIdx, &m_state.m_nWidth, &m_state.m_nHeight);
            }
        }
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_screenModeWindow"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            if (sp->FUN_1422ce0e0())
                m_state.m_nScreenMode = 1;
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_screenModeFullWindow"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            if (sp->FUN_1422ce0e0())
                m_state.m_nScreenMode = 2;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showFrameRate"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bShowFrameRate = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_effectStep"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_nEffectStep = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<Unk_GoSlider> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a58110(CString("m_quality"), -1);
        if (static_cast<Unk_GoSlider*>(sp) != 0)
            m_state.m_nQuality = (int)sp->FUN_1422ce630();
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_hdr"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bHdr = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_shimmer"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bShimmer = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_shadow"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
        {
            int nSel = sp->FUN_1422df6c0();
            if (nSel == 0)
                m_state.m_nShadow = 0;
            else if (nSel == 1)
                m_state.m_nShadow = 2;
            else if (nSel == 2)
                m_state.m_nShadow = 3;
        }
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_vsync"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bVsync = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_enchantEffect"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state.m_bEnchantEffect = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_multisampling"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
            m_state.m_nMultisampling = sp->FUN_1422df6c0();
    }
    {
        MS2Ptr<Unk_GoCombo> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_optimalHide"), -1);
        if (static_cast<Unk_GoCombo*>(sp) != 0)
            m_state2.m_nOptimalHide = sp->FUN_1422df6c0();
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_hideAlways"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            m_state2.m_bHideAlways = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_hideBossBattle"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            m_state2.m_bHideBossBattle = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showParty"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            m_state2.m_bShowParty = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showGuild"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            m_state2.m_bShowGuild = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoRadio> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a46480(CString("m_showCustom"), -1);
        if (static_cast<Unk_GoRadio*>(sp) != 0)
            m_state2.m_bShowCustom = sp->FUN_1422ce0e0() != 0;
    }
    {
        MS2Ptr<Unk_GoInput> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_14124e2e0(CString("m_customInput"), -1);
        if (static_cast<Unk_GoInput*>(sp) != 0)
            m_state2.m_nCustomInput = FUN_1407181a0(sp->FUN_1422e0b00());
    }
    {
        MS2Ptr<Unk_GoCheck> sp = ((Unk_GoDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_showPhysx"), -1);
        if (static_cast<Unk_GoCheck*>(sp) != 0)
            m_state2.m_bShowPhysx = sp->FUN_1422ce0e0() != 0;
    }
}

// @0x14124ce20
void CGameOptionGraphicDefault::FUN_14124ce20()
{
    Unk_GraphicState* pGfx = TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0();
    bool bResChanged = false;
    if (m_state.m_nScreenMode != pGfx->m_nScreenMode || m_state.m_nResIdx != pGfx->m_nResIdx)
        bResChanged = true;
    if (bResChanged)
    {
        FUN_14125e910(TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0(), m_state.m_nScreenMode, m_state.m_nResIdx);
        m_state.m_nWidth = TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0()->m_nWidth;
        m_state.m_nHeight = TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0()->m_nHeight;
    }
    if (m_state.m_nQuality != pGfx->m_nQuality)
        FUN_14125e1f0(&m_state, m_state.m_nQuality, 0);
    if (m_state.m_bHdr != pGfx->m_bHdr)
        FUN_14125e300(&m_state, m_state.m_bHdr);
    if (m_state.m_bShimmer != pGfx->m_bShimmer)
        FUN_14125e3b0(&m_state, m_state.m_bShimmer);
    if (m_state.m_nEffectStep != pGfx->m_nEffectStep)
        FUN_1403ed280()->FUN_1411a8880(m_state.m_nEffectStep);
    bool bMultisampling = m_state.m_nMultisampling != pGfx->m_nMultisampling;
    if (bMultisampling)
        FUN_14125e4b0(&m_state, FUN_140ae1c00()->FUN_141376790(m_state.m_nMultisampling));
    bool bVsync = m_state.m_bVsync != pGfx->m_bVsync;
    if (bVsync)
        FUN_14125e5b0(&m_state, m_state.m_bVsync);
    if (!m_state.m_bShowFrameRate)
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e7d);
    else
        FUN_1403ed2b0()->FUN_141adc530(0x4e7d);
    if (bVsync || bMultisampling)
        FUN_140d73bc0(0x84e, 0, 0, CStringW(L""));
}

// @0x14124d080
void CGameOptionGraphicDefault::FUN_14124d080()
{
    MS2Ptr<Unk_GoCombo> spCombo = ((Unk_GoDialog*)GetOptionDialog())->FUN_140cfcf10(CString("m_resolution"), -1);
    if (static_cast<Unk_GoCombo*>(spCombo) != 0)
    {
        spCombo->FUN_1422dfc10();
        int nCurWidth = m_state.m_nWidth;
        int nCurHeight = m_state.m_nHeight;
        Unk_GoGfxDevice* pDevice = FUN_140994450();
        if (pDevice != 0)
        {
            Unk_GoModeSource* pSource = pDevice->FUN_14124fea0();
            if (pSource != 0)
            {
                std::vector<Unk_GoResMode> modes;
                for (unsigned int i = 0; i < pSource->FUN_14124ff10(); i++)
                {
                    Unk_GoRawMode* pRaw = pSource->FUN_14124fee0(i);
                    if (pRaw != 0
                        && FUN_14125e7e0(TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0(), pRaw->m_nFormat, pRaw->m_nWidth, pRaw->m_nHeight))
                        modes.push_back(Unk_GoResMode(i, pRaw->m_nWidth, pRaw->m_nHeight));
                }
                if (!modes.empty())
                {
                    int nRows = (int)modes.size();
                    if (nRows < 7)
                        spCombo->FUN_1422df5f0(nRows);
                    else
                        spCombo->FUN_1422df8c0(CStringW(L"export_scroll"));
                    std::sort(modes.begin(), modes.end(), Unk_GoResModeLess());
                    int nSelected = 0;
                    for (int j = 0; j < nRows; j++)
                    {
                        const Unk_GoResMode& mode = modes.at(j);
                        int nWidth = mode.m_size.first;
                        int nHeight = mode.m_size.second;
                        CStringW strLabel;
                        std::pair<int, int> ratio = FUN_14124d9d0(nWidth, nHeight);
                        if ((float)ratio.first / (float)ratio.second < 1.59f)
                            strLabel = FormatStringId(0x30f, nWidth, nHeight, ratio.first, ratio.second);
                        else
                            strLabel = FormatStringId(0x310, nWidth, nHeight, ratio.first, ratio.second);
                        ASObj row(2);
                        row.FUN_1407cb9c0("modeid", mode.m_nIndex);
                        row.FUN_1407cbb20("label", strLabel);
                        spCombo->FUN_1422dfc70(row);
                        if (nCurWidth == nWidth && nCurHeight == nHeight)
                            nSelected = j;
                    }
                    spCombo->FUN_1422df690(nSelected);
                    spCombo->vfunc_24(true);
                }
            }
        }
    }
}

// @0x14124d5f0
void CGameOptionGraphicDefault::FUN_14124d5f0(int nIndex, int* pnWidth, int* pnHeight)
{
    Unk_GoGfxDevice* pDevice = FUN_140994450();
    if (pDevice != 0)
    {
        Unk_GoModeSource* pSource = pDevice->FUN_14124fea0();
        if (pSource != 0)
        {
            Unk_GoRawMode* pRaw = pSource->FUN_14124fee0(nIndex);
            if (pRaw != 0)
            {
                *pnWidth = pRaw->m_nWidth;
                *pnHeight = pRaw->m_nHeight;
            }
        }
    }
}

// @0x14124d6a0
void CGameOptionGraphicDefault::vfunc_10()
{
    CBaseOption::vfunc_10();
    bool bOldEnchant = true;
    Unk_GraphicState* pGfx = TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0();
    if (pGfx != 0)
        bOldEnchant = pGfx->m_bEnchantEffect;
    FUN_14124ce20();
    FUN_14125dff0(TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0(), &m_state);
    FUN_14125ef60(TSingleton<CGameOption>::GetInstance()->FUN_140c77560(), &m_state2);
    FUN_14125ef90(&m_state2);
    if (m_state.m_bEnchantEffect != bOldEnchant)
    {
        if (!m_state.m_bEnchantEffect)
            FUN_1403ed2d0()->FUN_141bd4260();
        else
            FUN_1403ed2d0()->FUN_141bd41d0();
    }
}

// @0x14124d7a0
void CGameOptionGraphicDefault::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125d8c0(&m_state);
    FUN_14125d9b0(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0(), 1);
    FUN_14125ec50(&m_state2);
    FUN_14125ecc0(&m_state2, TSingleton<CGameOption>::GetInstance()->FUN_1412442a0());
    vfunc_6();
}

// @0x14124d840
CString CGameOptionGraphicDefault::vfunc_1()
{
    return CString("GameOptionGraphic");
}

// @0x14124d890
bool CGameOptionGraphicDefault::vfunc_14()
{
    unsigned int nDiff1 = memcmp(&m_state, TSingleton<CGameOption>::GetInstance()->FUN_1409a8ac0(), sizeof(Unk_GraphicState));
    unsigned int nDiff2 = memcmp(&m_state2, TSingleton<CGameOption>::GetInstance()->FUN_140c77560(), sizeof(Unk_GraphicState2));
    return nDiff1 | nDiff2;
}

// @0x14124d900
static int FUN_14124d900(int a, int b)
{
    while (b != 0)
    {
        int nRem = a % b;
        a = b;
        b = nRem;
    }
    return abs(a);
}

// @0x14124d950
static float FUN_14124d950(float f)
{
    float fInt = (float)(int)f;
    if (0.5f <= f - fInt)
        fInt = ceilf(fInt + 1.0f);
    return fInt;
}

// The aspect ratio of a resolution as a small integer pair (16:9, 16:10, ...).
// @0x14124d9d0
static std::pair<int, int> FUN_14124d9d0(int nWidth, int nHeight)
{
    int nGcd = FUN_14124d900(nWidth, nHeight);
    int a = nWidth;
    int b = nHeight;
    if (1 < nGcd)
    {
        a = nWidth / nGcd;
        b = nHeight / nGcd;
    }
    bool bScale = 0x10 < a;
    if (!bScale)
    {
        float fRatio = (float)a / (float)b;
        if (fRatio < 1.6f || 1.67f <= fRatio)
            bScale = 5 < a;
        else
        {
            int nMul = (int)(16.0f / (float)a);
            a = a * nMul;
            b = b * nMul;
            if (a < 0x10 && (nGcd = FUN_14124d900(a, b), 1 < nGcd))
            {
                a = a / nGcd;
                b = b / nGcd;
            }
        }
    }
    if (bScale)
    {
        float fRatio = (float)a / (float)b;
        float fScaled;
        if (1.6f <= fRatio)
            fScaled = fRatio * 10.0f;
        else
            fScaled = FUN_14124d950(fRatio * 10.0f);
        if (1.57f <= fRatio)
        {
            float fNine = 9.0f;
            float fMul = 9.0f / (float)b;
            a = (int)FUN_14124d950((float)a * fMul);
            b = (int)fNine;
        }
        else
        {
            int nScaled = (int)fScaled;
            float fMul = (float)nScaled / (float)a;
            a = nScaled;
            b = (int)FUN_14124d950((float)b * fMul);
            float fRatio2 = (float)a / (float)b;
            if ((fRatio2 < 1.6f || 1.67f <= fRatio2) && (nGcd = FUN_14124d900(a, b), 1 < nGcd))
            {
                a = a / nGcd;
                b = b / nGcd;
            }
        }
    }
    return std::pair<int, int>(a, b);
}
