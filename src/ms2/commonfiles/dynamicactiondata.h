// dynamicactiondata.h - CDynamicActionData (RTTI name): one row of korDynamicAction.xml (a skill that runs a dynamic
// action; "reserved" lists the action paths). The class keeps the rows, the set of default-on skill ids and the set of
// all listed skill ids as statics behind a lock. Header name assumed from the unit path; member names are invented from use.
// Proven (exe): CDynamicActionData is 0x58 bytes (CCacheData at +0, CValidData at +0x28).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptrvalue.h"

class Unk_140165cf0;    // xml element (declared where the loaders are)

// The pointer the statics hold to a skill id set: the same code as TPtrValue<std::set<unsigned>> (the exe has a second
// copy of every member for it, with no Make), so it is a class of its own here.
class Unk_DynSetRef
{
public:
    typedef std::set<unsigned> Set;
    Unk_DynSetRef() { m_p = 0; }                                        // 0x140347ba0
    Unk_DynSetRef(const Unk_DynSetRef& o) { m_p = o.m_p; AddRef(); }    // 0x140347b20
    Unk_DynSetRef(const TPtrValue<Set>& o) { m_p = o.get(); AddRef(); }   // 0x140347b60
    ~Unk_DynSetRef() { Release(); }                                     // 0x140347d60
    Unk_DynSetRef& operator=(const Unk_DynSetRef& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }   // 0x140347e40
    Set* operator->() const { return m_p; }                             // 0x140347f40
    int operator!() const { int r; if (m_p == 0) r = 1; else r = 0; return r; }   // 0x140347ec0

private:
    void AddRef() const { if (m_p) Reference(Owner(m_p)); }             // 0x1403488b0
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }            // 0x140348a10
    void ReleaseImpl(void*)                                             // 0x140348ad0
    {
        TPtredDummy<Set>* owner = Owner(m_p);
        if (CPtred::ReleasePtred(owner) == 0) {
            Reference(owner);
            CPtred::DeletePtred(owner);
        }
    }
    static void Reference(TPtredDummy<Set>* p) { CPtred::AddRefPtred(p); }
    static TPtredDummy<Set>* Owner(Set* p) { return p == 0 ? 0 : CONTAINING_RECORD(p, TPtredDummy<Set>, value); }

    void* m_00;
    Set* m_p;
};

// RTTI CDynamicActionData, 0x58 bytes.
class CDynamicActionData : public CCacheData, public CValidData<CDynamicActionData>
{
public:
    typedef Unk_DynSetRef SkillSet;

    CDynamicActionData();                       // 0x140346f60
    virtual ~CDynamicActionData();              // 0x140346ff0 (scalar deleting 0x140348000)

    static void Load();                         // 0x140347180 korDynamicAction.xml into the statics
    static MS2Ptr<CDynamicActionData> Find(int nSkillId);   // 0x140347050
    static void GetDefaults(ATL::CAtlArray<MS2Ptr<CDynamicActionData> >& rOut);   // 0x1403477b0 the rows with "default"
    static bool IsDefault(unsigned nSkillId);   // 0x140347890 skill id is in the default set
    static bool IsListed(unsigned nSkillId);    // 0x140347960 skill id is in the all-skills set
    static void CheckInit();                    // 0x1403481e0
    static void SetInit(bool b);                // 0x1403488a0

    int m_nDefault;                             // +0x30 "default"
    unsigned m_nSkillId;                        // +0x34 "skillID"
    ATL::CAtlArray<CStringW> m_reserved;        // +0x38 the "reserved" entries as "/<entry>"

    static bool s_bInit;                        // 0x143aad201
    static CLockCriticalSection s_lock;         // 0x143aad208
    static ATL::CAtlList<MS2Ptr<CDynamicActionData> > s_rows;   // 0x143aad238
    static SkillSet s_defaultSkills;            // 0x143aad268
    static SkillSet s_allSkills;                // 0x143aad278
};
MS2_CHECK_SIZE(CDynamicActionData, 0x58);
MS2_CHECK_OFFSET(CDynamicActionData, m_nDefault, 0x30);
MS2_CHECK_OFFSET(CDynamicActionData, m_reserved, 0x38);
