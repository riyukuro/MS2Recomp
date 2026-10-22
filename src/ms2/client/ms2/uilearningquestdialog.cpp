// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UILearningQuestDialog: see uilearningquestdialog.h.
// MS2-UNIT: ?\uilearningquestdialog.cpp
// MS2-RANGE: 0x1400dba90-0x1400dbc00 .text$di
// MS2-RANGE: 0x140ea0850-0x140ea44b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uilearningquestdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uilearningquestdialog.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/learningquesttable.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of this unit (same shape as header_statics_a.h): the sort-name / skill / stun strings and the condition.
#include "ms2/placeholder/header_statics_a.h"

// ---- out-of-unit callees (names describe uses) ----
class TiXmlElement { public:
    TiXmlElement(const char* pszName);                                      // 0x14086f2f0
private:
    void* m_pad[18];
};
class TiXmlDeclaration { public:
    TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // 0x1408704d0
    virtual ~TiXmlDeclaration();                                            // 0x14081ad20
private:
    void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68;
};
class CFileSystem;
CFileSystem* GetFileSystem();
int FUN_1403974b0(CFileSystem* pFiles, TiXmlDocument* pDoc, const char* pszPath, int nFlags, bool bA, bool bB);   // load an xml file
TiXmlElement* FUN_140165cf0(TiXmlDocument* pParent, const char* pszName);   // FirstChildElement
TiXmlElement* FUN_140165cf0(TiXmlElement* pParent, const char* pszName);
void* FUN_14086e000(void* pParent, const void* pChild);                     // InsertEndChild
void* FUN_14086e090(void* pParent, void* pChild);                           // LinkEndChild
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* pszPath);               // SaveFile
int FUN_1408731e0(TiXmlElement* pElem, const char* pszName, unsigned* pnOut);   // QueryIntAttribute
void FUN_140873ca0(TiXmlElement* pElem, const char* pszName, int nValue);   // SetAttribute
CString FUN_1412755f0();                                                    // the character save directory
CString FUN_141275640();                                                    // the account save directory
CString FUN_140cc2a00(const CString& strDir, const CString& strFile);       // path join
CString FUN_1402bb1c0(const char* pszFormat, const int& n);                 // StringFormat(format, int)
CString FUN_1401d9af0(const char* pszFormat, const __int64* pn);            // StringFormat(format, size_t)
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& n);
CStringW FUN_1402a5170(const wchar_t* pszFormat, const CString& str);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);         // format a string-table text with one argument
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CStringW FUN_140719630(int n);                                              // number with thousands separators
CStringW FUN_14083cb20(const CStringW& str);
CStringW FUN_1416e7fb0(int nChapter);                                       // chapter name
CStringW FUN_1416e4df0(int nQuestId);                                       // quest name
class Unk_LqNameFilter { public: void FUN_1416fb340(CStringW& str); };      // the name / profanity filter
Unk_LqNameFilter* FUN_1403b4750();
class Unk_LqActor { public: int FUN_141527e00(); };
class Unk_LqWorld { public: Unk_LqActor* FUN_141bd0cc0(); };
Unk_LqWorld* FUN_1403ed2d0();
class Unk_LqUIMgr { public: int FUN_141adc940(int nClass); void FUN_141adc530(int nClass); };
Unk_LqUIMgr* FUN_1403ed2b0();
class Unk_LqSceneMgr;
Unk_LqSceneMgr* FUN_1408e57f0();
int FUN_1422b9e00(Unk_LqSceneMgr* pMgr);                                    // the current scene id
struct Unk_LqOptions { char m_pad_00[0x50]; char m_50; char* FUN_140ea41a0() { return &m_50; } };
Unk_LqOptions* FUN_1409a8b10();
bool FUN_140930b70();
class Unk_LqStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener* p); void FUN_141b0cd90(UIStatusEventListener* p); };
Unk_LqStatusMgr* FUN_140aa6d40();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074bd10(int nQuestId);                                            // sort key (a short)
class Unk_140acd6e0 : public ASDisplayObject { public:
    void FUN_1422c1fe0(unsigned);
};
class Unk_LqRoot : public AScript { public:
    Scaleform::GFx::Value FUN_140ba4cc0(const char*, const ASObj&);         // Invoke(method, object)
};
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const int* pn);           // index of the value (-1 when absent)
NotifySystem* FUN_140939a10();
UIQuestEventDispatcher* FUN_140bfc4b0();
CQuestManager* FUN_140764020();
QuestDataTable* FUN_1407476c0();
typedef MS2Ptr<CLearningQuestData> LqPtr;
typedef ATL::CAtlArray<LqPtr> LqArray;
int FUN_1402bacf0(ATL::CAtlArray<int>& rArr, const int& n);                 // index of the value (-1 when absent)
static int FUN_140ea3980(const void* pA, const void* pB);

// @0x140ea0850
UILearningQuestDialog::UILearningQuestDialog() : m_1a8(GetTypeName())
{
    m_7c = 1;
    m_80 = 0;
    m_188 = 0;
    FUN_141925e70(3, 1);
    FUN_141924170(1);
    FUN_140939a10()->RegisterNotify(L"NotifyChangeServer", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c00));
    FUN_140939a10()->RegisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c30));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1d70));
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140aa6d40()->FUN_141b0cd00(this);
}

// @0x140ea0da0
UILearningQuestDialog::~UILearningQuestDialog()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeServer", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c00));
    FUN_140939a10()->UnregisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c30));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1d70));
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140aa6d40()->FUN_141b0cd90(this);
}

// @0x140ea11b0
CString UILearningQuestDialog::GetTypeName() { return "LearningQuestDialog"; }

// @0x140ea1200
int UILearningQuestDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x140ea1220
void UILearningQuestDialog::vfunc_67()
{
    m_1a8.FUN_140d43990();
    m_1a0.Empty();
    UIDialog::vfunc_67();
}

// @0x140ea1270
void UILearningQuestDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140ea15d0(1);
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries / branch layout of the early-return flow differ from the exe
// @0x140ea12a0
int UILearningQuestDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
    {
        Unk_LqActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor == 0)
            return 0;
        LqPtr spData = CLearningQuestTable::GetInstance()->Get(m_18c);
        if (spData == 0)
            return 0;
        if (pActor->FUN_141527e00() == 0 || spData->m_nGotoField != 62000000)
        {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(0x10);
            packet.vfunc_o10_3(m_18c);
            FUN_140710590(packet);
        }
        else
        {
            if (FUN_1403ed2b0()->FUN_141adc940(0x4f3f) != 0)
                FUN_1403ed2b0()->FUN_141adc530(0x4f3f);
        }
    }
    else
    {
        if (_stricmp(szMethod, "onSelectQuest") == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nQuest = data.FUN_1422b8b10();
                int nId = data.FUN_1422b8a10();
                if (m_194 != nQuest)
                {
                    LqPtr spData = CLearningQuestTable::GetInstance()->Get(nId);
                    if (spData.get() != 0)
                    {
                        m_194 = nQuest;
                        m_18c = nId;
                        m_190 = spData->m_nCategory;
                        m_198 = spData->m_strMovie;
                        FUN_140ea15d0(0);
                    }
                }
            }
        }
    }
    return 0;
}

// @0x140ea1580
void UILearningQuestDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_188 != 0)
    {
        FUN_140ea1e20(1);
        m_188 = 0;
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; frame temporaries of the nested if / by-value copies differ from the exe
// @0x140ea15d0
void UILearningQuestDialog::FUN_140ea15d0(int bPickCategory)
{
    ASObj data(2);
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_194);
    if (spQuest.get() != 0)
    {
        ASObj rewardAccept(2);
        ASObj rewardComplete(2);
        for (__int64 i = 0; (size_t)i < spQuest->m_rewards.size(); ++i)
        {
            const CQuestData::QuestRewardItem& item = spQuest->m_rewards[i];
            CString strBound = m_1a8.FUN_140d43310(item.m_itemId, item.m_count, item.m_job);
            rewardAccept.FUN_1407cba60((const char*)FUN_1401d9af0("reward{0}", &i), strBound);
        }
        FUN_140ea3570(spQuest->m_complete, rewardComplete);
        data.FUN_1409eb270("rewardAccept", rewardAccept);
        data.FUN_1409eb270("rewardComplete", rewardComplete);
    }
    if (bPickCategory != 0)
        FUN_140ea2e50(data);
    if (m_1a0 != m_198)
    {
        data.FUN_1407cbb20("video", FUN_1402a5170(L"Common/{0}.usm", m_198));
        m_1a0 = m_198;
    }
    static_cast<Unk_LqRoot*>(m_30.operator->())->FUN_140ba4cc0("setData", data);
    CStringW strCategory = FUN_14028b8e0(FUN_1401ceea0(L"s_learning_quest_category_{0}", m_190));
    MS2Ptr<ASTextField> spName = FUN_140bb4cf0("m_name");
    if (spName.get() != 0)
    {
        CStringW strName = FUN_1405c2690(CStringW(L"s_learning_quest_name"), strCategory);
        FUN_1403b4750()->FUN_1416fb340(strName);
        spName->FUN_1422c4cd0(strName);
    }
    MS2Ptr<Unk_140acd6e0> spOk = FUN_140bb4b10("m_ok");
    if (spOk.get() != 0)
    {
        unsigned nState = 0;
        LqPtr spData = CLearningQuestTable::GetInstance()->Get(m_18c);
        if (spData.get() != 0)
            nState = FUN_140764020()->FUN_1416d0260(spData, 0);
        spOk->FUN_1422c1fe0(nState);
    }
}

// @0x140ea1c00
void UILearningQuestDialog::FUN_140ea1c00(NotifyObject*)
{
    LoadLearningQuest();
    FUN_140ea3910();
}

// MS2-FUNCTIONAL: behaviour-equivalent; the exe passes the CAtlMap::SetAt value by value; the 14.16 ATL headers bind a const reference
// @0x140ea1c30
void UILearningQuestDialog::FUN_140ea1c30(NotifyObject*)
{
    m_310.RemoveAll();
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    for (size_t i = 0; i < all.GetCount(); i++)
    {
        unsigned bClosed = FUN_140764020()->FUN_1416d0260(all[i], 0) == 0;
        m_310.SetAt(all[i]->m_nId, bClosed);
    }
}

// @0x140ea1d70
void UILearningQuestDialog::FUN_140ea1d70(NotifyObject*)
{
    m_2c8.RemoveAll();
}

// @0x140ea1da0
void UILearningQuestDialog::vfunc_o178_2(void*)
{
    FUN_140ea3910();
}

// @0x140ea1dd0
void UILearningQuestDialog::vfunc_oa0_9(unsigned short)
{
    FUN_140ea3910();
}

// @0x140ea1e00
void UILearningQuestDialog::vfunc_12()
{
    FUN_140ea3910();
}

// MS2-FUNCTIONAL: behaviour-equivalent; branch layout of the nested early returns differs from the exe
// @0x140ea1e20
int UILearningQuestDialog::FUN_140ea1e20(int bNew)
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
        return 0;
    if (FUN_141924630() != 0)
        return 0;
    if (bNew != 0)
    {
        if (*FUN_1409a8b10()->FUN_140ea41a0() != 0)
            return 0;
    }
    if (FUN_140930b70() == 0)
        return 0;
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    LqPtr spFound(0);
    for (size_t i = 0; i < all.GetCount(); i++)
    {
        LqPtr spItem(all[i]);
        if (FUN_140764020()->FUN_1416d0260(LqPtr(spItem), bNew) != 0)
        {
            if (bNew != 0)
            {
                unsigned nSeen = 0;
                if (m_2c8.Lookup(spItem->m_nId, nSeen) && nSeen != 0)
                    continue;
                m_2c8.SetAt(spItem->m_nId, 1);
                SaveLearningQuest();
            }
            spFound = spItem;
            break;
        }
    }
    if (spFound.get() == 0)
        return 0;
    m_18c = spFound->m_nId;
    m_194 = spFound->m_nReqQuest;
    m_198 = spFound->m_strMovie;
    m_190 = spFound->m_nCategory;
    FUN_141924680();
    return 1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the path building / xml loading differ from the exe
// @0x140ea2120
void UILearningQuestDialog::LoadLearningQuest()
{
    m_2c8.RemoveAll();
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    for (size_t i = 0; i < all.GetCount(); i++)
        m_2c8.SetAt(all[i]->m_nId, 0);
    if (FUN_1403974b0(GetFileSystem(), &m_1e8, (const char*)FUN_140cc2a00(FUN_1412755f0(), "learningQuestCharacter.xml"), 0, true, false) != 0)
    {
        TiXmlElement* pRoot = FUN_140165cf0(&m_1e8, "ms2");
        if (pRoot != 0)
        {
            TiXmlElement* pList = FUN_140165cf0(pRoot, "v1");
            if (pList != 0)
            {
                for (size_t i = 0; i < all.GetCount(); i++)
                {
                    LqPtr spItem(all[i]);
                    if (spItem->m_nQuestKind == 0)
                    {
                        unsigned nSeen = 0;
                        FUN_1408731e0(pList, (const char*)FUN_1402bb1c0("learning{0}", spItem->m_nId), &nSeen);
                        m_2c8.SetAt(spItem->m_nId, nSeen);
                    }
                }
            }
        }
    }
    if (FUN_1403974b0(GetFileSystem(), &m_258, (const char*)FUN_140cc2a00(FUN_141275640(), "learningQuestAccount.xml"), 0, true, false) != 0)
    {
        TiXmlElement* pRoot = FUN_140165cf0(&m_258, "ms2");
        if (pRoot != 0)
        {
            TiXmlElement* pList = FUN_140165cf0(pRoot, "v1");
            if (pList != 0)
            {
                for (size_t i = 0; i < all.GetCount(); i++)
                {
                    LqPtr spItem(all[i]);
                    if (spItem->m_nQuestKind != 0)
                    {
                        unsigned nSeen = 0;
                        FUN_1408731e0(pList, (const char*)FUN_1402bb1c0("learning{0}", spItem->m_nId), &nSeen);
                        m_2c8.SetAt(spItem->m_nId, nSeen);
                    }
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the xml writing differ from the exe
// @0x140ea26e0
void UILearningQuestDialog::SaveLearningQuest()
{
    TiXmlElement* pRoot = FUN_140165cf0(&m_1e8, "ms2");
    if (pRoot == 0)
    {
        TiXmlDeclaration decl("1.0", "utf-8", "");
        FUN_14086e000(&m_1e8, &decl);
        pRoot = new TiXmlElement("ms2");
        FUN_14086e090(&m_1e8, pRoot);
    }
    TiXmlElement* pList = FUN_140165cf0(pRoot, "v1");
    if (pList == 0)
    {
        pList = new TiXmlElement("v1");
        FUN_14086e090(pRoot, pList);
    }
    POSITION pos = m_2c8.GetStartPosition();
    while (pos != 0)
    {
        int nId = m_2c8.GetKeyAt(pos);
        unsigned nSeen = m_2c8.GetValueAt(pos);
        MS2Ptr<CLearningQuestData> spData = CLearningQuestTable::GetInstance()->Get(nId);
        if (spData.get() != 0 && spData->m_nQuestKind == 0)
            FUN_140873ca0(pList, (const char*)FUN_1402bb1c0("learning{0}", spData->m_nId), nSeen);
        m_2c8.GetNext(pos);
    }
    FUN_1408710c0(&m_1e8, (const char*)FUN_140cc2a00(FUN_1412755f0(), "learningQuestCharacter.xml"));
    TiXmlElement* pRoot2 = FUN_140165cf0(&m_258, "ms2");
    if (pRoot2 == 0)
    {
        TiXmlDeclaration decl("1.0", "utf-8", "");
        FUN_14086e000(&m_1e8, &decl);
        pRoot2 = new TiXmlElement("ms2");
        FUN_14086e090(&m_258, pRoot2);
    }
    TiXmlElement* pList2 = FUN_140165cf0(pRoot2, "v1");
    if (pList2 == 0)
    {
        pList2 = new TiXmlElement("v1");
        FUN_14086e090(pRoot2, pList2);
    }
    POSITION pos2 = m_2c8.GetStartPosition();
    while (pos2 != 0)
    {
        int nId = m_2c8.GetKeyAt(pos2);
        unsigned nSeen = m_2c8.GetValueAt(pos2);
        MS2Ptr<CLearningQuestData> spData = CLearningQuestTable::GetInstance()->Get(nId);
        if (spData.get() != 0 && spData->m_nQuestKind != 0)
            FUN_140873ca0(pList2, (const char*)FUN_1402bb1c0("learning{0}", spData->m_nId), nSeen);
        m_2c8.GetNext(pos2);
    }
    FUN_1408710c0(&m_258, (const char*)FUN_140cc2a00(FUN_141275640(), "learningQuestAccount.xml"));
}

// MS2-FUNCTIONAL: behaviour-equivalent; frame temporaries (ASObj / ASArray locals) and the CAtlMap::SetAt by-value argument differ from the exe
// @0x140ea2e50
void UILearningQuestDialog::FUN_140ea2e50(ASObj& rOut)
{
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    ATL::CAtlMap<int, unsigned> firstOfChapter;
    ATL::CAtlArray<int> chapters;
    for (size_t i = 0; i < all.GetCount(); i++)
    {
        LqPtr spItem(all[i]);
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(spItem->m_nReqQuest);
        if (!spQuest)
            continue;
        if (FUN_1402bacf0(chapters, spQuest->m_28) == -1)
        {
            chapters.Add(spQuest->m_28);
            firstOfChapter.SetAt(spQuest->m_28, spItem->m_nId);
        }
    }
    qsort(chapters.GetData(), chapters.GetCount(), 4, FUN_140ea3980);
    ASObj root(2);
    ASArray nodes(2);
    int nNode = 0;
    int nSelected = -1;
    for (size_t j = 0; j < chapters.GetCount(); j++)
    {
        int nChapter = chapters[j];
        ATL::CAtlArray<unsigned> quests;
        FUN_1407476c0()->FUN_14074cfd0(nChapter, quests);
        if (quests.GetCount() == 0)
            continue;
        if (FUN_140764020()->FUN_1416ce3d0(nChapter) != 0)
            continue;
        if (FUN_140764020()->FUN_1416ce340(nChapter) == 0 && FUN_140764020()->FUN_1416ce260(nChapter) == 0)
            continue;
        ASObj node(2);
        ASArray children(2);
        unsigned nFirst = 0;
        firstOfChapter.Lookup(nChapter, nFirst);
        int nType = FUN_140408410(&quests, &m_194) == -1 ? 2 : 1;
        unsigned nNew = 1;
        m_310.Lookup(nFirst, nNew);
        m_310.SetAt(nFirst, 0);
        node.FUN_1407cbb20("label", FUN_1416e7fb0(nChapter));
        node.FUN_1407cb9c0("type", nType);
        node.FUN_1409c0dc0("rendererClassName", "UILearningQuestDialog_renderer_category");
        node.FUN_1409eb1d0("nodes", children);
        node.FUN_1407cb9c0("isNew", nNew);
        nNode++;
        for (size_t k = 0; k < quests.GetCount(); k++)
        {
            if (FUN_140764020()->FUN_140745590(quests[k]) == 0)
            {
                ASObj leaf(2);
                leaf.FUN_1409c0d20("id", quests[k]);
                leaf.FUN_1407cb9c0("guide", nFirst);
                leaf.FUN_1407cbb20("label", FUN_1416e4df0(quests[k]));
                leaf.FUN_1409c0dc0("rendererClassName", "UILearningQuestDialog_renderer_contents");
                children.FUN_1422bbf00(leaf);
                if ((int)quests[k] == m_194)
                    nSelected = nNode;
                if (nType == 1)
                    nNode++;
            }
        }
        nodes.FUN_1422bbf00(node);
    }
    root.FUN_140e35d00("type", 1);
    root.FUN_1409eb1d0("nodes", nodes);
    rOut.FUN_1409eb270("list", root);
    rOut.FUN_1407cb9c0("selectedIndex", nSelected);
}

// @0x140ea3570
void UILearningQuestDialog::FUN_140ea3570(const CQuestData::CompleteReward& rReward, ASObj& rOut)
{
    if (rReward.m_exp != 0)
    {
        CStringW strExp = FUN_1405c2690(CStringW(L"s_learning_quest_exp"), FUN_14083cb20(FUN_140719630(rReward.m_exp)));
        rOut.FUN_1407cbb20("exp", strExp);
    }
    if (rReward.m_money != 0)
    {
        CStringW strMeso = FUN_1405c2690(CStringW(L"s_learning_quest_meso"), FUN_14083cb20(FUN_140719630(rReward.m_money)));
        rOut.FUN_1407cbb20("meso", strMeso);
    }
    for (__int64 i = 0; (size_t)i < rReward.m_choiceRewards.GetCount(); ++i)
    {
        const CQuestData::QuestRewardItem& item = rReward.m_choiceRewards[i];
        CString strBound = m_1a8.FUN_140d43310(item.m_itemId, item.m_count, item.m_job);
        rOut.FUN_1407cba60((const char*)FUN_1401d9af0("reward{0}", &i), strBound);
    }
}

// @0x140ea3910
void UILearningQuestDialog::FUN_140ea3910()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
        return;
    if (m_2c8.GetCount() == 0)
        return;
    m_188 = 1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; qsort callback: frame temporaries of the two CAtlArray locals differ from the exe
// @0x140ea3980
static int FUN_140ea3980(const void* pA, const void* pB)
{
    const int* pChapterA = (const int*)pA;
    const int* pChapterB = (const int*)pB;
    ATL::CAtlArray<unsigned> questsA;
    ATL::CAtlArray<unsigned> questsB;
    FUN_1407476c0()->FUN_14074cfd0(*pChapterA, questsA);
    FUN_1407476c0()->FUN_14074cfd0(*pChapterB, questsB);
    if (questsA.GetCount() != 0 && questsB.GetCount() != 0)
    {
        unsigned short nKeyA = FUN_14074bd10(questsA[0]);
        unsigned short nKeyB = FUN_14074bd10(questsB[0]);
        int nResult;
        if (nKeyB < nKeyA)
            nResult = 1;
        else
            nResult = -1;
        return nResult;
    }
    return 0;
}

// ---- hooks (functions that call CLearningQuestTable::GetInstance / build delegates are not hooked: see RECOVERY section 9) ----
MS2_REPLACE_METHOD(0x140EA11B0, UILearningQuestDialog, GetTypeName, 61, 0x440B3F21);
MS2_REPLACE_METHOD(0x140EA1200, UILearningQuestDialog, vfunc_65, 24, 0xD85237DC);
MS2_REPLACE_METHOD(0x140EA1220, UILearningQuestDialog, vfunc_67, 63, 0x5082B5DD);
MS2_REPLACE_METHOD(0x140EA1E00, UILearningQuestDialog, vfunc_12, 24, 0xBB2FC109);
MS2_REPLACE_METHOD(0x140EA3570, UILearningQuestDialog, FUN_140ea3570, 922, 0x583AF749);
MS2_REPLACE_METHOD(0x140EA3910, UILearningQuestDialog, FUN_140ea3910, 97, 0xE2A0E4D1);
MS2_REPLACE_METHOD(0x140EA1D70, UILearningQuestDialog, FUN_140ea1d70, 38, 0xCFBD6CB7);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca7f60-0x142ca7ff0 .text$yd
