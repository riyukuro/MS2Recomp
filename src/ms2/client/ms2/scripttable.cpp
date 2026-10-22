// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CScriptTable: the NPC script strings (String\script*.xml,
// <key id name/>) in one id -> text map.
// MS2-UNIT: ?\scripttable.cpp
// MS2-RANGE: 0x141020bd0-0x1410229d0 .text$mn
// MS2-PIN: ??_7CScriptTable@@6B?$TSingleton@VCScriptTable@@@@@ 0x142e9da10
// MS2-PIN: ??_7CScriptTable@@6B?$CValidData@VCScriptTable@@@@@ 0x142e9da20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scripttable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cscripttable.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071ae20(const CString& strFile);                           // the localised string table path
CString FUN_140651350();                                                 // the locale folder name
CString FUN_14016a5c0(const char* psz, int n);
CString FUN_14028d3c0(CString strPath);                                  // the directory part of a path
void FUN_1401d3700(CString& str);                                        // normalises the case
bool FUN_14028f710(Unk_140165cf0* pElem);                                // the element is usable
int FUN_140873320(Unk_140165cf0* pElem, const char* pszName, unsigned __int64& nOut);

// The unit's two-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_ScriptLog(CLogString* log, int level, int category, const wchar_t* format, const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols-manual.tsv); a local copy stays false -> "is not initialized" box
bool CScriptTable::s_bInit;
#endif

// @0x141020bd0
CScriptTable::CScriptTable() : m_mapScripts(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x141020c80
CScriptTable::~CScriptTable()
{
}

// @0x141020ce0
void CScriptTable::Load()
{
    ATL::CAtlArray<CString> files;
    FUN_140399100(CString("*.xml"), FUN_14071ae20(FUN_140651350()), files, CString(""), false);
    for (size_t i = 0; i < files.GetCount(); i++)
    {
        CString strDir = FUN_14028d3c0(files[i]);
        FUN_1401d3700(strDir);
        if (strDir.Find("script", 0) == 0)
        {
            TiXmlDocument doc;
            if (GetFileSystem()->FUN_1403974b0(&doc, files[i], 0, true, false) == 0)
                return;
            Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
            if (pRoot == 0)
            {
                FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", files[i]);
                return;
            }
            for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
            {
                if (!FUN_14028f710(pKey))
                    continue;
                unsigned __int64 nId = 0;
                CStringW strName;
                FUN_140873320(pKey, "id", nId);
                FUN_140873420(pKey, "name", strName);
                if (m_mapScripts.Lookup(nId) != 0)
                {
                    const CString& rFile = files[i];
                    Unk_ScriptLog(GetLogString(), 1, 0x13, L"중복된 키 값이 존재 합니다.[<ms2> {0}] {1}", rFile, nId);
                    continue;
                }
                m_mapScripts.SetAt(nId, strName);
            }
        }
    }
    SetInit(true);
}

// @0x141021140
void CScriptTable::Reload()
{
    m_mapScripts.RemoveAll();
    Load();
}

// @0x141021170
CStringW CScriptTable::GetScript(unsigned __int64 nId)
{
    CheckInit();
    CStringW strScript;
    if (m_mapScripts.Lookup(nId, strScript))
        return strScript;
    return CStringW(L"");
}

// @0x1410218b0
void CScriptTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CScriptTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1410227c0
void CScriptTable::SetInit(bool b)
{
    s_bInit = b;
}

MS2_EMIT_CRT_MEMMOVE_S();
