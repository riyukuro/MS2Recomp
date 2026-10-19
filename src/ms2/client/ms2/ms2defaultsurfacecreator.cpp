// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMS2DefaultSurfaceCreator: the game's ecr::IDefaultSurfaceCreator,
// which builds the main render context (MS2RenderContext) and its first render surface with the game's render list processor.
// MS2-UNIT: ?\ms2defaultsurfacecreator.cpp
// MS2-RANGE: 0x1414b2470-0x1414b3ee0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2defaultsurfacecreator.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <ecr/RenderService.h>
#include <ecr/RenderContext.h>
#include "ms2/placeholder/cms2defaultsurfacecreator.h"
#include "ms2/client/ms2/afterimageeffectparam.h"
#include "ms2/client/ms2/ms2rendercontext.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414b2470
CMS2DefaultSurfaceCreator::CMS2DefaultSurfaceCreator()
{
}
#endif

// @0x1414b24b0
CMS2DefaultSurfaceCreator::~CMS2DefaultSurfaceCreator()
{
}

// The background color is built by the color wrapper class (0x14097f1d0, defined in afterimageitem.cpp).
// @0x1414b24e0
bool CMS2DefaultSurfaceCreator::CreateDefaultSurface(ecr::RenderService* pRenderService, const efd::ColorA& color)
{
    ecr::RenderContext* pContext = 0;
    pContext = EE_NEW MS2RenderContext(pRenderService, 0);
    pContext->SetBackgroundColor(Unk_AfterImageColor(0.0f, 0.0f, 0.0f, 1.0f));
    pRenderService->AddRenderContext(pContext);
    ecr::RenderSurfacePtr spSurface = pRenderService->CreateRenderSurface(0);
    NiRenderListProcessor* pProcessor = EE_NEW MS2RenderListProcessor();
    pContext->AddRenderSurface(spSurface, pProcessor);
    pRenderService->SetActiveRenderSurface(spSurface);
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();
