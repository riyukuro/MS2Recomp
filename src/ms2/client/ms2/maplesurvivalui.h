// maplesurvivalui.h - Mushking Royale (Maple Survival) restore: the windows' contract with the manager. NOT recovered
// KMS code (see maplesurvival.h). The windows follow the GMS 2019 x86 client (VAs are that exe's, image base 0x400000);
// the movies are the ui*.gfx files the KMS Gfx pack still ships.
// Branch restore/mushking only.
#pragma once

#include "maplesurvival.h"

// UI class ids. GMS used KMS id + 1 (0x4f6d, 0x4f7b, ...), but KMS reuses those numbers for other dialogs, so the
// restored windows take a free block (no KMS dialog or object returns 0x4fc0-0x4fcf).
enum
{
    MS2_UI_MAPLESURVIVAL = 0x4fc0,             // UIMapleSurvivalDialog, swf "MapleSurvivalDialog" (GMS 0x4f6d)
    MS2_UI_MAPLESURVIVAL_PASS = 0x4fc1,        // UIMapleSurvivalPassDialog, "MapleSurvivalPassDialog" (GMS 0x4f7b)
    MS2_UI_MAPLESURVIVAL_BUYBUNDLE = 0x4fc2,   // UIMapleSurvivalBuyBundleDialog (GMS 0x4f81)
    MS2_UI_MAPLESURVIVAL_SKIN = 0x4fc3,        // UIMapleSurvivalSkinDialog (GMS 0x4f80)
    MS2_UI_SURVIVAL_GAMERESULT = 0x4fc4,       // UISurvivalGameResultDialog (GMS 0x4f6f)
    MS2_UI_SURVIVAL_KILLLOG = 0x4fc5,          // UISurvivalKillLogDialog (GMS 0x4f69)
    MS2_UI_SURVIVAL_OBSERVER = 0x4fc6,         // UISurvivalObserverDialog (GMS 0x4f6b)
    MS2_UI_STORMBAR = 0x4fc7,                  // UIStormBar, "StormBar" (GMS zone UI 0x4f67, vftable 0x175863c)
};

// Manager -> window events. Each is defined in the window's own unit and does nothing when the window is not loaded
// (the manager keeps every value in CMapleSurvivalManager, so a window reads it again on open / load).
namespace MushkingUI
{
    // maplesurvivaldialog.cpp (lobby) and maplesurvivalbuybundledialog.cpp
    void Lobby_OnState();                     // state change (GMS 0x6e2a90 -> 0x79dac0)
    void Lobby_OnSeason();                    // modes 0x12 / 0x15 / 0x16 / 0x18 (0x79d120, 0x79d4b0, 0x79d790, 0x79d320)
    void BuyBundle_OnBundle();                // the pass-bundle GameEvent started / ended
    // maplesurvivalpassdialog.cpp and maplesurvivalskindialog.cpp
    void Pass_OnState();                      // state change (0x79f8e0)
    void Pass_OnSeason();                     // modes 0x16 / 0x18 (0x7a0990)
    void Pass_OnRecord();                     // mode 0x17 (0x7a0da0, 0x7a1120, 0x7a3310)
    void Pass_OnSkins();                      // modes 0x1e-0x20 (0x6e2810 -> 0x7a27e0)
    void Skin_OnSkins();                      // modes 0x1e-0x20 (0x6e2810 -> 0x7a5b90)
    // survivalgameresultdialog.cpp, survivalkilllogdialog.cpp, survivalobserverdialog.cpp, stormbar.cpp
    void Result_Show();                       // mode 0x11 (0x89b290 with CMapleSurvivalManager::m_result)
    void KillLog_OnKill(const SurvivalKillFeed& kill);   // mode 0x19 (0x89be30)
    void KillLog_OnAlive();                   // mode 0x1a (0x89c320, m_alive)
    void KillLog_OnCounts(bool bFlag);        // mode 0x1b (0x89c300, m_killA / m_killB; bFlag: + 0x89c320)
    void KillLog_OnGameStart();               // mode 0x13
    void Observer_OnGameFinish(bool bLocalIn);   // mode 0x14
    void Storm_OnZones();                     // storm modes 0-3 (0x899380, CSurvivalStormManager::m_zones)
    void Storm_OnCountdown(int nSeconds);     // storm mode 6 (0x8992f0); mode 1 goes through Storm_OnZones (0x899350)

    // survivalstormfx.cpp: the storm effects and minimap markers (GMS CStormManager 0x74b000-0x74c400). Called after
    // CSurvivalStormManager::m_zones changed.
    void StormFx_OnAdd(const SurvivalStormZone& zone);      // storm mode 0 (0x74baa0: nif by type, scale, markers)
    void StormFx_OnUpdate(const SurvivalStormZone& zone);   // storm mode 1 (0x74b8d0 -> 0x74b290)
    void StormFx_OnRemove(short id);                        // storm mode 2 (0x74b660)
    void StormFx_OnClear();                                 // storm mode 3 (0x74b730) and field leave
    void StormFx_OnShrinkStart();                           // storm mode 5 (0x74b3c0: Eff_Survival_Storm_B01 once)

    // Each window unit's registration (called from RegisterDialogs).
    void RegisterLobbyDialogs();              // MapleSurvival + BuyBundle
    void RegisterPassDialogs();               // Pass + Skin
    void RegisterGameDialogs();               // GameResult + KillLog + Observer + StormBar
}

// The GameEvent switches (maplesurvival.cpp): kind 0 survival, 1 squad, 2 pass, 3 observer; true while an event turns
// the feature off.
bool IsMapleSurvivalShutdown(int kind);
// GameEventMapleSurvivalPassBundle while it runs (GMS 0x4e76d0): a, b = value1 / value2 (i64), c = value3. False if none.
bool GetMapleSurvivalPassBundle(__int64& a, __int64& b, int& c);

// Called once from the end of CUIService::CreateAllDialogs (MS2-RESTORE: mushking): registers every window.
void MushkingRegisterDialogs();
