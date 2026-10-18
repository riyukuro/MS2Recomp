// fishsimultedata.h - the fishing tables: CFishSimulteData (the simulated catch record of a cast), CFishData (one row
// of Table/fish.xml), CFishingRodData (fishingRod.xml), CFishingSpotData (fishingSpot.xml) and the CFishingTable
// singleton that loads them (RTTI names). Owning unit: ?\fishsimultedata.cpp (0x1403b0e30-0x1403b72d0; header name
// assumed from the unit path). Member names are invented from use; the four data classes derive from CPtred and only
// have the deleting destructor as a virtual.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/xmlattr.h"

class CByteBuffer;

// A min / max pair (the exe's ctor is 0x1402fc100 and the setter 0x140303060, both shared COMDATs).
struct Unk_FishRange
{
    Unk_FishRange() : m_nMin(0), m_nMax(0) {}
    void FUN_140303060(unsigned nMin, unsigned nMax) { m_nMin = nMin; m_nMax = nMax; }
    bool FUN_1403b4ef0(unsigned n) const;                           // 0x1403b4ef0 n is inside the range
    unsigned m_nMin;
    unsigned m_nMax;
};
MS2_CHECK_SIZE(Unk_FishRange, 8);

// The catch record of a cast, 0x38 bytes (RTTI CFishSimulteData).
class CFishSimulteData : public CPtred
{
public:
    CFishSimulteData();                                             // 0x1403b0e30
    virtual ~CFishSimulteData();                                    // 0x1403b39f0
    void Write(COutputStream& out);                                 // 0x1403b0ea0
    void Read(CByteBuffer& in);                                     // 0x1403b0f50

    int m_n18;                                                      // +0x18
    int m_n1c;                                                      // +0x1c
    int m_n20;                                                      // +0x20
    int m_aN24[4];                                                  // +0x24
};
MS2_CHECK_SIZE(CFishSimulteData, 0x38);

// One <fish> row of fish.xml, 0x58 bytes (RTTI CFishData).
class CFishData : public CPtred
{
public:
    CFishData();                                                    // 0x1403b1040
    virtual ~CFishData();                                           // 0x1403b39d0
    int Load(Unk_140165cf0* pNode);                                 // 0x1403b1100 the row's attributes (0 when the size ranges are bad)
    bool FUN_1403b14d0(unsigned nSize) const;                       // the size is in the largest class
    unsigned __int64 FUN_1403b1520(unsigned nSize) const;           // the size class (0..3, 4 = none)
    int FUN_1403b1590(unsigned nSize) const;                        // the size class as a 0..3 grade
    CStringW FUN_1403b1600() const;                                 // "./Data/Resource/Image/Fishing/<id>.png"
    CStringW FUN_1403b1650() const;                                 // the name from the string table
    CStringW FUN_1403b16b0(int bDetail) const;                      // tooltip text: habitat maps and the description

    unsigned m_nId;                                                 // +0x18 "id"
    unsigned m_nMastery;                                                 // +0x1c "fishMastery"
    int m_nHabitat;                                                 // +0x20 "habitat" (0..8)
    int m_nRank;                                                    // +0x24 "rank"
    Unk_FishRange m_aSize[4];                                       // +0x28 "smallSize" / "bigSize" classes
    int m_nIgnoreSpotMastery;                                       // +0x48 "ignoreSpotMastery"
    int m_nFishingBook;                                             // +0x4c "fishingBook"
    unsigned m_nCompanion;                                          // +0x50 "companion"
};
MS2_CHECK_SIZE(CFishData, 0x58);
MS2_CHECK_OFFSET(CFishData, m_aSize, 0x28);
MS2_CHECK_OFFSET(CFishData, m_nCompanion, 0x50);

// One <rod> row of fishingRod.xml, 0x40 bytes (RTTI CFishingRodData).
class CFishingRodData : public CPtred
{
public:
    CFishingRodData();                                              // 0x1403b1980
    virtual ~CFishingRodData();                                     // 0x1403b3a10
    bool Load(Unk_140165cf0* pNode);                                // 0x1403b1a20

    unsigned m_nRodCode;                                            // +0x18 "rodCode"
    unsigned m_nMasteryLimit;                                          // +0x1c "fishMasteryLimit"
    unsigned m_nAddMastery;                                          // +0x20 "addFishMastery"
    unsigned m_nReduceTime;                                          // +0x24 "reduceFishingTime"
    CString m_strChair;                                             // +0x28 "chair"
    CString m_strLureEffect;                                        // +0x30 "fishLureEffect"
    CString m_strChairEffect;                                       // +0x38 "fishingChairEffect"
};
MS2_CHECK_SIZE(CFishingRodData, 0x40);

// One <spot> row of fishingSpot.xml, 0x48 bytes (RTTI CFishingSpotData).
class CFishingSpotData : public CPtred
{
public:
    CFishingSpotData();                                             // 0x1403b1b20
    virtual ~CFishingSpotData();                                    // 0x1403b3a60
    bool Load(Unk_140165cf0* pNode);                                // 0x1403b1b90

    unsigned m_nId;                                                 // +0x18 "id"
    unsigned m_nMinMastery;                                         // +0x1c "minMastery"
    unsigned m_nMaxMastery;                                              // +0x20 "maxMastery"
    ATL::CAtlArray<int> m_arrLiquid;                                // +0x28 "liquidType" (the habitat ids)
};
MS2_CHECK_SIZE(CFishingSpotData, 0x48);

typedef MS2Ptr<CFishData> CFishDataPtr;
typedef MS2Ptr<CFishingRodData> CFishingRodDataPtr;
typedef MS2Ptr<CFishingSpotData> CFishingSpotDataPtr;
typedef Unk_BmBoxPtr<ATL::CAtlArray<unsigned int> > CFishMapIdsPtr;

class Unk_FishTextFilter;       // the text post-processor of the UI (0x1416fbf20)

// The table. RTTI CFishingTable, 0x130 bytes: TSingleton +0, CValidData +8 and the four maps. Created by
// CGameApp::InitInstance (?\ms2.cpp).
class CFishingTable : public TSingleton<CFishingTable>, public CValidData<CFishingTable>
{
public:
    CFishingTable();                                                // 0x1403b1d00
    virtual ~CFishingTable();                                       // 0x1403b1e60

    int Load();                                                     // 0x1403b1f00 the four xml files (0 on the first failure)
    int FUN_1403b1f70(const CStringW& strHabitat);                  // habitat name -> id (8 = unknown)
    CStringW FUN_1403b20b0(int nHabitat);                           // habitat id -> string table text
    CStringW FUN_1403b2240(int n);                                  // string table text 0xbba + n
    int LoadFish();                                                 // 0x1403b2540 fish.xml
    int LoadRods();                                                 // 0x1403b27e0 fishingRod.xml
    int LoadSpots();                                                // 0x1403b22a0 fishingSpot.xml
    int LoadHabitats();                                             // 0x1403b2a80 fishHabitat.xml
    CFishDataPtr GetFish(int nId);                                  // 0x1403b2d30
    CFishingRodDataPtr GetRod(int nId);                             // 0x1403b2dc0
    CFishingSpotDataPtr GetSpot(int nId);                           // 0x1403b2e50
    CStringW FUN_1403b2ee0(unsigned nFishId);                       // "$map:<id>$, ..." of the (up to three) maps of a fish
    void FUN_1403b30b0(ATL::CAtlArray<unsigned int>* pOut, int nHabitat, int bBookOnly);   // fish ids of a habitat

    static void CheckInit();                                        // 0x1403b3f70
    static void SetInit(bool b);                                    // 0x1403b6cf0
    static Unk_FishTextFilter* GetTextFilter() { return s_pTextFilter; }   // 0x1403b4750

    static bool s_bInit;                                            // DAT_143aaece8
    static Unk_FishTextFilter* s_pTextFilter;                       // DAT_143aaecf0

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<int, CFishDataPtr> m_mapFish;                      // +0x10
    ATL::CAtlMap<int, CFishingRodDataPtr> m_mapRod;                 // +0x58
    ATL::CAtlMap<int, CFishingSpotDataPtr> m_mapSpot;               // +0xa0
    ATL::CAtlMap<unsigned int, CFishMapIdsPtr> m_mapMaps;           // +0xe8 fish id -> the ids of its maps
};
MS2_CHECK_SIZE(CFishingTable, 0x130);
MS2_CHECK_OFFSET(CFishingTable, m_mapFish, 0x10);
MS2_CHECK_OFFSET(CFishingTable, m_mapRod, 0x58);
MS2_CHECK_OFFSET(CFishingTable, m_mapSpot, 0xa0);
MS2_CHECK_OFFSET(CFishingTable, m_mapMaps, 0xe8);
