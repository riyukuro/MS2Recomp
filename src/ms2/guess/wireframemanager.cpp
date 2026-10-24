// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The .text$di tail of ?\wireframemanager.cpp: the dynamic
// initializer of the TU's registrar object (0x143af8110). Its constructor is out of line (0x141d16b90: [this]=name
// record, [this+8]=reserved) and gets the TU's name/RTTI block from .rdata (0x142ff7f58, "CWireframeManager") plus a
// zero - exactly the object the TU then finds its manager by.
// MS2-UNIT: ?\wireframemanager.cpp
// MS2-RANGE: 0x14011fff0-0x140120010 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\wireframemanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/wireframemanager.h"

// The TU's registrar ctor lives out of line in the exe at 0x141d16b90 (unnamed there: [this]=pNameRecord, [this+8]=n).
// The TU's name/RTTI block; only its address is taken here.
static const char s_szWireframeManager[] = "CWireframeManager";

// The registration: one global, so the whole thing folds into the file's dynamic initializer.
Unk_WireframeRegistrar g_wireframeRegistrar(s_szWireframeManager, 0);
