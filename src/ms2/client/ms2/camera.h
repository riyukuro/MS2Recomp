// camera.h - the client's gameplay camera: CameraMgr (RTTI .?AVCameraMgr@@, the TSingleton<CameraMgr> camera manager
// that owns the current camera mode, the camera effects and the per-map camera xml), the engine side Camera object it
// hands to every camera mode (RTTI .?AVCamera@@, efd::IBase; the camera mode headers call it Unk_CameraOwner) and the
// camera effects (CCameraEffect, CVibrateCameraEffect). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// owning unit `?\camera.cpp` (0x140ae7940-0x140afd490, .text$di 0x1400c6520-0x1400c6730, dir client\ms2). Header
// name assumed; FUN_<va> names are functions whose purpose is not recovered.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <vector>
#include <efd/IBase.h>
#include <efd/ClassInfo.h>
#include <efd/ReferenceCounting.h>
#include <efd/RefCount.h>
#include <efd/SmartPointer.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>
#include <NiNode.h>
#include <NiCamera.h>
#include <NiFrustumPlanes.h>
#include <NiInterpolator.h>
#include <NiInterpController.h>
#include <NiFOVInterpolator.h>
#include <NiFOVController.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/mapcameradata.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/localtargetcameramode.h"

class GameObject;
class Camera;
class CameraMgr;
class CCameraMoveEffectParam;
class Unk_GoPickListPtr;

// The current field of view of a NiFOVInterpolator (the camera effect nifs animate "Camera01" with a NiFOVController).
class Unk_FOVInterpolator : public NiFOVInterpolator
{
public:
    float FUN_141c2f230() const;                                        // (another obj)
};

// The engine camera object of the camera modes: a reference counted efd::IBase (0x18 bytes, vftable 0x142dd5a70).
class Camera : public efd::IBase
{
    EE_DECLARE_CLASS1(Camera, 0x06200001, efd::IBase);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    Camera();                                                           // 0x140ae7940
    virtual ~Camera();                                                  // 0x140ae79b0

    // @0x140af9b20
    void FUN_140af9b20(int n) { m_c = n; }
    // @0x140af9a50
    void FUN_140af9a50(egf::Entity* pEntity) { m_10 = pEntity; }
    // @0x140af7f60
    egf::Entity* FUN_140af7f60() { return m_10; }
    egf::EntityID FUN_140af7fd0();                                      // the camera entity id (inline, camera.cpp)
    unsigned __int64 FUN_141bfe700();                                   // the camera entity id value (inline: its COMDAT reads
                                                                        // the including TU's kENTITY_INVALID copy; worldservice.cpp)
    void FUN_140a38dc0(Unk_StreamPoint pt);                             // look-at offset (another obj)
    void FUN_140a38e00(Unk_StreamPoint pt);                             // second point property (another obj)

    int m_c;                                                            // +0x0c
    egf::Entity* m_10;                                                  // +0x10 (the camera entity)
};
MS2_CHECK_SIZE(Camera, 0x18);

// A timed camera effect (0x28 bytes, vftable 0x142dd5ce8): vfunc_1 tells whether it is still running at a time.
class CCameraEffect : public CPtred
{
public:
    CCameraEffect(double fStart, double fEnd);                          // 0x140ae9370
    virtual ~CCameraEffect();                                           // 0x140ae93d0
    // Moves the look-at point / up vector of the current mode; false once the effect is over.
    virtual bool vfunc_1(double fTime, Unk_StreamPoint& ptLook, Unk_StreamPoint& ptUp);  // 0x140ae9400

    double m_fStart;                                                    // +0x18
    double m_fEnd;                                                      // +0x20
};
MS2_CHECK_SIZE(CCameraEffect, 0x28);

// The camera shake (0x58 bytes, vftable 0x142dd5d00): a sine of m_fFrequency waves along a random direction that
// flips at every half wave, fading out from m_fFadeStart.
class CVibrateCameraEffect : public CCameraEffect
{
public:
    CVibrateCameraEffect(double fStart, double fEnd, float fFrequency, float fAmplitude, float fMinScale,
        double fFadeStart, int bVertical);                              // 0x140ae9450
    virtual ~CVibrateCameraEffect();                                    // 0x140ae9520
    virtual bool vfunc_1(double fTime, Unk_StreamPoint& ptLook, Unk_StreamPoint& ptUp);  // 0x140ae9550

    float m_fFrequency;                                                 // +0x28
    float m_fAmplitude;                                                 // +0x2c
    float m_fMinScale;                                                  // +0x30
    double m_fFadeStart;                                                // +0x38
    Unk_StreamPoint m_ptDir;                                            // +0x40
    int m_bNegative;                                                    // +0x4c
    int m_bVertical;                                                    // +0x50
};
MS2_CHECK_SIZE(CVibrateCameraEffect, 0x58);

// The fly-by request (0x80 bytes): Unk_FlyByCameraData plus the setting the fly-by returns to. The default ctor
// (0x140947440) belongs to another obj; the copy ctor and the copy assignment are implicit.
struct Unk_CameraFlyBy
{
    Unk_CameraFlyBy();                                                  // 0x140947440

    int m_nKind;                                                        // +0x00
    float m_fDuration;                                                  // +0x04
    Unk_CameraSetting m_from;                                           // +0x08
    Unk_CameraSetting m_to;                                             // +0x30
    Unk_CameraSetting m_return;                                         // +0x58
};
MS2_CHECK_SIZE(Unk_CameraFlyBy, 0x80);

// The camera animation state of the camera manager (+0x1d8, 0x68 bytes): a nif whose "Camera01" moves the camera,
// and the running camera effects.
struct Unk_CameraEffectState
{
    Unk_CameraEffectState();                                            // 0x140af6760

    double m_fStart;                                                    // +0x00
    Unk_StreamPoint m_ptOffset;                                         // +0x08
    double m_fMaxTime;                                                  // +0x18
    float m_20;                                                         // +0x20
    int m_24;                                                           // +0x24
    int m_28;                                                           // +0x28
    NiAVObjectPtr m_spScene;                                            // +0x30
    NiCamera* m_pCamera;                                                // +0x38
    NiNodePtr m_spCameraNode;                                           // +0x40
    NiFOVInterpolatorPtr m_spFOV;                                       // +0x48
    float m_fFOV;                                                       // +0x50
    std::list<MS2Ptr<CCameraEffect>> m_effects;                         // +0x58
};
MS2_CHECK_SIZE(Unk_CameraEffectState, 0x68);

template <class T> class TSingleton;
template <> class TSingleton<CameraMgr>
{
public:
    TSingleton();                                                       // 0x140af5dd0 (inline, camera.cpp)
    virtual ~TSingleton() { s_instance = 0; }                           // 0x140af6a20
    static CameraMgr* s_instance;                                       // 0x143ab3700
    static CameraMgr* GetInstance();                    // 0x1409478c0
};

typedef ATL::CRBMap<egf::Entity*, Unk_CameraSetup> Unk_EntityCameraSetupMap;

// The camera manager (0x330 bytes, vftable 0x142dd6980: the deleting dtor).
class CameraMgr : public TSingleton<CameraMgr>
{
public:
    CameraMgr();                                                        // 0x140ae9b10
    virtual ~CameraMgr();                                               // 0x140ae9db0

    void FUN_140ae9ed0(egf::Entity* pEntity, const Unk_StreamPoint* pLook, const Unk_StreamPoint* pRot);  // init
    void FUN_140aea4c0(float fTime);                                    // per-frame update
    void FUN_140aea7f0();                                               // debug camera keys
    void FUN_140aead90();                                               // release the camera, the modes and effects
    void FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n);         // set the camera target
    BOOL FUN_140aeb070();                                               // activate the camera on the render surface
    // @0x141bfe750
    unsigned __int64 FUN_141bfe750()                                    // the camera entity id value, 0 without a camera
    {
        if (m_pCamera != NULL)
            return m_pCamera->FUN_141bfe700();
        return 0;
    }
    void FUN_140aeb420(int nMode, const Unk_CameraFlyBy* pFlyBy);       // switch mode, keeping the setting
    void FUN_140aeb730(efd::Point3 ptPos);                              // fixed-position camera at a point
    void FUN_140aeb830(int n);
    void FUN_140aeb880(float f1, float f2, float f3);
    void FUN_140aeb900(bool b);
    void FUN_140aeb920();
    void FUN_140aeb540(const egf::EntityID& id, const Unk_CameraSetting& setting);  // save a setting per entity
    bool FUN_140aeb590(Unk_CameraSetting& setting);                     // the first saved setting
    void FUN_140aeb950(CLocalTargetCameraMode* pMode);                  // cycle the map camera setups
    void FUN_140aec0e0(unsigned int nMapId);                            // load the map camera xml
    void FUN_140aebb30(unsigned int nMapId);
    void FUN_140aec4c0();                                               // create the map camera entity
    CString FUN_140af80c0();                                            // the gameplay camera model name
    void FUN_140aeb600();                                               // leave the map: drop the map camera data
    void FUN_140aed580(const Unk_CameraFlyBy* pFlyBy, int nKind, float fDuration);  // start a fly-by
    void FUN_140aed750(int nMode, int bKeep);                           // set the camera mode
    void FUN_140aed1c0();
    void FUN_140aeb1a0();                                               // pick the npc under the cursor (npc control)
    Unk_GoPickListPtr FUN_140af0850(float fX, float fY, bool bFrontOnly, bool bAppCulled, bool bClosestOnly,
        NiAVObject* pRoot);                                             // pick the scene under a window point
    void FUN_140aec8a0(bool bKeep);                                     // apply the map camera data
    void FUN_140aecbb0(int nId, int nTargetId, bool bEnter);            // enter/leave a trigger camera setup
    void FUN_140aece50();                                               // start the setup the target walked into
    int FUN_140a18070();                                                // (another obj)
    Unk_CameraTargetEntity* FUN_140a38d60();                            // the camera target (another obj)
    void FUN_140aefa70();                                               // toggle the target camera lock (game scene)
    Unk_CameraFlyBy FUN_140aeffd0(float fDuration, const Unk_CameraSetting& to);  // a fly-by from the current view
    void FUN_140af1a90();                                               // stop the camera effects
    void FUN_140af1de0();                                               // apply the camera effects
    void FUN_140af1f70();
    void FUN_140aefb20(const struct Unk_CameraPathRow* pRow);            // play a camera path nif
    void FUN_140af0e40(const CCameraMoveEffectParam* pParam);           // play the param's camera nif
    bool FUN_140aed0b0();
    bool FUN_140aed0d0();
    int FUN_140aed0f0();                                                // camera effects enabled
    int FUN_140aed160();
    void FUN_140aed180(const Unk_CameraSetting& setting);               // remember a setting
    void FUN_140aed1e0(const Unk_CameraSetup& setup);                   // local-target mode: blend to a setup
    void FUN_140aed260();                                               // leave the local-target mode
    void FUN_140aed330();                                               // local-target mode: abort the blend
    BOOL FUN_140aed3a0();                                               // in the local-target mode
    bool FUN_140aed3e0();
    BOOL FUN_140aed440(Unk_CameraSetting& setting);                     // the current mode's setting
    bool FUN_140aed4b0();
    void FUN_140aed500(egf::Entity* pEntity, const Unk_CameraSetup& setup);
    void FUN_140aed540(egf::Entity* pEntity);
    float FUN_140af0140();
    void FUN_140af0170(float f, bool b);
    int FUN_140af01d0();                                                // camera control type
    BOOL FUN_140af0210();
    NiPoint3 FUN_140af0250();                                           // camera world direction
    NiPoint3 FUN_140af0340();                                           // camera world up vector
    NiPoint3 FUN_140af0430();                                           // camera world right vector
    bool FUN_140af0520(const NiPoint2& kScreen, NiPoint3& kOrigin, NiPoint3& kDir);  // screen point to ray
    bool FUN_140af05d0(const efd::Point3& kWorld, NiPoint2& kScreen);   // world point to screen pixels
    bool FUN_140af0700(const efd::Point3& kWorld, NiPoint3& kScreen);   // world point to screen pixels and depth
    bool FUN_140af0aa0(const efd::Point3& kPos, float fRadius);         // sphere in the view frustum
    void FUN_140af0b70(int bOn, float f1, float f2);
    void FUN_140af0c10();
    float FUN_140af0c70();
    void FUN_140af0cc0(float f);
    float FUN_140af0d30();
    bool FUN_140af0d80();
    void FUN_140af0de0(MS2Ptr<CCameraEffect> spEffect);                 // add a camera effect
    float FUN_140ad4b40();                                              // current mode: setting m_0 (another obj)
    Unk_StreamPoint FUN_140a17e10();                                    // current mode: setting m_c (another obj)
    void FUN_140ad4ff0(float f);                                        // (another obj)

    // @0x140af2520
    CCameraMode* FUN_140af2520() { return m_spMode.get(); }
    // @0x140af24f0
    CCameraMode* FUN_140af24f0() { return m_spTargetMode.get(); }
    // @0x140af7e30
    int FUN_140af7e30() { if (m_spMode.get()) return m_spMode->vfunc_1(); return 0; }
    // @0x140af7f00
    float FUN_140af7f00() { if (m_spMode.get()) return m_spMode->FUN_140af7ef0(); return 0; }
    // @0x140af7ea0
    float FUN_140af7ea0() { if (m_spMode.get()) return m_spMode->FUN_140af7e90(); return 0; }
    // @0x140af9b40
    void FUN_140af9b40(float f) { if (m_spMode.get()) m_spMode->vfunc_16(f); }
    // @0x140af9870
    void FUN_140af9870(float fDegree) { if (m_spMode.get()) m_spMode->vfunc_12(fDegree); }
    // @0x140af98d0
    void FUN_140af98d0(float fDegree) { if (m_spMode.get()) m_spMode->vfunc_13(fDegree); }
    // @0x140af81a0
    bool FUN_140af81a0() { if (m_spMode.get()) return m_spMode->FUN_140af8140(); return false; }
    // @0x140af8290
    Unk_StreamPoint FUN_140af8290() { if (m_spMode.get()) return m_spMode->FUN_140af8260(); return g_143b01a60; }
    // @0x140aed720
    void FUN_140aed720(const Unk_CameraSetting& setting) { m_setting = setting; }
    // @0x140af7f70
    egf::Entity* FUN_140af7f70() { return (m_pCamera && m_pCamera->FUN_140af7f60()) ? m_pCamera->FUN_140af7f60() : 0; }
    // @0x140af9a70
    void FUN_140af9a70(egf::Entity* pEntity) { if (m_pCamera) m_pCamera->FUN_140af9a50(pEntity); }
    // @0x140af9ab0
    void FUN_140af9ab0(float f1, float f2) { if (m_spMode.get()) m_spMode->vfunc_18(f1, f2); }
    // @0x140af9c10
    void FUN_140af9c10(int n) { m_1ac = n; }
    // @0x140af9930
    void FUN_140af9930(int n) { m_1d0 = n; }
    // @0x140af7be0
    void FUN_140af7be0(int n) { m_244 = n; }
    // 0x140947860 (inline, ?\actioncameramode.cpp obj)
    void FUN_140947860(int n) { m_108 = n; }
    // 0x140947980 (inline, ?\actioncameramode.cpp obj)
    void FUN_140947980(int n) { m_nPendingMode = n; }
    // 0x1409478a0 (inline, ?\actioncameramode.cpp obj)
    Unk_CameraEffectState* FUN_1409478a0() { return &m_effect; }

    int m_bFlyBy;                                                       // +0x08
    Unk_CameraSetting m_setting;                                        // +0x0c
    Unk_CameraFlyBy m_flyBy;                                            // +0x34
    int m_nPendingMode;                                                 // +0xb4
    std::map<egf::EntityID, Unk_CameraSetting> m_savedSettings;         // +0xb8
    Unk_NiPoint3 m_c8;                                                  // +0xc8
    Unk_NiPoint3 m_d4;                                                  // +0xd4
    Unk_CameraSetting m_homeSetting;                                    // +0xe0
    int m_108;                                                          // +0x108
    Camera* m_pCamera;                                                  // +0x110
    MS2Ptr<CCameraMode> m_spMode;                                       // +0x118
    MS2Ptr<CCameraMode> m_spTargetMode;                                 // +0x128
    Unk_StreamPoint m_ptMove;                                           // +0x138
    NiFrustumPlanes m_frustumPlanes;                                    // +0x144
    int m_1a8;                                                          // +0x1a8
    int m_1ac;                                                          // +0x1ac
    int m_1b0;                                                          // +0x1b0
    int m_1b4;                                                          // +0x1b4
    int m_1b8;                                                          // +0x1b8
    Unk_CameraTargetEntity* m_pTarget;                                  // +0x1c0
    efd::SmartPointer<GameObject> m_spTargetObject;                     // +0x1c8
    int m_1d0;                                                          // +0x1d0
    Unk_CameraEffectState m_effect;                                     // +0x1d8
    int m_240;                                                          // +0x240
    int m_244;                                                          // +0x244
    int m_248;                                                          // +0x248
    bool m_24c;                                                         // +0x24c
    Unk_CameraSetting m_savedSetting;                                   // +0x250
    float m_278;                                                        // +0x278
    bool m_27c;                                                         // +0x27c
    std::map<DWORD, std::vector<Unk_CameraSetup>> m_setups;               // +0x280
    std::map<DWORD, DWORD> m_290;                                                 // +0x290
    MS2Ptr<CMapCameraData> m_spMapCameraData;                           // +0x2a0
    Unk_EntityCameraSetupMap m_entitySetups;                            // +0x2b0
    CCacheData m_testCache;                                             // +0x2e0
    CCacheData m_mapCache;                                              // +0x308
};
MS2_CHECK_SIZE(CameraMgr, 0x330);
MS2_CHECK_OFFSET(CameraMgr, m_flyBy, 0x34);
MS2_CHECK_OFFSET(CameraMgr, m_savedSettings, 0xb8);
MS2_CHECK_OFFSET(CameraMgr, m_pCamera, 0x110);
MS2_CHECK_OFFSET(CameraMgr, m_frustumPlanes, 0x144);
MS2_CHECK_OFFSET(CameraMgr, m_spTargetObject, 0x1c8);
MS2_CHECK_OFFSET(CameraMgr, m_effect, 0x1d8);
MS2_CHECK_OFFSET(CameraMgr, m_savedSetting, 0x250);
MS2_CHECK_OFFSET(CameraMgr, m_setups, 0x280);
MS2_CHECK_OFFSET(CameraMgr, m_spMapCameraData, 0x2a0);
MS2_CHECK_OFFSET(CameraMgr, m_entitySetups, 0x2b0);
MS2_CHECK_OFFSET(CameraMgr, m_testCache, 0x2e0);
MS2_CHECK_OFFSET(CameraMgr, m_mapCache, 0x308);
