// raindroponcubeemitter.h - the rain effect over the cube terrain: RainDropSystem (owns the particle system, the
// emitter and the controller) and RainDropOnCubeEmitter (a volume emitter that spawns drops on the cube columns
// around the local player, one drop per column and a cool-down). Owning unit: ?\raindroponcubeemitter.cpp
// (0x1416ec580-0x1416f44e0, .text$di 0x1400fed80). Header name assumed from the unit path; member names are invented
// from use.
#pragma once
#include "ms2/ms2layout.h"
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <unordered_map>
#include <efd/customalloc.h>
#include <NiSmartPointer.h>
#include <NiPSVolumeEmitter.h>
#include <NiPSParticleSystem.h>
#include <NiPSEmitParticlesCtlr.h>
#include <NiNode.h>
#include <NiTexture.h>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/commonfiles/ugcbuildvalidator.h"

// A scheduled drop: the time it becomes due and the column it falls on (0x18 bytes).
struct Unk_RainDrop
{
    Unk_RainDrop();                                                 // 0x1416ec5c0
    Unk_RainDrop(double dTime, const Unk_Int3& kPos);            // 0x1416ec5f0
    double GetTime() const;                                         // 0x1416ec580
    const Unk_Int3& GetPos() const;                              // 0x1416ec5a0
    double m_dTime;
    Unk_CubePoint m_kPos;
};
MS2_CHECK_SIZE(Unk_RainDrop, 0x18);

typedef std::list<Unk_RainDrop, efd::CustomAllocator<Unk_RainDrop> > DropListBase;

// The scheduled drops: a thin class over the list (its ctor is an out-of-line wrapper in the exe).
class DropList : public DropListBase
{
};

typedef std::unordered_map<unsigned int, unsigned int, std::hash<unsigned int>, std::equal_to<unsigned int>,
                           efd::CustomAllocator<std::pair<const unsigned int, unsigned int> > > ColumnMapBase;

// The column map: a thin class over the hash map (its ctor is an out-of-line wrapper in the exe).
class ColumnMap : public ColumnMapBase
{
};

class RainDropOnCubeEmitter : public NiPSVolumeEmitter
{
    NiDeclareRTTI;                                                  // GetRTTI 0x1416f13c0
public:
    RainDropOnCubeEmitter(const NiFixedString& kName, NiAVObject* pkEmitterObj, float fSize, float fSizeVar,
                          float fLifeSpan, float fLifeSpanVar);     // 0x1416ec650
    // ~RainDropOnCubeEmitter is implicit: 0x1416f05b0, ??_G 0x1416f0df0
    virtual bool ComputeVolumeInitialPositionAndVelocity(NiQuatTransform& kEmitterToPSys, NiPoint3& kPosition,
                                                         NiPoint3& kVelocity);   // 0x1416eccc0
    void MarkDirty();                                               // 0x1416f17e0
    void Refresh();                                                 // 0x1416eca00 rebuild the drops when the player moved
public:
    MS2_LAYOUT_FRIEND;
    DropList m_lstDrops;                             // +0x98 due drops, ordered by time
    ColumnMap m_mapColumns;    // +0xa8 column key -> column key
    unsigned int m_nCenterKey;                                      // +0xe8 key of the player's column
    float m_fCooldown;                                              // +0xec seconds before a column rains again
    bool m_bDirty;                                                  // +0xf0
};
MS2_CHECK_SIZE(RainDropOnCubeEmitter, 0xf8);
MS2_CHECK_OFFSET(RainDropOnCubeEmitter, m_lstDrops, 0x98);
MS2_CHECK_OFFSET(RainDropOnCubeEmitter, m_mapColumns, 0xa8);
MS2_CHECK_OFFSET(RainDropOnCubeEmitter, m_nCenterKey, 0xe8);

NiSmartPointer(RainDropOnCubeEmitter);

// 0x60 bytes. Dtor 0x1416ecfb0, ??_G 0x1416f0e50.
class RainDropSystem : public NiRefObject
{
public:
    RainDropSystem();                                               // 0x1416eced0
    virtual ~RainDropSystem();                                      // 0x1416ecfb0
    void Create();                                                  // 0x1416ed080 build the particle system and its textures
    void Update();                                                  // 0x1416ed980
    void Destroy();                                                 // 0x1416ed9c0
    void SetupProperties();                                         // 0x1416eda10
    void SelectTexture();                                           // 0x1416eded0
public:
    MS2_LAYOUT_FRIEND;
    NiPSParticleSystemPtr m_spSystem;                               // +0x10
    Unk_NodePtr m_spNode;                                           // +0x18
    RainDropOnCubeEmitterPtr m_spEmitter;                           // +0x20
    NiPSEmitParticlesCtlrPtr m_spCtlr;                              // +0x28
    unsigned int m_nHandle;                                         // +0x30 id of the scene registration
    ATL::CAtlArray<NiTexturePtr> m_arrTexture;                      // +0x38 the 16 rain textures
    unsigned int m_nTexture;                                        // +0x58
};
MS2_CHECK_SIZE(RainDropSystem, 0x60);
MS2_CHECK_OFFSET(RainDropSystem, m_spSystem, 0x10);
MS2_CHECK_OFFSET(RainDropSystem, m_arrTexture, 0x38);
