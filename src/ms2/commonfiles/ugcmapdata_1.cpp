// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ugcmapdata.cpp#1
// MS2-RANGE: 0x1408a0190-0x1408ad320 .text$mn
// MS2-RANGE: 0x1400bdf00-0x1400bdfc0 .text$di
// MS2-RANGE: 0x142c9c980-0x142c9c9b0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1408a1a70 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHUUnk_UGCGroup@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1408a1f00 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1408a1f50 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@HV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1408a1fa0 ; unique
// MS2-PIN: ??$_Pocca@V?$allocator@H@std@@@std@@YAXAEAV?$allocator@H@0@AEBV10@@Z 0x1408a70b0 ; prop
// MS2-PIN: ??$_Pocca@V?$allocator@H@std@@@std@@YAXAEAV?$allocator@H@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1408a70e0 ; prop
// MS2-PIN: ??$_Pocca@V?$allocator@I@std@@@std@@YAXAEAV?$allocator@I@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1408a7120 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1408a8400 ; prop
// MS2-PIN: ??0?$allocator@I@std@@QEAA@XZ 0x1408a8410 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x1408ab1f0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@I@2@XZ 0x1408ab2d0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x1408ab3b0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAPEAIXZ 0x1408abaa0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x1408abb40 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??B?$SmartPointer@VEntity@egf@@@efd@@QEBAPEAVEntity@egf@@XZ 0x1408a9090
// MS2-PIN: ??4?$vector@HV?$allocator@H@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1408a8ac0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcmapdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcmapdata.h"
#include "fielddata.h"
#include "hook/ms2hook.h"
#include <efd/ServiceManager.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2color.h"
#include "ms2/placeholder/ms2ptr_impl.h"

static CString s_sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
// Earlier objects own these shared bodies.
template<> Unk_PayloadPtr<CFieldData>::~Unk_PayloadPtr();
template<> bool Unk_PayloadPtr<CFieldData>::operator==(CFieldData*)const;
template<> CFieldData* Unk_PayloadPtr<CFieldData>::operator->()const;
template<> Unk_PayloadPtr<CUGCMapData>::Unk_PayloadPtr(const Unk_PayloadPtr&);
Unk_PayloadPtr<CFieldData> FUN_140374140(unsigned);
void* FUN_1401c0d90();
void FUN_14047ddd0(void*,int,int,__int64);
unsigned FUN_140479720(void*);
unsigned FUN_140479870(void*);
bool FUN_14053f8c0(unsigned);
bool FUN_14053f940(unsigned);
Unk_Int3* FUN_1408850a0(Unk_Int3*);
float FUN_14059d930(float);
class PCBase;
extern char DAT_143b059e8;
class Unk_UgcPhysSvc {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    void FUN_1410bb610(int mode,PCBase* player,float distance,std::vector<efd::SmartPointer<egf::Entity> >& hits);
};
class Unk_UgcPhysSvcRef {
public:
    Unk_UgcPhysSvcRef(Unk_UgcPhysSvc* svc) { m_p=svc; if(m_p) m_p->vfunc_1(); }
    ~Unk_UgcPhysSvcRef();
    Unk_UgcPhysSvc* FUN_1401cd1a0();
    Unk_UgcPhysSvc* m_p;
};
void FUN_1401cd150(Unk_UgcPhysSvcRef*);
Unk_UgcPhysSvcRef::~Unk_UgcPhysSvcRef() { FUN_1401cd150(this); }
Unk_UgcPhysSvc* FUN_1401cd040(char*);
class Unk_UgcWorld { public: PCBase* FUN_141bd0cc0(); };
Unk_UgcWorld* FUN_1403ed2d0();
int FUN_1408b4f20(Cube*);
MS2Ptr<CItemData> FUN_14053f870(int);
void FUN_140194470(void*,const void*);
void FUN_1402237c0(Unk_IntArr*);
__int64 FUN_141656a80(PCBase*);

// @0x1408a0190
unsigned FUN_1408a0190(int type) {
    switch(type) {
    case 3: return 1;
    case 4: return 2;
    case 5: case 6: case 7: return 4;
    default: return 0;
    }
}
MS2_REPLACE(0x1408a0190, FUN_1408a0190, 69, 0x79BD809D);
// @0x1408a01e0
int FUN_1408a01e0(CString text) {
    int result=0;
    if(text=="Ground") result=1;
    else if(text=="Building") result=2;
    else if(text=="Object") result=4;
    else if(text=="Fluid") result=0x40;
    return result;
}
MS2_REPLACE(0x1408a01e0, FUN_1408a01e0, 179, 0x0FBBC392);
// @0x1408a02a0
int FUN_1408a02a0(CString text) {
    if(text=="TrigonalPrism") return 1;
    else if(text=="MovableUnder") return 2;
    else if(text=="HalfCube") return 3;
    return 0;
}
MS2_REPLACE(0x1408a02a0, FUN_1408a02a0, 184, 0x75D22760);
// @0x1408a0370
int FUN_1408a0370(int x,int y,int z) { int result=(x&0xff)+((y&0xff)<<8)+((z&0xff)<<16); return result; }
MS2_REPLACE(0x1408a0370, FUN_1408a0370, 67, 0xE97E08EA);
// @0x1408a03c0
int FUN_1408a03c0(const Unk_Int3& p) { return FUN_1408a0370(p.x,p.y,p.z); }
MS2_REPLACE(0x1408a03c0, FUN_1408a03c0, 43, 0xFDC1CB50);
// @0x1408a0400
Unk_Int3 FUN_1408a0400(int packed) {
    Unk_Int3 p; FUN_1408850a0(&p);
    p.x=(char)(packed&0xff); p.y=(char)((packed>>8)&0xff); p.z=(char)((packed>>16)&0xff);
    return p;
}
MS2_REPLACE(0x1408a0400, FUN_1408a0400, 111, 0x0E4D8B28);
// @0x1408a0480
void FUN_1408a0480(Cube* cube) {
    if(FUN_1408b4f20(cube)==0) return;
    MS2Ptr<CItemData> item=FUN_14053f870(FUN_1408b4f20(cube));
    if(item.get()!=0) {
        cube->field58=item->install.placeable;
        cube->field64=item->install.unchangeable;
        cube->field5c=item->install.stackable;
        cube->field60=item->install.attachable;
        cube->field74=item->install.cannotStackAttach;
        cube->field68=item->install.wall;
        cube->field6c=item->install.generatePhysX;
        cube->field70=item->install.cubeProp;
        FUN_140194470(&cube->offset,&item->install.physXdimension);
        cube->textA0=item->install.mapAttribute;
        cube->fieldAc=item->install.space;
        cube->fieldB0=item->install.animatable;
        cube->fieldB4=item->install.objCode;
        cube->fieldB8=item->install.staticAngle;
        if(item->install.propCollisionGroup==0) cube->fieldA8=9;
        else cube->fieldA8=item->install.propCollisionGroup;
    }
}
MS2_REPLACE(0x1408a0480, FUN_1408a0480, 534, 0xB42E0BC4);
// @0x1408a06a0
bool FUN_1408a06a0(int mapID,int group) {
    Unk_UGCMapPtr p=FUN_1408ad3f0(mapID);
    if(p==0) return false;
    if(p->groups.find(group)==p->groups.end()) return false;
    Unk_UGCGroup& info=p->groups[group];
    return info.adminOnly;
}
MS2_REPLACE(0x1408a06a0, FUN_1408a06a0, 257, 0x22A131A0);
// @0x1408a07b0
void FUN_1408a07b0(int mapID,int blockID,__int64 ownerID) {
    FUN_14047ddd0(FUN_1401c0d90(),mapID,blockID,ownerID);
}
MS2_REPLACE(0x1408a07b0, FUN_1408a07b0, 49, 0x301F651E);
// @0x1408a07f0
bool FUN_1408a07f0(unsigned mapID) {
    Unk_PayloadPtr<CFieldData> p=FUN_140374140(mapID);
    if(p==0) return false;
    return p->m_nMassiveEventField==1;
}
MS2_REPLACE(0x1408a07f0, FUN_1408a07f0, 139, 0x6AAD10DC);
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
// @0x1408a0890
int FUN_1408a0890(int mapID,int group,int* result) {
    Unk_UGCMapPtr p=FUN_1408ad3f0(mapID);
    if(p==0) return 0;
    if(!(p==0)) {
        if(p->groups.find(group)!=p->groups.end()) {
            *result=p->groups[group].sellType;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x1408a0890, FUN_1408a0890, 303, 0x384A4FFD);
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
// @0x1408a09d0
int FUN_1408a09d0(unsigned* item,__int64* price,int mapID,int group) {
    *price=0;
    int result=0;
    Unk_UGCMapPtr p=FUN_1408ad3f0(mapID);
    if(p.get()!=0) {
        if(p->groups.find(group)!=p->groups.end()) {
            result=1;
            *item=p->groups[group].contractPriceItemCode;
            *price=p->groups[group].contractPrice;
            if(FUN_14053f8c0(*item) || FUN_14053f940(*item)) {
                void* manager=FUN_1401c0d90();
                unsigned discount=FUN_140479720(manager);
                *price=*price-(__int64)(*price*(unsigned __int64)discount)/10000;
            }
        }
    }
    return result;
}
MS2_REPLACE(0x1408a09d0, FUN_1408a09d0, 417, 0xBB65AC27);
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
// @0x1408a0b80
int FUN_1408a0b80(unsigned* item,__int64* price,int mapID,int group) {
    *price=0;
    int result=0;
    Unk_UGCMapPtr p=FUN_1408ad3f0(mapID);
    if(p.get()!=0) {
        if(p->groups.find(group)!=p->groups.end()) {
            result=1;
            *item=p->groups[group].extensionPriceItemCode;
            *price=p->groups[group].extensionPrice;
            if(FUN_14053f8c0(*item) || FUN_14053f940(*item)) {
                void* manager=FUN_1401c0d90();
                unsigned discount=FUN_140479870(manager);
                *price=*price-(__int64)(*price*(unsigned __int64)discount)/10000;
            }
        }
    }
    return result;
}
MS2_REPLACE(0x1408a0b80, FUN_1408a0b80, 418, 0x255B7FA3);
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
// @0x1408a0d30
int FUN_1408a0d30(int group,Unk_UGCGroup& result,int mapID) {
    Unk_UGCMapPtr p(0);
    if(mapID==0) return 0;
    p=FUN_1408ad3f0(mapID);
    if(p==0) return 0;
    if(p->groups.find(group)==p->groups.end()) return 0;
    result=p->groups[group];
    return 1;
}
MS2_REPLACE(0x1408a0d30, FUN_1408a0d30, 376, 0x7AAFE732);
// @0x1408a0eb0
void FUN_1408a0eb0(Unk_CubeOwners& owners,int mapID,int blockID) {
    if(owners.find(mapID)==owners.end()) return;
    Unk_CubeOwnerMap& blocks=owners[mapID];
    if(blocks.find(blockID)==blocks.end()) return;
    blocks.erase(blockID);
    if(blocks.size()==0) owners.erase(mapID);
}
MS2_REPLACE(0x1408a0eb0, FUN_1408a0eb0, 227, 0x51696E03);
// @0x1408a0fa0
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners,int mapID,int blockID) {
    if(owners.find(mapID)==owners.end()) return Unk_CubeOwnerPtr(0);
    Unk_CubeOwnerMap& blocks=owners[mapID];
    if(blocks.find(blockID)==blocks.end()) return Unk_CubeOwnerPtr(0);
    return blocks[blockID];
}
MS2_REPLACE(0x1408a0fa0, FUN_1408a0fa0, 302, 0xE574321C);
// Not hooked: constructs CubeOwner with DLL-local RTTI.
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
void FUN_1408a10e0(Unk_CubeOwners& owners,int mapID,int blockID,const CStringW& name,__int64 ownerID);
#ifndef MS2_HOOK_DLL
// @0x1408a10e0
void FUN_1408a10e0(Unk_CubeOwners& owners,int mapID,int blockID,const CStringW& name,__int64 ownerID) {
    Unk_CubeOwnerPtr p=FUN_1408a0fa0(owners,mapID,blockID);
    if(p==0) {
        p=new CubeOwner(mapID,blockID,ownerID,name);
        if(owners.find(mapID)==owners.end()) {
            Unk_CubeOwnerMap empty;
            owners[mapID]=empty;
        }
        Unk_CubeOwnerMap& blocks=owners[mapID];
        if(blocks.find(blockID)==blocks.end()) blocks[blockID]=p;
    } else {
        p->mapID=mapID; p->blockID=blockID; p->ownerID=ownerID; p->ownerName=name;
    }
}
#endif
// @0x1408a1360
int FUN_1408a1360(const NiPoint3& a,const NiPoint3& b) { int x=(int)(a.z/150.0f); int y=(int)(b.z/150.0f); return x==y; }
MS2_REPLACE(0x1408a1360, FUN_1408a1360, 100, 0x09C21056);
Unk_Int3 FUN_1408a1430(NiPoint3);
// MS2-FUNCTIONAL: reviewed branches and side effects; compiler temporaries differ.
// @0x1408a13d0
int FUN_1408a13d0(NiPoint3 p) { Unk_Int3 cube; cube=FUN_1408a1430(p); return FUN_1408a03c0(cube); }
MS2_REPLACE(0x1408a13d0, FUN_1408a13d0, 81, 0x560BD7D8);
// @0x1408a1430
Unk_Int3 FUN_1408a1430(NiPoint3 p) {
    Unk_Int3 result; FUN_1408850a0(&result);
    result.x=(int)(p.x/150.0f); result.y=(int)(p.y/150.0f); result.z=(int)(p.z/150.0f);
    return result;
}
MS2_REPLACE(0x1408a1430, FUN_1408a1430, 135, 0xE7BE9A17);
// @0x1408a14c0
Unk_Int3 FUN_1408a14c0(NiPoint3 p) {
    Unk_Int3 result; FUN_1408850a0(&result);
    result.x=(int)((FUN_14059d930(p.x)+75.0f)/150.0f);
    result.y=(int)((FUN_14059d930(p.y)+75.0f)/150.0f);
    result.z=(int)(p.z/150.0f);
    if(p.x<0.0f) result.x=-result.x;
    if(p.y<0.0f) result.y=-result.y;
    if(p.z<0.0f) --result.z;
    return result;
}
MS2_REPLACE(0x1408a14c0, FUN_1408a14c0, 232, 0xDF76819B);
// @0x1408a15b0
NiPoint3 FUN_1408a15b0(const Unk_Int3& p,NiPoint3& out) {
    out.x=(float)p.x*150.0f; out.y=(float)p.y*150.0f; out.z=(float)p.z*150.0f;
    return out;
}
MS2_REPLACE(0x1408a15b0, FUN_1408a15b0, 124, 0x4D11513D);
// @0x1408a1640
void FUN_1408a1640(Cube* cube) {
    int unusedA=0;
    int objCode=0;
    bool wall=false;
    bool unchangeable=false;
    bool field74=false;
    egf::PropertyResult result=(egf::PropertyResult)0;
    egf::Entity* entity=cube->entity;
    result=entity->GetPropertyValue(0xa4c827fd,unusedA);
    result=entity->GetPropertyValue(0xc30cd7b2,objCode);
    result=entity->GetPropertyValue(0xd06a740b,wall);
    result=entity->GetPropertyValue(0xde9ecdb6,unchangeable);
    result=entity->GetPropertyValue(0xe599ffe5,field74);
    cube->field64=unchangeable;
    cube->field74=field74;
    Unk_IntArr types;
    CString typeText("");
    efd::utf8string typeNames;
    FUN_1402237c0(&types);
    entity->GetPropertyValue(0x6b780e9d,typeNames);
    typeText=typeNames.c_str();
    FUN_140177de0(typeText,&types,",");
    for(size_t i=0;i<types.FUN_140186260();i++) {
        int type=*types.FUN_1401844d0(i);
        cube->field5c|=FUN_1408a0190(type);
    }
    cube->fieldB4=objCode;
    cube->field68=wall;
    cube->field70=entity->GetModel()->ContainsModel(0xd8dea70d);
    bool animatable=false;
    entity->GetPropertyValue(0x38141815,animatable);
    cube->field6c=animatable;
}
MS2_REPLACE(0x1408a1640, FUN_1408a1640, 640, 0x80A95CB0);
// MS2-FUNCTIONAL: float argument reaches the call via movss xmm0; movaps xmm3,xmm0 in the exe (no source form found).
// @0x1408a18d0
int FUN_1408a18d0(__int64 charID) {
    Unk_UgcPhysSvcRef service(FUN_1401cd040(&DAT_143b059e8));
    int style=0;
    PCBase* player=FUN_1403ed2d0()->FUN_141bd0cc0();
    if(player!=0) {
        if(charID==FUN_141656a80(player)) {
            std::vector<efd::SmartPointer<egf::Entity> > hits;
            MS2Color color(3);
            float packed=(float)(unsigned)(FUN_1401d3200()->ConstructUgcDistance.Read()*color);
            service.FUN_1401cd1a0()->FUN_1410bb610(3,player,packed,hits);
            if(hits.size()>0) {
                efd::SmartPointer<egf::Entity> first=hits[0];
                first->GetPropertyValue(0x85ef19e7,style);
            }
        }
    }
    return style;
}
MS2_REPLACE(0x1408a18d0, FUN_1408a18d0, 364, 0xAE4C35ED);
// @0x1408a85a0
Unk_Int3* FUN_1408a85a0(Unk_Int3* p,int x,int y,int z) { p->x=x; p->y=y; p->z=z; return p; }

// @0x1408ad110
Unk_UGCGroup::Unk_UGCGroup() {
    contractPrice=0x7fffffff;
    contractPriceItemCode=0;
    extensionPrice=0x7fffffff;
    extensionPriceItemCode=0;
    contractDate=0;
    extensionDate=0;
    heightLimit=0;
    buildingCount=0;
    indoorCount=0;
    blockCode=0;
    houseNumber=0;
    field30=0;
    buildingType=0;
    returnPlaceID=0;
    maidCount=0;
    installNpcCount=0;
    hideEmoticon=0;
    trophyID=0;
    adminOnly=false;
    triggerCount=0;
    indoorSizeType="";
    useCouponEvent=0;
}

// @0x1408ad2c0
int Unk_UGCGroup::FUN_1408ad2c0() { return FUN_14053f8c0(contractPriceItemCode); }
MS2_REPLACE_METHOD(0x1408ad2c0, Unk_UGCGroup, FUN_1408ad2c0, 30, 0x39B3499B);
// @0x1408ad2f0
int Unk_UGCGroup::FUN_1408ad2f0() { return FUN_14053f940(contractPriceItemCode); }
MS2_REPLACE_METHOD(0x1408ad2f0, Unk_UGCGroup, FUN_1408ad2f0, 30, 0x52EB71DE);
