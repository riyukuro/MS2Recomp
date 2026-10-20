// gfxfileopener.h - PLACEHOLDER for GFxFileOpener (RTTI .?AVGFxFileOpener@@, vftable 0x143116b58, 0x28 bytes): the game's
// Scaleform file opener. NOT an original header. A Scaleform::GFx::FileOpener (0x18) that redirects the first "ime.xml"
// request to ./Data/Xml/Table/ime.xml and the first Ime.swf / Ime.gfx request to the GFx UI manager's IME movie path, and
// can route buffered opens through a registered callback (FUN_1422eb400). Slots: 0 ??_G 0x1422eb420, 1 OpenFile
// 0x1422eaf60, 2/3 the SDK's GetFileModifyTime / OpenFileEx.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

class GFxFileOpener : public Scaleform::GFx::FileOpener
{
public:
    // the open callback (buffered opens; the CString is destroyed by the callee)
    typedef Scaleform::File* (*OpenCallback)(CString strPath);

    GFxFileOpener();                                                            // 0x1422eaea0
    virtual ~GFxFileOpener();                                                   // 0x1422eaf20
    virtual Scaleform::File* OpenFile(const char* purl, int flags, int mode);   // 1 0x1422eaf60
    Scaleform::File* FUN_1422eb2f0(const CString& strPath, int flags, int mode);   // open through the callback / the SDK
    static void FUN_1422eb400(OpenCallback pfn);                                // set the open callback

private:
    int m_bImeXmlOpened;                // +0x18 "ime.xml" was redirected once
    int m_bImeSwfOpened;                // +0x1c "Ime.swf"/"Ime.gfx" was redirected once
    CString m_strImeXmlPath;            // +0x20 "./Data/Xml/Table/ime.xml"
};
MS2_CHECK_SIZE(GFxFileOpener, 0x28);
