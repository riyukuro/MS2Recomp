// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NiGFxLocalizeManager, the GFx UI's font configs and
// localized string table.
// MS2-UNIT: ?\nigfxlocalizemanager.cpp
// MS2-RANGE: 0x1422eb480-0x1422ec360 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). Tail: the inline FontConfigSet /
// ConfigParser members and the Scaleform Array<Ptr<FontConfig>> / Ptr<FontConfig> glue of `delete m_pConfigSet`.
#include "ms2/placeholder/ms2stdafx.h"

#include "nigfxlocalizemanager.h"

#include "GFx/GFx_FontLib.h"

#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/xmlattr.h"

#include "hook/ms2hook.h"

#pragma function(strcmp)     // the exe calls the CRT strcmp (0x14280f2b8)

void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const char* const& rArg);
CLogString* FUN_140166440();
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);    // FirstChildElement of a document

// @0x1422eb480
NiGFxLocalizeManager::NiGFxLocalizeManager()
    : m_pConfig(0), m_pConfigSet(0)
{
}

// @0x1422eb510
NiGFxLocalizeManager::~NiGFxLocalizeManager()
{
    FUN_1422ebe90();
}

// @0x1422eb570
bool NiGFxLocalizeManager::FUN_1422eb570(Scaleform::GFx::Loader* pLoader, const char* szPath, const CString& strConfig)
{
    Scaleform::Ptr<Scaleform::GFx::FontLib> spFontLib = pLoader->GetFontLib();
    if (spFontLib.GetPtr() == 0)
        return false;
    if (szPath == 0)
        return false;

    ConfigParser parser(szPath);
    if (!parser.IsValid())
    {
        FUN_1403a1280(FUN_140166440(), 2, 0x1a, L"Unable to load font config:{0}", szPath);
        return false;
    }

    FUN_1422ebe90();
    m_pConfigSet = new FontConfigSet;
    if (m_pConfigSet == 0)
        return false;
    m_pConfigSet->Parse(&parser);
    if (m_pConfigSet->GetSize() > 0)
    {
        FUN_1422ebb80(pLoader, strConfig);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422EB570, NiGFxLocalizeManager, FUN_1422eb570, 534, 0x3DE349A6);

// @0x1422eb790
void NiGFxLocalizeManager::FUN_1422eb790(const CString& strKey, const CStringW& strText)
{
    if (m_pConfigSet != 0)
    {
        Scaleform::String strKeyUtf8(strKey);
        m_pConfigSet->AddMapping(strKeyUtf8, Scaleform::String(strText));
    }
    m_strings.SetAt(strKey, strText);
}
MS2_REPLACE_METHOD(0x1422EB790, NiGFxLocalizeManager, FUN_1422eb790, 188, 0x3EEA964A);

// @0x1422eb860
CStringW NiGFxLocalizeManager::FUN_1422eb860(const CString& strKey)
{
    CStringW strText;
    if (!m_strings.Lookup(strKey, strText))
        return L"";
    return strText;
}
MS2_REPLACE_METHOD(0x1422EB860, NiGFxLocalizeManager, FUN_1422eb860, 183, 0x8BDB7639);

// @0x1422eb920
void NiGFxLocalizeManager::FUN_1422eb920()
{
    FUN_1422eb940();
}
MS2_REPLACE_METHOD(0x1422EB920, NiGFxLocalizeManager, FUN_1422eb920, 24, 0x56AAF3CF);

// @0x1422eb940
void NiGFxLocalizeManager::FUN_1422eb940()
{
    if (!ms_kXmlLoader1.IsNull())
    {
        TiXmlDocument doc;
        if (ms_kXmlLoader1(doc))
            FUN_1422ebc80(&doc, "value");
    }
    if (!ms_kXmlLoader2.IsNull())
    {
        TiXmlDocument doc;
        if (ms_kXmlLoader2(doc))
            FUN_1422ebc80(&doc, "name");
    }
    if (!ms_kXmlLoader3.IsNull())
    {
        TiXmlDocument doc;
        if (ms_kXmlLoader3(doc))
            FUN_1422ebc80(&doc, "name");
    }
    if (!ms_kXmlLoader4.IsNull())
    {
        TiXmlDocument doc;
        if (ms_kXmlLoader4(doc))
            FUN_1422ebc80(&doc, "value");
    }
}
MS2_REPLACE_METHOD(0x1422EB940, NiGFxLocalizeManager, FUN_1422eb940, 564, 0x9037D653);

// @0x1422ebb80
bool NiGFxLocalizeManager::FUN_1422ebb80(Scaleform::GFx::Loader* pLoader, const CString& strConfig)
{
    FontConfig* pConfig = FUN_1422ebf10(strConfig);
    if (pConfig != 0)
    {
        FUN_1422eb940();
        m_pConfig = pConfig;
        m_pConfig->Apply(pLoader);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422EBB80, NiGFxLocalizeManager, FUN_1422ebb80, 101, 0xB57A75CF);

// @0x1422ebbf0
CString NiGFxLocalizeManager::FUN_1422ebbf0()
{
    if (m_pConfig != 0)
        return m_pConfig->ConfigName.ToCStr();
    return "Default";
}
MS2_REPLACE_METHOD(0x1422EBBF0, NiGFxLocalizeManager, FUN_1422ebbf0, 126, 0x0CD82D0D);

// @0x1422ebc80
void NiGFxLocalizeManager::FUN_1422ebc80(TiXmlDocument* pDoc, CString strAttrName)
{
    Unk_140165cf0* pRoot = FUN_140165cf0(pDoc, "ms2");
    if (pRoot == 0)
        return;

    CString strKey;
    CStringW strText;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CString strLocale = FUN_14015f710(pNode, "locale", "");
        if (!strLocale.IsEmpty() && strLocale.CompareNoCase(ms_strLocale) != 0)
            continue;
        FUN_1408733e0(pNode, "id", strKey);
        if (FUN_140873420(pNode, strAttrName, strText) == 1)
        {
            strText = strKey;
        }
        else
        {
            strText.Replace(L"\\n", L"\n");
            strText.Replace(L"\\r", L"\r");
        }
        FUN_1422eb790(strKey, strText);
    }
}

// @0x1422ebe90
void NiGFxLocalizeManager::FUN_1422ebe90()
{
    delete m_pConfigSet;
    m_pConfig = 0;
    m_pConfigSet = 0;
    m_strings.RemoveAll();
}
MS2_REPLACE_METHOD(0x1422EBE90, NiGFxLocalizeManager, FUN_1422ebe90, 120, 0xA658EE2A);

// @0x1422ebf10
FontConfig* NiGFxLocalizeManager::FUN_1422ebf10(const CString& strConfig)
{
    if (m_pConfigSet == 0)
        return 0;
    for (unsigned int i = 0; i < m_pConfigSet->GetSize(); i++)
    {
        if (strcmp(strConfig, (*m_pConfigSet)[i]->ConfigName.ToCStr()) == 0)
        {
            m_pConfigSet->nCurrent = i;
            return (*m_pConfigSet)[i];
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422EBF10, NiGFxLocalizeManager, FUN_1422ebf10, 187, 0x7FAD41DA);

// MS2-PIN: ??_GNiGFxLocalizeManager@@UEAAPEAXI@Z 0x1422ec1a0
