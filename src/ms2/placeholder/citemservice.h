// citemservice.h - PLACEHOLDER for CItemService (RTTI .?AVCItemService@@, 0x68 bytes). NOT an original header.
// Bases: efd::ISystemService at +0x0, TSingleton<CItemService> at +0x18. The client item efd system service (class id
// 0x0610000a). Owning unit ?\itemservice.cpp; only the ctor is declared.
#pragma once

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CEquipItem;
class PC;

class CItemService : public efd::ISystemService, public TSingleton<CItemService>
{
    EE_DECLARE_CLASS1(CItemService, 0x0610000a, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CItemService();                                                 // 0x141419df0
    virtual ~CItemService();
    virtual const char* GetDisplayName() const;
    MS2Ptr<CEquipItem> FUN_14141a060(CItem* pItem, PC* pPC, __int64 nValue);   // 0x14141a060 create the equip item (equipment.cpp)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_24[0x68 - 0x24];
};
MS2_CHECK_SIZE(CItemService, 0x68);
