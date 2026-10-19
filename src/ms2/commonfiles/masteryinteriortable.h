// masteryinteriortable.h - CMasteryInteriorTable (RTTI name, 0xe0 bytes) and its row types: the ugc housing tables
// Table/masteryUGCHousing.xml (mastery grades), ugcHousingExtendHeight.xml, ugcHousingExtendArea.xml and
// ugcHousingPointReward.xml. A TSingleton created by CGameApp::InitInstance. Header name assumed from the unit path;
// member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

// One <v> row of masteryUGCHousing.xml: the points needed for a grade and the items it unlocks (0x40 bytes).
struct MasteryInteriorInfo : CPtred
{
    MasteryInteriorInfo();                              // 0x1406646e0
    int m_nGrade;                                       // "grade"
    unsigned m_nValue;                                  // "value"
    ATL::CAtlArray<MS2Ptr<ItemEntity> > m_items;        // rewardJobItemID / Rank / Count
};
MS2_CHECK_SIZE(MasteryInteriorInfo, 0x40);

// One <v> row of ugcHousingExtendHeight.xml (0x28 bytes).
struct ExtendHeightInfo : CPtred
{
    ExtendHeightInfo();                                 // 0x140664600
    int m_nHeight;                                      // "height"
    __int64 m_nPrice;                                   // "price"
};
MS2_CHECK_SIZE(ExtendHeightInfo, 0x28);

// One <v> row of ugcHousingExtendArea.xml (0x30 bytes).
struct ExtendAreaInfo : CPtred
{
    ExtendAreaInfo();                                   // 0x1406645a0
    int m_nArea;                                        // "area"
    __int64 m_nPrice;                                   // "price"
    int m_nWidth;                                       // "value" "w,l"
    int m_nLength;
};
MS2_CHECK_SIZE(ExtendAreaInfo, 0x30);

// One <v> row of ugcHousingPointReward.xml (0x38 bytes).
struct InteriorPointReward : CPtred
{
    InteriorPointReward();                              // 0x140664650
    __int64 m_nPoint;                                   // "housingPoint"
    unsigned m_nDropBox;                                // "individualDropBoxId"
    CStringA m_strIcon;                                 // "icon"
    CStringA m_strKey;                                  // "stringKey"
};
MS2_CHECK_SIZE(InteriorPointReward, 0x38);

class CMasteryInteriorTable : public TSingleton<CMasteryInteriorTable>
{
public:
    CMasteryInteriorTable();                            // 0x140661c00
    virtual ~CMasteryInteriorTable();                   // 0x140661d00

    bool Load();                                        // 0x140661d80
    bool LoadMastery();                                 // 0x140661df0
    bool LoadHeight();                                  // 0x140662430
    bool LoadArea();                                    // 0x1406626f0
    bool LoadRewards();                                 // 0x140662ae0
    void AddMastery(__int64& nCurrent, unsigned short& nGrade, __int64 nAmount);    // 0x140662ea0
    void GetInteriorItems(int nLevel, int nJob, ATL::CAtlArray<MS2Ptr<ItemEntity> >& rItems);   // 0x140663010
    unsigned GetMasteryValue(int nGrade);               // 0x1406631b0
    __int64 GetMasteryTotal(unsigned short nGrade, __int64 nCurrent);   // 0x140663250
    bool FindNextHeight(unsigned char nHeight, unsigned char& rNext, __int64& rPrice);   // 0x1406632c0
    bool FindNextArea(unsigned char nArea, unsigned char& rNext, __int64& rPrice, int& rWidth, int& rLength);   // 0x1406633a0
    unsigned GetDropBox(__int64 nPoints);               // 0x1406634b0
    MS2Ptr<MasteryInteriorInfo> GetMastery(unsigned short nGrade);      // 0x1406635c0
    MS2Ptr<InteriorPointReward> GetPointReward(__int64 nPoints);        // 0x140663640
    MS2Ptr<ExtendAreaInfo> GetArea(int nArea);          // 0x140663790
    MS2Ptr<ExtendAreaInfo> GetPreviousArea(int nArea);  // 0x140663820
    MS2Ptr<ExtendAreaInfo> GetNextArea(int nArea);      // 0x140663970
    MS2Ptr<ExtendHeightInfo> GetHeight(int nHeight);    // 0x140663ab0
    MS2Ptr<ExtendHeightInfo> GetPreviousHeight(int nHeight);    // 0x140663b30
    MS2Ptr<ExtendHeightInfo> GetNextHeight(int nHeight);        // 0x140663c80

    int m_nMaxGrade;                                    // +0x08
    ATL::CRBMap<int, MS2Ptr<MasteryInteriorInfo> > m_mapMastery;        // +0x10 by grade
    int m_nMaxHeight;                                   // +0x40
    ATL::CRBMap<int, MS2Ptr<ExtendHeightInfo> > m_mapHeight;            // +0x48 by height
    int m_nMaxArea;                                     // +0x78
    ATL::CRBMap<int, MS2Ptr<ExtendAreaInfo> > m_mapArea;                // +0x80 by area
    ATL::CRBMap<__int64, MS2Ptr<InteriorPointReward> > m_mapReward;     // +0xb0 by housing point
};
MS2_CHECK_SIZE(CMasteryInteriorTable, 0xe0);
