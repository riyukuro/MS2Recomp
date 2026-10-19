// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClientPlatformTencent: the Tencent (China) IClientPlatform.
// It derives CClientPlatformBase (+0, vftable 0x142e11e80) and TSingleton<CClientPlatformTencent> (+0x10, vftable
// 0x142e12100), then keeps one CAtlArray<void*> at +0x18 that nothing fills. Most slots are constants or no-ops; the
// real ones are the merat/blue-merat notice parser (vfunc_42), the report dialog opener (vfunc_48) and the push
// notice sender (vfunc_43).
// Owning unit: client\ms2\ms2clientplatformtencent.cpp.
#pragma once

#include "ms2/client/ms2/ms2clientplatformbase.h"
#include "ms2/commonfiles/os.h"
#include <atlcoll.h>

class CClientPlatformTencent : public CClientPlatformBase, public TSingleton<CClientPlatformTencent>
{
public:
    CClientPlatformTencent();                                   // 0x140c7cd70
    virtual ~CClientPlatformTencent();                          // 0x140c7cde0

    virtual int vfunc_1() override;
    virtual int vfunc_2() override;
    virtual const char* vfunc_3() override;
    virtual void vfunc_5() override;
    virtual void vfunc_7() override;
    virtual void vfunc_8() override;
    virtual void vfunc_9() override;
    virtual void vfunc_10() override;
    virtual void vfunc_11() override;
    virtual int vfunc_17() override;
    virtual void vfunc_20(int a1, int a2) override;
    virtual void vfunc_24() override;
    virtual void vfunc_25(void* a1) override;
    virtual void* vfunc_28() override;
    virtual void vfunc_29() override;
    virtual void vfunc_31(CStringA a1, int a2, int a3) override;
    virtual void vfunc_33(__int64 a1) override;
    virtual int vfunc_34(void* a1) override;
    virtual int vfunc_35(void* a1) override;
    virtual int vfunc_36() override;
    virtual int vfunc_37(void* a1) override;
    virtual void vfunc_38(void* a1) override;
    virtual bool vfunc_39(__int64 a1, int a2) override;
    virtual bool vfunc_40(__int64 a1) override;
    virtual bool vfunc_41(__int64 a1) override;
    virtual void vfunc_42(void* a1) override;                   // a CInPacket*: the merat/blue merat notice
    virtual bool vfunc_43(int a1, bool a2, int a3) override;
    virtual const CStringA& vfunc_44() override;
    virtual const CStringA& vfunc_45() override;
    virtual void vfunc_48(MS2Ptr<CUserReportData> spReport) override;
    virtual int vfunc_49() override;
    virtual void vfunc_50() override;
    virtual void vfunc_51() override;
    virtual int vfunc_52(void* a1, int a2) override;
    virtual int vfunc_53(void* a1, int a2) override;
    virtual int vfunc_54(CStringW a1, CStringW a2, int a3, CStringW a4) override;
    virtual void vfunc_55(float a1) override;
    virtual void vfunc_56(int a1) override;
    virtual void vfunc_58(int a1, int a2) override;
    virtual void vfunc_59(int a1) override;
    virtual void vfunc_60(int a1) override;
    virtual void vfunc_61() override;
    virtual void vfunc_62() override;
    virtual void vfunc_63(bool a1, int a2, int a3) override;
    virtual void vfunc_65(int a1) override;
    virtual void vfunc_66() override;
    virtual void vfunc_73(int a1) override;

    ATL::CAtlArray<void*> m_arr;                                // +0x18
};
