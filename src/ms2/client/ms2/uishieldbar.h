// uishieldbar.h - UIShieldBar (RTTI .?AVUIShieldBar@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf
// "ShieldBar" ui id 0x4f77) and UIShieldBar::Entity (0xc0 bytes: TimerEntity + the shield value pair, "open" the
// m_shield/m_gauge movie clips). Owning unit: ?\uishieldbar.cpp (0x140e855f0-0x140e86d80). Header name assumed from
// the unit path (w4s10).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UIShieldBar : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x140e855f0
        virtual ~Entity();                              //  0 0x140e856c0 (??_G 0x140e86b70)
        virtual void vfunc_3();                         //  3 0x140e856f0 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x140e85720 Entity::vfunc_4(); clear the values
        virtual void vfunc_5();                         //  5 0x140e85790 "open"(m_a0, m_a8); read the gauge width
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x140e85970 push the shield value, place the clip
        virtual void vfunc_7();                         //  7 0x140e85cf0 m_shield "_hide"
        virtual int vfunc_8(int n);                     //  8 0x140e85dd0
        virtual float vfunc_9();                        //  9 0x140e85e60 vertical offset above the actor

        void FUN_140e85ed0(int n);                      // m_b0 = n (shield shown)
        int FUN_140e85ef0();                            // m_b0
        void FUN_140e85f10(__int64 nCur, __int64 nMax); // new value pair, restart the timer, vfunc_2()
        void FUN_140e85fc0(__int64 nCur, __int64 nMax); // new value pair; hide when empty
        void FUN_140e86090();                           // m_38 size 100 x 100
        int FUN_140e860f0();                            // is the shield shown for this actor (config flags)

        __int64 m_a0;                        // +0xa0 current shield
        __int64 m_a8;                        // +0xa8 maximum shield
        int m_b0;                            // +0xb0
        int m_b4;                            // +0xb4 value changed since the last vfunc_6
        int m_b8;                            // +0xb8 gauge clip width
    };

    UIShieldBar();                                      // 0x140e861f0
    virtual ~UIShieldBar();                             //  0 0x140e86260 (??_G 0x140e86bb0)
    virtual CString GetTypeName();                          //  1 0x140e862a0 "ShieldBar"
    virtual void OnLoadComplete();                      // 22 0x140e862f0 UIObject::OnLoadComplete(); FUN_140e86430(m_68)
    virtual int vfunc_48() { return 0x4f77; }           // 48 0x140e86bf0

    void FUN_140e86430(unsigned int nCount);            // create the entity cache
    Entity* FUN_140e86610(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIShieldBar::Entity, 0xc0);
MS2_CHECK_OFFSET(UIShieldBar::Entity, m_a0, 0xa0);
MS2_CHECK_OFFSET(UIShieldBar::Entity, m_b8, 0xb8);
MS2_CHECK_SIZE(UIShieldBar, 0xf0);
