// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The side popup conditions (CSidePopupCondition and its five
// subclasses, created by name from Table/SidePopupTalk.xml) and CSidePopupTalkTable: see uisidepopuptalk.h. Third of
// the three TUs of ?\uisidepopuptalk.cpp (its own file name is unknown; it has no header statics, only the factory
// registrations).
// MS2-UNIT: ?\uisidepopuptalk.cpp#3
// MS2-RANGE: 0x1400dafe0-0x1400db1c0 .text$di
// MS2-RANGE: 0x140e8d770-0x140e93690 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\sidepopuptalktable.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uisidepopuptalk.h"

#include <vector>

#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned long&);   // C3: was FUN_1408732a0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

CString GetXmlPath(const CString& strDir, const CString& strFile);   // <dir>/<file> of the data files
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
int Parse_14021abf0(const CStringA& value);                 // the side popup ui type of a name (commonenum.cpp)

// ---- CSidePopupCondition ---------------------------------------------------------------------------------------------

// @0x140e8d770
ClassObject* CSidePopupCondition::CreateObject()
{
    return new CSidePopupCondition;
}

// @0x140e8d7d0
CStringW CSidePopupCondition::GetTypeName()
{
    return L"CSidePopupCondition";
}
MS2_REPLACE_METHOD(0x140E8D7D0, CSidePopupCondition, GetTypeName, 61, 0x1F1409FD);

// @0x140e8d820
CSidePopupCondition::CSidePopupCondition()
{
    m_eKind = SIDEPOPUP_EVENT_NONE;
}

// @0x140e8d860
void CSidePopupCondition::vfunc_2(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "key", m_nId);
}
MS2_REPLACE_METHOD(0x140E8D860, CSidePopupCondition, vfunc_2, 48, 0xC403BAA5);

// @0x140e8d8a0
ClassObject* CSidePopupConditionQuestAccept::CreateObject()
{
    return new CSidePopupConditionQuestAccept;
}

// @0x140e8d900
CStringW CSidePopupConditionQuestAccept::GetTypeName()
{
    return L"CSidePopupConditionQuestAccept";
}
MS2_REPLACE_METHOD(0x140E8D900, CSidePopupConditionQuestAccept, GetTypeName, 61, 0x1A1B9F58);

// @0x140e8d950
CSidePopupConditionQuestAccept::CSidePopupConditionQuestAccept()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_ACCEPT;
}

// @0x140e8d990
ClassObject* CSidePopupConditionQuestSatisfied::CreateObject()
{
    return new CSidePopupConditionQuestSatisfied;
}

// @0x140e8d9f0
CStringW CSidePopupConditionQuestSatisfied::GetTypeName()
{
    return L"CSidePopupConditionQuestSatisfied";
}
MS2_REPLACE_METHOD(0x140E8D9F0, CSidePopupConditionQuestSatisfied, GetTypeName, 61, 0x00BA248A);

// @0x140e8da40
CSidePopupConditionQuestSatisfied::CSidePopupConditionQuestSatisfied()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_SATISFIED;
}

// @0x140e8da80
int CSidePopupConditionQuestSatisfied::vfunc_4()
{
    MS2Ptr<CQuest> spQuest = TSingleton<CQuestManager>::GetInstance()->vfunc_o10_3(m_nId);
    if (spQuest.IsNull())
        return 0;
    return spQuest->IsComplete();
}
MS2_REPLACE_METHOD(0x140E8DA80, CSidePopupConditionQuestSatisfied, vfunc_4, 162, 0x33E45610);

// @0x140e8db30
ClassObject* CSidePopupConditionQuestComplete::CreateObject()
{
    return new CSidePopupConditionQuestComplete;
}

// @0x140e8db90
CStringW CSidePopupConditionQuestComplete::GetTypeName()
{
    return L"CSidePopupConditionQuestComplete";
}
MS2_REPLACE_METHOD(0x140E8DB90, CSidePopupConditionQuestComplete, GetTypeName, 61, 0xA9D9FFF0);

// @0x140e8dbe0
CSidePopupConditionQuestComplete::CSidePopupConditionQuestComplete()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_COMPLETE;
}

// @0x140e8dc20
ClassObject* CSidePopupConditionBossRegen::CreateObject()
{
    return new CSidePopupConditionBossRegen;
}

// @0x140e8dc80
CStringW CSidePopupConditionBossRegen::GetTypeName()
{
    return L"CSidePopupConditionBossRegen";
}
MS2_REPLACE_METHOD(0x140E8DC80, CSidePopupConditionBossRegen, GetTypeName, 61, 0x17139103);

// @0x140e8dcd0
CSidePopupConditionBossRegen::CSidePopupConditionBossRegen()
{
    m_eKind = SIDEPOPUP_EVENT_BOSS_REGEN;
}

// @0x140e8dd10
ClassObject* CSidePopupConditionQuestProgress::CreateObject()
{
    return new CSidePopupConditionQuestProgress;
}

// @0x140e8dd70
CStringW CSidePopupConditionQuestProgress::GetTypeName()
{
    return L"CSidePopupConditionQuestProgress";
}
MS2_REPLACE_METHOD(0x140E8DD70, CSidePopupConditionQuestProgress, GetTypeName, 61, 0x2C300AF9);

// @0x140e8ddc0
CSidePopupConditionQuestProgress::CSidePopupConditionQuestProgress()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_PROGRESS;
}

// @0x140e8de10
void CSidePopupConditionQuestProgress::vfunc_2(TiXmlElement* pElem)
{
    CSidePopupCondition::vfunc_2(pElem);
    XmlTokenList(pElem, "args", m_args);
}
MS2_REPLACE_METHOD(0x140E8DE10, CSidePopupConditionQuestProgress, vfunc_2, 63, 0xE19C0415);

// @0x140e8de60
int CSidePopupConditionQuestProgress::vfunc_3()
{
    return FUN_140e8dea0();
}
MS2_REPLACE_METHOD(0x140E8DE60, CSidePopupConditionQuestProgress, vfunc_3, 24, 0x4DCA262F);

// @0x140e8de80
int CSidePopupConditionQuestProgress::vfunc_4()
{
    return FUN_140e8dea0();
}
MS2_REPLACE_METHOD(0x140E8DE80, CSidePopupConditionQuestProgress, vfunc_4, 24, 0x56AAF3CF);

// @0x140e8dea0
int CSidePopupConditionQuestProgress::FUN_140e8dea0()
{
    MS2Ptr<CQuest> spQuest = TSingleton<CQuestManager>::GetInstance()->vfunc_o10_3(m_nId);
    if (spQuest.IsNull())
        return 0;
    for (size_t i = 0; i < m_args.GetCount(); i++)
    {
        if (spQuest->GetProgress((int)i) != m_args[i])
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140E8DEA0, CSidePopupConditionQuestProgress, FUN_140e8dea0, 267, 0xF5F7BF4C);

// ---- CSidePopupTalkTable ---------------------------------------------------------------------------------------------

// @0x140e8dfc0
CSidePopupTalkTable::CSidePopupTalkTable()
{
}

// @0x140e8dff0
CSidePopupTalkTable::~CSidePopupTalkTable()
{
}

// @0x140e8e020
void CSidePopupTalkTable::Init()
{
    CString strPath = GetXmlPath("Table", "SidePopupTalk.xml");
    TiXmlDocument doc;
    if (TSingleton<CFileSystem>::GetInstance()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
        return;
    std::vector<TiXmlElement*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "popup", "id", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (size_t i = 0; i < nodes.size(); i++)
    {
        TiXmlElement* pElem = nodes[i];
        CStringA strType;
        XmlGetAttr((class TiXmlElement*)(pElem), "eventType", strType);
        CStringW strClass = StringFormat(L"CSidePopupCondition{0}", strType);
        MS2Ptr<CSidePopupCondition> spCond(static_cast<CSidePopupCondition*>(FUN_1401f7f50(strClass)));
        if (spCond.get())
        {
            spCond->vfunc_2(pElem);
            MS2Ptr<PopupData> spData(new PopupData);
            spData->m_spParam.AssignRaw(new SidePopupTalkParam);
            XmlEnumName<int, Parse_14021abf0>(pElem, "uiType", spData->m_spParam->m_nKind);
            XmlGetAttr((class TiXmlElement*)(pElem), "usm", spData->m_spParam->m_strName);
            XmlGetAttr((class TiXmlElement*)(pElem), "illust", spData->m_spParam->m_strIcon);
            XmlTokenList(pElem, "script", spData->m_spParam->m_script);
            XmlGetAttr((class TiXmlElement*)(pElem), "duration", reinterpret_cast<unsigned long&>(spData->m_spParam->m_nNpcId));
            XmlGetAttr((class TiXmlElement*)(pElem), "voice", spData->m_spParam->m_strSound);
            XmlGetAttr((class TiXmlElement*)(pElem), "sound", spData->m_spParam->m_strScript);
            spData->m_spCond = spCond;
            XmlGetAttr((class TiXmlElement*)(pElem), "map", spData->m_nMapId);
            PopupMap::key_type key = std::make_pair(spCond->m_eKind, spCond->m_nId);
            m_popups[key] = spData;
        }
    }
}

// @0x140e8e5b0
MS2Ptr<SidePopupTalkParam> CSidePopupTalkTable::Find(eSidePopupEvent eKind, unsigned nId)
{
    PopupMap::key_type key = std::make_pair(eKind, nId);
    PopupMap::iterator it = m_popups.find(key);
    if (it != m_popups.end())
    {
        MS2Ptr<PopupData> spData = it->second;
        if (spData->m_spCond->vfunc_3() == 0)
            return 0;
        if (spData->m_nMapId != 0 && spData->m_nMapId != TSingleton<WorldService>::GetInstance()->FUN_141bd3060())
            return 0;
        return spData->m_spParam;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E8E5B0, CSidePopupTalkTable, Find, 475, 0x7B711F9E);

// @0x140e8e7a0
MS2Ptr<SidePopupTalkParam> CSidePopupTalkTable::FindByMap(int nMapId)
{
    for (PopupMap::iterator it = m_popups.begin(), itEnd = m_popups.end(); it != itEnd; ++it)
    {
        MS2Ptr<PopupData> spData = it->second;
        if (spData->m_nMapId == 0)
            continue;
        if (spData->m_nMapId != nMapId)
            continue;
        if (spData->m_spCond->vfunc_4() == 0)
            continue;
        return spData->m_spParam;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E8E7A0, CSidePopupTalkTable, FindByMap, 350, 0x9BCABD96);

// @0x140e90ce0
SidePopupTalkParam::SidePopupTalkParam()
    : m_nKind(0), m_nNpcId(0)
{
}

// ---- the factory registrations (.text$di, in name order) ----------------------------------------------------------------
#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time
static ClassObjectRegistrar s_regCondition(L"CSidePopupCondition", CSidePopupCondition::CreateObject);
static ClassObjectRegistrar s_regBossRegen(L"CSidePopupConditionBossRegen", CSidePopupConditionBossRegen::CreateObject);
static ClassObjectRegistrar s_regQuestAccept(L"CSidePopupConditionQuestAccept", CSidePopupConditionQuestAccept::CreateObject);
static ClassObjectRegistrar s_regQuestComplete(L"CSidePopupConditionQuestComplete", CSidePopupConditionQuestComplete::CreateObject);
static ClassObjectRegistrar s_regQuestProgress(L"CSidePopupConditionQuestProgress", CSidePopupConditionQuestProgress::CreateObject);
static ClassObjectRegistrar s_regQuestSatisfied(L"CSidePopupConditionQuestSatisfied", CSidePopupConditionQuestSatisfied::CreateObject);
#endif
