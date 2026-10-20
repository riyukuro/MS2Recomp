// propertycache.h - PLACEHOLDER for the client's egf::Entity property cache (NOT an original header). MS2 changed
// egf::Entity: three members after the engine layout (+0xc8 caching on, +0xd0 the plain writes, +0xe0 the keyed writes)
// and the SetPropertyValue<T> templates, which first save the property's old value in the cache when caching is on
// (scenestategame.cpp writes the saved values back and frees them). The engine headers keep the stock Entity, so the
// cache is reached through this egf::Entity view. Names invented.
//
// The exe's efd::map<unsigned, Unk_PropertyCacheEntry> glue belongs to the ?\actioncameramode.cpp obj (the first user:
// Camera::FUN_140947940 -> SetPropertyValue<float> 0x1409457c0). Unk_PropertyCacheEntry is spelled exactly as in
// hardwareinstancingservice.h (same mangled names for the shared COMDATs); a unit including both must use that one.
#pragma once

#include <efd/StdContainers.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>

#include "ms2/ms2layout.h"

#ifndef MS2_PROPERTYCACHEENTRY_DEFINED
#define MS2_PROPERTYCACHEENTRY_DEFINED
// A property write saved while an entity's property cache is on (id, a heap copy of the old value, its class id).
// Same view as bosstargetcamera.cpp (its ctor 0x140947490) and scenestategame.cpp.
struct Unk_PropertyCacheEntry
{
    Unk_PropertyCacheEntry() : m_id(0), m_pValue(NULL), m_type(0) {}       // 0x1409474d0
    Unk_PropertyCacheEntry(unsigned nId, void* pValue, unsigned nType) : m_id(nId), m_pValue(pValue), m_type(nType) {}

    unsigned m_id;
    void* m_pValue;
    unsigned m_type;
};
MS2_CHECK_SIZE(Unk_PropertyCacheEntry, 0x18);
#endif

// egf::Entity with MS2's property cache (the exe Entity is 0xf0 bytes).
class Unk_CachedEntity : public egf::Entity
{
public:
    // Saves the old value of propID once per caching session (0x140945670 for float).
    template<typename T>
    void CachePropertyValue(egf::PropertyID propID, const T& data);
    // MS2's Entity::SetPropertyValue<T> (0x1409457c0 for float).
    template<typename T>
    egf::PropertyResult SetPropertyValue(egf::PropertyID propID, const T& data);

    bool m_bCaching;                                                        // +0xc8
    efd::map<unsigned, Unk_PropertyCacheEntry> m_mapCache;                  // +0xd0
    efd::map<unsigned, efd::map<efd::utf8string, Unk_PropertyCacheEntry> > m_mapKeyedCache;   // +0xe0
};
MS2_CHECK_OFFSET(Unk_CachedEntity, m_bCaching, 0xc8);
MS2_CHECK_OFFSET(Unk_CachedEntity, m_mapCache, 0xd0);
MS2_CHECK_OFFSET(Unk_CachedEntity, m_mapKeyedCache, 0xe0);

template<typename T>
void Unk_CachedEntity::CachePropertyValue(egf::PropertyID propID, const T& data)
{
    if (m_bCaching)
    {
        if (m_mapCache.find(propID) == m_mapCache.end())
        {
            T kOld;
            GetPropertyValueUnsafe(propID, &kOld, efd::GetClassIDFromType<T>());
            m_mapCache[propID] = Unk_PropertyCacheEntry(propID, new T(kOld), efd::GetClassIDFromType<T>());
        }
    }
}

template<typename T>
egf::PropertyResult Unk_CachedEntity::SetPropertyValue(egf::PropertyID propID, const T& data)
{
    CachePropertyValue(propID, data);
    return SetPropertyValueUnsafe(propID, &data, efd::GetClassIDFromType<T>());
}
