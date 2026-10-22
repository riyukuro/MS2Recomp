// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include <vector>
class CInPacket;
class CMsgBoxData;
class Unk_WcButton;
class Unk_WcClip;
class Unk_WcTitle;
class Unk_WcItemSlot;
class Unk_WcDate {
public:
    Unk_WcDate();
    Unk_WcDate(__int64);
private: __int64 p0; __int64 p8;
};
MS2_CHECK_SIZE(Unk_WcDate, 0x10);
class UIWorldChampionRewardDialog : public UIDialog {
public:
    UIWorldChampionRewardDialog();
    virtual ~UIWorldChampionRewardDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_48() { return 0x4f68; }
    void FUN_140feb1b0(CInPacket&);
    void FUN_140feb2c0(CInPacket&);
    void FUN_140feb440(CInPacket&);
    void SendWorldChampionMode8();
    void FUN_140feb630();
    void FUN_140feb6b0();
    void FUN_140feb870();
    void FUN_140febc40();
    void FUN_140fec200(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140fec260(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140fec2b0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140fec310(const Scaleform::GFx::FunctionHandler::Params&);
    bool SendWorldChampionMode9(int, const CMsgBoxData&);
    void FUN_140fec540(size_t);
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_season;
    Unk_WcDate m_start;
    Unk_WcDate m_end;
    unsigned char m_step, m_maxStep, m_selected, m_page, m_maxPage;
    int m_field;
    std::vector<unsigned int> m_rewardVector;
    std::vector<MS2Ptr<Unk_WcClip>> m_stepSlotVecotr;
    std::vector<MS2Ptr<Unk_WcButton>> m_stepSlotButtonVecotr;
    MS2Ptr<Unk_WcButton> m_prev, m_next, m_move;
    MS2Ptr<Unk_WcTitle> m_title;
    MS2Ptr<Unk_WcClip> m_area;
    std::vector<MS2Ptr<Unk_WcItemSlot>> m_items;
};
MS2_CHECK_SIZE(UIWorldChampionRewardDialog, 0x260);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_season, 0x178);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_start, 0x180);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_step, 0x1a0);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_field, 0x1a8);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_rewardVector, 0x1b0);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_title, 0x228);
MS2_CHECK_OFFSET(UIWorldChampionRewardDialog, m_items, 0x248);
