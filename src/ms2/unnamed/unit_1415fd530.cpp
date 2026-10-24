// Recovered Nexon Messenger vector growth/reallocation helpers from unit_1415fd530.
// MS2-UNIT: unit_1415fd530
// MS2-RANGE: 0x1415fd530-0x141601f30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstddef>
#include <cstdint>
#include <new>

// @0x1415ffc70
void FUN_1415ffc70() {}

// @0x1415ffc80
void FUN_1415ffc80() {}

// @0x1415ffc90
void FUN_1415ffc90() {}

// @0x1415ffca0
void FUN_1415ffca0() {}

// @0x1415ffcb0
void FUN_1415ffcb0() {}

// @0x1415ffcc0
void FUN_1415ffcc0() {}

// @0x1415ffcd0
void FUN_1415ffcd0() {}

// @0x1415ffce0
void FUN_1415ffce0() {}

// @0x1415ffcf0
void FUN_1415ffcf0() {}

// @0x1415ffd00
void FUN_1415ffd00() {}

// @0x1415ffd10
void FUN_1415ffd10() {}

// @0x1415ffd20
void FUN_1415ffd20() {}

// @0x1415ffd30
void FUN_1415ffd30() {}

// @0x1415ffd40
void FUN_1415ffd40() {}

// @0x1415ffd50
void FUN_1415ffd50() {}

// @0x1415ffd60
void FUN_1415ffd60() {}

// @0x1415ffd70
void FUN_1415ffd70() {}

// @0x1415ffd80
void FUN_1415ffd80() {}

// @0x1415ffd90
void FUN_1415ffd90() {}

// @0x1415ffda0
void FUN_1415ffda0() {}

// @0x1415ffdb0
void FUN_1415ffdb0() {}

// @0x1415ffdc0
void FUN_1415ffdc0() {}

// @0x1415ffdd0
void FUN_1415ffdd0() {}

// @0x1415ffde0
void FUN_1415ffde0() {}

template <class T>
static unsigned long long nm_vector_growth(const std::vector<T>& vector, unsigned long long requested)
{
    const unsigned long long current = vector.capacity();
    const unsigned long long limit = vector.max_size();
    unsigned long long grown = requested;
    if (current <= limit - current / 2) {
        grown = current + current / 2;
        if (grown < requested) grown = requested;
    }
    return grown;
}
static void nm_vector_change_array(void* p, void* memory, unsigned long long size, unsigned long long capacity, size_t elementSize)
{
    auto** fields = static_cast<unsigned char**>(p);
    void* old = fields[0];
    if (old && old != memory) ::operator delete(old);
    auto* first = static_cast<unsigned char*>(memory);
    fields[0] = first;
    fields[1] = first ? first + size * elementSize : nullptr;
    fields[2] = first ? first + capacity * elementSize : nullptr;
}

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd6d0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<NMChatSessionTarget>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd6d0@@YA_KPEAX_K@Z 0x1415fd6d0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd760(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<NMFriendKey>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd760@@YA_KPEAX_K@Z 0x1415fd760 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd7f0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMCateFriendInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd7f0@@YA_KPEAX_K@Z 0x1415fd7f0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd880(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMChannelMemberInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd880@@YA_KPEAX_K@Z 0x1415fd880 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd910(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMCharacter>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd910@@YA_KPEAX_K@Z 0x1415fd910 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fd9a0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMChatRoomMemberInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fd9a0@@YA_KPEAX_K@Z 0x1415fd9a0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fda30(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMFileEvent>*>(p), requested); }
// MS2-PIN: ?FUN_1415fda30@@YA_KPEAX_K@Z 0x1415fda30 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdac0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMFilePath>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdac0@@YA_KPEAX_K@Z 0x1415fdac0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdb50(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<Unk_StlElem<224>>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdb50@@YA_KPEAX_K@Z 0x1415fdb50 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdbe0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMFriendInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdbe0@@YA_KPEAX_K@Z 0x1415fdbe0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdc70(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMGameCode>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdc70@@YA_KPEAX_K@Z 0x1415fdc70 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdd00(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMGameInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdd00@@YA_KPEAX_K@Z 0x1415fdd00 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdd90(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMGameServerCode>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdd90@@YA_KPEAX_K@Z 0x1415fdd90 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fde20(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<Unk_StlElem<104>>*>(p), requested); }
// MS2-PIN: ?FUN_1415fde20@@YA_KPEAX_K@Z 0x1415fde20 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdeb0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMGuildMemberInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdeb0@@YA_KPEAX_K@Z 0x1415fdeb0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdf40(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMGuildMemberLevelInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdf40@@YA_KPEAX_K@Z 0x1415fdf40 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fdfd0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<Unk_StlElem<400>>*>(p), requested); }
// MS2-PIN: ?FUN_1415fdfd0@@YA_KPEAX_K@Z 0x1415fdfd0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe060(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMNoteInfo2>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe060@@YA_KPEAX_K@Z 0x1415fe060 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe0f0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<Unk_StlElem<3784>>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe0f0@@YA_KPEAX_K@Z 0x1415fe0f0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe180(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMRejectedUser>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe180@@YA_KPEAX_K@Z 0x1415fe180 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe210(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMSessionMemberInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe210@@YA_KPEAX_K@Z 0x1415fe210 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe2a0(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<CNMVirtualUserInfo>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe2a0@@YA_KPEAX_K@Z 0x1415fe2a0 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: applies the recovered 1.5x capacity growth rule using this vector instantiation's capacity and max_size.
unsigned long long FUN_1415fe330(void* p, unsigned long long requested) { return nm_vector_growth(*static_cast<std::vector<Unk_StlElem<5288>>*>(p), requested); }
// MS2-PIN: ?FUN_1415fe330@@YA_KPEAX_K@Z 0x1415fe330 ; MS2-FUNCTIONAL: reuses the recovered capacity growth decision for this instantiation

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 16.
void FUN_1415fe3c0(void* p, Unk_StlElem<16>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 16); }
// MS2-PIN: ?FUN_1415fe3c0@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@_K2@Z 0x1415fe3c0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415fe4d0(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415fe4d0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415fe4d0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 88.
void FUN_1415fe5e0(void* p, Unk_StlElem<88>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 88); }
// MS2-PIN: ?FUN_1415fe5e0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@_K2@Z 0x1415fe5e0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 48.
void FUN_1415fe6f0(void* p, Unk_StlElem<48>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 48); }
// MS2-PIN: ?FUN_1415fe6f0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@_K2@Z 0x1415fe6f0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 152.
void FUN_1415fe800(void* p, Unk_StlElem<152>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 152); }
// MS2-PIN: ?FUN_1415fe800@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@_K2@Z 0x1415fe800 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 544.
void FUN_1415fe910(void* p, Unk_StlElem<544>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 544); }
// MS2-PIN: ?FUN_1415fe910@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@_K2@Z 0x1415fe910 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 296.
void FUN_1415fea20(void* p, Unk_StlElem<296>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 296); }
// MS2-PIN: ?FUN_1415fea20@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@_K2@Z 0x1415fea20 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 280.
void FUN_1415feb30(void* p, Unk_StlElem<280>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 280); }
// MS2-PIN: ?FUN_1415feb30@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@_K2@Z 0x1415feb30 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 224.
void FUN_1415fec40(void* p, Unk_StlElem<224>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 224); }
// MS2-PIN: ?FUN_1415fec40@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@_K2@Z 0x1415fec40 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 1408.
void FUN_1415fed50(void* p, Unk_StlElem<1408>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 1408); }
// MS2-PIN: ?FUN_1415fed50@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@_K2@Z 0x1415fed50 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415fee60(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415fee60@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415fee60 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 5288.
void FUN_1415fef70(void* p, Unk_StlElem<5288>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 5288); }
// MS2-PIN: ?FUN_1415fef70@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@_K2@Z 0x1415fef70 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415ff080(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415ff080@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415ff080 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 400.
void FUN_1415ff190(void* p, Unk_StlElem<400>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 400); }
// MS2-PIN: ?FUN_1415ff190@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@_K2@Z 0x1415ff190 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 184.
void FUN_1415ff2a0(void* p, Unk_StlElem<184>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 184); }
// MS2-PIN: ?FUN_1415ff2a0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@_K2@Z 0x1415ff2a0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 88.
void FUN_1415ff3b0(void* p, Unk_StlElem<88>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 88); }
// MS2-PIN: ?FUN_1415ff3b0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@_K2@Z 0x1415ff3b0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 104.
void FUN_1415ff4c0(void* p, Unk_StlElem<104>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 104); }
// MS2-PIN: ?FUN_1415ff4c0@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@_K2@Z 0x1415ff4c0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 2792.
void FUN_1415ff5d0(void* p, Unk_StlElem<2792>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 2792); }
// MS2-PIN: ?FUN_1415ff5d0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@_K2@Z 0x1415ff5d0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 3784.
void FUN_1415ff6e0(void* p, Unk_StlElem<3784>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 3784); }
// MS2-PIN: ?FUN_1415ff6e0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@_K2@Z 0x1415ff6e0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 200.
void FUN_1415ff7f0(void* p, Unk_StlElem<200>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 200); }
// MS2-PIN: ?FUN_1415ff7f0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@_K2@Z 0x1415ff7f0 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 248.
void FUN_1415ff900(void* p, Unk_StlElem<248>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 248); }
// MS2-PIN: ?FUN_1415ff900@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@_K2@Z 0x1415ff900 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 1168.
void FUN_1415ffa10(void* p, Unk_StlElem<1168>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 1168); }
// MS2-PIN: ?FUN_1415ffa10@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@_K2@Z 0x1415ffa10 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 32.
void FUN_1415ffb20(void* p, Unk_StlElem<32>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 32); }
// MS2-PIN: ?FUN_1415ffb20@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@_K2@Z 0x1415ffb20 ; MS2-FUNCTIONAL: size-specialized helper performs the same storage field updates and old allocation release

// MS2-FUNCTIONAL: returns the vector allocator/storage address recovered by the wrapper.
void* FUN_141601cd0(void* p) { return p; }
// MS2-PIN: ?FUN_141601cd0@@YAPEAXPEAX@Z 0x141601cd0 ; MS2-FUNCTIONAL: returns the storage address, with a different leaf/non-leaf frame

// MS2-FUNCTIONAL: returns the vector allocator/storage address recovered by the wrapper.
void* FUN_141601ed0(void* p) { return p; }
// MS2-PIN: ?FUN_141601ed0@@YAPEAXPEAX@Z 0x141601ed0 ; MS2-FUNCTIONAL: returns the storage address, with a different leaf/non-leaf frame
