// survivalobserverdialog.cpp - Mushking Royale restore: UISurvivalObserverDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: survivalobserverdialog
// MS2-NO-EXE: 0x140db5398 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/survivalobserverdialog.h"
#include "ms2/client/ms2/survivalkilllogdialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/opcodes.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- KMS helpers (declarations as their other callers have them) ----
CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);   // GMS 0xa1fd00
void FUN_140710590(COutPacket& packet);                                  // send
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);             // a new message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show it
void* FUN_14025e7c0();                                                   // the input key handler

namespace
{
const int kObserverStateId = 0x3f;          // PCBase state: StateObserver
const DWORD kLeaveDelayMs = 10000;          // GMS: constants +0xb5fc (value not known; 10 s assumed)

CStringW Key(const wchar_t* key)
{
    return GetStringCommonByKey(CStringW(key));
}

PCBase* LocalPC()
{
    WorldService* pWs = WorldService::GetInstance();
    if (pWs == 0)
        return 0;
    return (PCBase*)pWs->GetLocalPlayer();
}

void InvokeText(MS2Ptr<AScript>& sp, const char* szMethod, const CStringW& str)
{
    ASArgList args;
    args.push_back(Scaleform::GFx::Value((const wchar_t*)str));
    sp->FUN_1422bb8f0(szMethod, args);
}
}

// GMS 0x89ce20
UISurvivalObserverDialog::UISurvivalObserverDialog() : m_dwLeaveAt(0), m_nFieldId(0)
{
    SetFlag(1, 1);      // not closed by CloseAllDialogs (StateObserver enter)
    SetFlag(3, 1);      // ticked while hidden too (leave timer)
}

UISurvivalObserverDialog::~UISurvivalObserverDialog()
{
}

// GMS 0x89c720
CString UISurvivalObserverDialog::GetTypeName()
{
    return "SurvivalObserverDialog";
}

// GMS 0x89c7a0: RequestMoveField u8 1 (back to the lobby field). KMS has no send helper for it (the same packet is built
// inline in uidarkstreamresultdialog.cpp).
void UISurvivalObserverDialog::LeaveField()
{
    COutPacket packet(static_cast<int>(SendOp::RequestMoveField), 0);
    packet.WriteUInt8(1);
    FUN_140710590(packet);
}

// GMS slot 14 (0x89c9e0): Escape asks before leaving (the dialog has flag 1, so the base never closes it).
int UISurvivalObserverDialog::vfunc_13()
{
    if (vfunc_55() == 0 && ((class CInputKeyHandler*)FUN_14025e7c0())->IsEscapePressed())
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(Key(L"s_maple_survival_ui_observer_exit"), 1);
        if (box.get() != 0)
        {
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UISurvivalObserverDialog::OnExitBox));
            FUN_140d73c60(box);
        }
        return 1;
    }
    return UIDialog::vfunc_13();
}

// GMS 0x89c830: OK -> SpectateMushtopia u8 3 (stop watching), then leave the field.
bool UISurvivalObserverDialog::OnExitBox(int nResult, const CMsgBoxData& box)
{
    (void)box;
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::SpectateMushtopia), 0);
        packet.WriteUInt8(3);
        FUN_140710590(packet);
        LeaveField();
    }
    return true;
}

// GMS 0x89cb10
void UISurvivalObserverDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull())
        return;
    InvokeText(m_30, "initData", m_strName);
    if (!m_strMessage.IsEmpty())
        InvokeText(m_30, "setGameMessage", m_strMessage);
}

// GMS slot 65: open, then visible. The watched name is the local player's last killer (the target of the result
// dialog's OnWatch); StateObserver's own target is not reachable from here.
int UISurvivalObserverDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    vfunc_8(1);
    WorldService* pWs = WorldService::GetInstance();
    m_nFieldId = pWs != 0 ? pWs->GetFieldId() : 0;
    m_dwLeaveAt = 0;
    m_strMessage = L"";
    ChangePlayerName(UISurvivalKillLogDialog::s_killerName);
    return 1;
}

// GMS 0x89c760
void UISurvivalObserverDialog::vfunc_67()
{
    m_dwLeaveAt = 0;
    UIDialog::vfunc_67();
}

// GMS 0x89c9a0: the leave timer. (GMS 0x89c8e0 also starts it when no party member is left alive: left out.) Here also:
// close when the local player leaves StateObserver or the field.
void UISurvivalObserverDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;     // closed
    if (m_dwLeaveAt != 0 && (int)(GetTickCount() - m_dwLeaveAt) >= 0)
    {
        m_dwLeaveAt = 0;
        LeaveField();
    }
    WorldService* pWs = WorldService::GetInstance();
    PCBase* pMe = LocalPC();
    if (pWs == 0 || pMe == 0 || pWs->GetFieldId() != m_nFieldId || pMe->GetCurStateId() != kObserverStateId)
    {
        CUIService* pUI = CUIService::GetInstance();
        if (pUI != 0)
            pUI->CloseDialog((eUIClassID)MS2_UI_SURVIVAL_OBSERVER);
    }
}

// GMS 0x89cb90
void UISurvivalObserverDialog::ChangePlayerName(const CStringW& strName)
{
    m_strName = strName;
    if (m_30.IsNull())
        return;
    InvokeText(m_30, "changePlayerName", m_strName);
}

// GMS 0x89cc30
void UISurvivalObserverDialog::SetGameMessage(const CStringW& strText)
{
    m_strMessage = strText;
    if (m_30.IsNull())
        return;
    InvokeText(m_30, "setGameMessage", m_strMessage);
}

// GMS 0x89ccc0: start the leave timer; a solo watcher gets a notice, a squad watcher whose squad is still in
// (bLocalIn) gets the squad text in the window. (GMS tests a mode flag at 0x4ab450 that is not identified; bLocalIn
// stands in for it.)
void UISurvivalObserverDialog::OnGameFinish(bool bLocalIn)
{
    if (vfunc_55() != 0)
        return;     // not open
    m_dwLeaveAt = GetTickCount() + kLeaveDelayMs;
    if (m_dwLeaveAt == 0)
        m_dwLeaveAt = 1;
    if (bLocalIn)
        SetGameMessage(Key(L"s_maple_survival_squad_finish_observer"));
    else
        ShowSystemNotice(Key(L"s_maple_survival_finish_observer"), 1, 1);
}

namespace MushkingUI
{
// Mode 0x14 (GMS NotifySurvivalGameFinish): the game HUD closes; the observer window starts its leave timer.
void Observer_OnGameFinish(bool bLocalIn)
{
    UISurvivalKillLogDialog::CloseGameHud();
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return;
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_SURVIVAL_OBSERVER);
    if (sp.get() == 0)
        return;
    static_cast<UISurvivalObserverDialog*>(sp.operator->())->OnGameFinish(bLocalIn);
}
}

#endif   // MS2_HOOK_DLL
