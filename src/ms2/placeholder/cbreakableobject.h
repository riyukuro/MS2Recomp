// cbreakableobject.h - CBreakableObject (RTTI .?AVCBreakableObject@@, 0x2c0 bytes, ctor 0x140add560): a breakable or
// moving field object (map prop entity with a box collision, a kinematic PhysX box actor, regen / damage / revive
// animations and effects, a tomb stone variant). Bases: CPtred (+0) and CGlobalKeyTextCallback (+0x18, the actor
// manager callback: EndOfSequence advances the state). NOT an original header (name assumed); owning unit
// ?\breakableobject.cpp (0x140add560-0x140ae2d20). Member names are invented from use; methods keep FUN_ addresses
// (other units call them so: their Unk_RideeFieldObj / Unk_WsC_Breakable views are this class).
// vftable 0x142dd5448 (2 slots), listener vftable 0x142dd5460 (6 slots: ??_E thunk, 4 inherited, EndOfSequence).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <efd/Point3.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>
#include <egfPhysX/EntityActorData.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"                  // MS2Ptr<T>
#include "ms2/commonfiles/timer.h"
#include "ms2/client/ms2/animationcallbackmanager.h"  // CGlobalKeyTextCallback

class CBoxCollision;
class CGemTombStone;
class NxActor;

// Object states (m_nState; the server sends them): 2 idle, 3 broken, 4 hidden, 5 regen, 6 damaged.
class CBreakableObject : public CPtred, public CGlobalKeyTextCallback
{
public:
    CBreakableObject();                                             // 0x140add560
    virtual ~CBreakableObject();                                    //  0 0x140adda30 (??_G 0x140ae1970)
    virtual int vfunc_1(egf::Entity* pEntity, int nState);          //  1 0x140ade120 bind the entity, load, set the state

    // CGlobalKeyTextCallback override (listener slot 5)
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);             // 0x140adf920

    void FUN_140adde00(CString strName);                            // set the name key
    CString FUN_140adde50();                                        // the name key
    int FUN_140addea0();                                            // can be hit now
    MS2Ptr<CBoxCollision> FUN_140addf10();                          // pose the box collision, return it
    void FUN_140ade030(int nHitter, int nKind);                     // play the hit sound
    void FUN_140ade420(int nState, unsigned int nDelay);                  // set the state (animations, effects, actor)
    int FUN_140adea80();                                            // the state
    void FUN_140adeaa0(int nSyncA, int nSyncB, int nSyncC);         // the moving-object sync values
    void FUN_140adeaf0(int nNow);                                   // per-frame update (timers, movement)
    bool FUN_140adf310();                                           // m_bC1
    int FUN_140adf330();                                            // tomb stone
    int FUN_140adf350();                                            // m_n184
    void FUN_140adf370(egf::Entity* pEntity, int nArg, MS2Ptr<CGemTombStone> spTomb);   // bind as a tomb stone
    void FUN_140adf6e0();                                           // the state animation ended
    void FUN_140adf770(efd::Point3 ptPos);                          // move: position property
    void FUN_140adf830(efd::Point3 ptRot);                          // turn: rotation property
    efd::Point3 FUN_140adf8e0();                                    // the position
    egf::EntityPtr FUN_140adf980();                                 // the entity
    void FUN_140adf9d0(egf::Entity* pEntity);                       // read the entity's properties, build the box
    efd::Point3 FUN_140ae0150();                                    // the velocity
    void FUN_140ae0190();                                           // resync the actor when the time changed
    void MakeNxBoxController();                                     // 0x140ae0210 the kinematic PhysX box actor
    efd::Point3 FUN_140ae0660();                                    // the box size
    void FUN_140ae06a0(int nPhase, int nNow);                       // enter a movement phase
    bool FUN_140ae0700();                                           // synced (m_nSyncA != 0)
    void FUN_140ae0720();                                           // release the PhysX actor
    void FUN_140ae07d0(int bShow);                                  // fade the model in / out
    void FUN_140ae0990(int bShow);                                  // the shadow on / off
    void FUN_140ae0a90(const CString& strEffect);                   // play an effect on the model
    void FUN_140ae0b90();                                           // drop the tomb stone effects
    void FUN_140ae0c20(egf::Entity* pEntity);                       // the animations of a plain object
    void FUN_140ae0e40();                                           // attach to the scene graph
    void FUN_140ae0ec0(int nDelay);                                 // detach from the scene graph (now or later)

public:
    MS2_LAYOUT_FRIEND;
    CString m_strName;                                              // +0x20
    egf::EntityPtr m_spEntity;                                      // +0x28
    int m_nState;                                                   // +0x30
    MS2Ptr<CBoxCollision> m_spBox;                                  // +0x38
    bool m_bHittable;                                               // +0x48
    int m_nHitSound;                                                // +0x4c
    Timer m_kHitTimer;                                              // +0x50
    Timer m_kFadeTimer;                                             // +0x88
    bool m_bShadow;                                                 // +0xc0
    bool m_bC1;                                                     // +0xc1
    bool m_bPhysics;                                                // +0xc2
    unsigned int m_nTombId;                                         // +0xc4
    ATL::CAtlArray<CString> m_aReviveAnims;                         // +0xc8
    ATL::CAtlArray<CString> m_aRegenAnims;                          // +0xe8
    ATL::CAtlArray<CString> m_aDamageAnims;                         // +0x108
    efd::utf8string m_strIdleAnim;                                  // +0x128
    efd::Point3 m_ptPos;                                            // +0x148
    efd::Point3 m_ptSize;                                           // +0x154
    efd::Point3 m_ptRot;                                            // +0x160 (z: the yaw in degrees)
    efd::Point3 m_ptRotBase;                                        // +0x16c
    NxActor* m_pActor;                                              // +0x178
    int m_bTombStone;                                               // +0x180
    int m_n184;                                                     // +0x184
    int m_bActorDirty;                                              // +0x188
    efd::Point3 m_ptPosBase;                                        // +0x18c
    egfPhysX::EntityActorDataPtr m_spActorData;                     // +0x198
    efd::Point3 m_ptMoveDir;                                        // +0x1a0
    float m_fMoveDelay;                                             // +0x1ac
    float m_fSpeed;                                                 // +0x1b0
    float m_fMoveTime;                                              // +0x1b4
    float m_afWait[2];                                              // +0x1b8 the waits at the two ends
    int m_nMoveMode;                                                // +0x1c0 (1 one way, 2 turn back)
    int m_bHasAnim;                                                 // +0x1c4
    efd::Point3 m_ptVelocity;                                       // +0x1c8
    float m_fTimeScale;                                             // +0x1d4
    unsigned short m_nGroup;                                        // +0x1d8 the PhysX collision group
    int m_n1dc;                                                     // +0x1dc
    int m_nPhaseStart;                                              // +0x1e0
    int m_nPhase;                                                   // +0x1e4
    int m_nPhaseTime;                                               // +0x1e8 (not initialised by the ctor)
    int m_nSyncA;                                                   // +0x1ec
    int m_nSyncB;                                                   // +0x1f0
    unsigned int m_nSyncC;                                          // +0x1f4
    CString m_strDeadEffect;                                        // +0x1f8
    bool m_bTombEffects;                                            // +0x200
    CString m_strIdleEffect;                                        // +0x208
    CString m_strRegenEffect;                                       // +0x210
    CString m_strDamageEffect;                                      // +0x218
    CString m_strReviveEffect;                                      // +0x220
    ATL::CAtlArray<unsigned int> m_aEffects;                        // +0x228 the playing effect ids
    bool m_bDetached;                                               // +0x248
    Timer m_kDetachTimer;                                           // +0x250
    Timer m_kStateTimer;                                            // +0x288
};
MS2_CHECK_OFFSET(CBreakableObject, m_strName, 0x20);
MS2_CHECK_OFFSET(CBreakableObject, m_spBox, 0x38);
MS2_CHECK_OFFSET(CBreakableObject, m_kHitTimer, 0x50);
MS2_CHECK_OFFSET(CBreakableObject, m_bShadow, 0xc0);
MS2_CHECK_OFFSET(CBreakableObject, m_aReviveAnims, 0xc8);
MS2_CHECK_OFFSET(CBreakableObject, m_strIdleAnim, 0x128);
MS2_CHECK_OFFSET(CBreakableObject, m_ptPos, 0x148);
MS2_CHECK_OFFSET(CBreakableObject, m_pActor, 0x178);
MS2_CHECK_OFFSET(CBreakableObject, m_ptPosBase, 0x18c);
MS2_CHECK_OFFSET(CBreakableObject, m_spActorData, 0x198);
MS2_CHECK_OFFSET(CBreakableObject, m_ptVelocity, 0x1c8);
MS2_CHECK_OFFSET(CBreakableObject, m_nGroup, 0x1d8);
MS2_CHECK_OFFSET(CBreakableObject, m_strDeadEffect, 0x1f8);
MS2_CHECK_OFFSET(CBreakableObject, m_aEffects, 0x228);
MS2_CHECK_OFFSET(CBreakableObject, m_bDetached, 0x248);
MS2_CHECK_OFFSET(CBreakableObject, m_kStateTimer, 0x288);
MS2_CHECK_SIZE(CBreakableObject, 0x2c0);
