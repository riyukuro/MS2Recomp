// cequipmentslotlayerinfo.h - PLACEHOLDER for CEquipmentSlotLayerInfo (RTTI .?AVCEquipmentSlotLayerInfo@@, 0x58 bytes,
// base CPtred, vftable 0x142ec0268, ctor 0x1411f6f10, dtor 0x1411f7660, ??_G 0x1411f85a0). NOT an original header.
// One layer of an equipment slot: the active period of the codi (outfit) tab of the PC's equipment (+0x188 of the
// equipment holder, read by the item use handler ItemActiveCodiTab in unit_140d1ae30). Member names are invented.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"

class CEquipmentSlotLayerInfo : public CPtred
{
public:
    CEquipmentSlotLayerInfo(int nKind);                     // 0x1411f6f10
    bool FUN_1411df700();                                   // expired
    bool FUN_1411df810();                                   // active (m_bActive)
    int FUN_1411df830();                                    // state: 0 off, 1 active with an end, 2 no end, 3 expired, 4 not started
    unsigned FUN_1411df8e0();                               // the most days the period may span

    CMsTime m_start;                                        // +0x18 (CMsTime(0) in the ctor)
    CMsTime m_end;                                          // +0x28
    bool m_bActive;                                         // +0x38
    int m_3c;                                               // +0x3c
    int m_nKind;                                            // +0x40 the ctor argument
    bool m_bBusy;                                           // +0x44
    int m_48;                                               // +0x48
    int m_4c[2];                                            // +0x4c (ctor 0x140517b00)
    int m_pad_54;
};
MS2_CHECK_SIZE(CEquipmentSlotLayerInfo, 0x58);
MS2_CHECK_OFFSET(CEquipmentSlotLayerInfo, m_end, 0x28);
MS2_CHECK_OFFSET(CEquipmentSlotLayerInfo, m_nKind, 0x40);
MS2_CHECK_OFFSET(CEquipmentSlotLayerInfo, m_4c, 0x4c);
