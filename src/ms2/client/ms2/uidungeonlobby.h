// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uidungeonlobby.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIDungeonLobby is a small dialog ("DungeonLobby", UI type 0x4f21) with a title text ("m_title"), a sub title
// ("m_subTitle") and a web guide button ("m_webGuideButton"). It reads the dungeon room id (m_178) and a second
// value (m_17c) from a server packet (opcode 0xf0, registered through the packet manager in the ctor).
// RTTI .?AVUIDungeonLobby@@, 0x1a0 bytes, vftables 0x142e43b58 (84 slots) and the IMessageListener one at +0x18.
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;

// The "m_webGuideButton" clip (an AS* wrapper). Class unknown.
class Unk_ASWebGuideButton : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int nVisible);                 // slot 4: SetVisible?
    void FUN_1422c00f0(float x, float y);               // set position
    void FUN_1422c0f60(float* pX, float* pY);           // get position
};

// The "m_title" text clip (an AS* wrapper). Class unknown.
class Unk_ASTitleText : public CPtred
{
public:
    void FUN_1422c4cd0(const CStringW& str);            // set text
    double FUN_1422c5970();                              // text width?
};

class UIDungeonLobby : public UIDialog
{
public:
    UIDungeonLobby();
    virtual ~UIDungeonLobby();                                      //  0

    virtual CString GetTypeName();                                      //  1 "DungeonLobby"
    virtual void OnLoadComplete();                                  // 22
    virtual void vfunc_26();                                        // 26
    virtual int vfunc_48() { return 0x4f21; }                       // 48 UI type id (COMDAT 0x140e18480)

    void FUN_140e17930(CInPacket& packet);                          // packet handler: reads m_178, m_17c

private:
    MS2_LAYOUT_FRIEND;
    int m_nRoomId;                                  // +0x178 read from the packet
    int m_n17c;                                     // +0x17c read from the packet
    MS2Ptr<Unk_ASWebGuideButton> m_pWebGuideButton; // +0x180 "m_webGuideButton"
    MS2Ptr<Unk_ASTitleText> m_pTitle;               // +0x190 "m_title"
};
MS2_CHECK_SIZE(UIDungeonLobby, 0x1a0);
MS2_CHECK_OFFSET(UIDungeonLobby, m_nRoomId, 0x178);
MS2_CHECK_OFFSET(UIDungeonLobby, m_n17c, 0x17c);
MS2_CHECK_OFFSET(UIDungeonLobby, m_pWebGuideButton, 0x180);
MS2_CHECK_OFFSET(UIDungeonLobby, m_pTitle, 0x190);
