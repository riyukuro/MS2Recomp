// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The .text$yd atexit thunks of Crypto++ 5.6.2 function-local
// statics (Singleton<T>::Ref's simple_ptr<T> s_pObject, the DL_*/EC parameter tables) that gbprogress's di/yd block
// pass does not pair: their initializers run lazily inside the engine-stage gb:CryptoPP/* TUs, so no .text$di function
// registers them. Each thunk is written out by hand over the static it destroys; the statics are exe data (DAT_<va>).
// MS2-UNIT: lib_cryptopp_tail
// MS2-RANGE: 0x142cc8c20-0x142cc8cb0 .text$yd
// MS2-RANGE: 0x142cc8ce0-0x142cc92ab .text$yd
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <windows.h>
#include <wincrypt.h>
#include <intrin.h>
#include <vector>
#include <memory>
#include "cryptopp562/asn.h"

// the MSVC std::string layout (SSO buffer / heap pointer, size, capacity)
struct CppStdString
{
    union { char buf[16]; char* ptr; };
    size_t size;
    size_t res;
};
namespace CryptoPP { extern const std::string DEFAULT_CHANNEL; }   // 0x143a29388 (cryptlib.cpp)
// @0x142cc8c20
// the atexit thunk of CryptoPP::DEFAULT_CHANNEL: ~std::string (frees a heap buffer, resets to the empty SSO string)
void FUN_142cc8c20()
{
    typedef std::string Str;
    const_cast<Str&>(CryptoPP::DEFAULT_CHANNEL).~Str();
    _ReadWriteBarrier();   // keeps the reset stores: cl drops stores to a known-const global
    //
    //
    //
}

// operator delete / aligned free / __ehvec_dtor as the exe's CRT and Crypto++ expose them
namespace CryptoPP { void UnalignedDeallocate(void* p); }
// the CRT'"'"'s array-destructor helper, which this link does not provide: destroys the elements in reverse order
extern "C" __declspec(noinline) void __ehvec_dtor(void* p, size_t size, int count, void (*pDtor)(void*))
{
    char* e = (char*)p + size * count;
    while (count-- > 0)
    {
        e -= size;
        pDtor(e);
    }
}
// the tables' element dtors: ~OID (0x1423291a0, ICF-folded with ~EcRecommendedParameters<ECP>) and
// ~EcRecommendedParameters<EC2N> (0x142329200); both destroy the OID (std::vector<word32>) at offset 0
void FUN_1423291a0(void* p);
void FUN_142329200(void* p);
#ifndef MS2_HOOK_DLL
// Full exe: no eccrypto there (see the tables below), so the two dtors are defined here over the real CryptoPP::OID
void FUN_1423291a0(void* p) { static_cast<CryptoPP::OID*>(p)->~OID(); }
void FUN_142329200(void* p) { static_cast<CryptoPP::OID*>(p)->~OID(); }
#endif

// CryptoPP::simple_ptr<T>
// (no destructor here: the thunks below are its body, and the full exe's zeroed definitions must not register one)
template <class T> struct CppSimplePtr
{
    T* m_p;
    void Free()
    {
        delete m_p;
        m_p = 0;
    }
};

// a trivially destructible 8-byte object
struct Cpp8 { void* m_p; };
// an object with a virtual destructor
struct CppVirt { virtual ~CppVirt(); };
// CryptoPP::SecBlock<word, AllocatorWithCleanup<word>>: m_alloc (empty, padded), m_size, m_ptr
struct CppSecBlock
{
    char m_alloc;
    size_t m_size;
    unsigned long long* m_ptr;
    ~CppSecBlock() { Deallocate(m_ptr, m_size); }
    // AllocatorWithCleanup::deallocate: SecureWipeArray (__stosq for word64), then UnalignedDeallocate
    static void Deallocate(unsigned long long* p, size_t n)
    {
        __stosq(p, 0, n);
        CryptoPP::UnalignedDeallocate(p);
    }
};
struct CppOneBlock { CppSecBlock a; };
struct CppTwoBlocks { void* vptr; CppSecBlock a; CppSecBlock b; };
struct CppFourWords { void* v0; void* v1; CppSecBlock a; void* v5; void* v6; CppSecBlock b; void* v9; };

typedef std::vector<unsigned short> CppU16Vec;
// CryptoPP::MicrosoftCryptoProvider: the process-wide CryptoAPI context (Singleton<MicrosoftCryptoProvider>)
struct CppCryptoProvider
{
    HCRYPTPROV m_hProvider;
    ~CppCryptoProvider() { CryptReleaseContext(m_hProvider, 0); }
};
// The Singleton<T>::Ref() s_pObject statics (simple_ptr<T>) these thunks free, as exe data. Full exe: gb:CryptoPP
// builds no eccrypto/gfpcrypt/integer/gf2n/ec2n/ecp/nbtheory/osrng, so no Ref() of these exists there, nothing
// registers these thunks and the statics are defined here, zeroed. The hook DLL binds the exe's own.
extern CppSimplePtr<Cpp8> DAT_143b10178;
extern CppSimplePtr<Cpp8> DAT_143b10168;
extern CppSimplePtr<Cpp8> DAT_143b10158;
extern CppSimplePtr<Cpp8> DAT_143b10138;
extern CppSimplePtr<Cpp8> DAT_143b10338;
extern CppSimplePtr<Cpp8> DAT_143b10308;
extern CppSimplePtr<Cpp8> DAT_143b10318;
extern CppSimplePtr<CppVirt> DAT_143b10148;
extern CppSimplePtr<CppVirt> DAT_143b102e8;
extern CppSimplePtr<CppVirt> DAT_143b102f8;
extern CppSimplePtr<CppVirt> DAT_143b102d8;
extern CppSimplePtr<CppVirt> DAT_143b10328;
extern CppSimplePtr<CppVirt> DAT_143b10398;
extern CppSimplePtr<CppOneBlock> DAT_143b10348;
extern CppSimplePtr<CppOneBlock> DAT_143b10358;
extern CppSimplePtr<CppTwoBlocks> DAT_143b10368;
extern CppSimplePtr<CppFourWords> DAT_143b10378;
extern CppSimplePtr<CppU16Vec> DAT_143b10388;
extern CppSimplePtr<CppCryptoProvider> DAT_143b103a8;
#ifndef MS2_HOOK_DLL
CppSimplePtr<Cpp8> DAT_143b10178;
CppSimplePtr<Cpp8> DAT_143b10168;
CppSimplePtr<Cpp8> DAT_143b10158;
CppSimplePtr<Cpp8> DAT_143b10138;
CppSimplePtr<Cpp8> DAT_143b10338;
CppSimplePtr<Cpp8> DAT_143b10308;
CppSimplePtr<Cpp8> DAT_143b10318;
CppSimplePtr<CppVirt> DAT_143b10148;
CppSimplePtr<CppVirt> DAT_143b102e8;
CppSimplePtr<CppVirt> DAT_143b102f8;
CppSimplePtr<CppVirt> DAT_143b102d8;
CppSimplePtr<CppVirt> DAT_143b10328;
CppSimplePtr<CppVirt> DAT_143b10398;
CppSimplePtr<CppOneBlock> DAT_143b10348;
CppSimplePtr<CppOneBlock> DAT_143b10358;
CppSimplePtr<CppTwoBlocks> DAT_143b10368;
CppSimplePtr<CppFourWords> DAT_143b10378;
CppSimplePtr<CppU16Vec> DAT_143b10388;
CppSimplePtr<CppCryptoProvider> DAT_143b103a8;
#endif

// eccrypto's GetRecommendedParameters tables: 18 ECP entries of 0x58 bytes and 22 EC2N entries of 0x48
extern Cpp8 DAT_143b0f4c0[18 * 0x58 / sizeof(Cpp8)];
extern Cpp8 DAT_143b0fb00[22 * 0x48 / sizeof(Cpp8)];
#ifndef MS2_HOOK_DLL
// Full exe: gb:CryptoPP builds no eccrypto, so the tables these exit-time destructors walk are defined here. Nothing
// fills or registers them there; zeroed entries destroy as empty. The hook DLL binds the exe's own.
Cpp8 DAT_143b0f4c0[18 * 0x58 / sizeof(Cpp8)];
Cpp8 DAT_143b0fb00[22 * 0x48 / sizeof(Cpp8)];
#endif

// @0x142cc8ce0
void FUN_142cc8ce0()
{
    __ehvec_dtor(DAT_143b0f4c0, 0x58, 18, (void (*)(void*))FUN_1423291a0);
}
// @0x142cc8d00
void FUN_142cc8d00()
{
    __ehvec_dtor(DAT_143b0fb00, 0x48, 22, (void (*)(void*))FUN_142329200);
}


// @0x142cc8d20
void FUN_142cc8d20()
{
    DAT_143b10178.Free();
}

// @0x142cc8d50
void FUN_142cc8d50()
{
    DAT_143b10168.Free();
}

// @0x142cc8d80
void FUN_142cc8d80()
{
    DAT_143b10158.Free();
}

// @0x142cc8db0
void FUN_142cc8db0()
{
    DAT_143b10138.Free();
}

// @0x142cc8ea0
void FUN_142cc8ea0()
{
    DAT_143b10158.Free();
}

// @0x142cc8ed0
void FUN_142cc8ed0()
{
    DAT_143b10338.Free();
}

// @0x142cc8f00
void FUN_142cc8f00()
{
    DAT_143b10308.Free();
}

// @0x142cc8f30
void FUN_142cc8f30()
{
    DAT_143b10138.Free();
}

// @0x142cc8f60
void FUN_142cc8f60()
{
    DAT_143b10318.Free();
}

// @0x142cc8de0
void FUN_142cc8de0()
{
    DAT_143b10148.Free();
}

// @0x142cc8e10
void FUN_142cc8e10()
{
    DAT_143b102e8.Free();
}

// @0x142cc8e40
void FUN_142cc8e40()
{
    DAT_143b102f8.Free();
}

// @0x142cc8e70
void FUN_142cc8e70()
{
    DAT_143b102d8.Free();
}

// @0x142cc8f90
void FUN_142cc8f90()
{
    DAT_143b10148.Free();
}

// @0x142cc8fc0
void FUN_142cc8fc0()
{
    DAT_143b10328.Free();
}

// @0x142cc9240
void FUN_142cc9240()
{
    DAT_143b10398.Free();
}

// @0x142cc8ff0
void FUN_142cc8ff0()
{
    DAT_143b10348.Free();
}

// @0x142cc9050
void FUN_142cc9050()
{
    DAT_143b10358.Free();
}

// @0x142cc90b0
void FUN_142cc90b0()
{
    DAT_143b10368.Free();
}

// @0x142cc9130
void FUN_142cc9130()
{
    DAT_143b10378.Free();
}

// @0x142cc91b0
void FUN_142cc91b0()
{
    DAT_143b10388.Free();
}

// @0x142cc9270
void FUN_142cc9270()
{
    DAT_143b103a8.Free();
}
