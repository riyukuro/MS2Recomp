// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The bundled fmt formatting library's TU (unit name a guess,
// work/map/units.tsv). For now only its dynamic initializer is written: the numeric locale the formatting code reads
// (DAT_143aad168, the Korean locale until localepath.cpp picks the service locale's one). The .text$mn functions of
// the unit (0x1402cb2a0-0x1402e1070) are not written yet.
// MS2-UNIT: ?\fmt.cpp
// MS2-RANGE: 0x1400b5ae0-0x1400b5b10 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fmt.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <locale.h>

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's global (symbols-manual.tsv); its initializer already ran in the exe
_locale_t DAT_143aad168 = _create_locale(LC_NUMERIC, "korean");   // 0x143aad168
#endif
