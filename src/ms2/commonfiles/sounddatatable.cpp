// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSoundDataTable: Table/soundDataTable_<lang>.xml.
// MS2-UNIT: commonfiles\sounddatatable.cpp
// MS2-RANGE: 0x1408179d0-0x14081c780 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Allocate@_Default_allocate_traits@std@@SAPEAX_K@Z 0x14081b310 ; unique
// MS2-PIN: ?Clone@CAtlStringMgr@ATL@@UEAAPEAUIAtlStringMgr@2@XZ 0x14081b340 ; order
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\sounddatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "sounddatatable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (same ones the other xml table loaders use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140345b40(); Unk_140165cf0* FUN_1403f0510(); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);   // string attribute
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);                     // integer attribute
int FUN_1406516b0();                                                      // current language id
CString FUN_1406522f0(int nLanguage);                                     // language id -> file name suffix
CString FUN_14038f6d0(const CString& str, const char* psz);               // str + psz
CString FUN_1401d2b10(const CString& a, const CString& b);                // a + b
bool FUN_140184310(const CString& str, const char* psz);                  // str == psz
CString FUN_14016a5c0(const char* psz, int nFlags);                       // path conversion
void* FUN_14086e000(void* pParent, const void* pChild);                   // InsertEndChild
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue);   // SetAttribute(name, string)
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);         // SetAttribute(name, int)
bool FUN_1408710c0(void* pDoc, const char* pszPath);                      // SaveFile

// Unit-local views of the game's TinyXML (bare global names, not efd::).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* m_data[0x12];
};
class Unk_TiXmlString { public: ~Unk_TiXmlString(); void* m_rep; };    // dtor 0x1401646b0
class TiXmlNode
{
public:
    virtual ~TiXmlNode();                                                // 0x14086dd00
    virtual void Print(FILE*, int) const = 0;
    virtual const char* Parse(const char*, void*, int) = 0;
    // @0x14081b360
    virtual TiXmlDocument* ToDocument() { return 0; }
    // @0x14081b350
    virtual const TiXmlDocument* ToDocument() const { return 0; }
    //
    //
    //
    //
    //
    //
    //
    virtual Unk_TiXmlElement* ToElement() { return 0; }
    virtual const Unk_TiXmlElement* ToElement() const { return 0; }
    virtual void* ToComment() { return 0; }
    virtual const void* ToComment() const { return 0; }
    virtual void* ToUnknown() { return 0; }
    virtual const void* ToUnknown() const { return 0; }
    virtual void* ToText() { return 0; }
    virtual const void* ToText() const { return 0; }
    virtual class TiXmlDeclaration* ToDeclaration() { return 0; }
    virtual const class TiXmlDeclaration* ToDeclaration() const { return 0; }
    virtual TiXmlNode* Clone() const = 0;
    virtual bool Accept(void*) const = 0;
private:
    void* m_base[9];
};
class TiXmlDeclaration : public TiXmlNode
{
public:
    TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // 0x1408704d0
    // @0x14081ad20
    virtual ~TiXmlDeclaration() {}      // inline as in tinyxml.h (the out-of-line copy clashed with commonfiles/tinyxml.cpp in the DLL)
    // @0x14081b2d0
    virtual void Print(FILE* f, int nDepth) const { Print(f, nDepth, 0); }
    virtual const char* Parse(const char*, void*, int) { return 0; }
    // @0x14081b340
    virtual TiXmlDeclaration* ToDeclaration() { return this; }
    // @0x14081b330
    virtual const TiXmlDeclaration* ToDeclaration() const { return this; }
    //
    //
    //
    //
    //
    //
    //
    virtual TiXmlNode* Clone() const;   // commonfiles/tinyxml.cpp
    virtual bool Accept(void*) const { return false; }
    virtual void Print(FILE*, int, void*) const {}
private:
    Unk_TiXmlString m_version, m_encoding, m_standalone;
};
MS2_CHECK_SIZE(TiXmlDeclaration, 0x68);

// @0x14081b310
static Unk_140165cf0* DocRootElement(TiXmlDocument* pDoc)
{
    return reinterpret_cast<Unk_140165cf0*>(pDoc)->FUN_140345b40();
}

// @0x1408179d0
CSoundDataTable::CSoundDataTable()
{
    int nLanguage = 0;
    int nId = FUN_1406516b0();
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

// MS2-FUNCTIONAL: register allocation of the path pointer (r8 via rcx) differs
// @0x140817b50
int CSoundDataTable::Load()
{
    TiXmlDocument doc;
    const CString& strPath = GetPath();
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"failed to read {0}", strPath);
        return 0;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
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
    FUN_14086e000(&doc, &static_cast<const TiXmlDeclaration&>(TiXmlDeclaration("1.0", "utf-8", "")));
    FUN_14086e000(&doc, &static_cast<const Unk_TiXmlElement&>(Unk_TiXmlElement("ms2")));

    {
        Unk_TiXmlElement eventSound("eventSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_eventSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            Unk_TiXmlElement sound("sound");
            FUN_140874050(&sound, "id", pEntry->strName);
            FUN_140873ca0(&sound, "lengthms", pEntry->nLengthMs);
            FUN_14086e000(&eventSound, &sound);
        }
        FUN_14086e000(DocRootElement(&doc), &eventSound);
    }

    {
        Unk_TiXmlElement programmerSound("programmerSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_programmerSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            Unk_TiXmlElement sound("sound");
            FUN_140874050(&sound, "id", pEntry->strName);
            FUN_140873ca0(&sound, "lengthms", pEntry->nLengthMs);
            FUN_14086e000(&programmerSound, &sound);
        }
        FUN_14086e000(DocRootElement(&doc), &programmerSound);
    }

    {
        Unk_TiXmlElement triggerVoiceSound("triggerVoiceSound");
        MS2_FOR_EACH(const SoundMap::value_type& it, m_triggerVoiceSounds)
        {
            const CSoundDataEntry* pEntry = &it.second;
            Unk_TiXmlElement sound("sound");
            FUN_140874050(&sound, "id", pEntry->strName);
            FUN_140873ca0(&sound, "lengthms", pEntry->nLengthMs);
            FUN_14086e000(&triggerVoiceSound, &sound);
        }
        FUN_14086e000(DocRootElement(&doc), &triggerVoiceSound);
    }

    CString strPath = FUN_14016a5c0(GetPath(), 0);
    if (!FUN_1408710c0(&doc, strPath))
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
    m_strPath = FUN_14071a5b0(strDir, strFile);
}

// @0x140818460
CSoundDataEntry* CSoundDataTable::FindEventSound(const CString& strDir, const CString& strName)
{
    CString strKey = FUN_1401d2b10(FUN_14038f6d0(strDir, "/"), strName);
    if (m_eventSounds.find(strKey) == m_eventSounds.end())
        return 0;
    return &m_eventSounds[strKey];
}

// MS2-FUNCTIONAL: extra pointer-save around Right(1) temporary not reproduced
// @0x140818570
CSoundDataEntry* CSoundDataTable::FindProgrammerSound(CString strName)
{
    bool bTagged = FUN_140184310(strName.Left(1), "$") && FUN_140184310(strName.Right(1), "$");
    if (bTagged)
        strName.Remove('$');
    if (m_programmerSounds.find(strName) == m_programmerSounds.end())
        return 0;
    return &m_programmerSounds[strName];
}

// MS2-FUNCTIONAL: extra pointer-save around Right(1) temporary not reproduced
// @0x140818740
CSoundDataEntry* CSoundDataTable::FindTriggerVoiceSound(CString strName)
{
    bool bTagged = FUN_140184310(strName.Left(1), "$") && FUN_140184310(strName.Right(1), "$");
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
int CSoundDataTable::ParseSection(Unk_140165cf0* pRoot, const char* pszTag, int nType, SoundMap& map)
{
    if (pRoot == 0)
    {
        MS2_ASSERT_AT(0x50, 0);
        return 0;
    }
    Unk_140165cf0* pSection = pRoot->FUN_140165cf0(pszTag);
    if (pSection == 0)
        return 0;
    for (Unk_140165cf0* pElem = pSection->FUN_140345b40(); pElem != 0; pElem = pElem->FUN_1403f0510())
    {
        CString strId;
        strId = FUN_14015f710(pElem, "id", CString(""));
        int nLengthMs = FUN_140197350(pElem, "lengthms", 0);
        CSoundDataEntry* pEntry = &map[strId];
        pEntry->nType = nType;
        pEntry->strName = strId;
        pEntry->nLengthMs = nLengthMs;
    }
    return 1;
}

