// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers (and their atexit thunks) of the
// shared header statics of 2 TU(s) between uibeautyshopdialog (complete set) and uiblackmarketdialog (whose head 0x1401108b0.. it owns now); only uibirdhead is left for two sets.
// Split by ps1, left without owner; standalone per the gap2 orphan di sweep. The CU names are unknown.
// MS2-UNIT: unit_1401105f0
// MS2-RANGE: 0x1401105f0-0x1401108b0 .text$di
// MS2-RANGE: 0x142cbcd10-0x142cbce10 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include <egf/EntityID.h>

// TU 1
static CString s_strPremiumSortNames1[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// TU 2
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
// egf::kENTITY_INVALID of <egf/EntityID.h> (EntityID ctor 0x1401cd100), pinned below

// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x140110890
