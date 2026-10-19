// CGemStoneItem: 0x40-byte socket UI record. Constructor 0x140c4dd90,
// setter 0x140c4e720 prove both item handles and the locked-slot flag.
#pragma once
#include "ms2/placeholder/citem.h"
class CGemStoneItem : public CPtred {
public:
    CGemStoneItem();
    virtual ~CGemStoneItem();
    void FUN_140c4e720(MS2Ptr<CItem> equipment, MS2Ptr<CItem> gemstone, bool locked = false);
    bool GetLocked() const { return m_locked; }      // inline COMDAT 0x140cfead0 (gemstoneslot.cpp)
    MS2Ptr<CItem> m_equipment;
    MS2Ptr<CItem> m_gemstone;
    bool m_locked;
};
MS2_CHECK_SIZE(CGemStoneItem, 0x40);
MS2_CHECK_OFFSET(CGemStoneItem, m_equipment, 0x18);
MS2_CHECK_OFFSET(CGemStoneItem, m_gemstone, 0x28);
MS2_CHECK_OFFSET(CGemStoneItem, m_locked, 0x38);
