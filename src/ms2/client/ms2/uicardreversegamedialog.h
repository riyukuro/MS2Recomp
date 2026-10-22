// uicardreversegamedialog.h - the card reverse game page (RTTI UICardReverseGameDialog, UI id 0x4f02): the player
// shuffles a deck of reward cards, picks one and the server answers with the opened reward (opcode 0xda, request opcode
// 0x86). NOT an original header (the unit is ?\uicardreversegamedialog.cpp). Member and helper names are invented
// from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class UIMsg;
class UISwfEntity;
class ASData;

class UICardReverseGameDialog : public UIDialog
{
public:
    // One reward card of the deck (a ref-counted record, 0x30 bytes).
    class CardReward : public CPtred
    {
    public:
        CardReward();                                   // 0x140f28d70
        virtual ~CardReward() = default;                // 0x140f28e50 (??_G 0x140f29040)
        int m_nIndex;                                   // +0x18 position in the packet
        int m_nItemId;                                  // +0x1c
        int m_nRank;                                    // +0x20 1
        int m_nCount;                                   // +0x24
        CString m_strBindId;                            // +0x28 the item slot key
    };

    UICardReverseGameDialog();                          // 0x140f26990
    virtual ~UICardReverseGameDialog() = default;        // 0x140f28e80 (??_G 0x140f29080)
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void OnLoadInit();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_43();
    // @0x140f29340
    virtual int vfunc_48() { return 0x4f02; }
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_79(void* p);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);

    void OnCardTweenComplete();                               // refresh the "select" info text

private:
    MS2_LAYOUT_FRIEND;
    void* m_178;                                        // +0x178 (not touched by the ctor)
    ATL::CAtlArray<CString> m_180;                      // +0x180 the item slot keys that are bound
    int m_1a0;                                          // +0x1a0 slot key counter
    ATL::CAtlArray<MS2Ptr<CardReward> > m_1a8;          // +0x1a8 the deck as the server sent it
    ATL::CAtlArray<MS2Ptr<CardReward> > m_1c8;          // +0x1c8 the shuffled cards not opened yet
    int m_1e8;                                          // +0x1e8 the play item (name table id)
    unsigned m_1ec;                                     // +0x1ec play count
    int m_1f0;                                          // +0x1f0 the clicked card (-1 none)
    int m_1f4;                                          // +0x1f4 cards left to pick
    MS2Ptr<CardReward> m_1f8;                           // +0x1f8 the picked card
};
MS2_CHECK_SIZE(UICardReverseGameDialog, 0x208);
MS2_CHECK_SIZE(UICardReverseGameDialog::CardReward, 0x30);
MS2_CHECK_OFFSET(UICardReverseGameDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UICardReverseGameDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UICardReverseGameDialog, m_1c8, 0x1c8);
MS2_CHECK_OFFSET(UICardReverseGameDialog, m_1f8, 0x1f8);
