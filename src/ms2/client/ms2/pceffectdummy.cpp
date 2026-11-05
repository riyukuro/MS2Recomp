// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPCEffectDummy: the player-character effect-dummy table
// Table/pcEffectDummy.xml - <effectdummy><dummy gender=".." name=".."><attachInfo .../><transform .../></dummy>...
// kept as rows (CEffectDummy) grouped by gender. Also the unit's std::map / std::vector instantiation copies.
// MS2-UNIT: ?\pceffectdummy.cpp
// MS2-RANGE: 0x1416841a0-0x1416889f0 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pceffectdummy.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include "ms2/placeholder/cpceffectdummy.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0

// Unrecovered helpers (same ones the other xml table units use).
class Unk_140166420 : public CFileSystem { };
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_FileLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_1403a1280

// The game's TinyXML element / declaration (constructed through new, which null-checks the allocation as the exe does);
// its writers in free-function form (`this` first): InsertEndChild,
// SetAttribute for string, int, bool, Point3-like and float values, SaveFile.
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
class TiXmlDeclaration { public: TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);
    private: void* m_pad[0x68 / sizeof(void*)]; };                                                                // ctor 0x1408704d0
// C3 #12: was a local TiXml view





void XmlSetAttr(class TiXmlElement*, char const*, CString const&);   // C3: was FUN_140874050
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, bool);   // C3: was FUN_140873bc0
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void XmlSetAttr(class TiXmlElement*, char const*, const efd::Point3&);   // C3: was FUN_140874ad0

// @0x1416841a0
CPCEffectDummy::CPCEffectDummy()
{
}

// ~CPCEffectDummy (0x141686ff0) is implicit: an explicit empty body keeps a dead vptr store the exe does not have.

// @0x1416841f0
int CPCEffectDummy::Load()
{
    CString strPath = FUN_14071a5b0("Table", "pcEffectDummy.xml");
    return LoadFile(strPath);
}

// @0x141684290
int CPCEffectDummy::LoadFile(const char* pszPath)
{
    TiXmlDocument doc;
    if (((class Unk_140166420*)GetFileSystem())->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
    if (pRoot == 0)
    {
        Unk_FileLog<const char*>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", pszPath);
        return 0;
    }
    TiXmlElement* pGroup = ((class TiXmlElement*)(pRoot->FirstChild("effectdummy")));
    if (pGroup != 0)
    {
        m_dummies.clear();
        CEffectDummy kDummy;
        for (TiXmlElement* pElem = ((class TiXmlElement*)((class Unk_XmlNode*)(pGroup))->FirstChild("dummy")); pElem != 0; pElem = (TiXmlElement*)(((class TiXmlNode*)(pElem))->NextSiblingElement()))
        {
            int nGender = 0;
            XmlGetAttr((class TiXmlElement*)(pElem), "gender", reinterpret_cast<int&>(nGender));
            kDummy.Parse(pElem);
            m_dummies[nGender].push_back(kDummy);
        }
    }
    return 1;
}

// @0x141684460
int CPCEffectDummy::Find(const char* pszName, CEffectDummy& kOut)
{
    for (std::map<int, std::vector<CEffectDummy> >::iterator it = m_dummies.begin(); it != m_dummies.end(); ++it)
    {
        for (std::vector<CEffectDummy>::iterator itRow = it->second.begin(); itRow != it->second.end(); ++itRow)
        {
            if ((itRow->GetName() == pszName))
            {
                kOut = *itRow;
                return 1;
            }
        }
    }
    return 0;
}

// @0x141684580
size_t CPCEffectDummy::GetCount(int nGender)
{
    return m_dummies[nGender].size();
}

// @0x1416845c0
int CPCEffectDummy::Get(int nGender, unsigned nIndex, CEffectDummy& kOut)
{
    if (nIndex < m_dummies[nGender].size())
    {
        kOut = m_dummies[nGender][nIndex];
        return 1;
    }
    return 0;
}

// @0x141684660
void CPCEffectDummy::SetRows(int nGender, const std::vector<CEffectDummy>& rows)
{
    m_dummies[nGender] = rows;
}

// Writes the table back out as xml.
// @0x1416846a0
int CPCEffectDummy::Save(const char* pszPath)
{
    TiXmlDocument doc;
    void* pDecl = new TiXmlDeclaration("1.0", "utf-8", "");
    void* pRoot = new TiXmlElement("ms2");
    ((void*)((class TiXmlNode*)(void*)(&doc))->LinkEndChild((class TiXmlNode*)(pDecl)));
    ((void*)((class TiXmlNode*)(void*)(&doc))->LinkEndChild((class TiXmlNode*)(pRoot)));
    void* pGroup = new TiXmlElement("effectdummy");
    ((void*)((class TiXmlNode*)(void*)(pRoot))->LinkEndChild((class TiXmlNode*)(pGroup)));
    void* pDummy = 0;
    for (std::map<int, std::vector<CEffectDummy> >::iterator it = m_dummies.begin(); it != m_dummies.end(); ++it)
    {
        for (std::vector<CEffectDummy>::iterator itRow = it->second.begin(); itRow != it->second.end(); ++itRow)
        {
            pDummy = new TiXmlElement("dummy");
            ((void*)((class TiXmlNode*)(void*)(pGroup))->LinkEndChild((class TiXmlNode*)(pDummy)));
            XmlSetAttr((class TiXmlElement*)(pDummy), "name", itRow->GetName());
            XmlSetAttr((class TiXmlElement*)(pDummy), "gender", it->first);
            void* pAttach = new TiXmlElement("attachInfo");
            ((void*)((class TiXmlNode*)(void*)(pDummy))->LinkEndChild((class TiXmlNode*)(pAttach)));
            void* pTransform = new TiXmlElement("transform");
            ((void*)((class TiXmlNode*)(void*)(pDummy))->LinkEndChild((class TiXmlNode*)(pTransform)));
            XmlSetAttr((class TiXmlElement*)(pAttach), "parentNode", itRow->GetParentNode());
            XmlSetAttr((class TiXmlElement*)(pAttach), "applyWorldTransform", itRow->m_bApplyWorldTransform);
            XmlSetAttr((class TiXmlElement*)(pAttach), "applyLocalScale", itRow->m_bApplyLocalScale);
            XmlSetAttr((class TiXmlElement*)(pTransform), "translate", itRow->GetTranslate());
            XmlSetAttr((class TiXmlElement*)(pTransform), "rotation", itRow->m_vRotation);
            XmlSetAttr((class TiXmlElement*)(pTransform), "scale", itRow->m_fScale);
        }
    }
    return doc.SaveFile(pszPath);
}
