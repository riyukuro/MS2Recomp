// stateweddingemotion.h - StateWeddingEmotionData (the payload of the wedding-emotion actor state, 0x38) and
// StateWeddingEmotion (the state itself, state type 0x47, 0x70 bytes). NOT an original header (class names from the
// vtable symbols, layouts from the ctors and the scalar deleting dtors 0x140ac7420 / 0x140ac73e0). Owning unit
// ?\stateweddingemotiondata.cpp (0x140ac6400-0x140ac7740). Both classes derive State / StateData
// (ms2/placeholder/state.h); slot names follow that header.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class PCBase;

// The state-sync record that StateData slots 1/2 carry (RTTI .?AVStateSyncObject@@, exe name Unk_StateDataArg).
// This unit is where its wedding-emotion fields are written, so it needs the full layout.
class Unk_StateDataArg : public CPtred
{
public:
    char m_pad_18[0x58];
    CString m_strAnim;         // +0x70 animation name
    char m_pad_78[0x40];
};
MS2_CHECK_SIZE(Unk_StateDataArg, 0xb8);
MS2_CHECK_OFFSET(Unk_StateDataArg, m_strAnim, 0x70);

// RTTI .?AVStateSyncObjectWeddingEmotion@@: the sync record as the wedding-emotion state uses it (the +0xb8 fields
// mirror StateWeddingEmotionData's own, see the two direction functions).
class Unk_SyncWeddingEmotion : public Unk_StateDataArg
{
public:
    bool m_bB8;                // +0xb8 mirrored m_b18
    bool m_bB9;                // +0xb9 mirrored m_b2c
    char m_pad_ba[2];
    int m_nBC;                 // +0xbc duration (s)
    int m_nC0;                 // +0xc0
    bool m_bC4;                // +0xc4
    char m_pad_c5[3];
};
MS2_CHECK_OFFSET(Unk_SyncWeddingEmotion, m_bB8, 0xb8);
MS2_CHECK_OFFSET(Unk_SyncWeddingEmotion, m_bB9, 0xb9);
MS2_CHECK_OFFSET(Unk_SyncWeddingEmotion, m_nBC, 0xbc);
MS2_CHECK_OFFSET(Unk_SyncWeddingEmotion, m_nC0, 0xc0);
MS2_CHECK_OFFSET(Unk_SyncWeddingEmotion, m_bC4, 0xc4);

// The argument of State slots 22/28 (a state request); the exe hands the same sync record through both paths.
#ifndef MS2_UNK_STATEARG22_DEFINED   // also defined by another header (w539: both may be included)
#define MS2_UNK_STATEARG22_DEFINED
class Unk_StateArg22 : public Unk_StateDataArg
{
};
#endif

#include "ms2/placeholder/state.h"

// 0x38. The wedding-emotion state's payload. +0x18 = 1 selects the emotion list path (m_n28 id) instead of the single
// animation (m_strAnim); +0x2c = repeat forever, +0x2d = the +0x28 id is an emotion id.
class StateWeddingEmotionData : public StateData
{
public:
    StateWeddingEmotionData();                              // 0x140ac6400
    virtual ~StateWeddingEmotionData();                     // 0x140ac6490 (??_G 0x140ac7420)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 1 0x140ac64d0
    virtual void vfunc_2(Unk_StateDataArg* p);              // 2 0x140ac65d0

    bool m_b18;                                             // +0x18
    char m_pad_19[7];
    CString m_strAnim;                                      // +0x20
    int m_n28;                                              // +0x28
    bool m_b2c;                                             // +0x2c
    bool m_b2d;                                             // +0x2d
    char m_pad_2e[2];
    unsigned m_n30;                                         // +0x30 duration (ms)
    int m_pad_34;
};
MS2_CHECK_SIZE(StateWeddingEmotionData, 0x38);
MS2_CHECK_OFFSET(StateWeddingEmotionData, m_strAnim, 0x20);

// The wedding-emotion table row (owner ?\weddingemotiontable.cpp): only the animation-name vector this unit reads is
// spelled out - +0x18 = vector<CString>. A row is intrusive-refcounted like every MS2Ptr target.
class WeddingEmotionData : public CPtred
{
public:
    Unk_StrVec m_names;                                     // +0x18
};
MS2_CHECK_OFFSET(WeddingEmotionData, m_names, 0x18);

// 0x70. Plays the wedding-emotion animation (state type 0x47).
class StateWeddingEmotion : public State
{
public:
    StateWeddingEmotion(PCBase* pOwner);                    // 0x140ac66c0
    virtual ~StateWeddingEmotion();                         // 0x140ac6790 (??_G 0x140ac73e0)
    virtual int vfunc_1();                                  // 1  0x140ac7500: 0x47
    virtual void vfunc_3(double fTime);                     // 3  0x140ac6c40
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ac67e0
    virtual void vfunc_5(int n);                            // 5  0x140ac6c70
    virtual void vfunc_7(int n);                            // 7  0x140ac6bc0
    virtual void vfunc_8(double fTime);                     // 8  0x140ac6ca0
    virtual void vfunc_9(double fTime);                     // 9  0x140ac6ce0
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ac6d10
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140ac7090
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140ac7460

    MS2Ptr<StateWeddingEmotionData> m_spData;               // +0x40
    unsigned m_n50;                                         // +0x50 start time (ms)
    MS2Ptr<WeddingEmotionData> m_spEmotion;                 // +0x58 the row the animation names come from
    unsigned m_n68;                                         // +0x68 animation index
};
MS2_CHECK_SIZE(StateWeddingEmotion, 0x70);
MS2_CHECK_OFFSET(StateWeddingEmotion, m_spData, 0x40);
MS2_CHECK_OFFSET(StateWeddingEmotion, m_n50, 0x50);
MS2_CHECK_OFFSET(StateWeddingEmotion, m_spEmotion, 0x58);
MS2_CHECK_OFFSET(StateWeddingEmotion, m_n68, 0x68);
