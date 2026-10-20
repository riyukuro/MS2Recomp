// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PhysX character-controller hit report.
// MS2-UNIT: ?\gameobjectcontrollerhitreport.cpp
// MS2-RANGE: 0x140cfad00-0x140cfb200 .text$mn
// MS2-RANGE: 0x1400d16f0-0x1400d19f0 .text$di
// MS2-PIN: ??__Es_nullEntityId@@YAXXZ 0x1400d16f0
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameobjectcontrollerhitreport.cpp"
#include "ms2/placeholder/ms2stdafx.h"

// The null entity id is the first static of the unit (exe: first .text$di entry), i.e. it comes before the statics
// the engine headers below define; its type is the game's egf::EntityID (8 bytes, ctor from a 64-bit id).
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static Unk_1401cd100 s_nullEntityId(NULL);

#include "gameobjectcontrollerhitreport.h"
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CPhysXHelper* FUN_1409f7ca0();
Unk_Entity* FUN_141689970(CPhysXHelper* pHelper, NxActor* pActor);   // entity owning an actor (null if none)
int FUN_140cfb1e0(const NxVec3& v);

// header statics, first inclusion
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
class Unk_1402a9d70
{
public:
    Unk_1402a9d70(int, float, float, float, int);
    ~Unk_1402a9d70();
private:
    void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48;
};
MS2_CHECK_SIZE(Unk_1402a9d70, 0x50);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
// header statics, second inclusion
static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140cfad00
GameObjectControllerHitReport::GameObjectControllerHitReport()
    : NxUserControllerHitReport(), m_normal(0.0f), m_entity(0), m_pOther(0), m_p28(0), m_bHit(0)
{
}

// @0x140cfada0
GameObjectControllerHitReport::~GameObjectControllerHitReport()
{
}

// @0x140cfade0
NxControllerAction GameObjectControllerHitReport::onShapeHit(const NxControllerShapeHit& hit)
{
    if (hit.shape != 0)
    {
        if (FUN_140cfb1e0(hit.worldNormal) == 0)
            return NX_ACTION_NONE;
        m_normal = hit.worldNormal;
        Unk_Entity* pEntity = FUN_141689970(FUN_1409f7ca0(), &hit.shape->getActor());
        if (pEntity != 0)
        {
            m_entity.FUN_1408b6ec0(pEntity);
            m_bHit = 1;
        }
        else
        {
            FUN_140cfaf30();
            m_bHit = 0;
        }
    }
    return NX_ACTION_NONE;
}
MS2_REPLACE_METHOD(0x140CFADE0, GameObjectControllerHitReport, onShapeHit, 212, 0x350ECD10);

// @0x140cfaec0
NxControllerAction GameObjectControllerHitReport::onControllerHit(const NxControllersHit& hit)
{
    m_pOther = hit.other;
    return NX_ACTION_NONE;
}
MS2_REPLACE_METHOD(0x140CFAEC0, GameObjectControllerHitReport, onControllerHit, 31, 0x3D697A76);

// @0x140cfaef0
NxVec3 GameObjectControllerHitReport::GetNormal() const
{
    return m_normal;
}
MS2_REPLACE_METHOD(0x140CFAEF0, GameObjectControllerHitReport, GetNormal, 46, 0x23D6DDA1);

// @0x140cfaf30
void GameObjectControllerHitReport::FUN_140cfaf30()
{
    m_entity = 0;
    m_bHit = 0;
}
MS2_REPLACE_METHOD(0x140CFAF30, GameObjectControllerHitReport, FUN_140cfaf30, 45, 0xB1B85EDE);

// @0x140cfaf70
egf::EntityID GameObjectControllerHitReport::GetEntityID() const
{
    if (m_entity.FUN_1408b70b0(0))
        return reinterpret_cast<const egf::EntityID&>(s_nullEntityId);
    return reinterpret_cast<egf::Entity*>(m_entity.FUN_1408a9280())->GetEntityID();
}
MS2_REPLACE_METHOD(0x140CFAF70, GameObjectControllerHitReport, GetEntityID, 112, 0x3DF814DF);

// @0x140cfaff0
Unk_Entity* GameObjectControllerHitReport::GetEntity() const
{
    return m_entity.FUN_1408a9090();
}
MS2_REPLACE_METHOD(0x140CFAFF0, GameObjectControllerHitReport, GetEntity, 31, 0x0110B063);

// @0x140cfb020
void GameObjectControllerHitReport::SetEntity(Unk_Entity* pEntity)
{
    m_entity.FUN_1408b6ec0(pEntity);
}
MS2_REPLACE_METHOD(0x140CFB020, GameObjectControllerHitReport, SetEntity, 41, 0x04B44E2C);

// @0x140cfb050
void* GameObjectControllerHitReport::GetOtherController() const
{
    return m_pOther;
}
MS2_REPLACE_METHOD(0x140CFB050, GameObjectControllerHitReport, GetOtherController, 15, 0xCBEE5D21);

// @0x140cfb070
void GameObjectControllerHitReport::ClearOtherController()
{
    m_pOther = 0;
}
MS2_REPLACE_METHOD(0x140CFB070, GameObjectControllerHitReport, ClearOtherController, 19, 0x13A4CB1D);

// @0x140cfb090
void GameObjectControllerHitReport::SetField28(void* p)
{
    m_p28 = p;
}
MS2_REPLACE_METHOD(0x140CFB090, GameObjectControllerHitReport, SetField28, 25, 0x8BB2CE0B);

// @0x140cfb0b0
void GameObjectControllerHitReport::ClearHit()
{
    m_bHit = 0;
}
MS2_REPLACE_METHOD(0x140CFB0B0, GameObjectControllerHitReport, ClearHit, 18, 0xFA94C07B);

// @0x140cfb0d0
int GameObjectControllerHitReport::GetHit() const
{
    return m_bHit;
}
MS2_REPLACE_METHOD(0x140CFB0D0, GameObjectControllerHitReport, GetHit, 14, 0x828204CF);

// @0x140cfb1e0
int FUN_140cfb1e0(const NxVec3& v)
{
    return v.isFinite();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4630-0x142ca4750 .text$yd
