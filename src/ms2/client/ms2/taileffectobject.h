// CTailEffectObject (RTTI name): the "tail" a game object drags behind itself (a trail of effect nodes, rows of
// Table/tailEffect.xml: TailEffectData). It keeps a list of TailEffectInfo (one spawned effect + its scene node each);
// the list grows / shrinks to the wanted count and every node follows the previous one at a fixed distance.
// Owning unit: ?\taileffectobject.cpp (0x140aced60-0x140ad1860). Member names are invented from their use.
#pragma once
#include <list>
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/commonfiles/taileffectdatatable.h"

class GameObject;

class CTailEffectObject : public CPtred
{
public:
    // One spawned effect (0x28 bytes, vftable: deleting dtor only; RTTI CTailEffectObject::TailEffectInfo).
    struct TailEffectInfo : public CPtred
    {
        // implicit ctor (0x140ad08b0): `new TailEffectInfo()` zero-fills before it runs
        Unk_NodePtr m_spNode;               // +0x18 the scene node the effect is attached to
        int m_nEffectId;                    // +0x20 effect-manager handle
    };

    CTailEffectObject(GameObject* pOwner, MS2SvrPtr<TailEffectData> spData);    // 0x140aced60
    virtual ~CTailEffectObject();                                               // 0x140acee20
    virtual bool vfunc_1();                                                     // 0x140ad0250 the owner is alive

    void FUN_140acee90();                   // append one effect behind the last one
    void FUN_140acf570();                   // drop the first effect (plays the end effect)
    void FUN_140acf7b0();                   // drop all effects
    void FUN_140acf820();                   // grow / shrink the list to the wanted count
    void FUN_140acf8f0();                   // drag every node behind its predecessor
    void FUN_140acfda0();                   // show all effects
    void FUN_140acfeb0();                   // hide all effects
    void FUN_140acffc0(float fAlpha);       // set the alpha of all nodes
    void FUN_140ad00e0(int nCount);         // wanted length (0..30)
    void FUN_140ad0120(int nTailId);        // switch to another tail row
    void FUN_140ad01d0();                   // length 0, drop all effects
    void FUN_140ad0200();                   // per-frame update

    GameObject* m_pOwner;                                       // +0x18
    std::list<MS2Ptr<TailEffectInfo> > m_listInfo;              // +0x20
    MS2SvrPtr<TailEffectData> m_spData;                         // +0x30
    float m_fAlpha;                                             // +0x40
    bool m_bVisible;                                            // +0x44
    bool m_bDestroyed;                                          // +0x45
    int m_nCount;                                               // +0x48 wanted number of effects
};
MS2_CHECK_SIZE(CTailEffectObject, 0x50);
MS2_CHECK_OFFSET(CTailEffectObject, m_listInfo, 0x20);
MS2_CHECK_OFFSET(CTailEffectObject, m_spData, 0x30);
MS2_CHECK_OFFSET(CTailEffectObject, m_fAlpha, 0x40);
MS2_CHECK_OFFSET(CTailEffectObject, m_nCount, 0x48);
MS2_CHECK_SIZE(CTailEffectObject::TailEffectInfo, 0x28);
