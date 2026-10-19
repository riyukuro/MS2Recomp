// uimeratmarketweapontype.h - PLACEHOLDER for UIMeratMarketCommon::WeaponType (RTTI .?AVWeaponType@UIMeratMarketCommon@@,
// 0x20 bytes, vftable 0x142e64738 with the scalar deleting dtor 0x140ec3730 only). NOT an original header.
// The weapon filter of the merat market tabs (two weapon categories; 0 = none, then the job / gender test applies).
// Its members are in ?\uimeratmarketcommon.cpp; the ctor takes the owner PC (0x140ebb6c0 passes it on to FUN_140ebb730).
// itempreview.cpp and asitemslot.cpp (MS2Ptr<WeaponType> 0x1409c1220..) use it.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class PC;
class CItemData;

namespace UIMeratMarketCommon {

class WeaponType : public CPtred
{
public:
    WeaponType(PC* pOwner);                                 // 0x140ebb6c0
    virtual ~WeaponType();                                  // 0x140ec3500 (scalar deleting 0x140ec3730)
    bool FUN_140ebb730(PC* pOwner);                         // 0x140ebb730 (returns true)
    void FUN_140ebb750();                                   // 0x140ebb750 reset the filter
    bool FUN_140ebb780(int nGender, int nJob, MS2Ptr<CItemData> spData);   // 0x140ebb780 the item passes the filter

    int m_n18;                                              // +0x18 first weapon category
    int m_n1c;                                              // +0x1c second weapon category
};
MS2_CHECK_SIZE(WeaponType, 0x20);

}   // namespace UIMeratMarketCommon
