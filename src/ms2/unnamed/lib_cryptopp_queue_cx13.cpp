// Executable-derived copy constructor for Crypto++'s queue storage object.
// MS2-UNIT: lib_cryptopp_queue_cx13
// MS2-RANGE: 0x142351e00-0x142351e6e .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace CryptoPP { void* UnalignedAllocate(std::size_t size); }

// MS2-FUNCTIONAL: reproduces the source object's six-word state and deep-copies its optional byte buffer with memcpy_s, as the exe
// does; the exe has a 0x30 frame with an EH state slot but no handler (an inlined SecBlock copy ctor).
// @0x142351e00
std::uint64_t* FUN_142351e00(std::uint64_t* destination, const std::uint64_t* source)
{
    destination[0] = source[0];
    const std::size_t size = static_cast<std::size_t>(source[2]);
    destination[2] = size;
    auto* bytes = size ? static_cast<std::uint8_t*>(CryptoPP::UnalignedAllocate(size)) : nullptr;
    destination[3] = reinterpret_cast<std::uintptr_t>(bytes);
    memcpy_s(bytes, static_cast<std::size_t>(destination[2]), reinterpret_cast<const void*>(source[3]),
             static_cast<std::size_t>(destination[2]));
    destination[4] = source[4];
    destination[5] = source[5];
    return destination;
}
