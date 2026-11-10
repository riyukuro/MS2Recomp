// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSoundDataTable: Table/soundDataTable_<lang>.xml.
// MS2-UNIT: commonfiles\sounddatatable.cpp
// MS2-RANGE: 0x1408179d0-0x14081c780 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Allocate@_Default_allocate_traits@std@@SAPEAX_K@Z 0x14081b310 ; unique
// MS2-PIN: ?ToDeclaration@TiXmlDeclaration@@UEBAPEBV1@XZ 0x14081b340 ; inline in tinyxml.h, was the view's tag (ICF twin of CAtlStringMgr::Clone)
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\sounddatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "sounddatatable.h"
#include "ms2/commonfiles/tinyxml.h"   // C3: the real TinyXML, before filesystem.h, so placeholder/tixmldocument.h steps aside
// (TiXmlString comes from tinystr.h; was placeholder/tixmlprinter.h)
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Unrecovered helpers (same ones the other xml table loaders use).
// C3: was class Unk_140165cf0 (TiXmlElement; NextSiblingElement() = TiXmlNode::NextSiblingElement, 0x1403f0510)
TiXmlElement* GetFirstChildElement(TiXmlDocument* pDoc);   // C3: dungeonroomshutdowncontext.cpp's definition (0x140345b40), the first child element
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int GetIntAttr(TiXmlElement* pElem, const char* pszName, int nDefault);                     // integer attribute
int GetRegion();                                                      // current language id
CString FUN_1406522f0(int nLanguage);                                     // language id -> file name suffix
CString ToCString(const char* psz, int nFlags);                       // path conversion
void XmlSetAttr(class TiXmlElement *, char const *, class ATL::CStringT<char, class StrTraitMFC_DLL<char, class ATL::ChTraitsCRT<char>>> const &);
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0


// C3: TiXmlElement / TiXmlNode / TiXmlDeclaration were unit-local views; they are now commonfiles/tinyxml.h.
// Its inline bodies emitted here (formerly tagged in the views): TiXmlNode::ToDocument const 14081b360 / non-const
// 14081b350, TiXmlDeclaration::~TiXmlDeclaration 14081ad20, Print(FILE*, int) 14081b2d0, ToDeclaration const
// 14081b340 / non-const 14081b330.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// @0x14081b310
TiXmlElement* DocRootElement(TiXmlDocument* pDoc)
{
    return GetFirstChildElement(pDoc);
}

// @0x1408179d0
CSoundDataTable::CSoundDataTable()
{
    int nLanguage = 0;
    int nId = GetRegion();
    switch (nId)
    {
    case 0: nLanguage = 0; break;
    case 1: nLanguage = 1; break;
    case 2: nLanguage = 2; break;
    case 3: nLanguage = 3; break;
    }
    SetLanguage(nLanguage);
}

// @0x140817ad0
CSoundDataTable::~CSoundDataTable()
{
}

// @0x140817b50
int CSoundDataTable::Load()
{
    TiXmlDocument doc;
    const CString& strPath = GetPath();
    if (GetFileSystem()->LoadXmlFile(&doc, (const char*)strPath, 0, true, false) == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"failed to read {0}", strPath);
        return 0;
    }
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        MS2_ASSERT_AT(0x41, 0);
        return 0;
    }
    ParseSection(pRoot, "eventSound", 0, m_eventSounds);
    ParseSection(pRoot, "programmerSound", 1, m_programmerSounds);
    ParseSection(pRoot, "triggerVoiceSound", 2, m_triggerVoiceSounds);
    return 1;
}

// @0x140817d70
int CSoundDataTable::Save()
{
    TiXmlDocument doc;
    ((void*)((class TiXmlNode*)(void*)(&doc))->InsertEndChild(*(class TiXmlNode const*)(&static_cast<const TiXmlDeclaration&>(TiXmlDeclaration("1.0", "utf-8", "")))));
    ((void*)((class TiXmlNode*)(void*)(&doc))->InsertEndChild(*(class TiXmlNode const*)(&static_cast<const TiXmlElement&>(TiXmlElement("ms2")))));

    {
        TiXmlElement eventSound("eventSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_eventSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            TiXmlElement sound("sound");
            XmlSetAttr((class TiXmlElement *)(&sound), "id", pEntry->strName);
            XmlSetAttr((class TiXmlElement*)(&sound), "lengthms", pEntry->nLengthMs);
            ((void*)((class TiXmlNode*)(void*)(&eventSound))->InsertEndChild(*(class TiXmlNode const*)(&sound)));
        }
        ((void*)((class TiXmlNode*)(void*)(DocRootElement(&doc)))->InsertEndChild(*(class TiXmlNode const*)(&eventSound)));
    }

    {
        TiXmlElement programmerSound("programmerSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_programmerSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            TiXmlElement sound("sound");
            XmlSetAttr((class TiXmlElement *)(&sound), "id", pEntry->strName);
            XmlSetAttr((class TiXmlElement*)(&sound), "lengthms", pEntry->nLengthMs);
            ((void*)((class TiXmlNode*)(void*)(&programmerSound))->InsertEndChild(*(class TiXmlNode const*)(&sound)));
        }
        ((void*)((class TiXmlNode*)(void*)(DocRootElement(&doc)))->InsertEndChild(*(class TiXmlNode const*)(&programmerSound)));
    }

    {
        TiXmlElement triggerVoiceSound("triggerVoiceSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_triggerVoiceSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            TiXmlElement sound("sound");
            XmlSetAttr((class TiXmlElement *)(&sound), "id", pEntry->strName);
            XmlSetAttr((class TiXmlElement*)(&sound), "lengthms", pEntry->nLengthMs);
            ((void*)((class TiXmlNode*)(void*)(&triggerVoiceSound))->InsertEndChild(*(class TiXmlNode const*)(&sound)));
        }
        ((void*)((class TiXmlNode*)(void*)(DocRootElement(&doc)))->InsertEndChild(*(class TiXmlNode const*)(&triggerVoiceSound)));
    }

    CString strPath = ToCString(GetPath(), 0);
    if (!reinterpret_cast<TiXmlDocument*>(&doc)->SaveFile(strPath))
    {
        MS2_ASSERT_AT(0x9f, 0);
        return 0;
    }
    return 1;
}

// @0x140818320
CString CSoundDataTable::GetPath()
{
    return m_strPath;
}

// @0x140818370
void CSoundDataTable::SetLanguage(int nLanguage)
{
    CString strFile;
    strFile.Format("soundDataTable_%s.xml", (const char*)FUN_1406522f0(nLanguage));
    CString strDir("Table");
    m_strPath = GetXmlPath(strDir, strFile);
}

// @0x140818460
CSoundDataEntry* CSoundDataTable::FindEventSound(const CString& strDir, const CString& strName)
{
    CString strKey = strDir + "/" + strName;
    if (m_eventSounds.find(strKey) == m_eventSounds.end())
        return 0;
    return &m_eventSounds[strKey];
}

// @0x140818570
CSoundDataEntry* CSoundDataTable::FindProgrammerSound(CString strName)
{
    bool bTagged = (strName.Left(1) == "$") && strName.Right(1) == "$";
    if (bTagged)
        strName.Remove('$');
    if (m_programmerSounds.find(strName) == m_programmerSounds.end())
        return 0;
    return &m_programmerSounds[strName];
}

// @0x140818740
CSoundDataEntry* CSoundDataTable::FindTriggerVoiceSound(CString strName)
{
    bool bTagged = (strName.Left(1) == "$") && strName.Right(1) == "$";
    if (bTagged)
        strName.Remove('$');
    if (m_triggerVoiceSounds.find(strName) == m_triggerVoiceSounds.end())
        return 0;
    return &m_triggerVoiceSounds[strName];
}

// @0x140818910
int CSoundDataTable::GetTriggerVoiceLength(CString strName)
{
    CSoundDataEntry* pEntry = FindTriggerVoiceSound(strName);
    if (pEntry == 0)
        return 0;
    return pEntry->nLengthMs;
}

// @0x1408189b0
int CSoundDataTable::GetVoiceLength(const CString& strName)
{
    CSoundDataEntry* pEntry;
    {
        CString strDir("ms2sound/sound/voice");
        pEntry = FindEventSound(strDir, strName);
    }
    if (pEntry == 0)
        return 0;
    return pEntry->nLengthMs;
}

// @0x140818a20
void CSoundDataTable::SetEventSounds(const SoundList& list)
{
    m_eventSounds.clear();
    MS2_FOR_EACH(const CSoundDataEntry& e, list)
    {
        m_eventSounds[e.strName] = e;
    }
}

// @0x140818ad0
void CSoundDataTable::SetProgrammerSounds(const SoundList& list)
{
    m_programmerSounds.clear();
    MS2_FOR_EACH(const CSoundDataEntry& e, list)
    {
        m_programmerSounds[e.strName] = e;
    }
}

// @0x140818b80
void CSoundDataTable::SetTriggerVoiceSounds(const SoundList& list)
{
    m_triggerVoiceSounds.clear();
    MS2_FOR_EACH(const CSoundDataEntry& e, list)
    {
        m_triggerVoiceSounds[e.strName] = e;
    }
}

// @0x140818c30
int CSoundDataTable::ParseSection(TiXmlElement* pRoot, const char* pszTag, int nType, SoundMap& map)
{
    if (pRoot == 0)
    {
        MS2_ASSERT_AT(0x50, 0);
        return 0;
    }
    TiXmlElement* pSection = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild(pszTag));
    if (pSection == 0)
        return 0;
    for (TiXmlElement* pElem = GetFirstChildElement(reinterpret_cast<TiXmlDocument*>(pSection)); pElem != 0; pElem = pElem->NextSiblingElement())
    {
        CString strId;
        strId = Unk_ReadString((class Unk_XmlNode*)(pElem), "id", CString(""));
        int nLengthMs = GetIntAttr(pElem, "lengthms", 0);
        CSoundDataEntry* pEntry = &map[strId];
        pEntry->nType = nType;
        pEntry->strName = strId;
        pEntry->nLengthMs = nLengthMs;
    }
    return 1;
}

