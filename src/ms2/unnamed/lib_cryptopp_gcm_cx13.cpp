// Executable-derived Crypto++ GCM recovery.
// MS2-UNIT: lib_cryptopp_gcm_cx13
// MS2-RANGE: 0x142353880-0x1423542a0 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>

namespace
{
struct RijndaelLocalsCx13
{
    std::uint32_t cachedKeys[48];
    std::uint32_t workspace[8];
    const std::uint8_t* input;
    const std::uint8_t* inputXor;
    const std::uint8_t* outputXor;
    std::uint8_t* output;
    std::size_t inputIncrement;
    std::size_t inputXorIncrement;
    std::size_t outputXorIncrement;
    std::size_t outputIncrement;
    std::size_t registerSpill;
    std::size_t lengthAndCounterFlag;
    std::size_t keysBegin;
};

static_assert(offsetof(RijndaelLocalsCx13, input) == 0xe0, "Rijndael helper input offset");
static_assert(offsetof(RijndaelLocalsCx13, lengthAndCounterFlag) == 0x128, "Rijndael helper length offset");
static_assert(offsetof(RijndaelLocalsCx13, keysBegin) == 0x130, "Rijndael helper key offset");

std::uint8_t AesXtime(std::uint8_t x)
{
    return static_cast<std::uint8_t>((x << 1) ^ ((x & 0x80) ? 0x1b : 0));
}

std::uint8_t AesMultiply(std::uint8_t a, std::uint8_t b)
{
    std::uint8_t product = 0;
    for (unsigned i = 0; i != 8; ++i)
    {
        product ^= static_cast<std::uint8_t>(a & static_cast<std::uint8_t>(0u - (b & 1u)));
        a = AesXtime(a);
        b >>= 1;
    }
    return product;
}

std::uint8_t AesSubByte(std::uint8_t x)
{
    std::uint8_t inverse = 1;
    std::uint8_t base = x;
    unsigned exponent = 254;
    while (exponent)
    {
        if (exponent & 1)
            inverse = AesMultiply(inverse, base);
        base = AesMultiply(base, base);
        exponent >>= 1;
    }
    if (x == 0)
        inverse = 0;
    const std::uint8_t rotated1 = static_cast<std::uint8_t>((inverse << 1) | (inverse >> 7));
    const std::uint8_t rotated2 = static_cast<std::uint8_t>((inverse << 2) | (inverse >> 6));
    const std::uint8_t rotated3 = static_cast<std::uint8_t>((inverse << 3) | (inverse >> 5));
    const std::uint8_t rotated4 = static_cast<std::uint8_t>((inverse << 4) | (inverse >> 4));
    return static_cast<std::uint8_t>(inverse ^ rotated1 ^ rotated2 ^ rotated3 ^ rotated4 ^ 0x63);
}

void AesEncryptBlockCx13(const std::uint8_t input[16], const std::uint32_t* key,
                         unsigned rounds, std::uint8_t output[16])
{
    const auto* keyBytes = reinterpret_cast<const std::uint8_t*>(key);
    const auto roundKeyByte = [keyBytes, rounds](unsigned round, unsigned byteIndex) {
        if (round != 0 && round != rounds)
            byteIndex = (byteIndex & ~3u) | (3u - (byteIndex & 3u));
        return keyBytes[round * 16 + byteIndex];
    };
    std::uint8_t state[16];
    for (unsigned i = 0; i != 16; ++i)
        state[i] = static_cast<std::uint8_t>(input[i] ^ roundKeyByte(0, i));

    for (unsigned round = 1; round <= rounds; ++round)
    {
        for (unsigned i = 0; i != 16; ++i)
            state[i] = AesSubByte(state[i]);

        std::uint8_t shifted[16];
        for (unsigned row = 0; row != 4; ++row)
            for (unsigned col = 0; col != 4; ++col)
                shifted[row + 4 * col] = state[row + 4 * ((col + row) & 3)];
        for (unsigned i = 0; i != 16; ++i)
            state[i] = static_cast<std::uint8_t>(shifted[i] ^ roundKeyByte(round, i));

        if (round != rounds)
        {
            for (unsigned col = 0; col != 4; ++col)
            {
                const unsigned i = col * 4;
                const std::uint8_t a = state[i], b = state[i + 1], c = state[i + 2], d = state[i + 3];
                state[i] = static_cast<std::uint8_t>(AesMultiply(a, 2) ^ AesMultiply(b, 3) ^ c ^ d);
                state[i + 1] = static_cast<std::uint8_t>(a ^ AesMultiply(b, 2) ^ AesMultiply(c, 3) ^ d);
                state[i + 2] = static_cast<std::uint8_t>(a ^ b ^ AesMultiply(c, 2) ^ AesMultiply(d, 3));
                state[i + 3] = static_cast<std::uint8_t>(AesMultiply(a, 3) ^ b ^ c ^ AesMultiply(d, 2));
            }
        }
    }
    for (unsigned i = 0; i != 16; ++i)
        output[i] = state[i];
}

void RijndaelAdvancedBlocksCx13(RijndaelLocalsCx13* locals, const std::uint32_t* key)
{
    const bool counterMode = (locals->lengthAndCounterFlag & 1) != 0;
    const std::size_t bytes = locals->lengthAndCounterFlag + (counterMode ? 1 : 0);
    const std::size_t blocks = bytes / 16;
    const unsigned rounds = static_cast<unsigned>(14 - locals->keysBegin / 16 + (counterMode ? 1 : 0));
    const auto* input = locals->input;
    const auto* inputXor = locals->inputXor;
    const auto* outputXor = locals->outputXor;
    auto* output = locals->output;

    for (std::size_t block = 0; block != blocks; ++block)
    {
        std::uint8_t plain[16], encrypted[16], result[16];
        for (unsigned i = 0; i != 16; ++i)
            plain[i] = static_cast<std::uint8_t>(input[i] ^ inputXor[i]);
        AesEncryptBlockCx13(plain, key, rounds, encrypted);
        for (unsigned i = 0; i != 16; ++i)
            result[i] = static_cast<std::uint8_t>(encrypted[i] ^ outputXor[i]);
        for (unsigned i = 0; i != 16; ++i)
            output[i] = result[i];

        input = reinterpret_cast<const std::uint8_t*>(reinterpret_cast<std::uintptr_t>(input) + locals->inputIncrement);
        inputXor = reinterpret_cast<const std::uint8_t*>(reinterpret_cast<std::uintptr_t>(inputXor) + locals->inputXorIncrement);
        outputXor = reinterpret_cast<const std::uint8_t*>(reinterpret_cast<std::uintptr_t>(outputXor) + locals->outputXorIncrement);
        output = reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uintptr_t>(output) + locals->outputIncrement);
    }
}

// The recovery tables store H multiplied by each input bit. This extracts H
// from the row generated for the most significant bit of the first byte.
void GcmMultiply(const std::uint8_t x[16], const std::uint8_t h[16], std::uint8_t out[16])
{
    std::uint8_t v[16];
    for (unsigned i = 0; i != 16; ++i)
    {
        out[i] = 0;
        v[i] = h[i];
    }

    // GHASH numbers the most significant bit of the first byte as bit zero;
    // reduction is by x^128 + x^7 + x^2 + x + 1.
    for (unsigned bit = 0; bit != 128; ++bit)
    {
        const std::uint8_t mask = static_cast<std::uint8_t>(0u - ((x[bit >> 3] >> (7 - (bit & 7))) & 1u));
        for (unsigned j = 0; j != 16; ++j)
            out[j] ^= static_cast<std::uint8_t>(v[j] & mask);

        const std::uint8_t lsb = static_cast<std::uint8_t>(v[15] & 1u);
        for (int j = 15; j > 0; --j)
            v[j] = static_cast<std::uint8_t>((v[j] >> 1) | (v[j - 1] << 7));
        v[0] >>= 1;
        v[0] ^= static_cast<std::uint8_t>(0xe1u & static_cast<std::uint8_t>(0u - lsb));
    }
}

void GcmAuthenticate(const std::uint8_t* data, std::size_t blocks,
                     std::uint8_t* state, const std::uint8_t* h)
{
    for (std::size_t block = 0; block != blocks; ++block)
    {
        std::uint8_t x[16], next[16];
        for (unsigned i = 0; i != 16; ++i)
            x[i] = static_cast<std::uint8_t>(state[i] ^ data[block * 16 + i]);
        GcmMultiply(x, h, next);
        for (unsigned i = 0; i != 16; ++i)
            state[i] = next[i];
    }
}
}

// MASM AES T-table multi-block helper, replaced with a scalar AES implementation
// using the same locals layout, round keys, XOR inputs, and pointer increments.
// MS2-FUNCTIONAL: preserves AES block transforms and AdvancedProcessBlocks pointer/flag behavior; uses scalar AES rounds instead of the cache-preloaded T-table assembly.
// @0x142353880
void FUN_142353880(void* locals, const std::uint32_t* key)
{
    RijndaelAdvancedBlocksCx13(static_cast<RijndaelLocalsCx13*>(locals), key);
}

// MASM/SSE2 2 KiB nibble-table GHASH equivalent. The table starts 0x20 bytes
// after the accumulator and its first H row is at table+0x480.
// MS2-FUNCTIONAL: same block accumulator and GHASH result; uses scalar GF(2^128) multiplication instead of SSE2 table XORs.
// @0x142353ed8
void FUN_142353ed8(const std::uint8_t* data, std::size_t blocks,
                   std::uint64_t* hashBuffer, const std::uint16_t* reductionTable)
{
    (void)reductionTable;
    auto* state = reinterpret_cast<std::uint8_t*>(hashBuffer);
    const std::uint8_t* const table = state + 0x20;
    GcmAuthenticate(data, blocks, state, table + 0x480);
}

// MASM/SSE2 64 KiB byte-table GHASH equivalent. The H row is the first
// generated row, corresponding to input bit 0 at table offset 0x800.
// MS2-FUNCTIONAL: same block accumulator and GHASH result; uses scalar GF(2^128) multiplication instead of 16 parallel byte lookups.
// @0x142354158
void FUN_142354158(const std::uint8_t* data, std::size_t blocks, std::uint64_t* hashBuffer)
{
    auto* state = reinterpret_cast<std::uint8_t*>(hashBuffer);
    const std::uint8_t* const table = state + 0x20;
    GcmAuthenticate(data, blocks, state, table + 0x800);
}
