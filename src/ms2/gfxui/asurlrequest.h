// asurlrequest.h - ASURLRequest (RTTI .?AVASURLRequest@@, base AScript, vftable 0x143115ac8, 1 slot): wraps a new AS3
// flash.net.URLRequest object (the image source of ASLoader). Header name and directory assumed (the GFx UI library
// has no __FILE__ strings). The scalar deleting dtor 0x1422e5a30 is a COMDAT of ASLoader's obj (?\asloader.cpp).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASURLRequest : public AScript
{
public:
    // Creates `new flash.net.URLRequest(strUrl)` in movie nMovieId (the AScript base is created in movie 2).
    ASURLRequest(CStringW strUrl, int nMovieId);                // 0x1422e5a70 (strUrl by value: the ctor destroys it)
    virtual ~ASURLRequest();                                    // 0x1422e5b50
};
MS2_CHECK_SIZE(ASURLRequest, 0x40);

// "img://icon:<strName>", the URL of an icon image (0x1422e5b80; name invented, the exe has no name for it).
CStringW FUN_1422e5b80(CStringW strName);
