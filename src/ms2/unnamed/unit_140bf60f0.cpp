// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAllianceQuestDialog (the alliance quest window of an
// alliance npc) and the glue of its quest sort / confirm callbacks. See ms2/client/ms2/uialliancequestdialog.h. sh8.
// MS2-UNIT: unit_140bf60f0
// MS2-RANGE: 0x140bf60f0-0x140bfcb00 .text$mn
// MS2-RANGE: 0x1400cb290-0x1400cb590 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strJobCode@@YAXXZ 0x1400cb420 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400cb450 ; probe
// MS2-PIN: ??__Es_strSortValue@@YAXXZ 0x1400cb500 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400cb530 ; probe
// MS2-PIN: ??__Es_strTabIndex@@YAXXZ 0x1400cb560 ; probe
// MS2-PIN: ?IsNull@?$Unk_PayloadPtr@VCQuest@@@@QEBA_NXZ 0x140bfc310 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140bfc3f0 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBAAEBW4Unk_FameAlliance@@PEAU__POSITION@@@Z 0x140bfc4c0 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140bfc530 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140bfc5c0 ; unique
// MS2-PIN: ?vfunc_48@UIAllianceQuestDialog@@UEAAHXZ 0x140bfc630 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEAAAEAHPEAU__POSITION@@@Z 0x140bfc640 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@W4Unk_FameAlliance@@HV?$CElementTraits@W4Unk_FameAlliance@@@ATL@@V?$CElementTraits@H@3@@ATL@@QEBA_NXZ 0x140bfc6b0 ; prop
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIAllianceQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140bfc900 ; unique
// MS2-PIN: ??$Call@VUIAllianceQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIAllianceQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIAllianceQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140bfc940 ; unique
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@AEBH@Z 0x140bfa7f0 ; hand: FMT_VARIADIC_W string table formatter <CStringW, int>
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uialliancequestdialog.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uipopupnpctalkdialog.h"
#include "ms2/commonfiles/famegradedata.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <stdlib.h>
#include <vector>

// ---- statics of the unit's header (init order: the two sort name lists, skill, stun, a condition object, the key
// controller, then three attribute names) ----

static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// ---- unit-local views of exe types ----

// The list control of the movie (the AS list with clear / append).
class Unk_AqList : public AScript
{
public:
    Unk_AqList(const Scaleform::GFx::Value& v, int nMovieId);           // 0x1422cf590
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                               // clear
    void FUN_1422dd230(const ASObj& row);                               // append a row
private:
    void* m_unrecovered_40[9];
};
MS2_CHECK_SIZE(Unk_AqList, 0x88);

// The movie root: Invoke("setData" / "setNpc", object).
class Unk_AqRoot : public AScript { public:
    Scaleform::GFx::Value FUN_140ba4cc0(const char*, const ASObj&);     // Invoke(method, object)
};

class Unk_140acd6e0 : public ASDisplayObject { public:
    void FUN_1422c1fe0(unsigned);                                       // set enabled
};

// The talk script of an npc (Unk_PnScriptPtr, the 16-byte handle): the contents array at +0x68.
class Unk_AqContent;
struct Unk_AqContentPtr
{
    Unk_AqContent* FUN_14078f3d0() const;                               // operator->
    void* m_00;
    void* m_p;
};
class Unk_AqContentArray
{
public:
    int FUN_14078fae0() const;                                          // GetCount
    const Unk_AqContentPtr& FUN_14078f350(__int64 i) const;             // GetAt
};
class Unk_AqTalkScript
{
public:
    char m_pad[0x68];
    Unk_AqContentArray m_contents;                                      // +0x68
};
class Unk_AqContent
{
public:
    char m_pad[0x18];
    CStringW m_strText;                                                 // +0x18
    CStringA m_strSound;                                                // +0x20
};
Unk_PnScriptPtr FUN_140856c50(unsigned nNpcId, int nMode);              // the default script of an npc
Unk_PnScriptPtr FUN_140856980(unsigned nNpcId, const CStringW& strTag); // the script with the tag

struct Unk_AqPos { float m_v[3]; };
void* FUN_1403ed2d0();                                                  // the world service
void* FUN_141bd0cc0(void* pWorld);                                      // its local player
void* FUN_1403ed280();                                                  // the effect service
void* FUN_140166410();
bool FUN_14036d570(void* pOption, int nIndex);
typedef Unk_AqPos (*Unk_AqPosFn)(void*);
typedef unsigned short (*Unk_AqLevelFn)(void*);
inline Unk_AqPos Unk_AqActorPos(void* pActor) { return reinterpret_cast<Unk_AqPosFn>((*reinterpret_cast<void***>(pActor))[18])(pActor); }
inline unsigned short Unk_AqActorLevel(void* pActor) { return reinterpret_cast<Unk_AqLevelFn>((*reinterpret_cast<void***>(pActor))[78])(pActor); }
class Unk_AqNpcTable { public: CString FUN_140a7d1a0(unsigned nNpcId); };   // the illust path of an npc
Unk_AqNpcTable* FUN_1406d6e90();
CString FUN_140cc2c70(const CString& strPath);                          // the full path of an illust
CStringW FUN_1401aa6a0(int nId);                                        // npc name

// out-of-unit callees (names describe uses)
class Unk_AqTicketRules { public: int FUN_14067a0b0(Unk_FameAlliance nAlliance, int nGrade); };
Unk_AqTicketRules* FUN_1401c0db0();
class Unk_AqStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_AqStrings* FUN_1401a9d70();
class Unk_AqItemTable;
Unk_AqItemTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_AqItemTable* p, int nTag);                  // the item of a tag
class Unk_AqInventory { public: char m_pad; };
extern Unk_AqInventory DAT_143ab2a90;
int FUN_140a5f780(Unk_AqInventory* pInv, int nTag, int n);              // item count by tag
extern int DAT_143abdc30;                                               // the alliance npc shown
class Unk_AqUI { public: void FUN_141add520(CStringW strText, CStringW strArg); };
Unk_AqUI* FUN_1403ed2b0();
class Unk_AqMsgBox : public CPtred {};
MS2Ptr<Unk_AqMsgBox> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
void FUN_14151f150(MS2Ptr<CMsgBoxData> spBox);
void FUN_140534d60(MS2Ptr<Unk_AqMsgBox>* p);                            // handle dtor
class Unk_AqPane : public UIDialog { };                                 // the 0x4e3b dialog
class Unk_AqShopMgr;
Unk_AqPane* FUN_140534780(int nUIType);
void FUN_141afb760(Unk_AqPane* p);
void FUN_141b1feb0(void* pTalk);
void* FUN_140967100();
CQuestManager* FUN_140764020();
QuestDataTable* FUN_1407476c0();
CFameTable* FUN_140764010();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b070(CQuestData* pData);
int FUN_14074b1c0(CQuestData* pData, int nBit);
int FUN_14074b030(CQuestData* pData);
UIQuestEventDispatcher* FUN_140bfc4b0();
int FUN_1407636c0(int nNpcId);
int FUN_140931210(int nAlliance);
int FUN_140931250(int nAlliance);
CStringW FUN_140762ee0(int nAlliance, int nGrade);
CStringW FUN_140762f50(int nAlliance, int nGrade);
CStringW FUN_140762de0(int nAlliance);
void FUN_140762fc0(int nAlliance, int* pnCurrent, int* pnMax, CStringW& strPoint);
CString FUN_140762e90(int nAlliance);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_14052b9d0(CStringW strKey, const unsigned short& nLevel, const CStringW& strName);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14062b4f0(CStringW key, const int* value);
CStringW FUN_140763e10(int value);
CStringW FUN_1409404f0(__int64 n);
CString FUN_14021aa20(int nGrade);
CStringW FUN_1416e4df0(int nQuestId);
CStringW FUN_1416e5500(int nQuestId);
int FUN_140761ea0(int, int);
__int64 FUN_140761ba0(int, int);
CStringW FUN_14086aec0(__int64 nSpan, int, int, int, int);
__int64 FUN_140869440();
__int64 FUN_14086b190(int nKind, __int64 nTime);
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const unsigned* pValue);
void FUN_140710590(COutPacket&);
void FUN_1411a4f40(void* pEffects, CString strSound, const Unk_AqPos& kPos);
CStringW FUN_14016a730(const char* psz, int n);                         // narrow -> wide
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                  // has the AS object been released

// Small COMDATs of the unit.
int FUN_140bfc5b0(CQuestManagerCommon* p) { return p->m_selector; }     // @0x140bfc5b0
extern UIQuestEventDispatcher* DAT_143abdd70;
UIQuestEventDispatcher* FUN_140bfc4b0() { return DAT_143abdd70; }       // @0x140bfc4b0

// @0x140bfa1b0 the order of a repeat kind
int FUN_140bfa1b0(int nRepeat)
{
    if (nRepeat == 0)
        return 0;
    if (nRepeat == 2)
        return 2;
    if (nRepeat == 3)
        return 1;
    return 3;
}

// @0x140bfa200 the order of a quest state
int FUN_140bfa200(int nQuest)
{
    if (FUN_140764020()->vfunc_1(nQuest, 0) != 0)
        return 0;
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
    if (spQuest.IsNull())
        return 1;
    return FUN_140764020()->FUN_140745590(nQuest);
}

// @0x140bfa2d0 the quest row order
bool FUN_140bfa2d0(MS2Ptr<CQuestData> spA, MS2Ptr<CQuestData> spB)
{
    int nStateA = FUN_140bfa200(FUN_14074b030(spA.get()));
    int nStateB = FUN_140bfa200(FUN_14074b030(spB.get()));
    if (nStateA != nStateB)
        return nStateA == 0;
    int nRepeatA = FUN_14074b070(spA.get());
    int nRepeatB = FUN_14074b070(spB.get());
    if (nRepeatA != nRepeatB)
        return FUN_140bfa1b0(nRepeatA) < FUN_140bfa1b0(nRepeatB);
    return spA->m_50 < spB->m_50;
}

// The string table formatter; its <CStringW, int> variadic instance is 0x140bfa7f0 (pinned).
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

typedef Delegate<bool(int, const CMsgBoxData&)> AqAnswerDelegate;

// @0x140bfab20 a message box with a text, a result callback and the quest id as its argument
MS2Ptr<CMsgBoxData> FUN_140bfab20(CStringW strText, int nType, AqAnswerDelegate cb, int nQuest)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(nType));
    spBox->SetMsg(strText);
    spBox->FUN_141a027c0(cb);
    spBox->FUN_140534050(nQuest);
    FUN_14151f150(MS2Ptr<CMsgBoxData>(spBox));
    return spBox;
}

// ---- UIAllianceQuestDialog ----

// @0x140bf60f0
UIAllianceQuestDialog::UIAllianceQuestDialog() : m_180(GetTypeName())
{
    m_80 = 0;
    m_88 = 1;
    m_58 = 1;
}

// @0x140bf61f0
UIAllianceQuestDialog::~UIAllianceQuestDialog() {}

// @0x140bf6290
CString UIAllianceQuestDialog::GetTypeName() { return "AllianceQuestDialog"; }

// @0x140bf62e0
void UIAllianceQuestDialog::vfunc_67()
{
    m_180.FUN_140d43990();
    UIDialog::vfunc_67();
    FUN_141b1feb0(FUN_140967100());
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// @0x140bf6360
void UIAllianceQuestDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140bf7630();
    FUN_140bf70f0();
    FUN_140bf6ef0();
    MS2Ptr<Unk_140acd6e0> spAcceptAll = FUN_140bb4b10("m_acceptAll");
    if (spAcceptAll.get() != 0)
        spAcceptAll->FUN_1422c1fe0(FUN_140bf8900());
    MS2Ptr<Unk_140acd6e0> spCompleteAll = FUN_140bb4b10("m_completeAll");
    if (spCompleteAll.get() != 0)
        spCompleteAll->FUN_1422c1fe0(FUN_140bf8ab0());
}

// @0x140bf6520
int UIAllianceQuestDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData unused;
    if (_stricmp("onAccept", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nQuest = data.FUN_1422b8b10();
            if (FUN_140764020()->FUN_1407456d0(nQuest) != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
                packet.vfunc_o10_1(8);
                packet.vfunc_o10_3(nQuest);
                packet.vfunc_o10_2(2);
                FUN_140710590(packet);
            }
            else if (FUN_140764020()->vfunc_1(nQuest, 0) != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
                packet.vfunc_o10_1(8);
                packet.vfunc_o10_3(nQuest);
                packet.vfunc_o10_2(0);
                FUN_140710590(packet);
            }
        }
        return 1;
    }
    else if (_stricmp("onShop", szMethod) == 0)
    {
        Unk_AqPane* pPane = FUN_140534780(0x4e3b);
        if (pPane != 0)
        {
            if (pPane->FUN_141924630() != 0)
                pPane->vfunc_67();
            else
            {
                FUN_141afb760(pPane);
                pPane->FUN_141924680();
            }
        }
    }
    else if (_stricmp("onTalk", szMethod) == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
        packet.vfunc_o10_1(9);
        FUN_140710590(packet);
    }
    else if (_stricmp("onTicket", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nQuest = data.FUN_1422b8b10();
            FUN_140bf8c30(nQuest);
        }
    }
    else if (_stricmp("onAcceptAll", szMethod) == 0)
    {
        if (FUN_140bf8900() != 0)
        {
            FUN_140d74090(AqAnswerDelegate(this, &UIAllianceQuestDialog::SendQuestMode34), L"s_quest_alliance_accept_all_confirm");
        }
    }
    else if (_stricmp("onCompleteAll", szMethod) == 0 && FUN_140bf8ab0() != 0)
    {
        FUN_140d74090(AqAnswerDelegate(this, &UIAllianceQuestDialog::SendQuestMode35), L"s_quest_alliance_complete_all_confirm");
    }
    return 0;
}

// @0x140bf6a90
void UIAllianceQuestDialog::vfunc_o178_2(void* pQuest)
{
    if (reinterpret_cast<CQuest*>(pQuest)->GetQuestType() == 9)
        vfunc_67();
}

// @0x140bf6af0
int UIAllianceQuestDialog::FUN_140bf6af0(int nNpc)
{
    return FUN_1407636c0(nNpc);
}

// @0x140bf6b20
CStringW UIAllianceQuestDialog::FUN_140bf6b20(int nAlliance)
{
    return FUN_1405c2690(L"s_alliance_quest_current_fame_grade", FUN_140762ee0(nAlliance, FUN_140931210(nAlliance)));
}

// @0x140bf6be0
CStringW UIAllianceQuestDialog::FUN_140bf6be0(int nAlliance)
{
    return FUN_1405c2690(L"s_alliance_quest_daily_mission", FUN_140762de0(nAlliance));
}

// @0x140bf6c90
CStringW UIAllianceQuestDialog::FUN_140bf6c90(unsigned nQuest)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (!spData)
        return L"";
    int nRepeat = FUN_14074b070(spData.get());
    CMsTime now(FUN_140869440());
    CMsTime reset;
    if (nRepeat == 2)
    {
        reset = now;
        AddDays(reset, 1);
        TruncateToDay(reset);
    }
    else if (nRepeat == 3)
        reset = FUN_14086b190(spData->m_resetType, now.Get());
    CStringW strTime = FUN_14086aec0((reset - now).GetTimeSpan(), 1, 1, 1, 0);
    if (strTime.GetLength() == 0)
        strTime = GetStringCommonByKey(L"s_alliance_quest_complete_mission_sec");
    return FUN_1405c2690(L"s_alliance_quest_complete_mission", strTime);
}

// @0x140bf6ef0
void UIAllianceQuestDialog::FUN_140bf6ef0()
{
    int nAlliance = FUN_140bf6af0(DAT_143abdc30);
    int nCurrent;
    int nMax;
    CStringW strPoint;
    FUN_140762fc0(nAlliance, &nCurrent, &nMax, strPoint);
    ASObj data(2);
    data.FUN_1407cbb20("fameStr", FUN_140bf6b20(nAlliance));
    data.FUN_1407cbb20("allianceStr", FUN_140bf6be0(nAlliance));
    data.FUN_1407cb9c0("currentFame", nCurrent);
    data.FUN_1407cb9c0("maxFame", nMax);
    data.FUN_1407cbb20("famePoint", strPoint);
    data.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
    static_cast<Unk_AqRoot*>(FUN_1409ee290(&m_30))->FUN_140ba4cc0("setData", data);
}

// @0x140bf70f0
void UIAllianceQuestDialog::FUN_140bf70f0()
{
    Unk_PnScriptPtr spScript = FUN_140856c50(DAT_143abdc30, 0);
    CStringW strLimit = FUN_140bf9e10();
    if (strLimit.GetLength() != 0)
        spScript = FUN_140856980(DAT_143abdc30, L"limitFameGrade");
    CStringW strRequire = FUN_140bf9bd0();
    if (strRequire.GetLength() != 0)
    {
        int nAlliance = FUN_140bf6af0(DAT_143abdc30);
        MS2Ptr<CFameSeasonDef> spSeason = FUN_140764010()->GetSeason(static_cast<Unk_FameAlliance>(nAlliance));
        if (spSeason.get() == 0)
            return;
        spScript = FUN_140856980(DAT_143abdc30, FUN_14016a730(spSeason->m_strLimitNpcScriptTag, 0));
    }
    CStringW strText;
    if (!spScript.IsNull())
    {
        Unk_AqTalkScript* pScript = reinterpret_cast<Unk_AqTalkScript*>(spScript.FUN_14085a610());
        if (pScript->m_contents.FUN_14078fae0() != 0)
        {
            strText = pScript->m_contents.FUN_14078f350(0).FUN_14078f3d0()->m_strText;
            if (pScript->m_contents.FUN_14078f350(0).FUN_14078f3d0()->m_strSound.GetLength() != 0)
            {
                void* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
                if (pActor != 0)
                    FUN_1411a4f40(FUN_1403ed280(), pScript->m_contents.FUN_14078f350(0).FUN_14078f3d0()->m_strSound, Unk_AqActorPos(pActor));
            }
        }
    }
    ASObj data(2);
    data.FUN_1407cba60("imgPath", FUN_140cc2c70(FUN_1406d6e90()->FUN_140a7d1a0(DAT_143abdc30)));
    data.FUN_1407cbb20("npcName", FUN_1401aa6a0(DAT_143abdc30));
    data.FUN_1407cbb20("npcScript", strText);
    static_cast<Unk_AqRoot*>(FUN_1409ee290(&m_30))->FUN_140ba4cc0("setNpc", data);
}

// @0x140bf7630
void UIAllianceQuestDialog::FUN_140bf7630()
{
    int nAlliance = FUN_140bf6af0(DAT_143abdc30);
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d2b0(static_cast<Unk_FameAlliance>(nAlliance), ids);
    std::vector<MS2Ptr<CQuestData> > quests;
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        int nQuest = ids[i];
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            continue;
        int nRepeat = FUN_14074b070(spData.get());
        if (nRepeat == 0)
        {
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
            if (!spQuest.IsNull() && FUN_140764020()->vfunc_1(nQuest, 0) == 0)
                continue;
            if (FUN_140764020()->FUN_140745590(nQuest) != 0)
                continue;
            quests.push_back(spData);
        }
        else if (nRepeat == 2)
        {
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
            if (!spQuest.IsNull() && FUN_140764020()->vfunc_1(nQuest, 0) == 0)
                continue;
            if (FUN_140764020()->FUN_1416d0780(nQuest) == 0)
                continue;
            quests.push_back(spData);
        }
        else if (nRepeat != 3 || FUN_140bf9580(nQuest) != 0)
            quests.push_back(spData);
    }
    std::sort(quests.begin(), quests.end(), FUN_140bfa2d0);
    MS2Ptr<Unk_AqList> spList = FUN_140bfa760("m_list");
    if (spList.get() == 0)
        return;
    spList->FUN_1422dd1d0();
    spList->Invoke("resetRenderer");
    CStringW strRequire = FUN_140bf9bd0();
    if (strRequire.GetLength() != 0)
    {
        ASObj row(2);
        row.FUN_1409c0e60("group", L"");
        row.FUN_1409c0e60("desc", L"");
        row.FUN_1409c0e60("exp", L"");
        row.FUN_1407cb9c0("enabled", 0);
        row.FUN_1409c0e60("buttonStr", L"");
        row.FUN_1407cbb20("complete", strRequire);
        spList->FUN_1422dd230(row);
        spList->vfunc_24(true);
        return;
    }
    CStringW strLimit = FUN_140bf9e10();
    for (size_t i = 0; i < quests.size(); i++)
    {
        MS2Ptr<CQuestData> spData = quests[i];
        if (spData.get() != 0)
            continue;
        int nQuest = FUN_14074b030(spData.get());
        CStringW strReward;
        int nFame = FUN_140761ea0(nQuest, 1);
        __int64 nExp = FUN_140761ba0(nQuest, 1);
        if (nFame != 0)
            strReward += FUN_1405c2690(L"s_alliance_quest_reward_fame_point", FUN_140763e10(nFame));
        if (nExp != 0)
        {
            if (strReward.GetLength() != 0)
                strReward += L"\n";
            strReward += FUN_1405c2690(L"s_alliance_quest_reward_exp", FUN_1409404f0(nExp));
        }
        CString strGrade = FUN_14021aa20(spData->m_50);
        if (FUN_14074b1c0(spData.get(), 0) != 0)
            strGrade = "Special";
        ASObj row(2);
        row.FUN_1409c0d20("id", nQuest);
        row.FUN_1407cbb20("group", FUN_1416e4df0(nQuest));
        row.FUN_1407cbb20("desc", FUN_1416e5500(nQuest));
        row.FUN_1407cba60("grade", strGrade);
        row.FUN_1407cbb20("exp", strReward);
        row.FUN_1407cbbe0("expIcon", FUN_140761ba0(nQuest, 1) != 0);
        if (spData->m_complete.m_choiceRewards.GetCount() != 0)
        {
            const CQuestData::QuestRewardItem& rItem = spData->m_complete.m_choiceRewards[0];
            row.FUN_1407cba60("bind1", m_180.FUN_140d43310(rItem.m_itemId, rItem.m_count, rItem.m_job));
        }
        if (spData->m_complete.m_choiceRewards.GetCount() > 1)
        {
            const CQuestData::QuestRewardItem& rItem = spData->m_complete.m_choiceRewards[1];
            row.FUN_1407cba60("bind2", m_180.FUN_140d43310(rItem.m_itemId, rItem.m_count, rItem.m_job));
        }
        if (FUN_140bf8800(nQuest) != 0)
        {
            int nCost = FUN_1401c0db0()->FUN_14067a0b0(spData->m_4c, spData->m_50);
            if (nCost > 0)
                row.FUN_1407cbb20("ticketStr", FUN_14062b4f0(L"s_alliance_quest_completion_ticket_count", &nCost));
        }
        int bCanStart = FUN_140764020()->vfunc_1(nQuest, 0);
        if (strLimit.GetLength() == 0)
        {
            if (bCanStart == 0)
            {
                if (FUN_140764020()->FUN_140745590(nQuest) == 0)
                {
                    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
                    if (spQuest == 0)
                    {
                        unsigned nPrev = FUN_140bf9580(nQuest);
                        if (FUN_140764020()->FUN_140745590(nPrev) == 0)
                        {
                            if (FUN_140764020()->FUN_140745630(nPrev) != 0)
                                row.FUN_1407cbb20("complete", GetStringCommonByKey(L"s_alliance_quest_rumble_warn"));
                        }
                        else
                            row.FUN_1407cbb20("complete", FUN_140bf6c90(nQuest));
                    }
                }
                else
                    row.FUN_1407cbb20("complete", FUN_140bf6c90(nQuest));
            }
        }
        else
            row.FUN_1407cbb20("complete", strLimit);
        CStringW strButton;
        int bEnabled;
        if (bCanStart == 0)
        {
            strButton = GetStringCommonByKey(L"s_alliance_quest_complete");
            bEnabled = FUN_140764020()->FUN_1407456d0(nQuest);
        }
        else
        {
            strButton = GetStringCommonByKey(L"s_alliance_quest_accept");
            bEnabled = 1;
        }
        row.FUN_1407cb9c0("enabled", bEnabled);
        row.FUN_1407cbb20("buttonStr", strButton);
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(true);
}

// @0x140bf8800
int UIAllianceQuestDialog::FUN_140bf8800(unsigned nQuest)
{
    if (!FUN_14036d570(FUN_140166410(), 0xef))
        return 0;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (!spData)
        return 0;
    if (FUN_14074b1c0(spData.get(), 2) == 0)
        return 0;
    if (FUN_140764020()->FUN_140745630(nQuest) == 0)
        return 0;
    return 1;
}

// @0x140bf8900
int UIAllianceQuestDialog::FUN_140bf8900()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d2b0(static_cast<Unk_FameAlliance>(FUN_140bf6af0(DAT_143abdc30)), ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nQuest = ids[i];
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            continue;
        if (FUN_14074b070(spData.get()) != 2 && FUN_14074b070(spData.get()) != 3)
            continue;
        if (spData->m_require.m_unrequireGroup.GetCount() != 0)
            continue;
        if (FUN_140764020()->vfunc_1(nQuest, 0) == 0)
            continue;
        return 1;
    }
    return 0;
}

// @0x140bf8ab0
int UIAllianceQuestDialog::FUN_140bf8ab0()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d2b0(static_cast<Unk_FameAlliance>(FUN_140bf6af0(DAT_143abdc30)), ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nQuest = ids[i];
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            continue;
        if (FUN_14074b070(spData.get()) != 2 && FUN_14074b070(spData.get()) != 3)
            continue;
        if (FUN_140764020()->FUN_140746ba0(nQuest, 0, 0) != 0)
            continue;
        return 1;
    }
    return 0;
}

// @0x140bf8c30
void UIAllianceQuestDialog::FUN_140bf8c30(unsigned nQuest)
{
    if (FUN_140bf8800(nQuest) == 0)
        return;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (!spData)
        return;
    int nCost = FUN_1401c0db0()->FUN_14067a0b0(spData->m_4c, spData->m_50);
    if (nCost == 0)
        return;
    int nCount = FUN_140a5f780(&DAT_143ab2a90, 0xd1, 0);
    unsigned nItem = FUN_1405575b0(FUN_140281980(), 0xd1);
    if (nCount < nCost)
    {
        unsigned nLackItem = FUN_1405575b0(FUN_140281980(), 0xd1);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nLackItem);
        CStringW strText = FUN_1405c2690(L"s_alliance_quest_completion_ticket_lack", strName);
        FUN_1403ed2b0()->FUN_141add520(CStringW(strName), CStringW(strText));
    }
    else
    {
        CStringW strText = FUN_14028dfa0(L"s_alliance_quest_completion_ticket_use", FUN_1401a9d70()->FUN_141811980(1, nItem), nCost);
        MS2Ptr<CMsgBoxData> spBox = FUN_140bfab20(CStringW(strText), 1, AqAnswerDelegate(this, &UIAllianceQuestDialog::SendQuestMode33), nQuest);
        FUN_140534d60(reinterpret_cast<MS2Ptr<Unk_AqMsgBox>*>(&spBox));
    }
}

// @0x140bf9010
bool UIAllianceQuestDialog::SendQuestMode34(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Quest), 0);
        packet.vfunc_o10_1(0x22);
        FUN_140710590(packet);
        FUN_140bf91b0();
    }
    return true;
}

// @0x140bf9090
bool UIAllianceQuestDialog::SendQuestMode35(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Quest), 0);
        packet.vfunc_o10_1(0x23);
        FUN_140710590(packet);
        FUN_140bf9360();
    }
    return true;
}

// @0x140bf9110
bool UIAllianceQuestDialog::SendQuestMode33(int nResult, const CMsgBoxData& rBox)
{
    if (nResult == 0)
    {
        unsigned nQuest = rBox.FUN_141a02e90(0, 0);
        COutPacket packet(static_cast<int>(SendOp::Quest), 0);
        packet.vfunc_o10_1(0x21);
        packet.vfunc_o10_3(nQuest);
        FUN_140710590(packet);
    }
    return true;
}

// @0x140bf91b0
void UIAllianceQuestDialog::FUN_140bf91b0()
{
    m_1c0.RemoveAll();
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d2b0(static_cast<Unk_FameAlliance>(FUN_140bf6af0(DAT_143abdc30)), ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nQuest = ids[i];
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            continue;
        if (FUN_14074b070(spData.get()) != 2 && FUN_14074b070(spData.get()) != 3)
            continue;
        if (spData->m_require.m_unrequireGroup.GetCount() != 0)
            continue;
        if (FUN_140764020()->vfunc_1(nQuest, 0) == 0)
            continue;
        m_1c0.Add(nQuest);
    }
}

// @0x140bf9360
void UIAllianceQuestDialog::FUN_140bf9360()
{
    m_1e0.RemoveAll();
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d2b0(static_cast<Unk_FameAlliance>(FUN_140bf6af0(DAT_143abdc30)), ids);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        unsigned nQuest = ids[i];
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            continue;
        if (FUN_14074b070(spData.get()) != 2 && FUN_14074b070(spData.get()) != 3)
            continue;
        if (FUN_140764020()->FUN_140746ba0(nQuest, 0, 0) != 0)
            continue;
        m_1e0.Add(nQuest);
    }
}

// @0x140bf94e0
int UIAllianceQuestDialog::FUN_140bf94e0(int nQuest)
{
    return FUN_140408410(&m_1c0, reinterpret_cast<unsigned*>(&nQuest)) != -1;
}

// @0x140bf9530
int UIAllianceQuestDialog::FUN_140bf9530(int nQuest)
{
    return FUN_140408410(&m_1e0, reinterpret_cast<unsigned*>(&nQuest)) != -1;
}

// @0x140bf9580
unsigned UIAllianceQuestDialog::FUN_140bf9580(unsigned nQuest)
{
    if (FUN_140764020()->FUN_140745630(nQuest) != 0)
        return nQuest;
    if (FUN_140764020()->FUN_140745590(nQuest) != 0)
    {
        MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
        if (!spData)
            return 0;
        if (spData->m_require.m_groupId == 0)
        {
            if (FUN_140764020()->FUN_1416d07c0(nQuest) != 0)
                return nQuest;
        }
        else
        {
            int nSelector = FUN_140bfc5b0(FUN_140764020());
            int nSeed = FUN_140764020()->FUN_140747000(nQuest);
            ATL::CAtlArray<unsigned> picked;
            FUN_1407476c0()->FUN_14074e6c0(spData->m_require.m_groupId, nSelector, nSeed, picked);
            if (FUN_140408410(&picked, &nQuest) != -1)
                return nQuest;
        }
    }
    if (FUN_140764020()->vfunc_1(nQuest, 0) != 0)
        return nQuest;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (!spData)
        return 0;
    if (FUN_14074b070(spData.get()) == 3 && spData->m_require.m_unrequireGroup.GetCount() != 0)
    {
        if (FUN_140bf9a40(nQuest) == 0)
            return 0;
        for (size_t i = 0; i < spData->m_require.m_unrequireGroup.GetCount(); i++)
        {
            int nSelector = FUN_140bfc5b0(FUN_140764020());
            int nSeed = FUN_140764020()->FUN_140747000(nQuest);
            ATL::CAtlArray<unsigned> picked;
            FUN_1407476c0()->FUN_14074e6c0(spData->m_require.m_groupId, nSelector, nSeed, picked);
            for (size_t j = 0; j < picked.GetCount(); j++)
            {
                Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(picked[j]);
                if (!spQuest.IsNull())
                    return spQuest->FUN_140bfc580();
            }
        }
    }
    return 0;
}

// @0x140bf9a40
int UIAllianceQuestDialog::FUN_140bf9a40(unsigned nQuest)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (!spData)
        return 0;
    if (spData->m_require.m_alliance != 0 && spData->m_require.m_fameGrade != 0)
    {
        int nGrade = FUN_140931250(spData->m_require.m_alliance);
        if (nGrade < spData->m_require.m_fameGrade)
            return 0;
    }
    ATL::CAtlArray<unsigned>& rQuests = spData->m_require.m_quest;
    for (size_t i = 0; i < rQuests.GetCount(); i++)
    {
        if (rQuests[i] != 0 && FUN_140764020()->FUN_140745590(rQuests[i]) == 0)
            return 0;
    }
    return 1;
}

// @0x140bf9bd0
CStringW UIAllianceQuestDialog::FUN_140bf9bd0()
{
    int nAlliance = FUN_140bf6af0(DAT_143abdc30);
    MS2Ptr<CFameSeasonDef> spSeason = FUN_140764010()->GetSeason(static_cast<Unk_FameAlliance>(nAlliance));
    if (spSeason.get() == 0)
        return L"";
    void* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return L"";
    unsigned nLevel = Unk_AqActorLevel(pActor);
    if ((int)spSeason->m_nRequireLv <= (int)nLevel && FUN_140764020()->FUN_140745590(spSeason->m_nRequireQuest) != 0)
        return L"";
    unsigned short nRequireLv = spSeason->m_nRequireLv;
    return FUN_14052b9d0(L"s_alliance_quest_require_condition", nRequireLv, FUN_1416e4df0(spSeason->m_nRequireQuest));
}

// @0x140bf9e10
CStringW UIAllianceQuestDialog::FUN_140bf9e10()
{
    int nAlliance = FUN_140bf6af0(DAT_143abdc30);
    MS2Ptr<CFameLimitData> spLimit = FUN_140764010()->GetLimit(static_cast<Unk_FameAlliance>(nAlliance));
    if (spLimit.get() == 0)
        return L"";
    CStringW strLimits;
    for (POSITION pos = spLimit->m_mapGrade.GetStartPosition(); pos != 0; spLimit->m_mapGrade.GetNext(pos))
    {
        Unk_FameAlliance nOther = spLimit->m_mapGrade.GetKeyAt(pos);
        int nGrade = spLimit->m_mapGrade.GetValueAt(pos);
        if (FUN_140931250(nOther) < nGrade)
        {
            CStringW strOne = FUN_1408f71a0(L"s_alliance_quest_limit_alliance", FUN_140762de0(nOther), FUN_140762f50(nOther, nGrade));
            if (strLimits.GetLength() != 0)
                strLimits += FUN_140298ea0(L"s_alliance_quest_limit_alliance_delimeter");
            strLimits += strOne;
        }
    }
    CStringW strResult;
    if (strLimits.GetLength() != 0)
        strResult = FUN_1405c2690(L"s_alliance_quest_limit_alliance_condition", strLimits);
    return strResult;
}

// ---- movie child creation (the same shapes as unit_140e3efd0.cpp) ----

// @0x140bfa5f0
template<class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x140bfa6a0
template<class T> MS2Ptr<T> AScript::FUN_140bfa6a0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}

// @0x140bfa760
MS2Ptr<Unk_AqList> UIAllianceQuestDialog::FUN_140bfa760(const CString& strName)
{
    if (FUN_140ba28d0(&m_30, 0))
        return MS2Ptr<Unk_AqList>(0);
    return FUN_1409ee290(&m_30)->FUN_140bfa6a0<Unk_AqList>(strName);
}

// @0x140bfc580 the id of the quest
int CQuest::FUN_140bfc580()
{
    return FUN_14074b030(m_data.operator->());
}

// ---- UIQuestEventListener default slots (all no-ops) ----

// @0x140bfc6e0
void UIQuestEventListener::vfunc_o178_8(void*) {}
// @0x140bfc6f0
void UIQuestEventListener::vfunc_o178_10(void*) {}
// @0x140bfc700
void UIQuestEventListener::vfunc_o178_9(void*) {}
// @0x140bfc710
void UIQuestEventListener::vfunc_o178_11(void*) {}
// @0x140bfc720
void UIQuestEventListener::vfunc_o178_1(void*) {}
// @0x140bfc730
void UIQuestEventListener::vfunc_o178_5(void*) {}
// @0x140bfc740
void UIQuestEventListener::vfunc_o178_7(int, int) {}
// @0x140bfc750
void UIQuestEventListener::vfunc_o178_3(void*) {}
// @0x140bfc760
void UIQuestEventListener::vfunc_o178_6(void*) {}
// @0x140bfc770
void UIQuestEventListener::vfunc_o178_4(void*) {}
// @0x140bfc780
void UIQuestEventListener::vfunc_o178_12(void*) {}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1f30-0x142ca2070 .text$yd
