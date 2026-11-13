// maplesurvival.h - Mushking Royale (Maple Survival) restore for the KMS client. NOT recovered KMS code: the KMS 2022
// client ships the feature's notify classes and GameEvent switches but not the manager, the storm manager or the
// tables. The design follows the unprotected GMS 2019 x86 client (VAs below are that exe's, image base 0x400000).
// Branch restore/mushking only; master stays the byte-matched recomp.
#pragma once

#include <afx.h>
#include <map>
#include <vector>

class CInPacket;
class CMsgBoxData;

// The restored client's survival requests go out on this op. KMS has no survival send op: SendOp ends at HomeBlock
// 0xC1 and no KMS code path builds a 0xC2 packet; the fork server takes it.
enum { MS2_SENDOP_MAPLESURVIVAL = 0xC2 };
// Recv ops (KMS RecvOp): Survival 0x119 and SurvivalEvent (the storm) 0x116.
enum { MS2_RECVOP_SURVIVAL = 0x119, MS2_RECVOP_SURVIVALEVENT = 0x116 };

// ---- tables (GMS loaders 0x6268e0, 0x626d20, 0x626fa0, 0x6286b0, 0x627460) ----
struct SurvivalLevelData { int level; __int64 reqExp; int grade; };
struct SurvivalLevelReward { int level; int itemId[3]; int itemRank[3]; int itemCount[3]; };
struct SurvivalPassRewardEntry { CStringW type; CStringW id; CStringW value; CStringW count; };
struct SurvivalPassReward { int id; int level; bool bSpecial; SurvivalPassRewardEntry entry[2]; };
struct SurvivalOpenPeriod { int id; int levelId; int rewardId; CStringW startTime; CStringW endTime; int passPrice; };
struct SurvivalSkinInfo { int id; CStringW type; CString imagePath; CString mainImagePath; int value1; int effectId; int effectLevel; };

class CMapleSurvivalTable
{
public:
    static CMapleSurvivalTable& Get();
    void Load();   // every file is optional: the KMS client pack has none of them (the server pack does)
    std::map<int, SurvivalLevelData> m_levels;
    std::map<int, SurvivalLevelReward> m_levelRewards;
    std::map<int, SurvivalPassReward> m_passRewards;
    std::map<int, SurvivalPassReward> m_passRewardsPaid;
    std::map<int, SurvivalOpenPeriod> m_periods;
    std::map<int, SurvivalSkinInfo> m_skins;
    bool m_bLoaded;
private:
    CMapleSurvivalTable() : m_bLoaded(false) {}
};

// ---- the manager (GMS CMapleSurvivalManager, ctor 0x6e2dc0, OnPacket 0x6e3110) ----
struct SurvivalSkinSlot { int equipped; std::vector<std::pair<int, __int64> > skins; };
struct SurvivalKillFeed { int type; CStringW killer; CStringW victim; int weapon; int value; };
// mode 0x11 (GMS reads items with 0x45c7c0: i32 id, i16, i32, bool x 4 at +0x1c/+0x1e/+0x1d/+0x1f)
struct SurvivalResultItem { int id; short rarity; int count; bool flag[4]; };
struct SurvivalGameResult { int r[16]; float f[4]; std::vector<SurvivalResultItem> items; };
// mode 0x16 (the last packet with active == 1)
struct SurvivalSeasonInfo { int id; int active; __int64 time; CStringW name; int value; int extra[6]; };

class CMapleSurvivalManager
{
public:
    static CMapleSurvivalManager* GetInstance();
    void OnPacket(CInPacket& packet);
    int GetState() const { return m_state; }

    // requests (GMS send sites, op 0xC2, u8 mode first)
    void RequestMatch();                         // mode 0
    void AcceptMatch();                          // mode 1
    void CancelMatch();                          // mode 2
    void RefuseMatch(unsigned char reason);      // mode 3
    bool RequestSquadMatch();                    // mode 4 (GMS 0x6e21f0: false = refused with a notice)
    void RequestSeasonRecord();                  // mode 5 (throttled 1000 ms)
    void AcceptRejoin();                         // mode 6
    void EquipSkin(unsigned char slot, int skin);   // mode 8
    void RequestRefresh();                       // mode 0x12 (throttled 500 ms)
    void BuyPass(bool bPaid, __int64 price);     // mode 0x22
    void ClaimRewards(int a, int b);             // mode 0x23

    bool OnMatchBox(int result, const CMsgBoxData& box);    // GMS 0x6e2110
    bool OnRejoinBox(int result, const CMsgBoxData& box);   // GMS 0x6e2140

    int m_state;            // GMS +4: 0 idle, 1 matching, 2 matched
    int m_seasonId;         // +8
    int m_seasonValue;      // +0xc
    __int64 m_exp;          // +0x10
    int m_level;            // +0x18
    int m_1a;               // +0x1a
    int m_1c;               // +0x1c
    int m_1e;               // +0x1e
    int m_20;               // +0x20
    SurvivalGameResult m_result;          // mode 0x11
    SurvivalSeasonInfo m_season;          // mode 0x16
    __int64 m_record0;                    // mode 0x17 first i64
    int m_record1;                        // mode 0x17 first i32
    __int64 m_record7;                    // mode 0x17 last i64
    int m_alive;                          // mode 0x1a (GMS kill log +0x120)
    int m_killA, m_killB;                 // mode 0x1b (GMS kill log +0x118 / +0x11c)
    int m_passGain[4];                    // mode 0x23
    std::vector<__int64> m_finishList;   // +0x30
    SurvivalSkinSlot m_skinSlots[3];     // +0x3c, 0x34 each
    std::vector<SurvivalKillFeed> m_killFeed;
private:
    CMapleSurvivalManager();
    void SetState(int nState);           // GMS 0x6e2a90
    void ShowMatchBox(__int64 charId, bool bShort, bool bRejoin);
    void RefreshSkins();                 // GMS 0x6e2810
};

// ---- the storm (GMS SurvivalEvent recv 0xbe4750, zone helpers 0x74b220..0x74baa0) ----
// Storm mode 0 (GMS 0x74baa0): radius / pos = the current circle, previewRadius / preview = the next one. Mode 1
// (0x74b8d0) sets radius and pos.
struct SurvivalStormZone { short id; short radius; short step; float pos[3]; short previewRadius; float preview[3]; };

class CSurvivalStormManager
{
public:
    static CSurvivalStormManager* GetInstance();
    void OnPacket(CInPacket& packet);
    std::map<short, SurvivalStormZone> m_zones;
    bool m_bStormLoaded;
private:
    CSurvivalStormManager() : m_bStormLoaded(false) {}
};

// Called once from CGameApp::InitInstance (the one edit to matched code, marked MS2-RESTORE: mushking).
void MushkingRestoreInit();
