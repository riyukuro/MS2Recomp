// cameramode.h - CCameraMode (RTTI .?AVCCameraMode@@): the abstract base of the client's camera modes (RPG, action,
// target, fly-by, tool, ... about 20 classes). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\cameramode.cpp` (0x140afd490-0x140afe800). Header name assumed; the vfunc_N names are vftable slot numbers and the
// member names are invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

// The object that owns the camera modes (CCameraMode::m_pOwner); it forwards the settings to the engine camera
// through a property bag at +0x10 (hash-keyed setters).
class Unk_CameraPropertyBag
{
public:
    void FUN_14098c6e0(unsigned int nHash, const bool& bValue);
    int FUN_1409457c0(unsigned int nHash, const float& fValue);     // egf::Entity::SetPropertyValue<float>
    int FUN_1408a20a0(unsigned int nHash, bool& bValue) const;      // egf::Entity::GetPropertyValue<bool>
};

class Unk_CameraOwner
{
public:
    void FUN_140a38dc0(Vector3 pt);     // property 0xfd95ca52 (look-at offset)
    void FUN_140a38e00(Vector3 pt);     // second point property
    void FUN_140947940(float f);                // property 0x88b558f6 (distance)
    // @0x140afe7c0
    void FUN_140afe7c0(bool b)
    {
        if (m_10)
            m_10->FUN_14098c6e0(0x2310d55e, b);
    }
    // @0x140af8160
    bool FUN_140af8160()
    {
        bool b = false;
        if (m_10)
            m_10->FUN_1408a20a0(0x2310d55e, b);
        return b;
    }
    // @0x140af9a10
    void FUN_140af9a10(float f)
    {
        if (m_10)
            m_10->FUN_1409457c0(0xd2c672d5, f);
    }
    // @0x140af9990
    void FUN_140af9990(float f)
    {
        if (m_10)
            m_10->FUN_1409457c0(0x4b35f1d, f);
    }

    void* m_pad_00;
    void* m_pad_08;
    Unk_CameraPropertyBag* m_10;                // +0x10
};

// The camera settings block at CCameraMode+0x20 (0x28 bytes). The ctor (0x140ae7ce0), the copy ctor (0x140ae7d90)
// and the implicit copy assignment (0x140ae7de0) are COMDATs of the camera.cpp obj.
extern const Vector3 g_143b01a60;       // NiPoint3::ZERO
struct Unk_CameraSetting
{
    // 0x140ae7d90 (another obj): the members are default-constructed, then assigned
    Unk_CameraSetting(const Unk_CameraSetting& o)
    {
        *this = o;
    }
    Unk_CameraSetting()
    {
        m_c = g_143b01a60;
        m_18 = g_143b01a60;
        m_0 = 0.0f;
        m_4 = 250.0f;
        m_8 = 18000.0f;
        m_24 = false;
    }

    // The member-wise arithmetic (camera.cpp; the interpolators blend settings with them). The compound forms
    // return a copy.
    Unk_CameraSetting FUN_140ae7e80(float f) const;                     // operator*(float)
    Unk_CameraSetting FUN_140ae7f70(float f);                           // operator*=(float)
    Unk_CameraSetting FUN_140ae8020(float f) const;                     // operator/(float)
    Unk_CameraSetting FUN_140ae8110(float f);                           // operator/=(float)
    Unk_CameraSetting FUN_140ae81c0(const Unk_CameraSetting& o) const;  // operator+
    Unk_CameraSetting FUN_140ae82c0(const Unk_CameraSetting& o);        // operator+=
    Unk_CameraSetting FUN_140ae8380(const Unk_CameraSetting& o) const;  // operator-
    Unk_CameraSetting FUN_140ae8480(const Unk_CameraSetting& o);        // operator-=

    float m_0;                                  // +0x00
    float m_4;                                  // +0x04
    float m_8;                                  // +0x08
    Vector3 m_c;                        // +0x0c (vfunc_3)
    Vector3 m_18;                       // +0x18 (vfunc_4)
    bool m_24;                                  // +0x24 (vfunc_5)
};
MS2_CHECK_SIZE(Unk_CameraSetting, 0x28);

// The camera target entity (+0x1c0 of the camera manager); slot 17 returns its position.
class Unk_CameraTargetEntity
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16();
    virtual Vector3 vfunc_17();
    virtual Vector3 vfunc_18();                 // world position (consoleCameraMode adds its offset to it)
};

// The fly-by camera request stored in the camera manager at +0x34 (0x58 bytes): interpolation kind (1 linear, 2 log,
// 3 exp), duration, then the start and end camera settings.
struct Unk_FlyByCameraData
{
    int m_nKind;                                // +0x00
    float m_fDuration;                          // +0x04
    Unk_CameraSetting m_from;                   // +0x08
    Unk_CameraSetting m_to;                     // +0x30
};
MS2_CHECK_SIZE(Unk_FlyByCameraData, 0x58);

class CCameraMode;
class Unk_PickListPtr;                  // picked-object list (defined by the units that use it)

// The camera manager singleton (0x143ab3700). Its methods are inline COMDATs of other objs.
class Unk_CameraManager
{
public:
    static Unk_CameraManager* FUN_1409478c0();          // inline, ?\actioncameramode.cpp obj
    Unk_CameraTargetEntity* FUN_140a38d60();            // m_1c0 (the camera target)
    void FUN_140af0170(float f, bool b);                // applies f to the current mode (CCameraMode::FUN_140afe270)
    int FUN_140af01d0();                                // camera control type (0: normal, 1: ...)
    float FUN_140b67d10();                              // distance of the current mode (0 without one)
    float FUN_140ad4b40();                              // current mode: setting m_0 (0 without one)
    float FUN_140af7f00();                              // current mode: setting m_4
    float FUN_140af7ea0();                              // current mode: setting m_8
    Vector3 FUN_140a17e10();                    // current mode: setting m_c (zero without one)
    Vector3 FUN_140af8290();                    // current mode: setting m_18
    Vector3 FUN_140af0250();                    // camera world direction (by value: this, hidden return)
    Vector3 FUN_140af0340();                    // camera world up vector
    void FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n);
    CCameraMode* FUN_140af24f0();                       // the current camera mode
    Vector3 FUN_140a38d00();                    // m_138 (pending move input)
    void FUN_140a38d90(Vector3 pt);             // m_138 = pt
    Unk_FlyByCameraData* FUN_1412201a0();               // &m_34 (inline, ?\flybycameramode.cpp obj)
    Unk_PickListPtr FUN_140af0850(float fX, float fY, bool b1, bool b2, bool b3, void* p);  // pick at the cursor
};

// Argument of vfunc_36 (a camera preset row).
struct Unk_CameraPreset
{
    char m_pad_00[0x1c];
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
};

// 0x78 bytes. vftable 0x142dd6ab8, 37 slots (slots 1 and 2 pure).
class CCameraMode : public CPtred
{
public:
    CCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x140afd490 (copies pPrev's settings)
    virtual ~CCameraMode();                                         // 0x140afd540

    virtual int vfunc_1() = 0;                                      // mode id
    virtual bool vfunc_2() = 0;
    virtual void vfunc_3(Vector3 pt);                       // 0x140afd570
    virtual void vfunc_4(Vector3 pt);                       // 0x140afd5d0
    virtual void vfunc_5(bool b);                                   // 0x140afd630
    virtual void vfunc_6(int n);                                    // 0x140afd670
    virtual void vfunc_7();                                         // 0x140afd740
    virtual void vfunc_8(double fTime);                             // 0x140afd750
    virtual void vfunc_9();                                         // 0x140afd770
    virtual void vfunc_10();                                        // 0x140afd780
    virtual void vfunc_11(float f);                                 // 0x140afd790
    virtual void vfunc_12(float fDegree);                           // 0x140afd7f0
    virtual void vfunc_13(float fDegree);                           // 0x140afd830
    virtual void vfunc_14(float f);                                 // 0x140afd870
    virtual float vfunc_15();                                       // 0x140afd8a0
    virtual void vfunc_16(float f);                                 // 0x140afd8c0
    virtual float vfunc_17();                                       // 0x140afd8f0
    virtual void vfunc_18(float f1, float f2);                      // 0x140afd910
    virtual float vfunc_19();                                       // 0x140afd950
    virtual void vfunc_20(float f);                                 // 0x140afd970
    virtual void vfunc_21(float f, int n);                          // 0x140afd9a0
    virtual float vfunc_22();                                       // 0x140afd9d0
    virtual float vfunc_23();                                       // 0x140afd9e0
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);                 // 0x140afd9f0
    virtual Unk_CameraTargetEntity* vfunc_25();                                   // 0x140afda10
    virtual Vector3 vfunc_26();                             // 0x140afda20
    virtual float vfunc_27();                                       // 0x140afda50
    virtual int vfunc_28();                                         // 0x140afda60
    virtual void vfunc_29(float f1, float f2, float f3);            // 0x140afda80
    // 0x140947930 (COMDAT of the ?\actioncameramode.cpp obj)
    virtual void vfunc_30() {}
    virtual BOOL vfunc_31();                                        // 0x140afe2c0
    virtual void vfunc_32(float f);                                 // 0x140afe320
    virtual void vfunc_33();                                        // 0x140afe350
    // 0x1409478d0 (COMDAT of the ?\actioncameramode.cpp obj)
    virtual bool vfunc_34() { return true; }
    virtual Vector3 vfunc_35();                             // 0x140afe360
    virtual void vfunc_36(Unk_CameraPreset* pPreset);               // 0x140afe410

    void FUN_140afdaa0(MS2Ptr<CCameraMode> pPrev);                  // copy pPrev's settings or set the defaults
    static Vector3 FUN_140afdd40(const Vector3& ptEye, const Vector3& ptAt,
                                         const Vector3& ptUp);     // look-at -> euler angles (degrees)
    static Vector3 FUN_140afdec0(float t, const Vector3& a, const Vector3& b); // angle lerp
    void FUN_140afe270(float f, bool bApply);
    float FUN_140afe2e0();
    float FUN_140afe300();
    void FUN_140afe4b0();
    // @0x140af8140
    bool FUN_140af8140() { return m_pOwner->FUN_140af8160(); }      // owner property 0x2310d55e (set by vfunc_5)

    // 0x1409f2540 (inline, another obj)
    Vector3 FUN_1409f2540() { return m_setting.m_c; }
    // 0x140af8260 (inline, another obj)
    Vector3 FUN_140af8260() { return m_setting.m_18; }
    // 0x140ad4b30 (inline, another obj)
    float FUN_140ad4b30() { return m_setting.m_0; }
    // @0x140af9820
    void FUN_140af9820(Unk_CameraOwner* pOwner) { m_pOwner = pOwner; }
    // @0x140af99d0
    void FUN_140af99d0(float f) { m_setting.m_4 = f; m_pOwner->FUN_140af9a10(f); }
    // @0x140af9950
    void FUN_140af9950(float f) { m_setting.m_8 = f; m_pOwner->FUN_140af9990(f); }
    // @0x140af7ef0
    float FUN_140af7ef0() { return m_setting.m_4; }
    // @0x140af7e90
    float FUN_140af7e90() { return m_setting.m_8; }
    // @0x140af84b0
    float FUN_140af84b0() { return m_70; }

    Unk_CameraOwner* m_pOwner;          // +0x18
    Unk_CameraSetting m_setting;        // +0x20
    float m_48;                         // +0x48 (radians; vfunc_12 adds pi)
    float m_4c;                         // +0x4c (radians)
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    float m_6c;
    float m_70;                         // +0x70 (ctor 1.0)
};
MS2_CHECK_SIZE(CCameraMode, 0x78);
MS2_CHECK_OFFSET(CCameraMode, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CCameraMode, m_setting, 0x20);
MS2_CHECK_OFFSET(CCameraMode, m_70, 0x70);
