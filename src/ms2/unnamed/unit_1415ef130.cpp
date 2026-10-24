// Full-exe Nexon Messenger copy helpers recovered from unit_1415ef130.
// MS2-UNIT: unit_1415ef130
// MS2-RANGE: 0x1415ef130-0x1415f9410 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <cstring>

extern void* FUN_1415f39a0(void*);
extern void* FUN_1415f39c0(void*);
extern void* FUN_1415f39d0(void*);
extern void* FUN_1415f39e0(void*);
extern void FUN_1415f99f0(void*, void*);
extern void FUN_1415f9a90(void*, const void*);
extern void FUN_1415f9ae0(void*, void*);
extern void FUN_1415f9b30(void*, void*);
extern void FUN_1415f9b80(void*, void*);

// MS2-FUNCTIONAL: follows the recovered two-call wrapper and returns the destination.
// @0x1415ef130
void* FUN_1415ef130(void* dst, void* src)
{
    FUN_1415f99f0(dst, FUN_1415f39a0(src));
    return dst;
}

// MS2-FUNCTIONAL: follows the recovered two-call wrapper and returns the destination.
// @0x1415ef160
void* FUN_1415ef160(void* dst, void* src)
{
    FUN_1415f9a90(dst, FUN_1415f39c0(src));
    return dst;
}

// MS2-FUNCTIONAL: forwards the value then returns the destination as in the executable.
// @0x1415ef190
void* FUN_1415ef190(void* dst, void* value)
{
    FUN_1415f9a90(dst, value);
    return dst;
}

// MS2-FUNCTIONAL: follows the recovered two-call wrapper and returns the destination.
// @0x1415ef1c0
void* FUN_1415ef1c0(void* dst, void* src)
{
    FUN_1415f9ae0(dst, FUN_1415f39d0(src));
    return dst;
}

// MS2-FUNCTIONAL: forwards the value then returns the destination as in the executable.
// @0x1415ef1f0
void* FUN_1415ef1f0(void* dst, void* value)
{
    FUN_1415f9ae0(dst, value);
    return dst;
}

// MS2-FUNCTIONAL: follows the recovered two-call wrapper and returns the destination.
// @0x1415ef220
void* FUN_1415ef220(void* dst, void* src)
{
    FUN_1415f9b30(dst, FUN_1415f39e0(src));
    return dst;
}

// MS2-FUNCTIONAL: forwards the value then returns the destination as in the executable.
// @0x1415ef250
void* FUN_1415ef250(void* dst, void* value)
{
    FUN_1415f9b30(dst, value);
    return dst;
}

// These record layouts contain fixed arrays except for the three explicitly handled vectors below.
template <class T>
static T& copy_record_bytes(T& dst, const T& src)
{
    dst.CNMSerializable::CopyFrom(const_cast<CNMSerializable*>(static_cast<const CNMSerializable*>(&src)));
    std::memcpy(reinterpret_cast<unsigned char*>(&dst) + 0x10,
                reinterpret_cast<const unsigned char*>(&src) + 0x10, sizeof(T) - 0x10);
    return dst;
}

// MS2-FUNCTIONAL: clears null values and performs the recovered bounded copy into the 0x800-byte storage.
// The original fixed-string setter clears null values or copies into its allocated 0x800-byte storage.
// @0x1415ef280
void FUN_1415ef280(void* p, unsigned long long value)
{
    auto** slot = static_cast<char**>(p);
    if (!value) { *slot = nullptr; return; }
    if (*slot) { std::strncpy(*slot, reinterpret_cast<const char*>(value), 0x7ff); (*slot)[0x7ff] = 0; }
}
// MS2-PIN: ?FUN_1415ef280@@YAXPEAX_K@Z 0x1415ef280

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415efbf0
CNMCateFriendInfo& CNMCateFriendInfo::operator=(const CNMCateFriendInfo& r)
{
    CNMSerializable::CopyFrom(const_cast<CNMCateFriendInfo*>(&r));
    std::memcpy(reinterpret_cast<char*>(this) + 0x10, reinterpret_cast<const char*>(&r) + 0x10, 0x30);
    m_aFriends = r.m_aFriends;
    return *this;
}
// MS2-FUNCTIONAL: copies the recovered base fields and friend vector.
// MS2-PIN: ??4CNMCateFriendInfo@@QEAAAEAV0@AEBV0@@Z 0x1415efbf0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415efdd0
CNMCharacter& CNMCharacter::operator=(const CNMCharacter& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMCharacter@@QEAAAEAV0@AEBV0@@Z 0x1415efdd0
// MS2-PIN: ?FUN_1415efdd0@@YAXPEAX0@Z 0x1415efdd0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f03b0
CNMChatRoomInfoEx& CNMChatRoomInfoEx::operator=(const CNMChatRoomInfoEx& r)
{
    CNMSerializable::CopyFrom(const_cast<CNMChatRoomInfoEx*>(&r));
    std::memcpy(reinterpret_cast<char*>(this) + 0x10, reinterpret_cast<const char*>(&r) + 0x10, 0x4b0);
    m_4c0 = r.m_4c0;
    std::memcpy(reinterpret_cast<char*>(this) + 0x4d8, reinterpret_cast<const char*>(&r) + 0x4d8, 8);
    return *this;
}
// MS2-FUNCTIONAL: copies fixed room fields and assigns the member-level vector.
// MS2-PIN: ??4CNMChatRoomInfoEx@@QEAAAEAV0@AEBV0@@Z 0x1415f03b0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f05b0
CNMChatRoomMemberInfo& CNMChatRoomMemberInfo::operator=(const CNMChatRoomMemberInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMChatRoomMemberInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f05b0

// MS2-FUNCTIONAL: preserves CopyFrom's base-field behavior and copies the recovered fixed payload.
// @0x1415f06d0
CNMSerializable* FUN_1415f06d0(CNMSerializable* dst, long long src)
{
    dst->CopyFrom(reinterpret_cast<CNMSerializable*>(src));
    std::memcpy(reinterpret_cast<char*>(dst) + 0x10, reinterpret_cast<const char*>(src) + 0x10, 0x4d0);
    return dst;
}
// MS2-PIN: ?FUN_1415f06d0@@YAPEAVCNMSerializable@@PEAV1@_J@Z 0x1415f06d0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f09b0
CNMFileEvent& CNMFileEvent::operator=(const CNMFileEvent& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMFileEvent@@QEAAAEAV0@AEBV0@@Z 0x1415f09b0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f0a90
CNMFilePath& CNMFilePath::operator=(const CNMFilePath& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMFilePath@@QEAAAEAV0@AEBV0@@Z 0x1415f0a90

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f0bf0
CNMFriendInfo& CNMFriendInfo::operator=(const CNMFriendInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMFriendInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f0bf0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f0db0
CNMGameCode& CNMGameCode::operator=(const CNMGameCode& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMGameCode@@QEAAAEAV0@AEBV0@@Z 0x1415f0db0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f0df0
CNMGameInfo& CNMGameInfo::operator=(const CNMGameInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMGameInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f0df0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f1140
CNMGameServerCode& CNMGameServerCode::operator=(const CNMGameServerCode& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMGameServerCode@@QEAAAEAV0@AEBV0@@Z 0x1415f1140

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f1180
CNMGuildMemberInfo& CNMGuildMemberInfo::operator=(CNMGuildMemberInfo&& r) { return copy_record_bytes(*this, r); }
// MS2-FUNCTIONAL: copies the recovered fixed-layout moved record; this record owns no heap-backed member.
// MS2-PIN: ??4CNMGuildMemberInfo@@QEAAAEAV0@$$QEAV0@@Z 0x1415f1180

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f12d0
CNMGuildMemberInfo& CNMGuildMemberInfo::operator=(const CNMGuildMemberInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMGuildMemberInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f12d0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f1420
CNMGuildMemberLevelInfo& CNMGuildMemberLevelInfo::operator=(const CNMGuildMemberLevelInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMGuildMemberLevelInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f1420

// MS2-FUNCTIONAL: copies the recovered fixed payload after serializable base fields.
// @0x1415f14b0
CNMSerializable* FUN_1415f14b0(CNMSerializable* dst, long long src)
{
    dst->CopyFrom(reinterpret_cast<CNMSerializable*>(src));
    std::memcpy(reinterpret_cast<char*>(dst) + 0x10, reinterpret_cast<const char*>(src) + 0x10, 0x88);
    return dst;
}
// MS2-PIN: ?FUN_1415f14b0@@YAPEAVCNMSerializable@@PEAV1@_J@Z 0x1415f14b0

// MS2-FUNCTIONAL: copies the recovered fixed payload after serializable base fields.
// @0x1415f1580
CNMSerializable* FUN_1415f1580(CNMSerializable* dst, long long src)
{
    dst->CopyFrom(reinterpret_cast<CNMSerializable*>(src));
    std::memcpy(reinterpret_cast<char*>(dst) + 0x10, reinterpret_cast<const char*>(src) + 0x10, 0x88);
    return dst;
}
// MS2-PIN: ?FUN_1415f1580@@YAPEAVCNMSerializable@@PEAV1@_J@Z 0x1415f1580

// MS2-FUNCTIONAL: copies the recovered 0x1004-byte fixed payload after base fields.
// @0x1415f1660
void FUN_1415f1660(void* dst, const void* src)
{
    static_cast<CNMSerializable*>(dst)->CopyFrom(const_cast<CNMSerializable*>(static_cast<const CNMSerializable*>(src)));
    std::memcpy(static_cast<char*>(dst) + 0x10, static_cast<const char*>(src) + 0x10, 0x1004);
}
// MS2-PIN: ?FUN_1415f1660@@YAXPEAXPEBX@Z 0x1415f1660

// @0x1415f1760
CNMNoteInfo2& CNMNoteInfo2::operator=(const CNMNoteInfo2& r)
{
    CNMSerializable::CopyFrom(const_cast<CNMNoteInfo2*>(&r));
    std::memcpy(reinterpret_cast<char*>(this) + 0x10, reinterpret_cast<const char*>(&r) + 0x10, 0xa28);
    m_a38 = r.m_a38;
    m_aCharacters = r.m_aCharacters;
    return *this;
}
// MS2-FUNCTIONAL: copies the fixed note fields and deep-assigns the character list.
// MS2-PIN: ??4CNMNoteInfo2@@QEAAAEAV0@AEBV0@@Z 0x1415f1760
// MS2-PIN: ?FUN_1415f1760@@YAPEAVCNMSerializable@@PEAV1@_J@Z 0x1415f1760

// MS2-FUNCTIONAL: copies the recovered fixed payload after base fields.
// @0x1415f1be0
void FUN_1415f1be0(void* dst, const void* src)
{
    static_cast<CNMSerializable*>(dst)->CopyFrom(const_cast<CNMSerializable*>(static_cast<const CNMSerializable*>(src)));
    std::memcpy(static_cast<char*>(dst) + 0x10, static_cast<const char*>(src) + 0x10, 0xd0);
}
// MS2-PIN: ?FUN_1415f1be0@@YAXPEAXPEBX@Z 0x1415f1be0

// MS2-FUNCTIONAL: copies the recovered 0xc1-byte real-friend payload.
// @0x1415f1e90
long long FUN_1415f1e90(long long dst, long long src)
{
    std::memcpy(reinterpret_cast<char*>(dst) + 0x10, reinterpret_cast<const char*>(src) + 0x10, 0xc1);
    return dst;
}
// MS2-PIN: ?FUN_1415f1e90@@YA_J_J0@Z 0x1415f1e90

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f2280
CNMRejectedUser& CNMRejectedUser::operator=(const CNMRejectedUser& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMRejectedUser@@QEAAAEAV0@AEBV0@@Z 0x1415f2280

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f25b0
CNMSessionMemberInfo& CNMSessionMemberInfo::operator=(const CNMSessionMemberInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMSessionMemberInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f25b0

// MS2-FUNCTIONAL: reproduces the recovered assignment over this record's fields.
// @0x1415f28e0
CNMVirtualUserInfo& CNMVirtualUserInfo::operator=(const CNMVirtualUserInfo& r) { return copy_record_bytes(*this, r); }
// MS2-PIN: ??4CNMVirtualUserInfo@@QEAAAEAV0@AEBV0@@Z 0x1415f28e0

// MS2-FUNCTIONAL: performs the recovered 0x98-byte character-vector element calculation.
// @0x1415f38c0
void* FUN_1415f38c0(void* p, int index)
{
    return *reinterpret_cast<char**>(p) + static_cast<long long>(index) * sizeof(CNMCharacter);
}
// MS2-PIN: ?FUN_1415f38c0@@YAPEAXPEAXH@Z 0x1415f38c0

// These six helpers return the first pointer-sized field of their argument, as in the recovered decompilation.
void* FUN_1415f3990(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f3990@@YAPEAXPEAX@Z 0x1415f3990
void* FUN_1415f39a0(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f39a0@@YAPEAXPEAX@Z 0x1415f39a0
void* FUN_1415f39c0(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f39c0@@YAPEAXPEAX@Z 0x1415f39c0
void* FUN_1415f39d0(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f39d0@@YAPEAXPEAX@Z 0x1415f39d0
void* FUN_1415f39e0(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f39e0@@YAPEAXPEAX@Z 0x1415f39e0
void* FUN_1415f39f0(void* p) { return *static_cast<void**>(p); }
// MS2-PIN: ?FUN_1415f39f0@@YAPEAXPEAX@Z 0x1415f39f0

// @0x1415f9110
void FUN_1415f9110(void*) { }
// MS2-FUNCTIONAL: the recovered target is the virtual slot's scalar deleting destructor entry.
// MS2-PIN: ?vfunc_0@CNMVirtualUserInfo@@UEAAXXZ 0x1415f9110
