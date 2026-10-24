// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail between ?\meratmarketbasketinfo.cpp (which
// ends at 0x1406ae9c0) and ?\mesomarketproduct.cpp: the four TiXmlString inline members that one construction of a
// TiXmlString from a literal pulled in - the two-argument init(), the one-argument init() over it, length() and
// start(). The constructor's own COMDAT (0x1406a85d0) sits inside the meratmarketbasketinfo range.
// MS2-UNIT: unit_1406ae9c0
// MS2-RANGE: 0x1406ae9c0-0x1406aeaf0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/tixmlprinter.h"

// The construction that emits the four members (documented, not an exe function of its own).
static TiXmlString s_strUnknown("");
