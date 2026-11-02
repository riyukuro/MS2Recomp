// cubemotionmanager.h - CCubeMotionManager (RTTI): per-entity timed motions of cube objects (scale, rotation, bounce,
// fade), each stored in an ATL red-black map keyed by the entity id. The motion value classes are unnamed in the exe
// (their ctors/dtors are header-inline COMDATs of this obj); the names below are invented from what they drive.
#pragma once
#include <atlcoll.h>
#include <vector>
#include <efd/customalloc.h>
#include <egf/EntityID.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/timer.h"

class TransparencyStandardMaterial;
struct Unk_CmMaterialList : std::vector<TransparencyStandardMaterial*, efd::CustomAllocator<TransparencyStandardMaterial*> >
{
};

// Scale motion: lerps a float entity property from m_fFrom to m_fTo over the timer.
class Unk_CmScale
{
public:
    Unk_CmScale() {}                                                // 0x1410af660 (inline, the timer ctor), dtor 0x1410af6b0
    Unk_CmScale(float fFrom, float fTo, unsigned nMs);              // 0x14115e3e0
    float m_fFrom;                  // +0x00
    float m_fTo;                    // +0x04
    Timer m_timer;                  // +0x08
};
MS2_CHECK_SIZE(Unk_CmScale, 0x40);

// Rotation motion (degrees): takes the short way round when the span exceeds 180.
class Unk_CmRotate
{
public:
    Unk_CmRotate() {}                                               // 0x1410af630 (inline, the timer ctor), dtor 0x1410af690
    Unk_CmRotate(float fFrom, float fTo, unsigned nMs);             // 0x14115e2c0
    float m_fFrom;                  // +0x00
    float m_fTo;                    // +0x04
    Timer m_timer;                  // +0x08
};
MS2_CHECK_SIZE(Unk_CmRotate, 0x40);

// Bounce motion: an up phase (m_timer) followed by a down phase (m_timerDown).
class Unk_CmBounce
{
public:
    Unk_CmBounce(float fFrom, float fTo, unsigned nUnused, unsigned nMs);   // 0x14115e1c0
    float m_fFrom;                  // +0x00
    float m_fTo;                    // +0x04
    Timer m_timer;                  // +0x08
    Timer m_timerDown;              // +0x40
};
MS2_CHECK_SIZE(Unk_CmBounce, 0x78);

// Fade motion: lerps the alpha of the entity's transparency materials.
class Unk_CmFade
{
public:
    Unk_CmFade();                                                   // 0x14115e0e0
    Unk_CmFade(egf::EntityID id, float fFrom, float fTo, unsigned nMs, bool bHide);   // 0x14115dd90
    ~Unk_CmFade();                                                  // 0x14115e8b0
    void FUN_141161600();                                           // restore the materials
    float m_fFrom;                  // +0x00
    float m_fTo;                    // +0x04
    bool m_bHide;                   // +0x08
    Timer m_timer;                  // +0x10
    egf::EntityID m_id;             // +0x48
    Unk_CmMaterialList m_materials;   // +0x50
};
MS2_CHECK_SIZE(Unk_CmFade, 0x68);

class CCubeMotionManager : public TSingleton<CCubeMotionManager>
{
public:
    CCubeMotionManager();                                           // 0x14115b040
    virtual ~CCubeMotionManager();                                  // 0x14115b120 (scalar deleting 0x14115eca0)
    void AddScale(const egf::EntityID& id, float fFrom, float fTo, unsigned nMs);                     // 0x14115b1e0
    void AddRotate(egf::EntityID id, float fFrom, float fTo, unsigned nMs);                    // 0x14115b260
    void AddBounce(const egf::EntityID& id, float fFrom, float fTo, unsigned nUnused, unsigned nMs);  // 0x14115b2e0
    void AddFade(egf::EntityID id, float fFrom, float fTo, unsigned nMs, bool bHide);          // 0x14115b370
    void RemoveFade(egf::EntityID id);                       // 0x14115b430
    bool FUN_14115b4c0(const egf::EntityID& id, Unk_CmScale& out);  // 0x14115b4c0 (the entity has a scale motion)
    bool FUN_14115b500(const egf::EntityID& id, Unk_CmRotate& out); // 0x14115b500 (the entity has a rotate motion)
    void Update();                                                  // 0x14115b540

    ATL::CRBMap<egf::EntityID, Unk_CmScale> m_scale;                // +0x08
    ATL::CRBMap<egf::EntityID, Unk_CmRotate> m_rotate;              // +0x38
    ATL::CRBMap<egf::EntityID, Unk_CmBounce> m_bounce;              // +0x68
    ATL::CRBMap<egf::EntityID, Unk_CmFade> m_fade;                  // +0x98
};
MS2_CHECK_SIZE(CCubeMotionManager, 0xc8);
