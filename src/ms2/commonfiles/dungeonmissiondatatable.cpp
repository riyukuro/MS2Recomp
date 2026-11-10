// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DungeonMissionDataTable: loads Table/DungeonMission.xml
// into DungeonMissionData objects by id.
// MS2-UNIT: commonfiles\dungeonmissiondatatable.cpp
// MS2-RANGE: 0x140318c80-0x14031b800 .text$mn
// The unit name is a guess: the queue row commonfiles\dungeonmatch.cpp (0x1402e6c50-0x14031b800) is four TUs, see
// commonfiles\dungeonmatch.cpp.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonmissiondatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonmissiondatatable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// The common log (GetLogString()).
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
class Unk_CommonLog
{
public:
    void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
class CLogString* GetLogString();

CString GetXmlPath(const CString& strDir, const CString& strFile);    // Table/<file>
bool IsElementAvailable(struct Unk_XmlElement*);   // C3: was IsElementAvailable

// The mapped object of key, or NULL.
template <class K, class V> MS2Ptr<V> FindValue(std::map<K, MS2Ptr<V>>& map, K key)
{
    typename std::map<K, MS2Ptr<V>>::iterator it = map.find(key);
    if (it != map.end())
        return it->second;
    return MS2Ptr<V>(0);
}

// @0x140318c80
DungeonMissionDataTable::DungeonMissionDataTable()
{
    ReadFromXml();
}

// @0x140318ce0
MS2Ptr<DungeonMissionData> DungeonMissionDataTable::GetMission(unsigned nId)
{
    return FindValue(m_missions, nId);
}
MS2_REPLACE_METHOD(0x140318CE0, DungeonMissionDataTable, GetMission, 75, 0x78D16B16);

// @0x140318d40
BOOL DungeonMissionDataTable::ReadFromXml()
{
    CString strPath = GetXmlPath("Table", "DungeonMission.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return FALSE;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return FALSE;
    }
    for (TiXmlElement* pElem = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("DungeonMission")); pElem; pElem = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->NextSibling("DungeonMission")))
    {
        if (!IsElementAvailable((struct Unk_XmlElement*)(pElem)))
            continue;
        MS2Ptr<DungeonMissionData> pData = DungeonMissionData::Create(pElem);
        if (pData == 0 || pData->GetId() == 0)
        {
            reinterpret_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x13, L"Create Error DungeonMissionData On DungeonMissionDataTable::ReadFromXml");
            continue;
        }
        m_missions.insert(std::make_pair(pData->GetId(), pData));
    }
    return TRUE;
}
MS2_REPLACE_METHOD(0x140318D40, DungeonMissionDataTable, ReadFromXml, 706, 0x254AECEE);
