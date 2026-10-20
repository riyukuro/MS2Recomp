// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of neighbouring TUs:
// two market sort-type name tables (each with its own skill/stun labels and a condition object), the key-input
// controller singleton, three stray AS-property names, and a name/record registrar object.
// MS2-UNIT: unit_1400fa940
// MS2-RANGE: 0x1400fa940-0x1400fad30 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// The TU's registrar ctor lives out of line in the exe at 0x141d16b90 ([this]=name record, [this+8]=record).
class Unk_ScpRegistrar
{
public:
    Unk_ScpRegistrar(const void* pName, const void* pRecord);

    const void* m_pName;                // +0x00
    const void* m_pRecord;              // +0x08
};

// first TU: the market sort-type name table with its labels and condition
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU: the key-input controller singleton
static UICommon::CMyPCKeyInputController s_keyInputController;

// next TU: three AS-property names
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// next TU: the second sort-type name table, its labels, condition and registrar
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// The TU's registration record; only its address is taken here.
static char s_registrarRecord[1];
static Unk_ScpRegistrar s_registrar("OutlineRenderStep", s_registrarRecord);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb3a70-0x142cb3c10 .text$yd
