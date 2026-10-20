// statecoupleemotion.h - StateCoupleEmotionData (the payload of the couple-emotion actor state, 0x40),
// CoupleEmotionAnimInfo (the loaded animation set of one running emotion, 0x98) and StateCoupleEmotion (the state
// itself, state type 0x3a, 0xa8 bytes). NOT an original header (class names from the vtable symbols, layouts from the
// ctors and the scalar deleting dtors 0x140b86040 / 0x140b86080 / 0x140b860c0). Owning unit
// client\ms2\statecoupleemotion.cpp (0x140b7fa70-0x140b866d0). The classes derive State / StateData
// (ms2/placeholder/state.h); slot names follow that header.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include <NiPoint3.h>
#include <NiAVObject.h>
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/state.h"

class PCBase;
class MyPC;
class NiNode;
class NiAVObject;
class Unk_StateDataArg;

// 0x40. The couple-emotion state's payload: which emotion, who the partner is, the animation index and the two actors'
// start / end positions. Mirrored into / out of StateSyncObjectCoupleEmotion by slots 1 / 2.
class StateCoupleEmotionData : public StateData
{
public:
    StateCoupleEmotionData();                               // 0x140b7fa70
    virtual ~StateCoupleEmotionData();                      // 0x140b85cb0 (??_G 0x140b860c0)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1 0x140b7fb00
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2 0x140b7fbe0

    int m_nEmotion;                                         // +0x18 coupleEmotion table id
    int m_nPartnerId;                                       // +0x1c object id of the other actor
    int m_nRequesterId;                                     // +0x20 object id of the actor that asked
    int m_nAni;                                             // +0x24 animation index
    efd::Point3 m_posStart;                             // +0x28
    efd::Point3 m_posEnd;                               // +0x34
};
MS2_CHECK_SIZE(StateCoupleEmotionData, 0x40);
MS2_CHECK_OFFSET(StateCoupleEmotionData, m_posStart, 0x28);
MS2_CHECK_OFFSET(StateCoupleEmotionData, m_posEnd, 0x34);

// The smart pointer at CoupleEmotionAnimInfo +0x90 (its COMDATs are 0x140b85910 / 0x140b85b20 / 0x140b85cd0): a
// reference-counted pointer to the first animated target of the loaded nif.
class Unk_TargetPtr
{
public:
    Unk_TargetPtr(NiObjectNET* p);                                 // 0x140b85910
    ~Unk_TargetPtr();                                       // 0x140b85b20
    Unk_TargetPtr& operator=(NiObjectNET* p);                      // 0x140b85cd0
    bool operator!=(int nNull) const;                       // 0x140b85fc0
    void* m_p;
};
MS2_CHECK_SIZE(Unk_TargetPtr, 8);

// 0x98. The animation set of one running couple emotion (the table row copied for the chosen gender pairing) plus the
// scene-graph handles that were found in the loaded nif. Base CPtred.
class CoupleEmotionAnimInfo : public CPtred
{
public:
    CoupleEmotionAnimInfo();                                // 0x140b85a20
    // implicit virtual dtor 0x140b85be0 (??_G 0x140b86040): no vftable reset, so it must stay compiler-generated

    bool Init(int nEmotion, int nGender1, int nGender2, bool bSwap);   // 0x140b7fcc0
    bool Load(int nAni);                                    // 0x140b7ff20 loads the nif of animation nAni
    void UpdateNif();                                       // 0x140b80630 advance the nif to "now"
    CStringA GetAniName(int nAni);                           // 0x140b806a0 the partner's animation name
    int GetLastAni();                                       // 0x140b861f0 last valid animation index
    void SetStartTime(float f);                             // 0x140b86350

    bool m_bLoop;                                           // +0x18 the row's <pair>_loop
    char m_pad_19[7];
    CString m_strTeleportEffect;                            // +0x20 the row's teleport_effect
    CString m_strOwnerNode;                                 // +0x28 node name of the first actor ("A" / "B")
    CString m_strPeerNode;                                  // +0x30 node name of the second actor
    std::vector<CString> m_aniNames;                        // +0x38 partner's animation names
    std::vector<CString> m_nifPaths;                        // +0x50 one nif per animation
    float m_fStartTime;                                     // +0x68 clock at which the current nif was started
    float m_fDuration;                                      // +0x6c longest controller of the owner node
    NiAVObjectPtr m_spNifRoot;                              // +0x70 scene root of the loaded nif
    Unk_NodePtr m_spOwnerNode;                              // +0x78 node named m_strOwnerNode
    Unk_NodePtr m_spPeerNode;                               // +0x80 node named m_strPeerNode
    Unk_NodePtr m_spCenterNode;                             // +0x88 "Eff_center" (falls back to the owner node)
    Unk_TargetPtr m_spTarget;                               // +0x90
};
MS2_CHECK_SIZE(CoupleEmotionAnimInfo, 0x98);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_strTeleportEffect, 0x20);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_aniNames, 0x38);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_nifPaths, 0x50);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_spNifRoot, 0x70);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_spOwnerNode, 0x78);
MS2_CHECK_OFFSET(CoupleEmotionAnimInfo, m_spTarget, 0x90);

class StateSyncObjectCoupleEmotion;
template <class T> class MS2Ptr;

// 0xa8. Plays a couple emotion (state type 0x3a): the actor is moved next to the partner, a looping effect node is
// attached and the animations of the table row play in sequence.
class StateCoupleEmotion : public State
{
public:
    StateCoupleEmotion(PCBase* pOwner);                     // 0x140b80760
    virtual ~StateCoupleEmotion();                          // 0x140b80820 (??_G 0x140b86080)
    virtual int vfunc_1();                                  // 1  0x140b86220: 0x3a
    virtual void vfunc_2(int n);                            // 2  0x140b81950
    virtual void vfunc_3(double fTime);                     // 3  0x140b80f00
    virtual void vfunc_4(StateData* pData);                 // 4  0x140b808a0
    virtual void vfunc_5(int n);                            // 5  0x140b80d10
    virtual void vfunc_6();                                 // 6  0x140b81650
    virtual void vfunc_8(double fTime);                     // 8  0x140b81830
    virtual void vfunc_9(double fTime);                     // 9  0x140b810d0
    virtual void TextKeyEvent(NiActorManager* pkManager, unsigned int eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);     // 12 0x140b81a30
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140b81670
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140b81da0
    virtual void vfunc_24();                                // 24 0x140b811d0
    virtual bool vfunc_28(MS2Ptr<Unk_StateArg22> p);        // 28 0x140b81f70
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140b86100

    int GetEmotionId();                                     // 0x140b81fe0 the payload's emotion (0 without one)
    int GetPartnerId();                                     // 0x140b82030
    int GetRequesterId();                                   // 0x140b82080
    void SetStartPos(const efd::Point3& pos);           // 0x140b820d0
    void SetEndPos(const efd::Point3& pos);             // 0x140b82130
    bool IsRequester();                                     // 0x140b82190 the owner asked for the emotion
    bool FindPlacement(efd::Point3& posA, efd::Point3& posB, float* pfYaw);   // 0x140b82230
    PCBase* GetPartner();                                   // 0x140b82a00
    void Stop(int bNotify);                                 // 0x140b82aa0 leave the state, tell the server
    bool SyncWithPartner();                                 // 0x140b82c40
    CStringA GetCurAniName();                                // 0x140b83260
    int GetAniIndex();                                      // 0x140b833a0 (-1 without a payload)
    bool AddEffect(CStringA strName);                        // 0x140b833f0
    bool RemoveEffect(CStringA strName);                     // 0x140b83a90
    bool PlayFirstAni();                                    // 0x140b83b80
    bool PlayNextAni();                                     // 0x140b83c20
    bool PlayAni(int nAni);                                 // 0x140b83ce0

    MS2Ptr<StateCoupleEmotionData> m_spCoupleData;          // +0x40
    MS2Ptr<CoupleEmotionAnimInfo> m_spAnimInfo;             // +0x50
    efd::Point3 m_posSaved;                             // +0x60 position before the emotion started
    unsigned m_n6c;                                         // +0x6c time (ms) the current phase was entered
    Unk_NodePtr m_spLoopEffectNode;                         // +0x70
    ATL::CRBMap<CStringA, int> m_effects;                   // +0x78 effect name -> effect handle
};
MS2_CHECK_SIZE(StateCoupleEmotion, 0xa8);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_spCoupleData, 0x40);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_spAnimInfo, 0x50);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_posSaved, 0x60);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_n6c, 0x6c);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_spLoopEffectNode, 0x70);
MS2_CHECK_OFFSET(StateCoupleEmotion, m_effects, 0x78);
