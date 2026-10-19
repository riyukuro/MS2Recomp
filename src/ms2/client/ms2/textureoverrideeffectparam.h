// textureoverrideeffectparam.h - the "TextureOverride" effect (effect XML type 0xf): swaps the texture of every
// textured node of the owner actor for "texturepath" while the effect runs (one TextureLayer per node, registered
// with the world's TextureLayerManager). Owning unit: ?\textureoverrideeffectparam.cpp (0x14184b540-0x14184c790).
// Header name assumed from the unit path.
#pragma once
#include <atlcoll.h>
#include <NiAVObject.h>
#include <efd/StdContainers.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/postprocesseffect.h"   // Unk_PPSmartC (texture handle)

// TextureLayer (NiObject-based Layer, 0x30 bytes) is owned by ?\textureanimationdata.cpp.
#include "ms2/client/ms2/textureanimationdata.h"

// 0x50 bytes. vftable 0x142f87618 region (8 slots; overrides 1, 5, 6). Implicit dtor 0x14184bf80, ??_G 0x14184c0b0.
class TextureOverrideEffectParam : public CEffectParam
{
public:
    TextureOverrideEffectParam();                               // 0x14184b540
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x14184b590 "texturepath"
    virtual bool vfunc_5(int nFlags);                           // 5 0x14184b5e0 preload the texture
    virtual CEffectPtr vfunc_6();                               // 6 0x14184b690 new TextureOverrideEffect
public:
    CString m_strTexturePath;       // +0x48 "texturepath" (relative to the resource root)
};
MS2_CHECK_SIZE(TextureOverrideEffectParam, 0x50);
MS2_CHECK_OFFSET(TextureOverrideEffectParam, m_strTexturePath, 0x48);

// 0x70 bytes. 13 slots; ??_G 0x14184c050.
class TextureOverrideEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14184c2a0; ms_RTTI 0x143aef488
public:
    TextureOverrideEffect();                                    // 0x14184b730
    virtual ~TextureOverrideEffect();                           // 0x14184b7b0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14184b840 collect nodes, load
    virtual void vfunc_4();                                     // 4 0x14184baa0 start: apply to every node
    virtual void vfunc_7();                                     // 7 0x14184bb80 stop: remove the layers
    virtual int vfunc_12();                                     // 12 0x14184c290 return 0xf

    void FUN_14184bbb0(NiAVObjectPtr spNode);                   // 0x14184bbb0 add a layer per textured child
    void FUN_14184bd70();                                       // 0x14184bd70 remove all layers
public:
    efd::vector<NiAVObjectPtr> m_vecNodes;                      // +0x30 owner's nodes (GameObject slot 44)
    ATL::CAtlArray<TextureLayerPtr> m_arrLayers;                // +0x48
    Unk_PPSmartC m_spTexture;                                   // +0x68
};
MS2_CHECK_SIZE(TextureOverrideEffect, 0x70);
MS2_CHECK_OFFSET(TextureOverrideEffect, m_vecNodes, 0x30);
MS2_CHECK_OFFSET(TextureOverrideEffect, m_arrLayers, 0x48);
MS2_CHECK_OFFSET(TextureOverrideEffect, m_spTexture, 0x68);
