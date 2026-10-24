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

extern void* FUN_1423103b0(void* self, std::size_t firstSize, std::size_t blockSize,
                           std::size_t lastSize, void* attachment);
extern void* FUN_1423049e0(void* self, int initializeCpu);
extern void* FUN_1423106b0(void* self, void* hashModule, void* attachment,
                           std::uint32_t flags, int digestSize);
extern void* FUN_1423104c0(void* self, void* hashModule, void* attachment, bool passMessage,
                           int digestSize, const void* firstChannel, const void* secondChannel);
extern void* FUN_142311070(void* self, void* cipher, void* attachment,
                           int padding, bool authenticated);
extern char DAT_14311e038[];
extern char DAT_14311e200[];
extern char DAT_14311e220[];
extern char DAT_14311e3e8[];
extern char DAT_14311e638[];
extern char DAT_14311e7a0[];
extern char DAT_143b0dc48[];

struct CryptoPPOutputProxyCx13
{
    void* vtable0;
    void* vtable1;
    std::uint64_t refCount;
    void* owner;
    bool passSignal;
    char padding[7];
};

static CryptoPPOutputProxyCx13* NewCryptoPPOutputProxy(void* owner, std::uintptr_t vtable0,
                                                       std::uintptr_t vtable1)
{
    auto* proxy = static_cast<CryptoPPOutputProxyCx13*>(::operator new(sizeof(CryptoPPOutputProxyCx13)));
    FUN_1423049e0(proxy, 0);
    proxy->vtable0 = reinterpret_cast<void*>(vtable0);
    proxy->vtable1 = reinterpret_cast<void*>(vtable1);
    proxy->refCount = 0;
    proxy->owner = owner;
    proxy->passSignal = false;
    return proxy;
}

static std::size_t CryptoPPDigestSize(void* hashModule)
{
    auto** vtable = *reinterpret_cast<void***>(hashModule);
    using DigestSizeFn = unsigned int (*)(void*);
    auto digestSize = reinterpret_cast<DigestSizeFn>(vtable[7]);
    return digestSize(hashModule);
}

// MS2-FUNCTIONAL: exe helper constructors initialize both embedded filters and proxy objects; this C++ version matches successful construction, while exceptional unwind cleanup differs.
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
    FUN_1423103b0(self, firstSize, 1, lastSize, attachment);
    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e220;
    outerVtable[1] = DAT_14311e3e8;

    auto* hashOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                               reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    FUN_1423106b0(static_cast<std::uint8_t*>(self) + 0x90, hashModule, hashOutput,
                  flags, truncatedDigestSize);

    auto* streamOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                                 reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    FUN_142311070(static_cast<std::uint8_t*>(self) + 0x148, streamCipher,
                  streamOutput, paddingScheme, true);
    return self;
}

// MS2-FUNCTIONAL: exe helper constructors initialize the stream-filter base and hash-filter member; this C++ version matches successful construction, while exceptional unwind cleanup differs.
// @0x14230ff90
void* FUN_14230ff90(void* self, void* cipher, void* attachment, bool putAAD,
                    int truncatedDigestSize, const void* macChannel, int paddingScheme)
{
    auto* cipherBytes = static_cast<std::uint8_t*>(cipher);
    void* hashModule = cipherBytes + 8;
    void* streamCipher = cipherBytes + 0x10;
    FUN_142311070(self, streamCipher, attachment, paddingScheme, true);

    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e038;
    outerVtable[1] = DAT_14311e200;

    auto* hashOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                               reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    const void* aadChannel = DAT_143b0dc48;
    FUN_1423104c0(static_cast<std::uint8_t*>(self) + 0xb8, hashModule, hashOutput,
                  putAAD, truncatedDigestSize, aadChannel, macChannel);
    return self;
}
