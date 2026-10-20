// ms2clientplatformnexonkorea.h - CClientPlatformNexonKorea (RTTI .?AVCClientPlatformNexonKorea@@, 0x38 bytes): the
// Korean (service region 0) IClientPlatform, created by CreateClientPlatform 0x140d86270 (operator new(0x38) in
// 0x140d86370). It drives the Nexon launcher SDK wrapper CNXMan (create/connect/auth/shutdown), parses the launch
// arguments, sends the Nexon login request and shows the shutdown-warning notices. Recovered from MapleStory2.exe
// KMS2_DEV x64 (2022-04-13); unit unit_140c77ab0 (0x140c77ab0-0x140c7cd70). The header name is assumed (no __FILE__ in
// the TU); slot names follow IClientPlatform's vfunc_N. Layout cross-checked with the v2525 snapshot.
#pragma once

#include "ms2/client/ms2/ms2clientplatformbase.h"
#include "ms2/commonfiles/os.h"
#include <vector>

// vftables 0x142e10aa0 (+0, 79 slots) and 0x142e10d20 (+0x10, TSingleton: the ??_G thunk).
class CClientPlatformNexonKorea : public CClientPlatformBase, public TSingleton<CClientPlatformNexonKorea>
{
public:
    CClientPlatformNexonKorea();                                // 0x140c77ab0
    virtual ~CClientPlatformNexonKorea();                       // 0x140c77bf0

    virtual int vfunc_1() override;                             // the feature server type is 4
    virtual const char* vfunc_3() override;                     // the single-instance mutex name
    virtual int vfunc_4() override;                             // launcher authentication (1 ok, 3 failed)
    virtual void vfunc_6() override;                            // per-frame: the shutdown countdown notices
    virtual int vfunc_12() override;
    virtual CStringA vfunc_13() override;                       // the "/passport:" launch argument
    virtual void vfunc_14() override;                           // creates and connects CNXMan
    virtual void vfunc_15() override;                           // shuts down and destroys CNXMan
    virtual void vfunc_16() override;
    virtual int vfunc_17() override;                            // parses and checks the launch arguments
    virtual void vfunc_18(void* a1) override;
    virtual void vfunc_19(int a1, void* a2, void* a3) override; // window message 1234 -> CNXMan
    virtual void vfunc_20(int a1, int a2) override;             // sends the Nexon login request (packet 3)
    virtual void vfunc_26(void* a1) override;                   // a CInPacket*: shutdown time / maintenance notice
    virtual void* vfunc_28() override;
    virtual void vfunc_29() override;
    virtual void vfunc_30() override;
    virtual void vfunc_32(void* a1) override;
    virtual int vfunc_74() override;                            // the service-id index (4, or 5 for CNXMan's flag)
    virtual CStringA vfunc_75() override;                       // the service id
    virtual CStringA vfunc_76() override;                       // the "/sid:" launch argument
    virtual CStringA vfunc_77() override;                       // the "/nexonsn:" launch argument

    std::vector<CStringA> m_strings;                            // +0x18 service ids by vfunc_74 index
    int m_30;                                                   // +0x30 set by vfunc_18
    int m_34;                                                   // +0x34 tick of the last countdown check
};
MS2_CHECK_SIZE(CClientPlatformNexonKorea, 0x38);
MS2_CHECK_OFFSET(CClientPlatformNexonKorea, m_strings, 0x18);
