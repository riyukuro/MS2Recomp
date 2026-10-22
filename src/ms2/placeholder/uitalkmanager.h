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
class Unk_TalkIdList : public ATL::CAtlArray<void*>
{
public:
    unsigned __int64 FUN_140186270();                           // GetCount
    unsigned& FUN_140184510(unsigned __int64 nIndex);           // GetAt
    unsigned& FUN_1401c0c80(__int64 nIndex);                    // GetAt (checked)
    void FUN_1401855a0(unsigned nId);                           // Add
    void FUN_1402c2830();                                       // RemoveAll
};
MS2_CHECK_SIZE(Unk_TalkIdList, 0x20);

// The talk's id queue: the current position and the ids (a "XInfoError" in Ghidra, wrongly).
class Unk_TalkIdState
{
public:
    Unk_TalkIdState();                                          // 0x141b1da80
    ~Unk_TalkIdState();                                         // 0x141b22200
    void FUN_141b1dac0();                                       // reset
    unsigned FUN_141b1daf0();                                   // the id at the current position (0 past the end)
    int m_nPos;                                                 // +0x00
    Unk_TalkIdList m_ids;                                       // +0x08
};
MS2_CHECK_SIZE(Unk_TalkIdState, 0x28);

// The reward items of the talk (16-byte handles to CItem).
class Unk_TalkItemList : public ATL::CAtlArray<void*>
{
public:
    unsigned FUN_140720ca0();                                   // GetCount
    MS2Ptr<CItem>& FUN_140a69ee0(unsigned nIndex);              // GetAt
    void FUN_140720b80(const MS2Ptr<CItem>& spItem);            // Add
    void FUN_1408f3a80();                                       // RemoveAll
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
        virtual ~CTalkRewardData();                                 // 0x141b221d0 (??_G 0x141b22350)
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

    void FUN_141b1ddd0(CInPacket& in);                      // the talk packet
    void FUN_141b1e8a0(CInPacket& in);                      // mode 3: move the player next to the npc
    void FUN_141b1e990(CInPacket& in);                      // mode 1: set the npc's name tag
    void FUN_141b1ea90(CInPacket& in);                      // mode 4: open a dialog by name
    void FUN_141b1eb90(CString strDialog, CString strArg);  // open the named dialog (by value: the callee destroys them)
    void FUN_141b1f350(CInPacket& in);                      // mode 5: reward items
    void FUN_141b1f620(CInPacket& in);                      // mode 6: meso
    void FUN_141b1f6b0(CInPacket& in);                      // mode 7: merat
    void FUN_141b1f740(CInPacket& in);                      // mode 8: exp
    void FUN_141b1f7a0(CInPacket& in);                      // mode 9: affinity exp, jackpot flag
    void FUN_141b1f840(CInPacket& in);                      // mode 10: pop up a message
    void FUN_141b1f920(const CString& strArgs);             // BeautyShopDialog
    void FUN_141b1fa20(const CString& strArgs);             // BeautyStyleDialog (the argument is not read)
    bool FUN_141b1fa60();                                   // the local player exists
    void FUN_141b1faa0(int nMode, int nDialogId);           // open a dialog from the talk
    void FUN_141b1fcf0(unsigned nNpcId);                    // start the talk with an npc
    void SendNpcTalkMode0();                                   // end the talk
    void FUN_141b1ff80(unsigned nNpcId);                    // begin: quest script
    void FUN_141b200d0(unsigned nNpcId, CTalkScript* pScript);   // begin: given script
    void FUN_141b20210();                                   // reset the talk
    int FUN_141b204d0();                                    // show the first page
    void FUN_141b20700();                                   // look the script up again
    void FUN_141b20790(int nNpcId);                         // swap to another npc
    int FUN_141b20ac0();                                    // always 0
    void FUN_141b20af0();                                   // end the talk when the npc is gone
    int FUN_141b20bb0();                                    // show the current page
    void SendNpcTalkMode2(unsigned nNpcId);                    // ask the server to continue
    void FUN_141b20e60(MS2Ptr<CTalkScript> spScript, int nId, int nPage);   // begin at a page
    CStringW FUN_141b20ed0();                               // the name of the current page
    MS2Ptr<CTalkScript> GetScript();                    // the script handle
    MS2Ptr<CCinematicContent> FUN_141b21030();              // the current page
    void FUN_141b21190(unsigned char nFlags, int nParam, int nPage);   // set the state words
    int FUN_141b211d0();                                    // the talk cooldown elapsed
    int GetTalking();                                    // IsTalking
    int FUN_141b21240(int nNpcId);                          // IsTalkingWith
    unsigned FUN_141b212c0();                               // npc id (0 when not talking)
    int FUN_141b212f0();                                    // npc id of the open talk
    Unk_TcNpc* FUN_141b21350();                             // the npc actor
    void FUN_141b21390();                                   // stop
    int FUN_141b213c0();                                    // the talk has no npc
    unsigned FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound);   // begin without an npc
    void FUN_141b215b0(int bSamePage);                      // advance to the next page
    void FUN_141b217b0();                                   // clear the id queue
    void FUN_141b217e0(unsigned nId);                       // queue an id
    unsigned FUN_141b21810(int nIndex);                     // the queued id
    unsigned __int64 FUN_141b21860();                       // queue length
    unsigned FUN_141b21890();                               // m_48
    int FUN_141b218b0(Unk_TcNpc* pNpc);                     // refuse a talk (shows a notice)
    Unk_TalkIdList* FUN_141b21a10();                        // the dialogs the talk opened
    void FUN_141b21a30();                                   // close them
    void FUN_141b21ae0(const CString& strDialog);           // remember or close the dialog
    MS2Ptr<CTalkScript> FUN_141b21b90();                    // find the script of the talk
    unsigned FUN_141b21d70();                               // the sound of the page
    int FUN_141b1d810() { return m_nSound; }                // 0x141b1d810 (inline)

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
