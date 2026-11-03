// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Cache of an egf entity's key -> EntityID meta property.
// MS2-UNIT: ?\mapmetamanager.cpp
// MS2-RANGE: 0x1400f7d10-0x1400f7d50 .text$di
// MS2-RANGE: 0x141478090-0x14147a2a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "mapmetamanager.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include <egf/Entity.h>
#include <egf/EntityManager.h>
#include <efd/Point3.h>
#include <efd/EEMath.h>   // C3: efd::Sqrt was FUN_140968970
#include <math.h>

// The exe calls these three CRT functions through its IAT (`call [__imp_x]`); see gpumanager.cpp for the idiom.
extern "C" float (__cdecl* __imp_atanf)(float);
extern "C" float (__cdecl* __imp_cosf)(float);
extern "C" float (__cdecl* __imp_sinf)(float);

// ---- out-of-unit callees ----

// @0x1400f7d10
const NiRTTI CMapMetaManager::ms_RTTI("CMapMetaManager", 0);

// @0x1400f7d30 (static initialised by FUN_1401cd100(&DAT_143add978, 0))
static const egf::EntityID s_noEntity(0);

// @0x141478090
CMapMetaManager::CMapMetaManager(egf::EntityID entityID)
    : m_values(10)
{
    m_entityID = entityID;
    m_values.RemoveAll();
}

// @0x141478130
CMapMetaManager::~CMapMetaManager()
{
    m_values.RemoveAll();
}

// @0x141478180
egf::EntityID CMapMetaManager::FUN_141478180(efd::utf8string key)
{
    if (m_values.GetCount() <= 0) {
        egf::Entity* entity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_entityID);
        if (entity != NULL) {
            efd::UInt32 count = 0;
            entity->GetPropertyCount(0x25000038, count);
            efd::list<efd::utf8string> keys;
            entity->GetPropertyKeys(0x25000038, keys);
            for (efd::list<efd::utf8string>::iterator it = keys.begin(); it != keys.end(); ++it) {
                efd::utf8string name(*it);
                egf::EntityID value;
                entity->GetPropertyValue(0x25000038, name, value);
                m_values.SetAt(name, value);
            }
        }
    }
    egf::EntityID found;
    if (m_values.Lookup(key, found))
        return found;
    return s_noEntity;
}

// @0x141478ea0
const NiRTTI* CMapMetaManager::GetRTTI() const { return &ms_RTTI; }

// ---- ballistic arc solver (not part of CMapMetaManager; sits in this unit's range) ----
float FUN_140966ea0(efd::Point3 a, efd::Point3 b);                           // distance in the xy plane
bool FUN_14028d470(float a, float b);                                        // nearly equal
efd::Point3 FUN_141192780(efd::Point3 from, efd::Point3 to, bool flatten);   // direction from -> to

// Launch solution for a projectile of the given speed under gravity: the low-angle arc from origin to target.
struct Unk_ArcSolution
{
    float m_flightScale;        // +0x00 horizontal distance / (cos * speed)
    float m_speed;              // +0x04
    float m_gravity;            // +0x08
    efd::Point3 m_target;       // +0x0c
    efd::Point3 m_direction;    // +0x18
    efd::Point3 m_origin;       // +0x24
    float m_cos;                // +0x30
    float m_sin;                // +0x34

    void FUN_141479ed0(efd::Point3 origin, efd::Point3 target, float speed, float gravity);
};

// @0x141479ed0
void Unk_ArcSolution::FUN_141479ed0(efd::Point3 origin, efd::Point3 target, float speed, float gravity)
{
    float distance = FUN_140966ea0(target, origin);
    if (FUN_14028d470(distance, 0.0f)) {
        m_speed = speed;
        return;
    }
    float dz = target.z - origin.z;
    float speedSq = speed * speed;
    float distSq = distance * distance;
    float distQuad = distSq * distSq;
    float gravitySq = gravity * gravity;
    float speedQuad = speedSq * speedSq;
    float discriminant = (distSq - gravitySq * distQuad / speedQuad) + 2.0f * gravity * distSq * dz / speedSq;
    if (discriminant < 0.0f) {
        speed = speed * 1.16f;
        FUN_141479ed0(origin, target, speed, gravity);
    } else {
        float tangent = speedSq * ((-distance - efd::Sqrt(discriminant)) / (gravity * distSq));
        float angle = __imp_atanf(tangent);
        m_speed = speed;
        m_direction = FUN_141192780(origin, target, true);
        m_target = target;
        m_origin = origin;
        m_gravity = gravity;
        m_cos = __imp_cosf(angle);
        m_sin = __imp_sinf(angle);
        if (__imp_cosf(angle) <= 0.0f)
            m_flightScale = 0.0f;
        else
            m_flightScale = distance / (m_cos * speed);
    }
}
