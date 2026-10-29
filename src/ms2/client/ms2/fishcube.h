// fishcube.h - CFishCube (RTTI .?AVCFishCube@@): the five-int record describing a fishing cube (id, three parameters
// and a 16-bit value) with its stream (de)serialisers. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the
// unit is `?\fishcube.cpp` (0x1403b08b0-0x1403b0e20). Header name assumed; the member names are invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"

// 0x30 bytes. vftable 0x142d33d90 (1 slot: the deleting destructor).
class CFishCube : public CPtred
{
public:
    CFishCube();                                        // 0x1403b08b0
    // ~CFishCube() is implicit (0x1403b0cb0): the exe dtor stores no vftable pointer

    void FUN_1403b0910(COutputStream* pStream);         // writes m_id, the constant 10000001, 25, m_b, 1 (short)
    void FUN_1403b09a0(COutputStream* pStream);         // writes m_id, m_a, m_b, m_c, m_d (short)
    void FUN_1403b0a40(CByteBuffer* pStream);           // reads m_id, m_a, m_b, m_c, m_d (short)
    void FUN_1403b0b30();                               // zero m_a .. m_d
    void FUN_1403b0b70(COutputStream* pStream);         // writes m_id, m_a, m_b, m_c
    void FUN_1403b0bf0(CByteBuffer* pStream);           // reads m_id, m_a, m_b, m_c

    int m_id;                                           // +0x18
    int m_a;                                            // +0x1c
    int m_b;                                            // +0x20
    int m_c;                                            // +0x24
    int m_d;                                            // +0x28
};
MS2_CHECK_SIZE(CFishCube, 0x30);
MS2_CHECK_OFFSET(CFishCube, m_d, 0x28);
