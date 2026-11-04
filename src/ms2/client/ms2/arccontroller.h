// arccontroller.h - CArcController (RTTI .?AVCArcController@@): plays back a ballistic arc (the launch solution of
// Unk_ArcFlight, solved by the mapmetamanager unit's FUN_141479ed0) over time and reports the current offset and world
// position. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\arccontroller.cpp`
// (0x1409ab110-0x1409ab7c0, dir client\ms2). Header name assumed; member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/Point2.h>
#include <NiRefObject.h>
#include <NiRTTI.h>

// The solved arc (0x38 bytes); the implicit ctor is the COMDAT 0x1409ab560. Solver: FUN_141479ed0.
struct Unk_ArcFlight
{
    float m_flightScale;                // +0x00 flight time
    float m_speed;                      // +0x04
    float m_gravity;                    // +0x08
    Vector3 m_target;           // +0x0c
    Vector3 m_direction;        // +0x18 horizontal unit direction
    Vector3 m_origin;           // +0x24
    efd::Point2 m_angle;                // +0x30 cos (x) / sin (y) of the launch angle

    void FUN_141479ed0(Vector3 origin, Vector3 target, float speed, float gravity);
};
MS2_CHECK_SIZE(Unk_ArcFlight, 0x38);

// 0x68 bytes; vftable 0x142e69378-ish (3 slots), deleting dtor 0x1409ab630.
class CArcController : public NiRefObject
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143ab3db0

    CArcController();                                           // 0x1409ab110
    virtual ~CArcController();                                  // 0x1409ab180
    virtual const NiRTTI* GetRTTI() const;                      // slot 2, 0x1409ab690

    bool FUN_1409ab1b0(Vector3 from, Vector3 to, float speed, float gravityScale);  // start; false if from/to coincide
    float FUN_1409ab300() const;                                // flight time
    bool IsRising() const;                                 // still rising
    Vector3 GetPosition() const;                      // current world position
    bool FUN_1409ab370() const;                                 // finished
    void FUN_1409ab3b0(float fDelta);                           // advance

public:
    Unk_ArcFlight m_arc;                                        // +0x10
    float m_elapsed;                                            // +0x48
    Vector3 m_offset;                                   // +0x4c offset from the origin
    bool m_bRising;                                             // +0x58
    Vector3 m_position;                                 // +0x5c
};
MS2_CHECK_SIZE(CArcController, 0x68);
MS2_CHECK_OFFSET(CArcController, m_elapsed, 0x48);
MS2_CHECK_OFFSET(CArcController, m_position, 0x5c);

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
