// Executable-derived recovery for previously unpaired Crypto++ routines.
// MS2-UNIT: lib_crypto_recovery_cx13
// MS2-RANGE: 0x1423537e0-0x14235382b .text$mn
// MS2-RANGE: 0x142353830-0x14235387b .text$mn
// MS2-RANGE: 0x1423542a0-0x142355145 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>
#include <intrin.h>

// Multi-precision word addition used by Crypto++'s Integer implementation.
// The executable walks from the least-significant end and propagates carry.
// MS2-FUNCTIONAL: same limb addition and final carry; the source uses carry intrinsics instead of the exe's carry-flag loop.
// @0x1423537e0
std::uint64_t FUN_1423537e0(std::uint64_t* result, std::size_t count,
                            const std::uint64_t* left, const std::uint64_t* right)
{
    unsigned char carry = 0;
    for (std::size_t i = 0; i < count; ++i)
    {
        carry = _addcarry_u64(carry, left[i], right[i], &result[i]);
    }
    return static_cast<std::uint64_t>(carry);
}

// Multi-precision word subtraction; the return value is the final borrow bit.
// MS2-FUNCTIONAL: same limb subtraction and final borrow; the source uses borrow intrinsics instead of the exe's carry-flag loop.
// @0x142353830
std::uint64_t FUN_142353830(std::uint64_t* result, std::size_t count,
                            const std::uint64_t* left, const std::uint64_t* right)
{
    unsigned char borrow = 0;
    for (std::size_t i = 0; i < count; ++i)
    {
        const std::uint64_t a = left[i];
        const std::uint64_t b = right[i];
        borrow = _subborrow_u64(borrow, a, b, &result[i]);
    }
    return borrow;
}

static std::uint32_t Sha256RotateRight(std::uint32_t x, unsigned n)
{
    return (x >> n) | (x << (32 - n));
}

// Crypto++ SHA-256 block transform: each input byte block is decoded as sixteen
// big-endian words, expanded to 64 schedule words, then added to the 8-word state.
// MS2-FUNCTIONAL: same 64-round compression transform; the exe unrolls and schedules the rounds differently.
// @0x1423542a0
void FUN_1423542a0(std::uint32_t state[8], const std::uint8_t* input, std::size_t byteCount)
{
    static const std::uint32_t roundConstant[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    const std::uint8_t* const end = input + byteCount;
    while (input != end)
    {
        std::uint32_t schedule[64];
        for (unsigned i = 0; i < 16; ++i)
        {
            schedule[i] = (static_cast<std::uint32_t>(input[i * 4]) << 24) |
                          (static_cast<std::uint32_t>(input[i * 4 + 1]) << 16) |
                          (static_cast<std::uint32_t>(input[i * 4 + 2]) << 8) |
                          static_cast<std::uint32_t>(input[i * 4 + 3]);
        }
        for (unsigned i = 16; i < 64; ++i)
        {
            const std::uint32_t s0 = Sha256RotateRight(schedule[i - 15], 7) ^
                                     Sha256RotateRight(schedule[i - 15], 18) ^ (schedule[i - 15] >> 3);
            const std::uint32_t s1 = Sha256RotateRight(schedule[i - 2], 17) ^
                                     Sha256RotateRight(schedule[i - 2], 19) ^ (schedule[i - 2] >> 10);
            schedule[i] = schedule[i - 16] + s0 + schedule[i - 7] + s1;
        }

        std::uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
        std::uint32_t e = state[4], f = state[5], g = state[6], h = state[7];
        for (unsigned i = 0; i < 64; ++i)
        {
            const std::uint32_t sum1 = Sha256RotateRight(e, 6) ^ Sha256RotateRight(e, 11) ^ Sha256RotateRight(e, 25);
            const std::uint32_t choose = (e & f) ^ (~e & g);
            const std::uint32_t t1 = h + sum1 + choose + roundConstant[i] + schedule[i];
            const std::uint32_t sum0 = Sha256RotateRight(a, 2) ^ Sha256RotateRight(a, 13) ^ Sha256RotateRight(a, 22);
            const std::uint32_t majority = (a & b) ^ (a & c) ^ (b & c);
            const std::uint32_t t2 = sum0 + majority;
            h = g; g = f; f = e; e = d + t1;
            d = c; c = b; b = a; a = t1 + t2;
        }
        state[0] += a; state[1] += b; state[2] += c; state[3] += d;
        state[4] += e; state[5] += f; state[6] += g; state[7] += h;
        input += 64;
    }
}
