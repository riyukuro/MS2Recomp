// uibirdhead.h - UIBirdHead (RTTI .?AVUIBirdHead@@, 0xa4 bytes, UIObject): the bird's-head tooltip anchored to a world
// position ("BirdHead" swf, ui id 0x4e84). Owning unit: ?\uibirdhead.cpp (0x1418ce5e0-0x1418cf080). Header name assumed
// from the unit path. Same shape as UIDebugTooltip. vftable 0x142f949f0 (IMessageListener part 0x142f94ba0); 53 slots, 52 is its own virtual.
#pragma once
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"

class UIBirdHead : public UIObject
{
public:
    UIBirdHead();                                                   // 0x1418ce5e0
    virtual ~UIBirdHead();                                          //  0 0x1418ce710 (??_G 0x1418cf030)
    virtual CString GetTypeName();                                      //  1 0x1418ce790 "BirdHead"
    virtual void vfunc_15();                                        // 15 0x1418ced90 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1418cee20
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x1418cefc0 movie loaded: m_30 = new ASGameEntity
    // @0x1418cf070
    virtual int vfunc_48() { return 0x4e84; }                       // 48
    virtual void vfunc_52();                                        // 52 0x1418ceb10 push the texts to the movie

    int FUN_1418ce7e0();                                            // m_78 (shown)
    void FUN_1418ce800();                                           // m_78 = m_7c = 1
    void FUN_1418ce890();                                           // m_78 = m_7c = 0
    void FUN_1418ce830();                                           // unregister from the manager
    void FUN_1418ce8c0(const Vector3& pt);                  // m_6c = pt (the world anchor)
    void FUN_1418ce8f0(CStringW strMain, CStringW strExtra);        // m_88 = main, m_98 = extra; m_7c = 1
    void FUN_1418ce970(CStringW strAdditional);                     // m_90 = text; m_7c = 1
    void FUN_1418ce9d0();                                           // toggle the "additional" text
    void FUN_1418cee70();                                           // project m_6c to the screen and move the movie

private:
    MS2_LAYOUT_FRIEND;
    int m_68;                           // +0x68 1
    Vector3 m_6c;               // +0x6c world anchor (starts as the zero point DAT_143b01a60)
    int m_78;                           // +0x78 shown
    int m_7c;                           // +0x7c texts dirty
    int m_80;                           // +0x80 additional text visible
    int m_pad_84;
    CStringW m_88;                      // +0x88 main text
    CStringW m_90;                      // +0x90 additional text
    CStringW m_98;                      // +0x98 extra text
    float m_a0;                         // +0xa0 y offset of the screen position
};
MS2_CHECK_SIZE(UIBirdHead, 0xa8);
MS2_CHECK_OFFSET(UIBirdHead, m_68, 0x68);
MS2_CHECK_OFFSET(UIBirdHead, m_6c, 0x6c);
MS2_CHECK_OFFSET(UIBirdHead, m_88, 0x88);
MS2_CHECK_OFFSET(UIBirdHead, m_a0, 0xa0);
