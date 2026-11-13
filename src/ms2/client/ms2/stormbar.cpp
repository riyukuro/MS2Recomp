// stormbar.cpp - Mushking Royale restore: UIStormBar. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: stormbar
// MS2-NO-EXE: 0x140db5399 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include <math.h>

#include "ms2/client/ms2/stormbar.h"
#include "ms2/client/ms2/survivalkilllogdialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"

namespace
{
UIStormBar* FindStormBar()
{
    CUIService* pUI = CUIService::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIDialog> sp = pUI->FindDialog((eUIClassID)MS2_UI_STORMBAR);
    if (sp.get() == 0)
        return 0;
    return static_cast<UIStormBar*>(sp.operator->());   // the service keeps the dialog alive
}

int RoundInt(float f)
{
    return (int)floorf(f + 0.5f);
}
}

// GMS 0x899300
UIStormBar::UIStormBar()
    : m_bZone(false), m_nCountdown(0), m_nDist(0), m_nCurR(0), m_nNextR(0), m_nFieldId(0)
{
    for (int i = 0; i < 3; ++i)
    {
        m_cur[i] = 0.0f;
        m_next[i] = 0.0f;
    }
    SetFlag(1, 1);      // not closed by CloseAllDialogs (StateObserver enter)
    SetFlag(3, 1);      // ticked while hidden too (field-leave check)
}

UIStormBar::~UIStormBar()
{
}

// GMS 0x8992c0
CString UIStormBar::GetTypeName()
{
    return "StormBar";
}

int UIStormBar::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    WorldService* pWs = WorldService::GetInstance();
    m_nFieldId = pWs != 0 ? pWs->GetFieldId() : 0;
    return 1;
}

// GMS 0x899560
void UIStormBar::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull() || m_nCountdown == 0)
        return;
    m_30->Invoke("setStopWatch", m_nCountdown);
    m_nCountdown = 0;
}

// GMS 0x8994a0: dock (3, 0x19, -(w / 2 + 0x32)). GMS w comes from 0x1168a30 (not identified); 0 here.
void UIStormBar::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(3, 0x19, -0x32);
}

// GMS 0x8992f0 stores the countdown for OnLoadComplete; when the movie is already loaded it is shown at once.
void UIStormBar::SetCountdown(int nSeconds)
{
    if (!m_30.IsNull() && nSeconds != 0)
    {
        m_30->Invoke("setStopWatch", nSeconds);
        m_nCountdown = 0;
        return;
    }
    m_nCountdown = nSeconds;
}

// GMS 0x899380: current circle (radius, centre), next circle; dist = round(max(0, |cur - next| + curR - nextR)).
void UIStormBar::SetZone(int nCurR, const float* pCur, int nNextR, const float* pNext)
{
    m_nCurR = nCurR;
    m_nNextR = nNextR;
    for (int i = 0; i < 3; ++i)
    {
        m_cur[i] = pCur[i];
        m_next[i] = pNext[i];
    }
    float dx = m_cur[0] - m_next[0];
    float dy = m_cur[1] - m_next[1];
    float dz = m_cur[2] - m_next[2];
    float d = sqrtf(dx * dx + dy * dy + dz * dz) + (float)m_nCurR - (float)m_nNextR;
    m_nDist = RoundInt(d > 0.0f ? d : 0.0f);
    m_bZone = true;
}

// GMS 0x899640: "update"(player distance outside the next circle, next radius, circle distance). Here also: field
// leave closes the game HUD.
void UIStormBar::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;     // closed
    WorldService* pWs = WorldService::GetInstance();
    PCBase* pMe = pWs != 0 ? (PCBase*)pWs->GetLocalPlayer() : 0;
    if (pWs == 0 || pMe == 0 || pWs->GetFieldId() != m_nFieldId)
    {
        UISurvivalKillLogDialog::CloseGameHud();
        return;
    }
    if (m_30.IsNull() || !m_bZone)
        return;
    NiPoint3 pos = pMe->vfunc_18();
    float dx = pos.x - m_next[0];
    float dy = pos.y - m_next[1];
    float d = sqrtf(dx * dx + dy * dy) - (float)m_nNextR;
    ASArgList args;
    args.push_back(Scaleform::GFx::Value((double)RoundInt(d > 0.0f ? d : 0.0f)));
    args.push_back(Scaleform::GFx::Value((double)m_nNextR));
    args.push_back(Scaleform::GFx::Value((Scaleform::SInt32)m_nDist));
    m_30->FUN_1422bb8f0("update", args);
}

namespace MushkingUI
{
// Storm modes 0-3 (GMS 0x899380 with CSurvivalStormManager::m_zones). The bar shows the first zone (lowest id):
// radius / pos = current circle, previewRadius / preview = next circle.
void Storm_OnZones()
{
    UIStormBar* pBar = FindStormBar();
    if (pBar == 0)
        return;
    CSurvivalStormManager* pMgr = CSurvivalStormManager::GetInstance();
    if (pMgr == 0 || pMgr->m_zones.empty())
    {
        pBar->ClearZone();
        return;
    }
    const SurvivalStormZone& z = pMgr->m_zones.begin()->second;
    pBar->SetZone(z.radius, z.pos, z.previewRadius, z.preview);
}

// Storm mode 6 (GMS 0x8992f0).
void Storm_OnCountdown(int nSeconds)
{
    UIStormBar* pBar = FindStormBar();
    if (pBar != 0)
        pBar->SetCountdown(nSeconds);
}
}

#endif   // MS2_HOOK_DLL
