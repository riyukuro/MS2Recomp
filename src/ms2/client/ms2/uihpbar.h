// uihpbar.h - UIHpBar (RTTI .?AVUIHpBar@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf "HpBar" ui id
// 0x4e36) and its entity UIHpBar::Entity (0xc8 bytes: TimerEntity + the hp pair, the "open"/m_renderHp/m_guideHp gauge
// movie clips), plus the two UIHpBar subclasses of the same unit: UITombStoneBar (ui id 0x4e64, Entity 0xd0) and
// UISlimeEventBar (ui id 0x4e65, Entity 0xe0). Owning unit: ?\uihpbar.cpp (0x141991700-0x1419950d0). Header name assumed
// from the unit path (w20).
#pragma once
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/client/ms2/fielddatacli.h"   // Unk_GVec3 (out-of-line copy ctor 0x14027dcf0)

class Unk_HpClip;

class UIHpBar : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x141991700
        virtual ~Entity();                              //  0 0x141991810 (??_G 0x141994dc0)
        virtual void vfunc_3();                         //  3 0x141991840 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x141991870 Entity::vfunc_4(); clear the values
        virtual void vfunc_5();                         //  5 0x141991900 "open"(hp, max, level, relation); read m_guideHp
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x141991a80 push the hp, place the clip
        virtual void vfunc_7();                         //  7 0x141991d40 hide the clip
        virtual int vfunc_8(int n);                     //  8 0x141991da0 1 = drop the entity
        virtual float vfunc_9();                        //  9 0x141992100 vertical offset above the actor

        void FUN_141992140(int n);                      // m_b8 = n (shown)
        int FUN_141992160();                            // m_b8
        void FUN_141992180(__int64 nCur, __int64 nMax); // new hp pair, restart the timer, vfunc_2()
        void FUN_141992230(__int64 nCur, __int64 nMax); // new hp pair; flash on a boss-type hit
        void FUN_1419923b0();                           // m_38 size 100 x 100
        int FUN_1419923f0();                            // is the bar shown for this actor (config flags)
        int FUN_141992580();                            // refresh the relation (m_b4); 1 when it changed
        void FUN_141992680();                           // refresh the level (m_b0)

        __int64 m_a0;                        // +0xa0 current hp
        __int64 m_a8;                        // +0xa8 maximum hp
        unsigned short m_b0;                 // +0xb0 level (npc rank / pc: m_c4)
        int m_b4;                            // +0xb4 relation: 1 friendly, 0 hostile, -1 unknown
        int m_b8;                            // +0xb8 shown
        int m_bc;                            // +0xbc hp changed since the last vfunc_6
        int m_c0;                            // +0xc0 gauge clip width
        int m_c4;                            // +0xc4 pc level shown (100)
    };

    UIHpBar();                                          // 0x1419927f0
    virtual ~UIHpBar();                                 //  0 0x141992860 (??_G 0x141994e80)
    virtual CString GetTypeName();                          //  1 0x1419928a0 "HpBar"
    virtual void OnLoadComplete();                      // 22 0x1419928f0 UIObject::OnLoadComplete(); FUN_141993790(m_68)
    virtual int vfunc_48() { return 0x4e36; }           // 48 0x141994f40

    void FUN_141993790(unsigned int nCount);            // create the entity cache
    Entity* FUN_141993d30(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIHpBar::Entity, 0xc8);
MS2_CHECK_OFFSET(UIHpBar::Entity, m_a0, 0xa0);
MS2_CHECK_OFFSET(UIHpBar::Entity, m_b0, 0xb0);
MS2_CHECK_OFFSET(UIHpBar::Entity, m_c4, 0xc4);
MS2_CHECK_SIZE(UIHpBar, 0xf0);

class UITombStoneBar : public UIHpBar
{
public:
    class Entity : public UIHpBar::Entity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x141992a30
        virtual ~Entity();                              //  0 0x141992aa0 (??_G 0x141994e40)
        virtual void vfunc_5();                         //  5 0x141992ad0 UIHpBar::Entity::vfunc_5(); gotoAndPlay("start")
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x141992b30 place the clip 35 above the anchor
        virtual int vfunc_8(int n);                     //  8 0x141992c30
        virtual NiPoint3 vfunc_10();                    // 10 0x141992d50 the seat position of a seated pc

        void FUN_141992e40();                           // m_c8 = m_cc = 5; shown; restart the timer
        void FUN_141992ea0(int nHit, int nMax);         // gotoAndPlay("hit{n}")

        int m_c8;                            // +0xc8 hits left
        int m_cc;                            // +0xcc hits maximum
    };

    UITombStoneBar();                                   // 0x141992fd0
    virtual ~UITombStoneBar();                          //  0 0x141993040 (??_G 0x141994f00)
    virtual CString GetTypeName();                          //  1 0x141993080 "TombGaugeBar"
    virtual void OnLoadComplete();                      // 22 0x1419930d0 UIHpBar::OnLoadComplete(); FUN_141993b50(m_68)
    virtual int vfunc_48() { return 0x4e64; }           // 48 0x141994f60

    void FUN_141993b50(unsigned int nCount);            // create the entity cache
    Entity* FUN_1419945b0(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UITombStoneBar::Entity, 0xd0);
MS2_CHECK_OFFSET(UITombStoneBar::Entity, m_c8, 0xc8);
MS2_CHECK_SIZE(UITombStoneBar, 0xf0);

class UISlimeEventBar : public UIHpBar
{
public:
    class Entity : public UIHpBar::Entity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x1419931c0
        virtual ~Entity();                              //  0 0x141993260 (??_G 0x141994e00)
        virtual void vfunc_5();                         //  5 0x141993290 UIHpBar::Entity::vfunc_5()
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x1419932b0 place the clip 35 above the anchor
        virtual int vfunc_8(int n);                     //  8 0x1419933b0 UIHpBar::Entity::vfunc_8(n)

        void FUN_1419933e0();                           // shown; restart the timer
        void FUN_141993420(unsigned int nX, unsigned int nY, int nCur, int nMax);   // "setArrow" / "setValue"
        int FUN_141993560();                            // full

        int m_c8;                            // +0xc8 value
        int m_cc;                            // +0xcc maximum
        Unk_GVec3 m_d0;                      // +0xd0 (ZERO)
    };

    UISlimeEventBar();                                  // 0x1419935a0
    virtual ~UISlimeEventBar();                         //  0 0x141993610 (??_G 0x141994ec0)
    virtual CString GetTypeName();                          //  1 0x141993650 "SlimeEventBar"
    virtual void OnLoadComplete();                      // 22 0x1419936a0 UIHpBar::OnLoadComplete(); FUN_141993970(m_68)
    virtual int vfunc_48() { return 0x4e65; }           // 48 0x141994f50

    void FUN_141993970(unsigned int nCount);            // create the entity cache
    Entity* FUN_141994170(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UISlimeEventBar::Entity, 0xe0);
MS2_CHECK_OFFSET(UISlimeEventBar::Entity, m_d0, 0xd0);
MS2_CHECK_SIZE(UISlimeEventBar, 0xf0);
