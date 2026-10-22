// chatemoticoncli.h - CChatEmoticonCli (RTTI .?AVCChatEmoticonCli@@, vftable 0x142e34698, CPtred-derived client state of
// the chat emoticon packs) and ChatEmoticonGroupInfo (RTTI, 0x28 bytes: one owned pack with its expiry time). The
// constructor / destructor of CChatEmoticonCli live in another unit (notifydebugstate range, 0x140d9ee70..); this header
// only declares them. Member names other than the RTTI class names are inferred from use.
#pragma once

#include <afx.h>
#include <list>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CInPacket;
class UIChatEmoticonDialog;

// One owned emoticon pack: the pack id and the (server time) it expires at. The exe's destructor is the implicit one
// (it only runs ~CPtred), the constructor is the inline one at 0x140a3d300.
class ChatEmoticonGroupInfo : public CPtred
{
public:
    ChatEmoticonGroupInfo() : m_nId(0), m_nExpire(0) {}

    unsigned m_nId;                                       // +0x18
    __int64 m_nExpire;                                  // +0x20
};
MS2_CHECK_SIZE(ChatEmoticonGroupInfo, 0x28);

class CChatEmoticonCli : public CPtred
{
public:
    CChatEmoticonCli();
    virtual ~CChatEmoticonCli();

    void FUN_140a38fa0(CInPacket& packet);              // 0: the full state (owned ids, then the packs with expiry)
    void FUN_140a39170(CInPacket& packet);              // 1: expired packs removed
    void FUN_140a39360(CInPacket& packet);              // 2: packs added (with a chat notice)
    void FUN_140a39720(CInPacket& packet);              // 5: one id moved to the end of the owned list
    void FUN_140a397b0(CInPacket& packet);              // 6: one id removed from the owned list
    void FUN_140a39830(CInPacket& packet);              // 3: a pack opened in the messenger browser
    void FUN_140a39940(CInPacket& packet);              // 4: a pack opened in the group messenger browser
    void FUN_140a39a20(CInPacket& packet);              // 7: result notice of a pack operation
    bool FUN_140a39dd0(int nEmoticonId);                // the pack of an emoticon is owned and not expired
    bool FUN_140a39fa0(int nEmoticonId);                // the emoticon is in the owned id list
    bool FUN_140a3a0b0(int nEmoticonId);                // the pack of an emoticon is unowned or expired
    bool FUN_140a3a140(unsigned nGroupId);                   // the pack is unowned or expired
    void FUN_140a3a290(unsigned nGroupId, __int64 nExpire);  // own a pack (replacing an old entry)
    void FUN_140a3a380(unsigned nGroupId);                   // forget a pack
    void SendMessenger();                               // report the expired packs to the server
    MS2Ptr<ChatEmoticonGroupInfo> FUN_140a3a640(unsigned nGroupId);   // the owned pack, or null
    void FUN_140a3a700(CInPacket& packet);              // packet dispatcher

    std::list<unsigned> m_ids;                                               // +0x18
    std::list<MS2Ptr<ChatEmoticonGroupInfo> > m_groups;                  // +0x28
    std::map<unsigned, MS2Ptr<ChatEmoticonGroupInfo> > m_groupById;           // +0x38
};
MS2_CHECK_SIZE(CChatEmoticonCli, 0x48);
