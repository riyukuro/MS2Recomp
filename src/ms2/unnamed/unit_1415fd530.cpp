// Recovered Nexon Messenger vector growth/reallocation helpers from unit_1415fd530.
// MS2-UNIT: unit_1415fd530
// MS2-RANGE: 0x1415fd530-0x141601f30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstddef>
#include <cstdint>
#include <new>

static unsigned long long nm_vector_growth(void* p, unsigned long long requested, size_t elementSize)
{
    auto** fields = static_cast<unsigned char**>(p);
    auto* first = fields[0];
    auto* last = fields[1];
    const unsigned long long current = first && last ? static_cast<unsigned long long>(last - first) / elementSize : 0;
    const unsigned long long limit = static_cast<unsigned long long>(-1) / elementSize;
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

// MS2-FUNCTIONAL: reproduces the vector 1.5x growth policy for 224-byte elements.
unsigned long long FUN_1415fdb50(void* p, unsigned long long requested) { return nm_vector_growth(p, requested, 224); }
// MS2-PIN: ?FUN_1415fdb50@@YA_KPEAX_K@Z 0x1415fdb50

// MS2-FUNCTIONAL: reproduces the vector 1.5x growth policy for 104-byte elements.
unsigned long long FUN_1415fde20(void* p, unsigned long long requested) { return nm_vector_growth(p, requested, 104); }
// MS2-PIN: ?FUN_1415fde20@@YA_KPEAX_K@Z 0x1415fde20

// MS2-FUNCTIONAL: reproduces the vector 1.5x growth policy for 400-byte elements.
unsigned long long FUN_1415fdfd0(void* p, unsigned long long requested) { return nm_vector_growth(p, requested, 400); }
// MS2-PIN: ?FUN_1415fdfd0@@YA_KPEAX_K@Z 0x1415fdfd0

// MS2-FUNCTIONAL: reproduces the vector 1.5x growth policy for 3784-byte elements.
unsigned long long FUN_1415fe0f0(void* p, unsigned long long requested) { return nm_vector_growth(p, requested, 3784); }
// MS2-PIN: ?FUN_1415fe0f0@@YA_KPEAX_K@Z 0x1415fe0f0

// MS2-FUNCTIONAL: reproduces the vector 1.5x growth policy for 5288-byte elements.
unsigned long long FUN_1415fe330(void* p, unsigned long long requested) { return nm_vector_growth(p, requested, 5288); }
// MS2-PIN: ?FUN_1415fe330@@YA_KPEAX_K@Z 0x1415fe330

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 16.
void FUN_1415fe3c0(void* p, Unk_StlElem<16>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 16); }
// MS2-PIN: ?FUN_1415fe3c0@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@_K2@Z 0x1415fe3c0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415fe4d0(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415fe4d0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415fe4d0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 88.
void FUN_1415fe5e0(void* p, Unk_StlElem<88>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 88); }
// MS2-PIN: ?FUN_1415fe5e0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@_K2@Z 0x1415fe5e0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 48.
void FUN_1415fe6f0(void* p, Unk_StlElem<48>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 48); }
// MS2-PIN: ?FUN_1415fe6f0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@_K2@Z 0x1415fe6f0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 152.
void FUN_1415fe800(void* p, Unk_StlElem<152>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 152); }
// MS2-PIN: ?FUN_1415fe800@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@_K2@Z 0x1415fe800

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 544.
void FUN_1415fe910(void* p, Unk_StlElem<544>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 544); }
// MS2-PIN: ?FUN_1415fe910@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@_K2@Z 0x1415fe910

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 296.
void FUN_1415fea20(void* p, Unk_StlElem<296>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 296); }
// MS2-PIN: ?FUN_1415fea20@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@_K2@Z 0x1415fea20

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 280.
void FUN_1415feb30(void* p, Unk_StlElem<280>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 280); }
// MS2-PIN: ?FUN_1415feb30@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@_K2@Z 0x1415feb30

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 224.
void FUN_1415fec40(void* p, Unk_StlElem<224>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 224); }
// MS2-PIN: ?FUN_1415fec40@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@_K2@Z 0x1415fec40

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 1408.
void FUN_1415fed50(void* p, Unk_StlElem<1408>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 1408); }
// MS2-PIN: ?FUN_1415fed50@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@_K2@Z 0x1415fed50

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415fee60(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415fee60@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415fee60

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 5288.
void FUN_1415fef70(void* p, Unk_StlElem<5288>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 5288); }
// MS2-PIN: ?FUN_1415fef70@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@_K2@Z 0x1415fef70

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 24.
void FUN_1415ff080(void* p, Unk_StlElem<24>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 24); }
// MS2-PIN: ?FUN_1415ff080@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@_K2@Z 0x1415ff080

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 400.
void FUN_1415ff190(void* p, Unk_StlElem<400>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 400); }
// MS2-PIN: ?FUN_1415ff190@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@_K2@Z 0x1415ff190

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 184.
void FUN_1415ff2a0(void* p, Unk_StlElem<184>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 184); }
// MS2-PIN: ?FUN_1415ff2a0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@_K2@Z 0x1415ff2a0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 88.
void FUN_1415ff3b0(void* p, Unk_StlElem<88>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 88); }
// MS2-PIN: ?FUN_1415ff3b0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@_K2@Z 0x1415ff3b0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 104.
void FUN_1415ff4c0(void* p, Unk_StlElem<104>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 104); }
// MS2-PIN: ?FUN_1415ff4c0@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@_K2@Z 0x1415ff4c0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 2792.
void FUN_1415ff5d0(void* p, Unk_StlElem<2792>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 2792); }
// MS2-PIN: ?FUN_1415ff5d0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@_K2@Z 0x1415ff5d0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 3784.
void FUN_1415ff6e0(void* p, Unk_StlElem<3784>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 3784); }
// MS2-PIN: ?FUN_1415ff6e0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@_K2@Z 0x1415ff6e0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 200.
void FUN_1415ff7f0(void* p, Unk_StlElem<200>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 200); }
// MS2-PIN: ?FUN_1415ff7f0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@_K2@Z 0x1415ff7f0

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 248.
void FUN_1415ff900(void* p, Unk_StlElem<248>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 248); }
// MS2-PIN: ?FUN_1415ff900@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@_K2@Z 0x1415ff900

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 1168.
void FUN_1415ffa10(void* p, Unk_StlElem<1168>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 1168); }
// MS2-PIN: ?FUN_1415ffa10@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@_K2@Z 0x1415ffa10

// MS2-FUNCTIONAL: replaces vector storage using the recovered element size 32.
void FUN_1415ffb20(void* p, Unk_StlElem<32>* memory, unsigned long long size, unsigned long long capacity) { nm_vector_change_array(p, memory, size, capacity, 32); }
// MS2-PIN: ?FUN_1415ffb20@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@_K2@Z 0x1415ffb20

// MS2-FUNCTIONAL: returns the vector allocator/storage address recovered by the wrapper.
void* FUN_141601cd0(void* p) { return p; }
// MS2-PIN: ?FUN_141601cd0@@YAPEAXPEAX@Z 0x141601cd0

// MS2-FUNCTIONAL: returns the vector allocator/storage address recovered by the wrapper.
void* FUN_141601ed0(void* p) { return p; }
// MS2-PIN: ?FUN_141601ed0@@YAPEAXPEAX@Z 0x141601ed0
