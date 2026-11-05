// effectdummy.h - CEffectDummy / EffectDummyGroup (RTTI names): one <dummy> row and the <group> that owns them,
// read from Table/defaultEffectDummy.xml. Header name assumed. Sizes from operator_new in the exe: CEffectDummy 0x50,
// EffectDummyGroup 0x30. Member names are invented from use (xml attribute names where they exist).
#pragma once
#include "ms2/ms2layout.h"
#include <afx.h>
#include <vector>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include <NiPoint3.h>

class TiXmlNode;
class TiXmlElement;   // game TinyXML element (see effectdummy.cpp)


class CEffectDummy : public CPtred
{
public:
    CEffectDummy();                                         // 0x140a50d40
    CEffectDummy(const CEffectDummy& o);                    // 0x140a50e00
    virtual ~CEffectDummy();                                // 0x140a50ea0, sdd 0x140a52600

    CEffectDummy& operator=(const CEffectDummy& o);         // 0x140a513d0 (FUN_140a50f20 is the wrapper that returns this)
    bool operator==(const CEffectDummy& o) const;           // 0x140a50f50
    bool operator!=(const CEffectDummy& o) const;           // 0x140a510b0
    MS2SvrPtr<CEffectDummy> Clone() const;                  // 0x140a51100
    void Assign(const CEffectDummy& o);                     // 0x140a513d0 (member-wise copy)
    void Parse(TiXmlElement* pNode);                           // 0x140a511b0: <dummy name> <attachInfo ...> <transform ...>
    void SetName(const CString& s);                         // 0x140a512e0
    void SetParentNode(const CString& s);                   // 0x140a51310
    void SetTranslate(const NiPoint3& v);              // 0x140a51340
    const CString& GetName() const;                         // 0x140a51370
    const CString& GetParentNode() const;                   // 0x140a51390
    const NiPoint3& GetTranslate() const;              // 0x140a513b0

    float m_fScale;                                         // +0x18 <transform scale>
    NiPoint3 m_vRotation;                              // +0x1c <transform rotation>
    bool m_bApplyWorldTransform;                            // +0x28 <attachInfo applyWorldTransform>
    bool m_bApplyLocalScale;                                // +0x29 <attachInfo applyLocalScale>
    CString m_strName;                                      // +0x30 <dummy name>
    CString m_strParentNode;                                // +0x38 <attachInfo parentNode>
    NiPoint3 m_vTranslate;                             // +0x40 <transform translate>
};
MS2_CHECK_SIZE(CEffectDummy, 0x50);
MS2_CHECK_OFFSET(CEffectDummy, m_strName, 0x30);
MS2_CHECK_OFFSET(CEffectDummy, m_vTranslate, 0x40);

// The exe's MS2SvrPtr<CEffectDummy> has a real copy ctor (copy + AddRef, 0x140a521d0) and a move ctor (steal, 0x140a521a0);
// the shared placeholder's non-const-lvalue "steal" ctor would pick the wrong one for `return *it` and push_back, so the
// class is specialised here with the same layout and the remaining members unchanged.
template <>
class MS2SvrPtr<CEffectDummy>
{
public:
    MS2SvrPtr() { m_p = 0; }
    MS2SvrPtr(int) { m_p = 0; }
    MS2SvrPtr(CEffectDummy* p) { m_p = p; AddRef(); }
    MS2SvrPtr(const MS2SvrPtr& o) { m_p = o.m_p; AddRef(); }
    MS2SvrPtr(MS2SvrPtr&& o) { m_p = o.m_p; o.m_p = 0; }
    ~MS2SvrPtr() { Release(); }
    MS2SvrPtr& operator=(const MS2SvrPtr& o)
    {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    MS2SvrPtr& operator=(CEffectDummy* p)
    {
        MS2SvrPtr tmp(p);
        CEffectDummy* old = m_p;
        m_p = tmp.m_p;
        tmp.m_p = old;
        return *this;
    }
    operator CEffectDummy*() const { return m_p; }
    CEffectDummy* operator->() const { return m_p; }
    CEffectDummy& operator*() const { return *m_p; }
    CEffectDummy* get() const { return m_p; }
    bool operator==(CEffectDummy* o) const { return m_p == o; }
    bool operator!() const { return m_p == 0; }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void AddRefImpl(void*) const { Reference(m_p); }
    static void Reference(CEffectDummy* p) { CPtred::AddRefPtred(p); }
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    void ReleaseImpl(void*)
    {
        if (CPtred::ReleasePtred(m_p) == 0)
        {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }
    void* m_unk_00;
    CEffectDummy* m_p;                  // +0x08
};
MS2_CHECK_SIZE(MS2SvrPtr<CEffectDummy>, 0x10);

class EffectDummyGroup : public CPtred
{
public:
    typedef MS2SvrPtr<CEffectDummy> DummyPtr;

    EffectDummyGroup();                                     // 0x140a51490

    void FUN_140a514e0(TiXmlNode* pNode);                   // builds the dummy list from the <dummy> children
    size_t FUN_140a515c0();                                 // list size (the callers use it as a count)
    MS2SvrPtr<CEffectDummy> FUN_140a515f0(const CString& name);   // lookup by name
    bool FUN_140a516e0(unsigned int idx, void* pOut);       // copies dummy [idx] into *pOut (a CEffectDummy)

    std::vector<DummyPtr> m_dummies;                        // +0x18
};
MS2_CHECK_SIZE(EffectDummyGroup, 0x30);
