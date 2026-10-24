// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Locale-aware text helpers shared by the UI: date and
// date-time formatters (separator and field order depend on the client language), thousands/percent number text,
// a <tag> stripper, the localized-attribute lookup of "<ms2>" xml strings and the clipboard setters.
// MS2-UNIT: unit_14083bab0
// MS2-RANGE: 0x14083bab0-0x14083f3d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x14083f200 ; unique
// MS2-PIN: ??1?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x14083f240 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x14083f2e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetCount@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_KXZ 0x14083f320
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/tixmldocument.h"
#include <atlcoll.h>

int FUN_1406516a0();                                                    // client language (localepath.cpp)
void FUN_1406514e0(int nCountry, ATL::CAtlArray<int>& rLanguages);     // fallback language list of a country
CStringA FUN_1406522f0(int nLanguage);                                  // language code text
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);            // equals
CStringA FUN_14016a5c0(const char* psz, int n);
class Unk_Be790Xml;
Unk_Be790Xml* FUN_140345b40(TiXmlDocument* pDoc);                      // first child element
Unk_Be790Xml* FUN_140345b40(Unk_Be790Xml* pNode);
void FUN_140873420(Unk_Be790Xml* pElem, const char* pszName, CStringW& rOut);   // string attribute
class Unk_Be790Loader { public: int FUN_140397ab0(TiXmlDocument* pDoc, const CStringW& strXml); };
Unk_Be790Loader* FUN_140166420();
double FUN_1407184e0(const CStringW& str);                              // text -> number
long long FUN_140718320(const CStringW& str);
CStringW FUN_140719a00(long long n);                                    // integer text
CStringW FUN_1405dbf60(const wchar_t* pszFormat, const double& d);      // one double argument
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& n);        // one int argument
#include "ms2/commonfiles/commonutil.h"
CStringW FUN_1405c2690(CStringW strKey, CStringW strArg);               // localized string with an argument

extern int DAT_143ab0240;                                               // client language
extern int DAT_143ab0248;                                               // client country
extern CStringA DAT_143ab0250;                                          // xml attribute name of the localized text

CStringW FUN_14083da90(int nLang);
CStringW FUN_14083db10(int nLang);
CStringW FUN_14083dbc0(int nLang);
bool FUN_14083f280(const CStringW& str, wchar_t ch);
bool FUN_14083d7e0(const CStringW& str, const CStringW& strPrefix);

// @0x14083bab0
// Date text "<d1><sep><d2><sep><d3>"; the field order follows the language.
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep)
{
    int nLang = FUN_1406516a0();
    CStringW strOut;
    if (FUN_1403b3c40(strSep, L"/"))
        strSep = FUN_14083da90(nLang);
    if (nLang == 2)
    {
        int nYear = time.GetYear();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        strOut = StringFormat(L"{1:02d}{0}{2:02d}{0}{3:04d}", strSep, nMonth, nDay, nYear);
    }
    else if (nLang < 4 || nLang > 7)
    {
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        int nYear = time.GetYear();
        strOut = StringFormat(L"{1:04d}{0}{2:02d}{0}{3:02d}", strSep, nYear, nMonth, nDay);
    }
    else
    {
        int nYear = time.GetYear();
        int nMonth = time.GetMonth();
        int nDay = time.GetDay();
        strOut = StringFormat(L"{1:02d}{0}{2:02d}{0}{3:04d}", strSep, nDay, nMonth, nYear);
    }
    return strOut;
}

// @0x14083bdc0
// Date and time text; bShort24 selects the 24-hour clock (no AM/PM suffix).
CStringW FUN_14083bdc0(const CMsTime& time, char bShort24, CStringW strDateSep, CStringW strTimeSep)
{
    unsigned nUnused = 0;
    int nLang = FUN_1406516a0();
    CStringW strOut;
    int nHour = 0;
    CStringW strAmPm;
    strDateSep = FUN_14083da90(nLang);
    if (bShort24 == 0)
    {
        if (time.GetHour() < 13)
        {
            nHour = time.GetHour();
            strAmPm = L"AM";
        }
        else
        {
            nHour = time.GetHour();
            nHour = nHour - 12;
            strAmPm = L"PM";
        }
    }
    else
    {
        nHour = time.GetHour();
    }
    if (nLang == 2)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nYear = time.GetYear();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d} {8}", strDateSep, strTimeSep, nMonth, nDay, nYear, nHour, nMinute, nSecond, strAmPm);
    }
    else if (nLang > 3 && nLang < 7)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour24 = time.GetHour();
        int nYear = time.GetYear();
        int nMonth = time.GetMonth();
        int nDay = time.GetDay();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d}", strDateSep, strTimeSep, nDay, nMonth, nYear, nHour24, nMinute, nSecond);
    }
    else if (nLang == 7)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nYear = time.GetYear();
        int nMonth = time.GetMonth();
        int nDay = time.GetDay();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d} {8}", strDateSep, strTimeSep, nDay, nMonth, nYear, nHour, nMinute, nSecond, strAmPm);
    }
    else
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour24 = time.GetHour();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        int nYear = time.GetYear();
        strOut = StringFormat(L"{2:04d}{0}{3:02d}{0}{4:02d} {5:02d}{1}{6:02d}{1}{7:02d}", strDateSep, strTimeSep, nYear, nMonth, nDay, nHour24, nMinute, nSecond);
    }
    nUnused |= 1;
    return strOut;
}

// @0x14083c410
// Date and time text with a 12-hour clock whose hour is formatted separately.
CStringW FUN_14083c410(const CMsTime& time, CStringW strDateSep, CStringW strTimeSep)
{
    unsigned nUnused = 0;
    int nLang = FUN_1406516a0();
    CStringW strOut;
    CStringW strHour;
    CStringW strAmPm;
    strDateSep = FUN_14083da90(nLang);
    if (time.GetHour() < 13)
    {
        int nHour = time.GetHour();
        strHour = FUN_1401ceea0(L"{0}", nHour);
        strAmPm = L"AM";
    }
    else
    {
        int nHour = time.GetHour();
        nHour = nHour - 12;
        strHour = FUN_1401ceea0(L"{0}", nHour);
        strAmPm = L"PM";
    }
    if (nLang == 2)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nYear = time.GetYear();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d} {8}", strDateSep, strTimeSep, nMonth, nDay, nYear, strHour, nMinute, nSecond, strAmPm);
    }
    else if (nLang > 3 && nLang < 7)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour24 = time.GetHour();
        int nYear = time.GetYear();
        int nMonth = time.GetMonth();
        int nDay = time.GetDay();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d}", strDateSep, strTimeSep, nDay, nMonth, nYear, nHour24, nMinute, nSecond);
    }
    else if (nLang == 7)
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nYear = time.GetYear();
        int nMonth = time.GetMonth();
        int nDay = time.GetDay();
        strOut = StringFormat(L"{2:02d}{0}{3:02d}{0}{4:04d} {5:02d}{1}{6:02d}{1}{7:02d} {8}", strDateSep, strTimeSep, nDay, nMonth, nYear, strHour, nMinute, nSecond, strAmPm);
    }
    else
    {
        int nSecond = time.GetSecond();
        int nMinute = time.GetMinute();
        int nHour24 = time.GetHour();
        int nDay = time.GetDay();
        int nMonth = time.GetMonth();
        int nYear = time.GetYear();
        strOut = StringFormat(L"{2:04d}{0}{3:02d}{0}{4:02d} {5:02d}{1}{6:02d}{1}{7:02d}", strDateSep, strTimeSep, nYear, nMonth, nDay, nHour24, nMinute, nSecond);
    }
    nUnused |= 1;
    return strOut;
}

// @0x14083cb20
// Inserts the thousands separator into a number text (the decimal point becomes the language's decimal separator).
CStringW FUN_14083cb20(const CStringW& str)
{
    int nLen = str.GetLength();
    int nDot = str.Find(L".", 0);
    int nInt = nLen;
    if (nDot > -1)
        nInt = nDot;
    if (nInt < 4 && nLen == nInt)
        return str;
    CStringW strOut(str);
    if (nInt < nLen)
        strOut.SetAt(nInt, FUN_14083dbc0(DAT_143ab0240)[0]);
    strOut.Preallocate(nLen + nLen / 3);
    CStringW strSep = FUN_14083db10(DAT_143ab0240);
    int nPos;
    while ((nPos = nInt - 3) > 0)
    {
        strOut.Insert(nPos, strSep.GetString());
        nInt = nPos;
    }
    return strOut;
}

// @0x14083ccf0
// Re-renders a typed number text: strips the thousands separators and formats it again.
CStringW FUN_14083ccf0(const CStringW& str)
{
    unsigned nUnused = 0;
    CStringW strDigits;
    CStringW strSep = FUN_14083dbc0(DAT_143ab0240);
    bool bFraction = false;
    for (int i = 0; i < str.GetLength(); ++i)
    {
        wchar_t ch = str.GetAt(i);
        if ((char)ch < '0' || '9' < (char)ch)
        {
            if ((char)ch == '-' && i == 0)
                strDigits.AppendChar(L'-');
            else if (FUN_14083f280(strSep, ch))
            {
                strDigits.AppendChar(ch);
                bFraction = true;
            }
        }
        else
            strDigits.AppendChar(ch);
    }
    CStringW strOut;
    if (bFraction)
    {
        double d = FUN_1407184e0(strDigits);
        strOut = FUN_1405dbf60(L"{0}", d);
    }
    else
    {
        strOut = FUN_140719a00(FUN_140718320(strDigits));
    }
    nUnused |= 1;
    return strOut;
}

// @0x14083cf10
CStringW FUN_14083cf10(const CStringW& str)
{
    return FUN_14083ccf0(str);
}

// @0x14083cf50
// Percent text of a value in hundredths ("12.5%"); bLocalized wraps it in the s_common_percent string.
CStringW FUN_14083cf50(int nValue, char bLocalized)
{
    int nFrac = nValue % 100;
    int nInt = nValue / 100;
    if (nFrac < 1)
    {
        CStringW strFormat = bLocalized == 0 ? CStringW(L"{0}") : GetStringCommonByKey(CStringW(L"s_common_percent"));
        return FUN_1401ceea0(strFormat, nInt);
    }
    CStringW strNumber = StringFormat(L"{0}.{1}", nInt, nFrac);
    double d = FUN_1407184e0(strNumber);
    CStringW strFixed = FUN_1405dbf60(L"{0:.2f}", d);
    CStringW strOut = bLocalized == 0 ? CStringW(strFixed) : FUN_1405c2690(CStringW(L"s_common_percent"), strFixed);
    return strOut;
}

// @0x14083d2b0
// Removes every <...> tag from the text.
void FUN_14083d2b0(CStringW& str)
{
    int nOpen;
    int nClose;
    while ((nOpen = str.Find(L"<", 0)) != -1 && (nClose = str.Find(L">", nOpen + 1)) != -1)
        str.Delete(nOpen, nClose - nOpen + 1);
}

// @0x14083d340
// For "<ms2>" xml text: the first child element's localized attribute (the client language, then its fallbacks).
CStringW FUN_14083d340(CStringW str)
{
    if (!FUN_14083d7e0(str, CStringW(L"<ms2>")))
        return str;
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, str) == 0)
        return str;
    Unk_Be790Xml* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return str;
    Unk_Be790Xml* pElem = FUN_140345b40(pRoot);
    if (pElem == NULL)
        return str;
    CStringW strText;
    FUN_140873420(pElem, FUN_14016a5c0(DAT_143ab0250, 0), strText);
    if (!strText.IsEmpty())
        return strText;
    ATL::CAtlArray<int> arrLang;
    FUN_1406514e0(DAT_143ab0248, arrLang);
    for (unsigned i = 0; i < arrLang.GetCount(); ++i)
    {
        int nLang = arrLang[i];
        CStringA strName = FUN_1406522f0(nLang);
        FUN_140873420(pElem, FUN_14016a5c0(strName, 0), strText);
        if (!strText.IsEmpty())
            return strText;
    }
    return str;
}

// @0x14083d7e0
// str starts with strPrefix.
bool FUN_14083d7e0(const CStringW& str, const CStringW& strPrefix)
{
    if (str.GetLength() < strPrefix.GetLength())
        return false;
    for (int i = 0; i < strPrefix.GetLength(); ++i)
    {
        if (str[i] != strPrefix[i])
            return false;
    }
    return true;
}

// @0x14083d890
bool FUN_14083d890(CStringW str)
{
    if (!OpenClipboard(NULL))
        return false;
    if (!EmptyClipboard())
        return false;
    HGLOBAL hMem = GlobalAlloc(0, (SIZE_T)(str.GetLength() + 1) << 1);
    lstrcpyW((LPWSTR)hMem, str.GetString());
    if (SetClipboardData(CF_UNICODETEXT, hMem) == NULL)
    {
        CloseClipboard();
        GlobalFree(hMem);
        return false;
    }
    CloseClipboard();
    return true;
}

// @0x14083d990
bool FUN_14083d990(CStringA str)
{
    if (!OpenClipboard(NULL))
        return false;
    if (!EmptyClipboard())
        return false;
    HGLOBAL hMem = GlobalAlloc(0, (SIZE_T)(str.GetLength() + 1));
    lstrcpyA((LPSTR)hMem, str.GetString());
    if (SetClipboardData(CF_TEXT, hMem) == NULL)
    {
        CloseClipboard();
        GlobalFree(hMem);
        return false;
    }
    CloseClipboard();
    return true;
}

// @0x14083da90
// Date separator of a language.
CStringW FUN_14083da90(int nLang)
{
    if (nLang == 5)
        return CStringW(L".");
    return CStringW(L"/");
}

// @0x14083db10
// Thousands separator of a language.
CStringW FUN_14083db10(int nLang)
{
    if (nLang == 4)
        return CStringW(L" ");
    if (nLang < 5 || nLang > 6)
        return CStringW(L",");
    return CStringW(L".");
}

// @0x14083dbc0
// Decimal separator of a language.
CStringW FUN_14083dbc0(int nLang)
{
    if (nLang < 5 || nLang > 6)
        return CStringW(L".");
    return CStringW(L",");
}

// @0x14083f280
bool FUN_14083f280(const CStringW& str, wchar_t ch)
{
    return str.GetLength() == 1 && str[0] == ch;
}

// @0x14083f330
// The text between the first ch1 and the next ch2.
CStringW FUN_14083f330(const CStringW& str, wchar_t ch1, wchar_t ch2)
{
    int nFirst = str.Find(ch1, 0);
    int nSecond = str.Find(ch2, nFirst);
    return str.Mid(nFirst + 1, nSecond - nFirst - 1);
}
