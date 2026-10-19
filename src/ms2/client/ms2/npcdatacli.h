// npcdatacli.h - NpcDataCli (one client npc row: CNpcData plus the icon / sound / effect / gender columns) and
// NpcDataTableCli (the client NpcData/<nnn>.xml table). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); NOT an
// original header: the member names come from the XML attribute names the loader reads.
#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/client/ms2/effectdummy.h"

class NpcDataCli : public CNpcData
{
public:
    NpcDataCli();                                           // 0x140a7beb0
    virtual ~NpcDataCli();                                  // 0x140a7c020, sdd 0x140a81680
    virtual bool LoadXml(Unk_140165cf0* pElem);             // 0x140a7c420
    bool Different(const NpcDataCli* pOther);               // 0x140a7c150
    bool GetNametag();                                      // 0x140a7c8d0
    bool IsFemale();                                        // 0x140a7c8f0
    bool IsBossNpc();                                       // 0x140a7c930
    int GetUnknown12();                                     // 0x140a7c950
    unsigned GetClassConstant();                            // 0x140a7c970

    CStringA m_strIcon;                                     // +0x520 iconName
    CStringA m_strMinimapIcon;                              // +0x528 minimapIconName
    CStringA m_strShopIcon;                                 // +0x530 shopIconName
    CStringA m_strSoundStart;                               // +0x538 npcSoundStart
    CStringA m_strSoundEnd;                                 // +0x540 npcSoundEnd
    CStringA m_strSoundDead;                                // +0x548 npcSoundDead
    CStringA m_strRegenEffect;                              // +0x550
    CStringA m_strDeadEffect;                               // +0x558
    CStringA m_strDamageEffect;                             // +0x560
    CStringA m_strCreateEffect;                             // +0x568
    CStringA m_strKeepEffect;                               // +0x570
    CStringA m_strIllust;                                   // +0x578
    bool m_bHpBar;                                          // +0x580
    bool m_bAttackDamage;                                   // +0x581
    bool m_bNametag;                                        // +0x582
    std::vector<CEffectDummy> m_effectDummies;              // +0x588
    int m_nGender;                                          // +0x5a0 (3 = unspecified)
};
MS2_CHECK_SIZE(NpcDataCli, 0x5a8);
MS2_CHECK_OFFSET(NpcDataCli, m_strIllust, 0x578);
MS2_CHECK_OFFSET(NpcDataCli, m_effectDummies, 0x588);

class NpcDataTableCli : public CNpcDataTable, public TSingleton<NpcDataTableCli>
{
public:
    NpcDataTableCli();                                      // 0x140a7ca40
    virtual ~NpcDataTableCli() = default;                   // 0x140a80ae0 (pinned: the exe dtor has no vptr store)

    MS2Ptr<NpcDataCli> Find(unsigned nId);                  // 0x140a7cab0
    void LoadAll();                                         // 0x140a7cbf0
    void IndexAllRegions();                                 // 0x140a7cc70
    void Load(int nFile);                                   // 0x140a7cd70
    CStringA GetIllust(unsigned nId);                       // 0x140a7d1a0
    void Collect(std::map<unsigned, MS2Ptr<NpcDataCli> >& mapOut);  // 0x140a7d260

    std::unordered_map<unsigned, MS2Ptr<NpcDataCli> > m_mapNpc;     // +0x120
};
MS2_CHECK_SIZE(NpcDataTableCli, 0x160);
MS2_CHECK_OFFSET(NpcDataTableCli, m_mapNpc, 0x120);
