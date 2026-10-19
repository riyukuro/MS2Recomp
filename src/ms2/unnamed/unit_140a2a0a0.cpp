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

class Unk_CommonVec3;
class TiXmlElement;
TiXmlElement* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);
struct Unk_FlatFiles { int FUN_1403974b0(TiXmlDocument*, const char*, int, bool, bool); };
Unk_FlatFiles* FUN_140166420();
void FUN_140399100(CStringA strExt, CStringA strDir, ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> >& arrFiles, CStringA strPrefix, bool bRecursive);
void FUN_14015f050(CStringA& str, ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> >& arrOut, const char* pszDelim);
void FUN_14028c2d0(CStringA str, Unk_CommonVec3* pOut);
int FUN_14028d260(float f);
bool FUN_140184310(const CStringA& str, const char* psz);
CStringA FUN_140188f50(const char* psz, int nCodePage);

class Unk_ModelMgr
{
public:
    Unk_ModelMgr();                         // 0x140a2a0a0
    ~Unk_ModelMgr();                        // 0x140a2a140
    int FUN_140a2a180();                   // load every .flat file
    int FUN_140a2a920(const CStringA& strModel, CStringA strMixin);                // model is, or inherits, strMixin
    Unk_ValueList* FUN_140a2a9f0(CStringA strModel, const CStringA& strProp);       // cached values of a property
    int FUN_140a2aab0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, ATL::CAtlArray<TPtr<CNpcSpawnData>, ATL::CElementTraits<TPtr<CNpcSpawnData> > >* pOut);
    int FUN_140a2afd0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, Unk_CommonVec3* pOut);
    int FUN_140a2b270(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, int* pOut);
    int FUN_140a2b550(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, int* pOut);
    int FUN_140a2b790(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, float* pOut);
    int FUN_140a2b9d0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, bool* pOut);
    int FUN_140a2bc30(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, CStringA* pOut);

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
        if (FUN_140166420()->FUN_1403974b0(&doc, strFile, 0, true, false) == 0)
            continue;
        Unk_140165cf0* pModel = reinterpret_cast<Unk_140165cf0*>(FUN_140165cf0(&doc, "model"));
        if (pModel == 0)
            return 0;
        const char* pszName = FUN_14086f4b0(pModel, "name");
        if (pszName == 0)
            continue;
        CStringA strModel(pszName);
        Unk_MixinSet* pMixins = 0;
        if (!m_mixins.Lookup(strModel, pMixins)) {
            pMixins = new Unk_MixinSet;
            m_mixins.SetAt(strModel, pMixins);
        }
        for (Unk_140165cf0* pMixin = pModel->FUN_140165cf0("mixin"); pMixin != 0; pMixin = pMixin->FUN_140168650("mixin")) {
            const char* pszMixin = FUN_14086f4b0(pMixin, "name");
            if (pszMixin != 0) {
                CStringA strMixin(pszMixin);
                int nDummy;
                if (!pMixins->Lookup(strMixin, nDummy))
                    pMixins->SetAt(strMixin, 0);
            }
        }
        Unk_PropMap* pProps = 0;
        if (!m_props.Lookup(strModel, pProps)) {
            pProps = new Unk_PropMap;
            m_props.SetAt(strModel, pProps);
        }
        for (Unk_140165cf0* pProp = pModel->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
            const char* pszProp = FUN_14086f4b0(pProp, "name");
            if (pszProp != 0) {
                CStringA strProp(pszProp);
                Unk_ValueList* pValues = 0;
                if (!pProps->Lookup(strProp, pValues)) {
                    pValues = new Unk_ValueList;
                    pProps->SetAt(strProp, pValues);
                }
                for (Unk_140165cf0* pSet = pProp->FUN_140165cf0("set"); pSet != 0; pSet = pSet->FUN_140168650("set")) {
                    const char* pszIndex = FUN_14086f4b0(pSet, "index");
                    if (pszIndex != 0) {
                        CStringA strIndex(pszIndex);
                        pValues->Add(strIndex);
                    }
                    CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
                    pValues->Add(strValue);
                }
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
int Unk_ModelMgr::FUN_140a2aab0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, ATL::CAtlArray<TPtr<CNpcSpawnData>, ATL::CElementTraits<TPtr<CNpcSpawnData> > >* pOut)
{
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        if (FUN_140184310(strName, pszProp)) {
            for (Unk_140165cf0* pSet = pProp->FUN_140165cf0("set"); pSet != 0; pSet = pSet->FUN_140168650("set")) {
                TPtr<CNpcSpawnData> spData(new CNpcSpawnData);
                CStringA strIndex = FUN_140188f50(FUN_14086f4b0(pSet, "index"), 0);
                spData->id = atoi(strIndex);
                ATL::CAtlArray<CStringA, ATL::CElementTraits<CStringA> > arrValue;
                CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
                FUN_14015f050(strValue, arrValue, ",");
                if (arrValue.GetCount() != 0)
                    spData->count = atoi(arrValue[0]);
                if (arrValue.GetCount() > 1)
                    spData->probability = FUN_14028d260((float)atoi(arrValue[1]));
                pOut->Add(spData);
            }
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues == 0)
        return 0;
    for (size_t i = 0; i < pValues->GetCount(); i += 2) {
        TPtr<CNpcSpawnData> spData(new CNpcSpawnData);
        spData->id = atoi((*pValues)[i]);
        spData->count = atoi((*pValues)[i + 1]);
        pOut->Add(spData);
    }
    return 1;
}

// @0x140a2afd0
int Unk_ModelMgr::FUN_140a2afd0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, Unk_CommonVec3* pOut)
{
    memset(pOut, 0, 12);
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
            FUN_14028c2d0(strValue, pOut);
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        CStringA strValue = (*pValues)[0];
        FUN_14028c2d0(strValue, pOut);
        return 1;
    }
    return 0;
}

// @0x140a2b270
int Unk_ModelMgr::FUN_140a2b270(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, int* pOut)
{
    *pOut = 0;
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName(FUN_14086f4b0(pProp, "name"));
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            CStringA strValue(FUN_14086f4b0(pSet, "value"));
            if (FUN_140184310(strValue, "False"))
                *pOut = 0;
            else if (FUN_140184310(strValue, "True"))
                *pOut = 1;
            else
                *pOut = atoi(strValue);
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        CStringA strValue = (*pValues)[0];
        if (FUN_140184310(strValue, "False"))
            *pOut = 0;
        else if (FUN_140184310(strValue, "True"))
            *pOut = 1;
        else
            *pOut = atoi(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b550
int Unk_ModelMgr::FUN_140a2b550(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, int* pOut)
{
    *pOut = 0;
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
            *pOut = atoi(strValue);
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        CStringA strValue = (*pValues)[0];
        *pOut = atoi(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b790
int Unk_ModelMgr::FUN_140a2b790(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, float* pOut)
{
    *pOut = 0.0f;
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
            *pOut = (float)atof(strValue);
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        CStringA strValue = (*pValues)[0];
        *pOut = (float)atof(strValue);
        return 1;
    }
    return 0;
}

// @0x140a2b9d0
int Unk_ModelMgr::FUN_140a2b9d0(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, bool* pOut)
{
    *pOut = false;
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            CStringA strValue = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
            *pOut = FUN_140184310(strValue, "True");
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        CStringA strValue = (*pValues)[0];
        *pOut = FUN_140184310(strValue, "True");
        return 1;
    }
    return 0;
}

// @0x140a2bc30
int Unk_ModelMgr::FUN_140a2bc30(Unk_140165cf0* pElem, CStringA strModel, const char* pszProp, CStringA* pOut)
{
    *pOut = "";
    for (Unk_140165cf0* pProp = pElem->FUN_140165cf0("property"); pProp != 0; pProp = pProp->FUN_140168650("property")) {
        CStringA strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
        Unk_140165cf0* pSet;
        if (FUN_140184310(strName, pszProp) && (pSet = pProp->FUN_140165cf0("set")) != 0) {
            *pOut = FUN_140188f50(FUN_14086f4b0(pSet, "value"), 0);
            return 1;
        }
    }
    Unk_ValueList* pValues = FUN_140a2a9f0(strModel, CStringA(pszProp));
    if (pValues != 0 && pValues->GetCount() != 0) {
        *pOut = (*pValues)[0];
        return 1;
    }
    return 0;
}
