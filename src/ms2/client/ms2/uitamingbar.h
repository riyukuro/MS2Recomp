// uitamingbar.h - UITamingBar (RTTI .?AVUITamingBar@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf
// "TamingBar" ui id 0x4f3b) and UITamingBar::Entity (0xc0 bytes: TimerEntity + the value pair, "open" the m_bar
// movie clip). Owning unit: ?\uitamingbar.cpp (0x140e97670-0x140e988a0). Header name assumed from the unit path (w4s10).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UITamingBar : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x140e97670
        virtual ~Entity();                              //  0 0x140e97750 (??_G 0x140e98810)
        virtual void vfunc_3();                         //  3 0x140e97780 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x140e977b0 Entity::vfunc_4(); reset the values
        virtual void vfunc_5();                         //  5 0x140e97830 "open"(m_a0, m_a8, m_b0); read m_barWidth
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x140e97910 push the value, place the clip
        virtual void vfunc_7();                         //  7 0x140e97b10 hide the clip
        virtual int vfunc_8(int n);                     //  8 0x140e97b70
        virtual float vfunc_9();                        //  9 0x140e97c50 vertical offset above the actor

        void FUN_140e97ca0(int n);                      // m_b4 = n
        int FUN_140e97cc0();                            // m_b4
        void FUN_140e97ce0(__int64 nCur);               // new value, restart the timer, vfunc_2()
        void FUN_140e97d70(__int64 nCur);               // new value
        void FUN_140e97e00();                           // m_b0 from the actor

        __int64 m_a0;                        // +0xa0 current value
        __int64 m_a8;                        // +0xa8 maximum value
        int m_b0;                            // +0xb0
        int m_b4;                            // +0xb4
        int m_b8;                            // +0xb8 value changed since the last vfunc_6
        float m_bc;                          // +0xbc m_bar clip width
    };

    UITamingBar();                                      // 0x140e97e50
    virtual ~UITamingBar();                             //  0 0x140e97ec0 (??_G 0x140e98850)
    virtual CString GetTypeName();                          //  1 0x140e97f00 "TamingBar"
    virtual void OnLoadComplete();                      // 22 0x140e97f50 UIObject::OnLoadComplete(); FUN_140e98040(m_68)
    virtual int vfunc_48() { return 0x4f3b; }           // 48 0x140e98890

    void FUN_140e98040(unsigned int nCount);            // create the entity cache
    Entity* FUN_140e98220(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UITamingBar::Entity, 0xc0);
MS2_CHECK_OFFSET(UITamingBar::Entity, m_a0, 0xa0);
MS2_CHECK_OFFSET(UITamingBar::Entity, m_bc, 0xbc);
MS2_CHECK_SIZE(UITamingBar, 0xf0);
