// uinametag.h - UINameTag (RTTI .?AVUINameTag@@, 0xf0 bytes like UIHudEntity: no fields of its own, the swf "NameTag"
// ui id 0x4e5a) and UINameTag::Entity (0x80 bytes: UIHudEntity::Entity + font size/colour, the measured text width,
// the skin name and the two "visible" flags). Owning unit: ?\uinametag.cpp (0x141a5e3c0-0x141a623e0). Header name
// assumed from the unit path (w13).
#pragma once
#include "ms2/client/ms2/uihudentity.h"

class UINameTag : public UIHudEntity
{
public:
    class Entity : public UIHudEntity::Entity
    {
    public:
        Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId);   // 0x141a5e3c0
        virtual ~Entity();                              //  0 0x141a5e480 (??_G 0x141a62230)
        virtual void vfunc_1();                         //  1 0x141a5e6e0 reset (font 18, white, no text, both flags on)
        virtual void vfunc_2();                         //  2 0x141a5e760 Entity::vfunc_2()
        virtual void vfunc_3();                         //  3 0x141a5e780 Entity::vfunc_3(); m_68 = 0
        virtual void vfunc_4();                         //  4 0x141a5e7b0 Entity::vfunc_4(); reset the look
        virtual void vfunc_5();                         //  5 0x141a5e810 push the data (by mode), measure the text
        virtual void vfunc_6(NiPoint3* pPos);           //  6 0x141a5e8d0 fade by distance, place the clip
        virtual void vfunc_7();                         //  7 0x141a5eb80 clip slot 3 (hide)
        virtual int vfunc_8(int n);                     //  8 0x141a5ebe0 (1 = drop the entity)
        virtual float vfunc_9();                        //  9 0x141a5eea0 vertical offset above the actor
        virtual NiPoint3 vfunc_10();                    // 10 0x141a5edb0 anchor (the rider seat of a mounted player)

        void FUN_141a5e4c0(int nFontSize);              // font size (0 = keep)
        void FUN_141a5e500(int nColor);                 // font colour
        void FUN_141a5e540(CString strNode);            // anchor node name of the actor
        int FUN_141a5e5d0(float* pPos);                 // clip position, centred on the text (0 = no clip)
        int FUN_141a5e690();                            // clip visible
        void FUN_141a5f040(const CString& strSkin);            // skin name; mark dirty
        void FUN_141a5f080();                           // setData with the debug dump (mode 2)
        void FUN_141a5ff60();                           // setData with name, guild, symbol (mode 1)
        bool FUN_141a60920();                           // is the tag shown for this actor (config flags)
        void FUN_141a60b90(int nVisibleSymbol, int nVisibleName);

        int m_60;                            // +0x60 font size (18)
        int m_64;                            // +0x64 font colour (0xffffff)
        unsigned int m_68;                   // +0x68 measured text width
        CString m_70;                        // +0x70 skin name
        int m_78;                            // +0x78 visibleName
        int m_7c;                            // +0x7c visibleSymbol
    };

    UINameTag();                                        // 0x141a60c00
    virtual ~UINameTag();                               //  0 0x141a60c70 (??_G 0x141a62270)
    virtual CString GetTypeName();                          //  1 0x141a60cb0 "NameTag"
    virtual void OnLoadComplete();                      // 22 0x141a60d00 UIObject::OnLoadComplete(); FUN_141a60f70(m_68)
    virtual int vfunc_48() { return 0x4e5a; }           // 48 0x141a622b0

    void FUN_141a60f70(unsigned int nCount);            // create the entity cache
    Entity* FUN_141a61150(int nActorId);                // the entity of the actor (created or recycled)
};
MS2_CHECK_SIZE(UINameTag::Entity, 0x80);
MS2_CHECK_OFFSET(UINameTag::Entity, m_60, 0x60);
MS2_CHECK_OFFSET(UINameTag::Entity, m_68, 0x68);
MS2_CHECK_OFFSET(UINameTag::Entity, m_70, 0x70);
MS2_CHECK_OFFSET(UINameTag::Entity, m_78, 0x78);
MS2_CHECK_OFFSET(UINameTag::Entity, m_7c, 0x7c);
MS2_CHECK_SIZE(UINameTag, 0xf0);
