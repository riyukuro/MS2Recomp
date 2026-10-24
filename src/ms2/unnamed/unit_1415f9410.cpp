// Recovered Nexon Messenger string, cryptor, and singleton symbols from unit_1415f9410.
// MS2-UNIT: unit_1415f9410
// MS2-RANGE: 0x1415f9410-0x1415fb820 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <windows.h>

static void nm_free_string_storage(char*& p)
{
    if (p) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(p, &info, sizeof(info)) && info.Type == MEM_PRIVATE)
            ::operator delete(p);
        p = nullptr;
    }
}

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
    virtual void vfunc_6(); virtual void vfunc_5(); virtual void vfunc_4(); virtual void vfunc_3();
};
class CStreamCryptor_v1
{
public:
    virtual void vfunc_6(); virtual void vfunc_5(); virtual void vfunc_4(); virtual void vfunc_3();
};
// @0x1415fa0d0
void CStreamCryptor_v0::vfunc_6() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_6@CStreamCryptor_v0@@UEAAXXZ 0x1415fa0d0
// @0x1415fa0e0
void CStreamCryptor_v1::vfunc_6() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_6@CStreamCryptor_v1@@UEAAXXZ 0x1415fa0e0
// @0x1415fa100
void CStreamCryptor_v0::vfunc_5() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_5@CStreamCryptor_v0@@UEAAXXZ 0x1415fa100
// @0x1415fa110
void CStreamCryptor_v1::vfunc_5() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_5@CStreamCryptor_v1@@UEAAXXZ 0x1415fa110

// @0x1415fa260
CNMManager* CNMManager::GetInstance()
{
    static CNMManager manager;
    return &manager;
}
// MS2-FUNCTIONAL: provides a process-stable singleton instance with static initialization.
// MS2-PIN: ?GetInstance@CNMManager@@SAPEAV1@XZ 0x1415fa260

// @0x1415fb610
void CStreamCryptor_v0::vfunc_4() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_4@CStreamCryptor_v0@@UEAAXXZ 0x1415fb610
// @0x1415fb620
void CStreamCryptor_v1::vfunc_4() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_4@CStreamCryptor_v1@@UEAAXXZ 0x1415fb620
// @0x1415fb6e0
void CStreamCryptor_v0::vfunc_3() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_3@CStreamCryptor_v0@@UEAAXXZ 0x1415fb6e0
// @0x1415fb6f0
void CStreamCryptor_v1::vfunc_3() { }
// MS2-FUNCTIONAL: preserves the recovered virtual slot; Ghidra's return-value annotation conflicts with the exported signature.
// MS2-PIN: ?vfunc_3@CStreamCryptor_v1@@UEAAXXZ 0x1415fb6f0

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
