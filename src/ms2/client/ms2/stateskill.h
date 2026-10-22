// StateSkill (RTTI .?AVStateSkill@@, 0x168 bytes, vftable 0x142f73338 36 slots + ICastingEventListener at +0x40,
// vftable 0x142f73460): the actor state of a player casting a skill. It plays the skill's motion sequences (combo,
// charging and loop phases from the text keys), moves the actor with a CMotionController, fires the attacks (magic
// models, target picks) and reports them to the server. CFillTargetContext (0x88) is the input/output of one area
// target pick (stateskill.cpp and magicdata.cpp build it). Member names are invented from their use.
// Owning unit: client\ms2\stateskill.cpp (0x1417e47d0-0x1417f6050, statics 0x140103f20-0x140104310).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <efd/Point3.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/socketptr.h"

class PCBase;
class GameObject;
class CSkillRecord;
class SkillLevelData;
class SkillAttackData;
class CBaseCollision;
class CMotionController;
class NiControllerSequence;
class Unk_EffectTarget;
class CArrowFillTargetContext;
struct Unk_MagicTagPtr;

// The hit pause / camera vibration of the running attack (StateSkill +0xb8).
class Unk_SkillPauseEvent
{
public:
    Unk_SkillPauseEvent();                                              // 0x1417e47d0
    void FUN_1417e4810(PCBase* pOwner, unsigned nSkillId, unsigned short nLevel, const CString& strPoint);
                                                                        // arm with the attack of a cast point
    void FUN_1417e4900(PCBase* pOwner, float fTime);                    // start the pause (or keep it pending)
    void FUN_1417e4c50(PCBase* pOwner);                                 // stop and disarm
    void FUN_1417e4cd0(PCBase* pOwner, CSkillRecord* pRecord);          // tick: end the pause when it is over
    int FUN_1417e4e40();                                                // the pause is running

    float m_fStart;                                                     // +0x00 the pause start time (0: off)
    float m_fPending;                                                   // +0x04 a start time before the arm
    char m_pad08[8];
    SkillAttackData* m_pAttack;                                         // +0x10
};
MS2_CHECK_OFFSET(Unk_SkillPauseEvent, m_pAttack, 0x10);
MS2_CHECK_SIZE(Unk_SkillPauseEvent, 0x18);

// One area target pick (vftable 0x142f73328, ctor 0x1417e4e80, dtor 0x1417f5ab0).
class CFillTargetContext : public CPtred
{
public:
    CFillTargetContext();
    // ~CFillTargetContext() is implicit (0x1417f5ab0: no vptr store).

    PCBase* m_pOwner;                                                   // +0x18 the caster
    efd::Point3 m_ptOwner;                                              // +0x20 the caster's position
    ATL::CAtlArray<efd::SmartPointer<GameObject> > m_arrTargets;        // +0x30 the picked objects
    MS2Ptr<SkillLevelData> m_spLevel;                                   // +0x50 the skill source
    int m_n60;                                                          // +0x60 use the second query kind
    int m_nMotion;                                                      // +0x64
    int m_nAttack;                                                      // +0x68
    float m_fZOffset;                                                   // +0x6c the shape lookup's z offset (0x141754580)
    MS2Ptr<CBaseCollision> m_spCollision;                               // +0x70 the pick shape
    unsigned m_nKindFlags;                                              // +0x80 or'ed into the query kind
    int m_n84;                                                          // +0x84 test every anchor box
};
MS2_CHECK_OFFSET(CFillTargetContext, m_arrTargets, 0x30);
MS2_CHECK_OFFSET(CFillTargetContext, m_spLevel, 0x50);
MS2_CHECK_OFFSET(CFillTargetContext, m_spCollision, 0x70);
MS2_CHECK_SIZE(CFillTargetContext, 0x88);

class StateSkill : public State, public ICastingEventListener
{
public:
    StateSkill(PCBase* pOwner);                                         // 0x1417e4f70
    virtual ~StateSkill();                                              // 0x1417e5210 (??_G 0x1417f5df0)
    virtual int vfunc_1();                                              // 1  0x1417f5f00: 0x10
    virtual void vfunc_3(double fTime);                                 // 3  0x1417e6820
    virtual void vfunc_4(StateData* pData);                             // 4  0x1417e5350 enter
    virtual void vfunc_5(int n);                                        // 5  0x1417e5ee0 leave
    virtual void vfunc_7(int n);                                        // 7  0x1417e6690
    virtual void vfunc_8(double fTime);                                 // 8  0x1417e6990
    virtual void AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                // 11 0x1417e71d0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                // 12 0x1417e7660
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                // 13 0x1417e9130
    virtual int vfunc_14();                                             // 14 0x1417ecbd0
    virtual int vfunc_15();                                             // 15 0x1417e92c0
    virtual int vfunc_18();                                             // 18 0x1417e7150
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);                     // 22 0x1417e67c0
    virtual void vfunc_26(Unk_StateDataArg* p);                         // 26 0x1417e91f0

    MS2Ptr<CSkillRecord> GetRecord();                               // the running cast
    void FUN_1417ed740(MS2Ptr<CSkillRecord> spRecord);                  // set the charging cast
    MS2Ptr<CSkillRecord> GetCharge();                               // the charging cast
    void FUN_1417ec2f0();                                               // send the charge / aim state
    void FUN_1417ec630(bool bCharge, bool bStart);                      // charge input on/off
    void FUN_1417ecc10(Unk_MagicTagPtr spTag);
    void FUN_1417ed7f0();
    void FUN_1417edc20(double fTime);
    void FUN_1417ee120();
    void FUN_1417eeb10(bool bChain);
    bool FUN_1417eed70(MS2Ptr<CSkillRecord> spNext);
    void FUN_1417ef4a0();
    int FUN_1417efbe0();
    int FUN_1417efef0();
    void FUN_1417f0070();
    MS2Ptr<CSkillRecord> FUN_1417f0230();
    MS2Ptr<CSkillRecord> FUN_1417f0570(int nKind);
    void FUN_1417f0940();
    void FUN_1417f0d60(unsigned nTick, const char* szPoint);                                 // fire the current attack
    float FUN_1417f0ec0();
    void FUN_1417f0f10(unsigned nTick, const char* szPoint);              // fire the attack of a cast point
    void FUN_1417f1060();
    void FUN_1417f11d0();
    void FUN_1417f16f0(MS2Ptr<CSkillRecord> spRecord);
    static float FUN_1417ec0d0(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord);  // the sequence frequency of a cast
    static void FUN_1417ec210(MS2Ptr<CSkillRecord> spRecord, float fStart, float fEnd, float fSpeed);  // arm a move phase
    int FUN_1417f1a10(unsigned nNow, unsigned nStart);
    void FUN_1417f1a90();
    void FUN_1417f1ea0();
    void FUN_1417f1fe0();
    void FUN_1417f2030();
    void FUN_1417f2150();
    void FUN_1417f27d0();
    void FUN_1417f2a90(bool bFinish);
    float GetSpeed();                                              // the sequence frequency
    static int FUN_1417e93a0(PCBase* pOwner, MS2Ptr<SkillLevelData> spLevel, int n60, int nAttack);
                                                                        // pick per motion until one finds targets
    static int FUN_1417e95a0(Unk_SocketPtr<CFillTargetContext> spCtx);  // run an area pick (callee releases)
    static int FUN_1417ea310(GameObject* pOwner, ATL::CAtlArray<efd::SmartPointer<GameObject> >& aTargets);
                                                                        // party members first
    static int FUN_1417e9d20(Unk_SocketPtr<CArrowFillTargetContext> spCtx);  // run an arrow pick (callee releases)
    unsigned FUN_1417e9330();                                           // the running skill id (0: none)
    float FUN_1417f4ea0(PCBase* pOwner, efd::Point3 kRot);
    void SendSkillMode4();
    void FUN_1417f4d20();                                               // start the super armor effect
    void FUN_1417f4dc0();                                               // stop it
    bool FUN_1417f5060();                                               // the combo input may chain
    static void FUN_1417f2b50(MS2Ptr<CSkillRecord> spRecord);           // fire the due magic models of a cast
    static int FUN_1417ea570(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult);   // check a cast by kind
    static void FUN_1417ea750(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord);   // the cast's start effect
    static int FUN_1417ea920(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord);    // fire the cast's first attack
    static int FUN_1417eaa50(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult);
    static int FUN_1417eb3a0(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult);
    static int FUN_1417ebc00(PCBase* pOwner, MS2Ptr<CSkillRecord> spRecord, int* pResult);
    static void FUN_1417ecce0(unsigned nTick, MS2Ptr<CSkillRecord> spRecord, int nAttack, PCBase* pOwner);
                                                                        // fire one attack (magic models + packet)
    static void FUN_1417f2cb0(float fTime, MS2Ptr<CSkillRecord> spRecord, int nAttack, PCBase* pOwner);   // the debug range
    static void FUN_1417f3180(ATL::CAtlArray<Unk_MagicTagPtr>& aTags, const efd::Point3& kDir,
        MS2Ptr<CSkillRecord> spRecord, int nAttack, PCBase* pOwner);   // pick the targets of an attack
    static void FUN_1417f3e80(int nBounce, ATL::CAtlList<Unk_MagicTagPtr>& lstChain, MS2Ptr<CSkillRecord> spRecord,
        int nAttack, PCBase* pOwner);   // chain a bounce from the last record
    static bool FUN_1417f4bc0(Unk_EffectTarget& kTarget);               // the effect is hidden by the options

    bool m_b48;                         // +0x48 the chain input is held
    bool m_b49;                         // +0x49 the combo input
    bool m_b4a;                         // +0x4a the self combo input
    bool m_bMoved;                      // +0x4b the motion controller moved the actor this tick
    MS2Ptr<CSkillRecord> m_spNext;      // +0x50 the queued next cast
    MS2Ptr<CSkillRecord> m_spRecord;    // +0x60 the running cast
    MS2Ptr<CSkillRecord> m_spCharge;    // +0x70 the charging cast
    int m_nAttack;                      // +0x80 the next attack index of the motion
    unsigned m_nSequenceId;             // +0x84
    float m_fStartTime;                 // +0x88
    CMotionController* m_pMotion;       // +0x90
    float m_fLoopStart;                 // +0x98
    float m_fLoopEnd;                   // +0x9c
    unsigned m_nLoopSequenceId;         // +0xa0
    bool m_bCharging;                   // +0xa4
    bool m_bA5;                         // +0xa5
    float m_fChargeTime;                // +0xa8
    NiControllerSequence* m_pSequence;  // +0xb0
    Unk_SkillPauseEvent m_pause;        // +0xb8
    efd::Point3 m_ptSentRot;            // +0xd0 the last sent aim
    efd::Point3 m_ptSentPos;            // +0xdc
    bool m_bSentCharging;               // +0xe8
    bool m_bSentLoop;                   // +0xe9
    float m_fSpeed;                     // +0xec the sequence frequency
    int m_nEffectId;                    // +0xf0
    CString m_strSequence;              // +0xf8
    int m_nRepeat;                      // +0x100
    efd::Point3 m_ptPush;               // +0x104 the knock-back of the cast
    bool m_b110;                        // +0x110
    bool m_b111;                        // +0x111
    bool m_b112;                        // +0x112
    bool m_bLoop;                       // +0x113 in the charging loop
    bool m_b114;                        // +0x114
    bool m_b115;                        // +0x115
    bool m_b116;                        // +0x116
    bool m_b117;                        // +0x117
    int m_nChainType;                   // +0x118 the next skill's chain type
    bool m_b11c;                        // +0x11c
    bool m_b11d;                        // +0x11d
    bool m_b11e;                        // +0x11e
    int m_nComboTick;                   // +0x120
    int m_nSelfComboTick;               // +0x124
    int m_nChargingComboTick;           // +0x128
    int m_nChargingAttackTick;          // +0x12c
    unsigned m_nStartTick;              // +0x130
    unsigned m_n134;                    // +0x134 the loop length (ms)
    unsigned m_n138;                    // +0x138 the loop start tick
    unsigned m_nChargeTick;             // +0x13c the charge time (ms)
    bool m_bMove0;                      // +0x140
    bool m_bMove2;                      // +0x141
    efd::Point3 m_pt144;                // +0x144
    unsigned m_nCastEnd;                // +0x150 the casting bar end tick
    int m_nCastDuration;                // +0x154
    __int64 m_nCastId;                  // +0x158 the cast the bar was shown for
    int m_nLoopEffectId;                // +0x160
};
MS2_CHECK_OFFSET(StateSkill, m_b48, 0x48);
MS2_CHECK_OFFSET(StateSkill, m_spRecord, 0x60);
MS2_CHECK_OFFSET(StateSkill, m_pMotion, 0x90);
MS2_CHECK_OFFSET(StateSkill, m_pause, 0xb8);
MS2_CHECK_OFFSET(StateSkill, m_strSequence, 0xf8);
MS2_CHECK_OFFSET(StateSkill, m_ptPush, 0x104);
MS2_CHECK_OFFSET(StateSkill, m_nChainType, 0x118);
MS2_CHECK_OFFSET(StateSkill, m_nChargeTick, 0x13c);
MS2_CHECK_OFFSET(StateSkill, m_pt144, 0x144);
MS2_CHECK_OFFSET(StateSkill, m_nCastId, 0x158);
MS2_CHECK_SIZE(StateSkill, 0x168);
