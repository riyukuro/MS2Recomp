// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CClientPlatformTencent, the Tencent IClientPlatform: a
// CClientPlatformBase whose slots are mostly constants/no-ops, plus the merat notice parser, the push notice sender
// and the Tencent report dialog opener. The unit also holds the Tencent report struct's destructor/assignment.
// MS2-UNIT: client\ms2\ms2clientplatformtencent.cpp
// MS2-RANGE: 0x1400cef70-0x1400cf250 .text$di
// MS2-RANGE: 0x140c7cd70-0x140c7eea0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2clientplatformtencent.cpp"
// MS2-PIN: ??_7CClientPlatformTencent@@6B?$TSingleton@VCClientPlatformTencent@@@@@ 0x142e12100
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2clientplatformtencent.h"
#include "ms2/client/ms2/uitencentuserreportdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using namespace TencentUserReport;

// ---- header statics (the order of the unit's dynamic initializers) ----
static CStringA s_strReportSiren("PremiumShop_ReportSiren");        // 0x143abf588
static CStringA s_strSkill("skill");                                // 0x143abf640
static CStringA s_strStun("stun");                                  // 0x143abf638
struct Unk_TcHandleMarker {};
void FUN_1401cd100(void* pHandle, int nValue);
static void* s_pHandle;                                             // 0x143abf630
static Unk_TcHandleMarker s_initHandle = (FUN_1401cd100(&s_pHandle, 0), Unk_TcHandleMarker());
static CStringA s_strSortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143abf648
static CStringA s_strSortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143abf690
static CStringA s_strSkill2("skill");                               // 0x143abf688
static CStringA s_strStun2("stun");                                 // 0x143abf680
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);  // 0x143abf6d0

// ---- out-of-unit types and functions ----
extern bool DAT_143ab2947;
extern bool DAT_143ab2966;
bool FUN_1407105c0(COutPacket& packet, int nKind, int nParam);
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_1412751b0(const CStringW& strText, int nKind);
CStringW FUN_1409404f0(__int64 nValue);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1409eec40(int nStringId);
CFeatureManager* FUN_140166410();
void FUN_1409304d0(__int64 nValue, int a, int b, int c);
void FUN_140930af0(__int64 nValue);
void* FUN_140aa6d40();
void FUN_141b0ce20(void* pObject, int nKind, int nValue);
void* FUN_1403ed2b0();                                              // the UI service
MS2Ptr<UIObject> FUN_141adcea0(void* pService, int nId);
const CStringA& FUN_141adc5d0(void* pStrings, int nId);
void FUN_140200e40(Unk_ReportData* pData);                          // the report struct's ctor

class Unk_TcRewardNotify
{
public:
    void FUN_141ac0860(__int64 nValue);                             // "merat"
    void FUN_141ac0990(__int64 nValue);                             // "merat_red"
};
Unk_TcRewardNotify* FUN_140938cd0(int nUiType);

bool FUN_140c7e3d0(CClientPlatformTencent* pThis, unsigned char nKind, bool bOn, int nParam);
UITencentUserReportDialog* FUN_140c7e460(int nId);
Unk_ReportData* FUN_140c7e6c0(Unk_ReportData* pTo, const Unk_ReportData* pFrom);
void FUN_140c7ee40(UITencentUserReportDialog* pDialog, const Unk_ReportData* pData);

class Unk_TcValueApi { public: int FUN_140971260(int nKey); };
class Unk_TcObject { public: Unk_TcValueApi* FUN_1416749a0(); };
class Unk_TcContext { public: Unk_TcObject* FUN_141bd0cc0(); };
Unk_TcContext* FUN_1403ed2d0();

// ---- CClientPlatformTencent ----
// @0x140c7cd70
CClientPlatformTencent::CClientPlatformTencent()
{
}

// @0x140c7cde0
CClientPlatformTencent::~CClientPlatformTencent()
{
}

// @0x140c7ce40
int CClientPlatformTencent::vfunc_1() { return 0; }
// @0x140c7ce50
int CClientPlatformTencent::vfunc_2() { return 0; }

// @0x140c7ce60
const char* CClientPlatformTencent::vfunc_3()
{
    static char s_szMutexName[] = "Global\\D6B677C8-BACF-4097-B1F1-88487E1ED601";
    return s_szMutexName;
}

// @0x140c7ce80
void CClientPlatformTencent::vfunc_5() {}
// @0x140c7ce90
void CClientPlatformTencent::vfunc_7() {}
// @0x140c7cea0
void CClientPlatformTencent::vfunc_8() {}
// @0x140c7ceb0
void CClientPlatformTencent::vfunc_9() {}
// @0x140c7cec0
void CClientPlatformTencent::vfunc_10() {}
// @0x140c7ced0
void CClientPlatformTencent::vfunc_11() {}
// @0x140c7cee0
int CClientPlatformTencent::vfunc_17() { return 1; }
// @0x140c7cf00
void CClientPlatformTencent::vfunc_20(int, int) {}
// @0x140c7cf20
void CClientPlatformTencent::vfunc_24() {}
// @0x140c7cf30
void CClientPlatformTencent::vfunc_33(__int64) {}

// @0x140c7cf50
void* CClientPlatformTencent::vfunc_28()
{
    return CClientPlatformBase::vfunc_28();
}

// @0x140c7cf70
void CClientPlatformTencent::vfunc_29()
{
    CClientPlatformBase::vfunc_29();
}

// @0x140c7cf90
void CClientPlatformTencent::vfunc_31(CStringA a1, int a2, int a3)
{
    CClientPlatformBase::vfunc_31(a1, a2, a3);
}

// @0x140c7d000
int CClientPlatformTencent::vfunc_34(void*) { return 3; }
// @0x140c7d020
int CClientPlatformTencent::vfunc_35(void*) { return 3; }

// @0x140c7d040
int CClientPlatformTencent::vfunc_36()
{
    Unk_TcObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer) {
        return pPlayer->FUN_1416749a0()->FUN_140971260(0x2fac971);
    } else {
        return 0;
    }
}

// @0x140c7d090
int CClientPlatformTencent::vfunc_37(void*) { return 1; }
// @0x140c7d0b0
void CClientPlatformTencent::vfunc_25(void*) {}
// @0x140c7d0d0
void CClientPlatformTencent::vfunc_38(void*) {}

// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
// @0x140c7d0f0 the merat (+0x20 text id) / blue merat notice: the packet holds a type byte, then per currency a
// "show" flag, the new balance and the change
void CClientPlatformTencent::vfunc_42(void* a1)
{
    int nType = static_cast<CInPacket*>(a1)->vfunc_o8_1();
    switch (nType) {
    case 0: {
        DAT_143ab2947 = static_cast<CInPacket*>(a1)->vfunc_o8_1() == 1;
        __int64 nBalance = static_cast<CInPacket*>(a1)->vfunc_o8_4();
        __int64 nDelta = static_cast<CInPacket*>(a1)->vfunc_o8_4();
        FUN_1409304d0(nBalance, 0, 0, 0);
        FUN_141b0ce20(FUN_140aa6d40(), 0xb, 0);
        if (nDelta > 0) {
            Unk_TcRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify != 0)
                pNotify->FUN_141ac0860(nDelta);
            FUN_141276180(CString("Merat_Get"), CString(""));
            CStringW strDelta = FUN_1409404f0(nDelta);
            FUN_1412751b0(FUN_14052bd00(0x2c7, strDelta), 6);
        } else if (nDelta < 0) {
            FUN_141276180(CString("Merat_Use"), CString(""));
            CStringW strDelta = FUN_1409404f0(-nDelta);
            FUN_1412751b0(FUN_14052bd00(0x2d9, strDelta), 6);
            if (FUN_140166410()->FUN_14036d570(0xba))
                FUN_1412751b0(FUN_1409eec40(0x2db), 6);
        }
        break;
    }
    case 1: {
        DAT_143ab2966 = static_cast<CInPacket*>(a1)->vfunc_o8_1() == 1;
        __int64 nBalance = static_cast<CInPacket*>(a1)->vfunc_o8_4();
        __int64 nDelta = static_cast<CInPacket*>(a1)->vfunc_o8_4();
        FUN_140930af0(nBalance);
        FUN_141b0ce20(FUN_140aa6d40(), 0xd, 0);
        if (nDelta > 0) {
            Unk_TcRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify != 0)
                pNotify->FUN_141ac0990(nDelta);
            FUN_141276180(CString("Merat_Get"), CString(""));
            CStringW strDelta = FUN_1409404f0(nDelta);
            FUN_1412751b0(FUN_14052bd00(0x2c8, strDelta), 6);
        } else if (nDelta < 0) {
            FUN_141276180(CString("Merat_Use"), CString(""));
            CStringW strDelta = FUN_1409404f0(-nDelta);
            FUN_1412751b0(FUN_14052bd00(0x2da, strDelta), 6);
            if (FUN_140166410()->FUN_14036d570(0xba))
                FUN_1412751b0(FUN_1409eec40(0x2db), 6);
        }
        break;
    }
    case 2:
        DAT_143ab2947 = static_cast<CInPacket*>(a1)->vfunc_o8_1() == 1;
        FUN_1409304d0(static_cast<CInPacket*>(a1)->vfunc_o8_4(), 0, 0, 0);
        FUN_141b0ce20(FUN_140aa6d40(), 0xb, 0);
        DAT_143ab2966 = static_cast<CInPacket*>(a1)->vfunc_o8_1() == 1;
        FUN_140930af0(static_cast<CInPacket*>(a1)->vfunc_o8_4());
        FUN_141b0ce20(FUN_140aa6d40(), 0xd, 0);
        break;
    case 4:
        FUN_140d86260()->vfunc_45();
        break;
    case 5:
        FUN_141adc5d0(FUN_1403ed2b0(), static_cast<CInPacket*>(a1)->vfunc_o8_3());
        break;
    default:
        MS2_ASSERT_AT(500, 0);
        break;
    }
}

// @0x140c7d9b0
bool CClientPlatformTencent::vfunc_43(int nKind, bool bOn, int nParam)
{
    switch (nKind) {
    case 2:
        if (bOn == true)
            return FUN_140c7e3d0(this, 0, bOn, nParam);
        if (DAT_143ab2947 == false)
            return FUN_140c7e3d0(this, 0, bOn, nParam);
        return false;
    case 8:
        if (bOn == true)
            return FUN_140c7e3d0(this, 1, bOn, nParam);
        if (DAT_143ab2966 == false)
            return FUN_140c7e3d0(this, 1, bOn, nParam);
        return false;
    case 0xe:
        if (bOn == true)
            return FUN_140c7e3d0(this, 2, bOn, nParam);
        if (DAT_143ab2947 == false && DAT_143ab2966 == false)
            return FUN_140c7e3d0(this, 2, bOn, nParam);
        if (DAT_143ab2947 == false && DAT_143ab2966 == true)
            return FUN_140c7e3d0(this, 0, bOn, nParam);
        if (DAT_143ab2947 == true && DAT_143ab2966 == false)
            return FUN_140c7e3d0(this, 1, bOn, nParam);
        return false;
    default:
        MS2_ASSERT_AT(0x235, 0);
        return false;
    }
}

// @0x140c7db80
bool CClientPlatformTencent::vfunc_39(__int64 a1, int a2)
{
    return CClientPlatformBase::vfunc_39(a1, a2);
}

// @0x140c7dbc0
bool CClientPlatformTencent::vfunc_40(__int64 a1)
{
    return CClientPlatformBase::vfunc_40(a1);
}

// @0x140c7dbf0
bool CClientPlatformTencent::vfunc_41(__int64 a1)
{
    return CClientPlatformBase::vfunc_41(a1);
}

// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
// @0x140c7dc20 opens the Tencent report dialog with the report copied into its data
void CClientPlatformTencent::vfunc_48(MS2Ptr<CUserReportData> spReport)
{
    UITencentUserReportDialog* pDialog = FUN_140c7e460(0x4f32);
    if (pDialog != 0) {
        if (pDialog->FUN_141924630() == 1)
            return;
        Unk_ReportData data;
        data.type = spReport->GetField28();
        data.m_88 = spReport->GetFielda0();
        data.m_90 = spReport->GetFielda8();
        data.m_98 = spReport->GetFieldb0();
        data.reportTitle = spReport->GetFieldb8();
        data.reportId = spReport->GetFieldc0();
        data.reportPath = spReport->GetFieldc8();
        data.reportComment = spReport->GetFieldd0();
        data.m_c0 = spReport->GetFieldd8();
        data.m_c8 = spReport->GetFielde0();
        data.m_d0 = "";
        data.m_d8 = spReport->GetFieldf0();
        data.m_e0 = spReport->GetFieldf8();
        data.itemKind = spReport->m_n110;
        data.name = spReport->GetTitle();
        data.target = spReport->GetField80();
        data.itemName = spReport->GetField38();
        data.m_20 = spReport->GetField88();
        data.title = spReport->GetField100();
        data.path = spReport->GetField108();
        data.m_28 = spReport->GetField90();
        data.content = spReport->GetField98();
        reinterpret_cast<Unk_ReportId*>(&data.m_38)->Copy(spReport->m_id);
        data.itemId = spReport->GetField60();
        data.guildId = spReport->GetField48();
        data.guildNumber = spReport->GetField58();
        FUN_140c7ee40(pDialog, &data);
        pDialog->FUN_141924680();
        FUN_141276180(s_strReportSiren, CString(""));
    }
}

// The slots 44/45 return a CStringA reference in the base but are empty here (the exe falls off the end).
#pragma warning(push)
#pragma warning(disable : 4716)
// @0x140c7e210
const CStringA& CClientPlatformTencent::vfunc_45() {}
// @0x140c7e220
const CStringA& CClientPlatformTencent::vfunc_44() {}
#pragma warning(pop)

// @0x140c7e230
int CClientPlatformTencent::vfunc_49() { return 0; }
// @0x140c7e240
void CClientPlatformTencent::vfunc_50() {}
// @0x140c7e250
void CClientPlatformTencent::vfunc_51() {}
// @0x140c7e260
int CClientPlatformTencent::vfunc_52(void*, int) { return 0; }
// @0x140c7e280
int CClientPlatformTencent::vfunc_53(void*, int) { return 0; }
// @0x140c7e2a0
int CClientPlatformTencent::vfunc_54(CStringW, CStringW, int, CStringW) { return 0; }
// @0x140c7e2f0
void CClientPlatformTencent::vfunc_55(float) {}
// @0x140c7e310
void CClientPlatformTencent::vfunc_56(int) {}
// @0x140c7e320
void CClientPlatformTencent::vfunc_59(int) {}
// @0x140c7e330
void CClientPlatformTencent::vfunc_58(int, int) {}
// @0x140c7e350
void CClientPlatformTencent::vfunc_60(int) {}
// @0x140c7e360
void CClientPlatformTencent::vfunc_61() {}
// @0x140c7e370
void CClientPlatformTencent::vfunc_62() {}
// @0x140c7e380
void CClientPlatformTencent::vfunc_63(bool, int, int) {}
// @0x140c7e3a0
void CClientPlatformTencent::vfunc_65(int) {}
// @0x140c7e3b0
void CClientPlatformTencent::vfunc_66() {}
// @0x140c7e3c0
void CClientPlatformTencent::vfunc_73(int) {}

// @0x140c7e3d0 sends the push notice setting (kind, on) to the server
bool FUN_140c7e3d0(CClientPlatformTencent*, unsigned char nKind, bool bOn, int nParam)
{
    COutPacket packet(0x96, 0);
    packet.vfunc_o10_1(nKind);
    packet.vfunc_o10_0(bOn);
    return FUN_1407105c0(packet, nKind, nParam);
}

// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
// @0x140c7e460 the open dialog of the given ui class id as a Tencent report dialog
UITencentUserReportDialog* FUN_140c7e460(int nId)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> spObject = FUN_141adcea0(FUN_1403ed2b0(), nId);
        if (spObject.get() != 0)
            return dynamic_cast<UITencentUserReportDialog*>((UIObject*)spObject);
    }
    return 0;
}

// @0x140c7e590
Unk_ReportData::~Unk_ReportData()
{
}

// @0x140c7e6c0 member-wise copy of the report struct (the ids at +0x2c/+0x5c/+0x84/+0xdc are not copied)
Unk_ReportData* FUN_140c7e6c0(Unk_ReportData* pTo, const Unk_ReportData* pFrom)
{
    pTo->type = pFrom->type;
    pTo->reason = pFrom->reason;
    pTo->name = pFrom->name;
    pTo->target = pFrom->target;
    pTo->itemName = pFrom->itemName;
    pTo->m_20 = pFrom->m_20;
    pTo->m_28 = pFrom->m_28;
    pTo->content = pFrom->content;
    memcpy(&pTo->m_38, &pFrom->m_38, 16);
    pTo->itemId = pFrom->itemId;
    pTo->guildId = pFrom->guildId;
    pTo->guildNumber = pFrom->guildNumber;
    pTo->m_60 = pFrom->m_60;
    pTo->comment = pFrom->comment;
    pTo->title = pFrom->title;
    pTo->path = pFrom->path;
    pTo->itemKind = pFrom->itemKind;
    pTo->m_88 = pFrom->m_88;
    pTo->m_90 = pFrom->m_90;
    pTo->m_98 = pFrom->m_98;
    pTo->reportTitle = pFrom->reportTitle;
    pTo->reportId = pFrom->reportId;
    pTo->reportPath = pFrom->reportPath;
    pTo->reportComment = pFrom->reportComment;
    pTo->m_c0 = pFrom->m_c0;
    pTo->m_c8 = pFrom->m_c8;
    pTo->m_d0 = pFrom->m_d0;
    pTo->m_d8 = pFrom->m_d8;
    pTo->m_e0 = pFrom->m_e0;
    return pTo;
}

// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
// FUN_140c7ee40 reaches the dialog's private data member through the layout friend
template <> struct MS2LayoutCheck<UITencentUserReportDialog, 7001>
{
    static Unk_ReportData& Data(UITencentUserReportDialog* p) { return p->m_data; }
};

// @0x140c7ee40
void FUN_140c7ee40(UITencentUserReportDialog* pDialog, const Unk_ReportData* pData)
{
    FUN_140c7e6c0(&MS2LayoutCheck<UITencentUserReportDialog, 7001>::Data(pDialog), pData);
}

// @0x140c7e570 frees the BSTR a holder points at
void FUN_140c7e570(BSTR* p)
{
    SysFreeString(*p);
}

// MS2-FUNCTIONAL: the exe loads the holder pointer through a register copy before the call
// @0x140c7e6a0
void FUN_140c7e6a0(BSTR* p)
{
    FUN_140c7e570(p);
}

// @0x140c7e9b0 vector/scalar deleting destructor of the 0x10 byte BSTR holders
// MS2-FUNCTIONAL: element destruction loop is open coded instead of the CRT eh vector iterator
void* FUN_140c7e9b0(void* p, unsigned int nFlags)
{
    if ((nFlags & 2) == 0) {
        FUN_140c7e6a0((BSTR*)p);
        if (nFlags & 1) {
            operator delete(p);
        }
    } else {
        char* pBase = (char*)p - 8;
        for (unsigned long long n = *(unsigned long long*)pBase; n > 0; --n) {
            FUN_140c7e6a0((BSTR*)((char*)p + (n - 1) * 0x10));
        }
        if (nFlags & 1) {
            operator delete[](pBase);
        }
        p = pBase;
    }
    return p;
}

// @0x140c7ee70
CRuntimeClass* FUN_140c7ee70()
{
    return CDialog::GetThisClass();
}
