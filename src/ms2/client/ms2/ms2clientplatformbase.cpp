// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClientPlatformBase, the default IClientPlatform (every
// slot a no-op or a constant except the Nexon Analytics hooks and the report dialog), with its CUserReportData record
// and the Nexon Analytics value helpers. PARTIAL: the .text$mn tail from 0x140c77990 (CClientPlatformNexonKorea and
// its helpers) is not recovered yet.
// MS2-UNIT: client\ms2\ms2clientplatformbase.cpp
// MS2-RANGE: 0x1400cecb0-0x1400cef9a .text$di
// MS2-RANGE: 0x140c74e70-0x140c77ab0 .text$mn
// MS2-PIN: ?Reference@?$MS2Ptr@VCUserReportData@@@@CAXPEAVCUserReportData@@@Z 0x140c77740 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VCUserReportData@@@@AEAAXXZ 0x140c77760 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCUserReportData@@@@AEAAXPEAX@Z 0x140c777a0 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2clientplatformbase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2clientplatformbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdarg.h>

// ---- header statics (the order of the unit's dynamic initializers) ----
static CStringA s_strReportSiren("PremiumShop_ReportSiren");        // 0x143abf4c0
static CStringW s_strMaintenanceExit(L"maintenanceExit");           // 0x143abf510
static CStringA s_strSortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143abf4d8
static CStringA s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143abf550
static CStringA s_strSkill("skill");                                // 0x143abf548
static CStringA s_strStun("stun");                                  // 0x143abf540
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);  // 0x143abf590
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143abf5e0
static CStringA s_strReportSiren2("PremiumShop_ReportSiren");       // 0x143abf588

// ---- out-of-unit types and functions ----
void FUN_140c77760(void* p);
void FUN_14092e580(void* p);
void FUN_14092ea10(void* p, int n);
void* FUN_140159860(int nSize, void* pStorage);
class CFeatureManager { public: bool FUN_14036d650(); };
class UIReportDialog;
Unk_NexonAnalytics* FUN_140c77900();
UIReportDialog* FUN_140c76fd0(int nId);
class UIReportDialog : public UIObject
{
public:
    int FUN_141924630();                                            // the dialog's busy test
    void FUN_141ab9aa0(__int64 nTargetId, const CStringW& strText);
    void FUN_141ab9b10(const CStringW& strA, const CStringW& strB);
    void FUN_141ab9a10(__int64 nTargetId, int nKind, const CStringA& strA, const CStringW& strText);
    void FUN_141ab9b80(Unk_ReportId id, __int64 nTargetId, CStringW strA, CStringW strB, int nFlag);
    void FUN_141ab9c50(__int64 nTargetId, const CStringW& strText, int nA, int nB);
    void FUN_141ab9ce0(CStringW strA, CStringW strB);
    void FUN_141924680();                                           // show
};
void FUN_141276180(CStringA* pTarget, const CStringA& strValue);
void* FUN_140166440();                                              // the common log
void FUN_140ab1290(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const int& nArg0, const CStringA& strArg1);
void FUN_1403a1280(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg0);
void FUN_1401859c0(void* pLog, int nLevel, int nCategory, const wchar_t* pszText);
void FUN_140c76c70(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const __int64& nArg0,
                   const CStringA& strArg1, const CStringA& strArg2);
__int64 FUN_140930240();
__int64 FUN_140930390(int nKind);
__int64 FUN_140930ae0();
CFeatureManager* FUN_140166410();
extern int DAT_143ab2914;
void* FUN_1403ed2b0();                                              // the UI service
struct Unk_CpUIService {
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                         // 0x141adcea0 object by id
};
const CStringA& FUN_141adc5d0(void* pStrings, int nId);
const CStringA& FUN_141adc530(void* pStrings, int nId);
void* FUN_140b04f80(int nId);
void FUN_1410355e0(void* pWindow, CStringA strA, CStringA strB);
void* FUN_140aadf80();
HWND FUN_14209c720(void* pApp);
void FUN_1416a0e70();
void* FUN_1409a8b10();
void* FUN_140c77560(void* pGame);
void FUN_14125ec20(Unk_OptionProfile* p);
void FUN_14125ef90(Unk_OptionProfile* p);
void FUN_14125ef60(void* pTarget, const Unk_OptionProfile* pSource);
void FUN_1412432d0(void* pGame);
__int64 FUN_140718350(const CStringA& str);
extern int DAT_1439f4840;

class CAntiHackManager : public TSingleton<CAntiHackManager>
{
public:
    CAntiHackManager();
    virtual ~CAntiHackManager();
};

// @0x140c74e70
CUserReportData::CUserReportData()
{
    Reset();
}

// @0x140c74fc0
CUserReportData::CUserReportData(int nType)
{
    Reset();
    m_nType = nType;
}

// @0x140c75120
CUserReportData::~CUserReportData()
{
}

// @0x140c75240
void CUserReportData::Reset()
{
    m_id.Reset();
    m_nType = 0xff;
    m_strTitle = L"";
    m_n40 = 0;
    m_n48 = 0;
    m_str50 = L"";
    m_n60 = 0;
    m_n58 = 0;
    m_n68 = 0;
    m_n70 = 0;
    m_n74 = 0;
    m_str78 = L"";
    m_str80 = L"";
    m_na0 = 0;
    m_na8 = 0;
    m_strb0 = L"";
    m_strb8 = L"";
    m_nc0 = 0;
    m_strc8 = "";
    m_strd0 = L"";
    m_nd8 = 0;
    m_ne0 = 0;
    m_ne8 = 0;
    m_nf0 = 0;
    m_nf8 = 0;
    m_n110 = 0;
}

// @0x140c75430 (a member of an unrecovered class; the object is unused)
unsigned __int64 FUN_140c75430(void* pThis, int nKind)
{
    switch (nKind) {
    case 0: return 0;
    case 1: return 4;
    case 2: return 0xd;
    case 3: return 7;
    case 4: return 6;
    case 5: return 3;
    case 6: return 9;
    case 7: return 10;
    case 8: return 10;
    case 9: return 0xb;
    case 10: return 5;
    case 11: return 8;
    case 12: return 0xc;
    case 13: return 8;
    case 14: return 0xe;
    case 15: return 0xf;
    case 16: return 0x10;
    case 17: return 0x11;
    default:
        MS2_ASSERT_AT(85, 0);
        return 0;
    }
}

// @0x140c75570
CClientPlatformBase::CClientPlatformBase()
    : m_bAnalyticsOn(false), m_bAnalyticsLoaded(false)
{
    CAntiHackManager::CreateInstance();
}

// @0x140c755c0
CClientPlatformBase::~CClientPlatformBase()
{
    CAntiHackManager::DestroyInstance();
}

// @0x140c75600
int CClientPlatformBase::vfunc_0() { return 0; }
// @0x140c75610
int CClientPlatformBase::vfunc_1() { return 1; }
// @0x140c75630
int CClientPlatformBase::vfunc_2() { return 0; }

// @0x140c75640
const char* CClientPlatformBase::vfunc_3()
{
    MS2_ASSERT_AT(121, 0);
    return 0;
}

// @0x140c75680
int CClientPlatformBase::vfunc_4() { return 1; }
// @0x140c756a0
void CClientPlatformBase::vfunc_5() {}
// @0x140c756b0
void CClientPlatformBase::vfunc_6() {}
// @0x140c756c0
void CClientPlatformBase::vfunc_7() {}
// @0x140c756d0
void CClientPlatformBase::vfunc_8() {}
// @0x140c756e0
void CClientPlatformBase::vfunc_9() {}
// @0x140c756f0
void CClientPlatformBase::vfunc_10() {}
// @0x140c75700
void CClientPlatformBase::vfunc_11() {}
// @0x140c75710
int CClientPlatformBase::vfunc_12() { return 1; }

// @0x140c75730
CStringA CClientPlatformBase::vfunc_13()
{
    return "";
}

// @0x140c75780
void CClientPlatformBase::vfunc_14() {}
// @0x140c75790
void CClientPlatformBase::vfunc_15() {}
// @0x140c757a0
void CClientPlatformBase::vfunc_16() {}
// @0x140c757b0
void CClientPlatformBase::vfunc_26(void*) {}
// @0x140c757d0
int CClientPlatformBase::vfunc_17() { return 1; }
// @0x140c757f0
void CClientPlatformBase::vfunc_18(void*) {}
// @0x140c75810
void CClientPlatformBase::vfunc_19(int, void*, void*) {}
// @0x140c75830
void CClientPlatformBase::vfunc_20(int, int) {}
// @0x140c75850
void CClientPlatformBase::vfunc_21(void*) {}

// @0x140c75870
void CClientPlatformBase::vfunc_22(int nCode, const char* pszFormat, ...)
{
    if (m_bAnalyticsOn) {
        CStringA strLog;
        va_list args;
        va_start(args, pszFormat);
        strLog.FormatV(pszFormat, args);
        va_end(args);
        FUN_140c77900()->FUN_14092d1f0(nCode, strLog);
        FUN_140ab1290(FUN_140166440(), 0xb, 400, L"enqueueStageLog with nCode: {0}, strLog: {1}", nCode, strLog);
    }
}

// @0x140c75940
void CClientPlatformBase::vfunc_23(int nCode, const char* pszFormat, ...)
{
    if (m_bAnalyticsOn) {
        CStringA strLog;
        va_list args;
        va_start(args, pszFormat);
        strLog.FormatV(pszFormat, args);
        va_end(args);
        FUN_140c77900()->FUN_14092d280(nCode, strLog);
        FUN_140ab1290(FUN_140166440(), 0xb, 400, L"enqueueErrorLog with nCode: {0}, strLog: {1}", nCode, strLog);
    }
}

// @0x140c75a10
void CClientPlatformBase::vfunc_24() {}
// @0x140c75a20
void CClientPlatformBase::vfunc_25(void*) {}
// @0x140c75a40
int CClientPlatformBase::vfunc_27() { return 1; }

// @0x140c75a60
void* CClientPlatformBase::vfunc_28()
{
    return CAntiHackManager::CreateInstance();
}

// @0x140c75a80
void CClientPlatformBase::vfunc_29()
{
    CAntiHackManager::DestroyInstance();
}

// @0x140c75aa0
void CClientPlatformBase::vfunc_30() {}

// @0x140c75ab0
void CClientPlatformBase::vfunc_31(CStringA, int, int a3)
{
    PostMessageA(FUN_14209c720(FUN_140aadf80()), 0x467, (WPARAM)a3, 0);
}

// @0x140c75b20
void CClientPlatformBase::vfunc_32(void*) {}
// @0x140c75b40
void CClientPlatformBase::vfunc_33(__int64) {}
// @0x140c75b60
int CClientPlatformBase::vfunc_34(void*) { return 3; }
// @0x140c75b80
int CClientPlatformBase::vfunc_35(void*) { return 3; }
// @0x140c75ba0
int CClientPlatformBase::vfunc_36() { return 0; }
// @0x140c75bb0
int CClientPlatformBase::vfunc_37(void*) { return 1; }
// @0x140c75bd0
void CClientPlatformBase::vfunc_38(void*) {}

// @0x140c75bf0
bool CClientPlatformBase::vfunc_40(__int64 nTime)
{
    return FUN_140930240() - nTime >= 0;
}

// @0x140c75c30
bool CClientPlatformBase::vfunc_39(__int64 nTime, int nKind)
{
    return FUN_140930390(nKind) - nTime >= 0;
}

// @0x140c75c80
bool CClientPlatformBase::vfunc_41(__int64 nTime)
{
    if (!FUN_140166410()->FUN_14036d650())
        return false;
    if (DAT_143ab2914 >= 52)
        return FUN_140930ae0() - nTime >= 0;
    return false;
}

// @0x140c75cf0
void CClientPlatformBase::vfunc_42(void*) {}
// @0x140c75d10
bool CClientPlatformBase::vfunc_43(int, bool, int) { return false; }

// @0x140c75d30
const CStringA& CClientPlatformBase::vfunc_44()
{
    return FUN_141adc5d0(FUN_1403ed2b0(), 20156);
}

// @0x140c75d60
const CStringA& CClientPlatformBase::vfunc_45()
{
    return FUN_141adc530(FUN_1403ed2b0(), 20156);
}

// @0x140c75d90
int CClientPlatformBase::vfunc_46() { return 2; }

// @0x140c75db0
void CClientPlatformBase::vfunc_47(CStringA strA, CStringA strB)
{
    void* pWindow = FUN_140b04f80(20156);
    if (pWindow != 0)
        FUN_1410355e0(pWindow, CStringA(strA), CStringA(strB));
}

// @0x140c75e70
void CClientPlatformBase::vfunc_48(MS2Ptr<CUserReportData> spReport)
{
    UIReportDialog* pDialog = FUN_140c76fd0(0x4e86);
    if (pDialog == 0)
        return;
    if (pDialog->FUN_141924630() == 1)
        return;
    switch (spReport->GetType()) {
    case 0:
        pDialog->FUN_141ab9aa0(spReport->GetField40(), spReport->GetTitle());
        break;
    case 1:
        pDialog->FUN_141ab9b10(spReport->GetTitle(), spReport->GetField78());
        break;
    case 2:
        pDialog->FUN_141ab9a10(spReport->GetField48(), spReport->GetField58(), spReport->GetField50(), spReport->GetTitle());
        break;
    case 3:
        pDialog->FUN_141ab9b80(spReport->m_id, spReport->GetField60(), spReport->GetField38(), spReport->GetTitle(),
                               spReport->m_n110);
        break;
    case 4:
        pDialog->FUN_141ab9c50(spReport->GetField68(), spReport->GetTitle(), spReport->GetField70(), spReport->GetField74());
        break;
    case 7:
        pDialog->FUN_141ab9ce0(spReport->GetTitle(), spReport->GetField80());
        break;
    case 8:
        MS2_ASSERT_AT(512, 0);
        break;
    default:
        MS2_ASSERT_AT(515, 0);
        return;
    }
    pDialog->FUN_141924680();
    FUN_141276180(&s_strReportSiren, CStringA(""));
}

// @0x140c76440
int CClientPlatformBase::vfunc_49() { return 0; }
// @0x140c76450
void CClientPlatformBase::vfunc_50() {}
// @0x140c76460
void CClientPlatformBase::vfunc_51() {}
// @0x140c76470
int CClientPlatformBase::vfunc_52(void*, int) { return 1; }
// @0x140c76490
int CClientPlatformBase::vfunc_53(void*, int) { return 1; }
// @0x140c764b0
int CClientPlatformBase::vfunc_54(CStringW, CStringW, int, CStringW) { return 1; }
// @0x140c76500
void CClientPlatformBase::vfunc_55(float) {}
// @0x140c76520
void CClientPlatformBase::vfunc_56(int) {}
// @0x140c76530
void CClientPlatformBase::vfunc_57(void*) {}
// @0x140c76550
void CClientPlatformBase::vfunc_59(int) {}
// @0x140c76560
void CClientPlatformBase::vfunc_58(int, int) {}
// @0x140c76580
void CClientPlatformBase::vfunc_60(int) {}
// @0x140c76590
void CClientPlatformBase::vfunc_61() {}
// @0x140c765a0
void CClientPlatformBase::vfunc_62() {}
// @0x140c765b0
void CClientPlatformBase::vfunc_63(bool, int, int) {}

// MS2-FUNCTIONAL: the exe frame (0x48) has no /GS cookie for the 40-byte option profile local; the opaque placeholder struct gets one (a pointer member drops it but leaves a 0x58 frame); same callees
// @0x140c765d0
void CClientPlatformBase::vfunc_64(int nMode)
{
    if (nMode >= 0 && nMode < 3) {
        {
            Unk_OptionProfile kProfile;
            FUN_14125ec20(&kProfile);
            kProfile.m_nMode = nMode;
            FUN_14125ef60(FUN_140c77560(FUN_1409a8b10()), &kProfile);
            FUN_14125ef90(&kProfile);
        }
        FUN_1412432d0(FUN_1409a8b10());
    }
}

// @0x140c76640
void CClientPlatformBase::vfunc_65(int) {}

// @0x140c76650
void CClientPlatformBase::vfunc_67()
{
    Unk_NexonAnalytics* pAnalytics = FUN_140c77900();
    if (pAnalytics->FUN_14092ca70(pAnalytics->GetModuleName()) == 1) {
        const char* pszModule = pAnalytics->GetModuleName();
        FUN_1403a1280(FUN_140166440(), 0xb, 400, L"{0} 파일을 정상적으로 로드했습니다.", pszModule);
        m_bAnalyticsLoaded = true;
    } else {
        const char* pszModule = pAnalytics->GetModuleName();
        FUN_1403a1280(FUN_140166440(), 1, 400, L"{0} 파일을 로드하지 못했습니다.", pszModule);
    }
}

// MS2-FUNCTIONAL: the exe frame has a /GS cookie (some local of the original is array-typed, not identified among the Nx event/string helpers); same callees and control flow
// @0x140c76710
void CClientPlatformBase::vfunc_68()
{
    __int64 nId = 0;
    CStringA strSerial = vfunc_75();
    if (strSerial.IsEmpty())
        return;
    if (!m_bAnalyticsLoaded)
        return;
    Unk_NxEvent kEvent;
    kEvent.m_nType = 4;
    kEvent.m_strSerial.Set((const char*)strSerial, 3);
    CStringA strId = vfunc_77();
    __int64 nParsed = FUN_140718350(strId);
    if (nParsed != 0)
        nId = nParsed;
    kEvent.m_numId.Set(nId);
    nId = kEvent.m_numId.GetValue();
    CStringA strSession = vfunc_76();
    if (!strSession.IsEmpty())
        kEvent.m_strSession.Set((const char*)strSession, 3);
    FUN_140c76c70(FUN_140166440(), 0xb, 400, L"InitializeNexonAnalytics nexonSn={0} sessionId={1} serviceId={2}", nId,
                  strSession, strSerial);
    Unk_NxNumber kService(DAT_1439f4840);
    Unk_NexonAnalytics* pAnalytics = FUN_140c77900();
    Unk_NxString kHost("livelog.nexon.com", 3);
    bool bResult;
    if (nId != 0) {
        Unk_NxString kVersion("1.0.0", 3);
        if (pAnalytics->FUN_14092ce80(&kVersion, &kHost) && pAnalytics->FUN_14092cf80(&kEvent, &kHost, &kService))
            bResult = true;
        else
            bResult = false;
    } else {
        bResult = false;
    }
    if (bResult) {
        FUN_1401859c0(FUN_140166440(), 0xb, 400, L"Nexon Analytics SDK 의 초기화를 완료했습니다.");
        m_bAnalyticsOn = true;
    }
}

// @0x140c76a60
void CClientPlatformBase::vfunc_69()
{
    if (m_bAnalyticsOn) {
        m_bAnalyticsOn = false;
        FUN_140c77900()->FUN_14092d070(true);
        FUN_1401859c0(FUN_140166440(), 0xb, 400, L"Nexon Analytics SDK 를 정상적으로 종료했습니다.");
    }
}

// @0x140c76ac0
void CClientPlatformBase::vfunc_70()
{
    if (m_bAnalyticsLoaded) {
        Unk_NexonAnalytics* pAnalytics = FUN_140c77900();
        pAnalytics->FUN_14092cbf0();
        const char* pszModule = pAnalytics->GetModuleName();
        FUN_1403a1280(FUN_140166440(), 0xb, 400, L"{0} 파일을 정상적으로 언로드했습니다.", pszModule);
    }
}

// @0x140c76b30
void CClientPlatformBase::vfunc_71(void*) {}

// @0x140c76b50
void CClientPlatformBase::vfunc_72()
{
    FUN_1416a0e70();
    PostQuitMessage(0);
}

// @0x140c76b80
int CClientPlatformBase::vfunc_74() { return 0; }

// @0x140c76b90
CStringA CClientPlatformBase::vfunc_75()
{
    return "";
}

// @0x140c76be0
CStringA CClientPlatformBase::vfunc_76()
{
    return "";
}

// @0x140c76c30
CStringA CClientPlatformBase::vfunc_77()
{
    return "0";
}

// @0x140c76c70
// MS2-FUNCTIONAL: the exe expands the {0}/{1}/{2} format with an inlined variadic template; this substitutes directly
void FUN_140c76c70(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const __int64& nArg0,
                   const CStringA& strArg1, const CStringA& strArg2)
{
    CStringW strText(pszFormat);
    CStringW strValue;
    strValue.Format(L"%I64d", nArg0);
    strText.Replace(L"{0}", strValue);
    strText.Replace(L"{1}", CStringW(strArg1));
    strText.Replace(L"{2}", CStringW(strArg2));
    FUN_1401859c0(pLog, nLevel, nCategory, strText);
}

// @0x140c76fd0
UIReportDialog* FUN_140c76fd0(int nId)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> spObject = ((Unk_CpUIService*)FUN_1403ed2b0())->FUN_141adcea0(nId);
        if (spObject.get() != 0)
            return dynamic_cast<UIReportDialog*>((UIObject*)spObject);
    }
    return 0;
}

// @0x140c77140
Unk_NxNumber::Unk_NxNumber(int n)
{
    Init(n);
}

// @0x140c77190
void Unk_NxNumber::Init(unsigned n)
{
    m_nKind = 0;
    m_nFlags = 0;
    m_nSize = 0;
    m_n8 = 0;
    Set(n);
}

// @0x140c77230
void FUN_140c77230(void* pThis)
{
    FUN_140c77760(pThis);
}

// @0x140c77260
Unk_NexonAnalytics::~Unk_NexonAnalytics()
{
    FUN_14092cbf0();
}

// @0x140c772f0
Unk_NxNumber::~Unk_NxNumber()
{
    FUN_14092e580(this);
}

// @0x140c77310
Unk_NxString::Unk_NxString(const char* psz, int)
{
    FUN_140c777f0(psz, 3);
}

// @0x140c77340
Unk_NxNumber::Unk_NxNumber(__int64 n)
{
    Set(n);
}

// @0x140c77090
Unk_NxEvent::Unk_NxEvent()
{
}

// @0x140c77560
void* FUN_140c77560(void* pGame)
{
    return (char*)pGame + 0x9c;
}

// @0x140c77720
void CClientPlatformBase::vfunc_66() {}

// @0x140c77730
void CClientPlatformBase::vfunc_73(int) {}

// @0x140c777f0
void Unk_NxString::FUN_140c777f0(const char* psz, int nMode)
{
    Set(psz, nMode);
}

// @0x140c77820
void Unk_NxNumber::Set(__int64 n)
{
    SetStorage(n);
}

// @0x140c77850
void Unk_NxNumber::Set(unsigned n)
{
    FUN_14092ea10(this, 3);
    void* p = FUN_140159860(8, &m_n10);
    *(unsigned __int64*)p = n;
}

// @0x140c778a0
void Unk_NxNumber::SetStorage(__int64 n)
{
    FUN_14092ea10(this, 3);
    void* p = FUN_140159860(8, &m_n10);
    *(__int64*)p = n;
}

// @0x140c778f0
const char* Unk_NexonAnalytics::GetModuleName() const
{
    return "NexonAnalytics64.dll";
}

// @0x140c77100
IClientPlatform::IClientPlatform()
{
}

// @0x140c77290
Unk_NxEvent::~Unk_NxEvent()
{
}

// @0x140c77900
Unk_NexonAnalytics* FUN_140c77900()
{
    static Unk_NexonAnalytics s_kAnalytics;
    return &s_kAnalytics;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3690-0x142ca37f0 .text$yd
