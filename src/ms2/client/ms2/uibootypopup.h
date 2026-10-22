// uibootypopup.h - UIBootyPopup (RTTI .?AVUIBootyPopup@@, 0x90 bytes, UIObject): the "BootyPopup" swf (ui id 0x4ebb),
// a world-anchored popup above a function-cube / loot object that shows the item name and description of the reward
// (the owner is CFunctionCubeObject, m_spBooty). Owning unit: ?\uibootypopup.cpp (0x141031430-0x141031f80). Header
// name assumed from the unit path. vftable 0x142ea0a78 (IMessageListener part +0x18); 53 slots, slot 52 is its own
// virtual. Same shape as UIBirdHead.
#pragma once
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"
#include <egf/EntityID.h>

class UIBootyPopup : public UIObject
{
public:
    UIBootyPopup();                                                 // 0x141031430
    virtual ~UIBootyPopup();                                        //  0 0x141031510 (??_G 0x141031f30)
    virtual CString GetTypeName();                                      //  1 0x141031550 "BootyPopup"
    virtual void vfunc_15();                                        // 15 0x1410317a0 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141031840
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141031ec0 movie loaded: m_30 = new ASGameEntity
    virtual int vfunc_48();                                         // 48 0x141031f70: 0x4ebb
    virtual void vfunc_52();                                        // 52 0x1410316f0 hide once the movie clip exists

    int FUN_1410315a0();                                            // m_74 (shown)
    void FUN_1410315c0();                                           // m_78 = m_74 = 1
    void FUN_1410315f0();                                           // unregister from the manager; m_78 = m_74 = 0
    void FUN_141031660(const Unk_StreamPoint& pt);                  // m_68 = pt (the world anchor)
    void FUN_141031690(const egf::EntityID& kId);                   // m_80 = kId
    void FUN_1410316d0(int nItemId);                                // m_88 = nItemId
    void FUN_141031890();                                           // project m_68 to the screen and move the movie
    void FUN_141031a60(int bShow);                                  // show/hide; on show push the item name + description

private:
    MS2_LAYOUT_FRIEND;
    Unk_StreamPoint m_68;               // +0x68 world anchor (starts as the zero point DAT_143b01a60)
    int m_74;                           // +0x74 shown
    int m_78;                           // +0x78 hide request pending
    int m_7c;                           // +0x7c state last sent to the swf
    egf::EntityID m_80;                 // +0x80 the owning entity
    int m_88;                           // +0x88 item id
    int m_pad_8c;
};
MS2_CHECK_SIZE(UIBootyPopup, 0x90);
MS2_CHECK_OFFSET(UIBootyPopup, m_68, 0x68);
MS2_CHECK_OFFSET(UIBootyPopup, m_74, 0x74);
MS2_CHECK_OFFSET(UIBootyPopup, m_80, 0x80);
MS2_CHECK_OFFSET(UIBootyPopup, m_88, 0x88);
