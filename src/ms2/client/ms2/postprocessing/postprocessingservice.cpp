// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The post-processing render steps (anti-alias, bloom, colour
// perspective, depth of field, fades, blurs, shimmer, overdraw), their PostProcessEffect / ReloadablePostProcess bases and
// the PostProcessingService that owns them.
// MS2-UNIT: client\ms2\postprocessing\postprocessingservice.cpp
// MS2-RANGE: 0x14169d920-0x1416b5320 .text$mn
// MS2-RANGE: 0x1400fc2a0-0x1400fc960 .text$di
// MS2-RANGE: 0x142cb45d0-0x142cb4715 .text$yd
// MS2-PIN: ??1MS2VelocityMaterialSwapProcessor@@UEAA@XZ 0x1416af0e0 ; fx13: own dtor (~NiClickRenderStep/~NiRenderStep rows are mainsystem.cpp 0x141474db0/0x141474e50)
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GDepthOfFieldRenderStep@@UEAAPEAXI@Z 0x1416a09a0 ; prop
// MS2-PIN: ??_GFadeInOutRenderStep@@UEAAPEAXI@Z 0x1416a0e80 ; prop
// MS2-PIN: ??_GFadeInRenderStep@@UEAAPEAXI@Z 0x1416a1320 ; prop
// MS2-PIN: ??_GGaussianBlurRenderStep@@UEAAPEAXI@Z 0x1416a1900 ; unique
// MS2-PIN: ??_GHeatShimmerRenderStep@@UEAAPEAXI@Z 0x1416a1bc0 ; prop
// MS2-PIN: ??_GMonochromeRenderStep@@UEAAPEAXI@Z 0x1416a1ea0 ; prop
// MS2-PIN: ??_GMotionBlurRenderStep@@UEAAPEAXI@Z 0x1416a2380 ; prop
// MS2-PIN: ??_GOuterBlurRenderStep@@UEAAPEAXI@Z 0x1416a2500 ; prop
// MS2-PIN: ??_GOverdrawRenderStep@@UEAAPEAXI@Z 0x1416a2810 ; unique
// MS2-PIN: ??9?$SmartPointer@VNiRenderedTexture@@@efd@@QEBA_NPEAVNiRenderedTexture@@@Z 0x1416a2d80 ; unique
// MS2-PIN: ??$_Kfn@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@?$_Tmap_traits@HV?$SmartPointer@VPostProcessEffect@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@1@@Z 0x1416ad7a0 ; unique
// MS2-PIN: ??$forward@AEAV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@YAAEAV?$SmartPointer@VPostProcessEffect@@@efd@@AEAV12@@Z 0x1416adc10 ; prop
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x1416adc30 ; prop
// MS2-PIN: ??0?$SmartPointer@VPostProcessEffect@@@efd@@QEAA@AEBV01@@Z 0x1416ae420 ; prop
// MS2-PIN: ??1InterpItem@NiGeomMorpherController@@QEAA@XZ 0x1416aeff0 ; prop
// MS2-PIN: ??4?$SmartPointer@VNiAVObject@@@efd@@QEAAAEAV01@AEBV01@@Z 0x1416af580 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1416afbf0 ; prop
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x1416afd00 ; unique
// MS2-PIN: ??_G?$NiTList@H@@UEAAPEAXI@Z 0x1416aff70 ; prop
// MS2-PIN: ??_G?$NiTListBase@V?$DFALL@H@@H@@MEAAPEAXI@Z 0x1416affd0 ; prop
// MS2-PIN: ??_G?$NiTPointerListBase@V?$DFALL@H@@H@@UEAAPEAXI@Z 0x1416b0030 ; prop
// MS2-PIN: ??_G?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@QEAAPEAXI@Z 0x1416b0110 ; unique
// MS2-PIN: ??_GNiRefObject@@UEAAPEAXI@Z 0x1416b0270 ; unique
// MS2-PIN: ?GetClassDesc@PostProcessingService@@UEBAPEBVClassInfo@efd@@XZ 0x1416b0ac0 ; unique
// MS2-PIN: ?GetClassDesc@SceneGraphRemovedMessage@ecr@@UEBAPEBVClassInfo@efd@@XZ 0x1416b0ad0 ; unique
// MS2-PIN: ?GetDevType@NiDX9Renderer@@QEBA?AW4_D3DDEVTYPE@@XZ 0x1416b0b00 ; unique
// MS2-PIN: ?FUN_1416b1d10@CPlaneReflectionSetting@@QEAA_NXZ 0x1416b1d10 ; unique
// MS2-PIN: ?FUN_1416b1d40@Unk_PPGraphicsOptions@@QEAA_NXZ 0x1416b1d40 ; unique
// MS2-PIN: ?vfunc_1@PostProcessingService@@UEAAXH@Z 0x1416b1d80 ; unique
// MS2-PIN: ?vfunc_4@PostProcessingService@@UEAAXH@Z 0x1416b1dc0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VPostProcessingService@@VEntityChangeMessage@egf@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1dd0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VPostProcessingService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1e10 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VPostProcessingService@@VSceneGraphRemovedMessage@ecr@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1e50 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageSubclassHandler@VPostProcessingService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1e90 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageWrapperSubclassHandler@VPostProcessingService@@VEntityChangeMessage@egf@@V23@$0CAAE@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1ed0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageWrapperSubclassHandler@VPostProcessingService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x1416b1ef0 ; unique
// MS2-PIN: ?SetupClassInfo@PostProcessingService@@SAXPEAVClassInfo@efd@@_K@Z 0x1416b2650 ; unique
// MS2-PIN: ?TypeCast@PostProcessingService@@UEBA_NIPEAPEAX@Z 0x1416b26d0 ; unique
// MS2-PIN: ?TypeCast@PostProcessingService@@UEBA_NIPEAPEBX@Z 0x1416b2720 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x1416b3920 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@2@XZ 0x1416b3990 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$SmartPointer@VPostProcessEffect@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x1416b3a50 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VPostProcessingService@@VEntityChangeMessage@egf@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x1416b0fd0 ; hand: byte-identical look-alikes
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VPostProcessingService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x1416b1410 ; hand: exe vftable 0x142f52268
// MS2-PIN: ?HandleMessage@?$MessageHandlerImpl@VPostProcessingService@@VSceneGraphRemovedMessage@ecr@@@efd@@UEAAXPEAVIBase@2@PEBVIMessage@2@VCategory@2@@Z 0x1416b1850 ; hand: exe vftable 0x142f52288
// MS2-PIN: ??_GSceneGraphRemovedMessage@ecr@@UEAAPEAXI@Z 0x1416b0390 ; hand: exe vftable 0x142f51ff0
// MS2-PIN: ?GetNumObjectsDrawn@OutlineRenderClick@@UEBAIXZ 0x1416b0df0 ; hand: exe vftable 0x142f52348
// MS2-PIN: ??_GOutlineRenderClick@@UEAAPEAXI@Z 0x1416b02d0 ; hand: exe vftable 0x142f52348
// MS2-PIN: ??1OutlineRenderClick@@UEAA@XZ 0x1416af150 ; hand: ??_G 0x1416b02d0 call site
// MS2-PIN: ?AppendRenderView@NiViewRenderClick@@QEAAXPEAVNiRenderView@@@Z 0x1416b06b0 ; hand: this TU's inline copy
// MS2-PIN: ?IncRefCount@PostProcessingService@@UEBAXXZ 0x1416b1c90 ; hand: byte-identical look-alikes
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1416ac600 ; hand: _Insert_nohint 0x1416ad390 call site
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1416ac6f0 ; hand: _Tree_comp_alloc ctor 0x1416ae5d0 call site
// MS2-PIN: ??$?0HV?$SmartPointer@VPostProcessEffect@@@efd@@$0A@@?$pair@$$CBHV?$SmartPointer@VPostProcessEffect@@@efd@@@std@@QEAA@$$QEAU?$pair@HV?$SmartPointer@VPostProcessEffect@@@efd@@@1@@Z 0x1416ac790 ; hand: _Construct1 0x1416ace00 call site
// MS2-PIN: ??1SceneGraphRemovedMessage@ecr@@UEAA@XZ 0x1416af170 ; hand: ??_G 0x1416b0390 call site
// MS2-PIN: ?ErrorMessage@_com_error@@QEBAPEBDXZ 0x1416b0810 ; hand: this TU's copy (FUN_1416a69a0 call site)
// MS2-PIN: ??$format_arg@_WW4Unk_PPTexture@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_PPTexture@@@Z 0x1416ada90 ; hand: FormatCustomArg 0x1416adbb0 call site
// MS2-PIN: ??4Unk_ShaderColor@@QEAAAEAV0@$$QEAV0@@Z 0x14169f1d0
// MS2-PIN: ??4Unk_ShaderColor@@QEAAAEAV0@AEBV0@@Z 0x14169f200
// MS2-PIN: ??4Unk_ShaderVec4@@QEAAAEAV0@AEBV0@@Z 0x14169f230
// MS2-PIN: ??0?$SmartPointer@VNiRenderClick@@@efd@@QEAA@AEBV01@@Z 0x14169f660
// MS2-PIN: ?RemoveHead@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@XZ 0x14169f990
// MS2-PIN: ?RemovePos@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@AEAPEAX@Z 0x14169fa70
// MS2-PIN: ?RemoveTail@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@XZ 0x14169fc50
// MS2-PIN: ??1OverdrawRenderStep@@UEAA@XZ 0x1416a27f0
// MS2-PIN: ??_7PostProcessingService@@6B?$TSingleton@VPostProcessingService@@@@@ 0x142f52100
// MS2-PIN: ??_7PostProcessingService@@6BISystemService@efd@@@ 0x142f52110
// MS2-PIN: ??__ENiD3DXEffectShaderSDMObject@@YAXXZ 0x1400fc840 ; hand: NiD3DXEffectShaderLib.h static, between the sort names and "skill"
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x1400fc8f0 ; hand: dynamic init of s_pointer
// MS2-PIN: ?FUN_1416b0de0@CPlaneReflectionSetting@@QEAAAEAVPoint3@efd@@XZ 0x1416b0de0 ; hand: tplpin proposal
// MS2-PIN: ?FUN_1416b0e20@CPlaneReflectionSetting@@QEAAAEAVPoint3@efd@@XZ 0x1416b0e20 ; hand: tplpin proposal
#ifdef __clang__
// The exe passes the address of a temporary NiFixedString (an MSVC extension) to the SSAO step ctor.
#pragma clang diagnostic ignored "-Waddress-of-temporary"
#endif
// MS2-FUNCTIONAL ?ErrorMessage@_com_error@@QEBAPEBDXZ: comdef.h inline (via the PCH); the exe copy (0x1416b0810) calls
//   strlen out of line (0x14280f01e) where our /Oi build inlines it, and #pragma function(strlen) after the PCH can't reach it
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\postprocessingservice.cpp"
#ifndef NOMINMAX
#define NOMINMAX                                                            // PhysX (via entityworldmanager.h)
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "postprocessingservice.h"
#include <NiClickRenderStep.h>
#include <NiPoint2.h>
#include <NiRenderClick.h>
#include <NiRenderedTexture.h>
#include <NiRenderTargetGroup.h>
#include <NiShaderFactory.h>
#include <NiShaderLibrary.h>
#include <NiDepthStencilBuffer.h>
#include <NiMaterialLibrary.h>
#include <NiViewRenderClick.h>
#include <NiScreenFillingRenderView.h>
#include <NiTexturingProperty.h>
#include <NiRenderObject.h>
#include <NiSingleShaderMaterial.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/client/ms2/mirrored3drenderview.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#include "ms2/client/ms2/ms2overdrawprocessor.h"
#include "ms2/client/ms2/ms2materialswapprocessor.h"
#include "ms2/client/ms2/postprocessing/postprocesssetting.h"
#include "ms2/client/ms2/planereflectionsetting.h"
#include "ms2/client/ms2/ms2texturedensityprocessor.h"
#include "ms2/client/ms2/depthoffieldmanager.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include <NiTextureEffect.h>
#include <NiRenderListProcessor.h>
#include <NiDefaultClickRenderStep.h>
#include <NiDX9Renderer.h>
#include <NiDX92DBufferData.h>
#include <NiDX9PixelFormat.h>
#include <NiRenderFrame.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <ecrInput/InputService.h>
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include <comdef.h>
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include <egf/EntityManager.h>
#include <d3dx9.h>
#include <egf/IBuiltinModel.h>
#include <efd/MessageService.h>
#include "ssaorenderstep.h"
#include "outlinerenderstep.h"
#include "postshimmerrenderstep.h"
#include "radialblurrenderstep.h"
#include "screenmaskingrenderstep.h"
#include "worldfadeoutrenderstep.h"
#include <egf/EntityChangeMessage.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <egf/FlatModelManager.h>
#include "ms2/placeholder/ms2renderprocessors.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern NiFixedString DAT_143ae53e0;                         // "gakNormalSampleOffsets" (global shader constant name)
void FUN_1411781e0(const NiFixedString& kName, const NiPoint2* pkValues, int nCount);   // set a global shader constant array
extern NiFixedString DAT_143ae53e8;                         // "gakSampleOffsets"
extern NiFixedString DAT_143ae53f0;                         // "gakSampleWeights"

// The 16-byte shader constant (four floats), as in uiupperhuddialog.cpp / meshuvpicker.h.
class Unk_ShaderVec4
{
public:
    Unk_ShaderVec4();                                       // 0x141480230
    void Assign(float a, float b, float c, float d);        // 0x14135e000
    Unk_ShaderVec4& operator=(const Unk_ShaderVec4& rhs)    // 0x14169f230 (user-declared, so the derived copy/move both call it)
    {
        m_af[0] = rhs.m_af[0];
        m_af[1] = rhs.m_af[1];
        m_af[2] = rhs.m_af[2];
        m_af[3] = rhs.m_af[3];
        return *this;
    }
private:
    float m_af[4];
};
MS2_CHECK_SIZE(Unk_ShaderVec4, 0x10);

class Unk_ShaderColor : public Unk_ShaderVec4
{
public:
    Unk_ShaderColor() {}                                    // 0x141480210
    Unk_ShaderColor(float a, float b, float c, float d);    // 0x14135dc80
    void SetZero() { Assign(0.0f, 0.0f, 0.0f, 0.0f); }
};
MS2_CHECK_SIZE(Unk_ShaderColor, 0x10);

void FUN_14135db70(const NiFixedString& kName, const Unk_ShaderColor* pkValues, int nCount);   // set a global shader constant array
unsigned long GetTickCountMs2();
void FUN_1409a5770(const NiFixedString& kName, const float* pfValues, int nCount);   // set a global float shader constant
extern "C" float (__cdecl* __imp_sqrtf)(float);
extern "C" float (__cdecl* __imp_expf)(float);

bool FUN_14169ea50(NiRenderClick* pkClick, void* pvData);
bool FUN_14169eb00(NiRenderClick* pkClick, void* pvData);
bool FUN_14169ec70(NiRenderClick* pkClick, void* pvData);
void FUN_14169ede0(const NiPoint2* akOffsets, const Unk_ShaderColor* akWeights);
void FUN_14169ee30(unsigned int uiWidth, unsigned int uiHeight, NiPoint2* akOffsets);
float FUN_14169ef20(float x, float y, float fRho);
void FUN_14169efd0(unsigned int uiTexSize, float* afTexCoordOffset, Unk_ShaderColor* akColorWeight, float fDeviation,
    float fMultiplier);

// ---- AntiAliasRenderStep

// @0x1400fc2a0
const NiRTTI AntiAliasRenderStep::ms_RTTI("AntiAliasRenderStep", &NiRenderStep::ms_RTTI);

// @0x14169d920
AntiAliasRenderStep::AntiAliasRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("AntiAliasRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169d9a0
AntiAliasRenderStep::~AntiAliasRenderStep()
{
}

// @0x14169d9d0
bool AntiAliasRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "SmoothEdge", FUN_14169dbb0, m_80->GetBuffer(), m_80, 0, 0, 0, "MRT_SmoothEdge",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169d9d0, AntiAliasRenderStep, vfunc_15, 462, 0x3EB2DD5D);

// @0x14169dbb0
bool AntiAliasRenderStep::FUN_14169dbb0(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[8];
    float fX = 1.0f / (float)pkBuffer->GetWidth();
    float fY = 1.0f / (float)pkBuffer->GetHeight();
    akOffsets[0] = NiPoint2(-fX, fY);
    akOffsets[1] = NiPoint2(fX, -fY);
    akOffsets[2] = NiPoint2(-fX, -fY);
    akOffsets[3] = NiPoint2(fX, fY);
    akOffsets[4] = NiPoint2(-fX, 0.0f);
    akOffsets[5] = NiPoint2(fX, 0.0f);
    akOffsets[6] = NiPoint2(0.0f, -fY);
    akOffsets[7] = NiPoint2(0.0f, fY);
    FUN_1411781e0(DAT_143ae53e0, akOffsets, 8);
    return true;
}

// @0x14169de50
const NiRTTI* AntiAliasRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x14169de70
bool AntiAliasRenderStep::vfunc_14() { return false; }

// @0x14169de80
bool AntiAliasRenderStep::vfunc_13() { return true; }

// ---- BloomRenderStep (the DirectX SDK HDRLighting bloom passes)

// @0x1400fc2d0
const NiRTTI BloomRenderStep::ms_RTTI("BloomRenderStep", &PostProcessEffect::ms_RTTI);

// @0x14169de90
BloomRenderStep::BloomRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a8(0), m_b0(0)
{
    NiFixedString name("BloomRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169df70
BloomRenderStep::~BloomRenderStep()
{
}

// @0x14169e000
// MS2-FUNCTIONAL: argument temporaries of the five render-click calls are spilled in a different order; behaviour equivalent
bool BloomRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    m_a0 = GetTickCountMs2();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_a8 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_a8)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_b0 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b0)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    for (int i = 0; i < 2; i++)
    {
        m_b8[i] = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
        if (!m_b8[i])
        {
            vfunc_16();
            return false;
        }
    }
    efd::SmartPointer<NiRenderedTexture>* pkTargets = static_cast<efd::SmartPointer<NiRenderedTexture>*>(b);
    if (FUN_140c8f690(FUN_1416b4990(this, "Scene_To_Scene_Scaled", FUN_14169ea50, m_80->GetBuffer(), m_80, 0, 0, m_a8,
        "HDRRenderStep_DownScale4x4", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "SceneScaled_To_BrightPass", 0, 0, m_a8, 0, 0, m_b0,
        "HDRRenderStep_BrightPassFilter", pkTargets[8], 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Bloom1", FUN_14169eb00, m_b0->GetBuffer(), m_b0, 0, 0, m_b8[1],
        "HDRRenderStep_Bloom", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Bloom0", FUN_14169ec70, m_b0->GetBuffer(), m_b8[1], 0, 0, m_b8[0],
        "HDRRenderStep_Bloom", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "FinalScenePass", 0, 0, m_80, 1, 0, 0,
        "HDRRenderStep_FinalScenePass", m_b8[0], 0, pkTargets[6])) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169e000, BloomRenderStep, vfunc_15, 2474, 0x98BA3515);

// @0x14169e9b0
void BloomRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a8 = 0;
    m_b0 = 0;
    for (int i = 0; i < 2; i++)
        m_b8[i] = 0;
}
MS2_REPLACE_METHOD(0x14169e9b0, BloomRenderStep, vfunc_16, 123, 0x7EDDE2F9);

// @0x14169ea40
void BloomRenderStep::vfunc_21()
{
}

// @0x14169ea50
bool FUN_14169ea50(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    FUN_14169ee30(pkBuffer->GetWidth(), pkBuffer->GetHeight(), akOffsets);
    FUN_14169ede0(akOffsets, 0);
    return true;
}

// @0x14169eb00
bool FUN_14169eb00(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    Unk_ShaderColor akWeights[16];
    float afOffsets[16] = {};
    for (int i = 0; i < 16; i++)
        akWeights[i].SetZero();
    FUN_14169efd0(pkBuffer->GetWidth(), afOffsets, akWeights, 3.0f, 2.0f);
    for (int i = 0; i < 16; i++)
        akOffsets[i] = NiPoint2(afOffsets[i], 0.0f);
    FUN_14169ede0(akOffsets, akWeights);
    return true;
}

// @0x14169ec70
bool FUN_14169ec70(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    Unk_ShaderColor akWeights[16];
    float afOffsets[16] = {};
    for (int i = 0; i < 16; i++)
        akWeights[i].SetZero();
    FUN_14169efd0(pkBuffer->GetWidth(), afOffsets, akWeights, 3.0f, 2.0f);
    for (int i = 0; i < 16; i++)
        akOffsets[i] = NiPoint2(0.0f, afOffsets[i]);
    FUN_14169ede0(akOffsets, akWeights);
    return true;
}

// @0x14169ede0
void FUN_14169ede0(const NiPoint2* akOffsets, const Unk_ShaderColor* akWeights)
{
    FUN_1411781e0(DAT_143ae53e8, akOffsets, 16);
    if (akWeights != 0)
        FUN_14135db70(DAT_143ae53f0, akWeights, 16);
}

// @0x14169ee30
void FUN_14169ee30(unsigned int uiWidth, unsigned int uiHeight, NiPoint2* akOffsets)   // GetSampleOffsets_DownScale4x4
{
    float tU = 1.0f / (float)uiWidth;
    float tV = 1.0f / (float)uiHeight;
    int iIndex = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            akOffsets[iIndex].x = ((float)x - 1.5f) * tU;
            akOffsets[iIndex].y = ((float)y - 1.5f) * tV;
            iIndex++;
        }
    }
}

// @0x14169ef20
float FUN_14169ef20(float x, float y, float fRho)   // GaussianDistribution
{
    float g = 1.0f / __imp_sqrtf(2.0f * 3.14159265f * fRho * fRho);
    g *= __imp_expf(-(x * x + y * y) / (2.0f * fRho * fRho));
    return g;
}

// @0x14169efd0
// MS2-FUNCTIONAL: our build adds a /GS cookie for the Unk_ShaderColor temporaries (the exe has none); behaviour equivalent
void FUN_14169efd0(unsigned int uiTexSize, float* afTexCoordOffset, Unk_ShaderColor* akColorWeight, float fDeviation,
    float fMultiplier)   // GetSampleOffsets_Bloom
{
    float tu = 1.0f / (float)uiTexSize;
    float fWeight = fMultiplier * FUN_14169ef20(0.0f, 0.0f, fDeviation);
    akColorWeight[0] = Unk_ShaderColor(fWeight, fWeight, fWeight, 1.0f);
    afTexCoordOffset[0] = 0.0f;
    for (int i = 1; i < 8; i++)
    {
        fWeight = fMultiplier * FUN_14169ef20((float)i, 0.0f, fDeviation);
        afTexCoordOffset[i] = (float)i * tu;
        akColorWeight[i] = Unk_ShaderColor(fWeight, fWeight, fWeight, 1.0f);
    }
    for (int i = 8; i < 15; i++)
    {
        akColorWeight[i] = akColorWeight[i - 7];
        afTexCoordOffset[i] = -afTexCoordOffset[i - 7];
    }
}

// @0x14169f340
const NiRTTI* BloomRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x14169f350
bool BloomRenderStep::vfunc_14() { return false; }

// @0x14169f360
bool BloomRenderStep::vfunc_13() { return false; }

// ---- ColorPerspectiveRenderStep

// @0x1400fc300
const NiRTTI ColorPerspectiveRenderStep::ms_RTTI("ColorPerspectiveRenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x14169f3a0
ColorPerspectiveRenderStep::ColorPerspectiveRenderStep(unsigned __int64 a, unsigned int b)
    : ReloadablePostProcess(a, "ColorPerspective", 1, b), m_b8(0)
{
    NiFixedString name("ColorPerspectiveRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169f460
bool ColorPerspectiveRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    m_b8 = static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1];
    if (!vfunc_23())
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169f460, ColorPerspectiveRenderStep, vfunc_15, 142, 0x1D07049C);

// @0x14169f500
// MS2-FUNCTIONAL: one extra 8-byte stack slot in our frame shifts the spill offsets; behaviour equivalent
bool ColorPerspectiveRenderStep::vfunc_23()
{
    NiRenderClick* pkClick = GetRenderClickByName("ColorPerspectiveRenderClick");
    if (pkClick != 0)
        RemoveRenderClick(pkClick);
    return FUN_140c8f690(FUN_1416b4990(this, "ColorPerspectiveRenderClick", 0, 0, m_80, 0, 3, 0, "ColorPerspective", m_b8, 0, 0)) != 0;
}
MS2_REPLACE_METHOD(0x14169f500, ColorPerspectiveRenderStep, vfunc_23, 341, 0x047DD5E6);

// @0x14169f6a0 (implicit destructor: no vptr store, unlike the user-declared ones)

// @0x14169f850
const NiRTTI* ColorPerspectiveRenderStep::GetRTTI() const { return &ms_RTTI; }

// ---- DepthOfFieldRenderStep

// @0x1400fc330
const NiRTTI DepthOfFieldRenderStep::ms_RTTI("DepthOfFieldRenderStep", &NiRenderStep::ms_RTTI);

// @0x14169fd30
DepthOfFieldRenderStep::DepthOfFieldRenderStep(unsigned __int64 a, unsigned int b)
    : PostProcessEffect(a, b), m_a0(0), m_a8(0), m_b0(0), m_b8(0)
{
    NiFixedString name("DepthOfFieldRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169fe10
DepthOfFieldRenderStep::~DepthOfFieldRenderStep()
{
}

// @0x14169fe90
// MS2-FUNCTIONAL: argument temporaries of the seven render-click calls are spilled in a different order; behaviour equivalent
bool DepthOfFieldRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_a0 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a0)
    {
        vfunc_16();
        return false;
    }
    m_a8 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a8)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_b0 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b0)
    {
        vfunc_16();
        return false;
    }
    m_b8 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b8)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DownSample", 0, 0, m_80, 0, 0, m_b0, "Dof_DownSample", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_HorzBlur", 0, 0, m_b0, 0, 0, m_b8, "Dof_HorzBlur", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_VertBlur", 0, 0, m_b8, 0, 0, m_b0, "Dof_VertBlur", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurMask", 0, 0, m_b0, 0, 0, m_a0, "Dof_DepthBlurMask",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurHorzFore", 0, 0, m_a0, 0, 0, m_a8, "Dof_DepthBlurHorzFore", m_a0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurVertFore", 0, 0, m_a8, 0, 0, m_a0, "Dof_DepthBlurVertFore", m_a8, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthOfField", 0, 0, m_b0, 1, 0, 0, "Dof_DepthOfField", m_80, m_a0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169fe90, DepthOfFieldRenderStep, vfunc_15, 2710, 0x510CFB83);

// @0x1416a0930
void DepthOfFieldRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b8 = 0;
}
MS2_REPLACE_METHOD(0x1416a0930, DepthOfFieldRenderStep, vfunc_16, 108, 0x0051C425);

// @0x1416a0a00
const NiRTTI* DepthOfFieldRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a0a10
bool DepthOfFieldRenderStep::vfunc_14() { return false; }

// @0x1416a0a20
bool DepthOfFieldRenderStep::vfunc_13() { return false; }

// ---- FadeInOutRenderStep

extern int DAT_1439f823c;           // default fade-out time (ms)
extern int DAT_1439f8240;           // default fade-in time (ms)
extern float DAT_1439f8248;         // fade constant scale
extern NiFixedString DAT_143ae5320; // the fade shader constant name

// @0x1400fc380
const NiRTTI FadeInOutRenderStep::ms_RTTI("FadeInOutRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
float FadeInOutRenderStep::ms_fAlpha;
unsigned int FadeInOutRenderStep::ms_uiStartTime;
int FadeInOutRenderStep::ms_iState;
// @0x1400fc370
int FadeInOutRenderStep::ms_iFadeOutTime = DAT_1439f823c;
// @0x1400fc360
int FadeInOutRenderStep::ms_iFadeInTime = DAT_1439f8240;

// @0x1416a0a30
FadeInOutRenderStep::FadeInOutRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("FadeInOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a0ab0
FadeInOutRenderStep::~FadeInOutRenderStep()
{
    NiFixedString name("FadeInOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a0b20
bool FadeInOutRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    ms_iState = 0;
    ms_uiStartTime = GetTickCountMs2();
    NiRenderClick* pkClick = static_cast<NiRenderClick*>(FUN_140c8f690(FUN_1416b4990(this, "FadeInOut", FUN_1416a0cd0, this, m_80,
        0, 0, 0, "FadeInOut", static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2],
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    pkClick->SetClearAllBuffers(true);
    return true;
}

// @0x1416a0cd0
// MS2-FUNCTIONAL: the exe spills the elapsed time and converts the duration first (16 bytes more frame); behaviour equivalent
bool FadeInOutRenderStep::FUN_1416a0cd0(NiRenderClick* pkClick, void* pvData)
{
    if (ms_iState == 2)
        return true;
    int iDuration = (ms_iState == 1) ? ms_iFadeOutTime : ms_iFadeInTime;
    if (iDuration != 0)
        ms_fAlpha = ((float)GetTickCountMs2() - (float)ms_uiStartTime) / (float)iDuration;
    else
        ms_fAlpha = 1.0f;
    if (ms_iState == 1)
    {
        ms_fAlpha = 1.0f - ms_fAlpha;
        if (ms_fAlpha <= 0.0f)
        {
            ms_fAlpha = 0.0f;
            ms_iFadeOutTime = DAT_1439f823c;
            ms_iState = 2;
        }
    }
    else if (ms_fAlpha >= 1.0f)
    {
        FadeInOutRenderStep* pkStep = static_cast<FadeInOutRenderStep*>(pvData);
        reinterpret_cast<Unk_PPOwner*>(pkStep->m_70)->FUN_1416a0fb0(13);
        ms_fAlpha = 1.0f;
        ms_iFadeInTime = DAT_1439f8240;
        ms_iState = 0;
    }
    ms_fAlpha = ms_fAlpha * (ms_fAlpha * DAT_1439f8248);
    FUN_1409a5770(DAT_143ae5320, &ms_fAlpha, 1);
    return true;
}

// Empty; the message boxes call it right before PostQuitMessage (uimessagebox.cpp). Too short to hook.
// @0x1416a0e70
void FUN_1416a0e70()
{
}

// @0x1416a0fb0
void PostProcessingService::FUN_1416a0fb0(int nEvent)
{
    m_kEvents.AddTail(nEvent);
}

// @0x1416a0fe0
const NiRTTI* FadeInOutRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a0ff0
bool FadeInOutRenderStep::vfunc_14() { return false; }

// @0x1416a1000
bool FadeInOutRenderStep::vfunc_13() { return false; }

// ---- FadeInRenderStep

// @0x1400fc3b0
const NiRTTI FadeInRenderStep::ms_RTTI("FadeInRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
float FadeInRenderStep::ms_fAlpha;
unsigned int FadeInRenderStep::ms_uiStartTime;

// @0x1416a1010
FadeInRenderStep::FadeInRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("FadeInRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1090
FadeInRenderStep::~FadeInRenderStep()
{
}

// @0x1416a10c0
bool FadeInRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    ms_uiStartTime = GetTickCountMs2();
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "FadeIn", FUN_1416a1260, this, m_80, 0, 0, 0, "FadeInOut",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}

// @0x1416a1260
bool FadeInRenderStep::FUN_1416a1260(NiRenderClick* pkClick, void* pvData)
{
    ms_fAlpha = ((float)GetTickCount() - (float)ms_uiStartTime) / (float)DAT_1439f8240;
    if (ms_fAlpha >= 1.0f)
    {
        FadeInRenderStep* pkStep = static_cast<FadeInRenderStep*>(pvData);
        reinterpret_cast<Unk_PPOwner*>(pkStep->m_70)->FUN_1416a0fb0(14);
        ms_fAlpha = 1.0f;
    }
    ms_fAlpha = ms_fAlpha * ms_fAlpha;
    FUN_1409a5770(DAT_143ae5320, &ms_fAlpha, 1);
    return true;
}

// @0x1416a1380
const NiRTTI* FadeInRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1390
bool FadeInRenderStep::vfunc_14() { return false; }

// @0x1416a13a0
bool FadeInRenderStep::vfunc_13() { return false; }

// ---- GaussianBlurRenderStep

extern NiFixedString DAT_143ae5460;     // outer blur shader constants, reset by vfunc_22
extern NiFixedString DAT_143ae5468;

// @0x1400fc3e0
const NiRTTI GaussianBlurRenderStep::ms_RTTI("GaussianBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a13b0
GaussianBlurRenderStep::GaussianBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a0(0)
{
    NiFixedString name("GaussianBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1450
GaussianBlurRenderStep::~GaussianBlurRenderStep()
{
}

// @0x1416a1490
// MS2-FUNCTIONAL: argument temporaries of the two render-click calls are spilled in a different order; behaviour equivalent
bool GaussianBlurRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_a0 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_H", 0, 0, m_80, 0, 0, m_a0, "OuterGaussianBlur_H",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_V", 0, 0, m_a0, 0, 0, 0, "OuterGaussianBlur_V",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1490, GaussianBlurRenderStep, vfunc_15, 973, 0xA5640F8D);

// @0x1416a1870
void GaussianBlurRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a0 = 0;
}
MS2_REPLACE_METHOD(0x1416a1870, GaussianBlurRenderStep, vfunc_16, 45, 0x99C977BC);

// @0x1416a18b0
void GaussianBlurRenderStep::vfunc_22()
{
    float fZero = 0.0f;
    FUN_1409a5770(DAT_143ae5460, &fZero, 1);
    FUN_1409a5770(DAT_143ae5468, &fZero, 1);
}
MS2_REPLACE_METHOD(0x1416a18b0, GaussianBlurRenderStep, vfunc_22, 69, 0x94FA78C6);

// @0x1416a1960
const NiRTTI* GaussianBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1970
bool GaussianBlurRenderStep::vfunc_14() { return false; }

// @0x1416a1980
bool GaussianBlurRenderStep::vfunc_13() { return false; }

// ---- HeatShimmerRenderStep

// @0x1400fc410
const NiRTTI HeatShimmerRenderStep::ms_RTTI("HeatShimmerRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a1990
HeatShimmerRenderStep::HeatShimmerRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("HeatShimmerRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1a10
HeatShimmerRenderStep::~HeatShimmerRenderStep()
{
}

// @0x1416a1a40
bool HeatShimmerRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "HeatShimmer", 0, this, m_80, 0, 0, 0, "HeatShimmer",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1a40, HeatShimmerRenderStep, vfunc_15, 382, 0xF8E30FF5);

// @0x1416a1c20
const NiRTTI* HeatShimmerRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1c30
bool HeatShimmerRenderStep::vfunc_14() { return false; }

// @0x1416a1c40
bool HeatShimmerRenderStep::vfunc_13() { return false; }

// ---- MonochromeRenderStep

// @0x1400fc440
const NiRTTI MonochromeRenderStep::ms_RTTI("MonochromeRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a1c50
MonochromeRenderStep::MonochromeRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("MonochromeRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1cd0
MonochromeRenderStep::~MonochromeRenderStep()
{
    PostProcessEffect::vfunc_16();
}

// @0x1416a1d20
bool MonochromeRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "Monochrome", 0, 0, m_80, 0, 0, 0, "Monochrome",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1d20, MonochromeRenderStep, vfunc_15, 378, 0xC021FB8F);

// @0x1416a1f00
const NiRTTI* MonochromeRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1f10
bool MonochromeRenderStep::vfunc_14() { return false; }

// @0x1416a1f20
bool MonochromeRenderStep::vfunc_13() { return false; }

// ---- OuterBlurRenderStep

// @0x1400fc4a0
const NiRTTI OuterBlurRenderStep::ms_RTTI("OuterBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a2440
OuterBlurRenderStep::OuterBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("OuterBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a24c0
OuterBlurRenderStep::~OuterBlurRenderStep()
{
    PostProcessEffect::vfunc_16();
}

// @0x1416a2560
const NiRTTI* OuterBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2570
bool OuterBlurRenderStep::vfunc_14() { return false; }

// @0x1416a2580
bool OuterBlurRenderStep::vfunc_13() { return false; }

// ---- OverdrawRenderStep

// @0x1400fc4d0
const NiRTTI OverdrawRenderStep::ms_RTTI("OverdrawRenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x1416a2590
OverdrawRenderStep::OverdrawRenderStep(unsigned __int64 a, unsigned int b) : ReloadablePostProcess(a, "OverdrawColorize", 0, b)
{
    NiFixedString name("OverdrawRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a2640
bool OverdrawRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, b))
        return false;
    vfunc_23();
    return true;
}
MS2_REPLACE_METHOD(0x1416a2640, OverdrawRenderStep, vfunc_15, 74, 0x483F2540);

// @0x1416a2690
// MS2-FUNCTIONAL: one extra 8-byte stack slot in our frame shifts the spill offsets; behaviour equivalent
bool OverdrawRenderStep::vfunc_23()
{
    NiRenderClick* pkClick = GetRenderClickByName("Overdraw");
    if (pkClick != 0)
        RemoveRenderClick(pkClick);
    return FUN_140c8f690(FUN_1416b4990(this, "Overdraw", 0, 0, m_80, 0, 3, 0, "OverdrawColorize",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(m_98)[9], 0, 0)) != 0;
}
MS2_REPLACE_METHOD(0x1416a2690, OverdrawRenderStep, vfunc_23, 351, 0xA9CC357A);

// @0x1416a2870
const NiRTTI* OverdrawRenderStep::GetRTTI() const { return &ms_RTTI; }

// ---- PostProcessEffect / ReloadablePostProcess

void FUN_1427b7820(NiShaderLibrary* pkLibrary, void** ppvOut, const char* pcName);   // NiD3DXEffect library: load the named effect

// @0x1400fc500
const NiRTTI PostProcessEffect::ms_RTTI("PostProcessEffect", &NiDefaultClickRenderStep::ms_RTTI);
// @0x1400fc530
const NiRTTI ReloadablePostProcess::ms_RTTI("ReloadablePostProcess", &PostProcessEffect::ms_RTTI);

// @0x1416a2880
PostProcessEffect::PostProcessEffect(unsigned __int64 a, unsigned int b) : m_70(a), m_80(0), m_88(0)
{
    m_90 = 0;
}

// @0x1416a2910
PostProcessEffect::~PostProcessEffect()
{
    m_80 = 0;
}

// @0x1416a2990
// MS2-FUNCTIONAL: locals sit one slot higher and m_90 (unsigned char in the shared header, bool in the exe) is returned via a compare
bool PostProcessEffect::vfunc_15(unsigned int a, void* b)
{
    RemoveAllRenderClicks();
    m_98 = b;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (pkRenderer != 0)
    {
        NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
        if (pkRTG != 0)
        {
            unsigned int uiWidth = pkRTG->GetWidth(0);
            unsigned int uiHeight = pkRTG->GetHeight(0);
            unsigned short usMSAA = pkRTG->GetBuffer(0)->GetMSAAPref();
            NiTexture::FormatPrefs kPrefs;
            kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
            if (m_80 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, usMSAA))
                m_88 = NiRenderTargetGroup::Create(m_80->GetBuffer(), pkRenderer, true, true);
        }
    }
    m_90 = m_80 != 0;
    return m_90;
}
MS2_REPLACE_METHOD(0x1416a2990, PostProcessEffect, vfunc_15, 432, 0x140FA897);

// @0x1416a2b50
void PostProcessEffect::vfunc_16()
{
    m_98 = 0;
    m_80 = 0;
    m_88 = 0;
    m_90 = 0;
}
MS2_REPLACE_METHOD(0x1416a2b50, PostProcessEffect, vfunc_16, 84, 0x7F856485);

// @0x1416a2bb0
ReloadablePostProcess::ReloadablePostProcess(unsigned __int64 a, const NiFixedString& name, unsigned char flag, unsigned int b)
    : PostProcessEffect(a, b)
{
    m_b0 = 0;
    m_a8 = flag;
    m_a0 = name;
}

// @0x1416a2c60
// MS2-FUNCTIONAL: the exe keeps the factory/library in different stack slots (frame 0x48 vs 0x38); behaviour equivalent
void ReloadablePostProcess::vfunc_21()
{
    if (!m_a8)
        return;
    NiShaderFactory* pkFactory = NiShaderFactory::GetInstance();
    NiShaderLibrary* pkLibrary = pkFactory->GetFirstLibrary();
    while (true)
    {
        if (strcmp(pkLibrary->GetName(), "NiD3DXEffectShaderLib") == 0)
        {
            FUN_1427b7820(pkLibrary, &m_b0, m_a0);
            if (m_b0 != 0)
                pkLibrary->SetShaderLibraryDesc(static_cast<NiShaderLibraryDesc*>(m_b0));
            if (!vfunc_23())
                vfunc_16();
            return;
        }
        pkLibrary = pkFactory->GetNextLibrary();
    }
}
MS2_REPLACE_METHOD(0x1416a2c60, ReloadablePostProcess, vfunc_21, 288, 0xF934429C);

// @0x1416a2e90
const NiRTTI* PostProcessEffect::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2ea0
const NiRTTI* ReloadablePostProcess::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2eb0
bool PostProcessEffect::vfunc_14() { return false; }

// @0x1416a2ec0
bool PostProcessEffect::vfunc_13() { return false; }

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy).
// @0x1416a2ed0
#pragma function(memset, memcpy)
static __inline errno_t ms2_pps_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
#pragma intrinsic(memset, memcpy)
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnPpsMemcpyS)(void*, size_t, const void*, size_t) = &ms2_pps_memcpy_s;

// ---- MotionBlurRenderStep

// @0x1400fc470
const NiRTTI MotionBlurRenderStep::ms_RTTI("MotionBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
NiTexturingProperty* MotionBlurRenderStep::ms_pkTexProp;

// @0x1416a1f30
MotionBlurRenderStep::MotionBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("MotionBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1fb0
MotionBlurRenderStep::~MotionBlurRenderStep()
{
}

// @0x1416a1fe0
bool MotionBlurRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiViewRenderClick* pkClick = static_cast<NiViewRenderClick*>(FUN_140c8f690(FUN_1416b4990(this, "MotionBlur", FUN_1416a21c0, this,
        m_80, 0, 0, 0, "MotionBlur", static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2],
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    NiScreenFillingRenderView* pkView = NiDynamicCast(NiScreenFillingRenderView, pkClick->GetRenderViews().GetHead());
    ms_pkTexProp = static_cast<NiTexturingProperty*>(pkView->GetScreenFillingQuad().GetProperty(NiProperty::TEXTURING));
    return true;
}

// @0x1416a21c0
// MS2-FUNCTIONAL: our NiNew expansion keeps the MemHint differently (exe spills its address); behaviour equivalent
bool MotionBlurRenderStep::FUN_1416a21c0(NiRenderClick* pkClick, void* pvData)
{
    int iFrame = reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->m_iFrame;
    NiTexturingProperty::ShaderMap* pkMap0 = NiNew NiTexturingProperty::ShaderMap(
        reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->FUN_1416a23f0(iFrame + 3), 1);
    int iPrev = (reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->m_iFrame + 1) % 2;
    NiTexturingProperty::ShaderMap* pkMap1 = NiNew NiTexturingProperty::ShaderMap(
        reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->FUN_1416a23f0(iPrev + 3), 0);
    ms_pkTexProp->SetShaderMap(0, pkMap0);
    ms_pkTexProp->SetShaderMap(1, pkMap1);
    return true;
}

// @0x1416a23f0
NiRenderedTexture* PostProcessingService::FUN_1416a23f0(int nIndex)
{
    return m_aspTextures[nIndex];
}

// @0x1416a23e0
const NiRTTI* MotionBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2420
bool MotionBlurRenderStep::vfunc_14() { return false; }

// @0x1416a2430
bool MotionBlurRenderStep::vfunc_13() { return false; }

// ---- PostProcessingService ----

extern PostProcessingService* DAT_143ae4660;                // the service, set by the constructor
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);            // the entity's scene graph root
Ni3DRenderView* FUN_1413f9a70();                            // the main 3D view
void FUN_140d9dab0(NiDX9RenderState* pkState, bool bEnable);
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
NiViewRenderClick* FUN_1413f99a0();                         // the main scene click
void FUN_1411ab770(efd::IDependencyRegistrar* pRegistrar, int nFlags);     // AddDependency<ecr::RenderService> (0x07002001)
void FUN_1411ab740(efd::IDependencyRegistrar* pRegistrar, int nFlags);     // AddDependency<MS2 service 0x06100001>

// The graphics options block (FUN_1409a8b10()->FUN_1409a8ac0()); only the plane-reflection flag is known.
class Unk_PPGraphicsOptions
{
public:
    bool FUN_1416b0b20() { return m_bReflection; }
    bool FUN_1416b0b30() { return m_bOuterBlur; }
    bool FUN_1416b1d40() { return m_b1b; }
    char m_pad_0[0x1b];
    bool m_b1b;                 // +0x1b
    bool m_bOuterBlur;          // +0x1c
    char m_pad_1d[2];
    bool m_bReflection;         // +0x1f
};
MS2_CHECK_OFFSET(Unk_PPGraphicsOptions, m_bReflection, 0x1f);
class Unk_PPOptions
{
public:
    Unk_PPGraphicsOptions* FUN_1409a8ac0();
};
Unk_PPOptions* FUN_1409a8b10();
class Unk_PPSecondView;
class Unk_PPPostEffectMgr
{
public:
    void FUN_1409a5190(bool bEnable);
    Unk_PPSecondView* FUN_1409a5160();
    void FUN_1409a3b60(bool bBeforeReset);      // device reset notification
};
Unk_PPPostEffectMgr* FUN_1409a8b00();
class WorldService;
WorldService* FUN_1403ed2d0();
void FUN_141bbae40(WorldService* pWorld, IWorldServiceCallback* pCallback);
// The game clock (FUN_14086d260()).
class Unk_PPClock
{
public:
    float FUN_141473230();      // frame delta (s)
    double FUN_141473280();     // elapsed time (s)
};
Unk_PPClock* FUN_14086d260();
// The keyboard state (FUN_14025e7c0()).
class Unk_PPKeyboard
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);    // key down
    bool FUN_14116d9c0(int nKey, bool b, int n);    // key pressed this frame
};
Unk_PPKeyboard* FUN_14025e7c0();
// The post-effect manager's second scene view (FUN_1409a8b00()->FUN_1409a5160()).
class Unk_PPSecondView
{
public:
    NiViewRenderClick* FUN_141774010();
};
CLogString* FUN_140166440();                                                // the client log
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pwszText);
// The log with two format arguments.
// @0x1416ac870
template<class T, class U> inline void Unk_PPLog2(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pwszFormat,
    const T& kFirst, const U& kSecond)
{
    const fmt::internal::ArgArray<2>::Type akArgs = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(kFirst),
        fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(kSecond)};
    pLog->FUN_1406530d0(nLevel, nCategory, pwszFormat, fmt::ArgList(fmt::internal::make_type(kFirst, kSecond), akArgs));
}
PostProcessingService* FUN_1409a8b20();                                     // the post-processing service (other TU accessor)
void FUN_1409a5770(const NiFixedString& kName, const float* pfValues, int nCount);   // set a global shader constant
extern NiFixedString DAT_143ae53f8;                                         // the view-projection constant name
void FUN_1427e7520(Ni2DBuffer::RendererData* pkData);                       // NiDX92DBufferData: release the render-target references
extern const efd::Matrix3 DAT_143a09600;                                    // the texture effect's rotation
extern NiFixedString DAT_143ae52c0;                                         // post-process material names
extern NiFixedString DAT_143ae52c8;
extern NiFixedString DAT_143ae52d0;
extern NiFixedString DAT_143ae52d8;
extern NiFixedString DAT_143ae5268;
extern const efd::Category DAT_143ae4c20;                                   // the entity channel (defined below)
EntityWorldManager* FUN_1409670f0();                                        // the entity world manager (iterates the current map's entities)

// CEffectService (0x0610000c) has no recovered header; this carries its class id for AddDependency<>.
struct Unk_PPEffectServiceDep
{
    static const efd::ClassID CLASS_ID = 0x0610000c;
};

// ---- static initializers (.text$di, in this order) ----
// @0x1400fc560
static D3DXMATRIX DAT_143ae4be0;                                            // the last view-projection matrix
// @0x1400fc580
EE_IMPLEMENT_CONCRETE_CLASS_INFO(PostProcessingService);
#ifndef MS2_HOOK_DLL
// @0x1400fc5a0
EE_HANDLER(PostProcessingService, FUN_1416a4110, ecr::SceneGraphAddedMessage);
// @0x1400fc600
EE_HANDLER(PostProcessingService, FUN_1416a4240, ecr::SceneGraphRemovedMessage);
// @0x1400fc660
EE_HANDLER_WRAP(PostProcessingService, FUN_1416a43e0, egf::EntityChangeMessage, 8253);
// @0x1400fc6c0
EE_HANDLER_WRAP(PostProcessingService, FUN_1416a44d0, egf::EntityChangeMessage, 8254);
// @0x1400fc720
EE_HANDLER_WRAP(PostProcessingService, FUN_1416a4350, egf::EntityChangeMessage, 8196);
#endif
// The shared header statics (see ms2/placeholder/header_statics_a.h); the D3DX effect library's static data manager sits
// between the sort names and "skill".
// @0x1400fc780
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#include <NiD3DXEffectShaderLib.h>
// @0x1400fc860
static CString s_strSkill = "skill";
// @0x1400fc890
static CString s_strStun = "stun";
// @0x1400fc8c0
const efd::Category DAT_143ae4c20(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };     // ctor 0x1401cd100
static Unk_1401cd100 s_pointer(NULL);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

inline TSingleton<PostProcessingService>::TSingleton() { s_instance = static_cast<PostProcessingService*>(this); }

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1416a3020
PostProcessingService::PostProcessingService()
    : m_bMRT(false), m_bHDR(false), m_b1c2(false), m_b1c3(false), m_nFormat(2), m_b210(false)
{
    DAT_143ae4660 = this;
    for (int i = 0; i < 11; i++)
    {
        m_aspClicks[i] = 0;
        m_aspTextures[i] = 0;
        m_aiRefCount[i] = 0;
    }
}
#endif

// @0x1416a3380
PostProcessingService::~PostProcessingService()
{
}

// @0x1416a35a0
const char* PostProcessingService::GetDisplayName() const
{
    return "PostProcessingService";
}
MS2_REPLACE_METHOD_VIA(0x1416a35a0, PostProcessingService, efd::ISystemService, GetDisplayName, 13, 0x1E1596B4);

// @0x1416a35c0
bool PostProcessingService::FUN_1416a35c0(bool bEnable)
{
    if (m_b1c2 == bEnable)
        return true;
    m_b1c2 = bEnable;
    if (m_b1c2)
    {
        FUN_1416a7050();
    }
    else
    {
        m_aspTextures[1] = 0;
        m_aspTextures[2] = 0;
        m_aspTextures[6] = 0;
        m_aspTextures[3] = 0;
        m_aspTextures[4] = 0;
        m_aspTextures[5] = 0;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a35c0, PostProcessingService, FUN_1416a35c0, 287, 0x96F8C49B);

// @0x1416a36f0
bool PostProcessingService::FUN_1416a36f0(bool bEnable)
{
    if (m_b1c3 == bEnable)
        return true;
    m_b1c3 = bEnable;
    if (m_b1c3)
        m_nFormat = 0xd;
    else
        m_nFormat = 2;
    return true;
}
MS2_REPLACE_METHOD(0x1416a36f0, PostProcessingService, FUN_1416a36f0, 101, 0xA1B06AB9);

// @0x1416a3760
bool PostProcessingService::FUN_1416a3760()
{
    return m_b1c2;
}
MS2_REPLACE_METHOD(0x1416a3760, PostProcessingService, FUN_1416a3760, 18, 0x7E113906);

// @0x1416a3780
bool PostProcessingService::FUN_1416a3780()
{
    return m_b1c3;
}
MS2_REPLACE_METHOD(0x1416a3780, PostProcessingService, FUN_1416a3780, 18, 0x265E72CD);

// @0x1416a37a0
bool PostProcessingService::FUN_1416a37a0(int nStep, bool bRelink)
{
    bool bActive = false;
    efd::map<int, efd::SmartPointer<PostProcessEffect> >::iterator it = m_kSteps.find(nStep);
    if (it != m_kSteps.end())
    {
        bActive = !it->second->GetActive();
        it->second->SetActive(bActive);
        it->second->vfunc_19();
    }
    if (bRelink)
        FUN_1416aaef0();
    if (it != m_kSteps.end())
        it->second->vfunc_20();
    return bActive;
}
MS2_REPLACE_METHOD(0x1416a37a0, PostProcessingService, FUN_1416a37a0, 364, 0x9F16B5B6);

// @0x1416a3920
bool PostProcessingService::FUN_1416a3920(int nStep, bool bActive)
{
    efd::map<int, efd::SmartPointer<PostProcessEffect> >::iterator it = m_kSteps.find(nStep);
    if (it != m_kSteps.end())
    {
        bool bCurrent = it->second->GetActive();
        if (bCurrent != bActive)
        {
            it->second->vfunc_22();
            FUN_1416a37a0(nStep, true);
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1416a3920, PostProcessingService, FUN_1416a3920, 213, 0xF825659C);

// @0x1416a3a00
bool PostProcessingService::FUN_1416a3a00(int nStep)
{
    bool bActive = false;
    efd::map<int, efd::SmartPointer<PostProcessEffect> >::iterator it = m_kSteps.find(nStep);
    if (it != m_kSteps.end())
        bActive = it->second->GetActive();
    return bActive;
}
MS2_REPLACE_METHOD(0x1416a3a00, PostProcessingService, FUN_1416a3a00, 135, 0xF11ED346);

// @0x1416a3a90
PostProcessEffect* PostProcessingService::FUN_1416a3a90(int nStep)
{
    efd::map<int, efd::SmartPointer<PostProcessEffect> >::iterator it = m_kSteps.find(nStep);
    if (it != m_kSteps.end())
        return it->second;
    return 0;
}
MS2_REPLACE_METHOD(0x1416a3a90, PostProcessingService, FUN_1416a3a90, 117, 0xACC1F5BE);

// @0x1416a3b10
egf::IBuiltinModel* PostProcessingService::FUN_1416a3b10()
{
    DAT_143ae4660->m_spSetting = EE_NEW PostProcessSetting();
    return DAT_143ae4660->m_spSetting;
}

// @0x1416a3bb0
void PostProcessingService::FUN_1416a3bb0()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (pkRenderer != 0)
    {
        NiRenderTargetGroup* pkDefault = pkRenderer->GetDefaultRenderTargetGroup();
        if (pkDefault != 0)
        {
            const NiPixelFormat* pkFormat = pkDefault->GetPixelFormat(0);
            unsigned int uiWidth = pkDefault->GetWidth(0);
            unsigned int uiHeight = pkDefault->GetHeight(0);
            LPDIRECT3DSURFACE9 pkSurface = FUN_1416a3cd0(pkFormat, uiWidth, uiHeight);
            if (pkSurface != 0)
            {
                Ni2DBuffer* pkBuffer = 0;
                NiDX9Direct3DBufferData* pkData = NiDX9Direct3DBufferData::Create(pkSurface, pkBuffer);
                pkSurface->Release();
                m_spTarget190 = NiRenderTargetGroup::Create(pkBuffer, NiRenderer::GetRenderer(), true, false);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416a3bb0, PostProcessingService, FUN_1416a3bb0, 275, 0x9613AC8A);

// Creates an A8R8G8B8 render-target surface using the renderer's multisample mode (as CreateRenderTargetSurface).
// @0x1416a3cd0
LPDIRECT3DSURFACE9 PostProcessingService::FUN_1416a3cd0(const NiPixelFormat* pkFormat, unsigned int uiWidth,
    unsigned int uiHeight)
{
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != 0)
    {
        D3DFORMAT eFormat = D3DFMT_A8R8G8B8;
        unsigned int uiCreateWidth;
        unsigned int uiCreateHeight;
        unsigned int uiUseFlags;
        NiWindowRef kWndDevice;
        NiWindowRef kWndFocus;
        unsigned int uiAdapter;
        NiDX9Renderer::DeviceDesc eDesc;
        NiDX9Renderer::FrameBufferFormat eFBFormat;
        NiDX9Renderer::DepthStencilFormat eDSFormat;
        NiDX9Renderer::PresentationInterval ePresentationInterval;
        NiDX9Renderer::SwapEffect eSwapEffect;
        unsigned int uiFBMode;
        unsigned int uiBackBufferCount;
        unsigned int uiRefreshRate;
        pkRenderer->GetCreationParameters(uiCreateWidth, uiCreateHeight, uiUseFlags, kWndDevice, kWndFocus, uiAdapter,
            eDesc, eFBFormat, eDSFormat, ePresentationInterval, eSwapEffect, uiFBMode, uiBackBufferCount, uiRefreshRate);
        D3DMULTISAMPLE_TYPE eMultiSample = NiDX9Renderer::GetMultiSampleType(uiFBMode);
        DWORD uiQuality = NiDX9Renderer::GetMultiSampleQuality(uiFBMode);
        LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
        if (pkDevice != 0)
        {
            IDirect3DSurface9* pkSurface = 0;
            HRESULT hr = E_FAIL;
            hr = pkDevice->CreateRenderTarget(uiWidth, uiHeight, eFormat, eMultiSample, uiQuality, FALSE, &pkSurface, 0);
            return pkSurface;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a3cd0, PostProcessingService, FUN_1416a3cd0, 485, 0x74BF7095);

// The first active step.
// @0x1416a3ec0
PostProcessEffect* PostProcessingService::FUN_1416a3ec0()
{
    MS2_FOR_EACH(const auto& kStep, m_kSteps)
    {
        if ((bool)kStep.second && kStep.second->GetActive())
            return kStep.second;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a3ec0, PostProcessingService, FUN_1416a3ec0, 226, 0x8912E6B3);

// @0x1416a3fb0
efd::SmartPointer<NiRenderTargetGroup> PostProcessingService::FUN_1416a3fb0()
{
    return m_spTarget190;
}
MS2_REPLACE_METHOD(0x1416a3fb0, PostProcessingService, FUN_1416a3fb0, 67, 0x78A76B94);

// Re-point the shimmer click's mirrored view at the main view's camera.
// @0x1416a4000
bool PostProcessingService::FUN_1416a4000(NiRenderStep* pkStep, void* pvData)
{
    if (DAT_143ae4660 == 0 || (NiViewRenderClick*)DAT_143ae4660->m_aspClicks[7] == 0)
        return false;
    CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView,
        DAT_143ae4660->m_aspClicks[7]->GetRenderViews().GetHead());
    if (pkView == 0)
        return false;
    pkView->SetCamera(FUN_1413f9a70()->GetCamera());
    return true;
}

// @0x1416a40c0
bool PostProcessingService::FUN_1416a40c0(NiRenderStep* pkStep, void* pvData)
{
    NiDX9RenderState* pkState = NiDX9Renderer::GetRenderer()->GetRenderState();
    pkState->SetRenderState(D3DRS_CLIPPLANEENABLE, 0);
    FUN_140d9dab0(pkState, false);
    return true;
}

// @0x1416a4110
void PostProcessingService::FUN_1416a4110(const ecr::SceneGraphAddedMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    if (pEntity != 0 && m_b210 && m_aspClicks[7])
    {
        CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView, m_aspClicks[7]->GetRenderViews().GetHead());
        if (pkView == 0)
            return;
        NiAVObject* pkScene = FUN_141b6efc0(pEntity);
        if (pkScene != 0)
            pkView->AppendScene(pkScene);
    }
}

// @0x1416a4240
void PostProcessingService::FUN_1416a4240(const ecr::SceneGraphRemovedMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    if (pEntity == 0 || (NiViewRenderClick*)m_aspClicks[7] == 0)
        return;
    CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView, m_aspClicks[7]->GetRenderViews().GetHead());
    if (pkView != 0 && pkView->GetScenes().GetSize() != 0)
    {
        NiAVObject* pkScene = FUN_141b6efc0(pEntity);
        if (pkScene != 0)
            pkView->RemoveScene(pkScene);
    }
}

// The plane-reflection model's "enable" property changed.
// @0x1416a4350
void PostProcessingService::FUN_1416a4350(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    if (FUN_1408a9bd0(pEntity)->ContainsModel(0xddb91342))
    {
        bool bEnable;
        pEntity->GetPropertyValue(0x2683e9ec, bEnable);
        FUN_1416aa450(7, bEnable);
    }
}

// A plane-reflection entity entered the world.
// @0x1416a43e0
void PostProcessingService::FUN_1416a43e0(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    if (pEntity != 0 && FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b20()
        && FUN_1408a9bd0(pEntity)->ContainsModel(0xddb91342))
    {
        bool bEnable;
        pEntity->GetPropertyValue(0x2683e9ec, bEnable);
        FUN_1416aa450(7, bEnable && FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b20());
    }
}

// A plane-reflection entity left the world.
// @0x1416a44d0
void PostProcessingService::FUN_1416a44d0(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMessage->GetEntity();
    if (pEntity == 0)
        return;
    if (FUN_1408a9bd0(pEntity)->ContainsModel(0xddb91342))
    {
        FUN_1416aa450(7, false);
        m_spReflection = 0;
    }
}

// Swap the main click's render-list processor with the texture-density one (debug view).
// @0x1416a4570
void PostProcessingService::FUN_1416a4570(bool bEnable)
{
    if (FUN_1416a4620() == bEnable)
        return;
    efd::SmartPointer<NiRenderListProcessor> spOld = FUN_1413f99a0()->GetProcessor();
    FUN_1413f99a0()->SetProcessor(m_spProcessor);
    m_spProcessor = spOld;
}
MS2_REPLACE_METHOD(0x1416a4570, PostProcessingService, FUN_1416a4570, 161, 0xDB793BAB);

// @0x1416a4620
bool PostProcessingService::FUN_1416a4620()
{
    return m_spProcessor != m_spDensity;
}
MS2_REPLACE_METHOD(0x1416a4620, PostProcessingService, FUN_1416a4620, 53, 0x7A4B7694);

// @0x1416a4660
void PostProcessingService::FUN_1416a4660(int nMode)
{
    m_spDensity->FUN_14150d360(nMode);
}
MS2_REPLACE_METHOD(0x1416a4660, PostProcessingService, FUN_1416a4660, 49, 0xB62389FA);

// @0x1416a46a0
int PostProcessingService::FUN_1416a46a0()
{
    return m_spDensity->FUN_14150d380();
}
MS2_REPLACE_METHOD(0x1416a46a0, PostProcessingService, FUN_1416a46a0, 41, 0x16BD3474);

// Toggle the outline click (and its step 16).
// @0x1416a46d0
void PostProcessingService::FUN_1416a46d0()
{
    if ((NiViewRenderClick*)m_aspClicks[9] != 0)
    {
        bool bActive = m_aspClicks[9]->GetActive();
        FUN_1416a3920(0x10, !bActive);
        FUN_1416aa450(9, !bActive);
    }
}
MS2_REPLACE_METHOD(0x1416a46d0, PostProcessingService, FUN_1416a46d0, 175, 0x455F7CBE);

// @0x1416a4790
bool PostProcessingService::FUN_1416a4790()
{
    if ((NiViewRenderClick*)m_aspClicks[9] != 0)
    {
        bool bActive = m_aspClicks[9]->GetActive();
        return bActive;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1416a4790, PostProcessingService, FUN_1416a4790, 100, 0x7B8A5E63);

// @0x1416a4800
efd::SyncResult PostProcessingService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1411ab770(pRegistrar, 1);
    pRegistrar->AddDependency<egf::FlatModelManager>(1);
    FUN_1411ab740(pRegistrar, 1);
    pRegistrar->AddDependency<Unk_PPEffectServiceDep>(1);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD_VIA(0x1416a4800, PostProcessingService, efd::ISystemService, OnPreInit, 84, 0x822D00AC);

// @0x1416a4860
// MS2-FUNCTIONAL: frame is 0x20 bytes larger than the exe (temporary layout of the step allocations); same calls in the same order
efd::AsyncResult PostProcessingService::OnInit()
{
    egf::FlatModelManager* pFlatModelManager = m_pServiceManager->GetSystemServiceAs<egf::FlatModelManager>();
    pFlatModelManager->RegisterBuiltinModelFactory("PostProcessSetting", 0xc1e6b8c7, FUN_1416a3b10, 0);
    pFlatModelManager->RegisterBuiltinModelFactory("PlaneReflectionSetting", 0xddb91342, FUN_1416aa1a0, 0);
    m_pServiceManager->GetSystemServiceAs<efd::MessageService>()->Subscribe(this, DAT_143ae4c20, 0, false);
    FUN_141bbae40(FUN_1403ed2d0(), this);

    if (FUN_1416a69a0())
        FUN_1416a36f0(true);
    if (FUN_1416a66d0())
        FUN_1416a35c0(true);
    FUN_1416a3bb0();
    FUN_1416a7570();

    FUN_1416a6d90(0, NiNew SSAORenderStep((unsigned __int64)this, &NiFixedString("SSAO"), 0));
    FUN_1416a6d90(1, NiNew SSAORenderStep((unsigned __int64)this, &NiFixedString("SSAOOnly"), 0));
    FUN_1416a6d90(5, NiNew ColorPerspectiveRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(10, NiNew MotionBlurRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(6, NiNew OuterBlurRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0x10, NiNew OverdrawRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(8, NiNew ScreenMaskingRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(2, NiNew AntiAliasRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(3, NiNew BloomRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(4, NiNew DepthOfFieldRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0xb, NiNew GaussianBlurRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(7, NiNew MonochromeRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(9, NiNew RadialBlurRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0xc, NiNew HeatShimmerRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0xd, NiNew FadeInOutRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0xe, NiNew FadeInRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0xf, NiNew WorldFadeOutRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0x11, NiNew OutlineRenderStep((unsigned __int64)this, 0));
    FUN_1416a6d90(0x12, NiNew PostShimmerRenderStep((unsigned __int64)this, 0));

    FUN_1416a37a0(0, false);
    FUN_1416a37a0(1, false);
    FUN_1416a37a0(5, false);
    FUN_1416a37a0(10, false);
    FUN_1416a37a0(6, false);
    FUN_1416a37a0(0x10, false);
    FUN_1416a37a0(8, false);
    FUN_1416a37a0(2, false);
    FUN_1416a37a0(3, false);
    FUN_1416a37a0(4, false);
    FUN_1416a37a0(9, false);
    FUN_1416a37a0(0xb, false);
    FUN_1416a37a0(7, false);
    FUN_1416a37a0(0xd, false);
    FUN_1416a37a0(0xe, false);
    FUN_1416a37a0(0xf, false);
    FUN_1416a37a0(0xc, false);
    FUN_1416a3920(0x11, true);
    FUN_1416a37a0(0x12, false);
    FUN_1416aaef0();

    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != 0)
        pkRenderer->AddResetNotificationFunc(FUN_1416abce0, this);

    FUN_1416aa450(6, FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b30());
    FUN_1416aa450(7, false);
    FUN_1416aa450(8, true);
    FUN_1416aa450(10, true);

    m_spProcessor = m_spDensity = NiNew MS2TextureDensityProcessor();
    if ((CDepthOfFieldManager*)m_spDoF == 0)
    {
        m_spDoF = NiNew CDepthOfFieldManager();
        m_spDoF->FUN_141177fa0();
    }
    FUN_1409a8b00()->FUN_1409a5190(FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b1d40());
    return efd::AsyncResult_Complete;
}

// @0x1416a5f20
efd::AsyncResult PostProcessingService::OnTick()
{
    if (m_spSetting)
        m_spSetting->ApplyShaderConstants(FUN_14086d260()->FUN_141473230());
    FUN_1416a6fc0();
    FUN_1416aae50();
    if (m_spTextureEffect)
    {
        m_spTextureEffect->SetModelProjectionMatrix(DAT_143a09600);
        m_spTextureEffect->SetModelProjectionTranslation(efd::Point3::ZERO);
        m_spTextureEffect->Update((float)FUN_14086d260()->FUN_141473280());
    }
    if (m_spDoF)
        m_spDoF->FUN_141178000(FUN_14086d260()->FUN_141473230());
    return efd::AsyncResult_Pending;
}

// @0x1416a6100
efd::AsyncResult PostProcessingService::OnShutdown()
{
    efd::MessageService* pkMessageService = m_pServiceManager->GetSystemServiceAs<efd::MessageService>();
    pkMessageService->Unsubscribe(this, DAT_143ae4c20, false);
    ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pkRenderService == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"ERROR: PostProcessingService::LinkEffects pRenderService is Null");
        return efd::AsyncResult_Pending;
    }
    if (pkRenderService->GetActiveRenderSurface() != 0)
    {
        FUN_1416ac3b0(0);
        NiRenderFrame* pkFrame = pkRenderService->GetActiveRenderSurface()->GetRenderFrame();
        if (pkFrame == 0)
        {
            FUN_1401859c0(FUN_140166440(), 1, 0x13, L"ERROR: PostProcessingService::LinkEffects pFrame is Null");
            return efd::AsyncResult_Pending;
        }
        MS2_FOR_EACH(const auto& kStep, m_kSteps)
        {
            pkFrame->RemoveRenderStep(kStep.second);
            kStep.second->vfunc_16();
        }
        m_kSteps.clear();
        for (int i = 0; i < 2; i++)
        {
            if ((NiRenderTargetGroup*)m_aspFrameTargets[i] != 0)
            {
                FUN_1416aade0(m_aspFrameTargets[i]);
                m_aspFrameTargets[i] = 0;
            }
        }
        if ((NiRenderTargetGroup*)m_spTarget170 != 0)
        {
            FUN_1416aade0(m_spTarget170);
            m_spTarget170 = 0;
        }
        if ((NiRenderTargetGroup*)m_spTarget178 != 0)
        {
            FUN_1416aade0(m_spTarget178);
            m_spTarget178 = 0;
        }
        if (pkFrame != 0)
        {
            if ((NiDefaultClickRenderStep*)m_spMirroredStep != 0)
            {
                m_spMirroredStep->RemoveAllRenderClicks();
                m_aspClicks[7] = 0;
                m_aspTextures[7] = 0;
                pkFrame->RemoveRenderStep(m_spMirroredStep);
                m_spMirroredStep = 0;
            }
            NiDefaultClickRenderStep* pkStep = NiDynamicCast(NiDefaultClickRenderStep,
                pkFrame->GetRenderStepByName("PreprocessRenderStep"));
            if (pkStep != 0)
            {
                for (int i = 0; i < 11; i++)
                {
                    if (m_aspClicks[i] != 0)
                        pkStep->RemoveRenderClick(m_aspClicks[i]);
                    m_aspClicks[i] = 0;
                    m_aspTextures[i] = 0;
                }
                pkFrame->RemoveRenderStep(pkStep);
            }
        }
    }
    m_spSetting = 0;
    m_spTarget190 = 0;
    m_spReflection = 0;
    m_spTextureEffect = 0;
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != 0)
        pkRenderer->RemoveResetNotificationFunc(FUN_1416abce0);
    return efd::AsyncResult_Complete;
}

// @0x1416a66d0
bool PostProcessingService::FUN_1416a66d0()
{
    ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pkRenderService != 0)
    {
        NiRendererPtr spRenderer = pkRenderService->GetRenderer();
        if (spRenderer)
        {
            m_bMRT = true;
            if (spRenderer->GetMaxBuffersPerRenderTargetGroup() < 3)
            {
                EE_LOG_AT(1, 1, ("Multiple render targets not supported"), MS2_THIS_FILE, 0x238);
                m_bMRT = false;
            }
            Ni2DBuffer* pkBackBuffer = spRenderer->GetDefaultBackBuffer();
            if (pkBackBuffer != 0)
            {
                if (pkBackBuffer->GetMSAAPref() != Ni2DBuffer::MULTISAMPLE_NONE)
                {
                    EE_LOG_AT(1, 1, ("Multiple render targets disabled because MSAA is enabled under DX9"), MS2_THIS_FILE, 0x241);
                    m_bMRT = false;
                }
            }
        }
    }
    return m_bMRT;
}
MS2_REPLACE_METHOD(0x1416a66d0, PostProcessingService, FUN_1416a66d0, 699, 0x3366DDCD);

// @0x1416a69a0
// MS2-FUNCTIONAL: the exe routes the device-type local through edx before r8 (one extra mov); behaviour equivalent
bool PostProcessingService::FUN_1416a69a0()
{
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != 0)
    {
        NiTexture::FormatPrefs kFloatPrefs;
        kFloatPrefs.m_ePixelLayout = NiTexture::FormatPrefs::FLOAT_COLOR_64;
        kFloatPrefs.m_eMipMapped = NiTexture::FormatPrefs::NO;
        kFloatPrefs.m_eAlphaFmt = NiTexture::FormatPrefs::NONE;
        NiTexture::FormatPrefs kColorPrefs;
        kColorPrefs.m_ePixelLayout = NiTexture::FormatPrefs::TRUE_COLOR_32;
        kColorPrefs.m_eMipMapped = NiTexture::FormatPrefs::NO;
        kColorPrefs.m_eAlphaFmt = NiTexture::FormatPrefs::NONE;
        const NiPixelFormat* pkFloatFormat = pkRenderer->FindClosestPixelFormat(kFloatPrefs);
        const NiPixelFormat* pkColorFormat = pkRenderer->FindClosestPixelFormat(kColorPrefs);
        if (pkFloatFormat == 0 || pkColorFormat == 0)
        {
            m_bHDR = false;
        }
        else
        {
            LPDIRECT3D9 pkD3D = NiDX9Renderer::GetDirect3D();
            if (pkD3D != 0)
            {
                D3DFORMAT eFloat = NiDX9PixelFormat::DetermineD3DFormat(*pkFloatFormat);
                D3DFORMAT eColor = NiDX9PixelFormat::DetermineD3DFormat(*pkColorFormat);
                unsigned int uiDevType = pkRenderer->GetDevType();
                HRESULT hr = pkD3D->CheckDeviceFormatConversion(pkRenderer->GetAdapter(), (D3DDEVTYPE)uiDevType, eColor, eFloat);
                if (hr == D3D_OK)
                {
                    m_bHDR = true;
                }
                else if (hr == D3DERR_NOTAVAILABLE)
                {
                    m_bHDR = false;
                    EE_LOG_AT(1, 1, ("HDR to RGBA32 conversion is not supported."), MS2_THIS_FILE, 0x21a);
                }
                else
                {
                    m_bHDR = false;
                    EE_LOG_AT(1, 1, ("Error 0x%08x: %s", hr, _com_error(hr).ErrorMessage()), MS2_THIS_FILE, 0x21f);
                }
            }
        }
    }
    return m_bHDR;
}

// @0x1416a6d90
void PostProcessingService::FUN_1416a6d90(int nStep, efd::SmartPointer<PostProcessEffect> spStep)
{
    if (!spStep)
        return;
    if ((!spStep->vfunc_14() || m_bHDR) && (!spStep->vfunc_13() || m_bMRT))
    {
        m_kSteps.insert(std::make_pair(nStep, spStep));
    }
    else
    {
        EE_LOG_AT(1, 1, ("Failed to insert %s because HDR or MRT is not supported.", (const char*)spStep->GetName()),
            MS2_THIS_FILE, 0x28f);
    }
}

// @0x1416a6fc0
void PostProcessingService::FUN_1416a6fc0()
{
    ecrInput::InputService* pkInput = m_pServiceManager->GetSystemServiceAs<ecrInput::InputService>();
    if (pkInput != 0)
    {
        NiInputSystem* pkInputSystem = pkInput->GetInputSystem();
        if (pkInputSystem != 0)
        {
            if (FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0) && FUN_14025e7c0()->FUN_14116d9c0(0x1f, true, 0))
                FUN_1416a46d0();
        }
    }
}
MS2_REPLACE_METHOD(0x1416a6fc0, PostProcessingService, FUN_1416a6fc0, 136, 0xDFF6D6DD);

// @0x1416aade0
void PostProcessingService::FUN_1416aade0(NiRenderTargetGroup* pkTarget)
{
    if (pkTarget == 0)
        return;
    Ni2DBuffer* pkBuffer = pkTarget->GetBuffer(0);
    if (pkBuffer != 0)
    {
        Ni2DBuffer::RendererData* pkData = pkBuffer->GetRendererData();
        if (pkData != 0)
            FUN_1427e7520(pkData);
    }
}
MS2_REPLACE_METHOD(0x1416aade0, PostProcessingService, FUN_1416aade0, 96, 0x6CEB88E6);

// @0x1416aae50
void PostProcessingService::FUN_1416aae50()
{
    NiTListIterator kPos = m_kEvents.GetHeadPos();
    while (kPos != 0)
    {
        int nEvent = m_kEvents.Get(kPos);
        FUN_1416a37a0(nEvent, true);
        kPos = m_kEvents.GetNextPos(kPos);
    }
    m_kEvents.RemoveAll();
}
MS2_REPLACE_METHOD(0x1416aae50, PostProcessingService, FUN_1416aae50, 143, 0x005BD9F4);

// @0x1416ac3b0
void PostProcessingService::FUN_1416ac3b0(NiRenderTargetGroup* pkTarget)
{
    NiViewRenderClick* pkClick = FUN_1413f99a0();
    if (pkClick == 0)
        return;
    pkClick->SetRenderTargetGroup(pkTarget);
    Unk_PPPostEffectMgr* pkMgr = FUN_1409a8b00();
    if (pkMgr == 0)
        return;
    Unk_PPSecondView* pkView = pkMgr->FUN_1409a5160();
    if (pkView == 0)
        return;
    NiViewRenderClick* pkSecondClick = pkView->FUN_141774010();
    if (pkSecondClick == 0)
        return;
    pkSecondClick->SetRenderTargetGroup(pkTarget);
}

// @0x1416aa1a0
egf::IBuiltinModel* PostProcessingService::FUN_1416aa1a0()
{
    DAT_143ae4660->m_spReflection = EE_NEW CPlaneReflectionSetting();
    return DAT_143ae4660->m_spReflection;
}

// @0x1416aa240
void PostProcessingService::FUN_1416aa240()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    FUN_1416aade0(m_spTarget178);
    m_spTarget178 = 0;
    if (!m_aspTextures[7])
        return;
    Ni2DBuffer* pkBuffer = m_aspTextures[7]->GetBuffer();
    NiDepthStencilBuffer* pkDepth = NiDepthStencilBuffer::CreateCompatible(pkBuffer, pkRenderer);
    m_spTarget178 = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, pkDepth);
}
MS2_REPLACE_METHOD(0x1416aa240, PostProcessingService, FUN_1416aa240, 233, 0xB8534CC0);

// @0x1416aa330
void PostProcessingService::FUN_1416aa330()
{
    NiFixedString akNames[7] = { DAT_143ae52c0, DAT_143ae52c8, DAT_143ae52d0, DAT_143ae52d8, DAT_143ae5268, DAT_143ae5268,
        DAT_143ae5268 };
    for (int i = 0; i < 7; i++)
        m_aspMaterials[i] = NiMaterialLibrary::CreateMaterial(akNames[i]);
}

// @0x1416aa850
bool PostProcessingService::FUN_1416aa850(int nClick)
{
    if ((NiViewRenderClick*)m_aspClicks[nClick] != 0)
        return m_aspClicks[nClick]->GetActive();
    return false;
}
MS2_REPLACE_METHOD(0x1416aa850, PostProcessingService, FUN_1416aa850, 87, 0xA8DFE426);

// @0x1416aa8b0
bool PostProcessingService::FUN_1416aa8b0(NiRenderStep* pkStep)
{
    return pkStep != 0 && (pkStep->GetName() == "FadeInRenderStep" || pkStep->GetName() == "FadeInOutRenderStep" ||
        pkStep->GetName() == "FadeOutRenderStep");
}
MS2_REPLACE_METHOD(0x1416aa8b0, PostProcessingService, FUN_1416aa8b0, 146, 0x690747AC);

// @0x1416aac60
void PostProcessingService::FUN_1416aac60(NiAVObject* pkScene)
{
    if ((NiViewRenderClick*)m_aspClicks[7] != 0)
    {
        CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView, m_aspClicks[7]->GetRenderViews().GetHead());
        if (pkView != 0)
            pkView->RemoveScene(pkScene);
    }
}
MS2_REPLACE_METHOD(0x1416aac60, PostProcessingService, FUN_1416aac60, 151, 0x8060DB8C);

// @0x1416aad00
CDepthOfFieldManager* PostProcessingService::FUN_1416aad00()
{
    return m_spDoF;
}
MS2_REPLACE_METHOD(0x1416aad00, PostProcessingService, FUN_1416aad00, 33, 0x74B8236B);

// @0x1416aad30
void PostProcessingService::vfunc_3(int)
{
    m_b210 = false;
    if ((NiViewRenderClick*)m_aspClicks[7] != 0)
    {
        CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView, m_aspClicks[7]->GetRenderViews().GetHead());
        if (pkView != 0)
            pkView->RemoveAllScenes();
    }
}
MS2_REPLACE_METHOD_VIA(0x1416aad30, PostProcessingService, IWorldServiceCallback, vfunc_3, 157, 0x558D0698);

// @0x1416abce0
bool PostProcessingService::FUN_1416abce0(bool bBeforeReset, void* pvData)
{
    PostProcessingService* pkService = static_cast<PostProcessingService*>(pvData);
    if (pkService != 0)
        return pkService->FUN_1416abd20(bBeforeReset);
    return false;
}

// @0x1416aa450
// MS2-FUNCTIONAL: the exe builds the "PlaneReflection" name in a named local and keeps an extra copy of the found object (frame 0x10 smaller)
void PostProcessingService::FUN_1416aa450(int nClick, bool bActive)
{
    if (nClick >= 11 || !m_aspClicks[nClick])
        return;
    m_aspClicks[nClick]->SetActive(bActive);
    if (nClick == 7 && m_spMirroredStep)
    {
        m_spMirroredStep->SetActive(bActive);
        bool bEnable = m_spReflection && m_spReflection->FUN_1416b1d10();
        bEnable &= bActive;
        if (bEnable)
        {
            FUN_1416aa950();
        }
        else
        {
            m_spTextureEffect->DetachAllAffectedNodes();
            Unk_WorldEntityMap::iterator kPos = FUN_1409670f0()->FUN_1411ce4c0();
            egf::Entity* pkEntity = 0;
            while (FUN_1409670f0()->FUN_1411ce510(kPos, pkEntity))
            {
                NiNode* pkNode = NiDynamicCast(NiNode, FUN_141b6efc0(pkEntity));
                if (pkNode == 0)
                    continue;
                NiAVObject* pkObject = pkNode->GetObjectByName(NiFixedString("PlaneReflection"));
                if (pkObject != 0)
                    pkObject->UpdateEffects();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416aa450, PostProcessingService, FUN_1416aa450, 579, 0xAE9B339F);

// @0x1416aa6a0
void PostProcessingService::FUN_1416aa6a0(Unk_PPTexture nClick, bool bActive)
{
    if (nClick >= 11 || !m_aspClicks[nClick])
        return;
    if (bActive)
    {
        if (++m_aiRefCount[nClick] == 1)
        {
            m_aspClicks[nClick]->SetActive(true);
            FUN_1416a7570();
            FUN_1416ab960();
            FUN_1416aaef0();
        }
    }
    else
    {
        if (m_aiRefCount[nClick] > 0)
        {
            if (--m_aiRefCount[nClick] == 0)
            {
                m_aspClicks[nClick]->SetActive(false);
                FUN_1416a7570();
                FUN_1416ab960();
                FUN_1416aaef0();
            }
        }
    }
    bool bNowActive = m_aspClicks[nClick]->GetActive();
    Unk_PPLog2(FUN_140166440(), 0xc, 0x13, L"SetPreprocessRCActiveRef texture={0} active={1}\n", nClick, bNowActive);
}
MS2_REPLACE_METHOD(0x1416aa6a0, PostProcessingService, FUN_1416aa6a0, 423, 0x945022B3);

// @0x1416ac0b0
bool PostProcessingService::FUN_1416ac0b0(NiRenderClick* pkClick, void* pvData)
{
    PostProcessingService* pkService = static_cast<PostProcessingService*>(pvData);
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    pkRenderer->GetBackgroundColor(pkService->m_kBackground);
    pkRenderer->SetBackgroundColor(NiColor(0.5f, 0.5f, 0.0f));
    return true;
}

// @0x1416ac150
bool PostProcessingService::FUN_1416ac150(NiRenderClick* pkClick, void* pvData)
{
    if (pvData == 0)
        return true;
    PostProcessingService* pkService = FUN_1409a8b20();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiColorA* pkColor = static_cast<NiColorA*>(pvData);
    pkRenderer->GetBackgroundColor(pkService->m_kBackground);
    pkRenderer->SetBackgroundColor(*pkColor);
    return true;
}

// @0x1416ac1e0
bool PostProcessingService::FUN_1416ac1e0(NiRenderClick* pkClick, void* pvData)
{
    PostProcessingService* pkService = FUN_1409a8b20();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    pkRenderer->SetBackgroundColor(pkService->m_kBackground);
    return true;
}

#ifndef MS2_HOOK_DLL
// @0x1416ac240
bool PostProcessingService::FUN_1416ac240(NiRenderClick* pkClick, void* pvData)
{
    if (DAT_143ae4660 == 0 || pkClick == 0)
        return false;
    FUN_1409a5770(DAT_143ae53f8, (const float*)&DAT_143ae4be0, 16);
    DAT_143ae4660->m_iFrame = 1 - DAT_143ae4660->m_iFrame;
    pkClick->SetRenderTargetGroup(DAT_143ae4660->m_aspFrameTargets[DAT_143ae4660->m_iFrame]);
    return true;
}
#endif

#ifndef MS2_HOOK_DLL
// @0x1416ac2e0
bool PostProcessingService::FUN_1416ac2e0(NiRenderClick* pkClick, void* pvData)
{
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != 0)
    {
        D3DXMATRIX kView(pkRenderer->GetD3DView());
        D3DXMATRIX kProj(pkRenderer->GetD3DProj());
        if (DAT_143ae4660 != 0)
            DAT_143ae4be0 = kView * kProj;
        return true;
    }
    return false;
}
#endif

// @0x1416aaef0
// PostProcessingService::LinkEffects (name from its log strings): takes the steps out of the active render frame, then
// inserts the active ones after the main scene step (fade steps at the tail), chaining each step's output into the next
// one; the UI steps render into the first fade step's input and the last step into the default target.
void PostProcessingService::FUN_1416aaef0()
{
    ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pkRenderService == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"ERROR: PostProcessingService::LinkEffects pRenderService is Null");
        return;
    }
    NiRenderFrame* pkFrame = pkRenderService->GetActiveRenderSurface()->GetRenderFrame();
    if (pkFrame == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"ERROR: PostProcessingService::LinkEffects pFrame is Null");
        return;
    }
    NiRenderStep* pkMainSceneRenderStep = pkRenderService->GetActiveRenderSurface()->GetRenderStep();
    if (pkMainSceneRenderStep == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13,
            L"ERROR: PostProcessingService::LinkEffects pMainSceneRenderStep is Null");
        return;
    }

    MS2_FOR_EACH(const auto& kStep, m_kSteps)
        pkFrame->RemoveRenderStep(kStep.second);

    efd::SmartPointer<PostProcessEffect> spPrev = 0;
    efd::SmartPointer<PostProcessEffect> spFirst = 0;
    efd::SmartPointer<PostProcessEffect> spFirstFade = 0;
    NiTListIterator kPos = pkFrame->GetRenderSteps().FindPos(pkMainSceneRenderStep);

    MS2_FOR_EACH(const auto& kStep, m_kSteps)
    {
        if (!kStep.second)
            continue;
        kStep.second->SetPreProcessingCallbackFunc(0, 0);
        if (kStep.second->GetActive())
        {
            if (FUN_1416aa8b0(kStep.second))
                continue;
            if (spFirst == 0)
                spFirst = kStep.second;
            if (!kStep.second->FUN_1409a8f00())
            {
                if (!FUN_1416ac060(kStep.second))
                    continue;
            }
            else
            {
                kStep.second->vfunc_21();
            }
            kPos = pkFrame->GetRenderSteps().InsertAfter(kPos, NiDynamicCast(NiRenderStep, kStep.second));
            if (spPrev != 0)
                spPrev->SetOutputRenderTargetGroup((NiRenderTargetGroup*)kStep.second->vfunc_18());
            spPrev = kStep.second;
        }
    }

    MS2_FOR_EACH(const auto& kStep, m_kSteps)
    {
        if (!kStep.second)
            continue;
        if (kStep.second->GetActive())
        {
            if (!FUN_1416aa8b0(kStep.second))
                continue;
            if (spFirst == 0)
                spFirst = kStep.second;
            if (spFirstFade == 0)
                spFirstFade = kStep.second;
            if (!kStep.second->FUN_1409a8f00())
            {
                if (!kStep.second->vfunc_15(m_nFormat, m_aspTextures))
                    continue;
            }
            pkFrame->GetRenderSteps().AddTail(NiDynamicCast(NiRenderStep, kStep.second));
            if (spPrev != 0)
                spPrev->SetOutputRenderTargetGroup((NiRenderTargetGroup*)kStep.second->vfunc_18());
            spPrev = kStep.second;
        }
    }

    NiTListIterator kIter = 0;
    if (kIter == 0)
        kIter = pkFrame->GetRenderSteps().GetHeadPos();
    while (kIter)
    {
        NiRenderStep* pkStep = pkFrame->GetRenderSteps().GetNext(kIter);
        if (pkStep != 0 && (pkStep->GetName() == "UI Render Step" || pkStep->GetName() == "Screen Elements Render Step"))
        {
            if (spFirstFade)
            {
                if (spFirstFade == spFirst)
                    pkStep->SetOutputRenderTargetGroup(m_spTarget190);
                else
                    pkStep->SetOutputRenderTargetGroup((NiRenderTargetGroup*)spFirstFade->vfunc_18());
            }
            else
            {
                pkStep->SetOutputRenderTargetGroup(pkRenderService->GetRenderer()->GetDefaultRenderTargetGroup());
            }
        }
    }

    if (spFirst == 0)
    {
        FUN_1416ac3b0(pkRenderService->GetRenderer()->GetDefaultRenderTargetGroup());
    }
    else if (spPrev != 0)
    {
        spPrev->SetOutputRenderTargetGroup(pkRenderService->GetRenderer()->GetDefaultRenderTargetGroup());
        FUN_1416ac3b0(m_spTarget190);
        spFirst->SetPreProcessingCallbackFunc(FUN_1416abac0, this);
    }
}
MS2_REPLACE_METHOD(0x1416aaef0, PostProcessingService, FUN_1416aaef0, 2660, 0x8ED2747E);

// @0x1416ab960
void PostProcessingService::FUN_1416ab960()
{
    ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pkRenderService != 0)
    {
        NiRenderFrame* pkFrame = pkRenderService->GetActiveRenderSurface()->GetRenderFrame();
        if (pkFrame != 0)
        {
            MS2_FOR_EACH(const auto& kStep, m_kSteps)
            {
                if (kStep.second)
                {
                    pkFrame->RemoveRenderStep(kStep.second);
                    kStep.second->vfunc_16();
                    FUN_1416ac060(kStep.second);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416ab960, PostProcessingService, FUN_1416ab960, 332, 0x7308CC9D);

// @0x1416abac0
bool PostProcessingService::FUN_1416abac0(NiRenderStep* pkStep, void* pvData)
{
    PostProcessingService* pkService = static_cast<PostProcessingService*>(pvData);
    if (pkService != 0)
    {
        PostProcessEffect* pkEffect = static_cast<PostProcessEffect*>(pkStep);
        if (pkEffect != 0)
        {
            pkService->FUN_1416abb30(static_cast<NiTexture*>(pkEffect->vfunc_17()));
            return true;
        }
    }
    return false;
}

// @0x1416abb30
void PostProcessingService::FUN_1416abb30(NiTexture* pkTexture)
{
    if (m_spTarget190 && pkTexture != 0)
    {
        NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
        if (pkRenderer != 0)
        {
            if (pkRenderer->IsRenderTargetGroupActive())
                pkRenderer->EndUsingRenderTargetGroup();
            Ni2DBuffer* pkBuffer = m_spTarget190->GetBuffer(0);
            NiDX92DBufferData* pkData;
            if (pkBuffer != 0 && (pkData = (NiDX92DBufferData*)pkBuffer->GetRendererData()) != 0)
            {
                LPDIRECT3DSURFACE9 pkSource = pkData->GetSurface();
                NiDX9TextureData* pkTextureData = (NiDX9TextureData*)pkTexture->GetRendererData();
                LPDIRECT3DTEXTURE9 pkD3DTexture = (LPDIRECT3DTEXTURE9)pkTextureData->GetD3DTexture();
                LPDIRECT3DSURFACE9 pkDest = 0;
                HRESULT hr = pkD3DTexture->GetSurfaceLevel(0, &pkDest);
                LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
                hr = pkDevice->StretchRect(pkSource, 0, pkDest, 0, D3DTEXF_NONE);
                pkDest->Release();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416abb30, PostProcessingService, FUN_1416abb30, 425, 0x9F8C271C);

// @0x1416ac060
bool PostProcessingService::FUN_1416ac060(PostProcessEffect* pkEffect)
{
    return pkEffect->vfunc_15(m_nFormat, m_aspTextures);
}
MS2_REPLACE_METHOD(0x1416ac060, PostProcessingService, FUN_1416ac060, 70, 0x9865683C);

void FUN_141773ed0(Unk_PPSecondView* pkSoftParticles);      // (softparticlesmanager.cpp) re-bind the soft-particle depth texture (m_aspTextures[1])
extern NiFixedString DAT_143ae5328;                         // texel-size shader constant name
extern NiFixedString DAT_143ae5330;                         // horizontal 9-tap offsets
extern NiFixedString DAT_143ae5338;                         // vertical 9-tap offsets

// @0x1416a7050
void PostProcessingService::FUN_1416a7050()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    FUN_1416ac440(uiWidth, uiHeight);

    NiTexture::FormatPrefs kPrefs;
    for (int i = 0; i < 11; i++)
    {
        if (m_aspTextures[i])
            m_aspTextures[i] = 0;
    }

    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(8);
    m_aspTextures[1] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    FUN_141773ed0(FUN_1409a8b00()->FUN_1409a5160());
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_aspTextures[2] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(0xd);
    m_aspTextures[3] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    m_aspTextures[4] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(m_nFormat);
    m_aspTextures[5] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_aspTextures[6] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_aspTextures[7] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);

    m_spTextureEffect = NiNew NiTextureEffect;
    m_spTextureEffect->SetEffectTexture(m_aspTextures[7]);
    m_spTextureEffect->SetTextureFilter(NiTexturingProperty::FILTER_BILERP);
    m_spTextureEffect->SetTextureClamp(NiTexturingProperty::CLAMP_S_CLAMP_T);
    m_spTextureEffect->SetTextureType(NiTextureEffect::ENVIRONMENT_MAP);
    m_spTextureEffect->SetTextureCoordGen(static_cast<NiTextureEffect::CoordGenType>(5));   // MS2 screen-space mode (not in the SDK enum)

    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(8);
    m_aspTextures[8] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_aspTextures[9] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_aspTextures[10] = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
}
MS2_REPLACE_METHOD(0x1416a7050, PostProcessingService, FUN_1416a7050, 1299, 0x5577C7E9);

// @0x1416ac440
void PostProcessingService::FUN_1416ac440(unsigned int uiWidth, unsigned int uiHeight)
{
    float afTexel[2] = { 1.0f / (float)uiWidth, 1.0f / (float)uiHeight };
    FUN_1409a5770(DAT_143ae5328, afTexel, 2);

    const int iTaps = 9;
    float afOffsetsX[iTaps];
    float afOffsetsY[iTaps];
    for (int i = 0; i < iTaps; i++)
    {
        int iOffset = i - 4;
        afOffsetsX[i] = (float)iOffset / (float)uiWidth;
        afOffsetsY[i] = (float)iOffset / (float)uiHeight;
    }
    FUN_1409a5770(DAT_143ae5330, afOffsetsX, iTaps);
    FUN_1409a5770(DAT_143ae5338, afOffsetsY, iTaps);
}
MS2_REPLACE(0x1416ac440, PostProcessingService::FUN_1416ac440, 306, 0x04D746FF);

// @0x1416a7570
void PostProcessingService::FUN_1416a7570()
{
    ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (pkRenderService != 0)
    {
        NiRenderFrame* pkFrame = pkRenderService->GetActiveRenderSurface()->GetRenderFrame();
        if (pkFrame != 0)
        {

            bool abActive[11] = { false };
            for (int i = 0; i < 11; i++)
            {
                abActive[i] = false;
                if (m_aspClicks[i])
                {
                    abActive[i] = m_aspClicks[i]->GetActive();
                    m_aspClicks[i] = 0;
                }
            }

            NiRenderStep* pkOldStep = pkFrame->GetRenderStepByName("PreprocessRenderStep");
            if (pkOldStep != 0)
                pkFrame->RemoveRenderStep(pkOldStep);

            FUN_1416a7050();

            NiDefaultClickRenderStep* pkStep = NiNew NiDefaultClickRenderStep;
            if (pkStep != 0)
            {
                pkStep->SetName("PreprocessRenderStep");
                pkFrame->AppendRenderStep(pkStep);

                if (m_aspClicks[3] = FUN_1416a8140())
                {
                    pkStep->AppendRenderClick(m_aspClicks[3]);
                    m_aspClicks[3]->SetActive(abActive[3]);
                }
                if (m_aspClicks[1] = FUN_1416a8600())
                {
                    m_aspClicks[1]->SetActive(abActive[1]);
                    m_aspClicks[1]->SetBackgroundColor(Unk_AfterImageColor(0.0f, 0.0f, 0.0f, 1.0f));
                    pkStep->AppendRenderClick(m_aspClicks[1]);
                }
                if (m_aspClicks[6] = FUN_1416a8e50())
                {
                    m_aspClicks[6]->SetActive(abActive[6]);
                    pkStep->AppendRenderClick(m_aspClicks[6]);
                }
                if (m_aspClicks[8] = FUN_1416a92e0())
                {
                    m_aspClicks[8]->SetActive(abActive[8]);
                    m_aspClicks[8]->SetBackgroundColor(Unk_AfterImageColor(0.0f, 0.0f, 0.0f, 0.0f));
                    pkStep->AppendRenderClick(m_aspClicks[8]);
                }
                if (m_aspClicks[9] = FUN_1416a9a90())
                {
                    m_aspClicks[9]->SetActive(abActive[9]);
                    pkStep->AppendRenderClick(m_aspClicks[9]);
                }
                if (m_aspClicks[10] = FUN_1416a9e20())
                {
                    m_aspClicks[10]->SetActive(abActive[10]);
                    pkStep->AppendRenderClick(m_aspClicks[10]);
                }
            }

            if (m_spMirroredStep)
                pkFrame->RemoveRenderStep(m_spMirroredStep);
            FUN_1416aa240();

            if (m_spMirroredStep = NiNew NiDefaultClickRenderStep())
            {
                m_spMirroredStep->SetName("MirroredRenderStep");
                pkFrame->AppendRenderStep(m_spMirroredStep);
                if (m_aspClicks[7] = FUN_1416a97b0())
                {
                    m_aspClicks[7]->SetActive(abActive[7]);
                    m_spMirroredStep->AppendRenderClick(m_aspClicks[7]);
                }
                m_spMirroredStep->SetPreProcessingCallbackFunc(FUN_1416a4000, 0);
                m_spMirroredStep->SetPostProcessingCallbackFunc(FUN_1416a40c0, 0);
                m_spMirroredStep->SetActive(true);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416a7570, PostProcessingService, FUN_1416a7570, 3005, 0x5D8FCE97);

extern NiFixedString DAT_143ae5260;     // motion-blur velocity material name

// @0x1416a8140
// The motion-blur velocity click: renders the main view with the velocity material into the ping-pong frame targets
// built over the motion-blur history textures (3/4).
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a8140()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiViewRenderClick* pkClick = NiNew NiViewRenderClick;
    if (pkClick)
    {
        pkClick->SetName("VelocityRenderClick");
        for (int i = 0; i < 2; i++)
        {
            if (m_aspFrameTargets[i])
            {
                FUN_1416aade0(m_aspFrameTargets[i]);
                m_aspFrameTargets[i] = 0;
            }
            if (m_aspTextures[i + 3])
            {
                Ni2DBuffer* pkBuffer = m_aspTextures[i + 3]->GetBuffer();
                NiDepthStencilBuffer* pkDepth = NiDepthStencilBuffer::CreateCompatible(pkBuffer, pkRenderer);
                if (pkDepth == 0)
                    return 0;
                m_aspFrameTargets[i] = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, pkDepth);
                if (!m_aspFrameTargets[i])
                    return 0;
            }
        }
        m_iFrame = 1;
        if (m_aspFrameTargets[m_iFrame])
        {
            pkClick->SetRenderTargetGroup(m_aspFrameTargets[m_iFrame]);
            pkClick->SetClearAllBuffers(true);
            pkClick->AppendRenderView(FUN_1413f9a70());
            NiMaterialPtr spMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5260);
            if (!spMaterial)
                return 0;
            MS2VelocityMaterialSwapProcessor* pkProcessor = NiNew MS2VelocityMaterialSwapProcessor(spMaterial, 0xffffffff);
            pkProcessor->FUN_14135e060(1);
            pkClick->SetProcessor(pkProcessor);
            pkClick->SetPreProcessingCallbackFunc(FUN_1416ac240, this);
            pkClick->SetPostProcessingCallbackFunc(FUN_1416ac2e0, this);
            return pkClick;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a8140, PostProcessingService, FUN_1416a8140, 1198, 0x9DA5D7D5);

// @0x1416a97b0
// The shimmer source click: renders a mirrored copy of the main view into m_spTarget178.
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a97b0()
{
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick)
    {
        spClick->SetName("MirroredRenderClick");
        spClick->SetRenderTargetGroup(m_spTarget178);
        spClick->SetClearAllBuffers(true);
        Ni3DRenderView* pkMainView = FUN_1413f9a70();
        CMirrored3DRenderView* pkView = NiNew CMirrored3DRenderView(pkMainView->GetCamera(),
            pkMainView->GetCullingProcess(), pkMainView->GetAlwaysUseCameraViewport());
        spClick->AppendRenderView(pkView);
        spClick->SetProcessor(NiNew MS2RenderListProcessor);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a97b0, PostProcessingService, FUN_1416a97b0, 729, 0xCC1298A7);

extern NiColorA DAT_143a09680;          // efd::ColorA::BLACK (0,0,0,1)

// @0x1416a9a90
// The overdraw accumulation click: renders the main view with the overdraw processor into texture 9.
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a9a90()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (!m_aspTextures[9])
        return 0;
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick)
    {
        spClick->SetName("AccumRenderClick");
        Ni2DBuffer* pkBuffer = m_aspTextures[9]->GetBuffer();
        NiRenderTargetGroupPtr spTarget = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, true, true);
        if (!spTarget)
            return 0;
        spClick->SetRenderTargetGroup(spTarget);
        spClick->SetClearAllBuffers(true);
        spClick->AppendRenderView(FUN_1413f9a70());
        MS2OverdrawProcessor* pkProcessor = NiNew MS2OverdrawProcessor;
        spClick->SetProcessor(pkProcessor);
        spClick->SetPreProcessingCallbackFunc(FUN_1416ac150, &DAT_143a09680);
        spClick->SetPostProcessingCallbackFunc(FUN_1416ac1e0, 0);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a9a90, PostProcessingService, FUN_1416a9a90, 896, 0x26CEBED6);

// @0x1416a9e20
// The outline click: renders the outlined objects with MS2OutlinePreProcessor into texture 10.
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a9e20()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (!m_aspTextures[10])
        return 0;
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew OutlineRenderClick())
    {
        spClick->SetName("OutlineRenderClick");
        Ni2DBuffer* pkBuffer = m_aspTextures[10]->GetBuffer();
        NiRenderTargetGroupPtr spTarget = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, true, true);
        spClick->SetRenderTargetGroup(spTarget);
        spClick->SetClearAllBuffers(true);
        spClick->AppendRenderView(FUN_1413f9a70());
        efd::SmartPointer<MS2OutlinePreProcessor> spProcessor = NiNew MS2OutlinePreProcessor;
        spClick->SetProcessor(spProcessor);
        spClick->SetPreProcessingCallbackFunc(FUN_1416ac150, &DAT_143a09680);
        spClick->SetPostProcessingCallbackFunc(FUN_1416ac1e0, 0);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a9e20, PostProcessingService, FUN_1416a9e20, 878, 0xCA30F9C3);

// @0x1416a8e50
// The shimmer click: renders the shimmering objects with MS2ShimmerSortProcessor into texture 6 (m_spTarget170).
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a8e50()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    FUN_1416aade0(m_spTarget170);
    m_spTarget170 = 0;
    if (!m_aspTextures[6])
        return 0;
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick)
    {
        spClick->SetName("ShimmerhRenderClick");
        Ni2DBuffer* pkBuffer = m_aspTextures[6]->GetBuffer();
        NiDepthStencilBufferPtr spDepth = NiDepthStencilBuffer::CreateCompatible(pkBuffer, pkRenderer);
        if (!spDepth)
            return 0;
        m_spTarget170 = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, spDepth);
        if (!m_spTarget170)
            return 0;
        spClick->SetRenderTargetGroup(m_spTarget170);
        spClick->SetClearAllBuffers(true);
        spClick->AppendRenderView(FUN_1413f9a70());
        efd::SmartPointer<MS2ShimmerSortProcessor> spProcessor = NiNew MS2ShimmerSortProcessor;
        spClick->SetProcessor(spProcessor);
        spClick->SetPreProcessingCallbackFunc(FUN_1416ac0b0, this);
        spClick->SetPostProcessingCallbackFunc(FUN_1416ac1e0, this);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a8e50, PostProcessingService, FUN_1416a8e50, 1149, 0x10C60E57);

extern NiFixedString DAT_143ae51f0;     // glow material name
int FUN_1414cffc0(NiRenderObject* pkObject);    // glow material-swap predicate

// @0x1416a92e0
// The glow click: renders the glowing objects with the glow material into texture 8.
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a92e0()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (!m_aspTextures[8])
        return 0;
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick)
    {
        spClick->SetName("GlowRenderClick");
        Ni2DBuffer* pkBuffer = m_aspTextures[8]->GetBuffer();
        NiDepthStencilBufferPtr spDepth = NiDepthStencilBuffer::CreateCompatible(pkBuffer, pkRenderer);
        if (!spDepth)
            return 0;
        NiRenderTargetGroupPtr spTarget = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, spDepth);
        if (!spTarget)
            return 0;
        spClick->SetRenderTargetGroup(spTarget);
        spClick->SetClearAllBuffers(true);
        spClick->AppendRenderView(FUN_1413f9a70());
        NiMaterialPtr spMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae51f0);
        if (!spMaterial)
            return 0;
        MS2MaterialSwapProcessor* pkProcessor = NiNew MS2MaterialSwapProcessor(spMaterial, FUN_1414cffc0);
        pkProcessor->FUN_1414cfbc0(0);
        pkProcessor->DisableOutlineColor();
        spClick->SetProcessor(pkProcessor);
        spClick->SetPreProcessingCallbackFunc(FUN_1416ac150, &DAT_143a09680);
        spClick->SetPostProcessingCallbackFunc(FUN_1416ac1e0, 0);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a92e0, PostProcessingService, FUN_1416a92e0, 1223, 0x392779DD);

extern NiFixedString DAT_143ae5210;     // depth material name (static objects)
extern NiFixedString DAT_143ae5220;     // depth material name (skinned objects)
extern NiFixedString DAT_143ae5228;     // depth material name (alpha-tested objects)
int FUN_1414d0120(NiRenderObject* pkObject);    // depth material-swap predicates
int FUN_1414cfef0(NiRenderObject* pkObject);
int FUN_1414d00b0(NiRenderObject* pkObject);

// @0x1416a8600
// The depth click: renders the scene depth with three predicate-selected depth materials into texture 1.
efd::SmartPointer<NiViewRenderClick> PostProcessingService::FUN_1416a8600()
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (!m_aspTextures[1])
        return 0;
    if (efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick)
    {
        spClick->SetName("DepthRenderClick");
        Ni2DBuffer* pkBuffer = m_aspTextures[1]->GetBuffer();
        NiDepthStencilBufferPtr spDepth = NiDepthStencilBuffer::CreateCompatible(pkBuffer, pkRenderer);
        if (!spDepth)
            return 0;
        NiRenderTargetGroupPtr spTarget = NiRenderTargetGroup::Create(pkBuffer, pkRenderer, spDepth);
        if (!spTarget)
            return 0;
        spClick->SetRenderTargetGroup(spTarget);
        spClick->SetClearAllBuffers(true);
        spClick->AppendRenderView(FUN_1413f9a70());
        spClick->SetPreProcessingCallbackFunc(FUN_1416ac150, &DAT_143a09680);
        spClick->SetPostProcessingCallbackFunc(FUN_1416ac1e0, 0);
        NiMaterialPtr spSkinned = NiMaterialLibrary::CreateMaterial(DAT_143ae5220);
        if (!spSkinned)
            return 0;
        NiMaterialPtr spAlpha = NiMaterialLibrary::CreateMaterial(DAT_143ae5228);
        if (!spAlpha)
            return 0;
        NiMaterialPtr spStatic = NiMaterialLibrary::CreateMaterial(DAT_143ae5210);
        if (!spStatic)
            return 0;
        std::vector<NiPointer<MaterialSwapper> > kSwappers;
        kSwappers.push_back(NiNew MaterialSwapper(FUN_1414d0120, spStatic));
        kSwappers.push_back(NiNew MaterialSwapper(FUN_1414cfef0, spSkinned));
        kSwappers.push_back(NiNew MaterialSwapper(FUN_1414d00b0, spAlpha));
        MS2MaterialSwapProcessor* pkProcessor = NiNew MS2MaterialSwapProcessor(kSwappers);
        pkProcessor->FUN_1414cfbc0(0);
        spClick->SetProcessor(pkProcessor);
        return spClick;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416a8600, PostProcessingService, FUN_1416a8600, 2118, 0xAE544DEE);

// @0x1416aa950
// MS2-FUNCTIONAL: the exe keeps the GetObjectByName result in an extra slot and uses jne/jmp for the cast test; locals swapped
// Turn the mirrored (plane reflection) view on: mirror the main view's scenes and attach the reflection texture
// effect to every entity's "PlaneReflection" node.
void PostProcessingService::FUN_1416aa950()
{
    if (!m_aspClicks[7])
        return;
    CMirrored3DRenderView* pkView = NiDynamicCast(CMirrored3DRenderView, m_aspClicks[7]->GetRenderViews().GetHead());
    if (!pkView)
        return;
    pkView->RemoveAllScenes();
    if (!m_spTextureEffect)
        return;
    m_spTextureEffect->DetachAllAffectedNodes();
    if (!FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b20())
        return;
    if (m_spReflection)
        pkView->SetMirrorPoints((const NiPoint3&)m_spReflection->FUN_1416b0e20(),
            (const NiPoint3&)m_spReflection->FUN_1416b0de0());
    pkView->RemoveAllScenes();
    Ni3DRenderView* pkMainView = FUN_1413f9a70();
    if (pkMainView)
    {
        NiTPointerList<NiAVObjectPtr>& kScenes = pkMainView->GetScenes();
        NiTListIterator kPos = kScenes.GetHeadPos();
        while (kPos)
        {
            NiAVObject* pkScene = kScenes.GetNext(kPos);
            pkView->AppendScene(pkScene);
        }
        Unk_WorldEntityMap::iterator kIter = FUN_1409670f0()->FUN_1411ce4c0();
        egf::Entity* pEntity = 0;
        while (FUN_1409670f0()->FUN_1411ce510(kIter, pEntity))
        {
            NiNode* pkRoot = NiDynamicCast(NiNode, FUN_141b6efc0(pEntity));
            if (!pkRoot)
                continue;
            NiAVObject* pkObject = pkRoot->GetObjectByName("PlaneReflection");
            NiNode* pkNode;
            if (pkObject && (pkNode = NiDynamicCast(NiNode, pkObject)) != 0)
            {
                m_spTextureEffect->AttachAffectedNode(pkNode);
                pkObject->UpdateEffects();
            }
        }
    }
    m_b210 = true;
}
MS2_REPLACE_METHOD(0x1416aa950, PostProcessingService, FUN_1416aa950, 775, 0x502A26EE);

// @0x1416abd20
// MS2-FUNCTIONAL: the exe calls the virtual GetOutputRenderTargetGroup before GetRenderer and copies the step map's begin()/end() temporaries into separate locals
// Device reset: before the reset detach every target that is not the back buffer and release the copy target; after
// it rebuild the targets, the pre-process step and the effect chain.
bool PostProcessingService::FUN_1416abd20(bool bBeforeReset)
{
    if (bBeforeReset)
    {
        if (FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b20())
            FUN_1416aa450(7, false);
        NiRenderer::GetRenderer()->EndUsingRenderTargetGroup();
        ecr::RenderService* pkRenderService = m_pServiceManager->GetSystemServiceAs<ecr::RenderService>();
        if (pkRenderService != 0)
        {
            NiRenderStep* pkStep = pkRenderService->GetActiveRenderSurface()->GetRenderStep();
            if (pkStep != 0)
            {
                if (pkStep->GetOutputRenderTargetGroup() != pkRenderService->GetRenderer()->GetDefaultRenderTargetGroup())
                    FUN_1416ac3b0(0);
                MS2_FOR_EACH(const auto& kStep, m_kSteps)
                {
                    if (kStep.second->GetOutputRenderTargetGroup() != pkRenderService->GetRenderer()->GetDefaultRenderTargetGroup()
                        && kStep.second)
                        kStep.second->SetOutputRenderTargetGroup(0);
                }
            }
        }
    }
    if (!bBeforeReset)
    {
        FUN_1416a3bb0();
        FUN_1416a7570();
        if (FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1416b0b20())
            FUN_1416aa450(7, true);
        FUN_1416ab960();
        FUN_1416aaef0();
    }
    else if (m_spTarget190)
    {
        Ni2DBuffer* pkBuffer = m_spTarget190->GetBuffer(0);
        if (pkBuffer != 0)
        {
            Ni2DBuffer::RendererData* pkData = pkBuffer->GetRendererData();
            if (pkData != 0)
                FUN_1427e7520(pkData);
            m_spTarget190 = 0;
        }
    }
    FUN_1409a8b00()->FUN_1409a3b60(bBeforeReset);
    return true;
}
MS2_REPLACE_METHOD(0x1416abd20, PostProcessingService, FUN_1416abd20, 820, 0x723AFA3D);

// Builds one screen-filling post-process pass: a full-screen quad textured with
// pkSource (plus up to three shader maps), drawn with pcMaterial into pkTarget,
// and appends the click to pkStep. Callers reach it through FUN_1416b4990.
// @0x1416b4990
efd::SmartPointer<NiViewRenderClick> setupRenderClick(NiDefaultClickRenderStep* pkStep, const char* pcName,
    NiRenderClick::Callback pfnCallback, void* pvCallbackData, NiTexture* pkSource,
    NiTexturingProperty::FilterMode eFilter, NiTexturingProperty::ClampMode eClamp, NiRenderedTexture* pkTarget,
    const char* pcMaterial, NiTexture* pkMap0, NiTexture* pkMap1, NiTexture* pkMap2)
{
    {
        efd::SmartPointer<NiScreenFillingRenderView> spView =
            NiDynamicCast(NiScreenFillingRenderView, NiScreenFillingRenderView::Create());
        if (spView)
        {
            efd::SmartPointer<NiViewRenderClick> spClick = NiNew NiViewRenderClick;
            if (spClick)
            {
                spClick->SetName(pcName);
                spClick->SetBackgroundColor((const efd::ColorA&)DAT_143a09680);
                spClick->SetClearColorBuffers(false);
                spClick->AppendRenderView(spView);
                spClick->SetPreProcessingCallbackFunc(pfnCallback, pvCallbackData);
                NiRenderObject* pkQuad = &spView->GetScreenFillingQuad();
                {
                    efd::SmartPointer<NiTexturingProperty> spTexProp = NiNew NiTexturingProperty;
                    if (spTexProp)
                    {
                        spTexProp->SetBaseTexture(pkSource);
                        spTexProp->SetBaseFilterMode(eFilter);
                        spTexProp->SetBaseClampMode(eClamp);
                        pkQuad->AttachProperty(spTexProp);
                        if (pkTarget != 0)
                        {
                            efd::SmartPointer<NiRenderTargetGroup> spTarget = NiRenderTargetGroup::Create(
                                pkTarget->GetBuffer(), FUN_140994450(), true, true);
                            if (!spTarget)
                                return 0;
                            spClick->SetRenderTargetGroup(spTarget);
                        }
                        if (pcMaterial == 0)
                            return 0;
                        efd::SmartPointer<NiMaterial> spMaterial = NiSingleShaderMaterial::Create(pcMaterial, true);
                        if (!spMaterial)
                            return 0;
                        pkQuad->ApplyAndSetActiveMaterial(spMaterial);
                        pkStep->AppendRenderClick(spClick);
                        if (pkMap0 != 0)
                        {
                            NiTexturingProperty::ShaderMap* pkMap =
                                NiNew NiTexturingProperty::ShaderMap(pkMap0, 0, eClamp, eFilter, 0);
                            if (pkMap == 0)
                                return 0;
                            spTexProp->SetShaderMap(0, pkMap);
                        }
                        if (pkMap1 != 0)
                        {
                            NiTexturingProperty::ShaderMap* pkMap =
                                NiNew NiTexturingProperty::ShaderMap(pkMap1, 1, eClamp, eFilter, 0);
                            if (pkMap == 0)
                                return 0;
                            spTexProp->SetShaderMap(1, pkMap);
                        }
                        if (pkMap2 != 0)
                        {
                            NiTexturingProperty::ShaderMap* pkMap =
                                NiNew NiTexturingProperty::ShaderMap(pkMap2, 2, eClamp, eFilter, 0);
                            if (pkMap == 0)
                                return 0;
                            spTexProp->SetShaderMap(2, pkMap);
                        }
                    }
                    else
                        return 0;
                }
                pkQuad->Update(0.0f, true);
                pkQuad->UpdateEffects();
                pkQuad->UpdateProperties();
                spClick->SetClearAllBuffers(true);
                return spClick;
            }
        }
    }
    return 0;
}
MS2_REPLACE(0x1416b4990, setupRenderClick, 2448, 0x1AC6ABD0);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x14169dbb0, AntiAliasRenderStep::FUN_14169dbb0, 558, 0xA464B825);
MS2_REPLACE_METHOD(0x14169de50, AntiAliasRenderStep, GetRTTI, 13, 0x999A4F05);
MS2_REPLACE_METHOD(0x14169de70, AntiAliasRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x14169de80, AntiAliasRenderStep, vfunc_13, 8, 0x71679366);
MS2_REPLACE_METHOD(0x14169ea40, BloomRenderStep, vfunc_21, 6, 0xA9AF6E37);
MS2_REPLACE(0x14169ea50, FUN_14169ea50, 156, 0x46256621);
MS2_REPLACE(0x14169eb00, FUN_14169eb00, 351, 0x39DDC9AD);
MS2_REPLACE(0x14169ec70, FUN_14169ec70, 351, 0x7C0B5643);
MS2_REPLACE(0x14169ede0, FUN_14169ede0, 73, 0x1B390CC2);
MS2_REPLACE(0x14169ee30, FUN_14169ee30, 224, 0x6828FB8D);
MS2_REPLACE(0x14169ef20, FUN_14169ef20, 164, 0xE3B72275);
MS2_REPLACE(0x14169efd0, FUN_14169efd0, 505, 0x050DD5EC);
MS2_REPLACE_METHOD(0x14169f340, BloomRenderStep, GetRTTI, 13, 0xA11D5231);
MS2_REPLACE_METHOD(0x14169f350, BloomRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x14169f360, BloomRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a0a00, DepthOfFieldRenderStep, GetRTTI, 13, 0x91350CB0);
MS2_REPLACE_METHOD(0x1416a0a10, DepthOfFieldRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a0a20, DepthOfFieldRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a0b20, FadeInOutRenderStep, vfunc_15, 419, 0x3BA4755A);
MS2_REPLACE(0x1416a0cd0, FadeInOutRenderStep::FUN_1416a0cd0, 394, 0xB126006A);
MS2_REPLACE(0x1416a0e70, FUN_1416a0e70, 3, 0x9B77E60D);
MS2_REPLACE_METHOD(0x1416a0fb0, PostProcessingService, FUN_1416a0fb0, 42, 0xC4C54FCD);
MS2_REPLACE_METHOD(0x1416a0fe0, FadeInOutRenderStep, GetRTTI, 13, 0x0E54005A);
MS2_REPLACE_METHOD(0x1416a0ff0, FadeInOutRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1000, FadeInOutRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a10c0, FadeInRenderStep, vfunc_15, 397, 0xE1AC1D0F);
MS2_REPLACE(0x1416a1260, FadeInRenderStep::FUN_1416a1260, 180, 0xA6F4D431);
MS2_REPLACE_METHOD(0x1416a1380, FadeInRenderStep, GetRTTI, 13, 0xDCCC0031);
MS2_REPLACE_METHOD(0x1416a1390, FadeInRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a13a0, FadeInRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1960, GaussianBlurRenderStep, GetRTTI, 13, 0x4DDFA13B);
MS2_REPLACE_METHOD(0x1416a1970, GaussianBlurRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1980, GaussianBlurRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1c20, HeatShimmerRenderStep, GetRTTI, 13, 0xD3A978AE);
MS2_REPLACE_METHOD(0x1416a1c30, HeatShimmerRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1c40, HeatShimmerRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1f00, MonochromeRenderStep, GetRTTI, 13, 0x040ECB35);
MS2_REPLACE_METHOD(0x1416a1f10, MonochromeRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1f20, MonochromeRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a2560, OuterBlurRenderStep, GetRTTI, 13, 0x39AF39D7);
MS2_REPLACE_METHOD(0x1416a2570, OuterBlurRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a2580, OuterBlurRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a2870, OverdrawRenderStep, GetRTTI, 13, 0xBF69E7DA);
MS2_REPLACE_METHOD(0x1416a2e90, PostProcessEffect, GetRTTI, 13, 0xB3E8A894);
MS2_REPLACE_METHOD(0x1416a2ea0, ReloadablePostProcess, GetRTTI, 13, 0xB3E8A894);
MS2_REPLACE_METHOD(0x1416a2eb0, PostProcessEffect, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a2ec0, PostProcessEffect, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a1fe0, MotionBlurRenderStep, vfunc_15, 474, 0x0FD9F210);
MS2_REPLACE_METHOD(0x1416a23f0, PostProcessingService, FUN_1416a23f0, 44, 0x82C749EE);
MS2_REPLACE_METHOD(0x1416a23e0, MotionBlurRenderStep, GetRTTI, 13, 0x065B90E9);
MS2_REPLACE_METHOD(0x1416a2420, MotionBlurRenderStep, vfunc_14, 8, 0x41132FCD);
MS2_REPLACE_METHOD(0x1416a2430, MotionBlurRenderStep, vfunc_13, 8, 0x41132FCD);
MS2_REPLACE(0x1416a4000, PostProcessingService::FUN_1416a4000, 186, 0xAE107199);
MS2_REPLACE(0x1416a40c0, PostProcessingService::FUN_1416a40c0, 69, 0x7797E812);
MS2_REPLACE_METHOD_VIA(0x1416a5f20, PostProcessingService, efd::IBase, OnTick, 461, 0xA6872DF1);
MS2_REPLACE_METHOD_VIA(0x1416a6100, PostProcessingService, efd::IBase, OnShutdown, 1480, 0x1DB3CE6E);
MS2_REPLACE_METHOD(0x1416a69a0, PostProcessingService, FUN_1416a69a0, 989, 0xACC6462D);
MS2_REPLACE(0x1416ac3b0, PostProcessingService::FUN_1416ac3b0, 134, 0xBB51FCFF);
MS2_REPLACE_METHOD(0x1416aa330, PostProcessingService, FUN_1416aa330, 278, 0x5375FBBF);
MS2_REPLACE(0x1416abce0, PostProcessingService::FUN_1416abce0, 55, 0xB834EF06);
MS2_REPLACE(0x1416ac0b0, PostProcessingService::FUN_1416ac0b0, 145, 0xC9CEBAD3);
MS2_REPLACE(0x1416ac150, PostProcessingService::FUN_1416ac150, 130, 0xD664E50E);
MS2_REPLACE(0x1416ac1e0, PostProcessingService::FUN_1416ac1e0, 84, 0x28ED1C8A);
MS2_REPLACE(0x1416abac0, PostProcessingService::FUN_1416abac0, 93, 0xBAD97880);

