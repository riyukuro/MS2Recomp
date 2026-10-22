// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINpcPreviewDialog: see uinpcpreviewdialog.h.
// MS2-UNIT: ?\uinpcpreviewdialog.cpp
// MS2-RANGE: 0x140119f90-0x14011a360 .text$di
// MS2-RANGE: 0x141a6e060-0x141a72480 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpcpreviewdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uinpcpreviewdialog.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
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

// The list control of the movie (the AS list with clear / append / refresh).
class Unk_NpList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dcca0(int nIndex);                     // select an index (-1 = none)
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append an object row
    void FUN_1422dd2a0(const CString& str);             // append a text row
    void FUN_1422dd310(const CStringW& str);            // append a text row
};

// The button bar (tab strip) of the movie.
class Unk_NpTab : public AScript
{
public:
    int FUN_1422e3210();                                // the selected tab
};

// The world: the actors of an object id, the preview npc spawn / removal and the npc tree.
class Unk_NpWorld
{
public:
    PCBase* FUN_141bd1320(int nId);                     // the actor of an object id
    PCBase* FUN_141bd0cc0();                            // the local player
    int FUN_141bd0dd0(Vector3* pPos, Vector3* pDir);    // a spawn position in front of the camera
    int FUN_141bbb1e0(GameObject* pObj, int nA, unsigned nB);   // add an actor to the field
    void FUN_141bbb7f0(GameObject* pObj, int nA);       // remove an actor from the field
    ATL::CRBMap<unsigned int, efd::SmartPointer<CNpc> >* FUN_141bd36d0();   // the npc tree
    void FUN_141bd2db0(ATL::CAtlList<efd::SmartPointer<GameObject> >* pOut, int (*pFilter)(GameObject*));   // collect the actors
};
Unk_NpWorld* FUN_1403ed2d0();
int FUN_141274aa0(GameObject* pObj);                    // the actor filter of the collection above
static CNpc* FUN_141a71850(const efd::SmartPointer<GameObject>& spObj);

// The ui text service (singleton): the text of a "$s_..." key.
class Unk_NpText { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_NpText* FUN_14025e7a0();
CStringTable* GetStringTable();
CStringW FUN_1401aa6a0(unsigned nNpc);                  // the name text of an npc id

// The talk window.
class Unk_NpTalkMgr { public: unsigned FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound); };
Unk_NpTalkMgr* FUN_140967100();

// Talk scripts.
typedef Unk_ScriptPtr<CTalkScript> TalkPtr;
typedef TPtrValue<ATL::CAtlArray<TalkPtr> > TalkArrayPtr;
TalkArrayPtr FUN_140857330(int nNpcId);                 // the select / job talks of an npc
TalkArrayPtr FUN_140857660(int nNpcId);                 // the monologues of an npc
TalkPtr FUN_140856820(int nNpcId, int nTalkId);
TalkPtr FUN_140856af0(int nNpcId, int nTalkId);
TalkPtr FUN_140856c50(int nNpcId, int nKind);
TalkPtr FUN_1408564b0(int nQuestId, int nTalkId);
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints
size_t FUN_140186260(ATL::CAtlArray<int>& arr);                                     // GetCount
int* FUN_1401844d0(ATL::CAtlArray<int>& arr, size_t i);                             // GetAt
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& n);                          // Find (-1 = absent)

// Text helpers and formatters instantiated by other units.
CStringW FUN_1406c6bd0(const wchar_t* szFormat, const __int64& n);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a, const CStringW& b);
CStringW FUN_1416e4df0(int n);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);
CStringW GetStringCommon(int nKey);
CString FUN_14016a5c0(const char* psz, int nCodePage);          // narrows a string
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
void FUN_1409989e0(efd::utf8string* pOut, const CString& str);   // utf8string from a narrow string
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
class Unk_NpQuestTable { public: std::vector<unsigned>* FUN_14074e0f0(int nNpcId); };
Unk_NpQuestTable* FUN_1407476c0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
unsigned* FUN_1416e1dd0(std::vector<unsigned>* pVec);           // begin
unsigned* FUN_1416e1e70(std::vector<unsigned>* pVec);           // end
CFieldMetaTable* FUN_140700390();
class Unk_NpTextFilter { public: void FUN_1416fb380(CStringW& strText); void FUN_1416fb340(CStringW& strText); };
Unk_NpTextFilter* FUN_1403b4750();
class Unk_NpPathCfg;
CString FUN_14071ae20(CString str);                     // the path of a data file
class Unk_NpXml { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* szPath, int nA, bool bB, bool bC); };
Unk_NpXml* FUN_140166420();
CStringW FUN_1401bf530(Unk_140165cf0*, const char*, CStringW strDefault);   // string attribute with default
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);            // tracked allocation
void* FUN_140876480(void* pkOut, int nCategory);                            // memory category helper, returns unsigned int*
class Unk_NpPhys { public: int FUN_14168a310(const Vector3& ptFrom, Vector3& ptHit, void* pInfo, float fLen, Vector3* pNormal, int nMask); };
Unk_NpPhys* FUN_1409f7ca0();
int FUN_1404ad1f0(void* pMap, unsigned nKey, CStringW* pValue);     // CAtlMap::SetAt of the filter result
extern int DAT_143ab2914;                               // the ui level: below 0x32 the panel does not react

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a71990
Unk_NpRow::Unk_NpRow()
{
    m_kind = 0;
    m_a = 0;
    m_b = 0;
}

// @0x141a71910
Unk_NpRow::Unk_NpRow(const Unk_NpRow& o)
{
    m_kind = o.m_kind;
    m_text = o.m_text;
    m_a = o.m_a;
    m_b = o.m_b;
    m_c = o.m_c;
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

// @0x141a71a40
UINpcPreviewDialog::~UINpcPreviewDialog()
{
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nRow = data.FUN_1422b8a10();
            return FUN_141a6fd90(nRow);
        }
        return 1;
    }
    if (_stricmp("onLoad", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            return FUN_141a6e7e0(data.FUN_1422b8f40());
    } else if (_stricmp("onSelectNpc", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nNpc = data.FUN_1422b8b10();
            return FUN_141a6ee60(nNpc);
        }
    } else if (_stricmp("onTalk", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nRow = data.FUN_1422b8a10();
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
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nActorOid);
    if (pActor == 0)
        return;
    std::vector<CString> names;
    pActor->GetAnimMgr()->FUN_14099e800(&names);
    if (names.size() == 0)
        return;
    m_bPending = 0;
    MS2Ptr<Unk_NpList> spList = FUN_140c02900("m_list");
    if (spList.get() != 0) {
        spList->FUN_1422dd1d0();
        for (std::vector<CString>::iterator it = names.begin(); it != names.end(); ++it) {
            Unk_NpRow row;
            row.m_kind = 6;
            row.m_text = (const char*)*it;
            m_rows.Add(row);
            spList->FUN_1422dd2a0(FUN_14016a5c0((const char*)*it, 0));
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
    for (POSITION pos = m_names.GetHeadPosition(); pos != 0; ) {
        unsigned int nId = m_names.GetKeyAt(pos);
        CStringW strName = m_names.GetValueAt(pos);
        m_names.GetNext(pos);
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
    MS2Ptr<Unk_NpList> spList = FUN_140c02900("m_npcList");
    if (spList.IsNull() == 0) {
        spList->FUN_1422dcca0(-1);
        spList->FUN_1422dd1d0();
        for (POSITION pos = found.GetStartPosition(); pos != 0; ) {
            unsigned int nId = found.GetKeyAt(pos);
            CStringW strName = found.GetValueAt(pos);
            found.GetNext(pos);
            ASObj row(2);
            row.FUN_1407cbb20("label", strName);
            row.FUN_1409c0d20("id", nId);
            spList->FUN_1422dd230(row);
        }
        spList->vfunc_24(1);
    }
    return 1;
}

// @0x141a6ec20
int UINpcPreviewDialog::LoadNpcName()
{
    CString strPath = FUN_14071ae20(CString("npcName.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key")) {
        int nId = 0;
        FUN_1408731e0(pNode, "id", nId);
        CStringW strName = FUN_1401bf530(pNode, "name", CStringW(L""));
        FUN_1403b4750()->FUN_1416fb380(strName);
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
    MS2Ptr<Unk_NpList> spList = FUN_140c02900("m_list");
    if (spList.IsNull())
        return 0;
    MS2Ptr<CNpcData> spData = FUN_1406cd330(nNpcId);
    if (spData.IsNull()) {
        spList->FUN_1422dd1d0();
        spList->vfunc_24(1);
        return 0;
    }
    MS2Ptr<ASTextField> spName = FUN_140bb4cf0("m_name");
    if (spName.IsNull() == 0)
        spName->FUN_1422c4cd0(FUN_1401aa6a0(nNpcId));
    MS2Ptr<ASTextField> spKind = FUN_140bb4cf0("m_kind");
    if (spKind.IsNull() == 0)
        spKind->FUN_1422c4cd0(GetStringTable()->FUN_141811980(10, nNpcId));
    MS2Ptr<ASTextField> spIllust = FUN_140bb4cf0("m_illust");
    if (FUN_141a711b0()) {
        Unk_NpRow rowLoc;
        rowLoc.m_kind = 1;
        rowLoc.m_text = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_location"));
        m_rows.Add(rowLoc);
        std::vector<unsigned>* pQuests = FUN_1407476c0()->FUN_14074e0f0(nNpcId);
        if (pQuests != 0) {
            for (unsigned* pId = FUN_1416e1dd0(pQuests); pId != FUN_1416e1e70(pQuests); ++pId) {
                MS2Ptr<CQuestData> spQuest = FUN_14074bc40(*pId);
                if (spQuest.IsNull())
                    return 0;
                Unk_NpRow rowQuest;
                rowQuest.m_kind = 2;
                rowQuest.m_a = *pId;
                rowQuest.m_b = spQuest->m_2e8 == nNpcId;
                CStringW strQuest = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_quest"));
                CStringW strStart = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_start"));
                CStringW strComplate = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_complate"));
                rowQuest.m_text = FUN_140656190(strQuest, rowQuest.m_b != 0 ? strStart : strComplate, FUN_1416e4df0(*pId));
                m_rows.Add(rowQuest);
            }
        }
        for (size_t i = 0; i < 2; i++) {
            TalkPtr spTalk = FUN_140856c50(nNpcId, (int)i);
            if (spTalk.get() != 0) {
                Unk_NpRow rowCine;
                rowCine.m_kind = 4;
                rowCine.m_c = (int)i;
                CStringW strCine = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_cinematic_talk"));
                CStringW strSelect = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_select_talk"));
                CStringW strJob = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_job_talk"));
                rowCine.m_text = FUN_1401e8510(strCine, i == 0 ? strSelect : strJob);
                m_rows.Add(rowCine);
            }
        }
        TalkArrayPtr spTalks = FUN_140857330(nNpcId);
        if (!!spTalks) {
            for (size_t i = 0; i < spTalks->GetCount(); i++) {
                TalkPtr spTalk = spTalks->GetAt(i);
                if (spTalk.get() != 0) {
                    Unk_NpRow rowTalk;
                    rowTalk.m_kind = 3;
                    rowTalk.m_c = spTalk->m_id;
                    CStringW strTalk = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_cinematic_talk2"));
                    __int64 nTalk = spTalk->m_id;
                    rowTalk.m_text = FUN_1406c6bd0(strTalk, nTalk);
                    m_rows.Add(rowTalk);
                }
            }
        }
        TalkArrayPtr spMonos = FUN_140857660(nNpcId);
        if (!!spMonos) {
            for (size_t i = 0; i < spMonos->GetCount(); i++) {
                TalkPtr spTalk = spMonos->GetAt(i);
                if (spTalk.get() != 0) {
                    Unk_NpRow rowMono;
                    rowMono.m_kind = 5;
                    rowMono.m_c = spTalk->m_id;
                    CStringW strMono = FUN_14025e7a0()->FUN_1422b0570(CString("$s_npcpreview_dialog_msg_monologue"));
                    __int64 nTalk = spTalk->m_id;
                    rowMono.m_text = FUN_1406c6bd0(strMono, nTalk);
                    m_rows.Add(rowMono);
                }
            }
        }
    }
    MS2Ptr<Unk_NpList> spList2 = FUN_140c02900("m_list");
    if (spList2.IsNull() == 0) {
        spList2->FUN_1422dd1d0();
        for (size_t i = 0; i < m_rows.GetCount(); i++)
            spList2->FUN_1422dd310(m_rows[i].m_text);
        spList2->vfunc_24(1);
    }
    return 1;
}

// Replaces the placeholders of a talk text and filters it.
static void FUN_NpTalkText(CStringW& strText)
{
    strText.Replace(L"$MaidName$", L"메이드");
    strText.Replace(L"$OwnerName$", GetStringCommon(0x787));
    FUN_1403b4750()->FUN_1416fb340(strText);
}

// @0x141a6fd90
int UINpcPreviewDialog::FUN_141a6fd90(int nRow)
{
    if (nRow < 0 || nRow >= (int)m_rows.GetCount())
        return 0;
    MS2Ptr<ASTextField> spOut = FUN_140bb4cf0("m_output");
    if (spOut.IsNull())
        return 0;
    spOut->FUN_1422c4cd0(CStringW(L""));
    Unk_NpRow row = m_rows.GetAt(nRow);
    CStringW strOut;
    if (row.m_kind == 1) {
        Unk_FieldIdList ids(10);
        FUN_140700390()->FUN_1406fb520(m_nNpcId, ids);
        for (POSITION pos = ids.GetHeadPosition(); pos != 0; ) {
            unsigned int nId = ids.GetNext(pos);
            strOut += GetStringTable()->FUN_141811980(3, nId);
            spOut->FUN_1422c5ab0(strOut);
        }
    } else if (row.m_kind == 2) {
        ATL::CAtlArray<int> talkIds;
        FUN_141a708e0(row.m_a, row.m_b == 0 ? 300 : 100, talkIds);
        for (size_t i = 0; i < FUN_140186260(talkIds); i++) {
            TalkPtr spTalk = FUN_1408564b0(row.m_a, *FUN_1401844d0(talkIds, i));
            if (spTalk.get() == 0)
                continue;
            for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
                CStringW strText = spTalk->m_contents[j]->m_text;
                FUN_NpTalkText(strText);
                strOut.AppendFormat(L"%d : %s\n\n", (int)j, (const wchar_t*)strText);
            }
            strOut += L"-----------------------------------------------------\n\n";
        }
        spOut->FUN_1422c4f00(strOut);
    } else if (row.m_kind == 4 || row.m_kind == 3 || row.m_kind == 5) {
        TalkPtr spTalk;
        if (row.m_kind == 4)
            spTalk = FUN_140856c50(m_nNpcId, row.m_c);
        else if (row.m_kind == 3)
            spTalk = FUN_140856820(m_nNpcId, row.m_c);
        else
            spTalk = FUN_140856af0(m_nNpcId, row.m_c);
        if (spTalk.get() == 0)
            return 0;
        for (size_t j = 0; j < spTalk->m_contents.GetCount(); j++) {
            CStringW strText = spTalk->m_contents[j]->m_text;
            FUN_NpTalkText(strText);
            strOut.AppendFormat(L"%d : %s\n\n", (int)j, (const wchar_t*)strText);
        }
        spOut->FUN_1422c4f00(strOut);
    }
    return 1;
}

// @0x141a708e0
int UINpcPreviewDialog::FUN_141a708e0(int nQuestId, int nTalkId, ATL::CAtlArray<int>& rOut)
{
    rOut.Add(nTalkId);
    TalkPtr spTalk = FUN_1408564b0(nQuestId, nTalkId);
    if (spTalk.get() == 0)
        return 0;
    for (size_t i = 0; i < spTalk->m_contents.GetCount(); i++) {
        if (spTalk->m_contents[i]->vfunc_1() != 0)
            continue;
        CCinematicContent* pCine = static_cast<CCinematicContent*>(spTalk->m_contents[i].get());
        if (pCine->m_distractors.get() == 0)
            continue;
        for (size_t j = 0; j < pCine->m_distractors->m_choices.GetCount(); j++) {
            CStringA strGoto(pCine->m_distractors->m_choices.GetAt(j).m_goto);
            ATL::CAtlArray<int> ids;
            FUN_140177de0(strGoto, ids, ",");
            for (size_t k = 0; k < FUN_140186260(ids); k++) {
                int nId = *FUN_1401844d0(ids, k);
                if (FUN_1402bacf0(rOut, nId) != -1)
                    continue;
                if (nId != spTalk->m_id)
                    FUN_141a708e0(nQuestId, nId, rOut);
            }
        }
    }
    return 1;
}

// @0x141a70b90
int UINpcPreviewDialog::FUN_141a70b90(int nRow)
{
    if (nRow < 0 || nRow >= (int)m_rows.GetCount())
        return 0;
    Unk_NpRow row = m_rows.GetAt(nRow);
    if (row.m_kind == 2) {
        TalkPtr spTalk = FUN_1408564b0(row.m_a, row.m_b == 0 ? 300 : 100);
        FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(spTalk.get()), row.m_b, 4, 0);
    } else if (row.m_kind == 4) {
        TalkPtr spTalk = FUN_140856c50(m_nNpcId, row.m_c);
        FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(spTalk.get()), m_nNpcId, 8, 0);
    } else if (row.m_kind == 3) {
        TalkPtr spTalk = FUN_140856820(m_nNpcId, row.m_c);
        FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(spTalk.get()), m_nNpcId, 2, 0);
    } else if (row.m_kind == 5) {
        TalkPtr spTalk = FUN_140856af0(m_nNpcId, row.m_c);
        if (spTalk.get() == 0)
            return 0;
        ATL::CAtlList<efd::SmartPointer<GameObject> > npcs(10);
        FUN_1403ed2d0()->FUN_141bd2db0(&npcs, FUN_141274aa0);
        for (POSITION pos = npcs.GetHeadPosition(); pos != 0; ) {
            efd::SmartPointer<GameObject> spObj = npcs.GetNext(pos);
            CNpc* pNpc = FUN_141a71850(spObj);
            if (pNpc != 0 && pNpc->FUN_141092fa0() == m_nNpcId)
                pNpc->FUN_14166fff0(CStringW(spTalk->m_contents[0]->m_text));
        }
    }
    return 1;
}

// @0x141a71050
void UINpcPreviewDialog::FUN_141a71050(int nRow)
{
    if (nRow < 0 || nRow >= (int)m_rows.GetCount())
        return;
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1320(m_nActorOid);
    if (pActor == 0)
        return;
    Unk_NpRow row = m_rows.GetAt(nRow);
    if (row.m_kind == 6) {
        efd::utf8string strAnim;
        FUN_1409989e0(&strAnim, FUN_14016a600(row.m_text, 0));
        pActor->FUN_14166dd20(strAnim, 1.0f, false, false);
    }
}

// @0x141a711b0
bool UINpcPreviewDialog::FUN_141a711b0()
{
    MS2Ptr<Unk_NpTab> spTab = FUN_140c02870("m_buttonBar");
    return !spTab.IsNull() && spTab->FUN_1422e3210() == 0;
}

// @0x141a71280
efd::SmartPointer<CNpc> UINpcPreviewDialog::FUN_141a71280()
{
    efd::SmartPointer<CNpc> spNone(0);
    ATL::CRBMap<unsigned int, efd::SmartPointer<CNpc> >* pNpcs = FUN_1403ed2d0()->FUN_141bd36d0();
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
    Vector3 kPos;
    Vector3 kDir;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0) {
        NiPoint3 kP = pPlayer->vfunc_18();
        kPos = reinterpret_cast<Vector3&>(kP);
        NiPoint3 kD = pPlayer->vfunc_20();
        kDir = reinterpret_cast<Vector3&>(kD);
    } else if (FUN_1403ed2d0()->FUN_141bd0dd0(&kPos, &kDir) == 0) {
        return;
    }
    int nCatTmp;
    unsigned int* pCat = (unsigned int*)FUN_140876480(&nCatTmp, 0);
    void* pMem = FUN_14208a860(sizeof(CNpc), *pCat);
    efd::SmartPointer<CNpc> spNpc(pMem == 0 ? 0 : ::new (pMem) CNpc);
    spNpc->FUN_14123c5a0(999999);
    spNpc->vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    spNpc->vfunc_21(reinterpret_cast<efd::Point3&>(kDir));
    if (spNpc->vfunc_124(m_nNpcId) == 0)
        return;
    kPos.z += 100.0f;
    Vector3 kHit;
    if (FUN_1409f7ca0()->FUN_14168a310(kPos, kHit, 0, 0.0f, 0, 0) == 0)
        return;
    kHit.z += 1.0f;
    spNpc->vfunc_19(reinterpret_cast<efd::Point3&>(kHit));
    for (int i = 0; i < 0x23; i++) {
        spNpc->FUN_1416708a0(i, 100);
        spNpc->FUN_141670700(i, 0);
    }
    spNpc->vfunc_59(1, 0, 0, 0);
    if (FUN_1403ed2d0()->FUN_141bbb1e0(spNpc, 0, 1) == 0)
        return;
    m_nActorOid = spNpc->FUN_14123c580();
}

// @0x141a717c0
void UINpcPreviewDialog::FUN_141a717c0()
{
    efd::SmartPointer<PCBase> spActor(FUN_1403ed2d0()->FUN_141bd1320(m_nActorOid));
    if (spActor != 0) {
        FUN_1403ed2d0()->FUN_141bbb7f0(spActor, 0);
        m_nActorOid = 0;
    }
}

// @0x141a71850
static CNpc* FUN_141a71850(const efd::SmartPointer<GameObject>& spObj)
{
    CNpc* pNpc = 0;
    if (spObj != 0 && spObj->TypeCast(0x6200028, (void**)&pNpc))
        return pNpc;
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1020-0x142cc1190 .text$yd
