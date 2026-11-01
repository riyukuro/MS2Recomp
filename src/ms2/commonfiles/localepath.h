// localepath.h - CLocaleLanguage / CLocaleLanguageData (RTTI names): the table of selectable game locales read from
// <Table>/gameOptionLocale.xml (<gameoptionlocale locale language region voice/>), plus the process-wide locale
// helpers (language / region code, code page, CRT locale). Header name assumed; member and helper names are invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One <gameoptionlocale> row. RTTI CLocaleLanguageData, 0x80 bytes;.
class CLocaleLanguageData : public CPtred
{
public:
    CLocaleLanguageData();                          // 0x14064ead0
    virtual ~CLocaleLanguageData();                 // 0x14064eb60

    int HasLanguageId(int nLanguage);               // does this row offer the language enum
    int HasLanguageCode(CString strCode);             // CompareNoCase search of the language codes (by value, callee frees)
    int GetDefaultLanguage();                            // first language code as an enum
    void GetLanguages(ATL::CAtlArray<int, ATL::CDefaultElementTraits<int>>& out);   // all language codes as enums
    void GetLanguageCodes(ATL::CAtlArray<CString>& out);   // all language codes, upper-cased
    void Clear();                           // clear

    CString m_strLocale;                            // +0x18 "locale"
    ATL::CAtlArray<CString> m_languages;            // +0x20 "language" (comma separated)
    ATL::CAtlArray<CString> m_regions;              // +0x40 "region"
    ATL::CAtlArray<CString> m_voices;               // +0x60 "voice"
};
MS2_CHECK_SIZE(CLocaleLanguageData, 0x80);
MS2_CHECK_OFFSET(CLocaleLanguageData, m_languages, 0x20);
MS2_CHECK_OFFSET(CLocaleLanguageData, m_voices, 0x60);

typedef MS2SvrPtr<CLocaleLanguageData> LocaleLanguageDataPtr;

// RTTI CLocaleLanguage: singleton holding the rows..
class CLocaleLanguage : public TSingleton<CLocaleLanguage>
{
public:
    CLocaleLanguage();                              // 0x14064efc0
    virtual ~CLocaleLanguage();                     // 0x14064f020

    LocaleLanguageDataPtr GetLocaleData(unsigned int nLocale);   // the row for the configured locale (0 = from options)
    int HasLanguageId(int nLanguage);
    int GetDefaultLanguage();
    void GetLanguages(ATL::CAtlArray<int, ATL::CDefaultElementTraits<int>>& out);
    void GetLanguageCodes(ATL::CAtlArray<CString>& out);
    int LoadGameOptionLocale();                            // load gameOptionLocale.xml

    ATL::CAtlArray<LocaleLanguageDataPtr> m_rows;   // +0x08
};
MS2_CHECK_SIZE(CLocaleLanguage, 0x28);
