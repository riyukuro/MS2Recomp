// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UILevelUpGuideDialog (the level-up guide window) and the
// glue of its contents table (CRBMap / vector / sort) and message box callback. See uilevelupguidedialog.h. w335.
// MS2-UNIT: ?\uilevelupguidedialog.cpp
// MS2-RANGE: 0x140f84310-0x140f8c480 .text$mn
// MS2-RANGE: 0x1400e0c00-0x1400e0d70 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e0cc0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e0cf0 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400e0d20 ; unique
// MS2-PIN: ?vfunc_48@UILevelUpGuideDialog@@UEAAHXZ 0x140f8abc0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@HV?$MS2Ptr@VRecommendContnets@UILevelUpGuideDialog@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VRecommendContnets@UILevelUpGuideDialog@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VRecommendContnets@UILevelUpGuideDialog@@@@@Z 0x140f8b750 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUILevelUpGuideDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f8c1b0 ; unique
// MS2-PIN: ??$Call@VUILevelUpGuideDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUILevelUpGuideDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUILevelUpGuideDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f8c1f0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uilevelupguidedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uilevelupguidedialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>

// ---- unit-local views of exe types ----

// The list control of the movie (the AS list with clear / append).
class Unk_LgList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422cf4f0(int n);
};
class Unk_LgCheck : public ASDisplayObject
{
public:
    bool FUN_1422ce0e0();                                       // is checked
    void FUN_1422ce090(int bChecked);                           // set checked
};
// the event dialog child (m_eventDialog): a display object with the same Invoke targets as the movie root
class Unk_LgEvent : public ASDisplayObject {};
// the movie root: Invoke("setPC", level) and the child lookup of the event dialog
class Unk_LgRoot : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ea5e70(const char* szMethod, unsigned short a1);
    template <class T> MS2Ptr<T> FUN_140e44410(const CString& strName);
};
#define LG_ROOT(p) static_cast<Unk_LgRoot*>((p).operator->())

// the local player: slot 78 is the level
class Unk_LgPlayer;
void* FUN_1403ed2d0();                                          // the world service
void* FUN_141bd0cc0(void* pWorld);                              // its local player
typedef unsigned short (*Unk_LgLevelFn)(void*);
#define Unk_LgActorLevel(pActor) reinterpret_cast<Unk_LgLevelFn>((*reinterpret_cast<void***>(pActor))[78])(pActor)
class Unk_LgSelf { public: int FUN_141654700(); };               // the job of the player

// listener registries
UIQuestEventDispatcher* FUN_140bfc4b0();
class Unk_LgStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener*); void FUN_141b0cd90(UIStatusEventListener*); };
Unk_LgStatusMgr* FUN_140aa6d40();

// items bound to the slots of the rewards
void FUN_141415600(const CString& strBindID);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);

// quests
CQuestManager* FUN_140764020();
QuestDataTable* FUN_1407476c0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_140748050(void* pItem, int nJob);                       // the reward item suits the job

// strings
class Unk_LgStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_LgStrings* FUN_1401a9d70();
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_1409e8820(CStringW strKey, const short& a1);
CStringW FUN_140ec2f00(CStringW strKey, const short& a1, const short& a2);
CStringW FUN_1409e9ed0(CStringW strKey, const CStringW& a1, const unsigned short& a2);
CStringW FUN_1401aa6a0(int nId);                                // npc name
int FUN_140841300(const CString& str, const char* sz);

// message boxes and packets
MS2Ptr<CMsgBoxData> FUN_140d73d20(int type, CStringW text, void* listener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140710590(COutPacket& packet);

// npcs and the boss tooltip
class Unk_LgNpc : public CPtred {};
MS2Ptr<Unk_LgNpc> FUN_1406cd330(int nNpcId);
unsigned short FUN_1406cd060(Unk_LgNpc* p);                     // npc level
class Unk_LgBossTip { public: void FUN_141b99dc0(int nNpcId, ASTooltip* pTip); };
Unk_LgBossTip* FUN_140cb17d0();

// opening the dialogs of a row
class Unk_LgUIMgr
{
public:
    void FUN_141adc530(int nUiId);
    void FUN_141adc690(int nUiId);
};
Unk_LgUIMgr* FUN_1403ed2b0();
class Unk_LgRoomDlg { public: void FUN_1412b8ff0(int nId); };
Unk_LgRoomDlg* FUN_140961550(int nUiId);
class Unk_LgWorldMap : public UIDialog
{
public:
    void FUN_141b5bc70(int nCode);
    void FUN_141b5bcc0(CStringW strText);
};
Unk_LgWorldMap* FUN_140961730(int nUiId);
class Unk_LgFieldMeta { public: int FUN_1406fb700(unsigned nId, unsigned* pOut); };
Unk_LgFieldMeta* FUN_140700390();
class Unk_CommandUIRef
{
public:
    ~Unk_CommandUIRef();
    UIObject* FUN_1403e8a70() const;
private:
    void* m_unk;
    UIObject* m_object;
};
MS2_CHECK_SIZE(Unk_CommandUIRef, 0x10);
struct Unk_LgUiMgr { Unk_CommandUIRef FUN_141adcf50(const CString& strName); };
UIObject* FUN_1403ed9e0(Unk_CommandUIRef& ref);

// recommendContents.xml
CString FUN_14071a5b0(const CString&, const CString&);
struct Unk_LgFiles { int FUN_1403974b0(TiXmlDocument&, const char*, int, bool, bool); };
Unk_LgFiles* FUN_140166420();
struct Unk_LgLog { void FUN_14015eb90(int, int, const wchar_t*, const CString&); };
Unk_LgLog* FUN_140166440();
void* FUN_140165cf0(void*, const char*);
void* FUN_140168650(void*, const char*);
bool FUN_14028f710(void*);
int FUN_1408731e0(void*, const char*, int&);
int FUN_1408731a0(void*, const char*, unsigned short&);
int FUN_140873ad0(void*, const char*, CString&);

// the root of the movie
bool FUN_140a467d0(const MS2Ptr<AScript>* pAS);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);

typedef Delegate<bool(int, const CMsgBoxData&)> LgAnswerDelegate;

// the quest level (first target value of its first condition)
#define LgQuestLevel(pData) ((unsigned short)(pData)->m_conditions[0]->m_target.GetFirstValue())

static int LgQuestOrder(const void* pA, const void* pB);
static bool LgRowOrder(MS2Ptr<UILevelUpGuideDialog::RecommendContnets> spA, MS2Ptr<UILevelUpGuideDialog::RecommendContnets> spB);

// ---- RecommendContnets ----

// @0x140f8a590
UILevelUpGuideDialog::RecommendContnets::RecommendContnets()
{
    m_id = 0;
    m_code = 0;
    m_sorting = 0x7fffffff;
    m_minLevel = 0;
    m_maxLevel = 0;
}

// @0x140f8a790
UILevelUpGuideDialog::RecommendContnets::~RecommendContnets() {}

// ---- UILevelUpGuideDialog ----

// @0x140f84310
UILevelUpGuideDialog::UILevelUpGuideDialog() : m_1e0(10)
{
    FUN_141924170(1);
    FUN_140f85ba0();
    m_1cc[0] = 1;
    m_1cc[1] = 1;
    m_1cc[2] = 1;
}

// @0x140f84450
UILevelUpGuideDialog::~UILevelUpGuideDialog() {}

// @0x140f84520
CString UILevelUpGuideDialog::vfunc_1() { return "LevelUpGuideDialog"; }

// @0x140f84570
int UILevelUpGuideDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140f84610
void UILevelUpGuideDialog::vfunc_67()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    for (size_t i = 0; i < m_1a8.GetCount(); i++)
        FUN_141415600(m_1a8.GetAt(i));
    MS2Ptr<Unk_LgCheck> spEtc = FUN_140e52670("m_contentsEtc");
    m_1cc[0] = spEtc->FUN_1422ce0e0();
    MS2Ptr<Unk_LgCheck> spBoss = FUN_140e52670("m_contentsBoss");
    m_1cc[1] = spBoss->FUN_1422ce0e0();
    MS2Ptr<Unk_LgCheck> spDungeon = FUN_140e52670("m_contentsDungeon");
    m_1cc[2] = spDungeon->FUN_1422ce0e0();
    UIDialog::vfunc_67();
}

// @0x140f84900
void UILevelUpGuideDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    FUN_140f85330(Unk_LgActorLevel(pPlayer));
    MS2Ptr<Unk_LgCheck> spEtc = FUN_140e52670("m_contentsEtc");
    spEtc->FUN_1422ce090(m_1cc[0]);
    MS2Ptr<Unk_LgCheck> spBoss = FUN_140e52670("m_contentsBoss");
    spBoss->FUN_1422ce090(m_1cc[1]);
    MS2Ptr<Unk_LgCheck> spDungeon = FUN_140e52670("m_contentsDungeon");
    spDungeon->FUN_1422ce090(m_1cc[2]);
    FUN_140f85f90();
    FUN_140f861c0();
    FUN_140f869f0();
}

// @0x140f84bb0
int UILevelUpGuideDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140f857e0(data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onClickContents") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140f854b0(data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onContentsFilter") == 0) {
        FUN_140f861c0();
    }
    else if (_stricmp(szMethod, "onLevelSelect") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            FUN_140f87af0((unsigned short)data.FUN_1422b8b10());
            FUN_140f861c0();
        }
    }
    return 0;
}

// @0x140f84dc0
void UILevelUpGuideDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CString strType = pArgs->FUN_1422b8d30();
    if (FUN_140841300(strType, "contents") != 0)
        return;
    int nId = pArgs->FUN_1422b8b10();
    MS2Ptr<RecommendContnets> spRow;
    if (!m_1e0.Lookup(nId, spRow))
        return;
    if (spRow->m_kind == 0)
        FUN_140f878e0(spRow, pRetVal);
    else if (spRow->m_kind == 1)
        FUN_140f876b0(spRow, pRetVal);
}

// @0x140f84f30 a quest was updated
void UILevelUpGuideDialog::vfunc_o178_8(void* pQuestRaw)
{
    CQuest* pQuest = static_cast<CQuest*>(pQuestRaw);
    MS2Ptr<CQuestData> spData = pQuest->GetData();
    if (spData.get() == 0)
        return;
    if (spData->m_338.m_value == 1) {
        ASObj obj(2);
        FUN_140f86dd0(obj, pQuest->FUN_140bfc580());
        m_30->Invoke("addLevelGuide", obj);
    }
    else if (spData->m_338.m_value == 2) {
        MS2Ptr<Unk_LgEvent> spEvent = FUN_140f880c0("m_eventDialog");
        if (spEvent.get() == 0)
            return;
        ASObj obj(2);
        obj.FUN_1409c0d20("disableEvent", 1);
        FUN_140f86dd0(obj, pQuest->FUN_140bfc580());
        spEvent->Invoke("addLevelGuide", obj);
    }
}

// @0x140f851f0 level changed
void UILevelUpGuideDialog::vfunc_oa0_9(unsigned short nLevel)
{
    if (m_30.IsNull())
        return;
    LG_ROOT(m_30)->FUN_140ea5e70("setPC", nLevel);
    FUN_140f87af0(nLevel);
    FUN_140f861c0();
}

// @0x140f85290
bool UILevelUpGuideDialog::FUN_140f85290(int nResult, const CMsgBoxData& rBox)
{
    if (nResult == 0) {
        unsigned nQuest = rBox.FUN_141a02e90(0, 0);
        COutPacket packet(0x29, 0);
        packet.vfunc_o10_1(0x18);
        packet.vfunc_o10_3(nQuest);
        FUN_140710590(packet);
    }
    return true;
}

// @0x140f85330
void UILevelUpGuideDialog::FUN_140f85330(unsigned short nLevel)
{
    m_188.RemoveAll();
    m_1d8 = 0;
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    FUN_1407476c0()->FUN_14074cca0(quests, 1);
    for (size_t i = 0; i < quests.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = quests[i];
        if (spData->m_conditions.GetCount() == 0)
            continue;
        unsigned short nQuestLevel = LgQuestLevel(spData.get());
        if (nQuestLevel > m_1d8)
            m_1d8 = nQuestLevel;
        m_188.Add(nQuestLevel);
    }
    FUN_140f87af0(nLevel);
}

// @0x140f854b0
void UILevelUpGuideDialog::FUN_140f854b0(int nId)
{
    MS2Ptr<RecommendContnets> spRow;
    if (!m_1e0.Lookup(nId, spRow))
        return;
    if (spRow->m_link.IsEmpty())
        return;
    if (spRow->m_link == "DungeonRoomDialog") {
        Unk_LgRoomDlg* pDialog = FUN_140961550(0x4ebd);
        if (pDialog != 0) {
            FUN_1403ed2b0()->FUN_141adc690(0x4ebd);
            pDialog->FUN_1412b8ff0(spRow->m_code);
            FUN_1403ed2b0()->FUN_141adc530(0x4ebd);
        }
    }
    else if (spRow->m_link == "WorldMapDialog") {
        Unk_LgWorldMap* pDialog = FUN_140961730(0x4e42);
        if (pDialog != 0) {
            if (spRow->m_kind == 0 || spRow->m_kind == 2) {
                if (spRow->m_code != 0)
                    pDialog->FUN_141b5bc70(spRow->m_code);
                CStringW strText = FUN_1401a9d70()->FUN_141811980(0x24, spRow->m_id);
                if (!strText.IsEmpty())
                    pDialog->FUN_141b5bcc0(strText);
            }
            else {
                unsigned nField = 0;
                FUN_140700390()->FUN_1406fb700(spRow->m_code, &nField);
                pDialog->FUN_141b5bc70(nField);
            }
            pDialog->FUN_141924680();
        }
    }
    else {
        Unk_CommandUIRef ref = reinterpret_cast<Unk_LgUiMgr*>(FUN_1403ed2b0())->FUN_141adcf50(spRow->m_link);
        UIDialog* pDialog = dynamic_cast<UIDialog*>(FUN_1403ed9e0(ref));
        if (pDialog != 0)
            pDialog->FUN_141924680();
    }
}

// @0x140f857e0
void UILevelUpGuideDialog::FUN_140f857e0(int nQuest)
{
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
    if (spQuest.IsNull() || spQuest->IsComplete() == 0)
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.get() == 0)
        return;
    Unk_LgSelf* pSelf = static_cast<Unk_LgSelf*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (spData->m_338.m_value == 1 && pSelf->FUN_141654700() == 1) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028b8e0(L"s_recommend_contents_newbie_warn"), 0, L"");
        spBox->FUN_140534050(nQuest);
        spBox->FUN_141a027c0(LgAnswerDelegate(this, &UILevelUpGuideDialog::FUN_140f85290));
        FUN_140d73c60(spBox);
    }
    else {
        COutPacket packet(0x29, 0);
        packet.vfunc_o10_1(0x18);
        packet.vfunc_o10_3(nQuest);
        FUN_140710590(packet);
    }
}

// @0x140f85ba0 Table\recommendContents.xml
void UILevelUpGuideDialog::FUN_140f85ba0()
{
    CString path = FUN_14071a5b0(CString("Table"), CString("recommendContents.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(doc, path, 0, true, false) == 0)
        return;
    void* root = FUN_140165cf0(&doc, "ms2");
    if (root == 0) {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", path);
        return;
    }
    for (void* node = FUN_140165cf0(root, "contents"); node; node = FUN_140168650(node, "contents")) {
        if (!FUN_14028f710(node))
            continue;
        MS2Ptr<RecommendContnets> spRow(new RecommendContnets);
        if (spRow.get() == 0)
            continue;
        FUN_1408731e0(node, "id", spRow->m_id);
        FUN_1408731a0(node, "minLevel", spRow->m_minLevel);
        FUN_1408731a0(node, "maxLevel", spRow->m_maxLevel);
        FUN_1408731e0(node, "code", spRow->m_code);
        FUN_1408731e0(node, "sorting", spRow->m_sorting);
        FUN_140873ad0(node, "type", spRow->m_type);
        FUN_140873ad0(node, "img", spRow->m_img);
        FUN_140873ad0(node, "link", spRow->m_link);
        if (spRow->m_type == "common")
            spRow->m_kind = 0;
        else if (spRow->m_type == "boss")
            spRow->m_kind = 1;
        else if (spRow->m_type == "dungeon")
            spRow->m_kind = 2;
        m_1e0.SetAt(spRow->m_id, spRow);
    }
}

// @0x140f85f90
void UILevelUpGuideDialog::FUN_140f85f90()
{
    if (FUN_140a467d0(&m_30))
        return;
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    FUN_1407476c0()->FUN_14074cca0(quests, 1);
    qsort(quests.GetData(), quests.GetCount(), sizeof(MS2Ptr<CQuestData>), LgQuestOrder);
    for (size_t i = 0; i < quests.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = quests[i];
        if (spData->m_conditions.GetCount() == 0)
            continue;
        ASObj row(2);
        if (FUN_140f86dd0(row, spData->m_id) != 0)
            m_30->Invoke("addLevelGuide", row);
    }
    LG_ROOT(m_30)->FUN_140ea5e70("setPC", Unk_LgActorLevel(pPlayer));
}

// @0x140f861c0
void UILevelUpGuideDialog::FUN_140f861c0()
{
    MS2Ptr<ASTextField> spLevel = FUN_140bb4cf0("m_contentsLevel");
    if (spLevel.get() != 0) {
        short nLo = m_1c8.m_nLow;
        short nHi = m_1c8.m_nHigh;
        if (m_1c8.m_nLow == m_1c8.m_nHigh)
            spLevel->FUN_1422c4cd0(FUN_1409e8820(CStringW(L"s_recommend_contents_title_equal"), nLo));
        else
            spLevel->FUN_1422c4cd0(FUN_140ec2f00(CStringW(L"s_recommend_contents_title"), nLo, nHi));
    }
    MS2Ptr<Unk_LgList> spList = FUN_140ba4b70("m_contentsList");
    if (spList.get() == 0)
        return;
    spList->Invoke("resetRenderer");
    spList->FUN_1422dd1d0();
    spList->FUN_1422cf4f0(0);
    std::vector<MS2Ptr<RecommendContnets> > rows;
    POSITION pos = m_1e0.GetHeadPosition();
    while (pos != 0) {
        MS2Ptr<RecommendContnets> spRow = m_1e0.GetValueAt(pos);
        m_1e0.GetNext(pos);
        if (FUN_140f87a30(spRow) != 0)
            rows.push_back(spRow);
    }
    std::sort(rows.begin(), rows.end(), LgRowOrder);
    for (size_t i = 0; i < rows.size(); i++) {
        MS2Ptr<RecommendContnets> spRow = rows[i];
        if (spRow->m_kind == 0) {
            MS2Ptr<Unk_LgCheck> spCheck = FUN_140e52670("m_contentsEtc");
            if (!spCheck->FUN_1422ce0e0())
                continue;
        }
        else if (spRow->m_kind == 1) {
            MS2Ptr<Unk_LgCheck> spCheck = FUN_140e52670("m_contentsBoss");
            if (!spCheck->FUN_1422ce0e0())
                continue;
        }
        else if (spRow->m_kind == 2) {
            MS2Ptr<Unk_LgCheck> spCheck = FUN_140e52670("m_contentsDungeon");
            if (!spCheck->FUN_1422ce0e0())
                continue;
        }
        ASObj row(2);
        row.FUN_1409c0d20("id", spRow->m_id);
        row.FUN_1407cba60("type", spRow->m_type);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(0x23, spRow->m_id));
        row.FUN_1407cba60("imgPath", spRow->m_img);
        row.FUN_1407cbbe0("clickable", !spRow->m_link.IsEmpty());
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(true);
}

// @0x140f869f0
void UILevelUpGuideDialog::FUN_140f869f0()
{
    MS2Ptr<Unk_LgEvent> spEvent = FUN_140f880c0("m_eventDialog");
    if (spEvent.get() == 0)
        return;
    void* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    FUN_1407476c0()->FUN_14074cca0(quests, 2);
    int nAdded = 0;
    for (size_t i = 0; i < quests.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = quests[i];
        Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(spData->m_id);
        if (spQuest.IsNull())
            continue;
        if (spQuest->FUN_1407447c0() != 0)
            continue;
        int nState = spQuest->FUN_1407476d0();
        if (nState != 1 && nState != 2)
            continue;
        ASObj row(2);
        row.FUN_1409c0d20("disableEvent", 1);
        if (FUN_140f86dd0(row, spData->m_id) == 0)
            continue;
        spEvent->Invoke("addLevelGuide", row);
        nAdded++;
    }
    if (nAdded != 0) {
        static_cast<Unk_LgRoot*>(static_cast<AScript*>(spEvent.get()))->FUN_140ea5e70("setPC", Unk_LgActorLevel(pPlayer));
        spEvent->vfunc_3(1);
    }
    else
        spEvent->vfunc_3(0);
}

// @0x140f86dd0
int UILevelUpGuideDialog::FUN_140f86dd0(ASObj& rObj, int nQuest)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (spData.get() == 0 || spData->m_conditions.GetCount() == 0)
        return 0;
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuest);
    CString strState("lock");
    if (!spQuest.IsNull()) {
        if (spQuest->IsComplete() != 0)
            strState = "active";
        if (spQuest->IsRewarded() != 0)
            strState = "inactive";
    }
    unsigned short nLevel = LgQuestLevel(spData.get());
    CStringW strLevel;
    if (nLevel == m_1d8)
        strLevel = FUN_1409e8820(CStringW(L"s_recommend_contents_max_level"), (short)nLevel);
    else
        strLevel = FUN_1409e8820(CStringW(L"s_recommend_contents_level"), (short)nLevel);
    rObj.FUN_1409c0d20("id", nQuest);
    rObj.FUN_1407cba60("state", strState);
    rObj.FUN_1409c48f0("level", (short)nLevel);
    rObj.FUN_1407cbb20("levelStr", strLevel);
    FUN_140f87270(rObj, nQuest, 0);
    return 1;
}

// @0x140f87270
void UILevelUpGuideDialog::FUN_140f87270(ASObj& rObj, int nQuest, int bName)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuest);
    if (spData.get() == 0)
        return;
    if (spData->m_338.m_value < 1 || spData->m_338.m_value > 2)
        return;
    Unk_LgSelf* pSelf = static_cast<Unk_LgSelf*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (pSelf == 0)
        return;
    for (size_t i = 0; i < spData->m_complete.m_choiceRewards.GetCount(); i++) {
        CQuestData::QuestRewardItem& item = spData->m_complete.m_choiceRewards[i];
        if (item.m_itemId == 0)
            continue;
        if (FUN_140748050(&item, pSelf->FUN_141654700()) == 0)
            continue;
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_14052b130(item.m_itemId, item.m_count, 0) == 0)
            continue;
        spItem->FUN_140526c70(item.m_job);
        CString strBindID;
        strBindID.Format("%s.%d", (LPCSTR)vfunc_1(), m_1a8.GetCount() + 1);
        FUN_141415450(strBindID, spItem, 0, 0x415, 0x800);
        rObj.FUN_1407cba60("binding", strBindID);
        if (bName != 0)
            rObj.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, item.m_itemId));
        m_1a8.Add(strBindID);
        return;
    }
}

// @0x140f876b0 boss tooltip
void UILevelUpGuideDialog::FUN_140f876b0(MS2Ptr<RecommendContnets> spRow, Scaleform::GFx::Value* pRetVal)
{
    int nNpc = spRow->m_code;
    MS2Ptr<Unk_LgNpc> spNpc = FUN_1406cd330(nNpc);
    if (spNpc.get() == 0)
        return;
    ASTooltip tip(1, 2);
    FUN_140cb17d0()->FUN_141b99dc0(nNpc, &tip);
    unsigned short nLevel = FUN_1406cd060(spNpc.get());
    tip.FUN_1407cbb20("text", FUN_1409e9ed0(CStringW(L"s_recommend_contents_tooltip_boss"), FUN_1401aa6a0(nNpc), nLevel));
    tip.FUN_1409c0e60("enableLClick", L"");
    tip.FUN_1409c6d70("WorldMapTooltip_Boss");
    tip.FUN_1409c6e00(300);
    tip.FUN_1409c6e30(60000);
    tip.FUN_1409c6dc0(1);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x140f878e0 plain text tooltip
void UILevelUpGuideDialog::FUN_140f878e0(MS2Ptr<RecommendContnets> spRow, Scaleform::GFx::Value* pRetVal)
{
    CStringW strText = FUN_1401a9d70()->FUN_141811980(0x25, spRow->m_id);
    if (strText.IsEmpty())
        return;
    ASTooltip tip(1, 2);
    tip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tip.FUN_1409c6e00(300);
    tip.FUN_1409c6e30(60000);
    tip.FUN_1409c6dc0(1);
    tip.FUN_1409c6cb0(strText);
    *pRetVal = tip.FUN_1422bb870();
}

// @0x140f87a30
int UILevelUpGuideDialog::FUN_140f87a30(MS2Ptr<RecommendContnets> spRow)
{
    for (unsigned short nLevel = spRow->m_minLevel; nLevel <= spRow->m_maxLevel; nLevel++) {
        if (m_1c8.FUN_1407790e0(nLevel))
            return 1;
    }
    return 0;
}

// @0x140f87af0
void UILevelUpGuideDialog::FUN_140f87af0(unsigned short nLevel)
{
    unsigned short nLo = 1;
    unsigned short nHi = m_1d8;
    for (size_t i = 0; i < m_188.GetCount(); i++) {
        unsigned short nStep = m_188[i];
        if (nStep <= nLevel) {
            if (nStep > nLo)
                nLo = nStep;
        }
        else if (nStep < nHi)
            nHi = nStep;
    }
    m_1c8.FUN_14075bc80(nLo, nHi - 1);
    if (nLo == m_1d8)
        m_1c8.FUN_14075bc80(nLo, m_1d8);
}

// @0x140f87c80 the order of the level steps
static int LgQuestOrder(const void* pA, const void* pB)
{
    const MS2Ptr<CQuestData>& spA = *static_cast<const MS2Ptr<CQuestData>*>(pA);
    const MS2Ptr<CQuestData>& spB = *static_cast<const MS2Ptr<CQuestData>*>(pB);
    if (spA->m_conditions.GetCount() == 1) {
        if (spB->m_conditions.GetCount() == 1)
            return LgQuestLevel(spA.get()) < LgQuestLevel(spB.get()) ? -1 : 1;
        return -1;
    }
    return 1;
}

// @0x140f87e00 the order of the contents rows
static bool LgRowOrder(MS2Ptr<UILevelUpGuideDialog::RecommendContnets> spA, MS2Ptr<UILevelUpGuideDialog::RecommendContnets> spB)
{
    if (spA->m_sorting == spB->m_sorting)
        return spA->m_id < spB->m_id;
    return spA->m_sorting < spB->m_sorting;
}

// @0x140f880c0
MS2Ptr<Unk_LgEvent> UILevelUpGuideDialog::FUN_140f880c0(const CString& strName)
{
    if (!FUN_140ba28d0(&m_30, 0))
        return static_cast<Unk_LgRoot*>(FUN_1409ee290(&m_30))->FUN_140e44410<Unk_LgEvent>(strName);
    return MS2Ptr<Unk_LgEvent>(0);
}

MS2_EMIT_CRT_MEMMOVE_S();
