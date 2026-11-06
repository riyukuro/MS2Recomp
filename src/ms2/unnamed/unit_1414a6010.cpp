// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Assorted glue of the CGameApp / ServiceManager start-up and
// shutdown path: an opaque node-container reset (walks a tree through the children at node+0x18/+0x20 and returns every
// node to the container's allocator), two CGameApp vtable stubs (slots 60/61 of vftable 0x142f1e140, one state bit each),
// the ServiceManager shutdown-flag clear, the GFx image-creator callback setter, a 16-byte field copy and the KFM cache
// factory setter. File and function names are invented; the container and its allocator live in other units.
// MS2-UNIT: unit_1414a6010
// MS2-RANGE: 0x1414a6010-0x1414a6250 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/tfunctor2.h"
#include "ms2/placeholder/gfximageloader.h"
#include "hook/ms2hook.h"

#include <string.h>

typedef long long i64;

// ---- the node container reset ---------------------------------------------------------------------------------------------
// The container is ATL::CRBTree<DWORD, CStringA> (an MFC CString value): 0x1414a6010 is its RemoveAll and 0x1414a6090
// the private RemovePostOrder it calls (IsNil 0x140a44a40, FreeNode 0x140a44760 live in another unit). Nothing in the
// sources calls RemoveAll on this tree type, so Unk_DwordStrTreeInst instantiates it; the pins at the end bind the
// real-name instances to the exe VAs (they were the FUN_1414a6010 / FUN_1414a6090 stand-ins over FUN_ wrappers).
typedef ATL::CRBTree<DWORD, CStringA> Unk_DwordStrTree;

void Unk_DwordStrTreeInst(Unk_DwordStrTree* pTree)
{
    pTree->RemoveAll();
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// ---- CGameApp vtable stubs (vftable 0x142f1e140 slots 60/61) --------------------------------------------------------------
// CGameApp's own flag word at +0x14c is not part of the shared CGameApp view (ms2.h); each stub reads one bit of it.
struct Unk_CGameAppFlags {
    char m_pad_00[0x14c];
    unsigned int m_nFlags;   // +0x14c
};
MS2_CHECK_OFFSET(Unk_CGameAppFlags, m_nFlags, 0x14c);

// @0x1414a60f0
unsigned int FUN_1414a60f0(Unk_CGameAppFlags* pApp)
{
    return pApp->m_nFlags & 0x10;
}

// @0x1414a61a0
unsigned int FUN_1414a61a0(Unk_CGameAppFlags* pApp)
{
    return pApp->m_nFlags & 0x20;
}

// ---- reference slot release -----------------------------------------------------------------------------------------------
namespace efd { class ServiceManager; class IBase; }

class Unk_RefObj { public: virtual ~Unk_RefObj(); };

// @0x1414a6110
void FUN_1414a6110(Unk_RefObj** ppObj)
{
    if (*ppObj != 0) {
        delete *ppObj;      // scalar deleting destructor (vftable slot 0), delete flag 1
        *ppObj = 0;
    }
}

// ---- ServiceManager shutdown flag -----------------------------------------------------------------------------------------
// The flag at +0x119 is an MS2 engine addition to efd::ServiceManager (missing from the SDK headers).
struct Unk_ServiceManagerView {
    char m_pad_00[0x119];
    unsigned char m_bFlag119;   // +0x119
};
MS2_CHECK_OFFSET(Unk_ServiceManagerView, m_bFlag119, 0x119);

// @0x1414a6180
void FUN_1414a6180(efd::ServiceManager* pServiceManager)
{
    ((Unk_ServiceManagerView*)pServiceManager)->m_bFlag119 = 0;
}

// ---- GFx image-creator callback setter ------------------------------------------------------------------------------------
namespace Scaleform { namespace Render { class Image; class TextureManager; } }
typedef TFunctor<Scaleform::Render::Image*, ParamList<const GFxImageLoader::Protocol&,
    ParamList<Scaleform::Render::TextureManager*, EmptyParam>>> Unk_GFxImageCallback;

// The Scaleform UI manager singleton (DAT_143aaccf8); the image-creator callback handle sits at +0x138.
class Unk_GFxManager
{
public:
    char m_pad_00[0x138];
    Unk_GFxImageCallback m_callback138;   // +0x138
    void FUN_1414a61c0(Unk_GFxImageCallback fnCallback);
};
MS2_CHECK_OFFSET(Unk_GFxManager, m_callback138, 0x138);

// @0x1414a61c0
void Unk_GFxManager::FUN_1414a61c0(Unk_GFxImageCallback fnCallback)
{
    m_callback138 = fnCallback;
}

// ---- 16-byte field copy ---------------------------------------------------------------------------------------------------
struct Unk_Owner60 {
    char m_pad_00[0x60];
    char m_data60[0x10];   // +0x60
};
MS2_CHECK_OFFSET(Unk_Owner60, m_data60, 0x60);

// @0x1414a6200
void FUN_1414a6200(Unk_Owner60* pThis, const void* pSrc)
{
    memcpy(pThis->m_data60, pSrc, 0x10);
}

// ---- KFM cache factory ----------------------------------------------------------------------------------------------------
namespace egmAnimation { class KFMCache; }
extern egmAnimation::KFMCache* (*g_pfnMS2CreateKFMCache)();   // C3: was extern void* DAT_143b094a0 (AnimationService.cpp)

// @0x1414a6230
void FUN_1414a6230(efd::IBase* (*pfnFactory)())
{
    g_pfnMS2CreateKFMCache = (egmAnimation::KFMCache* (*)())pfnFactory;
}

// MS2-PIN: ?RemoveAll@?$CRBTree@KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@K@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAXXZ 0x1414a6010 ; the real tree RemoveAll (was FUN_1414a6010 over the FUN_140a44a40 IsNil wrapper)
// MS2-PIN: ?RemovePostOrder@?$CRBTree@KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@K@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x1414a6090 ; the real private RemovePostOrder (was FUN_1414a6090 over the FUN_140a44a40 / FUN_140a44760 IsNil / FreeNode wrappers)
