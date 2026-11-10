// Group chat (CGroupChatMember / CGroupChat / CGroupChatManager); names from RTTI, Unk_ names are inferred.
// Owning unit: client\ms2\groupchatmanager.cpp (0x14137b010-0x141382b90 .text$mn, two original TUs).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/userproxy.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CGroupChatMember;
class CGroupChat;

// 16-byte intrusive pointer (pointer at +8) with a stealing move constructor. The exe instantiates it once per
// pointee in each of the two TUs of this unit; the original template name is unknown.
template <class T> class Unk_ChatPtr {
public:
    Unk_ChatPtr(Unk_ChatPtr&& o) { m_p = o.m_p; o.m_p = 0; }
    Unk_ChatPtr(const Unk_ChatPtr& o) { m_p = o.m_p; AddRef(); }
    Unk_ChatPtr(int) { m_p = 0; }
    Unk_ChatPtr(T* p) { m_p = p; AddRef(); }
    ~Unk_ChatPtr() { Release(); }
    Unk_ChatPtr& operator=(const Unk_ChatPtr& o) {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    bool operator==(T* p) const { return m_p == p; }
    T* get() const { return m_p; }
    operator T*() const { return m_p; }                 // 0x14194e5f0 (CGroupChatMember; folded [this+8] accessor)
    T* operator->() const { return m_p; }

private:
    void AddRef() const {
        if (m_p)
            AddRefImpl(0);
    }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() {
        if (m_p) {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    void ReleaseImpl(void*) {
        if (CPtred::ReleasePtred(m_p) == 0) {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }
    void* m_00;
    T* m_p;
};
MS2_CHECK_SIZE(Unk_ChatPtr<CGroupChatMember>, 0x10);

typedef Unk_ChatPtr<CGroupChatMember> Unk_ChatMemberPtr;
typedef Unk_ChatPtr<CGroupChat> Unk_ChatPtrChat;

// One participant: a user proxy plus the join state (1 = joined, 2 = invited).
class CGroupChatMember : public CPtred {
public:
    CGroupChatMember();
    virtual ~CGroupChatMember();
    int ReadFromPacket(CInPacket* packet);   // reads the state byte, then the proxy for state 1 and 2
    int FUN_14137b160() const;             // joined (state 1)

    Unk_UserProxy m_proxy;                  // +0x18
    int m_state;                            // +0x368
};
MS2_CHECK_SIZE(CGroupChatMember, 0x370);
MS2_CHECK_OFFSET(CGroupChatMember, m_proxy, 0x18);
MS2_CHECK_OFFSET(CGroupChatMember, m_state, 0x368);

class CGroupChat : public CPtred {
public:
    CGroupChat();
    virtual ~CGroupChat();
    unsigned GetOid() const;                  // oid
    int ReadFromPacket(CInPacket* packet);            // reads oid + members
    int HasMemberById(__int64 characterId);          // has a member with this id
    int HasMemberByName(CStringW name);                // has a member with this name
    int AddMember(Unk_ChatMemberPtr member);     // adds (max 20)
    void RemoveMember(CStringW name);               // removes by name
    void ClearMembers();                            // removes all
    Unk_ChatMemberPtr FindMemberById(__int64 characterId);
    Unk_ChatMemberPtr FindMemberByName(CStringW name);
    int GetMemberCount();                             // member count
    int FUN_14137bb00();                             // joined member count
    void GetMemberIds(ATL::CAtlList<__int64>& ids);
    void GetMembers(ATL::CAtlList<Unk_ChatMemberPtr>& out);
    void FUN_14137bdc0(ATL::CAtlList<Unk_ChatMemberPtr>& out);   // joined only
    void FUN_14137bee0(ATL::CAtlList<Unk_ChatMemberPtr>& out);   // not joined only

    unsigned m_oid;                                  // +0x18
    CLockCriticalSection m_lock;                     // +0x20
    ATL::CRBMap<CStringW, Unk_ChatMemberPtr> m_members;   // +0x50, keyed by name
};
MS2_CHECK_SIZE(CGroupChat, 0x80);
MS2_CHECK_OFFSET(CGroupChat, m_oid, 0x18);
MS2_CHECK_OFFSET(CGroupChat, m_lock, 0x20);
MS2_CHECK_OFFSET(CGroupChat, m_members, 0x50);

class CGroupChatManager : public TSingleton<CGroupChatManager> {
public:
    CGroupChatManager();
    virtual ~CGroupChatManager();
    void FUN_14137e160();
    void FUN_14137e190();
    void DumpChats();                            // debug dump
    CStringW GetLocalPlayerName();
    void AddChat(Unk_ChatPtrChat chat);
    void RemoveChat(unsigned oid);
    Unk_ChatPtrChat FindChat(unsigned oid);
    void FindChatsWithMember(__int64 characterId, ATL::CAtlList<unsigned>& oids);
    int GetChatCount();
    void Create(CStringW name);
    void Invite(unsigned oid, CStringW name);
    void SendGroupChatMode4(unsigned oid, int flag);
    void SendGroupChatMode10(unsigned oid, CStringW text);
    void OnGroupChat(CInPacket* packet);           // packet dispatcher
    void OnPacketAddChat(CInPacket* packet);
    void OnPacketChatCreated(CInPacket* packet);
    void FUN_14137f640(CInPacket* packet);
    void FUN_14137f790(CInPacket* packet);
    void OnPacketRemoveChat(CInPacket* packet);
    void OnPacketAddMember(CInPacket* packet);
    void OnPacketRemoveMember(CInPacket* packet);
    void OnPacketMemberOnline(CInPacket* packet);
    void OnPacketMemberOffline(CInPacket* packet);
    void OnPacketChatMessage(CInPacket* packet);
    void FUN_141380320(CInPacket* packet);
    void OnPacketMemberPicture(CInPacket* packet);
    void OnPacketResult(CInPacket* packet);

    CLockCriticalSection m_lock;                     // +0x08
    ATL::CRBMap<unsigned, Unk_ChatPtrChat> m_chats;  // +0x38, keyed by oid
};
MS2_CHECK_OFFSET(CGroupChatManager, m_lock, 0x8);
MS2_CHECK_OFFSET(CGroupChatManager, m_chats, 0x38);
