// Condition contexts and checker: RTTI names, layout from conditionutil.cpp and
// the CQuest local constructions at 0x1416c67e0. Context names are structs in RTTI.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/delegatelib.h"

struct ConditionContext
{
    ConditionContext();
    virtual int FUN_1402a90e0() = 0;
};
struct ConditionUserFindContext : public ConditionContext
{
    ConditionUserFindContext();
    // ~ConditionUserFindContext is implicit (0x1416c7df0): the exe dtor stores no vptr.
    int FUN_1402a90e0() override;
    void* m_user;
    unsigned short m_level;
    int m_targetKind, m_myKind, m_job, m_gender, m_24;
    ATL::CAtlArray<unsigned> m_skills;
};
MS2_CHECK_SIZE(ConditionContext, 8);
MS2_CHECK_SIZE(ConditionUserFindContext, 0x48);
MS2_CHECK_OFFSET(ConditionUserFindContext, m_level, 0x10);
MS2_CHECK_OFFSET(ConditionUserFindContext, m_skills, 0x28);

class CQuestConditionChecker : public CPtred
{
public:
    CQuestConditionChecker();
    virtual ~CQuestConditionChecker() = default;     // 0x1402a5a60 (no vptr store)
    virtual bool Check(CConditionCommonData*, ConditionContext*) = 0;
};
class CQuestConditionCheckerUserFind : public CQuestConditionChecker
{
public:
    typedef DelegateLib::DelegateMember2<CQuestConditionCheckerUserFind, const CString&, ConditionUserFindContext*, bool>
        Handler;
    CQuestConditionCheckerUserFind();                           // 0x1402a9100
    virtual ~CQuestConditionCheckerUserFind() = default;        // 0x1402a5a80 (no vptr store)
    bool Check(CConditionCommonData*, ConditionContext*) override;  // 0x1402a9a40

    // The handlers keyed by the target dictionary's key (the xml attribute name); each gets the value and the context.
    bool CheckJobId(const CString& strValue, ConditionUserFindContext* pContext);            // 0x1402a9540
    bool CheckLevel(const CString& strValue, ConditionUserFindContext* pContext);            // 0x1402a95a0
    bool CheckGender(const CString& strValue, ConditionUserFindContext* pContext);           // 0x1402a96b0
    bool CheckEquipItemsAnd(const CString& strValue, ConditionUserFindContext* pContext);    // 0x1402a9710
    bool CheckEquipItemsOr(const CString& strValue, ConditionUserFindContext* pContext);     // 0x1402a9810
    bool CheckTitleId(const CString& strValue, ConditionUserFindContext* pContext);          // 0x1402a9910
    bool CheckRideeId(const CString& strValue, ConditionUserFindContext* pContext);          // 0x1402a9970
    bool CheckOppositeGender(const CString& strValue, ConditionUserFindContext* pContext);   // 0x1402a99d0

    // The checker's key is known (the 0x11f "dictionary" condition validates its target with it).
    int HasHandler(const CString& strKey);                     // 0x1402a6b80

private:
    ATL::CAtlMap<CString, Handler, ATL::CStringElementTraitsI<CString> > m_handlers;   // +0x18
};
MS2_CHECK_SIZE(CQuestConditionChecker, 0x18);
MS2_CHECK_SIZE(CQuestConditionCheckerUserFind, 0x60);
