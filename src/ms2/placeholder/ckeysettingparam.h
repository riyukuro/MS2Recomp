// ckeysettingparam.h - PLACEHOLDER for CKeySettingParam (RTTI .?AVCKeySettingParam@@, CPtred, 0x38 bytes, vftable
// 0x142f12db0, ctor 0x141435250, deleting dtor 0x141436100). NOT an original header.
// One bindable action of a key-setting category: CKeyTable keeps them per category (tab id 9..13) in a
// TPtrValue<CAtlList<TPtr<CKeySettingParam>>> (TPtredDummy box, vftable 0x142f12e20; FUN_141430710), and the option
// page edits them (?\gameoptioninputdefault.cpp). Member names are invented from their use.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CKeySettingParam : public CPtred
{
public:
    CKeySettingParam();                                     // 0x141435250
    virtual ~CKeySettingParam();

    __int64 m_nAction;                                      // +0x18 action id (keyGUID; 0x49409 is the fixed one)
    int m_nType;                                            // +0x20
    int m_nPriority;                                        // +0x24 primary (0) / secondary (1) / thirdly (2) slot being edited (ctor 1)
    int m_nPrimaryLocked;                                   // +0x28 nonzero: the primary key cannot be changed
    int m_nSecondaryLocked;                                 // +0x2c
    int m_nThirdlyLocked;                                   // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(CKeySettingParam, 0x38);
MS2_CHECK_OFFSET(CKeySettingParam, m_nAction, 0x18);
MS2_CHECK_OFFSET(CKeySettingParam, m_nThirdlyLocked, 0x30);
