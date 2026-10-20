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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // <dir>/<file> of the data files
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
int Parse_14021abf0(const CStringA& value);                 // the side popup ui type of a name (commonenum.cpp)

// ---- CSidePopupCondition ---------------------------------------------------------------------------------------------

// @0x140e8d770
ClassObject* CSidePopupCondition::CreateObject()
{
    return new CSidePopupCondition;
}

// @0x140e8d7d0
CStringW CSidePopupCondition::vfunc_1()
{
    return L"CSidePopupCondition";
}

// @0x140e8d820
CSidePopupCondition::CSidePopupCondition()
{
    m_eKind = SIDEPOPUP_EVENT_NONE;
}

// @0x140e8d860
void CSidePopupCondition::vfunc_2(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "key", m_nId);
}

// @0x140e8d8a0
ClassObject* CSidePopupConditionQuestAccept::CreateObject()
{
    return new CSidePopupConditionQuestAccept;
}

// @0x140e8d900
CStringW CSidePopupConditionQuestAccept::vfunc_1()
{
    return L"CSidePopupConditionQuestAccept";
}

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
CStringW CSidePopupConditionQuestSatisfied::vfunc_1()
{
    return L"CSidePopupConditionQuestSatisfied";
}

// @0x140e8da40
CSidePopupConditionQuestSatisfied::CSidePopupConditionQuestSatisfied()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_SATISFIED;
}

// @0x140e8da80
int CSidePopupConditionQuestSatisfied::vfunc_4()
{
    Unk_PayloadPtr<CQuest> spQuest = TSingleton<CQuestManager>::GetInstance()->vfunc_o10_3(m_nId);
    if (spQuest.IsNull())
        return 0;
    return spQuest->IsComplete();
}

// @0x140e8db30
ClassObject* CSidePopupConditionQuestComplete::CreateObject()
{
    return new CSidePopupConditionQuestComplete;
}

// @0x140e8db90
CStringW CSidePopupConditionQuestComplete::vfunc_1()
{
    return L"CSidePopupConditionQuestComplete";
}

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
CStringW CSidePopupConditionBossRegen::vfunc_1()
{
    return L"CSidePopupConditionBossRegen";
}

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
CStringW CSidePopupConditionQuestProgress::vfunc_1()
{
    return L"CSidePopupConditionQuestProgress";
}

// @0x140e8ddc0
CSidePopupConditionQuestProgress::CSidePopupConditionQuestProgress()
{
    m_eKind = SIDEPOPUP_EVENT_QUEST_PROGRESS;
}

// @0x140e8de10
void CSidePopupConditionQuestProgress::vfunc_2(Unk_140165cf0* pElem)
{
    CSidePopupCondition::vfunc_2(pElem);
    XmlTokenList(pElem, "args", m_args);
}

// @0x140e8de60
int CSidePopupConditionQuestProgress::vfunc_3()
{
    return FUN_140e8dea0();
}

// @0x140e8de80
int CSidePopupConditionQuestProgress::vfunc_4()
{
    return FUN_140e8dea0();
}

// @0x140e8dea0
int CSidePopupConditionQuestProgress::FUN_140e8dea0()
{
    Unk_PayloadPtr<CQuest> spQuest = TSingleton<CQuestManager>::GetInstance()->vfunc_o10_3(m_nId);
    if (spQuest.IsNull())
        return 0;
    for (size_t i = 0; i < m_args.GetCount(); i++)
    {
        if (spQuest->GetProgress((int)i) != m_args[i])
            return 0;
    }
    return 1;
}

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
    CString strPath = FUN_14071a5b0("Table", "SidePopupTalk.xml");
    TiXmlDocument doc;
    if (TSingleton<CFileSystem>::GetInstance()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "popup", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pElem = nodes[i];
        CStringA strType;
        FUN_1408733e0(pElem, "eventType", strType);
        CStringW strClass = StringFormat(L"CSidePopupCondition{0}", strType);
        MS2Ptr<CSidePopupCondition> spCond(static_cast<CSidePopupCondition*>(FUN_1401f7f50(strClass)));
        if (spCond.get())
        {
            spCond->vfunc_2(pElem);
            MS2Ptr<PopupData> spData(new PopupData);
            spData->m_spParam.AssignRaw(new SidePopupTalkParam);
            XmlEnumName<int, Parse_14021abf0>(pElem, "uiType", spData->m_spParam->m_nKind);
            FUN_1408733e0(pElem, "usm", spData->m_spParam->m_strName);
            FUN_1408733e0(pElem, "illust", spData->m_spParam->m_strIcon);
            XmlTokenList(pElem, "script", spData->m_spParam->m_script);
            FUN_1408732a0(pElem, "duration", spData->m_spParam->m_nNpcId);
            FUN_1408733e0(pElem, "voice", spData->m_spParam->m_strSound);
            FUN_1408733e0(pElem, "sound", spData->m_spParam->m_strScript);
            spData->m_spCond = spCond;
            FUN_140873220(pElem, "map", spData->m_nMapId);
            m_popups[std::make_pair(spCond->m_eKind, spCond->m_nId)] = spData;
        }
    }
}

// @0x140e8e5b0
MS2Ptr<SidePopupTalkParam> CSidePopupTalkTable::Find(eSidePopupEvent eKind, unsigned nId)
{
    PopupMap::iterator it = m_popups.find(std::make_pair(eKind, nId));
    if (it != m_popups.end())
    {
        MS2Ptr<PopupData> spData = (*it).second;
        if (spData->m_spCond->vfunc_3() == 0)
            return 0;
        if (spData->m_nMapId != 0)
        {
            if (spData->m_nMapId != TSingleton<WorldService>::GetInstance()->FUN_141bd3060())
                return 0;
        }
        return spData->m_spParam;
    }
    return 0;
}

// @0x140e8e7a0
MS2Ptr<SidePopupTalkParam> CSidePopupTalkTable::FindByMap(int nMapId)
{
    for (PopupMap::value_type& entry : m_popups)
    {
        MS2Ptr<PopupData> spData = entry.second;
        if (spData->m_nMapId != 0)
        {
            if (spData->m_nMapId == nMapId)
            {
                if (spData->m_spCond->vfunc_4())
                    return spData->m_spParam;
            }
        }
    }
    return 0;
}

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
