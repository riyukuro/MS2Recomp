// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers: a market sort-name table group, the
// ClonePC::ms_ClassInfo registration (tail of clonepc.cpp), a second table group with a condition object and the
// CNpc::ms_ClassInfo registration.
// MS2-UNIT: unit_1400e53e0
// MS2-PIN: ??__E?ms_ClassInfo@CNpc@@2VClassInfo@efd@@B@@YAXXZ 0x1400e5690
// MS2-RANGE: 0x1400e53e0-0x1400e56b0 .text$di
// MS2-RANGE: 0x142cabc60-0x142cabd60 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/pcbase.h"

// CNpc (RTTI "CNpc", id 0x6200028): only its efd class descriptor is registered here (layout: scenestategame.cpp).
class CNpc : public PCBase
{
public:
    EE_DECLARE_CLASS1(CNpc, 0x06200028, PCBase);
};

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ClonePC);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CNpc);
