// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPTeamFlagGagueDialog (UI type 0x4ed4, "PvPTeamFlagGagueDialog"):
// the red team's flag gauge of the team PvP; shown for 2 seconds after each change. Class declared in uipvpteamflaggaguedialog.h.
// MS2-UNIT: ?\uipvpteamflaggaguedialog.cpp
// MS2-RANGE: 0x141344ab0-0x141345070 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpteamflaggaguedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uipvpteamflaggaguedialog.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

unsigned FUN_140869420();                                               // millisecond clock

// UIPvPTeamFlagGagueDialog (uipvpteamflaggaguedialog.h): RTTI .?AVUIPvPTeamFlagGagueDialog@@, vftables (primary) and
// +0x18 (IMessageListener).

// @0x141344ab0
UIPvPTeamFlagGagueDialog::UIPvPTeamFlagGagueDialog()
{
    FUN_141925e70(1, 1);
    m_nPercent = 0;
    m_nShownTick = 0;
    m_nLastPercent = -1;
    m_bShown = false;
}

// @0x141344b50
UIPvPTeamFlagGagueDialog::~UIPvPTeamFlagGagueDialog()
{
}

// @0x141344b90
CString UIPvPTeamFlagGagueDialog::vfunc_1()
{
    return "PvPTeamFlagGagueDialog";
}
MS2_REPLACE_METHOD(0x141344B90, UIPvPTeamFlagGagueDialog, vfunc_1, 61, 0x0DF3FB13);

// @0x141344be0
void UIPvPTeamFlagGagueDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_bShown = true;
    FUN_141344d50(m_nPercent - 1);
}
MS2_REPLACE_METHOD(0x141344BE0, UIPvPTeamFlagGagueDialog, OnLoadComplete, 61, 0xDFD85496);

// @0x141344c30
void UIPvPTeamFlagGagueDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        pEntity->vfunc_2(1, 0, 0x14a);
}
MS2_REPLACE_METHOD(0x141344C30, UIPvPTeamFlagGagueDialog, vfunc_43, 167, 0x7C5D7D66);

// @0x141344ce0
void UIPvPTeamFlagGagueDialog::vfunc_72()
{
    if (!m_30)
        return;
    if (!m_bShown)
        return;
    if (m_nShownTick + 2000U < FUN_140869420())
        FUN_141344f20();
}
MS2_REPLACE_METHOD(0x141344CE0, UIPvPTeamFlagGagueDialog, vfunc_72, 101, 0xCE26E10C);

// @0x141344d50
void UIPvPTeamFlagGagueDialog::FUN_141344d50(int nPercent)
{
    nPercent = nPercent + 1;
    if (!m_30) {
        m_nPercent = nPercent;
        m_nLastPercent = nPercent;
    } else {
        m_nShownTick = FUN_140869420();
        if (nPercent < 1)
            nPercent = 1;
        if (nPercent > 0x65)
            nPercent = 0x65;
        if (!m_bShown) {
            vfunc_8(1);
            m_bShown = true;
        }
        m_30->Invoke("setRedTeamGaguePercent", nPercent);
        int nArrow = 0;
        if (m_nLastPercent >= 0) {
            if (m_nLastPercent < nPercent)
                nArrow = 2;
            else if (m_nLastPercent > nPercent)
                nArrow = 1;
        }
        m_30->Invoke("setArrow", nArrow);
        m_nLastPercent = nPercent;
    }
}
MS2_REPLACE_METHOD(0x141344D50, UIPvPTeamFlagGagueDialog, FUN_141344d50, 453, 0x3878F040);

// @0x141344f20
void UIPvPTeamFlagGagueDialog::FUN_141344f20()
{
    vfunc_8(0);
    m_bShown = false;
    m_nLastPercent = -1;
}
MS2_REPLACE_METHOD(0x141344F20, UIPvPTeamFlagGagueDialog, FUN_141344f20, 59, 0x57251EE9);

// @0x141344fb0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
