// commandchat.h - PLACEHOLDER for the chat command record (name unrecovered, no RTTI). NOT an original header.
// 0x20 bytes, built on the stack by the slash-command / notice senders and handed to FUN_141276f80 (chat send:
// whisper target check, chat penalty, field limit, then packet 0x11 written by FUN_1401fa700). One shared definition
// for what used to be eleven unit-local copies (Unk_PetChatCmd, Unk_ChatInput, Unk_ChaosChat, Unk_DpChat, Unk_PdChat,
// Unk_WmCommandChat, ...). The ctor/dtor are inline COMDATs owned by tabcontentspetevolution.cpp. FUN_141276f80 itself
// is declared by each caller (its owner unit_141274d10.cpp defines it with a pointer argument; same ABI).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"

class COutPacket;

struct Unk_CommandChat
{
    Unk_CommandChat();                                      // 0x140acd570: state 1, kind 0, value 0
    ~Unk_CommandChat();                                     // 0x140acd770
    void FUN_1401fa700(COutPacket& packet);                 // 0x1401fa700 write the chat packet body

    int state;                                              // +0x00
    int kind;                                               // +0x04 (4 = whisper)
    CStringW message;                                       // +0x08
    CStringW target;                                        // +0x10 the whisper recipient
    __int64 value;                                          // +0x18
};
MS2_CHECK_SIZE(Unk_CommandChat, 0x20);
