// Reward / fame-contents HUD notifications and the roulette dialog (one fused exe unit with two header-static groups).
// Recovered from MapleStory2.exe KMS2_DEV x64. Helper names are inferred from the AS member names they fill.
#pragma once
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
class PC; class NotifyObject; class CInPacket; class Unk_RNItemRef; class Unk_RNAchieve;

// HUD queue of "reward" toasts (exp, meso, items, titles, skills, fishing, ...). Each Push*/Show* builds an AS object
// (type/msg/icon/...) and hands it to FUN_141ac1fe0, which sends "appendReward" or queues it until the movie is ready.
class UIRewardNotify : public UIHeadUpDisplay {
public:
    UIRewardNotify();                                                                   // 0x141abe1d0
    virtual ~UIRewardNotify();                                                          // 0 0x141ac3930
    virtual CString vfunc_1();                                                          // 1 0x141abe240
    virtual void vfunc_2();                                                             // 2 0x141abe290
    virtual void vfunc_3();                                                             // 3 0x141abe2d0
    virtual void vfunc_15();                                                            // 15 0x141abe740
    virtual void OnLoadInit();                                                          // 20 0x141abe300
    virtual void vfunc_26();                                                            // 26 0x141abe4c0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141abe8b0
    virtual void vfunc_41(const Scaleform::GFx::Value& root);                           // 41 0x141ac2120
    virtual void vfunc_43();                                                            // 43 0x141abe680
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x141ac1fa0
    virtual int vfunc_48();                                                             // 48 0x141ac3fb0

    void FUN_141abea10(NotifyObject* pNotice);                                          // "NotifyLearnEmotion"
    void FUN_141abea50(NotifyObject* pNotice);                                          // "NotifyChangedTokenMoney"
    void FUN_141abf1f0();                                                               // block the toasts
    void FUN_141abf210();                                                               // unblock the toasts
    void FUN_141abf230(__int64 nExp, __int64 nBonus);                                   // exp
    void FUN_141abf450(__int64 nMoney, __int64 nBonus);                                 // meso
    void FUN_141abf6e0(int nItemId, int nGrade);                                        // item by id
    void FUN_141abfa10(Unk_RNItemRef pItem);                                            // item
    void FUN_141abfdc0(Unk_RNAchieve* pAchieve);                                        // achievement / title
    void FUN_141abffa0(int nEmotionId);                                                 // emotion
    void FUN_141ac0210(PC* pPlayer);                                                  // learned skills
    void FUN_141ac05d0(int nSkillId, CStringW strMsg, int nSkillType);                  // skill message (by value: the callee destroys it)
    void FUN_141ac0860(__int64 nValue);                                                 // "merat"
    void FUN_141ac0990(__int64 nValue);                                                 // "merat_red"
    void FUN_141ac0ac0(int nId);                                                        // title
    void FUN_141ac0cd0(const CStringW& strMsg, const CStringW& strIcon);                // token / currency message
    void FUN_141ac0e50(int nFishId, unsigned nLength);                                       // fishing success
    void FUN_141ac11b0(int nFishId, unsigned nLength);                                       // fishing fail
    void FUN_141ac14b0();                                                               // "skillLevelUp"
    void FUN_141ac1580(const CStringW& strIcon, const CStringW& strMsg, int nEffect);   // message + icon + effect
    void FUN_141ac1730(const CStringW& strMsg, int nSpecial, const CStringW& strTag);   // stamp
    void FUN_141ac18e0(bool bOpen);                                                     // "OnSkillBookDialog"
    void FUN_141ac1950(int nPoint, int nKind);                                          // skill point
    void FUN_141ac1b50(int nPoint);                                                     // stat point
    void FUN_141ac1d10(int nItemId);                                                    // box open (cash coupon)
    void FUN_141ac1f40();                                                               // "rewardComplete"
    void FUN_141ac1fe0(MS2Ptr<AScript> pReward);                                          // send "appendReward" or queue

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<AScript> > m_queue;      // +0x70 rewards waiting for the movie
    int m_block;                                 // +0x90
};
MS2_CHECK_SIZE(UIRewardNotify, 0x98);
MS2_CHECK_OFFSET(UIRewardNotify, m_queue, 0x70);
MS2_CHECK_OFFSET(UIRewardNotify, m_block, 0x90);

// "Fame contents" opening/ending banner queue: (quest id, 1 = opening / 0 = ending) pairs.
class UIFameContentsNotify : public UIHeadUpDisplay {
public:
    UIFameContentsNotify();                                                             // 0x141ac2190
    virtual ~UIFameContentsNotify();                                                    // 0 0x141ac22d0
    virtual CString vfunc_1();                                                          // 1 0x141ac23e0
    virtual void vfunc_2();                                                             // 2 0x141ac2430
    virtual void vfunc_3();                                                             // 3 0x141ac2450
    virtual void vfunc_18();                                                            // 18 0x141ac24b0
    virtual void OnLoadComplete();                                                      // 22 0x141ac2470
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ac2510
    virtual int vfunc_48();                                                             // 48 0x141ac3fa0

    void FUN_141ac25b0(int nQuestId);                                                   // queue an opening banner
    void FUN_141ac26a0(int nQuestId);                                                   // queue an ending banner
    void FUN_141ac2790(NotifyObject* pNotice);                                          // "NotifyFadeInComplete"
    int FUN_141ac27d0();                                                                // show the front banner; 0 if none

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<std::pair<int, int> > m_list;  // +0x70
};
MS2_CHECK_SIZE(UIFameContentsNotify, 0xa0);
MS2_CHECK_OFFSET(UIFameContentsNotify, m_list, 0x70);

// One result of a roulette spin: the slot that was hit and the item it pays out.
struct Unk_RouletteSpin {
    int m_slot;
    int m_itemId;
    unsigned m_rarity;
    int m_count;
};
MS2_CHECK_SIZE(Unk_RouletteSpin, 0x10);

// Roulette: 12 reward slots (item id / rarity / count arrays filled by the server packet 0x7c), then the spin results.
class UIRouletteDialog : public UIDialog {
public:
    UIRouletteDialog();                                                                 // 0x141ac4920
    virtual ~UIRouletteDialog();                                                        // 0 0x141ac4a90
    virtual CString vfunc_1();                                                          // 1 0x141ac4bd0
    virtual int vfunc_13();                                                             // 13 0x141ac4eb0
    virtual void vfunc_15();                                                            // 15 0x141ac4e90 (returns this)
    virtual void OnLoadInit();                                                          // 20 0x141ac4d40
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ac4ec0
    virtual void vfunc_43();                                                            // 43 0x141ac4d70
    virtual int vfunc_48();                                                             // 48 0x141ac6ad0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);               // 49 0x141ac5540 tooltips
    virtual int vfunc_65();                                                             // 65 0x141ac4c20
    virtual void vfunc_67();                                                            // 67 0x141ac4c50

    int FUN_141ac59e0();                                                                // spin index
    int FUN_141ac5a00();                                                                // spin count
    void FUN_141ac5a30();                                                               // fill the 12 slots into the movie
    void FUN_141ac5e70(CInPacket& pkt);                                                 // packet 0x7c

private:
    MS2_LAYOUT_FRIEND;
    int m_178;
    ATL::CAtlArray<int> m_itemIds;                  // +0x180
    ATL::CAtlArray<unsigned> m_rarities;            // +0x1a0
    ATL::CAtlArray<int> m_counts;                   // +0x1c0
    unsigned m_1e0;
    ATL::CAtlArray<CString> m_binds;                // +0x1e8 bind ids of the slot icons
    ATL::CAtlArray<Unk_RouletteSpin> m_spins;       // +0x208
    int m_spinIndex;                                // +0x228
    int m_hSound;                                   // +0x22c
};
MS2_CHECK_SIZE(UIRouletteDialog, 0x230);
MS2_CHECK_OFFSET(UIRouletteDialog, m_itemIds, 0x180);
MS2_CHECK_OFFSET(UIRouletteDialog, m_rarities, 0x1a0);
MS2_CHECK_OFFSET(UIRouletteDialog, m_counts, 0x1c0);
MS2_CHECK_OFFSET(UIRouletteDialog, m_1e0, 0x1e0);
MS2_CHECK_OFFSET(UIRouletteDialog, m_binds, 0x1e8);
MS2_CHECK_OFFSET(UIRouletteDialog, m_spins, 0x208);
MS2_CHECK_OFFSET(UIRouletteDialog, m_spinIndex, 0x228);
