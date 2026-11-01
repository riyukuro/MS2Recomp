// unit_141274d10_statics.h - the statics of unit_141274d10.cpp that sit between the shared header statics ("stun") and the
// condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): the resolution-scale cache and a
// null handle (same shape as reactor_statics.h).
#pragma once

#include <atlcoll.h>

// The key of the screen-scale cache: the display size (width, height) as floats; hashed as w*1000 + h*100.
struct Unk_ScreenKey
{
    float m_fWidth;
    float m_fHeight;
    Unk_ScreenKey(float fWidth, float fHeight) { m_fWidth = fWidth; m_fHeight = fHeight; }       // 0x141278370
};
MS2_CHECK_SIZE(Unk_ScreenKey, 8);

class Unk_ScreenKeyTraits : public ATL::CElementTraitsBase<Unk_ScreenKey>
{
public:
    static ULONG Hash(const Unk_ScreenKey& key)                                                // 0x1412788f0
    {
        return (int)(__int64)key.m_fWidth * 1000 + (int)(__int64)(key.m_fHeight * 100.0f);
    }
    static bool CompareElements(const Unk_ScreenKey& a, const Unk_ScreenKey& b)               // 0x141278500
    {
        return a.m_fWidth == b.m_fWidth && a.m_fHeight == b.m_fHeight ? 1 : 0;
    }
};

typedef ATL::CAtlMap<Unk_ScreenKey, float, Unk_ScreenKeyTraits> Unk_ScaleMap;

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };     // ctor 0x1401cd100

static Unk_ScaleMap s_scaleCache(17, 0.75f, 0.25f, 2.25f, 10);                           // @0x1400ebca0
static Unk_BuddyHandle s_dat_143ad61a8(0);                                           // @0x1400ebcf0
