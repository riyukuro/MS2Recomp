// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CIgnoreFile: the "except" lists of the ignore-pack-file xml.
// MS2-UNIT: ?\ignorefile.cpp
// MS2-RANGE: 0x14050e140-0x140511030 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ignorefile.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>
#include <ctype.h>

#include "ms2/placeholder/cignorefile.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

CLogString* GetLogString();                                        // the log singleton
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat);
template<class T> inline void Unk_FileLog(CLogString* log, int level, int category, const wchar_t* format, const T& value) {
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(value), args));
}
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text (NULL: missing)

// @0x14050e140
CIgnoreFile::CIgnoreFile()
    : m_nMode(0)
{
}

// @0x14050e1b0
CIgnoreFile::~CIgnoreFile()
{
}

// @0x14050e200
bool CIgnoreFile::FUN_14050e200(std::string strPath, int nMode)
{
    m_nMode = nMode;
    m_setDirs.clear();
    m_setFiles.clear();
    return FUN_14050e4c0(strPath, nMode);
}

// @0x14050e2a0
bool CIgnoreFile::FUN_14050e2a0(std::string strPath)
{
    if (m_setFiles.find(strPath) != m_setFiles.end())
        return true;
    for (std::set<std::string>::iterator it = m_setDirs.begin(); it != m_setDirs.end(); ++it)
    {
        if (strPath.find(*it, 0) != std::string::npos)
        {
            const char* pszDir = it->c_str();
            Unk_FileLog(GetLogString(), 0xc, 0x13, L"[Ignore Dir] {0}", pszDir);
            return true;
        }
    }
    return false;
}

// @0x14050e420
bool CIgnoreFile::FUN_14050e420(std::string strPath)
{
    if (m_setDirs.find(strPath) != m_setDirs.end())
        return true;
    return false;
}

// @0x14050e4c0
bool CIgnoreFile::FUN_14050e4c0(std::string strPath, int nMode)
{
    TiXmlDocument doc;
    CString strFile;
    strFile = strPath.c_str();
    if (!doc.FUN_140870fc0(strFile, 0))
    {
        const char* pszFile = strFile;
        Unk_FileLog(GetLogString(), 2, 0x13, L"[IgnoreFile] {0} \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4.\n", pszFile);
        return false;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_1401859c0(GetLogString(), 1, 0x13, L"[IgnoreFile] xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4.\n");
        return false;
    }
    for (Unk_140165cf0* pExcept = pRoot->FUN_140165cf0("except"); pExcept != 0; pExcept = pExcept->FUN_140168650("except"))
    {
        std::string strEntry;
        const char* pszTag = FUN_14086f4b0(pExcept, "tag");
        if (pszTag != 0 && atoi(pszTag) <= nMode)
            continue;
        for (Unk_140165cf0* pDir = pExcept->FUN_140165cf0("directory"); pDir != 0; pDir = pDir->FUN_140168650("directory"))
        {
            const char* pszName = FUN_14086f4b0(pDir, "name");
            if (pszName != 0)
            {
                std::string strName(pszName);
                std::transform(strName.begin(), strName.end(), strName.begin(), tolower);
                for (std::string::iterator it = strName.begin(); it != strName.end(); ++it)
                {
                    if (*it == '\\')
                        *it = '/';
                }
                if (*strName.rbegin() != '/')
                    strName += "/";
                strEntry = strName;
                m_setDirs.insert(strEntry);
            }
        }
        for (Unk_140165cf0* pFile = pExcept->FUN_140165cf0("file"); pFile != 0; pFile = pFile->FUN_140168650("file"))
        {
            const char* pszName = FUN_14086f4b0(pFile, "name");
            if (pszName != 0)
            {
                std::string strName(pszName);
                std::transform(strName.begin(), strName.end(), strName.begin(), tolower);
                for (std::string::iterator it = strName.begin(); it != strName.end(); ++it)
                {
                    if (*it == '\\')
                        *it = '/';
                }
                strEntry = strName;
                std::transform(strEntry.begin(), strEntry.end(), strEntry.begin(), tolower);
                m_setFiles.insert(strEntry);
            }
        }
    }
    return true;
}

// @0x140510f10
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
