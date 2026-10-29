// CNifAnimationController: loads a NIF through the scene-graph service and drives its "Dummy01" (mode 0) or
// "Camera01" (mode 1) node animation. 0x60 bytes, NiRefObject-derived; vftable 0x142f2c048 (dtor, DeleteThis, GetRTTI).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/ninode.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/postprocesseffect.h"   // NiFixedString
#include "ms2/placeholder/statecoupleemotion.h"  // Unk_TargetPtr
#include <NiCamera.h>
#include <efd/Point3.h>

class CNifAnimationController : public NiRefObject {
public:
    CNifAnimationController();                                        // 0x141544660
    virtual ~CNifAnimationController();                               // 0x141544750 (deleting 0x1415452e0)
    virtual const NiRTTI* GetRTTI() const;                            // 0x141545340
    bool FUN_141544850(int mode, CStringA name, const efd::Point3& kEuler);      // load nif + hook up controllers
    void FUN_141544ec0(float time);                                   // update (mode 1): sample camera transform
    efd::Point3 FUN_141545020();                                      // copy of +0x38
    efd::Point3 FUN_141545050();                                      // copy of +0x44

    static const NiRTTI ms_RTTI;                                      // 0x143ae1a30

    NiAVObjectPtr m_10;                                               // +0x10 nif scene root
    NiNodePtr m_18;                                                   // +0x18 "Dummy01" node
    Unk_TargetPtr m_20;                                               // +0x20 first animated target (statecoupleemotion.h)
    NiNodePtr m_28;                                                   // +0x28 "Camera01" node
    NiCameraPtr m_30;                                                 // +0x30 camera
    efd::Point3 m_38;                                                 // +0x38 camera translate
    efd::Point3 m_44;                                                 // +0x44 camera euler angles (degrees)
    float m_50;                                                       // +0x50
    float m_54;                                                       // +0x54 max end time
    int m_58;                                                         // +0x58 mode
    int m_5c;
};
MS2_CHECK_SIZE(CNifAnimationController, 0x60);

void FUN_141545080(int value, void* node);   // recursive: set a value on every controller of a node subtree
void FUN_1415451d0(int value, void* entityId);
void FUN_141545250(void* entityId, int mode);
