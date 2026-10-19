// Recovered UIPCInfoDialog (UI type 0x4ec8, movie "MyInfoDialog"): the character information dialog of another player
// (equipment, gems, stats, profile, guild, wedding); UIMyInfoDialog derives from it. RTTI .?AVUIPCInfoDialog@@
// (0x143a87c58): vftables 0x142eed528 (107 slots), IMessageListener +0x18 0x142eed888, UIUGCEventListener +0x178
// 0x142eed898, IUIAvatarEventListener +0x180 0x142eed8e0; 0x1e8 bytes (sized delete in 0x141339150). Slots 84-106 are
// new here; their names and every member name are invented (from the AS method names and the PCInfo fields passed).
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/pcinfo.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"        // IUIAvatarEventListener

class ASButton;
class UIAvatarBase;
class CInPacket;
class CMsgBoxData;
class PC;
class ASData;
class ASArray;
class CPCDataPack;

class UIPCInfoDialog : public UIDialog, public UIUGCEventListener, public IUIAvatarEventListener
{
public:
    UIPCInfoDialog();                                                   // 0x14132bc00
    virtual ~UIPCInfoDialog();                                          //  0 0x14132bea0 (??_G 0x141339150)
    virtual CString vfunc_1();                                          //  1 0x14132c030 "MyInfoDialog"
    virtual int vfunc_65();                                             // 65 0x14132d500
    virtual void vfunc_67();                                            // 67 0x14132d530 close: unregister, clear
    virtual void vfunc_26();                                            // 26 0x14132d600
    virtual void vfunc_79(void* pPacket);                               // 79 0x14132d630 packet 0x78 (the pc record)
    virtual void vfunc_ugc_1(void* nCharacterId, CString strPath);      // UGC 1 0x14132d900 profile image uploaded
    virtual int vfunc_46();                                             // 46 0x14132da70
    virtual void OnLoadComplete();                                      // 22 0x14132dc20
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);           // IMessageListener 0 0x14132e4d0
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x14132e850
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14132e890
    virtual void vfunc_84();                                            // 84 0x14132fb40 show the record (or clear)
    virtual void vfunc_85();                                            // 85 0x14132fec0 today memo
    virtual void vfunc_86();                                            // 86 0x14132ff30 the stat lists
    virtual void vfunc_87();                                            // 87 0x1413322c0 the stat points
    virtual void vfunc_88(int nTab);                                    // 88 0x141332e00 show the equip / gem bag
    virtual void vfunc_89();                                            // 89 0x141332fc0 clear both bags
    virtual void vfunc_90(int nTab);                                    // 90 0x141333000 "onChangeTab"
    virtual void vfunc_91(int nStat);                                   // 91 0x141333060 "OnAddStatPoint" (empty)
    virtual void vfunc_92();                                            // 92 0x141333070 reset confirmed (empty)
    virtual int vfunc_93();                                             // 93 0x141333080 can reset the stat points (0)
    virtual void vfunc_94(const unsigned int& nJob);                    // 94 0x141333180 job image and name
    virtual void vfunc_95(const unsigned short& nLevel);                        // 95 0x141333340 level
    virtual void vfunc_96(int nTitle, const ATL::CAtlArray<unsigned int>& aTitles);   // 96 0x141333420 title combo
    virtual void vfunc_97(const CStringW& strName);                     // 97 0x1413338e0 "setName"
    virtual void vfunc_98(const CStringW& strProfile);                  // 98 0x141333980 "setProfile"
    virtual void vfunc_99(const CStringW& strMemo);                     // 99 0x141333bb0 "setTodayMemo"
    virtual void vfunc_100(int nGender, unsigned int nSkin);            // 100 0x141333cb0 character image
    virtual void vfunc_101(const CStringW& strAddress);                 // 101 0x141333dd0 home address
    virtual void vfunc_102(int nPoint, int nRank);                      // 102 0x141334000 interior points
    virtual void vfunc_103(const CStringW& strGuild, const CStringW& strRank);   // 103 0x141334120 guild
    virtual void vfunc_104(int nTrophy);                                // 104 0x141334320 "setTrophy"
    virtual void vfunc_105(const int& nLevel);                          // 105 0x141334390 adventure level
    virtual void vfunc_106();                                           // 106 0x141334550 wedding state
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x141337040
    virtual void vfunc_16();                                            // 16 0x141337380
    virtual bool vfunc_17();                                            // 17 0x1413373b0
    virtual int vfunc_o178_1(void* pAvatar);                            // IUIAvatarEventListener 1 0x1413373f0 model loaded
    virtual int vfunc_48() { return 0x4ec8; }                           // 48 (COMDAT 0x141339190)

    int FUN_14132c080(__int64 nCharacterId);                            // 0x14132c080 request the record (0 sent, 1 cached, 2 shown)
    void FUN_14132c130(PC* pPC);                                        // 0x14132c130 show a pc of the field
    void FUN_14132c330(CPCDataPack* pPack);                             // 0x14132c330 build the record from the packet
    void FUN_14132ed50(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x14132ed50 "m_myNews" click
    bool FUN_14132ee90(int nResult, const CMsgBoxData& data);           // 0x14132ee90 reset stat points answer
    void FUN_14132eed0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x14132eed0 stat tooltip
    void FUN_14132f020(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x14132f020 remaining point tooltip
    void FUN_14132f5d0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x14132f5d0 wedding tooltip
    void FUN_14132fa50(const CStringW& strAddress);                     // 0x14132fa50
    void FUN_14132fa90();                                               // 0x14132fa90 refresh the profile image
    void FUN_14132faf0(const CStringW& strProfile);                     // 0x14132faf0
    void FUN_141333090();                                               // 0x141333090 clear
    __int64 FUN_141334890();                                            // 0x141334890 offense score
    __int64 FUN_141335290();                                            // 0x141335290 defense score
    __int64 FUN_141335780();                                            // 0x141335780 mean attack
    __int64 FUN_141335830(int nStat);                                   // 0x141335830 bonus of a stat
    float FUN_141335940(int nStat, float* pfBase, float* pfBonus, float* pfTotal);   // 0x141335940 basic stat
    float FUN_141335d20(int nStat, bool bTenth, float* pfBase, float* pfBonus, float* pfTotal);   // 0x141335d20 special stat
    Scaleform::GFx::Value FUN_141335e00(int nStat, int nContainer, int nLabel);    // 0x141335e00 basic stat row
    Scaleform::GFx::Value FUN_1413363d0(int nStat, int nContainer, int nLabel);    // 0x1413363d0 special stat row
    Scaleform::GFx::Value FUN_1413369a0(unsigned int nContainer, int nLabel);      // 0x1413369a0 shield row
    CStringW FUN_141336c90();                                           // 0x141336c90 profile image path
    int FUN_141336de0(int nTab);                                        // 0x141336de0 tab -> equip kind (6 = none)
    void FUN_141336e40(ASArray& aTabs, int nTab, const CStringW& strLabel, const CStringW& strFrame,
                       const CStringW& strTooltip);                     // 0x141336e40 add a tab
    void FUN_141337560();                                               // 0x141337560 "loadRenderTarget"
    void FUN_1413375c0();                                               // 0x1413375c0 "unloadRenderTarget"
    
    MS2_LAYOUT_FRIEND;
    __int64 m_188;                                                      // +0x188 the character asked for
    MS2Ptr<PCInfo> m_spInfo;                                            // +0x190
    CString m_strEquipBag;                                              // +0x1a0 "PcInfoDialog.Equip"
    CString m_strGemBag;                                                // +0x1a8 "PcInfoDialog.Gem"
    int m_nTab;                                                         // +0x1b0
    MS2Ptr<ASButton> m_spMyNews;                                        // +0x1b8 "m_myNews"
    MS2Ptr<UIAvatarBase> m_spAvatar;                                    // +0x1c8
    __int64 m_1d8;                                                      // +0x1d8 the character of the last request
    Unk_IntervalTimer m_1e0;                                              // +0x1e0 request timer (5 s)
};
MS2_CHECK_SIZE(UIPCInfoDialog, 0x1e8);
MS2_CHECK_OFFSET(UIPCInfoDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIPCInfoDialog, m_spInfo, 0x190);
MS2_CHECK_OFFSET(UIPCInfoDialog, m_nTab, 0x1b0);
MS2_CHECK_OFFSET(UIPCInfoDialog, m_spAvatar, 0x1c8);
MS2_CHECK_OFFSET(UIPCInfoDialog, m_1e0, 0x1e0);
