// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers (and their atexit thunks) of the
// shared header statics of 2 TU(s) between the uiquestnavigation and uirpseventdialog sets (candidates: the four uiquiz* dialogs, unit_140e7f2e0, uireconnecttoplayernotify, uiregionlistdialog).
// Split by ps1, left without owner; standalone per the gap2 orphan di sweep. The CU names are unknown.
// MS2-UNIT: unit_1400da440
// MS2-RANGE: 0x1400da440-0x1400da6a0 .text$di
// MS2-RANGE: 0x142ca7700-0x142ca77e0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

// TU 1
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// TU 2
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController2;
