// uipopupprofileimage.h - UIPopupProfileImage (RTTI .?AVUIPopupProfileImage@@, 0xf0 bytes like UIHudEntity: no fields of
// its own, the swf "PopupProfileImage" ui id 0x4e57, name "profile_ugc_balloon") and UIPopupProfileImage::Entity (0xa8
// bytes: TimerEntity + one int). Owning unit: ?\uipopupprofileimage.cpp (0x141a8f3a0-0x141a904f0). Header name assumed
// from the unit path (w4s10).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UIPopupProfileImage : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::TimerEntity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x141a8f3a0
        virtual ~Entity();                              //  0 0x141a8f450 (??_G 0x141a90320)
        virtual void vfunc_2();                         //  2 0x141a8f480 TimerEntity::vfunc_2()
        virtual void vfunc_3();                         //  3 0x141a8f4a0 TimerEntity::vfunc_3(); "close"
        virtual void vfunc_4();                         //  4 0x141a8f510 Entity::vfunc_4(); m_a0 = 0
        virtual void vfunc_5();                         //  5 0x141a8f540 "open"(imgPath, dead)
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x141a8f790 place the clip
        virtual void vfunc_7();                         //  7 0x141a8f880 reset the profile popup; "close"
        virtual int vfunc_8(int n);                     //  8 0x141a8f920

        int m_a0;                            // +0xa0
    };

    UIPopupProfileImage();                              // 0x141a8fa20
    virtual ~UIPopupProfileImage();                     //  0 0x141a8fa90 (??_G 0x141a90360)
    virtual CString GetTypeName();                          //  1 0x141a8fad0 "PopupProfileImage"
    virtual void OnLoadComplete();                      // 22 0x141a8fb20 UIObject::OnLoadComplete(); FUN_141a8fc30(m_68)
    virtual int vfunc_48() { return 0x4e57; }           // 48 0x141a903a0

    void FUN_141a8fc30(unsigned int nCount);            // create the entity cache
    Entity* FUN_141a8fe10(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UIPopupProfileImage::Entity, 0xa8);
MS2_CHECK_OFFSET(UIPopupProfileImage::Entity, m_a0, 0xa0);
MS2_CHECK_SIZE(UIPopupProfileImage, 0xf0);
