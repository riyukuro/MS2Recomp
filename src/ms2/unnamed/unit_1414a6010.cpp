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
// The container and its node allocator are opaque here (the allocator lives in another unit): the reset walks the tree
// through the children at node+0x18 / +0x20, returns every node to the allocator, then drops the auxiliary buffer and
// reinstalls the sentinel as the head.
bool FUN_140a44a40(void* pContainer, void* pNode);   // true when pNode is the container's sentinel (nothing to erase)
void FUN_140a44760(void* pContainer, void* pNode);   // returns one node to the container's allocator
void FUN_140159e70(void* p);                          // frees a raw block

struct Unk_TreeHead {
    void* m_pHead;      // +0x00  root, or the sentinel when the container is empty
    i64   m_nCount;     // +0x08
    i64   m_field10;    // +0x10
    void* m_pBuffer;    // +0x18  auxiliary buffer, freed on reset
    i64   m_field20;    // +0x20
    void* m_pSentinel;  // +0x28  reinstalled as the head on reset
};
MS2_CHECK_SIZE(Unk_TreeHead, 0x30);

struct Unk_TreeNode {
    char  m_pad_00[0x18];
    void* m_pLeft;       // +0x18
    void* m_pRight;      // +0x20
};
MS2_CHECK_OFFSET(Unk_TreeNode, m_pLeft, 0x18);
MS2_CHECK_OFFSET(Unk_TreeNode, m_pRight, 0x20);

// @0x1414a6090
void FUN_1414a6090(Unk_TreeHead* pTree, Unk_TreeNode* pNode)
{
    if (FUN_140a44a40(pTree, pNode))
        return;
    FUN_1414a6090(pTree, (Unk_TreeNode*)pNode->m_pLeft);
    FUN_1414a6090(pTree, (Unk_TreeNode*)pNode->m_pRight);
    FUN_140a44760(pTree, pNode);
}

// @0x1414a6010
void FUN_1414a6010(Unk_TreeHead* pTree)
{
    if (!FUN_140a44a40(pTree, pTree->m_pHead))
        FUN_1414a6090(pTree, (Unk_TreeNode*)pTree->m_pHead);
    pTree->m_nCount = 0;
    FUN_140159e70(pTree->m_pBuffer);
    pTree->m_pBuffer = 0;
    pTree->m_field10 = 0;
    pTree->m_pHead = pTree->m_pSentinel;
}

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
extern void* DAT_143b094a0;

// @0x1414a6230
void FUN_1414a6230(efd::IBase* (*pfnFactory)())
{
    DAT_143b094a0 = (void*)pfnFactory;
}
