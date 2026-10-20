// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the header statics of several
// neighbouring TUs: a null handle, the sort-type name table and the skill/stun labels with a condition table, the
// equipment/avatar slot labels, then two more copies of the sort-type table with their skill/stun labels.
// MS2-UNIT: unit_1400e65d0
// MS2-RANGE: 0x1400e65d0-0x1400e6d40 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// first TU
static Unk_1401cd100 s_pointer1(NULL);
static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// slot labels
static CString s_strCap = "Cap";
static CString s_strCustomize = "Customize";
static CString s_strDefault = "Default";
static CString s_strEmotion = "Emotion";
static CString s_strExceptRender = "ExceptRender";
static CString s_strExpired = "Expired";
static CString s_strHair = "Hair";
static CString s_strInvalide = "Invalide";
static CString s_strLayerExpired = "layerExpired";
static CString s_strLower = "Lower";
static CString s_strMissMatch = "MissMatch";
static CString s_strOptimizer = "Optimizer";
static CString s_strPCBang = "PCBang";
static CString s_strSlot = "Slot";
static CString s_strUndo = "Undo";
static CString s_strVIP = "VIP";
static CString s_strWillUpdatePos = "WillUpdatePos";

// next TU
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// last TU
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static CString s_sortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cac3b0-0x142cac760 .text$yd
