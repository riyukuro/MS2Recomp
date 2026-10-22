// uibanner.h - UIBanner (RTTI .?AVUIBanner@@, 0x120 bytes: UIHudEntity (0xf0) + the listener map; the swf "Banner"
// ui id 0x4e30), UIBanner::Entity (0x68 bytes: UIHudEntity::Entity + the banner type) and the event listeners
// UIBannerEventListener / ...RpsGame / ...CoupleDance (0x18 bytes, CPtred + one virtual). Owning unit:
// client\ms2\uibanner.cpp (0x140ba8280-0x140bac2f0); the listeners' vfunc_1 bodies live in
// client\ms2\uibannereventlistener.cpp (0x140bac2f0-0x140bad0a0, unrecovered). Header name assumed from the unit
// path (w48).
#pragma once
#include <atlcoll.h>

#include "ms2/client/ms2/uihudentity.h"

class PCBase;

class UIBanner : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::Entity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x140ba8280
        virtual ~Entity();                              //  0 0x140ba8310 (??_G 0x140ba9eb0)
        virtual void vfunc_2();                         //  2 0x140ba8340 FUN_140ba8740("Eff_Foot_World"); Entity::vfunc_2()
        virtual void vfunc_3();                         //  3 0x140ba8390 Entity::vfunc_3(); vfunc_7()
        virtual void vfunc_4();                         //  4 0x140ba83c0 Entity::vfunc_4()
        virtual void vfunc_5();                         //  5 0x140ba83e0 "open"({type, gameOID})
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x140ba8540 place the clip 110 left of the anchor
        virtual void vfunc_7();                         //  7 0x140ba85e0 "close"
        virtual int vfunc_8(int n);                     //  8 0x140ba8640
        virtual float vfunc_9();                        //  9 0x140ba8690 vertical offset above the actor

        PCBase* FUN_140ba86d0();                        // the actor's player character (FUN_140974230(actor))
        int FUN_140ba8700();                            // m_60
        void FUN_140ba8720(int nType);                  // m_60 = nType
        void FUN_140ba8740(CString strNode);            // anchor node name: m_28 = name, m_20 = node of the actor

        int m_60;                            // +0x60 banner type (the listener key)
    };

    enum BannerType { BANNER_RPS_GAME = 1, BANNER_COUPLE_DANCE = 2 };   // the listener key (passed by const&)

    UIBanner();                                         // 0x140ba87d0
    virtual ~UIBanner();                                //  0 0x140ba8990 (??_G 0x140ba9ef0)
    virtual CString GetTypeName();                          //  1 0x140ba89e0 "Banner"
    virtual void OnLoadComplete();                      // 22 0x140ba8a30 UIObject::OnLoadComplete(); FUN_140ba8db0(m_68)
    virtual int vfunc_28(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ba8a60 "onClick"
    virtual int vfunc_48();                             // 48 0x140baa6b0 0x4e30

    void FUN_140ba8b80(int nActorId);                   // click: the banner's listener gets the entity
    void FUN_140ba8db0(unsigned int nCount);            // create the entity cache
    Entity* FUN_140ba8f90(int nActorId);                // the entity of the actor (created or recycled)
    Entity* FUN_140ba93d0(int nActorId);                // the live entity of the actor (0: none)

    ATL::CRBMap<BannerType, MS2Ptr<class UIBannerEventListener> > m_f0;    // +0xf0 banner type -> listener
};
MS2_CHECK_SIZE(UIBanner::Entity, 0x68);
MS2_CHECK_OFFSET(UIBanner::Entity, m_60, 0x60);
MS2_CHECK_SIZE(UIBanner, 0x120);
MS2_CHECK_OFFSET(UIBanner, m_f0, 0xf0);

class UIBannerEventListener : public CPtred
{
public:
    virtual ~UIBannerEventListener() = default;                               //  0 0x140ba9ce0 (??_G 0x140ba9f30)
    virtual void vfunc_1(MS2Ptr<UIBanner::Entity> pEntity) = 0;     //  1 pure: a banner was clicked
};
MS2_CHECK_SIZE(UIBannerEventListener, 0x18);

class UIBannerEventListenerRpsGame : public UIBannerEventListener
{
public:
    virtual ~UIBannerEventListenerRpsGame() = default;                        //  0 0x140ba9d20 (??_G 0x140ba9fb0)
    virtual void vfunc_1(MS2Ptr<UIBanner::Entity> pEntity);         //  1 0x140bac2f0 (uibannereventlistener.cpp)
};
MS2_CHECK_SIZE(UIBannerEventListenerRpsGame, 0x18);

class UIBannerEventListenerCoupleDance : public UIBannerEventListener
{
public:
    virtual ~UIBannerEventListenerCoupleDance() = default;                    //  0 0x140ba9d00 (??_G 0x140ba9f70)
    virtual void vfunc_1(MS2Ptr<UIBanner::Entity> pEntity);         //  1 0x140bac880 (uibannereventlistener.cpp)
};
MS2_CHECK_SIZE(UIBannerEventListenerCoupleDance, 0x18);
