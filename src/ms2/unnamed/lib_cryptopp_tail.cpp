// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The .text$yd atexit thunks of Crypto++ 5.6.2 function-local
// statics (Singleton<T>::Ref's simple_ptr<T> s_pObject, the DL_*/EC parameter tables) that gbprogress's di/yd block
// pass does not pair: their initializers run lazily inside the engine-stage gb:CryptoPP/* TUs, so no .text$di function
// registers them. Each thunk is written out by hand over the static it destroys; the statics are exe data (DAT_<va>).
// MS2-UNIT: lib_cryptopp_tail
// MS2-RANGE: 0x142cc8c20-0x142cc92ab .text$yd
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <windows.h>
#include <wincrypt.h>
#include <intrin.h>
#include <vector>
#include <memory>

// @0x142cc8c20
// std::string::_Tidy(true): free a heap buffer (big-allocation header unwrapped), then reset to the empty SSO string
struct CppStdString
{
    union { char buf[16]; char* ptr; };
    size_t size;
    size_t res;
};
extern CppStdString DAT_143a29388;
void FUN_142cc8c20()
{
    CppStdString& s = DAT_143a29388;                                    // CryptoPP::DEFAULT_CHANNEL
    if (s.res >= 16)
        std::allocator<char>().deallocate(s.ptr, s.res + 1);
    s.size = 0;
    s.res = 15;
    s.buf[0] = 0;
}

// operator delete / aligned free / __ehvec_dtor as the exe's CRT and Crypto++ expose them
void FUN_142308be0(void* p);                                                    // CryptoPP::UnalignedDeallocate
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
void FUN_1423291a0(void* p);
void FUN_142329200(void* p);

// CryptoPP::simple_ptr<T>
template <class T> struct CppSimplePtr
{
    T* m_p;
    ~CppSimplePtr() { Free(); }
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
        FUN_142308be0(p);
    }
};
struct CppOneBlock { CppSecBlock a; };
struct CppTwoBlocks { void* vptr; CppSecBlock a; CppSecBlock b; };
struct CppFourWords { void* v0; void* v1; CppSecBlock a; void* v5; void* v6; CppSecBlock b; void* v9; };

extern Cpp8 DAT_143b0f4c0[18];
extern Cpp8 DAT_143b0fb00[22];

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


extern CppSimplePtr<Cpp8> DAT_143b10178;
// @0x142cc8d20
void FUN_142cc8d20()
{
    DAT_143b10178.Free();
}

extern CppSimplePtr<Cpp8> DAT_143b10168;
// @0x142cc8d50
void FUN_142cc8d50()
{
    DAT_143b10168.Free();
}

extern CppSimplePtr<Cpp8> DAT_143b10158;
// @0x142cc8d80
void FUN_142cc8d80()
{
    DAT_143b10158.Free();
}

extern CppSimplePtr<Cpp8> DAT_143b10138;
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

extern CppSimplePtr<Cpp8> DAT_143b10338;
// @0x142cc8ed0
void FUN_142cc8ed0()
{
    DAT_143b10338.Free();
}

extern CppSimplePtr<Cpp8> DAT_143b10308;
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

extern CppSimplePtr<Cpp8> DAT_143b10318;
// @0x142cc8f60
void FUN_142cc8f60()
{
    DAT_143b10318.Free();
}

extern CppSimplePtr<CppVirt> DAT_143b10148;
// @0x142cc8de0
void FUN_142cc8de0()
{
    DAT_143b10148.Free();
}

extern CppSimplePtr<CppVirt> DAT_143b102e8;
// @0x142cc8e10
void FUN_142cc8e10()
{
    DAT_143b102e8.Free();
}

extern CppSimplePtr<CppVirt> DAT_143b102f8;
// @0x142cc8e40
void FUN_142cc8e40()
{
    DAT_143b102f8.Free();
}

extern CppSimplePtr<CppVirt> DAT_143b102d8;
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

extern CppSimplePtr<CppVirt> DAT_143b10328;
// @0x142cc8fc0
void FUN_142cc8fc0()
{
    DAT_143b10328.Free();
}

extern CppSimplePtr<CppVirt> DAT_143b10398;
// @0x142cc9240
void FUN_142cc9240()
{
    DAT_143b10398.Free();
}

extern CppSimplePtr<CppOneBlock> DAT_143b10348;
// @0x142cc8ff0
void FUN_142cc8ff0()
{
    DAT_143b10348.Free();
}

extern CppSimplePtr<CppOneBlock> DAT_143b10358;
// @0x142cc9050
void FUN_142cc9050()
{
    DAT_143b10358.Free();
}

extern CppSimplePtr<CppTwoBlocks> DAT_143b10368;
// @0x142cc90b0
void FUN_142cc90b0()
{
    DAT_143b10368.Free();
}

extern CppSimplePtr<CppFourWords> DAT_143b10378;
// @0x142cc9130
void FUN_142cc9130()
{
    DAT_143b10378.Free();
}

typedef std::vector<unsigned short> CppU16Vec;
extern CppSimplePtr<CppU16Vec> DAT_143b10388;
// @0x142cc91b0
void FUN_142cc91b0()
{
    DAT_143b10388.Free();
}

// CryptoPP::MicrosoftCryptoProvider: the process-wide CryptoAPI context (Singleton<MicrosoftCryptoProvider>)
struct CppCryptoProvider
{
    HCRYPTPROV m_hProvider;
    ~CppCryptoProvider() { CryptReleaseContext(m_hProvider, 0); }
};
extern CppSimplePtr<CppCryptoProvider> DAT_143b103a8;
// @0x142cc9270
void FUN_142cc9270()
{
    DAT_143b103a8.Free();
}
