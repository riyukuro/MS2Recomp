// Guild XML layouts recovered from constructors, allocations and member access.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include <map>
#include <set>
#include "ms2/commonfiles/itemgift.h"
#include <vector>
class CInPacket; class COutPacket;
// Type names of the two original enumeration keys have not been recovered.
// Values proved by FUN_140219f50; names follow the accepted XML strings.
enum Unk_GuildNpcKind {
    Unk_GuildNpcKind_None=0, Unk_GuildNpcKind_Equip=1, Unk_GuildNpcKind_Goods=2,
    Unk_GuildNpcKind_Gemstone=3, Unk_GuildNpcKind_ItemMerge=4,
    Unk_GuildNpcKind_Music=5, Unk_GuildNpcKind_Quest=6
};
// Values proved by FUN_14021a0a0; the previous None-only enum excluded valid XML values.
enum Unk_GuildContribution {
    Unk_GuildContribution_None=0, Unk_GuildContribution_Attend=1,
    Unk_GuildContribution_Donation=2, Unk_GuildContribution_WinMiniGame=3,
    Unk_GuildContribution_LoseMiniGame=4, Unk_GuildContribution_DailyQuest=5,
    Unk_GuildContribution_WeeklyQuest=6, Unk_GuildContribution_Raid=7,
    Unk_GuildContribution_WinPvp=8, Unk_GuildContribution_LosePvp=9
};
MS2_CHECK_SIZE(Unk_GuildNpcKind,4);
MS2_CHECK_SIZE(Unk_GuildContribution,4);
class CGuildPVPSeasonHistoryData:public CPtred {
public:
    CGuildPVPSeasonHistoryData(); virtual ~CGuildPVPSeasonHistoryData();
    void FUN_1404d4250(); void FUN_1404d4330(const CGuildPVPSeasonHistoryData*);
    void FUN_1404d4460(COutPacket*); void FUN_1404d4490(CInPacket*);
    void FUN_1404d44e0(COutputStream&); void FUN_1404d4680(CInputStream&);
    int f18; __int64 f20,f28; CStringW f30; int f38,f3c,f40; CString f48;
    int f50,f54,f58,f5c,f60,f64,f68;
};
MS2_CHECK_SIZE(CGuildPVPSeasonHistoryData,0x70);
MS2_CHECK_OFFSET(CGuildPVPSeasonHistoryData,f48,0x48);
class CGuildXmlData:public TSingleton<CGuildXmlData>,public CValidData<CGuildXmlData> {
public:
    struct GuildProperty:public CPtred {
        GuildProperty();
        bool FUN_1404d4990(void* node);
        int f18;
        int f1c;
        int f20;
        __int64 f28;
        int f30;
        int f34;
        int f38;
        int f3c;
        int f40;
        int f44;
        int f48;
        int f4c;
        int f50;
        float f54;
        float f58;
        int f5c;
        int f60;
        int f64;
        int f68;
    };
    struct GuildSkill:public CPtred {
        GuildSkill();
        bool FUN_1404d4cb0(void* node);
        bool FUN_1404d4e40(); bool FUN_1404d4e60(); bool FUN_1404d4e80();
        int f18;
        int f1c;
        int f20;
        int f24;
        int f28;
        int f2c;
        int f30;
        int f34;
        int f38;
        int f3c;
        CStringW f40;
    };
    struct GuildEvent:public CPtred {
        GuildEvent();
        bool FUN_1404d4f10(void* node);
        int f18;
        int f1c;
        CStringW f20;
    };
    struct GuildHouse:public CPtred {
        GuildHouse();
        bool FUN_1404d5070(void* node);
        int f18;
        int f1c;
        int f20;
        int f24;
        int f28;
        int f2c;
        int f30;
        std::vector<int> f38;
        unsigned f50;
        CStringW f58;
        CStringW f60;
    };
    struct GuildNpc:public CPtred {
        GuildNpc();
        bool FUN_1404d5270(void* node);
        Unk_GuildNpcKind f18;
        int f1c;
        __int64 f20;
        int f28;
        int f2c;
        int f30;
    };
    struct GuildRaid:public CPtred {
        GuildRaid();
        bool FUN_1404d53d0(void* node);
        unsigned f18;
        int f1c;
        float f20;
        float f24;
    };
    struct GuildRaidReward:public CPtred {
        GuildRaidReward();
        bool FUN_1404d54e0(void*);
        int f18; __int64 f20;
        std::vector<ItemEntity> items;
    };
    CGuildXmlData(); virtual ~CGuildXmlData();
    bool FUN_1404d5960();
    bool LoadGuildProperty();
    bool LoadGuildBuff();
    bool LoadGuildEvent();
    bool LoadGuildHouse();
    bool LoadGuildNpc();
    bool LoadGuildRaid();
    bool FUN_1404d6ab0();
    bool LoadGuildQuestRewardFactor();
    bool LoadGuildContribution();
    unsigned FUN_1404d7130(int); int FUN_1404d7200(int); int FUN_1404d7280(); int FUN_1404d72f0();
    float FUN_1404d7360(unsigned short,int); int FUN_1404d73d0(int);
    Unk_PayloadPtr<GuildProperty> FUN_1404d7410(int);
    Unk_PayloadPtr<GuildSkill> FUN_1404d74e0(int,int);
    void FUN_1404d7630(std::vector<int>&); void FUN_1404d7730(std::vector<int>&);
    Unk_PayloadPtr<GuildEvent> FUN_1404d7830(int); void FUN_1404d7900(std::vector<int>&);
    Unk_PayloadPtr<GuildHouse> FUN_1404d79b0(int,int); void FUN_1404d7a90(std::vector<std::pair<int,int>>&);
    Unk_PayloadPtr<GuildNpc> FUN_1404d7b40(Unk_GuildNpcKind,int);
    void FUN_1404d7c20(std::set<Unk_GuildNpcKind>&);
    Unk_PayloadPtr<GuildRaid> FUN_1404d7cb0(unsigned); void FUN_1404d7d80(std::vector<unsigned>&);
    Unk_PayloadPtr<GuildRaidReward> FUN_1404d7e30(int);
    std::map<int,Unk_PayloadPtr<GuildProperty>> property;
    std::map<int,std::vector<Unk_PayloadPtr<GuildSkill>>> skill;
    std::map<int,Unk_PayloadPtr<GuildEvent>> event;
    std::map<std::pair<int,int>,Unk_PayloadPtr<GuildHouse>> house;
    std::map<std::pair<Unk_GuildNpcKind,int>,Unk_PayloadPtr<GuildNpc>> npc;
    std::map<unsigned,Unk_PayloadPtr<GuildRaid>> raid;
    std::map<int,Unk_PayloadPtr<GuildRaidReward>> reward;
    float questFactors[300][5];
    int contribution[10];
};
MS2_CHECK_SIZE(CGuildXmlData,0x1818);
MS2_CHECK_OFFSET(CGuildXmlData,property,0x10);
MS2_CHECK_OFFSET(CGuildXmlData,questFactors,0x80);
MS2_CHECK_OFFSET(CGuildXmlData,contribution,0x17f0);
MS2_CHECK_SIZE(CGuildXmlData::GuildRaidReward,0x40);
MS2_CHECK_SIZE(CGuildXmlData::GuildProperty,0x70);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f20,0x20);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f28,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f30,0x30);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f34,0x34);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f38,0x38);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f3c,0x3c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f40,0x40);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f44,0x44);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f48,0x48);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f4c,0x4c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f50,0x50);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f54,0x54);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f58,0x58);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f5c,0x5c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f60,0x60);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f64,0x64);
MS2_CHECK_OFFSET(CGuildXmlData::GuildProperty,f68,0x68);
MS2_CHECK_SIZE(CGuildXmlData::GuildSkill,0x48);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f20,0x20);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f24,0x24);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f28,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f2c,0x2c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f30,0x30);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f34,0x34);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f38,0x38);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f3c,0x3c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildSkill,f40,0x40);
MS2_CHECK_SIZE(CGuildXmlData::GuildEvent,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildEvent,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildEvent,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildEvent,f20,0x20);
MS2_CHECK_SIZE(CGuildXmlData::GuildHouse,0x68);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f20,0x20);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f24,0x24);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f28,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f2c,0x2c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f30,0x30);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f38,0x38);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f50,0x50);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f58,0x58);
MS2_CHECK_OFFSET(CGuildXmlData::GuildHouse,f60,0x60);
MS2_CHECK_SIZE(CGuildXmlData::GuildNpc,0x38);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f20,0x20);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f28,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f2c,0x2c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildNpc,f30,0x30);
MS2_CHECK_SIZE(CGuildXmlData::GuildRaid,0x28);
MS2_CHECK_OFFSET(CGuildXmlData::GuildRaid,f18,0x18);
MS2_CHECK_OFFSET(CGuildXmlData::GuildRaid,f1c,0x1c);
MS2_CHECK_OFFSET(CGuildXmlData::GuildRaid,f20,0x20);
MS2_CHECK_OFFSET(CGuildXmlData::GuildRaid,f24,0x24);
