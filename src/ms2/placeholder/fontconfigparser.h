// fontconfigparser.h - PLACEHOLDER for the game's copy of the Scaleform sample "FontConfigParser" (Apps/Samples/Common/
// FontConfigParser.h of the GFx SDK, compiled into the GFx UI library as ?\fontconfig.cpp, 0x1422f8c70-0x1422fe810, not
// recovered yet). NOT an original header. The classes are in the global namespace (RTTI .?AVFontConfig@@,
// .?AVFontTranslator@@, Scaleform::RefCountBase<FontConfig,2>); layouts follow the SDK sample, checked against the exe:
// FontConfig::ConfigName +0x10, FontLibFiles +0x20, pFontMap +0x38, pTranslation +0x40 (FUN_1422f9dd0 / FUN_1422fac60);
// FontConfigSet is 0x20 bytes (`new` 0x20 in NiGFxLocalizeManager) with an MS2 current-config index at +0x18.
// The inline members (IsValid, GetSize, operator[]) are COMDATs of ?\nigfxlocalizemanager.cpp, their first user.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

#include <stdlib.h>

#include "Kernel/SF_Hash.h"
#include "Kernel/SF_WString.h"
#include "GFx/GFx_Loader.h"

// Reads a font config file (wide text) line by line (0x30 bytes, the frame of NiGFxLocalizeManager::FUN_1422eb570).
class ConfigParser
{
    Scaleform::WStringBuffer Buffer;    // +0x00
    int Pos;                            // +0x20
    unsigned Line;                      // +0x24

    void SkipWhitespace()
    {
        while (Pos < (int)Buffer.GetLength() && (Buffer[Pos] == L' ' || Buffer[Pos] == L'\t'))
            Pos++;
    }
    static bool IsFirstIdChar(wchar_t c) { return (c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z') || c == L'_'; }
    static bool IsNextIdChar(wchar_t c) { return IsFirstIdChar(c) || (c >= L'0' && c <= L'9'); }
    static bool IsNumberChar(wchar_t c) { return (c >= L'0' && c <= L'9') || c == L'.'; }
public:
    Scaleform::String ParentPath;       // +0x28

    ConfigParser(const char* pfilename);        // 0x1422f8c70
    ~ConfigParser();                            // 0x1422f9200

    // @0x1422ec2b0
    bool IsValid() const { return Buffer.GetLength() != 0; }

    enum TokenType
    {
        Tok_Error,
        Tok_EOL,
        Tok_EOF,
        Tok_Char,
        Tok_String,
        Tok_Id,
        Tok_Number
    };

    struct Token
    {
        TokenType Type;
        const wchar_t* pData;
        unsigned Length;
        const char* pError;

        TokenType Set(TokenType t, const wchar_t* pdata = 0, unsigned length = 0)
        {
            pError = "";
            Type = t;
            pData = pdata;
            Length = length;
            return t;
        }

        // Newlines are stripped (Flash multiline text uses \r).
        Scaleform::String GetString() const
        {
            if (pData)
            {
                Scaleform::String str;
                for (unsigned i = 0; i < Length; i++)
                {
                    if (pData[i] != '\n')
                        str.AppendChar(pData[i]);
                }
                return str;
            }
            else
            {
                return Scaleform::String();
            }
        }
        wchar_t GetChar() const { return pData ? pData[0] : 0; }
        float GetNumber() const
        {
            Scaleform::String s1;
            s1.AppendString(pData, Length);
            return (float)atof(s1.ToCStr());
        }
        bool IsId() const { return Type == Tok_Id; }
        bool IsString() const { return Type == Tok_String; }
        bool IsNumber() const { return Type == Tok_Number; }
        bool IsId(const wchar_t* pid) const
        {
            Scaleform::String s1, s2;
            s1.AppendString(pData, Length);
            s2.AppendString(pid);
            return Type == Tok_Id && Length == s2.GetLength() && !s1.CompareNoCase(s2);
        }
        bool IsChar(wchar_t c) const { return Type == Tok_Char && GetChar() == c; }
    };

    TokenType NextToken(Token* ptoken);                         // 0x1422f9240

    struct TokenLine
    {
        Scaleform::Array<Token> Tokens;     // +0x00
        int ErrorIndex;                     // +0x18
        unsigned LineIndex;                 // +0x1c

        bool HasErrors() { return ErrorIndex != -1; }
    };

    bool TokenizeLine(TokenLine* pline, unsigned max);          // 0x1422f97b0
    static bool MatchLine(Scaleform::Array<Token>& tokens, const wchar_t* pformat, ...);    // 0x1422f9880
};

// The translator of a font config: "tr" lines map a key to a replacement text.
class FontTranslator : public Scaleform::GFx::Translator
{
public:
    typedef Scaleform::Hash<Scaleform::String, Scaleform::String, Scaleform::String::HashFunctor> MappingHash;

    virtual unsigned GetCaps() const { return Cap_StripTrailingNewLines; }

    void AddMapping(const Scaleform::String& key, const Scaleform::String& value);      // 0x1422f9cd0
    void AddMappings(const MappingHash& mappings);
    virtual void Translate(TranslateInfo* ptranslateInfo);                              // 0x1422f9d10
private:
    MappingHash Mappings;               // +0x20
};

class FontConfig : public Scaleform::RefCountBase<FontConfig, Scaleform::Stat_Default_Mem>
{
public:
    enum ProviderType
    {
        Provider_Undefined,
        Provider_None,
        Provider_Win32,
        Provider_FT2
    };

    Scaleform::String ConfigName;                           // +0x10
    ProviderType Provider;                                  // +0x18
    Scaleform::ArrayLH<Scaleform::String> FontLibFiles;     // +0x20
    Scaleform::Ptr<Scaleform::GFx::FontMap> pFontMap;       // +0x38
    Scaleform::Ptr<FontTranslator> pTranslation;            // +0x40

    FontConfig();                                           // 0x1422fbcf0

    // Apply config settings to loader.
    void Apply(Scaleform::GFx::Loader* ploader);            // 0x1422f9dd0
};

class FontConfigSet
{
public:
    Scaleform::Array<Scaleform::Ptr<FontConfig> > Configs;  // +0x00
    int nCurrent;                                           // +0x18 MS2: the config FUN_1422ebf10 selected

    FontConfigSet();                                        // 0x1422f9fb0
    // Parse font configuration set.
    void Parse(ConfigParser* pparser);                      // 0x1422f9ff0
    // MS2: adds key -> value to the current config's translator.
    void AddMapping(const Scaleform::String& key, const Scaleform::String& value);   // 0x1422fac60

    // Array-style access
    // @0x1422ec290
    unsigned GetSize() const { return (unsigned)Configs.GetSize(); }
    // @0x1422ec0e0
    FontConfig* operator[](unsigned index) { return Configs[index]; }
};
MS2_CHECK_SIZE(ConfigParser, 0x30);
MS2_CHECK_SIZE(FontConfigSet, 0x20);
