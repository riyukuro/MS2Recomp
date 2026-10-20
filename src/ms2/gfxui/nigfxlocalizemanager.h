// nigfxlocalizemanager.h - NiGFxLocalizeManager (RTTI .?AVNiGFxLocalizeManager@@, base NiRefObject, vftable 0x143116d60,
// 2 slots: ??_G 0x1422ec1a0, DeleteThis; 0x68 bytes: ??_G deletes 0x68): the GFx UI's localization tables: the font
// config set (fontconfig.txt-style file, SDK FontConfigParser) and a map of AS string keys to localized text, read from
// four XML documents. Header name and directory assumed (the GFx UI library has no __FILE__ strings). The code is in
// nigfxlocalizemanager.cpp (?\nigfxlocalizemanager.cpp). Member names are Ghidra's (FUN_<va>); comments say what they do.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fontconfigparser.h"
#include "ms2/placeholder/tixmldocument.h"

class NiGFxLocalizeManager : public NiRefObject
{
public:
    NiGFxLocalizeManager();                                                     // 0x1422eb480
    virtual ~NiGFxLocalizeManager();                                            // 0 0x1422eb510

    // Parses the font config file szPath, selects config strConfig and applies it to pLoader (false if the
    // loader has no font lib, the file is missing or holds no config).
    bool FUN_1422eb570(Scaleform::GFx::Loader* pLoader, const char* szPath, const CString& strConfig);
    void FUN_1422eb790(const CString& strKey, const CStringW& strText);         // add a string (and a translator mapping)
    CStringW FUN_1422eb860(const CString& strKey);                              // the string of a key ("" if unknown)
    void FUN_1422eb920();                                                       // reload the XML string tables
    void FUN_1422eb940();                                                       // load the four XML string tables
    bool FUN_1422ebb80(Scaleform::GFx::Loader* pLoader, const CString& strConfig);   // select and apply a font config
    CString FUN_1422ebbf0();                                                    // the current config's name ("Default")
    void FUN_1422ebc80(TiXmlDocument* pDoc, CString strAttrName);               // read one XML string table (by value)
    void FUN_1422ebe90();                                                       // drop the configs and strings
    FontConfig* FUN_1422ebf10(const CString& strConfig);                        // find a font config by name (and select it)

    // The four XML documents (Delegate<bool(TiXmlDocument&)> statics; their dynamic initializers are in
    // unit_14013acc0.cpp, the library's shared .text$di) and the locale an XML entry must match (or be empty).
    static Delegate<bool(TiXmlDocument&)> ms_kXmlLoader1;                       // 0x143b0d7a0 ("value" attribute)
    static Delegate<bool(TiXmlDocument&)> ms_kXmlLoader2;                       // 0x143b0d7a8 ("name")
    static Delegate<bool(TiXmlDocument&)> ms_kXmlLoader3;                       // 0x143b0d7b0 ("name")
    static Delegate<bool(TiXmlDocument&)> ms_kXmlLoader4;                       // 0x143b0d7b8 ("value")
    static CString ms_strLocale;                                                // 0x143b0d798

private:
    MS2_LAYOUT_FRIEND;
    FontConfig* m_pConfig;                                                      // +0x10 the selected config
    FontConfigSet* m_pConfigSet;                                                // +0x18
    CAtlMap<CString, CStringW, CStringElementTraits<CString> > m_strings;      // +0x20 key -> text
};
MS2_CHECK_SIZE(NiGFxLocalizeManager, 0x68);
MS2_CHECK_OFFSET(NiGFxLocalizeManager, m_pConfigSet, 0x18);
MS2_CHECK_OFFSET(NiGFxLocalizeManager, m_strings, 0x20);
