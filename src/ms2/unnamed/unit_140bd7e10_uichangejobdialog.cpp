// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIChangeJobDialog: see unit_140bd7e10.h. w378.
// MS2-UNIT: unit_140bd7e10
// MS2-RANGE: 0x140bd7e10-0x140bd8ca0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140bd7e10.h"
#include <atlcoll.h>
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cchangejobtable.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// A row of the change job table (ChangeJobData). View only.
class Unk_CjData
{
public:
    unsigned char m_pad_00[4];
    int m_nJobCode;                                             // +0x04
    unsigned char m_pad_08[8];
    CString m_strMovie;                                         // +0x10 the movie path
    CStringW m_strDesc;                                         // +0x18
    CStringW m_strJobName;                                      // +0x20
    CStringW m_strSkillDesc1;                                   // +0x28
    CStringW m_strSkillDesc2;                                   // +0x30
    ATL::CAtlArray<unsigned int> m_skills1;                     // +0x38 the first skill list
    ATL::CAtlArray<unsigned int> m_skills2;                     // +0x58 the second skill list
};
MS2_CHECK_OFFSET(Unk_CjData, m_strMovie, 0x10);
MS2_CHECK_OFFSET(Unk_CjData, m_skills1, 0x38);
MS2_CHECK_OFFSET(Unk_CjData, m_skills2, 0x58);

// The 16 byte row handles (a pad and the pointer); the destructors / accessors are COMDATs of other units.
void FUN_1401d73f0(void* p);
struct Unk_CjRef
{
    ~Unk_CjRef() { FUN_1401d73f0(this); }
    Unk_CjData* FUN_1401d75d0() const;                          // operator->
    void* m_0; Unk_CjData* m_8;
};
bool FUN_140bd8af0(const Unk_CjRef* p);                         // the handle is empty (defined here)

// A skill row of the skill table (the icon path at +0x48). View only.
class Unk_CjSkillRow
{
public:
    unsigned char m_pad_00[0x48];
    CString m_strIcon;                                          // +0x48
};
MS2_CHECK_OFFSET(Unk_CjSkillRow, m_strIcon, 0x48);
void FUN_14063e5c0(void* p);
struct Unk_CjSkillRef
{
    ~Unk_CjSkillRef() { FUN_14063e5c0(this); }
    bool FUN_14063eab0(int nNull) const;                        // operator==
    Unk_CjSkillRow* FUN_14063ed50() const;                      // operator->
    void* m_0; void* m_8;
};
class Unk_CjSkillTable { public: Unk_CjSkillRef FUN_1407ee1d0(int nSkillId); };
Unk_CjSkillTable* FUN_1401958b0();

class Unk_CjTable
{
public:
    Unk_CjRef FUN_1401d6c30(int nJobCode);                      // the row of a job
    int FUN_1401d6ce0(int nJob, int nJobCode, unsigned short nLevel);    // may change
    int FUN_1401d6d70(int nJobCode);                            // the job to change to
};

// The job table rows (the change announcement). Views only.
class Unk_CjJobRow
{
public:
    int FUN_14074b030();
    unsigned char m_pad_00[0x2e8];
    int m_n2e8;                                                 // +0x2e8
};
MS2_CHECK_OFFSET(Unk_CjJobRow, m_n2e8, 0x2e8);
void FUN_14064d3e0(void* p);
struct Unk_CjJobRef
{
    ~Unk_CjJobRef() { FUN_14064d3e0(this); }
    bool FUN_14064d4e0() const;                                 // IsNull
    Unk_CjJobRow* FUN_14064d520() const;                        // operator->
    void* m_0; void* m_8;
};
Unk_CjJobRef FUN_14074bc40(int nJobCode);
void FUN_14078f140(void* p);
struct Unk_CjNotice
{
    ~Unk_CjNotice() { FUN_14078f140(this); }
    bool FUN_14085a420() const;                                 // IsNull
    void* m_0; void* m_8;
};
Unk_CjNotice FUN_1408564b0(int nId, int nRate);
struct Unk_CjIcon { unsigned char m[0x20]; };
Unk_CjIcon FUN_140859bc0(const Unk_CjNotice& kNotice);
class Unk_CjMsgSvc { public: void FUN_141b213f0(Unk_CjIcon kIcon, int nValue, int nA, int nB); };
Unk_CjMsgSvc* FUN_140967100();

// The local player: the world service hands out the actor; a few members used here.
class Unk_CjWorld { public: void* FUN_141bd0cc0(); };
Unk_CjWorld* FUN_1403ed2d0();
int FUN_141654730(PCBase* pPC);                                 // the player's job code
int FUN_141654700(PCBase* pPC);                                 // the player's job
class Unk_CjQuestMgr { public: int FUN_1416cae20(int nJobCode); };
Unk_CjQuestMgr* FUN_141523ba0(PCBase* pPC);

// ASObj / ASArray members used here only.
void FUN_1422bbb50(void* p, int nType);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// The change job table singleton (TSingleton<CChangeJobTable>::GetInstance, 0x140bd8b60).
#define CjTable() reinterpret_cast<Unk_CjTable*>(CChangeJobTable::GetInstance())

// @0x140bd7e10
UIChangeJobDialog::UIChangeJobDialog()
    : m_nJobCode(0)
{
    FUN_1401d7020(&m_map, 17, 0.75f, 0.25f, 2.25f, 10);
    m_2c = 0x23;
}

// @0x140bd7eb0
UIChangeJobDialog::~UIChangeJobDialog()
{
    FUN_1401d73c0(&m_map);
}

// @0x140bd7f00
CString UIChangeJobDialog::GetTypeName()
{
    return "ChangeJobDialog";
}

// @0x140bd7f50
void UIChangeJobDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PCBase* pPC = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    FUN_140bd8040(FUN_141654730(pPC));
}

// @0x140bd7fa0
int UIChangeJobDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onChangeJob", szMethod) == 0)
    {
        vfunc_67();
        FUN_140bd89d0(CjTable()->FUN_1401d6d70(m_nJobCode));
        return 1;
    }
    return 0;
}

// @0x140bd8040
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIChangeJobDialog::FUN_140bd8040(int nJobCode)
{
    if (m_30.IsNull())
        return;
    m_nJobCode = nJobCode;
    Unk_CjRef spData = CjTable()->FUN_1401d6c30(nJobCode);
    if (FUN_140bd8af0(&spData))
        return;

    ASObj obj(2);
    obj.FUN_140bd0d90("jobcode", spData.FUN_1401d75d0()->m_nJobCode);
    obj.FUN_1407cbb20("jobName", CStringW(spData.FUN_1401d75d0()->m_strJobName));
    obj.FUN_1407cbb20("desc", CStringW(spData.FUN_1401d75d0()->m_strDesc));
    obj.FUN_1407cbb20("skilldesc1", CStringW(spData.FUN_1401d75d0()->m_strSkillDesc1));
    obj.FUN_1407cbb20("skilldesc2", CStringW(spData.FUN_1401d75d0()->m_strSkillDesc2));
    obj.FUN_1407cba60("moviepath", CString(spData.FUN_1401d75d0()->m_strMovie));

    ASArray skills1(2);
    ASArray skills2(2);
    for (size_t i = 0; i < spData.FUN_1401d75d0()->m_skills1.GetCount(); i++)
    {
        Unk_CjSkillRef spSkill = FUN_1401958b0()->FUN_1407ee1d0(spData.FUN_1401d75d0()->m_skills1[i]);
        if (!spSkill.FUN_14063eab0(0))
        {
            ASObj skill(2);
            skill.FUN_1409c0d20("id", spData.FUN_1401d75d0()->m_skills1[i]);
            skill.FUN_1407cba60("icon", CString(spSkill.FUN_14063ed50()->m_strIcon));
            ASTooltip tooltip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x10, 2);
            if (tooltip.FUN_1409e1c50(spData.FUN_1401d75d0()->m_skills1[i], 1, 1) != 0)
                skill.FUN_1409adbe0("tooltip", tooltip.FUN_1422bb870());
            skills1.FUN_1422bc050(skill.FUN_1422bb870());
        }
    }
    for (size_t i = 0; i < spData.FUN_1401d75d0()->m_skills2.GetCount(); i++)
    {
        Unk_CjSkillRef spSkill = FUN_1401958b0()->FUN_1407ee1d0(spData.FUN_1401d75d0()->m_skills2[i]);
        if (!spSkill.FUN_14063eab0(0))
        {
            ASObj skill(2);
            skill.FUN_1409c0d20("id", spData.FUN_1401d75d0()->m_skills2[i]);
            skill.FUN_1407cba60("icon", CString(spSkill.FUN_14063ed50()->m_strIcon));
            ASTooltip tooltip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x10, 2);
            if (tooltip.FUN_1409e1c50(spData.FUN_1401d75d0()->m_skills2[i], 1, 1) != 0)
                skill.FUN_1409adbe0("tooltip", tooltip.FUN_1422bb870());
            skills2.FUN_1422bc050(skill.FUN_1422bb870());
        }
    }
    obj.FUN_1409adbe0("skills1", skills1.FUN_1422bb870());
    obj.FUN_1409adbe0("skills2", skills2.FUN_1422bb870());
    m_30->Invoke("setData", obj.FUN_1422bb870());
}

// @0x140bd88e0
// MS2-FUNCTIONAL: not byte-exact yet (call-result temporaries / argument copies differ)
int UIChangeJobDialog::FUN_140bd88e0()
{
    PCBase* pPC = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    unsigned short nLevel = (unsigned short)pPC->vfunc_78();
    int nJobCode = FUN_141654730(pPC);
    int nJob = FUN_141654700(pPC);
    if (CjTable()->FUN_1401d6ce0(nJob, nJobCode, nLevel) == 0)
        return 0;
    int nNext = CjTable()->FUN_1401d6d70(FUN_141654730(pPC));
    int nState = FUN_141523ba0(pPC)->FUN_1416cae20(nNext);
    if (nState == 1 || nState == 2)
        return 0;
    return 1;
}

// @0x140bd89d0
// MS2-FUNCTIONAL: not byte-exact yet (call-result temporaries / argument copies differ)
void UIChangeJobDialog::FUN_140bd89d0(int nJobCode)
{
    Unk_CjJobRef spJob = FUN_14074bc40(nJobCode);
    if (spJob.FUN_14064d4e0())
        return;
    Unk_CjNotice kNotice = FUN_1408564b0(spJob.FUN_14064d520()->FUN_14074b030(), 100);
    if (kNotice.FUN_14085a420())
        return;
    Unk_CjJobRow* pRow = spJob.FUN_14064d520();
    FUN_140967100()->FUN_141b213f0(FUN_140859bc0(kNotice), pRow->m_n2e8, 4, 0);
}

// @0x140bd8af0
bool FUN_140bd8af0(const Unk_CjRef* p)
{
    return p->m_8 == 0;
}

// @0x140bd8b70
int UIChangeJobDialog::vfunc_48()
{
    return 0x4f6b;
}
