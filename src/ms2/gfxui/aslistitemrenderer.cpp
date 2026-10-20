// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASListItemRenderer / ASItemRendererBase, the CLIK list row
// wrappers of the GFx UI library.
// MS2-UNIT: ?\aslistitemrenderer.cpp
// MS2-RANGE: 0x1422e1ba0-0x1422e2080 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Both
// classes are declared in src/ms2/placeholder/ascorelist.h. The "focusable" / "selectable" getters return the member's
// IsBool() (whether it is a Boolean at all), not its value: that is what the exe calls (0x141a4bfb0).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asfunction.h"

#include "hook/ms2hook.h"

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)

// @0x1422e1ba0
ASListItemRenderer::ASListItemRenderer(CString strLinkage, int nMovieId)
    : ASButton()
{
    m_nMovieId = nMovieId;
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == 0)
        return;
    pMovie->CreateObject(&m_value, strLinkage);
}

// @0x1422e1c50
ASListItemRenderer::ASListItemRenderer(const Scaleform::GFx::Value& v, int nMovieId)
    : ASButton(v, nMovieId)
{
}

// @0x1422e1ca0
ASListItemRenderer::~ASListItemRenderer()
{
}

// @0x1422e1cd0
bool ASListItemRenderer::FUN_1422e1cd0()
{
    return FUN_1422baa20("focusable").IsBool();
}
MS2_REPLACE_METHOD(0x1422E1CD0, ASListItemRenderer, FUN_1422e1cd0, 89, 0x8DF87546);

// @0x1422e1d30
void ASListItemRenderer::FUN_1422e1d30(bool bFocusable)
{
    FUN_1407cbbe0("focusable", bFocusable);
}
MS2_REPLACE_METHOD(0x1422E1D30, ASListItemRenderer, FUN_1422e1d30, 41, 0x15EBF5B2);

// @0x1422e1d60
unsigned int ASListItemRenderer::FUN_1422e1d60()
{
    return FUN_1422baa20("index").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E1D60, ASListItemRenderer, FUN_1422e1d60, 88, 0x5AF9C5E4);

// @0x1422e1dc0
void ASListItemRenderer::FUN_1422e1dc0(unsigned int nIndex)
{
    FUN_1409c0d20("index", nIndex);
}
MS2_REPLACE_METHOD(0x1422E1DC0, ASListItemRenderer, FUN_1422e1dc0, 40, 0x1A3E3B01);

// @0x1422e1df0
bool ASListItemRenderer::FUN_1422e1df0()
{
    return FUN_1422baa20("selectable").IsBool();
}
MS2_REPLACE_METHOD(0x1422E1DF0, ASListItemRenderer, FUN_1422e1df0, 89, 0xC6AE965B);

// @0x1422e1e50
void ASListItemRenderer::FUN_1422e1e50(bool bSelectable)
{
    FUN_1407cbbe0("selectable", bSelectable);
}
MS2_REPLACE_METHOD(0x1422E1E50, ASListItemRenderer, FUN_1422e1e50, 41, 0xAD761F5A);

// @0x1422e1e80
ASItemRendererBase::ASItemRendererBase(CString strLinkage, int nMovieId)
    : ASListItemRenderer(strLinkage, nMovieId)
{
}

// @0x1422e1f00
ASItemRendererBase::ASItemRendererBase(const Scaleform::GFx::Value& v, int nMovieId)
    : ASListItemRenderer(v, nMovieId)
{
}

// Not hooked: onData is destroyed by the callee.
// @0x1422e1f50
void ASItemRendererBase::FUN_1422e1f50(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> onData, void* pUser)
{
    FUN_141b46a40("fnSetData", ASFunction(onData, (__int64)pUser, m_nMovieId));
}

// MS2-PIN: ??1ASItemRendererBase@@UEAA@XZ 0x1422e1fe0
// MS2-PIN: ??_GASItemRendererBase@@UEAAPEAXI@Z 0x1422e2000
// MS2-PIN: ??_GASListItemRenderer@@UEAAPEAXI@Z 0x1422e2040
