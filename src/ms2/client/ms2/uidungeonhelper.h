// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
// Dungeon search "united reward" panel (weekly/daily reward gauge and item slots) and its reward item slot.
#pragma once
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cptred.h"
#include <vector>
class CMsgBoxData;
class Unk_DhButton;
class Unk_DhRewardAmount;

// The AS item slot of a reward icon; carries the meso/exp amounts shown in its tooltip.
class ASWeeklyRewardItemSlot : public ASItemSlot {
public:
    ASWeeklyRewardItemSlot(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASWeeklyRewardItemSlot();
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);
    void FUN_140e12780(__int64 nMeso, __int64 nExp);
    void FUN_140e12bf0();
private:
    MS2_LAYOUT_FRIEND;
    __int64 m_nMeso;
    __int64 m_nExp;
};
MS2_CHECK_SIZE(ASWeeklyRewardItemSlot, 0xa8);
MS2_CHECK_OFFSET(ASWeeklyRewardItemSlot, m_nMeso, 0x98);

class UIDungeonSearchUnitedReward : public CPtred {
public:
    UIDungeonSearchUnitedReward();
    virtual ~UIDungeonSearchUnitedReward();
    bool Init(MS2Ptr<ASMovieClip> root);
    void FUN_140e13c00();
    void FUN_140e142f0();
    void FUN_140e14400(const Scaleform::GFx::FunctionHandler::Params& params);
    bool SendRoomDungeon(int nResult, const CMsgBoxData& data);
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_root;                                 // +0x18
    std::vector<MS2Ptr<ASMovieClip> > m_points;                 // +0x28
    std::vector<MS2Ptr<ASWeeklyRewardItemSlot> > m_slots;       // +0x40
    MS2Ptr<ASMovieClip> m_gauge;                                // +0x58
    MS2Ptr<ASTextField> m_daily;                                // +0x68
    MS2Ptr<ASTextField> m_weekly;                               // +0x78
    MS2Ptr<Unk_DhButton> m_resetButton;                         // +0x88
};
MS2_CHECK_SIZE(UIDungeonSearchUnitedReward, 0x98);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_root, 0x18);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_points, 0x28);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_slots, 0x40);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_gauge, 0x58);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_daily, 0x68);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_weekly, 0x78);
MS2_CHECK_OFFSET(UIDungeonSearchUnitedReward, m_resetButton, 0x88);
