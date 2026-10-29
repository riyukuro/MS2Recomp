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

// Unrecovered helpers (same ones the other xml table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
void* FUN_140166440();
void FUN_1403a1280(void*, int, int, const wchar_t*, const char* const*);
bool FUN_140184310(const CString& str, const char* psz);                  // str == psz

// The game's TinyXML element / declaration (constructed through new, which null-checks the allocation as the exe does);
// its writers in free-function form (`this` first): InsertEndChild,
// SetAttribute for string, int, bool, Point3-like and float values, SaveFile.
class TiXmlElement { public: TiXmlElement(const char* pszName); private: void* m_pad[0x90 / sizeof(void*)]; };   // ctor 0x14086f2f0
class TiXmlDeclaration { public: TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);
    private: void* m_pad[0x68 / sizeof(void*)]; };                                                                // ctor 0x1408704d0
void* FUN_14086e090(void* pParent, void* pChild);                         // InsertEndChild
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue);
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);
void FUN_140873bc0(void* pElem, const char* pszName, bool bValue);
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void FUN_140874ad0(void* pElem, const char* pszName, const Unk_DummyVec3& kValue);
bool FUN_1408710c0(void* pDoc, const char* pszPath);

// @0x1416841a0
CPCEffectDummy::CPCEffectDummy()
{
}

// @0x141686ff0
CPCEffectDummy::~CPCEffectDummy()
{
}

// @0x1416841f0
bool CPCEffectDummy::Load()
{
    return LoadFile(FUN_14071a5b0("Table", "pcEffectDummy.xml"));
}

// @0x141684290
bool CPCEffectDummy::LoadFile(const char* pszPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_1403a1280(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", &pszPath);
        return false;
    }
    Unk_140165cf0* pGroup = pRoot->FUN_140165cf0("effectdummy");
    if (pGroup != 0)
    {
        m_dummies.clear();
        CEffectDummy kDummy;
        for (Unk_140165cf0* pElem = pGroup->FUN_140165cf0("dummy"); pElem != 0; pElem = pElem->NextSiblingElement())
        {
            int nGender = 0;
            FUN_1408731e0(pElem, "gender", nGender);
            kDummy.Parse(pElem);
            m_dummies[nGender].push_back(kDummy);
        }
    }
    return true;
}

// @0x141684460
int CPCEffectDummy::Find(const char* pszName, CEffectDummy& kOut)
{
    for (std::map<int, std::vector<CEffectDummy> >::iterator it = m_dummies.begin(); it != m_dummies.end(); ++it)
    {
        for (std::vector<CEffectDummy>::iterator itRow = it->second.begin(); itRow != it->second.end(); ++itRow)
        {
            if (FUN_140184310(itRow->GetName(), pszName))
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
    size_t nCount = m_dummies[nGender].size();
    if (nIndex < nCount)
        kOut = m_dummies[nGender][nIndex];
    return nIndex < nCount;
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
    FUN_14086e090(&doc, pDecl);
    FUN_14086e090(&doc, pRoot);
    void* pGroup = new TiXmlElement("effectdummy");
    FUN_14086e090(pRoot, pGroup);
    void* pDummy = 0;
    for (std::map<int, std::vector<CEffectDummy> >::iterator it = m_dummies.begin(); it != m_dummies.end(); ++it)
    {
        for (std::vector<CEffectDummy>::iterator itRow = it->second.begin(); itRow != it->second.end(); ++itRow)
        {
            pDummy = new TiXmlElement("dummy");
            FUN_14086e090(pGroup, pDummy);
            FUN_140874050(pDummy, "name", itRow->GetName());
            FUN_140873ca0(pDummy, "gender", it->first);
            void* pAttach = new TiXmlElement("attachInfo");
            FUN_14086e090(pDummy, pAttach);
            void* pTransform = new TiXmlElement("transform");
            FUN_14086e090(pDummy, pTransform);
            FUN_140874050(pAttach, "parentNode", itRow->GetParentNode());
            FUN_140873bc0(pAttach, "applyWorldTransform", itRow->m_bApplyWorldTransform);
            FUN_140873bc0(pAttach, "applyLocalScale", itRow->m_bApplyLocalScale);
            FUN_140874ad0(pTransform, "translate", itRow->GetTranslate());
            FUN_140874ad0(pTransform, "rotation", itRow->m_vRotation);
            FUN_140873e30(pTransform, "scale", itRow->m_fScale);
        }
    }
    return FUN_1408710c0(&doc, pszPath);
}
