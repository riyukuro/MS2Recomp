// fielddata.h - CFieldData (RTTI .?AVCFieldData@@), the per-map record of ./Data/Xml/Table/fieldData.xml.
// Recovered shared header (w3o3, 2026-10-15); owner unit ?\fielddata.cpp (0x1403727d0-0x14037bf80 .text$mn,
// 0x1400b6150-0x1400b6260 .text$di; probably commonfiles\fielddata.cpp: it sorts between featuremanager and
// fieldmissiontable). Implementation recovered by a3 in fielddata.cpp.
//
// HOW TO USE (Sonnet workers):
//   #include "ms2/commonfiles/fielddata.h"
//   - Derive from it (CFieldDataCli : CFieldData, ?\fielddatacli.cpp) or read its public members by name.
//   - Ctor/dtor/vfunc_1/vfunc_2 and table accessors are owned by fielddata.cpp; other isolated units bind through
//     progress/symbols-manual.tsv (ctor/dtor/vfuncs) or the FUN_<va> auto-binding (statics). Do NOT define them in
//     another unit. An override calls the base as `CFieldData::vfunc_1(node)`.
//   - The XML node type is the game's TinyXML element, spelled `Unk_140165cf0` like the done units
//     (FirstChildElement = Unk_140165cf0::FUN_140165cf0). Only forward-declared here, so a unit may still define its
//     local `class Unk_140165cf0 { ... };` after including this header.
//   - Do not change the slot list or the layout. If a layout is proven wrong, report it to the coordinator.
//
// Proven (exe):
//   - sizeof 0x160: ??_G 0x1403779d0 (no sized delete) and CFieldDataCli = 0x260 with its own members from +0x160
//     (CFieldDataCli ctor 0x140a54160 calls this ctor, then stores from +0x160); 4,648-size table says 352.
//   - vftable 0x142d2ef78, 3 slots: 0 ??_G 0x1403779d0, 1 Load 0x140374530, 2 GetCapacity 0x1403757a0.
//   - bases: CObjectCount<CFieldData> (empty, RTTI offset 24) and CPtred @0 (ctor 0x140159740 called first).
//   - ctor 0x1403738d0 (member order and initial values below), dtor 0x140373c90 (destroys +0xe8, +0xd0, +0x80, +0x30,
//     +0x28, +0x20, then ~CPtred: so the members are declared in this order).
//   - member names = the fieldData.xml attribute each one is read from in vfunc_1 (0x140374530); the vector element
//     types from their COMDATs (+0x80/+0xd0: std::vector<unsigned> ctor 0x140182ed0 / dtor 0x140183b90, harvested
//     from a matched unit; +0xe8: 2-byte elements, size() 0x14037bf00 shifts by 1, ctor 0x1403771d0, dtor 0x140377640,
//     filled by Tokenize + a 2-byte conversion, so short is assumed (signedness unproven)).
//   - XML reader wrappers used by vfunc_1 (by value type): 0x140873220 unsigned, 0x1408731e0 int, 0x1408731a0 short,
//     0x140873360 float, 0x1408730a0 / 0x1408736d0 bool (QueryBoolAttribute), 0x1408733e0 CString,
//     0x140375a40 / 0x140375ad0 enum (int-sized, exploreType / tutorialType).
// Unproven: the real method names (vfunc_1 = Load, vfunc_2 = GetCapacity invented), m_unk_1c / m_unk_148 meaning,
//   the exact enum types of +0x68 / +0x140 / +0x144, short vs unsigned short at +0xbe/+0xc0/+0xe8.
//
// The unit also holds the table: a static CAtlMap<unsigned, MS2Ptr<CFieldData>> at 0x143aaec00 (ctor 0x140376c60, 17 bins,
// 0.75/0.25/2.25, block 10; cleared by 0x14037a2d0) guarded by a lock at 0x143aaebc8, and the classes CStarting,
// CNpcSpawnData, CFieldSpawnTag, TPtredDummy<CRBMap<int,TPtr<CFieldSpawnTag>>> (not declared here). The loader
// 0x140373d50 creates `new CFieldDataCli` (0x260) for every <fieldData> element, sets m_nFieldID, calls vfunc_1.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T> (16-byte intrusive pointer of CPtred objects)
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/placeholder/cptred.h"

class Unk_140165cf0;   // game TinyXML element (TiXmlElement/TiXmlNode); FirstChildElement = FUN_140165cf0

class CFieldData : public CObjectCount<CFieldData>, public CPtred
{
public:
    CFieldData();                                   // 0x1403738d0
    virtual ~CFieldData();                          // slot 0: ??_G 0x1403779d0, dtor 0x140373c90
    // slot 1 (0x140374530): reads the <fieldData> element's children (<locale>, <feature>, <xblock>, <property>, a
    // drop node, <split>, <camera>, <cashCall>, <indoor>). Returns false when <xblock> is empty or channelGroupID is
    // out of 0..7 or the entrance buff ID/level counts differ.
    virtual bool vfunc_1(Unk_140165cf0* node);
    // slot 2 (0x1403757a0): return m_nCapacity.
    virtual int vfunc_2();

    // --- table accessors (static in the unit; names invented, bound by FUN_<va>) ---
    // 0x140373d30: clear the table (CAtlMap::RemoveAll on 0x143aaec00).
    static void FUN_140373d30();
    // 0x140373d50: load ./Data/Xml/Table/fieldData.xml into the table.
    static void LoadFieldData();
    // 0x140374090: append every table entry to out (vector::push_back 0x14037bed0), under the table lock.
    static void FUN_140374090(std::vector<MS2Ptr<CFieldData> >& out);
    // 0x140374140: look up a field id (0 -> null; logs "FieldID : {0}" when missing).
    static MS2Ptr<CFieldData> FUN_140374140(int fieldId);
    // 0x140374270: find the entry whose m_strXBlock equals xblock (case-insensitive compare 0x1401c0090).
    static MS2Ptr<CFieldData> FUN_140374270(CString xblock);
    // 0x1403743e0: FUN_1403744a0(this->m_nFieldID). Non-static.
    bool FUN_1403743e0();
    // 0x140374410 / 0x1403744a0: lookup(fieldId)->m_nMapType == 3 / == 9 (false when not found).
    static bool FUN_140374410(int fieldId);
    static bool FUN_1403744a0(int fieldId);

    // Recovered predicates and accessors (appended by a3; the shared layout is unchanged).
    bool FUN_140375100(); bool FUN_140375130(); bool FUN_140375170(); bool FUN_140375190();
    bool FUN_1403751b0(); bool FUN_140375270(); bool FUN_1403752c0(); bool HasTutorialType();
    int GetContinentCode(); int GetRegionCode();
    int FUN_140375390(); int FUN_1403753d0(); int FUN_140375410(); int FUN_140375450(); int FUN_140375490();
    int GetPkMode(); int FUN_1403754f0();
    int FUN_140375570(); int FUN_1403755a0(); int GetOnlyDarkTomb();
    int FUN_140375660(unsigned); int FUN_140375690(void*); bool FUN_1403756c0(unsigned);
    bool FUN_1403756f0(); int FUN_140375740(); int GetMapType(); int FUN_1403757c0(); unsigned GetSetItemRestrainId();

public:
    MS2_LAYOUT_FRIEND;
    int m_nFieldID;                     // +0x18 set by the loader from the <fieldData> id attribute
    int m_unk_1c;                       // +0x1c padding? (never written by the ctor)
    CStringW m_strFeature;              // +0x20 "feature"
    CString m_strLocale;                // +0x28 "locale"
    CString m_strXBlock;                // +0x30 <xblock> name (the map's xblock; table lookup key of 0x140374270)
    unsigned m_nRevivalReturnId;        // +0x38 "revivalreturnid" (defaults to m_nFieldID when 0)
    unsigned m_nEnterReturnId;          // +0x3c "enterreturnid"
    unsigned m_nMapCategoryCode;        // +0x40 "mapCategoryCode"
    int m_nContinentCode;               // +0x44 "continentCode"
    int m_nRegionCode;                  // +0x48 "regionCode"
    int m_nMapType;                     // +0x4c "mapType" (3 / 9 tested by 0x140374410 / 0x1403744a0)
    int m_nBigCity;                     // +0x50 "bigCity"
    int m_nGlobalSplit;                 // +0x54 <split> "globalSplit"
    int m_nIndoorMask;                  // +0x58 1, or 1 << <indoor> value (set by vfunc_1 only, not by the ctor)
    int m_nHomeReturnable;              // +0x5c "homeReturnable" = 1
    int m_nDeathPenalty;                // +0x60 "deathPenalty" = 1
    int m_nMinimapInvisible;            // +0x64 "minimapInvisible"
    int m_nAutoRevivalType;             // +0x68 "autoRevivalType" (read into an int local, then stored: an enum?)
    int m_nAutoRevivalTime;             // +0x6c "autoRevivalTime"
    int m_nOnlyDarkTomb;                // +0x70 "onlyDarkTomb"
    unsigned m_nMapLevel;               // +0x74 "maplevel"
    unsigned m_nDropRank;               // +0x78 "dropRank"
    int m_pad_7c;                       // +0x7c
    std::vector<unsigned> m_globalDropBoxIds;   // +0x80 "globalDropBoxID"
    unsigned m_nLimitContent;           // +0x98 "limitContent"
    bool m_bMapSearch;                  // +0x9c "mapSearch" = true
    int m_nFallDamage;                  // +0xa0 = 1 (read by CFieldDataCli: "fallDamage")
    int m_nUseEPSkill;                  // +0xa4 = 1 ("useEPSkill", CFieldDataCli)
    int m_nUsePet;                      // +0xa8 = 1 ("usePet", CFieldDataCli)
    int m_nUseRidee;                    // +0xac = 1 ("useRidee", CFieldDataCli)
    int m_nUseOptimalHide;              // +0xb0 = 1 ("useOptimalHide", CFieldDataCli)
    int m_nPkMode;                      // +0xb4 "pkMode"
    int m_nAutoFindTaxiStation;         // +0xb8 = 1 ("autoFindTaxiStation", CFieldDataCli)
    bool m_bBigDataCharacterSkillUseLog;    // +0xbc "bigDataCharacterSkillUseLog"
    short m_nEnterMinLevel;             // +0xbe "enterMinLevel"
    short m_nEnterMaxLevel;             // +0xc0 "enterMaxLevel"
    int m_nMassiveEventField;           // +0xc4 "massiveEventField"
    int m_nRecoveryFullHP;              // +0xc8 "recoveryFullHP"
    std::vector<unsigned> m_enteranceBuffIds;   // +0xd0 "enteranceBuffIDs"
    std::vector<short> m_enteranceBuffLevels;   // +0xe8 "enteranceBuffLevels" (count must equal +0xd0's)
    int m_nEnterAdminLevel;             // +0x100 "enterAdminLevel"
    int m_nChannelGroupId;              // +0x104 "channelGroupID" (0..7)
    int m_nWebFinder;                   // +0x108 "webFinder"
    int m_nCashTaxiNotDeparture;        // +0x10c <cashCall> "cashTaxiNotDeparture"
    int m_nCashTaxiNotDestination;      // +0x110 "cashTaxiNotDestination"
    int m_nCashCallMedicProhibit;       // +0x114 "cashCallMedicProhibit"
    int m_nCashCallMarketProhibit;      // +0x118 "cashCallMarketProhibit"
    int m_nRecallOtherUserProhibit;     // +0x11c "RecallOtherUserProhibit"
    int m_nCheckFly;                    // +0x120 "checkFly"
    int m_nCheckClimb;                  // +0x124 "checkClimb" = 1
    unsigned m_nLimitMove;              // +0x128 "limitMove"
    int m_nCheckPartyObserve;           // +0x12c "checkPartyObserve"
    int m_nDoNotRevivalHere;            // +0x130 "doNotRevivalHere"
    float m_fCubeSkillIntervalTime;     // +0x134 "cubeSkillIntervalTime" (clamped to >= 0.1f when non-zero)
    unsigned m_nSkillUseDisableMask;    // +0x138 |= 1 << each "skillUseDisable" entry
    int m_nInfinityMeratRevival;        // +0x13c "infinityMeratRevival" = 1
    int m_nExploreType;                 // +0x140 "exploreType" (enum)
    int m_nTutorialType;                // +0x144 "tutorialType" (enum)
    int m_unk_148;                      // +0x148 = 0, not read by vfunc_1
    unsigned m_nRequireQuest;           // +0x14c "requireQuest"
    bool m_bMinimapPing;                // +0x150 "minimapPing"
    bool m_bPopupMenu;                  // +0x151 "popupMenu" = true
    bool m_bGemSystem;                  // +0x152 "gemSystem" = true
    float m_fCameraHAngle;              // +0x154 <camera> "hangle" = 45.0f
    unsigned m_nSetItemRestrainId;      // +0x158 "setItemRestrainID"
    int m_nCapacity;                    // +0x15c "capacity" (vfunc_2)
};
MS2_CHECK_SIZE(CFieldData, 0x160);
MS2_CHECK_OFFSET(CFieldData, m_nFieldID, 0x18);
MS2_CHECK_OFFSET(CFieldData, m_strFeature, 0x20);
MS2_CHECK_OFFSET(CFieldData, m_strXBlock, 0x30);
MS2_CHECK_OFFSET(CFieldData, m_nMapType, 0x4c);
MS2_CHECK_OFFSET(CFieldData, m_globalDropBoxIds, 0x80);
MS2_CHECK_OFFSET(CFieldData, m_bMapSearch, 0x9c);
MS2_CHECK_OFFSET(CFieldData, m_nFallDamage, 0xa0);
MS2_CHECK_OFFSET(CFieldData, m_bBigDataCharacterSkillUseLog, 0xbc);
MS2_CHECK_OFFSET(CFieldData, m_nEnterMinLevel, 0xbe);
MS2_CHECK_OFFSET(CFieldData, m_nMassiveEventField, 0xc4);
MS2_CHECK_OFFSET(CFieldData, m_enteranceBuffIds, 0xd0);
MS2_CHECK_OFFSET(CFieldData, m_enteranceBuffLevels, 0xe8);
MS2_CHECK_OFFSET(CFieldData, m_nEnterAdminLevel, 0x100);
MS2_CHECK_OFFSET(CFieldData, m_nCheckFly, 0x120);
MS2_CHECK_OFFSET(CFieldData, m_fCubeSkillIntervalTime, 0x134);
MS2_CHECK_OFFSET(CFieldData, m_nRequireQuest, 0x14c);
MS2_CHECK_OFFSET(CFieldData, m_bMinimapPing, 0x150);
MS2_CHECK_OFFSET(CFieldData, m_fCameraHAngle, 0x154);
MS2_CHECK_OFFSET(CFieldData, m_nCapacity, 0x15c);
