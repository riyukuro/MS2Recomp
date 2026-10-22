// uidebugtooltip.h - UIDebugTooltip (RTTI .?AVUIDebugTooltip@@, 0xa0 bytes, UIObject): the small world-anchored debug
// tooltip ("CubeUGCHead" swf, ui id 0x4e71). Owning unit: ?\uidebugtooltip.cpp (0x14191a7e0-0x14191b380). Header name
// assumed from the unit path. vftable 0x142f9f868 (53 slots; 52 is its own virtual), IMessageListener-in-UIDebugTooltip
// 0x142f9fa18.
#pragma once
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"

class UIDebugTooltip : public UIObject
{
public:
    UIDebugTooltip(CString strName);                                // 0x14191a7e0
    virtual ~UIDebugTooltip();                                      //  0 0x14191a920 (??_G 0x14191b330)
    virtual CString GetTypeName();                                      //  1 0x14191a9a0 "CubeUGCHead"
    virtual void vfunc_2();                                         //  2 0x14191ad10 show
    virtual void vfunc_3();                                         //  3 0x14191ad60 hide
    virtual void vfunc_15();                                        // 15 0x14191b060 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14191b0f0
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x14191b2c0 movie loaded: m_30 = new ASGameEntity
    // @0x14191b370
    virtual int vfunc_48() { return 0x4e71; }                       // 48
    virtual void vfunc_52();                                        // 52 0x14191ada0 push the texts to the movie

    int FUN_14191a9f0();                                            // m_78 (shown)
    void FUN_14191aa10();                                           // m_78 = m_7c = 1
    void FUN_14191aa40();                                           // m_78 = m_7c = 0
    void FUN_14191aa70();                                           // unregister from the manager; m_78 = m_7c = 0
    void FUN_14191aae0(const Unk_StreamPoint& pt);                  // m_6c = pt (the world anchor)
    void FUN_14191ab10(CStringW strText);                           // m_88 = text; m_7c = 1
    void FUN_14191ab70(CStringW strAdditional);                     // m_90 = text; m_7c = 1
    void FUN_14191abd0();                                           // toggle the "additional" text
    void SetFollowsAnchor(int bFollow) { m_68 = bFollow; }          // inline (portal.cpp writes +0x68 directly)
    void FUN_14191b140();                                           // project m_6c to the screen and move the movie

private:
    MS2_LAYOUT_FRIEND;
    int m_68;                           // +0x68 1: follows the world anchor
    Unk_StreamPoint m_6c;               // +0x6c world anchor (starts as the zero point DAT_143b01a60)
    int m_78;                           // +0x78 shown
    int m_7c;                           // +0x7c texts dirty
    int m_80;                           // +0x80 additional text visible
    int m_pad_84;
    CStringW m_88;                      // +0x88 main text
    CStringW m_90;                      // +0x90 additional text
    CString m_98;                       // +0x98 name given to the ctor
};
MS2_CHECK_SIZE(UIDebugTooltip, 0xa0);
MS2_CHECK_OFFSET(UIDebugTooltip, m_68, 0x68);
MS2_CHECK_OFFSET(UIDebugTooltip, m_6c, 0x6c);
MS2_CHECK_OFFSET(UIDebugTooltip, m_88, 0x88);
MS2_CHECK_OFFSET(UIDebugTooltip, m_98, 0x98);
