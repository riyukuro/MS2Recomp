// Constructor recovery based on the executable's embedded-filter offsets and helper calls.
// MS2-UNIT: lib_cryptopp_filters_cx13
// MS2-RANGE: 0x14230fce0-0x1423100f4 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>
#include <new>
#include <string>

#include "cryptopp562/filters.h"   // the real Crypto++ 5.6.2 classes: OutputProxy's vftables are emitted here

extern char DAT_14311e038[];
extern char DAT_14311e200[];
extern char DAT_14311e220[];
extern char DAT_14311e3e8[];
// 0x143b0dc48 = CryptoPP::AAD_CHANNEL (cryptlib.h)

// the exe's `new OutputProxy(*this, false)`: 0x28 bytes, Algorithm(false), the two OutputProxy vptrs, owner, passSignal
static CryptoPP::OutputProxy* NewCryptoPPOutputProxy(void* owner)
{
    return new CryptoPP::OutputProxy(*static_cast<CryptoPP::BufferedTransformation*>(owner), false);
}

static std::size_t CryptoPPDigestSize(void* hashModule)
{
    auto** vtable = *reinterpret_cast<void***>(hashModule);
    using DigestSizeFn = unsigned int (*)(void*);
    auto digestSize = reinterpret_cast<DigestSizeFn>(vtable[7]);
    return digestSize(hashModule);
}

// MS2-FUNCTIONAL: AuthenticatedDecryptionFilter ctor; the exe inlines the filters.cpp ctors (FilterWithBufferedInput, HashVerificationFilter, Filter, OutputProxy) with their EH states, cross-TU (LTCG); this TU calls the real out-of-line ctors.
// @0x14230fce0
void* FUN_14230fce0(void* self, void* cipher, void* attachment, std::uint32_t flags,
                    int truncatedDigestSize, int paddingScheme)
{
    auto* cipherBytes = static_cast<std::uint8_t*>(cipher);
    void* hashModule = cipherBytes + 8;
    void* streamCipher = cipherBytes + 0x10;
    const std::size_t digestSize = truncatedDigestSize < 0
                                       ? CryptoPPDigestSize(hashModule)
                                       : static_cast<std::size_t>(truncatedDigestSize);
    const std::size_t firstSize = (flags & 1) ? digestSize : 0;
    const std::size_t lastSize = (flags & 1) ? 0 : digestSize;

    // FilterWithBufferedInput base: first, per-block, and trailing byte counts, then attachment.
    // (FilterWithBufferedInput is abstract: its constructor is called explicitly on the raw storage)
    CryptoPP::FilterWithBufferedInput* base = static_cast<CryptoPP::FilterWithBufferedInput*>(self);
    base->CryptoPP::FilterWithBufferedInput::FilterWithBufferedInput(firstSize, 1, lastSize, static_cast<CryptoPP::BufferedTransformation*>(attachment));
    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e220;
    outerVtable[1] = DAT_14311e3e8;

    auto* hashOutput = NewCryptoPPOutputProxy(self);
    new (static_cast<std::uint8_t*>(self) + 0x90) CryptoPP::HashVerificationFilter(*static_cast<CryptoPP::HashTransformation*>(hashModule),
                  hashOutput, flags, truncatedDigestSize);

    auto* streamOutput = NewCryptoPPOutputProxy(self);
    new (static_cast<std::uint8_t*>(self) + 0x148) CryptoPP::StreamTransformationFilter(*static_cast<CryptoPP::StreamTransformation*>(streamCipher),
                  streamOutput, static_cast<CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme>(paddingScheme), true);
    return self;
}

// MS2-FUNCTIONAL: AuthenticatedEncryptionFilter ctor; the exe inlines HashFilter::HashFilter, Filter and OutputProxy from filters.cpp with their EH states, cross-TU (LTCG); this TU calls the real out-of-line ctors.
// @0x14230ff90
void* FUN_14230ff90(void* self, void* cipher, void* attachment, bool putAAD,
                    int truncatedDigestSize, const void* macChannel, int paddingScheme)
{
    auto* cipherBytes = static_cast<std::uint8_t*>(cipher);
    void* hashModule = cipherBytes + 8;
    void* streamCipher = cipherBytes + 0x10;
    new (self) CryptoPP::StreamTransformationFilter(*static_cast<CryptoPP::StreamTransformation*>(streamCipher),
                  static_cast<CryptoPP::BufferedTransformation*>(attachment), static_cast<CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme>(paddingScheme), true);

    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e038;
    outerVtable[1] = DAT_14311e200;

    auto* hashOutput = NewCryptoPPOutputProxy(self);
    const void* aadChannel = &CryptoPP::AAD_CHANNEL;
    new (static_cast<std::uint8_t*>(self) + 0xb8) CryptoPP::HashFilter(*static_cast<CryptoPP::HashTransformation*>(hashModule),
                  hashOutput, putAAD, truncatedDigestSize,
                  *static_cast<const std::string*>(aadChannel), *static_cast<const std::string*>(macChannel));
    return self;
}
// MS2-PIN: ??_7OutputProxy@CryptoPP@@6BAlgorithm@1@@ 0x14311e638
// MS2-PIN: ??_7OutputProxy@CryptoPP@@6BWaitable@1@@ 0x14311e7a0
