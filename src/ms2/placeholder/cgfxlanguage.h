// cgfxlanguage.h - PLACEHOLDER for CGFxLanguage (RTTI .?AVCGFxLanguage@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<CGFxLanguage> at +0x0, CCacheData at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"

class CGFxLanguage : public TSingleton<CGFxLanguage>, public CCacheData
{
public:
    CGFxLanguage();                                         // 0x141815d50
    virtual ~CGFxLanguage();
    bool LoadKorFlash(class TiXmlDocument* pDoc);          // reads korFlash.xml
};
MS2_CHECK_SIZE(CGFxLanguage, 0x30);
