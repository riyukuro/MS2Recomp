// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic action picker dialog, UI id 0x4e7a: the
// dynamic actions (skills of main type 0xe) the local player has learned as pages of slots, a search box, favorites,
// sorting, key binds and a skill preview. Same shape as UICoupleActionDialog.
// MS2-UNIT: client\ms2\uidynamicactiondialog.cpp
// MS2-RANGE: 0x14192ac30-0x14192e8f0 .text$mn
// MS2-RANGE: 0x140112e30-0x140113000 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill1@@YAXXZ 0x140112e30 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x140112e60 ; probe
// MS2-PIN: ??__Es_strStun1@@YAXXZ 0x140112fa0 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x140112fd0 ; probe
// MS2-PIN: ??$?8PEAVUIDynamicActionDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x14192e110 ; prop
// MS2-PIN: ??$?8PEAVUIDynamicActionDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x14192e180 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x14192e360 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x14192e400 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14192e690 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14192e6f0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14192e750 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x14192e780 ; unique
// MS2-PIN: ??$Call@VUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14192e7b0 ; prop
// MS2-PIN: ??$Call@VUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x14192e7f0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14192e830 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDynamicActionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14192e890 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidynamicactiondialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidynamicactiondialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <atltime.h>
#include <cmath>
#include <set>
#include <vector>
#include "ms2/placeholder/unk_1402a9d70.h"

// header statics
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};
// "m_inputSearch": the search text input.
class Unk_DaInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                               // the text
    void FUN_1422e0920(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // text changed callback
};
int FUN_1422c76c0(Unk_DaInput* p);                          // the input has the focus
void FUN_1422c7630(ASDisplayObject* p, int nFocus);         // set / clear the focus
// "m_list": the page grid.
class Unk_DaList : public ASDisplayObject
{
public:
    int FUN_1422dccd0();                                    // the selected index
    void FUN_1422dcca0(int n);                              // select an index
    MS2Ptr<ASDataProvider> FUN_1422dcd80();                 // the data provider
};
int FUN_140ad02c0(int nMin, int n);                         // max
int FUN_140ad02f0(int nMax, int n);                         // min

// The search keywords of an action id: the strings are at +0x38.
class Unk_EmotionKeywords : public CPtred
{
public:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    ATL::CAtlArray<CStringW> m_38;                          // +0x38 keywords
};
MS2Ptr<Unk_EmotionKeywords> FUN_140347050(int nAction);

// The skill system (action list, mode, reset) and the player.
void FUN_1417691a0(CSkillSystem* p, ATL::CAtlArray<MS2Ptr<Unk_Emotion> >& list);
int FUN_141765cf0(CSkillSystem* p, int nMode);
void FUN_141769280(CSkillSystem* p);
void FUN_14151f200();
NotifySystem* FUN_140939a10();                              // the notify system

// Input state, the movie manager, the key binds.
class Unk_DaInputState { public: bool FUN_14116d9c0(int a, int b, int c); };
Unk_DaInputState* FUN_14025e7c0();
class Unk_DaUiMgr { public: int FUN_1422d4e20(CString strKey); };
Unk_DaUiMgr* FUN_140b632f0();
class Unk_DaKeyBinds
{
public:
    int FUN_14142e340(int n);                               // the key being pressed
    int FUN_14142cc40(int nKey);                            // the key may be bound
    __int64 FUN_14142d190(int nKey);                        // the action bound to a key (0 = none)
    int FUN_14142cf10(unsigned __int64 nAction);
    int FUN_141430470(unsigned __int64 nAction);
    int FUN_14142c940(unsigned __int64 nAction, int n);     // the key of an action
    CStringW FUN_14142d220(int nKey);                       // the text of a key
    int FUN_14142b250(int nKey, int a, unsigned __int64 nAction, int b, int c);
    void FUN_14142a8b0(unsigned __int64 nAction);
};
Unk_DaKeyBinds* FUN_1409331f0();

int FUN_1409e1b80(ASTooltip* p, int nId, int n);            // the learned skill tooltip
CStringW FUN_141811980(CStringTable* p, int nTable, int nId);
CStringTable* GetStringTable();
char FUN_1403b3c40(const CStringW& str, const wchar_t* szText);
void FUN_140988d60(CStringW& strSrc, std::vector<CStringW>& arrOut, const wchar_t* pszSep);
SkillDataTable* FUN_1401958b0();                            // the skill table
void FUN_140710590(COutPacket& packet);                     // send
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& strArg0, const CStringW& strArg1);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
ATL::CTime FUN_1406c47a0(__int64 nTime);                    // CTime from a time_t
__int64 FUN_140869440();                                    // the server time
CStringW FUN_1409e90c0(int nStringId, const int& nYear, const int& nMonth, const int& nDay, const int& nHour,
                       const int& nMinute);
int FUN_1416595d0(PCBase* pActor);
void* FUN_1403ed2b0();                                      // the UI service
class Unk_DaUIRef {
public:
    ~Unk_DaUIRef();
    UIObject* FUN_1403e8a70() const;
private: void* unknown; UIObject* object;
};
MS2_CHECK_SIZE(Unk_DaUIRef, 0x10);
Unk_DaUIRef FUN_141adcea0(void*, int);
UIObject* FUN_1403ed9e0(Unk_DaUIRef&);
void FUN_141adc530(void*, int);

// Sort orders of the action pages (the comparators live in the skill system unit).
struct Unk_EmotionLess { bool operator()(const MS2Ptr<Unk_Emotion>& a, const MS2Ptr<Unk_Emotion>& b) const; };   // 0x141764410
struct Unk_EmotionGreater { bool operator()(const MS2Ptr<Unk_Emotion>& a, const MS2Ptr<Unk_Emotion>& b) const; };   // 0x141764570

// @0x14192e660
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
bool Unk_DaSlot::IsSet() const
{
    return m_4 != 0;
}

// @0x14192ac30
UIDynamicActionDialog::UIDynamicActionDialog()
{
    m_5c = 1;
    m_1b0 = false;
    m_1b1 = false;
    FUN_141924170(1);
}

// @0x14192ad20
CString UIDynamicActionDialog::GetTypeName()
{
    return CString("DynamicAction");
}
MS2_REPLACE_METHOD(0x14192AD20, UIDynamicActionDialog, GetTypeName, 61, 0);

// @0x14192ad70
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
int UIDynamicActionDialog::vfunc_65()
{
    int r = UIDialog::vfunc_65();
    if (r != 0) {
        m_178.Clear();
        m_1b8.Empty();
        m_1b0 = false;
        m_1b1 = false;
    }
    return r != 0;
}
MS2_REPLACE_METHOD(0x14192AD70, UIDynamicActionDialog, vfunc_65, 100, 0);

// @0x14192ade0
void UIDynamicActionDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    MyPC* pPlayer = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0)
        FUN_141769280(pPlayer->FUN_141523bc0());
    m_190.clear();
}
MS2_REPLACE_METHOD(0x14192ADE0, UIDynamicActionDialog, vfunc_67, 87, 0);

// @0x14192ae40
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
int UIDynamicActionDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0) {
        if (pSender == dynamic_cast<UIMessageBox*>(pSender)) {
            int nResult = pMsg->FUN_1422b8a10();
            FUN_14151f200();
            if (nResult == 0) {
                FUN_14192df00(m_178.m_8, m_178.m_4);
            } else {
                FUN_14192df00(m_184.m_8, m_184.m_4);
                MS2Ptr<Unk_DaList> spList = FUN_140ba4b70("m_list");
                if (spList.get() != 0)
                    spList->FUN_1422dcca0(-1);
            }
            m_178.Clear();
        }
    }
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x14192AE40, UIDynamicActionDialog, IMessageListener, OnMessage, 422, 0);

// @0x14192aff0
void UIDynamicActionDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_14192c6b0();
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &UIDynamicActionDialog::FUN_14192c630));
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyClearAchieve"), Delegate<void(NotifyObject*)>(this, &UIDynamicActionDialog::FUN_14192c660));
}
MS2_REPLACE_METHOD(0x14192AFF0, UIDynamicActionDialog, OnLoadInit, 452, 0);

// @0x14192b1c0
void UIDynamicActionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0) {
        Unk_DaInput* pInput = m_30->FUN_140bbe940<Unk_DaInput>("m_inputSearch", m_1a0);
        if (pInput != 0)
            m_1a0->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDynamicActionDialog::FUN_14192c690));
    }
}
MS2_REPLACE_METHOD(0x14192B1C0, UIDynamicActionDialog, OnLoadComplete, 369, 0);

// @0x14192b340
void UIDynamicActionDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_1a0.AssignRaw(0);
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyLearnEmotion"), Delegate<void(NotifyObject*)>(this, &UIDynamicActionDialog::FUN_14192c630));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyClearAchieve"), Delegate<void(NotifyObject*)>(this, &UIDynamicActionDialog::FUN_14192c660));
}
MS2_REPLACE_METHOD(0x14192B340, UIDynamicActionDialog, vfunc_26, 463, 0);

// @0x14192b520
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
int UIDynamicActionDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) != 0) {
        ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
        if (pDlg != 0 && FUN_140b632f0() != 0) {
            if (FUN_140b632f0()->FUN_1422d4e20(CString(m_20)) != 0 && m_1a0.get() != 0) {
                if (FUN_1422c76c0(m_1a0.operator->()) != 0) {
                    FUN_14192d790(m_1a0->FUN_1422e0b00());
                    FUN_1422c7630(pDlg, 1);
                    FUN_1422c7630(m_1a0.operator->(), 0);
                    return 1;
                }
            }
        }
    }
    if (m_178.m_0 == 0) {
        if (m_178.IsSet()) {
            int nKey = FUN_1409331f0()->FUN_14142e340(0);
            if (nKey != 0) {
                if (FUN_1409331f0()->FUN_14142cc40(nKey) == 0) {
                    m_178.Clear();
                    FUN_140d73bc0(0x84c, 0, 0, CStringW(L""));
                } else if (FUN_14192deb0(nKey) == 0) {
                    m_178.m_0 = 1;
                    m_178.m_8 = nKey;
                    unsigned __int64 nOther = FUN_1409331f0()->FUN_14142d190(nKey);
                    CStringW strOther;
                    if (FUN_1409331f0()->FUN_14142cf10(nOther) == 0) {
                        strOther = GetStringTable()->FUN_1418125b0((unsigned)nOther);
                    } else {
                        strOther = FUN_140656190(L"{0}[{1}]", GetStringTable()->FUN_1418125b0((unsigned)nOther),
                                                 FUN_1409331f0()->FUN_14142d220(nKey));
                    }
                    if (FUN_1409331f0()->FUN_141430470(nOther) == 0) {
                        FUN_140d73aa0(FUN_14052bd00(0x84f, strOther), 1, static_cast<IMessageListener*>(this), CStringW(L""));
                    } else if (FUN_14192df00(nKey, (unsigned)m_178.m_4) != 0) {
                        m_178.Clear();
                    }
                } else if (FUN_14192df00(nKey, (unsigned)m_178.m_4) != 0) {
                    m_178.Clear();
                }
                return 1;
            }
        }
        return UIDialog::vfunc_13();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14192B520, UIDynamicActionDialog, vfunc_13, 1539, 0);

// @0x14192bb30
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    int nAction = pArgs->FUN_1422b8b10();
    MS2Ptr<Unk_EmotionKeywords> spData = FUN_140347050(nAction);
    if (spData.IsNull())
        return;
    std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_190.find(nAction);
    if (it == m_190.end())
        return;
    __int64 nPeriod = it->second->m_28;
    ASTooltip tooltip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x10, 2);
    if (FUN_1409e1b80(&tooltip, nAction, 0) != 0) {
        ASObj stat(2);
        stat.FUN_1407cb9c0("type", 1);
        stat.FUN_1409c0dc0("level", "");
        stat.FUN_1407cbb20("cooltime", FUN_14192d820(nAction));
        tooltip.FUN_1409adbe0("statDescription", stat.FUN_1422bb870());
        tooltip.FUN_1409c0dc0("enablePuton", "");
        if (0 < nPeriod) {
            ATL::CTime time = FUN_1406c47a0(nPeriod);
            int nStringId = 0xb8;
            if (nPeriod < FUN_140869440())
                nStringId = 0xb9;
            int nMinute = time.GetMinute();
            int nHour = time.GetHour();
            int nDay = time.GetDay();
            int nMonth = time.GetMonth();
            int nYear = time.GetYear();
            tooltip.FUN_1407cbb20("skillPeriod", FUN_1409e90c0(nStringId, nYear, nMonth, nDay, nHour, nMinute));
        }
        *pRetVal = tooltip.FUN_1422bb870();
    }
}
MS2_REPLACE_METHOD(0x14192BB30, UIDynamicActionDialog, vfunc_49, 908, 0);

// @0x14192bed0
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
int UIDynamicActionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onSelectEmotion") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nAction = data.FUN_1422b8b10();
            if (nAction == 0)
                return 0;
            FUN_14192c9b0(nAction);
        }
    } else if (_stricmp(szMethod, "onFocusIn") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nAction = data.FUN_1422b8b10();
            if (nAction == 0)
                return 0;
            m_178.Clear();
            m_178.m_4 = nAction;
            int nKey = FUN_1409331f0()->FUN_14142c940((unsigned)m_178.m_4, 0);
            m_184.Clear();
            m_184.m_8 = nKey;
            m_184.m_4 = nAction;
            FUN_14192df00(nKey, 0);
        }
    } else if (_stricmp(szMethod, "onFocusOut") == 0) {
        if (m_178.m_0 == 0)
            m_178.Clear();
    } else if (_stricmp(szMethod, "onShiftRClick") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nAction = data.FUN_1422b8b10();
            if (nAction == 0)
                return 0;
            FUN_14192ca10(nAction);
        }
    } else if (_stricmp(szMethod, "onFavoriteSort") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        m_1b1 = data.FUN_1422b8a90();
        FUN_14192c6b0();
    } else if (_stricmp(szMethod, "onSort") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        m_1b0 = data.FUN_1422b8a90();
        FUN_14192c6b0();
    } else if (_stricmp(szMethod, "onFavorite") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        int nAction = data.FUN_1422b8b10();
        if (nAction == 0)
            return 0;
        std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_190.find(nAction);
        if (it == m_190.end())
            return 0;
        unsigned short nLevel = it->second->m_level;
        bool bFavorite = data.FUN_1422b8a90();
        it->second->m_favorite = bFavorite;
        COutPacket packet(0x13, 0);
        packet.vfunc_o10_1(4);
        packet.vfunc_o10_3(nAction);
        packet.vfunc_o10_3(nLevel);
        packet.vfunc_o10_0(bFavorite);
        FUN_140710590(packet);
        if (m_1b1)
            FUN_14192c6b0();
    } else if (_stricmp(szMethod, "onSearch") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        FUN_14192d790(CStringW(data.FUN_1422b8f40()));
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14192BED0, UIDynamicActionDialog, vfunc_28, 1867, 0);

// @0x14192c630
void UIDynamicActionDialog::FUN_14192c630(NotifyObject* pNotify)
{
    FUN_14192c6b0();
}
MS2_REPLACE_METHOD(0x14192C630, UIDynamicActionDialog, FUN_14192c630, 29, 0);

// @0x14192c660
void UIDynamicActionDialog::FUN_14192c660(NotifyObject* pNotify)
{
    FUN_14192c6b0();
}
MS2_REPLACE_METHOD(0x14192C660, UIDynamicActionDialog, FUN_14192c660, 29, 0);

// @0x14192c690
void UIDynamicActionDialog::FUN_14192c690(const Scaleform::GFx::FunctionHandler::Params& params)
{
}
MS2_REPLACE_METHOD(0x14192C690, UIDynamicActionDialog, FUN_14192c690, 11, 0);

// @0x14192c6b0
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192c6b0()
{
    m_190.clear();
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        MyPC* pPlayer = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0) {
            ATL::CAtlArray<MS2Ptr<Unk_Emotion> > list;
            FUN_1417691a0(pPlayer->FUN_141523bc0(), list);
            int nMode = FUN_141765cf0(pPlayer->FUN_141523bc0(), 0);
            FUN_141765cf0(pPlayer->FUN_141523bc0(), nMode);
            std::map<unsigned int, Unk_Emotion> unused;
            for (size_t i = 0; i < list.GetCount(); i++) {
                unsigned int nId = list[i]->m_id;
                SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
                if (pSkill != 0 && pSkill->GetMainType() == 0xe)
                    m_190.insert(std::make_pair(nId, list[i]));
            }
            if (m_1b0 == false)
                FUN_14192ca70();
            else
                FUN_14192d100();
        }
    }
}
MS2_REPLACE_METHOD(0x14192C6B0, UIDynamicActionDialog, FUN_14192c6b0, 621, 0);

// @0x14192c930
void UIDynamicActionDialog::FUN_14192c930(int nAction)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0)
        pDlg->Invoke("setFocusByEmotion", (unsigned int)nAction);
}
MS2_REPLACE_METHOD(0x14192C930, UIDynamicActionDialog, FUN_14192c930, 117, 0);

// @0x14192c9b0
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192c9b0(int nAction)
{
    MyPC* pPlayer = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0 && FUN_1416595d0(pPlayer) == 0)
        pPlayer->FUN_141525480(nAction, 0);
}
MS2_REPLACE_METHOD(0x14192C9B0, UIDynamicActionDialog, FUN_14192c9b0, 79, 0);

// The skill preview dialog (UI id 0x4ec3), when it exists.
// @0x14192e1f0
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
UISkillPreviewDialog* FUN_14192e1f0(int nDialog)
{
    if (FUN_1403ed2b0() != 0) {
        Unk_DaUIRef ref = FUN_141adcea0(FUN_1403ed2b0(), nDialog);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<UISkillPreviewDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x14192ca10
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192ca10(int nAction)
{
    UISkillPreviewDialog* pPreview = FUN_14192e1f0(0x4ec3);
    if (pPreview != 0) {
        FUN_141adc530(FUN_1403ed2b0(), 0x4ec3);
        pPreview->FUN_140e93e70(nAction, 0);
    }
}
MS2_REPLACE_METHOD(0x14192CA10, UIDynamicActionDialog, FUN_14192ca10, 78, 0);

// @0x14192ca70
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192ca70()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        ASArray actions(2);
        int nFocus = 0;
        std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionLess> sorted;
        for (std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_190.begin(); it != m_190.end(); ++it)
        {
            MS2Ptr<Unk_Emotion> spCopy(it->second);
            sorted.insert(spCopy);
        }
        for (std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionLess>::iterator sit = sorted.begin(); sit != sorted.end(); ++sit) {
            MS2Ptr<Unk_Emotion> spAction(*sit);
            int nId = spAction->m_id;
            int nNew = spAction->m_isNew;
            bool bFavorite = spAction->m_favorite;
            SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
            if (pSkill == 0)
                continue;
            if (m_1b1 != 0 && !bFavorite)
                continue;
            if (!m_1b8.IsEmpty()) {
                if (FUN_1403b3c40(m_1b8, L"/") != 0)
                    continue;
                bool bFound = false;
                CStringW strName = FUN_141811980(GetStringTable(), 4, nId);
                if (strName.Find(m_1b8, 0) == -1) {
                    std::vector<CStringW> words;
                    CStringW strKeywords = FUN_14192d820(nId);
                    FUN_140988d60(strKeywords, words, L", ");
                    for (CStringW& strWord : words) {
                        if (strWord.Find(m_1b8, 0) != -1) {
                            bFound = true;
                            break;
                        }
                    }
                } else {
                    bFound = true;
                }
                if (!bFound)
                    continue;
            }
            if (nNew != 0)
                nFocus = nId;
            CStringW strKey = FUN_1409331f0()->FUN_14142d220(FUN_1409331f0()->FUN_14142c940((unsigned)nId, 0));
            ASObj action(2);
            action.FUN_1409c0d20("id", nId);
            action.FUN_1407cbb20("key", strKey);
            action.FUN_1407cb9c0("isNew", nNew);
            action.FUN_1407cb9c0("isLocked", 0);
            action.FUN_1407cba60("iconPath", pSkill->m_strIcon);
            action.FUN_1407cbbe0("isFavorite", bFavorite);
            actions.FUN_1422bbf00(action);
        }
        FUN_14192d960(actions);
        pDlg->FUN_140bd2cb0("buildActions", actions);
        if (nFocus != 0)
            FUN_14192c930(nFocus);
    }
}
MS2_REPLACE_METHOD(0x14192CA70, UIDynamicActionDialog, FUN_14192ca70, 1659, 0);

// @0x14192d100
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192d100()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0) {
        ASArray actions(2);
        int nFocus = 0;
        std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionGreater> sorted;
        for (std::map<unsigned int, MS2Ptr<Unk_Emotion> >::iterator it = m_190.begin(); it != m_190.end(); ++it)
        {
            MS2Ptr<Unk_Emotion> spCopy(it->second);
            sorted.insert(spCopy);
        }
        for (std::set<MS2Ptr<Unk_Emotion>, Unk_EmotionGreater>::iterator sit = sorted.begin(); sit != sorted.end(); ++sit) {
            MS2Ptr<Unk_Emotion> spAction(*sit);
            int nId = spAction->m_id;
            int nNew = spAction->m_isNew;
            bool bFavorite = spAction->m_favorite;
            SkillData* pSkill = FUN_1401958b0()->GetSkillData(nId);
            if (pSkill == 0)
                continue;
            if (m_1b1 != 0 && !bFavorite)
                continue;
            if (!m_1b8.IsEmpty()) {
                if (FUN_1403b3c40(m_1b8, L"/") != 0)
                    continue;
                bool bFound = false;
                CStringW strName = FUN_141811980(GetStringTable(), 4, nId);
                if (strName.Find(m_1b8, 0) == -1) {
                    std::vector<CStringW> words;
                    CStringW strKeywords = FUN_14192d820(nId);
                    FUN_140988d60(strKeywords, words, L", ");
                    for (CStringW& strWord : words) {
                        if (strWord.Find(m_1b8, 0) != -1) {
                            bFound = true;
                            break;
                        }
                    }
                } else {
                    bFound = true;
                }
                if (!bFound)
                    continue;
            }
            if (nNew != 0)
                nFocus = nId;
            CStringW strKey = FUN_1409331f0()->FUN_14142d220(FUN_1409331f0()->FUN_14142c940((unsigned)nId, 0));
            ASObj action(2);
            action.FUN_1409c0d20("id", nId);
            action.FUN_1407cbb20("key", strKey);
            action.FUN_1407cb9c0("isNew", nNew);
            action.FUN_1407cb9c0("isLocked", 0);
            action.FUN_1407cba60("iconPath", pSkill->m_strIcon);
            action.FUN_1407cbbe0("isFavorite", bFavorite);
            actions.FUN_1422bbf00(action);
        }
        FUN_14192d960(actions);
        pDlg->FUN_140bd2cb0("buildActions", actions);
        if (nFocus != 0)
            FUN_14192c930(nFocus);
    }
}
MS2_REPLACE_METHOD(0x14192D100, UIDynamicActionDialog, FUN_14192d100, 1659, 0);

// @0x14192d790
void UIDynamicActionDialog::FUN_14192d790(CStringW strSearch)
{
    if (m_1b8.CompareNoCase(strSearch) == 0)
        return;
    m_1b8 = strSearch;
    FUN_14192c6b0();
}
MS2_REPLACE_METHOD(0x14192D790, UIDynamicActionDialog, FUN_14192d790, 124, 0);

// @0x14192d820
CStringW UIDynamicActionDialog::FUN_14192d820(unsigned int nAction)
{
    MS2Ptr<Unk_EmotionKeywords> spData = FUN_140347050(nAction);
    if (!spData)
        return CStringW(L"");
    CStringW strKeywords;
    for (size_t i = 0; i < spData->m_38.GetCount(); i++)
        strKeywords.AppendFormat(L"%s ", (const wchar_t*)spData->m_38[i]);
    strKeywords.TrimRight();
    return strKeywords;
}
MS2_REPLACE_METHOD(0x14192D820, UIDynamicActionDialog, FUN_14192d820, 311, 0);

// @0x14192d960
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192d960(ASArray& arr)
{
    int nRounded = (int)(std::ceil((float)arr.FUN_1422bc5d0() / 6.0f) * 6.0f);
    int nPages = nRounded > 0x18 ? nRounded : 0x18;
    int nMissing = nPages - arr.FUN_1422bc5d0();
    if (nMissing < 0)
        return;
    for (int i = 0; i < nMissing; i++) {
        Scaleform::GFx::Value kEmpty;
        kEmpty.SetNull();
        arr.FUN_1422bc050(kEmpty);
    }
}
MS2_REPLACE_METHOD(0x14192D960, UIDynamicActionDialog, FUN_14192d960, 254, 0);

// @0x14192da70
// MS2-FUNCTIONAL: compiler scheduling/register-allocation differs from the exe
void UIDynamicActionDialog::FUN_14192da70(int nKey)
{
    if (nKey == 0x79) {
        MS2Ptr<Unk_DaList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            spList->FUN_1422dcca0(FUN_140ad02c0(0, nIndex - 4));
        }
    } else if (nKey == 0x7e) {
        MS2Ptr<Unk_DaList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            int nLast = spList->FUN_1422dcd80()->FUN_1422bc5d0();
            spList->FUN_1422dcca0(FUN_140ad02f0(nLast - 1, nIndex + 4));
        }
    } else if (nKey == 0x7b) {
        MS2Ptr<Unk_DaList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            spList->FUN_1422dcca0(FUN_140ad02c0(0, nIndex - 1));
        }
    } else if (nKey == 0x7c) {
        MS2Ptr<Unk_DaList> spList = FUN_140ba4b70("m_list");
        if (spList.get() != 0) {
            int nIndex = spList->FUN_1422dccd0();
            int nLast = spList->FUN_1422dcd80()->FUN_1422bc5d0();
            spList->FUN_1422dcca0(FUN_140ad02f0(nLast - 1, nIndex + 1));
        }
    }
}
MS2_REPLACE_METHOD(0x14192DA70, UIDynamicActionDialog, FUN_14192da70, 1067, 0);

// @0x14192deb0
int UIDynamicActionDialog::FUN_14192deb0(int nKey)
{
    return FUN_1409331f0()->FUN_14142d190(nKey) == 0;
}
MS2_REPLACE_METHOD(0x14192DEB0, UIDynamicActionDialog, FUN_14192deb0, 62, 0);

// @0x14192df00
int UIDynamicActionDialog::FUN_14192df00(int nKey, unsigned __int64 nAction)
{
    if (FUN_1409331f0()->FUN_14142b250(nKey, 2, nAction, 0, 0) != 0) {
        FUN_14192c6b0();
        FUN_1409331f0()->FUN_14142a8b0(nAction);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14192DF00, UIDynamicActionDialog, FUN_14192df00, 108, 0);

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbdd90-0x142cbde60 .text$yd
