// CCPetInfoPacket::Info from RTTI; member type names are descriptive placeholders.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/stream.h"
#include <atlcoll.h>
struct Unk_PetIdentity {
    Unk_PetIdentity();
    ~Unk_PetIdentity();
    void FUN_1401fee50(COutputStream&);
    void FUN_1401fef40(void*);
    void FUN_1401ff0f0(const Unk_PetIdentity&);
    void FUN_1401ff190(COutputStream&);
    void FUN_1401ff280(CInputStream&);
    CStringW name;
    __int64 id;
    int value;
    short level;
    int state,extra;
    CLockCriticalSection lock;
};
MS2_CHECK_SIZE(Unk_PetIdentity,0x50);
MS2_CHECK_OFFSET(Unk_PetIdentity,lock,0x20);
struct Unk_PetOption {
    Unk_PetOption():type(0),value(0),enabled(0){}
    Unk_PetOption(int t,float v,int e):type(t),value(v),enabled(e){}
    int type;float value;int enabled;
};
MS2_CHECK_SIZE(Unk_PetOption,12);
struct Unk_PetOptions {
    ATL::CAtlMap<unsigned int,Unk_PetOption> map;
    Unk_PetOptions();
    ~Unk_PetOptions();
    void FUN_1401ff3f0(COutputStream&);
    void FUN_1401ff4d0(void*);
    void FUN_1401ff5e0(const Unk_PetOptions&);
    int FUN_1401ff680();
};
MS2_CHECK_SIZE(Unk_PetOptions,0x48);
struct Unk_PetFlags {
    Unk_PetFlags();
    unsigned a,b,c,d,e,f,g,h,i,j;
};
MS2_CHECK_SIZE(Unk_PetFlags,0x28);
class CCPetInfoPacket {
public:
    class Info:public CPtred {
    public:
        Info();
        ~Info();
        void FUN_1401ffca0(COutputStream&);
        void FUN_1401ffd00(void*);
        Unk_PetIdentity identity;
        Unk_PetOptions options;
        Unk_PetFlags flags;
    };
};
MS2_CHECK_SIZE(CCPetInfoPacket::Info,0xd8);
MS2_CHECK_OFFSET(CCPetInfoPacket::Info,identity,0x18);
MS2_CHECK_OFFSET(CCPetInfoPacket::Info,options,0x68);
MS2_CHECK_OFFSET(CCPetInfoPacket::Info,flags,0xb0);
