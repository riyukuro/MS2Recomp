// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The last dynamic initializer of worldservice.cpp's .text$di
// run: a second CMyPCKeyInputController header static (0x143af82f0, between worldservice's own .bss statics) defined
// after header_statics_a. Kept as its own row because worldservice_1's MS2-RANGE ends one function short (0x1401208d0).
// MS2-UNIT: unit_1401208d0
// MS2-RANGE: 0x1401208d0-0x140120900 .text$di
// MS2-RANGE: 0x142cc3d10-0x142cc3d30 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"

static UICommon::CMyPCKeyInputController s_keyInputController;     // 0x143af82f0
