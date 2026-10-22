// ugcmappackageinfo.h - UGCMapPackageInfo / CUGCMapPackageData (RTTI names): a UGC map "package" read from
// ./Data/Xml/ExportedUGCMap/<name>.xml (<ugcmap indoorSizeType=..><cube itemID itemCount offsetCubePoint3 rotation
// wallDir isNotPlace/>...). Header name assumed. Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ms2svrptr.h"

struct Unk_Int3 { int x, y, z; Unk_Int3() = default; Unk_Int3(int, int, int); };       // 12-byte integer cube point (ctor 0x1408a85a0)

// One <cube> row. RTTI UGCMapPackageInfo, 0x38 bytes; vftable 0x142da1f20 (CPtred's slot).
class UGCMapPackageInfo : public CPtred
{
public:
    UGCMapPackageInfo();                    // 0x1408b9860
    virtual ~UGCMapPackageInfo();           // 0x1408ba5d0

    void FUN_1408b98f0(void* pXmlNode);     // read one <cube> element (name invented)

    int m_nItemId;                          // +0x18 "itemID"
    int m_nItemCount;                       // +0x1c "itemCount" (default 1)
    Unk_Int3 m_offsetCubePoint;             // +0x20 "offsetCubePoint3" ("x,y,z")
    float m_fRotation;                      // +0x2c "rotation"
    int m_nWallDir;                         // +0x30 "wallDir"
    bool m_bNotPlace;                       // +0x34 "isNotPlace"
};
MS2_CHECK_SIZE(UGCMapPackageInfo, 0x38);
MS2_CHECK_OFFSET(UGCMapPackageInfo, m_offsetCubePoint, 0x20);
MS2_CHECK_OFFSET(UGCMapPackageInfo, m_bNotPlace, 0x34);

typedef MS2SvrPtr<UGCMapPackageInfo> UGCMapPackageInfoPtr;

// One loaded package. RTTI CUGCMapPackageData, 0x50 bytes, CCacheData-derived; vftable 0x142da1f30 (1 slot).
class CUGCMapPackageData : public CCacheData
{
public:
    CUGCMapPackageData();                   // 0x1408b9a00
    virtual ~CUGCMapPackageData();          // 0x1408b9a60

    int FUN_1408b9ab0(int nItemId);         // number of cubes with that item id (name invented)

    CString m_strIndoorSizeType;            // +0x28 "indoorSizeType"
    ATL::CAtlArray<UGCMapPackageInfoPtr> m_cubes;   // +0x30
};
MS2_CHECK_SIZE(CUGCMapPackageData, 0x50);
MS2_CHECK_OFFSET(CUGCMapPackageData, m_cubes, 0x30);

typedef MS2SvrPtr<CUGCMapPackageData> UGCMapPackageDataPtr;

UGCMapPackageDataPtr FUN_1408b9b90(const CString& strName);     // cached lookup, loads on miss
void FUN_1408b9c90();                                           // clear the cache
UGCMapPackageDataPtr LoadExportedUGCMap(const CString& strName);     // load from xml (inserts into the cache)
