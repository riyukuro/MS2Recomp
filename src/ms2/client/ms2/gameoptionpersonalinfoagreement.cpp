// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptionpersonalinfoagreement.cpp: the
// personal info (log sending) agreement row of the game options.
// MS2-UNIT: ?\gameoptionpersonalinfoagreement.cpp
// MS2-RANGE: 0x1400c3670-0x1400c36d0 .text$di
// MS2-RANGE: 0x140a45d40-0x140a46ab0 .text$mn
// MS2-PIN: ??_GCGameOptionPersonalInfoAgreement@@UEAAPEAXI@Z 0x140a46820
// MS2-PIN: ?Invoke@AScript@@QEAA?AVValue@GFx@Scaleform@@PEBDV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x140a46640
// MS2-PIN: ?FUN_140a463d0@@YA?AV?$MS2Ptr@VUnk_PiCheck@@@@HAEBVValue@GFx@Scaleform@@@Z 0x140a463d0
// MS2-PIN: ?FUN_140a46480@Unk_PiDialog@@QEAA?AV?$MS2Ptr@VUnk_PiCheck@@@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z 0x140a46480
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptionpersonalinfoagreement.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameoptionpersonalinfoagreement.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cgameoption.h"
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
// The game-option settings object (CGameOption; +0x1b4 is the agreement setting).
class Unk_PiSettings;
unsigned char* FUN_140a46860(Unk_PiSettings* p);
class CPersonalInfoAgreement   // C3: member view for the former free stand-ins
{
public:
    void FUN_141262090();
};
void FUN_1412627c0(Unk_PiAgreeState* p, CString s);
void FUN_141261cf0(Unk_PiAgreeState* p);
void FUN_141261d20(Unk_PiAgreeState* p);
void FUN_141261d40(Unk_PiAgreeState* p);
void FUN_141261da0(void* pDst, const void* pSrc);
void FUN_141261dd0(void* p, int n);
bool FUN_141261f00(void* p, int n);
void FUN_141261e40(Unk_PiAgreeState* p, int a, int b);
CString* FUN_140298f80(void* p);

// View of the option dialog: an id at +0x28, the AS root at +0x30.
struct Unk_PiDialog
{
    // The check box child of a tab by name (a member: this in rcx, the return slot in rdx).
    MS2Ptr<Unk_PiCheck> FUN_140a46480(CString name, int nIndex);
    char m_pad[0x28];
    int m_nDialogId;    // +0x28, handed to each check box
    char m_pad2c[4];
    MS2Ptr<AScript> m_root;
};
void FUN_1422bce70(Scaleform::GFx::Value* v, const char* s);
void FUN_1422bccb0(Scaleform::GFx::Value* v, int n);

// AScript::Invoke(method, CString, int) (inline COMDAT; this in rcx, the return slot in rdx, the method name in r8).
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString name, int nIndex)   // 0x140a46640
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)name);
    FUN_1422bccb0(args.FUN_1409b1f70(1), nIndex);
    return FUN_1422bb8f0(szMethod, args);
}

MS2Ptr<Unk_PiCheck> FUN_140a463d0(int nId, const Scaleform::GFx::Value& v)    // 0x140a463d0
{
    MS2Ptr<Unk_PiCheck> sp(new Unk_PiCheck(v, nId));
    return sp;
}

MS2Ptr<Unk_PiCheck> Unk_PiDialog::FUN_140a46480(CString name, int nIndex)   // 0x140a46480
{
    if (m_root.IsNull())
        return MS2Ptr<Unk_PiCheck>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (child.IsDisplayObject())
    {
        MS2Ptr<Unk_PiCheck> check = FUN_140a463d0(m_nDialogId, child);
        if (check.get())
            return check;
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
        FUN_141261da0(&m_state, FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())));
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

void CGameOptionPersonalInfoAgreement::vfunc_6()   // @0x140a45ed0
{
    {
        MS2Ptr<Unk_PiCheck> agree = ((Unk_PiDialog*)GetOptionDialog())->FUN_140a46480(CString("m_sendLogAgree"), -1);
        if (agree.get() != 0)
            agree->FUN_1422ce090(m_state.m_bAgree);
    }
    MS2Ptr<Unk_PiCheck> deny = ((Unk_PiDialog*)GetOptionDialog())->FUN_140a46480(CString("m_sendLogDeny"), -1);
    if (deny.get() != 0)
        deny->FUN_1422ce090(m_state.m_bAgree == 0);
}

void CGameOptionPersonalInfoAgreement::vfunc_7()   // @0x140a46040
{
    {
        MS2Ptr<Unk_PiCheck> agree = ((Unk_PiDialog*)GetOptionDialog())->FUN_140a46480(CString("m_sendLogAgree"), -1);
        if (agree.get() != 0)
        {
            if (agree->FUN_1422ce0e0())
                m_state.m_bAgree = true;
        }
    }
    {
        MS2Ptr<Unk_PiCheck> deny = ((Unk_PiDialog*)GetOptionDialog())->FUN_140a46480(CString("m_sendLogDeny"), -1);
        if (deny.get() != 0)
        {
            if (deny->FUN_1422ce0e0())
                m_state.m_bAgree = false;
        }
    }
    int nMode = m_state.m_bAgree ? 2 : 4;
    FUN_141261e40(&m_state, 0, nMode);
    ((class CPersonalInfoAgreement*)(unsigned char*)(FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance()))))->FUN_141262090();
}

void CGameOptionPersonalInfoAgreement::vfunc_10()   // @0x140a461f0
{
    CBaseOption::vfunc_10();
    bool bChanged = false;
    if (m_state.m_bAgree != *FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())))
        bChanged = true;
    if (!FUN_141261f00(FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())), 0))
        bChanged = true;
    if (bChanged)
    {
        int nMode = m_state.m_bAgree ? 2 : 4;
        FUN_141261da0(FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())), &m_state);
        FUN_141261dd0(FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())), nMode);
        ((class CPersonalInfoAgreement*)(unsigned char*)(FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance()))))->FUN_141262090();
    }
}

void CGameOptionPersonalInfoAgreement::vfunc_12()   // @0x140a462f0
{
    CBaseOption::vfunc_12();
    FUN_141261d20(&m_state);
    FUN_141261d40(&m_state);
    vfunc_6();
}

CString CGameOptionPersonalInfoAgreement::GetTypeName()   // @0x140a46340
{
    return CString("GameOptionPersonalInfoAgreement");
}

int CGameOptionPersonalInfoAgreement::vfunc_14()   // @0x140a46390
{
    if (m_state.m_bAgree != *FUN_140a46860(reinterpret_cast<Unk_PiSettings*>(CGameOption::GetInstance())))
        return 1;
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

unsigned char* FUN_140a46860(Unk_PiSettings* p)   // 0x140a46860
{
    return (unsigned char*)p + 0x1b4;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f130-0x142c9f170 .text$yd
