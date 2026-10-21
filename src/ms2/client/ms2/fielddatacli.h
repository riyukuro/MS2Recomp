// fielddatacli.h - CFieldDataCli (client-side CFieldData, 0x260) and CMinimap (0x98, per-map minimap settings loaded from
// the map's xblock xml). Recovered from ?\fielddatacli.cpp (0x140a54160-0x140a571b0). The CFieldData base (0x160) comes
// from ms2/commonfiles/fielddata.h. Member names are the xml attributes each one is read from (CFieldDataCli::vfunc_1).
#pragma once
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/fieldproperty.h"   // Unk_Vec3f

// 12-byte vector class used for the camera settings. All special members are out of line in the exe.
struct Unk_GVec3 {
    Unk_GVec3();                                    // 0x1405522f0
    Unk_GVec3(float x, float y, float z);           // 0x14097f250
    Unk_GVec3(const Unk_GVec3& o);                  // 0x14027dcf0
    Unk_GVec3& operator=(Unk_GVec3 o);              // 0x14097faa0 (by-value parameter)
    float x, y, z;
};
struct Unk_Rect4 { Unk_Rect4(float l, float r, float t, float b); float l, r, t, b; };   // ctor 0x14097eac0
struct Unk_Frustum { Unk_Frustum(int bOrtho); float l, r, t, b, n, f; bool ortho; char pad[3]; };   // ctor 0x141d2fba0 (28 bytes)

struct Unk_Vec3Cli : Unk_Vec3f { Unk_Vec3Cli(float x, float y, float z); };   // 0x140a56db0 (forwards to Unk_Vec3f)

class CMinimap : public CPtred {
public:
    CMinimap();                                     // 0x140a56c20
    virtual ~CMinimap();                            // 0x140a56e30, sdd 0x140a56ff0
    CString m_strImageName;                         // +0x18 <image name>
    CString m_strImageIcon;                         // +0x20 <image icon>
    Unk_Rect4 m_rcImage;                            // +0x28 <image left right top bottom>
    Unk_Rect4 m_rcScreen;                           // +0x38 <screen ...>
    Unk_Frustum m_frustum;                          // +0x48 <frustum> (ortho flag at +0x60)
    Unk_GVec3 m_vecCamPos;                          // +0x64 <camera position>
    Unk_GVec3 m_vecCamRot;                          // +0x70 <camera rotation>
    float m_fZoomFactor;                            // +0x7c <zoom zoomfactor>
    int m_bVisibleMyPC;                             // +0x80 <visible mypc>
    int m_bVisibleOtherPC;                          // +0x84
    int m_bVisiblePortal;                           // +0x88
    int m_bVisibleNpc;                              // +0x8c
    int m_bLimitScale;                              // +0x90 <limit scale>
    int m_pad94;
};
MS2_CHECK_SIZE(CMinimap, 0x98);

class CFieldDataCli : public CFieldData {
public:
    CFieldDataCli();                                // 0x140a54160
    virtual ~CFieldDataCli();                       // 0x140a54540, sdd 0x140a56fb0
    virtual bool vfunc_1(Unk_140165cf0* node);      // 0x140a55500

    MS2Ptr<CMinimap> m_spMinimap;                   // +0x160
    Unk_GVec3 m_vecDummyTargetPos;                // +0x170 <camera dummyTargetPos>
    Unk_Vec3Cli m_vecUnk17c;                        // +0x17c
    unsigned m_nBgmId;                                   // +0x188 <bgm id>
    unsigned m_nBgmParam;                                // +0x18c
    float m_fBgmValue;                              // +0x190
    unsigned m_nBossBgmId;                               // +0x194
    unsigned m_nBossBgmParam;                            // +0x198
    float m_fBossBgmValue;                          // +0x19c
    CString m_strEnterSystemSound;                  // +0x1a0
    CString m_strBgMask;                            // +0x1a8 <ui bgMask>
    CString m_strBgDay;                             // +0x1b0 <clientProperty bgDay>
    int m_nVScroll;                                 // +0x1b8
    int m_nHScroll;                                 // +0x1bc
    int m_nUseEffLight;                             // +0x1c0
    int m_nFieldName;                               // +0x1c4
    int m_nEffectLOD;                               // +0x1c8
    int m_nInstancingGrid;                          // +0x1cc
    CString m_strMapEffectId;                       // +0x1d0
    bool m_bFastGlow;                               // +0x1d8 <optimize fastglow>
    int m_nFastShimmer;                             // +0x1dc
    int m_nGlobalNameTag;                           // +0x1e0
    int m_nShowHitEffect;                           // +0x1e4
    int m_nApplyCameraOption;                       // +0x1e8
    float m_fCameraExtraDistance;                   // +0x1ec
    bool m_bNoSkipFrame;                            // +0x1f0
    float m_fFov;                                   // +0x1f4 <fov value>
    int m_nUseDummyTarget;                          // +0x1f8 <camera usedummytarget>
    bool m_bUnk1fc;                                 // +0x1fc
    bool m_bFog;                                    // +0x1fd set when the xblock has <fog>
    unsigned m_nFogColor;                           // +0x200
    float m_fFogNear;                               // +0x204
    float m_fFogFar;                                // +0x208
    bool m_bHeightFog;                              // +0x20c
    unsigned m_nHeightFogColor;                     // +0x210
    float m_fHeightFogUpper;                        // +0x214
    float m_fHeightFogLower;                        // +0x218
    float m_fHeightFogPercentage;                   // +0x21c
    bool m_bHdr;                                    // +0x220 set when <hdr> exists
    float m_fHdrThreshold;                          // +0x224
    float m_fHdrOffset;                             // +0x228
    float m_fHdrMiddleGray;                         // +0x22c
    float m_fHdrBloomScale;                         // +0x230
    float m_fHdrGlowScale;                          // +0x234
    bool m_bUnk238;                                 // +0x238
    float m_fCameraDistance;                        // +0x23c
    float m_fCameraVAngle;                          // +0x240
    float m_fZoomOutHeightOffset;                   // +0x244
    float m_fZoomInHeightOffset;                    // +0x248
    bool m_bUseFileSetting;                         // +0x24c
    float m_fShadowIntensity;                       // +0x250
    float m_fShadowSimple;                          // +0x254
    int m_nShadowOptionHighLevel;                   // +0x258
    int m_pad25c;

    bool LoadXBlock();                              // 0x140a56690 (xblock xml: fog/heightfog/clientProperty/minimap)
    static MS2Ptr<CFieldDataCli> Find(int fieldId); // 0x140a55460
};
MS2_CHECK_SIZE(CFieldDataCli, 0x260);
MS2_CHECK_OFFSET(CFieldDataCli, m_spMinimap, 0x160);
MS2_CHECK_OFFSET(CFieldDataCli, m_strEnterSystemSound, 0x1a0);
MS2_CHECK_OFFSET(CFieldDataCli, m_fFov, 0x1f4);
MS2_CHECK_OFFSET(CFieldDataCli, m_bFog, 0x1fd);
MS2_CHECK_OFFSET(CFieldDataCli, m_bHdr, 0x220);
MS2_CHECK_OFFSET(CFieldDataCli, m_nShadowOptionHighLevel, 0x258);
