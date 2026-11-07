// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uicoupledanceeventdialog.h.
// MS2-UNIT: client\ms2\uicoupledanceeventdialog.cpp
// MS2-RANGE: 0x140bfcb00-0x140bfe4b0 .text$mn
// MS2-RANGE: 0x1400cb590-0x1400cb830 .text$di
// MS2-RANGE: 0x142ca2070-0x142ca2170 .text$yd
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicoupledanceeventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <vector>

#include "uicoupledanceeventdialog.h"

// ---- the unit's header statics: this one comes first (an unidentified header included before the common one) ----
static CStringW s_strBannerClose(L"bannerClose");

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/uimessagebox.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/actionkeyobject.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/worldservice.h"

static UICommon::CMyPCKeyInputController s_keyInputController;     // header static (origin unknown)
// A second string table from another unidentified header (enum names of a sort/chart order).
static CString s_strChartOrderNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----



void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);               // Value = b

CString FUN_1407186a0(const CStringW& str);      // narrow copy of a wide string
__int64 GetServerTime();                         // the current time source

// @0x140bfe2c0
template <> inline CString GameEventVariable::GetValue<CString>(const CString& strDefault)
{
    CMsTime now(GetServerTime());
    if (m_time <= now)
        return strDefault;
    return FUN_1407186a0(m_value);
}

// Local player (0x1403ed2d0 singleton -> 0x141bd0cc0): a large virtual class; only a few slots are used here.
struct Unk_Pos { Unk_Pos(); float m_0; float m_4; float m_8; };
class Unk_PCBaseComp_ac8 : public CPtred { };
class Unk_Mode : public Unk_ActionKeyManager { };
class PCBase   // C3: member view for 0x14166c930
{
public:
    int GetCurStateId();                                    // 0x14166c930 current state id
};
class Unk_141bd0cc0
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_Pos vfunc_18();                                     // 18: position
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59(int a1, int a2, int a3, int a4);
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();                      // 87
};
class Unk_1403ed2d0 { public: Unk_141bd0cc0* FUN_141bd0cc0(); };
bool FUN_140b7f400(class MyPC*);
struct Unk_MiActionState* Unk_PlayerActionState(struct Unk_MiPlayer*);
bool FUN_140b884e0(Vector3&);   // C3: was FUN_140b884e0

// Message boxes (CMsgBoxData, 0x2a0 bytes).
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strMessage, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140d73aa0(CStringW strMessage, int nType, void* pListener, CStringW strTag);
CStringW GetStringCommonByKey(const CStringW& strKey);     // translate
CStringW FUN_140298ea0(CStringW strKey);            // translate (by value)
void FUN_1412752d0(const CStringW& str, int n);     // system notice
void FUN_14151f200();

// The game menu dialog found by UI type (0x140938b90).
UIGameMenuDialog* FUN_140938b90(int);   // C3: was FUN_140938b90

template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140178270 (std::vector<int>)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140bfcb00
UICoupleDanceEventDialog::UICoupleDanceEventDialog()
    : m_178(false), m_180(GetTypeName()), m_1c0(0)
{
    FUN_141924170(1);
}

// @0x140bfcbb0
UICoupleDanceEventDialog::~UICoupleDanceEventDialog()
{
}

// @0x140bfcc00
CString UICoupleDanceEventDialog::GetTypeName()
{
    return "CoupleDanceEventDialog";
}
MS2_REPLACE_METHOD(0x140BFCC00, UICoupleDanceEventDialog, GetTypeName, 61, 0x3514F86F);

// @0x140bfcc50
void UICoupleDanceEventDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    FUN_140bfde00();
}
MS2_REPLACE_METHOD(0x140BFCC50, UICoupleDanceEventDialog, vfunc_72, 34, 0x3E669171);

// @0x140bfcc80
void UICoupleDanceEventDialog::vfunc_67()
{
    Unk_141bd0cc0* pPlayer = ((Unk_141bd0cc0*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer) {
        if (reinterpret_cast<PCBase*>(pPlayer)->GetCurStateId() == 0x3b)
            pPlayer->vfunc_59(1, 0, 0, 0);
    }
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140BFCC80, UICoupleDanceEventDialog, vfunc_67, 103, 0xD95EB8A6);

// @0x140bfccf0
void UICoupleDanceEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_178 = false;
    FUN_140bfd5e0();
}
MS2_REPLACE_METHOD(0x140BFCCF0, UICoupleDanceEventDialog, OnLoadComplete, 46, 0x80D1EE1D);

// @0x140bfcd30
int UICoupleDanceEventDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    MS2Ptr<CoupleDanceContext> pEvent = reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Get();
    if (pEvent == NULL)
        return 1;
    Unk_141bd0cc0* pPlayer = ((Unk_141bd0cc0*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPlayer) {
        MS2_ASSERT_AT(232, 0);
        return 0;
    }
    if (_stricmp("onOpenBanner", szMethod) == 0) {
        if (!FUN_140b7f400(reinterpret_cast<MyPC*>(pPlayer))) {
            FUN_1412752d0(L"s_microgame_couple_dance_open_banner_failed_wrong_state", 1);
            return 1;
        }
        if (reinterpret_cast<Unk_Mode*>(Unk_PlayerActionState(reinterpret_cast<Unk_MiPlayer*>(pPlayer)))->GetCur() != 0x1e) {
            FUN_1412752d0(L"s_microgame_couple_dance_open_banner_failed_action_key", 1);
            return 1;
        }
        Unk_Pos pos = pPlayer->vfunc_18();
        if (!FUN_140b884e0(*(Vector3*)&static_cast<struct Unk_Pos&>(pos))) {
            FUN_1412752d0(L"s_microgame_couple_dance_request_failed_wrong_position", 1);
            return 1;
        }
        COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
        packet.Encode2(0xd);
        packet.Encode4(pEvent->m_eventId);
        FUN_140710590(packet);
        return 1;
    }
    if (_stricmp("onCloseBanner", szMethod) == 0) {
        MS2Ptr<Unk_PCBaseComp_ac8> pParty = pPlayer->vfunc_87();
        if (pParty == NULL) {
            MS2_ASSERT_AT(270, 0);
            return 0;
        }
        if (reinterpret_cast<UIHudEntity::Entity*>(pParty.operator->())->FUN_140f48d40() == 0)
            return 0;
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(FUN_140298ea0(L"s_microgame_couple_dance_close"), 1);
        box->SetExtra(s_strBannerClose);
        box->FUN_141a024a0(0);
        FUN_140d73c60(box);
        return 1;
    }
    if (_stricmp("onReward", szMethod) == 0) {
        ASData data;
        if (!data.SetArgsIfAny(pArgs, nArgs)) {
            MS2_ASSERT_AT(293, 0);
            return 0;
        }
        int nStep = data.PopUInt();
        FUN_140bfdf60(nStep);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140BFCD30, UICoupleDanceEventDialog, vfunc_28, 1478, 0x6FA63D9B);

// @0x140bfd300
int UICoupleDanceEventDialog::vfunc_71()
{
    Unk_141bd0cc0* pPlayer = ((Unk_141bd0cc0*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPlayer) {
        MS2_ASSERT_AT(310, 0);
        return 0;
    }
    MS2Ptr<Unk_PCBaseComp_ac8> pParty = pPlayer->vfunc_87();
    if (pParty == NULL) {
        MS2_ASSERT_AT(317, 0);
        return 0;
    }
    if (reinterpret_cast<UIHudEntity::Entity*>(pParty.operator->())->FUN_140f48d40() == 1) {
        FUN_140d73aa0(GetStringCommonByKey(L"s_microgame_couple_dance_event_ask_close"), 1, static_cast<IMessageListener*>(this), CStringW(L"askClose"));
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140BFD300, UICoupleDanceEventDialog, vfunc_71, 451, 0x3484CE5F);

// @0x140bfd4d0
int UICoupleDanceEventDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (!pMsg->FUN_1422e4520() && dynamic_cast<UIMessageBox*>(pSender)) {
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (strTag.CompareNoCase(L"askClose") == 0 && nResult == 0)
            vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x140BFD4D0, UICoupleDanceEventDialog, IMessageListener, OnMessage, 255, 0x9620BC58);

// @0x140bfd5e0
void UICoupleDanceEventDialog::FUN_140bfd5e0()
{
    MS2Ptr<CoupleDanceContext> pEvent = reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Get();
    if (pEvent == NULL)
        return;
    FUN_140bfdc00();
    if (m_30 == NULL)
        return;
    CString strStates = DAT_143ab2fc0.GetValue<CString>(0x835, pEvent->m_eventId, "");
    std::vector<int> states;
    XmlSplit(strStates, states, ",");
    ASObj root(2);
    root.FUN_1407cbbe0("isOpenBanner", m_178);
    ASArray items(2);
    for (size_t i = 0; i < pEvent->m_dailyItems.size(); i++) {
        ASObj item(2);
        item.FUN_1407cba60("binding", m_180.BindNewItem(pEvent->m_dailyItems[i].begin()->m_itemId, ((ItemAble&)*pEvent->m_dailyItems[i].begin().operator->()).vfunc_o18_1(),
                                                          pEvent->m_dailyItems[i].begin()->m_count));
        if (i >= states.size()) {
            item.FUN_1407cbbe0("received", false);
            item.FUN_1407cbbe0("completed", false);
            item.FUN_1407cbbe0("isBonus", false);
        } else {
            switch (states[i]) {
            case 1:
                item.FUN_1407cbbe0("received", false);
                item.FUN_1407cbbe0("completed", true);
                item.FUN_1407cbbe0("isBonus", false);
                break;
            case 2:
                item.FUN_1407cbbe0("received", false);
                item.FUN_1407cbbe0("completed", true);
                item.FUN_1407cbbe0("isBonus", true);
                break;
            case 3:
                item.FUN_1407cbbe0("received", true);
                item.FUN_1407cbbe0("completed", true);
                item.FUN_1407cbbe0("isBonus", false);
                break;
            case 4:
                item.FUN_1407cbbe0("received", true);
                item.FUN_1407cbbe0("completed", true);
                item.FUN_1407cbbe0("isBonus", true);
                break;
            default:
                item.FUN_1407cbbe0("received", false);
                item.FUN_1407cbbe0("completed", false);
                item.FUN_1407cbbe0("isBonus", false);
                break;
            }
        }
        items.PushValue(item.FUN_1422bb870());
    }
    root.FUN_1409adbe0("rewardInfos", items.FUN_1422bb870());
    m_30->Invoke("setData", root.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140BFD5E0, UICoupleDanceEventDialog, FUN_140bfd5e0, 1554, 0xDF39C04A);

// @0x140bfdc00
void UICoupleDanceEventDialog::FUN_140bfdc00()
{
    MS2Ptr<CoupleDanceContext> pEvent = reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Get();
    if (pEvent == NULL)
        return;
    CString strStates = DAT_143ab2fc0.GetValue<CString>(0x835, pEvent->m_eventId, "");
    std::vector<int> states;
    XmlSplit(strStates, states, ",");
    m_1c0 = 0;
    ASArray unused(2);
    for (size_t i = 0; i < pEvent->m_dailyItems.size(); i++) {
        if (i < states.size()) {
            switch (states[i]) {
            case 1:
                m_1c0++;
                break;
            case 2:
                m_1c0++;
                break;
            }
        }
    }
    UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
    if (pMenu)
        pMenu->FUN_141938ae0(0x4f71, 0);
}
MS2_REPLACE_METHOD(0x140BFDC00, UICoupleDanceEventDialog, FUN_140bfdc00, 504, 0xEF596F64);

// @0x140bfde00
void UICoupleDanceEventDialog::FUN_140bfde00()
{
    if (m_30 == NULL)
        return;
    if (!FUN_141924630())
        return;
    Unk_141bd0cc0* pPlayer = ((Unk_141bd0cc0*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    MS2Ptr<Unk_PCBaseComp_ac8> pParty = pPlayer->vfunc_87();
    if (pParty == NULL)
        return;
    bool bOpen = reinterpret_cast<UIHudEntity::Entity*>(pParty.operator->())->FUN_140f48d40() == 1 ? true : false;
    if (m_178 == bOpen)
        return;
    m_178 = bOpen;
    m_30->Invoke("refreshBannerButton", m_178);
}
MS2_REPLACE_METHOD(0x140BFDE00, UICoupleDanceEventDialog, FUN_140bfde00, 345, 0xDE3EC071);

// @0x140bfdf60
void UICoupleDanceEventDialog::FUN_140bfdf60(int nStep)
{
    MS2Ptr<CoupleDanceContext> pEvent = reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Get();
    if (pEvent == NULL)
        return;
    if (nStep < 0 || nStep >= (int)pEvent->m_dailyItems.size())
        return;
    CString strStates = DAT_143ab2fc0.GetValue<CString>(0x835, pEvent->m_eventId, "");
    std::vector<int> states;
    XmlSplit(strStates, states, ",");
    if (nStep >= (int)states.size())
        return;
    if (states[nStep] != 1 && states[nStep] != 2)
        return;
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(0x19);
    packet.Encode4(pEvent->m_eventId);
    packet.Encode4(nStep);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140BFDF60, UICoupleDanceEventDialog, FUN_140bfdf60, 536, 0x27E52ABB);

// @0x140bfe180
int UICoupleDanceEventDialog::FUN_140bfe180()
{
    return m_1c0;
}
MS2_REPLACE_METHOD(0x140BFE180, UICoupleDanceEventDialog, FUN_140bfe180, 17, 0x05FDCC0A);

// @0x140bfe1a0
void UICoupleDanceEventDialog::FUN_140bfe1a0(void*)
{
    if (FUN_141924630())
        FUN_140bfd5e0();
    else
        FUN_140bfdc00();
}
MS2_REPLACE_METHOD(0x140BFE1A0, UICoupleDanceEventDialog, FUN_140bfe1a0, 55, 0xF5619877);

// ---- inline COMDATs of this unit (exe order: 0x140bfe1e0..) ----

// @0x140bfe360
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, bool b)
{
    ASArgList args;
    args.resize(1);
    FUN_1422bcce0(&args[0], b);
    return FUN_1422bb8f0(szMethod, args);
}
