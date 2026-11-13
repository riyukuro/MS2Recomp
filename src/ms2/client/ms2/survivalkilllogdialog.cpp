// survivalkilllogdialog.cpp - Mushking Royale restore: UISurvivalKillLogDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: survivalkilllogdialog
// MS2-NO-EXE: 0x140db5397 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/survivalkilllogdialog.h"
#include "ms2/client/ms2/stormbar.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- KMS helpers (declarations as their other callers have them) ----
template <class A> CStringW FormatStringId(int nId, const A& a);       // string table text with one name
int PlaySystemSound(const CString& strName, const CString& strExtra);
void FUN_1412751b0(const CStringW& strMsg, int nType);                  // chat-log system line
int FUN_1418fc760(const char* szMethod, void* pArgs, int nArgs, void* pDlg);   // common AS callbacks (UIDialog users)

__int64 UISurvivalKillLogDialog::s_killerId = 0;
CStringW UISurvivalKillLogDialog::s_killerName;
bool UISurvivalKillLogDialog::s_bInGame = false;

namespace
{
const int kObserverStateId = 0x3f;     // PCBase state: StateObserver (SpectateMushtopia mode 1)

PCBase* LocalPC()
{
    WorldService* pWs = WorldService::GetInstance();
    if (pWs == 0)
        return 0;
    return (PCBase*)pWs->GetLocalPlayer();
}

UISurvivalKillLogDialog* FindKillLog()
{
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_SURVIVAL_KILLLOG);
    if (sp.get() == 0)
        return 0;
    return static_cast<UISurvivalKillLogDialog*>(sp.operator->());   // the service keeps the dialog alive
}

UIStormBar* FindStormBar()
{
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_STORMBAR);
    if (sp.get() == 0)
        return 0;
    return static_cast<UIStormBar*>(sp.operator->());
}

}

// The game HUD (kill log + storm bar) closes on game finish and on field leave.
void UISurvivalKillLogDialog::CloseGameHud()
{
    s_bInGame = false;
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return;
    if (pUI->IsDialogOpen((eUIClassID)MS2_UI_SURVIVAL_KILLLOG))
        pUI->CloseDialog((eUIClassID)MS2_UI_SURVIVAL_KILLLOG);
    if (pUI->IsDialogOpen((eUIClassID)MS2_UI_STORMBAR))
        pUI->CloseDialog((eUIClassID)MS2_UI_STORMBAR);
}

// GMS 0x89bbe0
UISurvivalKillLogDialog::UISurvivalKillLogDialog() : m_bPlayInfo(true), m_nFieldId(0)
{
    SetFlag(1, 1);      // not closed by CloseAllDialogs (StateObserver enter)
    SetFlag(3, 1);      // ticked while hidden too (field-leave check)
}

UISurvivalKillLogDialog::~UISurvivalKillLogDialog()
{
}

// GMS 0x89bb70
CString UISurvivalKillLogDialog::GetTypeName()
{
    return "SurvivalKillLogDialog";
}

// GMS 0x89bba0
int UISurvivalKillLogDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    WorldService* pWs = WorldService::GetInstance();
    m_nFieldId = pWs != 0 ? pWs->GetFieldId() : 0;
    return 1;
}

// GMS 0x89bbb0
void UISurvivalKillLogDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// GMS 0x89c580
void UISurvivalKillLogDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull())
        return;
    if (!m_strPendKiller.IsEmpty() || !m_strPendVictim.IsEmpty())
    {
        CStringW strKiller = m_strPendKiller;
        CStringW strVictim = m_strPendVictim;
        m_strPendKiller = L"";
        m_strPendVictim = L"";
        AddKill(strKiller, strVictim);
    }
    RefreshStatus();
    if (!m_bPlayInfo)
        SetVisiblePlayInfo(false);
}

// GMS 0x89bbc0: no own callbacks.
int UISurvivalKillLogDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, (int)nArgs, (void*)this) != 0)
        return 1;
    return 0;
}

// GMS 0x89bce0: dock (3, 0x3c, w / 2). GMS w comes from 0x1168a30 (not identified); 0 here.
void UISurvivalKillLogDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(3, 0x3c, 0);
}

// GMS 0x89c550 ticks "setObserverCount" every 1000 ms (left out). Here: field leave closes the game HUD, and the
// observer window follows the local player's StateObserver (KMS StateObserver opens no survival window).
void UISurvivalKillLogDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;     // closed
    WorldService* pWs = WorldService::GetInstance();
    PCBase* pMe = LocalPC();
    if (pWs == 0 || pMe == 0 || pWs->GetFieldId() != m_nFieldId)
    {
        CloseGameHud();
        return;
    }
    if (!s_bInGame)
        return;
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return;
    if (pMe->GetCurStateId() == kObserverStateId && !pUI->IsDialogOpen((eUIClassID)MS2_UI_SURVIVAL_OBSERVER))
        pUI->OpenDialog((eUIClassID)MS2_UI_SURVIVAL_OBSERVER);
}

// GMS 0x89be30
void UISurvivalKillLogDialog::AddKill(const CStringW& strKiller, const CStringW& strVictim)
{
    PCBase* pMe = LocalPC();
    if (pMe != 0 && !strVictim.IsEmpty() && strVictim == pMe->vfunc_77())
    {
        // GMS 0x89bda0: remember the killer for the result dialog's OnWatch.
        s_killerName = strKiller;
        s_killerId = 0;
        WorldService* pWs = WorldService::GetInstance();
        if (pWs != 0 && !strKiller.IsEmpty())
        {
            MS2Ptr<CProxyGameObject> spKiller = pWs->FindProxyObjectByName(strKiller);
            if (spKiller.get() != 0)
                s_killerId = (__int64)spKiller.operator->()->GetCharacterId();
        }
    }
    if (m_30.IsNull())
    {
        m_strPendKiller = strKiller;
        m_strPendVictim = strVictim;
        return;
    }
    if (pMe == 0)
        return;
    CStringW strMe = pMe->vfunc_77();
    ASObj obj(2);
    obj.SetWStringMember("attackerName", strKiller);
    obj.SetWStringMember("targetName", strVictim);
    obj.SetWStringMember("myName", strMe);
    m_30->Invoke("addKill", Scaleform::GFx::Value(obj.GetValue()));

    // GMS: own kill / own death play a sound and print a system line. The GMS string ids (0x98c ...) are not in the
    // KMS table; the battle-field kill texts (0x973 / 0x972) and sounds are used instead.
    bool bMine = false;
    if (!strKiller.IsEmpty() && strKiller == strMe)
    {
        bMine = true;
        PlaySystemSound(CString("BattleField_Kill"), CString(""));
        if (!strVictim.IsEmpty())
            FUN_1412751b0(FormatStringId<CStringW>(0x973, strVictim), 0x14);
    }
    if (!strVictim.IsEmpty() && strVictim == strMe)
    {
        bMine = true;
        if (!strKiller.IsEmpty())
            FUN_1412751b0(FormatStringId<CStringW>(0x972, strKiller), 0x14);
    }
    if (bMine)
        PlaySystemSound(CString("System_KillPlayer"), CString(""));
}

// GMS 0x89c2a0
void UISurvivalKillLogDialog::RefreshStatus()
{
    if (m_30.IsNull())
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (pMgr == 0)
        return;
    ASArgList args;
    args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)pMgr->m_killA));
    args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)pMgr->m_killB));
    args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)pMgr->m_alive));
    m_30->FUN_1422bb8f0("setStatus", args);
}

// GMS 0x89c500
void UISurvivalKillLogDialog::SetVisiblePlayInfo(bool bVisible)
{
    m_bPlayInfo = bVisible;
    if (m_30.IsNull())
        return;
    ASArgList args;
    args.push_back(Scaleform::GFx::Value(bVisible));
    m_30->FUN_1422bb8f0("setVisiblePlayInfo", args);
}

namespace MushkingUI
{
// Mode 0x19 (GMS 0x89be30).
void KillLog_OnKill(const SurvivalKillFeed& kill)
{
    UISurvivalKillLogDialog* pDlg = FindKillLog();
    if (pDlg != 0)
        pDlg->AddKill(kill.killer, kill.victim);
}

// Mode 0x1a (GMS 0x89c320).
void KillLog_OnAlive()
{
    UISurvivalKillLogDialog* pDlg = FindKillLog();
    if (pDlg != 0)
        pDlg->RefreshStatus();
}

// Mode 0x1b (GMS 0x89c300; bFlag also 0x89c320). The manager already holds every value, so one refresh covers both.
void KillLog_OnCounts(bool bFlag)
{
    (void)bFlag;
    UISurvivalKillLogDialog* pDlg = FindKillLog();
    if (pDlg != 0)
        pDlg->RefreshStatus();
}

// Mode 0x13: the game HUD opens (GMS NotifySurvivalGameStart).
void KillLog_OnGameStart()
{
    UISurvivalKillLogDialog::s_killerId = 0;
    UISurvivalKillLogDialog::s_killerName = L"";
    UISurvivalKillLogDialog::s_bInGame = true;
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return;
    UISurvivalKillLogDialog* pDlg = FindKillLog();
    if (pDlg != 0)
    {
        if (!pUI->IsDialogOpen((eUIClassID)MS2_UI_SURVIVAL_KILLLOG))
            pUI->OpenDialog((eUIClassID)MS2_UI_SURVIVAL_KILLLOG);
        pDlg->SetVisiblePlayInfo(true);
        pDlg->RefreshStatus();
    }
    if (FindStormBar() != 0 && !pUI->IsDialogOpen((eUIClassID)MS2_UI_STORMBAR))
        pUI->OpenDialog((eUIClassID)MS2_UI_STORMBAR);
}
}

#endif   // MS2_HOOK_DLL
