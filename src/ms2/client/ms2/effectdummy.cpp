// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See effectdummy.h.
// MS2-UNIT: ?\effectdummy.cpp
// MS2-RANGE: 0x140a50d40-0x140a52ef0 .text$mn
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x140a50f00 ; unique
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectdummy.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "effectdummy.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----

// TinyXML element of the game (TiXmlElement/TiXmlNode); only the two navigation calls used here.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);      // FirstChildElement
    Unk_140165cf0* NextSiblingElement();                    // NextSiblingElement
};
void FUN_1408733e0(Unk_140165cf0* pNode, const char* pszAttr, CString& strOut);
void FUN_1408730a0(Unk_140165cf0* pNode, const char* pszAttr, bool& bOut);
void FUN_1408746f0(Unk_140165cf0* pNode, const char* pszAttr, Unk_DummyVec3& vOut);
void FUN_140873360(Unk_140165cf0* pNode, const char* pszAttr, float& fOut);
bool FUN_1401c0090(const CString& a, const CString& b);     // CString equality

// @0x140a50d40
CEffectDummy::CEffectDummy()
    : m_fScale(1.0f), m_vRotation(0.0f, 0.0f, 0.0f), m_bApplyWorldTransform(false), m_bApplyLocalScale(true),
      m_vTranslate(0.0f, 0.0f, 0.0f)
{
}

// @0x140a50e00
CEffectDummy::CEffectDummy(const CEffectDummy& o)
{
    Assign(o);
}

// @0x140a50ea0
CEffectDummy::~CEffectDummy()
{
}

// @0x140a50f20
CEffectDummy& CEffectDummy::operator=(const CEffectDummy& o)
{
    Assign(o);
    return *this;
}

// @0x140a50f50
bool CEffectDummy::operator==(const CEffectDummy& o) const
{
    return FUN_1401c0090(m_strName, o.m_strName) & FUN_1401c0090(m_strParentNode, o.m_strParentNode) &
           (m_fScale == o.m_fScale) & (m_vTranslate == o.m_vTranslate) & (m_vRotation == o.m_vRotation) &
           (m_bApplyWorldTransform == o.m_bApplyWorldTransform) & (m_bApplyLocalScale == o.m_bApplyLocalScale);
}

// @0x140a510b0
bool CEffectDummy::operator!=(const CEffectDummy& o) const
{
    return !(*this == o);
}

// @0x140a51100
MS2SvrPtr<CEffectDummy> CEffectDummy::Clone() const
{
    MS2SvrPtr<CEffectDummy> p(new CEffectDummy(*this));
    return p;
}
MS2_REPLACE_METHOD(0x140A51100, CEffectDummy, Clone, 157, 0xF7AFFC88);

// @0x140a511b0
void CEffectDummy::Parse(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return;
    FUN_1408733e0(pNode, "name", m_strName);
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach)
    {
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
        FUN_1408730a0(pAttach, "applyWorldTransform", m_bApplyWorldTransform);
        FUN_1408730a0(pAttach, "applyLocalScale", m_bApplyLocalScale);
    }
    Unk_140165cf0* pXf = pNode->FUN_140165cf0("transform");
    if (pXf)
    {
        FUN_1408746f0(pXf, "translate", m_vTranslate);
        FUN_1408746f0(pXf, "rotation", m_vRotation);
        FUN_140873360(pXf, "scale", m_fScale);
    }
}
MS2_REPLACE_METHOD(0x140A511B0, CEffectDummy, Parse, 295, 0x2481F264);

// @0x140a512e0
void CEffectDummy::SetName(const CString& s)
{
    m_strName = s;
}
MS2_REPLACE_METHOD(0x140A512E0, CEffectDummy, SetName, 42, 0xD25DFA6B);

// @0x140a51310
void CEffectDummy::SetParentNode(const CString& s)
{
    m_strParentNode = s;
}
MS2_REPLACE_METHOD(0x140A51310, CEffectDummy, SetParentNode, 42, 0x02F7F5E3);

// @0x140a51340
void CEffectDummy::SetTranslate(const Unk_DummyVec3& v)
{
    m_vTranslate = v;
}
MS2_REPLACE_METHOD(0x140A51340, CEffectDummy, SetTranslate, 41, 0x8F8B7CFA);

// @0x140a51370
const CString& CEffectDummy::GetName() const
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x140A51370, CEffectDummy, GetName, 15, 0x3758D2A9);

// @0x140a51390
const CString& CEffectDummy::GetParentNode() const
{
    return m_strParentNode;
}
MS2_REPLACE_METHOD(0x140A51390, CEffectDummy, GetParentNode, 15, 0x676E38F1);

// @0x140a513b0
const Unk_DummyVec3& CEffectDummy::GetTranslate() const
{
    return m_vTranslate;
}
MS2_REPLACE_METHOD(0x140A513B0, CEffectDummy, GetTranslate, 15, 0x177FAFB9);

// @0x140a513d0
void CEffectDummy::Assign(const CEffectDummy& o)
{
    m_strName = o.m_strName;
    m_strParentNode = o.m_strParentNode;
    m_fScale = o.m_fScale;
    m_vTranslate = o.m_vTranslate;
    m_vRotation = o.m_vRotation;
    m_bApplyWorldTransform = o.m_bApplyWorldTransform;
    m_bApplyLocalScale = o.m_bApplyLocalScale;
}
MS2_REPLACE_METHOD(0x140A513D0, CEffectDummy, Assign, 179, 0x963C269D);

// @0x140a51490
EffectDummyGroup::EffectDummyGroup()
{
}

// @0x140a514e0
void EffectDummyGroup::FUN_140a514e0(TiXmlNode* pNode)
{
    for (Unk_140165cf0* pDummy = reinterpret_cast<Unk_140165cf0*>(pNode)->FUN_140165cf0("dummy"); pDummy != 0; pDummy = pDummy->NextSiblingElement())
    {
        DummyPtr p(new CEffectDummy);
        p->Parse(pDummy);
        m_dummies.push_back(p);
    }
}
MS2_REPLACE_METHOD(0x140A514E0, EffectDummyGroup, FUN_140a514e0, 215, 0xF53907CC);

// @0x140a515c0
void EffectDummyGroup::FUN_140a515c0()
{
    (void)m_dummies.size();
}
MS2_REPLACE_METHOD(0x140A515C0, EffectDummyGroup, FUN_140a515c0, 31, 0xF84B7AE2);

// @0x140a515f0
MS2SvrPtr<CEffectDummy> EffectDummyGroup::FUN_140a515f0(const CString& name)
{
    for (std::vector<DummyPtr>::iterator it = m_dummies.begin(); it != m_dummies.end(); ++it)
    {
        if (FUN_1401c0090((*it)->GetName(), name))
            return *it;
    }
    return DummyPtr(0);
}
MS2_REPLACE_METHOD(0x140A515F0, EffectDummyGroup, FUN_140a515f0, 228, 0xDF39596A);

// @0x140a516e0
bool EffectDummyGroup::FUN_140a516e0(unsigned int idx, void* pOut)
{
    if (idx < m_dummies.size())
    {
        *static_cast<CEffectDummy*>(pOut) = *m_dummies[idx];
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140A516E0, EffectDummyGroup, FUN_140a516e0, 103, 0xB77AC540);

