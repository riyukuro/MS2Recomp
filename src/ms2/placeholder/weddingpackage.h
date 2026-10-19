// weddingpackage.h - PLACEHOLDER for WeddingPackage (RTTI .?AVWeddingPackage@@, 0x30 bytes) and WeddingHallData (RTTI
// .?AVWeddingHallData@@, 0x78 bytes), the rows of WeddingTable (weddingPackage.xml: a package and its halls). NOT an
// original header. Layouts follow the v2525 reference decomp (work/ext/v2525, include/ms2/commonfiles/WeddingPackage.h /
// WeddingHallData.h: ctors 0x140906ed0 / 0x1409065e0, Read 0x140906f80 / 0x140906740); member names are the XML keys.
#pragma once

#include <afx.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"

class WeddingHallData : public CPtred
{
public:
    WeddingHallData();                                      // 0x1409065e0
    virtual ~WeddingHallData();

    int m_nId;                                              // +0x18 "id"
    int m_nGrade;                                           // +0x1c "grade"
    __int64 m_nMerat;                                       // +0x20 "merat" (the price)
    CString m_strVideoPath;                                 // +0x28 "videoPath"
    CStringW m_strDesc;                                     // +0x30 "desc"
    CStringW m_strIllust;                                   // +0x38 "mcillust"
    unsigned char m_items[0x30];                            // +0x40 the weddingItem / weddingCompleteItem vectors
    unsigned int m_nFieldId;                                // +0x70 "fieldID"
    unsigned int m_nNightFieldId;                           // +0x74 "nightFieldID"

    unsigned int FUN_140906e40(bool bNight);                // the field id (the night field when set and nonzero)
    int FUN_140906e80();                                    // the reservation coupon of the grade (grade 1-3: 0xd4-0xd6, else 0)
};
MS2_CHECK_OFFSET(WeddingHallData, m_nMerat, 0x20);
MS2_CHECK_OFFSET(WeddingHallData, m_nFieldId, 0x70);
MS2_CHECK_SIZE(WeddingHallData, 0x78);

class WeddingPackage : public CPtred
{
public:
    WeddingPackage();                                       // 0x140906ed0
    virtual ~WeddingPackage();

    MS2Ptr<WeddingHallData> FUN_140907110(int nHallId);     // the hall of an id (null: none)

    int m_nId;                                              // +0x18 "id"
    unsigned int m_nPlanner;                                // +0x1c "planner"
    std::map<int, MS2Ptr<WeddingHallData>> m_halls;         // +0x20
};
MS2_CHECK_OFFSET(WeddingPackage, m_nId, 0x18);
MS2_CHECK_SIZE(WeddingPackage, 0x30);
