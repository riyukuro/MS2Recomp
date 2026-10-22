// ponytailphysxhelper.h - CPonyTailController (RTTI .?AVCPonyTailController@@, 0x250 bytes): the customize controller
// of the hair-physics ponytail (equip slot 1, hair parts "HR_Pony"/"HR"). It drags the two ponytail joint models (the
// two pony parts of the hair) around the head, keeps their rest transforms and pushes the result to the PhysX joints
// (CPonyTailPhysXHelper::UpdateModelPhysXValues). Owning unit: client\ms2\ponytailphysxhelper.cpp
// (src/ms2/client/ms2/ponytailphysxhelper.cpp, 0x1416916b0-0x141697140). Header name assumed; member names are invented
// from their use. The placeholder ms2/placeholder/cponytailcontroller.h forwards here.
#pragma once
#include "ms2/client/ms2/itemcustomizecontroller_1.h"
#include "ms2/client/ms2/itempickinghelper.h"
#include "ms2/client/ms2/frustumcollision.h"
#include "ms2/placeholder/nipoint3.h"
#include <NiTransform.h>

class CEquipModel;
class NiNode;

// One pony part of the controller (0xc0 bytes): the hair model that is dragged and its three transforms. The
// functions are the unit's own (0x1416916b0-0x1416917d0, dtor 0x141695df0).
struct Unk_PonyPart
{
    Unk_PonyPart();                                             // 0x1416916b0
    ~Unk_PonyPart();                                            // 0x141695df0 (drops the model)
    void Reset();                                               // 0x141691740 rest pose, no model
    void Swap(Unk_PonyPart& kOther);                            // 0x1416917d0

    float m_fValue;                                             // +0x00 angle of the part (180 for the first, 0 for the second)
    Unk_FcPoint3 m_kAnchor;                                     // +0x04 last anchor point of the drag
    NiTransform m_kRest;                                        // +0x10 rest transform of the model
    NiTransform m_kStart;                                       // +0x44 transform at the start of the drag
    NiTransform m_kPose;                                        // +0x78 transform pushed to the PhysX joint (rotation
                                                                //       +0x78, translation +0x9c, scale +0xa8)
    MS2Ptr<Unk_PickTarget> m_spModel;                           // +0xb0 the hair part model (a CEquipModel)
};
MS2_CHECK_SIZE(Unk_PonyPart, 0xc0);

// A texture-like handle (8 bytes, NiRefObject pointer: IncRefCount 0x140980460 / DecRefCount 0x1405a93d0).
struct Unk_PonyHandle
{
    Unk_PonyHandle(void* p = 0);                                // 0x141065070 init with p (AddRef)
    ~Unk_PonyHandle() { FUN_140a5a930(); }                      // drop (DecRef)
    void FUN_141068540(void* p);                                // assign (AddRef new, DecRef old)
    void FUN_140a5a930();                                       // drop (DecRef)
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PonyHandle, 8);

// Listener at +0xa0: slots 1, 2 and 5 are called by the controller (the base class only knows slot 0).
class Unk_PonyListener : public Unk_ItemCustomizeListener
{
public:
    virtual void vfunc_1(CItemCustomizeController* pController) = 0;
    virtual void vfunc_2(CItemCustomizeController* pController, float fValue, int nIndex) = 0;
    virtual void vfunc_3() = 0;
    virtual void vfunc_4() = 0;
    virtual void vfunc_5(CItemCustomizeController* pController, Unk_PickTarget* pPart) = 0;
};

class CPonyTailController;
class Unk_PonyPlayer;
// Pose callback of FUN_1416955b0 (a 16-byte pointer to member: code + this adjustment). Called with the part, the
// scene root, two values of the caller, and returns the part's position, euler angles and scale.
#pragma pointers_to_members(full_generality, multiple_inheritance)
typedef void (CPonyTailController::*Unk_PonyPoseFn)(MS2Ptr<Unk_PickTarget> spPart, NiNode* pRoot, int nValue, int nSecond,
                                                    Vector3& kPos, Vector3& kEuler, float& fScale);

class CPonyTailController : public CItemCustomizeController
{
public:
    CPonyTailController();                                          // 0x141691a20
    virtual ~CPonyTailController();                                 // 0x141691ad0, ??_G 0x141695ea0
    NiDeclareRTTI;                                                  // 2  GetRTTI 0x141695f00
    virtual int vfunc_3();                                          // 3  0x141691b40
    virtual void vfunc_5();                                         // 5  0x141691d30
    virtual void vfunc_6();                                         // 6  0x141691de0
    virtual void vfunc_9(int nIndex);                               // 9  0x141692850
    virtual void vfunc_14(float fValue);                            // 14 0x1416925e0
    virtual int vfunc_17();                                         // 17 0x1416925c0
    virtual float vfunc_19();                                       // 19 0x1416923e0
    virtual float vfunc_20();                                       // 20 0x141692410
    virtual const Unk_CustomizeRange* vfunc_23();                   // 23 0x141692440
    virtual void vfunc_25(float* pfMin, float* pfMax);              // 25 0x141692560
    virtual void vfunc_28();                                        // 28 0x141692a90
    virtual int vfunc_29();                                         // 29 0x1416929b0
    virtual void vfunc_30(const NiPoint3& kPos);                    // 30 0x141692db0
    virtual void vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue);
                                                                    // 32 0x141693210
    virtual void vfunc_33();                                        // 33 0x141694380
    virtual void vfunc_37();                                        // 37 0x141692b60
    virtual float vfunc_40();                                       // 40 0x141692b40

    // non-virtual (names invented)
    void FUN_141694650();                                           // reset both parts and rebuild them from the item
    void FUN_141694ea0(Unk_PickTarget** ppFirst, Unk_PickTarget** ppSecond);   // the two pony models in drag order
    void FUN_141694fb0(MS2Ptr<Unk_PickTarget> spPart, NiNode* pRoot, int nValue, int nSecond,
                       Vector3& kPos, Vector3& kEuler, float& fScale);   // pose: current model transform
    void FUN_141695120(MS2Ptr<Unk_PickTarget> spPart, NiNode* pRoot, int nIndex, int nSecond,
                       Vector3& kPos, Vector3& kEuler, float& fScale);   // pose: stored preset nIndex
    void FUN_141695220();                                           // puts the parts to their rest pose once
    void FUN_1416952c0(Unk_PonyPart* pPart);                        // applies a part's rest pose to its model
    void FUN_1416955b0(int nMode, int nIndex, Unk_PonyPoseFn pFn, int nValue);   // runs the pose callback for both parts
    void FUN_141695710(Unk_PonyPart* pPart, int nMode, int nIndex, Unk_PonyPoseFn pFn, int nValue, int bSecond);
    Vector3 FUN_141695bc0(const Vector3& kOrigin, const Vector3& kPoint, const Vector3& kPlane);
    NiTransform FUN_141695ca0(Unk_PickTarget* pModel);              // the transform of a part model

    float m_fSensitivity;                                           // +0xb8 drag speed (client config)
    int m_bBusy;                                                    // +0xbc 1 once the parts are in the rest pose
    int m_nValue;                                                   // +0xc0 the slider value (-1 none)
    Unk_PonyHandle m_kControlMap;                                   // +0xc8 the "_control.dds" mask
    Unk_PonyPart m_kFirst;                                          // +0xd0
    Unk_PonyPart m_kSecond;                                         // +0x190
};
MS2_CHECK_SIZE(CPonyTailController, 0x250);
MS2_CHECK_OFFSET(CPonyTailController, m_fSensitivity, 0xb8);
MS2_CHECK_OFFSET(CPonyTailController, m_nValue, 0xc0);
MS2_CHECK_OFFSET(CPonyTailController, m_kControlMap, 0xc8);
MS2_CHECK_OFFSET(CPonyTailController, m_kFirst, 0xd0);
MS2_CHECK_OFFSET(CPonyTailController, m_kSecond, 0x190);

// Static helper class of the unit (0x1416962d0): pushes the joint limits / anchors of a hair part to PhysX.
class CPonyTailPhysXHelper
{
public:
    static void UpdateModelPhysXValues(Unk_PickTarget* pModel, const void* pJoints);   // 0x1416962d0
};
