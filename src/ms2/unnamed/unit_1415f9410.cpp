// Recovered Nexon Messenger string, cryptor, and singleton symbols from unit_1415f9410.
// MS2-UNIT: unit_1415f9410
// MS2-RANGE: 0x1415f9410-0x1415fb820 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <windows.h>
#include <strsafe.h>

unsigned long long FUN_1415fb760(int high, int low);

static void nm_free_string_storage(char*& p)
{
    if (p) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(p, &info, sizeof(info)) && info.Type == MEM_PRIVATE)
            ::operator delete(p);
        p = nullptr;
    }
}

static bool nm_ensure_string(void** slot, size_t bytes, size_t emptyRva)
{
    void* empty = static_cast<unsigned char*>(reinterpret_cast<void*>(GetModuleHandleW(nullptr))) + emptyRva;
    if (*slot == nullptr || *slot == empty) {
        *slot = ::operator new(bytes);
        *static_cast<char*>(*slot) = 0;
    }
    return *slot != nullptr && *slot != empty;
}

static void nm_reset_string(void** slot, size_t emptyRva)
{
    void* empty = static_cast<unsigned char*>(reinterpret_cast<void*>(GetModuleHandleW(nullptr))) + emptyRva;
    if (*slot && *slot != empty) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(*slot, &info, sizeof(info)) && info.Type == MEM_PRIVATE)
            ::operator delete(*slot);
    }
    *slot = empty;
}

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9410
bool FUN_1415f9410(void** slot) { return nm_ensure_string(slot, 9, 0x3ae28ec); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f94c0
bool FUN_1415f94c0(void** slot) { return nm_ensure_string(slot, 0x100, 0x3ae28eb); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9570
bool FUN_1415f9570(void** slot) { return nm_ensure_string(slot, 0x1000, 0x3ae28ea); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9620
bool FUN_1415f9620(void** slot) { return nm_ensure_string(slot, 0x15e, 0x3ae28ed); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f96d0
bool FUN_1415f96d0(void** slot) { return nm_ensure_string(slot, 0x20, 0x3ae2848); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9780
bool FUN_1415f9780(void** slot) { return nm_ensure_string(slot, 0x40, 0x3ae28e9); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9830
bool FUN_1415f9830(void** slot) { return nm_ensure_string(slot, 0x400, 0x3ae28e8); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f98e0
bool FUN_1415f98e0(void** slot) { return nm_ensure_string(slot, 0x800, 0x3ae2849); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f99a0
void FUN_1415f99a0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ec); return; } if (FUN_1415f9410(slot)) StringCchCopyA(static_cast<char*>(*slot), 9, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f99f0
void FUN_1415f99f0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ea); return; } if (FUN_1415f9570(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x1000, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9a40
void FUN_1415f9a40(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ed); return; } if (FUN_1415f9620(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x15e, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9a90
void FUN_1415f9a90(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae2848); return; } if (FUN_1415f96d0(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x20, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9ae0
void FUN_1415f9ae0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28e9); return; } if (FUN_1415f9780(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x40, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9b30
void FUN_1415f9b30(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28e8); return; } if (FUN_1415f9830(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x400, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9b80
void FUN_1415f9b80(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae2849); return; } if (FUN_1415f98e0(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x800, value); }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f20
void* FUN_1415f9f20(void** slot) { FUN_1415f9410(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f40
void* FUN_1415f9f40(void** slot) { FUN_1415f94c0(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f60
void* FUN_1415f9f60(void** slot) { FUN_1415f9570(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f80
void* FUN_1415f9f80(void** slot) { FUN_1415f9620(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fa0
void* FUN_1415f9fa0(void** slot) { FUN_1415f96d0(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fc0
void* FUN_1415f9fc0(void** slot) { FUN_1415f9780(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fe0
void* FUN_1415f9fe0(void** slot) { FUN_1415f9830(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415fa000
void* FUN_1415fa000(void** slot) { FUN_1415f98e0(slot); return *slot; }
// @0x1415fa020
size_t FUN_1415fa020() { return 9; }

// @0x1415fa030
size_t FUN_1415fa030() { return 0x100; }

// @0x1415fa040
size_t FUN_1415fa040() { return 0x1000; }

// @0x1415fa050
size_t FUN_1415fa050() { return 0x15e; }

// @0x1415fa060
size_t FUN_1415fa060() { return 0x20; }

// @0x1415fa070
size_t FUN_1415fa070() { return 0x40; }

// @0x1415fa080
size_t FUN_1415fa080() { return 0x400; }

// @0x1415fa090
size_t FUN_1415fa090() { return 0x800; }

// @0x1415fa380
unsigned char FUN_1415fa380(const void* p) { return *(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0a0
unsigned int FUN_1415fa0a0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0b0
unsigned int FUN_1415fa0b0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0c0
unsigned int FUN_1415fa0c0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x20); }
// @0x1415fa120
void FUN_1415fa120(const void* p) { FUN_1415fb760(*reinterpret_cast<const int*>(static_cast<const unsigned char*>(p) + 4), *reinterpret_cast<const int*>(static_cast<const unsigned char*>(p) + 8)); }
// @0x1415fa150
unsigned int FUN_1415fa150(const unsigned int* p) { return *p; }
// @0x1415fa160
unsigned int FUN_1415fa160(const unsigned int* p) { return *p; }
// @0x1415fb760
unsigned long long FUN_1415fb760(int high, int low) { return (static_cast<unsigned long long>(static_cast<unsigned int>(high)) << 32) | static_cast<unsigned int>(low); }
// @0x1415fb780
unsigned long long FUN_1415fb780(int high, int low) { return (static_cast<unsigned long long>(static_cast<unsigned int>(high)) << 32) | static_cast<unsigned int>(low); }
// @0x1415fb7a0
void FUN_1415fb7a0(void* p) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x14) = 1; }
// @0x1415fb7c0
void FUN_1415fb7c0(void* p, unsigned int value) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x20) = value; }
// @0x1415fb7e0
void FUN_1415fb7e0(void* p, unsigned int value) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x14) = value; }
// @0x1415fb800
void FUN_1415fb800(unsigned int* p, unsigned int value) { *p = value; }

// @0x1415f9990
void FUN_1415f9990(void*) { }
// MS2-FUNCTIONAL: the recovered helper is an empty body; pin the alternate unsigned return analysis too.
// MS2-PIN: ?FUN_1415f9990@@YAXPEAX@Z 0x1415f9990
// MS2-PIN: ?FUN_1415f9990@@YAIPEAX@Z 0x1415f9990

// @0x1415f9c30
template<> void CNMStr<0x100>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0BAA@@@QEAAXXZ 0x1415f9c30

// @0x1415f9c90
template<> void CNMStr<0x1000>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0BAAA@@@QEAAXXZ 0x1415f9c90

// @0x1415f9cf0
template<> void CNMStr<350>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0BFO@@@QEAAXXZ 0x1415f9cf0

// @0x1415f9d50
template<> void CNMStr<32>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0CA@@@QEAAXXZ 0x1415f9d50

// @0x1415f9db0
template<> void CNMStr<64>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0EA@@@QEAAXXZ 0x1415f9db0

// @0x1415f9e10
template<> void CNMStr<1024>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0EAA@@@QEAAXXZ 0x1415f9e10

// @0x1415f9e70
template<> void CNMStr<2048>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0IAA@@@QEAAXXZ 0x1415f9e70

class CStreamCryptor_v0
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3();
    virtual unsigned long long vfunc_4(); virtual unsigned int vfunc_5(); virtual unsigned int vfunc_6(unsigned int);
};
class CStreamCryptor_v1
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3();
    virtual unsigned long long vfunc_4(); virtual unsigned int vfunc_5(); virtual int vfunc_6(int);
};
// @0x1415fa0d0
unsigned int CStreamCryptor_v0::vfunc_6(unsigned int value) { return value; }
// MS2-PIN: ?vfunc_6@CStreamCryptor_v0@@UEAAII@Z 0x1415fa0d0
// @0x1415fa0e0
int CStreamCryptor_v1::vfunc_6(int value) { return value + 10; }
// MS2-PIN: ?vfunc_6@CStreamCryptor_v1@@UEAAHH@Z 0x1415fa0e0
// @0x1415fa100
unsigned int CStreamCryptor_v0::vfunc_5() { return 0x8a119e; }
// MS2-PIN: ?vfunc_5@CStreamCryptor_v0@@UEAAIXZ 0x1415fa100
// @0x1415fa110
unsigned int CStreamCryptor_v1::vfunc_5() { return 0x820a9e12; }
// MS2-PIN: ?vfunc_5@CStreamCryptor_v1@@UEAAIXZ 0x1415fa110

// MS2-FUNCTIONAL: provides the process-stable singleton instance recovered from this function.
// @0x1415fa260
CNMManager* CNMManager::GetInstance()
{
    static CNMManager manager;
    return &manager;
}
// MS2-PIN: ?GetInstance@CNMManager@@SAPEAV1@XZ 0x1415fa260

// @0x1415fb610
unsigned long long CStreamCryptor_v0::vfunc_4() { return 0x1fca34; }
// MS2-PIN: ?vfunc_4@CStreamCryptor_v0@@UEAA_KXZ 0x1415fb610
// @0x1415fb620
unsigned long long CStreamCryptor_v1::vfunc_4() { return 0xa98c32a; }
// MS2-PIN: ?vfunc_4@CStreamCryptor_v1@@UEAA_KXZ 0x1415fb620
// @0x1415fb6e0
bool CStreamCryptor_v0::vfunc_3() { return false; }
// MS2-PIN: ?vfunc_3@CStreamCryptor_v0@@UEAA_NXZ 0x1415fb6e0
// @0x1415fb6f0
bool CStreamCryptor_v1::vfunc_3() { return true; }
// MS2-PIN: ?vfunc_3@CStreamCryptor_v1@@UEAA_NXZ 0x1415fb6f0

// @0x1415fb700
int FUN_1415fb700(void* p) { return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14); }
// MS2-PIN: ?FUN_1415fb700@@YAHPEAX@Z 0x1415fb700
// @0x1415fb700
int FUN_1415fb700(const void* p) { return *reinterpret_cast<const int*>(static_cast<const char*>(p) + 0x14); }
// MS2-PIN: ?FUN_1415fb700@@YAHPEBX@Z 0x1415fb700

// @0x1415fb720
int FUN_1415fb720(void* p) { return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14) == 0; }
// MS2-PIN: ?FUN_1415fb720@@YAHPEAX@Z 0x1415fb720

// @0x1415fb750
unsigned int FUN_1415fb750(void* p) { return *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x24); }
// MS2-PIN: ?FUN_1415fb750@@YAIPEAX@Z 0x1415fb750
// MS2-PIN: ?FUN_1415fb750@@YAHPEAX@Z 0x1415fb750
