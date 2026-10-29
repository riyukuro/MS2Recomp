// Recovered Nexon Messenger framed record encoder.
#pragma once

#include "ms2/placeholder/nmfunc.h"

// The stack encoder every EncodeFramed builds (0x10 bytes). The constructor (0x14156bcb0, FUN_14156bcb0 in
// unit_14156a020) writes the record header; the destructor (0x14156bd50) patches the record length. Units that use it
// pin both: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0 and
// ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50.
class CNMSerializableEncoder
{
public:
    CNMSerializableEncoder(CNMStream* pStream, CNMSerializable* pObject);
    ~CNMSerializableEncoder();

    void* m_p00;
    unsigned int m_n08;
    int m_n0c;
};
