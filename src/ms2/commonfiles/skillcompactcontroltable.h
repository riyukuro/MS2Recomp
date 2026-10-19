// skillcompactcontroltable.h - CSkillCompactControlTable and CCompactControlSkill (RTTI names): the "compact control"
// skill table read from data/xml/table/SkillCompactControl.xml. Per job (<job code= baseSP=>) a list of skills
// (<skill id= repeatCount=>); the table keeps three static CAtlMaps (skill id -> skill, job -> skill list, job -> base
// SP) behind a lock, and reloads the file when it changed on disk. Header name assumed; member and helper names are
// invented from use.
// Proven (exe): CSkillCompactControlTable is 0x10 bytes (TSingleton at +0, CValidData at +8), CCompactControlSkill is
// 0x20 bytes (CPtred, two dwords at +0x18).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/commonfiles/os.h"

// One <skill> row, 0x20 bytes.
class CCompactControlSkill : public CPtred
{
public:
    CCompactControlSkill();                     // 0x140dcb4a0
    virtual ~CCompactControlSkill();            // 0x140dcb800

    unsigned m_nSkillId;                        // +0x18 "id"
    unsigned m_nRepeatCount;                    // +0x1c "repeatCount"
};
MS2_CHECK_SIZE(CCompactControlSkill, 0x20);
MS2_CHECK_OFFSET(CCompactControlSkill, m_nSkillId, 0x18);
MS2_CHECK_OFFSET(CCompactControlSkill, m_nRepeatCount, 0x1c);

typedef Unk_SocketPtr<CCompactControlSkill> Unk_CcSkillPtr;
// The skills of one job: the box the job map's pointer owns.
typedef ATL::CAtlList<Unk_CcSkillPtr> Unk_CcSkillList;
template<> struct Unk_SocketRef<Unk_CcSkillList> {
    static CPtred* Base(Unk_CcSkillList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_CcSkillList>, value);
        return result;
    }
    static TPtredDummy<Unk_CcSkillList>* New(void*) { return new TPtredDummy<Unk_CcSkillList>(); }
    static Unk_CcSkillList* Value(CPtred* p) {
        Unk_CcSkillList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_CcSkillList>*>(p)->value;
        return result;
    }
    static Unk_CcSkillList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_CHECK_SIZE(TPtredDummy<Unk_CcSkillList>, 0x48);
MS2_CHECK_OFFSET(TPtredDummy<Unk_CcSkillList>, value, 0x18);
typedef Unk_SocketPtr<Unk_CcSkillList> Unk_CcSkillListPtr;

// The job code of a <job> row (the exe keys the job maps by an enum, so their ATL traits take the key by reference).
enum Unk_CcJob { Unk_CcJob_None = 0 };

// RTTI CSkillCompactControlTable, 0x10 bytes: TSingleton at +0, CValidData at +8. A TSingleton that CGameApp::InitInstance
// (?\ms2.cpp) creates.
class CSkillCompactControlTable : public TSingleton<CSkillCompactControlTable>, public CValidData<CSkillCompactControlTable>
{
public:
    CSkillCompactControlTable();                // 0x140dca750
    virtual ~CSkillCompactControlTable();       // 0x140dca7b0

    static int Load();                          // 0x140dca800 the xml into the three maps (reloads are guarded by the lock)
    static Unk_CcSkillPtr GetSkill(unsigned nSkillId);           // 0x140dcacd0
    static Unk_CcSkillListPtr GetJobSkills(Unk_CcJob nJob);       // 0x140dcada0
    static __int64 GetBaseSP(Unk_CcJob nJob);          // 0x140dcae70 (50 when the job has no row)
    static void CheckInit();                    // 0x140dcbc60
    static void SetInit(bool b);                // 0x140dcea70

    static bool s_bInit;                        // 0x143ac49c0
};
MS2_CHECK_SIZE(CSkillCompactControlTable, 0x10);
