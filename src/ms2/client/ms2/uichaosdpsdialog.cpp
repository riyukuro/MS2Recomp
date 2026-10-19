// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uichaosdpsdialog.h.
// MS2-UNIT: ?\uichaosdpsdialog.cpp
// MS2-RANGE: 0x140e05460-0x140e09a90 .text$mn
// MS2-RANGE: 0x1400d6fd0-0x1400d7230 .text$di
// MS2-FUNCTIONAL: five functions (055b0, 05950, vfunc_28, vfunc_72, the sort comparator) differ in register/stack allocation only; behaviour-equivalent.
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCPartyMember@@@@_K@Z 0x140e09040 ; unique
// MS2-PIN: ?vfunc_48@UIChaosDPSDialog@@UEAAHXZ 0x140e09160 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCPartyMember@@@@AEBAXPEAX@Z 0x140e091d0 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VCPartyMember@@@@V?$CElementTraits@V?$MS2Ptr@VCPartyMember@@@@@ATL@@@ATL@@QEBA_NXZ 0x140e09170
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uichaosdpsdialog.h"
#include <algorithm>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/client/ms2/battlerecordmanager.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- header statics (the second copy of the sort names comes from a header between the two dialog statics) ----
static CString s_strSortTypeNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keys;

// ---- unit-local views of exe objects ----

// The game option block (the second member of the settings singleton): two flags.
struct Unk_ChaosOpt
{
    bool FUN_14125bbe0();                                   // 0x14125bbe0 byte +4 and byte +0x15 are set
    char m_pad_00[4];
    char m_bFlag;                                           // +4
};
class Unk_ChaosSettings
{
public:
    Unk_ChaosOpt* FUN_140e09150();                          // 0x140e09150 &m_18
    char m_pad_00[0x18];
    Unk_ChaosOpt m_opt;                                     // +0x18
};
Unk_ChaosSettings* FUN_1409a8b10();

class Unk_ChaosFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_ChaosFeatures* FUN_140166410();
CPartyManager* FUN_1409670d0();

// The object registry (FUN_1403ed2d0) and the local player lookup.
class Unk_ChaosWorld;
Unk_ChaosWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_ChaosWorld* pWorld);
__int64 FUN_141656a80(PCBase* pPC);

// The AS root object of the dialog, with the invokes the exe instantiates for it.
class Unk_ChaosAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW str);        // 0x140acd130 Invoke(name, string)
    Scaleform::GFx::Value FUN_140e06cc0(const char* szMethod, double d);            // 0x140e06cc0 Invoke(name, number)
};

// The chat record the notice history is posted as (same record as usercommandcli.cpp's command chat).
struct Unk_ChaosChat
{
    Unk_ChaosChat();                                        // 0x140acd570
    ~Unk_ChaosChat();                                       // 0x140acd770
    int state, kind;
    CStringW message, target;
    __int64 value;
};
MS2_CHECK_SIZE(Unk_ChaosChat, 0x20);
void FUN_141276f80(const Unk_ChaosChat& kChat);

// Number parsing, localized strings and ASObj/Value setters of other units.
double FUN_1407184e0(const CStringW& str);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
CStringW FUN_140c2fcc0(CStringW strFormat, const int& nHour, const int& nMinute, const int& nSecond, const CStringW& strArg);
void FUN_141b70810(unsigned nMs, CStringW& strOut);
void FUN_1422b8160(ASData* pData, double d);
void FUN_140bd0d90(ASObj* pObj, const char* szName, int n);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);
void FUN_1422bcda0(Scaleform::GFx::Value* pValue, double d);

// The sort key shared by the ranking comparator and the rebuild (0x143ac5668).
static int s_nSortMode;

bool FUN_140e066f0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB);

// @0x140e05460
UIChaosDPSDialog::UIChaosDPSDialog()
{
    m_2c = 0x11;
    m_nGroup = 2;
    m_nMode = 0;
    FUN_141925e70(0, 1);
}

// @0x140e05510
UIChaosDPSDialog::~UIChaosDPSDialog()
{
}

// @0x140e05560
CString UIChaosDPSDialog::vfunc_1()
{
    return "ChaosDPSDialog";
}

// @0x140e055b0
bool UIChaosDPSDialog::FUN_140e055b0(ASObj& obj, CPartyMember* pMember, unsigned nRank)
{
    if (pMember != 0)
    {
        obj.FUN_1409c0d20("rank", nRank);
        obj.FUN_1409c48f0("level", pMember->user.m_34);
        FUN_140bd0d90(&obj, "job", pMember->user.m_40);
        obj.FUN_1407cbb20("name", pMember->user.FUN_1408f19e0());
        double dMeter = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, pMember->FUN_141637bb0(), m_nMode));
        obj.FUN_140e06d60("meterValue", dMeter);
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, pMember->FUN_141637bb0(), m_nMode);
        obj.FUN_1407cbb20("meterText", strMeter);
    }
    return pMember != 0;
}

// @0x140e057d0
void UIChaosDPSDialog::FUN_140e057d0()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_1405c2690(CStringW(L"s_chaosdps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    static_cast<Unk_ChaosAS*>(m_30.operator->())->FUN_140acd130("setTitle", strTitle);
    static_cast<AScript*>(m_30.operator->())->Invoke("setAscendingMeterValue", m_nMode == 6);
}

#ifndef MS2_HOOK_DLL
// @0x140e05950
void UIChaosDPSDialog::FUN_140e05950()
{
    if (m_30.IsNull() == 0)
    {
        CStringW strTime = CBattleRecordManager::GetInstance()->FUN_140a04b00(m_nGroup);
        static_cast<Unk_ChaosAS*>(m_30.operator->())->FUN_140acd130("setTime", strTime);
        ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = FUN_1409670d0()->FUN_14162ba30();
        if (members.IsEmpty() == 0)
        {
            m_members.clear();
            for (unsigned i = 0; i < members.GetCount(); i++)
            {
                CPartyMember* pMember = members[i].get();
                if (pMember != 0)
                    m_members.push_back(MS2Ptr<CPartyMember>(pMember));
            }
            s_nSortMode = m_nMode;
            std::sort(m_members.begin(), m_members.end(), FUN_140e066f0);
            MS2Ptr<CPartyMember> spLast = m_members[m_members.size() - 1];
            if (spLast.get() != 0)
            {
                double dBottom = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, spLast->FUN_141637bb0(), m_nMode));
                static_cast<Unk_ChaosAS*>(m_30.operator->())->FUN_140e06cc0("setBottomMeterValue", dBottom);
            }
            for (unsigned i = 0; i < m_members.size(); i++)
            {
                MS2Ptr<CPartyMember> spMember = m_members[i];
                if (i < 10)
                {
                    ASObj obj(2);
                    if (FUN_140e055b0(obj, spMember.get(), i + 1) != 0)
                        m_30->Invoke("UpdateMember", Scaleform::GFx::Value(obj.FUN_1422bb870()));
                }
                PCBase* pMe = FUN_141bd0cc0(FUN_1403ed2d0());
                if (pMe != 0)
                {
                    __int64 nMyId = FUN_141656a80(pMe);
                    if (nMyId == spMember->user.m_8)
                    {
                        ASObj objMy(2);
                        if (FUN_140e055b0(objMy, spMember.get(), i + 1) != 0)
                            m_30->Invoke("SetMyRank", Scaleform::GFx::Value(objMy.FUN_1422bb870()));
                    }
                }
            }
        }
    }
}
#endif

// @0x140e05f80
void UIChaosDPSDialog::FUN_140e05f80()
{
    if (m_30.IsNull())
        return;
    int nCount = FUN_1409670d0()->FUN_14162af00();
    if (nCount < 10)
        m_30->Invoke("RemoveMember");
}

// @0x140e06000
void UIChaosDPSDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140e06020
void UIChaosDPSDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_tick.FUN_140268840();
    CBattleRecordManager::GetInstance()->FUN_140a03f60(m_nGroup);
    FUN_140e057d0();
    FUN_140e05950();
}

// @0x140e06080
int UIChaosDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        FUN_1409a8b10()->FUN_140e09150()->m_bFlag = 0;
        CBattleRecordManager::GetInstance()->FUN_140a03fe0(m_nGroup);
        vfunc_67();
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onReset", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->FUN_140a03fa0(m_nGroup);
        return 1;
    }
    if (_stricmp("onNotice", szMethod) == 0)
    {
        CMsTime kNow(GetServerTime());
        int nSecond = kNow.GetSecond();
        int nMinute = kNow.GetMinute();
        int nHour = kNow.GetHour();
        CStringW strHistory = FUN_140c2fcc0(CStringW(L"s_chaosdps_notice_history_prefix"), nHour, nMinute, nSecond, CBattleRecordManager::FUN_140a04bc0(m_nMode));
        CStringW strRow = FUN_14028b8e0(L"s_chaosdps_notice_history_row");
        for (unsigned i = 0; i < m_members.size() && i <= 9; i++)
        {
            MS2Ptr<CPartyMember> spMember = m_members[i];
            strHistory.Append(StringFormat((const wchar_t*)strRow, i + 1, spMember->user.FUN_1408f19e0(),
                CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, spMember->FUN_141637bb0(), m_nMode)));
        }
        int nNow = GetTickCountMs2();
        int nTime = CBattleRecordManager::GetInstance()->FUN_140a04060(m_nGroup);
        nTime = nNow - nTime;
        CStringW strTotal;
        FUN_141b70810(nTime, strTotal);
        strHistory.Append(FUN_1405c2690(CStringW(L"s_chaosdps_notice_history_total_time"), strTotal));
        Unk_ChaosChat kChat;
        kChat.kind = 7;
        kChat.message = strHistory;
        FUN_141276f80(kChat);
        return 1;
    }
    if (_stricmp("onTextToggle", szMethod) == 0)
    {
        m_nMode = m_nMode + 1;
        if (6 < m_nMode)
            m_nMode = 0;
        FUN_140e057d0();
        return 1;
    }
    return 0;
}

// @0x140e06630
void UIChaosDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_1409a8b10()->FUN_140e09150()->FUN_14125bbe0() != 0)
    {
        if (FUN_1409670d0()->FUN_14162ab20() != 0)
        {
            if (FUN_140166410()->FUN_14036d570(0xbe) != 0)
            {
                if (m_30.IsNull() != 0)
                    return;
                if (m_tick.FUN_140268870(100) == 0)
                    return;
                FUN_140e05950();
                return;
            }
        }
    }
    vfunc_67();
}

// Orders the ranking: descending meter value (ascending for mode 6).
#ifndef MS2_HOOK_DLL
// @0x140e066f0
bool FUN_140e066f0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB)
{
    double dA = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(2, spA->FUN_141637bb0(), s_nSortMode));
    double dB = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(2, spB->FUN_141637bb0(), s_nSortMode));
    bool bLess;
    if (s_nSortMode == 6)
        bLess = dA < dB;
    else
        bLess = dB < dA;
    return bLess;
}
#endif

// @0x140e06cc0
Scaleform::GFx::Value Unk_ChaosAS::FUN_140e06cc0(const char* szMethod, double d)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcda0(args.FUN_1409b1f70(0), d);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e06d60
void ASObj::FUN_140e06d60(const char* szName, double d)
{
    ASData args;
    FUN_1422b8160(&args, d);
    FUN_1407cd930(&m_value, szName, args.FUN_1422b9260());
}

// @0x140e09150
Unk_ChaosOpt* Unk_ChaosSettings::FUN_140e09150()
{
    return &m_opt;
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140E055B0, UIChaosDPSDialog, FUN_140e055b0, 538, 0x93474119);
MS2_REPLACE_METHOD(0x140E057D0, UIChaosDPSDialog, FUN_140e057d0, 374, 0xD3E773C1);
MS2_REPLACE_METHOD(0x140E05F80, UIChaosDPSDialog, FUN_140e05f80, 111, 0x0AD55661);
