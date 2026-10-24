// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The tail of commonfiles\filesystem.cpp (its own range ends
// at 0x1403b0790): the three <stdio.h> inline wrappers the file's own sprintf call pulled in - sprintf, the one-argument
// _vsprintf_l over it and _vsnprintf_l. All three are static __inline in the UCRT header, so the copy lives in the TU
// that used it; only that use is reproduced here.
// MS2-UNIT: unit_1403b0790
// MS2-RANGE: 0x1403b0790-0x1403b08b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <stdio.h>

// The TU's formatting (documented, not an exe function of its own).
static char s_szFormatBuffer[0x100];
static int  s_nFormatUsed = sprintf(s_szFormatBuffer, "%s", "");
