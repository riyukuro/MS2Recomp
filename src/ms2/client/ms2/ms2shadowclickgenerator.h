// ms2shadowclickgenerator.h - MS2's shadow click generator / validator / visitor (Gamebryo 3.x NiShadow* subclasses).
// MS2ShadowClickGenerator replaces the stock NiDefaultShadowClickGenerator spot/point/directional handlers: it
// gathers the casters through MS2ShadowVisitor into a CAtlList (member +0x118) and frustum-culls them against the
// main camera's planes (member +0xb0). MS2ShadowClickValidator is NiTerrainShadowClickValidator with its own RTTI;
// MS2ShadowVisitor is NiDefaultShadowVisitor that skips the nodes MS2 tags as "no shadow" and builds ATL lists.
// Owning unit: ?\ms2shadowclickgenerator.cpp (0x141508390-0x14150c5e0 .text$mn).
#pragma once
#include "ms2/ms2layout.h"
#include <atlcoll.h>
#include <NiTerrainLibType.h>
#include <NiDefaultShadowClickGenerator.h>
#include <NiDefaultShadowVisitor.h>
#include <NiTerrainShadowClickValidator.h>
#include <NiFrustumPlanes.h>

class NiShadowGenerator;
class NiSpotLight;
class NiPointLight;
class NiDirectionalLight;

typedef CAtlList<NiAVObject*> MS2CasterList;

class MS2ShadowVisitor : public NiDefaultShadowVisitor
{
    NiDeclareRTTI;

public:
    MS2ShadowVisitor();                                                                     // 0x14150bb30
    virtual ~MS2ShadowVisitor();                                                            // 0x14150b5d0, ??_G 0x14150c040
    virtual void PopulateCasterList(NiShadowGenerator* pkGenerator, NiAVObjectRawList& kCasterList,
        bool bIncludeAppCulled = false);                                                    // 0x14150b600

    // ATL-list variants used by MS2ShadowClickGenerator (the engine ones fill NiTPointerList).
    void PopulateCasterListAtl(NiShadowGenerator* pkGenerator, MS2CasterList& kCasterList, bool bIncludeAppCulled);   // 0x14150b7d0
    void PopulateReceiverListAtl(NiShadowGenerator* pkGenerator, MS2CasterList& kReceiverList, bool bIncludeAppCulled); // 0x14150b8f0

    static NiShadowVisitor* CreateMS2ShadowVisitor();                                      // 0x14150ba80

protected:
    virtual bool ShouldProcessNodeChildren(NiNode* pkNode);                                 // 0x14150bfb0
    void AdditiveListHelperAtl(NiNode* pkNode, MS2CasterList* pkObjList, bool bIncludeAppCulled, bool bCastersOnly);   // 0x14150bb70
    void SubtractiveListHelperAtl(NiNode* pkNode, MS2CasterList* pkObjList);                // 0x14150be80
};
MS2_CHECK_SIZE(MS2ShadowVisitor, 8);

class MS2ShadowClickValidator : public NiTerrainShadowClickValidator
{
    NiDeclareRTTI;

public:
    // implicit default ctor (0x14150b160): NiNew T() value-initializes (zero-fills 0x38 bytes) before calling it
    virtual ~MS2ShadowClickValidator();                                                     // 0x14150b1c0, ??_G 0x14150b270
    virtual bool ValidateClick(NiRenderClick* pkRenderClick, unsigned int uiFrameID);       // 0x14150adb0

    static NiShadowClickValidator* CreateMS2ShadowClickValidator();                         // 0x14150b0e0
};
MS2_CHECK_SIZE(MS2ShadowClickValidator, 0x38);

class MS2ShadowClickGenerator : public NiDefaultShadowClickGenerator
{
    NiDeclareRTTI;

public:
    MS2ShadowClickGenerator();                                                              // 0x141508390
    MS2ShadowClickGenerator(NiFixedString kName);                                           // 0x141508430
    virtual ~MS2ShadowClickGenerator();                                                     // 0x14150a5b0, ??_G 0x14150a5f0

protected:
    virtual bool HandleSpotLight(NiShadowGenerator* pkGenerator, NiSpotLight* pkSpotLight,
        bool bRegenerateViews, bool bUpdateShadowMaps);                                     // 0x1415084c0
    virtual bool HandlePointLight(NiShadowGenerator* pkGenerator, NiPointLight* pkPointLight,
        bool bRegenerateViews, bool bUpdateShadowMaps);                                     // 0x141508bd0
    virtual bool HandleDirectionalLight(NiShadowGenerator* pkGenerator, NiDirectionalLight* pkDirLight,
        bool bRegenerateViews, bool bUpdateShadowMaps);                                     // 0x1415095b0

    bool HandleCameraFollowDirectionalLight(NiShadowGenerator* pkGenerator, NiDirectionalLight* pkDirLight,
        bool bRegenerateViews, bool bUpdateShadowMaps);                                     // 0x141509e60
    void UpdateCullPlanes();                                                          // 0x14150a420
    bool IsInCullPlanes(NiAVObject* pkObject);                                          // 0x14150a4c0

    NiFrustumPlanes m_kCullPlanes;    // +0xb0
    MS2CasterList m_kCasterList;            // +0x118 (CAtlList<NiAVObject*>, block size 10)
};
MS2_CHECK_SIZE(MS2ShadowClickGenerator, 0x148);
