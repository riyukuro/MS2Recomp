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
#include "ms2/commonfiles/changejobtable.h"
#include "ms2/commonfiles/talkscript.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_141654700 / FUN_141658e60

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The 16 byte row handle: the null test below reads the pointer directly.
struct Unk_CjRef { void* m_0; ChangeJobData* m_8; };
bool FUN_140bd8af0(const Unk_CjRef* p);                         // the handle is empty (defined here)

// A skill row of the skill table (the icon path at +0x48). View only.
class Unk_CjSkillRow
{
public:
    unsigned char m_pad_00[0x48];
    CString m_strIcon;                                          // +0x48
};
MS2_CHECK_OFFSET(Unk_CjSkillRow, m_strIcon, 0x48);
// The job table rows (the change announcement). Views only.
class Unk_CjJobRow
{
public:
    unsigned char m_pad_00[0x2e8];
    int m_n2e8;                                                 // +0x2e8
};
MS2_CHECK_OFFSET(Unk_CjJobRow, m_n2e8, 0x2e8);
MS2Ptr<CQuestData> FUN_14074bc40(int nJobCode);
int FUN_14074b030(CQuestData* pData);
Unk_ScriptPtr<CTalkScript> FUN_1408564b0(int nId, int nRate);
class UITalkManager { public: unsigned FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound); };
class Unk_AkoCutscene   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoCutscene* GetInstance();
};


// ASObj / ASArray members used here only.
void FUN_1422bbb50(void* p, int nType);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140bd7e10
UIChangeJobDialog::UIChangeJobDialog()
    : m_nJobCode(0)
{
    m_2c = 0x23;
}

// @0x140bd7eb0
UIChangeJobDialog::~UIChangeJobDialog()
{
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
    PCBase* pPC = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    FUN_140bd8040(reinterpret_cast<PC*>(pPC)->FUN_141654730());
}

// @0x140bd7fa0
int UIChangeJobDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onChangeJob", szMethod) == 0)
    {
        vfunc_67();
        FUN_140bd89d0(CChangeJobTable::GetInstance()->GetStartQuestId((Unk_SubJobCode)m_nJobCode));
        return 1;
    }
    return 0;
}

// @0x140bd8040
void UIChangeJobDialog::FUN_140bd8040(int nJobCode)
{
    if (m_30.IsNull())
        return;
    m_nJobCode = nJobCode;
    Unk_SocketPtr<ChangeJobData> spData = CChangeJobTable::GetInstance()->Get((Unk_SubJobCode)nJobCode);
    if (FUN_140bd8af0(reinterpret_cast<const Unk_CjRef*>(&spData)))
        return;

    ASObj obj(2);
    obj.FUN_140bd0d90("jobcode", spData->m_nChangeSubJobCode);
    obj.FUN_1407cbb20("jobName", CStringW(spData->m_strJobName));
    obj.FUN_1407cbb20("desc", CStringW(spData->m_strDesc));
    obj.FUN_1407cbb20("skilldesc1", CStringW(spData->m_strSkillDesc1));
    obj.FUN_1407cbb20("skilldesc2", CStringW(spData->m_strSkillDesc2));
    obj.FUN_1407cba60("moviepath", CString(spData->m_strMovie));

    ASArray skills1(2);
    ASArray skills2(2);
    for (size_t i = 0; i < spData->m_skills1.GetCount(); i++)
    {
        MS2Ptr<SkillData> spSkill = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(spData->m_skills1[i]);
        if (spSkill == 0)
            continue;
        ASObj skill(2);
        skill.FUN_1409c0d20("id", spData->m_skills1[i]);
        skill.FUN_1407cba60("icon", CString(reinterpret_cast<Unk_CjSkillRow*>(spSkill.operator->())->m_strIcon));
        ASTooltip tooltip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x10, 2);
        if (tooltip.FUN_1409e1c50(spData->m_skills1[i], 1, 1) != 0)
            skill.FUN_1409adbe0("tooltip", tooltip.FUN_1422bb870());
        skills1.PushValue(skill.FUN_1422bb870());
    }
    for (size_t i = 0; i < spData->m_skills2.GetCount(); i++)
    {
        MS2Ptr<SkillData> spSkill = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(spData->m_skills2[i]);
        if (spSkill == 0)
            continue;
        ASObj skill(2);
        skill.FUN_1409c0d20("id", spData->m_skills2[i]);
        skill.FUN_1407cba60("icon", CString(reinterpret_cast<Unk_CjSkillRow*>(spSkill.operator->())->m_strIcon));
        ASTooltip tooltip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x10, 2);
        if (tooltip.FUN_1409e1c50(spData->m_skills2[i], 1, 1) != 0)
            skill.FUN_1409adbe0("tooltip", tooltip.FUN_1422bb870());
        skills2.PushValue(skill.FUN_1422bb870());
    }
    obj.FUN_1409adbe0("skills1", skills1.FUN_1422bb870());
    obj.FUN_1409adbe0("skills2", skills2.FUN_1422bb870());
    m_30->Invoke("setData", obj.FUN_1422bb870());
}

// @0x140bd88e0
int UIChangeJobDialog::FUN_140bd88e0()
{
    PCBase* pPC = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (CChangeJobTable::GetInstance()->CanChange(reinterpret_cast<PC*>(pPC)->FUN_141654700(), (Unk_SubJobCode)reinterpret_cast<PC*>(pPC)->FUN_141654730(), (unsigned short)pPC->vfunc_78()) == 0)
        return 0;
    int nNext = CChangeJobTable::GetInstance()->GetStartQuestId((Unk_SubJobCode)reinterpret_cast<PC*>(pPC)->FUN_141654730());
    int nState = reinterpret_cast<MyPC*>(pPC)->FUN_141523ba0()->GetQuestState(nNext);
    if (nState == 1 || nState == 2)
        return 0;
    return 1;
}

// @0x140bd89d0
void UIChangeJobDialog::FUN_140bd89d0(int nJobCode)
{
    MS2Ptr<CQuestData> spJob = FUN_14074bc40(nJobCode);
    if (!spJob)
        return;
    Unk_ScriptPtr<CTalkScript> kNotice = FUN_1408564b0(FUN_14074b030(spJob.operator->()), 100);
    if (kNotice.IsNull())
        return;
    reinterpret_cast<UITalkManager*>(Unk_AkoCutscene::GetInstance())->FUN_141b213f0(reinterpret_cast<const MS2Ptr<CTalkScript>&>(kNotice), reinterpret_cast<Unk_CjJobRow*>(spJob.operator->())->m_n2e8, 4, 0);
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
