// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (unit ?\colorboostdata.cpp).
//
// CColorBoostData: one timed colour-scale boost on an actor (0x20: vfptr, started flag, start time, ...).
// CColorBoostManager: the list of the active boosts of a PCBase (RTTI .?AVCColorBoostManager@@, 0x48 bytes,
// PCBase+0x648); both are in colorboostmanager.h.
// UIColorBoostDialog: debug dialog ("ColorBoostDialog", UI type 0x4eaf) with the NPC / PC colour scale sliders.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include <egf/EntityID.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/colorboostmanager.h"

class ASData;

class UIColorBoostDialog : public UIDialog
{
public:
    UIColorBoostDialog();                                                       // 0x14109b900
    virtual ~UIColorBoostDialog();                                              // 0x14109b950
    virtual CString GetTypeName();                                                  //  1 0x14109b990
    virtual void OnLoadComplete();                                              // 22 0x14109b9e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                // 28 0x14109bb20
    virtual int vfunc_48() { return 0x4eaf; }                                   // 48 (COMDAT 0x14109bd50)
};
MS2_CHECK_SIZE(UIColorBoostDialog, 0x178);
