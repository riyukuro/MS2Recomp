// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINpcPreviewDialog: see uinpcpreviewdialog.h.
// MS2-UNIT: ?\uinpcpreviewdialog.cpp
// MS2-RANGE: 0x140119f90-0x14011a360 .text$di
// MS2-RANGE: 0x141a6e060-0x141a72480 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpcpreviewdialog.cpp"    // assumed

// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uinpcpreviewdialog.h"
#include "uidailymissiondialog.h"   // C3: UIDailyMissionDialog::FUN_140c02870 (the tab strip lookup)

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <efd/MemoryDefines.h>
#include <efd/SmartPointer.h>
#include <efd/utf8string.h>

#include "ms2/client/ms2/animationmanager.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/talkscript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/ms2format.h"   // C3: StringFormat<CStringW, CStringW> (was FUN_140656190)
#include "ms2/placeholder/asbuttonbar.h"

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- dynamic initializers of the header statics of this TU ------------------------------------------------------------
// The same header statics (a name table, the "skill" / "stun" labels, a condition object) are instantiated twice; the
// key-input controller singleton sits between the two groups.

static CString s_strNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

static UICommon::CMyPCKeyInputController s_keyInputController;

static CString s_strNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The button bar (tab strip) of the movie.

// The world: the actors of an object id, the preview npc spawn / removal and the npc tree.
class Unk_NpWorld : public WorldService
{
public:
    PCBase* FUN_141bd0cc0();                            // the local player
};
int FUN_141274aa0(class Unk_ExpActor* pObj);            // the actor filter of the collection above (getexp.cpp)
CNpc* FUN_141a71850(const efd::SmartPointer<GameObject>& spObj);

// The ui text service (singleton): the text of a "$s_..." key.
class GFxManager { public: CStringW Localize(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: the GFxManager (calls cast back)
CStringW FUN_1401aa6a0(int nNpc);                  // the name text of an npc id

// The talk window.
class UITalkManager { public: unsigned FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound); };   // uitalkmanager.h clashes with this unit's CCinematicContent

// Talk scripts.
typedef Unk_ScriptPtr<CTalkScript> TalkPtr;
typedef TPtrValue<ATL::CAtlArray<TalkPtr> > TalkArrayPtr;
TalkArrayPtr FUN_140857330(int nNpcId);                 // the select / job talks of an npc
TalkArrayPtr FUN_140857660(int nNpcId);                 // the monologues of an npc
TalkPtr FUN_140856820(int nNpcId, int nTalkId);
TalkPtr FUN_140856af0(int nNpcId, int nTalkId);
TalkPtr FUN_140856c50(int nNpcId, int nKind);
TalkPtr FUN_1408564b0(int nQuestId, int nTalkId);
namespace Common { template <class T> int FindElement(const ATL::CAtlArray<T>& arr, const T& value); }   // -1 = absent

// Text helpers and formatters instantiated by other units.
CStringW FUN_1416e4df0(int n);
CStringW GetStringCommon(int nKey);
CString FUN_14016a5c0(const char* psz, int nCodePage);          // narrows a string
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
class QuestDataTable;
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
unsigned* FUN_1416e1dd0(std::vector<unsigned>* pVec);           // begin
unsigned* FUN_1416e1e70(std::vector<unsigned>* pVec);           // end
class CReservedWordTable;
class Unk_NpPathCfg;
CString FUN_14071ae20(const CString& str);              // the path of a data file
CStringW FUN_1401bf530(TiXmlElement*, const char*, CStringW strDefault);   // string attribute with default
struct Unk_RayCastInfo;
class CPhysXHelper   // physxhelper.h needs NOMINMAX, which this unit's headers do not set
{
public:
    int RayCastFixedDirection(const Vector3& ptFrom, Vector3& ptHit, Unk_RayCastInfo* pInfo, float fLen, Vector3* pNormal, int nMask);
};
class Unk_AvPhysicsSvc* GetPhysXHelper();   // the physics service getter (calls cast back)
int FUN_1404ad1f0(void* pMap, unsigned nKey, CStringW* pValue);     // CAtlMap::SetAt of the filter result
extern int DAT_143ab2914;                               // the ui level: below 0x32 the panel does not react

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a71990
Unk_NpRow::Unk_NpRow() : m_kind(0)
{
    m_a = 0;
    m_b = 0;
}

// @0x141a71910
Unk_NpRow::Unk_NpRow(const Unk_NpRow& o) : m_kind(o.m_kind), m_text(o.m_text), m_a(o.m_a), m_b(o.m_b), m_c(o.m_c)
{
}

// @0x141a71a20
Unk_NpRow::~Unk_NpRow()
{
}

// @0x141a6e060
UINpcPreviewDialog::UINpcPreviewDialog()
    : m_names(10)
{
    m_40 = 1;
    m_bPending = 0;
    m_nActorOid = 0;
}

// @0x141a6e100
CString UINpcPreviewDialog::GetTypeName()
{
    return "NpcPreviewDialog";
}

// @0x141a6e150
void UINpcPreviewDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nNpcId = 0;
    FUN_141a717c0();
}

// @0x141a6e190
int UINpcPreviewDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (DAT_143ab2914 < 0x32)
        return 0;
    if (_stricmp("onListChange", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            int nRow = data.PopInt();
            return FUN_141a6fd90(nRow);
        }
        return 1;
    } else if (_stricmp("onLoad", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            CStringW strFilter = data.FUN_1422b8f40();
            return FUN_141a6e7e0(strFilter);
        }
    } else if (_stricmp("onSelectNpc", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            int nNpc = data.PopUInt();
            return FUN_141a6ee60(nNpc);
        }
    } else if (_stricmp("onTalk", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            int nRow = data.PopInt();
            if (FUN_141a711b0())
                FUN_141a70b90(nRow);
            else
                FUN_141a71050(nRow);
            return 1;
        }
    } else if (_stricmp("onCreateNpc", szMethod) == 0) {
        if (m_nActorOid != 0)
            FUN_141a717c0();
        FUN_141a713a0();
        m_bPending = 1;
    }
    return 0;
}

// @0x141a6e510
void UINpcPreviewDialog::vfunc_15()
{
    if (m_bPending == 0)
        return;
    if (m_nActorOid == 0)
        return;
    PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nActorOid));
    if (pActor == 0)
        return;
    std::vector<CString> names;
    pActor->GetAnimMgr()->GetAnimationNames(&names);
    if (names.size() == 0)
        return;
    m_bPending = 0;
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_list")) {
        spList->FUN_1422dd1d0();
        for (std::vector<CString>::iterator it = names.begin(); it != names.end(); ++it) {
            Unk_NpRow row;
            row.m_kind = 6;
            row.m_text = (const char*)*it;
            m_rows.Add(row);
            spList->AddLabelItemA(FUN_14016a5c0((const char*)*it, 0));
        }
        spList->vfunc_24(1);
    }
}

// @0x141a6e7e0
int UINpcPreviewDialog::FUN_141a6e7e0(CStringW strFilter)
{
    if (m_names.GetCount() == 0)
        LoadNpcName();
    int nSearch = _wtoi(strFilter);
    ATL::CAtlMap<unsigned int, CStringW> found(17, 0.75f, 0.25f, 2.25f, 10);
    for (POSITION pos = m_names.GetHeadPosition(); pos != 0; m_names.GetNext(pos)) {
        unsigned int nId = m_names.GetKeyAt(pos);
        CStringW strName = m_names.GetValueAt(pos);
        if (nSearch == 0) {
            if (strName.Find(strFilter, 0) == -1)
                continue;
            found.SetAt(nId, strName);
        } else {
            CStringW strId;
            strId.Format(L"%d", nId);
            if (strId.Find(strFilter, 0) == -1)
                continue;
            found.SetAt(nId, strName);
        }
    }
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_npcList")) {
        spList->SetSelectedIndex(-1);
        spList->FUN_1422dd1d0();
        for (POSITION pos = found.GetStartPosition(); pos != 0; found.GetNext(pos)) {
            ASObj row(2);
            unsigned int nId = found.GetKeyAt(pos);
            CStringW strName = found.GetValueAt(pos);
            row.FUN_1407cbb20("label", strName);
            row.SetMemberUInt("id", nId);
            spList->AddItem(row);
        }
        spList->vfunc_24(1);
    }
    return 1;
}

// @0x141a6ec20
int UINpcPreviewDialog::LoadNpcName()
{
    CString strPath = FUN_14071ae20("npcName.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
        return 0;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("key")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("key"))) {
        int nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<int&>(nId));
        CStringW strName = FUN_1401bf530(pNode, "name", CStringW(L""));
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(strName);
        strName.Replace(L"\\n", L"\n");
        m_names.SetAt(nId, strName);
    }
    return 1;
}

// @0x141a6ee60
int UINpcPreviewDialog::FUN_141a6ee60(int nNpcId)
{
    m_rows.RemoveAll();
    m_nNpcId = nNpcId;
    MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_list");
    if (spList.IsNull())
        return 0;
    MS2Ptr<CNpcData> spData = FUN_1406cd330(nNpcId);
    if (spData.IsNull()) {
        spList->FUN_1422dd1d0();
        spList->vfunc_24(1);
        return 0;
    }
    if (MS2Ptr<ASTextField> spName = GetChild<ASTextField>("m_name"))
        spName->SetTextW(FUN_1401aa6a0(nNpcId));
    if (MS2Ptr<ASTextField> spKind = GetChild<ASTextField>("m_kind"))
        spKind->SetTextW(TSingleton<CStringTable>::GetInstance()->FUN_141811980(10, nNpcId));
    if (MS2Ptr<ASTextField> spIllust = GetChild<ASTextField>("m_illust"))
    {
    }
    if (FUN_141a711b0()) {
        Unk_NpRow rowLoc;
        rowLoc.m_kind = 1;
        rowLoc.m_text = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_location");
        m_rows.Add(rowLoc);
        std::vector<unsigned>* pQuests = TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByNpc(nNpcId);
        if (pQuests != 0) {
            for (unsigned nQuestId : *pQuests) {
                MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
                if (spQuest.IsNull())
                    return 0;
                Unk_NpRow rowQuest;
                rowQuest.m_kind = 2;
                rowQuest.m_a = nQuestId;
                rowQuest.m_b = spQuest->m_2e8 == nNpcId;
                CStringW strQuest = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_quest");
                CStringW strStart = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_start");
                CStringW strComplate = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_complate");
                rowQuest.m_text = StringFormat<CStringW, CStringW>(strQuest, rowQuest.m_b != 0 ? strStart : strComplate, FUN_1416e4df0(nQuestId));
                m_rows.Add(rowQuest);
            }
        }
        for (size_t i = 0; i < 2; i++) {
            TalkPtr spTalk = FUN_140856c50(nNpcId, (int)i);
            if (spTalk.get() != 0) {
                Unk_NpRow rowCine;
                rowCine.m_kind = 4;
                rowCine.m_c = (int)i;
                CStringW strCine = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_cinematic_talk");
                CStringW strSelect = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_select_talk");
                CStringW strJob = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_job_talk");
                rowCine.m_text = StringFormat<CStringW>(strCine, i == 0 ? strSelect : strJob);
                m_rows.Add(rowCine);
            }
        }
        TalkArrayPtr spTalks = FUN_140857330(nNpcId);
        if (spTalks.get()) {
            for (size_t i = 0; i < spTalks->GetCount(); i++) {
                TalkPtr spTalk = spTalks->GetAt(i);
                if (spTalk.get() != 0) {
                    Unk_NpRow rowTalk;
                    rowTalk.m_kind = 3;
                    rowTalk.m_c = spTalk->m_id;
                    CStringW strTalk = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_cinematic_talk2");
                    rowTalk.m_text = StringFormat(strTalk, i);
                    m_rows.Add(rowTalk);
                }
            }
        }
        TalkArrayPtr spMonos = FUN_140857660(nNpcId);
        if (spMonos.get()) {
            for (size_t i = 0; i < spMonos->GetCount(); i++) {
                TalkPtr spTalk = spMonos->GetAt(i);
                if (spTalk.get() != 0) {
                    Unk_NpRow rowMono;
                    rowMono.m_kind = 5;
                    rowMono.m_c = spTalk->m_id;
                    CStringW strMono = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_npcpreview_dialog_msg_monologue");
                    rowMono.m_text = StringFormat(strMono, i);
                    m_rows.Add(rowMono);
                }
            }
        }
        if (MS2Ptr<ASScrollingList> spList2 = GetChild<ASScrollingList>("m_list")) {
            spList2->FUN_1422dd1d0();
            for (size_t i = 0; i < m_rows.GetCount(); i++)
                spList2->AddLabelItemW(m_rows[i].m_text);
            spList2->vfunc_24(1);
        }
    }
    return 1;
}

// @0x141a6fd90
int UINpcPreviewDialog::FUN_141a6fd90(int nRow)
{
    if (nRow >= (int)m_rows.GetCount() || nRow < 0)
        return 0;
    MS2Ptr<ASTextField> spOut = GetChild<ASTextField>("m_output");
    if (spOut.IsNull())
        return 0;
    spOut->SetTextW(L"");
    Unk_NpRow row = m_rows.GetAt(nRow);
    if (row.m_kind == 1) {
        Unk_FieldIdList ids(10);
        TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb520(m_nNpcId, ids);
        for (POSITION pos = ids.GetHeadPosition(); pos != 0; ids.GetNext(pos))
            spOut->AppendTextW(TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, ids.GetAt(pos)));
    } else if (row.m_kind == 2) {
        int nQuestId = row.m_a;
        ATL::CAtlArray<int> talkIds;
        FUN_141a708e0(nQuestId, row.m_b != 0 ? 100 : 300, talkIds);
        CStringW strOut;
        for (size_t i = 0; i < talkIds.GetCount(); i++) {
            TalkPtr spTalk = FUN_1408564b0(nQuestId, talkIds[i]);
            if (spTalk.IsNull())
                continue;
            for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
                CStringW strText = spTalk->m_contents[j]->m_text;
                strText.Replace(L"$MaidName$", L"메이드");
                strText.Replace(L"$OwnerName$", GetStringCommon(0x787));
                TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
                strOut.AppendFormat(L"%d : %s\n\n", j, (const wchar_t*)strText);
            }
            strOut.AppendFormat(L"-----------------------------------------------------\n\n");
        }
        spOut->SetTextHTMLW(strOut);
    } else if (row.m_kind == 4) {
        CStringW strOut;
        TalkPtr spTalk = FUN_140856c50(m_nNpcId, row.m_c);
        if (spTalk.IsNull())
            return 0;
        for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
            CStringW strText = spTalk->m_contents[j]->m_text;
            strText.Replace(L"$MaidName$", L"메이드");
            strText.Replace(L"$OwnerName$", GetStringCommon(0x787));
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
            strOut.AppendFormat(L"%d : %s\n\n", j, (const wchar_t*)strText);
        }
        spOut->SetTextHTMLW(strOut);
    } else if (row.m_kind == 3) {
        CStringW strOut;
        TalkPtr spTalk = FUN_140856820(m_nNpcId, row.m_c);
        if (spTalk.IsNull())
            return 0;
        for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
            CStringW strText = spTalk->m_contents[j]->m_text;
            strText.Replace(L"$MaidName$", L"메이드");
            strText.Replace(L"$OwnerName$", GetStringCommon(0x787));
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
            strOut.AppendFormat(L"%d : %s\n\n", j, (const wchar_t*)strText);
        }
        spOut->SetTextHTMLW(strOut);
    } else if (row.m_kind == 5) {
        CStringW strOut;
        TalkPtr spTalk = FUN_140856af0(m_nNpcId, row.m_c);
        if (spTalk.IsNull())
            return 0;
        for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
            CStringW strText = spTalk->m_contents[j]->m_text;
            strText.Replace(L"$MaidName$", L"메이드");
            strText.Replace(L"$OwnerName$", GetStringCommon(0x787));
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
            strOut.AppendFormat(L"%d : %s\n\n", j, (const wchar_t*)strText);
        }
        spOut->SetTextHTMLW(strOut);
    }
    return 1;
}

// MS2-PIN: ?IsNull@?$Unk_ScriptPtr@VCTalkScript@@@@QEBA_NXZ 0x14085a420 ; sfb: talk script Ptr null test
// MS2-PIN: ?get@?$Unk_ScriptPtr@VCCinematicDistractor@@@@QEBAPEAVCCinematicDistractor@@XZ 0x14078f390 ; sfb: distractor Ptr get
// MS2-PIN: ??C?$Unk_ScriptPtr@VCCinematicDistractor@@@@QEBAPEAVCCinematicDistractor@@XZ 0x14078f3b0 ; sfb: distractor Ptr operator->
// @0x141a708e0
int UINpcPreviewDialog::FUN_141a708e0(int nQuestId, int nTalkId, ATL::CAtlArray<int>& rOut)
{
    rOut.Add(nTalkId);
    TalkPtr spTalk = FUN_1408564b0(nQuestId, nTalkId);
    if (spTalk.IsNull())
        return 0;
    for (size_t i = 0; i < spTalk->m_contents.GetCount(); i++) {
        if (spTalk->m_contents[i]->vfunc_1() == 0) {
            CCinematicContent* pCine = static_cast<CCinematicContent*>(spTalk->m_contents[i].get());
            if (pCine->m_distractors.get() != 0) {
                for (size_t j = 0; j < pCine->m_distractors->FUN_14078d3a0(); j++) {
                    ATL::CAtlArray<int> ids;
                    XmlSplit(pCine->m_distractors->m_choices.GetAt(j).m_goto, ids, ",");
                    for (size_t k = 0; k < ids.GetCount(); k++) {
                        if (Common::FindElement<int>(rOut, ids[k]) != -1)
                            continue;
                        if (ids.GetAt(k) != spTalk->m_id)
                            FUN_141a708e0(nQuestId, ids.GetAt(k), rOut);
                    }
                }
            }
        }
    }
    return 1;
}

// @0x141a70b90
void UINpcPreviewDialog::FUN_141a70b90(int nRow)
{
    if (nRow < 0 || nRow >= (int)m_rows.GetCount())
        return;
    Unk_NpRow row = m_rows.GetAt(nRow);
    if (row.m_kind == 2) {
        CTalkScript* pTalk = FUN_1408564b0(row.m_a, row.m_b != 0 ? 100 : 300).get();
        TSingleton<UITalkManager>::GetInstance()->FUN_141b213f0(MS2Ptr<CTalkScript>(pTalk), row.m_b, 4, 0);
    } else if (row.m_kind == 4) {
        CTalkScript* pTalk = FUN_140856c50(m_nNpcId, row.m_c).get();
        TSingleton<UITalkManager>::GetInstance()->FUN_141b213f0(MS2Ptr<CTalkScript>(pTalk), m_nNpcId, 8, 0);
    } else if (row.m_kind == 3) {
        CTalkScript* pTalk = FUN_140856820(m_nNpcId, row.m_c).get();
        TSingleton<UITalkManager>::GetInstance()->FUN_141b213f0(MS2Ptr<CTalkScript>(pTalk), m_nNpcId, 2, 0);
    } else if (row.m_kind == 5) {
        TalkPtr spTalk = FUN_140856af0(m_nNpcId, row.m_c);
        if (spTalk.IsNull())
            return;
        if (spTalk->m_contents.GetCount() >= 0) {
            ATL::CAtlList<efd::SmartPointer<GameObject> > npcs(10);
            WorldService::GetInstance()->FUN_141bd2db0(reinterpret_cast<ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >*>(&npcs), reinterpret_cast<int (*)(class Unk_WsC_GameObj*)>(FUN_141274aa0));
            for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
                CNpc* pNpc = FUN_141a71850(npcs.GetAt(pos));
                if (pNpc != 0) {
                    if (pNpc->FUN_141092fa0() != m_nNpcId)
                        continue;
                    pNpc->ShowChatBalloon(CStringW(spTalk->m_contents[0]->m_text));
                }
            }
        }
    }
}

// @0x141a71050
void UINpcPreviewDialog::FUN_141a71050(int nRow)
{
    if (nRow < 0 || nRow >= (int)m_rows.GetCount())
        return;
    PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nActorOid));
    if (pActor == 0)
        return;
    Unk_NpRow row = m_rows.GetAt(nRow);
    if (row.m_kind == 6) {
        efd::utf8string strAnim(FUN_14016a600(row.m_text, 0));
        pActor->PlayAnimation(strAnim, 1.0f, false, false);
    }
}

// @0x141a711b0
int UINpcPreviewDialog::FUN_141a711b0()
{
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02870("m_buttonBar"))
        return spTab.operator->()->GetSelectedIndex() == 0;
    return 0;
}

// @0x141a71280
efd::SmartPointer<CNpc> UINpcPreviewDialog::FUN_141a71280()
{
    efd::SmartPointer<CNpc> spNone(0);
    ATL::CRBMap<unsigned int, efd::SmartPointer<CNpc> >* pNpcs = reinterpret_cast<ATL::CRBMap<unsigned int, efd::SmartPointer<CNpc> >*>(reinterpret_cast<Unk_NpWorld*>(WorldService::GetInstance())->FUN_141bd36d0());
    for (POSITION pos = pNpcs->GetHeadPosition(); pos != 0; pNpcs->GetNext(pos)) {
        efd::SmartPointer<CNpc> spNpc = pNpcs->GetValueAt(pos);
        if (spNpc->FUN_141092fa0() == m_nNpcId)
            return spNpc;
    }
    return efd::SmartPointer<CNpc>(0);
}

// @0x141a713a0
void UINpcPreviewDialog::FUN_141a713a0()
{
    efd::Point3 kPos;
    efd::Point3 kDir;
    PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer != 0) {
        kPos = pPlayer->vfunc_18();
        kDir = pPlayer->vfunc_20();
    } else if (reinterpret_cast<Unk_NpWorld*>(WorldService::GetInstance())->FUN_141bd0dd0(reinterpret_cast<Vector3*>(&kPos), reinterpret_cast<Vector3*>(&kDir)) == 0) {
        return;
    }
    efd::SmartPointer<CNpc> spNpc = EE_NEW CNpc;
    spNpc->SetObjectId(999999);
    spNpc->vfunc_19(kPos);
    spNpc->vfunc_21(kDir);
    if (spNpc->vfunc_124(m_nNpcId) == 0)
        return;
    kPos.z += 100.0f;
    efd::Point3 kHit;
    if (reinterpret_cast<CPhysXHelper*>(GetPhysXHelper())->RayCastFixedDirection(reinterpret_cast<const Vector3&>(kPos), reinterpret_cast<Vector3&>(kHit), 0, 0.0f, 0, 0) == 0)
        return;
    kHit.z += 1.0f;
    spNpc->vfunc_19(kHit);
    for (int i = 0; i < 0x23; i++) {
        spNpc->FUN_1416708a0(i, 100);
        spNpc->SetCurrentStat(i, 100);
    }
    spNpc->vfunc_59(1, 0, 0, 0);
    if (reinterpret_cast<Unk_NpWorld*>(WorldService::GetInstance())->FUN_141bbb1e0(spNpc, 0, 1) == 0)
        return;
    m_nActorOid = spNpc->GetObjectId();
}

// @0x141a717c0
void UINpcPreviewDialog::FUN_141a717c0()
{
    efd::SmartPointer<PCBase> spActor(reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1320(m_nActorOid)));
    if (spActor) {
        reinterpret_cast<Unk_NpWorld*>(WorldService::GetInstance())->FUN_141bbb7f0(spActor, 0);
        m_nActorOid = 0;
    }
}

// @0x141a71850
CNpc* FUN_141a71850(const efd::SmartPointer<GameObject>& spObj)
{
    CNpc* pNpc = 0;
    if ((spObj ? true : false) && spObj->TypeCast(0x6200028, (void**)&pNpc))
        return pNpc;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1020-0x142cc1190 .text$yd
