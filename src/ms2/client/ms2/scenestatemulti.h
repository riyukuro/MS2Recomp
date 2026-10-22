// scenestatemulti.h - CSceneStateMulti (efd RTTI name "CSceneStateMulti", class id 0x0620000d): the multi (character
// select / create lobby) scene state, plus its lobbyField.xml table (LobbyFieldTable) and the character backup
// record (CSceneStateMulti::BackUpCharacterInfo). Header name assumed from the unit path.
//
// Bases: CSceneStateBase (0x10), IWorldServiceCallback at +0x10 (vftable 0x142f608f8), IMessageListener at +0x18
// (vftable 0x142f60940, one slot: OnMessage 0x14174ea50).
#pragma once
#include <atlcoll.h>
#include "scenestatebase.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/tcreatecharinfo.h"
#include "ms2/placeholder/timer.h"

class NotifyObject;
class MyPC;
class Unk_BackUpItem;
class Unk_LobbyChar;

// lobbyField.xml (Table/lobbyField.xml, root <ms2>, rows <key jobCode= selectMap= createMap=/>): job code -> the map
// shown in the character select scene and the map shown in the character create scene. 0xe0 bytes, vftable
// 0x142f60850 (CCacheData's slot only; deleting dtor 0x141750750).
class LobbyFieldTable : public CCacheData
{
public:
    LobbyFieldTable();                                      // 0x14174d380
    virtual ~LobbyFieldTable();                             // 0x14174d450

    int Load();                                             // 0x14174d4d0 (FUN_14174d4d0) reads the xml once
    unsigned int GetSelectMap(int nJobCode);                // 0x14174d860 (FUN_14174d860) falls back to job 1
    unsigned int GetCreateMap(int nJobCode);                // 0x14174d8d0 (FUN_14174d8d0) falls back to a random select map
    void Clear();                                           // 0x14174d940 (FUN_14174d940)
    unsigned int GetRandomSelectMap();                      // 0x14174d9a0 (FUN_14174d9a0)

private:
    ATL::CAtlMap<DWORD, int> m_selectMap;                     // +0x28 jobCode -> selectMap
    ATL::CAtlArray<unsigned int> m_selectMaps;              // +0x70 the select maps of the rows without a createMap
    ATL::CAtlMap<DWORD, int> m_createMap;                     // +0x90 jobCode -> createMap
    bool m_bLoaded;                                         // +0xd8
};
MS2_CHECK_SIZE(LobbyFieldTable, 0xe0);

class CSceneStateMulti : public CSceneStateBase, public IWorldServiceCallback, public IMessageListener
{
    EE_DECLARE_CLASS1(CSceneStateMulti, 0x0620000d, efd::IBase);

public:
    // The character record kept while a lobby character is shown (CPtred-derived, 0x70 bytes, vftable 0x142f60860,
    // deleting dtor 0x1417506b0). Copies the pc's equip records, appearance ints and item list.
    class BackUpCharacterInfo : public CPtred
    {
    public:
        explicit BackUpCharacterInfo(MyPC* pPC);            // 0x14174dbc0
        virtual ~BackUpCharacterInfo();                     // 0x14174dd40

        ATL::CAtlList<MS2Ptr<Unk_BackUpItem> > m_items;     // +0x18
        Unk_CharEquip m_equip[2];                             // +0x48
        int m_nGender;                                      // +0x60
        int m_nJobCode;                                     // +0x64
        int m_n68;                                          // +0x68
    };

    CSceneStateMulti();                                     // 0x14174da20
    virtual ~CSceneStateMulti();                            // 0x14174db30

    void OnEnter(int nPrevState) override;                  // 0x14174dd90
    void OnLeave(int nNextState) override;                  // 0x14174dff0
    void OnUpdate(double fTime) override;                   // 0x14174e150
    void OnPacket(CInPacket& packet) override;              // 0x14174e6b0
    int vfunc_15() override;                                // 0x14174f3c0
    void vfunc_1(int) override;                             // 0x14174e880 (IWorldServiceCallback slot 1)
    void vfunc_4(int) override;                             // 0x14174e980 (IWorldServiceCallback slot 4)
    int OnMessage(UISwfEntity* pSender, UIMsg* pMsg) override;  // 0x14174ea50 (IMessageListener slot 0)

    int FUN_14174eaf0();                                   // a lobby actor exists
    void FUN_14174eb30();                                   // leave the lobby to the server list
    void FUN_14174eb80(int nJobCode);                       // enter the create scene for a job
    void FUN_14174ebc0();                                   // enter the select scene
    void FUN_14174ec40(int nGender, bool bFlag);           // spawn the preview pc for a new character
    void FUN_14174ee00(BackUpCharacterInfo* pInfo);         // respawn the preview pc from a backup
    Unk_LobbyChar* FUN_14174f0f0();                         // 0x14174f0f0 the lobby actor matching the scan row
    void FUN_14174f390(void* pActor, int);                  // 0x14174f390
    unsigned int FUN_14174f3e0();                                 // 0x14174f3e0 select map of the current job
    unsigned int FUN_14174f440();                                 // 0x14174f440 create map of the current job
    void FUN_14174f470();                                   // 0x14174f470
    void FUN_14174f4a0();                                   // 0x14174f4a0
    void FUN_14174f4c0(CInPacket& packet);                  // 0x14174f4c0 opcode 0x71
    void OnWaitingTicketUpdate(CInPacket& packet);                  // 0x14174f8d0 opcode 0xb4
    void FUN_14174fcc0(CInPacket& packet);                  // 0x14174fcc0 opcode 0x10f
    void FUN_14174fd00();                                   // 0x14174fd00 drop the preview pc
    int FUN_14174fd70();                                   // 0x14174fd70
    bool FUN_14174fdb0();                                   // 0x14174fdb0 same month as the server time
    void FUN_14174fe40();                                   // 0x14174fe40
    void FUN_14174fea0();                                   // 0x14174fea0
    void FUN_14174ff00();                                   // 0x14174ff00
    unsigned int FUN_14174ff70();                           // 0x14174ff70
    void FUN_14174ffb0(NotifyObject* pNotify);              // 0x14174ffb0 NotifyGameEventChanged handler
    void OnEventReward(CInPacket& packet);                  // 0x141750050 opcode 0xf7

private:
    unsigned long long m_hPreviewPC;                        // +0x20 handle of the lobby preview actor
    int m_nMode;                                            // +0x28 -1 none, 0 server list, 1 select, 2 create
    int m_nCreateMap;                                       // +0x2c
    int m_nJobCode;                                         // +0x30
    LobbyFieldTable m_lobbyField;                           // +0x38
    unsigned long long m_nServerTime;                       // +0x118 (opcode 0x10f)
    Timer m_timer;                                          // +0x120
    char m_bReconnecting;                                   // +0x158
    Timer m_reconnectTimer;                                 // +0x160
    int m_nRetry;                                           // +0x198
};
MS2_CHECK_SIZE(CSceneStateMulti, 0x1a0);
MS2_CHECK_SIZE(CSceneStateMulti::BackUpCharacterInfo, 0x70);
