// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail of ?\uiminimapentity.cpp (which ends at
// 0x141a517d0 in work/map/units.tsv): the MS2Ptr<T>::AddRef / AddRefImpl / Reference instances of the minimap
// marker and show-option pointers, then the alignment-info pointer ones
// (unit_141a517d0.h), in mangled-name order. The constructions that emit them live in
// uiminimapentity.cpp; the anchor below only reproduces them here (not an exe function of its own). w535.
// MS2-UNIT: unit_141a517d0
// MS2-RANGE: 0x141a517d0-0x141a51a30 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiminimapentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "unit_141a517d0.h"
#include "ms2/ms2recover.h"

// Copies of each pointer kind (documented anchor, not an exe function).
void Unk_MinimapPtrAddRefAnchor(UIMinimapDialog::TShowAttr* pAttr, UIMinimapEntity* pEntity,
                                       UIMinimapEntityPing* pPing, UIMinimapEntityTaxi* pTaxi,
                                       UICommon::CAlignmentInfo* pAlign)
{
    MS2Ptr<UIMinimapDialog::TShowAttr> spAttr(pAttr);
    MS2Ptr<UIMinimapEntity> spEntity(pEntity);
    MS2Ptr<UIMinimapEntityPing> spPing(pPing);
    MS2Ptr<UIMinimapEntityTaxi> spTaxi(pTaxi);
    Unk_AlignInfoPtr<UICommon::CAlignmentInfo> spAlign(pAlign);
}
