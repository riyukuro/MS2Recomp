// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClientPlatformBase (the default IClientPlatform: vftable
// 0x142e10280, 78 inherited slots + the virtual dtor), the user report record CUserReportData it hands to the report
// dialog, and the small Nexon Analytics value/handle types its init code builds. Names of the Nx* types and fields are
// invented from their use.
// Owning unit: client\ms2\ms2clientplatformbase.cpp.
#pragma once

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// 16-byte record id of a user report: ctor 0x1402038a0 and Copy 0x140204340 both call Reset 0x140207730.
struct Unk_ReportId
{
    Unk_ReportId() { Reset(); }
    void Reset() { m_nType = 0; m_nValue = 0; }
    void Copy(const Unk_ReportId& o) { Reset(); m_nType = o.m_nType; m_nValue = o.m_nValue; }
    int m_nType;
    __int64 m_nValue;
};
MS2_CHECK_SIZE(Unk_ReportId, 16);

class CUserReportData : public CPtred
{
public:
    CUserReportData();                          // 0x140c74e70
    CUserReportData(int nType);                 // 0x140c74fc0
    virtual ~CUserReportData();                 // 0x140c75120
    void Reset();                               // 0x140c75240

    int GetType() const { return m_nType; }                         // @0x140c775d0
    int GetField74() const { return m_n74; }                        // @0x140c775e0
    int GetField58() const { return m_n58; }                        // @0x140c774e0
    int GetField70() const { return m_n70; }                        // @0x140c77540
    __int64 GetField40() const { return m_n40; }                    // @0x140c77640
    __int64 GetField48() const { return m_n48; }                    // @0x140c77710
    __int64 GetField60() const { return m_n60; }                    // @0x140c776a0
    __int64 GetField68() const { return m_n68; }                    // @0x140c776b0
    CStringW GetTitle() const { return m_strTitle; }                // @0x140c775f0
    CStringW GetField38() const { return m_str38; }                 // @0x140c77650
    CStringW GetField78() const { return m_str78; }                 // @0x140c774f0
    CStringW GetField80() const { return m_str80; }                 // @0x140c77580
    CStringA GetField50() const { return m_str50; }                 // @0x140c776c0
    // setters (inline COMDATs of uimeratmarketcommon.cpp; the CStringW/CString arguments are by value: the callee destroys them)
    void SetField28(int n) { m_n28 = n; }                           // @0x140ec3c70
    void SetField60(__int64 n) { m_n60 = n; }                       // @0x140ec3e80
    void SetField38(CStringW str) { m_str38 = str; }                // @0x140ec3e40
    void SetTitle(CStringW str) { m_strTitle = str; }               // @0x140ec3e00
    void SetFielda0(__int64 n) { m_na0 = n; }                       // @0x140ec3c90
    void SetFielda8(__int64 n) { m_na8 = n; }                       // @0x140ec3cb0
    void SetFieldb0(CStringW str) { m_strb0 = str; }                // @0x140ec3cd0
    void SetFieldd8(__int64 n) { m_nd8 = n; }                       // @0x140ec3d20
    void SetFieldb8(CStringW str) { m_strb8 = str; }                // @0x140ec3d40
    void SetFieldc0(__int64 n) { m_nc0 = n; }                       // @0x140ec3d90
    void SetFieldc8(CStringA str) { m_strc8 = str; }                // @0x140ec3db0

    Unk_ReportId m_id;                          // +0x18
    int m_n28;
    int m_nType;                                // +0x2c
    CStringW m_strTitle;                        // +0x30
    CStringW m_str38;
    __int64 m_n40;
    __int64 m_n48;
    CStringA m_str50;
    int m_n58;
    __int64 m_n60;
    __int64 m_n68;
    int m_n70;
    int m_n74;
    CStringW m_str78;
    CStringW m_str80;
    __int64 m_n88; __int64 m_n90;
    CStringW m_str98;
    __int64 m_na0;
    __int64 m_na8;
    CStringW m_strb0;
    CStringW m_strb8;
    __int64 m_nc0;
    CStringA m_strc8;
    CStringW m_strd0;
    __int64 m_nd8;
    __int64 m_ne0;
    __int64 m_ne8;
    int m_nf0;
    __int64 m_nf8;
    CStringW m_str100;
    CStringA m_str108;
    int m_n110;
};
MS2_CHECK_SIZE(CUserReportData, 0x118);

// The 0x38-byte tagged value of the Nexon Analytics wrapper (a 16-byte header, then payload storage).
struct Unk_NxValue
{
    Unk_NxValue() : m_nKind(0), m_nFlags(0), m_nSize(0), m_n8(0) {}         // @0x140c771f0
    unsigned short m_nKind;
    unsigned short m_nFlags;
    unsigned m_nSize;
    unsigned __int64 m_n8;
    unsigned __int64 m_n10; unsigned __int64 m_n18; unsigned __int64 m_n20; unsigned __int64 m_n28;
    unsigned __int64 m_n30;
};
MS2_CHECK_SIZE(Unk_NxValue, 0x38);

struct Unk_NxString : Unk_NxValue
{
    Unk_NxString() {}                                           // @0x140c77120
    void FUN_140c777f0(const char* psz, int nMode);             // @0x140c777f0 -> Set
    Unk_NxString(const char* psz, int nMode);                            // @0x140c77310
    ~Unk_NxString();                                            // 0x14092e560 (another unit)
    void Set(const char* psz, int nMode);                       // 0x14092e710
};

struct Unk_NxNumber : Unk_NxValue
{
    Unk_NxNumber() {}                                           // @0x140c77170
    Unk_NxNumber(int n);                                        // @0x140c77140
    Unk_NxNumber(__int64 n);                                    // @0x140c77340
    ~Unk_NxNumber();                                            // @0x140c772f0 (calls 0x14092e580)
    void Set(unsigned n);                                       // @0x140c77850
    void Set(__int64 n);                                        // @0x140c77820 -> 0x140c778a0
    __int64 GetValue() const { return m_n10; }                  // @0x140c77980
    void SetStorage(__int64 n);                                 // @0x140c778a0
    void Init(unsigned n);                                      // @0x140c77190
};

struct Unk_NxEvent
{
    Unk_NxEvent();                                              // @0x140c77090
    ~Unk_NxEvent();                                             // @0x140c77290
    int m_nType;
    Unk_NxString m_strSerial;                                   // +0x08
    Unk_NxNumber m_num40;                                       // +0x40
    Unk_NxNumber m_numId;                                       // +0x78
    Unk_NxString m_strSession;                                  // +0xb0
};
MS2_CHECK_SIZE(Unk_NxEvent, 0xe8);

// The Nexon Analytics wrapper singleton (function-local static of FUN_140c77900).
class Unk_NexonAnalytics
{
public:
    Unk_NexonAnalytics() : m_p(0) {}                            // @0x140c77070
    ~Unk_NexonAnalytics();                                      // @0x140c77260 -> 0x14092cbf0
    const char* GetModuleName() const;                          // @0x140c778f0 "NexonAnalytics64.dll"
    bool FUN_14092ca70(const char* pszModule);
    void FUN_14092d1f0(int nCode, const CStringA& strLog);
    void FUN_14092d280(int nCode, const CStringA& strLog);
    bool FUN_14092ce80(const Unk_NxString* pVersion, const Unk_NxString* pHost);
    bool FUN_14092cf80(const Unk_NxEvent* pEvent, const Unk_NxString* pHost, const Unk_NxNumber* pService);
    void FUN_14092d070(bool bFlush);
    void FUN_14092cbf0();
    void* m_p;
};

// The option profile object the game option owner keeps at +0x9c (copy ctor/dtor 0x14125ec20/0x14125ef90).
struct Unk_OptionProfile
{
    // ctor 0x14125ec20 / dtor 0x14125ef90 live in another unit (called as FUN_ helpers)
    int m_nMode;
    int m_nRest[9];
};
MS2_CHECK_SIZE(Unk_OptionProfile, 40);

class CClientPlatformBase : public IClientPlatform
{
public:
    CClientPlatformBase();                                      // 0x140c75570
    virtual ~CClientPlatformBase();                             // slot 78: 0x140c755c0

    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual const char* vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_12();
    virtual CStringA vfunc_13();
    virtual int vfunc_17();
    virtual void vfunc_18(void* a1);
    virtual void vfunc_19(int a1, void* a2, void* a3);
    virtual void vfunc_20(int a1, int a2);
    virtual void vfunc_21(void* a1);
    virtual void vfunc_22(int nCode, const char* pszFormat, ...);
    virtual void vfunc_23(int nCode, const char* pszFormat, ...);
    virtual void vfunc_25(void* a1);
    virtual void vfunc_26(void* a1);
    virtual int vfunc_27();
    virtual void* vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_31(CStringA a1, int a2, int a3);
    virtual void vfunc_32(void* a1);
    virtual void vfunc_33(__int64 a1);
    virtual int vfunc_34(void* a1);
    virtual int vfunc_35(void* a1);
    virtual int vfunc_36();
    virtual int vfunc_37(void* a1);
    virtual void vfunc_38(void* a1);
    virtual bool vfunc_39(__int64 a1, int a2);
    virtual bool vfunc_40(__int64 a1);
    virtual bool vfunc_41(__int64 a1);
    virtual void vfunc_42(void* a1);
    virtual bool vfunc_43(int a1, bool a2, int a3);
    virtual const CStringA& vfunc_44();
    virtual const CStringA& vfunc_45();
    virtual int vfunc_46();
    virtual void vfunc_47(CStringA a1, CStringA a2);
    virtual void vfunc_48(MS2Ptr<CUserReportData> spReport);
    virtual int vfunc_49();
    virtual int vfunc_52(void* a1, int a2);
    virtual int vfunc_53(void* a1, int a2);
    virtual int vfunc_54(CStringW a1, CStringW a2, int a3, CStringW a4);
    virtual void vfunc_55(float a1);
    virtual void vfunc_56(int a1);
    virtual void vfunc_57(void* a1);
    virtual void vfunc_58(int a1, int a2);
    virtual void vfunc_59(int a1);
    virtual void vfunc_60(int a1);
    virtual void vfunc_63(bool a1, int a2, int a3);
    virtual void vfunc_64(int a1);
    virtual void vfunc_65(int a1);
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71(void* a1);
    virtual void vfunc_72();
    virtual void vfunc_73(int a1);
    virtual int vfunc_74();
    virtual CStringA vfunc_75();
    virtual CStringA vfunc_76();
    virtual CStringA vfunc_77();
    // The remaining void() slots (5-11, 14-16, 24, 30, 38?, 50, 51, 61, 62) are inherited stand-ins overridden below.
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_24();
    virtual void vfunc_30();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_61();
    virtual void vfunc_62();

    bool m_bAnalyticsOn;                                        // +0x08 InitializeNexonAnalytics succeeded
    bool m_bAnalyticsLoaded;                                    // +0x09 the analytics module initialised
};
MS2_CHECK_SIZE(CClientPlatformBase, 0x10);
