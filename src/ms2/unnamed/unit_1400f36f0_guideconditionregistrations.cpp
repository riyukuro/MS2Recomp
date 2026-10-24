// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dynamic initializers of ten CGuideCondition* classes (GuideClear
// .. Interactable): each registers its factory with the ClassObject registry from a one-byte static, in exe order (see
// unit_1400f4190 for the pattern).
// MS2-UNIT: unit_1400f36f0
// MS2-RANGE: 0x1400f36f0-0x1400f3a10 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/classobject.h"

// The class-object factory registrar (0x140316aa0, commonfiles\dungeonmissiondata.cpp); the factories are defined by the
// guide-condition TU's own code unit.
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
ClassObject* FUN_1413aaa50();
ClassObject* FUN_1413aa7e0();
ClassObject* FUN_1413ad3b0();
ClassObject* FUN_1413acd60();
ClassObject* FUN_1413ace40();
ClassObject* FUN_1413ae840();
ClassObject* FUN_1413af740();
ClassObject* FUN_1413a6580();
ClassObject* FUN_1413abd90();
ClassObject* FUN_1413a74c0();

// The initialized marker: no storage, so the dynamic initializer is the registration call and nothing else.
struct Unk_RegMarker {};

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registrar at DllInit time, before the exe's CRT/locks exist
// @0x1400f36f0
static char s_regGuideClear;
static Unk_RegMarker s_initGuideClear =
    (FUN_140316aa0(&s_regGuideClear, CStringW(L"CGuideConditionGuideClear"), FUN_1413aaa50), Unk_RegMarker());

// @0x1400f3740
static char s_regGuideOpen;
static Unk_RegMarker s_initGuideOpen =
    (FUN_140316aa0(&s_regGuideOpen, CStringW(L"CGuideConditionGuideOpen"), FUN_1413aa7e0), Unk_RegMarker());

// @0x1400f3790
static char s_regGuildPvpPeriod;
static Unk_RegMarker s_initGuildPvpPeriod =
    (FUN_140316aa0(&s_regGuildPvpPeriod, CStringW(L"CGuideConditionGuildPvpPeriod"), FUN_1413ad3b0), Unk_RegMarker());

// @0x1400f37e0
static char s_regHasManufacture;
static Unk_RegMarker s_initHasManufacture =
    (FUN_140316aa0(&s_regHasManufacture, CStringW(L"CGuideConditionHasManufacture"), FUN_1413acd60), Unk_RegMarker());

// @0x1400f3830
static char s_regHasMoney;
static Unk_RegMarker s_initHasMoney =
    (FUN_140316aa0(&s_regHasMoney, CStringW(L"CGuideConditionHasMoney"), FUN_1413ace40), Unk_RegMarker());

// @0x1400f3880
static char s_regHasStatPoint;
static Unk_RegMarker s_initHasStatPoint =
    (FUN_140316aa0(&s_regHasStatPoint, CStringW(L"CGuideConditionHasStatPoint"), FUN_1413ae840), Unk_RegMarker());

// @0x1400f38d0
static char s_regHomeMode;
static Unk_RegMarker s_initHomeMode =
    (FUN_140316aa0(&s_regHomeMode, CStringW(L"CGuideConditionHomeMode"), FUN_1413af740), Unk_RegMarker());

// @0x1400f3920
static char s_regInput;
static Unk_RegMarker s_initInput =
    (FUN_140316aa0(&s_regInput, CStringW(L"CGuideConditionInput"), FUN_1413a6580), Unk_RegMarker());

// @0x1400f3970
static char s_regInteractObject;
static Unk_RegMarker s_initInteractObject =
    (FUN_140316aa0(&s_regInteractObject, CStringW(L"CGuideConditionInteractObject"), FUN_1413abd90), Unk_RegMarker());

// @0x1400f39c0
static char s_regInteractable;
static Unk_RegMarker s_initInteractable =
    (FUN_140316aa0(&s_regInteractable, CStringW(L"CGuideConditionInteractable"), FUN_1413a74c0), Unk_RegMarker());

#endif
