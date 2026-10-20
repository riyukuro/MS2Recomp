// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers (and their atexit thunks) of the
// shared header statics of 1 TU(s) after ugcmanager (candidates ugcmanager#5 / ugcviewerequip; the condition and key input controller that would close the set may be the head of unit_14010f630).
// Split by ps1, left without owner; standalone per the gap2 orphan di sweep. The CU names are unknown.
// MS2-UNIT: unit_14010f440
// MS2-RANGE: 0x14010f440-0x14010f630 .text$di
// MS2-RANGE: 0x142cbc5c0-0x142cbc660 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

// TU 1
static CString s_strPremiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
