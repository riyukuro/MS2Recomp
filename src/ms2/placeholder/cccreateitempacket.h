// RTTI-named packet types; enum key names are invented.
#pragma once
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
enum Unk_PacketOptionA { Unk_PacketOptionA_Zero };
enum Unk_PacketOptionB { Unk_PacketOptionB_Zero };
class CCCreateItemPacket {
public:
    CCCreateItemPacket() : a(0), b(0), c(0), d(0), e(0), f(0), g(-1), h(-1), i(-1), j(0) {}    // 0x1412d4ee0 (inline COMDAT, uiitemoptioncreatedialog.cpp)
    virtual void vfunc_0(COutputStream&);
    virtual void vfunc_1(void*);
    virtual int vfunc_2();
    int a,b,c,d,e,f,g,h,i,j;
    ATL::CAtlMap<Unk_PacketOptionA,Unk_PayloadPtr<BaseOption>> optionsA[5];
    ATL::CAtlMap<Unk_PacketOptionB,Unk_PayloadPtr<BaseOption>> optionsB[5];
};
MS2_CHECK_SIZE(CCCreateItemPacket,0x300);
MS2_CHECK_OFFSET(CCCreateItemPacket,optionsA,0x30);
MS2_CHECK_OFFSET(CCCreateItemPacket,optionsB,0x198);
class CCCompareItemPacket:public CCCreateItemPacket {
public:
    CCCompareItemPacket() : compareValue(100) {}    // 0x1419b9db0 (inline COMDAT, uiitemcreatedialog.cpp)
    void vfunc_0(COutputStream&)override;
    void vfunc_1(void*)override;
    int compareValue;
};
MS2_CHECK_SIZE(CCCompareItemPacket,0x308);
MS2_CHECK_OFFSET(CCCompareItemPacket,compareValue,0x300);
