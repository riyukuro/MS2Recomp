// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\randomeffectparam.cpp
// MS2-RANGE: 0x1416f44e0-0x1416f57c0 .text$mn
// MS2-PIN: ??_GCRandomEffect@@UEAAPEAXI@Z 0x1416f5040
// MS2-PIN: ??_GCRandomEffectParam@@UEAAPEAXI@Z 0x1416f50a0
// MS2-PIN: ??1CRandomEffectParam@@UEAA@XZ 0x1416f4ef0
// MS2-PIN: ??1Unk_WeightedPicker@@QEAA@XZ 0x1416f4eb0
// MS2-PIN: ?GetRTTI@CRandomEffect@@UEBAPEBVNiRTTI@@XZ 0x1416f5240
// MS2-PIN: ??$make_pair@AEAHAEBK@std@@YA?AU?$pair@HK@0@AEAHAEBK@Z 0x1416f4d80
// MS2-PIN: ??$?0AEAHAEBK$0A@@?$pair@HK@std@@QEAA@AEAHAEBK@Z 0x1416f4d20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\randomeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "randomeffectparam.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Game TinyXML element: FirstChildElement / NextSiblingElement by name.
class Unk_XmlNode   // C3: member view (real class not in this TU)
{
public:
    Unk_XmlNode* FirstChild(char const*);
    Unk_XmlNode* NextSibling(char const*);
};
class Unk_140165cf0
{
public:
};

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp) and string helpers (commonfiles).
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
CString FUN_140188f50(const char* psz, int n);                                          // null-safe CString
void FUN_140177e10(const CString& str, ATL::CAtlArray<DWORD>& arr, const char* pszDelim);  // split to uints

// Effect factory (effectservice): parse one <effect> element / create the runtime effect of a param.
CEffectParamPtr FUN_1411a04e0(const CString& strOwner, Unk_140165cf0* pNode);
CEffectPtr FUN_14119eae0(CEffectParam* pParam, Unk_EffectTarget* pTarget);

// Game log (commonfiles singleton 0x140166440).
class Unk_GameLog
{
public:
    void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
};
Unk_GameLog* FUN_140166440();

// Game context (singleton 0x1403ed280): random seed source.
class Unk_GameCtx
{
public:
    int FUN_1411a8e70();
};
Unk_GameCtx* FUN_1403ed280();

// @0x1416f5250
bool Unk_WeightedPicker::Build()
{
    m_mapCumulative.clear();
    m_nTotal = 0;
    MS2_FOR_EACH(const WeightMap::value_type& kWeight, m_mapWeights)
    {
        if (kWeight.second == 0)
            continue;
        m_nTotal += kWeight.second;
        int nKey = m_nTotal - 1;
        m_mapCumulative.insert(std::make_pair(nKey, kWeight.first));
    }
    return m_nTotal > 0;
}
MS2_REPLACE_METHOD(0x1416f5250, Unk_WeightedPicker, Build, 315, 0xA9494016);

// @0x1416f55b0
const unsigned int* Unk_WeightedPicker::Pick(Unk_Random& kRandom)
{
    if (m_nTotal == 0)
        return NULL;
    int nKey = kRandom.FUN_1407684c0() % m_nTotal;
    return &m_mapCumulative.lower_bound(nKey)->second;
}
MS2_REPLACE_METHOD(0x1416f55b0, Unk_WeightedPicker, Pick, 99, 0x4B8D267E);

// @0x1416f44e0
CRandomEffectParam::CRandomEffectParam()
    : CEffectParam(0xb)
{
}

// @0x1416f4540
void CRandomEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    CString strProb = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pNode))->Attribute("prob"), 0);
    FUN_140177e10(strProb, m_arrWeights, ", ");
    for (Unk_140165cf0* pChild = ((Unk_140165cf0*)((Unk_XmlNode*)(Unk_140165cf0*)(pNode))->FirstChild("effect")); pChild; pChild = ((Unk_140165cf0*)((Unk_XmlNode*)(Unk_140165cf0*)(pChild))->NextSibling("effect")))
    {
        CEffectParamPtr spParam = FUN_1411a04e0(m_str20, pChild);
        if (spParam.get())
            m_arrEffects.Add(spParam);
    }
}
MS2_REPLACE_METHOD(0x1416f4540, CRandomEffectParam, vfunc_1, 249, 0xC523B3A5);

// @0x1416f4640
bool CRandomEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (!m_arrEffects.GetCount())
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"데이터가 없습니다[RandomEffect - Effect count 0] [{0}]", m_str20);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416f4640, CRandomEffectParam, vfunc_2, 118, 0x00274852);

// @0x1416f46c0
bool CRandomEffectParam::vfunc_5(int n)
{
    if (!m_arrEffects.GetCount())
        return false;
    for (unsigned int i = 0; i < m_arrEffects.GetCount(); i++)
    {
        CEffectParamPtr spParam = m_arrEffects[i];
        if (!spParam->vfunc_5(n))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416f46c0, CRandomEffectParam, vfunc_5, 224, 0xE4E1AA76);

// @0x1416f47b0
CEffectPtr CRandomEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CRandomEffect;
}

// @0x1416f4850
CRandomEffect::CRandomEffect()
    : m_spEffect(NULL)
{
}

// @0x1416f48a0
CRandomEffect::~CRandomEffect()
{
}

// @0x1416f48e0
bool CRandomEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CRandomEffectParam* pRandom = static_cast<const CRandomEffectParam*>(pParam);
    unsigned int nIndex = 0;
    unsigned int nCount = (unsigned int)pRandom->m_arrEffects.GetCount();
    if (!nCount)
        return false;
    if (pTarget->m_nRandomIndex)
    {
        nIndex = pTarget->m_nRandomIndex % nCount;
    }
    else
    {
        Unk_WeightedPicker kPicker;
        for (unsigned int i = 0; i < pRandom->m_arrEffects.GetCount(); i++)
        {
            int nWeight = 0;
            if (pRandom->m_arrWeights.GetCount() > i)
                nWeight = pRandom->m_arrWeights[i];
            kPicker.Set(i, nWeight);
        }
        if (!kPicker.Build())
            return false;
        int nSeed = FUN_1403ed280()->FUN_1411a8e70();
        Unk_Random kRandom(nSeed);
        nIndex = *kPicker.Pick(kRandom);
    }
    const CEffectParamPtr& spParam = pRandom->m_arrEffects[nIndex];
    m_spEffect = FUN_14119eae0(spParam.get(), pTarget);
    if (m_spEffect == NULL)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1416f48e0, CRandomEffect, vfunc_3, 622, 0x5D44BBC8);

// @0x1416f4b60
bool CRandomEffect::vfunc_9()
{
    return m_spEffect->vfunc_9();
}

// @0x1416f4ba0
void CRandomEffect::vfunc_5()
{
    m_spEffect->vfunc_5();
}

// @0x1416f4be0
void CRandomEffect::vfunc_7()
{
    m_spEffect->vfunc_7();
}

// @0x1416f4c20
int CRandomEffect::vfunc_8(void* p)
{
    return m_spEffect->vfunc_8(p);
}

// @0x1416f4c70
void CRandomEffect::vfunc_10(bool b)
{
    m_spEffect->vfunc_10(b);
}

// @0x1416f4cc0
int CRandomEffect::vfunc_12()
{
    if (m_spEffect)
        return m_spEffect->vfunc_12();
    return 0xb;
}
