// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition classes Next, QuestSatisfied, QuestComplete,
// QuestProgress, Dead and ConstructMode (factories, names, loaders, checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a7bc0
// MS2-RANGE: 0x1413a7bc0-0x1413a8370 .text$mn
// MS2-RANGE: 0x1400f40a0-0x1400f4190 .text$di
// MS2-RANGE: 0x1413b4ec0-0x1413b4f00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The local player: the dead / construct-mode tests.
class Unk_GcPC
{
public:
    int FUN_14166ce30();                                    // dead
    int FUN_141659610();                                    // construct mode
};

// The world manager (FUN_1403ed2d0).
class Unk_GcWorld
{
public:
    Unk_GcPC* FUN_141bd0cc0();                              // the local player
};
Unk_GcWorld* FUN_1403ed2d0();

class Unk_GcUI { public: int FUN_141adbb00(); };            // CUIService
Unk_GcUI* FUN_1403ed2b0();
class Unk_GcKeyboard { public: bool FUN_14116dcb0(int nSetting, bool bDebugOnly, int nLevel); };
Unk_GcKeyboard* FUN_14025e7c0();
unsigned FUN_140869420();                                   // millisecond clock
CQuestManager* FUN_140764020();

#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regQuestComplete(L"CGuideConditionQuestComplete", CGuideConditionQuestComplete::CreateObject);     // .text$di 0x1400f40a0
static ClassObjectRegistrar s_regQuestProgress(L"CGuideConditionQuestProgress", CGuideConditionQuestProgress::CreateObject);    // .text$di 0x1400f40f0
static ClassObjectRegistrar s_regQuestSatisfied(L"CGuideConditionQuestSatisfied", CGuideConditionQuestSatisfied::CreateObject); // .text$di 0x1400f4140
#endif

// ---- CGuideConditionNext ----------------------------------------------------------------------------------------------------

// @0x1413a7bc0
ClassObject* CGuideConditionNext::CreateObject()
{
    return new CGuideConditionNext;
}

// @0x1413a7c20
CStringW CGuideConditionNext::GetTypeName()
{
    return L"CGuideConditionNext";
}
MS2_REPLACE_METHOD(0x1413A7C20, CGuideConditionNext, GetTypeName, 61, 0x43EBC646);

// @0x1413a7c70
CGuideConditionNext::CGuideConditionNext()
{
    m_nStart = 0;
}

// @0x1413a7cb0
int CGuideConditionNext::vfunc_3()
{
    if (m_nStart == 0)
        m_nStart = FUN_140869420();
    if (FUN_140869420() - m_nStart >= (unsigned)m_n20)
        return 1;
    if (FUN_1403ed2b0()->FUN_141adbb00() != 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116dcb0(0x493e2, false, 0))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1413A7CB0, CGuideConditionNext, vfunc_3, 129, 0x78B22ABF);

// @0x1413a7d40
void CGuideConditionNext::vfunc_4()
{
    CGuideCondition::vfunc_4();
    m_nStart = 0;
}
MS2_REPLACE_METHOD(0x1413A7D40, CGuideConditionNext, vfunc_4, 36, 0xE65E354C);

// ---- CGuideConditionQuestSatisfied ------------------------------------------------------------------------------------------

// @0x1413a7d70
ClassObject* CGuideConditionQuestSatisfied::CreateObject()
{
    return new CGuideConditionQuestSatisfied;
}

// @0x1413a7dd0
CStringW CGuideConditionQuestSatisfied::GetTypeName()
{
    return L"CGuideConditionQuestSatisfied";
}
MS2_REPLACE_METHOD(0x1413A7DD0, CGuideConditionQuestSatisfied, GetTypeName, 61, 0x0393C4ED);

// @0x1413a7e20
int CGuideConditionQuestSatisfied::vfunc_3()
{
    return FUN_1413a55a0(FUN_140764020()->FUN_1407456d0(m_n20));
}
MS2_REPLACE_METHOD(0x1413A7E20, CGuideConditionQuestSatisfied, vfunc_3, 51, 0x97F87638);

// ---- CGuideConditionQuestComplete -------------------------------------------------------------------------------------------

// @0x1413a7e60
ClassObject* CGuideConditionQuestComplete::CreateObject()
{
    return new CGuideConditionQuestComplete;
}

// @0x1413a7ec0
CStringW CGuideConditionQuestComplete::GetTypeName()
{
    return L"CGuideConditionQuestComplete";
}
MS2_REPLACE_METHOD(0x1413A7EC0, CGuideConditionQuestComplete, GetTypeName, 61, 0x4D8EFF74);

// @0x1413a7f10
void CGuideConditionQuestComplete::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 8;
}
MS2_REPLACE_METHOD(0x1413A7F10, CGuideConditionQuestComplete, vfunc_2, 46, 0xBB5B3712);

// @0x1413a7f50
int CGuideConditionQuestComplete::vfunc_3()
{
    return FUN_1413a55a0(FUN_140764020()->FUN_140745590(m_n20));
}
MS2_REPLACE_METHOD(0x1413A7F50, CGuideConditionQuestComplete, vfunc_3, 51, 0x8AC757D6);

// @0x1413a7f90
int CGuideConditionQuestComplete::vfunc_8()
{
    if (m_b1c != 0)
        return 0;
    return m_n20;
}
MS2_REPLACE_METHOD(0x1413A7F90, CGuideConditionQuestComplete, vfunc_8, 31, 0xA6486D72);

// ---- CGuideConditionQuestProgress -------------------------------------------------------------------------------------------

// @0x1413a7fc0
ClassObject* CGuideConditionQuestProgress::CreateObject()
{
    return new CGuideConditionQuestProgress;
}

// @0x1413a8020
CStringW CGuideConditionQuestProgress::GetTypeName()
{
    return L"CGuideConditionQuestProgress";
}
MS2_REPLACE_METHOD(0x1413A8020, CGuideConditionQuestProgress, GetTypeName, 61, 0xE4F4DB14);

// @0x1413a8070
void CGuideConditionQuestProgress::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 7;
}
MS2_REPLACE_METHOD(0x1413A8070, CGuideConditionQuestProgress, vfunc_2, 46, 0xA9541651);

// @0x1413a80b0
int CGuideConditionQuestProgress::vfunc_3()
{
    return FUN_1413a55a0(FUN_140764020()->FUN_140745630(m_n20));
}
MS2_REPLACE_METHOD(0x1413A80B0, CGuideConditionQuestProgress, vfunc_3, 51, 0x6667D788);

// @0x1413a80f0
int CGuideConditionQuestProgress::vfunc_8()
{
    if (m_b1c != 0)
        return 0;
    return m_n20;
}
MS2_REPLACE_METHOD(0x1413A80F0, CGuideConditionQuestProgress, vfunc_8, 31, 0xA6486D72);

// ---- CGuideConditionDead ----------------------------------------------------------------------------------------------------

// @0x1413a8120
ClassObject* CGuideConditionDead::CreateObject()
{
    return new CGuideConditionDead;
}

// @0x1413a8180
CStringW CGuideConditionDead::GetTypeName()
{
    return L"CGuideConditionDead";
}
MS2_REPLACE_METHOD(0x1413A8180, CGuideConditionDead, GetTypeName, 61, 0x117DC4A7);

// @0x1413a81d0
void CGuideConditionDead::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 0xb;
}
MS2_REPLACE_METHOD(0x1413A81D0, CGuideConditionDead, vfunc_2, 46, 0xBB3AB92C);

// @0x1413a8210
int CGuideConditionDead::vfunc_3()
{
    Unk_GcPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a55a0(pPC->FUN_14166ce30());
}
MS2_REPLACE_METHOD(0x1413A8210, CGuideConditionDead, vfunc_3, 66, 0x63E40D3D);

// @0x1413a8260
int CGuideConditionDead::vfunc_8()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1413A8260, CGuideConditionDead, vfunc_8, 8, 0x7F371472);

// ---- CGuideConditionConstructMode -------------------------------------------------------------------------------------------

// @0x1413a8270
ClassObject* CGuideConditionConstructMode::CreateObject()
{
    return new CGuideConditionConstructMode;
}

// @0x1413a82d0
CStringW CGuideConditionConstructMode::GetTypeName()
{
    return L"CGuideConditionConstructMode";
}
MS2_REPLACE_METHOD(0x1413A82D0, CGuideConditionConstructMode, GetTypeName, 61, 0x8FDBE4D1);

// @0x1413a8320
int CGuideConditionConstructMode::vfunc_3()
{
    Unk_GcPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a55a0(pPC->FUN_141659610());
}
MS2_REPLACE_METHOD(0x1413A8320, CGuideConditionConstructMode, vfunc_3, 66, 0x5E415770);
