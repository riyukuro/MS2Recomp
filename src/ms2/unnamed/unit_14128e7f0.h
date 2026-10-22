// unit_14128e7f0.h - UIBuffBalloon (RTTI .?AVUIBuffBalloon@@, 0xf0 bytes like UIHudEntity: no fields of its own, the
// swf "BuffBalloon" ui id 0x4ea4) and UIBuffBalloon::Entity (0xb0 bytes: TimerEntity + the buff id and the image path).
// The unit has no __FILE__ string (the name "uibuffballoon.cpp" was rejected by the unit map), so it lives under
// unnamed/. Member names are invented where the exe has none (FUN_<va> otherwise).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UIBuffBalloon : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x14128e7f0
        virtual ~Entity();                              //  0 0x14128e890 (??_G 0x14128f740)
        virtual void vfunc_2();                         //  2 0x14128e8e0 TimerEntity::vfunc_2() when FUN_140a18070
        virtual void vfunc_3();                         //  3 0x14128e920 TimerEntity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x14128e950 Entity::vfunc_4(); clear the buff
        virtual void vfunc_5();                         //  5 0x14128e9a0 "open"(imgPath)
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x14128eae0 place the clip (-55, -110)
        virtual void vfunc_7();                         //  7 0x14128ec00 hide the clip
        virtual int vfunc_8(int n);                     //  8 0x14128ec60
        virtual float vfunc_9();                        //  9 0x14128ecb0 vertical offset above the actor

        void FUN_14128ecf0(int nBuffId, CString strImg, int nTime);   // show the buff (image path, timer period)
        void FUN_14128edb0(int nBuffId);                // hide when it is this buff
        CString FUN_14128edf0();                        // m_a0 (image path)

        CString m_a0;                        // +0xa0 image path
        int m_a8;                            // +0xa8 buff id
    };

    UIBuffBalloon();                                    // 0x14128ee40
    virtual ~UIBuffBalloon();                           //  0 0x14128eeb0 (??_G 0x14128f780)
    virtual CString GetTypeName();                          //  1 0x14128eef0 "BuffBalloon"
    virtual void OnLoadComplete();                      // 22 0x14128ef40 UIObject::OnLoadComplete(); FUN_14128f030(m_68)
    virtual int vfunc_48() { return 0x4ea4; }           // 48 0x14128f7c0

    void FUN_14128f030(unsigned int nCount);            // create the entity cache
    Entity* FUN_14128f210(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIBuffBalloon::Entity, 0xb0);
MS2_CHECK_OFFSET(UIBuffBalloon::Entity, m_a0, 0xa0);
MS2_CHECK_OFFSET(UIBuffBalloon::Entity, m_a8, 0xa8);
MS2_CHECK_SIZE(UIBuffBalloon, 0xf0);
