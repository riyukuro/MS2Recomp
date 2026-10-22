// getexp.h - CExpEffectInfo (one exp orb flying from a dead monster to the local player) and CGetExp (the list of
// live orbs). Owning unit: ?\getexp.cpp (0x141272630-0x141274d10, .text$di 0x1400eb710-0x1400eba80). Header name
// assumed from the unit path; class names are the exe's (RTTI).
#pragma once
#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/nipoint3.h"

class Unk_ExpActor;

// 0x90 bytes, vftable 1 slot (the deleting dtor 0x141273f50).
class CExpEffectInfo : public CPtred
{
public:
    CExpEffectInfo();                                       // 0x141272630
    virtual ~CExpEffectInfo();                              // 0x141272760
    Vector3 GetAxis0() const;                       // 0x1412727d0 column 0 of the orientation
    Vector3 GetAxis1() const;                       // 0x141272830
    Vector3 GetAxis2() const;                       // 0x141272890
    void UpdateOrientation();                               // 0x1412728f0 face the node along (target - source)
    void InitConstants();                                   // 0x141272b10 lazy-load the tuning values
    void StopEffect();                                      // 0x141272c20 release the effect handle
    void Update(float fElapsed);                            // 0x141272c60
    void UpdateMove(float fElapsed);                        // 0x141272cb0
    bool Create(int nObjectId, void* pOwner);               // 0x141272f20
    int GetState() const;                                   // 0x141273570 0 flying, 1 arrived
    void SetPosition(const Vector3& pt);            // 0x141273590
    void SetVisible(int nHide);                             // 0x141273630
    void Finish();                                          // 0x141273680
    void GetTargetPos(Unk_ExpActor* pActor, Vector3* pOut);   // 0x141273890 attach point or the actor position

    void* m_pOwner;                         // +0x18
    int m_n20;                              // +0x20
    unsigned int m_hEffect;                          // +0x24 effect-manager handle, 0 = none
    int m_pad_28;
    int m_pad_2c;
    Unk_NodePtr m_spNode;                   // +0x30 the orb's NiNode
    Vector3 m_ptPos;                // +0x38 current position
    float m_fElapsed;                       // +0x44
    Unk_NiMatrix3 m_rot;                    // +0x48 orientation
    float m_fProgress;                      // +0x6c distance / total
    float m_fTotal;                         // +0x70 total travel distance (scaled, clamped)
    Vector3 m_ptTarget;             // +0x74 where it flies to (the player)
    Vector3 m_ptSource;             // +0x80 where it started (the monster)
    int m_nState;                           // +0x8c
};
MS2_CHECK_SIZE(CExpEffectInfo, 0x90);
MS2_CHECK_OFFSET(CExpEffectInfo, m_spNode, 0x30);
MS2_CHECK_OFFSET(CExpEffectInfo, m_rot, 0x48);
MS2_CHECK_OFFSET(CExpEffectInfo, m_nState, 0x8c);

// 0x50 bytes, vftable 1 slot (the deleting dtor 0x141273f90).
class CGetExp : public CPtred
{
public:
    CGetExp();                                              // 0x141273920
    virtual ~CGetExp();                                     // 0x141273980
    void Update(float fElapsed);                            // 0x1412739d0 advance the orbs, drop the finished ones
    int FUN_141273b40();                                    // 0x141273b40 always 1
    void AddEffect(int nObjectId, void* pOwner);            // 0x141273b60
    void SetVisible(int nHide);                             // 0x141273c40

    ATL::CAtlList<MS2Ptr<CExpEffectInfo> > m_list;          // +0x18 (0x30)
    int m_bEnabled;                                         // +0x48
    int m_pad_4c;
};
MS2_CHECK_SIZE(CGetExp, 0x50);
MS2_CHECK_OFFSET(CGetExp, m_list, 0x18);
MS2_CHECK_OFFSET(CGetExp, m_bEnabled, 0x48);
