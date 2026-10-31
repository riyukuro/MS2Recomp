// soundpropertymgr.h - PLACEHOLDER for SoundPropertyMgr (RTTI .?AVSoundPropertyMgr@@, 0xe0 bytes). NOT an original header.
// Bases: TSingleton<SoundPropertyMgr> at +0x0, CValidData<SoundPropertyMgr> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class SoundPropertyMgr : public TSingleton<SoundPropertyMgr>, public CValidData<SoundPropertyMgr>
{
public:
    SoundPropertyMgr();                                     // 0x141791810
    virtual ~SoundPropertyMgr();
    unsigned Load();                                        // 0x141791940
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xe0 - 0x10];
};
MS2_CHECK_SIZE(SoundPropertyMgr, 0xe0);
