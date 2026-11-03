// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client command line parser (/passport, /sid, /nexonsn, /arg,
// "-key:value" options, the debug defaults) and its globals. w378. Unit name assumed (the exe has no path for it).
// MS2-UNIT: unit_1414b1230
// MS2-RANGE: 0x1400f8990-0x1400f8b50 .text$di
// MS2-RANGE: 0x1414b1230-0x1414b2470 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <afx.h>
#include <atlcoll.h>
#include <stdlib.h>
#include <string.h>

#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// return types of the getters this unit calls
class Unk_LaunchOptions;

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define MS2_CMDBITS_ASSERT(line, expression)                                                                      \
    (void)((!!(expression)) ||                                                                                     \
           (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line), 0))

// ---- unit-local views of exe objects ----

// The option table "-key:value" -> value (ctor 0x1401635e0, dtor 0x140164300).
typedef ATL::CAtlMap<CString, CString, ATL::CStringElementTraitsI<CString>> Unk_CmdArgMap;
MS2_CHECK_SIZE(Unk_CmdArgMap, 0x48);

// The one byte bitset of the parser flags (commonfiles\bitset.inl: operator[] line 152, Set line 243). Same code as
// Unk_Bitset8 of gameeventbase.cpp for four bits.
struct Unk_CmdBitset;
struct Unk_CmdBitRef
{
    Unk_CmdBitRef& FUN_1414b2270(bool bValue);                  // 0x1414b2270 operator=
    Unk_CmdBitset* m_pBits;
    int m_nPos;
};
struct Unk_CmdBitset
{
    Unk_CmdBitset();                                            // 0x1414b2250
    Unk_CmdBitRef FUN_140c79bc0(int nPos);                      // operator[] (ms2clientplatformbase.cpp)
    Unk_CmdBitset& FUN_1414b22b0(unsigned nPos, bool bValue);   // Set
    void FUN_1414b23d0(bool bFill);                             // Fill
    void FUN_1414b2430();                                       // ClearUnusedBits
    unsigned char m_bits[1];
};
MS2_CHECK_SIZE(Unk_CmdBitset, 1);

// ---- out-of-unit callees ----
int FUN_14028c3e0(const CString& str, ATL::CAtlArray<CString>& rOut, const char* szSep, int nMax);   // split, at most nMax parts
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
void Unk_SplitImplA(CString& str, ATL::CAtlArray<CString>* pOut, const char* szSep);   // split
class Unk_LaunchOptions { public: void FUN_1406aef60(const CString& strKey, const CString& strValue); };
Unk_LaunchOptions* FUN_1406aeee0();
int FUN_1406c34c0();                                                            // the Nexon platform is on
class CFeatureManager { public: static void SetServerTypeName(CString strEnv); };   // C3: member view;                                             // "-env" / the default "Dev"
void FUN_140651190(CString strLocale);                                          // "-locale"
int FUN_140718170(const CString& strValue);                                         // a number or an enum name
bool FUN_140718390(const CString& strValue);                                 // a bool
class CFilePreload { public: static void FUN_141210ca0(bool bValue); };   // C3: member view;                                       // "-preloadAll"
void FUN_140650e70(CString strLanguage);                                        // "-language"
void FUN_140650b50(CString strLanguage);                                        // "-language" / "-voice"

// ---- this unit's functions (called from other units) ----
int FUN_1414b1230();                                                            // parse the command line: 0 = quit
CString FUN_1414b1380(int nUnused);
void FUN_1414b13f0(int nIndex, CString strArg);                                 // one argument
bool FUN_1414b1580(CString strKey);                                             // is the option given
int FUN_1414b15f0(CString strArg);                                             // "/passport:"
int FUN_1414b16b0(CString strArg);                                             // "/sid:"
int FUN_1414b1770(CString strArg);                                              // "/arg:"
int FUN_1414b18c0(CString strArg);                                             // "/nexonsn:"
void FUN_1414b1980();
int FUN_1414b1c40(CString strArg);                                 // "/CRASHDUMP:" check
void FUN_1414b1f10();                                                           // the "-key" options
void FUN_1414b21d0();                                                           // the debug defaults

// ---- header statics (dynamic initializers 0x1400f8990..0x1400f8b20) ----
#ifndef MS2_HOOK_DLL
Unk_CmdArgMap g_args(17, 0.75f, 0.25f, 2.25f, 10);
Unk_CmdBitset g_bits;
CString g_strServerAddr = "";
CString g_strNexonSn = "";
CString g_strPassport = "";
CString g_strSid = "";
CString g_strCmdLine = "";
// @0x1400f8af0
static CString s_strSkill = "skill";
// @0x1400f8b20
static CString s_strStun = "stun";
#else
extern Unk_CmdArgMap g_args;
extern Unk_CmdBitset g_bits;
extern CString g_strServerAddr;
extern CString g_strNexonSn;
extern CString g_strPassport;
extern CString g_strSid;
extern CString g_strCmdLine;
#endif

// ---- globals ----
int g_nArgc;
int g_nPort;
int g_bPortSet;
int g_nIgnorePack;
char g_bLanguageSet;
extern CString DAT_143af37a0;                                                     // set by "-id"
extern int g_nLogLevel;                                                         // set by "-logLevel"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1414b1230
int FUN_1414b1230()
{
    g_nArgc = __argc;
    for (int i = 0; i < g_nArgc; i++)
    {
        g_strCmdLine.AppendFormat("%s", __argv[i]);
        if (i != g_nArgc - 1)
            g_strCmdLine.Append(" ");
    }
    if (g_nArgc >= 1)
    {
        if (FUN_1414b1c40(CString(__argv[1])) != 0)
            return 0;
    }
    if (FUN_1406c34c0() == 0)
    {
        FUN_1414b21d0();
        if (g_nArgc >= 2)
        {
            for (int j = 1; j < g_nArgc; j++)
                FUN_1414b13f0(j, CString(__argv[j]));
        }
        FUN_1414b1f10();
    }
    return 1;
}

// @0x1414b1380
CString FUN_1414b1380(int)
{
    CString str("");
    return CString(str);
}

// @0x1414b13f0
void FUN_1414b13f0(int nIndex, CString strArg)
{
    if (strArg.IsEmpty())
        return;
    if (strArg[0] == '-')
    {
        ATL::CAtlArray<CString> tokens;
        FUN_14028c3e0(strArg, tokens, ":", 2);
        if (tokens.GetCount() >= 2)
        {
            reinterpret_cast<Unk_LaunchOptions*>(FUN_1406aeee0())->FUN_1406aef60(tokens[0], tokens[1]);
            g_args.SetAt((const char*)tokens[0], tokens[1]);
        }
    }
    else
    {
        switch (nIndex)
        {
        case 1:
            g_strServerAddr = strArg;
            break;
        case 2:
            g_nPort = atoi(strArg);
            break;
        }
    }
}

// @0x1414b1580
bool FUN_1414b1580(CString strKey)
{
    CString strValue;
    return g_args.Lookup(strKey, strValue);
}

// @0x1414b15f0
int FUN_1414b15f0(CString strArg)
{
    if (strArg.Find("/passport:", 0) != 0)
        return 0;
    CString strValue = strArg.Mid(10);
    g_strPassport = strValue;
    g_bits.FUN_140c79bc0(0).FUN_1414b2270(true);
    return 1;
}

// @0x1414b16b0
int FUN_1414b16b0(CString strArg)
{
    if (strArg.Find("/sid:", 0) != 0)
        return 0;
    CString strValue = strArg.Mid(5);
    g_strSid = strValue;
    g_bits.FUN_140c79bc0(1).FUN_1414b2270(true);
    return 1;
}

// @0x1414b1770
int FUN_1414b1770(CString strArg)
{
    if (strArg.Find("/arg:", 0) != 0)
        return 0;
    CString strRest = strArg.Mid(5);
    ATL::CAtlArray<CString> tokens;
    Unk_SplitA(const_cast<CStringA&>(strRest), (ATL::CAtlArray<CStringA>*)&(tokens), ",");
    int nCount = (int)tokens.GetCount();
    if (nCount == 2)
    {
        g_strServerAddr = tokens[0];
        g_nPort = atoi(tokens[1]);
        g_bPortSet = 1;
    }
    g_bits.FUN_140c79bc0(3).FUN_1414b2270(true);
    return 1;
}

// @0x1414b18c0
int FUN_1414b18c0(CString strArg)
{
    if (strArg.Find("/nexonsn:", 0) != 0)
        return 0;
    CString strValue = strArg.Mid(9);
    g_strNexonSn = strValue;
    g_bits.FUN_140c79bc0(2).FUN_1414b2270(true);
    return 1;
}

// @0x1414b1980
void FUN_1414b1980()
{
    for (int i = 0; i < __argc; i++)
    {
        CString strArg(__argv[i]);
        if (strArg[0] == '/')
        {
            ATL::CAtlArray<CString> tokens;
            Unk_SplitImplA(strArg, &tokens, ":");
            if (tokens.GetCount() >= 2)
            {
                if ((tokens[0]).CompareNoCase("/passport") == 0)
                    FUN_1414b15f0(CString(strArg));
                else if ((tokens[0]).CompareNoCase("/sid") == 0)
                    FUN_1414b16b0(CString(strArg));
                else if ((tokens[0]).CompareNoCase("/nexonsn") == 0)
                    FUN_1414b18c0(CString(strArg));
                else if ((tokens[0]).CompareNoCase("/arg") == 0)
                {
                    CString strAll(strArg);
                    for (int j = i + 1; j < __argc; j++)
                    {
                        strAll += " ";
                        strAll += __argv[j];
                    }
                    FUN_1414b1770(CString(strAll));
                    break;
                }
            }
        }
    }
}

// @0x1414b1c40
int FUN_1414b1c40(CString strArg)
{
    char szTag[12] = { 0 };
    szTag[0] = '/';
    szTag[1] = 'C';
    szTag[2] = 'R';
    szTag[3] = 'A';
    szTag[4] = 'S';
    szTag[5] = 'H';
    szTag[6] = 'D';
    szTag[7] = 'U';
    szTag[8] = 'M';
    szTag[9] = 'P';
    szTag[10] = ':';
    szTag[11] = '\0';
    char szKey[13] = { 0 };
    szKey[0] = 'E';
    szKey[1] = 'E';
    szKey[2] = '4';
    szKey[3] = 'C';
    szKey[4] = 'F';
    szKey[5] = 'C';
    szKey[6] = '6';
    szKey[7] = 'B';
    szKey[8] = '3';
    szKey[9] = 'B';
    szKey[10] = 'B';
    szKey[11] = '5';
    if (strArg.GetLength() < 0x17)
        return 0;
    if (strncmp(szTag, strArg, 0xb) != 0)
        return 0;
    CString strRest = strArg.Mid(0xb);
    if (strncmp(szKey, strRest, 0xc) != 0)
        return 0;
    __debugbreak();
    return 1;
}

// @0x1414b1f10
void FUN_1414b1f10()
{
    CString strValue;
    if (g_args.Lookup("-env", strValue))
        CFeatureManager::SetServerTypeName(CString(strValue));
    if (g_args.Lookup("-locale", strValue))
        FUN_140651190(CString(strValue));
    if (g_args.Lookup("-ip", strValue))
        g_strServerAddr = strValue;
    if (g_args.Lookup("-port", strValue))
        g_nPort = atoi(strValue);
    if (g_args.Lookup("-id", strValue))
        DAT_143af37a0 = strValue;
    if (g_args.Lookup("-ignorePack", strValue))
        g_nIgnorePack = FUN_140718170(strValue);
    if (g_args.Lookup("-preloadAll", strValue))
        CFilePreload::FUN_141210ca0(FUN_140718390(strValue));
    if (g_args.Lookup("-logLevel", strValue))
        g_nLogLevel = FUN_140718170(strValue);
    if (g_args.Lookup("-language", strValue))
    {
        FUN_140650e70(CString(strValue));
        FUN_140650b50(CString(strValue));
        g_bLanguageSet = 1;
    }
    if (g_args.Lookup("-voice", strValue))
        FUN_140650b50(CString(strValue));
}

// @0x1414b21d0
void FUN_1414b21d0()
{
    g_strPassport = "";
    g_strSid = "";
    g_strServerAddr = "127.0.0.1";
    g_nPort = 0x4e21;
    CFeatureManager::SetServerTypeName(CString("Dev"));
}

// @0x1414b2250
Unk_CmdBitset::Unk_CmdBitset()
{
    FUN_1414b23d0(false);
}

// @0x1414b2270
Unk_CmdBitRef& Unk_CmdBitRef::FUN_1414b2270(bool bValue)
{
    m_pBits->FUN_1414b22b0(m_nPos, bValue);
    return *this;
}

// @0x1414b22b0
Unk_CmdBitset& Unk_CmdBitset::FUN_1414b22b0(unsigned nPos, bool bValue)
{
    if (nPos >= 4) { MS2_CMDBITS_ASSERT(243, 0); }
    if (bValue)
        m_bits[(int)nPos / 8] |= 1 << ((int)nPos % 8);
    else
        m_bits[(int)nPos / 8] &= ~(1 << ((int)nPos % 8));
    return *this;
}

// @0x1414b23d0
void Unk_CmdBitset::FUN_1414b23d0(bool bFill)
{
    for (int i = 0; i >= 0; i--)
        m_bits[i] = bFill;
    if (bFill)
        FUN_1414b2430();
}

// @0x1414b2430
void Unk_CmdBitset::FUN_1414b2430()
{
    if (4 % 8)
    {
    }
    else
        m_bits[(4 - 1) / 8] &= (1 << (4 % 8)) - 1;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2d20-0x142cb2de0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142cb2de0-0x142cb2e20 .text$yd
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cb2de0 ; sft: byte-identical atexit thunks, paired by VA order
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cb2e00 ; sft: byte-identical atexit thunks, paired by VA order
