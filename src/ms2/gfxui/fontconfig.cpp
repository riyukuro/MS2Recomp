// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The GFx UI's copy of the Scaleform sample font config reader
// (ConfigParser / FontTranslator / FontConfig / FontConfigSet), with the Array / Hash / Ptr template glue it instantiates.
// MS2-UNIT: sfr_gfx_11
// MS2-RANGE: 0x1422f8c70-0x1422fe810 .text$mn
//
// The classes sit in the global namespace (RTTI .?AVFontConfig@@); layouts and semantics are in
// ms2/placeholder/fontconfigparser.h. The unit name is the queue's (sfr_gfx_11), the file name and directory are assumed.
#include "ms2/placeholder/ms2stdafx.h"

#include <stdio.h>

#include "ms2/placeholder/fontconfigparser.h"

#include "GFx/GFx_FontLib.h"
#include "Kernel/SF_SysFile.h"

using Scaleform::String;
using Scaleform::Array;
using Scaleform::Ptr;
using Scaleform::UByte;
using Scaleform::UInt16;
using Scaleform::SysFile;
using Scaleform::GFx::URLBuilder;
using Scaleform::GFx::Loader;
using Scaleform::GFx::FontMap;
using Scaleform::GFx::FontLib;
using Scaleform::GFx::MovieDef;
using Scaleform::GFx::Translator;
namespace Alg = Scaleform::Alg;

// @0x1422f8c70
// MS2-FUNCTIONAL: exe keeps an extra local layout (frame 0xb8 vs 0xa8) and 12 more callees in the file read; no source form found yet.
ConfigParser::ConfigParser(const char* pfilename)
{
    Pos = 0;
    Line = 1;

    // An absolute path remembers its parent path.
    ParentPath.AppendString(pfilename);
    URLBuilder::ExtractFilePath(&ParentPath);
    if (ParentPath.CompareNoCase(pfilename) == 0)
        ParentPath = "";

    SysFile file(String(pfilename), 0x21, 0x1b6);
    if (file.IsValid())
    {
        int flen = 0;
        flen = file.GetLength();
        if (flen != 0)
        {
            UByte* td = (UByte*)SF_ALLOC(flen, Stat_Default_Mem);
            file.Read(td, flen);

            UInt16* prefix16 = (UInt16*)td;
            if (prefix16[0] == Alg::ByteUtil::BEToSystem((UInt16)0xFFFE))
            {
                prefix16++;
                int numChars = (flen / 2) - 1;
                UInt16* chars = (UInt16*)SF_ALLOC(numChars * 2, Stat_Default_Mem);
                Buffer.Resize(numChars);
                for (int i = 0; i < numChars; i++)
                    chars[i] = Alg::ByteUtil::LEToSystem(prefix16[i]);
                Buffer.SetString((const wchar_t*)chars, numChars);
                SF_FREE(chars);
            }
            else if (prefix16[0] == Alg::ByteUtil::BEToSystem((UInt16)0xFEFF))
            {
                prefix16++;
                int numChars = (flen / 2) - 1;
                UInt16* chars = (UInt16*)SF_ALLOC(numChars * 2, Stat_Default_Mem);
                Buffer.Resize(numChars);
                for (int i = 0; i < numChars; i++)
                    chars[i] = Alg::ByteUtil::BEToSystem(prefix16[i]);
                Buffer.SetString((const wchar_t*)chars, numChars);
                SF_FREE(chars);
            }
            else if (flen > 2 && td[0] == 0xEF && td[1] == 0xBB && td[2] == 0xBF)
            {
                Buffer.SetString((char*)td + 3, Scaleform::UTF8Util::GetLength((char*)td + 3, flen - 3));
            }
            else
            {
                Buffer.SetString((char*)td, Scaleform::UTF8Util::GetLength((char*)td, flen));
            }

            SF_FREE(td);
        }
    }
}

// @0x1422f9200
ConfigParser::~ConfigParser()
{
}

// @0x1422f9240
ConfigParser::TokenType ConfigParser::NextToken(Token* ptoken)
{
    if (!IsValid() || Pos == (int)Buffer.GetLength())
        return ptoken->Set(Tok_EOF);

    SkipWhitespace();

    // Skip the EOF byte, if any.
    if (Buffer[Pos] == 0x1A)
    {
        Pos++;
        if (Pos == (int)Buffer.GetLength())
            return ptoken->Set(Tok_EOF);
    }

    // '\r\n' and '\n' end a line.
    if (Buffer[Pos] == '\r' && Buffer[Pos + 1] == '\n')
    {
        Line++;
        Pos += 2;
        return ptoken->Set(Tok_EOL, &Buffer[Pos - 2], 2);
    }
    if (Buffer[Pos] == '\n')
    {
        Line++;
        Pos++;
        return ptoken->Set(Tok_EOL, &Buffer[Pos - 1], 1);
    }

    if (IsFirstIdChar(Buffer[Pos]))
    {
        wchar_t* pstart = &Buffer[Pos];
        unsigned start = Pos;
        Pos++;
        while (Pos < (int)Buffer.GetLength() && IsNextIdChar(Buffer[Pos]))
            Pos++;
        return ptoken->Set(Tok_Id, pstart, Pos - start);
    }

    if (IsNumberChar(Buffer[Pos]))
    {
        wchar_t* pstart = &Buffer[Pos];
        unsigned start = Pos;
        bool sawDot = Buffer[Pos] == L'.';
        Pos++;
        while (Pos < (int)Buffer.GetLength() && IsNumberChar(Buffer[Pos]))
        {
            if (Buffer[Pos] == L'.')
            {
                if (sawDot)
                    break;
                sawDot = true;
            }
            Pos++;
        }
        return ptoken->Set(Tok_Number, pstart, Pos - start);
    }

    if (Buffer[Pos] == '\"')
    {
        Pos++;
        wchar_t* pstart = &Buffer[Pos];
        unsigned start = Pos;
        while (Pos < (int)Buffer.GetLength() && Buffer[Pos] != '\"')
            Pos++;
        if (Buffer[Pos] == '\"')
        {
            Pos++;
            return ptoken->Set(Tok_String, pstart, Pos - start - 1);
        }
        else
        {
            ptoken->Set(Tok_Error);
            ptoken->pError = "closing quote \" character expected";
            return ptoken->Type;
        }
    }

    // Anything else is a control character.
    Pos++;
    return ptoken->Set(Tok_Char, &Buffer[Pos - 1], 1);
}

// @0x1422f97b0
bool ConfigParser::TokenizeLine(TokenLine* ptokens, unsigned max)
{
    Token tok;
    ptokens->ErrorIndex = -1;
    ptokens->LineIndex = Line;
    ptokens->Tokens.Clear();

    do
    {
        NextToken(&tok);
        if (tok.Type == Tok_Error && ptokens->ErrorIndex == -1)
            ptokens->ErrorIndex = (int)ptokens->Tokens.GetSize();
        ptokens->Tokens.PushBack(tok);
    } while (tok.Type > Tok_EOF);

    return ptokens->Tokens.GetSize() > 1 || tok.Type != Tok_EOF;
}

// @0x1422f9880
bool ConfigParser::MatchLine(Array<Token>& tokens, const wchar_t* pformat, ...)
{
    va_list vl;
    va_start(vl, pformat);

    unsigned tokenIndex = 0;
    while (*pformat != 0)
    {
        if (tokenIndex >= tokens.GetSize())
        {
            va_end(vl);
            return 0;
        }

        Token& tok = tokens[tokenIndex];
        switch (*pformat)
        {
        case '%':
            if (*(pformat + 1) == 'i')
            {
                if (!tok.IsId(va_arg(vl, const wchar_t*)))
                {
                    va_end(vl);
                    return 0;
                }
            }
            else if (*(pformat + 1) == 's')
            {
                if (!tok.IsString())
                {
                    va_end(vl);
                    return 0;
                }
                String* pstr = va_arg(vl, String*);
                *pstr = tok.GetString();
            }
            else if (*(pformat + 1) == 'I')
            {
                if (!tok.IsId())
                {
                    va_end(vl);
                    return 0;
                }
                String* pstr = va_arg(vl, String*);
                *pstr = tok.GetString();
            }
            else if (*(pformat + 1) == 'n')
            {
                if (!tok.IsNumber())
                {
                    va_end(vl);
                    return 0;
                }
                float* pnumber = va_arg(vl, float*);
                *pnumber = tok.GetNumber();
            }
            pformat++;
            break;

        default:
            if (!tok.IsChar(*pformat))
            {
                va_end(vl);
                return 0;
            }
        }

        pformat++;
        tokenIndex++;
    }

    va_end(vl);

    // The last token must be a new line or the end of the file.
    if (tokenIndex >= tokens.GetSize())
        return 0;
    Token& tok = tokens[tokenIndex];
    if (tok.Type == Tok_EOL || tok.Type == Tok_EOF)
        return 1;
    return 0;
}

// @0x1422f9cd0
void FontTranslator::AddMapping(const String& key, const String& value)
{
    Mappings.Set(key, value);
}

// @0x1422f9d10
void FontTranslator::Translate(TranslateInfo* ptranslateInfo)
{
    String key;
    key = ptranslateInfo->GetKey();
    if (key.IsEmpty())
        return;
    String* pvalue = Mappings.Get(key);
    if (pvalue)
        ptranslateInfo->SetResultHtml(pvalue->ToCStr(), pvalue->GetSize());
}

// @0x1422f9dd0
void FontConfig::Apply(Loader* ploader)
{
    ploader->SetFontLib(0);
    ploader->SetFontMap(pFontMap.GetPtr());

    // A new translator forces the re-translation.
    ploader->SetTranslator(pTranslation);

    if (FontLibFiles.GetSize())
    {
        Ptr<FontLib> plib = *new FontLib;
        ploader->SetFontLib(plib);
        for (unsigned i = 0; i < FontLibFiles.GetSize(); i++)
        {
            Ptr<MovieDef> pdef = *ploader->CreateMovie(FontLibFiles[i], 0x40);
            if (pdef)
                plib->AddFontsFrom(pdef, 0);
        }
    }
}

// @0x1422f9fb0
FontConfigSet::FontConfigSet()
    : nCurrent(0)
{
}

// Decodes a font style word of a "map" line.
static FontMap::MapFontFlags UpdateFontFlags(FontMap::MapFontFlags flags, const String& symbol, unsigned lineIndex)
{
    FontMap::MapFontFlags newFlags = FontMap::MFF_Original;

    if (!symbol.CompareNoCase("bold"))
        newFlags = FontMap::MFF_Bold;
    else if (!symbol.CompareNoCase("normal"))
        newFlags = FontMap::MFF_Normal;
    else if (!symbol.CompareNoCase("italic"))
        newFlags = FontMap::MFF_Italic;
    else
    {
        fprintf(stderr, "Warning: FontConfig(%d) - unknown map font style '%s'\n", lineIndex, symbol.ToCStr());
        return flags;
    }

    if (flags == FontMap::MFF_Original)
    {
        flags = newFlags;
    }
    else if ((flags == FontMap::MFF_Normal && (newFlags & FontMap::MFF_BoldItalic) != 0) ||
             (newFlags == FontMap::MFF_Normal && (flags & FontMap::MFF_BoldItalic) != 0))
    {
        fprintf(stderr, "Warning: FontConfig(%d) - unexpected map font style '%s'\n", lineIndex, symbol.ToCStr());
    }
    else
    {
        flags = (FontMap::MapFontFlags)(newFlags | flags);
    }

    return flags;
}

// @0x1422f9ff0
void FontConfigSet::Parse(ConfigParser* pparser)
{
    typedef ConfigParser::Token Token;

    ConfigParser::TokenLine line;
    Array<Token>& tokens = line.Tokens;

    String s1, s2, s3, s4;

    Configs.Clear();
    if (!pparser->IsValid())
        return;

    while (pparser->TokenizeLine(&line, 6))
    {
        if (line.HasErrors())
        {
            fprintf(stderr, "Error: FontConfig(%d) - %s\n", line.LineIndex, tokens[line.ErrorIndex].pError);
            break;
        }

        // [FontConfig]
        if (ConfigParser::MatchLine(tokens, L"[%i]", L"FontConfig"))
        {
            Ptr<FontConfig> pfontConfig = *new FontConfig;
            pfontConfig->ConfigName = "Unnamed";
            Configs.PushBack(pfontConfig);
        }
        // [FontConfig "English"]
        else if (ConfigParser::MatchLine(tokens, L"[%i%s]", L"FontConfig", &s1))
        {
            Ptr<FontConfig> pfontConfig = *new FontConfig;
            pfontConfig->ConfigName = s1;
            Configs.PushBack(pfontConfig);
        }
        else
        {
            // Empty lines are fine.
            if (ConfigParser::MatchLine(tokens, L""))
                continue;

            if (Configs.GetSize() == 0)
            {
                fprintf(stderr, "Error: FontConfig(%d) - file mappings outside of [FontConfig] section\n",
                        line.LineIndex);
                break;
            }

            FontConfig* pconfig = Configs[Configs.GetSize() - 1];
            float scaleFactor = 1.0f;

            // map "Arial" = "tahoma"
            if (ConfigParser::MatchLine(tokens, L"%i%s=%s", L"map", &s1, &s2))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr());
            }
            // map "Arial" = "tahoma" Bold
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s%I", L"map", &s1, &s2, &s3))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                FontMap::MapFontFlags mapFlags = UpdateFontFlags(FontMap::MFF_Original, s3, line.LineIndex);
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr(), mapFlags);
            }
            // map "Arial" = "tahoma" 1.3
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s%n", L"map", &s1, &s2, &scaleFactor))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr(), FontMap::MFF_Original, scaleFactor);
            }
            // map "Arial" = "tahoma" Bold 1.3
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s%I%n", L"map", &s1, &s2, &s3, &scaleFactor))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                FontMap::MapFontFlags mapFlags = UpdateFontFlags(FontMap::MFF_Original, s3, line.LineIndex);
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr(), mapFlags, scaleFactor);
            }
            // map "Arial" = "tahoma" Bold Italic
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s%I%I", L"map", &s1, &s2, &s3, &s4))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                FontMap::MapFontFlags mapFlags = UpdateFontFlags(FontMap::MFF_Original, s3, line.LineIndex);
                mapFlags = UpdateFontFlags(mapFlags, s4, line.LineIndex);
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr(), mapFlags);
            }
            // map "Arial" = "tahoma" Bold Italic 1.3
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s%I%I%n", L"map", &s1, &s2, &s3, &s4, &scaleFactor))
            {
                if (!pconfig->pFontMap)
                    pconfig->pFontMap = *new FontMap;
                FontMap::MapFontFlags mapFlags = UpdateFontFlags(FontMap::MFF_Original, s3, line.LineIndex);
                mapFlags = UpdateFontFlags(mapFlags, s4, line.LineIndex);
                pconfig->pFontMap->MapFont(s1.ToCStr(), s2.ToCStr(), mapFlags, scaleFactor);
            }
            // fontlib "myfile.swf"
            else if (ConfigParser::MatchLine(tokens, L"%i%s", L"fontlib", &s1))
            {
                // The parent path of the config file is prepended.
                String path(pparser->ParentPath);
                path += s1;
                pconfig->FontLibFiles.PushBack(path);
            }
            // tr "Good morning" = "Guten Morgen"
            else if (ConfigParser::MatchLine(tokens, L"%i%s=%s", L"tr", &s1, &s2))
            {
                pconfig->pTranslation->AddMapping(s1, s2);
            }
            else
            {
                fprintf(stderr, "Error: FontConfig(%d) - unexpected statement\n", line.LineIndex);
                break;
            }
        }
    }
}

// @0x1422fac60
void FontConfigSet::AddMapping(const String& key, const String& value)
{
    FontConfig* pconfig = Configs[nCurrent];
    pconfig->pTranslation->AddMapping(key, value);
}

// @0x1422fbcf0
FontConfig::FontConfig()
{
    Provider = Provider_Undefined;
    pTranslation = *new FontTranslator();
}
