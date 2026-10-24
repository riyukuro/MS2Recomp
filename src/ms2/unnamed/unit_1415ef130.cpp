// Full-exe Nexon Messenger copy helpers recovered from unit_1415ef130.
// MS2-UNIT: unit_1415ef130
// MS2-RANGE: 0x1415ef130-0x1415f9410 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmchatroomfunc.h"
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
extern void* FUN_1415f3b00(void*); extern void* FUN_1415f3b10(void*);
extern void* FUN_1415f3b20(void*); extern void* FUN_1415f3b30(void*);
extern void* FUN_1415f3b40(void*); extern void* FUN_1415f3b50(void*);
extern void* FUN_1415f3b60(void*); extern void* FUN_1415f3b70(void*);
extern void* FUN_1415f3b80(void*); extern void* FUN_1415f3b90(void*);
extern void* FUN_1415f3ba0(void*); extern void* FUN_1415f3bb0(void*);
extern void* FUN_1415f3bc0(void*); extern void* FUN_1415f3bd0(void*);
extern void* FUN_1415f3be0(void*); extern void* FUN_1415f3bf0(void*);
extern void* FUN_1415f3c00(void*); extern void* FUN_1415f3c10(void*);
extern void* FUN_1415f3c20(void*);

template <class Id, class Get, class Set, class First, class Last, class Range>
static void* copy_nm_sequence(void* dst, void* src, Id id, Get get, Set set,
                              First first, Last last, Range range)
{
    if (dst != id(src)) {
        set(dst, get(src));
        range(dst, *reinterpret_cast<void**>(first(src)), *reinterpret_cast<void**>(last(src)));
    }
    return dst;
}

#define NM_COPY_HELPERS(addr) \
    extern void* FUN_##addr(void*)
NM_COPY_HELPERS(1415e1620); NM_COPY_HELPERS(1415e1630); NM_COPY_HELPERS(1415e1640);
NM_COPY_HELPERS(1415e1650); NM_COPY_HELPERS(1415e1660); NM_COPY_HELPERS(1415e1670);
NM_COPY_HELPERS(1415e1680); NM_COPY_HELPERS(1415e1690); NM_COPY_HELPERS(1415e16a0);
NM_COPY_HELPERS(1415e16b0); NM_COPY_HELPERS(1415e16c0); NM_COPY_HELPERS(1415e16d0);
NM_COPY_HELPERS(1415e16e0); NM_COPY_HELPERS(1415e16f0); NM_COPY_HELPERS(1415e1700);
NM_COPY_HELPERS(1415e1710); NM_COPY_HELPERS(1415e1720);
NM_COPY_HELPERS(141601af0); NM_COPY_HELPERS(141601b30); NM_COPY_HELPERS(141601b70);
NM_COPY_HELPERS(141601bb0); NM_COPY_HELPERS(141601bf0); NM_COPY_HELPERS(141601c30);
NM_COPY_HELPERS(141601c70); NM_COPY_HELPERS(141601cb0); NM_COPY_HELPERS(141601d30);
NM_COPY_HELPERS(141601d70); NM_COPY_HELPERS(141601db0); NM_COPY_HELPERS(141601df0);
NM_COPY_HELPERS(141601e70); NM_COPY_HELPERS(141601eb0); NM_COPY_HELPERS(141601fb0);
NM_COPY_HELPERS(141601ff0); NM_COPY_HELPERS(141602030);
NM_COPY_HELPERS(1416039a0); NM_COPY_HELPERS(1416033e0); NM_COPY_HELPERS(1416039e0);
NM_COPY_HELPERS(141603420); NM_COPY_HELPERS(141603a20); NM_COPY_HELPERS(141603460);
NM_COPY_HELPERS(141603a60); NM_COPY_HELPERS(1416034a0); NM_COPY_HELPERS(141603aa0);
NM_COPY_HELPERS(1416034e0); NM_COPY_HELPERS(141603ae0); NM_COPY_HELPERS(141603520);
NM_COPY_HELPERS(141603b20); NM_COPY_HELPERS(141603560); NM_COPY_HELPERS(141603b60);
NM_COPY_HELPERS(1416035a0); NM_COPY_HELPERS(141603be0); NM_COPY_HELPERS(141603620);
NM_COPY_HELPERS(141603c20); NM_COPY_HELPERS(141603660); NM_COPY_HELPERS(141603c60);
NM_COPY_HELPERS(1416036a0); NM_COPY_HELPERS(141603ca0); NM_COPY_HELPERS(1416036e0);
NM_COPY_HELPERS(141603d20); NM_COPY_HELPERS(141603760); NM_COPY_HELPERS(141603d60);
NM_COPY_HELPERS(1416037a0); NM_COPY_HELPERS(141603e60); NM_COPY_HELPERS(1416038a0);
NM_COPY_HELPERS(141603ea0); NM_COPY_HELPERS(1416038e0); NM_COPY_HELPERS(141603ee0);
NM_COPY_HELPERS(141603920);
#undef NM_COPY_HELPERS

#define NM_COPY_SETTER(addr) extern void FUN_##addr(void*, void*)
NM_COPY_SETTER(1415ffe20); NM_COPY_SETTER(1415ffe50); NM_COPY_SETTER(1415ffe80);
NM_COPY_SETTER(1415ffeb0); NM_COPY_SETTER(1415ffee0); NM_COPY_SETTER(1415fff10);
NM_COPY_SETTER(1415fff40); NM_COPY_SETTER(1415fff70); NM_COPY_SETTER(1415fffa0);
NM_COPY_SETTER(1415fffd0); NM_COPY_SETTER(141600000); NM_COPY_SETTER(141600030);
NM_COPY_SETTER(141600060); NM_COPY_SETTER(141600090); NM_COPY_SETTER(1416000c0);
NM_COPY_SETTER(1416000f0); NM_COPY_SETTER(141600120);
#undef NM_COPY_SETTER

#define NM_COPY_RANGE(addr) extern void FUN_##addr(void*, void*, void*)
NM_COPY_RANGE(1415e1c70); NM_COPY_RANGE(1415e1cd0); NM_COPY_RANGE(1415e1d30);
NM_COPY_RANGE(1415e1d90); NM_COPY_RANGE(1415e1df0); NM_COPY_RANGE(1415e1e50);
NM_COPY_RANGE(1415e1eb0); NM_COPY_RANGE(1415e1f10); NM_COPY_RANGE(1415e1f70);
NM_COPY_RANGE(1415e1fd0); NM_COPY_RANGE(1415e2030); NM_COPY_RANGE(1415e2090);
NM_COPY_RANGE(1415e20f0); NM_COPY_RANGE(1415e2150); NM_COPY_RANGE(1415e21b0);
NM_COPY_RANGE(1415e2210); NM_COPY_RANGE(1415e2270);
#undef NM_COPY_RANGE

#define NM_COPY_FUNCTION(name, identity, getter, setter, first, last, range) \
    void* name(void* dst, void* src) \
    { return copy_nm_sequence(dst, src, identity, getter, setter, first, last, range); }

// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef2b0
NM_COPY_FUNCTION(FUN_1415ef2b0, FUN_1415e1620, FUN_141601af0, FUN_1415ffe20, FUN_1416039a0, FUN_1416033e0, FUN_1415e1c70)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef330
NM_COPY_FUNCTION(FUN_1415ef330, FUN_1415e1630, FUN_141601b30, FUN_1415ffe50, FUN_1416039e0, FUN_141603420, FUN_1415e1cd0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef3b0
NM_COPY_FUNCTION(FUN_1415ef3b0, FUN_1415e1640, FUN_141601b70, FUN_1415ffe80, FUN_141603a20, FUN_141603460, FUN_1415e1d30)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef430
NM_COPY_FUNCTION(FUN_1415ef430, FUN_1415e1650, FUN_141601bb0, FUN_1415ffeb0, FUN_141603a60, FUN_1416034a0, FUN_1415e1d90)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef4b0
NM_COPY_FUNCTION(FUN_1415ef4b0, FUN_1415e1660, FUN_141601bf0, FUN_1415ffee0, FUN_141603aa0, FUN_1416034e0, FUN_1415e1df0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef530
NM_COPY_FUNCTION(FUN_1415ef530, FUN_1415e1670, FUN_141601c30, FUN_1415fff10, FUN_141603ae0, FUN_141603520, FUN_1415e1e50)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef5b0
NM_COPY_FUNCTION(FUN_1415ef5b0, FUN_1415e1680, FUN_141601c70, FUN_1415fff40, FUN_141603b20, FUN_141603560, FUN_1415e1eb0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef630
NM_COPY_FUNCTION(FUN_1415ef630, FUN_1415e1690, FUN_141601cb0, FUN_1415fff70, FUN_141603b60, FUN_1416035a0, FUN_1415e1f10)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef6b0
NM_COPY_FUNCTION(FUN_1415ef6b0, FUN_1415e16a0, FUN_141601d30, FUN_1415fffa0, FUN_141603be0, FUN_141603620, FUN_1415e1f70)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef730
NM_COPY_FUNCTION(FUN_1415ef730, FUN_1415e16b0, FUN_141601d70, FUN_1415fffd0, FUN_141603c20, FUN_141603660, FUN_1415e1fd0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef7b0
NM_COPY_FUNCTION(FUN_1415ef7b0, FUN_1415e16c0, FUN_141601db0, FUN_141600000, FUN_141603c60, FUN_1416036a0, FUN_1415e2030)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef830
NM_COPY_FUNCTION(FUN_1415ef830, FUN_1415e16d0, FUN_141601df0, FUN_141600030, FUN_141603ca0, FUN_1416036e0, FUN_1415e2090)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef8b0
NM_COPY_FUNCTION(FUN_1415ef8b0, FUN_1415e16e0, FUN_141601e70, FUN_141600060, FUN_141603d20, FUN_141603760, FUN_1415e20f0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef930
NM_COPY_FUNCTION(FUN_1415ef930, FUN_1415e16f0, FUN_141601eb0, FUN_141600090, FUN_141603d60, FUN_1416037a0, FUN_1415e2150)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415ef9b0
NM_COPY_FUNCTION(FUN_1415ef9b0, FUN_1415e1700, FUN_141601fb0, FUN_1416000c0, FUN_141603e60, FUN_1416038a0, FUN_1415e21b0)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415efa30
NM_COPY_FUNCTION(FUN_1415efa30, FUN_1415e1710, FUN_141601ff0, FUN_1416000f0, FUN_141603ea0, FUN_1416038e0, FUN_1415e2210)
// MS2-FUNCTIONAL: applies the recovered same-object guard, scalar copy, and sequence range copy.
// @0x1415efab0
NM_COPY_FUNCTION(FUN_1415efab0, FUN_1415e1720, FUN_141602030, FUN_141600120, FUN_141603ee0, FUN_141603920, FUN_1415e2270)

#undef NM_COPY_FUNCTION

// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3c40
void FUN_1415f3c40(void* p) { (void)FUN_1415f3b00(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3c60
void FUN_1415f3c60(void* p) { (void)FUN_1415f3b10(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3c80
void FUN_1415f3c80(void* p) { (void)FUN_1415f3b20(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3ca0
void FUN_1415f3ca0(void* p) { (void)FUN_1415f3b30(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3cc0
void FUN_1415f3cc0(void* p) { (void)FUN_1415f3b40(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3ce0
void FUN_1415f3ce0(void* p) { (void)FUN_1415f3b50(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3d00
void FUN_1415f3d00(void* p) { (void)FUN_1415f3b60(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3d20
void FUN_1415f3d20(void* p) { (void)FUN_1415f3b70(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3d40
void FUN_1415f3d40(void* p) { (void)FUN_1415f3b80(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3d60
void FUN_1415f3d60(void* p) { (void)FUN_1415f3b90(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3d80
void FUN_1415f3d80(void* p) { (void)FUN_1415f3ba0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3da0
void FUN_1415f3da0(void* p) { (void)FUN_1415f3bb0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3dc0
void FUN_1415f3dc0(void* p) { (void)FUN_1415f3bc0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3de0
void FUN_1415f3de0(void* p) { (void)FUN_1415f3bd0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3e00
void FUN_1415f3e00(void* p) { (void)FUN_1415f3be0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3e20
void FUN_1415f3e20(void* p) { (void)FUN_1415f3bf0(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3e40
void FUN_1415f3e40(void* p) { (void)FUN_1415f3c00(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3e60
void FUN_1415f3e60(void* p) { (void)FUN_1415f3c10(p); }
// MS2-FUNCTIONAL: performs the recovered getter call; the returned value is intentionally discarded.
// @0x1415f3e80
void FUN_1415f3e80(void* p) { (void)FUN_1415f3c20(p); }

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

// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4850
void* NMScalarDelete_1415f4850(void* object, unsigned int flags)
{
    static_cast<CNMAddCategoryFunc*>(object)->~CNMAddCategoryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4890
void* NMScalarDelete_1415f4890(void* object, unsigned int flags)
{
    static_cast<CNMAddFriendToCategoryFunc*>(object)->~CNMAddFriendToCategoryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f48d0
void* NMScalarDelete_1415f48d0(void* object, unsigned int flags)
{
    static_cast<CNMAppendRejectedUserFunc*>(object)->~CNMAppendRejectedUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4910
void* NMScalarDelete_1415f4910(void* object, unsigned int flags)
{
    static_cast<CNMAttachToNMCOServerFunc*>(object)->~CNMAttachToNMCOServerFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4950
void* NMScalarDelete_1415f4950(void* object, unsigned int flags)
{
    static_cast<CNMAttendanceEventEvent*>(object)->~CNMAttendanceEventEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4990
void* NMScalarDelete_1415f4990(void* object, unsigned int flags)
{
    static_cast<CNMAuthConnectionClosedEvent*>(object)->~CNMAuthConnectionClosedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f49d0
void* NMScalarDelete_1415f49d0(void* object, unsigned int flags)
{
    static_cast<CNMAuthSecondaryConnectionClosedEvent*>(object)->~CNMAuthSecondaryConnectionClosedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4a10
void* NMScalarDelete_1415f4a10(void* object, unsigned int flags)
{
    static_cast<CNMAvatarFullInfo*>(object)->~CNMAvatarFullInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4a50
void* NMScalarDelete_1415f4a50(void* object, unsigned int flags)
{
    static_cast<CNMAvatarItemInfo*>(object)->~CNMAvatarItemInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4a90
void* NMScalarDelete_1415f4a90(void* object, unsigned int flags)
{
    static_cast<CNMBlockFriendFunc*>(object)->~CNMBlockFriendFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4ad0
void* NMScalarDelete_1415f4ad0(void* object, unsigned int flags)
{
    static_cast<CNMBringForwardStandAloneMsgFunc*>(object)->~CNMBringForwardStandAloneMsgFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4b10
void* NMScalarDelete_1415f4b10(void* object, unsigned int flags)
{
    static_cast<CNMCHBanUserFunc*>(object)->~CNMCHBanUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4b50
void* NMScalarDelete_1415f4b50(void* object, unsigned int flags)
{
    static_cast<CNMCHChangeChannelInfoFunc*>(object)->~CNMCHChangeChannelInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4b90
void* NMScalarDelete_1415f4b90(void* object, unsigned int flags)
{
    static_cast<CNMCHChangeMyInfoFunc*>(object)->~CNMCHChangeMyInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4bd0
void* NMScalarDelete_1415f4bd0(void* object, unsigned int flags)
{
    static_cast<CNMCHCloseFunc*>(object)->~CNMCHCloseFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4c10
void* NMScalarDelete_1415f4c10(void* object, unsigned int flags)
{
    static_cast<CNMCHGetChannelInfoFunc*>(object)->~CNMCHGetChannelInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4c50
void* NMScalarDelete_1415f4c50(void* object, unsigned int flags)
{
    static_cast<CNMCHGetMemberInfoListFunc*>(object)->~CNMCHGetMemberInfoListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4c90
void* NMScalarDelete_1415f4c90(void* object, unsigned int flags)
{
    static_cast<CNMCHInviteUserFunc*>(object)->~CNMCHInviteUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4cd0
void* NMScalarDelete_1415f4cd0(void* object, unsigned int flags)
{
    static_cast<CNMCHSendChannelMessageFunc*>(object)->~CNMCHSendChannelMessageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}

// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4d50
void* NMScalarDelete_1415f4d50(void* object, unsigned int flags)
{
    static_cast<CNMCRBanUserFunc*>(object)->~CNMCRBanUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4d90
void* NMScalarDelete_1415f4d90(void* object, unsigned int flags)
{
    static_cast<CNMCRChangeMyInfoFunc*>(object)->~CNMCRChangeMyInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4dd0
void* NMScalarDelete_1415f4dd0(void* object, unsigned int flags)
{
    static_cast<CNMCRChangeRoomInfoFunc*>(object)->~CNMCRChangeRoomInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4e50
void* NMScalarDelete_1415f4e50(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomCreatedEvent*>(object)->~CNMCRChatRoomCreatedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4e90
void* NMScalarDelete_1415f4e90(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomCreatedExEvent*>(object)->~CNMCRChatRoomCreatedExEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4ed0
void* NMScalarDelete_1415f4ed0(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomErrorEvent*>(object)->~CNMCRChatRoomErrorEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4f10
void* NMScalarDelete_1415f4f10(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomEstablishedEvent*>(object)->~CNMCRChatRoomEstablishedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4f50
void* NMScalarDelete_1415f4f50(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomEstablishedExEvent*>(object)->~CNMCRChatRoomEstablishedExEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4f90
void* NMScalarDelete_1415f4f90(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomInfoEvent*>(object)->~CNMCRChatRoomInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f4fd0
void* NMScalarDelete_1415f4fd0(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomInfoExEvent*>(object)->~CNMCRChatRoomInfoExEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5010
void* NMScalarDelete_1415f5010(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomMemberEvent*>(object)->~CNMCRChatRoomMemberEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5050
void* NMScalarDelete_1415f5050(void* object, unsigned int flags)
{
    static_cast<CNMCRChatRoomMessageReceivedEvent*>(object)->~CNMCRChatRoomMessageReceivedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5090
void* NMScalarDelete_1415f5090(void* object, unsigned int flags)
{
    static_cast<CNMCRCloseFunc*>(object)->~CNMCRCloseFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f50d0
void* NMScalarDelete_1415f50d0(void* object, unsigned int flags)
{
    static_cast<CNMCRGetMemberInfoFunc*>(object)->~CNMCRGetMemberInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5110
void* NMScalarDelete_1415f5110(void* object, unsigned int flags)
{
    static_cast<CNMCRGetMemberListFunc*>(object)->~CNMCRGetMemberListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5150
void* NMScalarDelete_1415f5150(void* object, unsigned int flags)
{
    static_cast<CNMCRGetRoomInfoExFunc*>(object)->~CNMCRGetRoomInfoExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5190
void* NMScalarDelete_1415f5190(void* object, unsigned int flags)
{
    static_cast<CNMCRGetRoomInfoFunc*>(object)->~CNMCRGetRoomInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f51d0
void* NMScalarDelete_1415f51d0(void* object, unsigned int flags)
{
    static_cast<CNMCRInviteUserFunc*>(object)->~CNMCRInviteUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5210
void* NMScalarDelete_1415f5210(void* object, unsigned int flags)
{
    static_cast<CNMCRRegisterCallbackFunc*>(object)->~CNMCRRegisterCallbackFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5250
void* NMScalarDelete_1415f5250(void* object, unsigned int flags)
{
    static_cast<CNMCRSendChatMessageFunc*>(object)->~CNMCRSendChatMessageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5290
void* NMScalarDelete_1415f5290(void* object, unsigned int flags)
{
    static_cast<CNMCSChatMessageReceivedEvent*>(object)->~CNMCSChatMessageReceivedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5310
void* NMScalarDelete_1415f5310(void* object, unsigned int flags)
{
    static_cast<CNMCSMultiChatCreatedEvent*>(object)->~CNMCSMultiChatCreatedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5350
void* NMScalarDelete_1415f5350(void* object, unsigned int flags)
{
    static_cast<CNMCSSendChatMessageFunc*>(object)->~CNMCSSendChatMessageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5390
void* NMScalarDelete_1415f5390(void* object, unsigned int flags)
{
    static_cast<CNMCateFriendInfo*>(object)->~CNMCateFriendInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f53d0
void* NMScalarDelete_1415f53d0(void* object, unsigned int flags)
{
    static_cast<CNMCategoryInfo*>(object)->~CNMCategoryInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5410
void* NMScalarDelete_1415f5410(void* object, unsigned int flags)
{
    static_cast<CNMChangeCategoryAllowTypeFunc*>(object)->~CNMChangeCategoryAllowTypeFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5450
void* NMScalarDelete_1415f5450(void* object, unsigned int flags)
{
    static_cast<CNMChangeCategoryNameFunc*>(object)->~CNMChangeCategoryNameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5490
void* NMScalarDelete_1415f5490(void* object, unsigned int flags)
{
    static_cast<CNMChangeCategoryPropertyFunc*>(object)->~CNMChangeCategoryPropertyFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f54d0
void* NMScalarDelete_1415f54d0(void* object, unsigned int flags)
{
    static_cast<CNMChangeConfigFunc*>(object)->~CNMChangeConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}

// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5510
void* NMScalarDelete_1415f5510(void* object, unsigned int flags)
{
    static_cast<CNMChangeFriendMemoExFunc*>(object)->~CNMChangeFriendMemoExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5550
void* NMScalarDelete_1415f5550(void* object, unsigned int flags)
{
    static_cast<CNMChangeFriendMemoFunc*>(object)->~CNMChangeFriendMemoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5590
void* NMScalarDelete_1415f5590(void* object, unsigned int flags)
{
    static_cast<CNMChangeLocalConfigFunc*>(object)->~CNMChangeLocalConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f55d0
void* NMScalarDelete_1415f55d0(void* object, unsigned int flags)
{
    static_cast<CNMChangeMetaDataFunc*>(object)->~CNMChangeMetaDataFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5610
void* NMScalarDelete_1415f5610(void* object, unsigned int flags)
{
    static_cast<CNMChangeMyInfoFunc*>(object)->~CNMChangeMyInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5650
void* NMScalarDelete_1415f5650(void* object, unsigned int flags)
{
    static_cast<CNMChangeMyLevelFunc*>(object)->~CNMChangeMyLevelFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5690
void* NMScalarDelete_1415f5690(void* object, unsigned int flags)
{
    static_cast<CNMChangeMyPositionFunc*>(object)->~CNMChangeMyPositionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f56d0
void* NMScalarDelete_1415f56d0(void* object, unsigned int flags)
{
    static_cast<CNMChangeNicknameFunc*>(object)->~CNMChangeNicknameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5710
void* NMScalarDelete_1415f5710(void* object, unsigned int flags)
{
    static_cast<CNMChannelCreatedEvent*>(object)->~CNMChannelCreatedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5750
void* NMScalarDelete_1415f5750(void* object, unsigned int flags)
{
    static_cast<CNMChannelErrorEvent*>(object)->~CNMChannelErrorEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5790
void* NMScalarDelete_1415f5790(void* object, unsigned int flags)
{
    static_cast<CNMChannelEstablishedEvent*>(object)->~CNMChannelEstablishedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f57d0
void* NMScalarDelete_1415f57d0(void* object, unsigned int flags)
{
    static_cast<CNMChannelInfo*>(object)->~CNMChannelInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5810
void* NMScalarDelete_1415f5810(void* object, unsigned int flags)
{
    static_cast<CNMChannelInfoEvent*>(object)->~CNMChannelInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5850
void* NMScalarDelete_1415f5850(void* object, unsigned int flags)
{
    static_cast<CNMChannelMemberInfo*>(object)->~CNMChannelMemberInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5890
void* NMScalarDelete_1415f5890(void* object, unsigned int flags)
{
    static_cast<CNMChannelMemberInfoEvent*>(object)->~CNMChannelMemberInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f58d0
void* NMScalarDelete_1415f58d0(void* object, unsigned int flags)
{
    static_cast<CNMChannelMemberInfoList*>(object)->~CNMChannelMemberInfoList();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5910
void* NMScalarDelete_1415f5910(void* object, unsigned int flags)
{
    static_cast<CNMChannelMemberInfoListEvent*>(object)->~CNMChannelMemberInfoListEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5950
void* NMScalarDelete_1415f5950(void* object, unsigned int flags)
{
    static_cast<CNMChannelMessage*>(object)->~CNMChannelMessage();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5990
void* NMScalarDelete_1415f5990(void* object, unsigned int flags)
{
    static_cast<CNMChannelMessageEvent*>(object)->~CNMChannelMessageEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f59d0
void* NMScalarDelete_1415f59d0(void* object, unsigned int flags)
{
    static_cast<CNMCharacter*>(object)->~CNMCharacter();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5a10
void* NMScalarDelete_1415f5a10(void* object, unsigned int flags)
{
    static_cast<CNMCharacterChangeName64Func*>(object)->~CNMCharacterChangeName64Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5a50
void* NMScalarDelete_1415f5a50(void* object, unsigned int flags)
{
    static_cast<CNMCharacterChangeNameFunc*>(object)->~CNMCharacterChangeNameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5a90
void* NMScalarDelete_1415f5a90(void* object, unsigned int flags)
{
    static_cast<CNMCharacterLogin64Func*>(object)->~CNMCharacterLogin64Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5ad0
void* NMScalarDelete_1415f5ad0(void* object, unsigned int flags)
{
    static_cast<CNMCharacterLoginFunc*>(object)->~CNMCharacterLoginFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5b10
void* NMScalarDelete_1415f5b10(void* object, unsigned int flags)
{
    static_cast<CNMCharacterLogout64Func*>(object)->~CNMCharacterLogout64Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5b50
void* NMScalarDelete_1415f5b50(void* object, unsigned int flags)
{
    static_cast<CNMCharacterLogoutFunc*>(object)->~CNMCharacterLogoutFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5b90
void* NMScalarDelete_1415f5b90(void* object, unsigned int flags)
{
    static_cast<CNMCharacterRemove64Func*>(object)->~CNMCharacterRemove64Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5bd0
void* NMScalarDelete_1415f5bd0(void* object, unsigned int flags)
{
    static_cast<CNMCharacterRemoveFunc*>(object)->~CNMCharacterRemoveFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5c10
void* NMScalarDelete_1415f5c10(void* object, unsigned int flags)
{
    static_cast<CNMCharacterSync64Func*>(object)->~CNMCharacterSync64Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5c50
void* NMScalarDelete_1415f5c50(void* object, unsigned int flags)
{
    static_cast<CNMCharacterSyncFunc*>(object)->~CNMCharacterSyncFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5c90
void* NMScalarDelete_1415f5c90(void* object, unsigned int flags)
{
    static_cast<CNMChatMessage*>(object)->~CNMChatMessage();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5cd0
void* NMScalarDelete_1415f5cd0(void* object, unsigned int flags)
{
    static_cast<CNMChatRoomInfo*>(object)->~CNMChatRoomInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5d10
void* NMScalarDelete_1415f5d10(void* object, unsigned int flags)
{
    static_cast<CNMChatRoomInfoEx*>(object)->~CNMChatRoomInfoEx();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5d50
void* NMScalarDelete_1415f5d50(void* object, unsigned int flags)
{
    static_cast<CNMChatRoomMemberInfo*>(object)->~CNMChatRoomMemberInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5d90
void* NMScalarDelete_1415f5d90(void* object, unsigned int flags)
{
    static_cast<CNMChatRoomMemberList*>(object)->~CNMChatRoomMemberList();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5dd0
void* NMScalarDelete_1415f5dd0(void* object, unsigned int flags)
{
    static_cast<CNMCheckNewsFunc*>(object)->~CNMCheckNewsFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5e10
void* NMScalarDelete_1415f5e10(void* object, unsigned int flags)
{
    static_cast<CNMClientChannelInfo*>(object)->~CNMClientChannelInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5e50
void* NMScalarDelete_1415f5e50(void* object, unsigned int flags)
{
    static_cast<CNMConfirmNewFriendFunc*>(object)->~CNMConfirmNewFriendFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5e90
void* NMScalarDelete_1415f5e90(void* object, unsigned int flags)
{
    static_cast<CNMConnConfig*>(object)->~CNMConnConfig();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5ed0
void* NMScalarDelete_1415f5ed0(void* object, unsigned int flags)
{
    static_cast<CNMCreateChannelFunc*>(object)->~CNMCreateChannelFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5f10
void* NMScalarDelete_1415f5f10(void* object, unsigned int flags)
{
    static_cast<CNMCreateChatRoomExFunc*>(object)->~CNMCreateChatRoomExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5f50
void* NMScalarDelete_1415f5f50(void* object, unsigned int flags)
{
    static_cast<CNMCreateChatRoomFunc*>(object)->~CNMCreateChatRoomFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5f90
void* NMScalarDelete_1415f5f90(void* object, unsigned int flags)
{
    static_cast<CNMCustomMessageEvent*>(object)->~CNMCustomMessageEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f5fd0
void* NMScalarDelete_1415f5fd0(void* object, unsigned int flags)
{
    static_cast<CNMCustomNotifyData*>(object)->~CNMCustomNotifyData();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6010
void* NMScalarDelete_1415f6010(void* object, unsigned int flags)
{
    static_cast<CNMCustomNotifyEvent*>(object)->~CNMCustomNotifyEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6050
void* NMScalarDelete_1415f6050(void* object, unsigned int flags)
{
    static_cast<CNMCustomNotifyFunc*>(object)->~CNMCustomNotifyFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6090
void* NMScalarDelete_1415f6090(void* object, unsigned int flags)
{
    static_cast<CNMDefaultUserInfo*>(object)->~CNMDefaultUserInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f60d0
void* NMScalarDelete_1415f60d0(void* object, unsigned int flags)
{
    static_cast<CNMDeleteCategoryFunc*>(object)->~CNMDeleteCategoryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6110
void* NMScalarDelete_1415f6110(void* object, unsigned int flags)
{
    static_cast<CNMDeleteFriendFromCategoryFunc*>(object)->~CNMDeleteFriendFromCategoryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6150
void* NMScalarDelete_1415f6150(void* object, unsigned int flags)
{
    static_cast<CNMDetachFromNMCOServerFunc*>(object)->~CNMDetachFromNMCOServerFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6190
void* NMScalarDelete_1415f6190(void* object, unsigned int flags)
{
    static_cast<CNMDownloadFileFunc*>(object)->~CNMDownloadFileFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f61d0
void* NMScalarDelete_1415f61d0(void* object, unsigned int flags)
{
    static_cast<CNMDownloadGuildMarkFileFunc*>(object)->~CNMDownloadGuildMarkFileFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6210
void* NMScalarDelete_1415f6210(void* object, unsigned int flags)
{
    static_cast<CNMEvent*>(object)->~CNMEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6250
void* NMScalarDelete_1415f6250(void* object, unsigned int flags)
{
    static_cast<CNMExecuteCommonFunc*>(object)->~CNMExecuteCommonFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6290
void* NMScalarDelete_1415f6290(void* object, unsigned int flags)
{
    static_cast<CNMExecuteLauncherFunc*>(object)->~CNMExecuteLauncherFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f62d0
void* NMScalarDelete_1415f62d0(void* object, unsigned int flags)
{
    static_cast<CNMExecuteNGMInstallerFunc*>(object)->~CNMExecuteNGMInstallerFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6310
void* NMScalarDelete_1415f6310(void* object, unsigned int flags)
{
    static_cast<CNMExecuteNGMLauncherFunc*>(object)->~CNMExecuteNGMLauncherFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6350
void* NMScalarDelete_1415f6350(void* object, unsigned int flags)
{
    static_cast<CNMExecuteNGMPatcher2Func*>(object)->~CNMExecuteNGMPatcher2Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6390
void* NMScalarDelete_1415f6390(void* object, unsigned int flags)
{
    static_cast<CNMExecuteNGMPatcherFunc*>(object)->~CNMExecuteNGMPatcherFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f63d0
void* NMScalarDelete_1415f63d0(void* object, unsigned int flags)
{
    static_cast<CNMExecutePatcherFunc*>(object)->~CNMExecutePatcherFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6410
void* NMScalarDelete_1415f6410(void* object, unsigned int flags)
{
    static_cast<CNMFDSControlFunc*>(object)->~CNMFDSControlFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6450
void* NMScalarDelete_1415f6450(void* object, unsigned int flags)
{
    static_cast<CNMFDSFileDownloadEventReceivedEvent*>(object)->~CNMFDSFileDownloadEventReceivedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f64d0
void* NMScalarDelete_1415f64d0(void* object, unsigned int flags)
{
    static_cast<CNMFDSGetDownloadDirFunc*>(object)->~CNMFDSGetDownloadDirFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6510
void* NMScalarDelete_1415f6510(void* object, unsigned int flags)
{
    static_cast<CNMFDSSetDownloadDirFunc*>(object)->~CNMFDSSetDownloadDirFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6550
void* NMScalarDelete_1415f6550(void* object, unsigned int flags)
{
    static_cast<CNMFUDSGetFileEventFunc*>(object)->~CNMFUDSGetFileEventFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6590
void* NMScalarDelete_1415f6590(void* object, unsigned int flags)
{
    static_cast<CNMFUSControlFunc*>(object)->~CNMFUSControlFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f65d0
void* NMScalarDelete_1415f65d0(void* object, unsigned int flags)
{
    static_cast<CNMFUSFileUploadEventReceivedEvent*>(object)->~CNMFUSFileUploadEventReceivedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6650
void* NMScalarDelete_1415f6650(void* object, unsigned int flags)
{
    static_cast<CNMFUSSendFileFunc*>(object)->~CNMFUSSendFileFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6690
void* NMScalarDelete_1415f6690(void* object, unsigned int flags)
{
    static_cast<CNMFileEvent*>(object)->~CNMFileEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f66d0
void* NMScalarDelete_1415f66d0(void* object, unsigned int flags)
{
    static_cast<CNMFilePath*>(object)->~CNMFilePath();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6710
void* NMScalarDelete_1415f6710(void* object, unsigned int flags)
{
    static_cast<CNMFinalizeFunc*>(object)->~CNMFinalizeFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6750
void* NMScalarDelete_1415f6750(void* object, unsigned int flags)
{
    static_cast<CNMFindUserFunc*>(object)->~CNMFindUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6790
void* NMScalarDelete_1415f6790(void* object, unsigned int flags)
{
    static_cast<CNMFindUserInfo*>(object)->~CNMFindUserInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f67d0
void* NMScalarDelete_1415f67d0(void* object, unsigned int flags)
{
    static_cast<CNMFindUserReplyEvent*>(object)->~CNMFindUserReplyEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6810
void* NMScalarDelete_1415f6810(void* object, unsigned int flags)
{
    static_cast<CNMFindUserRequestInfo*>(object)->~CNMFindUserRequestInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6850
void* NMScalarDelete_1415f6850(void* object, unsigned int flags)
{
    static_cast<CNMFriendInfo*>(object)->~CNMFriendInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6890
void* NMScalarDelete_1415f6890(void* object, unsigned int flags)
{
    static_cast<CNMFriendInfoChangedEvent*>(object)->~CNMFriendInfoChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f68d0
void* NMScalarDelete_1415f68d0(void* object, unsigned int flags)
{
    static_cast<CNMFriendList*>(object)->~CNMFriendList();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6910
void* NMScalarDelete_1415f6910(void* object, unsigned int flags)
{
    static_cast<CNMFunc*>(object)->~CNMFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6990
void* NMScalarDelete_1415f6990(void* object, unsigned int flags)
{
    static_cast<CNMGSGetInviteCandidateListFunc*>(object)->~CNMGSGetInviteCandidateListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f69d0
void* NMScalarDelete_1415f69d0(void* object, unsigned int flags)
{
    static_cast<CNMGSGetMemberListFunc*>(object)->~CNMGSGetMemberListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6a10
void* NMScalarDelete_1415f6a10(void* object, unsigned int flags)
{
    static_cast<CNMGSGetSessionInfoFunc*>(object)->~CNMGSGetSessionInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6a50
void* NMScalarDelete_1415f6a50(void* object, unsigned int flags)
{
    static_cast<CNMGSInviteRejectedEvent*>(object)->~CNMGSInviteRejectedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}

// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6a90
void* NMScalarDelete_1415f6a90(void* object, unsigned int flags)
{
    static_cast<CNMGSInviteUserExFunc*>(object)->~CNMGSInviteUserExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6ad0
void* NMScalarDelete_1415f6ad0(void* object, unsigned int flags)
{
    static_cast<CNMGSInviteUserFunc*>(object)->~CNMGSInviteUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6b10
void* NMScalarDelete_1415f6b10(void* object, unsigned int flags)
{
    static_cast<CNMGSMemberInfoChangedEvent*>(object)->~CNMGSMemberInfoChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6b50
void* NMScalarDelete_1415f6b50(void* object, unsigned int flags)
{
    static_cast<CNMGSMemberLeavedEvent*>(object)->~CNMGSMemberLeavedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6b90
void* NMScalarDelete_1415f6b90(void* object, unsigned int flags)
{
    static_cast<CNMGSNewMemberJoinedEvent*>(object)->~CNMGSNewMemberJoinedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6bd0
void* NMScalarDelete_1415f6bd0(void* object, unsigned int flags)
{
    static_cast<CNMGSRegisterCallbackFunc*>(object)->~CNMGSRegisterCallbackFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6c10
void* NMScalarDelete_1415f6c10(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionClosedEvent*>(object)->~CNMGSSessionClosedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6c50
void* NMScalarDelete_1415f6c50(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionCreatedEvent*>(object)->~CNMGSSessionCreatedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6c90
void* NMScalarDelete_1415f6c90(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionEstablishedEvent*>(object)->~CNMGSSessionEstablishedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6cd0
void* NMScalarDelete_1415f6cd0(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionFailedEvent*>(object)->~CNMGSSessionFailedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6d10
void* NMScalarDelete_1415f6d10(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionInfoChangedEvent*>(object)->~CNMGSSessionInfoChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6d50
void* NMScalarDelete_1415f6d50(void* object, unsigned int flags)
{
    static_cast<CNMGSSessionInfoEvent*>(object)->~CNMGSSessionInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6d90
void* NMScalarDelete_1415f6d90(void* object, unsigned int flags)
{
    static_cast<CNMGSSetServingProcessIDFunc*>(object)->~CNMGSSetServingProcessIDFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6dd0
void* NMScalarDelete_1415f6dd0(void* object, unsigned int flags)
{
    static_cast<CNMGSWantCloseFunc*>(object)->~CNMGSWantCloseFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6e10
void* NMScalarDelete_1415f6e10(void* object, unsigned int flags)
{
    static_cast<CNMGameCode*>(object)->~CNMGameCode();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6e50
void* NMScalarDelete_1415f6e50(void* object, unsigned int flags)
{
    static_cast<CNMGameInfo*>(object)->~CNMGameInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6e90
void* NMScalarDelete_1415f6e90(void* object, unsigned int flags)
{
    static_cast<CNMGameListData*>(object)->~CNMGameListData();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6ed0
void* NMScalarDelete_1415f6ed0(void* object, unsigned int flags)
{
    static_cast<CNMGameLogFinalizeFunc*>(object)->~CNMGameLogFinalizeFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6f10
void* NMScalarDelete_1415f6f10(void* object, unsigned int flags)
{
    static_cast<CNMGameLogGetSessionIDFunc*>(object)->~CNMGameLogGetSessionIDFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6f50
void* NMScalarDelete_1415f6f50(void* object, unsigned int flags)
{
    static_cast<CNMGameLogInitializeFunc*>(object)->~CNMGameLogInitializeFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6f90
void* NMScalarDelete_1415f6f90(void* object, unsigned int flags)
{
    static_cast<CNMGameLogWriteErrorLogFunc*>(object)->~CNMGameLogWriteErrorLogFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f6fd0
void* NMScalarDelete_1415f6fd0(void* object, unsigned int flags)
{
    static_cast<CNMGameLogWriteStageLogFunc*>(object)->~CNMGameLogWriteStageLogFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7010
void* NMScalarDelete_1415f7010(void* object, unsigned int flags)
{
    static_cast<CNMGameServerCode*>(object)->~CNMGameServerCode();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7050
void* NMScalarDelete_1415f7050(void* object, unsigned int flags)
{
    static_cast<CNMGetConfigFunc*>(object)->~CNMGetConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7090
void* NMScalarDelete_1415f7090(void* object, unsigned int flags)
{
    static_cast<CNMGetConnConfigFunc*>(object)->~CNMGetConnConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f70d0
void* NMScalarDelete_1415f70d0(void* object, unsigned int flags)
{
    static_cast<CNMGetCountFunc*>(object)->~CNMGetCountFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7110
void* NMScalarDelete_1415f7110(void* object, unsigned int flags)
{
    static_cast<CNMGetDomainFunc*>(object)->~CNMGetDomainFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7150
void* NMScalarDelete_1415f7150(void* object, unsigned int flags)
{
    static_cast<CNMGetFindUserResultFunc*>(object)->~CNMGetFindUserResultFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7190
void* NMScalarDelete_1415f7190(void* object, unsigned int flags)
{
    static_cast<CNMGetFriendInfoFunc*>(object)->~CNMGetFriendInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f71d0
void* NMScalarDelete_1415f71d0(void* object, unsigned int flags)
{
    static_cast<CNMGetFriendListFunc*>(object)->~CNMGetFriendListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7210
void* NMScalarDelete_1415f7210(void* object, unsigned int flags)
{
    static_cast<CNMGetGameFriendTitleFunc*>(object)->~CNMGetGameFriendTitleFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7250
void* NMScalarDelete_1415f7250(void* object, unsigned int flags)
{
    static_cast<CNMGetGameFullNameFunc*>(object)->~CNMGetGameFullNameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7290
void* NMScalarDelete_1415f7290(void* object, unsigned int flags)
{
    static_cast<CNMGetGameListFunc*>(object)->~CNMGetGameListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f72d0
void* NMScalarDelete_1415f72d0(void* object, unsigned int flags)
{
    static_cast<CNMGetGameServerListFunc*>(object)->~CNMGetGameServerListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7310
void* NMScalarDelete_1415f7310(void* object, unsigned int flags)
{
    static_cast<CNMGetGameServerNameFunc*>(object)->~CNMGetGameServerNameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7350
void* NMScalarDelete_1415f7350(void* object, unsigned int flags)
{
    static_cast<CNMGetGameShortNameFunc*>(object)->~CNMGetGameShortNameFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7390
void* NMScalarDelete_1415f7390(void* object, unsigned int flags)
{
    static_cast<CNMGetGameTokenFunc*>(object)->~CNMGetGameTokenFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f73d0
void* NMScalarDelete_1415f73d0(void* object, unsigned int flags)
{
    static_cast<CNMGetLocalConfigFunc*>(object)->~CNMGetLocalConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7410
void* NMScalarDelete_1415f7410(void* object, unsigned int flags)
{
    static_cast<CNMGetMyGuildListExFunc*>(object)->~CNMGetMyGuildListExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7450
void* NMScalarDelete_1415f7450(void* object, unsigned int flags)
{
    static_cast<CNMGetMyInfoFunc*>(object)->~CNMGetMyInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7490
void* NMScalarDelete_1415f7490(void* object, unsigned int flags)
{
    static_cast<CNMGetMyVirtualUserListFunc*>(object)->~CNMGetMyVirtualUserListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f74d0
void* NMScalarDelete_1415f74d0(void* object, unsigned int flags)
{
    static_cast<CNMGetNexonPassportFunc*>(object)->~CNMGetNexonPassportFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7510
void* NMScalarDelete_1415f7510(void* object, unsigned int flags)
{
    static_cast<CNMGetNoteBox2Func*>(object)->~CNMGetNoteBox2Func();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7550
void* NMScalarDelete_1415f7550(void* object, unsigned int flags)
{
    static_cast<CNMGetNoteBoxFunc*>(object)->~CNMGetNoteBoxFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7590
void* NMScalarDelete_1415f7590(void* object, unsigned int flags)
{
    static_cast<CNMGetNxHWIDFunc*>(object)->~CNMGetNxHWIDFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f75d0
void* NMScalarDelete_1415f75d0(void* object, unsigned int flags)
{
    static_cast<CNMGetPathFunc*>(object)->~CNMGetPathFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7610
void* NMScalarDelete_1415f7610(void* object, unsigned int flags)
{
    static_cast<CNMGetRejectedUserListFunc*>(object)->~CNMGetRejectedUserListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7650
void* NMScalarDelete_1415f7650(void* object, unsigned int flags)
{
    static_cast<CNMGetSecurityCodeCNFunc*>(object)->~CNMGetSecurityCodeCNFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7690
void* NMScalarDelete_1415f7690(void* object, unsigned int flags)
{
    static_cast<CNMGetSecurityQuestionFunc*>(object)->~CNMGetSecurityQuestionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f76d0
void* NMScalarDelete_1415f76d0(void* object, unsigned int flags)
{
    static_cast<CNMGetServerInfoFunc*>(object)->~CNMGetServerInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7710
void* NMScalarDelete_1415f7710(void* object, unsigned int flags)
{
    static_cast<CNMGetSessionValueFunc*>(object)->~CNMGetSessionValueFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7750
void* NMScalarDelete_1415f7750(void* object, unsigned int flags)
{
    static_cast<CNMGetSupportGameListFunc*>(object)->~CNMGetSupportGameListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7790
void* NMScalarDelete_1415f7790(void* object, unsigned int flags)
{
    static_cast<CNMGetUrlExFunc*>(object)->~CNMGetUrlExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f77d0
void* NMScalarDelete_1415f77d0(void* object, unsigned int flags)
{
    static_cast<CNMGetUrlFunc*>(object)->~CNMGetUrlFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7810
void* NMScalarDelete_1415f7810(void* object, unsigned int flags)
{
    static_cast<CNMGetUserDataListFunc*>(object)->~CNMGetUserDataListFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7850
void* NMScalarDelete_1415f7850(void* object, unsigned int flags)
{
    static_cast<CNMGetUserInfoFunc*>(object)->~CNMGetUserInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7890
void* NMScalarDelete_1415f7890(void* object, unsigned int flags)
{
    static_cast<CNMGuildChatMessageEvent*>(object)->~CNMGuildChatMessageEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f78d0
void* NMScalarDelete_1415f78d0(void* object, unsigned int flags)
{
    static_cast<CNMGuildInfoEx*>(object)->~CNMGuildInfoEx();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7910
void* NMScalarDelete_1415f7910(void* object, unsigned int flags)
{
    static_cast<CNMGuildListExInfo*>(object)->~CNMGuildListExInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7950
void* NMScalarDelete_1415f7950(void* object, unsigned int flags)
{
    static_cast<CNMGuildMemberInfo*>(object)->~CNMGuildMemberInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7990
void* NMScalarDelete_1415f7990(void* object, unsigned int flags)
{
    static_cast<CNMGuildMemberLevelInfo*>(object)->~CNMGuildMemberLevelInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f79d0
void* NMScalarDelete_1415f79d0(void* object, unsigned int flags)
{
    static_cast<CNMGuildOnlineInfo*>(object)->~CNMGuildOnlineInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7a10
void* NMScalarDelete_1415f7a10(void* object, unsigned int flags)
{
    static_cast<CNMGuildOnlineInfoEvent*>(object)->~CNMGuildOnlineInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7a50
void* NMScalarDelete_1415f7a50(void* object, unsigned int flags)
{
    static_cast<CNMGuildOnlineInfoEx*>(object)->~CNMGuildOnlineInfoEx();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7a90
void* NMScalarDelete_1415f7a90(void* object, unsigned int flags)
{
    static_cast<CNMGuildOnlineInfoExEvent*>(object)->~CNMGuildOnlineInfoExEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7ad0
void* NMScalarDelete_1415f7ad0(void* object, unsigned int flags)
{
    static_cast<CNMInitializeFunc*>(object)->~CNMInitializeFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7b10
void* NMScalarDelete_1415f7b10(void* object, unsigned int flags)
{
    static_cast<CNMInviteVirtualUserEvent*>(object)->~CNMInviteVirtualUserEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7b50
void* NMScalarDelete_1415f7b50(void* object, unsigned int flags)
{
    static_cast<CNMIsNGMInstalledFunc*>(object)->~CNMIsNGMInstalledFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7b90
void* NMScalarDelete_1415f7b90(void* object, unsigned int flags)
{
    static_cast<CNMJoinChannelFunc*>(object)->~CNMJoinChannelFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7bd0
void* NMScalarDelete_1415f7bd0(void* object, unsigned int flags)
{
    static_cast<CNMJoinToChatRoomExFunc*>(object)->~CNMJoinToChatRoomExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7c10
void* NMScalarDelete_1415f7c10(void* object, unsigned int flags)
{
    static_cast<CNMJoinToChatRoomFunc*>(object)->~CNMJoinToChatRoomFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7c50
void* NMScalarDelete_1415f7c50(void* object, unsigned int flags)
{
    static_cast<CNMLogReportSyncEvent*>(object)->~CNMLogReportSyncEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7c90
void* NMScalarDelete_1415f7c90(void* object, unsigned int flags)
{
    static_cast<CNMLogReportSyncFunc*>(object)->~CNMLogReportSyncFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7cd0
void* NMScalarDelete_1415f7cd0(void* object, unsigned int flags)
{
    static_cast<CNMLoginAuthFunc*>(object)->~CNMLoginAuthFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7d10
void* NMScalarDelete_1415f7d10(void* object, unsigned int flags)
{
    static_cast<CNMLoginAuthSecurityCNFunc*>(object)->~CNMLoginAuthSecurityCNFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7d50
void* NMScalarDelete_1415f7d50(void* object, unsigned int flags)
{
    static_cast<CNMLoginMessengerFunc*>(object)->~CNMLoginMessengerFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7d90
void* NMScalarDelete_1415f7d90(void* object, unsigned int flags)
{
    static_cast<CNMLoginNexonPassportFunc*>(object)->~CNMLoginNexonPassportFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7dd0
void* NMScalarDelete_1415f7dd0(void* object, unsigned int flags)
{
    static_cast<CNMLoginPassportFunc*>(object)->~CNMLoginPassportFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7e10
void* NMScalarDelete_1415f7e10(void* object, unsigned int flags)
{
    static_cast<CNMLoginVirtualFunc*>(object)->~CNMLoginVirtualFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7e50
void* NMScalarDelete_1415f7e50(void* object, unsigned int flags)
{
    static_cast<CNMLogoutAuthFunc*>(object)->~CNMLogoutAuthFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7e90
void* NMScalarDelete_1415f7e90(void* object, unsigned int flags)
{
    static_cast<CNMLogoutMessengerFunc*>(object)->~CNMLogoutMessengerFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7ed0
void* NMScalarDelete_1415f7ed0(void* object, unsigned int flags)
{
    static_cast<CNMLogoutVirtualFunc*>(object)->~CNMLogoutVirtualFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7f10
void* NMScalarDelete_1415f7f10(void* object, unsigned int flags)
{
    static_cast<CNMManager*>(object)->~CNMManager();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7f50
void* NMScalarDelete_1415f7f50(void* object, unsigned int flags)
{
    static_cast<CNMMessageData*>(object)->~CNMMessageData();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7f90
void* NMScalarDelete_1415f7f90(void* object, unsigned int flags)
{
    static_cast<CNMMessengerReplyEvent*>(object)->~CNMMessengerReplyEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f7fd0
void* NMScalarDelete_1415f7fd0(void* object, unsigned int flags)
{
    static_cast<CNMMinimizeAllFunc*>(object)->~CNMMinimizeAllFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8010
void* NMScalarDelete_1415f8010(void* object, unsigned int flags)
{
    static_cast<CNMMonitorGuildOnlineInfoExFunc*>(object)->~CNMMonitorGuildOnlineInfoExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8050
void* NMScalarDelete_1415f8050(void* object, unsigned int flags)
{
    static_cast<CNMMonitorGuildOnlineInfoFunc*>(object)->~CNMMonitorGuildOnlineInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8090
void* NMScalarDelete_1415f8090(void* object, unsigned int flags)
{
    static_cast<CNMMoveFriendCategoryFunc*>(object)->~CNMMoveFriendCategoryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f80d0
void* NMScalarDelete_1415f80d0(void* object, unsigned int flags)
{
    static_cast<CNMMsgConnectionClosedEvent*>(object)->~CNMMsgConnectionClosedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8110
void* NMScalarDelete_1415f8110(void* object, unsigned int flags)
{
    static_cast<CNMMyGameInfo*>(object)->~CNMMyGameInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8150
void* NMScalarDelete_1415f8150(void* object, unsigned int flags)
{
    static_cast<CNMNoteInfo2*>(object)->~CNMNoteInfo2();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8190
void* NMScalarDelete_1415f8190(void* object, unsigned int flags)
{
    static_cast<CNMNoteInfo*>(object)->~CNMNoteInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f81d0
void* NMScalarDelete_1415f81d0(void* object, unsigned int flags)
{
    static_cast<CNMNoteInfoEvent*>(object)->~CNMNoteInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8210
void* NMScalarDelete_1415f8210(void* object, unsigned int flags)
{
    static_cast<CNMNoteInfoEx*>(object)->~CNMNoteInfoEx();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8250
void* NMScalarDelete_1415f8250(void* object, unsigned int flags)
{
    static_cast<CNMNoteInstantMsgEvent*>(object)->~CNMNoteInstantMsgEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8290
void* NMScalarDelete_1415f8290(void* object, unsigned int flags)
{
    static_cast<CNMNotifyEvent*>(object)->~CNMNotifyEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f82d0
void* NMScalarDelete_1415f82d0(void* object, unsigned int flags)
{
    static_cast<CNMOpenGameSummaryFunc*>(object)->~CNMOpenGameSummaryFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8310
void* NMScalarDelete_1415f8310(void* object, unsigned int flags)
{
    static_cast<CNMPCBangLoginFunc*>(object)->~CNMPCBangLoginFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8350
void* NMScalarDelete_1415f8350(void* object, unsigned int flags)
{
    static_cast<CNMProcessNoteFunc*>(object)->~CNMProcessNoteFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8390
void* NMScalarDelete_1415f8390(void* object, unsigned int flags)
{
    static_cast<CNMRealFriendInfo*>(object)->~CNMRealFriendInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f83d0
void* NMScalarDelete_1415f83d0(void* object, unsigned int flags)
{
    static_cast<CNMRealFriendInfoChangedEvent*>(object)->~CNMRealFriendInfoChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8410
void* NMScalarDelete_1415f8410(void* object, unsigned int flags)
{
    static_cast<CNMRealUserInfo*>(object)->~CNMRealUserInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8450
void* NMScalarDelete_1415f8450(void* object, unsigned int flags)
{
    static_cast<CNMRefreshEvent*>(object)->~CNMRefreshEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8490
void* NMScalarDelete_1415f8490(void* object, unsigned int flags)
{
    static_cast<CNMRefreshMessageEvent*>(object)->~CNMRefreshMessageEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f84d0
void* NMScalarDelete_1415f84d0(void* object, unsigned int flags)
{
    static_cast<CNMRegisterCallbackFunc*>(object)->~CNMRegisterCallbackFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8510
void* NMScalarDelete_1415f8510(void* object, unsigned int flags)
{
    static_cast<CNMRejectedUser*>(object)->~CNMRejectedUser();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8550
void* NMScalarDelete_1415f8550(void* object, unsigned int flags)
{
    static_cast<CNMRejectedUserListChangedEvent*>(object)->~CNMRejectedUserListChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8590
void* NMScalarDelete_1415f8590(void* object, unsigned int flags)
{
    static_cast<CNMRemoveMyVirtualUserFunc*>(object)->~CNMRemoveMyVirtualUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f85d0
void* NMScalarDelete_1415f85d0(void* object, unsigned int flags)
{
    static_cast<CNMRemoveRejectedUserFunc*>(object)->~CNMRemoveRejectedUserFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8610
void* NMScalarDelete_1415f8610(void* object, unsigned int flags)
{
    static_cast<CNMReplySessionRequestFunc*>(object)->~CNMReplySessionRequestFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8650
void* NMScalarDelete_1415f8650(void* object, unsigned int flags)
{
    static_cast<CNMReportInfo*>(object)->~CNMReportInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8690
void* NMScalarDelete_1415f8690(void* object, unsigned int flags)
{
    static_cast<CNMRequestChatSessionExFunc*>(object)->~CNMRequestChatSessionExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f86d0
void* NMScalarDelete_1415f86d0(void* object, unsigned int flags)
{
    static_cast<CNMRequestChatSessionFunc*>(object)->~CNMRequestChatSessionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8710
void* NMScalarDelete_1415f8710(void* object, unsigned int flags)
{
    static_cast<CNMRequestFileUploadSessionExFunc*>(object)->~CNMRequestFileUploadSessionExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8750
void* NMScalarDelete_1415f8750(void* object, unsigned int flags)
{
    static_cast<CNMRequestFileUploadSessionFunc*>(object)->~CNMRequestFileUploadSessionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8790
void* NMScalarDelete_1415f8790(void* object, unsigned int flags)
{
    static_cast<CNMRequestMultiChatSessionExFunc*>(object)->~CNMRequestMultiChatSessionExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f87d0
void* NMScalarDelete_1415f87d0(void* object, unsigned int flags)
{
    static_cast<CNMRequestMultiChatSessionFunc*>(object)->~CNMRequestMultiChatSessionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8810
void* NMScalarDelete_1415f8810(void* object, unsigned int flags)
{
    static_cast<CNMRequestNewFriendData*>(object)->~CNMRequestNewFriendData();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8850
void* NMScalarDelete_1415f8850(void* object, unsigned int flags)
{
    static_cast<CNMRequestNewFriendEvent*>(object)->~CNMRequestNewFriendEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8890
void* NMScalarDelete_1415f8890(void* object, unsigned int flags)
{
    static_cast<CNMRequestNewFriendFunc*>(object)->~CNMRequestNewFriendFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f88d0
void* NMScalarDelete_1415f88d0(void* object, unsigned int flags)
{
    static_cast<CNMRequestNewsFunc*>(object)->~CNMRequestNewsFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8910
void* NMScalarDelete_1415f8910(void* object, unsigned int flags)
{
    static_cast<CNMRequestSessionData*>(object)->~CNMRequestSessionData();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8950
void* NMScalarDelete_1415f8950(void* object, unsigned int flags)
{
    static_cast<CNMRequestSessionToOtherFunc*>(object)->~CNMRequestSessionToOtherFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8990
void* NMScalarDelete_1415f8990(void* object, unsigned int flags)
{
    static_cast<CNMRequestWBSessionExFunc*>(object)->~CNMRequestWBSessionExFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f89d0
void* NMScalarDelete_1415f89d0(void* object, unsigned int flags)
{
    static_cast<CNMRequestWBSessionFunc*>(object)->~CNMRequestWBSessionFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8a10
void* NMScalarDelete_1415f8a10(void* object, unsigned int flags)
{
    static_cast<CNMResetCallbackFunc*>(object)->~CNMResetCallbackFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8a50
void* NMScalarDelete_1415f8a50(void* object, unsigned int flags)
{
    static_cast<CNMRestrictedWordsFunc*>(object)->~CNMRestrictedWordsFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8a90
void* NMScalarDelete_1415f8a90(void* object, unsigned int flags)
{
    static_cast<CNMSelfUserInfo*>(object)->~CNMSelfUserInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8ad0
void* NMScalarDelete_1415f8ad0(void* object, unsigned int flags)
{
    static_cast<CNMSendAccuseNoteMsgFunc*>(object)->~CNMSendAccuseNoteMsgFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8b10
void* NMScalarDelete_1415f8b10(void* object, unsigned int flags)
{
    static_cast<CNMSendNoteExMsgFunc*>(object)->~CNMSendNoteExMsgFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8b50
void* NMScalarDelete_1415f8b50(void* object, unsigned int flags)
{
    static_cast<CNMSendNoteInfoFunc*>(object)->~CNMSendNoteInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8b90
void* NMScalarDelete_1415f8b90(void* object, unsigned int flags)
{
    static_cast<CNMSendNoteMsgFunc*>(object)->~CNMSendNoteMsgFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8bd0
void* NMScalarDelete_1415f8bd0(void* object, unsigned int flags)
{
    static_cast<CNMSendRefreshMessageFunc*>(object)->~CNMSendRefreshMessageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8c10
void* NMScalarDelete_1415f8c10(void* object, unsigned int flags)
{
    static_cast<CNMSerializable*>(object)->~CNMSerializable();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8c50
void* NMScalarDelete_1415f8c50(void* object, unsigned int flags)
{
    static_cast<CNMServerMessageEvent*>(object)->~CNMServerMessageEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8c90
void* NMScalarDelete_1415f8c90(void* object, unsigned int flags)
{
    static_cast<CNMSessionInfo*>(object)->~CNMSessionInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8cd0
void* NMScalarDelete_1415f8cd0(void* object, unsigned int flags)
{
    static_cast<CNMSessionMemberInfo*>(object)->~CNMSessionMemberInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8d10
void* NMScalarDelete_1415f8d10(void* object, unsigned int flags)
{
    static_cast<CNMSessionMemberList*>(object)->~CNMSessionMemberList();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8d50
void* NMScalarDelete_1415f8d50(void* object, unsigned int flags)
{
    static_cast<CNMSetAuthClosedCallbackFunc*>(object)->~CNMSetAuthClosedCallbackFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8d90
void* NMScalarDelete_1415f8d90(void* object, unsigned int flags)
{
    static_cast<CNMSetCodePageFunc*>(object)->~CNMSetCodePageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8dd0
void* NMScalarDelete_1415f8dd0(void* object, unsigned int flags)
{
    static_cast<CNMSetConnConfigFunc*>(object)->~CNMSetConnConfigFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8e10
void* NMScalarDelete_1415f8e10(void* object, unsigned int flags)
{
    static_cast<CNMSetCountFunc*>(object)->~CNMSetCountFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8e50
void* NMScalarDelete_1415f8e50(void* object, unsigned int flags)
{
    static_cast<CNMSetLocaleFunc*>(object)->~CNMSetLocaleFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8e90
void* NMScalarDelete_1415f8e90(void* object, unsigned int flags)
{
    static_cast<CNMSetServerInfoFunc*>(object)->~CNMSetServerInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8ed0
void* NMScalarDelete_1415f8ed0(void* object, unsigned int flags)
{
    static_cast<CNMSetSessionValueFunc*>(object)->~CNMSetSessionValueFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8f10
void* NMScalarDelete_1415f8f10(void* object, unsigned int flags)
{
    static_cast<CNMSetStatInfoFunc*>(object)->~CNMSetStatInfoFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8f50
void* NMScalarDelete_1415f8f50(void* object, unsigned int flags)
{
    static_cast<CNMSpecialEvent*>(object)->~CNMSpecialEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8f90
void* NMScalarDelete_1415f8f90(void* object, unsigned int flags)
{
    static_cast<CNMStartStandAloneMsgFunc*>(object)->~CNMStartStandAloneMsgFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f8fd0
void* NMScalarDelete_1415f8fd0(void* object, unsigned int flags)
{
    static_cast<CNMTPATokenLoginFunc*>(object)->~CNMTPATokenLoginFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f9010
void* NMScalarDelete_1415f9010(void* object, unsigned int flags)
{
    static_cast<CNMUploadFileFunc*>(object)->~CNMUploadFileFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f9050
void* NMScalarDelete_1415f9050(void* object, unsigned int flags)
{
    static_cast<CNMUserInfoEvent*>(object)->~CNMUserInfoEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f9090
void* NMScalarDelete_1415f9090(void* object, unsigned int flags)
{
    static_cast<CNMVirtualFriendInfo*>(object)->~CNMVirtualFriendInfo();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f90d0
void* NMScalarDelete_1415f90d0(void* object, unsigned int flags)
{
    static_cast<CNMVirtualFriendInfoChangedEvent*>(object)->~CNMVirtualFriendInfoChangedEvent();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f9190
void* NMScalarDelete_1415f9190(void* object, unsigned int flags)
{
    static_cast<CNMWSGetAssocSerialKeyFunc*>(object)->~CNMWSGetAssocSerialKeyFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f91d0
void* NMScalarDelete_1415f91d0(void* object, unsigned int flags)
{
    static_cast<CNMWSSendWBMessageFunc*>(object)->~CNMWSSendWBMessageFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}
// MS2-FUNCTIONAL: calls the recovered class destructor and frees the object only for flag bit 0.
// @0x1415f92d0
void* NMScalarDelete_1415f92d0(void* object, unsigned int flags)
{
    static_cast<CNMWriteToWiselogFunc*>(object)->~CNMWriteToWiselogFunc();
    if (flags & 1) ::operator delete(object);
    return object;
}

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3980
void* FUN_1415f3980(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f39b0
void* FUN_1415f39b0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3a30
void* FUN_1415f3a30(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3a40
void* FUN_1415f3a40(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3a50
void* FUN_1415f3a50(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3ae0
void* FUN_1415f3ae0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3af0
void* FUN_1415f3af0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b00
void* FUN_1415f3b00(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b10
void* FUN_1415f3b10(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b20
void* FUN_1415f3b20(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b30
void* FUN_1415f3b30(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b40
void* FUN_1415f3b40(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b50
void* FUN_1415f3b50(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b60
void* FUN_1415f3b60(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b70
void* FUN_1415f3b70(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b80
void* FUN_1415f3b80(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3b90
void* FUN_1415f3b90(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3ba0
void* FUN_1415f3ba0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3bb0
void* FUN_1415f3bb0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3bc0
void* FUN_1415f3bc0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3bd0
void* FUN_1415f3bd0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3be0
void* FUN_1415f3be0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3bf0
void* FUN_1415f3bf0(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3c00
void* FUN_1415f3c00(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3c10
void* FUN_1415f3c10(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3c20
void* FUN_1415f3c20(void* p) { return *static_cast<void**>(p); }

// MS2-FUNCTIONAL: returns the pointer-sized value stored in the first field.
// @0x1415f3c30
void* FUN_1415f3c30(void* p) { return *static_cast<void**>(p); }
