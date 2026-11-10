// uitalkmanager.h - PLACEHOLDER for UITalkManager (RTTI .?AVUITalkManager@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<UITalkManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. The talk state machine: which npc and script are open,
// the page index, the reward block accumulated by the server packets. Its code is in ?\uitalkcinematic.cpp
// (0x141b1dc40..0x141b22460). Member and helper names are invented; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ctalkscript.h"
#include "ms2/placeholder/cinematiccontent.h"

class CInPacket;
class CItem;
class UITalkCinematic;
class Unk_TcNpc;

// An int array (the exe's CAtlArray<void*> shape: ctor/dtor are the plain ATL ones); the accessors are out of line.
class Unk_TalkIdList : public ATL::CAtlArray<unsigned>
{
};
MS2_CHECK_SIZE(Unk_TalkIdList, 0x20);

// The talk's id queue: the current position and the ids (a "XInfoError" in Ghidra, wrongly).
class Unk_TalkIdState
{
public:
    Unk_TalkIdState();                                          // 0x141b1da80
    ~Unk_TalkIdState();                                         // 0x141b22200
    void Reset();                                       // reset
    unsigned GetCurrentId();                                   // the id at the current position (0 past the end)
    int m_nPos;                                                 // +0x00
    Unk_TalkIdList m_ids;                                       // +0x08
};
MS2_CHECK_SIZE(Unk_TalkIdState, 0x28);

// The reward items of the talk. The dtor 0x1408f2340 is ~CAtlArray<MS2Ptr<CItem>>, which releases the items.
class Unk_TalkItemList : public ATL::CAtlArray<MS2Ptr<CItem> >
{
};
MS2_CHECK_SIZE(Unk_TalkItemList, 0x20);

class UITalkManager : public TSingleton<UITalkManager>
{
public:
    // The reward block of the open talk (RTTI UITalkManager::CTalkRewardData, 0x58 bytes, base CPtred).
    class CTalkRewardData : public CPtred
    {
    public:
        CTalkRewardData();                                          // 0x141b1db40
        // ~CTalkRewardData() is implicit                         // 0x141b221d0 (??_G 0x141b22350)
        void FUN_141b1dbd0();                                       // clear

        Unk_TalkItemList m_items;                                   // +0x18
        __int64 m_nMeso;                                            // +0x38
        __int64 m_nMerat;                                           // +0x40
        int m_nExp;                                                 // +0x48
        int m_nAffinity;                                            // +0x4c
        int m_nJackpot;                                             // +0x50
    };
    

    UITalkManager();                                        // 0x141b1dc40
    virtual ~UITalkManager();                               //  0 0x141b1dd30 (??_G 0x141b22390)
    virtual const void* vfunc_1();                          //  1 0x141b223d0 the registrar record "UITalkManager"

    void OnTalkPacket(CInPacket& in);                      // the talk packet
    void FUN_141b1e8a0(CInPacket& in);                      // mode 3: move the player next to the npc
    void SetNpcNameTag(CInPacket& in);                      // mode 1: set the npc's name tag
    void FUN_141b1ea90(CInPacket& in);                      // mode 4: open a dialog by name
    void FUN_141b1eb90(CString strDialog, CString strArg);  // open the named dialog (by value: the callee destroys them)
    void OnRewardItems(CInPacket& in);                      // mode 5: reward items
    void OnRewardMerat(CInPacket& in);                      // mode 6: meso
    void OnRewardMeso(CInPacket& in);                      // mode 7: merat
    void OnRewardExp(CInPacket& in);                      // mode 8: exp
    void OnRewardAffinity(CInPacket& in);                      // mode 9: affinity exp, jackpot flag
    void PlayCutSceneMovie(CInPacket& in);                      // mode 10: pop up a message
    void OpenBeautyShopDialog(const CString& strArgs);             // BeautyShopDialog
    void OpenBeautyStyleDialog(const CString& strArgs);             // BeautyStyleDialog (the argument is not read)
    bool HasLocalPlayer();                                   // the local player exists
    void OpenTalkDialog(int nMode, int nDialogId);           // open a dialog from the talk
    void FUN_141b1fcf0(unsigned nNpcId);                    // start the talk with an npc
    void SendNpcTalkMode0();                                   // end the talk
    void FUN_141b1ff80(unsigned nNpcId);                    // begin: quest script
    void FUN_141b200d0(unsigned nNpcId, CTalkScript* pScript);   // begin: given script
    void ResetTalk();                                   // reset the talk
    int FUN_141b204d0();                                    // show the first page
    void ReloadScript();                                   // look the script up again
    void ShowNpcMonologue(int nNpcId, int nFriendly);          // swap to another npc
    int FUN_141b20ac0();                                    // always 0
    void EndTalkIfNpcGone();                                   // end the talk when the npc is gone
    int ShowCurrentPage();                                    // show the current page
    void SendNpcTalkMode2(unsigned nNpcId);                    // ask the server to continue
    void OpenScript(MS2Ptr<CTalkScript> spScript, int nId, int nPage);   // begin at a page
    CStringW GetCurrentPageName();                               // the name of the current page
    Unk_ScriptPtr<CTalkScript> GetScript();                    // the script handle
    MS2Ptr<CCinematicContent> GetCurrentContent();              // the current page
    void SetTalkState(int nFlags, int nParam, int nPage);   // set the state words
    int IsTalkIntervalElapsed();                                    // the talk cooldown elapsed
    int GetTalking();                                    // IsTalking
    int IsTalkingWith(int nNpcId);                          // IsTalkingWith
    unsigned GetNpcId();                               // npc id (0 when not talking)
    int GetTalkNpcId();                                    // npc id of the open talk
    Unk_TcNpc* GetTalkNpc();                             // the npc actor
    void FUN_141b21390();                                   // stop
    int FUN_141b213c0();                                    // the talk has no npc
    unsigned BeginTalkWithoutNpc(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound);   // begin without an npc
    void FUN_141b215b0(int bSamePage);                      // advance to the next page
    void FUN_141b217b0();                                   // clear the id queue
    void FUN_141b217e0(unsigned nId);                       // queue an id
    unsigned GetIdAt(int nIndex);                     // the queued id
    unsigned __int64 FUN_141b21860();                       // queue length
    unsigned FUN_141b21890();                               // m_48
    int FUN_141b218b0(Unk_TcNpc* pNpc);                     // refuse a talk (shows a notice)
    Unk_TalkIdList* GetOpenedDialogs();                        // the dialogs the talk opened
    void OpenPendingDialogs();                                   // close them
    void OpenOrQueueDialog(const CString& strDialog);           // remember or close the dialog
    Unk_ScriptPtr<CTalkScript> FindTalkScript();                    // find the script of the talk
    unsigned FUN_141b21d70();                               // the sound of the page
    int GetSound() { return m_nSound; }                // 0x141b1d810 (inline)
    CTalkRewardData* FUN_141082d60() { return &m_reward; }  // 0x141082d60 (inline) the reward block of the open talk
    unsigned char FUN_141082ec0() { return m_nFlags; }      // 0x141082ec0 (inline) the state flags

private:
    MS2_LAYOUT_FRIEND;
    int m_nTalking;                                         // +0x08
    int m_nNpcId;                                           // +0x0c
    MS2Ptr<CTalkScript> m_spScript;                         // +0x10
    Unk_TalkIdState m_ids;                                  // +0x20
    int m_48;                                               // +0x48
    unsigned m_nLastTick;                                   // +0x4c
    unsigned char m_nFlags;                                 // +0x50
    int m_nParam;                                           // +0x54
    int m_nPage;                                            // +0x58
    int m_nSound;                                           // +0x5c
    CTalkRewardData m_reward;                               // +0x60
    Unk_TalkIdList m_openedDialogs;                         // +0xb8
    int m_nSpecialNpc;                                      // +0xd8
    int m_nPending;                                         // +0xdc
    int m_nSubMode;                                         // +0xe0
};
MS2_CHECK_SIZE(UITalkManager, 0xe8);
