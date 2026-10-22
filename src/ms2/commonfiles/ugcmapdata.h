// Shared cube-map declarations. Layouts proved by constructors and XML stores.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/placeholder/cptred.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include <NiPoint3.h>

struct Unk_UGCGroup {
    Unk_UGCGroup();
    int FUN_1408ad2c0();
    int FUN_1408ad2f0();
    int contractPrice;
    unsigned contractPriceItemCode;
    int extensionPrice;
    unsigned extensionPriceItemCode;
    int contractDate,extensionDate,heightLimit,buildingCount;
    int sellType,indoorCount,blockCode,houseNumber,field30;
    CString previewIcon;
    int buildingType;
    std::vector<unsigned> privilegeNPC;
    std::vector<int> privilegePortal,privilegeInteract;
    int privilegeTaxi,returnPlaceID,maidCount,installNpcCount,hideEmoticon;
    unsigned trophyID;
    bool adminOnly;
    int triggerCount;
    CString indoorSizeType;
    int useCouponEvent;
};
MS2_CHECK_SIZE(Unk_UGCGroup,0xc0);
MS2_CHECK_OFFSET(Unk_UGCGroup,previewIcon,0x38);
MS2_CHECK_OFFSET(Unk_UGCGroup,privilegeNPC,0x48);
MS2_CHECK_OFFSET(Unk_UGCGroup,privilegeTaxi,0x90);
MS2_CHECK_OFFSET(Unk_UGCGroup,adminOnly,0xa8);
MS2_CHECK_OFFSET(Unk_UGCGroup,indoorSizeType,0xb0);
struct Unk_UGCFloor {
    Unk_UGCFloor() { startHeight=0; field4=0; }
    float startHeight;
    int field4;
};
MS2_CHECK_SIZE(Unk_UGCFloor,8);
class CUGCMapData : public CPtred {
public:
    CUGCMapData();
    virtual ~CUGCMapData();
    std::map<int,Unk_UGCGroup> groups;
    std::map<int,Unk_UGCFloor> floors;
};
MS2_CHECK_SIZE(CUGCMapData,0x38);
MS2_CHECK_OFFSET(CUGCMapData,groups,0x18);
MS2_CHECK_OFFSET(CUGCMapData,floors,0x28);
class CubeOwner : public CPtred {
public:
    CubeOwner(int map,int block,__int64 owner,CStringW name) {
        mapID=map; blockID=block; ownerID=owner; ownerName=name;
    }
    virtual ~CubeOwner()=default;
    int mapID,blockID;
    __int64 ownerID;
    CStringW ownerName;
};
MS2_CHECK_SIZE(CubeOwner,0x30);
MS2_CHECK_OFFSET(CubeOwner,ownerName,0x28);
typedef Unk_PayloadPtr<CUGCMapData> Unk_UGCMapPtr;
typedef Unk_PayloadPtr<CubeOwner> Unk_CubeOwnerPtr;
typedef std::map<int,Unk_CubeOwnerPtr> Unk_CubeOwnerMap;
typedef std::map<int,Unk_CubeOwnerMap> Unk_CubeOwners;
Unk_UGCMapPtr FUN_1408ad3f0(int);
Unk_UGCMapPtr LoadUGCMap(unsigned);
