// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/mstime.h"
#include <vector>
class CInPacket;
class CMsgBoxData;
class ASButton;
class ASMovieClip;
class ASLabel;
class ASItemSlot;
class UIWorldChampionRewardDialog : public UIDialog {
public:
    UIWorldChampionRewardDialog();
    virtual ~UIWorldChampionRewardDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_48() { return 0x4f68; }
    void OnPacket(CInPacket&);
    void OnSeasonRewardPacket(CInPacket&);
    void OnNextSeasonPacket(CInPacket&);
    void SendWorldChampionMode8();
    void UpdatePageFromStep();
    void FUN_140feb6b0();
    void FUN_140feb870();
    void FUN_140febc40();
    void OnStepClick(const Scaleform::GFx::FunctionHandler::Params&);
    void OnPrevPageClick(const Scaleform::GFx::FunctionHandler::Params&);
    void OnNextPageClick(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140fec310(const Scaleform::GFx::FunctionHandler::Params&);
    bool SendWorldChampionMode9(int, const CMsgBoxData&);
    void EnsureItemSlots(size_t);
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_season;
    CMsTime m_start;
    CMsTime m_end;
    unsigned char m_step, m_maxStep, m_selected, m_page, m_maxPage;
    int m_field;
    std::vector<unsigned int> m_rewardVector;
    std::vector<MS2Ptr<ASMovieClip>> m_stepSlotVecotr;
    std::vector<MS2Ptr<ASButton>> m_stepSlotButtonVecotr;
    MS2Ptr<ASButton> m_prev, m_next, m_move;
    MS2Ptr<ASLabel> m_title;
    MS2Ptr<ASMovieClip> m_area;
    std::vector<MS2Ptr<ASItemSlot>> m_items;
};
MS2_CHECK_SIZE(UIWorldChampionRewardDialog, 0x260);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_season, 0x178);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_start, 0x180);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_step, 0x1a0);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_field, 0x1a8);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_rewardVector, 0x1b0);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_title, 0x228);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_items, 0x248);
