// reactor.h - CReactor (efd RTTI "CReactor", class id 0x0620007e): a GameObject that is one world reactor (a field
// object the player triggers, e.g. a sapling or a rune; Table/reactor.xml + reactorState.xml, see
// commonfiles/reactordata.h). Owning unit: client\ms2\reactor.cpp (0x140b788d0-0x140b7edf0). Header name assumed.
//
// Size 0x1e0 (??_G 0x140b7c9d0 frees 0x1e0). Only slot 9, slot 53 and CallbackObject::EndOfSequence are overridden.
// ClassInfo 0x143abc9c0 (setup 0x140b7e240, registration 0x1400c8d80). Ctor 0x140b788d0, dtor 0x140b789c0.
#pragma once
#include <set>
#include "ms2/client/ms2/gameobject.h"
#include "ms2/commonfiles/reactordata.h"

class CInPacket;
class PCBase;
struct Unk_ReactorInfo;

class CReactor : public GameObject
{
    EE_DECLARE_CLASS1(CReactor, 0x0620007e, GameObject);

public:
    CReactor();                                             // 0x140b788d0
    virtual ~CReactor();                                    // 0x140b789c0

    virtual void vfunc_9(void* p);                          // 9  0x140b7a160
    virtual void vfunc_53(float f);                         // 53 0x140b7a120 animation + connected-effect refresh
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 0x140b7a1b0 pops the finished animation off the queue

    CString FUN_140b78af0();                                // copy of m_strName
    void FUN_140b78b40(bool bFlag);                         // tells the animation service about the entity
    int FUN_140b78bb0();                                    // reactor table id (0 without data)
    MS2Ptr<ReactorStateData> FUN_140b78c00(int nIdx);       // state nIdx of the data (null when out of range)
    void FUN_140b78d90(Unk_ReactorInfo* pOut);              // action string and react time of the current state
    void FUN_140b78ea0(const CString& strAni);              // queue an animation (empty ones are dropped)
    bool FUN_140b78ef0(const CString& strEffect);           // show the connected effect (always true)
    bool FUN_140b79120(const CString& strEffect);           // hide the connected effect (always true)
    void FUN_140b791a0();                                   // play the head of the animation queue
    void FUN_140b79330();                                   // connect/disconnect the effect for the local player
    bool FUN_140b79490(CInPacket* pPacket);                 // field-add packet
    void SendStateReact();                                   // send the interact request (opcode 0xa9)
    void FUN_140b79a10(CInPacket* pPacket);                 // state-update packet
    bool FUN_140b79c30();                                   // local player may use the reactor
    int FUN_140b79cc0(PCBase* pPc);                           // 1 = the state refuses this player
    int FUN_140b79ee0(PCBase* pPc);                           // 1 = the player lacks the required items
    // Accessors defined in the unit that follows the animation-queue helpers (actionkeyobject.cpp); both copy a member.
    MS2Ptr<ReactorStateData> FUN_140966db0();               // state of m_nStateIdx
    MS2Ptr<ReactorData> FUN_140966e50();                    // copy of m_spData

public:
    MS2_LAYOUT_FRIEND;
    int m_nStateIdx;                                        // +0x140
    CString m_strName;                                      // +0x148 server-sent name
    __int64 m_n150;                                         // +0x150
    unsigned __int64 m_n158;                                // +0x158
    MS2Ptr<ReactorData> m_spData;                           // +0x160
    ATL::CAtlList<CString> m_listAnims;                     // +0x170 animation queue
    std::set<unsigned __int64> m_setPlayers;                      // +0x1a0 players that already used it
    ATL::CRBMap<CString, int> m_mapEffects;                 // +0x1b0 effect name -> effect handle
};
MS2_CHECK_SIZE(CReactor, 0x1e0);
MS2_CHECK_OFFSET(CReactor, m_nStateIdx, 0x140);
MS2_CHECK_OFFSET(CReactor, m_strName, 0x148);
MS2_CHECK_OFFSET(CReactor, m_spData, 0x160);
MS2_CHECK_OFFSET(CReactor, m_listAnims, 0x170);
MS2_CHECK_OFFSET(CReactor, m_setPlayers, 0x1a0);
MS2_CHECK_OFFSET(CReactor, m_mapEffects, 0x1b0);

// Placement/creation checks of the local player (free functions; PC = the local PCBase).
bool FUN_140b7a330(PCBase* pPc, int nReactorId);              // 0x140b7a330 true when the player may create the reactor (shows the failure)
int FUN_140b7a3d0(PCBase* pPc, int nReactorId);               // 0x140b7a3d0 game-event/daily-count check, 0 = ok
int FUN_140b7a5e0(PCBase* pPc);                               // 0x140b7a5e0 player action check, 0 = ok
int FUN_140b7a650(PCBase* pPc);                               // 0x140b7a650 placement check, 0 = ok
void FUN_140b7b7a0(int nError);                             // 0x140b7b7a0 shows the failure message
