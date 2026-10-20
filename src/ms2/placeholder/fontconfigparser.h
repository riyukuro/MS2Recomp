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

#include "Kernel/SF_WString.h"

// Reads a font config file (wide text) line by line (0x30 bytes, the frame of NiGFxLocalizeManager::FUN_1422eb570).
class ConfigParser
{
    Scaleform::WStringBuffer Buffer;    // +0x00
    int Pos;                            // +0x20
    unsigned Line;                      // +0x24
public:
    Scaleform::String ParentPath;       // +0x28

    ConfigParser(const char* pfilename);        // 0x1422f8c70
    ~ConfigParser();                            // 0x1422f9200

    // @0x1422ec2b0
    bool IsValid() const { return Buffer.GetLength() != 0; }
};

class FontTranslator;

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
