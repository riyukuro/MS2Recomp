// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ShadowClickGenerator / MS2ShadowClickValidator /
// MS2ShadowVisitor: Nexon's replacements for the stock Gamebryo shadow click generator, terrain click validator and
// default shadow visitor. The bodies follow the Gamebryo 3.x sources of NiDefaultShadowClickGenerator,
// NiTerrainShadowClickValidator and NiShadowVisitor (engine/gamebryo/.../NiMain); MS2 adds the main-camera frustum
// culling of casters, the camera-following directional light and the ATL caster lists.
// MS2-UNIT: ?\ms2shadowclickgenerator.cpp
// MS2-RANGE: 0x141508390-0x14150c5e0 .text$mn
// MS2-RANGE: 0x1400f94e0-0x1400f9510 .text$di
// MS2-RANGE: 0x1400f96a0-0x1400f9700 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsKindOf@NiObject@@QEBA_NPEBVNiRTTI@@@Z 0x14150b490 ; unique
// MS2-PIN: ?DynamicCast@NiObject@@QEBAPEAV1@PEBVNiRTTI@@@Z 0x14150b330 ; unique
// MS2-PIN: ?GetNearClippingDist@NiShadowGenerator@@QEAAMXZ 0x14150aa60 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAAAEAPEAVNiAVObject@@AEAPEAU__POSITION@@@Z 0x14150aa80 ; unique
// MS2-PIN: ?GetRenderClick@NiShadowCubeMap@@QEBAPEAVNiShadowRenderClick@@E@Z 0x14150ab10 ; unique
// MS2-PIN: ?GetRenderClick@NiShadowMap@@QEBAPEAVNiShadowRenderClick@@XZ 0x14150ab40 ; unique
// MS2-PIN: ?GetScenes@Ni3DRenderView@@QEAAAEAV?$NiTPointerList@V?$SmartPointer@VNiAVObject@@@efd@@@@XZ 0x14150ab60 ; unique
// MS2-PIN: ?GetShadowTechnique@NiShadowGenerator@@QEBAPEAVNiShadowTechnique@@XZ 0x14150ab70 ; unique
// MS2-PIN: ?GetSpotAngle@NiSpotLight@@QEBAMXZ 0x14150ab80 ; unique
// MS2-PIN: ?GetWorldDirection@NiDirectionalLight@@QEBAAEBVNiPoint3@@XZ 0x14150aba0 ; unique
// MS2-PIN: ?GetWorldScale@NiAVObject@@QEBAMXZ 0x14150abc0 ; unique
// MS2-PIN: ?SetAt@?$NiTMapBase@V?$DFALL@M@@PEAVNiDirectionalLight@@MV?$NiTMapHashFunctor@PEAVNiDirectionalLight@@@@V?$NiTMapEqualsFunctor@PEAVNiDirectionalLight@@@@@@QEAAXPEAVNiDirectionalLight@@M@Z 0x14150ac50 ; unique
// MS2-PIN: ?SetFarClippingDist@NiShadowGenerator@@QEAAXM@Z 0x14150ad70 ; unique
// MS2-PIN: ?SetNearClippingDist@NiShadowGenerator@@QEAAXM@Z 0x14150ad90 ; unique
// MS2-PIN: ??1NiRenderClickValidator@@UEAA@XZ 0x14150b1e0 ; prop
// MS2-PIN: ??1NiShadowClickValidator@@UEAA@XZ 0x14150b200 ; unique
// MS2-PIN: ??_GMS2ShadowClickValidator@@UEAAPEAXI@Z 0x14150b270 ; prop
// MS2-PIN: ??_GNiTerrainShadowClickValidator@@UEAAPEAXI@Z 0x14150b2d0 ; prop
// MS2-PIN: ?GetAssignedDynamicEffect@NiShadowGenerator@@QEBAPEAVNiDynamicEffect@@XZ 0x14150b3b0 ; unique
// MS2-PIN: ?GetBit@NiShadowRenderClick@@AEBA_NE@Z 0x14150b3d0 ; unique
// MS2-PIN: ?GetForceRender@NiShadowRenderClick@@QEBA_NXZ 0x14150b410 ; unique
// MS2-PIN: ?GetGenerator@NiShadowRenderClick@@QEBAPEAVNiShadowGenerator@@XZ 0x14150b430 ; unique
// MS2-PIN: ?GetRTTI@MS2ShadowClickValidator@@UEBAPEBVNiRTTI@@XZ 0x14150b450 ; unique
// MS2-PIN: ?GetRTTI@NiTerrainShadowClickValidator@@UEBAPEBVNiRTTI@@XZ 0x14150b460 ; unique
// MS2-PIN: ?GetSubmitModifiers@NiCullingProcess@@QEBA_NXZ 0x14150b470 ; unique
// MS2-PIN: ?MarkAsDirty@NiShadowRenderClick@@QEAAXXZ 0x14150b4f0 ; unique
// MS2-PIN: ?SetBit@NiShadowRenderClick@@AEAAX_NE@Z 0x14150b510 ; unique
// MS2-PIN: ?SetCamera@NiCullingProcess@@QEAAXPEAVNiCamera@@@Z 0x14150b570 ; unique
// MS2-PIN: ?SetSubmitModifiers@NiCullingProcess@@QEAAX_N@Z 0x14150b590 ; unique
// MS2-PIN: ?SetVisibleSet@NiCullingProcess@@QEAAXPEAVNiVisibleArray@@@Z 0x14150b5b0 ; unique
// MS2-PIN: ??_GMS2ShadowVisitor@@UEAAPEAXI@Z 0x14150c040 ; prop
// MS2-PIN: ?GetRTTI@MS2ShadowVisitor@@UEBAPEBVNiRTTI@@XZ 0x14150c220 ; unique
// MS2-PIN: ?GetRTTI@NiDefaultShadowVisitor@@UEBAPEBVNiRTTI@@XZ 0x14150c230 ; unique
// MS2-PIN: ?GetRTTI@NiShadowVisitor@@UEBAPEBVNiRTTI@@XZ 0x14150c240 ; unique
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2shadowclickgenerator.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/nipoint3.h"
#include "cameramode.h"
#include "ms2/placeholder/coptimizer.h"
#include <NiShadowGenerator.h>
#include <NiShadowManager.h>
#include <NiShadowMap.h>
#include <NiShadowCubeMap.h>
#include <NiShadowRenderClick.h>
#include <NiShadowTechnique.h>
#include <NiSpotLight.h>
#include <NiPointLight.h>
#include <NiDirectionalLight.h>
#include <NiRenderedCubeMap.h>
#include <Ni3DRenderView.h>
#include <NiCamera.h>
#include <NiNode.h>
#include <NiRenderer.h>
#include <NiCullingProcess.h>
#include <NiTerrainCullingProcess.h>

// ---- RTTI ----
#ifdef __clang__
static volatile unsigned __int64 s_msZero;
static const NiRTTI* msGenBase() { return (const NiRTTI*)((unsigned __int64)&NiDefaultShadowClickGenerator::ms_RTTI + s_msZero); }
static const NiRTTI* msValBase() { return (const NiRTTI*)((unsigned __int64)&NiTerrainShadowClickValidator::ms_RTTI + s_msZero); }
static const NiRTTI* msVisBase() { return (const NiRTTI*)((unsigned __int64)&NiDefaultShadowVisitor::ms_RTTI + s_msZero); }
#define MS2_GEN_BASE msGenBase()
#define MS2_VAL_BASE msValBase()
#define MS2_VIS_BASE msVisBase()
#else
#define MS2_GEN_BASE (&NiDefaultShadowClickGenerator::ms_RTTI)
#define MS2_VAL_BASE (&NiTerrainShadowClickValidator::ms_RTTI)
#define MS2_VIS_BASE (&NiDefaultShadowVisitor::ms_RTTI)
#endif

// @0x1400f94e0
const NiRTTI MS2ShadowClickGenerator::ms_RTTI("MS2ShadowClickGenerator", MS2_GEN_BASE);
// @0x1400f96a0
const NiRTTI MS2ShadowClickValidator::ms_RTTI("MS2ShadowClickValidator", MS2_VAL_BASE);
// @0x1400f96d0
const NiRTTI MS2ShadowVisitor::ms_RTTI("MS2ShadowVisitor", MS2_VIS_BASE);

// ---- out-of-unit data and helpers ----
extern char DAT_143ae51a8;      // NiFixedString: extra-data name that marks a shadow caster
extern int DAT_143ae2b34;       // 0: casters are found by that extra data, otherwise by the DISPLAY_OBJECT flag
extern char DAT_143ad1588;      // NiRTTI of the model node class (mode at +0x17c, flag byte at +0x131)
extern int DAT_143ae2b44;       // model-node culling enabled
class Unk_AvModeSvc* FUN_1409f7c90();   // C3: was FUN_1409f7c90
unsigned int FUN_141569010(NiAVObject* pkObject);   // the flag-based caster test (out of unit; also used by unit_141567000)

// "is this one of the shadow casters", written out inline at each use (a macro in the source: the exe has no call)
#define MS2_IS_SHADOW_CASTER(pkObject, bResult)                                                           \
    bResult = 0;                                                                                           \
    if (DAT_143ae2b34)                                                                                     \
        bResult = FUN_141569010(pkObject);                                                                 \
    else                                                                                                   \
        bResult = pkObject->GetExtraData(*(const NiFixedString*)&DAT_143ae51a8) != 0

// The model node (derives NiNode, 0x180+ bytes); only the two fields the shadow visitor reads.
class Unk_ShadowModelNode : public NiNode
{
public:
    int FUN_1410444a0() { return m_nMode; }
    bool FUN_14144e250() { return m_bIgnoreShadow; }
private:
    char m_pad_130;
    bool m_bIgnoreShadow;           // +0x131
    char m_pad_132[0x17c - 0x132 - 2 + 2];
    int m_nMode;                    // +0x17c
};

static const unsigned short MS2_FLAG_APP_CULLED = 0x1; // NiAVObject::APP_CULLED_MASK (protected)
static const unsigned short MS2_FLAG_DISPLAY_OBJECT = 0x20; // NiAVObject::DISPLAY_OBJECT_MASK (protected)
static const unsigned int MS2_FLAG_SHADOW_EXCLUDED = 0x100;
static const unsigned short NODE_FLAG_LEAF_GROUP = 0x200;    // NiAVObject::m_uFlags bit: the node is a single caster

// NiAVObject DISPLAY_OBJECT flag (0x20) set? (out-of-line COMDAT of another obj)
// A point temporary viewed as the other point type the callee takes (NiPoint3 <-> Vector3 <-> efd::Point3): cl binds
// the temporary straight to the parameter, as in the exe. clang-cl refuses an rvalue reinterpret_cast, so it goes
// through a helper there.
#ifdef __clang__
template <class U, class T> static const U& Unk_ScPoint(const T& k) { return reinterpret_cast<const U&>(k); }
#define MS2_SC_POINT(U, expr) Unk_ScPoint<U>(expr)
#else
#define MS2_SC_POINT(U, expr) reinterpret_cast<const U&>(expr)
#endif
extern "C" float (__cdecl* __imp_tanf)(float);      // the statically linked CRT tanf goes through the exe's IAT
bool FUN_1409943d0(NiAVObject* pkObject);

// @0x14150c290
static bool IsLeafGroup(NiNode* pkNode)
{
    return pkNode->MS2HasAnyFlag(NODE_FLAG_LEAF_GROUP);
}

// @0x14150baf0 -- registered as a callback (DAT_143afbfc8) that hides an object from the shadow visitors
void MS2ExcludeFromShadows(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() | MS2_FLAG_SHADOW_EXCLUDED;
        pkObject->SetMS2Flags(uiFlags);
    }
}

// The scene root (0x143ab...): holder of the scene camera; both getters are inline COMDATs of other objs.
class Unk_SceneCameraHolder
{
public:
    NiCamera* FUN_140af7df0();
};
class Unk_SceneRoot
{
public:
    static Unk_SceneRoot* FUN_1413f9890();
    Unk_SceneCameraHolder* FUN_140af7da0();
    NiCamera* GetSceneCamera()
    {
        Unk_SceneCameraHolder* pHolder = FUN_140af7da0();
        return pHolder ? pHolder->FUN_140af7df0() : 0;
    }
};

// The camera manager's current mode accepts shadow-follow cameras? (inline of ?\actioncameramode.cpp's obj)
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    bool FUN_140af0d80();
};

// ---- MS2ShadowClickGenerator ----

// @0x141508390
MS2ShadowClickGenerator::MS2ShadowClickGenerator()
    : NiDefaultShadowClickGenerator(NiFixedString(ms_RTTI.GetName())), m_kCasterList(10)
{
}

// @0x141508430
MS2ShadowClickGenerator::MS2ShadowClickGenerator(const NiFixedString& kName)
    : NiDefaultShadowClickGenerator(kName), m_kCasterList(10)
{
}

// 0x14150a5b0: the implicit ~MS2ShadowClickGenerator() (no vftable store at /Od)

// @0x1415084c0
bool MS2ShadowClickGenerator::HandleSpotLight(NiShadowGenerator* pkGenerator, NiSpotLight* pkSpotLight,
    bool bRegenerateViews, bool bUpdateShadowMaps)
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (pkRenderer->GetFrameID() == m_uiLastFrameID)
        return true;

    NiShadowMap* pkShadowMap = ObtainAndAssignShadowMap(pkGenerator, 0, NULL, NiStandardMaterial::LIGHT_SPOT);
    if (!pkShadowMap)
        return false;

    NiShadowRenderClick* pkShadowClick = pkShadowMap->GetRenderClick();
    Ni3DRenderView* pkShadowView = NiDynamicCast(Ni3DRenderView, pkShadowClick->GetRenderViews().GetHead());
    NiCamera* pkShadowCamera = pkShadowView->GetCamera();

    if (bRegenerateViews)
    {
        pkShadowView->GetScenes().RemoveAll();

        NiShadowVisitor* pkShadowVisitor = NiShadowManager::GetShadowVisitor();
        MS2ShadowVisitor* pkVisitor = dynamic_cast<MS2ShadowVisitor*>(pkShadowVisitor);
        if (pkVisitor)
            pkVisitor->PopulateCasterListAtl(pkGenerator, m_kCasterList, false);

        POSITION kPos = m_kCasterList.GetHeadPosition();
        float fNearClippingDist = pkGenerator->GetNearClippingDist();
        float fFarClippingDist = pkGenerator->GetFarClippingDist();

        if (pkGenerator->GetFlags() & NiShadowGenerator::AUTO_CALC_NEARFAR_MASK)
        {
            const NiPoint3& kLightPosition = pkSpotLight->GetWorldTranslate();
            float fMinDistance = 0.0f;
            float fMaxDistance = 0.0f;

            if (kPos)
            {
                NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                pkShadowView->AppendScene(pkGeometry);

                const NiBound& kFirstBound = pkGeometry->GetWorldBound();
                fMinDistance = (kFirstBound.GetCenter() - kLightPosition).Length() - kFirstBound.GetRadius();
                fMaxDistance = (kFirstBound.GetCenter() - kLightPosition).Length() + kFirstBound.GetRadius();

                while (kPos)
                {
                    NiAVObject* pkGeom = m_kCasterList.GetNext(kPos);
                    const NiBound& kBound = pkGeom->GetWorldBound();

                    const float fNearDistance = (kBound.GetCenter() - kLightPosition).Length() - kBound.GetRadius();
                    const float fFarDistance = (kBound.GetCenter() - kLightPosition).Length() + kBound.GetRadius();

                    fMinDistance = NiMin(fMinDistance, fNearDistance);
                    fMaxDistance = NiMax(fMaxDistance, fFarDistance);

                    pkShadowView->AppendScene(pkGeom);
                }

                if (fMinDistance < 1.0f)
                    fMinDistance = 1.0f;
            }

            if (pkGenerator->GetAutoCalcNearClippingDist())
            {
                fNearClippingDist = fMinDistance * 0.85f;
                pkGenerator->SetNearClippingDist(fNearClippingDist);
            }
            if (pkGenerator->GetAutoCalcFarClippingDist())
            {
                fFarClippingDist = fMaxDistance * 1.10f;
                pkGenerator->SetFarClippingDist(fFarClippingDist);
            }
        }
        else
        {
            while (kPos)
            {
                NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                pkShadowView->AppendScene(pkGeometry);
            }
        }

        float fAngle = pkSpotLight->GetSpotAngle();
        fAngle = fAngle * NI_PI / 180.0f;
        float fOffset = __imp_tanf(fAngle);     // the exe calls tanf through its import

        NiFrustum kFrustum(-fOffset, fOffset, fOffset, -fOffset, fNearClippingDist, fFarClippingDist, false);
        pkShadowCamera->SetViewFrustum(kFrustum);
    }

    pkShadowCamera->SetTranslate(pkSpotLight->GetWorldTranslate());
    pkShadowCamera->SetRotate(pkSpotLight->GetWorldRotate());
    pkShadowCamera->SetScale(pkSpotLight->GetWorldScale());
    pkShadowCamera->Update(0.0f);

    pkShadowClick->SetProcessor(NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_SPOT));

    if (bUpdateShadowMaps)
    {
        AddRenderClick(pkShadowClick);

        NiShadowTechnique* pkTechnique = pkGenerator->GetShadowTechnique();
        pkTechnique->PrepareShadowMap(pkShadowMap);
        pkTechnique->AppendPostProcessRenderClicks(pkShadowMap, this);
    }

    pkGenerator->SetRenderViewsDirty(false);
    return true;
}

// @0x141508bd0
bool MS2ShadowClickGenerator::HandlePointLight(NiShadowGenerator* pkGenerator, NiPointLight* pkPointLight,
    bool bRegenerateViews, bool bUpdateShadowMaps)
{
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (pkRenderer->GetFrameID() == m_uiLastFrameID)
        return true;

    NiShadowCubeMap* pkShadowCubeMap = ObtainAndAssignShadowCubeMap(pkGenerator, 0, NULL, NiStandardMaterial::LIGHT_POINT);
    if (!pkShadowCubeMap)
        return false;

    float fNearClippingDist = pkGenerator->GetNearClippingDist();
    float fFarClippingDist = pkGenerator->GetFarClippingDist();

    for (unsigned int uiFace = 0; uiFace < 6; uiFace++)
    {
        NiShadowRenderClick* pkShadowClick = pkShadowCubeMap->GetRenderClick((unsigned char)uiFace);
        Ni3DRenderView* pkShadowView = NiDynamicCast(Ni3DRenderView, pkShadowClick->GetRenderViews().GetHead());
        NiCamera* pkShadowCamera = pkShadowView->GetCamera();

        if (bRegenerateViews)
        {
            pkShadowClick->SetBackgroundColor(NiColorA(0, 0, 0, 0));
            pkShadowView->GetScenes().RemoveAll();

            NiShadowVisitor* pkShadowVisitor = NiShadowManager::GetShadowVisitor();
        MS2ShadowVisitor* pkVisitor = dynamic_cast<MS2ShadowVisitor*>(pkShadowVisitor);
            if (pkVisitor)
                pkVisitor->PopulateCasterListAtl(pkGenerator, m_kCasterList, false);

            POSITION kPos = m_kCasterList.GetHeadPosition();

            if (pkGenerator->GetFlags() & NiShadowGenerator::AUTO_CALC_NEARFAR_MASK)
            {
                const NiPoint3& kLightPosition = pkPointLight->GetWorldTranslate();
                float fMaxDistance = 0.0f;

                if (kPos)
                {
                    NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                    pkShadowView->AppendScene(pkGeometry);

                    const NiBound& kFirstBound = pkGeometry->GetWorldBound();
                    fMaxDistance = (kFirstBound.GetCenter() - kLightPosition).Length() + kFirstBound.GetRadius();

                    while (kPos)
                    {
                        pkGeometry = m_kCasterList.GetNext(kPos);
                        const NiBound& kBound = pkGeometry->GetWorldBound();
                        float fFarDistance = (kBound.GetCenter() - kLightPosition).Length() + kBound.GetRadius();
                        fMaxDistance = NiMax(fFarDistance, fMaxDistance);
                        pkShadowView->AppendScene(pkGeometry);
                    }
                }

                if (uiFace == 0)
                {
                    if (pkGenerator->GetAutoCalcNearClippingDist())
                        fNearClippingDist = 1.0f;
                    if (pkGenerator->GetAutoCalcFarClippingDist())
                        fFarClippingDist = fMaxDistance * 1.10f;
                }
                else
                {
                    if (pkGenerator->GetAutoCalcFarClippingDist())
                        fFarClippingDist = NiMax(fFarClippingDist, 1.10f * fMaxDistance);
                }
            }
            else
            {
                while (kPos)
                {
                    NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                    pkShadowView->AppendScene(pkGeometry);
                }
            }
        }

        pkShadowCamera->SetTranslate(pkPointLight->GetWorldTranslate());
        pkShadowCamera->Update(0.0f);

        NiPoint3 kLookAtPoint = pkPointLight->GetWorldTranslate();
        NiPoint3 kUp;

        switch ((NiRenderedCubeMap::FaceID)uiFace)
        {
        case NiRenderedCubeMap::FACE_POS_X:
            kLookAtPoint += NiPoint3(1, 0, 0);
            kUp = NiPoint3(0, 1, 0);
            break;
        case NiRenderedCubeMap::FACE_NEG_X:
            kLookAtPoint += NiPoint3(-1, 0, 0);
            kUp = NiPoint3(0, 1, 0);
            break;
        case NiRenderedCubeMap::FACE_POS_Y:
            kLookAtPoint += NiPoint3(0, 1, 0);
            kUp = NiPoint3(0, 0, 1);
            break;
        case NiRenderedCubeMap::FACE_NEG_Y:
            kLookAtPoint += NiPoint3(0, -1, 0);
            kUp = NiPoint3(0, 0, -1);
            break;
        case NiRenderedCubeMap::FACE_POS_Z:
            kLookAtPoint += NiPoint3(0, 0, -1);
            kUp = NiPoint3(0, 1, 0);
            break;
        case NiRenderedCubeMap::FACE_NEG_Z:
            kLookAtPoint += NiPoint3(0, 0, 1);
            kUp = NiPoint3(0, 1, 0);
            break;
        }

        pkShadowCamera->LookAtWorldPoint(kLookAtPoint, kUp);
        pkShadowCamera->SetScale(pkPointLight->GetWorldScale());
        pkShadowCamera->Update(0.0f);

        pkShadowClick->SetProcessor(NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_POINT));

        if (bUpdateShadowMaps)
            AddRenderClick(pkShadowClick);
    }

    if (bRegenerateViews)
    {
        if (pkGenerator->GetAutoCalcNearClippingDist())
            pkGenerator->SetNearClippingDist(fNearClippingDist);
        if (pkGenerator->GetAutoCalcFarClippingDist())
            pkGenerator->SetFarClippingDist(fFarClippingDist);

        for (unsigned int uiFace = 0; uiFace < 6; uiFace++)
        {
            NiShadowRenderClick* pkShadowClick = pkShadowCubeMap->GetRenderClick((unsigned char)uiFace);
            Ni3DRenderView* pkShadowView = NiDynamicCast(Ni3DRenderView, pkShadowClick->GetRenderViews().GetHead());
            NiCamera* pkShadowCamera = pkShadowView->GetCamera();

            NiFrustum kFrustum(-1.0f, 1.0f, 1.0f, -1.0f, fNearClippingDist, fFarClippingDist, false);
            pkShadowCamera->SetViewFrustum(kFrustum);
        }
    }

    if (bUpdateShadowMaps)
    {
        NiShadowTechnique* pkTechnique = pkGenerator->GetShadowTechnique();
        pkTechnique->PrepareShadowMap(pkShadowCubeMap);
        pkTechnique->AppendPostProcessRenderClicks(pkShadowCubeMap, this);
    }

    pkGenerator->SetRenderViewsDirty(false);
    return true;
}

// @0x1415095b0
bool MS2ShadowClickGenerator::HandleDirectionalLight(NiShadowGenerator* pkGenerator, NiDirectionalLight* pkDirLight,
    bool bRegenerateViews, bool bUpdateShadowMaps)
{
    NiShadowMap* pkShadowMap = ObtainAndAssignShadowMap(pkGenerator, 0, NULL, NiStandardMaterial::LIGHT_DIR);
    if (!pkShadowMap)
        return false;

    // With a camera target and a following camera mode the shadow camera tracks the player.
    if (Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60() != 0 &&
        !((class CameraMgr*)(class Unk_CameraManager*)(Unk_CameraManager::FUN_1409478c0()))->FUN_140af0d80())
        return HandleCameraFollowDirectionalLight(pkGenerator, pkDirLight, bRegenerateViews, bUpdateShadowMaps);

    NiShadowRenderClick* pkShadowClick = pkShadowMap->GetRenderClick();
    Ni3DRenderView* pkShadowView = NiDynamicCast(Ni3DRenderView, pkShadowClick->GetRenderViews().GetHead());
    NiCamera* pkShadowCamera = pkShadowView->GetCamera();

    UpdateCullPlanes();

    if (bRegenerateViews)
    {
        pkShadowView->GetScenes().RemoveAll();

        NiShadowVisitor* pkShadowVisitor = NiShadowManager::GetShadowVisitor();
        MS2ShadowVisitor* pkVisitor = dynamic_cast<MS2ShadowVisitor*>(pkShadowVisitor);
        if (pkVisitor)
            pkVisitor->PopulateCasterListAtl(pkGenerator, m_kCasterList, false);

        POSITION kPos = m_kCasterList.GetHeadPosition();
        NiPoint3 kCameraPos;
        float fNearClippingDist = pkGenerator->GetNearClippingDist();
        float fFarClippingDist = pkGenerator->GetFarClippingDist();
        float fDirLightFrustumWidth = pkGenerator->GetDirLightFrusturmWidth();

        if (pkGenerator->GetFlags() & NiShadowGenerator::AUTO_CALC_FULL_MASK)
        {
            NiBound kBound;
            bool bFirst = true;
            while (kPos)
            {
                NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                if (IsInCullPlanes(pkGeometry))
                {
                    if (bFirst)
                    {
                        kBound = pkGeometry->GetWorldBound();
                        bFirst = false;
                    }
                    else
                    {
                        kBound.Merge(&pkGeometry->GetWorldBound());
                    }
                    pkShadowView->AppendScene(pkGeometry);
                }
            }

            UpdateDirLightFrustum(&kBound, pkGenerator, pkDirLight, &fNearClippingDist, &fFarClippingDist,
                &fDirLightFrustumWidth, &kCameraPos);
        }
        else
        {
            while (kPos)
            {
                NiAVObject* pkGeometry = m_kCasterList.GetNext(kPos);
                pkShadowView->AppendScene(pkGeometry);
            }
            kCameraPos = pkDirLight->GetWorldTranslate();
        }

        NiFrustum kFrustum(-fDirLightFrustumWidth, fDirLightFrustumWidth, fDirLightFrustumWidth,
            -fDirLightFrustumWidth, fNearClippingDist, fFarClippingDist, true);
        pkShadowCamera->SetViewFrustum(kFrustum);
        pkShadowCamera->SetTranslate(kCameraPos);
    }

    else
    {
        if (pkGenerator->GetFlags() & NiShadowGenerator::AUTO_CALC_FULL_MASK)
        {
            const float fEpsilon = 1e-06f;
            float fPackedOldDirection = 0;
            float fPackedCurrentDirection =
                (pkDirLight->GetWorldDirection().x * 3) +
                (pkDirLight->GetWorldDirection().y * 2) +
                (pkDirLight->GetWorldDirection().z * 0.5f);

            if (!m_kDirLightMap.GetAt(pkDirLight, fPackedOldDirection) ||
                NiAbs(fPackedOldDirection - fPackedCurrentDirection) > fEpsilon)
            {
                m_kDirLightMap.SetAt(pkDirLight, fPackedCurrentDirection);

                NiBound kBound;
                NiPoint3 kCameraPos;
                float fNearClippingDist = pkGenerator->GetNearClippingDist();
                float fFarClippingDist = pkGenerator->GetFarClippingDist();
                float fDirLightFrustumWidth = pkGenerator->GetDirLightFrusturmWidth();

                NiTPointerList<NiAVObjectPtr>& kScenes = pkShadowView->GetScenes();
                NiTListIterator kIter = kScenes.GetHeadPos();
                bool bFirst = true;
                while (kIter)
                {
                    NiAVObjectPtr spObject = kScenes.GetNext(kIter);
                    if (IsInCullPlanes(spObject))
                    {
                        if (bFirst)
                        {
                            kBound = spObject->GetWorldBound();
                            bFirst = false;
                        }
                        else
                        {
                            kBound.Merge(&spObject->GetWorldBound());
                        }
                    }
                }

                UpdateDirLightFrustum(&kBound, pkGenerator, pkDirLight, &fNearClippingDist, &fFarClippingDist,
                    &fDirLightFrustumWidth, &kCameraPos);

                NiFrustum kFrustum(-fDirLightFrustumWidth, fDirLightFrustumWidth, fDirLightFrustumWidth,
                    -fDirLightFrustumWidth, fNearClippingDist, fFarClippingDist, true);
                pkShadowCamera->SetViewFrustum(kFrustum);
                pkShadowCamera->SetTranslate(kCameraPos);
            }
        }
        else
        {
            pkShadowCamera->SetTranslate(pkDirLight->GetWorldTranslate());
        }
    }
    pkShadowCamera->SetRotate(pkDirLight->GetWorldRotate());
    pkShadowCamera->SetScale(pkDirLight->GetWorldScale());
    pkShadowCamera->Update(0.0f);

    pkShadowClick->SetProcessor(NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_DIR));

    if (bUpdateShadowMaps)
    {
        AddRenderClick(pkShadowClick);

        NiShadowTechnique* pkTechnique = pkGenerator->GetShadowTechnique();
        pkTechnique->PrepareShadowMap(pkShadowMap);
        pkTechnique->AppendPostProcessRenderClicks(pkShadowMap, this);
    }

    pkGenerator->SetRenderViewsDirty(false);
    return true;
}

// @0x141509e60
bool MS2ShadowClickGenerator::HandleCameraFollowDirectionalLight(NiShadowGenerator* pkGenerator,
    NiDirectionalLight* pkDirLight, bool bRegenerateViews, bool bUpdateShadowMaps)
{
    NiShadowMap* pkShadowMap = ObtainAndAssignShadowMap(pkGenerator, 0, NULL, NiStandardMaterial::LIGHT_DIR);
    if (!pkShadowMap)
        return false;

    NiShadowRenderClick* pkShadowClick = pkShadowMap->GetRenderClick();
    Ni3DRenderView* pkShadowView = NiDynamicCast(Ni3DRenderView, pkShadowClick->GetRenderViews().GetHead());
    NiCamera* pkShadowCamera = pkShadowView->GetCamera();

    float fNear = 1.0f;
    float fFar = 25000.0f;
    float fHalfSize = 2000.0f;

    // The shadow camera hovers 10000 units against the light direction over the camera target, pushed 1500 units
    // along the scene camera's direction flattened onto the ground plane (z dropped, not renormalized).
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    NiPoint3 kCameraPos(MS2_SC_POINT(efd::Point3,
        pTarget->vfunc_18().FUN_140965c40(MS2_SC_POINT(Vector3, pkDirLight->GetWorldDirection() * 10000.0f))));
    Unk_SceneCameraHolder* pHolder = Unk_SceneRoot::FUN_1413f9890()->FUN_140af7da0();
    if (pHolder)
    {
        NiCamera* pkSceneCamera = pHolder->FUN_140af7df0();
        if (pkSceneCamera)
        {
            NiPoint3 kViewDir = pkSceneCamera->GetWorldDirection();
            kViewDir.z = 0.0f;
            kCameraPos += kViewDir * 1500.0f;
        }
    }

    NiFrustum kFrustum(-fHalfSize, fHalfSize, fHalfSize, -fHalfSize, fNear, fFar, true);
    pkShadowCamera->SetViewFrustum(kFrustum);
    pkShadowCamera->SetTranslate(kCameraPos);

    // Spin the light's world rotation by 45 degrees around the light direction.
    NiMatrix3 kRotation = pkDirLight->GetWorldRotate();
    NiMatrix3 kSpin;
    kSpin.MakeRotation(0.78539819f, pkDirLight->GetWorldDirection());
    kRotation = kSpin * kRotation;
    pkShadowCamera->SetRotate(kRotation);
    pkShadowCamera->SetScale(pkDirLight->GetWorldScale());
    pkShadowCamera->Update(0.0f);

    m_kCullPlanes.Set(kFrustum, pkShadowCamera->GetWorldTransform());
    m_kCullPlanes.EnableAllPlanes();

    if (bRegenerateViews)
    {
        NiShadowVisitor* pkShadowVisitor = NiShadowManager::GetShadowVisitor();
        MS2ShadowVisitor* pkVisitor = dynamic_cast<MS2ShadowVisitor*>(pkShadowVisitor);
        if (pkVisitor)
            pkVisitor->PopulateCasterListAtl(pkGenerator, m_kCasterList, false);
    }

    pkShadowView->GetScenes().RemoveAll();
    for (POSITION kPos = m_kCasterList.GetHeadPosition(); kPos; m_kCasterList.GetNext(kPos))
    {
        NiAVObject* pkObject = m_kCasterList.GetAt(kPos);
        if (IsInCullPlanes(pkObject))
            pkShadowView->AppendScene(pkObject);
    }

    pkShadowClick->SetProcessor(NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_DIR));

    if (bUpdateShadowMaps)
    {
        AddRenderClick(pkShadowClick);

        NiShadowTechnique* pkTechnique = pkGenerator->GetShadowTechnique();
        pkTechnique->PrepareShadowMap(pkShadowMap);
        pkTechnique->AppendPostProcessRenderClicks(pkShadowMap, this);
    }

    pkGenerator->SetRenderViewsDirty(false);
    return true;
}

// @0x14150a420
void MS2ShadowClickGenerator::UpdateCullPlanes()
{
    Unk_SceneCameraHolder* pHolder = Unk_SceneRoot::FUN_1413f9890()->FUN_140af7da0();
    if (pHolder == 0)
        return;
    NiCamera* pkCamera = pHolder->FUN_140af7df0();
    if (pkCamera == 0)
        return;
    m_kCullPlanes.Set(pkCamera->GetViewFrustum(), pkCamera->GetWorldTransform());
    m_kCullPlanes.EnableAllPlanes();
}

// @0x14150a4c0
bool MS2ShadowClickGenerator::IsInCullPlanes(NiAVObject* pkObject)
{
    NiPoint3 kCenter = pkObject->GetWorldBound().GetCenter();
    float fRadius = pkObject->GetWorldBound().GetRadius();

    unsigned int uiPlane;
    for (uiPlane = 0; uiPlane < NiFrustumPlanes::MAX_PLANES; uiPlane++)
    {
        if (m_kCullPlanes.IsPlaneActive(uiPlane))
        {
            float fDistance = m_kCullPlanes.GetPlane(uiPlane).Distance(kCenter);
            if (fDistance <= -fRadius - 2000.0f)
                break;
        }
    }
    if (uiPlane == NiFrustumPlanes::MAX_PLANES)
        return true;
    return false;
}

// ---- MS2ShadowClickValidator ----

// 0x14150b160: the implicit MS2ShadowClickValidator() ctor (COMDAT emitted by CreateMS2ShadowClickValidator)

// 0x14150b1c0: the implicit ~MS2ShadowClickValidator() (no vftable store at /Od)

// @0x14150b0e0
NiShadowClickValidator* MS2ShadowClickValidator::CreateMS2ShadowClickValidator()
{
    return NiNew MS2ShadowClickValidator();
}

// @0x14150adb0
bool MS2ShadowClickValidator::ValidateClick(NiRenderClick* pkRenderClick, unsigned int uiFrameID)
{
    EE_UNUSED_ARG(uiFrameID);

    NiShadowRenderClick* pkShadowClick = NiDynamicCast(NiShadowRenderClick, pkRenderClick);
    if (!pkShadowClick)
        return true;
    else if (pkShadowClick->GetForceRender())
    {
        pkShadowClick->MarkAsDirty();
        return true;
    }

    if (!m_spCamera || !m_spCullingProcess)
    {
        pkShadowClick->MarkAsDirty();
        return true;
    }

    bool bOldSubmitModifiers = m_spCullingProcess->GetSubmitModifiers();
    m_spCullingProcess->SetSubmitModifiers(false);

    m_kVisibleSet.RemoveAll();

    NiShadowGenerator* pkGenerator = pkShadowClick->GetGenerator();

    NiTerrainCullingProcess* pkTerrainCullingProcess = NiDynamicCast(NiTerrainCullingProcess, m_spCullingProcess);
    if (pkTerrainCullingProcess)
        pkTerrainCullingProcess->SetUpdateGeometry(false);

    NiDynamicEffect* pkDynEffect = pkGenerator->GetAssignedDynamicEffect();

    m_spCullingProcess->SetCamera(m_spCamera);
    m_spCullingProcess->SetFrustum(m_spCamera->GetViewFrustum());
    m_spCullingProcess->SetVisibleSet(&m_kVisibleSet);

    bool bRetVal = false;

    const NiTPointerMap<NiNode*, NiNode*>& kReceivers = pkDynEffect->GetAffectedNodeList();
    NiTMapIterator kMapIter = kReceivers.GetFirstPos();
    while (kMapIter)
    {
        NiNode* pkReceiver = NULL;
        kReceivers.GetNext(kMapIter, pkReceiver, pkReceiver);
        m_spCullingProcess->Cull(m_spCamera, pkReceiver, &m_kVisibleSet);
        if (m_kVisibleSet.GetCount() > 0)
        {
            pkShadowClick->MarkAsDirty();
            bRetVal = true;
            break;
        }
    }

    if (pkTerrainCullingProcess)
        pkTerrainCullingProcess->SetUpdateGeometry(true);

    m_spCullingProcess->SetSubmitModifiers(bOldSubmitModifiers);
    return bRetVal;
}

// ---- MS2ShadowVisitor ----

// @0x14150bb30
MS2ShadowVisitor::MS2ShadowVisitor()
{
}

// @0x14150b5d0
MS2ShadowVisitor::~MS2ShadowVisitor()
{
}

// @0x14150ba80
NiShadowVisitor* MS2ShadowVisitor::CreateMS2ShadowVisitor()
{
    return NiNew MS2ShadowVisitor();
}

// @0x14150bfb0
bool MS2ShadowVisitor::ShouldProcessNodeChildren(NiNode* pkNode)
{
    if (IsLeafGroup(pkNode))
        return false;
    return true;
}

// @0x14150b600
void MS2ShadowVisitor::PopulateCasterList(NiShadowGenerator* pkGenerator, NiAVObjectRawList& kCasterList,
    bool bIncludeAppCulled)
{
    kCasterList.RemoveAll();

    NiDynamicEffect* pkDynEffect = pkGenerator->GetAssignedDynamicEffect();
    if (pkDynEffect == 0)
        return;

    const NiTPointerMap<NiNode*, NiNode*>& kAffectedNodeList = pkDynEffect->GetAffectedNodeList();
    NiTListIterator kIter;
    NiTMapIterator kMapIter = kAffectedNodeList.GetFirstPos();
    while (kMapIter)
    {
        NiNode* pkNode = NULL;
        kAffectedNodeList.GetNext(kMapIter, pkNode, pkNode);
        AdditiveListHelper(pkNode, &kCasterList, bIncludeAppCulled);
    }

    const NiNodeList& kUnaffectedNodeList = pkDynEffect->GetUnaffectedNodeList();
    kIter = kUnaffectedNodeList.GetHeadPos();
    while (kIter)
    {
        NiNode* pkNode = kUnaffectedNodeList.GetNext(kIter);
        SubtractiveListHelper(pkNode, &kCasterList);
    }

    // Drop everything that is not a shadow caster.
    kIter = kCasterList.GetHeadPos();
    while (kIter)
    {
        NiTListIterator kCurrent = kIter;
        NiAVObject* pkObject = kCasterList.GetNext(kIter);
        unsigned int bCaster;
        MS2_IS_SHADOW_CASTER(pkObject, bCaster);
        if (!bCaster)
            kCasterList.RemovePos(kCurrent);
    }
}

// @0x14150b7d0
void MS2ShadowVisitor::PopulateCasterListAtl(NiShadowGenerator* pkGenerator, MS2CasterList& kCasterList,
    bool bIncludeAppCulled)
{
    kCasterList.RemoveAll();

    NiDynamicEffect* pkDynEffect = pkGenerator->GetAssignedDynamicEffect();
    if (pkDynEffect == 0)
        return;

    const NiTPointerMap<NiNode*, NiNode*>& kAffectedNodeList = pkDynEffect->GetAffectedNodeList();
    NiTListIterator kIter;
    NiTMapIterator kMapIter = kAffectedNodeList.GetFirstPos();
    while (kMapIter)
    {
        NiNode* pkNode = NULL;
        kAffectedNodeList.GetNext(kMapIter, pkNode, pkNode);
        AdditiveListHelperAtl(pkNode, &kCasterList, bIncludeAppCulled, true);
    }

    const NiNodeList& kUnaffectedNodeList = pkDynEffect->GetUnaffectedNodeList();
    kIter = kUnaffectedNodeList.GetHeadPos();
    while (kIter)
    {
        NiNode* pkNode = kUnaffectedNodeList.GetNext(kIter);
        SubtractiveListHelperAtl(pkNode, &kCasterList);
    }
}

// @0x14150b8f0
void MS2ShadowVisitor::PopulateReceiverListAtl(NiShadowGenerator* pkGenerator, MS2CasterList& kReceiverList,
    bool bIncludeAppCulled)
{
    kReceiverList.RemoveAll();

    NiDynamicEffect* pkDynEffect = pkGenerator->GetAssignedDynamicEffect();
    if (pkDynEffect == 0)
        return;

    const NiTPointerMap<NiNode*, NiNode*>& kAffectedNodeList = pkDynEffect->GetAffectedNodeList();
    NiTListIterator kIter;
    NiTMapIterator kMapIter = kAffectedNodeList.GetFirstPos();
    while (kMapIter)
    {
        NiNode* pkNode = NULL;
        kAffectedNodeList.GetNext(kMapIter, pkNode, pkNode);
        AdditiveListHelperAtl(pkNode, &kReceiverList, bIncludeAppCulled, false);
    }

    const NiNodeList& kUnaffectedNodeList = pkDynEffect->GetUnaffectedNodeList();
    kIter = kUnaffectedNodeList.GetHeadPos();
    while (kIter)
    {
        NiNode* pkNode = kUnaffectedNodeList.GetNext(kIter);
        SubtractiveListHelperAtl(pkNode, &kReceiverList);
    }

    const NiTPrimitiveSet<NiNode*>& kUnaffectedReceivers = pkGenerator->GetUnaffectedReceiverNodeList();
    for (unsigned int ui = 0; ui < kUnaffectedReceivers.GetSize(); ui++)
    {
        NiNode* pkNode = kUnaffectedReceivers.GetAt(ui);
        SubtractiveListHelperAtl(pkNode, &kReceiverList);
    }
}

// @0x14150bb70
void MS2ShadowVisitor::AdditiveListHelperAtl(NiNode* pkNode, MS2CasterList* pkObjList, bool bIncludeAppCulled,
    bool bCastersOnly)
{
    if (pkNode && (pkNode->GetMS2Flags() & MS2_FLAG_SHADOW_EXCLUDED) == 0)
    {
        Unk_ShadowModelNode* pkModel;
        if (((class COptimizer*)FUN_1409f7c90())->IsModelCullingOn() &&
            (pkModel = (Unk_ShadowModelNode*)NiObject::DynamicCast((const NiRTTI*)&DAT_143ad1588, pkNode)) != 0 &&
            pkModel->FUN_1410444a0() == 1 && !pkModel->FUN_14144e250())
            return;

        if (bIncludeAppCulled || !pkNode->GetAppCulled())
        {
            if (IsLeafGroup(pkNode))
            {
                if (bCastersOnly)
                {
                    unsigned int bCaster;
                    MS2_IS_SHADOW_CASTER(pkNode, bCaster);
                    if (bCaster)
                        pkObjList->AddTail(pkNode);
                }
                else
                {
                    pkObjList->AddTail(pkNode);
                }
                return;
            }
        }
        else
        {
            return;
        }

        unsigned int uiChildCount = pkNode->GetArrayCount();
        for (unsigned int i = 0; i < uiChildCount; i++)
        {
            NiAVObject* pkChild = pkNode->GetAt(i);
            if (pkChild)
            {
                if (FUN_1409943d0(pkChild) && (bIncludeAppCulled || !pkChild->GetAppCulled()))
                {
                    if (bCastersOnly)
                    {
                        unsigned int bCaster;
                        MS2_IS_SHADOW_CASTER(pkChild, bCaster);
                        if (bCaster)
                        {
                            NiAVObject* pkCaster = pkChild;
                            pkObjList->AddTail(pkCaster);
                        }
                    }
                    else
                    {
                        NiAVObject* pkReceiver = pkChild;
                        pkObjList->AddTail(pkReceiver);
                    }
                }
                else if (pkChild->IsNode())
                {
                    AdditiveListHelperAtl((NiNode*)pkChild, pkObjList, bIncludeAppCulled, bCastersOnly);
                }
            }
        }
    }
}

// @0x14150be80
void MS2ShadowVisitor::SubtractiveListHelperAtl(NiNode* pkNode, MS2CasterList* pkObjList)
{
    if (pkNode == 0)
        return;

    if (IsLeafGroup(pkNode))
    {
        NiAVObject* pkKey = pkNode;
        POSITION kPos = pkObjList->Find(pkKey);
        if (kPos)
            pkObjList->RemoveAt(kPos);
    }

    unsigned int uiChildCount = pkNode->GetArrayCount();
    for (unsigned int i = 0; i < uiChildCount; i++)
    {
        NiAVObject* pkChild = pkNode->GetAt(i);
        if (pkChild)
        {
            if (FUN_1409943d0(pkChild))
            {
                POSITION kPos = pkObjList->Find(pkChild);
                if (kPos)
                    pkObjList->RemoveAt(kPos);
            }
            else if (pkChild->IsNode())
            {
                SubtractiveListHelperAtl((NiNode*)pkChild, pkObjList);
            }
        }
    }
}

// Shared header statics of this TU (.text$di between the generator RTTI and the validator/visitor RTTIs, plus their
// atexit thunks; gap2 orphan di sweep). The fourth initializer is egf::kENTITY_INVALID (<egf/EntityID.h>).
// MS2-RANGE: 0x1400f9510-0x1400f96a0 .text$di
// MS2-RANGE: 0x142cb3230-0x142cb32c0 .text$yd
#include <egf/EntityID.h>
#include "ms2/placeholder/header_statics_a.h"

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x14150c290, IsLeafGroup, 28, 0x9B39B78E);
MS2_REPLACE(0x14150baf0, MS2ExcludeFromShadows, 54, 0x1C4DF93D);
MS2_REPLACE_METHOD(0x14150adb0, MS2ShadowClickValidator, ValidateClick, 793, 0xEAA0387D);
MS2_REPLACE_METHOD(0x14150b600, MS2ShadowVisitor, PopulateCasterList, 454, 0x03CFC609);
MS2_REPLACE_METHOD(0x14150b7d0, MS2ShadowVisitor, PopulateCasterListAtl, 276, 0xA39666FB);
MS2_REPLACE_METHOD(0x14150b8f0, MS2ShadowVisitor, PopulateReceiverListAtl, 386, 0x5D4F4B6C);

// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400f9630
