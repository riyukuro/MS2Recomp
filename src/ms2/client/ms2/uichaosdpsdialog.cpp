// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uichaosdpsdialog.h.
// MS2-UNIT: ?\uichaosdpsdialog.cpp
// MS2-RANGE: 0x140e05460-0x140e09a90 .text$mn
// MS2-RANGE: 0x1400d6fd0-0x1400d7230 .text$di
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
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include "ms2/placeholder/commandchat.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cgameoption.h"

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

class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

// The object registry (FUN_1403ed2d0) and the local player lookup.
class Unk_ChaosWorld;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
class PCBase   // C3: member view for the former free stand-ins
{
public:
    __int64 FUN_141656a80();
};

// The AS root object of the dialog (its Invoke(number) is ASArray::FUN_140e06cc0, asobj.h).
class Unk_ChaosAS : public AScript
{
};

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
int FUN_141276f80(Unk_CommandChat* pChat);

// Number parsing, localized strings and ASObj/Value setters of other units.
double FUN_1407184e0(const CStringW& str);
CStringW GetStringCommonByKey(const CStringW& strKey);
void FUN_141b70810(unsigned nMs, CStringW& strOut);
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
CString UIChaosDPSDialog::GetTypeName()
{
    return "ChaosDPSDialog";
}

// @0x140e055b0
int UIChaosDPSDialog::FUN_140e055b0(ASObj& obj, CPartyMember* pMember, unsigned nRank)
{
    if (pMember == 0)
        return 0;
    Unk_UserProxy& user = pMember->user;
    obj.FUN_1409c0d20("rank", nRank);
    obj.FUN_1409c48f0("level", user.m_34);
    ((class ASObj*)(class ASObj*)(&obj))->FUN_140bd0d90("job", user.m_40);
    ((class AScript&)(obj)).FUN_1407cbb20("name", user.FUN_1408f19e0());
    double dMeter = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, pMember->FUN_141637bb0(), m_nMode));
    obj.FUN_140e06d60("meterValue", dMeter);
    {
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, pMember->FUN_141637bb0(), m_nMode);
        ((class AScript&)(obj)).FUN_1407cbb20("meterText", strMeter);
    }
    return 1;
}

// @0x140e057d0
void UIChaosDPSDialog::OnTextToggle()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_14028dfa0<CStringW>(CStringW(L"s_chaosdps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    static_cast<Unk_ChaosAS*>(m_30.operator->())->Invoke("setTitle", strTitle);
    static_cast<AScript*>(m_30.operator->())->Invoke("setAscendingMeterValue", m_nMode == 6);
}

#ifndef MS2_HOOK_DLL
// @0x140e05950
void UIChaosDPSDialog::FUN_140e05950()
{
    if (m_30.IsNull())
        return;
    CStringW strTime = CBattleRecordManager::GetInstance()->GetElapsedTimeText(m_nGroup);
    static_cast<Unk_ChaosAS*>(m_30.operator->())->Invoke("setTime", strTime);
    ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = TSingleton<CPartyManager>::GetInstance()->GetMembers();
    if (members.IsEmpty())
        return;
    m_members.clear();
    for (unsigned i = 0; i < members.GetCount(); i++)
    {
        CPartyMember* pMember = members[i].get();
        if (pMember != 0)
        {
            MS2Ptr<CPartyMember> spMember(pMember);
            m_members.push_back(static_cast<MS2Ptr<CPartyMember>&&>(spMember));
        }
    }
    s_nSortMode = m_nMode;
    std::sort(m_members.begin(), m_members.end(), FUN_140e066f0);
    MS2Ptr<CPartyMember> spLast = m_members[m_members.size() - 1];
    if (spLast.get() != 0)
    {
        double dBottom = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, spLast->FUN_141637bb0(), m_nMode));
        static_cast<ASArray*>(m_30.operator->())->FUN_140e06cc0("setBottomMeterValue", dBottom);
    }
    for (unsigned i = 0; i < m_members.size(); i++)
    {
        MS2Ptr<CPartyMember> spMember = m_members[i];
        if (i < 10)
        {
            ASObj obj(2);
            if (FUN_140e055b0(obj, spMember.get(), i + 1))
                m_30->Invoke("UpdateMember", Scaleform::GFx::Value(obj.FUN_1422bb870()));
        }
        do
        {
            PCBase* pMe = ((class PCBase*)((class WorldService*)(class Unk_ChaosWorld*)(((class Unk_ChaosWorld*)WorldService::GetInstance())))->FUN_141bd0cc0());
            if (pMe == 0)
                break;
            if (((class PCBase*)(class PCBase*)(pMe))->FUN_141656a80() != spMember->user.m_8)
                break;
            ASObj objMy(2);
            if (!FUN_140e055b0(objMy, spMember.get(), i + 1))
                break;
            m_30->Invoke("SetMyRank", Scaleform::GFx::Value(objMy.FUN_1422bb870()));
        } while (0);
    }
}
#endif

// @0x140e05f80
void UIChaosDPSDialog::FUN_140e05f80()
{
    if (m_30.IsNull())
        return;
    int nCount = TSingleton<CPartyManager>::GetInstance()->FUN_14162af00();
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
    m_tick.Init();
    CBattleRecordManager::GetInstance()->StartGroupIfInactive(m_nGroup);
    OnTextToggle();
    FUN_140e05950();
}

// @0x140e06080
int UIChaosDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        reinterpret_cast<Unk_ChaosSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140e09150()->m_bFlag = 0;
        CBattleRecordManager::GetInstance()->StopGroup(m_nGroup);
        vfunc_67();
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onReset", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->StartGroup(m_nGroup);
        return 1;
    }
    else if (_stricmp("onNotice", szMethod) == 0)
    {
        CMsTime kNow(GetServerTime());
        int nSecond = kNow.GetSecond();
        int nMinute = kNow.GetMinute();
        int nHour = kNow.GetHour();
        CStringW strHistory = FUN_14028dfa0<int, int, int, CStringW>(CStringW(L"s_chaosdps_notice_history_prefix"), nHour, nMinute, nSecond, CBattleRecordManager::FUN_140a04bc0(m_nMode));
        CStringW strRow = GetStringCommonByKey(L"s_chaosdps_notice_history_row");
        for (unsigned i = 0; i < m_members.size(); i++)
        {
            if (i >= 10)
                break;
            MS2Ptr<CPartyMember> spMember = m_members[i];
            CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, spMember->FUN_141637bb0(), m_nMode);
            strHistory.Append(StringFormat((const wchar_t*)strRow, i + 1, spMember->user.FUN_1408f19e0(), strMeter));
        }
        int nNow = GetTickCountMs2();
        int nTime = nNow - CBattleRecordManager::GetInstance()->GetGroupStartTick(m_nGroup);
        CStringW strTotal;
        FUN_141b70810(nTime, strTotal);
        strHistory.Append(FUN_14028dfa0<CStringW>(CStringW(L"s_chaosdps_notice_history_total_time"), strTotal));
        Unk_CommandChat kChat;
        kChat.kind = 7;
        kChat.message = strHistory;
        FUN_141276f80((Unk_CommandChat*)&kChat);
        return 1;
    }
    else if (_stricmp("onTextToggle", szMethod) == 0)
    {
        m_nMode = m_nMode + 1;
        if (m_nMode >= 7)
            m_nMode = 0;
        OnTextToggle();
        return 1;
    }
    return 0;
}

// @0x140e06630
void UIChaosDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (reinterpret_cast<Unk_ChaosSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140e09150()->FUN_14125bbe0() == 0 || TSingleton<CPartyManager>::GetInstance()->IsInParty() == 0
        || ((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xbe) == 0)
        vfunc_67();
    else {
        if (!m_30)
            return;
        if (m_tick.Check(100) == 0)
            return;
        FUN_140e05950();
    }
}

// Orders the ranking: descending meter value (ascending for mode 6).
#ifndef MS2_HOOK_DLL
// @0x140e066f0
bool FUN_140e066f0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB)
{
    double dA = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(2, spA->FUN_141637bb0(), s_nSortMode));
    double dB = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(2, spB->FUN_141637bb0(), s_nSortMode));
    if (s_nSortMode == 6)
        return dB > dA;
    else
        return dA > dB;
}
#endif

// @0x140e06cc0
Scaleform::GFx::Value ASArray::FUN_140e06cc0(const char* szMethod, double d)
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
    ((class ASData*)(class ASData*)(&args))->AddDouble(d);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, args.PopValue());
}

// @0x140e09150
Unk_ChaosOpt* Unk_ChaosSettings::FUN_140e09150()
{
    return &m_opt;
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140E055B0, UIChaosDPSDialog, FUN_140e055b0, 538, 0x93474119);
MS2_REPLACE_METHOD(0x140E057D0, UIChaosDPSDialog, OnTextToggle, 374, 0xD3E773C1);
MS2_REPLACE_METHOD(0x140E05F80, UIChaosDPSDialog, FUN_140e05f80, 111, 0x0AD55661);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6210-0x142ca62f0 .text$yd
