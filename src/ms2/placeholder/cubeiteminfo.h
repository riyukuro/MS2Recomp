#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cugcitemlook.h"

// Heap layouts: CubeItemInfo ctor 1408b3450, Clear 1408b3810 and Copy 1408b3700.
class CInPacket;
class CubeItemInfo : public CPtred {
public:
    CubeItemInfo();
    CubeItemInfo(const CubeItemInfo& src);                                              // 0x1408b34b0
    CubeItemInfo(int itemId, __int64 instanceId, __int64 count, CUgcItemLook* pLook);   // 0x1408b3520
    CubeItemInfo(CInPacket& packet);                                                     // 0x1408b3630 (reads the item)
    virtual ~CubeItemInfo();
    void FUN_1408b3700(const CubeItemInfo*);
    int FUN_1408b3860();
    int itemId;
    __int64 instanceId;
    int count;
    MS2Ptr<CUgcItemLook> look;
};
MS2_CHECK_SIZE(CubeItemInfo, 0x40);
MS2_CHECK_OFFSET(CubeItemInfo, look, 0x30);
