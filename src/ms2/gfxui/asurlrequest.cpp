// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASURLRequest, the AS3 flash.net.URLRequest wrapper.
// MS2-UNIT: ?\asurlrequest.cpp
// MS2-RANGE: 0x1422e5a70-0x1422e5be0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
// The obj holds the ctor, the dtor and the icon URL helper; its ??_G (0x1422e5a30) was first emitted by ASLoader's obj.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/asurlrequest.h"
#include "ms2/ms2format.h"

#include "hook/ms2hook.h"

// The GFx movie of a movie id (AScript's static helper, ascript.cpp range; null if the movie is not loaded).
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);

// @0x1422e5a70
ASURLRequest::ASURLRequest(CStringW strUrl, int nMovieId)
    : AScript(2)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == NULL)
        return;
    Scaleform::GFx::Value arg;
    arg.SetStringW(strUrl);
    pMovie->CreateObject(&m_value, "flash.net.URLRequest", &arg, 1);
    if (m_value.IsUndefined()) {
    }
}

// @0x1422e5b50
ASURLRequest::~ASURLRequest()
{
}

// @0x1422e5b80
CStringW FUN_1422e5b80(CStringW strName)
{
    return StringFormat(L"img://icon:{0}", strName);
}
MS2_REPLACE(0x1422E5B80, FUN_1422e5b80, 85, 0xFFE8A799);
