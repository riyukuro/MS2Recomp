// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingPage and its three pages (message, skill, mission),
// the tabs of UIWeddingDialog: see uiweddingpage.h.
// MS2-UNIT: ?\uiweddingpage.cpp
// MS2-RANGE: 0x1400e3510-0x1400e3680 .text$di
// MS2-RANGE: 0x140fe7390-0x140fe9d00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e35d0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e3600 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIWeddingPage@@UEAAPEAXI@Z 0x140fe98c0
// MS2-PIN: ??_GUIWeddingPageMessage@@UEAAPEAXI@Z 0x140fe9900
// MS2-PIN: ??_GUIWeddingPageMission@@UEAAPEAXI@Z 0x140fe9940
// MS2-PIN: ??_GUIWeddingPageSkill@@UEAAPEAXI@Z 0x140fe9980
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddingpage.cpp"    // assumed

// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uiweddingpage.h"
#include "uiweddingdialog.h"
#include "questmanager_1.h"
#include "questmanager_2.h"
#include "uimessageboxdata.h"

#include <algorithm>
#include <map>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingproxy.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/weddingtable.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The movie root: child lookups by name (one COMDAT per wrapper class).
class Unk_WpRoot : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);
};

// A text input child of the page.
class Unk_WpInput : public ASDisplayObject
{
public:
    void FUN_1422e0ab0(const CStringW& str);                    // set the text
};

// The embedded item (+0x50) of an item grant row: its virtual slots give the item id / its count.
class Unk_WpGrant
{
public:
    virtual int vfunc_0();                                      // the item id
    virtual int vfunc_1();                                      // the count
};

// A wedding grade perk (WeddingTable's skill map): a skill (type 0) or an item (type 1) unlocked by a grade.
class Unk_WpPerk : public CPtred
{
public:
    unsigned short FUN_140907ad0(int nGrade);                            // the skill level the grade gives
    float FUN_140907b50(int nGrade);                            // the progress to the next level

    int m_pad_18;
    int m_nType;                                                // +0x1c 0 = skill, 1 = item
    int m_nGrade;                                               // +0x20 the grade that unlocks it
    int m_pad_24;
    int m_nSkillId;                                             // +0x28
    float m_pad_2c;
    char m_pad_30[0x20];
    Unk_WpGrant m_grant;                                        // +0x50
    Unk_WpGrant* GetGrant() { return &m_grant; }                // reached through a pointer so the calls stay virtual
};
MS2_CHECK_OFFSET(Unk_WpPerk, m_nType, 0x1c);
MS2_CHECK_OFFSET(Unk_WpPerk, m_grant, 0x50);

class Unk_WpPerkTable
{
public:
    std::map<int, MS2Ptr<Unk_WpPerk> >& FUN_140909a80();        // the perk map
    MS2Ptr<Unk_WpPerk> FUN_140909910(int nId);                  // one perk (null: none)
};

// Skill record and its icon.
class Unk_WpSkill : public CPtred
{
public:
    CString FUN_1401756c0();                                    // the icon path
};
class Unk_WpSkillMgr
{
public:
    MS2Ptr<Unk_WpSkill> FUN_140aafef0(int nSkillId, short nLevel);
};
class Unk_WpItemData : public CPtred
{
public:
    CString FUN_14053fdd0();                                    // the icon path
};
class Unk_WpNames : public CStringTable
{
public:
    CStringW FUN_141812290(int nSkillId, short nLevel, CString strKey);
};

Unk_WpSkillMgr* FUN_1401958b0();
MS2Ptr<Unk_WpItemData> FUN_14053f870(int nItemId);
extern Unk_Inventory DAT_143ab2a90;
extern __int64 DAT_143ab2828;                                   // the own character id

bool FUN_140a467d0(const MS2Ptr<AScript>& kScript);             // has the AS object been released
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);     // Value::IsNull
MS2Ptr<ASUIComponent> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
int FUN_141b89950(WeddingManager* pManager);                    // the wedding grade
CStringW FUN_140298ea0(CStringW strKey);                        // string table text
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);       // string table format
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);       // string table format
CStringW FUN_1409404f0(__int64 nValue);                         // number with separators
CStringW FUN_1416e5350(int nQuestId, int n);                    // quest title
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
bool FUN_140841300(const CStringW& str, const char* sz);        // string equals
void FUN_1412752d0(const CStringW& strText, int n);                    // notice
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);      // pRetVal = v
CQuestManager* FUN_140764020();
UIQuestEventDispatcher* FUN_140bfc4b0();

WorldService* FUN_1403ed2d0();

// ---- statics of the unit's header (the quest sort name list, skill, stun, a condition object) ----

static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member

// @0x140fe95a0
void ASObj::FUN_140fe95a0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// ---- UIWeddingPage ----

// @0x140fe7390
UIWeddingPage::UIWeddingPage(UIWeddingDialog* pDialog) : m_pScript(0)
{
    m_28 = pDialog;
}

// @0x140fe7400
UIWeddingPage::~UIWeddingPage()
{
}

// @0x140fe7440
bool UIWeddingPage::vfunc_1()
{
    if (FUN_140a467d0(m_28->FUN_1422dba00()))
        return false;
    Scaleform::GFx::Value kPage = m_28->FUN_1422dba00()->FUN_1422baa20("m_currentPage");
    if (FUN_1409b0350(&kPage) != 0)
        return false;
    m_pScript = FUN_140acca70(m_28->FUN_1422db730(), kPage);
    return true;
}

// @0x140fe75a0
void UIWeddingPage::vfunc_2()
{
    m_pScript = 0;
}

// @0x140fe75d0
bool UIWeddingPage::vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return false;
}

// @0x140fe75f0
void UIWeddingPage::vfunc_4()
{
}

// @0x140fe7600
void UIWeddingPage::vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
}

// @0x140fe7620
MS2Ptr<AScript> UIWeddingPage::GetScript() const
{
    return m_pScript;
}

// @0x140fe7670
UIWeddingDialog* UIWeddingPage::FUN_140fe7670() const
{
    return m_28;
}

// ---- UIWeddingPageMessage ----

// @0x140fe7690
UIWeddingPageMessage::UIWeddingPageMessage(UIWeddingDialog* pDialog) : UIWeddingPage(pDialog)
{
}

// @0x140fe9790 ~UIWeddingPageMessage is implicit (uiweddingpage.h).

// @0x140fe76d0
bool UIWeddingPageMessage::vfunc_1()
{
    if (!UIWeddingPage::vfunc_1())
        return false;
    WeddingProxy* pProxy = WeddingManager::GetInstance()->FUN_140d295d0();
    bool bGroom = pProxy->IsGroom(DAT_143ab2828);
    if (MS2Ptr<Unk_WpInput> spMine = static_cast<Unk_WpRoot*>(m_pScript.operator->())->FUN_140bbe880<Unk_WpInput>("m_myMessage"))
        spMine->FUN_1422e0ab0(pProxy->GetMessageW(bGroom));
    if (MS2Ptr<Unk_WpInput> spPartner = static_cast<Unk_WpRoot*>(m_pScript.operator->())->FUN_140bbe880<Unk_WpInput>("m_partnerMessage"))
        spPartner->FUN_1422e0ab0(pProxy->GetMessageW(!bGroom));
    return true;
}

// @0x140fe7900
CString UIWeddingPageMessage::vfunc_6()
{
    return "PageMessage";
}

// @0x140fe7950
CStringW UIWeddingPageMessage::vfunc_7()
{
    return GetStringCommonByKey(L"s_wedding_dialog_page_message");
}

// @0x140fe79c0
bool UIWeddingPageMessage::vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onChangeMessage") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strMessage = data.FUN_1422b8f40();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_140298ea0(CStringW(L"s_wedding_dialog_couple_message_confirm")), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWeddingPageMessage::SendWedding));
                spBox->FUN_140b76940(CStringW(strMessage));
                FUN_140d73c60(spBox);
            }
        }
        return true;
    }
    return false;
}

// @0x140fe7c60
bool UIWeddingPageMessage::SendWedding(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    CStringW strMessage = box.FUN_141a02fd0(0, CStringW());
    COutPacket pkt(static_cast<int>(SendOp::Wedding), 0);
    pkt.WriteUInt8(0x22);
    pkt.WriteUnicodeString(strMessage);
    FUN_140710590(pkt);
    return true;
}

// ---- UIWeddingPageSkill ----

// @0x140fe7d30
UIWeddingPageSkill::UIWeddingPageSkill(UIWeddingDialog* pDialog) : UIWeddingPage(pDialog)
{
}

// @0x140fe97f0 ~UIWeddingPageSkill is implicit (uiweddingpage.h).

// @0x140fe7d70
bool UIWeddingPageSkill::vfunc_1()
{
    if (!UIWeddingPage::vfunc_1())
        return false;
    int nGrade = FUN_141b89950(TSingleton<WeddingManager>::GetInstance());
    if (MS2Ptr<ASScrollingList> spList = static_cast<Unk_WpRoot*>(m_pScript.operator->())->FUN_140bc7280<ASScrollingList>("m_list"))
    {
        spList->FUN_1422dd1d0();
        std::map<int, MS2Ptr<Unk_WpPerk> >& perks = reinterpret_cast<Unk_WpPerkTable*>(TSingleton<WeddingTable>::GetInstance())->FUN_140909a80();
        std::map<int, MS2Ptr<Unk_WpPerk> >::iterator it = perks.begin();
        std::map<int, MS2Ptr<Unk_WpPerk> >::iterator itEnd = perks.end();
        for (; it != itEnd; ++it)
        {
            MS2Ptr<Unk_WpPerk> spPerk(it->second);
            ASObj obj(2);
            obj.FUN_1407cb9c0("id", it->first);
            obj.FUN_140fe95a0("type", spPerk->m_nType);
            obj.FUN_1407cbb20("level", FUN_14062b4f0(CStringW(L"s_wedding_dialog_wedding_grade"), spPerk->m_nGrade));
            obj.FUN_1407cbbe0("activate", nGrade >= spPerk->m_nGrade);
            if (spPerk->m_nType == 0)
            {
                unsigned short nSkillLevel = std::max<unsigned short>(spPerk->FUN_140907ad0(nGrade), 1);
                MS2Ptr<Unk_WpSkill> spSkill = FUN_1401958b0()->FUN_140aafef0(spPerk->m_nSkillId, nSkillLevel);
                if (spSkill == 0)
                    continue;
                obj.FUN_1407cbb20("name", reinterpret_cast<Unk_WpNames*>(TSingleton<CStringTable>::GetInstance())->FUN_141812290(spPerk->m_nSkillId, nSkillLevel, CString("name")));
                obj.FUN_1409c4a30("status", spPerk->FUN_140907b50(nGrade));
                obj.FUN_1407cba60("imgPath", spSkill->FUN_1401756c0());
            }
            else if (spPerk->m_nType == 1)
            {
                MS2Ptr<Unk_WpItemData> spItem = FUN_14053f870((&spPerk->m_grant)->vfunc_0());
                obj.FUN_1407cbb20("name", reinterpret_cast<Unk_WpNames*>(TSingleton<CStringTable>::GetInstance())->FUN_141811980(1, (&spPerk->m_grant)->vfunc_0()));
                obj.FUN_1407cb9c0("status", 0);
                obj.FUN_1407cba60("imgPath", spItem->FUN_14053fdd0());
            }
            spList->FUN_1422dd230(obj);
        }
        spList->vfunc_24(true);
    }
    return true;
}

// @0x140fe83f0
CString UIWeddingPageSkill::vfunc_6()
{
    return "PageSkill";
}

// @0x140fe8440
CStringW UIWeddingPageSkill::vfunc_7()
{
    return GetStringCommonByKey(L"s_wedding_dialog_page_skill");
}

// @0x140fe84b0
bool UIWeddingPageSkill::vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onReceive") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nId = data.FUN_1422b8a10();
            MS2Ptr<Unk_WpPerk> spPerk = reinterpret_cast<Unk_WpPerkTable*>(TSingleton<WeddingTable>::GetInstance())->FUN_140909910(nId);
            if (spPerk == 0)
                return true;
            if (spPerk->m_nType != 1)
                return true;
            if (DAT_143ab2a90.FUN_140a5e2e0((&spPerk->m_grant)->vfunc_0()).get() != 0)
            {
                {
                    CStringW strMsg(L"s_wedding_dialog_page_skill_exist");
                    FUN_1412752d0(strMsg, 1);
                }
                return true;
            }
            COutPacket pkt(static_cast<int>(SendOp::Wedding), 0);
            pkt.WriteUInt8(0x25);
            pkt.WriteInt32(nId);
            FUN_140710590(pkt);
        }
        return true;
    }
    return false;
}

// @0x140fe8720
void UIWeddingPageSkill::vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    int nId = pArgs->FUN_1422b8a10();
    MS2Ptr<Unk_WpPerk> spPerk = reinterpret_cast<Unk_WpPerkTable*>(TSingleton<WeddingTable>::GetInstance())->FUN_140909910(nId);
    if (spPerk == 0)
        return;
    int nGrade = FUN_141b89950(TSingleton<WeddingManager>::GetInstance());
    if (spPerk->m_nType == 0)
    {
        unsigned short nSkillLevel = std::max<unsigned short>(spPerk->FUN_140907ad0(nGrade), 1);
        MS2Ptr<Unk_WpSkill> spSkill = FUN_1401958b0()->FUN_140aafef0(spPerk->m_nSkillId, nSkillLevel);
        if (spSkill.get() != 0)
        {
            ASTooltip tip(*pRetVal, 2);
            tip.FUN_1409e2750(spSkill.get(), 6, 0);
        }
    }
    else if (spPerk->m_nType == 1)
    {
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e1770((&spPerk->m_grant)->vfunc_0(), (&spPerk->m_grant)->vfunc_1());
    }
}

// ---- UIWeddingPageMission ----

// @0x140fe8950
UIWeddingPageMission::UIWeddingPageMission(UIWeddingDialog* pDialog) : UIWeddingPage(pDialog), m_binder(CString("UIWeddingPageMission"))
{
}

// @0x140fe97b0 ~UIWeddingPageMission is implicit (uiweddingpage.h).

// @0x140fe89f0
bool UIWeddingPageMission::vfunc_1()
{
    if (!UIWeddingPage::vfunc_1())
        return false;
    FUN_140bfc4b0()->FUN_141aa87c0(static_cast<UIQuestEventListener*>(this));
    FUN_140fe8fb0();
    return true;
}

// @0x140fe8a60
void UIWeddingPageMission::vfunc_2()
{
    UIWeddingPage::vfunc_2();
    m_binder.FUN_140d43990();
    FUN_140bfc4b0()->FUN_141aa8850(static_cast<UIQuestEventListener*>(this));
}

// @0x140fe8ad0
CString UIWeddingPageMission::vfunc_6()
{
    return "PageMission";
}

// @0x140fe8b20
CStringW UIWeddingPageMission::vfunc_7()
{
    return GetStringCommonByKey(L"s_wedding_dialog_page_mission");
}

// @0x140fe8b90
bool UIWeddingPageMission::vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onReceiveItem") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nQuestId = data.FUN_1422b8b10();
            SendQuest(nQuestId);
        }
        return true;
    }
    return false;
}

// @0x140fe8c40
void UIWeddingPageMission::vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIWeddingPage::vfunc_5(pRetVal, pArgs);
    void* pScene = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pScene == 0)
        return;
    CStringW strName = pArgs->FUN_1422b8f40();
    int nQuestId = pArgs->FUN_1422b8b10();
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.IsNull())
        return;
    if (FUN_140841300(strName, "exp"))
    {
        ASTooltip tip(2);
        CStringW strTip = FUN_1405c2690(CStringW(L"s_wedding_dialog_page_wedding_exp_tooltip"), FUN_1409404f0(spData->m_complete.m_weddingExp));
        if (tip.FUN_1409e26b0(strTip) != 0)
        {
            tip.FUN_1409c6dc0(1);
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x140fe8e20 (the listener slot 12 thunk adjusts this by -0x30)
void UIWeddingPageMission::vfunc_o178_12(void* pQuest)
{
    FUN_140fe8fb0();
}

// @0x140fe8e50
void UIWeddingPageMission::SendQuest(int nQuestId)
{
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
    if (spQuest.IsNull())
        return;
    if (spQuest->IsComplete() == 0)
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.IsNull())
        return;
    COutPacket pkt(static_cast<int>(SendOp::Quest), 0);
    pkt.WriteUInt8(0x27);
    pkt.WriteInt32(nQuestId);
    FUN_140710590(pkt);
}

// @0x140fe8fb0
void UIWeddingPageMission::FUN_140fe8fb0()
{
    if (MS2Ptr<ASScrollingList> spList = static_cast<Unk_WpRoot*>(m_pScript.operator->())->FUN_140bc7280<ASScrollingList>("m_list"))
    {
        spList->FUN_1422dd1d0();
        m_binder.FUN_140d43990();
        ATL::CAtlArray<Unk_PayloadPtr<CQuest> > quests;
        FUN_140764020()->FUN_1416d1060(quests);
        for (size_t i = 0; i < quests.GetCount(); i++)
        {
            Unk_PayloadPtr<CQuest> spQuest(quests[i]);
            MS2Ptr<CQuestData> spData = spQuest->GetData();
            CStringW strDesc = FUN_1416e5350(spQuest->FUN_140bfc580(), 0);
            ASObj row(2);
            row.FUN_1409c0d20("id", spQuest->FUN_140bfc580());
            row.FUN_1407cbb20("desc", CStringW(strDesc));
            row.FUN_1407cb9c0("satisfied", spQuest->IsComplete());
            row.FUN_1407cb9c0("completed", spQuest->IsRewarded());
            row.FUN_1409c1180("exp", spData->m_complete.m_weddingExp);
            const ATL::CAtlArray<CQuestData::QuestRewardItem>& rewards = spData->m_complete.m_choiceRewards;
            if (rewards.GetCount() > 0)
                row.FUN_1407cba60("binding", m_binder.FUN_140d43310(rewards[0].m_itemId, rewards[0].m_count, rewards[0].m_job));
            if (1 < rewards.GetCount())
                row.FUN_1407cba60("binding2", m_binder.FUN_140d43310(rewards[1].m_itemId, rewards[1].m_count, rewards[1].m_job));
            spList->FUN_1422dd230(row);
        }
        spList->vfunc_24(true);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caafe0-0x142cab070 .text$yd
