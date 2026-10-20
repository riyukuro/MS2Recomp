// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail of ?\uiminimapentity.cpp, after
// unit_141a517d0: MS2Ptr<T>::Release / ReleaseImpl of the minimap show-option and marker pointers plus the
// alignment-info pointer pair (unit_141a517d0.h), then the clone slot (vfunc_1) of the two AS-callback DelegateImpls, in
// mangled-name order. The constructions that emit them live in uiminimapentity.cpp; the anchor below only
// reproduces them here (not an exe function of its own). w535.
// MS2-UNIT: unit_141a51a30
// MS2-RANGE: 0x141a51a30-0x141a51d30 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiminimapentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "unit_141a517d0.h"
#include "ms2/ms2recover.h"

// Pointer kinds whose release lands here, and the two AS callbacks (documented anchor, not an exe function).
void Unk_MinimapPtrReleaseAnchor(UIMinimapDialog* pDialog, UIMinimapEntity* pEntity, UIMinimapDialog::TShowAttr* pAttr,
                                 UIMinimapEntityPing* pPing, UIMinimapEntityTaxi* pTaxi,
                                 UICommon::CAlignmentInfo* pAlign)
{
    MS2Ptr<UIMinimapDialog::TShowAttr> spAttr(pAttr);
    MS2Ptr<UIMinimapEntityPing> spPing(pPing);
    MS2Ptr<UIMinimapEntityTaxi> spTaxi(pTaxi);
    Unk_AlignInfoPtr<UICommon::CAlignmentInfo> spAlign(pAlign);
    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cbDialog(pDialog, &UIMinimapDialog::FUN_141a456c0);
    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cbEntity(pEntity, &UIMinimapEntity::FUN_141a32120);
}
