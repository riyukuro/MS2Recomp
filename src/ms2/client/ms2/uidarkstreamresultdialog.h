// uidarkstreamresultdialog.h - UIDarkStreamResultDialog (RTTI .?AVUIDarkStreamResultDialog@@, 0x1b8 bytes: UIDialog +
// the result values, the reward items and their bag), the result window of the DarkStream ranking dungeon
// ("DarkStreamResultDialog", UI type 0x4ee5). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\uidarkstreamresultdialog.cpp` (0x140f345b0-0x140f35340 .text$mn, dir client\ms2). Header/unit name assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIDarkStreamResultDialog
// one at +0x18. Overridden slots: 1 (class name), 22 (OnLoadComplete), 28 (swf callbacks), 43 (root position), 48
// (UI type 0x4ee5), 67 (close, tells the server).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class CInPacket;

// The reward items (std::vector<ItemEntity>, 24 bytes) with the exe helpers this dialog calls.
class Unk_DarkStreamItems : public Unk_ItemVec
{
public:
    void FUN_1403fb160(const ItemEntity&);             // push_back
    ItemEntity& FUN_140be9400(size_t nIndex);           // element access
};
MS2_CHECK_SIZE(Unk_DarkStreamItems, 24);

class UIDarkStreamResultDialog : public UIDialog
{
public:
    UIDarkStreamResultDialog();                                      // 0x140f345b0
    virtual ~UIDarkStreamResultDialog();                             //  0 0x140f346e0 (??_G 0x140f352f0)
    virtual CString GetTypeName();                                       //  1 0x140f34760: "DarkStreamResultDialog"
    virtual void OnLoadComplete();                                   // 22 0x140f347b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                     // 28 0x140f34930
    virtual void vfunc_43();                                         // 43 0x140f34810
    virtual int vfunc_48();                                          // 48 0x140f35330: 0x4ee5
    virtual void vfunc_67();                                         // 67 0x140f348c0
    void FUN_140f34ab0(CInPacket& packet);                           // 0x140f34ab0 read the result packet
    void FUN_140f34cb0(bool bMode);                                  // 0x140f34cb0 swf "setMode"
    void FUN_140f34d50();                                            // 0x140f34d50 build the bag and send "setResult"
private:
    MS2_LAYOUT_FRIEND;
    int m_nValue0;                  // +0x178 the five result numbers read from the packet
    int m_nValue1;                  // +0x17c
    int m_nValue2;                  // +0x180
    int m_nValue3;                  // +0x184
    int m_nValue4;                  // +0x188
    bool m_bPending;                // +0x18c the result arrived before the movie loaded
    bool m_bMode;                   // +0x18d
    Unk_DarkStreamItems m_items;    // +0x190 the reward items
    CString m_strBagId;             // +0x1a8 name of the item bag shown by the swf
    CString m_strRankingUrl;        // +0x1b0 "maview:/rank/darkstream"
};
MS2_CHECK_SIZE(UIDarkStreamResultDialog, 0x1b8);
MS2_CHECK_OFFSET(UIDarkStreamResultDialog, m_items, 0x190);
MS2_CHECK_OFFSET(UIDarkStreamResultDialog, m_strBagId, 0x1a8);
