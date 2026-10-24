// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The smart-pointer glue of Unk_FieldPtr<CAtlList<unsigned>>
// (a boxed id list): Make() releases the held box and creates a fresh one, Create() allocates and marks the box.
// MS2-UNIT: unit_14045b6e0
// MS2-RANGE: 0x14045b6e0-0x14045b740 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/ms2recover.h"

// Unk_FieldPtr<T>::Make (0x14045b6e0) and Create (0x14045b710)
template void Unk_FieldPtr<ATL::CAtlList<unsigned int> >::Make();
