// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEventWidgetDialog and its two widgets, UILevelUpPackageWidgetDialog
// and UIBurningEventWidgetDialog, with the glue of their lists / maps. See uileveluppackagewidgetdialog.h. w345.
// MS2-UNIT: ?\uileveluppackagewidgetdialog.cpp
// MS2-RANGE: 0x140c58d30-0x140c5d230 .text$mn
// MS2-RANGE: 0x1400cdd10-0x1400ce050 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$CAtlArray@PEAVUIEventWidgetDialog@@V?$CElementTraits@PEAVUIEventWidgetDialog@@@ATL@@@ATL@@QEAA@XZ 0x140c5b440 ; probe
// MS2-PIN: ??__Es_keyInputController@@YAXXZ 0x1400ce020 ; prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@1@@Z 0x140c5b2d0 ; prop
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VBurningLevelupContext@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@1@@Z 0x140c5b310 ; prop
// MS2-PIN: ??8?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140c5b720 ; unique
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140c5b760 ; unique
// MS2-PIN: ??_EUIBurningEventWidgetDialog@@WBII@EAAPEAXI@Z 0x140c5b840 ; unique
// MS2-PIN: ??_EUILevelUpPackageWidgetDialog@@WBII@EAAPEAXI@Z 0x140c5b84c ; unique
// MS2-PIN: ?vfunc_84@UIEventWidgetDialog@@UEAAHXZ 0x140c5baa0 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@GV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140c5bcd0 ; prop
// MS2-PIN: ?GetPrev@?$CRBTree@GV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140c5bd10 ; prop
// MS2-PIN: ?vfunc_48@UIBurningEventWidgetDialog@@UEAAHXZ 0x140c5bd50 ; unique
// MS2-PIN: ?vfunc_48@UIEventWidgetDialog@@UEAAHXZ 0x140c5bd60 ; unique
// MS2-PIN: ?vfunc_48@UILevelUpPackageWidgetDialog@@UEAAHXZ 0x140c5bd70 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@GV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAPEAU__POSITION@@GAEBV?$MS2Ptr@VCQuestData@@@@@Z 0x140c5cab0 ; unique
// MS2-PIN: ?Successor@?$CRBTree@GV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140c5cb90 ; unique
// MS2-PIN: ?begin@?$list@V?$MS2Ptr@VBurningLevelupContext@@@@V?$allocator@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@2@XZ 0x140c5cf40 ; unique
// MS2-PIN: ?end@?$list@V?$MS2Ptr@VBurningLevelupContext@@@@V?$allocator@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@2@XZ 0x140c5d0b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uieventwidgetdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uileveluppackagewidgetdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <list>

// ---- statics (init order: the widget list, the header statics, a second copy of them, the key controller) ----

static ATL::CAtlArray<UIEventWidgetDialog*> s_widgets;                  // 0x143abee78

#include "ms2/placeholder/header_statics_a.h"
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static UICommon::CMyPCKeyInputController s_keyInputController;

// ---- unit-local views of exe types ----

// The movie root of the widget: Invoke("setData", object).
class Unk_EwRoot : public AScript { public:
    Scaleform::GFx::Value FUN_140ba4cc0(const char*, const ASObj&);
};
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
bool FUN_140a467d0(const MS2Ptr<AScript>* p);                           // the movie root is gone

// The widget's movie root as an ASDialog (RTTI .?AVASDialog@@).
class ASDialog : public ASDisplayObjectContainer {
public:
    float FUN_1422c10a0();                                              // x
    float FUN_1422c1110();                                              // y
    int FUN_1422c1500();                                                // width
    int FUN_1422c1530();                                                // height
private:
    void* m_unrecovered_80;
};
MS2_CHECK_SIZE(ASDialog, 0x88);

// the local player: slot 78 is the level
void* FUN_1403ed2d0();                                                  // the world service
void* FUN_141bd0cc0(void* pWorld);                                      // its local player
typedef unsigned short (*Unk_EwLevelFn)(void*);
#define Unk_EwActorLevel(pActor) reinterpret_cast<Unk_EwLevelFn>((*reinterpret_cast<void***>(pActor))[78])(pActor)
class Unk_EwSelf { public: int FUN_141654700(); __int64 FUN_141656a80(); };      // the job; the burning key of the player
#define Unk_EwBurningKey(pSelf) ((__int64)static_cast<Unk_EwSelf*>(pSelf)->FUN_141656a80())

// listener registries
UIQuestEventDispatcher* FUN_140bfc4b0();
class Unk_LgStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener*); void FUN_141b0cd90(UIStatusEventListener*); };
Unk_LgStatusMgr* FUN_140aa6d40();

// quests
CQuestManager* FUN_140764020();
QuestDataTable* FUN_1407476c0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b030(CQuestData* pData);                                   // the quest id
int FUN_140748050(void* pItem, int nJob);                               // the reward item suits the job
#define EwQuestLevel(pData) ((unsigned short)(pData)->m_conditions[0]->m_target.GetFirstValue())

// strings and packets
CStringW FUN_14028b8e0(const CStringW& strKey);
void FUN_140710590(COutPacket& packet);
class Unk_LgUIMgr { public: void FUN_141adc530(int nUiId); };
Unk_LgUIMgr* FUN_1403ed2b0();

// the burning level-up event values
void* FUN_140302b00();                                                  // CGameEventValueManager
CGameEventValueBurningLevelup* FUN_1403ed080(void* pManager);           // its burning level-up values
bool FUN_140c0e9f0(const std::vector<ItemEntity>* pItems);              // empty

// the event tables (0x143ab2fc0): (kind, event id) -> value; the key / iterator / map / entry views are those of the attend table
struct Unk_AttendKey
{
    Unk_AttendKey(int nRow, int nId);                       // 0x14041eee0
    int m_nRow;
    int m_nId;
};
class Unk_AttendValue;
class Unk_AttendIter                                        // 24 bytes; ctor 0x140420170, dtor 0x140420290
{
public:
    Unk_AttendIter();
    ~Unk_AttendIter();
    Unk_AttendValue* FUN_140420460();                       // the entry
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
};
MS2_CHECK_SIZE(Unk_AttendIter, 0x18);
class Unk_AttendMap { public: bool FUN_140420bb0(const Unk_AttendKey& key, Unk_AttendIter& it); };
__int64 FUN_140869440();                                    // the server time
unsigned __int64 FUN_140718370(const CStringW& strValue);   // _wtoi64
class Unk_AttendValue
{
public:
    __int64 FUN_140c5afd0(const __int64& nDefault) const;   // the value while it has not expired, else the default
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
    void* m_pad_18;
    CStringW m_strValue;                                    // +0x20 the stored text
    CMsTime m_expire;                                       // +0x28 the expiry
};
MS2_CHECK_OFFSET(Unk_AttendValue, m_strValue, 0x20);
MS2_CHECK_OFFSET(Unk_AttendValue, m_expire, 0x28);
class Unk_AttendTable
{
public:
    __int64 FUN_140c5af20(int nRow, unsigned nEventId, const __int64& nDefault);
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
    Unk_AttendMap m_map;                                    // +0x18
};
extern Unk_AttendTable g_attendTable;                       // 0x143ab2fc0
class Unk_DTTable { public: __int64 FUN_140be8f80(int nKind, unsigned nId, const __int64& nDefault); };
#define g_attendTableDT (*reinterpret_cast<Unk_DTTable*>(&g_attendTable))

class Unk_MyPCBurningEvent : public CPtred {};

// @0x140c58d30
UIEventWidgetDialog::UIEventWidgetDialog()
{
    FUN_141925e70(0, 1);
    m_178 = 0;
    UIEventWidgetDialog* pThis = this;
    s_widgets.Add(pThis);
}

// @0x140c58de0
UIEventWidgetDialog::~UIEventWidgetDialog()
{
    m_178 = 0;
}

// @0x140c58e60
CString UIEventWidgetDialog::vfunc_1()
{
    return "EventWidgetDialog";
}
MS2_REPLACE_METHOD(0x140C58E60, UIEventWidgetDialog, vfunc_1, 61, 0xD4D6FE06);

// @0x140c58eb0
CString UIEventWidgetDialog::vfunc_7()
{
    return "EventWidgetDialog";
}
MS2_REPLACE_METHOD(0x140C58EB0, UIEventWidgetDialog, vfunc_7, 61, 0x1DC2B55E);

// MS2-FUNCTIONAL: the exe returns a bool (x != 0 without a stack temp) from a slot the base declares int
// @0x140c58f00
int UIEventWidgetDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}
MS2_REPLACE_METHOD(0x140C58F00, UIEventWidgetDialog, vfunc_65, 37, 0x170ACFCB);

// @0x140c58f30
void UIEventWidgetDialog::vfunc_67()
{
    if (m_178.get())
        m_178->FUN_140d43990();
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140C58F30, UIEventWidgetDialog, vfunc_67, 75, 0x91098C16);

// @0x140c58f90
void UIEventWidgetDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140c59210();
}
MS2_REPLACE_METHOD(0x140C58F90, UIEventWidgetDialog, OnLoadComplete, 34, 0xF2D99F3E);

// MS2-FUNCTIONAL: branch layout differs from the exe (same calls and conditions)
// @0x140c58fc0
int UIEventWidgetDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onClickReward") == 0) {
        vfunc_86();
        return 1;
    }
    if (_stricmp(szMethod, "onOpenUI") == 0) {
        vfunc_87();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C58FC0, UIEventWidgetDialog, vfunc_28, 161, 0x1923AD3C);

// MS2-FUNCTIONAL: float compare / branch layout differs from the exe (same conditions)
// @0x140c59070
void UIEventWidgetDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (!pDialog)
        return;
    bool bReset = false;
    bool bFixed = m_60 == 0 && m_78 != 0 && vfunc_52() != 0;
    if (!bFixed)
        bReset = true;
    else if (!((float)pDialog->FUN_1422c10a0() <= (float)pDialog->FUN_1422c1500()
               && (float)pDialog->FUN_1422c1110() <= (float)pDialog->FUN_1422c1530()
               && 0.0f <= pDialog->FUN_1422c10a0() && 0.0f <= pDialog->FUN_1422c1110()))
        bReset = true;
    if (bReset) {
        ASDialog* pRoot = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pRoot)
            pRoot->vfunc_2(5, 0, 0x3c);
    }
}
MS2_REPLACE_METHOD(0x140C59070, UIEventWidgetDialog, vfunc_43, 396, 0x1C3E6B57);

// @0x140c59210
void UIEventWidgetDialog::FUN_140c59210()
{
    if (FUN_140a467d0(&m_30))
        return;
    ASObj data(2);
    if (!vfunc_85(data)) {
        vfunc_67();
        return;
    }
    static_cast<Unk_EwRoot*>(FUN_1409ee290(&m_30))->FUN_140ba4cc0("setData", data);
}
MS2_REPLACE_METHOD(0x140C59210, UIEventWidgetDialog, FUN_140c59210, 215, 0x3AAA625C);

// @0x140c592f0
int UIEventWidgetDialog::vfunc_85(ASObj& rObj)
{
    if (m_178.get())
        m_178->FUN_140d43990();
    return 1;
}
MS2_REPLACE_METHOD(0x140C592F0, UIEventWidgetDialog, vfunc_85, 75, 0xAFAF7C15);

// @0x140c59350
void UIEventWidgetDialog::FUN_140c59350()
{
    for (size_t i = 0; i < s_widgets.GetCount(); i++) {
        UIEventWidgetDialog* pDialog = s_widgets[i];
        if (pDialog && pDialog->vfunc_84())
            pDialog->FUN_141924680();
    }
}

// @0x140c593d0
UILevelUpPackageWidgetDialog::UILevelUpPackageWidgetDialog()
{
    m_198 = 0;
    m_178.AssignRaw(new ItemSlotBinder("LevelUpPackageWidget"));
}

// @0x140c59500
UILevelUpPackageWidgetDialog::~UILevelUpPackageWidgetDialog()
{
}

// @0x140c59590
CString UILevelUpPackageWidgetDialog::vfunc_1()
{
    return "LevelUpPackageWidget";
}
MS2_REPLACE_METHOD(0x140C59590, UILevelUpPackageWidgetDialog, vfunc_1, 61, 0x8CCC10F8);

// @0x140c595e0
int UILevelUpPackageWidgetDialog::vfunc_65()
{
    if (!UIEventWidgetDialog::vfunc_65())
        return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(static_cast<UIQuestEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x140C595E0, UILevelUpPackageWidgetDialog, vfunc_65, 143, 0x7328784C);

// @0x140c59680
void UILevelUpPackageWidgetDialog::vfunc_67()
{
    FUN_140bfc4b0()->FUN_141aa8850(static_cast<UIQuestEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIEventWidgetDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140C59680, UILevelUpPackageWidgetDialog, vfunc_67, 130, 0x45BE8DFA);

// @0x140c59710
void UILevelUpPackageWidgetDialog::vfunc_oa0_9(unsigned short nLevel)
{
    FUN_140c59210();
}

// MS2-FUNCTIONAL: the exe tests the quest pointer through the MS2Ptr helpers; the frame and EH states differ
// @0x140c59740
void UILevelUpPackageWidgetDialog::vfunc_o178_8(void* pQuest)
{
    if (!pQuest)
        return;
    MS2Ptr<CQuestData> spData = static_cast<CQuest*>(pQuest)->GetData();
    if (spData.get() == 0)
        return;
    if (spData->m_338.m_value == 1)
        FUN_140c59210();
}

// MS2-FUNCTIONAL: the exe returns a bool (x != 0 without a stack temp) from a slot the base declares int
// @0x140c597f0
int UILevelUpPackageWidgetDialog::vfunc_84()
{
    Unk_DcLevelRange range;
    return FUN_140c59bd0(range) != 0;
}
MS2_REPLACE_METHOD(0x140C597F0, UILevelUpPackageWidgetDialog, vfunc_84, 52, 0x9BB9FC0B);

// MS2-FUNCTIONAL: stack layout and temporaries differ from the exe (same calls and conditions)
// @0x140c59830
int UILevelUpPackageWidgetDialog::vfunc_85(ASObj& rObj)
{
    UIEventWidgetDialog::vfunc_85(rObj);
    void* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pSelf)
        return 0;
    Unk_DcLevelRange range;
    m_198 = FUN_140c59bd0(range);
    if (m_198 == 0)
        return 0;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(m_198);
    if (spData.get() == 0)
        return 0;
    CQuestData::QuestRewardItem* pReward = 0;
    for (size_t i = 0; i < spData->m_complete.m_choiceRewards.GetCount(); i++) {
        CQuestData::QuestRewardItem& item = spData->m_complete.m_choiceRewards[i];
        if (item.m_itemId != 0 && FUN_140748050(&item, static_cast<Unk_EwSelf*>(pSelf)->FUN_141654700()) != 0)
            pReward = &spData->m_complete.m_choiceRewards[i];
    }
    rObj.FUN_1409c0dc0("title", "$s_levelup_package_widget");
    rObj.FUN_1407cba60("binding", m_178->FUN_140d43310(pReward->m_itemId, pReward->m_count, pReward->m_job));
    rObj.FUN_1407cb9c0("max", (unsigned)range.m_nHigh - (unsigned)range.m_nLow);
    unsigned short nLevel = Unk_EwActorLevel(pSelf);
    rObj.FUN_1407cb9c0("current", (unsigned)nLevel - (unsigned)range.m_nLow);
    unsigned short nCurrent = Unk_EwActorLevel(pSelf);
    rObj.FUN_1407cbb20("text", StringFormat(L"{0}/{1}", nCurrent, range.m_nHigh));
    return 1;
}
MS2_REPLACE_METHOD(0x140C59830, UILevelUpPackageWidgetDialog, vfunc_85, 750, 0x2AB8BFF8);

// @0x140c59b30
void UILevelUpPackageWidgetDialog::vfunc_86()
{
    COutPacket packet(0x29, 0);
    packet.Encode1(0x18);
    packet.Encode4(m_198);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C59B30, UILevelUpPackageWidgetDialog, vfunc_86, 96, 0xC9ABCA2A);

// @0x140c59ba0
void UILevelUpPackageWidgetDialog::vfunc_87()
{
    FUN_1403ed2b0()->FUN_141adc530(0x4efa);
}
MS2_REPLACE_METHOD(0x140C59BA0, UILevelUpPackageWidgetDialog, vfunc_87, 32, 0x2A2706CB);

// MS2-FUNCTIONAL: stack layout and temporaries differ from the exe (same calls and conditions)
// @0x140c59bd0
int UILevelUpPackageWidgetDialog::FUN_140c59bd0(Unk_DcLevelRange& rRange)
{
    void* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pSelf)
        return 0;
    unsigned short nLevel = Unk_EwActorLevel(pSelf);
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    FUN_1407476c0()->FUN_14074cca0(quests, 1);
    ATL::CRBMap<unsigned short, MS2Ptr<CQuestData> > byLevel(10);
    for (size_t i = 0; i < quests.GetCount(); i++) {
        MS2Ptr<CQuestData> spData = quests[i];
        byLevel.SetAt(EwQuestLevel(spData.get()), spData);
    }
    POSITION posFound = 0;
    POSITION pos = byLevel.GetHeadPosition();
    while (pos) {
        unsigned short nKey = byLevel.GetKeyAt(pos);
        MS2Ptr<CQuestData> spData = byLevel.GetValueAt(pos);
        if (nLevel < nKey) {
            posFound = pos;
            break;
        }
        if (FUN_140764020()->FUN_140745590(FUN_14074b030(spData.get())) == 0) {
            posFound = pos;
            break;
        }
        byLevel.GetNext(pos);
    }
    if (posFound == 0)
        return 0;
    MS2Ptr<CQuestData> spFound = byLevel.GetValueAt(posFound);
    rRange.m_nHigh = byLevel.GetKeyAt(posFound);
    byLevel.GetPrev(posFound);
    if (posFound)
        rRange.m_nLow = byLevel.GetKeyAt(posFound);
    return FUN_14074b030(spFound.get());
}
MS2_REPLACE_METHOD(0x140C59BD0, UILevelUpPackageWidgetDialog, FUN_140c59bd0, 812, 0xE629CD1A);

// @0x140c59f10
UIBurningEventWidgetDialog::UIBurningEventWidgetDialog() : m_190(0), m_198(0)
{
    m_178.AssignRaw(new ItemSlotBinder("BurningEventWidget"));
}

// @0x140c5a030
UIBurningEventWidgetDialog::~UIBurningEventWidgetDialog()
{
}

// @0x140c5a0b0
CString UIBurningEventWidgetDialog::vfunc_1()
{
    return "BurningEventWidget";
}
MS2_REPLACE_METHOD(0x140C5A0B0, UIBurningEventWidgetDialog, vfunc_1, 61, 0x284A95D7);

// @0x140c5a100
void UIBurningEventWidgetDialog::FUN_140c5a100(void* pEvent)
{
    FUN_140c59210();
}

// @0x140c5a130
int UIBurningEventWidgetDialog::vfunc_65()
{
    if (!UIEventWidgetDialog::vfunc_65())
        return 0;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x140C5A130, UIBurningEventWidgetDialog, vfunc_65, 90, 0xAAA1CD5C);

// @0x140c5a190
void UIBurningEventWidgetDialog::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIEventWidgetDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140C5A190, UIBurningEventWidgetDialog, vfunc_67, 77, 0x5FA855AE);

// @0x140c5a1f0
void UIBurningEventWidgetDialog::vfunc_oa0_9(unsigned short nLevel)
{
    FUN_140c59210();
}

// MS2-FUNCTIONAL: stack layout and temporaries differ from the exe (same calls and conditions)
// @0x140c5a220
int UIBurningEventWidgetDialog::vfunc_84()
{
    void* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pSelf)
        return 0;
    std::list<MS2Ptr<BurningLevelupContext> > contexts;
    FUN_1403ed080(FUN_140302b00())->GetAll(contexts);
    for (std::list<MS2Ptr<BurningLevelupContext> >::iterator it = contexts.begin(); it != contexts.end(); ++it) {
        MS2Ptr<BurningLevelupContext> spContext = *it;
        if (spContext.get() == 0)
            continue;
        if (FUN_140c0e9f0(&spContext->m_rewardItems))
            continue;
        __int64 nDefault = 0;
        if (g_attendTableDT.FUN_140be8f80(0x7d2, spContext->m_eventId, nDefault) != 0)
            continue;
        nDefault = 0;
        if (g_attendTable.FUN_140c5af20(2000, spContext->m_eventId, nDefault) == Unk_EwBurningKey(pSelf))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C5A220, UIBurningEventWidgetDialog, vfunc_84, 490, 0x6EACB528);

// MS2-FUNCTIONAL: stack layout and temporaries differ from the exe (same calls and conditions)
// @0x140c5a420
int UIBurningEventWidgetDialog::vfunc_85(ASObj& rObj)
{
    UIEventWidgetDialog::vfunc_85(rObj);
    void* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pSelf)
        return 0;
    std::list<MS2Ptr<BurningLevelupContext> > contexts;
    FUN_1403ed080(FUN_140302b00())->GetAll(contexts);
    MS2Ptr<BurningLevelupContext> spResult(0);
    for (std::list<MS2Ptr<BurningLevelupContext> >::iterator it = contexts.begin(); it != contexts.end(); ++it) {
        MS2Ptr<BurningLevelupContext> spContext = *it;
        if (spContext.get() == 0)
            continue;
        if (FUN_140c0e9f0(&spContext->m_rewardItems)) {
            spResult = *it;
            continue;
        }
        __int64 nDefault = 0;
        if (g_attendTable.FUN_140c5af20(2000, spContext->m_eventId, nDefault) != Unk_EwBurningKey(pSelf))
            continue;
        nDefault = 0;
        if (g_attendTableDT.FUN_140be8f80(0x7d2, spContext->m_eventId, nDefault) == 0) {
            spResult = spContext;
            break;
        }
    }
    if (spResult.get() == 0)
        return 0;
    m_190 = spResult->m_eventId;
    rObj.FUN_1407cbb20("title", FUN_14028b8e0(spResult->m_rewardUiTitleStringKey));
    ItemEntity& item = spResult->m_rewardItems.front();
    rObj.FUN_1407cba60("binding", m_178->FUN_140d43310(item.m_itemId, item.vfunc_o18_1(), item.m_count));
    rObj.FUN_1409c48f0("max", spResult->m_endLevel);
    rObj.FUN_1409c48f0("current", Unk_EwActorLevel(pSelf));
    unsigned short nCurrent = Unk_EwActorLevel(pSelf);
    rObj.FUN_1407cbb20("text", StringFormat(L"{0}/{1}", nCurrent, spResult->m_endLevel));
    return 1;
}
MS2_REPLACE_METHOD(0x140C5A420, UIBurningEventWidgetDialog, vfunc_85, 1261, 0x598DDAF2);

// MS2-FUNCTIONAL: stack layout and temporaries differ from the exe (same calls and conditions)
// @0x140c5a930
void UIBurningEventWidgetDialog::vfunc_86()
{
    void* pSelf = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!pSelf)
        return;
    MS2Ptr<BurningLevelupContext> spContext = FUN_1403ed080(FUN_140302b00())->Get(m_190);
    if (spContext.get() == 0)
        return;
    if (FUN_140c0e9f0(&spContext->m_rewardItems))
        return;
    __int64 nDefault = 0;
    if (g_attendTable.FUN_140c5af20(2000, spContext->m_eventId, nDefault) != Unk_EwBurningKey(pSelf))
        return;
    nDefault = 0;
    if (g_attendTableDT.FUN_140be8f80(0x7d1, spContext->m_eventId, nDefault) == 0)
        return;
    nDefault = 0;
    if (g_attendTableDT.FUN_140be8f80(0x7d2, spContext->m_eventId, nDefault) != 0)
        return;
    COutPacket packet(0x97, 0);
    packet.Encode1(0xf);
    packet.Encode4(spContext->m_eventId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C5A930, UIBurningEventWidgetDialog, vfunc_86, 491, 0xA7113577);

// @0x140c5ab30
void UIBurningEventWidgetDialog::FUN_140c5ab30(MS2Ptr<Unk_MyPCBurningEvent> spEvent)
{
    m_198 = spEvent;
}
MS2_REPLACE_METHOD(0x140C5AB30, UIBurningEventWidgetDialog, FUN_140c5ab30, 63, 0x73AD55D6);

// @0x140c5ab80
MS2Ptr<Unk_MyPCBurningEvent> UIBurningEventWidgetDialog::FUN_140c5ab80()
{
    return m_198;
}
MS2_REPLACE_METHOD(0x140C5AB80, UIBurningEventWidgetDialog, FUN_140c5ab80, 67, 0x353C2547);

// MS2-FUNCTIONAL: frame size and temporaries differ from the exe (same calls and conditions)
// @0x140c5af20
__int64 Unk_AttendTable::FUN_140c5af20(int nRow, unsigned nEventId, const __int64& nDefault)
{
    Unk_AttendKey key(nRow, nEventId);
    Unk_AttendIter it;
    if (m_map.FUN_140420bb0(key, it))
        return it.FUN_140420460()->FUN_140c5afd0(nDefault);
    return nDefault;
}

// @0x140c5afd0
__int64 Unk_AttendValue::FUN_140c5afd0(const __int64& nDefault) const
{
    CMsTime now(FUN_140869440());
    if (m_expire <= now)
        return nDefault;
    return FUN_140718370(m_strValue);
}

// @0x140c5c510
void UIEventWidgetDialog::vfunc_87()
{
}

// @0x140c5c520
void UIEventWidgetDialog::vfunc_86()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3090-0x142ca31f0 .text$yd
