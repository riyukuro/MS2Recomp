// skillconfig.h - the player's saved skill window layouts: CSkillCompactControlConfig (RTTI .?AVCSkillCompactControlConfig@@, ctor
// 0x14026a5d0, vftable 0x142d15ae0, 0x38 bytes) and CSkillBookTreeTabConfig (ctor 0x14026a640, vftable 0x142d15af0, one tab of
// the skill book tree: an id, a name of at most 10 characters and the slot -> skill map). Member names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"

class CInPacket;

class CSkillCompactControlConfig : public CPtred
{
public:
    CSkillCompactControlConfig();                                   // 0x14026a5d0

    MS2_LAYOUT_FRIEND;
    CStringW m_strName;                                             // +0x18
    std::set<unsigned> m_skills;                                    // +0x20
    __int64 m_30;                                                   // +0x30
};
MS2_CHECK_SIZE(CSkillCompactControlConfig, 0x38);

class CSkillBookTreeTabConfig : public CPtred
{
public:
    CSkillBookTreeTabConfig();                                      // 0x14026a640
    void Write(COutputStream* pOut);                                // 0x14026a6e0
    void Read(CInPacket* pPacket);                                  // 0x14026a860 (reads through the packet's CInputStream half)

    MS2_LAYOUT_FRIEND;
    __int64 m_nId;                                                  // +0x18 generated from the server time
    CStringW m_strName;                                             // +0x20
    ATL::CAtlMap<unsigned, unsigned> m_slots;                       // +0x28
};
MS2_CHECK_SIZE(CSkillBookTreeTabConfig, 0x70);

// "a,b" parsed into two ints.
class Unk_CommonIntPair
{
public:
    Unk_CommonIntPair();                                            // 0x14026aa70
    void Parse(CStringW strText);                                   // 0x14026aaa0

    int m_first;
    int m_second;
};
MS2_CHECK_SIZE(Unk_CommonIntPair, 8);
