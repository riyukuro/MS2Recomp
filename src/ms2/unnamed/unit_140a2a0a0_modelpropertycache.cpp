// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the model property cache. At start-up it
// reads every ./Data/Resource/Exported/Flat/*.flat file (<model name=...> with <mixin name=.../> parents and
// <property name=...><set index=.. value=../></property> rows) into model -> mixin set and model -> property -> value
// list maps; the typed getters (int/bool/float/vec3/string/npc spawn rows) read a property from the model's own xml
// element first and fall back to the cached values of the model and its mixins. Descriptive names are provisional.
// MS2-UNIT: unit_140a2a0a0
// MS2-RANGE: 0x140a2a0a0-0x140a2f540 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <stdlib.h>
#include "ms2/placeholder/fieldspawn.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/filesystem.h"
#include <efd/Point3.h>
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};


// The 16-byte CPtred pointer instantiated for the npc spawn rows (see TPtr<CFieldSpawnTag> in fieldspawn.h).
template<> class TPtr<CNpcSpawnData> {
public:
    TPtr() : p(0) {}
    TPtr(CNpcSpawnData* v) : p(v) { AddRef(); }
    TPtr(const TPtr& v) : p(v.p) { AddRef(); }
    ~TPtr() { Release(); }
    CNpcSpawnData* operator->() const { return p; }
private:
    static void Reference(CNpcSpawnData* v) { CPtred::AddRefPtred(v); }
    void AddRef() const { if(p) AddRefImpl((void*)0); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl((void*)0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(p)==0) { Reference(p); CPtred::DeletePtred(p); } }
    void* pad;
    CNpcSpawnData* p;
};
MS2_CHECK_SIZE(TPtr<CNpcSpawnData>,16);

typedef ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> > Unk_ValueList;
typedef ATL::CAtlMap<CStringA, int, ATL::CStringElementTraits<CStringA>, ATL::CElementTraits<int> > Unk_MixinSet;
typedef ATL::CAtlMap<CStringA, Unk_ValueList*, ATL::CStringElementTraits<CStringA>, ATL::CElementTraits<Unk_ValueList*> > Unk_PropMap;
typedef ATL::CAtlMap<CStringA, Unk_MixinSet*, ATL::CStringElementTraits<CStringA>, ATL::CElementTraits<Unk_MixinSet*> > Unk_MixinMap;
typedef ATL::CAtlMap<CStringA, Unk_PropMap*, ATL::CStringElementTraits<CStringA>, ATL::CElementTraits<Unk_PropMap*> > Unk_ModelMap;

class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3: was a local TiXml view; the shared reduced view has the same names
//
//
//
//
struct Unk_FlatFiles : public CFileSystem { };
void FUN_140399100(CStringA strExt, CStringA strDir, ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> >& arrFiles, CStringA strPrefix, bool bRecursive);
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
void FUN_14028c2d0(CStringA str, efd::Point3* pOut);
__int64 FUN_14028d260(float f);   // C3: the definition's __int64 return; the caller below reads it as int through an int(*)(float) cast (the exe keeps eax, no (int) temp)
CStringA FUN_140188f50(const char* psz, int nCodePage);
// The exe's CAtlArray<CStringA>::operator[] COMDAT copy used by the int/float property readers (same body as 0x140164930).
#ifdef MS2_HOOK_DLL
CStringA& FUN_1401c0cc0(Unk_ValueList* pArr, size_t i);
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" CStringA& __identifier("??A?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@_K@Z")(Unk_ValueList* pArr, size_t i);
#define FUN_1401c0cc0 __identifier("??A?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@_K@Z")
#endif

class Unk_ModelMgr
{
public:
    Unk_ModelMgr();                         // 0x140a2a0a0
    ~Unk_ModelMgr();                        // 0x140a2a140
    int FUN_140a2a180();                   // load every .flat file
    int FUN_140a2a920(const CStringA& strModel, CStringA strMixin);                // model is, or inherits, strMixin
    Unk_ValueList* FUN_140a2a9f0(CStringA strModel, const CStringA& strProp);       // cached values of a property
    int FUN_140a2aab0(TiXmlElement* pElem, CStringA strModel, const char* pszProp, ATL::CAtlArray<TPtr<CNpcSpawnData>, ATL::CElementTraits<TPtr<CNpcSpawnData> > >* pOut);
    int FUN_140a2afd0(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, efd::Point3* pOut);
    int FUN_140a2b270(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, int* pOut);
    int FUN_140a2b550(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, int* pOut);
    int FUN_140a2b790(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, float* pOut);
    int FUN_140a2b9d0(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, bool* pOut);
    int FUN_140a2bc30(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, CStringA* pOut);

    Unk_MixinMap m_mixins;      // +0x00
    Unk_ModelMap m_props;       // +0x48
    int m_bLoaded;              // +0x90
};
MS2_CHECK_OFFSET(Unk_ModelMgr, m_props, 0x48);
MS2_CHECK_SIZE(Unk_ModelMgr, 0x98);

// @0x140a2a0a0
Unk_ModelMgr::Unk_ModelMgr() : m_bLoaded(0) {}

// @0x140a2a140
Unk_ModelMgr::~Unk_ModelMgr() {}

// @0x140a2a180
int Unk_ModelMgr::FUN_140a2a180()
{
    m_mixins.RemoveAll();
    m_props.RemoveAll();
    ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> > arrFiles;
    FUN_140399100(CStringA(".flat"), CStringA("./Data/Resource/Exported/Flat/"), arrFiles, CStringA(""), false);
    for (unsigned i = 0; i < arrFiles.GetCount(); i++) {
        CStringA strFile = arrFiles[i];
        TiXmlDocument doc;
        if (((struct Unk_FlatFiles*)GetFileSystem())->FUN_1403974b0(&doc, strFile, 0, true, false) == 0)
            continue;
        TiXmlElement* pModel = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("model"));
        if (pModel == 0)
            return 0;
        const char* pszName = ((class TiXmlElement*)(class TiXmlElement*)(pModel))->Attribute("name");
        if (pszName == 0)
            continue;
        CStringA strModel(pszName);
        Unk_MixinSet* pMixins = 0;
        if (!m_mixins.Lookup(strModel, pMixins)) {
            pMixins = new Unk_MixinSet;
            m_mixins.SetAt(strModel, pMixins);
        }
        TiXmlElement* pMixin = 0;
        for (pMixin = ((class TiXmlElement*)((class Unk_XmlNode*)(pModel))->FirstChild("mixin")); pMixin != 0; pMixin = ((class TiXmlElement*)((class Unk_XmlNode*)(pMixin))->NextSibling("mixin"))) {
            const char* pszMixin = ((class TiXmlElement*)(class TiXmlElement*)(pMixin))->Attribute("name");
            if (pszMixin == 0)
                continue;
            CStringA strMixin(pszMixin);
            int nDummy;
            if (!pMixins->Lookup(strMixin, nDummy))
                pMixins->SetAt(strMixin, 0);
        }
        Unk_PropMap* pProps = 0;
        if (!m_props.Lookup(strModel, pProps)) {
            pProps = new Unk_PropMap;
            m_props.SetAt(strModel, pProps);
        }
        TiXmlElement* pProp = 0;
        for (pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pModel))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
            const char* pszProp = ((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name");
            if (pszProp == 0)
                continue;
            CStringA strProp(pszProp);
            Unk_ValueList* pValues = 0;
            if (!pProps->Lookup(strProp, pValues)) {
                pValues = new Unk_ValueList;
                pProps->SetAt(strProp, pValues);
            }
            for (TiXmlElement* pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set")); pSet != 0; pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pSet))->NextSibling("set"))) {
                const char* pszIndex = ((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("index");
                if (pszIndex != 0) {
                    CStringA strIndex(pszIndex);
                    pValues->Add(strIndex);
                }
                CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
                pValues->Add(strValue);
            }
        }
    }
    m_bLoaded = 1;
    return 1;
}

// @0x140a2a920
int Unk_ModelMgr::FUN_140a2a920(const CStringA& strModel, CStringA strMixin)
{
    if (strModel == strMixin)
        return 1;
    Unk_MixinSet* pMixins = 0;
    if (!m_mixins.Lookup(strModel, pMixins))
        return 0;
    int nDummy;
    return pMixins->Lookup(strMixin, nDummy);
}

// @0x140a2a9f0
Unk_ValueList* Unk_ModelMgr::FUN_140a2a9f0(CStringA strModel, const CStringA& strProp)
{
    Unk_PropMap* pProps = 0;
    if (m_props.Lookup(strModel, pProps) == true) {
        Unk_ValueList* pValues = 0;
        if (pProps->Lookup(strProp, pValues) == true)
            return pValues;
    }
    return 0;
}

// @0x140a2aab0
int Unk_ModelMgr::FUN_140a2aab0(TiXmlElement* pElem, CStringA strModel, const char* pszProp, ATL::CAtlArray<TPtr<CNpcSpawnData>, ATL::CElementTraits<TPtr<CNpcSpawnData> > >* pOut)
{
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        if ((strName == pszProp)) {
            for (TiXmlElement* pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set")); pSet != 0; pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pSet))->NextSibling("set"))) {
                TPtr<CNpcSpawnData> spData(new CNpcSpawnData);
                CStringA strIndex = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("index"), 0);
                spData->id = atoi(strIndex);
                ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> > arrValue;
                CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
                Unk_SplitA(strValue, (ATL::CAtlArray<CStringA>*)&(arrValue), ", ");
                if (arrValue.GetCount() > 0)
                    spData->count = atoi(arrValue[0]);
                if (arrValue.GetCount() > 1)
                    spData->probability = ((int (*)(float))FUN_14028d260)((float)atoi(arrValue[1]));
                pOut->Add(spData);
            }
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0) {
        for (size_t i = 0; i < pValues->GetCount(); i += 2) {
            TPtr<CNpcSpawnData> spData(new CNpcSpawnData);
            const CStringA& strId = FUN_1401c0cc0(pValues, i);
            spData->id = atoi(strId);
            const CStringA& strCount = FUN_1401c0cc0(pValues, i + 1);
            spData->count = atoi(strCount);
            pOut->Add(spData);
        }
        return 1;
    }
    return 0;
}

// @0x140a2afd0
int Unk_ModelMgr::FUN_140a2afd0(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, efd::Point3* pOut)
{
    pOut->x = 0.0f;
    pOut->y = 0.0f;
    pOut->z = 0.0f;
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
            FUN_14028c2d0(strValue, pOut);
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        CStringA strValue = FUN_1401c0cc0(pValues, 0);
        FUN_14028c2d0(strValue, pOut);
        return 1;
    }
    return 0;
}

// @0x140a2b270
int Unk_ModelMgr::FUN_140a2b270(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, int* pOut)
{
    *pOut = 0;
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"));
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            CStringA strValue(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"));
            if ((strValue == "False"))
                *pOut = 0;
            else if ((strValue == "True"))
                *pOut = 1;
            else
                *pOut = atoi(strValue);
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        CStringA strValue = (*pValues)[0];
        if ((strValue == "False"))
            *pOut = 0;
        else if ((strValue == "True"))
            *pOut = 1;
        else
            *pOut = atoi(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b550
int Unk_ModelMgr::FUN_140a2b550(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, int* pOut)
{
    *pOut = 0;
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
            *pOut = atoi(strValue);
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        CStringA strValue = (*pValues)[0];
        *pOut = atoi(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b790
int Unk_ModelMgr::FUN_140a2b790(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, float* pOut)
{
    *pOut = 0.0f;
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
            *pOut = (float)atof(strValue);
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        CStringA strValue = (*pValues)[0];
        *pOut = (float)atof(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b9d0
int Unk_ModelMgr::FUN_140a2b9d0(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, bool* pOut)
{
    *pOut = false;
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            CStringA strValue = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
            if ((strValue == "True"))
                *pOut = true;
            else
                *pOut = false;
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        CStringA strValue = FUN_1401c0cc0(pValues, 0);
        if ((strValue == "True"))
            *pOut = true;
        else
            *pOut = false;
        return 1;
    }
    return 0;
}

// @0x140a2bc30
int Unk_ModelMgr::FUN_140a2bc30(TiXmlElement* pElem, const CStringA& strModel, const char* pszProp, CStringA* pOut)
{
    *pOut = "";
    for (TiXmlElement* pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("property")); pProp != 0; pProp = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->NextSibling("property"))) {
        CStringA strName = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pProp))->Attribute("name"), 0);
        TiXmlElement* pSet;
        if ((strName == pszProp) && (pSet = ((class TiXmlElement*)((class Unk_XmlNode*)(pProp))->FirstChild("set"))) != 0) {
            *pOut = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pSet))->Attribute("value"), 0);
            return 1;
        }
    }
    CStringA strProp = pszProp;
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, strProp);
    if (pValues != 0 && pValues->GetCount() > 0) {
        *pOut = (*pValues)[0];
        return 1;
    }
    return 0;
}
