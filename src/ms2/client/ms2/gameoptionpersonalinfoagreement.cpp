// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptionpersonalinfoagreement.cpp: the
// personal info (log sending) agreement row of the game options.
// MS2-UNIT: ?\gameoptionpersonalinfoagreement.cpp
// MS2-RANGE: 0x1400c3670-0x1400c36d0 .text$di
// MS2-RANGE: 0x140a45d40-0x140a46ab0 .text$mn
// MS2-PIN: ??_GCGameOptionPersonalInfoAgreement@@UEAAPEAXI@Z 0x140a46820
// MS2-PIN: ?FUN_140a46640@@YA?AVValue@GFx@Scaleform@@PEAVAScript@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x140a46640
// MS2-PIN: ?FUN_140a463d0@@YA?AV?$MS2Ptr@VUnk_PiCheck@@@@HAEBVValue@GFx@Scaleform@@@Z 0x140a463d0
// MS2-PIN: ?FUN_140a46480@@YA?AV?$MS2Ptr@VUnk_PiCheck@@@@PEAUUnk_PiDialog@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x140a46480
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionpersonalinfoagreement.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameoptionpersonalinfoagreement.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- unit-local placeholders ----
static CString s_stun = "stun";     // 0x143ab6740 (dynamic initializers 0x1400c3670 / 0x1400c36a0)
static CString s_skill = "skill";   // 0x143ab6748

// A checkbox-like AS entity of the option dialog (0x88 bytes).
class Unk_PiCheck : public CPtred
{
public:
    Unk_PiCheck(const Scaleform::GFx::Value& v, int nId);       // 0x1422ce4b0
    void FUN_1422ce090(int bChecked);
    bool FUN_1422ce0e0();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// The agreement state (member at +0x30 of the option); helper calls only.
class Unk_PiState : public Unk_PiAgreeState
{
public:
    Unk_PiState();                                              // 0x141261cf0
    void FUN_141261d20();
    void FUN_141261d40();
    void FUN_141261da0(const void* p);
    void FUN_141261dd0(int n);
    bool FUN_141261f00(int n);
    void FUN_141261e40(int a, int b);
    void FUN_1412627c0(CString s);
};
// The game-option settings object returned by FUN_1409a8b10 (+0x1b4 is the agreement setting).
class Unk_PiSettings;
Unk_PiSettings* FUN_1409a8b10();
unsigned char* FUN_140a46860(Unk_PiSettings* p);
void FUN_141262090(unsigned char* p);
void FUN_1412627c0(Unk_PiAgreeState* p, CString s);
void FUN_141261cf0(Unk_PiAgreeState* p);
void FUN_141261d20(Unk_PiAgreeState* p);
void FUN_141261d40(Unk_PiAgreeState* p);
void FUN_141261da0(void* pDst, const void* pSrc);
void FUN_141261dd0(void* p, int n);
bool FUN_141261f00(void* p, int n);
void FUN_141261e40(Unk_PiAgreeState* p, int a, int b);
CString* FUN_140298f80(void* p);

// View of the option dialog: the AS root at +0x30.
struct Unk_PiDialog
{
    char m_pad[0x30];
    MS2Ptr<AScript> m_root;
};
void FUN_1422bce70(Scaleform::GFx::Value* v, const char* s);
void FUN_1422bccb0(Scaleform::GFx::Value* v, int n);
bool FUN_1407cce10(const Scaleform::GFx::Value* v);

Scaleform::GFx::Value FUN_140a46640(AScript* pObj, CString name, int nIndex)   // 0x140a46640
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)name);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nIndex);
    return pObj->FUN_1422bb8f0("getTabChild", args);
}

MS2Ptr<Unk_PiCheck> FUN_140a463d0(int nId, const Scaleform::GFx::Value& v)    // 0x140a463d0
{
    Unk_PiCheck* p = new Unk_PiCheck(v, nId);
    MS2Ptr<Unk_PiCheck> tmp(p);
    MS2Ptr<Unk_PiCheck> res(0);
    res = tmp;
    return res;
}

MS2Ptr<Unk_PiCheck> FUN_140a46480(Unk_PiDialog* pDlg, CString name, int nIndex)   // 0x140a46480
{
    if (!pDlg->m_root.IsNull())
    {
        Scaleform::GFx::Value child = FUN_140a46640(pDlg->m_root.operator->(), name, nIndex);
        if (FUN_1407cce10(&child))
        {
            MS2Ptr<Unk_PiCheck> check = FUN_140a463d0(*(int*)((char*)pDlg + 0x28), child);
            if (!check.IsNull())
                return check;
        }
    }
    return MS2Ptr<Unk_PiCheck>(0);
}

// ---- CGameOptionPersonalInfoAgreement ----
CGameOptionPersonalInfoAgreement::CGameOptionPersonalInfoAgreement(int nId, int nType)   // @0x140a45d40
    : CBaseOption(nId, nType)
{
    FUN_141261cf0(&m_state);
}

CGameOptionPersonalInfoAgreement::~CGameOptionPersonalInfoAgreement()   // @0x140a45da0
{
}

void CGameOptionPersonalInfoAgreement::vfunc_3(int n)   // @0x140a45dd0
{
    if (n == 0)
        FUN_141261da0(&m_state, FUN_140a46860(FUN_1409a8b10()));
    CBaseOption::vfunc_3(n);
}

void CGameOptionPersonalInfoAgreement::vfunc_4(int n)   // @0x140a45e20
{
    CBaseOption::vfunc_4(n);
}

int CGameOptionPersonalInfoAgreement::vfunc_5(const char* pszName, void* pArg, int nArg)   // @0x140a45e50
{
    if (_stricmp(pszName, "OnDetail") == 0)
        FUN_1412627c0(&m_state, CString(*FUN_140298f80((char*)FUN_1401d3200() + 0xe918)));
    return 0;
}

// MS2-FUNCTIONAL: MS2Ptr/CString temporaries and EH states differ
void CGameOptionPersonalInfoAgreement::vfunc_6()   // @0x140a45ed0
{
    MS2Ptr<Unk_PiCheck> agree = FUN_140a46480((Unk_PiDialog*)GetOptionDialog(), CString("m_sendLogAgree"), -1);
    if (agree.get() != 0)
        agree->FUN_1422ce090(m_state.m_bAgree);
    agree = 0;
    MS2Ptr<Unk_PiCheck> deny = FUN_140a46480((Unk_PiDialog*)GetOptionDialog(), CString("m_sendLogDeny"), -1);
    if (deny.get() != 0)
        deny->FUN_1422ce090(m_state.m_bAgree == 0);
}

// MS2-FUNCTIONAL: MS2Ptr/CString temporaries and EH states differ
void CGameOptionPersonalInfoAgreement::vfunc_7()   // @0x140a46040
{
    MS2Ptr<Unk_PiCheck> agree = FUN_140a46480((Unk_PiDialog*)GetOptionDialog(), CString("m_sendLogAgree"), -1);
    if (agree.get() != 0)
    {
        if (agree->FUN_1422ce0e0())
            m_state.m_bAgree = true;
    }
    agree = 0;
    MS2Ptr<Unk_PiCheck> deny = FUN_140a46480((Unk_PiDialog*)GetOptionDialog(), CString("m_sendLogDeny"), -1);
    if (deny.get() != 0)
    {
        if (deny->FUN_1422ce0e0())
            m_state.m_bAgree = false;
    }
    deny = 0;
    int nMode;
    if (m_state.m_bAgree == 0)
        nMode = 4;
    else
        nMode = 2;
    FUN_141261e40(&m_state, 0, nMode);
    FUN_141262090(FUN_140a46860(FUN_1409a8b10()));
}

// MS2-FUNCTIONAL: exe keeps extra frame locals (byte 0 + dword) not reproduced
void CGameOptionPersonalInfoAgreement::vfunc_10()   // @0x140a461f0
{
    CBaseOption::vfunc_10();
    unsigned char cOld = m_state.m_bAgree;
    unsigned char cNew = *FUN_140a46860(FUN_1409a8b10());
    if (!FUN_141261f00(FUN_140a46860(FUN_1409a8b10()), 0) || cOld != cNew)
    {
        int nMode;
        if (m_state.m_bAgree == 0)
            nMode = 4;
        else
            nMode = 2;
        FUN_141261da0(FUN_140a46860(FUN_1409a8b10()), &m_state);
        FUN_141261dd0(FUN_140a46860(FUN_1409a8b10()), nMode);
        FUN_141262090(FUN_140a46860(FUN_1409a8b10()));
    }
}

void CGameOptionPersonalInfoAgreement::vfunc_12()   // @0x140a462f0
{
    CBaseOption::vfunc_12();
    FUN_141261d20(&m_state);
    FUN_141261d40(&m_state);
    vfunc_6();
}

CString CGameOptionPersonalInfoAgreement::vfunc_1()   // @0x140a46340
{
    return CString("GameOptionPersonalInfoAgreement");
}

// MS2-FUNCTIONAL: bool compare temp placement
int CGameOptionPersonalInfoAgreement::vfunc_14()   // @0x140a46390
{
    int c = m_state.m_bAgree;
    return c != *FUN_140a46860(FUN_1409a8b10()) ? true : false;
}

MS2_EMIT_CRT_MEMMOVE_S();

unsigned char* FUN_140a46860(Unk_PiSettings* p)   // 0x140a46860
{
    return (unsigned char*)p + 0x1b4;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f130-0x142c9f170 .text$yd
