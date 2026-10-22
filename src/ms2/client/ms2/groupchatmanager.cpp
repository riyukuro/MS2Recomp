// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Group chat members, chats and the manager singleton.
// MS2-UNIT: client\ms2\groupchatmanager.cpp
// MS2-RANGE: 0x14137b010-0x141382b90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$Log@$$BY0BK@DV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Unk_TimeLogger@@QEAAXHHPEB_WAEAY0BK@$$CBDAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x141380bf0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: memmove_s 0x14137df60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\groupchatmanager.cpp"
// MS2-PIN: ?FUN_14137e160@CGroupChatManager@@QEAAXXZ 0x14137e160
#include "ms2/placeholder/ms2stdafx.h"
#include "groupchatmanager.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uimessagebox.h"
#include "blockmanager.h"
#include "hook/ms2hook.h"

// ---------------------------------------------------------------------------------------------------------------
// Unit-local views of exe objects used by the packet handlers.
// ---------------------------------------------------------------------------------------------------------------
// Logger singleton (same shape as commonfiles\timeutil.cpp): Log(category, level, format, args...) forwards to
// 0x1406530d0 with a packed fmt::ArgList.
class Unk_TimeLogger {
public:
    void Log(int category, int level, const wchar_t* format, const fmt::ArgList& args);   // 0x1406530d0
#define MS2_LOG_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline void Log(int category, int level, const wchar_t* format, FMT_GEN(n, FMT_MAKE_ARG)) \
    { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_wchar_t)}; \
        Log(category, level, format, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
    MS2_LOG_WRAP(2)
    MS2_LOG_WRAP(3)
};
Unk_TimeLogger* FUN_140166440();


// The local player object (vtable slot 77 returns the display name).
class Unk_ChatPlayer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual CStringW vfunc_77();
};
// The camera option row of the game context (flags tested by FUN_140375660) and its smart pointer (pointer at +8).
struct Unk_CameraOption {
    int FUN_140375660(int flags);
};
class Unk_CameraOptionPtr {
public:
    ~Unk_CameraOptionPtr();                          // 0x1408850f0
    Unk_CameraOption* FUN_140885340() const;         // operator->
private:
    void* m_00;
    Unk_CameraOption* m_p;
};
// The game context (FUN_1403ed2d0).
class Unk_ChatGame {
public:
    Unk_ChatPlayer* FUN_141bd0cc0();
    Unk_CameraOptionPtr FUN_141bd30a0();             // copy of +0x298
};
Unk_ChatGame* FUN_1403ed2d0();
// The chat window controller (+0x50 of the UI root FUN_141482e80).
class Unk_ChatMessenger {
public:
    void FUN_1419515c0(int oid);
    void FUN_141951720(int oid, const CStringW& a, const CStringW& b);
    void FUN_1419517b0(int oid, const CStringW& a, const CStringW& b);
    void FUN_1419519a0(int oid);
    void FUN_1419519e0(int oid, const CStringW& a, const CStringW& b);
    void FUN_141951a70(int oid, const CStringW& name, int flag);
    void FUN_141951af0(int oid, const CStringW& name);
    void FUN_141951b70(int oid, const CStringW& name);
    void FUN_141951bf0(int oid, const CStringW& name, const CStringW& text);
    void FUN_141951c50(int oid, const CStringW& a, const CStringW& b);
    void FUN_141951d80(int oid, const CStringW& name, CInPacket* packet);
};
class Unk_ChatUI {
public:
    void* m_pad_00[10];
    Unk_ChatMessenger* m_messenger;                  // +0x50
};
Unk_ChatUI* FUN_141482e80();
// Profile image notifier (slot 1 receives the character id and the picture name).
class Unk_ChatPictureSink {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(__int64 characterId, CString picture);
};
Unk_ChatPictureSink* FUN_140bc09f0();
// Client options (+6: refuses group chat invitations).
struct Unk_ChatSettings {
    char m_pad_00[6];
    unsigned char m_refuseInvite;
};
class Unk_ChatOptions;
Unk_ChatOptions* FUN_1409a8b10();
Unk_ChatSettings* FUN_140ae6540(Unk_ChatOptions*);
// Misc exe helpers.
void FUN_1412751b0(const CStringW& text, int channel);
CStringW FUN_14052bd00(int id, const CStringW& arg);
CStringW GetStringCommon(int id);
CString FUN_14016a600(const wchar_t* text, int codepage);
CString FUN_141028be0(__int64 id, const CString& a, int b, CString c);
void FUN_140710590(COutPacket& packet);
Unk_MessageBoxPtr FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(Unk_MessageBoxPtr);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140d73bc0(int, int, void*, CStringW);
void* FUN_140534fc0(const Unk_MessageBoxPtr&);
void* FUN_140534fe0(const Unk_MessageBoxPtr&);
Unk_MessageBoxPtr FUN_14151f820();
const CStringW& FUN_141a02ce0(void* messageBoxData);
CBlockManager* FUN_140a6a830();
bool FUN_14025cd60(const CStringW&, const CStringW&);


// ---------------------------------------------------------------------------------------------------------------
// TU 1: CGroupChatMember / CGroupChat
// ---------------------------------------------------------------------------------------------------------------
// @0x14137b010
CGroupChatMember::CGroupChatMember() {
    m_state = 0;
    m_proxy.FUN_1408ebe30();
}
// @0x14137b080
CGroupChatMember::~CGroupChatMember() {}
// @0x14137b0c0
int CGroupChatMember::FUN_14137b0c0(CInPacket* packet) {
    m_state = packet->vfunc_o8_1();
    if (m_state == 1) {
        m_proxy.FUN_1408eeb60(packet);
    } else if (m_state == 2) {
        m_proxy.FUN_1408eeb60(packet);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14137B0C0, CGroupChatMember, FUN_14137b0c0, 146, 0xFD59E421);
// @0x14137b160
int CGroupChatMember::FUN_14137b160() const { if (m_state == 1) return true; return false; }
MS2_REPLACE_METHOD(0x14137B160, CGroupChatMember, FUN_14137b160, 29, 0xCDE002C2);

// @0x14137b190
CGroupChat::CGroupChat() : m_oid(0) {}
// @0x14137b200
CGroupChat::~CGroupChat() { m_members.RemoveAll(); }
// @0x14137b260
unsigned CGroupChat::GetOid() const { return m_oid; }
MS2_REPLACE_METHOD(0x14137B260, CGroupChat, GetOid, 14, 0x72E52537);
// @0x14137b280
int CGroupChat::FUN_14137b280(CInPacket* packet) {
    m_oid = packet->vfunc_o8_3();
    int count = packet->vfunc_o8_1();
    for (int i = 0; i < count; ++i) {
        Unk_ChatMemberPtr member(new CGroupChatMember);
        if (member->FUN_14137b0c0(packet) == 0)
            return 0;
        if (FUN_14137b680(member) == 0)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14137B280, CGroupChat, FUN_14137b280, 394, 0x61BD6F0C);
// @0x14137b410
int CGroupChat::FUN_14137b410(__int64 characterId) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (member->m_proxy.m_8 == characterId)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14137B410, CGroupChat, FUN_14137b410, 243, 0x8EC10524);
// @0x14137b510
int CGroupChat::FUN_14137b510(CStringW name) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (member->m_proxy.FUN_1408f19e0() == name)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14137B510, CGroupChat, FUN_14137b510, 351, 0x323F2968);
// @0x14137b680
int CGroupChat::FUN_14137b680(Unk_ChatMemberPtr member) {
    if (member == 0)
        return 0;
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        if (FUN_14137bad0() >= 0x14)
            return 0;
        m_members.SetAt(member->m_proxy.FUN_1408f19e0(), member);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14137B680, CGroupChat, FUN_14137b680, 317, 0xEEB9101C);
// @0x14137b7d0
void CGroupChat::FUN_14137b7d0(CStringW name) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        m_members.RemoveKey(name);
    }
}
MS2_REPLACE_METHOD(0x14137B7D0, CGroupChat, FUN_14137b7d0, 112, 0xF000DAA1);
// @0x14137b850
void CGroupChat::FUN_14137b850() {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        m_members.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x14137B850, CGroupChat, FUN_14137b850, 90, 0x396D8C74);
// @0x14137b8b0
Unk_ChatMemberPtr CGroupChat::FUN_14137b8b0(__int64 characterId) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (bool(member.get()) && member->m_proxy.m_8 == characterId)
                return member;
        }
    }
    return Unk_ChatMemberPtr(0);
}
MS2_REPLACE_METHOD(0x14137B8B0, CGroupChat, FUN_14137b8b0, 341, 0x7EC655AF);
// @0x14137ba10
Unk_ChatMemberPtr CGroupChat::FUN_14137ba10(CStringW name) {
    Unk_ChatMemberPtr result(0);
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        m_members.Lookup(name, result);
    }
    return result;
}
MS2_REPLACE_METHOD(0x14137BA10, CGroupChat, FUN_14137ba10, 184, 0xE63309F5);
// @0x14137bad0
int CGroupChat::FUN_14137bad0() { return (int)m_members.GetCount(); }
MS2_REPLACE_METHOD(0x14137BAD0, CGroupChat, FUN_14137bad0, 31, 0x80E102A6);
// @0x14137bb00
int CGroupChat::FUN_14137bb00() {
    int count = 0;
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (member->m_state == 1)
                ++count;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x14137BB00, CGroupChat, FUN_14137bb00, 218, 0x77C09BC6);
// @0x14137bbe0
void CGroupChat::FUN_14137bbe0(ATL::CAtlList<__int64>& ids) {
    ids.RemoveAll();
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (member.get() != 0)
                ids.AddTail(member->m_proxy.m_8);
        }
    }
}
MS2_REPLACE_METHOD(0x14137BBE0, CGroupChat, FUN_14137bbe0, 232, 0x5BE9FB61);
// @0x14137bcd0
void CGroupChat::FUN_14137bcd0(ATL::CAtlList<Unk_ChatMemberPtr>& out) {
    out.RemoveAll();
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (member.get() != 0)
                out.AddTail(member);
        }
    }
}
MS2_REPLACE_METHOD(0x14137BCD0, CGroupChat, FUN_14137bcd0, 223, 0xF672EE09);
// @0x14137bdc0
void CGroupChat::FUN_14137bdc0(ATL::CAtlList<Unk_ChatMemberPtr>& out) {
    out.RemoveAll();
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (bool(member.get()) && member->FUN_14137b160())
                out.AddTail(member);
        }
    }
}
MS2_REPLACE_METHOD(0x14137BDC0, CGroupChat, FUN_14137bdc0, 269, 0x29FC06EF);
// @0x14137bee0
void CGroupChat::FUN_14137bee0(ATL::CAtlList<Unk_ChatMemberPtr>& out) {
    out.RemoveAll();
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_members.GetHeadPosition(); pos; m_members.GetNext(pos)) {
            Unk_ChatMemberPtr member = m_members.GetValueAt(pos);
            if (bool(member.get()) && !member->FUN_14137b160())
                out.AddTail(member);
        }
    }
}
MS2_REPLACE_METHOD(0x14137BEE0, CGroupChat, FUN_14137bee0, 269, 0x8333B7CC);

MS2_EMIT_CRT_MEMMOVE_S();

// ---------------------------------------------------------------------------------------------------------------
// TU 2: CGroupChatManager
// ---------------------------------------------------------------------------------------------------------------
// @0x14137e080
CGroupChatManager::CGroupChatManager() { FUN_14137e160(); }
// @0x14137e0f0
CGroupChatManager::~CGroupChatManager() { FUN_14137e190(); }
// @0x14137e160
void CGroupChatManager::FUN_14137e160() { m_chats.RemoveAll(); }
MS2_REPLACE_METHOD(0x14137E160, CGroupChatManager, FUN_14137e160, 31, 0xAFDDD77C);
// @0x14137e190
void CGroupChatManager::FUN_14137e190() { m_chats.RemoveAll(); }
MS2_REPLACE_METHOD(0x14137E190, CGroupChatManager, FUN_14137e190, 31, 0x8872628C);
// @0x14137e1c0
// MS2-FUNCTIONAL: third Format argument load order and one nop
void CGroupChatManager::FUN_14137e1c0() {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        CStringW line;
        {
            CStringW rule(L"----------------------------------------");
            FUN_1412751b0(rule, 0x14);
        }
        line.Format(L"GroupChat count = %d", FUN_14137e820());
        FUN_1412751b0(line, 0x14);
        for (POSITION pos = m_chats.GetHeadPosition(); pos; m_chats.GetNext(pos)) {
            Unk_ChatPtrChat chat = m_chats.GetValueAt(pos);
            if (chat == 0)
                continue;
            {
                CStringW title(L"[Group Chat]");
                FUN_1412751b0(title, 0x14);
            }
            line.Format(L"oid = %d", chat->GetOid());
            FUN_1412751b0(line, 0x14);
            unsigned joined = chat->FUN_14137bb00();
            line.Format(L"member count = %d (%d)", chat->FUN_14137bad0(), joined);
            FUN_1412751b0(line, 0x14);
        }
        CStringW rule(L"----------------------------------------");
        FUN_1412751b0(rule, 0x14);
    }
}
MS2_REPLACE_METHOD(0x14137E1C0, CGroupChatManager, FUN_14137e1c0, 577, 0x0018B9BA);
// @0x14137e410
CStringW CGroupChatManager::FUN_14137e410() {
    Unk_ChatPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player == 0)
        return CStringW(L"");
    return player->vfunc_77();
}
MS2_REPLACE_METHOD(0x14137E410, CGroupChatManager, FUN_14137e410, 129, 0x6B224641);
// @0x14137e4a0
void CGroupChatManager::FUN_14137e4a0(Unk_ChatPtrChat chat) {
    if (chat == 0)
        return;
    if (FUN_14137e820() >= 3)
        return;
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        unsigned oid = chat->GetOid();
        if (FUN_14137e630(oid) == 0)
            m_chats.SetAt(oid, chat);
    }
}
MS2_REPLACE_METHOD(0x14137E4A0, CGroupChatManager, FUN_14137e4a0, 271, 0x0FDF968C);
// @0x14137e5c0
void CGroupChatManager::FUN_14137e5c0(unsigned oid) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        m_chats.RemoveKey(oid);
    }
}
MS2_REPLACE_METHOD(0x14137E5C0, CGroupChatManager, FUN_14137e5c0, 98, 0x9B51D476);
// @0x14137e630
Unk_ChatPtrChat CGroupChatManager::FUN_14137e630(unsigned oid) {
    Unk_ChatPtrChat result(0);
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        m_chats.Lookup(oid, result);
    }
    return result;
}
MS2_REPLACE_METHOD(0x14137E630, CGroupChatManager, FUN_14137e630, 171, 0xA48F2D1F);
// @0x14137e6f0
void CGroupChatManager::FUN_14137e6f0(__int64 characterId, ATL::CAtlList<unsigned>& oids) {
    if (Unk_LockGuard guard = m_lock) {
        __assume(0);
    } else {
        for (POSITION pos = m_chats.GetHeadPosition(); pos; m_chats.GetNext(pos)) {
            Unk_ChatPtrChat chat = m_chats.GetValueAt(pos);
            if (chat == 0)
                continue;
            if (chat->FUN_14137b410(characterId))
                oids.AddTail(chat->GetOid());
        }
    }
}
MS2_REPLACE_METHOD(0x14137E6F0, CGroupChatManager, FUN_14137e6f0, 283, 0x5D985D4A);
// @0x14137e820
// MS2-FUNCTIONAL: missing trailing nop after guard dtor call
int CGroupChatManager::FUN_14137e820() {
    Unk_LockGuard guard = m_lock;
    if (guard) {} else { return (int)m_chats.GetCount(); }
}
MS2_REPLACE_METHOD(0x14137E820, CGroupChatManager, FUN_14137e820, 110, 0x8ACB80F7);
// @0x14137e8a0
// MS2-FUNCTIONAL: temp reference copy and EH state layout around the message box temps
void CGroupChatManager::Create(CStringW name) {
    if (FUN_14137e820() >= 3) {
        Unk_MessageBoxPtr box = FUN_140d73d20(0, FUN_14052bd00(0x818, FUN_14137e410()), 0, CStringW(L""));
        if (FUN_140534fc0(box) != 0)
            FUN_140d73c60(box);
    } else {
        if (name.GetLength() >= 0x19) {
            MS2_ASSERT_AT(0x9a, FALSE);
            FUN_140166440()->Log(1, 0x13, L"{0}. strTargetName={1}", "CGroupChatManager::Create", name);
        } else {
            COutPacket packet(static_cast<int>(SendOp::GroupChat), 0);
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_8(name);
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x14137E8A0, CGroupChatManager, Create, 596, 0xCDD6234E);
// @0x14137eb00
// MS2-FUNCTIONAL: by-value arg copy is ordered before operator-> in the exe; EH states differ
void CGroupChatManager::Invite(unsigned oid, CStringW name) {
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    if (chat->FUN_14137b510(name) == 0) {
        if (chat->FUN_14137bad0() >= 0x14) {
            CStringW text = GetStringCommon(0x814);
            Unk_MessageBoxPtr active = FUN_14151f820();
            if (FUN_140534fc0(active) != 0) {
                if (FUN_14025cd60(FUN_141a02ce0(FUN_140534fe0(active)), text))
                    return;
            }
            Unk_MessageBoxPtr box = FUN_140d73d20(0, text, 0, text);
            if (FUN_140534fc0(box) != 0)
                FUN_140d73c60(box);
        }
        int len = name.GetLength();
        if (len >= 0x19) {
            MS2_ASSERT_AT(0xc9, FALSE);
            FUN_140166440()->Log(1, 0x13, L"{0}. strTargetName={1}", "CGroupChatManager::Invite", name);
        } else {
            COutPacket packet(static_cast<int>(SendOp::GroupChat), 0);
            packet.vfunc_o10_1(2);
            packet.vfunc_o10_8(name);
            packet.vfunc_o10_3(oid);
            FUN_140710590(packet);
        }
    } else {
        Unk_MessageBoxPtr box = FUN_140d73d20(0, GetStringCommon(0x816), 0, CStringW(L""));
        if (FUN_140534fc0(box) != 0)
            FUN_140d73c60(box);
    }
}
MS2_REPLACE_METHOD(0x14137EB00, CGroupChatManager, Invite, 1173, 0xCDB2E8FE);
// @0x14137efa0
void CGroupChatManager::SendGroupChatMode4(unsigned oid, int flag) {
    if (FUN_14137e630(oid) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::GroupChat), 0);
    packet.vfunc_o10_1(4);
    packet.vfunc_o10_3(oid);
    packet.vfunc_o10_1(flag);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x14137EFA0, CGroupChatManager, SendGroupChatMode4, 203, 0x55D554D6);
// @0x14137f080
// MS2-FUNCTIONAL: chat lookup temp copy and EH layout
void CGroupChatManager::SendGroupChatMode10(unsigned oid, CStringW text) {
    if (FUN_14137e630(oid) == 0)
        return;
    if (text.GetLength() >= 0x801)
        return;
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(2);
        if (blocked.get() != 0) {
            CStringW msg = FUN_1401ca400(blocked, 2);
            if (FUN_141482e80()->m_messenger != 0)
                FUN_141482e80()->m_messenger->FUN_141951bf0(oid, FUN_14137e410(), msg);
            return;
        }
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()->FUN_140375660(0x100) == 0) {
        COutPacket packet(static_cast<int>(SendOp::GroupChat), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_8(text);
        packet.vfunc_o10_3(oid);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x14137F080, CGroupChatManager, SendGroupChatMode10, 615, 0x230F9B6B);
// @0x14137f2f0
// MS2-FUNCTIONAL: dispatcher stack layout differs by a few bytes
void CGroupChatManager::OnGroupChat(CInPacket* packet) {
    switch (packet->vfunc_o8_1()) {
    case 0:    FUN_14137f490(packet); break;
    case 1:    FUN_14137f590(packet); break;
    case 2:    FUN_14137f640(packet); break;
    case 3:    FUN_14137f790(packet); break;
    case 4:    FUN_14137f910(packet); break;
    case 6:    FUN_14137f9d0(packet); break;
    case 7:    FUN_14137fc20(packet); break;
    case 8:    FUN_14137fe40(packet); break;
    case 9:    FUN_14137ffc0(packet); break;
    case 10:   FUN_141380140(packet); break;
    case 0xb:  FUN_141380320(packet); break;
    case 0xc:  FUN_141380560(packet); break;
    case 0xd:  FUN_141380900(packet); break;
    }
}
MS2_REPLACE_METHOD(0x14137F2F0, CGroupChatManager, OnGroupChat, 337, 0x4FE25F86);
// @0x14137f490
void CGroupChatManager::FUN_14137f490(CInPacket* packet) {
    Unk_ChatPtrChat chat(new CGroupChat);
    int ok = chat->FUN_14137b280(packet);
    if (ok == 0)
        return;
    if (FUN_14137e820() >= 3)
        return;
    FUN_14137e4a0(chat);
}
MS2_REPLACE_METHOD(0x14137F490, CGroupChatManager, FUN_14137f490, 247, 0xD4D3E365);
// @0x14137f590
void CGroupChatManager::FUN_14137f590(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CGroupChat* chat = FUN_14137e630(oid).get();
    if (chat != 0) {
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_1419515c0(oid);
    }
}
MS2_REPLACE_METHOD(0x14137F590, CGroupChatManager, FUN_14137f590, 164, 0x1AA86B3B);
// @0x14137f640
void CGroupChatManager::FUN_14137f640(CInPacket* packet) {
    CStringW first = packet->vfunc_o8_8();
    CStringW second = packet->vfunc_o8_8();
    unsigned oid = packet->vfunc_o8_3();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    if (FUN_141482e80()->m_messenger != 0)
        FUN_141482e80()->m_messenger->FUN_141951720(oid, first, second);
}
MS2_REPLACE_METHOD(0x14137F640, CGroupChatManager, FUN_14137f640, 318, 0x765CA6E8);
// @0x14137f790
void CGroupChatManager::FUN_14137f790(CInPacket* packet) {
    CStringW first = packet->vfunc_o8_8();
    CStringW second = packet->vfunc_o8_8();
    unsigned oid = packet->vfunc_o8_3();
    if (FUN_140ae6540(FUN_1409a8b10())->m_refuseInvite) {
        SendGroupChatMode4(oid, 1);
    } else {
        Unk_ChatPtrChat chat = FUN_14137e630(oid);
        if (chat == 0)
            return;
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_1419517b0(oid, first, second);
    }
}
MS2_REPLACE_METHOD(0x14137F790, CGroupChatManager, FUN_14137f790, 367, 0xFB9CE439);
// @0x14137f910
void CGroupChatManager::FUN_14137f910(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CGroupChat* chat = FUN_14137e630(oid).get();
    if (chat != 0) {
        FUN_14137e5c0(oid);
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_1419519a0(oid);
    }
}
MS2_REPLACE_METHOD(0x14137F910, CGroupChatManager, FUN_14137f910, 178, 0xF41BB1F8);
// @0x14137f9d0
void CGroupChatManager::FUN_14137f9d0(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW name = packet->vfunc_o8_8();
    Unk_ChatMemberPtr member(new CGroupChatMember);
    member->FUN_14137b0c0(packet);
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    if (chat->FUN_14137b680(member) == 0)
        return;
    if (FUN_141482e80()->m_messenger != 0)
        FUN_141482e80()->m_messenger->FUN_1419519e0(oid, name, member->m_proxy.FUN_1408f19e0());
}
MS2_REPLACE_METHOD(0x14137F9D0, CGroupChatManager, FUN_14137f9d0, 576, 0xD23A1A70);
// @0x14137fc20
void CGroupChatManager::FUN_14137fc20(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    unsigned reason = packet->vfunc_o8_1();
    CStringW name = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    CGroupChatMember* found = chat->FUN_14137ba10(name).get();
    if (found != 0) {
        chat->FUN_14137b7d0(name);
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_141951a70(oid, name, reason);
    }
}
MS2_REPLACE_METHOD(0x14137FC20, CGroupChatManager, FUN_14137fc20, 532, 0x73201602);
// @0x14137fe40
void CGroupChatManager::FUN_14137fe40(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW name = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    Unk_ChatMemberPtr member = chat->FUN_14137ba10(name);
    if (member.get() != 0) {
        member->m_state = 1;
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_141951af0(oid, name);
    }
}
MS2_REPLACE_METHOD(0x14137FE40, CGroupChatManager, FUN_14137fe40, 372, 0xCEC78FAD);
// @0x14137ffc0
void CGroupChatManager::FUN_14137ffc0(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW name = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    Unk_ChatMemberPtr member = chat->FUN_14137ba10(name);
    if (member.get() != 0) {
        member->m_state = 2;
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_141951b70(oid, name);
    }
}
MS2_REPLACE_METHOD(0x14137FFC0, CGroupChatManager, FUN_14137ffc0, 372, 0xE5740DDB);
// @0x141380140
void CGroupChatManager::FUN_141380140(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW first = packet->vfunc_o8_8();
    CStringW second = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    CGroupChatMember* found = chat->FUN_14137ba10(first).get();
    if (found != 0) {
        if (FUN_141482e80()->m_messenger != 0)
            FUN_141482e80()->m_messenger->FUN_141951c50(oid, first, second);
    }
}
MS2_REPLACE_METHOD(0x141380140, CGroupChatManager, FUN_141380140, 469, 0x39B109A7);
// @0x141380320
void CGroupChatManager::FUN_141380320(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW name = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    CGroupChatMember* found = chat->FUN_14137ba10(name).get();
    if (found != 0) {
        CGroupChatMember* again = chat->FUN_14137ba10(name).get();
        if (again != 0) {
            if (FUN_141482e80()->m_messenger != 0)
                FUN_141482e80()->m_messenger->FUN_141951d80(oid, name, packet);
        }
    }
}
MS2_REPLACE_METHOD(0x141380320, CGroupChatManager, FUN_141380320, 557, 0x5B7B0A0D);
// @0x141380560
// MS2-FUNCTIONAL: temp lifetime ordering differs by a few bytes
void CGroupChatManager::FUN_141380560(CInPacket* packet) {
    unsigned oid = packet->vfunc_o8_3();
    CStringW name = packet->vfunc_o8_8();
    CStringW picture = packet->vfunc_o8_8();
    Unk_ChatPtrChat chat = FUN_14137e630(oid);
    if (chat == 0)
        return;
    Unk_ChatMemberPtr member = chat->FUN_14137ba10(name);
    if (member == 0)
        return;
    member->m_proxy.FUN_1408f0850(FUN_14016a600(picture, 0));
    CString cached = FUN_141028be0(member->m_proxy.m_8, FUN_14016a600(picture, 0), 0, CString(""));
    if (!cached.IsEmpty()) {
        Unk_ChatPictureSink* sink = FUN_140bc09f0();
        sink->vfunc_1(member->m_proxy.m_8, FUN_14016a600(picture, 0));
    }
}
MS2_REPLACE_METHOD(0x141380560, CGroupChatManager, FUN_141380560, 921, 0x2E2E4F06);
// @0x141380900
// MS2-FUNCTIONAL: temp lifetime ordering differs by a few bytes
void CGroupChatManager::FUN_141380900(CInPacket* packet) {
    unsigned char flag = packet->vfunc_o8_1();
    int code = packet->vfunc_o8_3();
    CStringW first = packet->vfunc_o8_8();
    CStringW second = packet->vfunc_o8_8();
    if (code == 3) {
        FUN_140d73bc0(0x815, 0, 0, CStringW(L""));
    } else if (code == 10) {
        FUN_140d73aa0(FUN_14052bd00(0x818, second), 0, 0, CStringW(L""));
    } else if (code == 8) {
        FUN_140d73aa0(FUN_14052bd00(0x819, second), 0, 0, CStringW(L""));
    } else if (code == 0xd) {
        FUN_140d73aa0(FUN_14052bd00(0x29, second), 0, 0, CStringW(L""));
    }
}
MS2_REPLACE_METHOD(0x141380900, CGroupChatManager, FUN_141380900, 741, 0xFD651472);

// @0x141382a70
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
