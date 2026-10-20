// CManufacture (RTTI .?AVCManufacture@@, 0x40 bytes): a manufacture (crafting) record, a CPtred-derived value object with a
// packet writer / reader (FUN_140693fa0 / FUN_140694050 in manufacture.cpp). Field names inferred.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CManufacture : public CPtred
{
public:
    CManufacture();                                         // 0x140693e60
    CManufacture(__int64 a, __int64 b, int c, __int64 d, int e, int f);   // 0x140693ee0
    virtual ~CManufacture();                                //  0 0x140693f70 (??_G 0x1406941b0)

    __int64 FUN_140694170();                                // FUN_1406941f0() + FUN_140694200()
    __int64 FUN_1406941f0();                                // m_30
    int FUN_140694200();                                    // m_38

    int FUN_1409eedf0() { return m_28; }                    // inline COMDAT 0x1409eedf0 (astooltip.cpp): the recipe id
    __int64 FUN_140d52020() { return m_20; }                // inline COMDAT 0x140d52020 (manufacturemanager.cpp): the record id

    __int64 m_18;                                           // +0x18
    __int64 m_20;                                           // +0x20
    int m_28;                                               // +0x28
    int m_pad_2c;
    __int64 m_30;                                           // +0x30
    int m_38;                                               // +0x38
    int m_3c;                                               // +0x3c
};
MS2_CHECK_SIZE(CManufacture, 0x40);
