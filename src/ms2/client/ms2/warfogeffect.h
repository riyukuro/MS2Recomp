// warfogeffect.h - CWarFogEffect (RTTI .?AVCWarFogEffect@@): the dark ring of "war fog" drawn around a point: a 64-slice
// annulus built into a CMesh (positions and vertex colours), re-fitted every few ticks to the physics ground by casting
// a ray per slice. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\warfogeffect.cpp`
// (0x141b732c0-0x141b745f0). Header name assumed; vfunc names and member names are invented from their use.
#pragma once

#include <NiPoint3.h>
#include <NiNode.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/client/ms2/mesh.h"

// The effect parameter block passed to Update (a row of the effect table); only the accessors the effect uses.
struct Unk_WarFogParam
{
    // @0x1403812a0
    float FUN_1403812a0() const { return m_radius; }
    // @0x140381320
    bool FUN_140381320() const { return m_flag28; }
    // @0x140381340
    float FUN_140381340() const { return m_alpha * 0.01f; }
    // @0x140381370
    bool FUN_140381370() const { return m_flag2a; }

    char m_pad_00[0x18];
    float m_radius;                 // +0x18
    char m_pad_1c[0xc];
    bool m_flag28;                  // +0x28
    unsigned char m_alpha;          // +0x29 (percent)
    bool m_flag2a;                  // +0x2a
};

// The physics ray query (0x64 bytes, ctor 0x140ad4440) cast by the scene (0x1416892f0).
#pragma pack(push, 4)
struct Unk_WarFogRay
{
    // @0x140ad4440 (inline COMDAT of another obj)
    Unk_WarFogRay() : m_distance(0.0f), m_mask(0xffffffff), m_pad_20(0), m_pad_28(0),
        m_pad_30(0), m_pad_38(0), m_pad_40(0), m_flags(0) {}
    efd::Point3 m_origin;           // +0x00
    efd::Point3 m_dir;              // +0x0c
    float m_distance;               // +0x18
    unsigned int m_mask;            // +0x1c (ctor -1)
    unsigned __int64 m_pad_20, m_pad_28;                    // +0x20 (five zeroed qwords)
    unsigned __int64 m_pad_30, m_pad_38, m_pad_40;
    int m_flags;                    // +0x48
    efd::Point3 m_hit;              // +0x4c
    efd::Point3 m_normal;           // +0x58
};
#pragma pack(pop)
MS2_CHECK_SIZE(Unk_WarFogRay, 0x64);

// 0x38 bytes. vftable 0x142ff44f0 (1 slot: the deleting destructor).
class CWarFogEffect : public CPtred
{
public:
    CWarFogEffect();                                            // 0x141b732c0
    virtual ~CWarFogEffect();                                   // 0x141b73360

    void FUN_141b733c0();                                       // detach the ring mesh from its parent and drop it
    void FUN_141b734a0(bool bVisible);                          // show/hide the ring
    void FUN_141b73530(const Unk_WarFogParam* pParam, const efd::Point3& ptCenter);   // rebuild if needed, then refit
    bool FUN_141b739e0(const Unk_WarFogParam* pParam);          // true when the ring has to be rebuilt
    void FUN_141b73ab0(const Unk_WarFogParam* pParam);          // build the annulus mesh and attach it to the scene

    NiPointer<CMesh> m_spMesh;                                  // +0x18
    float m_fRadius;                                            // +0x20 (ctor -1)
    bool m_bFlag24;                                             // +0x24 (ctor true)
    float m_fAlpha;                                             // +0x28 (ctor 0.45)
    bool m_bFlag2c;                                             // +0x2c
    float m_fZ;                                                 // +0x30 smoothed centre height
    unsigned int m_nTick;                                       // +0x34 last refit tick
};
MS2_CHECK_SIZE(CWarFogEffect, 0x38);
MS2_CHECK_OFFSET(CWarFogEffect, m_fRadius, 0x20);
MS2_CHECK_OFFSET(CWarFogEffect, m_nTick, 0x34);
