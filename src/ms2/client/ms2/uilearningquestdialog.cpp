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
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/chomeprivilege.h"  // C3: CHomePrivilege complete for the headers above
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

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
class CFileSystem   // C3: member view for the former free stand-ins
{
public:
    int FUN_1403974b0(class TiXmlDocument*, char const*, int, bool, bool);
};
// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    class TiXmlNode* InsertEndChild(class TiXmlNode const&);
    class TiXmlNode* LinkEndChild(class TiXmlNode*);
};

int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, int nValue);      // SetAttribute
CString FUN_1412755f0();                                                    // the character save directory
CString FUN_141275640();                                                    // the account save directory
CString FUN_140cc2a00(const CString& strDir, const CString& strFile);       // path join
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_140719630(int n);                                              // number with thousands separators
CStringW FUN_14083cb20(const CStringW& str);
CStringW FUN_1416e7fb0(int nChapter);                                       // chapter name
CStringW FUN_1416e4df0(int nQuestId);                                       // quest name
      // the name / profanity filter
class CReservedWordTable;
class Unk_LqActor : public MyPC { };
class Unk_LqWorld { public: Unk_LqActor* FUN_141bd0cc0(); };
class Unk_LqUIMgr { public: void FUN_141adc530(int nClass); };
class Unk_LqSceneMgr;
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetSubSceneId();
};
Unk_StatusFlag* CGameOption::FUN_140ea41a0() { return &m_statusChar; }   // 0x140ea41a0 (C3: was the Unk_LqOptions view)
bool FUN_140930b70();
class UIStatusEventDispatcher;
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
unsigned short FUN_14074bd10(int);  // C3: the definition's signature
#include "ms2/placeholder/asbutton.h"   // C3: the button view is ASButton (was the stand-in Unk_140acd6e0)
//
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);   // index of the value, -1 if absent (0x140408410)
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
UIQuestEventDispatcher* FUN_140bfc4b0();
void* FUN_140764020();   // C3: was FUN_140764020
typedef MS2Ptr<CLearningQuestData> LqPtr;
typedef ATL::CAtlArray<LqPtr> LqArray;
namespace Common { template <class T> int FindElement(const ATL::CAtlArray<T>& arr, const T& v); }   // C3: was FUN_1402bacf0; index of the value (-1 when absent)
static int FUN_140ea3980(const void* pA, const void* pB);

// @0x140ea0850
UILearningQuestDialog::UILearningQuestDialog() : m_1a8(GetTypeName())
{
    m_7c = 1;
    m_80 = 0;
    m_188 = 0;
    FUN_141925e70(3, 1);
    FUN_141924170(1);
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangeServer", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c00));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c30));
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1d70));
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(this);
}

// @0x140ea0da0
UILearningQuestDialog::~UILearningQuestDialog()
{
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyChangeServer", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c00));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1c30));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UILearningQuestDialog::FUN_140ea1d70));
    FUN_140bfc4b0()->FUN_141aa8850(this);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(this);
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

// @0x140ea12a0
int UILearningQuestDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
    {
        Unk_LqActor* pActor = ((Unk_LqActor*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pActor == 0)
            return 0;
        LqPtr spData = CLearningQuestTable::GetInstance()->Get(m_18c);
        if (spData == 0)
            return 0;
        if (pActor->HasNoHome() != 0 && spData->m_nGotoField == 62000000)
        {
            if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)0x4f3f) != 0)
                (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4f3f)));
        }
        else
        {
            COutPacket packet(static_cast<int>(SendOp::Quest), 0);
            packet.WriteUInt8(0x10);
            packet.WriteInt32(m_18c);
            FUN_140710590(packet);
        }
    }
    else
    {
        if (_stricmp(szMethod, "onSelectQuest") == 0)
        {
            ASData data;
            if (data.SetArgsIfAny(pArgs, nArgs) != 0)
            {
                int nQuest = data.PopUInt();
                int nId = data.PopInt();
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
            CString strBound = m_1a8.BindNewItem(item.m_itemId, item.m_count, item.m_job);
            rewardAccept.FUN_1407cba60((const char*)StringFormat<unsigned __int64>("reward{0}", reinterpret_cast<const unsigned __int64&>(i)), strBound);
        }
        FUN_140ea3570(spQuest->m_complete, rewardComplete);
        data.FUN_1409eb270("rewardAccept", rewardAccept);
        data.FUN_1409eb270("rewardComplete", rewardComplete);
    }
    if (bPickCategory != 0)
        FUN_140ea2e50(data);
    if (m_1a0 != m_198)
    {
        data.FUN_1407cbb20("video", StringFormat<CString>(L"Common/{0}.usm", m_198));
        m_1a0 = m_198;
    }
    static_cast<AScript*>(m_30.operator->())->Invoke("setData", static_cast<const AScript&>(data));
    CStringW strCategory = GetStringCommonByKey(StringFormat<int>(L"s_learning_quest_category_{0}", m_190));
    if (MS2Ptr<ASTextField> spName = GetChild<ASTextField>("m_name"))
    {
        CStringW strName = FUN_14028dfa0<CStringW>(CStringW(L"s_learning_quest_name"), strCategory);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strName);
        spName->SetTextW(strName);
    }
    if (MS2Ptr<ASButton> spOk = GetChild<ASButton>("m_ok"))
    {
        unsigned nState = 0;
        LqPtr spData = CLearningQuestTable::GetInstance()->Get(m_18c);
        if (spData.get() != 0)
            nState = ((class CQuestManager*)FUN_140764020())->FUN_1416d0260(spData, 0);
        spOk->FUN_1422c1fe0(nState);
    }
}

// @0x140ea1c00
void UILearningQuestDialog::FUN_140ea1c00(NotifyObject*)
{
    LoadLearningQuest();
    FUN_140ea3910();
}

// @0x140ea1c30
void UILearningQuestDialog::FUN_140ea1c30(NotifyObject*)
{
    m_310.RemoveAll();
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    for (size_t i = 0; i < all.GetCount(); i++)
    {
        m_310.SetAt(all[i]->m_nId, ((class CQuestManager*)FUN_140764020())->FUN_1416d0260(all[i], 0) == 0);
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

// @0x140ea1e20
int UILearningQuestDialog::FUN_140ea1e20(int bNew)
{
    if (((class GFxSceneService*)CUserMail::FUN_1408e57f0())->GetSubSceneId() != 0x620001d)
        return 0;
    if (FUN_141924630() != 0)
        return 0;
    if (bNew != 0)
    {
        if (*reinterpret_cast<unsigned char*>(TSingleton<CGameOption>::GetInstance()->FUN_140ea41a0()) != 0)
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
        if (((class CQuestManager*)FUN_140764020())->FUN_1416d0260(LqPtr(spItem), bNew) == 0)
            continue;
        if (bNew != 0)
        {
            unsigned nSeen = 0;
            m_2c8.Lookup(spItem->m_nId, nSeen);
            if (nSeen != 0)
                continue;
            m_2c8.SetAt(spItem->m_nId, 1);
            SaveLearningQuest();
        }
        spFound = spItem;
        break;
    }
    if (spFound.get() != 0)
    {
        m_18c = spFound->m_nId;
        m_194 = spFound->m_nReqQuest;
        m_198 = spFound->m_strMovie;
        m_190 = spFound->m_nCategory;
        FUN_141924680();
        return 1;
    }
    return 0;
}

// @0x140ea2120
void UILearningQuestDialog::LoadLearningQuest()
{
    m_2c8.RemoveAll();
    LqArray all;
    if (CLearningQuestTable::GetInstance() != 0)
        CLearningQuestTable::GetInstance()->GetAll(all);
    for (size_t i = 0; i < all.GetCount(); i++)
        m_2c8.SetAt(all[i]->m_nId, 0);
    int bCharacterLoaded = ((class CFileSystem*)(class CFileSystem*)(GetFileSystem()))->FUN_1403974b0(&m_1e8, (const char*)FUN_140cc2a00(FUN_1412755f0(), "learningQuestCharacter.xml"), 0, true, false);
    if (bCharacterLoaded != 0)
    {
        TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&m_1e8))->FirstChild("ms2"));
        if (pRoot != 0)
        {
            TiXmlElement* pList = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v1"));
            if (pList != 0)
            {
                for (size_t i = 0; i < all.GetCount(); i++)
                {
                    LqPtr spItem(all[i]);
                    if (spItem->m_nQuestKind == 0)
                    {
                        unsigned nSeen = 0;
                        XmlGetAttr(pList, (const char*)StringFormat<int>("learning{0}", spItem->m_nId), *(int*)(&nSeen));
                        m_2c8.SetAt(spItem->m_nId, nSeen);
                    }
                }
            }
        }
    }
    int bAccountLoaded = ((class CFileSystem*)(class CFileSystem*)(GetFileSystem()))->FUN_1403974b0(&m_258, (const char*)FUN_140cc2a00(FUN_141275640(), "learningQuestAccount.xml"), 0, true, false);
    if (bAccountLoaded != 0)
    {
        TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&m_258))->FirstChild("ms2"));
        if (pRoot != 0)
        {
            TiXmlElement* pList = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v1"));
            if (pList != 0)
            {
                for (size_t i = 0; i < all.GetCount(); i++)
                {
                    LqPtr spItem(all[i]);
                    if (spItem->m_nQuestKind != 0)
                    {
                        unsigned nSeen = 0;
                        XmlGetAttr(pList, (const char*)StringFormat<int>("learning{0}", spItem->m_nId), *(int*)(&nSeen));
                        m_2c8.SetAt(spItem->m_nId, nSeen);
                    }
                }
            }
        }
    }
}

// @0x140ea26e0
void UILearningQuestDialog::SaveLearningQuest()
{
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&m_1e8))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        TiXmlDeclaration decl("1.0", "utf-8", "");
        ((void*)((class TiXmlNode*)(void*)(&m_1e8))->InsertEndChild(*(class TiXmlNode const*)(&decl)));
        pRoot = new TiXmlElement("ms2");
        ((void*)((class TiXmlNode*)(void*)(&m_1e8))->LinkEndChild((class TiXmlNode*)(pRoot)));
    }
    TiXmlElement* pList = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v1"));
    if (pList == 0)
    {
        pList = new TiXmlElement("v1");
        ((void*)((class TiXmlNode*)(void*)(pRoot))->LinkEndChild((class TiXmlNode*)(pList)));
    }
    for (POSITION pos = m_2c8.GetStartPosition(); pos != 0; m_2c8.GetNext(pos))
    {
        int nId = m_2c8.GetKeyAt(pos);
        unsigned nSeen = m_2c8.GetValueAt(pos);
        MS2Ptr<CLearningQuestData> spData = CLearningQuestTable::GetInstance()->Get(nId);
        if ((spData.get() ? true : false) && spData->m_nQuestKind == 0)
            XmlSetAttr(pList, (const char*)StringFormat<int>("learning{0}", spData->m_nId), nSeen);
    }
    reinterpret_cast<TiXmlDocument*>(&m_1e8)->SaveFile((const char*)FUN_140cc2a00(FUN_1412755f0(), "learningQuestCharacter.xml"));
    TiXmlElement* pRoot2 = ((class TiXmlElement*)((class Unk_XmlNode*)(&m_258))->FirstChild("ms2"));
    if (pRoot2 == 0)
    {
        TiXmlDeclaration decl("1.0", "utf-8", "");
        ((void*)((class TiXmlNode*)(void*)(&m_1e8))->InsertEndChild(*(class TiXmlNode const*)(&decl)));
        pRoot2 = new TiXmlElement("ms2");
        ((void*)((class TiXmlNode*)(void*)(&m_258))->LinkEndChild((class TiXmlNode*)(pRoot2)));
    }
    TiXmlElement* pList2 = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot2))->FirstChild("v1"));
    if (pList2 == 0)
    {
        pList2 = new TiXmlElement("v1");
        ((void*)((class TiXmlNode*)(void*)(pRoot2))->LinkEndChild((class TiXmlNode*)(pList2)));
    }
    for (POSITION pos2 = m_2c8.GetStartPosition(); pos2 != 0; m_2c8.GetNext(pos2))
    {
        int nId = m_2c8.GetKeyAt(pos2);
        unsigned nSeen = m_2c8.GetValueAt(pos2);
        MS2Ptr<CLearningQuestData> spData = CLearningQuestTable::GetInstance()->Get(nId);
        if ((spData.get() ? true : false) && spData->m_nQuestKind != 0)
            XmlSetAttr(pList2, (const char*)StringFormat<int>("learning{0}", spData->m_nId), nSeen);
    }
    reinterpret_cast<TiXmlDocument*>(&m_258)->SaveFile((const char*)FUN_140cc2a00(FUN_141275640(), "learningQuestAccount.xml"));
}

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
        if (Common::FindElement<int>(chapters, spQuest->m_28) == -1)
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
        TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByChapter(nChapter, quests);
        if (quests.GetCount() == 0)
            continue;
        if (((class CQuestManager*)FUN_140764020())->AreGroupQuestsComplete(nChapter) != 0)
            continue;
        if (((class CQuestManager*)FUN_140764020())->HasQuestInGroup(nChapter) == 0 && ((class CQuestManager*)FUN_140764020())->FUN_1416ce260(nChapter) == 0)
            continue;
        ASObj node(2);
        ASArray children(2);
        unsigned nFirst = 0;
        firstOfChapter.Lookup(nChapter, nFirst);
        int nType = Unk_ArrayFind<unsigned>(quests, reinterpret_cast<const unsigned&>(m_194)) != -1 ? 1 : 2;
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
            if (((class CQuestManager*)FUN_140764020())->FUN_140745590(quests[k]) != 0)
                continue;
            ASObj leaf(2);
            leaf.SetMemberUInt("id", quests[k]);
            leaf.FUN_1407cb9c0("guide", nFirst);
            leaf.FUN_1407cbb20("label", FUN_1416e4df0(quests[k]));
            leaf.FUN_1409c0dc0("rendererClassName", "UILearningQuestDialog_renderer_contents");
            children.PushObj(leaf);
            if ((int)quests[k] == m_194)
                nSelected = nNode;
            if (nType == 1)
                nNode++;
        }
        nodes.PushObj(node);
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
        CStringW strExp = FUN_14028dfa0<CStringW>(CStringW(L"s_learning_quest_exp"), FUN_14083cb20(FUN_140719630(rReward.m_exp)));
        rOut.FUN_1407cbb20("exp", strExp);
    }
    if (rReward.m_money != 0)
    {
        CStringW strMeso = FUN_14028dfa0<CStringW>(CStringW(L"s_learning_quest_meso"), FUN_14083cb20(FUN_140719630(rReward.m_money)));
        rOut.FUN_1407cbb20("meso", strMeso);
    }
    for (__int64 i = 0; (size_t)i < rReward.m_choiceRewards.GetCount(); ++i)
    {
        const CQuestData::QuestRewardItem& item = rReward.m_choiceRewards[i];
        CString strBound = m_1a8.BindNewItem(item.m_itemId, item.m_count, item.m_job);
        rOut.FUN_1407cba60((const char*)StringFormat<unsigned __int64>("reward{0}", reinterpret_cast<const unsigned __int64&>(i)), strBound);
    }
}

// @0x140ea3910
void UILearningQuestDialog::FUN_140ea3910()
{
    if (((Unk_LqActor*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()) == 0)
        return;
    if (((class GFxSceneService*)CUserMail::FUN_1408e57f0())->GetSubSceneId() != 0x620001d)
        return;
    if (m_2c8.GetCount() == 0)
        return;
    m_188 = 1;
}

// @0x140ea3980
static int FUN_140ea3980(const void* pA, const void* pB)
{
    const int* pChapterA = (const int*)pA;
    const int* pChapterB = (const int*)pB;
    ATL::CAtlArray<unsigned> questsA;
    ATL::CAtlArray<unsigned> questsB;
    TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByChapter(*pChapterA, questsA);
    TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByChapter(*pChapterB, questsB);
    if (questsA.GetCount() == 0 || questsB.GetCount() == 0)
        return 0;
    unsigned short nKeyA = FUN_14074bd10(questsA[0]);
    unsigned short nKeyB = FUN_14074bd10(questsB[0]);
    return nKeyA > nKeyB ? 1 : -1;
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
