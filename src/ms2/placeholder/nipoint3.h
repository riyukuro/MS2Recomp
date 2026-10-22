// nipoint3.h - PLACEHOLDER for the game's 12-byte float point and 3x3 matrix (Gamebryo NiPoint3 : efd::Point3 and
// NiMatrix3 : efd::Matrix3; NiMain headers are not on the game include path). NOT an original header.
//
// Vector3 (was Unk_StreamPoint; not NiPoint3 because the SDK class is visible in many units) plays both roles: the NiPoint3 default
// ctor and the efd::Point3 (x, y, z) ctor are recorded under its name in the symbol harvest. The efd::Point3 operators
// are inline COMDATs owned by other objs; they are declared as FUN_<va> members so that call sites byte-match and the
// hook DLL binds them to the exe.
#pragma once

#include "ms2/ms2layout.h"

namespace efd { class Point3; }

struct Vector3
{
    Vector3();                                              // 0x1402bd040 (NiPoint3())
    explicit Vector3(const efd::Point3& pt);                // 0x14027dcf0 (NiPoint3(const efd::Point3&))
    Vector3(float, float, float);                           // 0x14027dda0 (efd::Point3(x, y, z))
    Vector3& operator=(const Vector3&);             // 0x140194470
    Vector3 FUN_140965c40(const Vector3& pt) const; // efd::Point3::operator-
    Vector3 FUN_14097fd50(const Vector3& pt) const; // efd::Point3::operator+
    Vector3 FUN_140a00e10(const Vector3& pt) const; // efd::Point3::Cross
    float FUN_140968990();                                          // efd::Point3::Unitize (returns the old length)
    Vector3 FUN_14097fc90(float f) const;                   // efd::Point3::operator*(float)
    Vector3& FUN_140a4e560(const Vector3& pt);      // efd::Point3::operator+=
    bool FUN_140552700(const Vector3& pt) const;            // efd::Point3::operator!=
    bool FUN_140552690(const Vector3& pt) const;           // efd::Point3::operator==
    float FUN_140967ac0() const;                                    // efd::Point3::Length
    float FUN_140a00f20(const Vector3& pt) const;           // efd::Point3::Dot
    Vector3 FUN_1409f7960() const;                          // efd::Point3::operator- (unary)
    Vector3 FUN_140ae9180(float f) const;                   // efd::Point3::operator/(float)
    Vector3& FUN_140ae9200(const Vector3& pt);      // efd::Point3::operator-= (camera.cpp)
    Vector3& FUN_140ae9270(float f);                        // efd::Point3::operator/=(float) (camera.cpp)
    Vector3& FUN_140ad0c10(float f);                        // efd::Point3::operator*=(float)
    Vector3 FUN_14109adc0(const Vector3& pt) const; // unit cross product (getexp)
    float x, y, z;
};
MS2_CHECK_SIZE(Vector3, 12);

// efd::Point3 operator*(float, const Point3&) (friend, 0x1409ab5c0).
Vector3 FUN_1409ab5c0(float fScalar, const Vector3& pt);
// Horizontal distance of two points (z cleared on the copies; 0x140966ea0).
float FUN_140966ea0(Vector3 a, Vector3 b);

// NiPoint3 as a matrix-ctor argument: NiPoint3(const efd::Point3&) (0x14027dcf0) makes the conversion temporaries.
// Defined inline here (the exe copy belongs to another obj).
struct Unk_NiPoint3
{
    Unk_NiPoint3(const Vector3& pt) : x(pt.x), y(pt.y), z(pt.z) {}
    float FUN_140967ac0() const;                                    // efd::Point3::Length (inherited)
    bool FUN_140552690(const Vector3& pt) const;            // efd::Point3::operator== (inherited)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_NiPoint3, 12);

// efd::Matrix3 (0x24 bytes, rows of 3 floats), the base of NiMatrix3. The functions are external; the empty default
// ctor is 0x1409f72e0.
struct Unk_EfdMatrix3
{
    Unk_EfdMatrix3() {}
    Unk_EfdMatrix3(const Unk_NiPoint3& col0, const Unk_NiPoint3& col1, const Unk_NiPoint3& col2);   // 0x142083420
    void FUN_142083420(const Unk_NiPoint3& col0, const Unk_NiPoint3& col1, const Unk_NiPoint3& col2);
    void FUN_142083d40(float fX, float fY, float fZ);               // efd::Matrix3::FromEulerAnglesXYZ (radians)
    bool FUN_142085840(float& fX, float& fY, float& fZ) const;      // efd::Matrix3::ToEulerAnglesXYZ
    void FUN_142084b30(float fAngle);                               // efd::Matrix3::MakeXRotation
    void FUN_142084ba0(float fAngle);                               // efd::Matrix3::MakeYRotation
    void FUN_142084c10(float fAngle);                               // efd::Matrix3::MakeZRotation
    Vector3 FUN_140a00720(const Vector3& v) const;  // efd::Matrix3::operator*(Point3)
    void FUN_14107cc40(float fAngle, const Vector3& kAxis); // efd::Matrix3::MakeRotation (angle about a unit axis)
    Unk_EfdMatrix3 FUN_140a33480(const Unk_EfdMatrix3& m) const;    // efd::Matrix3::operator*
    float m_afEntry[3][3];
};
MS2_CHECK_SIZE(Unk_EfdMatrix3, 0x24);

// NiMatrix3 : efd::Matrix3. The ctors are inline COMDATs of other objs (defined here so that the DLL has them).
struct Unk_NiMatrix3 : public Unk_EfdMatrix3
{
    // 0x1409f7320
    Unk_NiMatrix3() {}
    // 0x140a0a480 -> efd::Matrix3::Matrix3(col0, col1, col2) 0x142083420
    Unk_NiMatrix3(const Unk_NiPoint3& col0, const Unk_NiPoint3& col1, const Unk_NiPoint3& col2)
        : Unk_EfdMatrix3(col0, col1, col2)
    {
    }
    // 0x140a33240: converts an efd::Matrix3 (memcpy)
    Unk_NiMatrix3(const Unk_EfdMatrix3& m)
    {
        memcpy(this, &m, sizeof(Unk_EfdMatrix3));
    }
    void FUN_140a01190(unsigned int uiCol, Vector3& pt) const;  // GetCol (inline, 0x140a01190)
    void FUN_14109aa30(unsigned int uiCol, const Vector3& pt);   // SetCol (0x14109aa30)
};
MS2_CHECK_SIZE(Unk_NiMatrix3, 0x24);
