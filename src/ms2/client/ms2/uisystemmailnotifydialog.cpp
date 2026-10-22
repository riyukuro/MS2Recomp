// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISystemMailNotifyDialog: see uisystemmailnotifydialog.h.
// MS2-UNIT: unit_1412a4590
// MS2-RANGE: 0x1400ed130-0x1400ed270 .text$di
// MS2-RANGE: 0x1412a4590-0x1412a74a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUISystemMailNotifyDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1412a66a0 ; prop
// MS2-PIN: ??$?8PEAVUISystemMailNotifyDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1412a6710 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x1412a6cc0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1412a6d60 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x1412a6f90 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x1412a6fd0 ; prop
// MS2-PIN: ??_GUISystemMailNotifyDialog@@UEAAPEAXI@Z 0x1412a7010 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412a7120 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412a7180 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412a71e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1412a7210 ; unique
// MS2-PIN: ??$Call@VUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412a7240 ; prop
// MS2-PIN: ??$Call@VUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1412a7280 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412a72c0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUISystemMailNotifyDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412a7320 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uisystemmailnotifydialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "uisystemmailnotifydialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of this unit's header: skill / stun, the condition table and the key-input controller (no sort-type
// names here), then the unit's own two sound event names.
static CString s_strSkill = "skill";                                        // @0x1400ed130
static CString s_strStun = "stun";                                          // @0x1400ed160
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);              // @0x1400ed190
static UICommon::CMyPCKeyInputController s_keyInput;                        // @0x1400ed1e0
static CString s_strPopDown = "system_mail_event_popdown";                  // @0x1400ed210
static CString s_strPopUp = "system_mail_event_popup";                      // @0x1400ed240

// ---- unit-local views of exe objects ----

// A reward row of a system mail (0x14 bytes): the job it is for (0 = all), the item and its count.
struct Unk_SmReward
{
    int m_nJob;                                                 // +0x00
    unsigned m_nItemId;                                         // +0x04
    int m_nCount;                                               // +0x08
    int m_pad_0c[2];
};
MS2_CHECK_SIZE(Unk_SmReward, 0x14);

// The body of a mail table record (at +0x70 of the record).
struct Unk_SmBody
{
    int m_nId;                                                  // +0x00
    int m_nPending;                                             // +0x04 the mail id a later popup is pending for
    CString m_strKey;                                           // +0x08 string table key of the description
    CString m_strAttach;                                        // +0x10 "attachment" or a text
    ATL::CAtlArray<Unk_SmReward> m_rewards;                     // +0x18
    // @0x1412a7050 the rewards for a job: its own rows and the all-job rows
    void FUN_1412a7050(unsigned nJob, ATL::CAtlArray<Unk_SmReward>& out)
    {
        for (size_t i = 0; i < m_rewards.GetCount(); i++)
        {
            if (m_rewards[i].m_nJob != 0 && m_rewards[i].m_nJob != nJob)
                continue;
            out.Add(m_rewards[i]);
        }
    }
};

struct Unk_SmData
{
    unsigned char m_pad_00[0x34];
    int m_nUrlTextId;                                           // +0x34
    unsigned char m_pad_38[0x38];
    Unk_SmBody m_body;                                          // +0x70
};
MS2_CHECK_OFFSET(Unk_SmData, m_body, 0x70);

// The counted handle of a mail record (ctor 0x1408d3090, dtor 0x1408d36d0, operator-> 0x1408d37f0).
class Unk_SmHandle
{
public:
    Unk_SmHandle(int nId);
    ~Unk_SmHandle();
    Unk_SmData* operator->() const;
    bool FUN_1412a6f10() const { return m_p == 0; }             // 0x1412a6f10 is empty
    Unk_SmData* FUN_1412a6f80() const { return m_p; }           // 0x1412a6f80
    void* m_unk_00;
    Unk_SmData* m_p;                                            // +0x08
};

// The button children: click callback, label.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n);   // click callback
};

// The reward icon slot of the event clip: it shows the item bound under a name.
class Unk_SmSlot : public ASUIComponent
{
public:
    void FUN_1422e4840(CString strName);
};

// The AS root of the dialog: the hit test of the event clip.
class Unk_SmScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);
};

// The container lookup (asdisplayobjectcontainer.h): getChildByName, else a depth-first search of the children.
class Unk_SmNode : public ASDisplayObjectContainer
{
public:
    // @0x1412a6780 (button) / @0x1412a6850 (reward slot): bind the child into outControl
    template <class T> MS2Ptr<T> GetChild(const CString& strName, MS2Ptr<T>& outControl);
    // @0x140d01e70 (button) / @0x1412a6920 (reward slot)
    template <class T> MS2Ptr<T> FUN_deep(const Scaleform::GFx::Value& v, const CString& strName);
};

// The event clip: the child lookups used on it (the AS clip is an Unk_SmNode in the exe).
class Unk_SmClip : public ASMovieClip
{
public:
    CString FUN_1422c2420() noexcept;                                    // the current frame label
};

MS2Ptr<ASDisplayObjectContainer> FUN_140bc5fc0(int nMovieId, const Scaleform::GFx::Value& v);
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);
template <> MS2Ptr<Unk_SmSlot> Unk_ASCreate<Unk_SmSlot>(int, const Scaleform::GFx::Value&);          // 0x140c3bb40
template <> MS2Ptr<Unk_140acd6e0> Unk_SmNode::FUN_deep<Unk_140acd6e0>(const Scaleform::GFx::Value&, const CString&);   // 0x140d01e70

#define MS2_ASDOC_ASSERT(line, expression) \
    (void)((expression) || (_wassert(L"outControl", L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\asdisplayobjectcontainer.h", (unsigned)(line)), 0))

// ---- out-of-unit callees (names describe uses) ----
class Unk_SmNotices { public:                                               // the notify table (TSingleton)
    void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>);
    void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>);
};
Unk_SmNotices* FUN_140939a10();
class Unk_SmChat { public: void FUN_141a25770(CStringW strCmd, int n); };   // the chat window: run a command
Unk_SmChat* FUN_140a3ab70(int nUiType);
class Unk_SmPlayer { public: int FUN_141654700(); };                        // the job of the player
class Unk_SmPlayers { public: Unk_SmPlayer* FUN_141bd0cc0(); };
Unk_SmPlayers* FUN_1403ed2d0();
class Unk_SmTexts { public: CStringW FUN_140478020(int nTextId); };      // text of a string id
Unk_SmTexts* FUN_1401c0d90();
class Unk_SmItemNames { public: CStringW FUN_141811980(int n, int nItemId); };   // the item name text
Unk_SmItemNames* FUN_1401a9d70();
void FUN_140cfefe0(const Scaleform::GFx::Value& root, CString strProp, CString strChild, CStringW strText);   // set a child's text
CStringW FUN_14016a730(const char* psz, int n);                             // narrow -> wide
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& strArg);    // text with one argument
CStringW FUN_14062b4f0(CStringW strKey, const unsigned& nArg);              // string table text with one argument
bool FUN_140184310(const CString& str, const char* psz) noexcept;                    // string equals
void FUN_1418fe1c0(const CString& strUrl);                                  // open the page
void FUN_141276180(const CString& strEvent, const CString& strArg);         // play a sound event
void FUN_141415600(const CString& strName);                                 // drop the item shown under a dialog name
void FUN_141415450(const CString& strName, MS2Ptr<CItem> item, int a, int b, int c);   // show an item under a dialog name
unsigned FUN_140869420();                                                   // the server time in seconds
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                      // has the AS object been released
class Unk_SmEvent { public: };
Unk_SmEvent* FUN_1408e57f0();
int FUN_1422b9e00(Unk_SmEvent* p);                                          // the notify type

template <class T> MS2Ptr<T> Unk_SmNode::GetChild(const CString& strName, MS2Ptr<T>& outControl)
{
    outControl = FUN_deep<T>(m_value, strName);
    MS2_ASDOC_ASSERT(0x5a, !outControl.IsNull());
    return outControl;
}

template <class T> MS2Ptr<T> Unk_SmNode::FUN_deep(const Scaleform::GFx::Value& v, const CString& strName)
{
    MS2Ptr<ASDisplayObjectContainer> spObj = FUN_140bc5fc0(m_nMovieId, v);
    if (!spObj->FUN_1422ba9f0("getChildByName"))
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = spObj->FUN_1422c6b00(strName);
    if (child.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, child);
    if (!spObj->FUN_1422ba9f0("numChildren"))
        return MS2Ptr<T>(0);
    int nCount = spObj->FUN_1422c6670();
    for (int i = 0; i < nCount; i++)
    {
        Scaleform::GFx::Value sub = spObj->FUN_1422c6aa0(i);
        if (!sub.IsObject())
            continue;
        MS2Ptr<T> spFound = FUN_deep<T>(sub, strName);
        if (spFound.get() != 0)
            return spFound;
    }
    return MS2Ptr<T>(0);
}

// @0x1412a4590
UISystemMailNotifyDialog::UISystemMailNotifyDialog()
    : m_bOnTime(0), m_nHideAt(0)
{
    FUN_141925e70(0, 1);
    m_17c = 0;
    m_178 = 0;
    m_180 = 0;
    m_184 = 1;
    FUN_140939a10()->FUN_140da4e40(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UISystemMailNotifyDialog::FUN_1412a5e60));
}

// @0x1412a47f0
UISystemMailNotifyDialog::~UISystemMailNotifyDialog()
{
    FUN_140939a10()->FUN_140da4eb0(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &UISystemMailNotifyDialog::FUN_1412a5e60));
}

// @0x1412a49b0
CString UISystemMailNotifyDialog::GetTypeName()
{
    return "SystemMailNotifyDialog";
}

// @0x1412a4a00
void UISystemMailNotifyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_140acd6e0* pShow = FUN_140bc6d10("m_btnShow", m_btnShow).get();
    if (pShow != 0)
        m_btnShow->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISystemMailNotifyDialog::FUN_1412a5d10), 0);
    if (m_bOnTime != 0)
    {
        ASMovieClip* pOnTime = FUN_140c57ce0("m_onTimeEvent", m_onTimeEvent).get();
        if (pOnTime != 0)
        {
            Unk_140acd6e0* pButton = static_cast<Unk_SmNode*>(static_cast<ASDisplayObjectContainer*>(m_onTimeEvent.operator->()))->GetChild<Unk_140acd6e0>("m_onTimeEventButton", m_btnOnTime).get();
            if (pButton != 0)
                m_btnOnTime->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISystemMailNotifyDialog::FUN_1412a5de0), 0);
            m_onTimeEvent->vfunc_3(1);
            m_onTimeEvent->vfunc_13("open");
            FUN_141276180(s_strPopUp, "");
        }
    }
    else
    {
        ASMovieClip* pEvent = FUN_140c57ce0("m_event", m_event).get();
        if (pEvent != 0)
        {
            Unk_140acd6e0* pDetail = static_cast<Unk_SmNode*>(static_cast<ASDisplayObjectContainer*>(m_event.operator->()))->GetChild<Unk_140acd6e0>("m_detail", m_btnDetail).get();
            if (pDetail != 0)
                m_btnDetail->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISystemMailNotifyDialog::FUN_1412a5ce0), 0);
            Unk_140acd6e0* pClose = static_cast<Unk_SmNode*>(static_cast<ASDisplayObjectContainer*>(m_event.operator->()))->GetChild<Unk_140acd6e0>("m_close", m_btnClose).get();
            if (pClose != 0)
                m_btnClose->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UISystemMailNotifyDialog::FUN_1412a5db0), 0);
            m_event->vfunc_3(0);
            m_event->vfunc_13("close");
        }
        if (m_178 != 0 && (m_180 != 0 || m_184 != 0))
        {
            m_180 = 0;
            FUN_1412a5570(m_178);
            if (m_184 != 0)
                m_184 = 0;
        }
    }
}

// @0x1412a52b0
void UISystemMailNotifyDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_strUrl.Empty();
    FUN_1412a6080();
    m_btnShow = 0;
    m_event = 0;
    m_btnDetail = 0;
    m_btnClose = 0;
}

// @0x1412a5340
void UISystemMailNotifyDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (m_nHideAt == 0)
        return;
    if (m_tick.FUN_140268870(500) != 0)
    {
        unsigned nNow = FUN_140869420();
        if (nNow >= m_nHideAt)
            FUN_1412a62a0();
        else
            FUN_1412a6390();
    }
}

// @0x1412a53e0
void UISystemMailNotifyDialog::FUN_1412a53e0(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 0:
        {
            int nId = packet.vfunc_o8_3();
            m_178 = nId;
            m_17c = nId;
        }
        break;
    case 1:
        {
            int nId = packet.vfunc_o8_3();
            {
                Unk_SmHandle rec(nId);
                if (rec.FUN_1412a6f80() != 0)
                {
                    m_178 = nId;
                    m_17c = rec->m_body.m_nPending;
                    if (FUN_141924630() != 0)
                        FUN_1412a5570(nId);
                }
            }
            m_180 = (nId != 0);
        }
        break;
    }
}

// @0x1412a5570
// MS2-FUNCTIONAL: the exe passes the job id to Unk_SmBody::FUN_1412a7050 through ecx->edx (2 extra bytes, no source form found)
void UISystemMailNotifyDialog::FUN_1412a5570(int nMailId)
{
    Unk_SmHandle rec(nMailId);
    if (rec.FUN_1412a6f10() != 0)
        return;
    if (m_30.IsNull() != 0)
        return;
    if (m_event == 0)
        return;
    Unk_SmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_strUrl = FUN_1401c0d90()->FUN_140478020(rec->m_nUrlTextId);
    ATL::CAtlArray<Unk_SmReward> rewards;
    int nJob = pPlayer->FUN_141654700();
    rec->m_body.FUN_1412a7050(nJob, rewards);
    if (rewards.GetCount() > 0)
    {
        FUN_1412a5eb0(&rewards[0]);
        MS2Ptr<Unk_SmSlot> spSlot;
        Unk_SmSlot* pSlotClip = static_cast<Unk_SmNode*>(static_cast<ASDisplayObjectContainer*>(m_event.operator->()))->GetChild<Unk_SmSlot>("m_slot", spSlot).get();
        if (pSlotClip != 0)
            spSlot->FUN_1422e4840(m_strSlot);
        FUN_140cfefe0(m_event->FUN_1422bb890(), "content", "m_title", FUN_1401a9d70()->FUN_141811980(1, rewards[0].m_nItemId));
        CStringW strAttach;
        if (FUN_140184310(rec->m_body.m_strAttach, "attachment"))
            strAttach = FUN_1401a9d70()->FUN_141811980(1, rewards[0].m_nItemId);
        else
            strAttach = (const char*)rec->m_body.m_strAttach;
        CStringW strDesc = FUN_1401e8510(GetStringCommonByKey(FUN_14016a730(rec->m_body.m_strKey, 0)), strAttach);
        FUN_140cfefe0(m_event->FUN_1422bb890(), "content", "m_desc", strDesc);
    }
    FUN_141276180(s_strPopUp, "");
    FUN_1412a60d0();
}

// @0x1412a5c50
void UISystemMailNotifyDialog::SetOnTime(bool bOnTime)
{
    m_bOnTime = bOnTime;
}

// @0x1412a5c70
void UISystemMailNotifyDialog::FUN_1412a5c70(int nMs)
{
    m_nHideAt = FUN_140869420() + nMs;
}

// @0x1412a5ca0
int UISystemMailNotifyDialog::FUN_1412a5ca0()
{
    return m_17c != 0;
}

// @0x1412a5ce0
void UISystemMailNotifyDialog::FUN_1412a5ce0(const Scaleform::GFx::FunctionHandler::Params&)
{
    FUN_1418fe1c0(m_strUrl);
}

// @0x1412a5d10
void UISystemMailNotifyDialog::FUN_1412a5d10(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_event.get() != 0)
    {
        if (FUN_140184310(static_cast<Unk_SmClip*>(m_event.operator->())->FUN_1422c2420(), "close"))
            FUN_1412a5570(m_178);
        else
            FUN_1412a61a0();
    }
}

// @0x1412a5db0
void UISystemMailNotifyDialog::FUN_1412a5db0(const Scaleform::GFx::FunctionHandler::Params&)
{
    FUN_1412a61a0();
}

// @0x1412a5de0
void UISystemMailNotifyDialog::FUN_1412a5de0(const Scaleform::GFx::FunctionHandler::Params&)
{
    Unk_SmChat* pChat = FUN_140a3ab70(0x4e61);
    if (pChat != 0)
        pChat->FUN_141a25770(L"/AddOntimeEvent", 0);
    vfunc_67();
}

// @0x1412a5e60
void UISystemMailNotifyDialog::FUN_1412a5e60(NotifyObject*)
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
        return;
    if (FUN_1412a5ca0() != 0)
        FUN_141924680();
}

// @0x1412a5eb0
void UISystemMailNotifyDialog::FUN_1412a5eb0(const Unk_SmReward* pReward)
{
    FUN_1412a6080();
    CString strName = StringFormat("{0}_{1}", GetTypeName(), pReward->m_nItemId);
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_140523c40(pReward->m_nItemId, pReward->m_nCount, 0) == 0)
        return;
    FUN_141415450(strName, MS2Ptr<CItem>(spItem), 0, 0x401, 0);
    m_strSlot = strName;
}

// @0x1412a6080
void UISystemMailNotifyDialog::FUN_1412a6080()
{
    FUN_141415600(m_strSlot);
    m_strSlot = "";
}

// @0x1412a60d0
void UISystemMailNotifyDialog::FUN_1412a60d0()
{
    if (m_event == 0)
        return;
    m_event->vfunc_3(1);
    m_event->vfunc_13("open");
    FUN_1412a5c70(3000);
}

// @0x1412a61a0
void UISystemMailNotifyDialog::FUN_1412a61a0()
{
    if (m_event == 0)
        return;
    m_event->vfunc_13("close");
    m_nHideAt = 0;
    m_178 = m_17c;
    if (m_178 == 0)
        vfunc_67();
    FUN_141276180(s_strPopDown, "");
}

// @0x1412a62a0
void UISystemMailNotifyDialog::FUN_1412a62a0()
{
    m_nHideAt = 0;
    if (m_event.get() != 0)
    {
        if (static_cast<Unk_SmScript*>(m_30.operator->())->FUN_1422bb330("hitTestEvent").GetBool())
        {
            FUN_1412a5c70(3000);
            return;
        }
        FUN_1412a61a0();
    }
    else
    {
        if (m_onTimeEvent.get() != 0)
        {
            m_bOnTime = 0;
            vfunc_67();
        }
    }
}

// @0x1412a6390
void UISystemMailNotifyDialog::FUN_1412a6390()
{
    if (m_onTimeEvent.get() != 0)
    {
        unsigned nRemain = (unsigned)(m_nHideAt - FUN_140869420()) / 1000;
        CStringW strText = FUN_14062b4f0(L"s_systemmail_notify_remain_text", nRemain);
        FUN_140cfefe0(m_onTimeEvent->FUN_1422bb890(), "content", "m_remainTime", strText);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf080-0x142caf140 .text$yd
