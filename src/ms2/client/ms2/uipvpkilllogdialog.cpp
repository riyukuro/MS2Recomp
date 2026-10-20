// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPKillLogDialog: see uipvpkilllogdialog.h.
// MS2-UNIT: ?\uipvpkilllogdialog.cpp
// MS2-RANGE: 0x1400efce0-0x1400efeb0 .text$di
// MS2-RANGE: 0x141342570-0x141342f10 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpkilllogdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uipvpkilllogdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static CString s_strBattleFieldKill = "BattleField_Kill";
static CString s_strSystemKillPlayer = "System_KillPlayer";

// ---- unit-local views of exe objects ----

class Unk_PkTextFilter { public: void FUN_1416fb340(CStringW& str); };
Unk_PkTextFilter* FUN_1403b4750();

void* FUN_1403ed2d0();                                          // the world
PCBase* FUN_141bd0cc0(void* pWorld);                            // the own character
bool FUN_14025cd60(const CStringW& strA, const CStringW& strB); // names are equal
CStringW FUN_14052bd00(int nId, const CStringW& strName);       // string table text with one name
void FUN_141276180(const CString& strName, const CString& strOpt);   // play a sound
void FUN_1412751b0(const CStringW& strMsg, int nType);
void FUN_141925e70(int, int);

// @0x141342570
UIPvPKillLogDialog::UIPvPKillLogDialog()
{
    FUN_141925e70(1, 1);
}

// @0x141342600
UIPvPKillLogDialog::~UIPvPKillLogDialog()
{
}

// @0x141342670
CString UIPvPKillLogDialog::vfunc_1()
{
    return "PvPKillLogDialog";
}

// @0x1413426c0
int UIPvPKillLogDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x1413426f0
void UIPvPKillLogDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141342710
void UIPvPKillLogDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_strAttacker.GetLength() != 0)
    {
        if (m_strTarget.GetLength() != 0)
        {
            FUN_141342880(m_strAttacker, m_strTarget);
            m_strAttacker = L"";
            m_strTarget = L"";
        }
    }
}

// @0x141342820
// MS2-FUNCTIONAL: the exe returns the vfunc_55 / IsNull result (the shared base declares vfunc_79 void)
void UIPvPKillLogDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        m_30.IsNull();
}

// @0x141342880
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void UIPvPKillLogDialog::FUN_141342880(CStringW strAttacker, CStringW strTarget)
{
    if (m_30.IsNull())
    {
        m_strAttacker = strAttacker;
        m_strTarget = strTarget;
        return;
    }
    PCBase* pMe = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pMe == 0)
        return;
    ASObj obj(2);
    obj.FUN_1407cbb20("attackerName", CStringW(strAttacker));
    obj.FUN_1407cbb20("targetName", CStringW(strTarget));
    obj.FUN_1407cbb20("myName", pMe->vfunc_77());
    m_30->Invoke("addKill", Scaleform::GFx::Value(obj.FUN_1422bb870()));
    if (FUN_14025cd60(strAttacker, pMe->vfunc_77()))
    {
        FUN_141276180(s_strBattleFieldKill, CString(""));
        if (!strTarget.IsEmpty())
        {
            CStringW strMsg = FUN_14052bd00(0x973, strTarget);
            FUN_1403b4750()->FUN_1416fb340(strMsg);
            FUN_1412751b0(strMsg, 0x14);
        }
    }
    if (FUN_14025cd60(strTarget, pMe->vfunc_77()) && !strAttacker.IsEmpty())
    {
        CStringW strMsg = FUN_14052bd00(0x972, strAttacker);
        FUN_1403b4750()->FUN_1416fb340(strMsg);
        FUN_1412751b0(strMsg, 0x14);
    }
    bool bInvolved = FUN_14025cd60(strAttacker, pMe->vfunc_77()) || FUN_14025cd60(strTarget, pMe->vfunc_77());
    if (bInvolved)
        FUN_141276180(s_strSystemKillPlayer, CString(""));
}

// @0x141342dc0
int UIPvPKillLogDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// @0x141342e10
void UIPvPKillLogDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(5, 0x1e, 300);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0290-0x142cb0360 .text$yd
