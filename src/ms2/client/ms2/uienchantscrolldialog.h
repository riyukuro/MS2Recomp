// uienchantscrolldialog.h - UIEnchantScrollDialog (RTTI .?AVUIEnchantScrollDialog@@, base UIDialog; 0x1e8 bytes): the item
// enchant scroll window (UI id 0x4ee0). The server opens it with a scroll (packet 0x71, reader FUN_140f3b920); the
// player drops an item on the EnchantScrollSlot, the window shows the stat change ("setData") and "onEnchant" sends the
// request (packet 0x71, subtype 2: scroll uid, item uid). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// header name assumed, member names invented. Ctor 0x140f3b490, dtor 0x140f3f140 (deleting 0x140f3f280).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class CInPacket;
class ASObj;
class CItem;
enum Unk_EsRank { Unk_EsRank_Min = 0 };       // the 4-byte rank ids of the scroll (an enum: the array glue is shared with the VIP ranks)

class UIEnchantScrollDialog : public UIDialog
{
public:
    UIEnchantScrollDialog();                                    // 0x140f3b490
    virtual ~UIEnchantScrollDialog() = default;                        //  0 0x140f3f140 (??_G 0x140f3f280)
    virtual CString GetTypeName();                                      //  1 0x140f3b530 "EnchantScrollDialog"
    virtual void vfunc_15();                                        // 15 0x140f3b810 (empty)
    virtual void OnLoadComplete();                                  // 22 0x140f3b650 shows the scroll
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f3b680 onEnchant
    virtual int vfunc_48();                                         // 48 0x140f3f4a0 0x4ee0
    virtual int vfunc_65();                                         // 65 0x140f3b580
    virtual void vfunc_67();                                        // 67 0x140f3b5b0 Close: drops the slot
    virtual void vfunc_72();                                        // 72 0x140f3b620
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x140f3b820 the "enchant_ok" answer

    void FUN_140f3b920(CInPacket& packet);                          // 0x140f3b920 packet: open with a scroll
    void FUN_140f3bd10(CInPacket& packet);                          // 0x140f3bd10 packet: an item was put on, fill the movie
    void FUN_140f3c6c0(CInPacket& packet);                          // 0x140f3c6c0 packet: the request result (0 = ask, else message)
    void FUN_140f3cb10();                                           // 0x140f3cb10 show the scroll and its limits
    void FUN_140f3d210();                                           // 0x140f3d210 reset to no scroll
    CStringW FUN_140f3d320(int nLevel, MS2Ptr<CItem> spItem, int bStable, int bRandom);   // 0x140f3d320 item name at a level
    void FUN_140f3d5b0(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet);   // 0x140f3d5b0 option rows of a level scroll
    void FUN_140f3db20(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet);   // 0x140f3db20 option rows of a random scroll
    CStringW FUN_140f3e390();                                       // 0x140f3e390 the scroll's effect value text
    CStringW FUN_140f3e550(MS2Ptr<CItem> spItem);                   // 0x140f3e550 the scroll's description
    CStringW FUN_140f3e730();                                       // 0x140f3e730 the failure text

private:
    MS2_LAYOUT_FRIEND;
    int m_nType;                                                    // +0x178 1 = enchant, 2 = restore, 3 = random, 5 = repair
    int m_nTargetLevel;                                             // +0x17c
    int m_nFailRate;                                                // +0x180 (percent)
    unsigned __int64 m_nScrollUid;                                  // +0x188
    unsigned __int64 m_nItemUid;                                    // +0x190
    bool m_bDisableBreak;                                           // +0x198
    short m_nLevelMin;                                              // +0x19a
    short m_nLevelMax;                                              // +0x19c
    ATL::CAtlArray<unsigned> m_equipTypes;                          // +0x1a0
    ATL::CAtlArray<Unk_EsRank> m_ranks;                               // +0x1c0
    unsigned m_nRandomMin;                                          // +0x1e0
    unsigned m_nRandomMax;                                          // +0x1e4
};
MS2_CHECK_SIZE(UIEnchantScrollDialog, 0x1e8);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_nType, 0x178);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_nScrollUid, 0x188);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_bDisableBreak, 0x198);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_equipTypes, 0x1a0);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_ranks, 0x1c0);
MS2_CHECK_OFFSET(UIEnchantScrollDialog, m_nRandomMin, 0x1e0);
