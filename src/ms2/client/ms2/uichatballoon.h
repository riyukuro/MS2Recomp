// uichatballoon.h - UIChatBalloon (RTTI .?AVUIChatBalloon@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf
// "PopupImageBalloon" ui id 0x4e2e, name "imageballoon_Ani") and UIChatBalloon::Entity (0xb8 bytes: TimerEntity + a
// flag, the skin name and the text). Owning unit: ?\uichatballoon.cpp (0x1418fafd0-0x1418fcee0). Header name assumed
// from the unit path (w13).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UIChatBalloon : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x1418fafd0
        virtual ~Entity();                              //  0 0x1418fb0b0 (??_G 0x1418fc5b0)
        virtual void vfunc_2();                         //  2 0x1418fb110 TimerEntity::vfunc_2()
        virtual void vfunc_3();                         //  3 0x1418fb130 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x1418fb160 Entity::vfunc_4(); clear the text
        virtual void vfunc_5();                         //  5 0x1418fb1c0 "open"(text, imgPath, bNpc, skin)
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x1418fb4a0 place the clip
        virtual void vfunc_7();                         //  7 0x1418fb580 "close"
        virtual int vfunc_8(int n);                     //  8 0x1418fb5e0
        virtual float vfunc_9();                        //  9 0x1418fb670 vertical offset above the actor

        bool FUN_1418fb6b0();                           // m_a0
        void FUN_1418fb6d0();                           // m_a0 = 1
        void FUN_1418fb6f0(const CString& strSkin);     // m_a8 = strSkin
        void FUN_1418fb730(const CStringW& strText);    // m_b0 = strText
        __int64 FUN_1418fb790();                        // player id of the actor (0 for a non player)
        CString FUN_1418fb7e0();                        // profile image path of the actor
        int FUN_1418fbbf0();                            // is the balloon allowed for this actor (config flags)

        bool m_a0;                           // +0xa0
        CString m_a8;                        // +0xa8 skin name
        CStringW m_b0;                       // +0xb0 text
    };

    UIChatBalloon();                                    // 0x1418fbc80
    virtual ~UIChatBalloon();                           //  0 0x1418fbcf0 (??_G 0x1418fc5f0)
    virtual CString GetTypeName();                          //  1 0x1418fbd30 "PopupImageBalloon"
    virtual void OnLoadComplete();                      // 22 0x1418fbd80 UIObject::OnLoadComplete(); FUN_1418fbe70(m_68)
    virtual int vfunc_48() { return 0x4e2e; }           // 48 0x1418fc630

    void FUN_1418fbe70(unsigned int nCount);            // create the entity cache
    Entity* FUN_1418fc050(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIChatBalloon::Entity, 0xb8);
MS2_CHECK_OFFSET(UIChatBalloon::Entity, m_a0, 0xa0);
MS2_CHECK_OFFSET(UIChatBalloon::Entity, m_a8, 0xa8);
MS2_CHECK_OFFSET(UIChatBalloon::Entity, m_b0, 0xb0);
MS2_CHECK_SIZE(UIChatBalloon, 0xf0);
