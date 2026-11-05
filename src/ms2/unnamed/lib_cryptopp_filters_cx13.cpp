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

namespace CryptoPP   // C3: views of the CryptoPP constructors these helpers call
{
class BufferedTransformation;
class HashTransformation;
class StreamTransformation;
struct BlockPaddingSchemeDef { enum BlockPaddingScheme { NO_PADDING, ZEROS_PADDING, PKCS_PADDING, ONE_AND_ZEROS_PADDING, DEFAULT_PADDING }; };
class Algorithm { public: Algorithm(bool checkSelfTestStatus); };
class FilterWithBufferedInput { public: FilterWithBufferedInput(std::size_t firstSize, std::size_t blockSize, std::size_t lastSize, BufferedTransformation* attachment); };
class HashVerificationFilter { public: HashVerificationFilter(HashTransformation& hm, BufferedTransformation* attachment, unsigned int flags, int truncatedDigestSize); };
class HashFilter { public: HashFilter(HashTransformation& hm, BufferedTransformation* attachment, bool putMessage, int truncatedDigestSize, const std::string& messagePutChannel, const std::string& hashPutChannel); };
class StreamTransformationFilter { public: StreamTransformationFilter(StreamTransformation& c, BufferedTransformation* attachment, BlockPaddingSchemeDef::BlockPaddingScheme padding, bool allowAuthenticatedSymmetricCipher); };
}
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
    if (proxy == nullptr)    // the exe's new-expression: a failed allocation passes null on unconstructed
        return nullptr;
    new (proxy) CryptoPP::Algorithm(false);
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
    new (self) CryptoPP::FilterWithBufferedInput(firstSize, 1, lastSize, static_cast<CryptoPP::BufferedTransformation*>(attachment));
    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e220;
    outerVtable[1] = DAT_14311e3e8;

    auto* hashOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                               reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    new (static_cast<std::uint8_t*>(self) + 0x90) CryptoPP::HashVerificationFilter(*static_cast<CryptoPP::HashTransformation*>(hashModule),
                  reinterpret_cast<CryptoPP::BufferedTransformation*>(hashOutput), flags, truncatedDigestSize);

    auto* streamOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                                 reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    new (static_cast<std::uint8_t*>(self) + 0x148) CryptoPP::StreamTransformationFilter(*static_cast<CryptoPP::StreamTransformation*>(streamCipher),
                  reinterpret_cast<CryptoPP::BufferedTransformation*>(streamOutput), static_cast<CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme>(paddingScheme), true);
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
    new (self) CryptoPP::StreamTransformationFilter(*static_cast<CryptoPP::StreamTransformation*>(streamCipher),
                  static_cast<CryptoPP::BufferedTransformation*>(attachment), static_cast<CryptoPP::BlockPaddingSchemeDef::BlockPaddingScheme>(paddingScheme), true);

    auto** outerVtable = reinterpret_cast<void**>(self);
    outerVtable[0] = DAT_14311e038;
    outerVtable[1] = DAT_14311e200;

    auto* hashOutput = NewCryptoPPOutputProxy(self, reinterpret_cast<std::uintptr_t>(DAT_14311e638),
                                               reinterpret_cast<std::uintptr_t>(DAT_14311e7a0));
    const void* aadChannel = DAT_143b0dc48;
    new (static_cast<std::uint8_t*>(self) + 0xb8) CryptoPP::HashFilter(*static_cast<CryptoPP::HashTransformation*>(hashModule),
                  reinterpret_cast<CryptoPP::BufferedTransformation*>(hashOutput), putAAD, truncatedDigestSize,
                  *static_cast<const std::string*>(aadChannel), *static_cast<const std::string*>(macChannel));
    return self;
}
