// bonerotateinterpolator.h - BoneRotateInterpolator (RTTI "BoneRotateInterpolator" 0x143ab5d68, 0x178 bytes,
// NiTransformInterpolator) and CBoneRotateManager (RTTI name, 0x220 bytes, CPtred): the head-look system. The manager owns
// one interpolator for a character's look-at bone ("Bip01 Head"), a map of look-at actions (mode -> action) and the timers
// that start/stop a look; the interpolator turns the bone toward the target with yaw/pitch limits and blends back to the
// animation. Owning unit: client\ms2\bonerotateinterpolator.cpp. Header name assumed from the unit path; member names are
// invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiTransformInterpolator.h>
#include <NiAVObject.h>
#include <egf/EntityID.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class GameObject;

// One look-at behaviour held by the manager (CPtred-derived, polymorphic). Slots 1..3 and 6 are the ones the manager calls;
// the class is defined elsewhere, so this is a call-only view (name invented).
class Unk_BrAction : public CPtred
{
public:
    virtual bool vfunc_1(int nOwnerId, int nTargetId, int nParam);     // +0x08 start (false = could not start)
    virtual void vfunc_2();                                             // +0x10 stop
    virtual bool vfunc_3();                                             // +0x18 may be started now
    virtual void vfunc_4();                                             // +0x20
    virtual void vfunc_5();                                             // +0x28
    virtual void vfunc_6(void* pArg);                                   // +0x30 per-frame update
};

class BoneRotateInterpolator : public NiTransformInterpolator
{
    NiDeclareRTTI;                                              // GetRTTI 0x140a33fa0
public:
    BoneRotateInterpolator();                                   // 0x140a31c40
    BoneRotateInterpolator(NiTransformData* pkData);            // 0x140a31de0
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);   // 0x140a31f80
    virtual bool AlwaysUpdate() const;                          // 0x140a32e50

    void FUN_140a32e90(bool bActive, unsigned int uiBlendMs);   // switch between animation (false) and look-at (true)
    void SetKEye(efd::Point3 kPos);                       // m_kEye
    void SetKBone(efd::Point3 kPos);                       // m_kBone
    void SetKEuler(efd::Point3 kPos);                       // m_kEuler
    void SetYawBias(float fValue);                           // m_fYawBias
    void SetPitchBias(float fValue);                           // m_fPitchBias
    void SetSmooth(bool bValue);                            // m_bSmooth
    bool IsSmooth() const;                                 // m_bSmooth
    void FUN_140a33100();                                       // restore the local transform from the target's world one

    efd::Point3 m_kEye;                                         // +0x50 look-at start point
    efd::Point3 m_kBone;                                        // +0x5c bone position
    efd::Point3 m_kEuler;                                       // +0x68 bone euler offset (degrees)
    bool m_bAlwaysUpdate;                                       // +0x74
    bool m_bActive;                                             // +0x75 true while looking at the target
    float m_fLastYaw;                                           // +0x78
    float m_fLastPitch;                                         // +0x7c
    bool m_b80;                                                 // +0x80
    float m_f84;                                                // +0x84
    bool m_bSmooth;                                             // +0x88 blend timer is restarted on a changed aim
    Timer m_tmLookIn;                                           // +0x90 blend into the look-at
    efd::Matrix3 m_kLastRotate;                                 // +0xc8 rotation applied last frame
    NiAVObject* m_pTarget;                                      // +0xf0 the node being driven
    Timer m_tmLookOut;                                          // +0xf8 blend back to the animation
    Timer m_tmAim;                                              // +0x130 smooth aim changes
    float m_fPitchBias;                                         // +0x168
    float m_fYawBias;                                           // +0x16c
    int m_nObjectId;                                            // +0x170 game object whose entity owns the model
    bool m_bHasValue;                                           // +0x174 a look-at value was written
};
MS2_CHECK_SIZE(BoneRotateInterpolator, 0x178);

// Look-at mode (the key of the action map). An enum: ATL passes the key by reference like the exe does (name invented).
enum Unk_BrMode { Unk_BrMode_None = 0 };

typedef MS2Ptr<Unk_BrAction> Unk_BrActionPtr;
typedef ATL::CRBMap<Unk_BrMode, Unk_BrActionPtr> Unk_BrActionMap;

class GameObject;

// 0x220 bytes, CPtred base (own vftable 0x142dc5610: ~CBoneRotateManager / deleting dtor).
class CBoneRotateManager : public CPtred
{
public:
    CBoneRotateManager();                                       // 0x140a347c0
    virtual ~CBoneRotateManager();                              // 0x140a34a70 (??_G 0x140a35cc0)

    void FUN_140a34b80(GameObject* pOwner, CString strBone);    // bind the owner and the bone name, forget all actions
    void FUN_140a34be0(Unk_BrMode nMode, GameObject* pTarget, int nParam);   // start the action of nMode
    void FUN_140a34d00(const efd::Point3& kPos, int nStart, int nEnd, int nDuration);    // look at a point
    void FUN_140a34de0(const egf::EntityID& kId, CString strBone, int nStart, int nEnd, int nDuration);    // look at an entity
    void FUN_140a34f00();                                       // stop looking, return to the animation
    void FUN_140a35060();                                       // per-frame: switch the interpolator at the end of a look
    void FUN_140a35500(void* pArg);                             // per-frame: pick/advance actions
    int FUN_140a35780();                                        // a look is running
    Unk_BrMode GetCurrent();                                 // current action mode
    void FUN_140a357e0(float fValue);                           // interpolator pitch bias
    void FUN_140a35820(float fValue);                           // interpolator yaw bias
    void FUN_140a35860(bool bValue);                            // interpolator smooth flag
    bool FUN_140a358a0();                                       // interpolator smooth flag (false without one)
    GameObject* GetOwner();                                // the owner
    void FUN_140a35900();                                       // drop the action pointers

    bool m_bEnabled;                                            // +0x18
    efd::Point3 m_kLookPos;                                     // +0x1c point being looked at
    Timer m_tmLook;                                             // +0x28 how long the look lasts
    Timer m_tmApply;                                            // +0x60 delay before the interpolator is switched
    CString m_strBone;                                          // +0x98 "Bip01 Head"
    float m_fIdleMs;                                            // +0xa0 idle time before the next automatic action
    Timer m_tmReserved1[2];                                     // +0xa8
    Timer m_tmReserved2[2];                                     // +0x118
    Timer m_tmIdle;                                             // +0x188
    int m_nStart;                                               // +0x1c0 blend time into the look
    int m_nEnd;                                                 // +0x1c4 blend time out of the look
    BoneRotateInterpolator* m_pInterp;                          // +0x1c8
    GameObject* m_pOwner;                                       // +0x1d0
    egf::EntityID m_kTargetId;                                  // +0x1d8
    NiAVObject* m_pRootNode;                                    // +0x1e0
    Unk_BrMode m_nCurrent;                                      // +0x1e8 mode of the running action
    Unk_BrActionMap m_actions;                                  // +0x1f0 mode -> action
};
MS2_CHECK_SIZE(CBoneRotateManager, 0x220);
MS2_CHECK_OFFSET(CBoneRotateManager, m_actions, 0x1f0);
MS2_CHECK_OFFSET(CBoneRotateManager, m_kTargetId, 0x1d8);
