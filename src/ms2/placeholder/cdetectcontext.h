// cdetectcontext.h - CDetectContext (RTTI .?AVCDetectContext@@, 0x90 bytes, ctor 0x1409fbb80, dtor 0x140a004f0): the
// input and output of one shape-based target search (CBaseCollision::Detect, ?\basecollision.cpp). The caller (skill
// states, pcbase.cpp, ...) fills owner/range/position/kind, a collision shape fills the direction axes and collects the
// hit objects into m_arrTargets. NOT an original header; member names are invented from use.
#pragma once
#include <atlcoll.h>
#include <efd/Point3.h>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class GameObject;

// The skill attack-range row a search runs for (stateskill.cpp passes it; 0 for plain searches). Only the fields the
// search reads are named.
struct Unk_DetectRange
{
    char m_pad_00[0xd4];
    int m_nBuffFilter;                  // +0xd4 buff id the target must carry (0: any)
    char m_pad_d8[0xe0 - 0xd8];
    int m_bBuffFromOwner;               // +0xe0 the buff must come from the searching actor
    int m_nFilterMode;                  // +0xe4 0: off, 2: keep only the filtered targets, 3: same unless none passes
    int m_bSameParty;                   // +0xe8 filter: same party id
    int m_bSameGuild;                   // +0xec filter: same guild name
    int m_nStatKind;                    // +0xf0 stat sort: the stat index
    int m_nStatSort;                    // +0xf4 stat sort: 0 off, 1/2 value desc/asc, 3/4 ratio desc/asc
    int m_nQueryFlags;                  // +0xf8 passed to the world query (target filter flags)
};
MS2_CHECK_OFFSET(Unk_DetectRange, m_nBuffFilter, 0xd4);
MS2_CHECK_OFFSET(Unk_DetectRange, m_nQueryFlags, 0xf8);

class CDetectContext : public CPtred
{
public:
    CDetectContext();                                               // 0x1409fbb80
    // ~CDetectContext() is implicit (0x140a004f0: no vptr store).

    GameObject* m_pOwner;                                           // +0x18 the searching actor
    Unk_DetectRange* m_pRange;                                      // +0x20
    efd::Point3 m_kPos;                                             // +0x28 search origin
    efd::Point3 m_kRight;                                           // +0x34 side axis (set by the shape)
    efd::Point3 m_kDir;                                             // +0x40 forward axis (set by the shape)
    ATL::CAtlArray<efd::SmartPointer<GameObject> > m_arrTargets;    // +0x50 the hits
    int m_nTargetKind;                                              // +0x70 world query kind
    int m_nSortMode;                                                // +0x74 0 shuffle, 1/2 lateral, 3/4 forward, 5/6 facing
    int m_n78;                                                      // +0x78
    int m_bRideToRider;                                             // +0x7c a hit mount counts as its rider (put first)
    ATL::CAtlMap<unsigned int, float>* m_pExclude;                  // +0x80 object ids to skip
    int m_bUseAllAnchors;                                           // +0x88 test every anchor box (GameObject::vfunc_28)
};
MS2_CHECK_OFFSET(CDetectContext, m_kPos, 0x28);
MS2_CHECK_OFFSET(CDetectContext, m_arrTargets, 0x50);
MS2_CHECK_OFFSET(CDetectContext, m_pExclude, 0x80);
MS2_CHECK_SIZE(CDetectContext, 0x90);
