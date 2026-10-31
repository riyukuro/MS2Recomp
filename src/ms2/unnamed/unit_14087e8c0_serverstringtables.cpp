// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CServerString / CServerStringGroup: the server-side string tables
// (stringTrigger.xml, stringNpcAi.xml, stringGameEvent.xml) and the ATL::CAtlMap<CStringW, CStringW> code they instantiate.
// MS2-UNIT: unit_14087e8c0
// MS2-RANGE: 0x14087e8c0-0x1408806b0 .text$mn
// MS2-PIN: ??_7CServerStringGroup@@6B?$CValidData@VCServerStringGroup@@@@@ 0x142d9d7a8
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/tixmldocument.h"
#include <typeinfo>

#include "ms2/placeholder/cserverstring.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers (the xml loader and logger the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 : public CFileSystem { };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
void FUN_14054c030(void*, int, int, const wchar_t*, const CStringA&, const CStringA&);   // logger with two arguments
CStringA FUN_14071ae20(const CStringA& strFile);                        // the full path of a table file
bool FUN_14028f710(Unk_140165cf0*);                                     // the element is usable
CStringW FUN_1401bf530(Unk_140165cf0*, const char* pszName, CStringW strDefault);   // string attribute with default
CStringA FUN_1401d4330(const wchar_t* psz, int nCodePage);              // narrows a string
CString FUN_14016a5c0(const char* psz, int nCodePage);                  // narrows a string (the RTTI name in CheckInit)
bool FUN_140841300(const CStringW& str, const char* psz);               // string equals
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // StringFormat with one argument

CReservedWordTable* FUN_1403b4750();

bool CServerStringGroup::s_bInit;

// @0x14087e8c0
CServerStringGroup::CServerStringGroup(CStringA strFile)
    : m_strFile(strFile)
{
}

// @0x14087e9c0
CServerStringGroup::~CServerStringGroup()
{
}

// @0x14087ea50
bool CServerStringGroup::Load()
{
    CStringA strPath = FUN_14071ae20(m_strFile);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    m_mapFile.RemoveAll();
    CCacheData::FUN_1401d1160(CStringA(strPath));
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pKey))
            continue;
        CStringW strId = FUN_1401bf530(pKey, "id", CStringW(L""));
        CStringW strName = FUN_1401bf530(pKey, "name", CStringW(L""));
        strName.Replace(L"\\n", L"\n");
        FUN_1403b4750()->FUN_1416fb380(strName);
        if (m_mapFile.Lookup(strId) != 0)
            FUN_14054c030(FUN_140166440(), 1, 0x13, L"중복된 키 값이 존재 합니다.[<ms2> {0}] {1}", strPath, FUN_1401d4330(strId, 0));
        m_mapFile.SetAt(strId, strName);
    }
    SetInit(true);
    return true;
}

// @0x14087ede0
CStringW CServerStringGroup::GetString(const CStringW& strKey)
{
    CheckInit();
    if (FUN_1401d1320(this))
    {
        m_mapFile.RemoveAll();
        Load();
    }
    bool bMarked = FUN_140841300(strKey.Left(1), "$") && FUN_140841300(strKey.Right(1), "$");
    if (bMarked)
    {
        CStringW strName(strKey);
        strName.Remove(L'$');
        CStringW strText;
        if (m_mapRuntime.Lookup(strName, strText))
        {
            FUN_1403b4750()->FUN_1416fb340(strText);
            return strText;
        }
        if (m_mapFile.Lookup(strName, strText))
        {
            FUN_1403b4750()->FUN_1416fb340(strText);
            return strText;
        }
        return FUN_1401e8510(L"NO KEY : {0}", strKey);
    }
    else
        return strKey;
}

// @0x14087f0f0
void CServerStringGroup::SetString(const CStringW& strKey, const CStringW& strText)
{
    m_mapRuntime.SetAt(strKey, strText);
}

// @0x14087f140
bool CServerStringGroup::RemoveString(const CStringW& strKey)
{
    return m_mapRuntime.RemoveKey(strKey);
}

// @0x14087f180
CServerString::CServerString()
    : m_trigger("stringTrigger.xml")
    , m_npcAi("stringNpcAi.xml")
    , m_gameEvent("stringGameEvent.xml")
{
}

// @0x14087f280
CServerString::~CServerString()
{
}

// @0x14087f2f0
bool CServerString::Load()
{
    if (!LoadTrigger())
        return false;
    if (!LoadNpcAi())
        return false;
    if (!LoadGameEvent())
        return false;
    return true;
}

// @0x14087f350
bool CServerString::LoadTrigger()
{
    return m_trigger.Load();
}

// @0x14087f380
bool CServerString::LoadNpcAi()
{
    return m_npcAi.Load();
}

// @0x14087f3b0
bool CServerString::LoadGameEvent()
{
    return m_gameEvent.Load();
}

// @0x14087f7b0
void CServerStringGroup::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CServerStringGroup).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1408805c0
void CServerStringGroup::SetInit(bool bInit)
{
    s_bInit = bInit;
}
