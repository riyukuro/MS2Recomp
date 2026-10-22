// uihudentity.h - UIHudEntity (RTTI .?AVUIHudEntity@@, 0xf0 bytes) and its nested UIHudEntity::Entity (0x60) /
// UIHudEntity::TimerEntity (0xa0): the base of the world-anchored HUD widgets (UIBanner, UIBuffBalloon, UIChatBalloon,
// UIEmoticon, UIHpBar, UINameTag, UIPopupProfileImage, UIShieldBar, UITamingBar). NOT an original header (sb2);
// directory assumed (client\ms2 like uibanner.cpp). Owning unit ?\uihudentity.cpp (0x140f48b40-0x140f4ab4a,
// unrecovered): every out-of-line member below is a symbols-manual row.
//
// UIHudEntity: base UIObject, no new virtuals (vftable 0x142e7a5d8, 52 slots; IMessageListener vftable @+0x18
// 0x142e7a780). Overrides 0 (??_G 0x140f4a1b0), 1, 10, 15, 26, 41, 48; slot 22 stays UIObject::OnLoadComplete.
//   ctor 0x140f49590: m_68 = 0; m_70 = ""; m_78 (CAtlList, block 10); m_a8 (CAtlMap 17 bins, .75/.25/2.25, block 10);
//   m_28 = FUN_141277f40() (next UI layer). dtor 0x140f49670. Size 0xf0: UIService FUN_141adf580 does
//   operator new(0xf0) for UITamingBar, which adds no fields.
//   m_78 = live entities (AddTail of MS2Ptr<Entity>, 0x140ba9ff0); m_a8 = actor id -> entity (Lookup 0x140baaa90,
//   RemoveKey 0x140f4aa70; FUN_140f49740 iterates keys as int ids).
// Entity: CPtred base (vftable 0x142e7a518, 11 slots, 6 and 7 pure). ctor 0x140f48b40 (int layer, const GFx::Value&
//   cache clip, int actor id): m_38 = FUN_140ba77e0(layer, clip) (MS2Ptr<ASGameEntity>), m_28 = "Eff_UI" (the actor
//   node the widget follows: FUN_141675150(actor, m_28) -> m_20, cached for actor m_30, see slot 10).
// TimerEntity: Entity + m_60, m_64 (timer period ms, FUN_140868750(m_64)) + Timer at +0x68 (vftable 0x142e7a578).
//   Derived entities: UITamingBar::Entity new(0xc0), etc.
#pragma once
#include <atlcoll.h>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"          // MS2Ptr<T>
#include "ms2/placeholder/asgameentity.h"
#include "ms2/commonfiles/timer.h"

class PCBase;
class NiAVObject;

class UIHudEntity : public UIObject
{
public:
    class Entity : public CPtred
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);  // 0x140f48b40
        virtual ~Entity();                          //  0 0x140f48c70 (??_G 0x140f4a130)
        virtual void vfunc_1();                     //  1 0x140f48f20 reset (m_1c = 0, m_28 = "Eff_UI", m_20/m_30 = 0 ...)
        virtual void vfunc_2();                     //  2 0x140f48fb0 m_48 = m_4c = 1
        virtual void vfunc_3();                     //  3 0x140f48fe0 m_48 = m_4c = 0
        virtual void vfunc_4();                     //  4 0x140f49010 FUN_140f48dc0(0); vfunc_1()
        virtual void vfunc_5();                     //  5 0x140f49040 m_38->slot3(1); m_48 = 0
        virtual void vfunc_6(NiPoint3* pPos) = 0;   //  6 pure; place the clip (pPos: Point3 operator*= 0x140ad0c10)
        virtual void vfunc_7() = 0;                 //  7 pure
        virtual int vfunc_8(int n);                 //  8 0x140f490b0 (1 = drop the entity)
        virtual float vfunc_9();                    //  9 0x140f491d0 0.0f (vertical offset)
        virtual NiPoint3 vfunc_10();                // 10 0x140f491e0 anchor position (node m_20 or actor slot 18)

        void FUN_140f48ce0(int nActorId);           // m_1c = id; m_20 = m_30 = 0
        int FUN_140f48d20();                        // m_1c
        int FUN_140f48d40();                        // m_4c
        int FUN_140f48d60();                        // m_48
        void FUN_140f48d80();                       // m_48 = 1
        void FUN_140f48da0();                       // m_50 = 1
        void FUN_140f48dc0(int bVisible);           // if (m_38) m_38->slot3(b)
        float FUN_140f48e20();                      // actor FUN_140f4a450 (1e9 without an actor)
        int FUN_140f48e60();                        // m_58
        void FUN_140f48e80(int n);                  // set m_58 (0: FUN_140f48d80 first)
        MS2Ptr<ASGameEntity> FUN_140f48ed0();       // copy of m_38
        PCBase* FUN_140f49330();                    // the actor: world FUN_141bd1200(m_1c)

        int m_18;                            // +0x18 UI layer (ctor arg 1)
        int m_1c;                            // +0x1c actor id (ctor arg 3)
        NiAVObject* m_20;                    // +0x20 cached anchor node
        CStringA m_28;                       // +0x28 anchor node name ("Eff_UI")
        PCBase* m_30;                        // +0x30 actor m_20 was looked up on
        MS2Ptr<ASGameEntity> m_38;           // +0x38 the widget clip
        int m_48;                            // +0x48
        int m_4c;                            // +0x4c
        int m_50;                            // +0x50
        float m_54;                          // +0x54 max distance (compared with FUN_140f48e20)
        int m_58;                            // +0x58
    };

    class TimerEntity : public Entity
    {
    public:
        TimerEntity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);  // 0x140f49360
        virtual ~TimerEntity();                     //  0 0x140f49430 (??_G 0x140f4a170)
        virtual void vfunc_2();                     //  2 0x140f49490 Entity::vfunc_2(); m_68.FUN_140868750(m_64)
        virtual void vfunc_3();                     //  3 0x140f494d0 Entity::vfunc_3(); m_60 = 0; m_68.FUN_140868820()
        virtual int vfunc_8(int n);                 //  8 0x140f49540 (!m_60 && !m_68.FUN_140868ba0()) ? 1 : Entity::vfunc_8(n)

        void FUN_140f49470();                       // m_60 = 1

        int m_60;                            // +0x60
        int m_64;                            // +0x64 period (ms)
        Timer m_68;                          // +0x68
    };

    UIHudEntity();                                                  // 0x140f49590
    virtual ~UIHudEntity();                                         //  0 0x140f49670 (??_G 0x140f4a1b0)
    virtual CString GetTypeName();                                      //  1 0x140f496f0 "HudEntity"
    virtual void vfunc_10();                                        // 10 0x140f49930 FUN_140f49740()
    virtual void vfunc_15();                                        // 15 0x140f49950
    virtual void vfunc_26();                                        // 26 0x140f49900 FUN_140f49740(); UIObject::vfunc_26()
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x140f49de0
    virtual int vfunc_48();                                         // 48 0x140f4a710 0x4ee2

    void FUN_140f49740();                       // drop every entity (m_78.RemoveAll, m_a8.RemoveAll)
    int FUN_140f49890(int nActorId);            // 1 if the actor is gone (or a global flag is set)
    void FUN_140f49c00(int nActorId);           // release the actor's entity back to m_78
    void FUN_140f49cb0(int nActorId);           // m_a8[id]->FUN_140f48d80()
    void FUN_140f49d20();                       // FUN_140f48d80() on every mapped entity

    int m_68;                                            // +0x68 cache size (OnLoadComplete: createCache count)
    CStringA m_70;                                       // +0x70 cache clip name ("entity_TamingBar", ...)
    CAtlList<MS2Ptr<Entity>> m_78;                       // +0x78 free entities
    CAtlMap<int, MS2Ptr<Entity>> m_a8;                   // +0xa8 actor id -> entity
};
MS2_CHECK_SIZE(UIHudEntity::Entity, 0x60);
MS2_CHECK_OFFSET(UIHudEntity::Entity, m_18, 0x18);
MS2_CHECK_OFFSET(UIHudEntity::Entity, m_28, 0x28);
MS2_CHECK_OFFSET(UIHudEntity::Entity, m_38, 0x38);
MS2_CHECK_OFFSET(UIHudEntity::Entity, m_54, 0x54);
MS2_CHECK_OFFSET(UIHudEntity::Entity, m_58, 0x58);
MS2_CHECK_SIZE(UIHudEntity::TimerEntity, 0xa0);
MS2_CHECK_OFFSET(UIHudEntity::TimerEntity, m_60, 0x60);
MS2_CHECK_OFFSET(UIHudEntity::TimerEntity, m_68, 0x68);
MS2_CHECK_SIZE(UIHudEntity, 0xf0);
MS2_CHECK_OFFSET(UIHudEntity, m_68, 0x68);
MS2_CHECK_OFFSET(UIHudEntity, m_70, 0x70);
MS2_CHECK_OFFSET(UIHudEntity, m_78, 0x78);
MS2_CHECK_OFFSET(UIHudEntity, m_a8, 0xa8);
