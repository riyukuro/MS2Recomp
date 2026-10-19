// stateplayinstrumentdata.h - StatePlayInstrument (type 0x2f): the actor state of a player playing an instrument (sub
// states 0x7d ready/direct, 0x7e solo score, 0x7f / 0x81 ensemble ready / playing; gosubstate.h) and its payload
// StatePlayInstrumentData (the instrument item). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\stateplayinstrumentdata.cpp` (0x140dde050-0x140de0f70 .text$mn, dir client\ms2). Header name assumed; member names
// invented from their use. Derives State / StateData (ms2/placeholder/state.h).
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include <egf/Entity.h>
#include <NiNode.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"

class CItem;
class CItemData;
class CInstrumentData;
class AvatarPC;

// 0x30. The instrument item that is played and a second value (the caller passes 0). The exe's dtor body is ~MS2Ptr then
// ~StateData with no vptr store, so it stays implicit:
// MS2-PIN: ??1StatePlayInstrumentData@@UEAA@XZ 0x140de09d0
class StatePlayInstrumentData : public StateData
{
public:
    StatePlayInstrumentData();                                  // 0x140dde050
    StatePlayInstrumentData(MS2Ptr<CItemData> spItem, __int64 n);   // 0x140dde0b0
    virtual void vfunc_1(Unk_StateDataArg* p);                  // 1 0x140dde130 (item id into the state-sync record)
    virtual void vfunc_2(Unk_StateDataArg* p);                  // 2 0x140dde180 (item from the record)
    int FUN_140dde200();                                        // the instrument id of the item (0 without an item)

    MS2Ptr<CItemData> m_spItem;                                 // +0x18
    __int64 m_n28;                                              // +0x28
};
MS2_CHECK_SIZE(StatePlayInstrumentData, 0x30);
MS2_CHECK_OFFSET(StatePlayInstrumentData, m_spItem, 0x18);
MS2_CHECK_OFFSET(StatePlayInstrumentData, m_n28, 0x28);

// 0xb8. m_n10 is the sub state (0x7d..0x81). m_spEffect is the instrument's ready effect model (sub state 0x7d), m_spItem
// the instrument item that is put into the owner's hand, m_vPos the position of the owner when the state started
// (leaving when it moved more than 50 away), m_spEntity the instrument entity ("MS2Actor" built from the asset),
// m_strLastAnim the animation that was played last (replayed after the model changes).
class StatePlayInstrument : public State
{
public:
    StatePlayInstrument(PCBase* pOwner);                    // 0x140dde250
    virtual ~StatePlayInstrument();                         // 0x140dde3b0 (??_G 0x140de0b80)
    virtual int vfunc_1();                                  // 1  0x140de0c80: 0x2f
    virtual void vfunc_2(int n);                            // 2  0x140ddf9e0 (sub state changed: replay the animations)
    virtual void vfunc_3(double fTime);                     // 3  0x140ddf4b0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140dde460 (enter)
    virtual void vfunc_5(int n);                            // 5  0x140ddf110 (leave)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x140ddfae0 (replay the idle animation)
    virtual int vfunc_19();                                 // 19 0x140de0c90: 0
    virtual int vfunc_22(MS2Ptr<Unk_StateArg22> p);         // 22 0x140ddfb10 (a request of another sub state replaces this)
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140de0c00: an empty StatePlayInstrumentData

    int FUN_140ddfbb0();                                    // the instrument id of the data (0 without data)
    void FUN_140ddfc00();                                   // (re)starts the two effects of the sub state
    void FUN_140de0410(int nLevel);                         // plays the animation of a play level (ensemble sub states)
    void FUN_140de04a0();                                   // plays the animation of the sub state
    void FUN_140de05a0(int nLevel);                         // plays the animation of a play level
    void FUN_140de0780(const CString& strAnim);             // plays an animation on the owner (and on the instrument entity)

    MS2Ptr<StatePlayInstrumentData> m_spInstrumentData;     // +0x40
    efd::SmartPointer<NiNode> m_spEffect;                   // +0x50
    MS2Ptr<CItem> m_spItem;                                 // +0x58
    int m_nEffect68;                                        // +0x68 id of the ready / play effect
    int m_nEffect6c;                                        // +0x6c id of the instrument effect
    MS2Ptr<CInstrumentData> m_spInstrument;                 // +0x70
    CString m_str80;                                        // +0x80
    Unk_StreamPoint m_vPos;                                 // +0x88
    egf::EntityPtr m_spEntity;                              // +0x98
    bool m_bA0;                                             // +0xa0 the first level animation was requested
    CString m_strLastAnim;                                  // +0xa8
    int m_nB0;                                              // +0xb0 the owner's slot 25 value (visibility)
    bool m_bB4;                                             // +0xb4 the entity is attached to the avatar
};
MS2_CHECK_SIZE(StatePlayInstrument, 0xb8);
MS2_CHECK_OFFSET(StatePlayInstrument, m_spInstrumentData, 0x40);
MS2_CHECK_OFFSET(StatePlayInstrument, m_spEffect, 0x50);
MS2_CHECK_OFFSET(StatePlayInstrument, m_spItem, 0x58);
MS2_CHECK_OFFSET(StatePlayInstrument, m_spInstrument, 0x70);
MS2_CHECK_OFFSET(StatePlayInstrument, m_vPos, 0x88);
MS2_CHECK_OFFSET(StatePlayInstrument, m_spEntity, 0x98);
MS2_CHECK_OFFSET(StatePlayInstrument, m_strLastAnim, 0xa8);
MS2_CHECK_OFFSET(StatePlayInstrument, m_bB4, 0xb4);
