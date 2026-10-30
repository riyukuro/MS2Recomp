// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers: market sort-name tables with "skill"/"stun"
// labels around a condition object and a global Nexon Messenger CNMCharacter, then a second table group.
// MS2-UNIT: unit_1400fa560
// MS2-RANGE: 0x1400fa560-0x1400fa870 .text$di
// MS2-RANGE: 0x142cb38a0-0x142cb3950 .text$yd
// MS2-RANGE: 0x142cb39b0-0x142cb3a40 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

// Nexon Messenger SDK character record (vendor class, 0x98 bytes as in placeholder/nmfunc.h; ctor 0x141570010, dtor
// 0x1415ecdb0); only its construction is needed here. The hook DLL runs the exe ctor on this static, so it must be full size.
class CNMCharacter
{
public:
    CNMCharacter();
    ~CNMCharacter();
    void* m_pad[0x98 / sizeof(void*)];
};
MS2_CHECK_SIZE(CNMCharacter, 0x98);

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CNMCharacter s_nmCharacter;

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
