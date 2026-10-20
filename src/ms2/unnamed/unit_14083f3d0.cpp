// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). String utilities: substring replace, case-insensitive
// compare/find, URL encoding, hex and base64 text, and the "{0} {1:.2f}" wide text formatter (Unk_TextFormat).
// No __FILE__ in the range; all function names are invented (FUN_<va>, matching the callers' declarations).
// MS2-UNIT: unit_14083f3d0
// MS2-RANGE: 0x14083f3d0-0x140841580 .text$mn
// MS2-RANGE: 0x142c9c430-0x142c9c445 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/textformat.h"
#include <malloc.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iomanip>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_1401d3700(CStringA& str);                                      // MakeLower
void FUN_14025fab0(CStringW& str);                                      // MakeLower
CStringA FUN_1401d4330(const wchar_t* psz, int nCodePage);              // wide -> narrow
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);              // wide -> narrow
// The exe calls the imported wcslen (`call [__imp_wcslen]`); the headers declare it without dllimport.
extern "C" size_t (__cdecl* __imp_wcslen)(const wchar_t*);

#ifdef __clang__
// clang emits an unavailable MFC CopyChars DLL import for CString's operator+; bind the exe's copies.
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* psz);
CStringW FUN_1401d0080(const CStringW& str1, const CStringW& str2);
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);
inline CStringW Unk_Concat(const CStringW& str, const wchar_t* psz) { return FUN_14061ad70(str, psz); }
inline CStringW Unk_Concat(const CStringW& str1, const CStringW& str2) { return FUN_1401d0080(str1, str2); }
inline CStringW Unk_Concat(const wchar_t* psz, const CStringW& str) { return FUN_1401d0160(psz, str); }
#define MS2_CONCAT(a, b) Unk_Concat(a, b)
#else
#define MS2_CONCAT(a, b) ((a) + (b))
#endif

// Lower-cases a wide string (header inline; COMDAT at 0x140841420).
inline void FUN_140841420(CStringW& str)
{
    FUN_14025fab0(str);
}

// @0x14083f3d0
// Replaces nCount characters at nPos by strNew.
CStringW FUN_14083f3d0(const CStringW& str, int nPos, int nCount, const CStringW& strNew)
{
    std::wstring wstr(str);
    std::wstring wstrNew(strNew);
    wstr.replace(nPos, nCount, wstrNew);
    return CStringW(wstr.c_str());
}
MS2_REPLACE(0x14083F3D0, FUN_14083f3d0, 240, 0xE1C60247);

// @0x14083f4d0
// Case-insensitive compare (strcmp of the lower-cased copies).
int FUN_14083f4d0(CStringA strA, CStringA strB)
{
    FUN_1401d3700(strA);
    FUN_1401d3700(strB);
    return strcmp(strA, strB);
}
MS2_REPLACE(0x14083F4D0, FUN_14083f4d0, 138, 0xC8811D59);

// @0x14083f560
// URL-encodes a string: alphanumerics and @./\-_: are kept, everything else becomes %xx.
CStringA FUN_14083f560(CStringA str)
{
    CStringA strResult;
    if (str.IsEmpty())
        return CStringA("");
    char* pBuf = (char*)_alloca(strlen(str) * 3 + 1);
    if (pBuf == NULL)
        return CStringA("");
    int nOut, i;
    for (i = nOut = 0; str[i] != 0; i++)
    {
        unsigned char ch = str[i];
        if (ch >= '0' && ch <= '9')
            pBuf[nOut++] = ch;
        else if (ch >= 'A' && ch <= 'Z')
            pBuf[nOut++] = ch;
        else if (ch >= 'a' && ch <= 'z')
            pBuf[nOut++] = ch;
        else if (ch == '@' || ch == '.' || ch == '/' || ch == '\\' || ch == '-' || ch == '_' || ch == ':')
            pBuf[nOut++] = ch;
        else
        {
            char szHex[3];
            sprintf(szHex, "%02x", ch);
            pBuf[nOut++] = '%';
            pBuf[nOut++] = szHex[0];
            pBuf[nOut++] = szHex[1];
        }
    }
    pBuf[nOut] = 0;
    strResult = pBuf;
    return strResult;
}
MS2_REPLACE(0x14083F560, FUN_14083f560, 788, 0x4C1BBCBB);

// @0x14083f880
// Lower-case hex text of the bytes of a string.
std::string FUN_14083f880(std::string str)
{
    unsigned i = 0;
    unsigned nLen = str.length();
    std::stringstream ss;
    for (i = 0; i < nLen; i++)
    {
        ss << "0123456789abcdef"[str[i] >> 4];
        ss << "0123456789abcdef"[str[i] & 0xf];
    }
    return ss.str();
}

// @0x14083f9c0
// Hex text of a number.
std::string FUN_14083f9c0(unsigned long n)
{
    std::stringstream ss;
    ss << std::hex << n;
    return ss.str();
}
MS2_REPLACE(0x14083F9C0, FUN_14083f9c0, 147, 0x65E7CEF7);

// @0x14083fa60
// base64 encoding (the well-known public-domain base64_encode).
std::string FUN_14083fa60(const unsigned char* pBytes, unsigned int nLen)
{
    static const std::string s_base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (nLen--)
    {
        char_array_3[i++] = *(pBytes++);
        if (i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                ret += s_base64Chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; j < i + 1; j++)
            ret += s_base64Chars[char_array_4[j]];

        while (i++ < 3)
            ret += '=';
    }
    return ret;
}
MS2_REPLACE(0x14083FA60, FUN_14083fa60, 971, 0x9886EC44);

// @0x14083fe40
// Case-insensitive find (-1 if not found).
int FUN_14083fe40(CStringA str, CStringA strFind)
{
    FUN_1401d3700(str);
    FUN_1401d3700(strFind);
    return str.Find(strFind, 0);
}
MS2_REPLACE(0x14083FE40, FUN_14083fe40, 107, 0xB4A832D8);

// @0x14083fec0
// Case-insensitive find (-1 if not found).
int FUN_14083fec0(CStringW str, CStringW strFind)
{
    FUN_140841420(str);
    FUN_140841420(strFind);
    return str.Find(strFind, 0);
}
MS2_REPLACE(0x14083FEC0, FUN_14083fec0, 107, 0xCEE36DAB);

// @0x14083ff40
// Replaces every "{n}" (n = the next argument index) by pszArg and every "{n:fmt}" by pszArg formatted with
// "%fmt" (as a double when fmt ends in 'f', else as an __int64), then advances the argument index.
Unk_TextFormat& Unk_TextFormat::FUN_14083ff40(const wchar_t* pszArg)
{
    CStringW strTag;
    strTag.Format(L"{%d", m_nArg);
    int nTagLen = strTag.GetLength();
    int nStart = 0;
    while (true)
    {
        int nFind = m_str.Find(strTag, nStart);
        if (nFind == -1)
            break;
        int nEnd = m_str.Find(L"}", nFind + nTagLen);
        if (nEnd == -1)
            break;
        if (nFind + nTagLen == nEnd)
        {
            m_str = MS2_CONCAT(MS2_CONCAT(m_str.Left(nFind), pszArg), m_str.Mid(nEnd + 1));
            nStart += (int)__imp_wcslen(pszArg);
        }
        else if (m_str[nFind + nTagLen] == L':')
        {
            CStringW strFmt = m_str.Mid(nFind + nTagLen + 1, nEnd - (nFind + nTagLen + 1));
            CStringW strType = strFmt.Right(1);
            if (strType == "f")
                strFmt.Format(MS2_CONCAT(L"%", strFmt), atof(FUN_1401d4330(pszArg, 0)));
            else
                strFmt.Format(MS2_CONCAT(L"%", strFmt), _atoi64(FUN_1401d4330(pszArg, 0)));
            m_str = MS2_CONCAT(MS2_CONCAT(m_str.Left(nFind), strFmt), m_str.Mid(nEnd + 1));
            nStart += strFmt.GetLength();
        }
    }
    m_nArg++;
    return *this;
}
MS2_REPLACE_METHOD(0x14083FF40, Unk_TextFormat, FUN_14083ff40, 1506, 0xBE3734C8);

// @0x140840530
Unk_TextFormat& Unk_TextFormat::FUN_140840530(CStringW strArg)
{
    return FUN_14083ff40(strArg);
}
MS2_REPLACE_METHOD(0x140840530, Unk_TextFormat, FUN_140840530, 73, 0x41600FE9);

// @0x140840580
CStringA Unk_TextFormat::FUN_140840580() const
{
    return FUN_14016a600(m_str, 0);
}
MS2_REPLACE_METHOD(0x140840580, Unk_TextFormat, FUN_140840580, 73, 0xFC51BFCB);

// @0x1408405d0
CStringW Unk_TextFormat::FUN_1408405d0() const
{
    return m_str;
}
MS2_REPLACE_METHOD(0x1408405D0, Unk_TextFormat, FUN_1408405d0, 62, 0xB9C4D915);

// The <xlocale> helpers call strlen/wcslen as functions in the exe (imported wcslen); this build expands them
// inline, so they stay functional (pinned).
// MS2-PIN: ??$_Maklocstr@_W@std@@YAPEA_WPEBDPEA_WAEBU_Cvtvec@@@Z 0x140840d40
// MS2-FUNCTIONAL ??$_Maklocstr@_W@std@@YAPEA_WPEBDPEA_WAEBU_Cvtvec@@@Z: STL header code; strlen inlined as an intrinsic here, a call in the exe
// MS2-PIN: ?_Maklocwcs@std@@YAPEA_WPEB_W@Z 0x140841440
// MS2-FUNCTIONAL ?_Maklocwcs@std@@YAPEA_WPEB_W@Z: STL header code; wcslen inlined as an intrinsic here, an IAT call in the exe
