// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClientPlatformNexonKorea, the Korean IClientPlatform (the
// Nexon launcher SDK wrapper CNXMan, the launch-argument checks, the Nexon login request, the shutdown countdown
// notices), plus the COMDATs this TU instantiates first: RawString (client\ms2\rawstring.h) with its
// CAtlMap<ERawString, CStringW> / CAtlArray<RawString::Entry>, std::vector<CStringA>::resize, the launch-flag bitset
// and the TSingleton<CClientPlatformNexonKorea/CNXMan/CNPSMan> helpers. No __FILE__ names the TU (probably
// ms2clientplatformnexonkorea.cpp); it ends with its UCRT memmove_s copy. Names marked "invented" are not in the exe.
// MS2-UNIT: unit_140c77ab0
// MS2-RANGE: 0x140c77ab0-0x140c7cd70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Uninit_alloc_fill_n1@PEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@_KV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@YAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QEAV12@_KAEBV12@AEAV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@0@U?$integral_constant@_N$0A@@0@@Z 0x140c792a0 ; unique
// MS2-PIN: ??R<lambda_c3b7fa1df2929afb91f96d07fa34b56c>@@QEBAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV12@_K@Z 0x140c79c90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$_Uninitialized_fill_n@PEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@_KV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@YAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QEAV12@_KAEBV12@AEAV?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@0@@Z 0x140c79330 ; builds the zeroed tag and calls _Uninit_alloc_fill_n1 0x140c792a0
// MS2-PIN: ?_Ufill@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEAAPEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAV34@_KAEBV34@@Z 0x140c7cb10 ; (dest, count, val) -> _Uninitialized_fill_n, called by the resize lambda 0x140c79c90
// MS2-PIN: ??_7CClientPlatformNexonKorea@@6B?$TSingleton@VCClientPlatformNexonKorea@@@@@ 0x142e10d20
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2clientplatformnexonkorea.h"
#include "ms2/client/ms2/rawstring.h"
#include "ms2/client/ms2/nxman.h"
#include "ms2/client/ms2/npsman.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/guess/machineidmanager.h"
#include "ms2/placeholder/cantihackmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/bitset.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the launch-argument flags (filled by the command-line parser 0x1414b1980 of unit_1414b1230) ----
// The bitset template of commonfiles\bitset.inl with its proxy reference (operator[] line 152, Test line 404); the
// class names are invented. Bits: 0 passport given, 1 sid given, 2/3 read and ignored.
template <int T> class Unk_LaunchBitset
{
public:
    class reference
    {
    public:
        reference(Unk_LaunchBitset* pBits, int nPos) : m_pBits(pBits), m_nPos(nPos) {}
        operator bool() const { return m_pBits->Test(m_nPos); }
        Unk_LaunchBitset* m_pBits;
        int m_nPos;
    };
    reference operator[](int pos)
    {
        MS2_BITSET_ASSERT(152, UINT(pos) < UINT(T));
        return reference(this, pos);
    }
    bool Test(int pos) const
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(404, 0); return false; }
        return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
    }
    unsigned char m_bits[(T + 7) / 8];
};

// ---- out-of-unit types, functions and globals ----
extern int DAT_143ac2fd0;                       // the platform failure code (shown by CGameApp::InitInstance)
extern CStringW DAT_143ac2fe0;                  // the platform failure message
extern Unk_LaunchBitset<4> g_launchBits;        // 0x143ae0901
extern CString g_strPassport;                   // 0x143ae0910 "/passport:"
extern CString g_strSid;                        // 0x143ae0918 "/sid:"
extern CString g_strNexonSn;                    // 0x143ae0920 "/nexonsn:"
extern __int64 g_nShutdownTime;                 // 0x143ab2908 server time of the announced shutdown (0 = none)
extern ATL::CAtlArray<int> g_aShutdownNoticed;  // 0x143ab30b8 one flag per countdown notice (30/15/5 minutes)
extern int g_socketClosing;                     // 0x143ab2910
extern CStringW DAT_143ab2d78;                  // the maintenance message
extern CStringW g_strMaintenanceExit;           // 0x143abf510 L"maintenanceExit" (the message box tag)
extern int DAT_143ab2858;                       // a login value received from the server
void FUN_1414b1980();                           // parses the launch arguments
DWORD GetTickCountMs2();
__int64 FUN_140869440();                        // the server time
CStringW FUN_1408116a0(int nStringId, const int& n);                       // FormatStringId<int>
CStringW FUN_14028de60(int nStringId);
void FUN_1412751f0(const CStringW& text, int nA, int nB);                   // a system notice
void FUN_141b6fcf0(const CStringW& text, const CStringW& caption, UINT nType);   // MessageBox over the game window
CStringW FUN_14016a730(const char* sz, int nCodePage);
unsigned FUN_14028ba90();
CFeatureManager* FUN_140166410();
// StringFormat<CString> (the fmt "{0}" wrapper, itemdata.cpp's COMDAT). Called by address name: progress/symbols.tsv binds
// the StringFormat<CString> name to the look-alike 0x140536a50 (Unk_SocketFormat<CString>, which calls 0x1402bf9a0).
CString FUN_140540050(const char* pszFormat, const CString& strArg);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                                 // show it
// CNXMan::FUN_14160dac0 / FUN_14160e5f0 as this TU's callers see them: int results (nxman.h declares bool), and dac0
// gets the argument the slot passes on (the callee ignores it).
int FUN_14160dac0(CNXMan* pNx, void* pParam);
int FUN_14160e5f0(CNXMan* pNx);

// The 16-byte machine id (zero-initialised by 0x14067c020, copied by 0x14067c080; unit_14067c020). Invented name.
struct Unk_NxMachineId
{
    Unk_NxMachineId();                                          // 0x14067c020
    Unk_NxMachineId* FUN_14067c080(const Unk_MachineID* pOther);
    unsigned char m_data[16];
};
MS2_CHECK_SIZE(Unk_NxMachineId, 0x10);

// The Nexon login request body (packet 3; encoded by 0x1401f9370 of commonfiles\classobject.cpp). Invented names.
struct Unk_NxLoginRequest
{
    Unk_NxLoginRequest() : m_nType(0), m_n18(0), m_n1c(0), m_n30(0), m_n34(0) {}   // @0x140c796c0
    void FUN_1401f9370(COutputStream* pOut);
    int m_nType;                                                // +0x00
    CString m_strPassport;                                      // +0x08
    CString m_strSession;                                       // +0x10
    int m_n18;                                                  // +0x18
    int m_n1c;                                                  // +0x1c
    Unk_NxMachineId m_id;                                       // +0x20
    int m_n30;                                                  // +0x30
    int m_n34;                                                  // +0x34
};
MS2_CHECK_SIZE(Unk_NxLoginRequest, 0x38);

// ---- CClientPlatformNexonKorea ----
// @0x140c77ab0
CClientPlatformNexonKorea::CClientPlatformNexonKorea() : m_30(0), m_34(0)
{
    m_strings.resize(6, "");
    m_strings[4] = "430008425";
    m_strings[5] = "430011497";
    m_strings[1] = "430007401";
}

// @0x140c77bf0
CClientPlatformNexonKorea::~CClientPlatformNexonKorea()
{
}

// @0x140c77c50
const char* CClientPlatformNexonKorea::vfunc_3()
{
    static char s_szMutexName[] = "Global\\0E139E89-A290-4568-9CA5-5868FF94446E";
    return s_szMutexName;
}

// @0x140c77c70
int CClientPlatformNexonKorea::vfunc_4()
{
    int nResult = 1;
    RawString rawString;
    CStringW strError;
    if (CNXMan::GetInstance()->FUN_14160dd50(strError) == 0) {
        DAT_143ac2fd0 = 0x4b1;
        DAT_143ac2fe0 = StringFormat(L"{0} {1}", rawString.Get(RAWSTRING_VERSION_CHECK_FAILED), strError);
        return 3;
    }
    vfunc_22(0x26c, "");
    nResult = CNXMan::GetInstance()->FUN_14160e260();
    if (nResult != 1) {
        if (nResult == 3) {
            DAT_143ac2fd0 = 0x4b1;
            DAT_143ac2fe0 = rawString.Get(RAWSTRING_VERSION_CHECK_FAILED2);
        }
        return nResult;
    }
    return nResult;
}

// @0x140c77e80
void CClientPlatformNexonKorea::vfunc_6()
{
    int nNow = GetTickCountMs2();
    if (m_34 == 0)
        m_34 = nNow;
    if (g_nShutdownTime > 0) {
        if (g_aShutdownNoticed.GetCount() == 0) {
            g_aShutdownNoticed.SetCount(3);
            for (unsigned i = 0; i < g_aShutdownNoticed.GetCount(); i++)
                g_aShutdownNoticed[i] = 0;
        }
        if ((unsigned)(nNow - m_34) >= 1000) {
            m_34 = nNow;
            __int64 nServerTime = FUN_140869440();
            if (nServerTime < g_nShutdownTime) {
                int nNotice = -1;
                __int64 nRemain = g_nShutdownTime - nServerTime;
                if (nRemain > 240 && nRemain <= 300 && g_aShutdownNoticed[2] == 0)
                    nNotice = 2;
                else if (nRemain > 840 && nRemain <= 900 && g_aShutdownNoticed[1] == 0)
                    nNotice = 1;
                else if (nRemain > 1740 && nRemain <= 1800 && g_aShutdownNoticed[0] == 0)
                    nNotice = 0;
                if (nNotice >= 0 && nNotice <= 2) {
                    CMsTime shutdown(g_nShutdownTime);
                    int nHour = shutdown.GetHour();
                    FUN_1412751f0(FUN_1408116a0(0x9a5, nHour), 1, 1);
                    g_aShutdownNoticed[nNotice] = 1;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140C77E80, CClientPlatformNexonKorea, vfunc_6, 602, 0x180C0463);

// @0x140c780e0
int CClientPlatformNexonKorea::vfunc_12()
{
    return m_30;
}

// @0x140c78100
CStringA CClientPlatformNexonKorea::vfunc_13()
{
    return g_strPassport;
}
MS2_REPLACE_METHOD(0x140C78100, CClientPlatformNexonKorea, vfunc_13, 61, 0xB5418E8C);

// @0x140c78150
void CClientPlatformNexonKorea::vfunc_14()
{
    CNXMan::CreateInstance();
    CNXMan::GetInstance()->FUN_14160d820();
}

// @0x140c78180
void CClientPlatformNexonKorea::vfunc_15()
{
    CNXMan::GetInstance()->FUN_14160da80();
    CNXMan::DestroyInstance();
}

// @0x140c781b0
void CClientPlatformNexonKorea::vfunc_16()
{
    if (CNXMan::GetInstance()->FUN_14160db80() == 0) {
        DAT_143ac2fd0 = 0x450;
        DAT_143ac2fe0 = FUN_14016a730(CNXMan::GetInstance()->FUN_14160e5a0(), 0);
    }
}

// @0x140c78260
void CClientPlatformNexonKorea::vfunc_26(void* a1)
{
    int nMode = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_1();
    if (nMode == 0) {
        int nKind = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_1();
        if (nKind == 0) {
            __int64 nTime = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_4();
            g_nShutdownTime = nTime;
        } else if (nKind == 1) {
            CStringW strMessage = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_8();
            g_socketClosing = 1;
            DAT_143ab2d78 = strMessage;
            COutPacket packet(0xd, 0);
            packet.Encode1(2);
            packet.Encode1(2);
            FUN_140710590(packet);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, strMessage, 0, g_strMaintenanceExit);
            if (spBox) {
                spBox->FUN_141a015d0(FUN_14028de60(0x219));
                FUN_140d73c60(spBox);
            }
        }
    } else if (nMode == 1) {
        int nKind = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_1();
        CStringW strMessage = static_cast<CInputStream&>(*(CInPacket*)a1).vfunc_o8_8();
        if (nKind == 1) {
            g_socketClosing = 1;
            DAT_143ab2d78 = strMessage;
            COutPacket packet(0xd, 0);
            packet.Encode1(2);
            packet.Encode1(2);
            FUN_140710590(packet);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, strMessage, 0, g_strMaintenanceExit);
            if (spBox) {
                spBox->FUN_141a015d0(FUN_14028de60(0x8c6));
                FUN_140d73c60(spBox);
            }
        } else {
            FUN_1412751f0(strMessage, 3, 1);
        }
    }
}
MS2_REPLACE_METHOD(0x140C78260, CClientPlatformNexonKorea, vfunc_26, 1297, 0x9DCDB96C);

// @0x140c78780
int CClientPlatformNexonKorea::vfunc_17()
{
    RawString rawString;
    FUN_1414b1980();
    if (!g_launchBits[0]) {
        DAT_143ac2fd0 = 0x3e9;
        DAT_143ac2fe0 = rawString.Get(RAWSTRING_INVALID_LAUNCH);
        return 0;
    }
    if (!g_launchBits[1]) {
        DAT_143ac2fd0 = 0x3ea;
        DAT_143ac2fe0 = rawString.Get(RAWSTRING_INVALID_LAUNCH);
        return 0;
    }
    if (g_launchBits[3]) {}     // read and ignored
    if (g_launchBits[2]) {}
    return 1;
}
MS2_REPLACE_METHOD(0x140C78780, CClientPlatformNexonKorea, vfunc_17, 437, 0x39A21ECE);

// @0x140c78940
void CClientPlatformNexonKorea::vfunc_18(void* a1)
{
    int nResult = FUN_14160dac0(CNXMan::GetInstance(), a1);
    if (nResult == 0) {
        {
            CStringW strCaption(L"Error");
            FUN_141b6fcf0(FUN_1408116a0(0xb21, 0x5b), strCaption, MB_ICONHAND);
        }
        PostQuitMessage(0);
    }
    m_30 = 1;
}

// @0x140c78a00
void CClientPlatformNexonKorea::vfunc_19(int a1, void* a2, void* a3)
{
    if (a1 == 1234) {
        if (CNXMan::GetInstance() != 0)
            CNXMan::GetInstance()->FUN_14160db40(a2, a3);
    }
}

// @0x140c78a50
void CClientPlatformNexonKorea::vfunc_20(int a1, int a2)
{
    CNXMan::GetInstance()->FUN_14160e410();
    Unk_NxLoginRequest request;
    request.m_nType = a2;
    request.m_strPassport = CNXMan::GetInstance()->FUN_14160e500();
    request.m_strSession = CNXMan::GetInstance()->FUN_14160e550();
    request.m_n18 = a1;
    request.m_n1c = FUN_14028ba90();
#ifndef __clang__
    TSingleton<CNPSMan>::GetInstance()->FUN_140db9070(CNXMan::GetInstance()->FUN_14160e500());   // temp to CString& (cl extension)
#else
    CString strPassport = CNXMan::GetInstance()->FUN_14160e500();
    TSingleton<CNPSMan>::GetInstance()->FUN_140db9070(strPassport);
#endif
    request.m_id.FUN_14067c080(TSingleton<CMachineIDManager>::GetInstance()->GetID());
    request.m_n30 = TSingleton<CMachineIDManager>::GetInstance()->GetValue();
    request.m_n34 = DAT_143ab2858;
    COutPacket packet(3, 0);
    request.FUN_1401f9370(&packet);
    FUN_140710590(packet);
}

// @0x140c78c30
void* CClientPlatformNexonKorea::vfunc_28()
{
    return CClientPlatformBase::vfunc_28();
}
MS2_REPLACE_METHOD(0x140C78C30, CClientPlatformNexonKorea, vfunc_28, 24, 0x83545907);

// @0x140c78c50
void CClientPlatformNexonKorea::vfunc_29()
{
    CClientPlatformBase::vfunc_29();
}
MS2_REPLACE_METHOD(0x140C78C50, CClientPlatformNexonKorea, vfunc_29, 24, 0x83545907);

// @0x140c78c70
void CClientPlatformNexonKorea::vfunc_30()
{
}

// @0x140c78c80
void CClientPlatformNexonKorea::vfunc_32(void* a1)
{
    CAntiHackManager::GetInstance()->FUN_1409a3410(a1);
}

// @0x140c78cb0
int CClientPlatformNexonKorea::vfunc_1()
{
    if (FUN_140166410() != 0 && FUN_140166410()->FUN_14036e6b0() == 4)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140C78CB0, CClientPlatformNexonKorea, vfunc_1, 48, 0x20596032);

// @0x140c78cf0
int CClientPlatformNexonKorea::vfunc_74()
{
    if (FUN_14160e5f0(CNXMan::GetInstance()) != 0)
        return 5;
    return 4;
}

// @0x140c78d30
CStringA CClientPlatformNexonKorea::vfunc_75()
{
    CStringA strServiceId;
    if (TSingleton<CClientPlatformNexonKorea>::GetInstance() == 0)
        return strServiceId;
    unsigned nIndex = vfunc_74();
    if (nIndex >= m_strings.size())
        return strServiceId;
    return m_strings[nIndex];
}

// @0x140c78e50
CStringA CClientPlatformNexonKorea::vfunc_76()
{
    return g_strSid;
}
MS2_REPLACE_METHOD(0x140C78E50, CClientPlatformNexonKorea, vfunc_76, 61, 0x8C272A90);

// @0x140c78ea0
CStringA CClientPlatformNexonKorea::vfunc_77()
{
    return FUN_140540050("{0}", g_strNexonSn);
}
MS2_REPLACE_METHOD(0x140C78EA0, CClientPlatformNexonKorea, vfunc_77, 67, 0x513DB67F);


MS2_EMIT_CRT_MEMMOVE_S();
