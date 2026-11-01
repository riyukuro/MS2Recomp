// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTailEffectDataTable: Table/tailEffect.xml.
// MS2-UNIT: ?\taileffectdatatable.cpp
// MS2-RANGE: 0x1408533a0-0x140854ea0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\taileffectdatatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "taileffectdatatable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
unsigned char FUN_1401d1320(CCacheData*);

// @0x1408533a0
CTailEffectDataTable::CTailEffectDataTable()
{
}

// @0x140853430
CTailEffectDataTable::~CTailEffectDataTable()
{
}

// @0x140853480
bool CTailEffectDataTable::Reload()
{
    if (!Load())
        return false;
    return true;
}

// @0x1408534b0
bool CTailEffectDataTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "tailEffect.xml");
    m_cache.FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(reinterpret_cast<Unk_140165cf0*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
        return false;
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("tailEffect")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("tailEffect")))
    {
        DataPtr data(new TailEffectData);
        XmlGetAttr((class TiXmlElement*)(pNode), "id", data->m_nId);
        XmlGetAttr((class TiXmlElement*)(pNode), "effectPath", data->m_strEffectPath);
        XmlGetAttr((class TiXmlElement*)(pNode), "endEffectPath", data->m_strEndEffectPath);
        XmlGetAttr((class TiXmlElement*)(pNode), "distance", data->m_fDistance);
        XmlGetAttr((class TiXmlElement*)(pNode), "speed", data->m_fSpeed);
        m_map.SetAt(data->m_nId, data);
    }
    return true;
}

// @0x1408537c0
CTailEffectDataTable::DataPtr CTailEffectDataTable::GetData(int nId)
{
    if (FUN_1401d1320(&m_cache) != 0)
        Load();
    DataPtr data;
    if (!m_map.Lookup(nId, data))
        return DataPtr(0);
    return data;
}

// @0x140853ad0
TailEffectData::TailEffectData()
{
}

// ~TailEffectData (0x140853be0) is implicit.

// @0x140854d80
MS2_EMIT_CRT_MEMMOVE_S();
