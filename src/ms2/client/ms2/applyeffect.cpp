// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ApplyEffect: the screen post-effect singleton (fog, soft
// particles, outer glow / material swap render lists, the active CScreenEffectBase objects) and the header-inline
// helpers and STL/ATL glue compiled into the same TU. Third-party v2525 bodies (work/xr2/bodies.tsv) used as hints.
// MS2-UNIT: ?\applyeffect.cpp
// MS2-RANGE: 0x1409a36c0-0x1409ab110 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1409a5490 ; unique
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x1409a5530 ; unique
// MS2-PIN: ??$?0AEBH@?$_Tuple_val@AEBH@std@@QEAA@AEBH@Z 0x1409a5580 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x1409a55b0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1409a5660 ; unique
// MS2-PIN: ??$GetSystemServiceAs@VMS2SceneGraphService@@@ServiceManager@efd@@QEBAPEAVMS2SceneGraphService@@XZ 0x1409a5730 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1409a58b0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@1@@Z 0x1409a5d70 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@1@@Z 0x1409a69b0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1409a6e70 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1409a7040 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1409a7120 ; unique
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x1409a7200 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x1409a7220 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x1409a7230 ; unique
// MS2-PIN: ??$get@$0A@AEBH@std@@YAAEBH$$QEAV?$tuple@AEBH@0@@Z 0x1409a7260 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x1409a7280 ; prop
// MS2-PIN: ??0?$SmartPointer@VNi3DRenderView@@@efd@@QEAA@PEAVNi3DRenderView@@@Z 0x1409a73e0 ; unique
// MS2-PIN: ??0?$SmartPointer@VNiViewRenderClick@@@efd@@QEAA@PEAVNiViewRenderClick@@@Z 0x1409a74a0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCScreenEffectBase@@@@QEAA@PEAVCScreenEffectBase@@@Z 0x1409a7560 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCScreenEffectBase@@@@QEAA@XZ 0x1409a7590 ; unique
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x1409a77c0 ; unique
// MS2-PIN: ??1?$SmartPointer@VNi3DRenderView@@@efd@@QEAA@XZ 0x1409a7ad0 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCScreenEffectBase@@@@QEAAAEAV0@H@Z 0x1409a7ed0 ; unique
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1409a8340 ; prop
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x1409a8430 ; unique
// MS2-PIN: ?GetRTTI@MS2RenderListProcessor@@UEBAPEBVNiRTTI@@XZ 0x1409a8c70 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCScreenEffectBase@@@@AEBAXXZ 0x1409a9d90 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCScreenEffectBase@@@@AEBAXPEAX@Z 0x1409a9de0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1409a9fb0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x1409aa7a0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1409aa7b0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$MS2Ptr@VCScreenEffectBase@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCScreenEffectBase@@@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x1409aa890 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??0SoftParticlesManager@@QEAA@XZ 0x1409a7940
// MS2-PIN: ??_7UpdateAffectsFunctor@@6BEntitySceneGraphFunctor@SceneGraphService@ecr@@@ 0x142db5b80
// MS2-PIN: ??_7UpdateAffectsFunctor@@6BHandleSceneGraphFunctor@SceneGraphService@ecr@@@ 0x142db5b98
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\applyeffect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <math.h>
#include <float.h>
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/softparticlesmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/posteffectparam.h"
#include "ms2/client/ms2/ms2outerglowmaterialswapprocessor.h"
#include "ms2/client/ms2/ms2materialswapprocessor.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "hook/ms2hook.h"
#include "ms2/ms2recover.h"
#include <NiDefaultClickRenderStep.h>
#include <NiViewRenderClick.h>
#include <NiMaterial.h>
#include <NiShaderFactory.h>
#include <NiFogProperty.h>
#include <NiRenderObject.h>
#include <NiCamera.h>
#include <NiRenderer.h>
#include <NiDX9Renderer.h>
#include <NiPoint3.h>
#include <ecr/RenderSurface.h>

// ---- out-of-unit callees (names inferred from the callers) ----
// The current field's effect settings (offsets read by the fog / soft particle / outer glow setters below).
class Unk_AeFieldInfo : public CPtred
{
public:
    unsigned char m_pad_18[0x17c - 0x18];
    NiPoint3 m_vOuterGlow;                                  // +0x17c shader constant of the outer glow color
    unsigned char m_pad_188[0x1d8 - 0x188];
    bool m_bRenderFlag;                                     // +0x1d8
    int m_nRenderValue;                                     // +0x1dc
    unsigned char m_pad_1e0[0x200 - 0x1e0];
    unsigned int m_uiFogColor;                              // +0x200
    float m_fFogNear;                                       // +0x204
    float m_fFogFar;                                        // +0x208
    bool m_bFieldFog;                                       // +0x20c
    unsigned int m_uiFieldFogColor;                         // +0x210 (passed by address)
    float m_fFieldFogNear;                                  // +0x214
    float m_fFieldFogFar;                                   // +0x218
    float m_fFieldFogDensity;                               // +0x21c
    unsigned char m_pad_220[4];
    float m_fSoftParticle[5];                               // +0x224
};
MS2_CHECK_OFFSET(Unk_AeFieldInfo, m_fSoftParticle, 0x224);

// The current field handle (0x20 bytes, returned through a hidden pointer by the world singleton).
struct Unk_AeMapRef;
void FUN_1408850f0(Unk_AeMapRef* pRef);                     // dtor
struct Unk_AeMapRef
{
    ~Unk_AeMapRef() { FUN_1408850f0(this); }
    void* m_p0; void* m_p1; void* m_p2; void* m_p3;
};
MS2_CHECK_SIZE(Unk_AeMapRef, 0x20);
class Unk_AeWorld
{
public:
    Unk_AeMapRef FUN_141bd30a0();                           // the current field
};
Unk_AeWorld* FUN_1403ed2d0();
long long FUN_1409657a0(Unk_AeMapRef* pRef);                // non-null test
Unk_AeFieldInfo* FUN_140885340(Unk_AeMapRef* pRef);         // operator->
void FUN_1414d0180(bool bFlag);
void FUN_14150ccc0(int nValue);
void FUN_14107b010();
ecr::RenderSurface* FUN_1413f98d0();
Ni3DRenderView* FUN_1413f9a70();                            // the main view
NiColor FUN_141b6dea0(unsigned int uiColor);                // 0xRRGGBB -> color
bool FUN_14028d470(float fA, float fB);                     // |a - b| < epsilon

// Header-inline engine / option accessors compiled into this TU (the COMDAT copies the other units call).
class Unk_AeGraphicOption
{
public:
    bool FUN_14125e020() const;                             // fog option
    bool FUN_14125e0b0() const;                             // soft particle option
    bool FUN_14125e160() const;                             // outer glow option
    // @0x1409a8fd0
    bool FUN_1409a8fd0() const { return m_bFieldFog; }
    // @0x1409a8ab0
    unsigned int FUN_1409a8ab0() const { return m_uiHeight; }
    // @0x1409a8aa0
    unsigned int FUN_1409a8aa0() const { return m_uiWidth; }
    unsigned char m_pad0[0x18];
    bool m_bFieldFog;                                       // +0x18
    unsigned char m_pad19[0xb];
    unsigned int m_uiHeight;                                // +0x24
    unsigned int m_uiWidth;                                 // +0x28
};
class Unk_AeGameOption;
extern Unk_AeGameOption* DAT_143ab3da8;                     // the option manager singleton
class Unk_AeGameOption
{
public:
    // @0x1409a8b10
    static Unk_AeGameOption* FUN_1409a8b10() { return DAT_143ab3da8; }
    // @0x1409a8ac0
    Unk_AeGraphicOption* FUN_1409a8ac0() { return &m_graphic; }
    unsigned char m_pad0[0x6c];
    Unk_AeGraphicOption m_graphic;
};

// The shader constant keys the effects write (global NiFixedStrings).
extern NiFixedString DAT_143ae5268;                         // outer glow material
extern NiFixedString DAT_143ae5270;                         // material swap material
extern NiFixedString DAT_143ae52f8, DAT_143ae5300, DAT_143ae5308, DAT_143ae5310, DAT_143ae5318;   // fog
extern NiFixedString DAT_143ae5340, DAT_143ae5348, DAT_143ae5350;
extern NiFixedString DAT_143ae5358, DAT_143ae5360, DAT_143ae5368, DAT_143ae5370, DAT_143ae5378;   // soft particles
extern NiFixedString DAT_143ae5458, DAT_143ae5460, DAT_143ae5468;                                // screen ratio

// 0x1409a8f20/0x1409a8f90: finite checks before a shader constant is updated.
int FUN_1409a8f20(const NiColor* pkColor)                   // @0x1409a8f20
{
    if ((_fpclass((double)pkColor->r) & 0x207) != 0 || (_fpclass((double)pkColor->g) & 0x207) != 0 ||
        (_fpclass((double)pkColor->b) & 0x207) != 0) {
        return 0;
    } else {
        return 1;
    }
}
int FUN_1409a8f90(const float* pf)                          // @0x1409a8f90
{
    if ((_fpclass((double)*pf) & 0x207) != 0) {
        return 0;
    } else {
        return 1;
    }
}

// The render feature switchboard (singleton 0x143ab3da0).
class Unk_AeFeatureState
{
public:
    // @0x1409a8f00
    bool FUN_1409a8f00() const { return m_bActive; }
    unsigned char m_pad0[0x90];
    bool m_bActive;
};
class Unk_AeFeatureMgr;
extern Unk_AeFeatureMgr* DAT_143ab3da0;
class Unk_AeFeatureMgr
{
public:
    // @0x1409a8b20
    static Unk_AeFeatureMgr* FUN_1409a8b20() { return DAT_143ab3da0; }
    void FUN_1416a3920(int nFeature, bool bEnable);
    Unk_AeFeatureState* FUN_1416a3a90(int nFeature);
    void FUN_1416aa450(int nFeature, bool bFlag);
};

// Shader constant update helpers (0x1409a5770 float array, 0x1409a5810 point array).
bool FUN_1409a5770(NiFixedString& kKey, const float* pfData, int iCount);
bool FUN_1409a5810(NiFixedString& kKey, const NiPoint3* pkData, int iCount);
bool FUN_1409a5850(NiFixedString& kKey, const bool* pbData, unsigned int uiSize);
MS2SceneGraphService* FUN_1413f98b0();
int FUN_1414d00b0(NiRenderObject* pObj);                    // material swap predicate

// @0x1409a36c0
ApplyEffect::ApplyEffect()
    : m_fFogNear(100.0f), m_fFogFar(10000.0f), m_uiFogColor(0), m_spOuterGlow(0), m_spMaterialSwap(0),
      m_clicks(10), m_spSoftParticles(0)
{
    m_spSoftParticles = NiNew SoftParticlesManager();
}

// @0x1409a3810
ApplyEffect::~ApplyEffect()
{
    m_spOuterGlow = 0;
    m_spMaterialSwap = 0;
}

// Scene-graph walker (48 bytes) and per-object shader value setters.
class Unk_AeSceneIter
{
public:
    Unk_AeSceneIter(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_AeSceneIter();                                     // 0x14098cf00
    NiAVObject* FUN_14098e0d0(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
MS2_CHECK_SIZE(Unk_AeSceneIter, 0x30);
void FUN_141b70c50(NiRenderObject* pObject, float fValueA, float fValueB);
NiAVObject* FUN_141b6efc0(void* pOwner);

// @0x1409a4020
bool ApplyEffect::FUN_1409a4020(int nId, CScreenEffectBase* pEffect)
{
    if (nId != 0 && pEffect != 0) {
        int key = pEffect->vfunc_5();
        m_effects[key].AssignRaw(pEffect);
        return true;
    }
    return false;
}

// @0x1409a3b60
void ApplyEffect::FUN_1409a3b60(bool bEnable)
{
    for (EffectMap::iterator it = m_effects.begin(); it != m_effects.end(); ++it) {
        if (it->second.get() != 0) {
            it->second->vfunc_6(bEnable);
        }
    }
}

// @0x1409a4090
void ApplyEffect::FUN_1409a4090()
{
    for (EffectMap::iterator it = m_effects.begin(); it != m_effects.end(); ++it) {
        if (it->second.get() != 0) {
            it->second->vfunc_4();
        }
    }
    m_effects.clear();
}

// @0x1409a4150
void ApplyEffect::FUN_1409a4150()
{
    for (EffectMap::iterator it = m_effects.begin(); it != m_effects.end(); ++it) {
        if (it->second.get() ? true : false) {
            if (!it->second->vfunc_2()) {
                it->second = 0;
            }
        }
    }
}

// @0x1409a3ee0
void ApplyEffect::FUN_1409a3ee0(int nId, int nType)
{
    MS2Ptr<CScreenEffectBase>& rEffect = m_effects[nId];
    if (rEffect.get() ? true : false) {
        if (rEffect->FUN_1409a8c30() == nType) {
            rEffect->vfunc_1();
        }
    }
}

// @0x1409a3f80
void ApplyEffect::FUN_1409a3f80(int nId, int nType)
{
    MS2Ptr<CScreenEffectBase>& rEffect = m_effects[nId];
    if (rEffect.get() ? true : false) {
        if (rEffect->FUN_1409a8c30() == nType) {
            rEffect->vfunc_3();
        }
    }
}

// @0x1409a4960
void ApplyEffect::GetFog(float* pfNear, float* pfFar, unsigned int* puiColor)
{
    *pfNear = m_fFogNear;
    *pfFar = m_fFogFar;
    *puiColor = m_uiFogColor;
}

// @0x1409a5160
SoftParticlesManager* ApplyEffect::GetSoftParticles()
{
    return m_spSoftParticles;
}

// @0x1409a5190
void ApplyEffect::SetSoftParticlesEnabled(bool bEnabled)
{
    m_spSoftParticles->FUN_141773940(bEnabled);
}

// @0x1409a4e70
void ApplyEffect::SetOuterGlowEnabled(bool bEnabled)
{
    int iResult;
    if (bEnabled) {
        SwapClickProcessor(m_spOuterGlow);
        iResult = 0;
    } else {
        RestoreClickProcessors();
        iResult = 0;
    }
}

// @0x1409a4e30
void ApplyEffect::ApplySoftParticleOption()
{
    SetSoftParticlesOption(Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125e0b0(), 0);
}

// @0x1409a4ed0
void ApplyEffect::ApplyOuterGlowOption()
{
    SetOuterGlowEnabled(Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125e160());
}

// @0x1409a4f10
void ApplyEffect::SetFeatureB(bool bEnabled)
{
    Unk_AeFeatureMgr::FUN_1409a8b20()->FUN_1416a3920(0xb, bEnabled);
}

// @0x1409a5100
void ApplyEffect::SetFeature8(bool bEnabled, bool bUnused)
{
    Unk_AeFeatureMgr::FUN_1409a8b20()->FUN_1416a3920(8, bEnabled);
    float fOne = 1.0f;
    FUN_1409a5770(DAT_143ae5340, &fOne, 1);
}

// @0x1409a5770
bool FUN_1409a5770(NiFixedString& kKey, const float* pfData, int iCount)
{
    for (int i = 0; i < iCount; i++) {
        if (!FUN_1409a8f90(&pfData[i])) {
            throw 13;
        }
    }
    if (NiShaderFactory::UpdateGlobalShaderConstant(kKey, (unsigned int)((__int64)iCount * sizeof(float)), pfData)) {
        return true;
    }
    return false;
}

// @0x1409a5810
bool FUN_1409a5810(NiFixedString& kKey, const NiPoint3* pkData, int iCount)
{
    if (NiShaderFactory::UpdateGlobalShaderConstant(kKey, (unsigned int)((__int64)iCount * 0xc), pkData)) {
        return true;
    }
    return false;
}

// @0x1409a5850
bool FUN_1409a5850(NiFixedString& kKey, const bool* pbData, unsigned int uiSize)
{
    if (NiShaderFactory::UpdateGlobalShaderConstant(kKey, uiSize, pbData)) {
        return true;
    }
    return false;
}

// @0x1409a3ad0
void ApplyEffect::ApplyOuterGlowColor()
{
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        if (Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125e160()) {
            FUN_1409a5810(DAT_143ae5348, &FUN_140885340(&field)->m_vOuterGlow, 1);
        }
    }
    FUN_14107b010();
}

// @0x1409a5080
void ApplyEffect::ApplyFieldRenderInfo()
{
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        FUN_1414d0180(FUN_140885340(&field)->m_bRenderFlag);
        FUN_14150ccc0(FUN_140885340(&field)->m_nRenderValue);
    }
}

// @0x1409a43a0
void ApplyEffect::ApplyFieldFogRange(bool bEnabled)
{
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        Unk_AeFieldInfo* pField = FUN_140885340(&field);
        SetFogRange(bEnabled, pField->m_fFogNear, pField->m_fFogFar, pField->m_uiFogColor);
    }
}

// @0x1409a4230
void ApplyEffect::ResetScreenRatio()
{
    float fZero = 0.0f;
    float fOne = 1.0f;
    FUN_1409a5770(DAT_143ae5350, &fOne, 1);
    FUN_1409a5770(DAT_143ae5340, &fZero, 1);
    FUN_1409a5770(DAT_143ae5458, &fZero, 1);
    unsigned int uiA = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8ab0();
    unsigned int uiB = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8aa0();
    if (uiA != 0 && uiB != 0) {
        if (uiA >= uiB) {
            float fFirst = (float)uiB / (float)uiA;
            float fSecond = fZero;
            FUN_1409a5770(DAT_143ae5460, &fFirst, 1);
            FUN_1409a5770(DAT_143ae5468, &fSecond, 1);
        } else {
            float fFirst = fZero;
            float fSecond = (float)uiA / (float)uiB;
            FUN_1409a5770(DAT_143ae5460, &fFirst, 1);
            FUN_1409a5770(DAT_143ae5468, &fSecond, 1);
        }
    }
}

// @0x1409a4f40
void ApplyEffect::SetScreenRatio(float fScale)
{
    unsigned int uiA = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8ab0();
    unsigned int uiB = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8aa0();
    if (uiA == 0 || uiB == 0) {
        return;
    }
    if (uiA >= uiB) {
        float fFirst = fScale * ((float)uiB / (float)uiA);
        float fSecond = fScale;
        FUN_1409a5770(DAT_143ae5460, &fFirst, 1);
        FUN_1409a5770(DAT_143ae5468, &fSecond, 1);
    } else {
        float fFirst = fScale;
        float fSecond = fScale * ((float)uiA / (float)uiB);
        FUN_1409a5770(DAT_143ae5460, &fFirst, 1);
        FUN_1409a5770(DAT_143ae5468, &fSecond, 1);
    }
}

// @0x1409a4c60
bool ApplyEffect::SetSoftParticlesOption(bool bEnabled, Unk_AeFieldInfo* pField)
{
    if (pField == 0) {
        Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
        pField = FUN_140885340(&field);
    }
    if (pField != 0) {
        Unk_AeFeatureState* pState = Unk_AeFeatureMgr::FUN_1409a8b20()->FUN_1416a3a90(3);
        if (pState != 0) {
            if (bEnabled) {
                FUN_1409a5770(DAT_143ae5358, &pField->m_fSoftParticle[0], 1);
                FUN_1409a5770(DAT_143ae5360, &pField->m_fSoftParticle[1], 1);
                FUN_1409a5770(DAT_143ae5368, &pField->m_fSoftParticle[2], 1);
                FUN_1409a5770(DAT_143ae5370, &pField->m_fSoftParticle[3], 1);
                FUN_1409a5770(DAT_143ae5378, &pField->m_fSoftParticle[4], 1);
            }
            Unk_AeFeatureMgr::FUN_1409a8b20()->FUN_1416a3920(3, bEnabled);
            bEnabled = (bEnabled && pState->FUN_1409a8f00()) ? 1 : 0;
            Unk_AeFeatureMgr::FUN_1409a8b20()->FUN_1416aa450(8, bEnabled);
        }
    }
    return bEnabled;
}

// @0x1409a49b0
void ApplyEffect::ApplyFieldFog()
{
    Unk_AeGraphicOption* pOption = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0();
    if (pOption != 0) {
        ApplyFieldFogRange(pOption->FUN_14125e020());
    }
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        bool bFog;
        if (pOption->FUN_1409a8fd0() && FUN_140885340(&field)->m_bFieldFog != 0) {
            bFog = true;
        } else {
            bFog = false;
        }
        Unk_AeFieldInfo* pField = FUN_140885340(&field);
        GetInstance()->SetFogEffect(bFog, &pField->m_uiFieldFogColor, pField->m_fFieldFogNear,
            pField->m_fFieldFogFar, pField->m_fFieldFogDensity);
    }
}

// @0x1409a4b00
void ApplyEffect::ApplyFieldFogEnabled(bool bEnabled)
{
    ApplyFieldFogRange(bEnabled);
    Unk_AeGraphicOption* pOption = Unk_AeGameOption::FUN_1409a8b10()->FUN_1409a8ac0();
    if (pOption == 0) {
        return;
    }
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        bool bFog;
        if (bEnabled && pOption->FUN_1409a8fd0() && FUN_140885340(&field)->m_bFieldFog != 0) {
            bFog = true;
        } else {
            bFog = false;
        }
        Unk_AeFieldInfo* pField = FUN_140885340(&field);
        GetInstance()->SetFogEffect(bFog, &pField->m_uiFieldFogColor, pField->m_fFieldFogNear,
            pField->m_fFieldFogFar, pField->m_fFieldFogDensity);
    }
}

// The renderer's fog state (the object the DX9 renderer keeps at +0xba8).
class Unk_AeFogState
{
public:
    // @0x1409a9bf0
    void FUN_1409a9bf0(float fScale)
    {
        if (fScale <= 0.0f) {
            fScale = 0.00001f;
        }
        m_fScale = fScale;
        m_fInverse = 1.0f / fScale - 1.0f;
    }
    unsigned char m_pad0[0x94];
    float m_fInverse;
    float m_fScale;
};
// @0x1409a8d60
inline Unk_AeFogState* FUN_1409a8d60(NiDX9Renderer* pRenderer)
{
    return *(Unk_AeFogState**)((char*)pRenderer + 0xba8);
}
extern efd::SmartPointer<NiFogProperty> DAT_143afa7f0;      // the default fog property
// @0x1409a8a80
inline NiFogProperty* FUN_1409a8a80() { return DAT_143afa7f0; }

// The scene graph service lookup (global service manager reference).
efd::ServiceManager* FUN_1401cd190(void* pHolder);
extern unsigned char DAT_143b059e8;
// @0x1409a5700
inline MS2SceneGraphService* FUN_1409a5700(void* pHolder)
{
    return FUN_1401cd190(pHolder)->GetSystemServiceAs<MS2SceneGraphService>();
}

// The functor that refreshes the effects of every scene graph.
class UpdateAffectsFunctor : public ecr::SceneGraphService::EntitySceneGraphFunctor,
    public ecr::SceneGraphService::HandleSceneGraphFunctor
{
public:
    UpdateAffectsFunctor();                                 // 0x1409a79c0
    virtual ~UpdateAffectsFunctor();                        // 0x1409a7d30
    virtual efd::Bool operator()(const egf::Entity* pEntity, const efd::vector<NiObjectPtr>& objects);   // 0x1409a84d0
    virtual efd::Bool operator()(const ecr::SceneGraphService::SceneGraphHandle handle,
        const efd::vector<NiObjectPtr>& objects);           // 0x1409a8470
};

// @0x1409a4450
void ApplyEffect::SetFogRange(bool bEnabled, float fNear, float fFar, unsigned int uiColor)
{
    m_fFogNear = fNear;
    m_fFogFar = fFar;
    m_uiFogColor = uiColor;
    float fDepth = 1.0f;
    float fScale = 1.0f;
    Ni3DRenderView* pView = FUN_1413f9a70();
    if (!pView) {
        return;
    }
    if (!pView->GetCamera()) {
        return;
    }
    const NiFrustum& kFrustum = pView->GetCamera()->GetViewFrustum();
    float fCameraNear = kFrustum.m_fNear;
    float fCameraFar = kFrustum.m_fFar;
    if (fCameraFar - fCameraNear != 0.0f) {
        fDepth = (fCameraFar - m_fFogNear) / (fCameraFar - fCameraNear);
    }
    float fSpan = (fCameraFar - fCameraNear) * fDepth;
    float fTotal = fSpan + (m_fFogFar - fCameraFar);
    if (fTotal != 0.0f) {
        fScale = fSpan / fTotal;
    }
    NiDX9Renderer* pDX9Renderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    FUN_1409a8d60(pDX9Renderer)->FUN_1409a9bf0(fScale);
    NiFogProperty* pFog = FUN_1409a8a80();
    pFog->SetFog(bEnabled);
    pFog->SetFogColor(FUN_141b6dea0(uiColor));
    pFog->SetDepth(fDepth);
    MS2SceneGraphService* pService = FUN_1409a5700(&DAT_143b059e8);
    if (pService) {
        UpdateAffectsFunctor kFunctor;
        pService->ForEachEntitySceneGraph(kFunctor);
    }
}

// @0x1409a46a0
void ApplyEffect::SetFogEffect(bool bEnabled, unsigned int* puiColor, float fNear, float fFar, float fDensity)
{
    NiColor kColor = FUN_141b6dea0(*puiColor);
    fDensity = fDensity / 100.0f;
    float fRange = ((fNear - fFar) + 1.0f) - fDensity;
    if (FUN_14028d470(fRange, 0.0f)) {
        throw 13;
    }
    if (!FUN_1409a8f90(&fRange)) {
        throw 13;
    }
    if (!bEnabled) {
        fNear = -10000.0f;
    }
    bEnabled = true;
    if (NiShaderFactory::GetInstance()->GetGlobalShaderConstantEntry(DAT_143ae52f8) == 0) {
        NiShaderFactory::RegisterGlobalShaderConstant(DAT_143ae52f8, NiShaderAttributeDesc::ATTRIB_TYPE_BOOL, 1, &bEnabled);
        if (!FUN_1409a8f20(&kColor)) {
            throw 13;
        }
        NiShaderFactory::RegisterGlobalShaderConstant(DAT_143ae5300, NiShaderAttributeDesc::ATTRIB_TYPE_POINT3, 0xc, &kColor);
        if (!FUN_1409a8f90(&fNear)) {
            throw 13;
        }
        NiShaderFactory::RegisterGlobalShaderConstant(DAT_143ae5308, NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT, 4, &fNear);
        if (!FUN_1409a8f90(&fFar)) {
            throw 13;
        }
        NiShaderFactory::RegisterGlobalShaderConstant(DAT_143ae5310, NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT, 4, &fFar);
        if (!FUN_1409a8f90(&fDensity)) {
            throw 13;
        }
        NiShaderFactory::RegisterGlobalShaderConstant(DAT_143ae5318, NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT, 4, &fDensity);
        FUN_1413f98b0()->ClearAllCachedShaders();
    }
    FUN_1409a5850(DAT_143ae52f8, &bEnabled, 1);
    FUN_1409a5810(DAT_143ae5300, (const NiPoint3*)&kColor, 1);
    FUN_1409a5770(DAT_143ae5308, &fNear, 1);
    FUN_1409a5770(DAT_143ae5310, &fFar, 1);
    FUN_1409a5770(DAT_143ae5318, &fDensity, 1);
}

// @0x1409a3c20
void ApplyEffect::RestoreClickProcessors()
{
    NiDefaultClickRenderStep* pStep = NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
    if (pStep) {
        for (POSITION pos = m_clicks.GetHeadPosition(); pos; m_clicks.GetNext(pos)) {
            CStringA strName = m_clicks.GetKeyAt(pos);
            NiRenderListProcessor* pProcessor = m_clicks.GetValueAt(pos);
            NiViewRenderClick* pClick;
            NiViewRenderClick* pAlias;
            {
                NiFixedString kName(strName);
                pClick = NiDynamicCast(NiViewRenderClick, pStep->GetRenderClickByName(kName));
                pAlias = pClick;
            }
            if (pClick) {
                pClick->SetProcessor(pProcessor, 0);
            }
        }
    }
    m_clicks.RemoveAll();
}

// @0x1409a3d80
void ApplyEffect::SwapClickProcessor(NiRenderListProcessor* pProcessor)
{
    if (!pProcessor) {
        return;
    }
    RestoreClickProcessors();
    Unk_AeMapRef field = FUN_1403ed2d0()->FUN_141bd30a0();
    if (FUN_1409657a0(&field) != 0) {
        NiDefaultClickRenderStep* pStep = NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
        if (pStep) {
            NiViewRenderClick* pClick;
            NiViewRenderClick* pAlias;
            {
                NiFixedString kName("SceneGraphClick");
                pClick = NiDynamicCast(NiViewRenderClick, pStep->GetRenderClickByName(kName));
                pAlias = pClick;
            }
            if (pClick) {
                NiRenderListProcessor* pOld = pClick->GetProcessor();
                {
                    CStringA strName(pClick->GetName());
                    m_clicks.SetAt(strName, pOld);
                }
                pClick->SetProcessor(pProcessor, 0);
            }
        }
    }
}

// @0x1409a38d0
void ApplyEffect::Initialize()
{
    if (!m_spOuterGlow) {
        NiMaterialPtr spMaterial(NiMaterial::GetMaterial(DAT_143ae5268));
        m_spOuterGlow = NiNew MS2OuterGlowMaterialSwapProcessor(spMaterial);
    }
    if (!m_spMaterialSwap) {
        NiMaterialPtr spMaterial(NiMaterial::GetMaterial(DAT_143ae5270));
        m_spMaterialSwap = NiNew MS2MaterialSwapProcessor(spMaterial, FUN_1414d00b0);
    }
    ApplyFieldFog();
    ApplySoftParticleOption();
    ApplyOuterGlowOption();
    ApplyFieldRenderInfo();
}

// @0x1409a78e0
MS2OuterGlowMaterialSwapProcessor::MS2OuterGlowMaterialSwapProcessor(NiMaterialPtr spMaterial)
    : m_spGlowMaterial(spMaterial)
{
}

// @0x1409a79c0
UpdateAffectsFunctor::UpdateAffectsFunctor()
{
}

// @0x1409a7d30
UpdateAffectsFunctor::~UpdateAffectsFunctor()
{
}

// @0x1409a84d0
efd::Bool UpdateAffectsFunctor::operator()(const egf::Entity* pEntity, const efd::vector<NiObjectPtr>& objects)
{
    NiNode* pNode = NiDynamicCast(NiNode, objects[0]);
    if (pNode) {
        pNode->UpdateEffects();
    }
    return false;
}

// @0x1409a8470
efd::Bool UpdateAffectsFunctor::operator()(const ecr::SceneGraphService::SceneGraphHandle handle,
    const efd::vector<NiObjectPtr>& objects)
{
    NiNode* pNode = NiDynamicCast(NiNode, objects[0]);
    if (pNode) {
        pNode->UpdateEffects();
    }
    return false;
}

SoftParticlesManager::SoftParticlesManager()
    : m_spClick(0), m_spView(0), m_spMaterial(0)
{
}

// @0x1409a8c70
const NiRTTI* MS2OuterGlowMaterialSwapProcessor::GetRTTI() const
{
    return &ms_RTTI;
}

// @0x1409a5320
void FUN_1409a5320(NiAVObject* pRoot, float fValueA, float fValueB, const char* pcName)
{
    if (pRoot == 0) {
        return;
    }
    Unk_AeSceneIter it(pRoot);
    NiAVObject* pObject;
    while ((pObject = it.FUN_14098e0d0(true)) != 0) {
        NiRenderObject* pRenderObject = NiDynamicCast(NiRenderObject, pObject);
        if (pRenderObject != 0) {
            if (pcName == 0 || pRenderObject->GetName().Equals(pcName)) {
                FUN_141b70c50(pRenderObject, fValueB, fValueA);
            }
        }
    }
    pRoot->UpdateProperties();
}

// @0x1409a51d0
void FUN_1409a51d0(void* pOwner, float fValueA, float fValueB, const char* pcName)
{
    if (pOwner != 0) {
        efd::SmartPointer<NiAVObject> spRoot(FUN_141b6efc0(pOwner));
        if (!(spRoot == 0)) {
            Unk_AeSceneIter it(spRoot);
            NiAVObject* pObject;
            while ((pObject = it.FUN_14098e0d0(true)) != 0) {
                NiRenderObject* pRenderObject = NiDynamicCast(NiRenderObject, pObject);
                if (pRenderObject != 0) {
                    if (pcName == 0 || pRenderObject->GetName().Equals(pcName)) {
                        FUN_141b70c50(pRenderObject, fValueB, fValueA);
                    }
                }
            }
            spRoot->UpdateProperties();
        }
    }
}
