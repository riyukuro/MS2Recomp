// animationmanager.h - CAnimationManager (RTTI "CAnimationManager", 0xa0 bytes, base CPtred, vftable 0x142db53e0 with
// the single deleting-dtor slot 0x1409a15e0): per-actor animation helper held by GameObject at +0x48 (MS2Ptr).
// Owning unit: ?\animationmanager.cpp (ctor 0x14099dbe0). Header name assumed. The animation-service table at +0x20
// (ctor 0x140996b20, dtor 0x140996b80) is an opaque 0x50-byte object owned by another unit.
#pragma once
#include <efd/utf8string.h>

#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class GameObject;
class Unk_AnimSvc;      // MS2 view of egmAnimation::AnimationService (animationmanager.cpp)

// Name of an animation (default ctor 0x1408a8700, dtor 0x1408a8900 are efd::utf8string's).
typedef efd::utf8string Unk_AnimRef;

#include "animationcallbackmanager.h"   // Unk_AnimTable

class CAnimationManager : public CPtred
{
public:
    CAnimationManager(GameObject* pOwner);                  // 0x14099dbe0
    virtual ~CAnimationManager();                           // 0x14099dc80, ??_G 0x1409a15e0
    // True when the named sequence of the owner's actor is currently active (state 1).
    bool IsAnimationPlaying(const efd::utf8string& kName);       // 0x14099dcd0
    // Name of the animation as the owner's model knows it (model-path prefix, else the plain name).
    CString ResolveAnimationName(const efd::utf8string& kName);    // 0x14099ddb0
    // Plays kSrc on the owner at speed fScale (bForce restarts it); false when the model has no such sequence.
    bool PlayAnimation(Unk_AnimRef& kSrc, float fScale, bool bForce);   // 0x14099e050
    void ReplayAnimation();                                   // 0x14099e640 replay the current animation
    void StopAnimation();                                   // 0x14099e680 stop
    void SetAnimationOffset(float fOffset);                      // 0x14099e710 offset of the current sequence
    void FUN_14099e7a0(void* p);                            // 0x14099e7a0 forwards to the table
    void FUN_14099e7d0(void* p);                            // 0x14099e7d0 forwards to the table
    void GetAnimationNames(void* pList);                        // 0x14099e800 append all sequence names to a CString list
    // @0x140a53f90
    Unk_AnimRef& FUN_140a53f90() { return m_78; }           // accessor COMDAT (effectobject.cpp)

public:
    MS2_LAYOUT_FRIEND;
    GameObject* m_pOwner;                                   // +0x18
    Unk_AnimTable m_table;                                  // +0x20
    Unk_AnimSvc* m_pModelCache;                             // +0x70 = FUN_141b6f910()
    Unk_AnimRef m_78;                                       // +0x78
    float m_fScale98;                                       // +0x98 = 1.0
    int m_pad_9c;                                           // +0x9c
};
MS2_CHECK_SIZE(CAnimationManager, 0xa0);
MS2_CHECK_OFFSET(CAnimationManager, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CAnimationManager, m_table, 0x20);
MS2_CHECK_OFFSET(CAnimationManager, m_pModelCache, 0x70);
MS2_CHECK_OFFSET(CAnimationManager, m_78, 0x78);
MS2_CHECK_OFFSET(CAnimationManager, m_fScale98, 0x98);
