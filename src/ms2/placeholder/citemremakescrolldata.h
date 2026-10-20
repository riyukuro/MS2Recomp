// citemremakescrolldata.h - PLACEHOLDER for CItemRemakeScrollData (RTTI .?AVCItemRemakeScrollData@@, 0x90 bytes, base CPtred;
// ctor 0x140615410): one <remakeScroll> row of Table/itemRemakeScroll.xml, read by CItemRemakeScrollTable::Load
// (?\itemremakescrolldata.cpp). NOT an original header. Names are invented from the xml attributes and the use in the
// remake scroll dialog (?\uiitemremakescrolldialog.cpp).
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

// The enum attributes of a row (read with the tinyxmlhelper.h enum reader; the enumerators are not recovered).
enum RemakeScrollOpKind { RemakeScrollOpKindNone = 0 };     // "addOpKind" (XmlValue instance 0x140619fd0)
enum RemakeScrollOpValue { RemakeScrollOpValueNone = 0 };   // "representOpValue" / "addOpValue" (0x14061a060)

class CItemRemakeScrollData : public CPtred
{
public:
    CItemRemakeScrollData();                                // 0x140615410
    virtual ~CItemRemakeScrollData();                       // 0x1406154d0

    unsigned short m_nLevelMin;                             // +0x18 "minLv"
    unsigned short m_nLevelMax;                             // +0x1a "maxLv"
    int m_nPetKind;                                         // +0x1c "onlyPet" nonzero: the scroll is for pets
    ATL::CAtlArray<unsigned> m_arrSlots;                    // +0x20 "slot" the equipment slots (item scrolls)
    ATL::CAtlArray<unsigned> m_arrItemTypes;                // +0x40 "item" the allowed item ids (empty: unrestricted)
    ATL::CAtlArray<unsigned> m_arrRanks;                    // +0x60 "rank" the allowed ranks
    RemakeScrollOpValue m_nLockOption;                      // +0x80 "representOpValue" option locking enabled
    RemakeScrollOpKind m_nOptionKind;                       // +0x84 "addOpKind" index for the kind text (kind_x / kind_o)
    RemakeScrollOpValue m_nOptionValue;                     // +0x88 "addOpValue" index for the value text; 0: none
};
MS2_CHECK_SIZE(CItemRemakeScrollData, 0x90);
MS2_CHECK_OFFSET(CItemRemakeScrollData, m_arrSlots, 0x20);
MS2_CHECK_OFFSET(CItemRemakeScrollData, m_nLockOption, 0x80);

typedef MS2Ptr<CItemRemakeScrollData> CItemRemakeScrollDataPtr;
