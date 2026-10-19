// citemremakescrolldata.h - PLACEHOLDER for CItemRemakeScrollData (RTTI .?AVCItemRemakeScrollData@@, 0x90 bytes, base CPtred;
// ctor 0x140615410): one row of Table/itemRemakeScroll.xml. NOT an original header. Only the members the remake scroll dialog
// (?\uiitemremakescrolldialog.cpp) reads are named; the reader and the table (citemremakescrolltable.h) stay in the exe.
// Names are invented from the use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

// An ATL::CAtlArray<unsigned> inside the row (0x20 bytes); the accessors are the exe's shared instances.
struct Unk_IrsUIntArray
{
    unsigned __int64 FUN_140186270();                       // GetCount
    unsigned* FUN_140184510(unsigned __int64 nIndex);       // operator[]
    bool FUN_140187930();                                   // IsEmpty
    char m_pad_00[0x20];
};
MS2_CHECK_SIZE(Unk_IrsUIntArray, 0x20);

class CItemRemakeScrollData : public CPtred
{
public:
    unsigned short m_nLevelMin;                             // +0x18
    unsigned short m_nLevelMax;                             // +0x1a
    int m_nPetKind;                                         // +0x1c nonzero: the scroll is for pets
    Unk_IrsUIntArray m_arrSlots;                            // +0x20 the equipment slots (item scrolls)
    Unk_IrsUIntArray m_arrItemTypes;                        // +0x40 the allowed item types (empty: unrestricted)
    Unk_IrsUIntArray m_arrRanks;                            // +0x60 the allowed ranks
    int m_nLockOption;                                      // +0x80 option locking enabled
    int m_nOptionKind;                                      // +0x84 index for the kind text (kind_x / kind_o)
    int m_nOptionValue;                                     // +0x88 index for the value text (value_x/o/high/max); 0: none
    int m_pad_8c;
};
MS2_CHECK_SIZE(CItemRemakeScrollData, 0x90);
MS2_CHECK_OFFSET(CItemRemakeScrollData, m_arrSlots, 0x20);
MS2_CHECK_OFFSET(CItemRemakeScrollData, m_nLockOption, 0x80);

typedef MS2Ptr<CItemRemakeScrollData> CItemRemakeScrollDataPtr;
